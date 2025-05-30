/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2168
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu May 29 15:07:12 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S433>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S443>/Motion State' */
#define FMS_IN_Brake_c                 ((uint8_T)1U)
#define FMS_IN_Hold_c                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S144>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o4                 ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S52>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S363>/Motion State' */
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
  ,                                    /* home */
  0.0F,                                /* local_psi */
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
                                        *   '<S487>/Constant'
                                        *   '<S346>/L1'
                                        *   '<S49>/Gain'
                                        *   '<S49>/Gain1'
                                        *   '<S131>/Gain'
                                        *   '<S131>/Gain1'
                                        *   '<S133>/Constant'
                                        *   '<S160>/L1'
                                        *   '<S241>/Saturation'
                                        *   '<S242>/Saturation1'
                                        *   '<S242>/Saturation2'
                                        *   '<S242>/Saturation3'
                                        *   '<S387>/Land_Speed'
                                        *   '<S388>/Saturation1'
                                        *   '<S474>/Takeoff_Speed'
                                        *   '<S475>/Gain2'
                                        *   '<S475>/Saturation1'
                                        *   '<S51>/Saturation1'
                                        *   '<S64>/Dead Zone'
                                        *   '<S64>/Gain'
                                        *   '<S65>/Dead Zone'
                                        *   '<S65>/Gain'
                                        *   '<S66>/Constant'
                                        *   '<S67>/Constant'
                                        *   '<S72>/Saturation'
                                        *   '<S88>/Saturation1'
                                        *   '<S100>/Saturation'
                                        *   '<S113>/Saturation1'
                                        *   '<S135>/Dead Zone'
                                        *   '<S135>/Gain'
                                        *   '<S136>/Dead Zone'
                                        *   '<S136>/Gain'
                                        *   '<S137>/Constant'
                                        *   '<S138>/Constant'
                                        *   '<S143>/Saturation'
                                        *   '<S296>/Gain2'
                                        *   '<S303>/Gain1'
                                        *   '<S303>/Gain2'
                                        *   '<S352>/Saturation1'
                                        *   '<S362>/Saturation'
                                        *   '<S374>/Saturation1'
                                        *   '<S389>/Constant'
                                        *   '<S392>/Gain2'
                                        *   '<S414>/Gain'
                                        *   '<S414>/Saturation1'
                                        *   '<S417>/Constant'
                                        *   '<S417>/vel'
                                        *   '<S417>/Switch'
                                        *   '<S54>/Gain2'
                                        *   '<S55>/Gain1'
                                        *   '<S61>/Constant'
                                        *   '<S75>/Gain2'
                                        *   '<S76>/Gain1'
                                        *   '<S83>/Constant'
                                        *   '<S91>/Gain2'
                                        *   '<S92>/Gain1'
                                        *   '<S98>/Constant'
                                        *   '<S103>/Gain2'
                                        *   '<S104>/Gain1'
                                        *   '<S111>/Constant'
                                        *   '<S116>/Gain2'
                                        *   '<S117>/Gain6'
                                        *   '<S128>/Constant'
                                        *   '<S129>/Constant'
                                        *   '<S146>/Gain2'
                                        *   '<S147>/Gain1'
                                        *   '<S154>/Constant'
                                        *   '<S179>/Gain'
                                        *   '<S179>/Saturation1'
                                        *   '<S182>/Constant'
                                        *   '<S182>/vel'
                                        *   '<S182>/Switch'
                                        *   '<S355>/Gain2'
                                        *   '<S356>/Gain1'
                                        *   '<S365>/Gain2'
                                        *   '<S366>/Gain1'
                                        *   '<S377>/Gain2'
                                        *   '<S378>/Gain6'
                                        *   '<S401>/Gain2'
                                        *   '<S401>/Saturation'
                                        *   '<S402>/Integrator'
                                        *   '<S57>/Land_Speed'
                                        *   '<S58>/Constant'
                                        *   '<S60>/Dead Zone'
                                        *   '<S60>/Gain'
                                        *   '<S80>/Dead Zone'
                                        *   '<S80>/Gain'
                                        *   '<S94>/Land_Speed'
                                        *   '<S95>/Constant'
                                        *   '<S97>/Dead Zone'
                                        *   '<S97>/Gain'
                                        *   '<S108>/Dead Zone'
                                        *   '<S108>/Gain'
                                        *   '<S122>/Dead Zone'
                                        *   '<S122>/Gain'
                                        *   '<S123>/Dead Zone'
                                        *   '<S123>/Gain'
                                        *   '<S124>/Constant'
                                        *   '<S151>/Dead Zone'
                                        *   '<S151>/Gain'
                                        *   '<S166>/Gain2'
                                        *   '<S166>/Saturation'
                                        *   '<S167>/Integrator'
                                        *   '<S358>/Dead Zone'
                                        *   '<S358>/Gain'
                                        *   '<S370>/Dead Zone'
                                        *   '<S370>/Gain'
                                        *   '<S382>/Dead Zone'
                                        *   '<S382>/Gain'
                                        *   '<S383>/Dead Zone'
                                        *   '<S383>/Gain'
                                        *   '<S432>/Saturation1'
                                        *   '<S442>/Saturation1'
                                        *   '<S197>/Saturation1'
                                        *   '<S207>/Saturation1'
                                        *   '<S435>/Gain2'
                                        *   '<S436>/Gain1'
                                        *   '<S445>/Gain2'
                                        *   '<S446>/Gain6'
                                        *   '<S200>/Gain2'
                                        *   '<S201>/Gain1'
                                        *   '<S210>/Gain2'
                                        *   '<S211>/Gain6'
                                        *   '<S438>/Dead Zone'
                                        *   '<S438>/Gain'
                                        *   '<S450>/Dead Zone'
                                        *   '<S450>/Gain'
                                        *   '<S451>/Dead Zone'
                                        *   '<S451>/Gain'
                                        *   '<S203>/Dead Zone'
                                        *   '<S203>/Gain'
                                        *   '<S215>/Dead Zone'
                                        *   '<S215>/Gain'
                                        *   '<S216>/Dead Zone'
                                        *   '<S216>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 77, 67, 32, 70, 77, 83, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S13>/Constant1'
                                        *   '<S485>/Constant'
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
 *    '<S432>/Hold Control'
 *    '<S352>/Hold Control'
 *    '<S197>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S88>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S435>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S432>/Hold Control'
 *    '<S352>/Hold Control'
 *    '<S197>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S88>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S435>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S432>/Hold Control'
 *    '<S352>/Hold Control'
 *    '<S197>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S88>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S435>/Delay' incorporates:
   *  Gain: '<S437>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S435>/Gain2' incorporates:
   *  Delay: '<S435>/Delay'
   *  Gain: '<S437>/Gain'
   *  Sum: '<S435>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S435>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S432>/Brake Control'
 *    '<S352>/Brake Control'
 *    '<S362>/Brake Control'
 *    '<S197>/Brake Control'
 *    '<S143>/Brake Control'
 *    '<S51>/Brake Control'
 *    '<S72>/Brake Control'
 *    '<S88>/Brake Control'
 *    '<S100>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S434>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S434>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S432>/Move Control'
 *    '<S352>/Move Control'
 *    '<S197>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S439>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S439>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S432>/Move Control'
 *    '<S352>/Move Control'
 *    '<S197>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S439>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S439>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S432>/Move Control'
 *    '<S352>/Move Control'
 *    '<S197>/Move Control'
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

  /* Product: '<S440>/Multiply1' incorporates:
   *  Constant: '<S440>/const1'
   *  DiscreteIntegrator: '<S439>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S438>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S438>/Dead Zone' */

  /* Sum: '<S440>/Add' incorporates:
   *  DiscreteIntegrator: '<S439>/Integrator1'
   *  Gain: '<S436>/Gain1'
   *  Gain: '<S438>/Gain'
   *  Sum: '<S439>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S440>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S440>/Sign' */

  /* Sum: '<S440>/Add2' incorporates:
   *  Abs: '<S440>/Abs'
   *  Gain: '<S440>/Gain'
   *  Gain: '<S440>/Gain1'
   *  Product: '<S440>/Multiply2'
   *  Product: '<S440>/Multiply3'
   *  Sqrt: '<S440>/Sqrt'
   *  Sum: '<S440>/Add1'
   *  Sum: '<S440>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S440>/Add4' */
  rtb_Add4_df = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S440>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S440>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S440>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S440>/Sign1' */

  /* Signum: '<S440>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S440>/Sign2' */

  /* Sum: '<S440>/Add5' incorporates:
   *  Gain: '<S440>/Gain2'
   *  Product: '<S440>/Multiply4'
   *  Sum: '<S440>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_df;

  /* SignalConversion: '<S436>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S439>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S439>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S439>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S440>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S440>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S440>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_df = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_df = 1.0F;
  } else {
    rtb_Add4_df = rtb_a_g;
  }

  /* End of Signum: '<S440>/Sign5' */

  /* Signum: '<S440>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S440>/Sign3' */

  /* Signum: '<S440>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S440>/Sign4' */

  /* Signum: '<S440>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S440>/Sign6' */

  /* Update for DiscreteIntegrator: '<S439>/Integrator' incorporates:
   *  Constant: '<S440>/const'
   *  Gain: '<S440>/Gain3'
   *  Product: '<S440>/Divide'
   *  Product: '<S440>/Multiply5'
   *  Product: '<S440>/Multiply6'
   *  Sum: '<S440>/Subtract4'
   *  Sum: '<S440>/Subtract5'
   *  Sum: '<S440>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_df) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S433>/Motion Status'
 *    '<S353>/Motion Status'
 *    '<S198>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S433>/Motion Status'
 *    '<S353>/Motion Status'
 *    '<S198>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S433>/Motion Status'
 *    '<S353>/Motion Status'
 *    '<S198>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S433>/Motion Status' */
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

  /* End of Chart: '<S433>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S442>/Hold Control'
 *    '<S374>/Hold Control'
 *    '<S207>/Hold Control'
 *    '<S113>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S445>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S442>/Hold Control'
 *    '<S374>/Hold Control'
 *    '<S207>/Hold Control'
 *    '<S113>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S445>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S442>/Hold Control'
 *    '<S374>/Hold Control'
 *    '<S207>/Hold Control'
 *    '<S113>/Hold Control'
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

  /* Delay: '<S445>/Delay' incorporates:
   *  SignalConversion: '<S445>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S449>/Trigonometric Function1' incorporates:
   *  Gain: '<S448>/Gain'
   *  Trigonometry: '<S449>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S449>/Trigonometric Function' incorporates:
   *  Gain: '<S448>/Gain'
   *  Trigonometry: '<S449>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S449>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S449>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S449>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S449>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S449>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S449>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S449>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S445>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S445>/Delay'
   *  SignalConversion: '<S445>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S445>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S445>/Multiply' incorporates:
   *  SignalConversion: '<S445>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S445>/Multiply' */

  /* Gain: '<S445>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S445>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S442>/Brake Control'
 *    '<S374>/Brake Control'
 *    '<S207>/Brake Control'
 *    '<S113>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S444>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S442>/Move Control'
 *    '<S374>/Move Control'
 *    '<S207>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S442>/Move Control'
 *    '<S374>/Move Control'
 *    '<S207>/Move Control'
 */
void FMS_MoveControl_i_Reset(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S442>/Move Control'
 *    '<S374>/Move Control'
 *    '<S207>/Move Control'
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

  /* SignalConversion: '<S446>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S452>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S453>/Multiply1' incorporates:
   *  Constant: '<S453>/const1'
   *  DiscreteIntegrator: '<S452>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S446>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S452>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S453>/Multiply1' incorporates:
   *  Constant: '<S453>/const1'
   *  DiscreteIntegrator: '<S452>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S450>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S450>/Dead Zone' */

  /* Sum: '<S453>/Add' incorporates:
   *  DiscreteIntegrator: '<S452>/Integrator1'
   *  Gain: '<S446>/Gain6'
   *  Gain: '<S450>/Gain'
   *  Sum: '<S452>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S451>/Dead Zone' */
  if (rtu_FMS_In_o > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_o >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S451>/Dead Zone' */

  /* Sum: '<S453>/Add' incorporates:
   *  DiscreteIntegrator: '<S452>/Integrator1'
   *  Gain: '<S446>/Gain6'
   *  Gain: '<S451>/Gain'
   *  Sum: '<S452>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S453>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S453>/Add2' incorporates:
   *  Abs: '<S453>/Abs'
   *  Gain: '<S453>/Gain'
   *  Gain: '<S453>/Gain1'
   *  Product: '<S453>/Multiply2'
   *  Product: '<S453>/Multiply3'
   *  Signum: '<S453>/Sign'
   *  Sqrt: '<S453>/Sqrt'
   *  Sum: '<S453>/Add1'
   *  Sum: '<S453>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S453>/Add3' incorporates:
   *  Signum: '<S453>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S453>/Subtract1' incorporates:
   *  Signum: '<S453>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S453>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S453>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S453>/Add5' incorporates:
   *  Gain: '<S453>/Gain2'
   *  Product: '<S453>/Multiply4'
   *  Signum: '<S453>/Sign'
   *  Sum: '<S453>/Add2'
   *  Sum: '<S453>/Add4'
   *  Sum: '<S453>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S452>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S452>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S453>/Sign3' incorporates:
   *  Sum: '<S453>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S453>/Sign4' incorporates:
   *  Sum: '<S453>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S453>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S453>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S453>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S453>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

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
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Signum: '<S453>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_l_idx_0 = 1.0F;
  } else {
    rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S453>/Add2' incorporates:
   *  Abs: '<S453>/Abs'
   *  Gain: '<S453>/Gain'
   *  Gain: '<S453>/Gain1'
   *  Product: '<S453>/Multiply2'
   *  Product: '<S453>/Multiply3'
   *  Signum: '<S453>/Sign'
   *  Sqrt: '<S453>/Sqrt'
   *  Sum: '<S453>/Add1'
   *  Sum: '<S453>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_l_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S453>/Add3' incorporates:
   *  Signum: '<S453>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S453>/Subtract1' incorporates:
   *  Signum: '<S453>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S453>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S453>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S453>/Add5' incorporates:
   *  Gain: '<S453>/Gain2'
   *  Product: '<S453>/Multiply4'
   *  Signum: '<S453>/Sign'
   *  Sum: '<S453>/Add2'
   *  Sum: '<S453>/Add4'
   *  Sum: '<S453>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S452>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S452>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S453>/Sign3' incorporates:
   *  Sum: '<S453>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S453>/Sign4' incorporates:
   *  Sum: '<S453>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S453>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S453>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S453>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S453>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

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
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S443>/Motion State'
 *    '<S375>/Motion State'
 *    '<S208>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S443>/Motion State'
 *    '<S375>/Motion State'
 *    '<S208>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S443>/Motion State'
 *    '<S375>/Motion State'
 *    '<S208>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S443>/Motion State' */
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

  /* End of Chart: '<S443>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S419>/NearbyRefWP'
 *    '<S184>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S457>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S362>/Hold Control'
 *    '<S143>/Hold Control'
 *    '<S72>/Hold Control'
 *    '<S100>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S365>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S362>/Hold Control'
 *    '<S143>/Hold Control'
 *    '<S72>/Hold Control'
 *    '<S100>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S365>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S362>/Hold Control'
 *    '<S143>/Hold Control'
 *    '<S72>/Hold Control'
 *    '<S100>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S365>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S365>/Sum' incorporates:
   *  Delay: '<S365>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S368>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S368>/Switch' incorporates:
   *  Constant: '<S368>/Constant'
   *  Constant: '<S369>/Constant'
   *  Product: '<S368>/Multiply'
   *  RelationalOperator: '<S369>/Compare'
   *  Sum: '<S368>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S368>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S368>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S368>/Switch' */

  /* Gain: '<S365>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S365>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S362>/Move Control'
 *    '<S143>/Move Control'
 *    '<S72>/Move Control'
 *    '<S100>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S371>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S371>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S362>/Move Control'
 *    '<S143>/Move Control'
 *    '<S72>/Move Control'
 *    '<S100>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S371>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S371>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S362>/Move Control'
 *    '<S143>/Move Control'
 *    '<S72>/Move Control'
 *    '<S100>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_ig;
  real32_T rtb_Subtract3_l;
  real32_T rtb_a_m;
  real32_T rtb_Add4_i3;
  real32_T rtb_a_p4;

  /* Product: '<S372>/Multiply1' incorporates:
   *  Constant: '<S372>/const1'
   *  DiscreteIntegrator: '<S371>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S370>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S370>/Dead Zone' */

  /* Sum: '<S372>/Add' incorporates:
   *  DiscreteIntegrator: '<S371>/Integrator1'
   *  Gain: '<S366>/Gain1'
   *  Gain: '<S370>/Gain'
   *  Sum: '<S371>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S372>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S372>/Sign' */

  /* Sum: '<S372>/Add2' incorporates:
   *  Abs: '<S372>/Abs'
   *  Gain: '<S372>/Gain'
   *  Gain: '<S372>/Gain1'
   *  Product: '<S372>/Multiply2'
   *  Product: '<S372>/Multiply3'
   *  Sqrt: '<S372>/Sqrt'
   *  Sum: '<S372>/Add1'
   *  Sum: '<S372>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S372>/Add4' */
  rtb_Add4_i3 = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S372>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_l + localC->d;

  /* Sum: '<S372>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S372>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S372>/Sign1' */

  /* Signum: '<S372>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S372>/Sign2' */

  /* Sum: '<S372>/Add5' incorporates:
   *  Gain: '<S372>/Gain2'
   *  Product: '<S372>/Multiply4'
   *  Sum: '<S372>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_l) * 0.5F * rtb_Add4_i3;

  /* SignalConversion: '<S366>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S371>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S371>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S371>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S372>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S372>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S372>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_i3 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_i3 = 1.0F;
  } else {
    rtb_Add4_i3 = rtb_a_m;
  }

  /* End of Signum: '<S372>/Sign5' */

  /* Signum: '<S372>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S372>/Sign3' */

  /* Signum: '<S372>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S372>/Sign4' */

  /* Signum: '<S372>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S372>/Sign6' */

  /* Update for DiscreteIntegrator: '<S371>/Integrator' incorporates:
   *  Constant: '<S372>/const'
   *  Gain: '<S372>/Gain3'
   *  Product: '<S372>/Divide'
   *  Product: '<S372>/Multiply5'
   *  Product: '<S372>/Multiply6'
   *  Sum: '<S372>/Subtract4'
   *  Sum: '<S372>/Subtract5'
   *  Sum: '<S372>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_i3) *
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

  /* BusAssignment: '<S348>/Bus Assignment' incorporates:
   *  Constant: '<S348>/Constant'
   *  Constant: '<S348>/Constant2'
   *  SignalConversion: '<S348>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S348>/Bus Assignment' */
}

/*
 * System initialize for atomic system:
 *    '<S144>/Motion State'
 *    '<S73>/Motion State'
 *    '<S101>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S144>/Motion State'
 *    '<S73>/Motion State'
 *    '<S101>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S144>/Motion State'
 *    '<S73>/Motion State'
 *    '<S101>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S144>/Motion State' */
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

  /* End of Chart: '<S144>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S51>/Move Control'
 *    '<S88>/Move Control'
 */
void FMS_MoveControl_l(real32_T rtu_FMS_In, real32_T rtu_FMS_In_l, uint32_T
  rtu_FMS_In_i, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_j;

  /* DeadZone: '<S60>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_j = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_j = 0.0F;
  } else {
    rtb_Gain1_j = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S60>/Dead Zone' */

  /* Gain: '<S55>/Gain1' incorporates:
   *  Gain: '<S60>/Gain'
   */
  rtb_Gain1_j = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_j *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S57>/Land_Speed'
   *  Constant: '<S58>/Constant'
   *  Constant: '<S59>/Constant'
   *  Gain: '<S57>/Gain'
   *  Logic: '<S55>/Logical Operator'
   *  MinMax: '<S57>/Min'
   *  RelationalOperator: '<S58>/Compare'
   *  RelationalOperator: '<S59>/Compare'
   *  S-Function (sfix_bitop): '<S55>/cmd_p valid'
   */
  if ((rtb_Gain1_j > 0.0F) && ((rtu_FMS_In_i & 256U) != 0U) && (rtu_FMS_In_l <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_j);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_j;
  }

  /* End of Switch: '<S55>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S52>/Motion Status'
 *    '<S89>/Motion Status'
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
 *    '<S89>/Motion Status'
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
 *    '<S89>/Motion Status'
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
  real_T rtb_Gain_d;
  real_T rtb_Sum3_l;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S489>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S490>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S490>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S490>/Multiply1' incorporates:
   *  Product: '<S490>/Multiply'
   */
  rtb_Gain_d = localC->ff * rtb_Sum2_ee;

  /* Product: '<S490>/Divide' incorporates:
   *  Constant: '<S490>/Constant'
   *  Constant: '<S490>/R'
   *  Sqrt: '<S490>/Sqrt'
   *  Sum: '<S490>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_d);

  /* Product: '<S490>/Product3' incorporates:
   *  Constant: '<S490>/Constant1'
   *  Product: '<S490>/Multiply1'
   *  Sum: '<S490>/Sum2'
   */
  rtb_Gain_d = 1.0 / (1.0 - rtb_Gain_d) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S490>/Multiply2' incorporates:
   *  Trigonometry: '<S490>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S489>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S494>/Abs' incorporates:
   *  Abs: '<S497>/Abs1'
   *  Switch: '<S494>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S494>/Switch1' incorporates:
   *  Abs: '<S494>/Abs'
   *  Bias: '<S494>/Bias2'
   *  Bias: '<S494>/Bias3'
   *  Constant: '<S491>/Constant'
   *  Constant: '<S491>/Constant1'
   *  Constant: '<S496>/Constant'
   *  Gain: '<S494>/Gain1'
   *  Product: '<S494>/Multiply'
   *  RelationalOperator: '<S496>/Compare'
   *  Switch: '<S491>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S497>/Switch1' incorporates:
     *  Bias: '<S497>/Bias2'
     *  Bias: '<S497>/Bias3'
     *  Constant: '<S497>/Constant'
     *  Constant: '<S498>/Constant'
     *  Math: '<S497>/Math Function'
     *  RelationalOperator: '<S498>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S497>/Switch1' */

    /* Signum: '<S494>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S494>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S491>/Sum' incorporates:
   *  Sum: '<S489>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S489>/Multiply' incorporates:
   *  Gain: '<S489>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_d;

  /* Switch: '<S493>/Switch1' incorporates:
   *  Abs: '<S493>/Abs1'
   *  Bias: '<S493>/Bias2'
   *  Bias: '<S493>/Bias3'
   *  Constant: '<S493>/Constant'
   *  Constant: '<S495>/Constant'
   *  Math: '<S493>/Math Function'
   *  RelationalOperator: '<S495>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S493>/Switch1' */

  /* Product: '<S489>/Multiply' incorporates:
   *  Gain: '<S489>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S489>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S492>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_d = cos(rtb_Sum2_ee);

  /* Sum: '<S492>/Sum2' incorporates:
   *  Product: '<S492>/Multiply1'
   *  Product: '<S492>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_d + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S492>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S492>/Multiply4' */
  rtb_Gain_d *= rtb_Sum_d;

  /* Sum: '<S492>/Sum3' */
  rtb_Sum3_l = rtb_Gain_d - rtb_Sum3_l;

  /* DataTypeConversion: '<S486>/Data Type Conversion' incorporates:
   *  Gain: '<S489>/Gain'
   *  Sum: '<S489>/Sum1'
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

    /* Delay: '<S15>/Delay' */
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

    /* End of Delay: '<S15>/Delay' */
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

    /* Delay: '<S15>/Delay' */
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

    /* End of Delay: '<S15>/Delay' */
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

    /* Delay: '<S15>/Delay' */
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

    /* End of Delay: '<S15>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Manual(void)
{
  FMS_B.target_mode = PilotMode_Manual;

  /* Delay: '<S15>/Delay' */
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
  /* RelationalOperator: '<S499>/Compare' incorporates:
   *  Abs: '<S488>/Abs'
   *  Constant: '<S499>/Constant'
   *  MinMax: '<S488>/Max'
   *  Sum: '<S488>/Sum'
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
              FMS_B.Cmd_In.local_psi = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
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
            FMS_B.Cmd_In.local_psi = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
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
      /* Reshape: '<S487>/Reshape' incorporates:
       *  Constant: '<S487>/Constant'
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
      FMS_B.Cmd_In.local_psi = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
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
        if (FMS_DW.valid_cmd && (FMS_B.Add == 0U)) {
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
  real32_T rtb_Saturation_n;
  real32_T rtb_Transpose[9];
  real32_T rtb_MatrixConcatenate3[3];
  real32_T rtb_Multiply_o[3];
  uint16_T rtb_Divide_b;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  real32_T rtb_Add3_c;
  real32_T rtb_Add4_j3;
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
  FMS_Error tmp_3;
  FMS_Error tmp_4;
  real32_T u1_tmp;
  uint32_T tmp_5;
  uint32_T tmp_6;
  uint32_T tmp_7;
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
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S14>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_m;
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
      FMS_B.target_mode = PilotMode_None;
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

  /* Sqrt: '<S509>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S509>/Square'
   *  Sum: '<S509>/Sum of Elements'
   */
  rtb_Saturation_n = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
    FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
    FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S505>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add3_c = FMS_U.INS_Out.quat[0] / rtb_Saturation_n;
  rtb_Divide_lr_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Saturation_n;
  rtb_Divide_lr_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_n;
  rtb_Saturation_n = FMS_U.INS_Out.quat[3] / rtb_Saturation_n;

  /* Math: '<S506>/Square' incorporates:
   *  Math: '<S507>/Square'
   *  Math: '<S508>/Square'
   */
  rtb_MathFunction_f_idx_0 = rtb_Add3_c * rtb_Add3_c;

  /* Math: '<S506>/Square2' incorporates:
   *  Math: '<S507>/Square2'
   *  Math: '<S508>/Square2'
   */
  rtb_Gain_fj = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

  /* Math: '<S506>/Square1' incorporates:
   *  Math: '<S507>/Square1'
   *  Math: '<S508>/Square1'
   */
  rtb_Add4_j3 = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1;

  /* Math: '<S506>/Square3' incorporates:
   *  Math: '<S507>/Square3'
   *  Math: '<S508>/Square3'
   */
  rtb_Sqrt_b = rtb_Saturation_n * rtb_Saturation_n;

  /* Sum: '<S506>/Subtract' incorporates:
   *  Math: '<S506>/Square'
   *  Math: '<S506>/Square1'
   *  Math: '<S506>/Square2'
   *  Math: '<S506>/Square3'
   *  Sum: '<S506>/Add'
   *  Sum: '<S506>/Add1'
   */
  rtb_Transpose[0] = (rtb_MathFunction_f_idx_0 + rtb_Add4_j3) - (rtb_Gain_fj +
    rtb_Sqrt_b);

  /* Product: '<S506>/Multiply' incorporates:
   *  Product: '<S507>/Multiply'
   */
  rtb_MathFunction_iq_idx_1 = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_2;

  /* Product: '<S506>/Multiply1' incorporates:
   *  Product: '<S507>/Multiply1'
   */
  rtb_MathFunction_f_idx_2 = rtb_Add3_c * rtb_Saturation_n;

  /* Gain: '<S506>/Gain' incorporates:
   *  Product: '<S506>/Multiply'
   *  Product: '<S506>/Multiply1'
   *  Sum: '<S506>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_MathFunction_iq_idx_1 - rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Product: '<S506>/Multiply2' incorporates:
   *  Product: '<S508>/Multiply'
   */
  rtb_Rem_p = rtb_Divide_lr_idx_1 * rtb_Saturation_n;

  /* Product: '<S506>/Multiply3' incorporates:
   *  Product: '<S508>/Multiply1'
   */
  rtb_TmpSignalConversionAtMath_0 = rtb_Add3_c * rtb_Divide_lr_idx_2;

  /* Gain: '<S506>/Gain1' incorporates:
   *  Product: '<S506>/Multiply2'
   *  Product: '<S506>/Multiply3'
   *  Sum: '<S506>/Add2'
   */
  rtb_Transpose[2] = (rtb_Rem_p + rtb_TmpSignalConversionAtMath_0) * 2.0F;

  /* Gain: '<S507>/Gain' incorporates:
   *  Sum: '<S507>/Add3'
   */
  rtb_Transpose[3] = (rtb_MathFunction_iq_idx_1 + rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Sum: '<S507>/Subtract' incorporates:
   *  Sum: '<S507>/Add'
   *  Sum: '<S507>/Add1'
   */
  rtb_Transpose[4] = (rtb_MathFunction_f_idx_0 + rtb_Gain_fj) - (rtb_Add4_j3 +
    rtb_Sqrt_b);

  /* Product: '<S507>/Multiply2' incorporates:
   *  Product: '<S508>/Multiply2'
   */
  rtb_MathFunction_iq_idx_1 = rtb_Divide_lr_idx_2 * rtb_Saturation_n;

  /* Product: '<S507>/Multiply3' incorporates:
   *  Product: '<S508>/Multiply3'
   */
  rtb_MathFunction_f_idx_2 = rtb_Add3_c * rtb_Divide_lr_idx_1;

  /* Gain: '<S507>/Gain1' incorporates:
   *  Product: '<S507>/Multiply2'
   *  Product: '<S507>/Multiply3'
   *  Sum: '<S507>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_MathFunction_iq_idx_1 - rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Gain: '<S508>/Gain' incorporates:
   *  Sum: '<S508>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Rem_p - rtb_TmpSignalConversionAtMath_0) * 2.0F;

  /* Gain: '<S508>/Gain1' incorporates:
   *  Sum: '<S508>/Add2'
   */
  rtb_Transpose[7] = (rtb_MathFunction_iq_idx_1 + rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Sum: '<S508>/Subtract' incorporates:
   *  Sum: '<S508>/Add'
   *  Sum: '<S508>/Add1'
   */
  rtb_Transpose[8] = (rtb_MathFunction_f_idx_0 + rtb_Sqrt_b) - (rtb_Add4_j3 +
    rtb_Gain_fj);

  /* Math: '<S7>/Transpose' */
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

  /* DiscreteIntegrator: '<S500>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Multiply_o[0];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply_o[1];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply_o[2];
  }

  /* Product: '<S7>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S7>/Sum of Elements'
   */
  rtb_Divide_b = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S502>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S502>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Product: '<S7>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S7>/Cos'
   *  Trigonometry: '<S7>/Cos1'
   */
  rtb_Gain_fj = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32(FMS_U.INS_Out.theta);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Gain_fj > 1.0F) {
    rtb_Gain_fj = 1.0F;
  } else {
    if (rtb_Gain_fj < 0.9F) {
      rtb_Gain_fj = 0.9F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Land_Lock_Thro'
   */
  rtb_Divide_lr_idx_2 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_Gain_fj;

  /* DiscreteIntegrator: '<S501>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_lr_idx_2;
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S500>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S501>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S502>/Discrete-Time Integrator5'
   *  Logic: '<S503>/AND'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S503>/Lower Test'
   *  RelationalOperator: '<S503>/Upper Test'
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
   *  Delay: '<S15>/Delay'
   *  RelationalOperator: '<S4>/Equal'
   */
  if (FMS_DW.Delay_DSTATE_c == FMS_B.target_mode) {
    tmp_3 = FMS_Error_None;
  } else {
    tmp_3 = FMS_Error_ModeDegradation;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant1'
   */
  if (FMS_B.LogicalOperator2) {
    tmp_4 = FMS_Error_LostLink;
  } else {
    tmp_4 = FMS_Error_None;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Sum: '<S484>/Add' incorporates:
   *  DataTypeConversion: '<S27>/Data Type Conversion'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   */
  FMS_B.Add = (uint32_T)tmp_3 + (uint32_T)tmp_4;

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
        /* Disable for SwitchCase: '<S442>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S432>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S374>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S352>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S362>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S37>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S156>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S207>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S197>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S156>/Mission_SubSystem' */
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
        /* Disable for SwitchCase: '<S143>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S51>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S72>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S88>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S113>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S100>/Switch Case' */
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
          /* Disable for SwitchCase: '<S442>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S432>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S374>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S352>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S362>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S156>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S207>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S197>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S156>/Mission_SubSystem' */
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
          /* Disable for SwitchCase: '<S143>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S51>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S72>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S88>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S113>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S100>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S32>/SubMode' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      /* SwitchCase: '<S39>/Switch Case' incorporates:
       *  Math: '<S464>/Math Function'
       *  Product: '<S466>/Divide'
       *  Sum: '<S420>/Subtract'
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
          /* Disable for SwitchCase: '<S442>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S432>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S374>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S352>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S362>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Takeoff' incorporates:
           *  ActionPort: '<S347>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S482>/cur_waypoint'
           *  DiscreteIntegrator: '<S478>/Integrator'
           *  DiscreteIntegrator: '<S478>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Takeoff' incorporates:
         *  ActionPort: '<S347>/Action Port'
         */
        /* Delay: '<S482>/cur_waypoint' incorporates:
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
        /* Product: '<S482>/Divide' incorporates:
         *  Delay: '<S482>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S482>/Sum1'
         *  Sum: '<S482>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Saturate: '<S482>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S482>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S483>/Trigonometric Function1' incorporates:
         *  Gain: '<S481>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S483>/Trigonometric Function3'
         */
        rtb_MathFunction_f_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[0] = rtb_MathFunction_f_idx_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S483>/Trigonometric Function' incorporates:
         *  Gain: '<S481>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S483>/Trigonometric Function2'
         */
        rtb_Gain_fj = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[1] = rtb_Gain_fj;

        /* SignalConversion: '<S483>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S483>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S483>/Gain' */
        rtb_Transpose[3] = -rtb_Gain_fj;

        /* Trigonometry: '<S483>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_MathFunction_f_idx_0;

        /* SignalConversion: '<S483>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S483>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S483>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S475>/Saturation1' */
        rtb_Add4_j3 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_MathFunction_f_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S475>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S482>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S482>/Multiply'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S475>/Sum'
         *  Sum: '<S482>/Sum3'
         *  Sum: '<S482>/Sum4'
         */
        rtb_Divide_lr_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Add3_c +
          FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_Saturation_n = ((FMS_B.Cmd_In.sp_waypoint[1] -
                             FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Add3_c +
                            FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S475>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Saturation_n + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Divide_lr_idx_1;
        }

        /* Saturate: '<S475>/Saturation1' incorporates:
         *  Gain: '<S475>/Gain2'
         *  Product: '<S475>/Multiply'
         */
        rtb_Gain_fj = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S347>/Bus Assignment1'
         *  Constant: '<S347>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S347>/Bus Assignment1' incorporates:
         *  Constant: '<S347>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S475>/Saturation1' */
        if (rtb_Gain_fj > rtb_Add4_j3) {
          /* BusAssignment: '<S347>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_j3;
        } else if (rtb_Gain_fj < rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S347>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_f_idx_0;
        } else {
          /* BusAssignment: '<S347>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_fj;
        }

        if (rtb_Add3_c > rtb_Add4_j3) {
          /* BusAssignment: '<S347>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_j3;
        } else if (rtb_Add3_c < rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S347>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_f_idx_0;
        } else {
          /* BusAssignment: '<S347>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S347>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S478>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S479>/Multiply1' incorporates:
         *  Constant: '<S479>/const1'
         *  DiscreteIntegrator: '<S478>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S474>/Switch' incorporates:
         *  Abs: '<S474>/Abs'
         *  Abs: '<S474>/Abs1'
         *  Constant: '<S474>/Takeoff_Speed'
         *  Constant: '<S476>/Constant'
         *  Constant: '<S477>/Constant'
         *  Gain: '<S474>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S474>/Logical Operator'
         *  RelationalOperator: '<S476>/Compare'
         *  RelationalOperator: '<S477>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S474>/Sum'
         *  Sum: '<S474>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_Saturation_n = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_Saturation_n = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S474>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S479>/Add' incorporates:
         *  DiscreteIntegrator: '<S478>/Integrator1'
         *  Sum: '<S478>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_a - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S479>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_lr_idx_1;
        }

        /* End of Signum: '<S479>/Sign' */

        /* Sum: '<S479>/Add2' incorporates:
         *  Abs: '<S479>/Abs'
         *  Gain: '<S479>/Gain'
         *  Gain: '<S479>/Gain1'
         *  Product: '<S479>/Multiply2'
         *  Product: '<S479>/Multiply3'
         *  Sqrt: '<S479>/Sqrt'
         *  Sum: '<S479>/Add1'
         *  Sum: '<S479>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) +
          FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
          rtb_Saturation_n + rtb_Add3_c;

        /* Sum: '<S479>/Add4' */
        rtb_Add4_j3 = (rtb_Divide_lr_idx_1 - rtb_Saturation_n) + rtb_Add3_c;

        /* Sum: '<S479>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_ConstB.d_m;

        /* Sum: '<S479>/Subtract1' */
        rtb_Divide_lr_idx_1 -= FMS_ConstB.d_m;

        /* Signum: '<S479>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S479>/Sign1' */

        /* Signum: '<S479>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S479>/Sign2' */

        /* Sum: '<S479>/Add5' incorporates:
         *  Gain: '<S479>/Gain2'
         *  Product: '<S479>/Multiply4'
         *  Sum: '<S479>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F *
          rtb_Add4_j3;

        /* Update for Delay: '<S482>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S478>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S478>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S479>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - FMS_ConstB.d_m;

        /* Sum: '<S479>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_Saturation_n + FMS_ConstB.d_m;

        /* Signum: '<S479>/Sign5' incorporates:
         *  Signum: '<S479>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;

          /* Signum: '<S479>/Sign6' */
          rtb_Add4_j3 = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;

          /* Signum: '<S479>/Sign6' */
          rtb_Add4_j3 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_Saturation_n;

          /* Signum: '<S479>/Sign6' */
          rtb_Add4_j3 = rtb_Saturation_n;
        }

        /* End of Signum: '<S479>/Sign5' */

        /* Signum: '<S479>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S479>/Sign3' */

        /* Signum: '<S479>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S479>/Sign4' */

        /* Update for DiscreteIntegrator: '<S478>/Integrator' incorporates:
         *  Constant: '<S479>/const'
         *  Gain: '<S479>/Gain3'
         *  Product: '<S479>/Divide'
         *  Product: '<S479>/Multiply5'
         *  Product: '<S479>/Multiply6'
         *  Sum: '<S479>/Subtract4'
         *  Sum: '<S479>/Subtract5'
         *  Sum: '<S479>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_Saturation_n / FMS_ConstB.d_m -
          rtb_MathFunction_f_idx_0) * FMS_ConstB.Gain4_a * ((rtb_Divide_lr_idx_1
          - rtb_Add3_c) * 0.5F) - rtb_Add4_j3 * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Land' incorporates:
           *  ActionPort: '<S345>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S390>/Integrator'
           *  DiscreteIntegrator: '<S390>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Land' incorporates:
         *  ActionPort: '<S345>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S395>/Trigonometric Function1' incorporates:
         *  Gain: '<S394>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S395>/Trigonometric Function' incorporates:
         *  Gain: '<S394>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S395>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S395>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S395>/Gain' incorporates:
         *  Gain: '<S394>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S395>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S395>/Trigonometric Function3' incorporates:
         *  Gain: '<S394>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S395>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S395>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S395>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S388>/Saturation1' */
        rtb_MathFunction_f_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Add4_j3 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S392>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S392>/Sum'
         */
        rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S392>/Multiply' incorporates:
         *  SignalConversion: '<S392>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Saturation_n + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Divide_lr_idx_1;
        }

        /* End of Product: '<S392>/Multiply' */

        /* Saturate: '<S388>/Saturation1' incorporates:
         *  Gain: '<S392>/Gain2'
         */
        rtb_Gain_fj = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S345>/Bus Assignment1'
         *  Constant: '<S345>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S345>/Bus Assignment1' incorporates:
         *  Constant: '<S345>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S388>/Saturation1' */
        if (rtb_Gain_fj > rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S345>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_f_idx_0;
        } else if (rtb_Gain_fj < rtb_Add4_j3) {
          /* BusAssignment: '<S345>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_j3;
        } else {
          /* BusAssignment: '<S345>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_fj;
        }

        if (rtb_Add3_c > rtb_MathFunction_f_idx_0) {
          /* BusAssignment: '<S345>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_f_idx_0;
        } else if (rtb_Add3_c < rtb_Add4_j3) {
          /* BusAssignment: '<S345>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_j3;
        } else {
          /* BusAssignment: '<S345>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S345>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S390>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S391>/Multiply1' incorporates:
         *  Constant: '<S391>/const1'
         *  DiscreteIntegrator: '<S390>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S387>/Switch' incorporates:
         *  Constant: '<S387>/Land_Speed'
         *  Constant: '<S389>/Constant'
         *  Gain: '<S387>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S387>/Logical Operator'
         *  RelationalOperator: '<S389>/Compare'
         *  S-Function (sfix_bitop): '<S387>/cmd_p valid'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_Saturation_n = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_Saturation_n = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S387>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S391>/Add' incorporates:
         *  DiscreteIntegrator: '<S390>/Integrator1'
         *  Sum: '<S390>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_j - rtb_Saturation_n) +
          rtb_Add3_c;

        /* Signum: '<S391>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_lr_idx_1;
        }

        /* End of Signum: '<S391>/Sign' */

        /* Sum: '<S391>/Add2' incorporates:
         *  Abs: '<S391>/Abs'
         *  Gain: '<S391>/Gain'
         *  Gain: '<S391>/Gain1'
         *  Product: '<S391>/Multiply2'
         *  Product: '<S391>/Multiply3'
         *  Sqrt: '<S391>/Sqrt'
         *  Sum: '<S391>/Add1'
         *  Sum: '<S391>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) +
          FMS_ConstB.d_p) * FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F *
          rtb_Saturation_n + rtb_Add3_c;

        /* Sum: '<S391>/Add4' */
        rtb_Add4_j3 = (rtb_Divide_lr_idx_1 - rtb_Saturation_n) + rtb_Add3_c;

        /* Sum: '<S391>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_ConstB.d_p;

        /* Sum: '<S391>/Subtract1' */
        rtb_Divide_lr_idx_1 -= FMS_ConstB.d_p;

        /* Signum: '<S391>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S391>/Sign1' */

        /* Signum: '<S391>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S391>/Sign2' */

        /* Sum: '<S391>/Add5' incorporates:
         *  Gain: '<S391>/Gain2'
         *  Product: '<S391>/Multiply4'
         *  Sum: '<S391>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F *
          rtb_Add4_j3;

        /* Update for DiscreteIntegrator: '<S390>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S390>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S391>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - FMS_ConstB.d_p;

        /* Sum: '<S391>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_Saturation_n + FMS_ConstB.d_p;

        /* Signum: '<S391>/Sign5' incorporates:
         *  Signum: '<S391>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;

          /* Signum: '<S391>/Sign6' */
          rtb_Add4_j3 = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;

          /* Signum: '<S391>/Sign6' */
          rtb_Add4_j3 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_Saturation_n;

          /* Signum: '<S391>/Sign6' */
          rtb_Add4_j3 = rtb_Saturation_n;
        }

        /* End of Signum: '<S391>/Sign5' */

        /* Signum: '<S391>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S391>/Sign3' */

        /* Signum: '<S391>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S391>/Sign4' */

        /* Update for DiscreteIntegrator: '<S390>/Integrator' incorporates:
         *  Constant: '<S391>/const'
         *  Gain: '<S391>/Gain3'
         *  Product: '<S391>/Divide'
         *  Product: '<S391>/Multiply5'
         *  Product: '<S391>/Multiply6'
         *  Sum: '<S391>/Subtract4'
         *  Sum: '<S391>/Subtract5'
         *  Sum: '<S391>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_Saturation_n / FMS_ConstB.d_p -
          rtb_MathFunction_f_idx_0) * FMS_ConstB.Gain4_e * ((rtb_Divide_lr_idx_1
          - rtb_Add3_c) * 0.5F) - rtb_Add4_j3 * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Return' incorporates:
           *  ActionPort: '<S346>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S398>/Delay'
           *  Delay: '<S399>/Delay'
           *  Delay: '<S421>/Delay'
           *  DiscreteIntegrator: '<S402>/Integrator'
           *  DiscreteIntegrator: '<S402>/Integrator1'
           *  DiscreteIntegrator: '<S417>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S422>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S469>/Discrete-Time Integrator'
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
           *  ActionPort: '<S346>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S433>/Motion Status'
           *  Chart: '<S443>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S39>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Return' incorporates:
         *  ActionPort: '<S346>/Action Port'
         */
        /* Delay: '<S421>/Delay' incorporates:
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
        /* Switch: '<S417>/Switch2' incorporates:
         *  Constant: '<S417>/vel'
         *  Constant: '<S426>/Constant'
         *  RelationalOperator: '<S426>/Compare'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_Add4_j3 = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_Add4_j3 = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S417>/Switch2' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* RelationalOperator: '<S416>/Compare' incorporates:
         *  Constant: '<S473>/Constant'
         *  DiscreteIntegrator: '<S422>/Discrete-Time Integrator'
         *  RelationalOperator: '<S473>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* DiscreteIntegrator: '<S417>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S443>/Motion State' incorporates:
         *  Constant: '<S443>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S443>/Square'
         *  Math: '<S443>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S443>/Sqrt'
         *  Sum: '<S443>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S442>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S442>/Hold Control' incorporates:
             *  ActionPort: '<S445>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S442>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S442>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S442>/Hold Control' incorporates:
           *  ActionPort: '<S445>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S442>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S442>/Brake Control' incorporates:
           *  ActionPort: '<S444>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S442>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S442>/Move Control' incorporates:
             *  ActionPort: '<S446>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S442>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_j);

            /* End of SystemReset for SubSystem: '<S442>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S442>/Move Control' incorporates:
           *  ActionPort: '<S446>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_a,
                            &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S442>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S442>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S433>/Motion Status' incorporates:
         *  Abs: '<S433>/Abs'
         *  Constant: '<S433>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S432>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S432>/Hold Control' incorporates:
             *  ActionPort: '<S435>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S432>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S432>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S432>/Hold Control' incorporates:
           *  ActionPort: '<S435>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_jj,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S432>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S432>/Brake Control' incorporates:
           *  ActionPort: '<S434>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_jj);

          /* End of Outputs for SubSystem: '<S432>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S432>/Move Control' incorporates:
             *  ActionPort: '<S436>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S432>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S432>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S432>/Move Control' incorporates:
           *  ActionPort: '<S436>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_jj,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S432>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S432>/Switch Case' */

        /* Switch: '<S397>/Switch' incorporates:
         *  Product: '<S421>/Multiply'
         *  Sum: '<S421>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S442>/Saturation1' */
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

          /* End of Saturate: '<S442>/Saturation1' */

          /* Saturate: '<S432>/Saturation1' */
          if (FMS_B.Merge_jj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_jj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_jj;
          }

          /* End of Saturate: '<S432>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S421>/Sum' incorporates:
           *  Delay: '<S421>/Delay'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S470>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S417>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_l_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Add3_c = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S421>/Sum' incorporates:
           *  Delay: '<S421>/Delay'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* Sum: '<S417>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_TmpSignalConversionAtMath_0 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sqrt: '<S429>/Sqrt' incorporates:
           *  Math: '<S429>/Square'
           *  Sum: '<S417>/Sum'
           *  Sum: '<S429>/Sum of Elements'
           */
          rtb_Sqrt_b = sqrtf(rtb_P_l_idx_0 * rtb_P_l_idx_0 +
                             rtb_TmpSignalConversionAtMath_0 *
                             rtb_TmpSignalConversionAtMath_0);

          /* SignalConversion: '<S472>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* SignalConversion: '<S472>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S472>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S471>/Gain' incorporates:
           *  DiscreteIntegrator: '<S469>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S469>/Add'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S472>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S472>/Trigonometric Function1'
           */
          rtb_MathFunction_f_idx_0 = arm_cos_f32(rtb_Saturation_n);
          rtb_Transpose[4] = rtb_MathFunction_f_idx_0;

          /* Trigonometry: '<S472>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S472>/Trigonometric Function'
           */
          rtb_Gain_fj = arm_sin_f32(rtb_Saturation_n);

          /* Gain: '<S472>/Gain' incorporates:
           *  Trigonometry: '<S472>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Gain_fj;

          /* SignalConversion: '<S472>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S472>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S472>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Gain_fj;

          /* Trigonometry: '<S472>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_f_idx_0;

          /* Switch: '<S428>/Switch2' incorporates:
           *  Constant: '<S417>/Constant2'
           *  DiscreteIntegrator: '<S417>/Acceleration_Speed'
           *  RelationalOperator: '<S428>/LowerRelop1'
           *  RelationalOperator: '<S428>/UpperRelop'
           *  Switch: '<S428>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_Add4_j3) {
            rtb_Saturation_n = rtb_Add4_j3;
          } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
            /* Switch: '<S428>/Switch' incorporates:
             *  Constant: '<S417>/Constant2'
             */
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_DW.Acceleration_Speed_DSTATE_j;
          }

          /* End of Switch: '<S428>/Switch2' */

          /* Switch: '<S417>/Switch' */
          if (rtb_Sqrt_b > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_Add4_j3;
          } else {
            /* Gain: '<S417>/Gain' */
            rtb_Gain_fj = 0.5F * rtb_Sqrt_b;

            /* Switch: '<S427>/Switch2' incorporates:
             *  Constant: '<S417>/Constant1'
             *  RelationalOperator: '<S427>/LowerRelop1'
             *  RelationalOperator: '<S427>/UpperRelop'
             *  Switch: '<S427>/Switch'
             */
            if (rtb_Gain_fj > rtb_Add4_j3) {
              rtb_Gain_fj = rtb_Add4_j3;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S427>/Switch' incorporates:
                 *  Constant: '<S417>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S427>/Switch2' */
          }

          /* End of Switch: '<S417>/Switch' */

          /* Switch: '<S417>/Switch1' incorporates:
           *  Sum: '<S417>/Sum1'
           */
          if (rtb_Saturation_n - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_Saturation_n;
          }

          /* End of Switch: '<S417>/Switch1' */

          /* Sum: '<S470>/Sum of Elements' incorporates:
           *  Math: '<S470>/Math Function'
           */
          rtb_Saturation_n = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Divide_lr_idx_1 *
            rtb_Divide_lr_idx_1;

          /* Math: '<S470>/Math Function1' incorporates:
           *  Sum: '<S470>/Sum of Elements'
           *
           * About '<S470>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S470>/Math Function1' */

          /* Switch: '<S470>/Switch' incorporates:
           *  Constant: '<S470>/Constant'
           *  Product: '<S470>/Product'
           */
          if (rtb_Saturation_n <= 0.0F) {
            rtb_Add3_c = 0.0F;
            rtb_Divide_lr_idx_1 = 0.0F;
            rtb_Saturation_n = 1.0F;
          }

          /* End of Switch: '<S470>/Switch' */

          /* Product: '<S468>/Multiply2' incorporates:
           *  Product: '<S470>/Divide'
           */
          rtb_MathFunction_f_idx_0 = rtb_Add3_c / rtb_Saturation_n * rtb_Gain_fj;
          rtb_Gain_fj *= rtb_Divide_lr_idx_1 / rtb_Saturation_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S423>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S423>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_n = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sqrt_b = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S423>/Divide' incorporates:
           *  Math: '<S424>/Square'
           *  Math: '<S425>/Square'
           *  Sqrt: '<S424>/Sqrt'
           *  Sqrt: '<S425>/Sqrt'
           *  Sum: '<S423>/Sum'
           *  Sum: '<S423>/Sum1'
           *  Sum: '<S424>/Sum of Elements'
           *  Sum: '<S425>/Sum of Elements'
           */
          rtb_Saturation_n = sqrtf(rtb_Saturation_n * rtb_Saturation_n +
            rtb_Sqrt_b * rtb_Sqrt_b) / sqrtf(rtb_Add3_c * rtb_Add3_c +
            rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1);

          /* Saturate: '<S423>/Saturation' */
          if (rtb_Saturation_n > 1.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            if (rtb_Saturation_n < 0.0F) {
              rtb_Saturation_n = 0.0F;
            }
          }

          /* End of Saturate: '<S423>/Saturation' */

          /* Product: '<S421>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_MathFunction_f_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S414>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S423>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S414>/Sum2'
           *  Sum: '<S423>/Add'
           *  Sum: '<S423>/Subtract'
           */
          rtb_Gain_fj = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_n +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S414>/Saturation1' incorporates:
           *  Product: '<S421>/Multiply'
           */
          if (rtb_Gain_fj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Gain_fj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Gain_fj;
          }

          /* End of Saturate: '<S414>/Saturation1' */
        }

        /* End of Switch: '<S397>/Switch' */

        /* Delay: '<S399>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S402>/Integrator1' incorporates:
         *  Delay: '<S399>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_eh = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S406>/Rem' incorporates:
         *  Constant: '<S406>/Constant1'
         *  DiscreteIntegrator: '<S402>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S401>/Sum'
         */
        rtb_Add3_c = rt_remf(FMS_DW.Integrator1_DSTATE_eh - FMS_U.INS_Out.psi,
                             6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S406>/Switch' incorporates:
         *  Abs: '<S406>/Abs'
         *  Constant: '<S406>/Constant'
         *  Constant: '<S407>/Constant'
         *  Product: '<S406>/Multiply'
         *  RelationalOperator: '<S407>/Compare'
         *  Sum: '<S406>/Add'
         */
        if (fabsf(rtb_Add3_c) > 3.14159274F) {
          /* Signum: '<S406>/Sign' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else if (rtb_Add3_c > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          } else {
            rtb_Divide_lr_idx_1 = rtb_Add3_c;
          }

          /* End of Signum: '<S406>/Sign' */
          rtb_Add3_c -= 6.28318548F * rtb_Divide_lr_idx_1;
        }

        /* End of Switch: '<S406>/Switch' */

        /* Gain: '<S401>/Gain2' */
        rtb_Add3_c *= FMS_PARAM.YAW_P;

        /* Saturate: '<S401>/Saturation' */
        if (rtb_Add3_c > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Add3_c = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Add3_c < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Add3_c = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S401>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S346>/Bus Assignment1'
         *  Constant: '<S346>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S346>/Bus Assignment1' incorporates:
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
        /* Sum: '<S463>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S463>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S461>/Sum of Elements'
         */
        rtb_Saturation_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S463>/Math Function1' incorporates:
         *  Sum: '<S463>/Sum of Elements'
         *
         * About '<S463>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Add3_c = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S463>/Math Function1' */

        /* Switch: '<S463>/Switch' incorporates:
         *  Constant: '<S463>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S463>/Product'
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

        /* End of Switch: '<S463>/Switch' */

        /* Delay: '<S398>/Delay' incorporates:
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
        /* Sum: '<S346>/Sum' incorporates:
         *  Delay: '<S398>/Delay'
         *  MATLAB Function: '<S419>/OutRegionRegWP'
         *  MATLAB Function: '<S419>/SearchL1RefWP'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S413>/Sum of Elements' incorporates:
         *  Math: '<S413>/Math Function'
         *  Sum: '<S346>/Sum'
         */
        rtb_Divide_lr_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_P_l_idx_0 * rtb_P_l_idx_0;

        /* Math: '<S413>/Math Function1' incorporates:
         *  Sum: '<S413>/Sum of Elements'
         *
         * About '<S413>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S413>/Math Function1' */

        /* Switch: '<S413>/Switch' incorporates:
         *  Constant: '<S413>/Constant'
         *  Product: '<S413>/Product'
         *  Sum: '<S346>/Sum'
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

        /* End of Switch: '<S413>/Switch' */

        /* Product: '<S463>/Divide' */
        rtb_Sum_ff[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S466>/Sum of Elements' incorporates:
         *  Math: '<S466>/Math Function'
         *  SignalConversion: '<S466>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_1 = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] *
          rtb_Sum_ff[0];

        /* Math: '<S466>/Math Function1' incorporates:
         *  Sum: '<S466>/Sum of Elements'
         *
         * About '<S466>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Add3_c = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S466>/Math Function1' */

        /* Switch: '<S466>/Switch' incorporates:
         *  Constant: '<S466>/Constant'
         *  Product: '<S466>/Product'
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

        /* End of Switch: '<S466>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S419>/NearbyRefWP' incorporates:
         *  Constant: '<S346>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_ff, &rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* MATLAB Function: '<S419>/SearchL1RefWP' incorporates:
         *  Constant: '<S346>/L1'
         *  Delay: '<S398>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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
          rtb_Sqrt_b = rtb_P_l_idx_0 * rtb_Add3_c + FMS_DW.Delay_DSTATE_p[0];
          rtb_MathFunction_iq_idx_1 = rtb_TmpSignalConversionAtMath_0 *
            rtb_Add3_c + FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S419>/OutRegionRegWP' incorporates:
         *  Delay: '<S398>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Divide_lr_idx_1 = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
          rtb_TmpSignalConversionAtMath_0 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE_p[0]) * rtb_P_l_idx_0) / (rtb_P_l_idx_0 *
          rtb_P_l_idx_0 + rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Divide_lr_idx_1 <= 0.0F);
        rtb_LogicalOperator_es = (rtb_Divide_lr_idx_1 >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_l_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_es) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_P_l_idx_0 = rtb_Divide_lr_idx_1 * rtb_P_l_idx_0 +
            FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S419>/Switch1' incorporates:
         *  Constant: '<S456>/Constant'
         *  RelationalOperator: '<S456>/Compare'
         */
        if (rtb_Rem_p <= 0.0F) {
          /* Switch: '<S419>/Switch' incorporates:
           *  Constant: '<S455>/Constant'
           *  MATLAB Function: '<S419>/SearchL1RefWP'
           *  RelationalOperator: '<S455>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Sum_ff[0] = rtb_Sqrt_b;
            rtb_Sum_ff[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S419>/OutRegionRegWP' incorporates:
             *  Delay: '<S398>/Delay'
             *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_ff[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_es) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else {
              rtb_Sum_ff[1] = rtb_Divide_lr_idx_1 *
                rtb_TmpSignalConversionAtMath_0 + FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S419>/Switch' */
        }

        /* End of Switch: '<S419>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S420>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Rem_p = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Rem_p;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Rem_p * rtb_Rem_p;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S420>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S464>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Rem_p = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S464>/Math Function' incorporates:
         *  Math: '<S462>/Square'
         */
        rtb_Divide_lr_idx_1 = rtb_Rem_p * rtb_Rem_p;

        /* Sum: '<S464>/Sum of Elements' incorporates:
         *  Math: '<S464>/Math Function'
         */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

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
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Rem_p;
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
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S467>/Sum of Elements' incorporates:
         *  Math: '<S467>/Math Function'
         *  SignalConversion: '<S467>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add3_c = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S467>/Math Function1' incorporates:
         *  Sum: '<S467>/Sum of Elements'
         *
         * About '<S467>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          rtb_Add3_c = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S467>/Math Function1' */

        /* Switch: '<S467>/Switch' incorporates:
         *  Constant: '<S467>/Constant'
         *  Product: '<S467>/Product'
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

        /* End of Switch: '<S467>/Switch' */

        /* Product: '<S467>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S462>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S413>/Divide' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S467>/Divide' incorporates:
         *  Product: '<S466>/Divide'
         */
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S466>/Divide' */
        rtb_Rem_p = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S413>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Gain_fj / rtb_MathFunction_f_idx_2;

        /* Sqrt: '<S461>/Sqrt' */
        rtb_Add3_c = sqrtf(rtb_Saturation_n);

        /* Gain: '<S420>/Gain' incorporates:
         *  Math: '<S420>/Square'
         */
        rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c * 2.0F;

        /* Sum: '<S465>/Subtract' incorporates:
         *  Product: '<S465>/Multiply'
         *  Product: '<S465>/Multiply1'
         */
        rtb_Add3_c = rtb_TmpSignalConversionAtMath_0 * rtb_Rem_p - rtb_P_l_idx_0
          * rtb_Sum_ff[0];

        /* Signum: '<S460>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S460>/Sign1' */

        /* Switch: '<S460>/Switch2' incorporates:
         *  Constant: '<S460>/Constant4'
         */
        if (rtb_Add3_c == 0.0F) {
          rtb_Add3_c = 1.0F;
        }

        /* End of Switch: '<S460>/Switch2' */

        /* DotProduct: '<S460>/Dot Product' */
        rtb_Rem_p = rtb_Sum_ff[0] * rtb_TmpSignalConversionAtMath_0 + rtb_Rem_p *
          rtb_P_l_idx_0;

        /* Trigonometry: '<S460>/Acos' incorporates:
         *  DotProduct: '<S460>/Dot Product'
         */
        if (rtb_Rem_p > 1.0F) {
          rtb_Rem_p = 1.0F;
        } else {
          if (rtb_Rem_p < -1.0F) {
            rtb_Rem_p = -1.0F;
          }
        }

        /* Product: '<S460>/Multiply' incorporates:
         *  Trigonometry: '<S460>/Acos'
         */
        rtb_Add3_c *= acosf(rtb_Rem_p);

        /* Saturate: '<S420>/Saturation' */
        if (rtb_Add3_c > 1.57079637F) {
          rtb_Add3_c = 1.57079637F;
        } else {
          if (rtb_Add3_c < -1.57079637F) {
            rtb_Add3_c = -1.57079637F;
          }
        }

        /* End of Saturate: '<S420>/Saturation' */

        /* Product: '<S420>/Divide' incorporates:
         *  Constant: '<S346>/L1'
         *  Constant: '<S420>/Constant'
         *  MinMax: '<S420>/Max'
         *  MinMax: '<S420>/Min'
         *  Product: '<S420>/Multiply1'
         *  Sqrt: '<S462>/Sqrt'
         *  Sum: '<S462>/Sum of Elements'
         *  Trigonometry: '<S420>/Sin'
         */
        rtb_Saturation_n = arm_sin_f32(rtb_Add3_c) * rtb_Saturation_n / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Divide_lr_idx_1 +
             rtb_TmpSignalConversionAtDela_a[0]), 0.5F));

        /* Sum: '<S411>/Subtract' incorporates:
         *  Product: '<S411>/Multiply'
         *  Product: '<S411>/Multiply1'
         */
        rtb_MathFunction_f_idx_2 = rtb_Sqrt_b * FMS_ConstB.Divide_d[1] -
          rtb_MathFunction_iq_idx_1 * FMS_ConstB.Divide_d[0];

        /* Signum: '<S400>/Sign1' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_2 > 0.0F) {
            rtb_MathFunction_f_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S400>/Sign1' */

        /* Switch: '<S400>/Switch2' incorporates:
         *  Constant: '<S400>/Constant4'
         */
        if (rtb_MathFunction_f_idx_2 == 0.0F) {
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S400>/Switch2' */

        /* DotProduct: '<S400>/Dot Product' */
        rtb_Gain_fj = FMS_ConstB.Divide_d[0] * rtb_Sqrt_b + FMS_ConstB.Divide_d
          [1] * rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S400>/Acos' incorporates:
         *  DotProduct: '<S400>/Dot Product'
         */
        if (rtb_Gain_fj > 1.0F) {
          rtb_Gain_fj = 1.0F;
        } else {
          if (rtb_Gain_fj < -1.0F) {
            rtb_Gain_fj = -1.0F;
          }
        }

        /* Product: '<S400>/Multiply' incorporates:
         *  Trigonometry: '<S400>/Acos'
         */
        rtb_MathFunction_f_idx_2 *= acosf(rtb_Gain_fj);

        /* Math: '<S403>/Rem' incorporates:
         *  Constant: '<S403>/Constant1'
         *  Delay: '<S399>/Delay'
         *  Sum: '<S399>/Sum2'
         */
        rtb_Add3_c = rt_remf(rtb_MathFunction_f_idx_2 - FMS_DW.Delay_DSTATE_a,
                             6.28318548F);

        /* Switch: '<S403>/Switch' incorporates:
         *  Abs: '<S403>/Abs'
         *  Constant: '<S403>/Constant'
         *  Constant: '<S409>/Constant'
         *  Product: '<S403>/Multiply'
         *  RelationalOperator: '<S409>/Compare'
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

        /* Sum: '<S399>/Sum' incorporates:
         *  Delay: '<S399>/Delay'
         */
        rtb_Divide_lr_idx_1 = rtb_Add3_c + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S408>/Multiply1' incorporates:
         *  Constant: '<S408>/const1'
         *  DiscreteIntegrator: '<S402>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S408>/Add' incorporates:
         *  DiscreteIntegrator: '<S402>/Integrator1'
         *  Sum: '<S402>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_eh -
          rtb_Divide_lr_idx_1) + rtb_Add3_c;

        /* Signum: '<S408>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_Divide_lr_idx_1;
        }

        /* End of Signum: '<S408>/Sign' */

        /* Sum: '<S408>/Add2' incorporates:
         *  Abs: '<S408>/Abs'
         *  Gain: '<S408>/Gain'
         *  Gain: '<S408>/Gain1'
         *  Product: '<S408>/Multiply2'
         *  Product: '<S408>/Multiply3'
         *  Sqrt: '<S408>/Sqrt'
         *  Sum: '<S408>/Add1'
         *  Sum: '<S408>/Subtract'
         */
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) + FMS_ConstB.d_l) *
                           FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_MathFunction_f_idx_0 + rtb_Add3_c;

        /* Sum: '<S408>/Add4' */
        rtb_MathFunction_f_idx_0 = (rtb_Divide_lr_idx_1 - rtb_Rem_p) +
          rtb_Add3_c;

        /* Sum: '<S408>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_ConstB.d_l;

        /* Sum: '<S408>/Subtract1' */
        rtb_Divide_lr_idx_1 -= FMS_ConstB.d_l;

        /* Signum: '<S408>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S408>/Sign1' */

        /* Signum: '<S408>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S408>/Sign2' */

        /* Sum: '<S408>/Add5' incorporates:
         *  Gain: '<S408>/Gain2'
         *  Product: '<S408>/Multiply4'
         *  Sum: '<S408>/Subtract2'
         */
        rtb_Rem_p += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F *
          rtb_MathFunction_f_idx_0;

        /* Sum: '<S408>/Add6' */
        rtb_Add3_c = rtb_Rem_p + FMS_ConstB.d_l;

        /* Sum: '<S408>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_Rem_p - FMS_ConstB.d_l;

        /* Product: '<S408>/Divide' */
        rtb_Sqrt_b = rtb_Rem_p / FMS_ConstB.d_l;

        /* Signum: '<S408>/Sign5' incorporates:
         *  Signum: '<S408>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;

          /* Signum: '<S408>/Sign6' */
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;

          /* Signum: '<S408>/Sign6' */
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Rem_p;

          /* Signum: '<S408>/Sign6' */
          rtb_MathFunction_f_idx_0 = rtb_Rem_p;
        }

        /* End of Signum: '<S408>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S399>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_2 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S404>/Rem' incorporates:
         *  Constant: '<S404>/Constant1'
         */
        rtb_Rem_p = rt_remf(rtb_MathFunction_f_idx_2, 6.28318548F);

        /* Switch: '<S404>/Switch' incorporates:
         *  Abs: '<S404>/Abs'
         *  Constant: '<S404>/Constant'
         *  Constant: '<S410>/Constant'
         *  Product: '<S404>/Multiply'
         *  RelationalOperator: '<S410>/Compare'
         *  Sum: '<S404>/Add'
         */
        if (fabsf(rtb_Rem_p) > 3.14159274F) {
          /* Signum: '<S404>/Sign' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Gain_fj = 1.0F;
          } else {
            rtb_Gain_fj = rtb_Rem_p;
          }

          /* End of Signum: '<S404>/Sign' */
          rtb_Rem_p -= 6.28318548F * rtb_Gain_fj;
        }

        /* End of Switch: '<S404>/Switch' */

        /* Abs: '<S397>/Abs' */
        rtb_Rem_p = fabsf(rtb_Rem_p);

        /* Update for Delay: '<S421>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S422>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S415>/Constant'
         *  RelationalOperator: '<S415>/Compare'
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

        /* End of Update for DiscreteIntegrator: '<S422>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S417>/Acceleration_Speed' incorporates:
         *  Constant: '<S417>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Product: '<S421>/Divide1' */
        rtb_Gain_fj = rtb_Saturation_n / rtb_Add4_j3;

        /* Saturate: '<S421>/Saturation' */
        if (rtb_Gain_fj > 0.314159274F) {
          rtb_Gain_fj = 0.314159274F;
        } else {
          if (rtb_Gain_fj < -0.314159274F) {
            rtb_Gain_fj = -0.314159274F;
          }
        }

        /* End of Saturate: '<S421>/Saturation' */

        /* Update for DiscreteIntegrator: '<S469>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_Gain_fj;

        /* Update for Delay: '<S399>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S402>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S402>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_eh += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S398>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S408>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S408>/Sign3' */

        /* Signum: '<S408>/Sign4' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S408>/Sign4' */

        /* Update for DiscreteIntegrator: '<S402>/Integrator' incorporates:
         *  Constant: '<S408>/const'
         *  Gain: '<S408>/Gain3'
         *  Product: '<S408>/Multiply5'
         *  Product: '<S408>/Multiply6'
         *  Sum: '<S408>/Subtract4'
         *  Sum: '<S408>/Subtract5'
         *  Sum: '<S408>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1)
          * FMS_ConstB.Gain4_n * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S402>/Integrator' */
        /* End of Outputs for SubSystem: '<S39>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S39>/Hold' incorporates:
           *  ActionPort: '<S344>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S353>/Motion Status'
           *  Chart: '<S363>/Motion State'
           *  Chart: '<S375>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S39>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Hold' incorporates:
         *  ActionPort: '<S344>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S353>/Motion Status' incorporates:
         *  Abs: '<S353>/Abs'
         *  Constant: '<S353>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S363>/Motion State' incorporates:
         *  Abs: '<S363>/Abs'
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

        /* End of Chart: '<S363>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S375>/Motion State' incorporates:
         *  Constant: '<S375>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S375>/Square'
         *  Math: '<S375>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S375>/Sqrt'
         *  Sum: '<S375>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S374>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S374>/Hold Control' incorporates:
             *  ActionPort: '<S377>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S374>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S374>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S374>/Hold Control' incorporates:
           *  ActionPort: '<S377>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S374>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S374>/Brake Control' incorporates:
           *  ActionPort: '<S376>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S374>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S374>/Move Control' incorporates:
             *  ActionPort: '<S378>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S374>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S374>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S374>/Move Control' incorporates:
           *  ActionPort: '<S378>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S374>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S374>/Switch Case' */

        /* SwitchCase: '<S352>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S352>/Hold Control' incorporates:
             *  ActionPort: '<S355>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S352>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S352>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S352>/Hold Control' incorporates:
           *  ActionPort: '<S355>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S352>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S352>/Brake Control' incorporates:
           *  ActionPort: '<S354>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S352>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S352>/Move Control' incorporates:
             *  ActionPort: '<S356>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S352>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S352>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S352>/Move Control' incorporates:
           *  ActionPort: '<S356>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S352>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S352>/Switch Case' */

        /* SwitchCase: '<S362>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S362>/Hold Control' incorporates:
             *  ActionPort: '<S365>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S362>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S362>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S362>/Hold Control' incorporates:
           *  ActionPort: '<S365>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S362>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S362>/Brake Control' incorporates:
           *  ActionPort: '<S364>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S362>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S362>/Move Control' incorporates:
             *  ActionPort: '<S366>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S362>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S362>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S362>/Move Control' incorporates:
           *  ActionPort: '<S366>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S362>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S362>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S344>/Bus Assignment'
         *  Constant: '<S344>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S344>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S362>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S362>/Saturation' */

        /* Saturate: '<S374>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S374>/Saturation1' */

        /* Saturate: '<S352>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S344>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S352>/Saturation1' */
        /* End of Outputs for SubSystem: '<S39>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S39>/Unknown' incorporates:
         *  ActionPort: '<S348>/Action Port'
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
       *  Math: '<S227>/Square'
       *  Math: '<S229>/Math Function'
       *  Sum: '<S185>/Subtract'
       *  Sum: '<S242>/Sum1'
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
        /* Disable for Resettable SubSystem: '<S156>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S207>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S197>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S156>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S37>/Offboard' incorporates:
         *  ActionPort: '<S157>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S322>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S325>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S326>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S326>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S326>/Multiply1' incorporates:
         *  Product: '<S326>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S326>/Divide' incorporates:
         *  Constant: '<S326>/Constant'
         *  Constant: '<S326>/R'
         *  Sqrt: '<S326>/Sqrt'
         *  Sum: '<S326>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S326>/Product3' incorporates:
         *  Constant: '<S326>/Constant1'
         *  Product: '<S326>/Multiply1'
         *  Sum: '<S326>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S326>/Multiply2' incorporates:
         *  Trigonometry: '<S326>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S325>/Sum' incorporates:
         *  Gain: '<S322>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S330>/Abs' incorporates:
         *  Abs: '<S333>/Abs1'
         *  Switch: '<S330>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S330>/Switch1' incorporates:
         *  Abs: '<S330>/Abs'
         *  Bias: '<S330>/Bias2'
         *  Bias: '<S330>/Bias3'
         *  Constant: '<S327>/Constant'
         *  Constant: '<S327>/Constant1'
         *  Constant: '<S332>/Constant'
         *  Gain: '<S330>/Gain1'
         *  Product: '<S330>/Multiply'
         *  RelationalOperator: '<S332>/Compare'
         *  Switch: '<S327>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S333>/Switch1' incorporates:
           *  Bias: '<S333>/Bias2'
           *  Bias: '<S333>/Bias3'
           *  Constant: '<S333>/Constant'
           *  Constant: '<S334>/Constant'
           *  Math: '<S333>/Math Function'
           *  RelationalOperator: '<S334>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S333>/Switch1' */

          /* Signum: '<S330>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S330>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S327>/Sum' incorporates:
         *  Gain: '<S322>/Gain1'
         *  Gain: '<S322>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S325>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S325>/Multiply' incorporates:
         *  Gain: '<S325>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S329>/Switch1' incorporates:
         *  Abs: '<S329>/Abs1'
         *  Bias: '<S329>/Bias2'
         *  Bias: '<S329>/Bias3'
         *  Constant: '<S329>/Constant'
         *  Constant: '<S331>/Constant'
         *  Math: '<S329>/Math Function'
         *  RelationalOperator: '<S331>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S329>/Switch1' */

        /* Product: '<S325>/Multiply' incorporates:
         *  Gain: '<S325>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S303>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S307>/Multiply1'
         *  Product: '<S308>/Multiply3'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S316>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S316>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S316>/Trigonometric Function3' incorporates:
           *  Gain: '<S315>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S316>/Gain' incorporates:
           *  Gain: '<S315>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S316>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S316>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S316>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S316>/Trigonometric Function' incorporates:
           *  Gain: '<S315>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S316>/Trigonometric Function1' incorporates:
           *  Gain: '<S315>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S316>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S307>/Saturation' incorporates:
           *  Constant: '<S313>/Constant'
           *  Constant: '<S314>/Constant'
           *  Constant: '<S324>/Constant'
           *  DataTypeConversion: '<S322>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S306>/Logical Operator'
           *  Product: '<S307>/Multiply'
           *  Product: '<S328>/Multiply1'
           *  Product: '<S328>/Multiply2'
           *  RelationalOperator: '<S313>/Compare'
           *  RelationalOperator: '<S314>/Compare'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S306>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S321>/lat_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S307>/Sum1'
           *  Sum: '<S328>/Sum2'
           *  Switch: '<S309>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          rtb_Gain_fj = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.x_R : 0.0F;
          if (rtb_Gain_fj > 4.0F) {
            rtb_Gain_fj = 4.0F;
          } else {
            if (rtb_Gain_fj < -4.0F) {
              rtb_Gain_fj = -4.0F;
            }
          }

          /* SignalConversion: '<S316>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S307>/Saturation' incorporates:
           *  Constant: '<S313>/Constant'
           *  Constant: '<S314>/Constant'
           *  Constant: '<S324>/Constant'
           *  DataTypeConversion: '<S322>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S306>/Logical Operator'
           *  Product: '<S307>/Multiply'
           *  Product: '<S328>/Multiply3'
           *  Product: '<S328>/Multiply4'
           *  RelationalOperator: '<S313>/Compare'
           *  RelationalOperator: '<S314>/Compare'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S306>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S321>/lon_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S307>/Sum1'
           *  Sum: '<S328>/Sum3'
           *  Switch: '<S309>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          rtb_Add3_c = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.y_R : 0.0F;
          if (rtb_Add3_c > 4.0F) {
            rtb_Add3_c = 4.0F;
          } else {
            if (rtb_Add3_c < -4.0F) {
              rtb_Add3_c = -4.0F;
            }
          }

          /* SignalConversion: '<S316>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S307>/Saturation' incorporates:
           *  Constant: '<S313>/Constant'
           *  Constant: '<S314>/Constant'
           *  Constant: '<S324>/Constant'
           *  DataTypeConversion: '<S322>/Data Type Conversion'
           *  DataTypeConversion: '<S322>/Data Type Conversion1'
           *  Gain: '<S310>/Gain'
           *  Gain: '<S322>/Gain2'
           *  Gain: '<S325>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S306>/Logical Operator'
           *  Product: '<S307>/Multiply'
           *  RelationalOperator: '<S313>/Compare'
           *  RelationalOperator: '<S314>/Compare'
           *  RelationalOperator: '<S324>/Compare'
           *  S-Function (sfix_bitop): '<S306>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S321>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S307>/Sum1'
           *  Sum: '<S325>/Sum1'
           *  Switch: '<S309>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          rtb_Divide_lr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_n -
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

          /* SignalConversion: '<S249>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S249>/Constant4'
           *  MultiPortSwitch: '<S239>/Index Vector'
           *  Product: '<S307>/Multiply1'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S249>/Trigonometric Function3' incorporates:
           *  Gain: '<S248>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S239>/Index Vector'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S249>/Gain' incorporates:
           *  Gain: '<S248>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S239>/Index Vector'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S249>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S249>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S249>/Constant3'
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S249>/Trigonometric Function' incorporates:
           *  Gain: '<S248>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S239>/Index Vector'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S249>/Trigonometric Function1' incorporates:
           *  Gain: '<S248>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S239>/Index Vector'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S249>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S247>/Constant'
           *  RelationalOperator: '<S247>/Compare'
           *  S-Function (sfix_bitop): '<S244>/ax_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S249>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S247>/Constant'
           *  RelationalOperator: '<S247>/Compare'
           *  S-Function (sfix_bitop): '<S244>/ay_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S249>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S247>/Constant'
           *  RelationalOperator: '<S247>/Compare'
           *  S-Function (sfix_bitop): '<S244>/az_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S239>/Index Vector' incorporates:
           *  Product: '<S245>/Multiply'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Saturation_n +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 1:
          /* SignalConversion: '<S320>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S320>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S318>/Gain' incorporates:
           *  Gain: '<S250>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S239>/Index Vector'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S308>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.local_psi);

          /* Trigonometry: '<S320>/Trigonometric Function3' incorporates:
           *  Gain: '<S318>/Gain'
           *  Trigonometry: '<S320>/Trigonometric Function1'
           */
          rtb_MathFunction_f_idx_0 = arm_cos_f32(rtb_Add3_c);
          rtb_Transpose[4] = rtb_MathFunction_f_idx_0;

          /* Trigonometry: '<S320>/Trigonometric Function2' incorporates:
           *  Gain: '<S318>/Gain'
           *  Trigonometry: '<S320>/Trigonometric Function'
           */
          rtb_Gain_fj = arm_sin_f32(rtb_Add3_c);

          /* Gain: '<S320>/Gain' incorporates:
           *  Trigonometry: '<S320>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_Gain_fj;

          /* SignalConversion: '<S320>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S320>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S320>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_Gain_fj;

          /* Trigonometry: '<S320>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_f_idx_0;

          /* SignalConversion: '<S320>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S319>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S320>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S319>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S320>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S319>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_e[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S319>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S319>/Constant4'
           */
          rtb_VectorConcatenate_e[5] = 0.0F;

          /* Trigonometry: '<S319>/Trigonometric Function3' incorporates:
           *  Gain: '<S317>/Gain'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S319>/Trigonometric Function1'
           */
          rtb_Divide_lr_idx_1 = arm_cos_f32(-FMS_B.Cmd_In.local_psi);
          rtb_VectorConcatenate_e[4] = rtb_Divide_lr_idx_1;

          /* Trigonometry: '<S319>/Trigonometric Function2' incorporates:
           *  Gain: '<S317>/Gain'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S319>/Trigonometric Function'
           */
          rtb_Saturation_n = arm_sin_f32(-FMS_B.Cmd_In.local_psi);

          /* Gain: '<S319>/Gain' incorporates:
           *  Trigonometry: '<S319>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_e[3] = -rtb_Saturation_n;

          /* SignalConversion: '<S319>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S319>/Constant3'
           */
          rtb_VectorConcatenate_e[2] = 0.0F;

          /* Trigonometry: '<S319>/Trigonometric Function' */
          rtb_VectorConcatenate_e[1] = rtb_Saturation_n;

          /* Trigonometry: '<S319>/Trigonometric Function1' */
          rtb_VectorConcatenate_e[0] = rtb_Divide_lr_idx_1;

          /* RelationalOperator: '<S324>/Compare' incorporates:
           *  Constant: '<S324>/Constant'
           *  S-Function (sfix_bitop): '<S321>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S321>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S321>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S322>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S322>/Data Type Conversion'
           *  Gain: '<S322>/Gain2'
           *  Gain: '<S325>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S328>/Multiply1'
           *  Product: '<S328>/Multiply2'
           *  Product: '<S328>/Multiply3'
           *  Product: '<S328>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S325>/Sum1'
           *  Sum: '<S328>/Sum2'
           *  Sum: '<S328>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S309>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S313>/Compare' incorporates:
           *  Constant: '<S313>/Constant'
           *  S-Function (sfix_bitop): '<S306>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S314>/Compare' incorporates:
           *  Constant: '<S314>/Constant'
           *  S-Function (sfix_bitop): '<S306>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S308>/Sum2' incorporates:
             *  Product: '<S308>/Multiply2'
             *  Switch: '<S309>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Saturation_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Saturation_n = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S308>/Saturation1' incorporates:
             *  Gain: '<S310>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S306>/Logical Operator'
             *  Product: '<S308>/Multiply'
             *  Product: '<S308>/Multiply2'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Sum: '<S308>/Sum2'
             */
            rtb_Gain_fj = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_Saturation_n - ((rtb_VectorConcatenate_e[rtb_Compare_bv_0 + 3]
              * FMS_U.INS_Out.y_R + rtb_VectorConcatenate_e[rtb_Compare_bv_0] *
              FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_e[rtb_Compare_bv_0 + 6]
                                  * -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Gain_fj > FMS_ConstP.pooled23[rtb_Compare_bv_0]) {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else if (rtb_Gain_fj < FMS_ConstP.pooled24[rtb_Compare_bv_0]) {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
                FMS_ConstP.pooled24[rtb_Compare_bv_0];
            } else {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] = rtb_Gain_fj;
            }

            /* End of Saturate: '<S308>/Saturation1' */
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

          /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S251>/Constant4'
           *  MultiPortSwitch: '<S239>/Index Vector'
           *  Product: '<S308>/Multiply3'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S251>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Add3_c);

          /* Gain: '<S251>/Gain' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           *  Trigonometry: '<S251>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Add3_c);

          /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S251>/Constant3'
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S251>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Add3_c);

          /* Trigonometry: '<S251>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Add3_c);

          /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S247>/Constant'
           *  RelationalOperator: '<S247>/Compare'
           *  S-Function (sfix_bitop): '<S244>/ax_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S247>/Constant'
           *  RelationalOperator: '<S247>/Compare'
           *  S-Function (sfix_bitop): '<S244>/ay_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S239>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S247>/Constant'
           *  RelationalOperator: '<S247>/Compare'
           *  S-Function (sfix_bitop): '<S244>/az_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S239>/Index Vector' incorporates:
           *  Product: '<S246>/Multiply3'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Saturation_n +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         default:
          /* SignalConversion: '<S312>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S312>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S312>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S312>/Trigonometric Function3' incorporates:
           *  Gain: '<S311>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S312>/Gain' incorporates:
           *  Gain: '<S311>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S312>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S312>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S312>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S312>/Trigonometric Function' incorporates:
           *  Gain: '<S311>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S312>/Trigonometric Function1' incorporates:
           *  Gain: '<S311>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S321>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S306>/lat_cmd valid'
           */
          tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S324>/Compare' incorporates:
           *  Constant: '<S324>/Constant'
           *  S-Function (sfix_bitop): '<S321>/lat_cmd valid'
           */
          tmp[0] = (tmp_5 > 0U);

          /* S-Function (sfix_bitop): '<S321>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S306>/lon_cmd valid'
           */
          tmp_6 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S324>/Compare' incorporates:
           *  Constant: '<S324>/Constant'
           *  S-Function (sfix_bitop): '<S321>/lon_cmd valid'
           */
          tmp[1] = (tmp_6 > 0U);

          /* S-Function (sfix_bitop): '<S321>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S306>/alt_cmd valid'
           */
          tmp_7 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S324>/Compare' incorporates:
           *  Constant: '<S324>/Constant'
           *  S-Function (sfix_bitop): '<S321>/alt_cmd valid'
           */
          tmp[2] = (tmp_7 > 0U);

          /* DataTypeConversion: '<S322>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S322>/Data Type Conversion'
           *  Gain: '<S322>/Gain2'
           *  Gain: '<S325>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S328>/Multiply1'
           *  Product: '<S328>/Multiply2'
           *  Product: '<S328>/Multiply3'
           *  Product: '<S328>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S325>/Sum1'
           *  Sum: '<S328>/Sum2'
           *  Sum: '<S328>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S309>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S313>/Compare' incorporates:
           *  Constant: '<S313>/Constant'
           *  S-Function (sfix_bitop): '<S306>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S306>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S314>/Compare' incorporates:
           *  Constant: '<S314>/Constant'
           */
          tmp_2[0] = (tmp_5 > 0U);
          tmp_2[1] = (tmp_6 > 0U);
          tmp_2[2] = (tmp_7 > 0U);

          /* Sum: '<S305>/Sum2' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S309>/Switch' incorporates:
             *  Product: '<S305>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Saturation_n = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Saturation_n = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S305>/Saturation1' incorporates:
             *  Gain: '<S310>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S306>/Logical Operator'
             *  Product: '<S305>/Multiply'
             *  Product: '<S305>/Multiply2'
             *  SignalConversion: '<S31>/Signal Copy1'
             */
            rtb_Gain_fj = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0] ?
              rtb_Saturation_n - ((rtb_Transpose[rtb_Compare_bv_0 + 3] *
              FMS_U.INS_Out.y_R + rtb_Transpose[rtb_Compare_bv_0] *
              FMS_U.INS_Out.x_R) + rtb_Transpose[rtb_Compare_bv_0 + 6] *
                                  -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Gain_fj > FMS_ConstP.pooled23[rtb_Compare_bv_0]) {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else if (rtb_Gain_fj < FMS_ConstP.pooled24[rtb_Compare_bv_0]) {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
                FMS_ConstP.pooled24[rtb_Compare_bv_0];
            } else {
              rtb_MatrixConcatenate3[rtb_Compare_bv_0] = rtb_Gain_fj;
            }

            /* End of Saturate: '<S305>/Saturation1' */
          }

          /* End of Sum: '<S305>/Sum2' */

          /* MultiPortSwitch: '<S239>/Index Vector' incorporates:
           *  Constant: '<S247>/Constant'
           *  Product: '<S239>/Multiply'
           *  RelationalOperator: '<S247>/Compare'
           *  S-Function (sfix_bitop): '<S244>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S244>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S244>/az_cmd valid'
           */
          rtb_TmpSignalConversionAtMath_c[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U)
            > 0U ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = (FMS_U.Auto_Cmd.cmd_mask &
            131072U) > 0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = (FMS_U.Auto_Cmd.cmd_mask &
            262144U) > 0U ? FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S303>/Index Vector' */

        /* Sum: '<S299>/Sum1' incorporates:
         *  Constant: '<S299>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S299>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_0 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F)
          - FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S300>/Abs' */
        rtb_Add3_c = fabsf(rtb_MathFunction_f_idx_0);

        /* Switch: '<S300>/Switch' incorporates:
         *  Constant: '<S300>/Constant'
         *  Constant: '<S301>/Constant'
         *  Product: '<S300>/Multiply'
         *  RelationalOperator: '<S301>/Compare'
         *  Sum: '<S300>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S300>/Sign' */
          if (rtb_MathFunction_f_idx_0 < 0.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          } else {
            if (rtb_MathFunction_f_idx_0 > 0.0F) {
              rtb_MathFunction_f_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S300>/Sign' */
          rtb_MathFunction_f_idx_0 *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S300>/Switch' */

        /* Saturate: '<S299>/Saturation' */
        if (rtb_MathFunction_f_idx_0 > 0.314159274F) {
          rtb_MathFunction_f_idx_0 = 0.314159274F;
        } else {
          if (rtb_MathFunction_f_idx_0 < -0.314159274F) {
            rtb_MathFunction_f_idx_0 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S299>/Saturation' */

        /* Gain: '<S296>/Gain2' */
        rtb_MathFunction_f_idx_0 *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S241>/Sum' incorporates:
         *  Constant: '<S298>/Constant'
         *  Constant: '<S302>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S296>/Multiply2'
         *  Product: '<S297>/Multiply1'
         *  RelationalOperator: '<S298>/Compare'
         *  RelationalOperator: '<S302>/Compare'
         *  S-Function (sfix_bitop): '<S296>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S297>/psi_rate_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Gain_fj = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                       rtb_MathFunction_f_idx_0 : 0.0F) +
          ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
           0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S303>/Gain1' */
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_Add4_j3 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S303>/Gain2' */
        rtb_MathFunction_f_idx_0 = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S304>/Index Vector' incorporates:
         *  Constant: '<S339>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S304>/Multiply'
         *  Product: '<S337>/Multiply'
         *  Product: '<S338>/Multiply3'
         *  RelationalOperator: '<S339>/Compare'
         *  S-Function (sfix_bitop): '<S336>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S336>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S336>/w_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S341>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S341>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S341>/Trigonometric Function3' incorporates:
           *  Gain: '<S340>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S341>/Gain' incorporates:
           *  Gain: '<S340>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S341>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S341>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S341>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S341>/Trigonometric Function' incorporates:
           *  Gain: '<S340>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S341>/Trigonometric Function1' incorporates:
           *  Gain: '<S340>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S341>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S304>/Multiply' incorporates:
           *  Constant: '<S339>/Constant'
           *  RelationalOperator: '<S339>/Compare'
           *  S-Function (sfix_bitop): '<S336>/u_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S341>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S304>/Multiply' incorporates:
           *  Constant: '<S339>/Constant'
           *  RelationalOperator: '<S339>/Compare'
           *  S-Function (sfix_bitop): '<S336>/v_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S341>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S304>/Multiply' incorporates:
           *  Constant: '<S339>/Constant'
           *  RelationalOperator: '<S339>/Compare'
           *  S-Function (sfix_bitop): '<S336>/w_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Saturation_n +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Divide_lr_idx_1);
          }
          break;

         case 1:
          /* SignalConversion: '<S343>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S343>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S342>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S338>/Subtract'
           */
          rtb_Divide_lr_idx_1 = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.local_psi);

          /* Trigonometry: '<S343>/Trigonometric Function3' incorporates:
           *  Gain: '<S342>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Divide_lr_idx_1);

          /* Gain: '<S343>/Gain' incorporates:
           *  Gain: '<S342>/Gain'
           *  Trigonometry: '<S343>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Divide_lr_idx_1);

          /* SignalConversion: '<S343>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S343>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S343>/Trigonometric Function' incorporates:
           *  Gain: '<S342>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Divide_lr_idx_1);

          /* Trigonometry: '<S343>/Trigonometric Function1' incorporates:
           *  Gain: '<S342>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Divide_lr_idx_1);

          /* SignalConversion: '<S343>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S304>/Multiply' incorporates:
           *  Constant: '<S339>/Constant'
           *  RelationalOperator: '<S339>/Compare'
           *  S-Function (sfix_bitop): '<S336>/u_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S343>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S304>/Multiply' incorporates:
           *  Constant: '<S339>/Constant'
           *  RelationalOperator: '<S339>/Compare'
           *  S-Function (sfix_bitop): '<S336>/v_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S343>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S304>/Multiply' incorporates:
           *  Constant: '<S339>/Constant'
           *  RelationalOperator: '<S339>/Compare'
           *  S-Function (sfix_bitop): '<S336>/w_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Saturation_n +
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

        /* End of MultiPortSwitch: '<S304>/Index Vector' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Add3_c;
        rtb_MatrixConcatenate3[1] += rtb_Add4_j3;

        /* Sum: '<S242>/Sum1' */
        rtb_Add3_c = rtb_MathFunction_f_idx_0 + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S259>/Switch' incorporates:
         *  Constant: '<S274>/Constant'
         *  Constant: '<S276>/Constant'
         *  Constant: '<S277>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S274>/Compare'
         *  RelationalOperator: '<S276>/Compare'
         *  RelationalOperator: '<S277>/Compare'
         *  S-Function (sfix_bitop): '<S259>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S259>/y_v_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S259>/Logical Operator' incorporates:
           *  Constant: '<S275>/Constant'
           *  Constant: '<S276>/Constant'
           *  Constant: '<S277>/Constant'
           *  RelationalOperator: '<S275>/Compare'
           *  RelationalOperator: '<S276>/Compare'
           *  RelationalOperator: '<S277>/Compare'
           *  S-Function (sfix_bitop): '<S259>/lat_lon_cmd valid'
           *  S-Function (sfix_bitop): '<S259>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S259>/y_v_cmd'
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

        /* End of Switch: '<S259>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S240>/u_cmd_valid' */
        /* MATLAB Function: '<S271>/bit_shift' incorporates:
         *  DataTypeConversion: '<S240>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_es << 6);

        /* End of Outputs for SubSystem: '<S240>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S240>/v_cmd_valid' */
        /* MATLAB Function: '<S272>/bit_shift' incorporates:
         *  DataTypeConversion: '<S240>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S240>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S260>/Switch' incorporates:
         *  Constant: '<S279>/Constant'
         *  Constant: '<S280>/Constant'
         *  Constant: '<S282>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S279>/Compare'
         *  RelationalOperator: '<S280>/Compare'
         *  RelationalOperator: '<S282>/Compare'
         *  S-Function (sfix_bitop): '<S260>/ax_cmd'
         *  S-Function (sfix_bitop): '<S260>/ay_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S260>/Logical Operator' incorporates:
           *  Constant: '<S280>/Constant'
           *  Constant: '<S282>/Constant'
           *  RelationalOperator: '<S280>/Compare'
           *  RelationalOperator: '<S282>/Compare'
           *  S-Function (sfix_bitop): '<S260>/ax_cmd'
           *  S-Function (sfix_bitop): '<S260>/ay_cmd'
           */
          rtb_LogicalOperator_es = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_es;
        } else {
          rtb_LogicalOperator_es = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S260>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S157>/Bus Assignment'
         *  Constant: '<S157>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S157>/Bus Assignment' incorporates:
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

        /* Saturate: '<S241>/Saturation' */
        if (rtb_Gain_fj > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Gain_fj < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Gain_fj;
        }

        /* End of Saturate: '<S241>/Saturation' */

        /* Saturate: '<S242>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S242>/Saturation2' */

        /* Saturate: '<S242>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S242>/Saturation1' */

        /* Saturate: '<S242>/Saturation3' */
        if (rtb_Add3_c > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Add3_c < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S157>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Add3_c;
        }

        /* End of Saturate: '<S242>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S240>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S240>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S240>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S240>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S240>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S240>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S240>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S240>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S240>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S240>/throttle_cmd_valid' */
        /* BusAssignment: '<S157>/Bus Assignment' incorporates:
         *  Constant: '<S252>/Constant'
         *  Constant: '<S253>/Constant'
         *  Constant: '<S254>/Constant'
         *  Constant: '<S255>/Constant'
         *  Constant: '<S256>/Constant'
         *  Constant: '<S257>/Constant'
         *  Constant: '<S258>/Constant'
         *  Constant: '<S278>/Constant'
         *  Constant: '<S281>/Constant'
         *  DataTypeConversion: '<S240>/Data Type Conversion10'
         *  DataTypeConversion: '<S240>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S261>/bit_shift'
         *  MATLAB Function: '<S262>/bit_shift'
         *  MATLAB Function: '<S263>/bit_shift'
         *  MATLAB Function: '<S265>/bit_shift'
         *  MATLAB Function: '<S266>/bit_shift'
         *  MATLAB Function: '<S267>/bit_shift'
         *  MATLAB Function: '<S268>/bit_shift'
         *  MATLAB Function: '<S269>/bit_shift'
         *  MATLAB Function: '<S270>/bit_shift'
         *  MATLAB Function: '<S273>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S252>/Compare'
         *  RelationalOperator: '<S253>/Compare'
         *  RelationalOperator: '<S254>/Compare'
         *  RelationalOperator: '<S255>/Compare'
         *  RelationalOperator: '<S256>/Compare'
         *  RelationalOperator: '<S257>/Compare'
         *  RelationalOperator: '<S258>/Compare'
         *  RelationalOperator: '<S278>/Compare'
         *  RelationalOperator: '<S281>/Compare'
         *  S-Function (sfix_bitop): '<S240>/p_cmd'
         *  S-Function (sfix_bitop): '<S240>/phi_cmd'
         *  S-Function (sfix_bitop): '<S240>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S240>/q_cmd'
         *  S-Function (sfix_bitop): '<S240>/r_cmd'
         *  S-Function (sfix_bitop): '<S240>/theta_cmd'
         *  S-Function (sfix_bitop): '<S240>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S259>/alt_z_w_cmd'
         *  S-Function (sfix_bitop): '<S260>/az_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         *  Sum: '<S240>/Add'
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

        /* End of Outputs for SubSystem: '<S240>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S240>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S240>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S240>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S240>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S240>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S240>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S240>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S240>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S240>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S37>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Mission' incorporates:
           *  ActionPort: '<S156>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  UnitDelay: '<S159>/Delay Input1'
           *
           * Block description for '<S159>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S37>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S37>/Mission' incorporates:
           *  ActionPort: '<S156>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S156>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S198>/Motion Status'
           *  Chart: '<S208>/Motion State'
           *  Delay: '<S164>/Delay'
           *  Delay: '<S186>/Delay'
           *  DiscreteIntegrator: '<S167>/Integrator'
           *  DiscreteIntegrator: '<S167>/Integrator1'
           *  DiscreteIntegrator: '<S182>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S234>/Discrete-Time Integrator'
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

          /* End of SystemReset for SubSystem: '<S156>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S37>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Mission' incorporates:
         *  ActionPort: '<S156>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* RelationalOperator: '<S159>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S159>/Delay Input1'
         *
         * Block description for '<S159>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S156>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S160>/Reset'
         */
        if (rtb_FixPtRelationalOperator_me &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S207>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S197>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S186>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S187>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for DiscreteIntegrator: '<S182>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S164>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S167>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S167>/Integrator' */
          FMS_DW.Integrator_DSTATE_ip = 0.0F;

          /* SystemReset for Chart: '<S208>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S198>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_me;

        /* Delay: '<S186>/Delay' incorporates:
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
        /* Switch: '<S182>/Switch2' incorporates:
         *  Constant: '<S182>/vel'
         *  Constant: '<S191>/Constant'
         *  RelationalOperator: '<S191>/Compare'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_Add4_j3 = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_Add4_j3 = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S182>/Switch2' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* DiscreteIntegrator: '<S187>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S159>/Delay Input1'
         *
         * Block description for '<S159>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S181>/Compare' incorporates:
         *  Constant: '<S238>/Constant'
         *  RelationalOperator: '<S238>/Compare'
         *  UnitDelay: '<S159>/Delay Input1'
         *
         * Block description for '<S159>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_on = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* DiscreteIntegrator: '<S182>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S208>/Motion State' incorporates:
         *  Constant: '<S208>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S208>/Square'
         *  Math: '<S208>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S208>/Sqrt'
         *  Sum: '<S208>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S207>/Switch Case' incorporates:
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
          FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S207>/Hold Control' incorporates:
             *  ActionPort: '<S210>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S207>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S207>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S207>/Hold Control' incorporates:
           *  ActionPort: '<S210>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S207>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S207>/Brake Control' incorporates:
           *  ActionPort: '<S209>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S207>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S207>/Move Control' incorporates:
             *  ActionPort: '<S211>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S207>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S207>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S207>/Move Control' incorporates:
           *  ActionPort: '<S211>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S207>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S207>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S198>/Motion Status' incorporates:
         *  Abs: '<S198>/Abs'
         *  Constant: '<S198>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S197>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S197>/Hold Control' incorporates:
             *  ActionPort: '<S200>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S197>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S197>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S197>/Hold Control' incorporates:
           *  ActionPort: '<S200>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S197>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S197>/Brake Control' incorporates:
           *  ActionPort: '<S199>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S197>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S197>/Move Control' incorporates:
             *  ActionPort: '<S201>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S197>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S197>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S197>/Move Control' incorporates:
           *  ActionPort: '<S201>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S197>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S197>/Switch Case' */

        /* Switch: '<S162>/Switch' incorporates:
         *  Product: '<S186>/Multiply'
         *  Sum: '<S186>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S207>/Saturation1' */
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

          /* End of Saturate: '<S207>/Saturation1' */

          /* Saturate: '<S197>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S197>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S186>/Sum' incorporates:
           *  Delay: '<S186>/Delay'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S235>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S182>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Sum_ff[0] = rtb_Divide_lr_idx_1;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S186>/Sum' incorporates:
           *  Delay: '<S186>/Delay'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_lr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE[1];

          /* Sum: '<S182>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sqrt: '<S194>/Sqrt' incorporates:
           *  Math: '<S194>/Square'
           *  Sum: '<S182>/Sum'
           *  Sum: '<S194>/Sum of Elements'
           */
          rtb_Add3_c = sqrtf(rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0
                             + rtb_Add3_c * rtb_Add3_c);

          /* SignalConversion: '<S237>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S237>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S236>/Gain' incorporates:
           *  DiscreteIntegrator: '<S234>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S234>/Add'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S237>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S237>/Gain' incorporates:
           *  Trigonometry: '<S237>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S237>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S237>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S237>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* Switch: '<S193>/Switch2' incorporates:
           *  Constant: '<S182>/Constant2'
           *  DiscreteIntegrator: '<S182>/Acceleration_Speed'
           *  RelationalOperator: '<S193>/LowerRelop1'
           *  RelationalOperator: '<S193>/UpperRelop'
           *  Switch: '<S193>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE > rtb_Add4_j3) {
            rtb_Saturation_n = rtb_Add4_j3;
          } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
            /* Switch: '<S193>/Switch' incorporates:
             *  Constant: '<S182>/Constant2'
             */
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_DW.Acceleration_Speed_DSTATE;
          }

          /* End of Switch: '<S193>/Switch2' */

          /* Switch: '<S182>/Switch' */
          if (rtb_Add3_c > FMS_PARAM.L1) {
            rtb_Gain_fj = rtb_Add4_j3;
          } else {
            /* Gain: '<S182>/Gain' */
            rtb_Gain_fj = 0.5F * rtb_Add3_c;

            /* Switch: '<S192>/Switch2' incorporates:
             *  Constant: '<S182>/Constant1'
             *  RelationalOperator: '<S192>/LowerRelop1'
             *  RelationalOperator: '<S192>/UpperRelop'
             *  Switch: '<S192>/Switch'
             */
            if (rtb_Gain_fj > rtb_Add4_j3) {
              rtb_Gain_fj = rtb_Add4_j3;
            } else {
              if (rtb_Gain_fj < 0.5F) {
                /* Switch: '<S192>/Switch' incorporates:
                 *  Constant: '<S182>/Constant1'
                 */
                rtb_Gain_fj = 0.5F;
              }
            }

            /* End of Switch: '<S192>/Switch2' */
          }

          /* End of Switch: '<S182>/Switch' */

          /* Switch: '<S182>/Switch1' incorporates:
           *  Sum: '<S182>/Sum1'
           */
          if (rtb_Saturation_n - rtb_Gain_fj < 0.0F) {
            rtb_Gain_fj = rtb_Saturation_n;
          }

          /* End of Switch: '<S182>/Switch1' */

          /* Sum: '<S235>/Sum of Elements' incorporates:
           *  Math: '<S235>/Math Function'
           */
          rtb_Saturation_n = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Divide_lr_idx_1 *
            rtb_Divide_lr_idx_1;

          /* Math: '<S235>/Math Function1' incorporates:
           *  Sum: '<S235>/Sum of Elements'
           *
           * About '<S235>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S235>/Math Function1' */

          /* Switch: '<S235>/Switch' incorporates:
           *  Constant: '<S235>/Constant'
           *  Product: '<S235>/Product'
           */
          if (rtb_Saturation_n > 0.0F) {
            rtb_Add3_c = rtb_Sum_ff[0];
          } else {
            rtb_Add3_c = 0.0F;
            rtb_Divide_lr_idx_1 = 0.0F;
            rtb_Saturation_n = 1.0F;
          }

          /* End of Switch: '<S235>/Switch' */

          /* Product: '<S233>/Multiply2' incorporates:
           *  Product: '<S235>/Divide'
           */
          rtb_MathFunction_f_idx_0 = rtb_Add3_c / rtb_Saturation_n * rtb_Gain_fj;
          rtb_Gain_fj *= rtb_Divide_lr_idx_1 / rtb_Saturation_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S188>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Rem_p = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S188>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sqrt_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Add3_c = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S188>/Divide' incorporates:
           *  Math: '<S189>/Square'
           *  Math: '<S190>/Square'
           *  Sqrt: '<S189>/Sqrt'
           *  Sqrt: '<S190>/Sqrt'
           *  Sum: '<S188>/Sum'
           *  Sum: '<S188>/Sum1'
           *  Sum: '<S189>/Sum of Elements'
           *  Sum: '<S190>/Sum of Elements'
           */
          rtb_Saturation_n = sqrtf(rtb_Sqrt_b * rtb_Sqrt_b + rtb_Add3_c *
            rtb_Add3_c) / sqrtf(rtb_Rem_p * rtb_Rem_p + rtb_Saturation_n *
                                rtb_Saturation_n);

          /* Saturate: '<S188>/Saturation' */
          if (rtb_Saturation_n > 1.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            if (rtb_Saturation_n < 0.0F) {
              rtb_Saturation_n = 0.0F;
            }
          }

          /* End of Saturate: '<S188>/Saturation' */

          /* Product: '<S186>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Gain_fj + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_MathFunction_f_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S179>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S188>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S179>/Sum2'
           *  Sum: '<S188>/Add'
           *  Sum: '<S188>/Subtract'
           */
          rtb_Gain_fj = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_n +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S179>/Saturation1' incorporates:
           *  Product: '<S186>/Multiply'
           */
          if (rtb_Gain_fj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Gain_fj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Gain_fj;
          }

          /* End of Saturate: '<S179>/Saturation1' */
        }

        /* End of Switch: '<S162>/Switch' */

        /* Delay: '<S164>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S167>/Integrator1' incorporates:
         *  Delay: '<S164>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S171>/Rem' incorporates:
         *  Constant: '<S171>/Constant1'
         *  DiscreteIntegrator: '<S167>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S166>/Sum'
         */
        rtb_Divide_lr_idx_1 = rt_remf(FMS_DW.Integrator1_DSTATE_p -
          FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S171>/Switch' incorporates:
         *  Abs: '<S171>/Abs'
         *  Constant: '<S171>/Constant'
         *  Constant: '<S172>/Constant'
         *  Product: '<S171>/Multiply'
         *  RelationalOperator: '<S172>/Compare'
         *  Sum: '<S171>/Add'
         */
        if (fabsf(rtb_Divide_lr_idx_1) > 3.14159274F) {
          /* Signum: '<S171>/Sign' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_lr_idx_1;
          }

          /* End of Signum: '<S171>/Sign' */
          rtb_Divide_lr_idx_1 -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S171>/Switch' */

        /* Gain: '<S166>/Gain2' */
        rtb_Divide_lr_idx_1 *= FMS_PARAM.YAW_P;

        /* Saturate: '<S166>/Saturation' */
        if (rtb_Divide_lr_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Divide_lr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Divide_lr_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_lr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S166>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S160>/Bus Assignment'
         *  Constant: '<S160>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S160>/Bus Assignment' incorporates:
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
        /* Sum: '<S228>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S228>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Saturation_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S228>/Math Function1' incorporates:
         *  Sum: '<S228>/Sum of Elements'
         *
         * About '<S228>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S228>/Math Function1' */

        /* Switch: '<S228>/Switch' incorporates:
         *  Constant: '<S228>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S228>/Product'
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

        /* End of Switch: '<S228>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S160>/Sum' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Gain_fj = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_TmpSignalConversionAtDela_a[0] = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_MathFunction_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];
        rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S178>/Sum of Elements' incorporates:
         *  Math: '<S178>/Math Function'
         *  Sum: '<S160>/Sum'
         */
        rtb_Saturation_n = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0 +
          rtb_Gain_fj * rtb_Gain_fj;

        /* Math: '<S178>/Math Function1' incorporates:
         *  Sum: '<S178>/Sum of Elements'
         *
         * About '<S178>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S178>/Math Function1' */

        /* Switch: '<S178>/Switch' incorporates:
         *  Constant: '<S178>/Constant'
         *  Product: '<S178>/Product'
         */
        if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_MathFunction_f_idx_2 = rtb_Divide_lr_idx_1;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_Gain_fj = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S178>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S184>/NearbyRefWP' incorporates:
         *  Constant: '<S160>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                        rtb_TmpSignalConversionAtDela_a, &rtb_Saturation_n);

        /* MATLAB Function: '<S184>/SearchL1RefWP' incorporates:
         *  Constant: '<S160>/L1'
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
        /* MATLAB Function: '<S184>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_TmpSignalConversionAtMath_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Rem_p = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Divide_lr_idx_1 = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1])
          * rtb_Rem_p + (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0]) *
          rtb_TmpSignalConversionAtMath_0) / (rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtMath_0 + rtb_Rem_p * rtb_Rem_p);

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

        /* Switch: '<S184>/Switch1' incorporates:
         *  Constant: '<S221>/Constant'
         *  RelationalOperator: '<S221>/Compare'
         */
        if (rtb_Saturation_n <= 0.0F) {
          /* Switch: '<S184>/Switch' incorporates:
           *  Constant: '<S220>/Constant'
           *  MATLAB Function: '<S184>/SearchL1RefWP'
           *  RelationalOperator: '<S220>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_Sqrt_b;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S184>/OutRegionRegWP' incorporates:
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
                rtb_Rem_p + FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }
          }

          /* End of Switch: '<S184>/Switch' */
        }

        /* End of Switch: '<S184>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S185>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_TmpSignalConversionAtDela_a[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sqrt_b * rtb_Sqrt_b;
        rtb_Add3_c = rtb_Sqrt_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S185>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S229>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Sqrt_b = rtb_TmpSignalConversionAtDela_a[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S229>/Math Function' incorporates:
         *  Math: '<S227>/Square'
         */
        rtb_Saturation_n = rtb_Sqrt_b * rtb_Sqrt_b;

        /* Sum: '<S229>/Sum of Elements' incorporates:
         *  Math: '<S229>/Math Function'
         */
        rtb_Divide_lr_idx_1 = rtb_Saturation_n +
          rtb_TmpSignalConversionAtDela_a[0];

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
          rtb_MatrixConcatenate3[0] = rtb_Add3_c;
          rtb_MatrixConcatenate3[1] = rtb_Sqrt_b;
          rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S229>/Switch' */

        /* Product: '<S228>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_P_l_idx_0 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S231>/Sum of Elements' incorporates:
         *  Math: '<S231>/Math Function'
         *  SignalConversion: '<S231>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S231>/Math Function1' incorporates:
         *  Sum: '<S231>/Sum of Elements'
         *
         * About '<S231>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S231>/Math Function1' */

        /* Switch: '<S231>/Switch' incorporates:
         *  Constant: '<S231>/Constant'
         *  Product: '<S231>/Product'
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

        /* End of Switch: '<S231>/Switch' */

        /* Product: '<S229>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S232>/Sum of Elements' incorporates:
         *  Math: '<S232>/Math Function'
         *  SignalConversion: '<S232>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_TmpSignalConversionAtMath_0 * rtb_TmpSignalConversionAtMath_0;

        /* Math: '<S232>/Math Function1' incorporates:
         *  Sum: '<S232>/Sum of Elements'
         *
         * About '<S232>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_1));
        } else {
          rtb_Divide_lr_idx_1 = sqrtf(rtb_Divide_lr_idx_1);
        }

        /* End of Math: '<S232>/Math Function1' */

        /* Switch: '<S232>/Switch' incorporates:
         *  Constant: '<S232>/Constant'
         *  Product: '<S232>/Product'
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

        /* End of Switch: '<S232>/Switch' */

        /* Product: '<S232>/Divide' */
        rtb_TmpSignalConversionAtMath_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S231>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S178>/Divide' */
        rtb_Sqrt_b = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Add3_c *= rtb_Add3_c;

        /* Product: '<S232>/Divide' incorporates:
         *  Math: '<S227>/Square'
         */
        rtb_P_l_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S231>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S178>/Divide' */
        rtb_MathFunction_iq_idx_1 = rtb_Gain_fj / rtb_MathFunction_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sqrt: '<S226>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S226>/Square'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S226>/Sum of Elements'
         */
        rtb_Divide_lr_idx_1 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S185>/Gain' incorporates:
         *  Math: '<S185>/Square'
         */
        rtb_Gain_fj = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1 * 2.0F;

        /* Sum: '<S230>/Subtract' incorporates:
         *  Product: '<S230>/Multiply'
         *  Product: '<S230>/Multiply1'
         */
        rtb_Divide_lr_idx_1 = rtb_TmpSignalConversionAtMath_0 *
          rtb_TmpSignalConversionAtDela_a[1] - rtb_P_l_idx_0 *
          rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S225>/Sign1' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S225>/Sign1' */

        /* Switch: '<S225>/Switch2' incorporates:
         *  Constant: '<S225>/Constant4'
         */
        if (rtb_Divide_lr_idx_1 == 0.0F) {
          rtb_Divide_lr_idx_1 = 1.0F;
        }

        /* End of Switch: '<S225>/Switch2' */

        /* DotProduct: '<S225>/Dot Product' */
        rtb_MathFunction_f_idx_0 = rtb_TmpSignalConversionAtDela_a[0] *
          rtb_TmpSignalConversionAtMath_0 + rtb_TmpSignalConversionAtDela_a[1] *
          rtb_P_l_idx_0;

        /* Trigonometry: '<S225>/Acos' incorporates:
         *  DotProduct: '<S225>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_0 > 1.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 < -1.0F) {
            rtb_MathFunction_f_idx_0 = -1.0F;
          }
        }

        /* Product: '<S225>/Multiply' incorporates:
         *  Trigonometry: '<S225>/Acos'
         */
        rtb_Divide_lr_idx_1 *= acosf(rtb_MathFunction_f_idx_0);

        /* Saturate: '<S185>/Saturation' */
        if (rtb_Divide_lr_idx_1 > 1.57079637F) {
          rtb_Divide_lr_idx_1 = 1.57079637F;
        } else {
          if (rtb_Divide_lr_idx_1 < -1.57079637F) {
            rtb_Divide_lr_idx_1 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S185>/Saturation' */

        /* Product: '<S185>/Divide' incorporates:
         *  Constant: '<S160>/L1'
         *  Constant: '<S185>/Constant'
         *  MinMax: '<S185>/Max'
         *  MinMax: '<S185>/Min'
         *  Product: '<S185>/Multiply1'
         *  Sqrt: '<S227>/Sqrt'
         *  Sum: '<S227>/Sum of Elements'
         *  Trigonometry: '<S185>/Sin'
         */
        rtb_MathFunction_f_idx_2 = arm_sin_f32(rtb_Divide_lr_idx_1) *
          rtb_Gain_fj / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_n +
          rtb_Add3_c), 0.5F));

        /* Sum: '<S176>/Subtract' incorporates:
         *  Product: '<S176>/Multiply'
         *  Product: '<S176>/Multiply1'
         */
        rtb_Rem_p = rtb_Sqrt_b * FMS_ConstB.Divide[1] -
          rtb_MathFunction_iq_idx_1 * FMS_ConstB.Divide[0];

        /* Signum: '<S165>/Sign1' */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_p = -1.0F;
        } else {
          if (rtb_Rem_p > 0.0F) {
            rtb_Rem_p = 1.0F;
          }
        }

        /* End of Signum: '<S165>/Sign1' */

        /* Switch: '<S165>/Switch2' incorporates:
         *  Constant: '<S165>/Constant4'
         */
        if (rtb_Rem_p == 0.0F) {
          rtb_Rem_p = 1.0F;
        }

        /* End of Switch: '<S165>/Switch2' */

        /* DotProduct: '<S165>/Dot Product' */
        rtb_Gain_fj = FMS_ConstB.Divide[0] * rtb_Sqrt_b + FMS_ConstB.Divide[1] *
          rtb_MathFunction_iq_idx_1;

        /* Trigonometry: '<S165>/Acos' incorporates:
         *  DotProduct: '<S165>/Dot Product'
         */
        if (rtb_Gain_fj > 1.0F) {
          rtb_Gain_fj = 1.0F;
        } else {
          if (rtb_Gain_fj < -1.0F) {
            rtb_Gain_fj = -1.0F;
          }
        }

        /* Product: '<S165>/Multiply' incorporates:
         *  Trigonometry: '<S165>/Acos'
         */
        rtb_Rem_p *= acosf(rtb_Gain_fj);

        /* Math: '<S168>/Rem' incorporates:
         *  Constant: '<S168>/Constant1'
         *  Delay: '<S164>/Delay'
         *  Sum: '<S164>/Sum2'
         */
        rtb_Divide_lr_idx_1 = rt_remf(rtb_Rem_p - FMS_DW.Delay_DSTATE_h,
          6.28318548F);

        /* Switch: '<S168>/Switch' incorporates:
         *  Abs: '<S168>/Abs'
         *  Constant: '<S168>/Constant'
         *  Constant: '<S174>/Constant'
         *  Product: '<S168>/Multiply'
         *  RelationalOperator: '<S174>/Compare'
         *  Sum: '<S168>/Add'
         */
        if (fabsf(rtb_Divide_lr_idx_1) > 3.14159274F) {
          /* Signum: '<S168>/Sign' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Divide_lr_idx_1;
          }

          /* End of Signum: '<S168>/Sign' */
          rtb_Divide_lr_idx_1 -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S168>/Switch' */

        /* Sum: '<S164>/Sum' incorporates:
         *  Delay: '<S164>/Delay'
         */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S173>/Multiply1' incorporates:
         *  Constant: '<S173>/const1'
         *  DiscreteIntegrator: '<S167>/Integrator'
         */
        rtb_Divide_lr_idx_1 = FMS_DW.Integrator_DSTATE_ip * 0.785398185F;

        /* Sum: '<S173>/Add' incorporates:
         *  DiscreteIntegrator: '<S167>/Integrator1'
         *  Sum: '<S167>/Subtract'
         */
        rtb_MathFunction_f_idx_0 = (FMS_DW.Integrator1_DSTATE_p - rtb_Add3_c) +
          rtb_Divide_lr_idx_1;

        /* Signum: '<S173>/Sign' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_MathFunction_f_idx_0 > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_MathFunction_f_idx_0;
        }

        /* End of Signum: '<S173>/Sign' */

        /* Sum: '<S173>/Add2' incorporates:
         *  Abs: '<S173>/Abs'
         *  Gain: '<S173>/Gain'
         *  Gain: '<S173>/Gain1'
         *  Product: '<S173>/Multiply2'
         *  Product: '<S173>/Multiply3'
         *  Sqrt: '<S173>/Sqrt'
         *  Sum: '<S173>/Add1'
         *  Sum: '<S173>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_MathFunction_f_idx_0) +
          FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Add3_c +
          rtb_Divide_lr_idx_1;

        /* Sum: '<S173>/Add4' */
        rtb_Divide_lr_idx_1 += rtb_MathFunction_f_idx_0 - rtb_Saturation_n;

        /* Sum: '<S173>/Add3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_0 + FMS_ConstB.d;

        /* Sum: '<S173>/Subtract1' */
        rtb_MathFunction_f_idx_0 -= FMS_ConstB.d;

        /* Signum: '<S173>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S173>/Sign1' */

        /* Signum: '<S173>/Sign2' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S173>/Sign2' */

        /* Sum: '<S173>/Add5' incorporates:
         *  Gain: '<S173>/Gain2'
         *  Product: '<S173>/Multiply4'
         *  Sum: '<S173>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Add3_c - rtb_MathFunction_f_idx_0) * 0.5F *
          rtb_Divide_lr_idx_1;

        /* Sum: '<S173>/Add6' */
        rtb_Add3_c = rtb_Saturation_n + FMS_ConstB.d;

        /* Sum: '<S173>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_Saturation_n - FMS_ConstB.d;

        /* Product: '<S173>/Divide' */
        rtb_Sqrt_b = rtb_Saturation_n / FMS_ConstB.d;

        /* Signum: '<S173>/Sign5' incorporates:
         *  Signum: '<S173>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_MathFunction_iq_idx_1 = -1.0F;

          /* Signum: '<S173>/Sign6' */
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_MathFunction_iq_idx_1 = 1.0F;

          /* Signum: '<S173>/Sign6' */
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_1 = rtb_Saturation_n;

          /* Signum: '<S173>/Sign6' */
          rtb_MathFunction_f_idx_0 = rtb_Saturation_n;
        }

        /* End of Signum: '<S173>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S164>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Rem_p -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S169>/Rem' incorporates:
         *  Constant: '<S169>/Constant1'
         */
        rtb_Saturation_n = rt_remf(rtb_Rem_p, 6.28318548F);

        /* Switch: '<S169>/Switch' incorporates:
         *  Abs: '<S169>/Abs'
         *  Constant: '<S169>/Constant'
         *  Constant: '<S175>/Constant'
         *  Product: '<S169>/Multiply'
         *  RelationalOperator: '<S175>/Compare'
         *  Sum: '<S169>/Add'
         */
        if (fabsf(rtb_Saturation_n) > 3.14159274F) {
          /* Signum: '<S169>/Sign' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Gain_fj = -1.0F;
          } else if (rtb_Saturation_n > 0.0F) {
            rtb_Gain_fj = 1.0F;
          } else {
            rtb_Gain_fj = rtb_Saturation_n;
          }

          /* End of Signum: '<S169>/Sign' */
          rtb_Saturation_n -= 6.28318548F * rtb_Gain_fj;
        }

        /* End of Switch: '<S169>/Switch' */

        /* Abs: '<S162>/Abs' */
        rtb_Saturation_n = fabsf(rtb_Saturation_n);

        /* Update for Delay: '<S186>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S187>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S180>/Constant'
         *  RelationalOperator: '<S180>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)
          (rtb_Saturation_n <= 0.17453292F) +
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S187>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S182>/Acceleration_Speed' incorporates:
         *  Constant: '<S182>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Product: '<S186>/Divide1' */
        rtb_Gain_fj = rtb_MathFunction_f_idx_2 / rtb_Add4_j3;

        /* Saturate: '<S186>/Saturation' */
        if (rtb_Gain_fj > 0.314159274F) {
          rtb_Gain_fj = 0.314159274F;
        } else {
          if (rtb_Gain_fj < -0.314159274F) {
            rtb_Gain_fj = -0.314159274F;
          }
        }

        /* End of Saturate: '<S186>/Saturation' */

        /* Update for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Gain_fj;

        /* Update for Delay: '<S164>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S167>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S167>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_ip;

        /* Signum: '<S173>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S173>/Sign3' */

        /* Signum: '<S173>/Sign4' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S173>/Sign4' */

        /* Update for DiscreteIntegrator: '<S167>/Integrator' incorporates:
         *  Constant: '<S173>/const'
         *  Gain: '<S173>/Gain3'
         *  Product: '<S173>/Multiply5'
         *  Product: '<S173>/Multiply6'
         *  Sum: '<S173>/Subtract4'
         *  Sum: '<S173>/Subtract5'
         *  Sum: '<S173>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_ip += ((rtb_Sqrt_b - rtb_MathFunction_iq_idx_1)
          * FMS_ConstB.Gain4 * ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F) -
          rtb_MathFunction_f_idx_0 * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_ip >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_ip = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_ip <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_ip = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S167>/Integrator' */
        /* End of Outputs for SubSystem: '<S156>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Update for UnitDelay: '<S159>/Delay Input1' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S159>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S37>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S37>/Unknown' incorporates:
         *  ActionPort: '<S158>/Action Port'
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
          /* Disable for SwitchCase: '<S143>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S51>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S72>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S88>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S113>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S100>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
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
           *  DiscreteIntegrator: '<S137>/Integrator'
           *  DiscreteIntegrator: '<S137>/Integrator1'
           *  DiscreteIntegrator: '<S138>/Integrator'
           *  DiscreteIntegrator: '<S138>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_k = 0.0F;
          FMS_DW.Integrator_DSTATE_a = 0.0F;
          FMS_DW.Integrator1_DSTATE_n = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S36>/Stabilize' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S144>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S36>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Stabilize' incorporates:
         *  ActionPort: '<S44>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S135>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S135>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S135>/Gain' */
        rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation_n;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S136>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S136>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S136>/Gain' */
        rtb_Add4_j3 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Saturation_n;

        /* Sum: '<S139>/Sum of Elements' incorporates:
         *  Math: '<S139>/Square'
         *  SignalConversion: '<S139>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S140>/Sum of Elements'
         *  Switch: '<S131>/Switch'
         */
        rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c + rtb_Add4_j3 * rtb_Add4_j3;

        /* Switch: '<S131>/Switch' incorporates:
         *  Constant: '<S134>/Constant'
         *  Product: '<S140>/Divide'
         *  RelationalOperator: '<S134>/Compare'
         *  Sqrt: '<S139>/Sqrt'
         *  Sum: '<S139>/Sum of Elements'
         */
        if (sqrtf(rtb_Saturation_n) > 1.0F) {
          /* Math: '<S140>/Math Function1'
           *
           * About '<S140>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S140>/Math Function1' */

          /* Switch: '<S140>/Switch' incorporates:
           *  Constant: '<S140>/Constant'
           *  Product: '<S140>/Product'
           */
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Add3_c;
            rtb_MatrixConcatenate3[1] = rtb_Add4_j3;
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S140>/Switch' */
          rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_Add4_j3 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
        }

        /* Product: '<S141>/Multiply1' incorporates:
         *  Constant: '<S141>/const1'
         *  DiscreteIntegrator: '<S137>/Integrator'
         */
        rtb_Gain_fj = FMS_DW.Integrator_DSTATE_a * 0.04F;

        /* Sum: '<S141>/Add' incorporates:
         *  DiscreteIntegrator: '<S137>/Integrator1'
         *  Gain: '<S131>/Gain'
         *  Sum: '<S137>/Subtract'
         */
        rtb_Sqrt_b = (FMS_DW.Integrator1_DSTATE_k - FMS_PARAM.ROLL_PITCH_LIM *
                      rtb_Add3_c) + rtb_Gain_fj;

        /* Saturate: '<S141>/Saturation' incorporates:
         *  Constant: '<S137>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S141>/Saturation' */

        /* Product: '<S141>/Multiply7' incorporates:
         *  Constant: '<S141>/const'
         */
        rtb_MathFunction_iq_idx_1 = 31.415926F * rtb_Saturation_n;

        /* Product: '<S141>/Multiply' */
        rtb_MathFunction_f_idx_2 = rtb_MathFunction_iq_idx_1 *
          FMS_ConstB.Square_ct;

        /* Signum: '<S141>/Sign' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Sqrt_b > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Sqrt_b;
        }

        /* End of Signum: '<S141>/Sign' */

        /* Sum: '<S141>/Add2' incorporates:
         *  Abs: '<S141>/Abs'
         *  Gain: '<S141>/Gain'
         *  Gain: '<S141>/Gain1'
         *  Product: '<S141>/Multiply2'
         *  Product: '<S141>/Multiply3'
         *  Sqrt: '<S141>/Sqrt'
         *  Sum: '<S141>/Add1'
         *  Sum: '<S141>/Subtract'
         */
        rtb_P_l_idx_0 = (sqrtf((8.0F * fabsf(rtb_Sqrt_b) +
          rtb_MathFunction_f_idx_2) * rtb_MathFunction_f_idx_2) -
                         rtb_MathFunction_f_idx_2) * 0.5F * rtb_Add3_c +
          rtb_Gain_fj;

        /* Sum: '<S141>/Add4' */
        rtb_Divide_lr_idx_1 = (rtb_Sqrt_b - rtb_P_l_idx_0) + rtb_Gain_fj;

        /* Sum: '<S141>/Add3' */
        rtb_Add3_c = rtb_Sqrt_b + rtb_MathFunction_f_idx_2;

        /* Sum: '<S141>/Subtract1' */
        rtb_Sqrt_b -= rtb_MathFunction_f_idx_2;

        /* Signum: '<S141>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S141>/Sign1' */

        /* Signum: '<S141>/Sign2' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S141>/Sign2' */

        /* Sum: '<S141>/Add5' incorporates:
         *  Gain: '<S141>/Gain2'
         *  Product: '<S141>/Multiply4'
         *  Sum: '<S141>/Subtract2'
         */
        rtb_P_l_idx_0 += (rtb_Add3_c - rtb_Sqrt_b) * 0.5F * rtb_Divide_lr_idx_1;

        /* Sum: '<S141>/Add6' */
        rtb_Add3_c = rtb_P_l_idx_0 + rtb_MathFunction_f_idx_2;

        /* Sum: '<S141>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 - rtb_MathFunction_f_idx_2;

        /* Product: '<S141>/Divide' */
        rtb_Rem_p = rtb_P_l_idx_0 / rtb_MathFunction_f_idx_2;

        /* Signum: '<S141>/Sign5' incorporates:
         *  Signum: '<S141>/Sign6'
         */
        if (rtb_P_l_idx_0 < 0.0F) {
          rtb_TmpSignalConversionAtMath_0 = -1.0F;

          /* Signum: '<S141>/Sign6' */
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else if (rtb_P_l_idx_0 > 0.0F) {
          rtb_TmpSignalConversionAtMath_0 = 1.0F;

          /* Signum: '<S141>/Sign6' */
          rtb_MathFunction_f_idx_0 = 1.0F;
        } else {
          rtb_TmpSignalConversionAtMath_0 = rtb_P_l_idx_0;

          /* Signum: '<S141>/Sign6' */
          rtb_MathFunction_f_idx_0 = rtb_P_l_idx_0;
        }

        /* End of Signum: '<S141>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Logic: '<S131>/Logical Operator' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* Chart: '<S144>/Motion State' incorporates:
         *  Abs: '<S144>/Abs'
         *  Abs: '<S144>/Abs1'
         *  Constant: '<S154>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S154>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S143>/Switch Case' incorporates:
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
          FMS_DW.SwitchCase_ActiveSubsystem_fs = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_fs = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_fs) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S143>/Hold Control' incorporates:
             *  ActionPort: '<S146>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S143>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S143>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S143>/Hold Control' incorporates:
           *  ActionPort: '<S146>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S143>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S143>/Brake Control' incorporates:
           *  ActionPort: '<S145>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S143>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S143>/Move Control' incorporates:
             *  ActionPort: '<S147>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S143>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S143>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S143>/Move Control' incorporates:
           *  ActionPort: '<S147>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S143>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S143>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S133>/Switch' incorporates:
         *  Constant: '<S133>/Constant'
         *  Constant: '<S133>/Constant4'
         *  Constant: '<S133>/Constant5'
         *  Gain: '<S133>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Saturate: '<S133>/Saturation'
         *  SignalConversion: '<S31>/Signal Copy2'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy7Inport1'
         *  Sum: '<S133>/Add'
         *  Sum: '<S133>/Sum'
         */
        if (FMS_B.Compare) {
          rtb_y_md = FMS_PARAM.LAND_LOCK_THRO;
        } else {
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            /* Saturate: '<S133>/Saturation' */
            rtb_Saturation_n = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            /* Saturate: '<S133>/Saturation' */
            rtb_Saturation_n = 0.0F;
          } else {
            /* Saturate: '<S133>/Saturation' incorporates:
             *  Constant: '<S133>/Constant4'
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S31>/Signal Copy2'
             *  Sum: '<S133>/Sum'
             */
            rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          rtb_y_md = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_Saturation_n),
            65536.0F) + 1000U);
        }

        /* End of Switch: '<S133>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S44>/Bus Assignment'
         *  Constant: '<S44>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S44>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S131>/Data Type Conversion'
         *  DiscreteIntegrator: '<S137>/Integrator1'
         *  DiscreteIntegrator: '<S138>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S131>/Multiply'
         *  Product: '<S131>/Multiply1'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_k;
        FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_n;

        /* Saturate: '<S143>/Saturation' */
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

        /* End of Saturate: '<S143>/Saturation' */

        /* BusAssignment: '<S44>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.throttle_cmd = rtb_y_md;

        /* Product: '<S142>/Multiply1' incorporates:
         *  Constant: '<S142>/const1'
         *  DiscreteIntegrator: '<S138>/Integrator'
         */
        rtb_P_l_idx_0 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Sum: '<S142>/Add' incorporates:
         *  DiscreteIntegrator: '<S138>/Integrator1'
         *  Gain: '<S131>/Gain1'
         *  Sum: '<S138>/Subtract'
         */
        rtb_MathFunction_f_idx_2 = (FMS_DW.Integrator1_DSTATE_n -
          -FMS_PARAM.ROLL_PITCH_LIM * rtb_Add4_j3) + rtb_P_l_idx_0;

        /* Saturate: '<S142>/Saturation' incorporates:
         *  Constant: '<S138>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S142>/Saturation' */

        /* Product: '<S142>/Multiply7' incorporates:
         *  Constant: '<S142>/const'
         */
        rtb_Sqrt_b = 31.415926F * rtb_Saturation_n;

        /* Product: '<S142>/Multiply' */
        rtb_Gain_fj = rtb_Sqrt_b * FMS_ConstB.Square_b;

        /* Signum: '<S142>/Sign' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_MathFunction_f_idx_2 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_MathFunction_f_idx_2;
        }

        /* End of Signum: '<S142>/Sign' */

        /* Sum: '<S142>/Add2' incorporates:
         *  Abs: '<S142>/Abs'
         *  Gain: '<S142>/Gain'
         *  Gain: '<S142>/Gain1'
         *  Product: '<S142>/Multiply2'
         *  Product: '<S142>/Multiply3'
         *  Sqrt: '<S142>/Sqrt'
         *  Sum: '<S142>/Add1'
         *  Sum: '<S142>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_MathFunction_f_idx_2) +
          rtb_Gain_fj) * rtb_Gain_fj) - rtb_Gain_fj) * 0.5F * rtb_Saturation_n +
          rtb_P_l_idx_0;

        /* Sum: '<S142>/Add4' */
        rtb_Add4_j3 = (rtb_MathFunction_f_idx_2 - rtb_Saturation_n) +
          rtb_P_l_idx_0;

        /* Sum: '<S142>/Add3' */
        rtb_P_l_idx_0 = rtb_MathFunction_f_idx_2 + rtb_Gain_fj;

        /* Sum: '<S142>/Subtract1' */
        rtb_MathFunction_f_idx_2 -= rtb_Gain_fj;

        /* Signum: '<S142>/Sign1' */
        if (rtb_P_l_idx_0 < 0.0F) {
          rtb_P_l_idx_0 = -1.0F;
        } else {
          if (rtb_P_l_idx_0 > 0.0F) {
            rtb_P_l_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S142>/Sign1' */

        /* Signum: '<S142>/Sign2' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_2 > 0.0F) {
            rtb_MathFunction_f_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S142>/Sign2' */

        /* Sum: '<S142>/Add5' incorporates:
         *  Gain: '<S142>/Gain2'
         *  Product: '<S142>/Multiply4'
         *  Sum: '<S142>/Subtract2'
         */
        rtb_Saturation_n += (rtb_P_l_idx_0 - rtb_MathFunction_f_idx_2) * 0.5F *
          rtb_Add4_j3;

        /* Update for DiscreteIntegrator: '<S137>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S137>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_k += 0.004F * FMS_DW.Integrator_DSTATE_a;

        /* Signum: '<S141>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S141>/Sign3' */

        /* Signum: '<S141>/Sign4' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S141>/Sign4' */

        /* Update for DiscreteIntegrator: '<S137>/Integrator' incorporates:
         *  Gain: '<S141>/Gain3'
         *  Gain: '<S141>/Gain4'
         *  Product: '<S141>/Multiply5'
         *  Product: '<S141>/Multiply6'
         *  Sum: '<S141>/Subtract4'
         *  Sum: '<S141>/Subtract5'
         *  Sum: '<S141>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_a += ((rtb_Rem_p -
          rtb_TmpSignalConversionAtMath_0) * -rtb_MathFunction_iq_idx_1 *
          ((rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F) - rtb_MathFunction_f_idx_0
          * rtb_MathFunction_iq_idx_1) * 0.004F;

        /* Update for DiscreteIntegrator: '<S138>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S138>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S142>/Subtract3' */
        rtb_Add3_c = rtb_Saturation_n - rtb_Gain_fj;

        /* Sum: '<S142>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_Saturation_n + rtb_Gain_fj;

        /* Signum: '<S142>/Sign5' incorporates:
         *  Signum: '<S142>/Sign6'
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;

          /* Signum: '<S142>/Sign6' */
          rtb_Add4_j3 = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;

          /* Signum: '<S142>/Sign6' */
          rtb_Add4_j3 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_Saturation_n;

          /* Signum: '<S142>/Sign6' */
          rtb_Add4_j3 = rtb_Saturation_n;
        }

        /* End of Signum: '<S142>/Sign5' */

        /* Signum: '<S142>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S142>/Sign3' */

        /* Signum: '<S142>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S142>/Sign4' */

        /* Update for DiscreteIntegrator: '<S138>/Integrator' incorporates:
         *  Gain: '<S142>/Gain3'
         *  Gain: '<S142>/Gain4'
         *  Product: '<S142>/Divide'
         *  Product: '<S142>/Multiply5'
         *  Product: '<S142>/Multiply6'
         *  Sum: '<S142>/Subtract4'
         *  Sum: '<S142>/Subtract5'
         *  Sum: '<S142>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Saturation_n / rtb_Gain_fj -
          rtb_MathFunction_f_idx_0) * -rtb_Sqrt_b * ((rtb_Divide_lr_idx_1 -
          rtb_Add3_c) * 0.5F) - rtb_Add4_j3 * rtb_Sqrt_b) * 0.004F;

        /* End of Outputs for SubSystem: '<S36>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S36>/Altitude' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S66>/Integrator'
           *  DiscreteIntegrator: '<S66>/Integrator1'
           *  DiscreteIntegrator: '<S67>/Integrator'
           *  DiscreteIntegrator: '<S67>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_g = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_e = 0.0F;
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S36>/Altitude' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S52>/Motion Status'
           *  Chart: '<S73>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S36>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Altitude' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S64>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S64>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S64>/Gain' */
        rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation_n;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S65>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S65>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S65>/Gain' */
        rtb_Add4_j3 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Saturation_n;

        /* Sum: '<S68>/Sum of Elements' incorporates:
         *  Math: '<S68>/Square'
         *  SignalConversion: '<S68>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S69>/Sum of Elements'
         *  Switch: '<S49>/Switch'
         */
        rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c + rtb_Add4_j3 * rtb_Add4_j3;

        /* Switch: '<S49>/Switch' incorporates:
         *  Constant: '<S63>/Constant'
         *  Product: '<S69>/Divide'
         *  RelationalOperator: '<S63>/Compare'
         *  Sqrt: '<S68>/Sqrt'
         *  Sum: '<S68>/Sum of Elements'
         */
        if (sqrtf(rtb_Saturation_n) > 1.0F) {
          /* Math: '<S69>/Math Function1'
           *
           * About '<S69>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S69>/Math Function1' */

          /* Switch: '<S69>/Switch' incorporates:
           *  Constant: '<S69>/Constant'
           *  Product: '<S69>/Product'
           */
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Add3_c;
            rtb_MatrixConcatenate3[1] = rtb_Add4_j3;
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S69>/Switch' */
          rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
          rtb_Add4_j3 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
        }

        /* Product: '<S70>/Multiply1' incorporates:
         *  Constant: '<S70>/const1'
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        rtb_Gain_fj = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Sum: '<S70>/Add' incorporates:
         *  DiscreteIntegrator: '<S66>/Integrator1'
         *  Gain: '<S49>/Gain'
         *  Sum: '<S66>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_g -
          FMS_PARAM.ROLL_PITCH_LIM * rtb_Add3_c) + rtb_Gain_fj;

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
        rtb_Saturation_n *= 31.415926F;

        /* Product: '<S70>/Multiply' */
        rtb_MathFunction_f_idx_0 = rtb_Saturation_n * FMS_ConstB.Square_j;

        /* Signum: '<S70>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Divide_lr_idx_1;
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
        rtb_Sqrt_b = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) +
                             rtb_MathFunction_f_idx_0) *
                            rtb_MathFunction_f_idx_0) - rtb_MathFunction_f_idx_0)
          * 0.5F * rtb_Add3_c + rtb_Gain_fj;

        /* Sum: '<S70>/Add4' */
        rtb_Gain_fj += rtb_Divide_lr_idx_1 - rtb_Sqrt_b;

        /* Sum: '<S70>/Add3' */
        rtb_Add3_c = rtb_Divide_lr_idx_1 + rtb_MathFunction_f_idx_0;

        /* Sum: '<S70>/Subtract1' */
        rtb_Divide_lr_idx_1 -= rtb_MathFunction_f_idx_0;

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
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign2' */

        /* Sum: '<S70>/Add5' incorporates:
         *  Gain: '<S70>/Gain2'
         *  Product: '<S70>/Multiply4'
         *  Sum: '<S70>/Subtract2'
         */
        rtb_Sqrt_b += (rtb_Add3_c - rtb_Divide_lr_idx_1) * 0.5F * rtb_Gain_fj;

        /* Sum: '<S70>/Add6' */
        rtb_Add3_c = rtb_Sqrt_b + rtb_MathFunction_f_idx_0;

        /* Sum: '<S70>/Subtract3' */
        rtb_Divide_lr_idx_1 = rtb_Sqrt_b - rtb_MathFunction_f_idx_0;

        /* Signum: '<S70>/Sign5' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Gain_fj = -1.0F;
        } else if (rtb_Sqrt_b > 0.0F) {
          rtb_Gain_fj = 1.0F;
        } else {
          rtb_Gain_fj = rtb_Sqrt_b;
        }

        /* End of Signum: '<S70>/Sign5' */

        /* Signum: '<S70>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign3' */

        /* Signum: '<S70>/Sign4' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign4' */

        /* Product: '<S70>/Multiply5' incorporates:
         *  Gain: '<S70>/Gain3'
         *  Gain: '<S70>/Gain4'
         *  Product: '<S70>/Divide'
         *  Sum: '<S70>/Subtract4'
         *  Sum: '<S70>/Subtract5'
         */
        rtb_Divide_lr_idx_1 = (rtb_Sqrt_b / rtb_MathFunction_f_idx_0 -
          rtb_Gain_fj) * -rtb_Saturation_n * ((rtb_Add3_c - rtb_Divide_lr_idx_1)
          * 0.5F);

        /* Signum: '<S70>/Sign6' */
        if (rtb_Sqrt_b < 0.0F) {
          rtb_Sqrt_b = -1.0F;
        } else {
          if (rtb_Sqrt_b > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign6' */

        /* Product: '<S70>/Multiply6' */
        rtb_MathFunction_iq_idx_1 = rtb_Sqrt_b * rtb_Saturation_n;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Logic: '<S49>/Logical Operator' incorporates:
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy7Inport1'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* Chart: '<S52>/Motion Status' incorporates:
         *  Abs: '<S52>/Abs'
         *  Abs: '<S52>/Abs1'
         *  Constant: '<S61>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S61>/Compare'
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
          FMS_DW.SwitchCase_ActiveSubsystem_m = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_m = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_m) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S51>/Hold Control' incorporates:
             *  ActionPort: '<S54>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S51>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S51>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S51>/Hold Control' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S51>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S51>/Brake Control' incorporates:
           *  ActionPort: '<S53>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S51>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S51>/Move Control' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_l);

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
          rtb_Saturation_n = 0.5F;
        } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_Saturation_n = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_Saturation_n = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S51>/Saturation1' */
          rtb_Saturation_n = FMS_B.Merge_l;
        }

        /* End of Switch: '<S48>/Switch' */

        /* Chart: '<S73>/Motion State' incorporates:
         *  Abs: '<S73>/Abs'
         *  Abs: '<S73>/Abs1'
         *  Constant: '<S83>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S83>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S72>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S72>/Hold Control' incorporates:
             *  ActionPort: '<S75>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S72>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S72>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S72>/Hold Control' incorporates:
           *  ActionPort: '<S75>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                            &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S72>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S72>/Brake Control' incorporates:
           *  ActionPort: '<S74>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S72>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S72>/Move Control' incorporates:
             *  ActionPort: '<S76>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S72>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_cr);

            /* End of SystemReset for SubSystem: '<S72>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S72>/Move Control' incorporates:
           *  ActionPort: '<S76>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_cr, &FMS_DW.MoveControl_cr);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S72>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S72>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S42>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S66>/Integrator1'
         *  DiscreteIntegrator: '<S67>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         *  Product: '<S49>/Multiply'
         *  Product: '<S49>/Multiply1'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_g;
        FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
          FMS_DW.Integrator1_DSTATE_e;

        /* Saturate: '<S72>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S72>/Saturation' */

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = rtb_Saturation_n;

        /* Product: '<S71>/Multiply1' incorporates:
         *  Constant: '<S71>/const1'
         *  DiscreteIntegrator: '<S67>/Integrator'
         */
        rtb_Sqrt_b = FMS_DW.Integrator_DSTATE_i * 0.04F;

        /* Sum: '<S71>/Add' incorporates:
         *  DiscreteIntegrator: '<S67>/Integrator1'
         *  Gain: '<S49>/Gain1'
         *  Sum: '<S67>/Subtract'
         */
        rtb_MathFunction_f_idx_0 = (FMS_DW.Integrator1_DSTATE_e -
          -FMS_PARAM.ROLL_PITCH_LIM * rtb_Add4_j3) + rtb_Sqrt_b;

        /* Saturate: '<S71>/Saturation' incorporates:
         *  Constant: '<S67>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S71>/Saturation' */

        /* Product: '<S71>/Multiply7' incorporates:
         *  Constant: '<S71>/const'
         */
        rtb_Saturation_n *= 31.415926F;

        /* Product: '<S71>/Multiply' */
        rtb_Gain_fj = rtb_Saturation_n * FMS_ConstB.Square_c;

        /* Signum: '<S71>/Sign' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_MathFunction_f_idx_0 > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_MathFunction_f_idx_0;
        }

        /* End of Signum: '<S71>/Sign' */

        /* Sum: '<S71>/Add2' incorporates:
         *  Abs: '<S71>/Abs'
         *  Gain: '<S71>/Gain'
         *  Gain: '<S71>/Gain1'
         *  Product: '<S71>/Multiply2'
         *  Product: '<S71>/Multiply3'
         *  Sqrt: '<S71>/Sqrt'
         *  Sum: '<S71>/Add1'
         *  Sum: '<S71>/Subtract'
         */
        rtb_MathFunction_f_idx_2 = (sqrtf((8.0F * fabsf(rtb_MathFunction_f_idx_0)
          + rtb_Gain_fj) * rtb_Gain_fj) - rtb_Gain_fj) * 0.5F * rtb_Add3_c +
          rtb_Sqrt_b;

        /* Sum: '<S71>/Add4' */
        rtb_Add4_j3 = (rtb_MathFunction_f_idx_0 - rtb_MathFunction_f_idx_2) +
          rtb_Sqrt_b;

        /* Sum: '<S71>/Add3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_0 + rtb_Gain_fj;

        /* Sum: '<S71>/Subtract1' */
        rtb_MathFunction_f_idx_0 -= rtb_Gain_fj;

        /* Signum: '<S71>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S71>/Sign1' */

        /* Signum: '<S71>/Sign2' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S71>/Sign2' */

        /* Sum: '<S71>/Add5' incorporates:
         *  Gain: '<S71>/Gain2'
         *  Product: '<S71>/Multiply4'
         *  Sum: '<S71>/Subtract2'
         */
        rtb_MathFunction_f_idx_2 += (rtb_Add3_c - rtb_MathFunction_f_idx_0) *
          0.5F * rtb_Add4_j3;

        /* Update for DiscreteIntegrator: '<S66>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Update for DiscreteIntegrator: '<S66>/Integrator' incorporates:
         *  Sum: '<S70>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += (rtb_Divide_lr_idx_1 -
          rtb_MathFunction_iq_idx_1) * 0.004F;

        /* Update for DiscreteIntegrator: '<S67>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S67>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Sum: '<S71>/Subtract3' */
        rtb_Add3_c = rtb_MathFunction_f_idx_2 - rtb_Gain_fj;

        /* Sum: '<S71>/Add6' */
        rtb_Divide_lr_idx_1 = rtb_MathFunction_f_idx_2 + rtb_Gain_fj;

        /* Signum: '<S71>/Sign5' incorporates:
         *  Signum: '<S71>/Sign6'
         */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;

          /* Signum: '<S71>/Sign6' */
          rtb_Add4_j3 = -1.0F;
        } else if (rtb_MathFunction_f_idx_2 > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;

          /* Signum: '<S71>/Sign6' */
          rtb_Add4_j3 = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_MathFunction_f_idx_2;

          /* Signum: '<S71>/Sign6' */
          rtb_Add4_j3 = rtb_MathFunction_f_idx_2;
        }

        /* End of Signum: '<S71>/Sign5' */

        /* Signum: '<S71>/Sign3' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S71>/Sign3' */

        /* Signum: '<S71>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S71>/Sign4' */

        /* Update for DiscreteIntegrator: '<S67>/Integrator' incorporates:
         *  Gain: '<S71>/Gain3'
         *  Gain: '<S71>/Gain4'
         *  Product: '<S71>/Divide'
         *  Product: '<S71>/Multiply5'
         *  Product: '<S71>/Multiply6'
         *  Sum: '<S71>/Subtract4'
         *  Sum: '<S71>/Subtract5'
         *  Sum: '<S71>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_MathFunction_f_idx_2 / rtb_Gain_fj -
          rtb_MathFunction_f_idx_0) * -rtb_Saturation_n * ((rtb_Divide_lr_idx_1
          - rtb_Add3_c) * 0.5F) - rtb_Add4_j3 * rtb_Saturation_n) * 0.004F;

        /* End of Outputs for SubSystem: '<S36>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S36>/Position' incorporates:
           *  ActionPort: '<S43>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S101>/Motion State'
           *  Chart: '<S114>/Motion State'
           *  Chart: '<S89>/Motion Status'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_i);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S36>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Position' incorporates:
         *  ActionPort: '<S43>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S89>/Motion Status' incorporates:
         *  Abs: '<S89>/Abs'
         *  Abs: '<S89>/Abs1'
         *  Constant: '<S98>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S98>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_i);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S88>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S88>/Hold Control' incorporates:
             *  ActionPort: '<S91>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S88>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S88>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S88>/Hold Control' incorporates:
           *  ActionPort: '<S91>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge, &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S88>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S88>/Brake Control' incorporates:
           *  ActionPort: '<S90>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S88>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S88>/Move Control' incorporates:
           *  ActionPort: '<S92>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S88>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S88>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S101>/Motion State' incorporates:
         *  Abs: '<S101>/Abs'
         *  Abs: '<S101>/Abs1'
         *  Constant: '<S111>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S111>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S114>/Logical Operator' incorporates:
         *  Abs: '<S114>/Abs1'
         *  Abs: '<S114>/Abs2'
         *  Constant: '<S128>/Constant'
         *  Constant: '<S129>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S128>/Compare'
         *  RelationalOperator: '<S129>/Compare'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S114>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S114>/Square'
         *  Math: '<S114>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S114>/Sqrt'
         *  Sum: '<S114>/Add'
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
                (FMS_DW.temporalCounter_i1_i >= 625U)) {
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

        /* End of Chart: '<S114>/Motion State' */

        /* SwitchCase: '<S113>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
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
            /* SystemReset for IfAction SubSystem: '<S113>/Hold Control' incorporates:
             *  ActionPort: '<S116>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S113>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S113>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S113>/Hold Control' incorporates:
           *  ActionPort: '<S116>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.ff2,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S113>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S113>/Brake Control' incorporates:
           *  ActionPort: '<S115>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.ff2);

          /* End of Outputs for SubSystem: '<S113>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S113>/Move Control' incorporates:
             *  ActionPort: '<S117>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S113>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S124>/Integrator'
             *  DiscreteIntegrator: '<S124>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE[0] = 0.0F;
            FMS_DW.Integrator_DSTATE[0] = 0.0F;
            FMS_DW.Integrator1_DSTATE[1] = 0.0F;
            FMS_DW.Integrator_DSTATE[1] = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S113>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S113>/Move Control' incorporates:
           *  ActionPort: '<S117>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S122>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S122>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S122>/Gain' */
          rtb_Add3_c = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Saturation_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S123>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S123>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S123>/Gain' */
          rtb_Add4_j3 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation_n;

          /* Sum: '<S125>/Sum of Elements' incorporates:
           *  Math: '<S125>/Square'
           *  SignalConversion: '<S125>/TmpSignal ConversionAtSquareInport1'
           *  Sum: '<S126>/Sum of Elements'
           *  Switch: '<S117>/Switch'
           */
          rtb_Saturation_n = rtb_Add3_c * rtb_Add3_c + rtb_Add4_j3 * rtb_Add4_j3;

          /* Switch: '<S117>/Switch' incorporates:
           *  Constant: '<S121>/Constant'
           *  Product: '<S126>/Divide'
           *  RelationalOperator: '<S121>/Compare'
           *  Sqrt: '<S125>/Sqrt'
           *  Sum: '<S125>/Sum of Elements'
           */
          if (sqrtf(rtb_Saturation_n) > 1.0F) {
            /* Math: '<S126>/Math Function1'
             *
             * About '<S126>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_n < 0.0F) {
              rtb_Divide_lr_idx_1 = -sqrtf(fabsf(rtb_Saturation_n));
            } else {
              rtb_Divide_lr_idx_1 = sqrtf(rtb_Saturation_n);
            }

            /* End of Math: '<S126>/Math Function1' */

            /* Switch: '<S126>/Switch' incorporates:
             *  Constant: '<S126>/Constant'
             *  Product: '<S126>/Product'
             */
            if (rtb_Divide_lr_idx_1 > 0.0F) {
              rtb_MatrixConcatenate3[0] = rtb_Add3_c;
              rtb_MatrixConcatenate3[1] = rtb_Add4_j3;
              rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_1;
            } else {
              rtb_MatrixConcatenate3[0] = 0.0F;
              rtb_MatrixConcatenate3[1] = 0.0F;
              rtb_MatrixConcatenate3[2] = 1.0F;
            }

            /* End of Switch: '<S126>/Switch' */
            rtb_Add3_c = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
            rtb_Add4_j3 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
          }

          /* Saturate: '<S127>/Saturation' incorporates:
           *  Constant: '<S124>/Constant'
           */
          if (FMS_PARAM.STICK_SENS > 1.0F) {
            rtb_Saturation_n = 1.0F;
          } else if (FMS_PARAM.STICK_SENS < 0.0F) {
            rtb_Saturation_n = 0.0F;
          } else {
            rtb_Saturation_n = FMS_PARAM.STICK_SENS;
          }

          /* End of Saturate: '<S127>/Saturation' */

          /* Product: '<S127>/Multiply7' incorporates:
           *  Constant: '<S127>/const'
           */
          rtb_Gain_fj = 980.6F * rtb_Saturation_n;

          /* Product: '<S127>/Multiply' */
          rtb_MathFunction_iq_idx_1 = rtb_Gain_fj * FMS_ConstB.Square;

          /* Product: '<S127>/Multiply1' incorporates:
           *  Constant: '<S127>/const1'
           *  DiscreteIntegrator: '<S124>/Integrator'
           */
          rtb_MathFunction_f_idx_0 = FMS_DW.Integrator_DSTATE[0] * 0.01F;

          /* Sum: '<S127>/Add' incorporates:
           *  DiscreteIntegrator: '<S124>/Integrator1'
           *  Gain: '<S117>/Gain6'
           *  Sum: '<S124>/Subtract'
           */
          rtb_Sqrt_b = (FMS_DW.Integrator1_DSTATE[0] - FMS_PARAM.VEL_XY_LIM *
                        rtb_Add3_c) + rtb_MathFunction_f_idx_0;

          /* Signum: '<S127>/Sign' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Sqrt_b > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Sqrt_b;
          }

          /* Sum: '<S127>/Add2' incorporates:
           *  Abs: '<S127>/Abs'
           *  Gain: '<S127>/Gain'
           *  Gain: '<S127>/Gain1'
           *  Product: '<S127>/Multiply2'
           *  Product: '<S127>/Multiply3'
           *  Sqrt: '<S127>/Sqrt'
           *  Sum: '<S127>/Add1'
           *  Sum: '<S127>/Subtract'
           */
          rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Sqrt_b) +
                              rtb_MathFunction_iq_idx_1) *
                             rtb_MathFunction_iq_idx_1) -
                       rtb_MathFunction_iq_idx_1) * 0.5F * rtb_Add3_c +
            rtb_MathFunction_f_idx_0;

          /* Sum: '<S127>/Add4' */
          rtb_MathFunction_f_idx_0 += rtb_Sqrt_b - rtb_Rem_p;

          /* Sum: '<S127>/Add3' */
          rtb_Add3_c = rtb_Sqrt_b + rtb_MathFunction_iq_idx_1;

          /* Sum: '<S127>/Subtract1' */
          rtb_Sqrt_b -= rtb_MathFunction_iq_idx_1;

          /* Signum: '<S127>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S127>/Sign2' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else {
            if (rtb_Sqrt_b > 0.0F) {
              rtb_Sqrt_b = 1.0F;
            }
          }

          /* Sum: '<S127>/Add5' incorporates:
           *  Gain: '<S127>/Gain2'
           *  Product: '<S127>/Multiply4'
           *  Sum: '<S127>/Subtract2'
           */
          rtb_Rem_p += (rtb_Add3_c - rtb_Sqrt_b) * 0.5F *
            rtb_MathFunction_f_idx_0;

          /* SignalConversion: '<S117>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S124>/Integrator1'
           */
          FMS_B.ff2[0] = FMS_DW.Integrator1_DSTATE[0];

          /* Update for DiscreteIntegrator: '<S124>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S124>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

          /* Signum: '<S127>/Sign4' incorporates:
           *  Sum: '<S127>/Subtract3'
           */
          rtb_Add3_c = rtb_Rem_p - rtb_MathFunction_iq_idx_1;

          /* Signum: '<S127>/Sign3' incorporates:
           *  Sum: '<S127>/Add6'
           */
          rtb_Divide_lr_idx_1 = rtb_Rem_p + rtb_MathFunction_iq_idx_1;

          /* Signum: '<S127>/Sign5' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Rem_p;
          }

          /* Signum: '<S127>/Sign3' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_1 > 0.0F) {
              rtb_Divide_lr_idx_1 = 1.0F;
            }
          }

          /* Signum: '<S127>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S127>/Sign6' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = rtb_Rem_p;
          }

          /* Update for DiscreteIntegrator: '<S124>/Integrator' incorporates:
           *  Gain: '<S127>/Gain3'
           *  Gain: '<S127>/Gain4'
           *  Product: '<S127>/Divide'
           *  Product: '<S127>/Multiply5'
           *  Product: '<S127>/Multiply6'
           *  Sum: '<S127>/Subtract4'
           *  Sum: '<S127>/Subtract5'
           *  Sum: '<S127>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE[0] += ((rtb_Rem_p / rtb_MathFunction_iq_idx_1
            - rtb_Saturation_n) * -rtb_Gain_fj * ((rtb_Divide_lr_idx_1 -
            rtb_Add3_c) * 0.5F) - rtb_Sqrt_b * rtb_Gain_fj) * 0.004F;

          /* Product: '<S127>/Multiply1' incorporates:
           *  Constant: '<S127>/const1'
           *  DiscreteIntegrator: '<S124>/Integrator'
           */
          rtb_MathFunction_f_idx_0 = FMS_DW.Integrator_DSTATE[1] * 0.01F;

          /* Sum: '<S127>/Add' incorporates:
           *  DiscreteIntegrator: '<S124>/Integrator1'
           *  Gain: '<S117>/Gain6'
           *  Sum: '<S124>/Subtract'
           */
          rtb_Sqrt_b = (FMS_DW.Integrator1_DSTATE[1] - FMS_PARAM.VEL_XY_LIM *
                        rtb_Add4_j3) + rtb_MathFunction_f_idx_0;

          /* Signum: '<S127>/Sign' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Sqrt_b > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Sqrt_b;
          }

          /* Sum: '<S127>/Add2' incorporates:
           *  Abs: '<S127>/Abs'
           *  Gain: '<S127>/Gain'
           *  Gain: '<S127>/Gain1'
           *  Product: '<S127>/Multiply2'
           *  Product: '<S127>/Multiply3'
           *  Sqrt: '<S127>/Sqrt'
           *  Sum: '<S127>/Add1'
           *  Sum: '<S127>/Subtract'
           */
          rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Sqrt_b) +
                              rtb_MathFunction_iq_idx_1) *
                             rtb_MathFunction_iq_idx_1) -
                       rtb_MathFunction_iq_idx_1) * 0.5F * rtb_Add3_c +
            rtb_MathFunction_f_idx_0;

          /* Sum: '<S127>/Add4' */
          rtb_MathFunction_f_idx_0 += rtb_Sqrt_b - rtb_Rem_p;

          /* Sum: '<S127>/Add3' */
          rtb_Add3_c = rtb_Sqrt_b + rtb_MathFunction_iq_idx_1;

          /* Sum: '<S127>/Subtract1' */
          rtb_Sqrt_b -= rtb_MathFunction_iq_idx_1;

          /* Signum: '<S127>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S127>/Sign2' */
          if (rtb_Sqrt_b < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else {
            if (rtb_Sqrt_b > 0.0F) {
              rtb_Sqrt_b = 1.0F;
            }
          }

          /* Sum: '<S127>/Add5' incorporates:
           *  Gain: '<S127>/Gain2'
           *  Product: '<S127>/Multiply4'
           *  Sum: '<S127>/Subtract2'
           */
          rtb_Rem_p += (rtb_Add3_c - rtb_Sqrt_b) * 0.5F *
            rtb_MathFunction_f_idx_0;

          /* SignalConversion: '<S117>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S124>/Integrator1'
           */
          FMS_B.ff2[1] = FMS_DW.Integrator1_DSTATE[1];

          /* Update for DiscreteIntegrator: '<S124>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S124>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

          /* Signum: '<S127>/Sign4' incorporates:
           *  Sum: '<S127>/Subtract3'
           */
          rtb_Add3_c = rtb_Rem_p - rtb_MathFunction_iq_idx_1;

          /* Signum: '<S127>/Sign3' incorporates:
           *  Sum: '<S127>/Add6'
           */
          rtb_Divide_lr_idx_1 = rtb_Rem_p + rtb_MathFunction_iq_idx_1;

          /* Signum: '<S127>/Sign5' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Rem_p;
          }

          /* Signum: '<S127>/Sign3' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Divide_lr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_1 > 0.0F) {
              rtb_Divide_lr_idx_1 = 1.0F;
            }
          }

          /* Signum: '<S127>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S127>/Sign6' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = rtb_Rem_p;
          }

          /* Update for DiscreteIntegrator: '<S124>/Integrator' incorporates:
           *  Gain: '<S127>/Gain3'
           *  Gain: '<S127>/Gain4'
           *  Product: '<S127>/Divide'
           *  Product: '<S127>/Multiply5'
           *  Product: '<S127>/Multiply6'
           *  Sum: '<S127>/Subtract4'
           *  Sum: '<S127>/Subtract5'
           *  Sum: '<S127>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE[1] += ((rtb_Rem_p / rtb_MathFunction_iq_idx_1
            - rtb_Saturation_n) * -rtb_Gain_fj * ((rtb_Divide_lr_idx_1 -
            rtb_Add3_c) * 0.5F) - rtb_Sqrt_b * rtb_Gain_fj) * 0.004F;

          /* End of Outputs for SubSystem: '<S113>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S113>/Switch Case' */

        /* SwitchCase: '<S100>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S100>/Hold Control' incorporates:
             *  ActionPort: '<S103>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S100>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S100>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S100>/Hold Control' incorporates:
           *  ActionPort: '<S103>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                            &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S100>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S100>/Brake Control' incorporates:
           *  ActionPort: '<S102>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S100>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S100>/Move Control' incorporates:
             *  ActionPort: '<S104>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S100>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_mr);

            /* End of SystemReset for SubSystem: '<S100>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S100>/Move Control' incorporates:
           *  ActionPort: '<S104>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_mr, &FMS_DW.MoveControl_mr);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S100>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S100>/Switch Case' */

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

        /* Saturate: '<S100>/Saturation' */
        if (FMS_B.Merge_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_d;
        }

        /* End of Saturate: '<S100>/Saturation' */

        /* Saturate: '<S113>/Saturation1' */
        if (FMS_B.ff2[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.ff2[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.ff2[0];
        }

        if (FMS_B.ff2[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.ff2[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.ff2[1];
        }

        /* End of Saturate: '<S113>/Saturation1' */

        /* Saturate: '<S88>/Saturation1' */
        if (FMS_B.Merge > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge;
        }

        /* End of Saturate: '<S88>/Saturation1' */
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
   *  DiscreteIntegrator: '<S485>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
   *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy4Inport1'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.local_psi = FMS_B.Cmd_In.local_psi;

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

  /* Update for DiscreteIntegrator: '<S500>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S500>/Gain'
   *  Sum: '<S500>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_o[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_o[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_o[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S502>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S502>/Gain'
   *  Sum: '<S502>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S501>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S501>/Gain'
   *  Sum: '<S501>/Sum5'
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

  /* Update for DiscreteIntegrator: '<S485>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S485>/Constant'
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
  /* Start for SwitchCase: '<S442>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S432>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;

  /* End of Start for SubSystem: '<S39>/Return' */

  /* Start for IfAction SubSystem: '<S39>/Hold' */
  /* Start for SwitchCase: '<S374>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S352>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S362>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S39>/Hold' */
  /* End of Start for SubSystem: '<S32>/SubMode' */

  /* Start for IfAction SubSystem: '<S32>/Auto' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S37>/Mission' */
  /* Start for Resettable SubSystem: '<S156>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S207>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S197>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S156>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S37>/Mission' */
  /* End of Start for SubSystem: '<S32>/Auto' */

  /* Start for IfAction SubSystem: '<S32>/Assist' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S36>/Stabilize' */
  /* Start for SwitchCase: '<S143>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S36>/Stabilize' */

  /* Start for IfAction SubSystem: '<S36>/Altitude' */
  /* Start for SwitchCase: '<S51>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S72>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S36>/Altitude' */

  /* Start for IfAction SubSystem: '<S36>/Position' */
  /* Start for SwitchCase: '<S88>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S113>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S100>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S36>/Position' */
  /* End of Start for SubSystem: '<S32>/Assist' */
  /* End of Start for SubSystem: '<S30>/Arm' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S500>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S502>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S501>/Discrete-Time Integrator5' */
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

  /* SystemInitialize for IfAction SubSystem: '<S30>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S32>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S39>/Takeoff' */
  /* InitializeConditions for Delay: '<S482>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S478>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S478>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S390>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S390>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Return' */
  /* InitializeConditions for Delay: '<S421>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S422>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S469>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;

  /* InitializeConditions for Delay: '<S399>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S402>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S398>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S402>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S443>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S442>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S442>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S442>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S442>/Move Control' */

  /* SystemInitialize for Merge: '<S442>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S433>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S432>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S432>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S432>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S432>/Move Control' */

  /* SystemInitialize for Merge: '<S432>/Merge' */
  FMS_B.Merge_jj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Hold' */
  /* SystemInitialize for Chart: '<S353>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S363>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S375>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S374>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S374>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S374>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S374>/Move Control' */

  /* SystemInitialize for Merge: '<S374>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S352>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S352>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S352>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S352>/Move Control' */

  /* SystemInitialize for Merge: '<S352>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S362>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S362>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S362>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S362>/Move Control' */

  /* SystemInitialize for Merge: '<S362>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S32>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S32>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S37>/Mission' */
  /* InitializeConditions for UnitDelay: '<S159>/Delay Input1'
   *
   * Block description for '<S159>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S156>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S186>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S187>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S182>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S164>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S167>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S167>/Integrator' */
  FMS_DW.Integrator_DSTATE_ip = 0.0F;

  /* SystemInitialize for Chart: '<S208>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S207>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S207>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S207>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S207>/Move Control' */

  /* SystemInitialize for Merge: '<S207>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S198>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S197>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S197>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S197>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S197>/Move Control' */

  /* SystemInitialize for Merge: '<S197>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S156>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S37>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S32>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S32>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S36>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_k = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S144>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S143>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S143>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S143>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S143>/Move Control' */

  /* SystemInitialize for Merge: '<S143>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S66>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S66>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S67>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S67>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S52>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S51>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S51>/Hold Control' */

  /* SystemInitialize for Merge: '<S51>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S73>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S72>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S72>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S72>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_cr);

  /* End of SystemInitialize for SubSystem: '<S72>/Move Control' */

  /* SystemInitialize for Merge: '<S72>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Position' */
  /* SystemInitialize for Chart: '<S89>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for IfAction SubSystem: '<S88>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S88>/Hold Control' */

  /* SystemInitialize for Chart: '<S101>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S114>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S113>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S113>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S113>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S124>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S113>/Move Control' */

  /* SystemInitialize for Merge: '<S113>/Merge' */
  FMS_B.ff2[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S113>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S124>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S113>/Move Control' */

  /* SystemInitialize for Merge: '<S113>/Merge' */
  FMS_B.ff2[1] = 0.0F;

  /* SystemInitialize for Merge: '<S88>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S100>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S100>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S100>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_mr);

  /* End of SystemInitialize for SubSystem: '<S100>/Move Control' */

  /* SystemInitialize for Merge: '<S100>/Merge' */
  FMS_B.Merge_d = 0.0F;

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
