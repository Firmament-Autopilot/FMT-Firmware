/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2247
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov 18 15:56:22 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S432>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S442>/Motion State' */
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

/* Named constants for Chart: '<S362>/Motion State' */
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
struct_xXeuwAPh0ajaUfdgPpGaUB FMS_PARAM = {
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
  1300U,
  0.5F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S3>/Constant1'
                                        *   '<S7>/Land_Lock_Thro'
                                        *   '<S28>/Constant'
                                        *   '<S486>/Constant'
                                        *   '<S345>/L1'
                                        *   '<S49>/Gain'
                                        *   '<S49>/Gain1'
                                        *   '<S126>/Gain'
                                        *   '<S126>/Gain1'
                                        *   '<S128>/Constant'
                                        *   '<S154>/L1'
                                        *   '<S235>/Saturation'
                                        *   '<S236>/Saturation1'
                                        *   '<S236>/Saturation2'
                                        *   '<S236>/Saturation3'
                                        *   '<S386>/Land_Speed'
                                        *   '<S387>/Saturation1'
                                        *   '<S473>/Takeoff_Speed'
                                        *   '<S474>/Gain2'
                                        *   '<S474>/Saturation1'
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
                                        *   '<S291>/Gain2'
                                        *   '<S298>/Gain1'
                                        *   '<S298>/Gain2'
                                        *   '<S351>/Saturation1'
                                        *   '<S361>/Saturation'
                                        *   '<S373>/Saturation1'
                                        *   '<S388>/Constant'
                                        *   '<S391>/Gain2'
                                        *   '<S413>/Gain'
                                        *   '<S413>/Saturation1'
                                        *   '<S416>/Constant'
                                        *   '<S416>/vel'
                                        *   '<S416>/Switch'
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
                                        *   '<S176>/Constant'
                                        *   '<S176>/vel'
                                        *   '<S176>/Switch'
                                        *   '<S354>/Gain2'
                                        *   '<S355>/Gain1'
                                        *   '<S364>/Gain2'
                                        *   '<S365>/Gain1'
                                        *   '<S376>/Gain2'
                                        *   '<S377>/Gain6'
                                        *   '<S400>/Gain2'
                                        *   '<S400>/Saturation'
                                        *   '<S401>/Integrator'
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
                                        *   '<S357>/Dead Zone'
                                        *   '<S357>/Gain'
                                        *   '<S369>/Dead Zone'
                                        *   '<S369>/Gain'
                                        *   '<S381>/Dead Zone'
                                        *   '<S381>/Gain'
                                        *   '<S382>/Dead Zone'
                                        *   '<S382>/Gain'
                                        *   '<S431>/Saturation1'
                                        *   '<S441>/Saturation1'
                                        *   '<S191>/Saturation1'
                                        *   '<S201>/Saturation1'
                                        *   '<S434>/Gain2'
                                        *   '<S435>/Gain1'
                                        *   '<S444>/Gain2'
                                        *   '<S445>/Gain6'
                                        *   '<S194>/Gain2'
                                        *   '<S195>/Gain1'
                                        *   '<S204>/Gain2'
                                        *   '<S205>/Gain6'
                                        *   '<S437>/Dead Zone'
                                        *   '<S437>/Gain'
                                        *   '<S449>/Dead Zone'
                                        *   '<S449>/Gain'
                                        *   '<S450>/Dead Zone'
                                        *   '<S450>/Gain'
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
                                        *   '<S484>/Constant'
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
 *    '<S431>/Hold Control'
 *    '<S351>/Hold Control'
 *    '<S191>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S434>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S431>/Hold Control'
 *    '<S351>/Hold Control'
 *    '<S191>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S434>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S431>/Hold Control'
 *    '<S351>/Hold Control'
 *    '<S191>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S434>/Delay' incorporates:
   *  Gain: '<S436>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S434>/Gain2' incorporates:
   *  Delay: '<S434>/Delay'
   *  Gain: '<S436>/Gain'
   *  Sum: '<S434>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S434>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S431>/Brake Control'
 *    '<S351>/Brake Control'
 *    '<S361>/Brake Control'
 *    '<S191>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S433>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S433>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S431>/Move Control'
 *    '<S351>/Move Control'
 *    '<S191>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S438>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S438>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S431>/Move Control'
 *    '<S351>/Move Control'
 *    '<S191>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S438>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S438>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S431>/Move Control'
 *    '<S351>/Move Control'
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

  /* Product: '<S439>/Multiply1' incorporates:
   *  Constant: '<S439>/const1'
   *  DiscreteIntegrator: '<S438>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S437>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S437>/Dead Zone' */

  /* Sum: '<S439>/Add' incorporates:
   *  DiscreteIntegrator: '<S438>/Integrator1'
   *  Gain: '<S435>/Gain1'
   *  Gain: '<S437>/Gain'
   *  Sum: '<S438>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S439>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S439>/Sign' */

  /* Sum: '<S439>/Add2' incorporates:
   *  Abs: '<S439>/Abs'
   *  Gain: '<S439>/Gain'
   *  Gain: '<S439>/Gain1'
   *  Product: '<S439>/Multiply2'
   *  Product: '<S439>/Multiply3'
   *  Sqrt: '<S439>/Sqrt'
   *  Sum: '<S439>/Add1'
   *  Sum: '<S439>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S439>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S439>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S439>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S439>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S439>/Sign1' */

  /* Signum: '<S439>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S439>/Sign2' */

  /* Sum: '<S439>/Add5' incorporates:
   *  Gain: '<S439>/Gain2'
   *  Product: '<S439>/Multiply4'
   *  Sum: '<S439>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S435>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S438>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S438>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S438>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S439>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S439>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S439>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_g;
  }

  /* End of Signum: '<S439>/Sign5' */

  /* Signum: '<S439>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S439>/Sign3' */

  /* Signum: '<S439>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S439>/Sign4' */

  /* Signum: '<S439>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S439>/Sign6' */

  /* Update for DiscreteIntegrator: '<S438>/Integrator' incorporates:
   *  Constant: '<S439>/const'
   *  Gain: '<S439>/Gain3'
   *  Product: '<S439>/Divide'
   *  Product: '<S439>/Multiply5'
   *  Product: '<S439>/Multiply6'
   *  Sum: '<S439>/Subtract4'
   *  Sum: '<S439>/Subtract5'
   *  Sum: '<S439>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S432>/Motion Status'
 *    '<S352>/Motion Status'
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
 *    '<S432>/Motion Status'
 *    '<S352>/Motion Status'
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
 *    '<S432>/Motion Status'
 *    '<S352>/Motion Status'
 *    '<S192>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S432>/Motion Status' */
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

  /* End of Chart: '<S432>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S441>/Hold Control'
 *    '<S373>/Hold Control'
 *    '<S201>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S444>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S441>/Hold Control'
 *    '<S373>/Hold Control'
 *    '<S201>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S444>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S441>/Hold Control'
 *    '<S373>/Hold Control'
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

  /* Delay: '<S444>/Delay' incorporates:
   *  SignalConversion: '<S444>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S448>/Trigonometric Function1' incorporates:
   *  Gain: '<S447>/Gain'
   *  Trigonometry: '<S448>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S448>/Trigonometric Function' incorporates:
   *  Gain: '<S447>/Gain'
   *  Trigonometry: '<S448>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S448>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S448>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S448>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S448>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S448>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S448>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S448>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S444>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S444>/Delay'
   *  SignalConversion: '<S444>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S444>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S444>/Multiply' incorporates:
   *  SignalConversion: '<S444>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S444>/Multiply' */

  /* Gain: '<S444>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S444>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S441>/Brake Control'
 *    '<S373>/Brake Control'
 *    '<S201>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S443>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S441>/Move Control'
 *    '<S373>/Move Control'
 *    '<S201>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S451>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S451>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S451>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S451>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S441>/Move Control'
 *    '<S373>/Move Control'
 *    '<S201>/Move Control'
 */
void FMS_MoveControl_i_Reset(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S451>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S451>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S451>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S451>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S441>/Move Control'
 *    '<S373>/Move Control'
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

  /* SignalConversion: '<S445>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S451>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S452>/Multiply1' incorporates:
   *  Constant: '<S452>/const1'
   *  DiscreteIntegrator: '<S451>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S445>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S451>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S452>/Multiply1' incorporates:
   *  Constant: '<S452>/const1'
   *  DiscreteIntegrator: '<S451>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S449>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S449>/Dead Zone' */

  /* Sum: '<S452>/Add' incorporates:
   *  DiscreteIntegrator: '<S451>/Integrator1'
   *  Gain: '<S445>/Gain6'
   *  Gain: '<S449>/Gain'
   *  Sum: '<S451>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S450>/Dead Zone' */
  if (rtu_FMS_In_o > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_o >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S450>/Dead Zone' */

  /* Sum: '<S452>/Add' incorporates:
   *  DiscreteIntegrator: '<S451>/Integrator1'
   *  Gain: '<S445>/Gain6'
   *  Gain: '<S450>/Gain'
   *  Sum: '<S451>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S452>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S452>/Add2' incorporates:
   *  Abs: '<S452>/Abs'
   *  Gain: '<S452>/Gain'
   *  Gain: '<S452>/Gain1'
   *  Product: '<S452>/Multiply2'
   *  Product: '<S452>/Multiply3'
   *  Signum: '<S452>/Sign'
   *  Sqrt: '<S452>/Sqrt'
   *  Sum: '<S452>/Add1'
   *  Sum: '<S452>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S452>/Add3' incorporates:
   *  Signum: '<S452>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S452>/Subtract1' incorporates:
   *  Signum: '<S452>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S452>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S452>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S452>/Add5' incorporates:
   *  Gain: '<S452>/Gain2'
   *  Product: '<S452>/Multiply4'
   *  Signum: '<S452>/Sign'
   *  Sum: '<S452>/Add2'
   *  Sum: '<S452>/Add4'
   *  Sum: '<S452>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S451>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S451>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S452>/Sign3' incorporates:
   *  Sum: '<S452>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S452>/Sign4' incorporates:
   *  Sum: '<S452>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S452>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S452>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S452>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S452>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S451>/Integrator' incorporates:
   *  Constant: '<S452>/const'
   *  Gain: '<S452>/Gain3'
   *  Product: '<S452>/Divide'
   *  Product: '<S452>/Multiply5'
   *  Product: '<S452>/Multiply6'
   *  Sum: '<S452>/Subtract4'
   *  Sum: '<S452>/Subtract5'
   *  Sum: '<S452>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Signum: '<S452>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_l_idx_0 = 1.0F;
  } else {
    rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S452>/Add2' incorporates:
   *  Abs: '<S452>/Abs'
   *  Gain: '<S452>/Gain'
   *  Gain: '<S452>/Gain1'
   *  Product: '<S452>/Multiply2'
   *  Product: '<S452>/Multiply3'
   *  Signum: '<S452>/Sign'
   *  Sqrt: '<S452>/Sqrt'
   *  Sum: '<S452>/Add1'
   *  Sum: '<S452>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_l_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S452>/Add3' incorporates:
   *  Signum: '<S452>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S452>/Subtract1' incorporates:
   *  Signum: '<S452>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S452>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S452>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S452>/Add5' incorporates:
   *  Gain: '<S452>/Gain2'
   *  Product: '<S452>/Multiply4'
   *  Signum: '<S452>/Sign'
   *  Sum: '<S452>/Add2'
   *  Sum: '<S452>/Add4'
   *  Sum: '<S452>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S451>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S451>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S452>/Sign3' incorporates:
   *  Sum: '<S452>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S452>/Sign4' incorporates:
   *  Sum: '<S452>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S452>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S452>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S452>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S452>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S451>/Integrator' incorporates:
   *  Constant: '<S452>/const'
   *  Gain: '<S452>/Gain3'
   *  Product: '<S452>/Divide'
   *  Product: '<S452>/Multiply5'
   *  Product: '<S452>/Multiply6'
   *  Sum: '<S452>/Subtract4'
   *  Sum: '<S452>/Subtract5'
   *  Sum: '<S452>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S442>/Motion State'
 *    '<S374>/Motion State'
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
 *    '<S442>/Motion State'
 *    '<S374>/Motion State'
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
 *    '<S442>/Motion State'
 *    '<S374>/Motion State'
 *    '<S202>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S442>/Motion State' */
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

  /* End of Chart: '<S442>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S418>/NearbyRefWP'
 *    '<S178>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S456>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S361>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S364>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S361>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S364>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S361>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_nb;

  /* Delay: '<S364>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S364>/Sum' incorporates:
   *  Delay: '<S364>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S367>/Abs' */
  rtb_Abs_nb = fabsf(rtb_psi_error_rad);

  /* Switch: '<S367>/Switch' incorporates:
   *  Constant: '<S367>/Constant'
   *  Constant: '<S368>/Constant'
   *  Product: '<S367>/Multiply'
   *  RelationalOperator: '<S368>/Compare'
   *  Sum: '<S367>/Subtract'
   */
  if (rtb_Abs_nb > 3.14159274F) {
    /* Signum: '<S367>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S367>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_nb - 6.28318548F;
  }

  /* End of Switch: '<S367>/Switch' */

  /* Gain: '<S364>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S364>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S361>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S361>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S370>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S361>/Move Control'
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

  /* Product: '<S371>/Multiply1' incorporates:
   *  Constant: '<S371>/const1'
   *  DiscreteIntegrator: '<S370>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S369>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S369>/Dead Zone' */

  /* Sum: '<S371>/Add' incorporates:
   *  DiscreteIntegrator: '<S370>/Integrator1'
   *  Gain: '<S365>/Gain1'
   *  Gain: '<S369>/Gain'
   *  Sum: '<S370>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S371>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
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
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S371>/Add4' */
  rtb_Add4_b = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S371>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_l + localC->d;

  /* Sum: '<S371>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S371>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S371>/Sign1' */

  /* Signum: '<S371>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S371>/Sign2' */

  /* Sum: '<S371>/Add5' incorporates:
   *  Gain: '<S371>/Gain2'
   *  Product: '<S371>/Multiply4'
   *  Sum: '<S371>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_l) * 0.5F * rtb_Add4_b;

  /* SignalConversion: '<S365>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S370>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S370>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S370>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S371>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S371>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S371>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_b = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_b = 1.0F;
  } else {
    rtb_Add4_b = rtb_a_m;
  }

  /* End of Signum: '<S371>/Sign5' */

  /* Signum: '<S371>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S371>/Sign3' */

  /* Signum: '<S371>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S371>/Sign4' */

  /* Signum: '<S371>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
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

  /* BusAssignment: '<S347>/Bus Assignment' incorporates:
   *  Constant: '<S347>/Constant'
   *  Constant: '<S347>/Constant2'
   *  SignalConversion: '<S347>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S347>/Bus Assignment' */
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

  /* Gain: '<S488>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S489>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S489>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S489>/Multiply1' incorporates:
   *  Product: '<S489>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S489>/Divide' incorporates:
   *  Constant: '<S489>/Constant'
   *  Constant: '<S489>/R'
   *  Sqrt: '<S489>/Sqrt'
   *  Sum: '<S489>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S489>/Product3' incorporates:
   *  Constant: '<S489>/Constant1'
   *  Product: '<S489>/Multiply1'
   *  Sum: '<S489>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S489>/Multiply2' incorporates:
   *  Trigonometry: '<S489>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S488>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S493>/Abs' incorporates:
   *  Abs: '<S496>/Abs1'
   *  Switch: '<S493>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S493>/Switch1' incorporates:
   *  Abs: '<S493>/Abs'
   *  Bias: '<S493>/Bias2'
   *  Bias: '<S493>/Bias3'
   *  Constant: '<S490>/Constant'
   *  Constant: '<S490>/Constant1'
   *  Constant: '<S495>/Constant'
   *  Gain: '<S493>/Gain1'
   *  Product: '<S493>/Multiply'
   *  RelationalOperator: '<S495>/Compare'
   *  Switch: '<S490>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S496>/Switch1' incorporates:
     *  Bias: '<S496>/Bias2'
     *  Bias: '<S496>/Bias3'
     *  Constant: '<S496>/Constant'
     *  Constant: '<S497>/Constant'
     *  Math: '<S496>/Math Function'
     *  RelationalOperator: '<S497>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S496>/Switch1' */

    /* Signum: '<S493>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S493>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S490>/Sum' incorporates:
   *  Sum: '<S488>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S488>/Multiply' incorporates:
   *  Gain: '<S488>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S492>/Switch1' incorporates:
   *  Abs: '<S492>/Abs1'
   *  Bias: '<S492>/Bias2'
   *  Bias: '<S492>/Bias3'
   *  Constant: '<S492>/Constant'
   *  Constant: '<S494>/Constant'
   *  Math: '<S492>/Math Function'
   *  RelationalOperator: '<S494>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S492>/Switch1' */

  /* Product: '<S488>/Multiply' incorporates:
   *  Gain: '<S488>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S488>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S491>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S491>/Sum2' incorporates:
   *  Product: '<S491>/Multiply1'
   *  Product: '<S491>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S491>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S491>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S491>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S485>/Data Type Conversion' incorporates:
   *  Gain: '<S488>/Gain'
   *  Sum: '<S488>/Sum1'
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
        FMS_DW.flag_start)) && (FMS_DW.Delay_DSTATE_c != PilotMode_None)) {
    FMS_B.degrade = 0.0;
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    guard6 = false;
    if (FMS_DW.Delay_DSTATE_c == PilotMode_Offboard) {
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U)
           != 0U)) {
        FMS_DW.is_Mode = FMS_IN_Offboard_h;
        FMS_B.target_mode = PilotMode_Offboard;
      } else {
        FMS_B.degrade = 1.0;
        guard6 = true;
      }
    } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Mission) {
      guard6 = true;
    } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Position) {
      guard5 = true;
    } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Altitude) {
      guard4 = true;
    } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Stabilize) {
      guard3 = true;
    } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Acro) {
      guard2 = true;
    } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Manual) {
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
  if (FMS_DW.Delay_DSTATE_c == PilotMode_Offboard) {
    if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U) &&
        ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U))
    {
      FMS_DW.is_Mode = FMS_IN_Offboard_h;
      FMS_B.target_mode = PilotMode_Offboard;
    } else {
      FMS_B.degrade = 1.0;
      guard6 = true;
    }
  } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Mission) {
    guard6 = true;
  } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Position) {
    guard5 = true;
  } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Altitude) {
    guard4 = true;
  } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Stabilize) {
    guard3 = true;
  } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Acro) {
    guard2 = true;
  } else if (FMS_DW.Delay_DSTATE_c == PilotMode_Manual) {
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
  /* RelationalOperator: '<S498>/Compare' incorporates:
   *  Abs: '<S487>/Abs'
   *  Constant: '<S498>/Constant'
   *  MinMax: '<S487>/Max'
   *  Sum: '<S487>/Sum'
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

      /* Outputs for Function Call SubSystem: '<S6>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S486>/Reshape' incorporates:
       *  Constant: '<S486>/Constant'
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
  real32_T rtb_Multiply_o[3];
  uint16_T rtb_Divide_dr;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  real32_T rtb_Add3_c;
  real32_T rtb_a_l;
  boolean_T rtb_Compare_on;
  MotionState rtb_state_c;
  real32_T rtb_Switch2_i;
  real32_T rtb_Rem_p;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real_T rtb_Switch1_p;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_TmpSignalConversionAtDela_a[2];
  real32_T rtb_VectorConcatenate_ia[9];
  real32_T rtb_VectorConcatenate_ei[9];
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
  real32_T tmp_3[3];
  int32_T rtb_Compare_bv_0;
  real32_T rtb_MathFunction_iq_idx_1;
  real32_T rtb_TmpSignalConversionAtMath_0;
  real32_T rtb_MathFunction_f_idx_2;
  real32_T rtb_P_l_idx_0;
  real32_T rtb_Divide_lr_idx_2;
  real32_T rtb_Divide_lr_idx_1;
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
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S15>/Switch1' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion1'
       *  Delay: '<S15>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S15>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S15>/Delay'
   *  Inport: '<Root>/INS_Out'
   */
  FMS_DW.mode_prev = FMS_DW.mode_start;
  FMS_DW.mode_start = FMS_DW.Delay_DSTATE_c;
  FMS_DW.flag_prev = FMS_DW.flag_start;
  FMS_DW.flag_start = FMS_U.INS_Out.flag;
  if (FMS_DW.is_active_c1_FMS == 0U) {
    FMS_DW.mode_prev = FMS_DW.Delay_DSTATE_c;
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

  /* Sqrt: '<S508>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S508>/Square'
   *  Sum: '<S508>/Sum of Elements'
   */
  rtb_Saturation_n = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
    FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
    FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S504>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add3_c = FMS_U.INS_Out.quat[0] / rtb_Saturation_n;
  rtb_Divide_lr_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Saturation_n;
  rtb_Divide_lr_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_n;
  rtb_Saturation_n = FMS_U.INS_Out.quat[3] / rtb_Saturation_n;

  /* Math: '<S505>/Square' incorporates:
   *  Math: '<S506>/Square'
   *  Math: '<S507>/Square'
   */
  rtb_a_l = rtb_Add3_c * rtb_Add3_c;

  /* Math: '<S505>/Square2' incorporates:
   *  Math: '<S506>/Square2'
   *  Math: '<S507>/Square2'
   */
  rtb_Gain_fj = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

  /* Math: '<S505>/Square1' incorporates:
   *  Math: '<S506>/Square1'
   *  Math: '<S507>/Square1'
   */
  rtb_Switch2_i = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1;

  /* Math: '<S505>/Square3' incorporates:
   *  Math: '<S506>/Square3'
   *  Math: '<S507>/Square3'
   */
  rtb_Sqrt_b = rtb_Saturation_n * rtb_Saturation_n;

  /* Sum: '<S505>/Subtract' incorporates:
   *  Math: '<S505>/Square'
   *  Math: '<S505>/Square1'
   *  Math: '<S505>/Square2'
   *  Math: '<S505>/Square3'
   *  Sum: '<S505>/Add'
   *  Sum: '<S505>/Add1'
   */
  rtb_Transpose[0] = (rtb_a_l + rtb_Switch2_i) - (rtb_Gain_fj + rtb_Sqrt_b);

  /* Product: '<S505>/Multiply' incorporates:
   *  Product: '<S506>/Multiply'
   */
  rtb_MathFunction_iq_idx_1 = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_2;

  /* Product: '<S505>/Multiply1' incorporates:
   *  Product: '<S506>/Multiply1'
   */
  rtb_MathFunction_f_idx_2 = rtb_Add3_c * rtb_Saturation_n;

  /* Gain: '<S505>/Gain' incorporates:
   *  Product: '<S505>/Multiply'
   *  Product: '<S505>/Multiply1'
   *  Sum: '<S505>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_MathFunction_iq_idx_1 - rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Product: '<S505>/Multiply2' incorporates:
   *  Product: '<S507>/Multiply'
   */
  rtb_Rem_p = rtb_Divide_lr_idx_1 * rtb_Saturation_n;

  /* Product: '<S505>/Multiply3' incorporates:
   *  Product: '<S507>/Multiply1'
   */
  rtb_TmpSignalConversionAtMath_0 = rtb_Add3_c * rtb_Divide_lr_idx_2;

  /* Gain: '<S505>/Gain1' incorporates:
   *  Product: '<S505>/Multiply2'
   *  Product: '<S505>/Multiply3'
   *  Sum: '<S505>/Add2'
   */
  rtb_Transpose[2] = (rtb_Rem_p + rtb_TmpSignalConversionAtMath_0) * 2.0F;

  /* Gain: '<S506>/Gain' incorporates:
   *  Sum: '<S506>/Add3'
   */
  rtb_Transpose[3] = (rtb_MathFunction_iq_idx_1 + rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Sum: '<S506>/Subtract' incorporates:
   *  Sum: '<S506>/Add'
   *  Sum: '<S506>/Add1'
   */
  rtb_Transpose[4] = (rtb_a_l + rtb_Gain_fj) - (rtb_Switch2_i + rtb_Sqrt_b);

  /* Product: '<S506>/Multiply2' incorporates:
   *  Product: '<S507>/Multiply2'
   */
  rtb_MathFunction_iq_idx_1 = rtb_Divide_lr_idx_2 * rtb_Saturation_n;

  /* Product: '<S506>/Multiply3' incorporates:
   *  Product: '<S507>/Multiply3'
   */
  rtb_MathFunction_f_idx_2 = rtb_Add3_c * rtb_Divide_lr_idx_1;

  /* Gain: '<S506>/Gain1' incorporates:
   *  Product: '<S506>/Multiply2'
   *  Product: '<S506>/Multiply3'
   *  Sum: '<S506>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_MathFunction_iq_idx_1 - rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Gain: '<S507>/Gain' incorporates:
   *  Sum: '<S507>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Rem_p - rtb_TmpSignalConversionAtMath_0) * 2.0F;

  /* Gain: '<S507>/Gain1' incorporates:
   *  Sum: '<S507>/Add2'
   */
  rtb_Transpose[7] = (rtb_MathFunction_iq_idx_1 + rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Sum: '<S507>/Subtract' incorporates:
   *  Sum: '<S507>/Add'
   *  Sum: '<S507>/Add1'
   */
  rtb_Transpose[8] = (rtb_a_l + rtb_Sqrt_b) - (rtb_Switch2_i + rtb_Gain_fj);

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
    rtb_Multiply_o[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 6] *
      FMS_U.INS_Out.az + (rtb_Transpose[rtb_Compare_bv_0 + 3] * FMS_U.INS_Out.ay
                          + rtb_Transpose[rtb_Compare_bv_0] * FMS_U.INS_Out.ax);
  }

  /* End of Product: '<S7>/Multiply' */

  /* DiscreteIntegrator: '<S499>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Multiply_o[0];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply_o[1];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply_o[2];
  }

  /* Product: '<S7>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S7>/Sum of Elements'
   */
  rtb_Divide_dr = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S501>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S501>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_dr;
  }

  /* Product: '<S7>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S7>/Cos'
   *  Trigonometry: '<S7>/Cos1'
   */
  rtb_a_l = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32(FMS_U.INS_Out.theta);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_a_l > 1.0F) {
    rtb_a_l = 1.0F;
  } else {
    if (rtb_a_l < 0.9F) {
      rtb_a_l = 0.9F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Land_Lock_Thro'
   */
  rtb_Divide_lr_idx_2 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_a_l;

  /* DiscreteIntegrator: '<S500>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_lr_idx_2;
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S499>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S500>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S501>/Discrete-Time Integrator5'
   *  Logic: '<S502>/AND'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S502>/Lower Test'
   *  RelationalOperator: '<S502>/Upper Test'
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
    (rtb_Switch_ga != 0) && (FMS_U.Auto_Cmd.frame <= 2));

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

  /* Sum: '<S483>/Add' incorporates:
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
        /* Disable for SwitchCase: '<S441>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S431>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S373>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S351>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S361>/Switch Case' */
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
          /* Disable for SwitchCase: '<S441>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S431>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S373>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S351>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S361>/Switch Case' */
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
       *  Math: '<S463>/Math Function'
       *  Product: '<S465>/Divide'
       *  Sum: '<S419>/Subtract'
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
          /* Disable for SwitchCase: '<S441>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S431>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S373>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S351>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S361>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Takeoff' incorporates:
           *  ActionPort: '<S346>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S481>/cur_waypoint'
           *  DiscreteIntegrator: '<S477>/Integrator'
           *  DiscreteIntegrator: '<S477>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Takeoff' incorporates:
         *  ActionPort: '<S346>/Action Port'
         */
        /* Delay: '<S481>/cur_waypoint' incorporates:
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
        /* Product: '<S481>/Divide' incorporates:
         *  Delay: '<S481>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S481>/Sum1'
         *  Sum: '<S481>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Saturate: '<S481>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S481>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S482>/Trigonometric Function1' incorporates:
         *  Gain: '<S480>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S482>/Trigonometric Function3'
         */
        rtb_a_l = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[0] = rtb_a_l;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S482>/Trigonometric Function' incorporates:
         *  Gain: '<S480>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S482>/Trigonometric Function2'
         */
        rtb_Gain_fj = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[1] = rtb_Gain_fj;

        /* SignalConversion: '<S482>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S482>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S482>/Gain' */
        rtb_Transpose[3] = -rtb_Gain_fj;

        /* Trigonometry: '<S482>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_a_l;

        /* SignalConversion: '<S482>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S482>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S482>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S474>/Saturation1' */
        rtb_Saturation_n = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Switch2_i = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S474>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S481>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S481>/Multiply'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S474>/Sum'
         *  Sum: '<S481>/Sum3'
         *  Sum: '<S481>/Sum4'
         */
        rtb_Divide_lr_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Add3_c +
          FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_Gain_fj = ((FMS_B.Cmd_In.sp_waypoint[1] -
                        FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Add3_c +
                       FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S474>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Divide_lr_idx_1;
        }

        /* Saturate: '<S474>/Saturation1' incorporates:
         *  Gain: '<S474>/Gain2'
         *  Product: '<S474>/Multiply'
         */
        rtb_a_l = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S346>/Bus Assignment1'
         *  Constant: '<S346>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S346>/Bus Assignment1' incorporates:
         *  Constant: '<S346>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S474>/Saturation1' */
        if (rtb_a_l > rtb_Saturation_n) {
          /* BusAssignment: '<S346>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Saturation_n;
        } else if (rtb_a_l < rtb_Switch2_i) {
          /* BusAssignment: '<S346>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch2_i;
        } else {
          /* BusAssignment: '<S346>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_a_l;
        }

        if (rtb_Add3_c > rtb_Saturation_n) {
          /* BusAssignment: '<S346>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        } else if (rtb_Add3_c < rtb_Switch2_i) {
          /* BusAssignment: '<S346>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch2_i;
        } else {
          /* BusAssignment: '<S346>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S346>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S477>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S478>/Multiply1' incorporates:
         *  Constant: '<S478>/const1'
         *  DiscreteIntegrator: '<S477>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S473>/Switch' incorporates:
         *  Abs: '<S473>/Abs'
         *  Abs: '<S473>/Abs1'
         *  Constant: '<S473>/Takeoff_Speed'
         *  Constant: '<S475>/Constant'
         *  Constant: '<S476>/Constant'
         *  Gain: '<S473>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S473>/Logical Operator'
         *  RelationalOperator: '<S475>/Compare'
         *  RelationalOperator: '<S476>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S473>/Sum'
         *  Sum: '<S473>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_Saturation_n = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_Saturation_n = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S473>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S478>/Add' incorporates:
         *  DiscreteIntegrator: '<S477>/Integrator1'
         *  Sum: '<S477>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_a - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S478>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_lr_idx_1;
        }

        /* End of Signum: '<S478>/Sign' */

        /* Sum: '<S478>/Add2' incorporates:
         *  Abs: '<S478>/Abs'
         *  Gain: '<S478>/Gain'
         *  Gain: '<S478>/Gain1'
         *  Product: '<S478>/Multiply2'
         *  Product: '<S478>/Multiply3'
         *  Sqrt: '<S478>/Sqrt'
         *  Sum: '<S478>/Add1'
         *  Sum: '<S478>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) + FMS_ConstB.d_m) *
                         FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
          rtb_Saturation_n + rtb_Add3_c;

        /* Sum: '<S478>/Add4' */
        rtb_Saturation_n = (rtb_Divide_lr_idx_1 - rtb_a_l) + rtb_Add3_c;

        /* Sum: '<S478>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_ConstB.d_m;

        /* Sum: '<S478>/Subtract1' */
        rtb_Divide_lr_idx_1 -= FMS_ConstB.d_m;

        /* Signum: '<S478>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S478>/Sign1' */

        /* Signum: '<S478>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S478>/Sign2' */

        /* Sum: '<S478>/Add5' incorporates:
         *  Gain: '<S478>/Gain2'
         *  Product: '<S478>/Multiply4'
         *  Sum: '<S478>/Subtract2'
         */
        rtb_a_l += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F * rtb_Saturation_n;

        /* Update for Delay: '<S481>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S477>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S477>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S478>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_m;

        /* Sum: '<S478>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_a_l + FMS_ConstB.d_m;

        /* Signum: '<S478>/Sign5' incorporates:
         *  Signum: '<S478>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Saturation_n = -1.0F;

          /* Signum: '<S478>/Sign6' */
          rtb_Switch2_i = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Saturation_n = 1.0F;

          /* Signum: '<S478>/Sign6' */
          rtb_Switch2_i = 1.0F;
        } else {
          rtb_Saturation_n = rtb_a_l;

          /* Signum: '<S478>/Sign6' */
          rtb_Switch2_i = rtb_a_l;
        }

        /* End of Signum: '<S478>/Sign5' */

        /* Signum: '<S478>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S478>/Sign3' */

        /* Signum: '<S478>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S478>/Sign4' */

        /* Update for DiscreteIntegrator: '<S477>/Integrator' incorporates:
         *  Constant: '<S478>/const'
         *  Gain: '<S478>/Gain3'
         *  Product: '<S478>/Divide'
         *  Product: '<S478>/Multiply5'
         *  Product: '<S478>/Multiply6'
         *  Sum: '<S478>/Subtract4'
         *  Sum: '<S478>/Subtract5'
         *  Sum: '<S478>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_a_l / FMS_ConstB.d_m -
          rtb_Saturation_n) * FMS_ConstB.Gain4_a * ((rtb_Divide_lr_idx_1 -
          rtb_Add3_c) * 0.5F) - rtb_Switch2_i * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Land' incorporates:
           *  ActionPort: '<S344>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S389>/Integrator'
           *  DiscreteIntegrator: '<S389>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Land' incorporates:
         *  ActionPort: '<S344>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S394>/Trigonometric Function1' incorporates:
         *  Gain: '<S393>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S394>/Trigonometric Function' incorporates:
         *  Gain: '<S393>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S394>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S394>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S394>/Gain' incorporates:
         *  Gain: '<S393>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S394>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S394>/Trigonometric Function3' incorporates:
         *  Gain: '<S393>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S394>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S394>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S394>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S387>/Saturation1' */
        rtb_Saturation_n = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Switch2_i = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S391>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S391>/Sum'
         */
        rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Gain_fj = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S391>/Multiply' incorporates:
         *  SignalConversion: '<S391>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Divide_lr_idx_1;
        }

        /* End of Product: '<S391>/Multiply' */

        /* Saturate: '<S387>/Saturation1' incorporates:
         *  Gain: '<S391>/Gain2'
         */
        rtb_a_l = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S344>/Bus Assignment1'
         *  Constant: '<S344>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
         *  Constant: '<S344>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S387>/Saturation1' */
        if (rtb_a_l > rtb_Saturation_n) {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Saturation_n;
        } else if (rtb_a_l < rtb_Switch2_i) {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch2_i;
        } else {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_a_l;
        }

        if (rtb_Add3_c > rtb_Saturation_n) {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        } else if (rtb_Add3_c < rtb_Switch2_i) {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch2_i;
        } else {
          /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S344>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S389>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S390>/Multiply1' incorporates:
         *  Constant: '<S390>/const1'
         *  DiscreteIntegrator: '<S389>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S386>/Switch' incorporates:
         *  Constant: '<S386>/Land_Speed'
         *  Constant: '<S388>/Constant'
         *  Gain: '<S386>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S386>/Logical Operator'
         *  RelationalOperator: '<S388>/Compare'
         *  S-Function (sfix_bitop): '<S386>/cmd_p valid'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_Saturation_n = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_Saturation_n = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S386>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S390>/Add' incorporates:
         *  DiscreteIntegrator: '<S389>/Integrator1'
         *  Sum: '<S389>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_j - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S390>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_lr_idx_1;
        }

        /* End of Signum: '<S390>/Sign' */

        /* Sum: '<S390>/Add2' incorporates:
         *  Abs: '<S390>/Abs'
         *  Gain: '<S390>/Gain'
         *  Gain: '<S390>/Gain1'
         *  Product: '<S390>/Multiply2'
         *  Product: '<S390>/Multiply3'
         *  Sqrt: '<S390>/Sqrt'
         *  Sum: '<S390>/Add1'
         *  Sum: '<S390>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) + FMS_ConstB.d_p) *
                         FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F *
          rtb_Saturation_n + rtb_Add3_c;

        /* Sum: '<S390>/Add4' */
        rtb_Saturation_n = (rtb_Divide_lr_idx_1 - rtb_a_l) + rtb_Add3_c;

        /* Sum: '<S390>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_ConstB.d_p;

        /* Sum: '<S390>/Subtract1' */
        rtb_Divide_lr_idx_1 -= FMS_ConstB.d_p;

        /* Signum: '<S390>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S390>/Sign1' */

        /* Signum: '<S390>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S390>/Sign2' */

        /* Sum: '<S390>/Add5' incorporates:
         *  Gain: '<S390>/Gain2'
         *  Product: '<S390>/Multiply4'
         *  Sum: '<S390>/Subtract2'
         */
        rtb_a_l += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F * rtb_Saturation_n;

        /* Update for DiscreteIntegrator: '<S389>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S389>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S390>/Subtract3' */
        rtb_Add3_c = rtb_a_l - FMS_ConstB.d_p;

        /* Sum: '<S390>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_a_l + FMS_ConstB.d_p;

        /* Signum: '<S390>/Sign5' incorporates:
         *  Signum: '<S390>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Saturation_n = -1.0F;

          /* Signum: '<S390>/Sign6' */
          rtb_Switch2_i = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Saturation_n = 1.0F;

          /* Signum: '<S390>/Sign6' */
          rtb_Switch2_i = 1.0F;
        } else {
          rtb_Saturation_n = rtb_a_l;

          /* Signum: '<S390>/Sign6' */
          rtb_Switch2_i = rtb_a_l;
        }

        /* End of Signum: '<S390>/Sign5' */

        /* Signum: '<S390>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S390>/Sign3' */

        /* Signum: '<S390>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S390>/Sign4' */

        /* Update for DiscreteIntegrator: '<S389>/Integrator' incorporates:
         *  Constant: '<S390>/const'
         *  Gain: '<S390>/Gain3'
         *  Product: '<S390>/Divide'
         *  Product: '<S390>/Multiply5'
         *  Product: '<S390>/Multiply6'
         *  Sum: '<S390>/Subtract4'
         *  Sum: '<S390>/Subtract5'
         *  Sum: '<S390>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_a_l / FMS_ConstB.d_p -
          rtb_Saturation_n) * FMS_ConstB.Gain4_e * ((rtb_Divide_lr_idx_1 -
          rtb_Add3_c) * 0.5F) - rtb_Switch2_i * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Return' incorporates:
           *  ActionPort: '<S345>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S397>/Delay'
           *  Delay: '<S398>/Delay'
           *  Delay: '<S420>/Delay'
           *  DiscreteIntegrator: '<S401>/Integrator'
           *  DiscreteIntegrator: '<S401>/Integrator1'
           *  DiscreteIntegrator: '<S416>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S421>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S468>/Discrete-Time Integrator'
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

          /* End of InitializeConditions for SubSystem: '<S39>/Return' */

          /* SystemReset for IfAction SubSystem: '<S39>/Return' incorporates:
           *  ActionPort: '<S345>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S432>/Motion Status'
           *  Chart: '<S442>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S39>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Return' incorporates:
         *  ActionPort: '<S345>/Action Port'
         */
        /* Delay: '<S420>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_l != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S416>/Switch2' incorporates:
         *  Constant: '<S416>/vel'
         *  Constant: '<S425>/Constant'
         *  RelationalOperator: '<S425>/Compare'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_Switch2_i = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_Switch2_i = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S416>/Switch2' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* RelationalOperator: '<S415>/Compare' incorporates:
         *  Constant: '<S472>/Constant'
         *  DiscreteIntegrator: '<S421>/Discrete-Time Integrator'
         *  RelationalOperator: '<S472>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* DiscreteIntegrator: '<S416>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S442>/Motion State' incorporates:
         *  Constant: '<S442>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S442>/Square'
         *  Math: '<S442>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S442>/Sqrt'
         *  Sum: '<S442>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S441>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S441>/Hold Control' incorporates:
             *  ActionPort: '<S444>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S441>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S441>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S441>/Hold Control' incorporates:
           *  ActionPort: '<S444>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S441>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S441>/Brake Control' incorporates:
           *  ActionPort: '<S443>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S441>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S441>/Move Control' incorporates:
             *  ActionPort: '<S445>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S441>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_j);

            /* End of SystemReset for SubSystem: '<S441>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S441>/Move Control' incorporates:
           *  ActionPort: '<S445>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_a,
                            &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S441>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S441>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S432>/Motion Status' incorporates:
         *  Abs: '<S432>/Abs'
         *  Constant: '<S432>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S431>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S431>/Hold Control' incorporates:
             *  ActionPort: '<S434>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S431>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S431>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S431>/Hold Control' incorporates:
           *  ActionPort: '<S434>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_jj,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S431>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S431>/Brake Control' incorporates:
           *  ActionPort: '<S433>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_jj);

          /* End of Outputs for SubSystem: '<S431>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S431>/Move Control' incorporates:
             *  ActionPort: '<S435>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S431>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S431>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S431>/Move Control' incorporates:
           *  ActionPort: '<S435>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_jj,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S431>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S431>/Switch Case' */

        /* Switch: '<S396>/Switch' incorporates:
         *  Product: '<S420>/Multiply'
         *  Sum: '<S420>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S441>/Saturation1' */
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

          /* End of Saturate: '<S441>/Saturation1' */

          /* Saturate: '<S431>/Saturation1' */
          if (FMS_B.Merge_jj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_jj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_jj;
          }

          /* End of Saturate: '<S431>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S420>/Sum' incorporates:
           *  Delay: '<S420>/Delay'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S469>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S416>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_l_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Add3_c = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S420>/Sum' incorporates:
           *  Delay: '<S420>/Delay'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* Sum: '<S416>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_TmpSignalConversionAtMath_0 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sqrt: '<S428>/Sqrt' incorporates:
           *  Math: '<S428>/Square'
           *  Sum: '<S416>/Sum'
           *  Sum: '<S428>/Sum of Elements'
           */
          rtb_Sqrt_b = sqrtf(rtb_P_l_idx_0 * rtb_P_l_idx_0 +
                             rtb_TmpSignalConversionAtMath_0 *
                             rtb_TmpSignalConversionAtMath_0);

          /* SignalConversion: '<S471>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* SignalConversion: '<S471>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S471>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S470>/Gain' incorporates:
           *  DiscreteIntegrator: '<S468>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S468>/Add'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S471>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S471>/Trigonometric Function1'
           */
          rtb_a_l = arm_cos_f32(rtb_Saturation_n);
          rtb_Transpose[4] = rtb_a_l;

          /* Trigonometry: '<S471>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S471>/Trigonometric Function'
           */
          rtb_Gain_fj = arm_sin_f32(rtb_Saturation_n);

          /* Gain: '<S471>/Gain' incorporates:
           *  Trigonometry: '<S471>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Gain_fj;

          /* SignalConversion: '<S471>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S471>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S471>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Gain_fj;

          /* Trigonometry: '<S471>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_a_l;

          /* Switch: '<S427>/Switch2' incorporates:
           *  Constant: '<S416>/Constant2'
           *  DiscreteIntegrator: '<S416>/Acceleration_Speed'
           *  RelationalOperator: '<S427>/LowerRelop1'
           *  RelationalOperator: '<S427>/UpperRelop'
           *  Switch: '<S427>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_Switch2_i) {
            rtb_Saturation_n = rtb_Switch2_i;
          } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
            /* Switch: '<S427>/Switch' incorporates:
             *  Constant: '<S416>/Constant2'
             */
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_DW.Acceleration_Speed_DSTATE_j;
          }

          /* End of Switch: '<S427>/Switch2' */

          /* Switch: '<S416>/Switch' */
          if (rtb_Sqrt_b > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_Switch2_i;
          } else {
            /* Gain: '<S416>/Gain' */
            rtb_Gain_fj = 0.5F * rtb_Sqrt_b;

            /* Switch: '<S426>/Switch2' incorporates:
             *  Constant: '<S416>/Constant1'
             *  RelationalOperator: '<S426>/LowerRelop1'
             *  RelationalOperator: '<S426>/UpperRelop'
             *  Switch: '<S426>/Switch'
             */
            if (rtb_Gain_fj > rtb_Switch2_i) {
              rtb_Gain_fj = rtb_Switch2_i;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S426>/Switch' incorporates:
                 *  Constant: '<S416>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S426>/Switch2' */
          }

          /* End of Switch: '<S416>/Switch' */

          /* Switch: '<S416>/Switch1' incorporates:
           *  Sum: '<S416>/Sum1'
           */
          if (rtb_Saturation_n - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_Saturation_n;
          }

          /* End of Switch: '<S416>/Switch1' */

          /* Sum: '<S469>/Sum of Elements' incorporates:
           *  Math: '<S469>/Math Function'
           */
          rtb_Saturation_n = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Divide_lr_idx_1 *
            rtb_Divide_lr_idx_1;

          /* Math: '<S469>/Math Function1' incorporates:
           *  Sum: '<S469>/Sum of Elements'
           *
           * About '<S469>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S469>/Math Function1' */

          /* Switch: '<S469>/Switch' incorporates:
           *  Constant: '<S469>/Constant'
           *  Product: '<S469>/Product'
           */
          if (rtb_Saturation_n <= 0.0F) {
            rtb_Add3_c = 0.0F;
            rtb_Divide_lr_idx_1 = 0.0F;
            rtb_Saturation_n = 1.0F;
          }

          /* End of Switch: '<S469>/Switch' */

          /* Product: '<S467>/Multiply2' incorporates:
           *  Product: '<S469>/Divide'
           */
          rtb_a_l = rtb_Add3_c / rtb_Saturation_n * rtb_Gain_fj;
          rtb_Gain_fj *= rtb_Divide_lr_idx_1 / rtb_Saturation_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S422>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S422>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_n = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sqrt_b = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S422>/Divide' incorporates:
           *  Math: '<S423>/Square'
           *  Math: '<S424>/Square'
           *  Sqrt: '<S423>/Sqrt'
           *  Sqrt: '<S424>/Sqrt'
           *  Sum: '<S422>/Sum'
           *  Sum: '<S422>/Sum1'
           *  Sum: '<S423>/Sum of Elements'
           *  Sum: '<S424>/Sum of Elements'
           */
          rtb_Saturation_n = sqrtf(rtb_Saturation_n * rtb_Saturation_n +
            rtb_Sqrt_b * rtb_Sqrt_b) / sqrtf(rtb_Add3_c * rtb_Add3_c +
            rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1);

          /* Saturate: '<S422>/Saturation' */
          if (rtb_Saturation_n > 1.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            if (rtb_Saturation_n < 0.0F) {
              rtb_Saturation_n = 0.0F;
            }
          }

          /* End of Saturate: '<S422>/Saturation' */

          /* Product: '<S420>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S413>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S422>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S413>/Sum2'
           *  Sum: '<S422>/Add'
           *  Sum: '<S422>/Subtract'
           */
          rtb_a_l = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_n +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S413>/Saturation1' incorporates:
           *  Product: '<S420>/Multiply'
           */
          if (rtb_a_l > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_a_l < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_a_l;
          }

          /* End of Saturate: '<S413>/Saturation1' */
        }

        /* End of Switch: '<S396>/Switch' */

        /* Delay: '<S398>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S401>/Integrator1' incorporates:
         *  Delay: '<S398>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S405>/Rem' incorporates:
         *  Constant: '<S405>/Constant1'
         *  DiscreteIntegrator: '<S401>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S400>/Sum'
         */
        rtb_Add3_c = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                             6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S405>/Switch' incorporates:
         *  Abs: '<S405>/Abs'
         *  Constant: '<S405>/Constant'
         *  Constant: '<S406>/Constant'
         *  Product: '<S405>/Multiply'
         *  RelationalOperator: '<S406>/Compare'
         *  Sum: '<S405>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S405>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          } else {
            rtb_Divide_lr_idx_1 = rtb_Add3_c;
          }

          /* End of Signum: '<S405>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Divide_lr_idx_1;
        }

        /* End of Switch: '<S405>/Switch' */

        /* Gain: '<S400>/Gain2' */
        rtb_Add3_c *= FMS_PARAM.YAW_P;

        /* Saturate: '<S400>/Saturation' */
        if (rtb_Add3_c > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Add3_c = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Add3_c < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Add3_c = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S400>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S345>/Bus Assignment1'
         *  Constant: '<S345>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S345>/Bus Assignment1' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Add3_c;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S462>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S462>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S460>/Sum of Elements'
         */
        rtb_Saturation_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S462>/Math Function1' incorporates:
         *  Sum: '<S462>/Sum of Elements'
         *
         * About '<S462>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Add3_c = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S462>/Math Function1' */

        /* Switch: '<S462>/Switch' incorporates:
         *  Constant: '<S462>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S462>/Product'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (rtb_Add3_c > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMath_c[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Add3_c;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S462>/Switch' */

        /* Delay: '<S397>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_px[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_px[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S345>/Sum' incorporates:
         *  Delay: '<S397>/Delay'
         *  MATLAB Function: '<S418>/OutRegionRegWP'
         *  MATLAB Function: '<S418>/SearchL1RefWP'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_px[0];
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_px[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S412>/Sum of Elements' incorporates:
         *  Math: '<S412>/Math Function'
         *  Sum: '<S345>/Sum'
         */
        rtb_Divide_lr_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_P_l_idx_0 * rtb_P_l_idx_0;

        /* Math: '<S412>/Math Function1' incorporates:
         *  Sum: '<S412>/Sum of Elements'
         *
         * About '<S412>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S412>/Math Function1' */

        /* Switch: '<S412>/Switch' incorporates:
         *  Constant: '<S412>/Constant'
         *  Product: '<S412>/Product'
         *  Sum: '<S345>/Sum'
         */
        if (rtb_Add3_c > 0.0F) {
          rtb_a_l = rtb_TmpSignalConversionAtMath_0;
          rtb_Gain_fj = rtb_P_l_idx_0;
          rtb_MathFunction_f_idx_2 = rtb_Add3_c;
        } else {
          rtb_a_l = 0.0F;
          rtb_Gain_fj = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S412>/Switch' */

        /* Product: '<S462>/Divide' */
        rtb_Sum_ff[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S465>/Sum of Elements' incorporates:
         *  Math: '<S465>/Math Function'
         *  SignalConversion: '<S465>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_1 = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] *
          rtb_Sum_ff[0];

        /* Math: '<S465>/Math Function1' incorporates:
         *  Sum: '<S465>/Sum of Elements'
         *
         * About '<S465>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S465>/Math Function1' */

        /* Switch: '<S465>/Switch' incorporates:
         *  Constant: '<S465>/Constant'
         *  Product: '<S465>/Product'
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

        /* End of Switch: '<S465>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S418>/NearbyRefWP' incorporates:
         *  Constant: '<S345>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_ff, &rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* MATLAB Function: '<S418>/SearchL1RefWP' incorporates:
         *  Constant: '<S345>/L1'
         *  Delay: '<S397>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        B = (rtb_P_l_idx_0 * (FMS_DW.Delay_DSTATE_px[0] - FMS_U.INS_Out.x_R) +
             rtb_TmpSignalConversionAtMath_0 * (FMS_DW.Delay_DSTATE_px[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_px[0] * FMS_DW.Delay_DSTATE_px[0]) +
                       FMS_DW.Delay_DSTATE_px[1] * FMS_DW.Delay_DSTATE_px[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_px[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_px[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Divide_lr_idx_1);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
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
          rtb_Sqrt_b = rtb_P_l_idx_0 * rtb_Add3_c + FMS_DW.Delay_DSTATE_px[0];
          rtb_MathFunction_iq_idx_1 = rtb_TmpSignalConversionAtMath_0 *
            rtb_Add3_c + FMS_DW.Delay_DSTATE_px[1];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S418>/OutRegionRegWP' incorporates:
         *  Delay: '<S397>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Divide_lr_idx_1 = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_px[1]) *
          rtb_TmpSignalConversionAtMath_0 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE_px[0]) * rtb_P_l_idx_0) / (rtb_P_l_idx_0 *
          rtb_P_l_idx_0 + rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Divide_lr_idx_1 <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Divide_lr_idx_1 >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_l_idx_0 = FMS_DW.Delay_DSTATE_px[0];
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_P_l_idx_0 = rtb_Divide_lr_idx_1 * rtb_P_l_idx_0 +
            FMS_DW.Delay_DSTATE_px[0];
        }

        /* Switch: '<S418>/Switch1' incorporates:
         *  Constant: '<S455>/Constant'
         *  RelationalOperator: '<S455>/Compare'
         */
        if (rtb_Rem_p <= 0.0F) {
          /* Switch: '<S418>/Switch' incorporates:
           *  Constant: '<S454>/Constant'
           *  MATLAB Function: '<S418>/SearchL1RefWP'
           *  RelationalOperator: '<S454>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_Sqrt_b;
            rtb_Sum_ff[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S418>/OutRegionRegWP' incorporates:
             *  Delay: '<S397>/Delay'
             *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_ff[1] = FMS_DW.Delay_DSTATE_px[1];
            } else if (rtb_LogicalOperator_es) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else {
              rtb_Sum_ff[1] = rtb_Divide_lr_idx_1 *
                rtb_TmpSignalConversionAtMath_0 + FMS_DW.Delay_DSTATE_px[1];
            }
          }

          /* End of Switch: '<S418>/Switch' */
        }

        /* End of Switch: '<S418>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S419>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Rem_p = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Rem_p;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Rem_p * rtb_Rem_p;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S419>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S463>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Rem_p = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S463>/Math Function' incorporates:
         *  Math: '<S461>/Square'
         */
        rtb_Divide_lr_idx_1 = rtb_Rem_p * rtb_Rem_p;

        /* Sum: '<S463>/Sum of Elements' incorporates:
         *  Math: '<S463>/Math Function'
         */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S463>/Math Function1' incorporates:
         *  Sum: '<S463>/Sum of Elements'
         *
         * About '<S463>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S463>/Math Function1' */

        /* Switch: '<S463>/Switch' incorporates:
         *  Constant: '<S463>/Constant'
         *  Product: '<S463>/Product'
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

        /* End of Switch: '<S463>/Switch' */

        /* Product: '<S463>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S466>/Sum of Elements' incorporates:
         *  Math: '<S466>/Math Function'
         *  SignalConversion: '<S466>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add3_c = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S466>/Math Function1' incorporates:
         *  Sum: '<S466>/Sum of Elements'
         *
         * About '<S466>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S466>/Math Function1' */

        /* Switch: '<S466>/Switch' incorporates:
         *  Constant: '<S466>/Constant'
         *  Product: '<S466>/Product'
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

        /* End of Switch: '<S466>/Switch' */

        /* Product: '<S466>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S461>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S412>/Divide' */
        rtb_Sqrt_b = rtb_a_l / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S466>/Divide' incorporates:
         *  Product: '<S465>/Divide'
         */
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S465>/Divide' */
        rtb_Rem_p = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S412>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Gain_fj / rtb_MathFunction_f_idx_2;

        /* Sqrt: '<S460>/Sqrt' */
        rtb_Add3_c = sqrtf(rtb_Saturation_n);

        /* Gain: '<S419>/Gain' incorporates:
         *  Math: '<S419>/Square'
         */
        rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c * 2.0F;

        /* Sum: '<S464>/Subtract' incorporates:
         *  Product: '<S464>/Multiply'
         *  Product: '<S464>/Multiply1'
         */
        rtb_Add3_c = rtb_TmpSignalConversionAtMath_0 * rtb_Rem_p - rtb_P_l_idx_0
          * rtb_Sum_ff[0];

        /* Signum: '<S459>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S459>/Sign1' */

        /* Switch: '<S459>/Switch2' incorporates:
         *  Constant: '<S459>/Constant4'
         */
        if (rtb_Add3_c == 0.0F) {
          rtb_Add3_c = 1.0F;
        }

        /* End of Switch: '<S459>/Switch2' */

        /* DotProduct: '<S459>/Dot Product' */
        rtb_Rem_p = rtb_Sum_ff[0] * rtb_TmpSignalConversionAtMath_0 + rtb_Rem_p *
          rtb_P_l_idx_0;

        /* Trigonometry: '<S459>/Acos' incorporates:
         *  DotProduct: '<S459>/Dot Product'
         */
        if (rtb_Rem_p > 1.0F) {
          rtb_Rem_p = 1.0F;
        } else {
          if (rtb_Rem_p < -1.0F) {
            rtb_Rem_p = -1.0F;
          }
        }

        /* Product: '<S459>/Multiply' incorporates:
         *  Trigonometry: '<S459>/Acos'
         */
        rtb_Add3_c *= acosf(rtb_Rem_p);

        /* Saturate: '<S419>/Saturation' */
        if (rtb_Add3_c > 1.57079637F) {
          rtb_Add3_c = 1.57079637F;
        } else {
          if (rtb_Add3_c < -1.57079637F) {
            rtb_Add3_c = -1.57079637F;
          }
        }

        /* End of Saturate: '<S419>/Saturation' */

        /* Product: '<S419>/Divide' incorporates:
         *  Constant: '<S345>/L1'
         *  Constant: '<S419>/Constant'
         *  MinMax: '<S419>/Max'
         *  MinMax: '<S419>/Min'
         *  Product: '<S419>/Multiply1'
         *  Sqrt: '<S461>/Sqrt'
         *  Sum: '<S461>/Sum of Elements'
         *  Trigonometry: '<S419>/Sin'
         */
        rtb_Gain_fj = arm_sin_f32(rtb_Add3_c) * rtb_Saturation_n / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Divide_lr_idx_1 +
             rtb_TmpSignalConversionAtDela_a[0]), 0.5F));

        /* Sum: '<S410>/Subtract' incorporates:
         *  Product: '<S410>/Multiply'
         *  Product: '<S410>/Multiply1'
         */
        rtb_MathFunction_f_idx_2 = rtb_Sqrt_b * FMS_ConstB.Divide_d[1] -
          rtb_MathFunction_iq_idx_1 * FMS_ConstB.Divide_d[0];

        /* Signum: '<S399>/Sign1' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_2 > 0.0F) {
            rtb_MathFunction_f_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S399>/Sign1' */

        /* Switch: '<S399>/Switch2' incorporates:
         *  Constant: '<S399>/Constant4'
         */
        if (rtb_MathFunction_f_idx_2 == 0.0F) {
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S399>/Switch2' */

        /* DotProduct: '<S399>/Dot Product' */
        rtb_a_l = FMS_ConstB.Divide_d[0] * rtb_Sqrt_b + FMS_ConstB.Divide_d[1] *
          rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S399>/Acos' incorporates:
         *  DotProduct: '<S399>/Dot Product'
         */
        if (rtb_a_l > 1.0F) {
          rtb_a_l = 1.0F;
        } else {
          if (rtb_a_l < -1.0F) {
            rtb_a_l = -1.0F;
          }
        }

        /* Product: '<S399>/Multiply' incorporates:
         *  Trigonometry: '<S399>/Acos'
         */
        rtb_MathFunction_f_idx_2 *= acosf(rtb_a_l);

        /* Math: '<S402>/Rem' incorporates:
         *  Constant: '<S402>/Constant1'
         *  Delay: '<S398>/Delay'
         *  Sum: '<S398>/Sum2'
         */
        rtb_Add3_c = rt_remf(rtb_MathFunction_f_idx_2 - FMS_DW.Delay_DSTATE_a,
                             6.28318548F);

        /* Switch: '<S402>/Switch' incorporates:
         *  Abs: '<S402>/Abs'
         *  Constant: '<S402>/Constant'
         *  Constant: '<S408>/Constant'
         *  Product: '<S402>/Multiply'
         *  RelationalOperator: '<S408>/Compare'
         *  Sum: '<S402>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S402>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          } else {
            rtb_Divide_lr_idx_1 = rtb_Add3_c;
          }

          /* End of Signum: '<S402>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Divide_lr_idx_1;
        }

        /* End of Switch: '<S402>/Switch' */

        /* Sum: '<S398>/Sum' incorporates:
         *  Delay: '<S398>/Delay'
         */
        rtb_Divide_lr_idx_1 = rtb_Add3_c + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S407>/Multiply1' incorporates:
         *  Constant: '<S407>/const1'
         *  DiscreteIntegrator: '<S401>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S407>/Add' incorporates:
         *  DiscreteIntegrator: '<S401>/Integrator1'
         *  Sum: '<S401>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_e - rtb_Divide_lr_idx_1)
          + rtb_Add3_c;

        /* Signum: '<S407>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_lr_idx_1;
        }

        /* End of Signum: '<S407>/Sign' */

        /* Sum: '<S407>/Add2' incorporates:
         *  Abs: '<S407>/Abs'
         *  Gain: '<S407>/Gain'
         *  Gain: '<S407>/Gain1'
         *  Product: '<S407>/Multiply2'
         *  Product: '<S407>/Multiply3'
         *  Sqrt: '<S407>/Sqrt'
         *  Sum: '<S407>/Add1'
         *  Sum: '<S407>/Subtract'
         */
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) + FMS_ConstB.d_l) *
                           FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Saturation_n + rtb_Add3_c;

        /* Sum: '<S407>/Add4' */
        rtb_Saturation_n = (rtb_Divide_lr_idx_1 - rtb_Rem_p) + rtb_Add3_c;

        /* Sum: '<S407>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_ConstB.d_l;

        /* Sum: '<S407>/Subtract1' */
        rtb_Divide_lr_idx_1 -= FMS_ConstB.d_l;

        /* Signum: '<S407>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S407>/Sign1' */

        /* Signum: '<S407>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S407>/Sign2' */

        /* Sum: '<S407>/Add5' incorporates:
         *  Gain: '<S407>/Gain2'
         *  Product: '<S407>/Multiply4'
         *  Sum: '<S407>/Subtract2'
         */
        rtb_Rem_p += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F *
          rtb_Saturation_n;

        /* Sum: '<S407>/Add6' */
        rtb_Add3_c = rtb_Rem_p + FMS_ConstB.d_l;

        /* Sum: '<S407>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_Rem_p - FMS_ConstB.d_l;

        /* Product: '<S407>/Divide' */
        rtb_Sqrt_b = rtb_Rem_p / FMS_ConstB.d_l;

        /* Signum: '<S407>/Sign5' incorporates:
         *  Signum: '<S407>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;

          /* Signum: '<S407>/Sign6' */
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;

          /* Signum: '<S407>/Sign6' */
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Rem_p;

          /* Signum: '<S407>/Sign6' */
          rtb_Saturation_n = rtb_Rem_p;
        }

        /* End of Signum: '<S407>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S398>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_2 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S403>/Rem' incorporates:
         *  Constant: '<S403>/Constant1'
         */
        rtb_Rem_p = rt_remf(rtb_MathFunction_f_idx_2, 6.28318548F);

        /* Switch: '<S403>/Switch' incorporates:
         *  Abs: '<S403>/Abs'
         *  Constant: '<S403>/Constant'
         *  Constant: '<S409>/Constant'
         *  Product: '<S403>/Multiply'
         *  RelationalOperator: '<S409>/Compare'
         *  Sum: '<S403>/Add'
         */
        if (fabsf(rtb_Rem_p) > 3.14159274F) {
          /* Signum: '<S403>/Sign' */
          if (rtb_Rem_p < 0.0F) {
            rtb_a_l = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_a_l = 1.0F;
          } else {
            rtb_a_l = rtb_Rem_p;
          }

          /* End of Signum: '<S403>/Sign' */
          rtb_Rem_p -= 6.28318548F * rtb_a_l;
        }

        /* End of Switch: '<S403>/Switch' */

        /* Abs: '<S396>/Abs' */
        rtb_Rem_p = fabsf(rtb_Rem_p);

        /* Update for Delay: '<S420>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S421>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S414>/Constant'
         *  RelationalOperator: '<S414>/Compare'
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

        /* End of Update for DiscreteIntegrator: '<S421>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S416>/Acceleration_Speed' incorporates:
         *  Constant: '<S416>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Product: '<S420>/Divide1' */
        rtb_a_l = rtb_Gain_fj / rtb_Switch2_i;

        /* Saturate: '<S420>/Saturation' */
        if (rtb_a_l > 0.314159274F) {
          rtb_a_l = 0.314159274F;
        } else {
          if (rtb_a_l < -0.314159274F) {
            rtb_a_l = -0.314159274F;
          }
        }

        /* End of Saturate: '<S420>/Saturation' */

        /* Update for DiscreteIntegrator: '<S468>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_a_l;

        /* Update for Delay: '<S398>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S401>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S401>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S397>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S407>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S407>/Sign3' */

        /* Signum: '<S407>/Sign4' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S407>/Sign4' */

        /* Update for DiscreteIntegrator: '<S401>/Integrator' incorporates:
         *  Constant: '<S407>/const'
         *  Gain: '<S407>/Gain3'
         *  Product: '<S407>/Multiply5'
         *  Product: '<S407>/Multiply6'
         *  Sum: '<S407>/Subtract4'
         *  Sum: '<S407>/Subtract5'
         *  Sum: '<S407>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1)
          * FMS_ConstB.Gain4_n * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F) -
          rtb_Saturation_n * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S401>/Integrator' */
        /* End of Outputs for SubSystem: '<S39>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S39>/Hold' incorporates:
           *  ActionPort: '<S343>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S352>/Motion Status'
           *  Chart: '<S362>/Motion State'
           *  Chart: '<S374>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S39>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Hold' incorporates:
         *  ActionPort: '<S343>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S352>/Motion Status' incorporates:
         *  Abs: '<S352>/Abs'
         *  Constant: '<S352>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S362>/Motion State' incorporates:
         *  Abs: '<S362>/Abs'
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

        /* End of Chart: '<S362>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S374>/Motion State' incorporates:
         *  Constant: '<S374>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S374>/Square'
         *  Math: '<S374>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S374>/Sqrt'
         *  Sum: '<S374>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S373>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S373>/Hold Control' incorporates:
             *  ActionPort: '<S376>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S373>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S373>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S373>/Hold Control' incorporates:
           *  ActionPort: '<S376>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S373>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S373>/Brake Control' incorporates:
           *  ActionPort: '<S375>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S373>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S373>/Move Control' incorporates:
             *  ActionPort: '<S377>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S373>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S373>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S373>/Move Control' incorporates:
           *  ActionPort: '<S377>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S373>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S373>/Switch Case' */

        /* SwitchCase: '<S351>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S351>/Hold Control' incorporates:
             *  ActionPort: '<S354>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S351>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S351>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S351>/Hold Control' incorporates:
           *  ActionPort: '<S354>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S351>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S351>/Brake Control' incorporates:
           *  ActionPort: '<S353>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S351>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S351>/Move Control' incorporates:
             *  ActionPort: '<S355>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S351>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S351>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S351>/Move Control' incorporates:
           *  ActionPort: '<S355>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S351>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S351>/Switch Case' */

        /* SwitchCase: '<S361>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S361>/Hold Control' incorporates:
             *  ActionPort: '<S364>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S361>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S361>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S361>/Hold Control' incorporates:
           *  ActionPort: '<S364>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S361>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S361>/Brake Control' incorporates:
           *  ActionPort: '<S363>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S361>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S361>/Move Control' incorporates:
             *  ActionPort: '<S365>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S361>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S361>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S361>/Move Control' incorporates:
           *  ActionPort: '<S365>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S361>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S361>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S343>/Bus Assignment'
         *  Constant: '<S343>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S343>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S361>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S361>/Saturation' */

        /* Saturate: '<S373>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S373>/Saturation1' */

        /* Saturate: '<S351>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S343>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S351>/Saturation1' */
        /* End of Outputs for SubSystem: '<S39>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S39>/Unknown' incorporates:
         *  ActionPort: '<S347>/Action Port'
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
       *  Math: '<S221>/Square'
       *  Math: '<S223>/Math Function'
       *  Sum: '<S179>/Subtract'
       *  Sum: '<S236>/Sum1'
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
        /* Gain: '<S320>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S323>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S324>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S324>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S324>/Multiply1' incorporates:
         *  Product: '<S324>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S324>/Divide' incorporates:
         *  Constant: '<S324>/Constant'
         *  Constant: '<S324>/R'
         *  Sqrt: '<S324>/Sqrt'
         *  Sum: '<S324>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S324>/Product3' incorporates:
         *  Constant: '<S324>/Constant1'
         *  Product: '<S324>/Multiply1'
         *  Sum: '<S324>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S324>/Multiply2' incorporates:
         *  Trigonometry: '<S324>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S323>/Sum' incorporates:
         *  Gain: '<S320>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S328>/Abs' incorporates:
         *  Abs: '<S331>/Abs1'
         *  Switch: '<S328>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S328>/Switch1' incorporates:
         *  Abs: '<S328>/Abs'
         *  Bias: '<S328>/Bias2'
         *  Bias: '<S328>/Bias3'
         *  Constant: '<S325>/Constant'
         *  Constant: '<S325>/Constant1'
         *  Constant: '<S330>/Constant'
         *  Gain: '<S328>/Gain1'
         *  Product: '<S328>/Multiply'
         *  RelationalOperator: '<S330>/Compare'
         *  Switch: '<S325>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S331>/Switch1' incorporates:
           *  Bias: '<S331>/Bias2'
           *  Bias: '<S331>/Bias3'
           *  Constant: '<S331>/Constant'
           *  Constant: '<S332>/Constant'
           *  Math: '<S331>/Math Function'
           *  RelationalOperator: '<S332>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S331>/Switch1' */

          /* Signum: '<S328>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S328>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S325>/Sum' incorporates:
         *  Gain: '<S320>/Gain1'
         *  Gain: '<S320>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S323>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S323>/Multiply' incorporates:
         *  Gain: '<S323>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S327>/Switch1' incorporates:
         *  Abs: '<S327>/Abs1'
         *  Bias: '<S327>/Bias2'
         *  Bias: '<S327>/Bias3'
         *  Constant: '<S327>/Constant'
         *  Constant: '<S329>/Constant'
         *  Math: '<S327>/Math Function'
         *  RelationalOperator: '<S329>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S327>/Switch1' */

        /* Product: '<S323>/Multiply' incorporates:
         *  Gain: '<S323>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S314>/Trigonometric Function1' incorporates:
         *  Gain: '<S313>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S314>/Trigonometric Function' incorporates:
         *  Gain: '<S313>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S314>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S314>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S314>/Gain' incorporates:
         *  Gain: '<S313>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S314>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S314>/Trigonometric Function3' incorporates:
         *  Gain: '<S313>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S314>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S314>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S314>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S298>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S303>/Multiply1'
         *  Product: '<S304>/Multiply3'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Switch: '<S307>/Switch' incorporates:
           *  Constant: '<S322>/Constant'
           *  DataTypeConversion: '<S320>/Data Type Conversion1'
           *  Product: '<S326>/Multiply1'
           *  Product: '<S326>/Multiply2'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/lat_cmd valid'
           *  Sum: '<S326>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S303>/Multiply' incorporates:
           *  Constant: '<S311>/Constant'
           *  Constant: '<S312>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S302>/Logical Operator'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  S-Function (sfix_bitop): '<S302>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S303>/Sum1'
           */
          rtb_Divide_lr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.x_R : 0.0F;

          /* Switch: '<S307>/Switch' incorporates:
           *  Constant: '<S322>/Constant'
           *  DataTypeConversion: '<S320>/Data Type Conversion1'
           *  Product: '<S326>/Multiply3'
           *  Product: '<S326>/Multiply4'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/lon_cmd valid'
           *  Sum: '<S326>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S303>/Multiply' incorporates:
           *  Constant: '<S311>/Constant'
           *  Constant: '<S312>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S302>/Logical Operator'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  S-Function (sfix_bitop): '<S302>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S303>/Sum1'
           */
          rtb_Gain_fj = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.y_R : 0.0F;

          /* Switch: '<S307>/Switch' incorporates:
           *  Constant: '<S322>/Constant'
           *  DataTypeConversion: '<S320>/Data Type Conversion'
           *  DataTypeConversion: '<S320>/Data Type Conversion1'
           *  Gain: '<S320>/Gain2'
           *  Gain: '<S323>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S323>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S303>/Multiply' incorporates:
           *  Constant: '<S311>/Constant'
           *  Constant: '<S312>/Constant'
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S302>/Logical Operator'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  S-Function (sfix_bitop): '<S302>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S303>/Sum1'
           */
          rtb_Sqrt_b = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_n -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Gain_fj +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 1:
          /* Switch: '<S307>/Switch' incorporates:
           *  Constant: '<S322>/Constant'
           *  DataTypeConversion: '<S320>/Data Type Conversion1'
           *  Product: '<S326>/Multiply1'
           *  Product: '<S326>/Multiply2'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/lat_cmd valid'
           *  Sum: '<S326>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S303>/Multiply' incorporates:
           *  Constant: '<S311>/Constant'
           *  Constant: '<S312>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S302>/Logical Operator'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  S-Function (sfix_bitop): '<S302>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S303>/Sum1'
           */
          rtb_Divide_lr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.x_R : 0.0F;

          /* Switch: '<S307>/Switch' incorporates:
           *  Constant: '<S322>/Constant'
           *  DataTypeConversion: '<S320>/Data Type Conversion1'
           *  Product: '<S326>/Multiply3'
           *  Product: '<S326>/Multiply4'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/lon_cmd valid'
           *  Sum: '<S326>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S303>/Multiply' incorporates:
           *  Constant: '<S311>/Constant'
           *  Constant: '<S312>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S302>/Logical Operator'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  S-Function (sfix_bitop): '<S302>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S303>/Sum1'
           */
          rtb_Gain_fj = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.y_R : 0.0F;

          /* Switch: '<S307>/Switch' incorporates:
           *  Constant: '<S322>/Constant'
           *  DataTypeConversion: '<S320>/Data Type Conversion'
           *  DataTypeConversion: '<S320>/Data Type Conversion1'
           *  Gain: '<S320>/Gain2'
           *  Gain: '<S323>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S323>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S303>/Multiply' incorporates:
           *  Constant: '<S311>/Constant'
           *  Constant: '<S312>/Constant'
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S302>/Logical Operator'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  S-Function (sfix_bitop): '<S302>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S303>/Sum1'
           */
          rtb_Sqrt_b = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_n -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Gain_fj +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 2:
          /* SignalConversion: '<S317>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S317>/Constant4'
           */
          rtb_VectorConcatenate_ia[5] = 0.0F;

          /* Trigonometry: '<S317>/Trigonometric Function3' incorporates:
           *  DataStoreRead: '<S304>/Data Store Read'
           *  Gain: '<S315>/Gain'
           *  Trigonometry: '<S317>/Trigonometric Function1'
           */
          rtb_Add3_c = arm_cos_f32(-FMS_DW.home[3]);
          rtb_VectorConcatenate_ia[4] = rtb_Add3_c;

          /* Trigonometry: '<S317>/Trigonometric Function2' incorporates:
           *  DataStoreRead: '<S304>/Data Store Read'
           *  Gain: '<S315>/Gain'
           *  Trigonometry: '<S317>/Trigonometric Function'
           */
          rtb_Divide_lr_idx_1 = arm_sin_f32(-FMS_DW.home[3]);

          /* Gain: '<S317>/Gain' incorporates:
           *  Trigonometry: '<S317>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ia[3] = -rtb_Divide_lr_idx_1;

          /* SignalConversion: '<S317>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S317>/Constant3'
           */
          rtb_VectorConcatenate_ia[2] = 0.0F;

          /* Trigonometry: '<S317>/Trigonometric Function' */
          rtb_VectorConcatenate_ia[1] = rtb_Divide_lr_idx_1;

          /* Trigonometry: '<S317>/Trigonometric Function1' */
          rtb_VectorConcatenate_ia[0] = rtb_Add3_c;

          /* SignalConversion: '<S317>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[6] = FMS_ConstB.VectorConcatenate3_ny[0];

          /* SignalConversion: '<S318>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ei[6] = FMS_ConstB.VectorConcatenate3_e0[0];

          /* SignalConversion: '<S317>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[7] = FMS_ConstB.VectorConcatenate3_ny[1];

          /* SignalConversion: '<S318>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ei[7] = FMS_ConstB.VectorConcatenate3_e0[1];

          /* SignalConversion: '<S317>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[8] = FMS_ConstB.VectorConcatenate3_ny[2];

          /* SignalConversion: '<S318>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ei[8] = FMS_ConstB.VectorConcatenate3_e0[2];

          /* SignalConversion: '<S318>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S318>/Constant4'
           */
          rtb_VectorConcatenate_ei[5] = 0.0F;

          /* Gain: '<S316>/Gain' incorporates:
           *  DataStoreRead: '<S304>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S304>/Subtract'
           */
          rtb_Divide_lr_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S318>/Trigonometric Function3' incorporates:
           *  Gain: '<S316>/Gain'
           *  Trigonometry: '<S318>/Trigonometric Function1'
           */
          rtb_Add3_c = arm_cos_f32(rtb_Divide_lr_idx_1);
          rtb_VectorConcatenate_ei[4] = rtb_Add3_c;

          /* Trigonometry: '<S318>/Trigonometric Function2' incorporates:
           *  Gain: '<S316>/Gain'
           *  Trigonometry: '<S318>/Trigonometric Function'
           */
          rtb_Divide_lr_idx_1 = arm_sin_f32(rtb_Divide_lr_idx_1);

          /* Gain: '<S318>/Gain' incorporates:
           *  Trigonometry: '<S318>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ei[3] = -rtb_Divide_lr_idx_1;

          /* SignalConversion: '<S318>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S318>/Constant3'
           */
          rtb_VectorConcatenate_ei[2] = 0.0F;

          /* Trigonometry: '<S318>/Trigonometric Function' */
          rtb_VectorConcatenate_ei[1] = rtb_Divide_lr_idx_1;

          /* Trigonometry: '<S318>/Trigonometric Function1' */
          rtb_VectorConcatenate_ei[0] = rtb_Add3_c;

          /* RelationalOperator: '<S322>/Compare' incorporates:
           *  Constant: '<S322>/Constant'
           *  S-Function (sfix_bitop): '<S319>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S319>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S319>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S320>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S320>/Data Type Conversion'
           *  Gain: '<S320>/Gain2'
           *  Gain: '<S323>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S326>/Multiply1'
           *  Product: '<S326>/Multiply2'
           *  Product: '<S326>/Multiply3'
           *  Product: '<S326>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S323>/Sum1'
           *  Sum: '<S326>/Sum2'
           *  Sum: '<S326>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S307>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S311>/Compare' incorporates:
           *  Constant: '<S311>/Constant'
           *  S-Function (sfix_bitop): '<S302>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S312>/Compare' incorporates:
           *  Constant: '<S312>/Constant'
           *  S-Function (sfix_bitop): '<S302>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S304>/Sum2' incorporates:
             *  Product: '<S304>/Multiply2'
             *  Switch: '<S307>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Saturation_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Saturation_n = tmp_0[rtb_Compare_bv_0];
            }

            /* Product: '<S304>/Multiply' incorporates:
             *  Gain: '<S308>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S302>/Logical Operator'
             *  Product: '<S304>/Multiply2'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Sum: '<S304>/Sum2'
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
          /* SignalConversion: '<S310>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[6] = FMS_ConstB.VectorConcatenate3_n[0];
          rtb_VectorConcatenate_ia[7] = FMS_ConstB.VectorConcatenate3_n[1];
          rtb_VectorConcatenate_ia[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S310>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S310>/Constant4'
           */
          rtb_VectorConcatenate_ia[5] = 0.0F;

          /* Trigonometry: '<S310>/Trigonometric Function3' incorporates:
           *  Gain: '<S309>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_VectorConcatenate_ia[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S310>/Gain' incorporates:
           *  Gain: '<S309>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S310>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ia[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S310>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S310>/Constant3'
           */
          rtb_VectorConcatenate_ia[2] = 0.0F;

          /* Trigonometry: '<S310>/Trigonometric Function' incorporates:
           *  Gain: '<S309>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_VectorConcatenate_ia[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S310>/Trigonometric Function1' incorporates:
           *  Gain: '<S309>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_VectorConcatenate_ia[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S319>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S302>/lat_cmd valid'
           */
          tmp_6 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S322>/Compare' incorporates:
           *  Constant: '<S322>/Constant'
           *  S-Function (sfix_bitop): '<S319>/lat_cmd valid'
           */
          tmp[0] = (tmp_6 > 0U);

          /* S-Function (sfix_bitop): '<S319>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S302>/lon_cmd valid'
           */
          tmp_7 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S322>/Compare' incorporates:
           *  Constant: '<S322>/Constant'
           *  S-Function (sfix_bitop): '<S319>/lon_cmd valid'
           */
          tmp[1] = (tmp_7 > 0U);

          /* S-Function (sfix_bitop): '<S319>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S302>/alt_cmd valid'
           */
          tmp_8 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S322>/Compare' incorporates:
           *  Constant: '<S322>/Constant'
           *  S-Function (sfix_bitop): '<S319>/alt_cmd valid'
           */
          tmp[2] = (tmp_8 > 0U);

          /* DataTypeConversion: '<S320>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S320>/Data Type Conversion'
           *  Gain: '<S320>/Gain2'
           *  Gain: '<S323>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S326>/Multiply1'
           *  Product: '<S326>/Multiply2'
           *  Product: '<S326>/Multiply3'
           *  Product: '<S326>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S323>/Sum1'
           *  Sum: '<S326>/Sum2'
           *  Sum: '<S326>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S307>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S311>/Compare' incorporates:
           *  Constant: '<S311>/Constant'
           *  S-Function (sfix_bitop): '<S302>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S302>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S312>/Compare' incorporates:
           *  Constant: '<S312>/Constant'
           */
          tmp_2[0] = (tmp_6 > 0U);
          tmp_2[1] = (tmp_7 > 0U);
          tmp_2[2] = (tmp_8 > 0U);

          /* Sum: '<S300>/Sum2' incorporates:
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S302>/Logical Operator'
           *  Product: '<S300>/Multiply'
           *  Product: '<S300>/Multiply2'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S307>/Switch' incorporates:
             *  Product: '<S300>/Multiply2'
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

          /* End of Sum: '<S300>/Sum2' */
          break;
        }

        /* End of MultiPortSwitch: '<S298>/Index Vector' */

        /* Trigonometry: '<S244>/Trigonometric Function1' incorporates:
         *  Gain: '<S243>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S244>/Trigonometric Function' incorporates:
         *  Gain: '<S243>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S244>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S244>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S244>/Gain' incorporates:
         *  Gain: '<S243>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S244>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S244>/Trigonometric Function3' incorporates:
         *  Gain: '<S243>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S244>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S244>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S244>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S233>/Index Vector' incorporates:
         *  Constant: '<S242>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S233>/Multiply'
         *  Product: '<S240>/Multiply'
         *  Product: '<S241>/Multiply3'
         *  RelationalOperator: '<S242>/Compare'
         *  S-Function (sfix_bitop): '<S239>/ax_cmd valid'
         *  S-Function (sfix_bitop): '<S239>/ay_cmd valid'
         *  S-Function (sfix_bitop): '<S239>/az_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S233>/Multiply' incorporates:
           *  Constant: '<S242>/Constant'
           *  RelationalOperator: '<S242>/Compare'
           *  S-Function (sfix_bitop): '<S239>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S239>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S239>/az_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Gain_fj = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Gain_fj +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 1:
          /* Product: '<S233>/Multiply' incorporates:
           *  Constant: '<S242>/Constant'
           *  RelationalOperator: '<S242>/Compare'
           *  S-Function (sfix_bitop): '<S239>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S239>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S239>/az_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Gain_fj = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Gain_fj +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 2:
          /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S246>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S245>/Gain' incorporates:
           *  DataStoreRead: '<S241>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S241>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S246>/Trigonometric Function3' incorporates:
           *  Gain: '<S245>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Add3_c);

          /* Gain: '<S246>/Gain' incorporates:
           *  Gain: '<S245>/Gain'
           *  Trigonometry: '<S246>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Add3_c);

          /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S246>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S246>/Trigonometric Function' incorporates:
           *  Gain: '<S245>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Add3_c);

          /* Trigonometry: '<S246>/Trigonometric Function1' incorporates:
           *  Gain: '<S245>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Add3_c);

          /* SignalConversion: '<S246>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S233>/Multiply' incorporates:
           *  Constant: '<S242>/Constant'
           *  RelationalOperator: '<S242>/Compare'
           *  S-Function (sfix_bitop): '<S239>/ax_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S246>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S233>/Multiply' incorporates:
           *  Constant: '<S242>/Constant'
           *  RelationalOperator: '<S242>/Compare'
           *  S-Function (sfix_bitop): '<S239>/ay_cmd valid'
           */
          rtb_Gain_fj = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S246>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S233>/Multiply' incorporates:
           *  Constant: '<S242>/Constant'
           *  RelationalOperator: '<S242>/Compare'
           *  S-Function (sfix_bitop): '<S239>/az_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Gain_fj +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
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

        /* End of MultiPortSwitch: '<S233>/Index Vector' */

        /* Sum: '<S294>/Sum1' incorporates:
         *  Constant: '<S294>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S294>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Saturation_n = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S295>/Abs' */
        rtb_Add3_c = fabsf(rtb_Saturation_n);

        /* Switch: '<S295>/Switch' incorporates:
         *  Constant: '<S295>/Constant'
         *  Constant: '<S296>/Constant'
         *  Product: '<S295>/Multiply'
         *  RelationalOperator: '<S296>/Compare'
         *  Sum: '<S295>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S295>/Sign' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* End of Signum: '<S295>/Sign' */
          rtb_Saturation_n *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S295>/Switch' */

        /* Saturate: '<S294>/Saturation' */
        if (rtb_Saturation_n > 0.314159274F) {
          rtb_Saturation_n = 0.314159274F;
        } else {
          if (rtb_Saturation_n < -0.314159274F) {
            rtb_Saturation_n = -0.314159274F;
          }
        }

        /* End of Saturate: '<S294>/Saturation' */

        /* Gain: '<S291>/Gain2' */
        rtb_Saturation_n *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S235>/Sum' incorporates:
         *  Constant: '<S293>/Constant'
         *  Constant: '<S297>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S291>/Multiply2'
         *  Product: '<S292>/Multiply1'
         *  RelationalOperator: '<S293>/Compare'
         *  RelationalOperator: '<S297>/Compare'
         *  S-Function (sfix_bitop): '<S291>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S292>/psi_rate_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_a_l = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Saturation_n :
                   0.0F) + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
                            FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S298>/Gain1' */
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_Switch2_i = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S298>/Gain2' */
        rtb_Saturation_n = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S340>/Trigonometric Function1' incorporates:
         *  Gain: '<S339>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S340>/Trigonometric Function' incorporates:
         *  Gain: '<S339>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S340>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S340>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S340>/Gain' incorporates:
         *  Gain: '<S339>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S340>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S340>/Trigonometric Function3' incorporates:
         *  Gain: '<S339>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S340>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S340>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S340>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S299>/Index Vector' incorporates:
         *  Constant: '<S338>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S299>/Multiply'
         *  Product: '<S335>/Multiply'
         *  Product: '<S336>/Multiply3'
         *  RelationalOperator: '<S338>/Compare'
         *  S-Function (sfix_bitop): '<S334>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S334>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S334>/w_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S299>/Multiply' incorporates:
           *  Constant: '<S338>/Constant'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S334>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S334>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S334>/w_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Gain_fj = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Gain_fj +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 1:
          /* Product: '<S299>/Multiply' incorporates:
           *  Constant: '<S338>/Constant'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S334>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S334>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S334>/w_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Gain_fj = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Gain_fj +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 2:
          /* SignalConversion: '<S342>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S342>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S341>/Gain' incorporates:
           *  DataStoreRead: '<S336>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S336>/Subtract'
           */
          rtb_Divide_lr_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S342>/Trigonometric Function3' incorporates:
           *  Gain: '<S341>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Divide_lr_idx_1);

          /* Gain: '<S342>/Gain' incorporates:
           *  Gain: '<S341>/Gain'
           *  Trigonometry: '<S342>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Divide_lr_idx_1);

          /* SignalConversion: '<S342>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S342>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S342>/Trigonometric Function' incorporates:
           *  Gain: '<S341>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Divide_lr_idx_1);

          /* Trigonometry: '<S342>/Trigonometric Function1' incorporates:
           *  Gain: '<S341>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Divide_lr_idx_1);

          /* SignalConversion: '<S342>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S299>/Multiply' incorporates:
           *  Constant: '<S338>/Constant'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S334>/u_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S342>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S299>/Multiply' incorporates:
           *  Constant: '<S338>/Constant'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S334>/v_cmd valid'
           */
          rtb_Gain_fj = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S342>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S299>/Multiply' incorporates:
           *  Constant: '<S338>/Constant'
           *  RelationalOperator: '<S338>/Compare'
           *  S-Function (sfix_bitop): '<S334>/w_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Gain_fj +
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

        /* End of MultiPortSwitch: '<S299>/Index Vector' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Add3_c;
        rtb_MatrixConcatenate3[1] += rtb_Switch2_i;

        /* Sum: '<S236>/Sum1' */
        rtb_Add3_c = rtb_Saturation_n + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S254>/Switch' incorporates:
         *  Constant: '<S269>/Constant'
         *  Constant: '<S271>/Constant'
         *  Constant: '<S272>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S269>/Compare'
         *  RelationalOperator: '<S271>/Compare'
         *  RelationalOperator: '<S272>/Compare'
         *  S-Function (sfix_bitop): '<S254>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S254>/y_v_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S254>/Logical Operator' incorporates:
           *  Constant: '<S270>/Constant'
           *  Constant: '<S271>/Constant'
           *  Constant: '<S272>/Constant'
           *  RelationalOperator: '<S270>/Compare'
           *  RelationalOperator: '<S271>/Compare'
           *  RelationalOperator: '<S272>/Compare'
           *  S-Function (sfix_bitop): '<S254>/lat_lon_cmd valid'
           *  S-Function (sfix_bitop): '<S254>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S254>/y_v_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 3072U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) >
            0U);
        }

        /* End of Switch: '<S254>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S234>/u_cmd_valid' */
        /* MATLAB Function: '<S266>/bit_shift' incorporates:
         *  DataTypeConversion: '<S234>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_es << 6);

        /* End of Outputs for SubSystem: '<S234>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S234>/v_cmd_valid' */
        /* MATLAB Function: '<S267>/bit_shift' incorporates:
         *  DataTypeConversion: '<S234>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S234>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S255>/Switch' incorporates:
         *  Constant: '<S274>/Constant'
         *  Constant: '<S275>/Constant'
         *  Constant: '<S277>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S274>/Compare'
         *  RelationalOperator: '<S275>/Compare'
         *  RelationalOperator: '<S277>/Compare'
         *  S-Function (sfix_bitop): '<S255>/ax_cmd'
         *  S-Function (sfix_bitop): '<S255>/ay_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S255>/Logical Operator' incorporates:
           *  Constant: '<S275>/Constant'
           *  Constant: '<S277>/Constant'
           *  RelationalOperator: '<S275>/Compare'
           *  RelationalOperator: '<S277>/Compare'
           *  S-Function (sfix_bitop): '<S255>/ax_cmd'
           *  S-Function (sfix_bitop): '<S255>/ay_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S255>/Switch' */
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

        /* Saturate: '<S235>/Saturation' */
        if (rtb_a_l > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_a_l < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_a_l;
        }

        /* End of Saturate: '<S235>/Saturation' */

        /* Saturate: '<S236>/Saturation2' */
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

        /* End of Saturate: '<S236>/Saturation2' */

        /* Saturate: '<S236>/Saturation1' */
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

        /* End of Saturate: '<S236>/Saturation1' */

        /* Saturate: '<S236>/Saturation3' */
        if (rtb_Add3_c > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Add3_c < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Add3_c;
        }

        /* End of Saturate: '<S236>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S234>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S234>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S234>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S234>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S234>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S234>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S234>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S234>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S234>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S234>/throttle_cmd_valid' */
        /* BusAssignment: '<S151>/Bus Assignment' incorporates:
         *  Constant: '<S247>/Constant'
         *  Constant: '<S248>/Constant'
         *  Constant: '<S249>/Constant'
         *  Constant: '<S250>/Constant'
         *  Constant: '<S251>/Constant'
         *  Constant: '<S252>/Constant'
         *  Constant: '<S253>/Constant'
         *  Constant: '<S273>/Constant'
         *  Constant: '<S276>/Constant'
         *  DataTypeConversion: '<S234>/Data Type Conversion10'
         *  DataTypeConversion: '<S234>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S256>/bit_shift'
         *  MATLAB Function: '<S257>/bit_shift'
         *  MATLAB Function: '<S258>/bit_shift'
         *  MATLAB Function: '<S260>/bit_shift'
         *  MATLAB Function: '<S261>/bit_shift'
         *  MATLAB Function: '<S262>/bit_shift'
         *  MATLAB Function: '<S263>/bit_shift'
         *  MATLAB Function: '<S264>/bit_shift'
         *  MATLAB Function: '<S265>/bit_shift'
         *  MATLAB Function: '<S268>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S247>/Compare'
         *  RelationalOperator: '<S248>/Compare'
         *  RelationalOperator: '<S249>/Compare'
         *  RelationalOperator: '<S250>/Compare'
         *  RelationalOperator: '<S251>/Compare'
         *  RelationalOperator: '<S252>/Compare'
         *  RelationalOperator: '<S253>/Compare'
         *  RelationalOperator: '<S273>/Compare'
         *  RelationalOperator: '<S276>/Compare'
         *  S-Function (sfix_bitop): '<S234>/p_cmd'
         *  S-Function (sfix_bitop): '<S234>/phi_cmd'
         *  S-Function (sfix_bitop): '<S234>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S234>/q_cmd'
         *  S-Function (sfix_bitop): '<S234>/r_cmd'
         *  S-Function (sfix_bitop): '<S234>/theta_cmd'
         *  S-Function (sfix_bitop): '<S234>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S254>/alt_z_w_cmd'
         *  S-Function (sfix_bitop): '<S255>/az_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         *  Sum: '<S234>/Add'
         */
        FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
          ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
           ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
          (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) + rtb_y_md) + rtb_y_c1)
          + (((FMS_U.Auto_Cmd.cmd_mask & 37376U) > 0U) << 8)) +
          (rtb_LogicalOperator_es << 9)) + (rtb_FixPtRelationalOperator_me << 10))
          + (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

        /* End of Outputs for SubSystem: '<S234>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S234>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S234>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S234>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S234>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S234>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S234>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S234>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S234>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S234>/q_cmd_valid' */
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
           *  Delay: '<S180>/Delay'
           *  DiscreteIntegrator: '<S161>/Integrator'
           *  DiscreteIntegrator: '<S161>/Integrator1'
           *  DiscreteIntegrator: '<S176>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S228>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_i = 1U;
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;
          FMS_DW.l1_heading = 0.0F;
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

          /* InitializeConditions for Delay: '<S180>/Delay' */
          FMS_DW.icLoad_i = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for DiscreteIntegrator: '<S176>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S228>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S158>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S202>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S192>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_me;

        /* Delay: '<S180>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_i != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S176>/Switch2' incorporates:
         *  Constant: '<S176>/vel'
         *  Constant: '<S185>/Constant'
         *  RelationalOperator: '<S185>/Compare'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_Switch2_i = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_Switch2_i = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S176>/Switch2' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* DiscreteIntegrator: '<S181>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S153>/Delay Input1'
         *
         * Block description for '<S153>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S175>/Compare' incorporates:
         *  Constant: '<S232>/Constant'
         *  RelationalOperator: '<S232>/Compare'
         *  UnitDelay: '<S153>/Delay Input1'
         *
         * Block description for '<S153>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_on = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* DiscreteIntegrator: '<S176>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

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

        /* Switch: '<S156>/Switch' incorporates:
         *  Product: '<S180>/Multiply'
         *  Sum: '<S180>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S201>/Saturation1' */
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

          /* End of Saturate: '<S201>/Saturation1' */

          /* Saturate: '<S191>/Saturation1' */
          if (FMS_B.Merge_e3 > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e3 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_e3;
          }

          /* End of Saturate: '<S191>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S180>/Sum' incorporates:
           *  Delay: '<S180>/Delay'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_p[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S229>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S176>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_l = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Sum_ff[0] = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S180>/Sum' incorporates:
           *  Delay: '<S180>/Delay'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_p[1];

          /* Sum: '<S176>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sqrt: '<S188>/Sqrt' incorporates:
           *  Math: '<S188>/Square'
           *  Sum: '<S176>/Sum'
           *  Sum: '<S188>/Sum of Elements'
           */
          rtb_Add3_c = sqrtf(rtb_a_l * rtb_a_l + rtb_Add3_c * rtb_Add3_c);

          /* SignalConversion: '<S231>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S231>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S231>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S230>/Gain' incorporates:
           *  DiscreteIntegrator: '<S228>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S228>/Add'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S231>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S231>/Gain' incorporates:
           *  Trigonometry: '<S231>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S231>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S231>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S231>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S231>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* Switch: '<S187>/Switch2' incorporates:
           *  Constant: '<S176>/Constant2'
           *  DiscreteIntegrator: '<S176>/Acceleration_Speed'
           *  RelationalOperator: '<S187>/LowerRelop1'
           *  RelationalOperator: '<S187>/UpperRelop'
           *  Switch: '<S187>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE > rtb_Switch2_i) {
            rtb_Saturation_n = rtb_Switch2_i;
          } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
            /* Switch: '<S187>/Switch' incorporates:
             *  Constant: '<S176>/Constant2'
             */
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_DW.Acceleration_Speed_DSTATE;
          }

          /* End of Switch: '<S187>/Switch2' */

          /* Switch: '<S176>/Switch' */
          if (rtb_Add3_c > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_Switch2_i;
          } else {
            /* Gain: '<S176>/Gain' */
            rtb_Gain_fj = 0.5F * rtb_Add3_c;

            /* Switch: '<S186>/Switch2' incorporates:
             *  Constant: '<S176>/Constant1'
             *  RelationalOperator: '<S186>/LowerRelop1'
             *  RelationalOperator: '<S186>/UpperRelop'
             *  Switch: '<S186>/Switch'
             */
            if (rtb_Gain_fj > rtb_Switch2_i) {
              rtb_Gain_fj = rtb_Switch2_i;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S186>/Switch' incorporates:
                 *  Constant: '<S176>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S186>/Switch2' */
          }

          /* End of Switch: '<S176>/Switch' */

          /* Switch: '<S176>/Switch1' incorporates:
           *  Sum: '<S176>/Sum1'
           */
          if (rtb_Saturation_n - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_Saturation_n;
          }

          /* End of Switch: '<S176>/Switch1' */

          /* Sum: '<S229>/Sum of Elements' incorporates:
           *  Math: '<S229>/Math Function'
           */
          rtb_Saturation_n = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Divide_lr_idx_1 *
            rtb_Divide_lr_idx_1;

          /* Math: '<S229>/Math Function1' incorporates:
           *  Sum: '<S229>/Sum of Elements'
           *
           * About '<S229>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S229>/Math Function1' */

          /* Switch: '<S229>/Switch' incorporates:
           *  Constant: '<S229>/Constant'
           *  Product: '<S229>/Product'
           */
          if (rtb_Saturation_n > 0.0F) {
            rtb_Add3_c = rtb_Sum_ff[0];
          } else {
            rtb_Add3_c = 0.0F;
            rtb_Divide_lr_idx_1 = 0.0F;
            rtb_Saturation_n = 1.0F;
          }

          /* End of Switch: '<S229>/Switch' */

          /* Product: '<S227>/Multiply2' incorporates:
           *  Product: '<S229>/Divide'
           */
          rtb_a_l = rtb_Add3_c / rtb_Saturation_n * rtb_Gain_fj;
          rtb_Gain_fj *= rtb_Divide_lr_idx_1 / rtb_Saturation_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S182>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Rem_p = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S182>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sqrt_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Add3_c = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S182>/Divide' incorporates:
           *  Math: '<S183>/Square'
           *  Math: '<S184>/Square'
           *  Sqrt: '<S183>/Sqrt'
           *  Sqrt: '<S184>/Sqrt'
           *  Sum: '<S182>/Sum'
           *  Sum: '<S182>/Sum1'
           *  Sum: '<S183>/Sum of Elements'
           *  Sum: '<S184>/Sum of Elements'
           */
          rtb_Saturation_n = sqrtf(rtb_Sqrt_b * rtb_Sqrt_b + rtb_Add3_c *
            rtb_Add3_c) / sqrtf(rtb_Rem_p * rtb_Rem_p + rtb_Saturation_n *
                                rtb_Saturation_n);

          /* Saturate: '<S182>/Saturation' */
          if (rtb_Saturation_n > 1.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            if (rtb_Saturation_n < 0.0F) {
              rtb_Saturation_n = 0.0F;
            }
          }

          /* End of Saturate: '<S182>/Saturation' */

          /* Product: '<S180>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] * rtb_a_l;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S173>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S182>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S173>/Sum2'
           *  Sum: '<S182>/Add'
           *  Sum: '<S182>/Subtract'
           */
          rtb_a_l = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_n +
                      FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S173>/Saturation1' incorporates:
           *  Product: '<S180>/Multiply'
           */
          if (rtb_a_l > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_a_l < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_a_l;
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
        rtb_Divide_lr_idx_1 = rt_remf(FMS_DW.Integrator1_DSTATE_p -
          FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S165>/Switch' incorporates:
         *  Abs: '<S165>/Abs'
         *  Constant: '<S165>/Constant'
         *  Constant: '<S166>/Constant'
         *  Product: '<S165>/Multiply'
         *  RelationalOperator: '<S166>/Compare'
         *  Sum: '<S165>/Add'
         */
        if (fabsf(rtb_Divide_lr_idx_1) > 3.14159274F) {
          /* Signum: '<S165>/Sign' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_lr_idx_1;
          }

          /* End of Signum: '<S165>/Sign' */
          rtb_Divide_lr_idx_1 -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S165>/Switch' */

        /* Gain: '<S160>/Gain2' */
        rtb_Divide_lr_idx_1 *= FMS_PARAM.YAW_P;

        /* Saturate: '<S160>/Saturation' */
        if (rtb_Divide_lr_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Divide_lr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Divide_lr_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_lr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
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
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_lr_idx_1;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S222>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S222>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Saturation_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S222>/Math Function1' incorporates:
         *  Sum: '<S222>/Sum of Elements'
         *
         * About '<S222>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S222>/Math Function1' */

        /* Switch: '<S222>/Switch' incorporates:
         *  Constant: '<S222>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S222>/Product'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (rtb_Divide_lr_idx_1 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMath_c[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Divide_lr_idx_1;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S222>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S154>/Sum' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Gain_fj = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_TmpSignalConversionAtDela_a[0] = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_a_l = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S172>/Sum of Elements' incorporates:
         *  Math: '<S172>/Math Function'
         *  Sum: '<S154>/Sum'
         */
        rtb_Saturation_n = rtb_a_l * rtb_a_l + rtb_Gain_fj * rtb_Gain_fj;

        /* Math: '<S172>/Math Function1' incorporates:
         *  Sum: '<S172>/Sum of Elements'
         *
         * About '<S172>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S172>/Math Function1' */

        /* Switch: '<S172>/Switch' incorporates:
         *  Constant: '<S172>/Constant'
         *  Product: '<S172>/Product'
         */
        if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_MathFunction_f_idx_2 = rtb_Divide_lr_idx_1;
        } else {
          rtb_a_l = 0.0F;
          rtb_Gain_fj = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S172>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S178>/NearbyRefWP' incorporates:
         *  Constant: '<S154>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                        rtb_TmpSignalConversionAtDela_a, &rtb_Rem_p);

        /* MATLAB Function: '<S178>/SearchL1RefWP' incorporates:
         *  Constant: '<S154>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Divide_lr_idx_1 = rtb_Add3_c * rtb_Add3_c + rtb_Divide_lr_idx_1 *
          rtb_Divide_lr_idx_1;

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
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Divide_lr_idx_1);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
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
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Sqrt_b = (FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
                        [0]) * rtb_Add3_c + FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_iq_idx_1 = (FMS_B.Cmd_In.sp_waypoint[1] -
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
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Divide_lr_idx_1 = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1])
          * rtb_Saturation_n + (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0])
          * rtb_TmpSignalConversionAtMath_0) / (rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_Saturation_n * rtb_Saturation_n);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Divide_lr_idx_1 <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Divide_lr_idx_1 >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = rtb_Divide_lr_idx_1 * rtb_TmpSignalConversionAtMath_0
            + FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Switch: '<S178>/Switch1' incorporates:
         *  Constant: '<S215>/Constant'
         *  RelationalOperator: '<S215>/Compare'
         */
        if (rtb_Rem_p <= 0.0F) {
          /* Switch: '<S178>/Switch' incorporates:
           *  Constant: '<S214>/Constant'
           *  MATLAB Function: '<S178>/SearchL1RefWP'
           *  RelationalOperator: '<S214>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_Sqrt_b;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S178>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else if (rtb_LogicalOperator_es) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = rtb_Divide_lr_idx_1 *
                rtb_Saturation_n + FMS_B.Cmd_In.cur_waypoint[1];

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
        rtb_Sqrt_b = rtb_TmpSignalConversionAtDela_a[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sqrt_b * rtb_Sqrt_b;
        rtb_Add3_c = rtb_Sqrt_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S179>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S223>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_TmpSignalConversionAtDela_a[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S223>/Math Function' incorporates:
         *  Math: '<S221>/Square'
         */
        rtb_Saturation_n = rtb_Sqrt_b * rtb_Sqrt_b;

        /* Sum: '<S223>/Sum of Elements' incorporates:
         *  Math: '<S223>/Math Function'
         */
        rtb_Divide_lr_idx_1 = rtb_Saturation_n +
          rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S223>/Math Function1' incorporates:
         *  Sum: '<S223>/Sum of Elements'
         *
         * About '<S223>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S223>/Math Function1' */

        /* Switch: '<S223>/Switch' incorporates:
         *  Constant: '<S223>/Constant'
         *  Product: '<S223>/Product'
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

        /* End of Switch: '<S223>/Switch' */

        /* Product: '<S222>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_P_l_idx_0 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S225>/Sum of Elements' incorporates:
         *  Math: '<S225>/Math Function'
         *  SignalConversion: '<S225>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S225>/Math Function1' incorporates:
         *  Sum: '<S225>/Sum of Elements'
         *
         * About '<S225>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S225>/Math Function1' */

        /* Switch: '<S225>/Switch' incorporates:
         *  Constant: '<S225>/Constant'
         *  Product: '<S225>/Product'
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

        /* End of Switch: '<S225>/Switch' */

        /* Product: '<S223>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S226>/Sum of Elements' incorporates:
         *  Math: '<S226>/Math Function'
         *  SignalConversion: '<S226>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S226>/Math Function1' incorporates:
         *  Sum: '<S226>/Sum of Elements'
         *
         * About '<S226>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S226>/Math Function1' */

        /* Switch: '<S226>/Switch' incorporates:
         *  Constant: '<S226>/Constant'
         *  Product: '<S226>/Product'
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

        /* End of Switch: '<S226>/Switch' */

        /* Product: '<S226>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S225>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S172>/Divide' */
        rtb_Sqrt_b = rtb_a_l / rtb_MathFunction_f_idx_2;
        rtb_Add3_c *= rtb_Add3_c;

        /* Product: '<S226>/Divide' incorporates:
         *  Math: '<S221>/Square'
         */
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S225>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S172>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Gain_fj / rtb_MathFunction_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sqrt: '<S220>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S220>/Square'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S220>/Sum of Elements'
         */
        rtb_Divide_lr_idx_1 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S179>/Gain' incorporates:
         *  Math: '<S179>/Square'
         */
        rtb_Gain_fj = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1 * 2.0F;

        /* Sum: '<S224>/Subtract' incorporates:
         *  Product: '<S224>/Multiply'
         *  Product: '<S224>/Multiply1'
         */
        rtb_Divide_lr_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtDela_a[1] - rtb_P_l_idx_0 *
          rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S219>/Sign1' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S219>/Sign1' */

        /* Switch: '<S219>/Switch2' incorporates:
         *  Constant: '<S219>/Constant4'
         */
        if (rtb_Divide_lr_idx_1 == 0.0F) {
          rtb_Divide_lr_idx_1 = 1.0F;
        }

        /* End of Switch: '<S219>/Switch2' */

        /* DotProduct: '<S219>/Dot Product' */
        rtb_a_l = rtb_TmpSignalConversionAtDela_a[0] *
          rtb_TmpSignalConversionAtMath_0 + rtb_TmpSignalConversionAtDela_a[1] *
          rtb_P_l_idx_0;

        /* Trigonometry: '<S219>/Acos' incorporates:
         *  DotProduct: '<S219>/Dot Product'
         */
        if (rtb_a_l > 1.0F) {
          rtb_a_l = 1.0F;
        } else {
          if (rtb_a_l < -1.0F) {
            rtb_a_l = -1.0F;
          }
        }

        /* Product: '<S219>/Multiply' incorporates:
         *  Trigonometry: '<S219>/Acos'
         */
        rtb_Divide_lr_idx_1 *= acosf(rtb_a_l);

        /* Saturate: '<S179>/Saturation' */
        if (rtb_Divide_lr_idx_1 > 1.57079637F) {
          rtb_Divide_lr_idx_1 = 1.57079637F;
        } else {
          if (rtb_Divide_lr_idx_1 < -1.57079637F) {
            rtb_Divide_lr_idx_1 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S179>/Saturation' */

        /* Product: '<S179>/Divide' incorporates:
         *  Constant: '<S154>/L1'
         *  Constant: '<S179>/Constant'
         *  MinMax: '<S179>/Max'
         *  MinMax: '<S179>/Min'
         *  Product: '<S179>/Multiply1'
         *  Sqrt: '<S221>/Sqrt'
         *  Sum: '<S221>/Sum of Elements'
         *  Trigonometry: '<S179>/Sin'
         */
        rtb_Gain_fj = arm_sin_f32(rtb_Divide_lr_idx_1) * rtb_Gain_fj / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_n + rtb_Add3_c), 0.5F));

        /* Sum: '<S170>/Subtract' incorporates:
         *  Product: '<S170>/Multiply'
         *  Product: '<S170>/Multiply1'
         */
        rtb_MathFunction_f_idx_2 = rtb_Sqrt_b * FMS_ConstB.Divide[1] -
          rtb_MathFunction_iq_idx_1 * FMS_ConstB.Divide[0];

        /* Signum: '<S159>/Sign1' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_2 > 0.0F) {
            rtb_MathFunction_f_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S159>/Sign1' */

        /* Switch: '<S159>/Switch2' incorporates:
         *  Constant: '<S159>/Constant4'
         */
        if (rtb_MathFunction_f_idx_2 == 0.0F) {
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S159>/Switch2' */

        /* DotProduct: '<S159>/Dot Product' */
        rtb_a_l = FMS_ConstB.Divide[0] * rtb_Sqrt_b + FMS_ConstB.Divide[1] *
          rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S159>/Acos' incorporates:
         *  DotProduct: '<S159>/Dot Product'
         */
        if (rtb_a_l > 1.0F) {
          rtb_a_l = 1.0F;
        } else {
          if (rtb_a_l < -1.0F) {
            rtb_a_l = -1.0F;
          }
        }

        /* Product: '<S159>/Multiply' incorporates:
         *  Trigonometry: '<S159>/Acos'
         */
        rtb_MathFunction_f_idx_2 *= acosf(rtb_a_l);

        /* Math: '<S162>/Rem' incorporates:
         *  Constant: '<S162>/Constant1'
         *  Delay: '<S158>/Delay'
         *  Sum: '<S158>/Sum2'
         */
        rtb_Divide_lr_idx_1 = rt_remf(rtb_MathFunction_f_idx_2 -
          FMS_DW.Delay_DSTATE_h, 6.28318548F);

        /* Switch: '<S162>/Switch' incorporates:
         *  Abs: '<S162>/Abs'
         *  Constant: '<S162>/Constant'
         *  Constant: '<S168>/Constant'
         *  Product: '<S162>/Multiply'
         *  RelationalOperator: '<S168>/Compare'
         *  Sum: '<S162>/Add'
         */
        if (fabsf(rtb_Divide_lr_idx_1) > 3.14159274F) {
          /* Signum: '<S162>/Sign' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_lr_idx_1;
          }

          /* End of Signum: '<S162>/Sign' */
          rtb_Divide_lr_idx_1 -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S162>/Switch' */

        /* Sum: '<S158>/Sum' incorporates:
         *  Delay: '<S158>/Delay'
         */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S167>/Multiply1' incorporates:
         *  Constant: '<S167>/const1'
         *  DiscreteIntegrator: '<S161>/Integrator'
         */
        rtb_Divide_lr_idx_1 = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S167>/Add' incorporates:
         *  DiscreteIntegrator: '<S161>/Integrator1'
         *  Sum: '<S161>/Subtract'
         */
        rtb_Saturation_n = (FMS_DW.Integrator1_DSTATE_p - rtb_Add3_c) +
          rtb_Divide_lr_idx_1;

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
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Saturation_n) + FMS_ConstB.d) *
                           FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Add3_c +
          rtb_Divide_lr_idx_1;

        /* Sum: '<S167>/Add4' */
        rtb_Divide_lr_idx_1 += rtb_Saturation_n - rtb_Rem_p;

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
        rtb_Rem_p += (rtb_Add3_c - rtb_Saturation_n) * 0.5F *
          rtb_Divide_lr_idx_1;

        /* Sum: '<S167>/Add6' */
        rtb_Add3_c = rtb_Rem_p + FMS_ConstB.d;

        /* Sum: '<S167>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_Rem_p - FMS_ConstB.d;

        /* Product: '<S167>/Divide' */
        rtb_Sqrt_b = rtb_Rem_p / FMS_ConstB.d;

        /* Signum: '<S167>/Sign5' incorporates:
         *  Signum: '<S167>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;

          /* Signum: '<S167>/Sign6' */
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;

          /* Signum: '<S167>/Sign6' */
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Rem_p;

          /* Signum: '<S167>/Sign6' */
          rtb_Saturation_n = rtb_Rem_p;
        }

        /* End of Signum: '<S167>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S158>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_2 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S163>/Rem' incorporates:
         *  Constant: '<S163>/Constant1'
         */
        rtb_Rem_p = rt_remf(rtb_MathFunction_f_idx_2, 6.28318548F);

        /* Switch: '<S163>/Switch' incorporates:
         *  Abs: '<S163>/Abs'
         *  Constant: '<S163>/Constant'
         *  Constant: '<S169>/Constant'
         *  Product: '<S163>/Multiply'
         *  RelationalOperator: '<S169>/Compare'
         *  Sum: '<S163>/Add'
         */
        if (fabsf(rtb_Rem_p) > 3.14159274F) {
          /* Signum: '<S163>/Sign' */
          if (rtb_Rem_p < 0.0F) {
            rtb_a_l = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_a_l = 1.0F;
          } else {
            rtb_a_l = rtb_Rem_p;
          }

          /* End of Signum: '<S163>/Sign' */
          rtb_Rem_p -= 6.28318548F * rtb_a_l;
        }

        /* End of Switch: '<S163>/Switch' */

        /* Abs: '<S156>/Abs' */
        rtb_Rem_p = fabsf(rtb_Rem_p);

        /* Update for Delay: '<S180>/Delay' */
        FMS_DW.icLoad_i = 0U;

        /* Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S174>/Constant'
         *  RelationalOperator: '<S174>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)(rtb_Rem_p <=
          0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S176>/Acceleration_Speed' incorporates:
         *  Constant: '<S176>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Product: '<S180>/Divide1' */
        rtb_a_l = rtb_Gain_fj / rtb_Switch2_i;

        /* Saturate: '<S180>/Saturation' */
        if (rtb_a_l > 0.314159274F) {
          rtb_a_l = 0.314159274F;
        } else {
          if (rtb_a_l < -0.314159274F) {
            rtb_a_l = -0.314159274F;
          }
        }

        /* End of Saturate: '<S180>/Saturation' */

        /* Update for DiscreteIntegrator: '<S228>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_a_l;

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
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
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
        FMS_DW.Integrator_DSTATE_i += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1) *
          FMS_ConstB.Gain4 * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F) -
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
        rtb_Switch2_i = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Saturation_n;

        /* Sum: '<S134>/Sum of Elements' incorporates:
         *  Math: '<S134>/Square'
         *  SignalConversion: '<S134>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S135>/Sum of Elements'
         *  Switch: '<S126>/Switch'
         */
        rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c + rtb_Switch2_i *
          rtb_Switch2_i;

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
            rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S135>/Math Function1' */

          /* Switch: '<S135>/Switch' incorporates:
           *  Constant: '<S135>/Constant'
           *  Product: '<S135>/Product'
           */
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Add3_c;
            rtb_MatrixConcatenate3[1] = rtb_Switch2_i;
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S135>/Switch' */
          rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_Switch2_i = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
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
        rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE_k - FMS_PARAM.ROLL_PITCH_LIM *
                       rtb_Add3_c * (real32_T)rtb_FixPtRelationalOperator_me) +
          rtb_a_l;

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
        rtb_Sqrt_b = 31.415926F * rtb_Saturation_n;

        /* Product: '<S136>/Multiply' */
        rtb_MathFunction_iq_idx_1 = rtb_Sqrt_b * FMS_ConstB.Square_c;

        /* Signum: '<S136>/Sign' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Gain_fj;
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
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Gain_fj) +
          rtb_MathFunction_iq_idx_1) * rtb_MathFunction_iq_idx_1) -
                            rtb_MathFunction_iq_idx_1) * 0.5F * rtb_Add3_c +
          rtb_a_l;

        /* Sum: '<S136>/Add4' */
        rtb_Divide_lr_idx_1 = (rtb_Gain_fj - rtb_Saturation_n) + rtb_a_l;

        /* Sum: '<S136>/Add3' */
        rtb_Add3_c = rtb_Gain_fj + rtb_MathFunction_iq_idx_1;

        /* Sum: '<S136>/Subtract1' */
        rtb_Gain_fj -= rtb_MathFunction_iq_idx_1;

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
        if (rtb_Gain_fj < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else {
          if (rtb_Gain_fj > 0.0F) {
            rtb_Gain_fj = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign2' */

        /* Sum: '<S136>/Add5' incorporates:
         *  Gain: '<S136>/Gain2'
         *  Product: '<S136>/Multiply4'
         *  Sum: '<S136>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Gain_fj) * 0.5F *
          rtb_Divide_lr_idx_1;

        /* Sum: '<S136>/Add6' */
        rtb_Add3_c = rtb_Saturation_n + rtb_MathFunction_iq_idx_1;

        /* Sum: '<S136>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_Saturation_n - rtb_MathFunction_iq_idx_1;

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
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
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
        rtb_Divide_lr_idx_1 = (rtb_Saturation_n / rtb_MathFunction_iq_idx_1 -
          rtb_a_l) * -rtb_Sqrt_b * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F);

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
        rtb_MathFunction_f_idx_2 = rtb_Saturation_n * rtb_Sqrt_b;

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
        rtb_MathFunction_iq_idx_1 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Sum: '<S137>/Add' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion'
         *  DiscreteIntegrator: '<S133>/Integrator1'
         *  Gain: '<S126>/Gain1'
         *  Product: '<S126>/Multiply1'
         *  Sum: '<S133>/Subtract'
         */
        rtb_Sqrt_b = (FMS_DW.Integrator1_DSTATE_nf - -FMS_PARAM.ROLL_PITCH_LIM *
                      rtb_Switch2_i * (real32_T)rtb_FixPtRelationalOperator_me)
          + rtb_MathFunction_iq_idx_1;

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
        rtb_Gain_fj = 31.415926F * rtb_Saturation_n;

        /* Product: '<S137>/Multiply' */
        rtb_a_l = rtb_Gain_fj * FMS_ConstB.Square_b;

        /* Signum: '<S137>/Sign' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Sqrt_b > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Sqrt_b;
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
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Sqrt_b) + rtb_a_l) * rtb_a_l) -
                     rtb_a_l) * 0.5F * rtb_Add3_c + rtb_MathFunction_iq_idx_1;

        /* Sum: '<S137>/Add4' */
        rtb_Saturation_n = (rtb_Sqrt_b - rtb_Rem_p) + rtb_MathFunction_iq_idx_1;

        /* Sum: '<S137>/Add3' */
        rtb_Add3_c = rtb_Sqrt_b + rtb_a_l;

        /* Sum: '<S137>/Subtract1' */
        rtb_Sqrt_b -= rtb_a_l;

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
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign2' */

        /* Sum: '<S137>/Add5' incorporates:
         *  Gain: '<S137>/Gain2'
         *  Product: '<S137>/Multiply4'
         *  Sum: '<S137>/Subtract2'
         */
        rtb_Rem_p += (rtb_Add3_c - rtb_Sqrt_b) * 0.5F * rtb_Saturation_n;

        /* Update for DiscreteIntegrator: '<S132>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S132>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_k += 0.004F * FMS_DW.Integrator_DSTATE_a;

        /* Update for DiscreteIntegrator: '<S132>/Integrator' incorporates:
         *  Sum: '<S136>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_a += (rtb_Divide_lr_idx_1 -
          rtb_MathFunction_f_idx_2) * 0.004F;

        /* Update for DiscreteIntegrator: '<S133>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S133>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_nf += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S137>/Subtract3' */
        rtb_Add3_c = rtb_Rem_p - rtb_a_l;

        /* Sum: '<S137>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_Rem_p + rtb_a_l;

        /* Signum: '<S137>/Sign5' incorporates:
         *  Signum: '<S137>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Saturation_n = -1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_Switch2_i = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_Saturation_n = 1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_Switch2_i = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Rem_p;

          /* Signum: '<S137>/Sign6' */
          rtb_Switch2_i = rtb_Rem_p;
        }

        /* End of Signum: '<S137>/Sign5' */

        /* Signum: '<S137>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
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
        FMS_DW.Integrator_DSTATE_b += ((rtb_Rem_p / rtb_a_l - rtb_Saturation_n) *
          -rtb_Gain_fj * ((rtb_Divide_lr_idx_1 - rtb_Add3_c) * 0.5F) -
          rtb_Switch2_i * rtb_Gain_fj) * 0.004F;

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
        rtb_Switch2_i = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Saturation_n;

        /* Sum: '<S67>/Sum of Elements' incorporates:
         *  Math: '<S67>/Square'
         *  SignalConversion: '<S67>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S68>/Sum of Elements'
         *  Switch: '<S49>/Switch'
         */
        rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c + rtb_Switch2_i *
          rtb_Switch2_i;

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
            rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S68>/Math Function1' */

          /* Switch: '<S68>/Switch' incorporates:
           *  Constant: '<S68>/Constant'
           *  Product: '<S68>/Product'
           */
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Add3_c;
            rtb_MatrixConcatenate3[1] = rtb_Switch2_i;
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S68>/Switch' */
          rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_Switch2_i = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
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
        rtb_Gain_fj = (FMS_DW.Integrator1_DSTATE_n - FMS_PARAM.ROLL_PITCH_LIM *
                       rtb_Add3_c * (real32_T)rtb_FixPtRelationalOperator_me) +
          rtb_a_l;

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
        rtb_Sqrt_b = 31.415926F * rtb_Saturation_n;

        /* Product: '<S69>/Multiply' */
        rtb_Saturation_n = rtb_Sqrt_b * FMS_ConstB.Square_m;

        /* Signum: '<S69>/Sign' */
        if (rtb_Gain_fj < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Gain_fj > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Gain_fj;
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
        rtb_MathFunction_iq_idx_1 = (sqrtf((8.0F * fabsf(rtb_Gain_fj) +
          rtb_Saturation_n) * rtb_Saturation_n) - rtb_Saturation_n) * 0.5F *
          rtb_Add3_c + rtb_a_l;

        /* Sum: '<S69>/Add4' */
        rtb_Divide_lr_idx_1 = (rtb_Gain_fj - rtb_MathFunction_iq_idx_1) +
          rtb_a_l;

        /* Sum: '<S69>/Add3' */
        rtb_Add3_c = rtb_Gain_fj + rtb_Saturation_n;

        /* Sum: '<S69>/Subtract1' */
        rtb_Gain_fj -= rtb_Saturation_n;

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
        rtb_MathFunction_iq_idx_1 += (rtb_Add3_c - rtb_Gain_fj) * 0.5F *
          rtb_Divide_lr_idx_1;

        /* Sum: '<S69>/Add6' */
        rtb_Add3_c = rtb_MathFunction_iq_idx_1 + rtb_Saturation_n;

        /* Sum: '<S69>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_MathFunction_iq_idx_1 - rtb_Saturation_n;

        /* Signum: '<S69>/Sign5' */
        if (rtb_MathFunction_iq_idx_1 < 0.0F) {
          rtb_a_l = -1.0F;
        } else if (rtb_MathFunction_iq_idx_1 > 0.0F) {
          rtb_a_l = 1.0F;
        } else {
          rtb_a_l = rtb_MathFunction_iq_idx_1;
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
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
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
        rtb_Divide_lr_idx_1 = (rtb_MathFunction_iq_idx_1 / rtb_Saturation_n -
          rtb_a_l) * -rtb_Sqrt_b * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F);

        /* Signum: '<S69>/Sign6' */
        if (rtb_MathFunction_iq_idx_1 < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_1 > 0.0F) {
            rtb_MathFunction_iq_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign6' */

        /* Product: '<S69>/Multiply6' */
        rtb_MathFunction_f_idx_2 = rtb_MathFunction_iq_idx_1 * rtb_Sqrt_b;

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
          rtb_MathFunction_iq_idx_1 = 0.5F;
        } else if (FMS_B.Merge_lf > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_MathFunction_iq_idx_1 = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_lf < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_MathFunction_iq_idx_1 = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S51>/Saturation1' */
          rtb_MathFunction_iq_idx_1 = FMS_B.Merge_lf;
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
        FMS_Y.FMS_Out.w_cmd = rtb_MathFunction_iq_idx_1;

        /* Product: '<S70>/Multiply1' incorporates:
         *  Constant: '<S70>/const1'
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        rtb_MathFunction_iq_idx_1 = FMS_DW.Integrator_DSTATE_g * 0.04F;

        /* Sum: '<S70>/Add' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S66>/Integrator1'
         *  Gain: '<S49>/Gain1'
         *  Product: '<S49>/Multiply1'
         *  Sum: '<S66>/Subtract'
         */
        rtb_Sqrt_b = (FMS_DW.Integrator1_DSTATE_i - -FMS_PARAM.ROLL_PITCH_LIM *
                      rtb_Switch2_i * (real32_T)rtb_FixPtRelationalOperator_me)
          + rtb_MathFunction_iq_idx_1;

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
        rtb_Gain_fj = 31.415926F * rtb_Saturation_n;

        /* Product: '<S70>/Multiply' */
        rtb_a_l = rtb_Gain_fj * FMS_ConstB.Square_i;

        /* Signum: '<S70>/Sign' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Sqrt_b > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Sqrt_b;
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
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Sqrt_b) + rtb_a_l) * rtb_a_l) -
                     rtb_a_l) * 0.5F * rtb_Add3_c + rtb_MathFunction_iq_idx_1;

        /* Sum: '<S70>/Add4' */
        rtb_Saturation_n = (rtb_Sqrt_b - rtb_Rem_p) + rtb_MathFunction_iq_idx_1;

        /* Sum: '<S70>/Add3' */
        rtb_Add3_c = rtb_Sqrt_b + rtb_a_l;

        /* Sum: '<S70>/Subtract1' */
        rtb_Sqrt_b -= rtb_a_l;

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
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign2' */

        /* Sum: '<S70>/Add5' incorporates:
         *  Gain: '<S70>/Gain2'
         *  Product: '<S70>/Multiply4'
         *  Sum: '<S70>/Subtract2'
         */
        rtb_Rem_p += (rtb_Add3_c - rtb_Sqrt_b) * 0.5F * rtb_Saturation_n;

        /* Update for DiscreteIntegrator: '<S65>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S65>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Update for DiscreteIntegrator: '<S65>/Integrator' incorporates:
         *  Sum: '<S69>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += (rtb_Divide_lr_idx_1 -
          rtb_MathFunction_f_idx_2) * 0.004F;

        /* Update for DiscreteIntegrator: '<S66>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_i += 0.004F * FMS_DW.Integrator_DSTATE_g;

        /* Sum: '<S70>/Subtract3' */
        rtb_Add3_c = rtb_Rem_p - rtb_a_l;

        /* Sum: '<S70>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_Rem_p + rtb_a_l;

        /* Signum: '<S70>/Sign5' incorporates:
         *  Signum: '<S70>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Saturation_n = -1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_Switch2_i = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_Saturation_n = 1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_Switch2_i = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Rem_p;

          /* Signum: '<S70>/Sign6' */
          rtb_Switch2_i = rtb_Rem_p;
        }

        /* End of Signum: '<S70>/Sign5' */

        /* Signum: '<S70>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
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
        FMS_DW.Integrator_DSTATE_g += ((rtb_Rem_p / rtb_a_l - rtb_Saturation_n) *
          -rtb_Gain_fj * ((rtb_Divide_lr_idx_1 - rtb_Add3_c) * 0.5F) -
          rtb_Switch2_i * rtb_Gain_fj) * 0.004F;

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
          rtb_Divide_lr_idx_1 = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_Gain_fj = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S111>/Multiply' incorporates:
           *  SignalConversion: '<S111>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Divide_lr_idx_1;
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
          rtb_Switch2_i = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation_n;

          /* Sum: '<S120>/Sum of Elements' incorporates:
           *  Math: '<S120>/Square'
           *  SignalConversion: '<S120>/TmpSignal ConversionAtSquareInport1'
           *  Sum: '<S121>/Sum of Elements'
           *  Switch: '<S112>/Switch'
           */
          rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c + rtb_Switch2_i *
            rtb_Switch2_i;

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
              rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
            } else {
              rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
            }

            /* End of Math: '<S121>/Math Function1' */

            /* Switch: '<S121>/Switch' incorporates:
             *  Constant: '<S121>/Constant'
             *  Product: '<S121>/Product'
             */
            if (rtb_Divide_lr_idx_1 > 0.0F) {
              rtb_MatrixConcatenate3[0] = rtb_Add3_c;
              rtb_MatrixConcatenate3[1] = rtb_Switch2_i;
              rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
            } else {
              rtb_MatrixConcatenate3[0] = 0.0F;
              rtb_MatrixConcatenate3[1] = 0.0F;
              rtb_MatrixConcatenate3[2] = 1.0F;
            }

            /* End of Switch: '<S121>/Switch' */
            rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
            rtb_Switch2_i = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
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
          rtb_Gain_fj = 980.6F * rtb_Saturation_n;

          /* Product: '<S122>/Multiply' */
          rtb_MathFunction_iq_idx_1 = rtb_Gain_fj * FMS_ConstB.Square;

          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          rtb_a_l = FMS_DW.Integrator_DSTATE[0] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Sqrt_b = (FMS_DW.Integrator1_DSTATE[0] - FMS_PARAM.VEL_XY_LIM *
                        rtb_Add3_c) + rtb_a_l;

          /* Signum: '<S122>/Sign' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Sqrt_b > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Sqrt_b;
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
          rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Sqrt_b) +
                              rtb_MathFunction_iq_idx_1) *
                             rtb_MathFunction_iq_idx_1) -
                       rtb_MathFunction_iq_idx_1) * 0.5F * rtb_Add3_c + rtb_a_l;

          /* Sum: '<S122>/Add4' */
          rtb_a_l += rtb_Sqrt_b - rtb_Rem_p;

          /* Sum: '<S122>/Add3' */
          rtb_Add3_c = rtb_Sqrt_b + rtb_MathFunction_iq_idx_1;

          /* Sum: '<S122>/Subtract1' */
          rtb_Sqrt_b -= rtb_MathFunction_iq_idx_1;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else {
            if (rtb_Sqrt_b > 0.0F) {
              rtb_Sqrt_b = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Rem_p += (rtb_Add3_c - rtb_Sqrt_b) * 0.5F * rtb_a_l;

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
          rtb_Add3_c = rtb_Rem_p - rtb_MathFunction_iq_idx_1;

          /* Signum: '<S122>/Sign3' incorporates:
           *  Sum: '<S122>/Add6'
           */
          rtb_Divide_lr_idx_1 = rtb_Rem_p + rtb_MathFunction_iq_idx_1;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Rem_p;
          }

          /* Signum: '<S122>/Sign3' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_1 > 0.0F) {
              rtb_Divide_lr_idx_1 = 1.0F;
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
          if (rtb_Rem_p < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = rtb_Rem_p;
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
          FMS_DW.Integrator_DSTATE[0] += ((rtb_Rem_p / rtb_MathFunction_iq_idx_1
            - rtb_Saturation_n) * -rtb_Gain_fj * ((rtb_Divide_lr_idx_1 -
            rtb_Add3_c) * 0.5F) - rtb_Sqrt_b * rtb_Gain_fj) * 0.004F;

          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          rtb_a_l = FMS_DW.Integrator_DSTATE[1] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Sqrt_b = (FMS_DW.Integrator1_DSTATE[1] - FMS_PARAM.VEL_XY_LIM *
                        rtb_Switch2_i) + rtb_a_l;

          /* Signum: '<S122>/Sign' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Sqrt_b > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Sqrt_b;
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
          rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Sqrt_b) +
                              rtb_MathFunction_iq_idx_1) *
                             rtb_MathFunction_iq_idx_1) -
                       rtb_MathFunction_iq_idx_1) * 0.5F * rtb_Add3_c + rtb_a_l;

          /* Sum: '<S122>/Add4' */
          rtb_a_l += rtb_Sqrt_b - rtb_Rem_p;

          /* Sum: '<S122>/Add3' */
          rtb_Add3_c = rtb_Sqrt_b + rtb_MathFunction_iq_idx_1;

          /* Sum: '<S122>/Subtract1' */
          rtb_Sqrt_b -= rtb_MathFunction_iq_idx_1;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else {
            if (rtb_Sqrt_b > 0.0F) {
              rtb_Sqrt_b = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Rem_p += (rtb_Add3_c - rtb_Sqrt_b) * 0.5F * rtb_a_l;

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
          rtb_Add3_c = rtb_Rem_p - rtb_MathFunction_iq_idx_1;

          /* Signum: '<S122>/Sign3' incorporates:
           *  Sum: '<S122>/Add6'
           */
          rtb_Divide_lr_idx_1 = rtb_Rem_p + rtb_MathFunction_iq_idx_1;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Rem_p;
          }

          /* Signum: '<S122>/Sign3' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_1 > 0.0F) {
              rtb_Divide_lr_idx_1 = 1.0F;
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
          if (rtb_Rem_p < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = rtb_Rem_p;
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
          FMS_DW.Integrator_DSTATE[1] += ((rtb_Rem_p / rtb_MathFunction_iq_idx_1
            - rtb_Saturation_n) * -rtb_Gain_fj * ((rtb_Divide_lr_idx_1 -
            rtb_Add3_c) * 0.5F) - rtb_Sqrt_b * rtb_Gain_fj) * 0.004F;

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
          rtb_Add3_c = 0.5F;
        } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S86>/Saturation1' */
          rtb_Add3_c = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S86>/Saturation1' */
          rtb_Add3_c = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S86>/Saturation1' */
          rtb_Add3_c = FMS_B.Merge_l;
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
        FMS_Y.FMS_Out.w_cmd = rtb_Add3_c;

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
   *  DiscreteIntegrator: '<S484>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S499>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S499>/Gain'
   *  Sum: '<S499>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_o[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_o[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_o[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S501>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S501>/Gain'
   *  Sum: '<S501>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S500>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S500>/Gain'
   *  Sum: '<S500>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_k += (rtb_Divide_lr_idx_2 -
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

  /* Update for DiscreteIntegrator: '<S484>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S484>/Constant'
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
  /* Start for SwitchCase: '<S441>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S431>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;

  /* End of Start for SubSystem: '<S39>/Return' */

  /* Start for IfAction SubSystem: '<S39>/Hold' */
  /* Start for SwitchCase: '<S373>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S351>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S361>/Switch Case' */
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
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S499>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S501>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S500>/Discrete-Time Integrator5' */
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
  /* InitializeConditions for Delay: '<S481>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S477>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S477>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S389>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S389>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Return' */
  /* InitializeConditions for Delay: '<S420>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S421>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S416>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S468>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;

  /* InitializeConditions for Delay: '<S398>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S401>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S397>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S401>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S442>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S441>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S441>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S441>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S441>/Move Control' */

  /* SystemInitialize for Merge: '<S441>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S432>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S431>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S431>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S431>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S431>/Move Control' */

  /* SystemInitialize for Merge: '<S431>/Merge' */
  FMS_B.Merge_jj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Hold' */
  /* SystemInitialize for Chart: '<S352>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S362>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S374>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S373>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S373>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S373>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S373>/Move Control' */

  /* SystemInitialize for Merge: '<S373>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S351>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S351>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S351>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S351>/Move Control' */

  /* SystemInitialize for Merge: '<S351>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S361>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S361>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S361>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S361>/Move Control' */

  /* SystemInitialize for Merge: '<S361>/Merge' */
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
  /* InitializeConditions for Delay: '<S180>/Delay' */
  FMS_DW.icLoad_i = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S176>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S228>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S158>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator' */
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
