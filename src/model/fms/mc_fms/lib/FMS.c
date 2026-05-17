/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2287
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun May 17 10:27:03 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S438>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S448>/Motion State' */
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

/* Named constants for Chart: '<S368>/Motion State' */
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
                                        *   '<S498>/Constant'
                                        *   '<S351>/L1'
                                        *   '<S49>/Gain'
                                        *   '<S49>/Gain1'
                                        *   '<S126>/Gain'
                                        *   '<S126>/Gain1'
                                        *   '<S128>/Constant'
                                        *   '<S154>/L1'
                                        *   '<S241>/Saturation'
                                        *   '<S242>/Saturation1'
                                        *   '<S242>/Saturation2'
                                        *   '<S242>/Saturation3'
                                        *   '<S392>/Land_Speed'
                                        *   '<S393>/Saturation1'
                                        *   '<S485>/Takeoff_Speed'
                                        *   '<S486>/Gain2'
                                        *   '<S486>/Saturation1'
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
                                        *   '<S297>/Gain2'
                                        *   '<S304>/Gain1'
                                        *   '<S304>/Gain2'
                                        *   '<S357>/Saturation1'
                                        *   '<S367>/Saturation'
                                        *   '<S379>/Saturation1'
                                        *   '<S394>/Constant'
                                        *   '<S397>/Gain2'
                                        *   '<S419>/Gain'
                                        *   '<S419>/Saturation1'
                                        *   '<S422>/Constant'
                                        *   '<S422>/vel'
                                        *   '<S422>/Switch'
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
                                        *   '<S360>/Gain2'
                                        *   '<S361>/Gain1'
                                        *   '<S370>/Gain2'
                                        *   '<S371>/Gain1'
                                        *   '<S382>/Gain2'
                                        *   '<S383>/Gain6'
                                        *   '<S406>/Gain2'
                                        *   '<S406>/Saturation'
                                        *   '<S407>/Integrator'
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
                                        *   '<S363>/Dead Zone'
                                        *   '<S363>/Gain'
                                        *   '<S375>/Dead Zone'
                                        *   '<S375>/Gain'
                                        *   '<S387>/Dead Zone'
                                        *   '<S387>/Gain'
                                        *   '<S388>/Dead Zone'
                                        *   '<S388>/Gain'
                                        *   '<S437>/Saturation1'
                                        *   '<S447>/Saturation1'
                                        *   '<S191>/Saturation1'
                                        *   '<S201>/Saturation1'
                                        *   '<S440>/Gain2'
                                        *   '<S441>/Gain1'
                                        *   '<S450>/Gain2'
                                        *   '<S451>/Gain6'
                                        *   '<S194>/Gain2'
                                        *   '<S195>/Gain1'
                                        *   '<S204>/Gain2'
                                        *   '<S205>/Gain6'
                                        *   '<S443>/Dead Zone'
                                        *   '<S443>/Gain'
                                        *   '<S455>/Dead Zone'
                                        *   '<S455>/Gain'
                                        *   '<S456>/Dead Zone'
                                        *   '<S456>/Gain'
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
                                        *   '<S496>/Constant'
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
 *    '<S437>/Hold Control'
 *    '<S357>/Hold Control'
 *    '<S191>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S440>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S437>/Hold Control'
 *    '<S357>/Hold Control'
 *    '<S191>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S440>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S437>/Hold Control'
 *    '<S357>/Hold Control'
 *    '<S191>/Hold Control'
 *    '<S51>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S440>/Delay' incorporates:
   *  Gain: '<S442>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S440>/Gain2' incorporates:
   *  Delay: '<S440>/Delay'
   *  Gain: '<S442>/Gain'
   *  Sum: '<S440>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S440>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S437>/Brake Control'
 *    '<S357>/Brake Control'
 *    '<S367>/Brake Control'
 *    '<S191>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S439>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S439>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S437>/Move Control'
 *    '<S357>/Move Control'
 *    '<S191>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S444>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S444>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S437>/Move Control'
 *    '<S357>/Move Control'
 *    '<S191>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S444>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S444>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S437>/Move Control'
 *    '<S357>/Move Control'
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

  /* Product: '<S445>/Multiply1' incorporates:
   *  Constant: '<S445>/const1'
   *  DiscreteIntegrator: '<S444>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S443>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S443>/Dead Zone' */

  /* Sum: '<S445>/Add' incorporates:
   *  DiscreteIntegrator: '<S444>/Integrator1'
   *  Gain: '<S441>/Gain1'
   *  Gain: '<S443>/Gain'
   *  Sum: '<S444>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S445>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S445>/Sign' */

  /* Sum: '<S445>/Add2' incorporates:
   *  Abs: '<S445>/Abs'
   *  Gain: '<S445>/Gain'
   *  Gain: '<S445>/Gain1'
   *  Product: '<S445>/Multiply2'
   *  Product: '<S445>/Multiply3'
   *  Sqrt: '<S445>/Sqrt'
   *  Sum: '<S445>/Add1'
   *  Sum: '<S445>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S445>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S445>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S445>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S445>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S445>/Sign1' */

  /* Signum: '<S445>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S445>/Sign2' */

  /* Sum: '<S445>/Add5' incorporates:
   *  Gain: '<S445>/Gain2'
   *  Product: '<S445>/Multiply4'
   *  Sum: '<S445>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S441>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S444>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S444>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S444>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S445>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S445>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S445>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_g;
  }

  /* End of Signum: '<S445>/Sign5' */

  /* Signum: '<S445>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S445>/Sign3' */

  /* Signum: '<S445>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S445>/Sign4' */

  /* Signum: '<S445>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S445>/Sign6' */

  /* Update for DiscreteIntegrator: '<S444>/Integrator' incorporates:
   *  Constant: '<S445>/const'
   *  Gain: '<S445>/Gain3'
   *  Product: '<S445>/Divide'
   *  Product: '<S445>/Multiply5'
   *  Product: '<S445>/Multiply6'
   *  Sum: '<S445>/Subtract4'
   *  Sum: '<S445>/Subtract5'
   *  Sum: '<S445>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S438>/Motion Status'
 *    '<S358>/Motion Status'
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
 *    '<S438>/Motion Status'
 *    '<S358>/Motion Status'
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
 *    '<S438>/Motion Status'
 *    '<S358>/Motion Status'
 *    '<S192>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S438>/Motion Status' */
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

  /* End of Chart: '<S438>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S447>/Hold Control'
 *    '<S379>/Hold Control'
 *    '<S201>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S450>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S447>/Hold Control'
 *    '<S379>/Hold Control'
 *    '<S201>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S450>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S447>/Hold Control'
 *    '<S379>/Hold Control'
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

  /* Delay: '<S450>/Delay' incorporates:
   *  SignalConversion: '<S450>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S454>/Trigonometric Function1' incorporates:
   *  Gain: '<S453>/Gain'
   *  Trigonometry: '<S454>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S454>/Trigonometric Function' incorporates:
   *  Gain: '<S453>/Gain'
   *  Trigonometry: '<S454>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S454>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S454>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S454>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S454>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S454>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S454>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S454>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S450>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S450>/Delay'
   *  SignalConversion: '<S450>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S450>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S450>/Multiply' incorporates:
   *  SignalConversion: '<S450>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S450>/Multiply' */

  /* Gain: '<S450>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S450>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S447>/Brake Control'
 *    '<S379>/Brake Control'
 *    '<S201>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S449>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S447>/Move Control'
 *    '<S379>/Move Control'
 *    '<S201>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S457>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S457>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S457>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S457>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S447>/Move Control'
 *    '<S379>/Move Control'
 *    '<S201>/Move Control'
 */
void FMS_MoveControl_i_Reset(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S457>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S457>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S457>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S457>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S447>/Move Control'
 *    '<S379>/Move Control'
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

  /* SignalConversion: '<S451>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S457>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S458>/Multiply1' incorporates:
   *  Constant: '<S458>/const1'
   *  DiscreteIntegrator: '<S457>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S451>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S457>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S458>/Multiply1' incorporates:
   *  Constant: '<S458>/const1'
   *  DiscreteIntegrator: '<S457>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S455>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S455>/Dead Zone' */

  /* Sum: '<S458>/Add' incorporates:
   *  DiscreteIntegrator: '<S457>/Integrator1'
   *  Gain: '<S451>/Gain6'
   *  Gain: '<S455>/Gain'
   *  Sum: '<S457>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S456>/Dead Zone' */
  if (rtu_FMS_In_o > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_o >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S456>/Dead Zone' */

  /* Sum: '<S458>/Add' incorporates:
   *  DiscreteIntegrator: '<S457>/Integrator1'
   *  Gain: '<S451>/Gain6'
   *  Gain: '<S456>/Gain'
   *  Sum: '<S457>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S458>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S458>/Add2' incorporates:
   *  Abs: '<S458>/Abs'
   *  Gain: '<S458>/Gain'
   *  Gain: '<S458>/Gain1'
   *  Product: '<S458>/Multiply2'
   *  Product: '<S458>/Multiply3'
   *  Signum: '<S458>/Sign'
   *  Sqrt: '<S458>/Sqrt'
   *  Sum: '<S458>/Add1'
   *  Sum: '<S458>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S458>/Add3' incorporates:
   *  Signum: '<S458>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S458>/Subtract1' incorporates:
   *  Signum: '<S458>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S458>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S458>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S458>/Add5' incorporates:
   *  Gain: '<S458>/Gain2'
   *  Product: '<S458>/Multiply4'
   *  Signum: '<S458>/Sign'
   *  Sum: '<S458>/Add2'
   *  Sum: '<S458>/Add4'
   *  Sum: '<S458>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S457>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S457>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S458>/Sign3' incorporates:
   *  Sum: '<S458>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S458>/Sign4' incorporates:
   *  Sum: '<S458>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S458>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S458>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S458>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S458>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S457>/Integrator' incorporates:
   *  Constant: '<S458>/const'
   *  Gain: '<S458>/Gain3'
   *  Product: '<S458>/Divide'
   *  Product: '<S458>/Multiply5'
   *  Product: '<S458>/Multiply6'
   *  Sum: '<S458>/Subtract4'
   *  Sum: '<S458>/Subtract5'
   *  Sum: '<S458>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Signum: '<S458>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_l_idx_0 = 1.0F;
  } else {
    rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S458>/Add2' incorporates:
   *  Abs: '<S458>/Abs'
   *  Gain: '<S458>/Gain'
   *  Gain: '<S458>/Gain1'
   *  Product: '<S458>/Multiply2'
   *  Product: '<S458>/Multiply3'
   *  Signum: '<S458>/Sign'
   *  Sqrt: '<S458>/Sqrt'
   *  Sum: '<S458>/Add1'
   *  Sum: '<S458>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_l_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S458>/Add3' incorporates:
   *  Signum: '<S458>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S458>/Subtract1' incorporates:
   *  Signum: '<S458>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S458>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S458>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S458>/Add5' incorporates:
   *  Gain: '<S458>/Gain2'
   *  Product: '<S458>/Multiply4'
   *  Signum: '<S458>/Sign'
   *  Sum: '<S458>/Add2'
   *  Sum: '<S458>/Add4'
   *  Sum: '<S458>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S457>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S457>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S458>/Sign3' incorporates:
   *  Sum: '<S458>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S458>/Sign4' incorporates:
   *  Sum: '<S458>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S458>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S458>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S458>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S458>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S457>/Integrator' incorporates:
   *  Constant: '<S458>/const'
   *  Gain: '<S458>/Gain3'
   *  Product: '<S458>/Divide'
   *  Product: '<S458>/Multiply5'
   *  Product: '<S458>/Multiply6'
   *  Sum: '<S458>/Subtract4'
   *  Sum: '<S458>/Subtract5'
   *  Sum: '<S458>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S448>/Motion State'
 *    '<S380>/Motion State'
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
 *    '<S448>/Motion State'
 *    '<S380>/Motion State'
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
 *    '<S448>/Motion State'
 *    '<S380>/Motion State'
 *    '<S202>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S448>/Motion State' */
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

  /* End of Chart: '<S448>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S424>/NearbyRefWP'
 *    '<S178>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S462>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S367>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S370>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S367>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S370>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S367>/Hold Control'
 *    '<S138>/Hold Control'
 *    '<S71>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_nb;

  /* Delay: '<S370>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S370>/Sum' incorporates:
   *  Delay: '<S370>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S373>/Abs' */
  rtb_Abs_nb = fabsf(rtb_psi_error_rad);

  /* Switch: '<S373>/Switch' incorporates:
   *  Constant: '<S373>/Constant'
   *  Constant: '<S374>/Constant'
   *  Product: '<S373>/Multiply'
   *  RelationalOperator: '<S374>/Compare'
   *  Sum: '<S373>/Subtract'
   */
  if (rtb_Abs_nb > 3.14159274F) {
    /* Signum: '<S373>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S373>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_nb - 6.28318548F;
  }

  /* End of Switch: '<S373>/Switch' */

  /* Gain: '<S370>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S370>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S367>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S376>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S376>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S367>/Move Control'
 *    '<S138>/Move Control'
 *    '<S71>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S376>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S376>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S367>/Move Control'
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

  /* Product: '<S377>/Multiply1' incorporates:
   *  Constant: '<S377>/const1'
   *  DiscreteIntegrator: '<S376>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S375>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S375>/Dead Zone' */

  /* Sum: '<S377>/Add' incorporates:
   *  DiscreteIntegrator: '<S376>/Integrator1'
   *  Gain: '<S371>/Gain1'
   *  Gain: '<S375>/Gain'
   *  Sum: '<S376>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S377>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S377>/Sign' */

  /* Sum: '<S377>/Add2' incorporates:
   *  Abs: '<S377>/Abs'
   *  Gain: '<S377>/Gain'
   *  Gain: '<S377>/Gain1'
   *  Product: '<S377>/Multiply2'
   *  Product: '<S377>/Multiply3'
   *  Sqrt: '<S377>/Sqrt'
   *  Sum: '<S377>/Add1'
   *  Sum: '<S377>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S377>/Add4' */
  rtb_Add4_b = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S377>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_l + localC->d;

  /* Sum: '<S377>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S377>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S377>/Sign1' */

  /* Signum: '<S377>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S377>/Sign2' */

  /* Sum: '<S377>/Add5' incorporates:
   *  Gain: '<S377>/Gain2'
   *  Product: '<S377>/Multiply4'
   *  Sum: '<S377>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_l) * 0.5F * rtb_Add4_b;

  /* SignalConversion: '<S371>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S376>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S376>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S376>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S377>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S377>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S377>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_b = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_b = 1.0F;
  } else {
    rtb_Add4_b = rtb_a_m;
  }

  /* End of Signum: '<S377>/Sign5' */

  /* Signum: '<S377>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S377>/Sign3' */

  /* Signum: '<S377>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S377>/Sign4' */

  /* Signum: '<S377>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S377>/Sign6' */

  /* Update for DiscreteIntegrator: '<S376>/Integrator' incorporates:
   *  Constant: '<S377>/const'
   *  Gain: '<S377>/Gain3'
   *  Product: '<S377>/Divide'
   *  Product: '<S377>/Multiply5'
   *  Product: '<S377>/Multiply6'
   *  Sum: '<S377>/Subtract4'
   *  Sum: '<S377>/Subtract5'
   *  Sum: '<S377>/Subtract6'
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

  /* BusAssignment: '<S353>/Bus Assignment' incorporates:
   *  Constant: '<S353>/Constant'
   *  Constant: '<S353>/Constant2'
   *  SignalConversion: '<S353>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S353>/Bus Assignment' */
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

  /* Gain: '<S500>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S501>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S501>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S501>/Multiply1' incorporates:
   *  Product: '<S501>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S501>/Divide' incorporates:
   *  Constant: '<S501>/Constant'
   *  Constant: '<S501>/R'
   *  Sqrt: '<S501>/Sqrt'
   *  Sum: '<S501>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S501>/Product3' incorporates:
   *  Constant: '<S501>/Constant1'
   *  Product: '<S501>/Multiply1'
   *  Sum: '<S501>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S501>/Multiply2' incorporates:
   *  Trigonometry: '<S501>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S500>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S505>/Abs' incorporates:
   *  Abs: '<S508>/Abs1'
   *  Switch: '<S505>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S505>/Switch1' incorporates:
   *  Abs: '<S505>/Abs'
   *  Bias: '<S505>/Bias2'
   *  Bias: '<S505>/Bias3'
   *  Constant: '<S502>/Constant'
   *  Constant: '<S502>/Constant1'
   *  Constant: '<S507>/Constant'
   *  Gain: '<S505>/Gain1'
   *  Product: '<S505>/Multiply'
   *  RelationalOperator: '<S507>/Compare'
   *  Switch: '<S502>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S508>/Switch1' incorporates:
     *  Bias: '<S508>/Bias2'
     *  Bias: '<S508>/Bias3'
     *  Constant: '<S508>/Constant'
     *  Constant: '<S509>/Constant'
     *  Math: '<S508>/Math Function'
     *  RelationalOperator: '<S509>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S508>/Switch1' */

    /* Signum: '<S505>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S505>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S502>/Sum' incorporates:
   *  Sum: '<S500>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S500>/Multiply' incorporates:
   *  Gain: '<S500>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S504>/Switch1' incorporates:
   *  Abs: '<S504>/Abs1'
   *  Bias: '<S504>/Bias2'
   *  Bias: '<S504>/Bias3'
   *  Constant: '<S504>/Constant'
   *  Constant: '<S506>/Constant'
   *  Math: '<S504>/Math Function'
   *  RelationalOperator: '<S506>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S504>/Switch1' */

  /* Product: '<S500>/Multiply' incorporates:
   *  Gain: '<S500>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S500>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S503>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S503>/Sum2' incorporates:
   *  Product: '<S503>/Multiply1'
   *  Product: '<S503>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S503>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S503>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S503>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S497>/Data Type Conversion' incorporates:
   *  Gain: '<S500>/Gain'
   *  Sum: '<S500>/Sum1'
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
  /* RelationalOperator: '<S510>/Compare' incorporates:
   *  Abs: '<S499>/Abs'
   *  Constant: '<S510>/Constant'
   *  MinMax: '<S499>/Max'
   *  Sum: '<S499>/Sum'
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
      /* Reshape: '<S498>/Reshape' incorporates:
       *  Constant: '<S498>/Constant'
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
  real32_T rtb_a_l;
  real32_T rtb_Add4_d;
  boolean_T rtb_Compare_on;
  boolean_T rtb_LogicalOperator_aa;
  real32_T rtb_Switch2_i;
  real32_T rtb_Integrator1_a;
  MotionState rtb_state_c;
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
  real32_T rtb_MathFunction_p_idx_1;
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
  real32_T rtb_MathFunction_f_idx_0;
  real32_T rtb_Divide_lr_idx_2;
  real32_T rtb_Divide_lr_idx_1;
  real32_T rtb_Divide_lr_idx_0;
  real_T rtb_Multiply_l5_idx_0;
  FMS_Error tmp_4;
  FMS_Error tmp_5;
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

  /* Sqrt: '<S520>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S520>/Square'
   *  Sum: '<S520>/Sum of Elements'
   */
  rtb_Saturation_n = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
    FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
    FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S516>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide_lr_idx_0 = FMS_U.INS_Out.quat[0] / rtb_Saturation_n;
  rtb_Divide_lr_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Saturation_n;
  rtb_Divide_lr_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_n;
  rtb_MathFunction_p_idx_1 = FMS_U.INS_Out.quat[3] / rtb_Saturation_n;

  /* Math: '<S517>/Square' incorporates:
   *  Math: '<S518>/Square'
   *  Math: '<S519>/Square'
   */
  rtb_Add4_d = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_0;

  /* Math: '<S517>/Square2' incorporates:
   *  Math: '<S518>/Square2'
   *  Math: '<S519>/Square2'
   */
  rtb_MathFunction_f_idx_0 = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

  /* Math: '<S517>/Square1' incorporates:
   *  Math: '<S518>/Square1'
   *  Math: '<S519>/Square1'
   */
  rtb_Saturation_n = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1;

  /* Math: '<S517>/Square3' incorporates:
   *  Math: '<S518>/Square3'
   *  Math: '<S519>/Square3'
   */
  rtb_a_l = rtb_MathFunction_p_idx_1 * rtb_MathFunction_p_idx_1;

  /* Sum: '<S517>/Subtract' incorporates:
   *  Math: '<S517>/Square'
   *  Math: '<S517>/Square1'
   *  Math: '<S517>/Square2'
   *  Math: '<S517>/Square3'
   *  Sum: '<S517>/Add'
   *  Sum: '<S517>/Add1'
   */
  rtb_Transpose[0] = (rtb_Add4_d + rtb_Saturation_n) - (rtb_MathFunction_f_idx_0
    + rtb_a_l);

  /* Product: '<S517>/Multiply' incorporates:
   *  Product: '<S518>/Multiply'
   */
  rtb_Switch2_i = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_2;

  /* Product: '<S517>/Multiply1' incorporates:
   *  Product: '<S518>/Multiply1'
   */
  rtb_Integrator1_a = rtb_Divide_lr_idx_0 * rtb_MathFunction_p_idx_1;

  /* Gain: '<S517>/Gain' incorporates:
   *  Product: '<S517>/Multiply'
   *  Product: '<S517>/Multiply1'
   *  Sum: '<S517>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_Switch2_i - rtb_Integrator1_a) * 2.0F;

  /* Product: '<S517>/Multiply2' incorporates:
   *  Product: '<S519>/Multiply'
   */
  rtb_MathFunction_f_idx_1 = rtb_Divide_lr_idx_1 * rtb_MathFunction_p_idx_1;

  /* Product: '<S517>/Multiply3' incorporates:
   *  Product: '<S519>/Multiply1'
   */
  rtb_MathFunction_f_idx_2 = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_2;

  /* Gain: '<S517>/Gain1' incorporates:
   *  Product: '<S517>/Multiply2'
   *  Product: '<S517>/Multiply3'
   *  Sum: '<S517>/Add2'
   */
  rtb_Transpose[2] = (rtb_MathFunction_f_idx_1 + rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Gain: '<S518>/Gain' incorporates:
   *  Sum: '<S518>/Add3'
   */
  rtb_Transpose[3] = (rtb_Switch2_i + rtb_Integrator1_a) * 2.0F;

  /* Sum: '<S518>/Subtract' incorporates:
   *  Sum: '<S518>/Add'
   *  Sum: '<S518>/Add1'
   */
  rtb_Transpose[4] = (rtb_Add4_d + rtb_MathFunction_f_idx_0) - (rtb_Saturation_n
    + rtb_a_l);

  /* Product: '<S518>/Multiply2' incorporates:
   *  Product: '<S519>/Multiply2'
   */
  rtb_Switch2_i = rtb_Divide_lr_idx_2 * rtb_MathFunction_p_idx_1;

  /* Product: '<S518>/Multiply3' incorporates:
   *  Product: '<S519>/Multiply3'
   */
  rtb_Integrator1_a = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_1;

  /* Gain: '<S518>/Gain1' incorporates:
   *  Product: '<S518>/Multiply2'
   *  Product: '<S518>/Multiply3'
   *  Sum: '<S518>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_Switch2_i - rtb_Integrator1_a) * 2.0F;

  /* Gain: '<S519>/Gain' incorporates:
   *  Sum: '<S519>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_MathFunction_f_idx_1 - rtb_MathFunction_f_idx_2) *
    2.0F;

  /* Gain: '<S519>/Gain1' incorporates:
   *  Sum: '<S519>/Add2'
   */
  rtb_Transpose[7] = (rtb_Switch2_i + rtb_Integrator1_a) * 2.0F;

  /* Sum: '<S519>/Subtract' incorporates:
   *  Sum: '<S519>/Add'
   *  Sum: '<S519>/Add1'
   */
  rtb_Transpose[8] = (rtb_Add4_d + rtb_a_l) - (rtb_Saturation_n +
    rtb_MathFunction_f_idx_0);

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

  /* DiscreteIntegrator: '<S511>/Discrete-Time Integrator5' */
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

  /* DiscreteIntegrator: '<S513>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S513>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_dr;
  }

  /* Product: '<S7>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S7>/Cos'
   *  Trigonometry: '<S7>/Cos1'
   */
  rtb_Add4_d = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32(FMS_U.INS_Out.theta);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Add4_d > 1.0F) {
    rtb_Add4_d = 1.0F;
  } else {
    if (rtb_Add4_d < 0.9F) {
      rtb_Add4_d = 0.9F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Land_Lock_Thro'
   */
  rtb_Divide_lr_idx_2 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_Add4_d;

  /* DiscreteIntegrator: '<S512>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_lr_idx_2;
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S511>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S512>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S513>/Discrete-Time Integrator5'
   *  Logic: '<S514>/AND'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S514>/Lower Test'
   *  RelationalOperator: '<S514>/Upper Test'
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

  /* Sum: '<S495>/Add' incorporates:
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
        /* Disable for SwitchCase: '<S447>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S437>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S379>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S357>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S367>/Switch Case' */
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
          /* Disable for SwitchCase: '<S447>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S437>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S379>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S357>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S367>/Switch Case' */
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
       *  Math: '<S469>/Math Function'
       *  Product: '<S471>/Divide'
       *  Sum: '<S425>/Subtract'
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
          /* Disable for SwitchCase: '<S447>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S437>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S379>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S357>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S367>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Takeoff' incorporates:
           *  ActionPort: '<S352>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S493>/cur_waypoint'
           *  DiscreteIntegrator: '<S489>/Integrator'
           *  DiscreteIntegrator: '<S489>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Takeoff' incorporates:
         *  ActionPort: '<S352>/Action Port'
         */
        /* Delay: '<S493>/cur_waypoint' incorporates:
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
        /* Product: '<S493>/Divide' incorporates:
         *  Delay: '<S493>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S493>/Sum1'
         *  Sum: '<S493>/Sum2'
         */
        rtb_Saturation_n = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
          FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Saturate: '<S493>/Saturation' */
        if (rtb_Saturation_n > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = 0.0F;
          }
        }

        /* End of Saturate: '<S493>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S494>/Trigonometric Function1' incorporates:
         *  Gain: '<S492>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S494>/Trigonometric Function3'
         */
        rtb_Add4_d = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[0] = rtb_Add4_d;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S494>/Trigonometric Function' incorporates:
         *  Gain: '<S492>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S494>/Trigonometric Function2'
         */
        rtb_MathFunction_f_idx_0 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[1] = rtb_MathFunction_f_idx_0;

        /* SignalConversion: '<S494>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S494>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S494>/Gain' */
        rtb_Transpose[3] = -rtb_MathFunction_f_idx_0;

        /* Trigonometry: '<S494>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_Add4_d;

        /* SignalConversion: '<S494>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S494>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S494>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S486>/Saturation1' */
        rtb_Divide_lr_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_a_l = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S486>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S493>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S493>/Multiply'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S486>/Sum'
         *  Sum: '<S493>/Sum3'
         *  Sum: '<S493>/Sum4'
         */
        rtb_Switch2_i = ((FMS_B.Cmd_In.sp_waypoint[0] -
                          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Saturation_n +
                         FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_Integrator1_a = ((FMS_B.Cmd_In.sp_waypoint[1] -
                              FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Saturation_n
                             + FMS_DW.cur_waypoint_DSTATE[1]) -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S486>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Integrator1_a + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Switch2_i;
        }

        /* Saturate: '<S486>/Saturation1' incorporates:
         *  Gain: '<S486>/Gain2'
         *  Product: '<S486>/Multiply'
         */
        rtb_Add4_d = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Saturation_n = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S352>/Bus Assignment1'
         *  Constant: '<S352>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S352>/Bus Assignment1' incorporates:
         *  Constant: '<S352>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S486>/Saturation1' */
        if (rtb_Add4_d > rtb_Divide_lr_idx_0) {
          /* BusAssignment: '<S352>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_lr_idx_0;
        } else if (rtb_Add4_d < rtb_a_l) {
          /* BusAssignment: '<S352>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_a_l;
        } else {
          /* BusAssignment: '<S352>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_d;
        }

        if (rtb_Saturation_n > rtb_Divide_lr_idx_0) {
          /* BusAssignment: '<S352>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Divide_lr_idx_0;
        } else if (rtb_Saturation_n < rtb_a_l) {
          /* BusAssignment: '<S352>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_l;
        } else {
          /* BusAssignment: '<S352>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        }

        /* BusAssignment: '<S352>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S489>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S490>/Multiply1' incorporates:
         *  Constant: '<S490>/const1'
         *  DiscreteIntegrator: '<S489>/Integrator'
         */
        rtb_Saturation_n = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S485>/Switch' incorporates:
         *  Abs: '<S485>/Abs'
         *  Abs: '<S485>/Abs1'
         *  Constant: '<S485>/Takeoff_Speed'
         *  Constant: '<S487>/Constant'
         *  Constant: '<S488>/Constant'
         *  Gain: '<S485>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S485>/Logical Operator'
         *  RelationalOperator: '<S487>/Compare'
         *  RelationalOperator: '<S488>/Compare'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S485>/Sum'
         *  Sum: '<S485>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_Divide_lr_idx_0 = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_Divide_lr_idx_0 = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S485>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S490>/Add' incorporates:
         *  DiscreteIntegrator: '<S489>/Integrator1'
         *  Sum: '<S489>/Subtract'
         */
        rtb_Divide_lr_idx_0 = (FMS_DW.Integrator1_DSTATE_a - rtb_Divide_lr_idx_0)
          + rtb_Saturation_n;

        /* Signum: '<S490>/Sign' */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_Divide_lr_idx_0 > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_Divide_lr_idx_0;
        }

        /* End of Signum: '<S490>/Sign' */

        /* Sum: '<S490>/Add2' incorporates:
         *  Abs: '<S490>/Abs'
         *  Gain: '<S490>/Gain'
         *  Gain: '<S490>/Gain1'
         *  Product: '<S490>/Multiply2'
         *  Product: '<S490>/Multiply3'
         *  Sqrt: '<S490>/Sqrt'
         *  Sum: '<S490>/Add1'
         *  Sum: '<S490>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_0) + FMS_ConstB.d_m) *
                         FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F * rtb_Add4_d +
          rtb_Saturation_n;

        /* Sum: '<S490>/Add4' */
        rtb_Add4_d = (rtb_Divide_lr_idx_0 - rtb_a_l) + rtb_Saturation_n;

        /* Sum: '<S490>/Add3' */
        rtb_Saturation_n = rtb_Divide_lr_idx_0 + FMS_ConstB.d_m;

        /* Sum: '<S490>/Subtract1' */
        rtb_Divide_lr_idx_0 -= FMS_ConstB.d_m;

        /* Signum: '<S490>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S490>/Sign1' */

        /* Signum: '<S490>/Sign2' */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Divide_lr_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_0 > 0.0F) {
            rtb_Divide_lr_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S490>/Sign2' */

        /* Sum: '<S490>/Add5' incorporates:
         *  Gain: '<S490>/Gain2'
         *  Product: '<S490>/Multiply4'
         *  Sum: '<S490>/Subtract2'
         */
        rtb_a_l += (rtb_Saturation_n - rtb_Divide_lr_idx_0) * 0.5F * rtb_Add4_d;

        /* Update for Delay: '<S493>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S489>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S489>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S490>/Subtract3' */
        rtb_Saturation_n = rtb_a_l - FMS_ConstB.d_m;

        /* Sum: '<S490>/Add6' */
        rtb_Add4_d = rtb_a_l + FMS_ConstB.d_m;

        /* Signum: '<S490>/Sign5' incorporates:
         *  Signum: '<S490>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Switch2_i = -1.0F;

          /* Signum: '<S490>/Sign6' */
          rtb_Divide_lr_idx_0 = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Switch2_i = 1.0F;

          /* Signum: '<S490>/Sign6' */
          rtb_Divide_lr_idx_0 = 1.0F;
        } else {
          rtb_Switch2_i = rtb_a_l;

          /* Signum: '<S490>/Sign6' */
          rtb_Divide_lr_idx_0 = rtb_a_l;
        }

        /* End of Signum: '<S490>/Sign5' */

        /* Signum: '<S490>/Sign3' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S490>/Sign3' */

        /* Signum: '<S490>/Sign4' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S490>/Sign4' */

        /* Update for DiscreteIntegrator: '<S489>/Integrator' incorporates:
         *  Constant: '<S490>/const'
         *  Gain: '<S490>/Gain3'
         *  Product: '<S490>/Divide'
         *  Product: '<S490>/Multiply5'
         *  Product: '<S490>/Multiply6'
         *  Sum: '<S490>/Subtract4'
         *  Sum: '<S490>/Subtract5'
         *  Sum: '<S490>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_a_l / FMS_ConstB.d_m - rtb_Switch2_i)
          * FMS_ConstB.Gain4_a * ((rtb_Add4_d - rtb_Saturation_n) * 0.5F) -
          rtb_Divide_lr_idx_0 * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Land' incorporates:
           *  ActionPort: '<S350>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S395>/Integrator'
           *  DiscreteIntegrator: '<S395>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S39>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Land' incorporates:
         *  ActionPort: '<S350>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S400>/Trigonometric Function1' incorporates:
         *  Gain: '<S399>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S400>/Trigonometric Function' incorporates:
         *  Gain: '<S399>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S400>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S400>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S400>/Gain' incorporates:
         *  Gain: '<S399>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S400>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S400>/Trigonometric Function3' incorporates:
         *  Gain: '<S399>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S400>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S400>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S400>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S393>/Saturation1' */
        rtb_Switch2_i = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Divide_lr_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S397>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S397>/Sum'
         */
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S397>/Multiply' incorporates:
         *  SignalConversion: '<S397>/TmpSignal ConversionAtMultiplyInport2'
         *  Sum: '<S397>/Sum'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Add4_d + rtb_Transpose[rtb_Compare_bv_0] * rtb_Saturation_n;
        }

        /* End of Product: '<S397>/Multiply' */

        /* Saturate: '<S393>/Saturation1' incorporates:
         *  Gain: '<S397>/Gain2'
         */
        rtb_Add4_d = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Saturation_n = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S350>/Bus Assignment1'
         *  Constant: '<S350>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
         *  Constant: '<S350>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S393>/Saturation1' */
        if (rtb_Add4_d > rtb_Switch2_i) {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch2_i;
        } else if (rtb_Add4_d < rtb_Divide_lr_idx_0) {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_lr_idx_0;
        } else {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_d;
        }

        if (rtb_Saturation_n > rtb_Switch2_i) {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch2_i;
        } else if (rtb_Saturation_n < rtb_Divide_lr_idx_0) {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Divide_lr_idx_0;
        } else {
          /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        }

        /* BusAssignment: '<S350>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S395>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S396>/Multiply1' incorporates:
         *  Constant: '<S396>/const1'
         *  DiscreteIntegrator: '<S395>/Integrator'
         */
        rtb_Saturation_n = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S392>/Switch' incorporates:
         *  Constant: '<S392>/Land_Speed'
         *  Constant: '<S394>/Constant'
         *  Gain: '<S392>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S392>/Logical Operator'
         *  RelationalOperator: '<S394>/Compare'
         *  S-Function (sfix_bitop): '<S392>/cmd_p valid'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_Divide_lr_idx_0 = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_Divide_lr_idx_0 = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S392>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S396>/Add' incorporates:
         *  DiscreteIntegrator: '<S395>/Integrator1'
         *  Sum: '<S395>/Subtract'
         */
        rtb_Divide_lr_idx_0 = (FMS_DW.Integrator1_DSTATE_j - rtb_Divide_lr_idx_0)
          + rtb_Saturation_n;

        /* Signum: '<S396>/Sign' */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_Divide_lr_idx_0 > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_Divide_lr_idx_0;
        }

        /* End of Signum: '<S396>/Sign' */

        /* Sum: '<S396>/Add2' incorporates:
         *  Abs: '<S396>/Abs'
         *  Gain: '<S396>/Gain'
         *  Gain: '<S396>/Gain1'
         *  Product: '<S396>/Multiply2'
         *  Product: '<S396>/Multiply3'
         *  Sqrt: '<S396>/Sqrt'
         *  Sum: '<S396>/Add1'
         *  Sum: '<S396>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_0) + FMS_ConstB.d_p) *
                         FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F * rtb_Add4_d +
          rtb_Saturation_n;

        /* Sum: '<S396>/Add4' */
        rtb_Add4_d = (rtb_Divide_lr_idx_0 - rtb_a_l) + rtb_Saturation_n;

        /* Sum: '<S396>/Add3' */
        rtb_Saturation_n = rtb_Divide_lr_idx_0 + FMS_ConstB.d_p;

        /* Sum: '<S396>/Subtract1' */
        rtb_Divide_lr_idx_0 -= FMS_ConstB.d_p;

        /* Signum: '<S396>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S396>/Sign1' */

        /* Signum: '<S396>/Sign2' */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Divide_lr_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_0 > 0.0F) {
            rtb_Divide_lr_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S396>/Sign2' */

        /* Sum: '<S396>/Add5' incorporates:
         *  Gain: '<S396>/Gain2'
         *  Product: '<S396>/Multiply4'
         *  Sum: '<S396>/Subtract2'
         */
        rtb_a_l += (rtb_Saturation_n - rtb_Divide_lr_idx_0) * 0.5F * rtb_Add4_d;

        /* Update for DiscreteIntegrator: '<S395>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S395>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S396>/Subtract3' */
        rtb_Saturation_n = rtb_a_l - FMS_ConstB.d_p;

        /* Sum: '<S396>/Add6' */
        rtb_Add4_d = rtb_a_l + FMS_ConstB.d_p;

        /* Signum: '<S396>/Sign5' incorporates:
         *  Signum: '<S396>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Switch2_i = -1.0F;

          /* Signum: '<S396>/Sign6' */
          rtb_Divide_lr_idx_0 = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Switch2_i = 1.0F;

          /* Signum: '<S396>/Sign6' */
          rtb_Divide_lr_idx_0 = 1.0F;
        } else {
          rtb_Switch2_i = rtb_a_l;

          /* Signum: '<S396>/Sign6' */
          rtb_Divide_lr_idx_0 = rtb_a_l;
        }

        /* End of Signum: '<S396>/Sign5' */

        /* Signum: '<S396>/Sign3' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S396>/Sign3' */

        /* Signum: '<S396>/Sign4' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S396>/Sign4' */

        /* Update for DiscreteIntegrator: '<S395>/Integrator' incorporates:
         *  Constant: '<S396>/const'
         *  Gain: '<S396>/Gain3'
         *  Product: '<S396>/Divide'
         *  Product: '<S396>/Multiply5'
         *  Product: '<S396>/Multiply6'
         *  Sum: '<S396>/Subtract4'
         *  Sum: '<S396>/Subtract5'
         *  Sum: '<S396>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_a_l / FMS_ConstB.d_p - rtb_Switch2_i)
          * FMS_ConstB.Gain4_e * ((rtb_Add4_d - rtb_Saturation_n) * 0.5F) -
          rtb_Divide_lr_idx_0 * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S39>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S39>/Return' incorporates:
           *  ActionPort: '<S351>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Delay: '<S403>/Delay'
           *  Delay: '<S404>/Delay'
           *  Delay: '<S426>/Delay'
           *  Delay: '<S426>/Delay1'
           *  DiscreteIntegrator: '<S407>/Integrator'
           *  DiscreteIntegrator: '<S407>/Integrator1'
           *  DiscreteIntegrator: '<S422>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S427>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S476>/Discrete-Time Integrator'
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
           *  ActionPort: '<S351>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S438>/Motion Status'
           *  Chart: '<S448>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S39>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Return' incorporates:
         *  ActionPort: '<S351>/Action Port'
         */
        /* RelationalOperator: '<S421>/Compare' incorporates:
         *  Constant: '<S484>/Constant'
         *  DiscreteIntegrator: '<S427>/Discrete-Time Integrator'
         *  RelationalOperator: '<S484>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* Logic: '<S426>/Logical Operator' incorporates:
         *  Delay: '<S426>/Delay1'
         */
        rtb_LogicalOperator_aa = (rtb_Compare_on || FMS_DW.Delay1_DSTATE_b);

        /* Delay: '<S426>/Delay' incorporates:
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
        /* RelationalOperator: '<S431>/Compare' incorporates:
         *  Constant: '<S431>/Constant'
         *  Delay: '<S426>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        FMS_DW.Delay1_DSTATE_b = (FMS_B.Cmd_In.set_speed > 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S422>/Switch2' incorporates:
         *  Constant: '<S422>/vel'
         *  Delay: '<S426>/Delay1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_DW.Delay1_DSTATE_b) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Switch2_i = FMS_B.Cmd_In.set_speed;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_Switch2_i = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S422>/Switch2' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S426>/Sum' incorporates:
         *  Delay: '<S426>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_e[0];

        /* Sum: '<S422>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* Sum: '<S426>/Sum' incorporates:
         *  Delay: '<S426>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_a_l = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_e[1];

        /* Sum: '<S422>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_h_idx_0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint
          [1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S434>/Sqrt' incorporates:
         *  Math: '<S434>/Square'
         *  Sum: '<S422>/Sum'
         *  Sum: '<S434>/Sum of Elements'
         */
        rtb_Divide_lr_idx_0 = sqrtf(rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0);

        /* Switch: '<S422>/Switch' */
        if (rtb_Divide_lr_idx_0 > FMS_PARAM.L1) {
          B = rtb_Switch2_i;
        } else {
          /* Gain: '<S422>/Gain' */
          B = 0.5F * rtb_Divide_lr_idx_0;

          /* Switch: '<S432>/Switch2' incorporates:
           *  Constant: '<S422>/Constant1'
           *  RelationalOperator: '<S432>/LowerRelop1'
           *  RelationalOperator: '<S432>/UpperRelop'
           *  Switch: '<S432>/Switch'
           */
          if (B > rtb_Switch2_i) {
            B = rtb_Switch2_i;
          } else {
            if (B < 0.5F) {
              /* Switch: '<S432>/Switch' incorporates:
               *  Constant: '<S422>/Constant1'
               */
              B = 0.5F;
            }
          }

          /* End of Switch: '<S432>/Switch2' */
        }

        /* End of Switch: '<S422>/Switch' */

        /* DiscreteIntegrator: '<S422>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Switch: '<S433>/Switch2' incorporates:
         *  Constant: '<S422>/Constant2'
         *  DiscreteIntegrator: '<S422>/Acceleration_Speed'
         *  RelationalOperator: '<S433>/LowerRelop1'
         *  RelationalOperator: '<S433>/UpperRelop'
         *  Switch: '<S433>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_Switch2_i) {
          rtb_Integrator1_a = rtb_Switch2_i;
        } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
          /* Switch: '<S433>/Switch' incorporates:
           *  Constant: '<S422>/Constant2'
           */
          rtb_Integrator1_a = 0.0F;
        } else {
          rtb_Integrator1_a = FMS_DW.Acceleration_Speed_DSTATE_j;
        }

        /* End of Switch: '<S433>/Switch2' */

        /* Switch: '<S422>/Switch1' incorporates:
         *  Sum: '<S422>/Sum1'
         */
        if (rtb_Integrator1_a - B >= 0.0F) {
          rtb_Integrator1_a = B;
        }

        /* End of Switch: '<S422>/Switch1' */

        /* DiscreteIntegrator: '<S476>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRe_e !=
             0)) {
          FMS_DW.l1_heading_e = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S448>/Motion State' incorporates:
         *  Constant: '<S448>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S448>/Square'
         *  Math: '<S448>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S448>/Sqrt'
         *  Sum: '<S448>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S447>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S447>/Hold Control' incorporates:
             *  ActionPort: '<S450>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S447>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S447>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S447>/Hold Control' incorporates:
           *  ActionPort: '<S450>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S447>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S447>/Brake Control' incorporates:
           *  ActionPort: '<S449>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S447>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S447>/Move Control' incorporates:
             *  ActionPort: '<S451>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S447>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_j);

            /* End of SystemReset for SubSystem: '<S447>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S447>/Move Control' incorporates:
           *  ActionPort: '<S451>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_a,
                            &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S447>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S447>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S438>/Motion Status' incorporates:
         *  Abs: '<S438>/Abs'
         *  Constant: '<S438>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S437>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S437>/Hold Control' incorporates:
             *  ActionPort: '<S440>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S437>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S437>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S437>/Hold Control' incorporates:
           *  ActionPort: '<S440>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_jj,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S437>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S437>/Brake Control' incorporates:
           *  ActionPort: '<S439>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_jj);

          /* End of Outputs for SubSystem: '<S437>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S437>/Move Control' incorporates:
             *  ActionPort: '<S441>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S437>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S437>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S437>/Move Control' incorporates:
           *  ActionPort: '<S441>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_jj,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S437>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S437>/Switch Case' */

        /* Switch: '<S402>/Switch' incorporates:
         *  Product: '<S426>/Multiply'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S447>/Saturation1' */
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

          /* End of Saturate: '<S447>/Saturation1' */

          /* Saturate: '<S437>/Saturation1' */
          if (FMS_B.Merge_jj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_jj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_jj;
          }

          /* End of Saturate: '<S437>/Saturation1' */
        } else {
          /* SignalConversion: '<S483>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S483>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S482>/Gain' incorporates:
           *  DiscreteIntegrator: '<S476>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S476>/Add'
           */
          rtb_MathFunction_p_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S483>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S483>/Trigonometric Function1'
           */
          rtb_Add4_d = arm_cos_f32(rtb_MathFunction_p_idx_1);
          rtb_Transpose[4] = rtb_Add4_d;

          /* Trigonometry: '<S483>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S483>/Trigonometric Function'
           */
          rtb_MathFunction_f_idx_0 = arm_sin_f32(rtb_MathFunction_p_idx_1);

          /* Gain: '<S483>/Gain' incorporates:
           *  Trigonometry: '<S483>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_f_idx_0;

          /* SignalConversion: '<S483>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S483>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S483>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_f_idx_0;

          /* Trigonometry: '<S483>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_Add4_d;

          /* SignalConversion: '<S483>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Sum: '<S478>/Sum of Elements' incorporates:
           *  Math: '<S478>/Math Function'
           *  SignalConversion: '<S478>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_0 = rtb_Saturation_n * rtb_Saturation_n + rtb_a_l *
            rtb_a_l;

          /* Math: '<S478>/Math Function1' incorporates:
           *  Sum: '<S478>/Sum of Elements'
           *
           * About '<S478>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_0 < 0.0F) {
            rtb_MathFunction_p_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
          } else {
            rtb_MathFunction_p_idx_1 = sqrtf(rtb_Divide_lr_idx_0);
          }

          /* End of Math: '<S478>/Math Function1' */

          /* Switch: '<S478>/Switch' incorporates:
           *  Constant: '<S478>/Constant'
           *  Product: '<S478>/Product'
           */
          if (rtb_MathFunction_p_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_0 = rtb_Saturation_n;
            rtb_Divide_lr_idx_1 = rtb_a_l;
          } else {
            rtb_Divide_lr_idx_0 = 0.0F;
            rtb_Divide_lr_idx_1 = 0.0F;
            rtb_MathFunction_p_idx_1 = 1.0F;
          }

          /* End of Switch: '<S478>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S428>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S428>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S428>/Divide' incorporates:
           *  Math: '<S429>/Square'
           *  Math: '<S430>/Square'
           *  Sqrt: '<S429>/Sqrt'
           *  Sqrt: '<S430>/Sqrt'
           *  Sum: '<S428>/Sum'
           *  Sum: '<S428>/Sum1'
           *  Sum: '<S429>/Sum of Elements'
           *  Sum: '<S430>/Sum of Elements'
           */
          rtb_Add4_d = sqrtf(rtb_Add4_d * rtb_Add4_d + rtb_MathFunction_f_idx_0 *
                             rtb_MathFunction_f_idx_0) / sqrtf(rtb_P_l_idx_0 *
            rtb_P_l_idx_0 + rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0);

          /* Saturate: '<S428>/Saturation' */
          if (rtb_Add4_d > 1.0F) {
            rtb_Add4_d = 1.0F;
          } else {
            if (rtb_Add4_d < 0.0F) {
              rtb_Add4_d = 0.0F;
            }
          }

          /* End of Saturate: '<S428>/Saturation' */

          /* Product: '<S474>/Multiply2' incorporates:
           *  Product: '<S478>/Divide'
           */
          rtb_Divide_lr_idx_0 = rtb_Divide_lr_idx_0 / rtb_MathFunction_p_idx_1 *
            rtb_Integrator1_a;
          rtb_Divide_lr_idx_1 = rtb_Divide_lr_idx_1 / rtb_MathFunction_p_idx_1 *
            rtb_Integrator1_a;

          /* Product: '<S426>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Divide_lr_idx_1 + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Divide_lr_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S419>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S428>/Multiply'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S419>/Sum2'
           *  Sum: '<S428>/Add'
           *  Sum: '<S428>/Subtract'
           */
          rtb_Add4_d = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Add4_d +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S419>/Saturation1' incorporates:
           *  Product: '<S426>/Multiply'
           */
          if (rtb_Add4_d > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Add4_d < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Add4_d;
          }

          /* End of Saturate: '<S419>/Saturation1' */
        }

        /* End of Switch: '<S402>/Switch' */

        /* Delay: '<S404>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S407>/Integrator1' incorporates:
         *  Delay: '<S404>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S411>/Rem' incorporates:
         *  Constant: '<S411>/Constant1'
         *  DiscreteIntegrator: '<S407>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S406>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S411>/Switch' incorporates:
         *  Abs: '<S411>/Abs'
         *  Constant: '<S411>/Constant'
         *  Constant: '<S412>/Constant'
         *  Product: '<S411>/Multiply'
         *  RelationalOperator: '<S412>/Compare'
         *  Sum: '<S411>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S411>/Sign' */
          if (B < 0.0F) {
            rtb_Divide_lr_idx_0 = -1.0F;
          } else if (B > 0.0F) {
            rtb_Divide_lr_idx_0 = 1.0F;
          } else {
            rtb_Divide_lr_idx_0 = B;
          }

          /* End of Signum: '<S411>/Sign' */
          B -= 6.28318548F * rtb_Divide_lr_idx_0;
        }

        /* End of Switch: '<S411>/Switch' */

        /* Gain: '<S406>/Gain2' */
        B *= FMS_PARAM.YAW_P;

        /* Saturate: '<S406>/Saturation' */
        if (B > FMS_PARAM.YAW_RATE_LIM) {
          B = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (B < -FMS_PARAM.YAW_RATE_LIM) {
            B = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S406>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S351>/Bus Assignment1'
         *  Constant: '<S351>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S351>/Bus Assignment1' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Sum: '<S480>/Sum of Elements' incorporates:
         *  Math: '<S480>/Math Function'
         *  SignalConversion: '<S480>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_0 = rtb_a_l * rtb_a_l + rtb_Saturation_n *
          rtb_Saturation_n;

        /* Math: '<S480>/Math Function1' incorporates:
         *  Sum: '<S480>/Sum of Elements'
         *
         * About '<S480>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
        } else {
          B = sqrtf(rtb_Divide_lr_idx_0);
        }

        /* End of Math: '<S480>/Math Function1' */

        /* Switch: '<S480>/Switch' incorporates:
         *  Constant: '<S480>/Constant'
         *  Product: '<S480>/Product'
         */
        if (B > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_a_l;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Saturation_n;
          rtb_TmpSignalConversionAtMath_c[2] = B;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S480>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S468>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S468>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S466>/Sum of Elements'
         */
        rtb_Divide_lr_idx_0 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S468>/Math Function1' incorporates:
         *  Sum: '<S468>/Sum of Elements'
         *
         * About '<S468>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
        } else {
          B = sqrtf(rtb_Divide_lr_idx_0);
        }

        /* End of Math: '<S468>/Math Function1' */

        /* Switch: '<S468>/Switch' incorporates:
         *  Constant: '<S468>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S468>/Product'
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

        /* End of Switch: '<S468>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S426>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_mp_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Switch_mp_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S481>/Sum of Elements' incorporates:
         *  Math: '<S481>/Math Function'
         *  Sum: '<S426>/Sum1'
         */
        D = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 + rtb_Switch_mp_idx_1 *
          rtb_Switch_mp_idx_1;

        /* Math: '<S481>/Math Function1' incorporates:
         *  Sum: '<S481>/Sum of Elements'
         *
         * About '<S481>/Math Function1':
         *  Operator: sqrt
         */
        if (D < 0.0F) {
          B = -sqrtf(fabsf(D));
        } else {
          B = sqrtf(D);
        }

        /* End of Math: '<S481>/Math Function1' */

        /* Switch: '<S481>/Switch' incorporates:
         *  Constant: '<S481>/Constant'
         *  Product: '<S481>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_mp_idx_2 = B;
        } else {
          rtb_Switch_mp_idx_0 = 0.0F;
          rtb_Switch_mp_idx_1 = 0.0F;
          rtb_Switch_mp_idx_2 = 1.0F;
        }

        /* End of Switch: '<S481>/Switch' */

        /* Delay: '<S403>/Delay' incorporates:
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
        /* Sum: '<S351>/Sum' incorporates:
         *  Delay: '<S403>/Delay'
         *  MATLAB Function: '<S424>/OutRegionRegWP'
         *  MATLAB Function: '<S424>/SearchL1RefWP'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S418>/Sum of Elements' incorporates:
         *  Math: '<S418>/Math Function'
         *  Sum: '<S351>/Sum'
         */
        D = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 + rtb_P_l_idx_0 *
          rtb_P_l_idx_0;

        /* Math: '<S418>/Math Function1' incorporates:
         *  Sum: '<S418>/Sum of Elements'
         *
         * About '<S418>/Math Function1':
         *  Operator: sqrt
         */
        if (D < 0.0F) {
          B = -sqrtf(fabsf(D));
        } else {
          B = sqrtf(D);
        }

        /* End of Math: '<S418>/Math Function1' */

        /* Switch: '<S418>/Switch' incorporates:
         *  Constant: '<S418>/Constant'
         *  Product: '<S418>/Product'
         *  Sum: '<S351>/Sum'
         */
        if (B > 0.0F) {
          rtb_Switch_f3_idx_0 = rtb_MathFunction_h_idx_0;
          rtb_Switch_f3_idx_1 = rtb_P_l_idx_0;
          rtb_Switch_f3_idx_2 = B;
        } else {
          rtb_Switch_f3_idx_0 = 0.0F;
          rtb_Switch_f3_idx_1 = 0.0F;
          rtb_Switch_f3_idx_2 = 1.0F;
        }

        /* End of Switch: '<S418>/Switch' */

        /* Product: '<S468>/Divide' */
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sum: '<S471>/Sum of Elements' incorporates:
         *  Math: '<S471>/Math Function'
         *  SignalConversion: '<S471>/TmpSignal ConversionAtMath FunctionInport1'
         */
        D = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Math: '<S471>/Math Function1' incorporates:
         *  Sum: '<S471>/Sum of Elements'
         *
         * About '<S471>/Math Function1':
         *  Operator: sqrt
         */
        if (D < 0.0F) {
          B = -sqrtf(fabsf(D));
        } else {
          B = sqrtf(D);
        }

        /* End of Math: '<S471>/Math Function1' */

        /* Switch: '<S471>/Switch' incorporates:
         *  Constant: '<S471>/Constant'
         *  Product: '<S471>/Product'
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

        /* End of Switch: '<S471>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S424>/NearbyRefWP' incorporates:
         *  Constant: '<S351>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_ff, &rtb_a_l);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* MATLAB Function: '<S424>/SearchL1RefWP' incorporates:
         *  Constant: '<S351>/L1'
         *  Delay: '<S403>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Add4_d = rtb_P_l_idx_0 * rtb_P_l_idx_0 + rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        B = (rtb_P_l_idx_0 * (FMS_DW.Delay_DSTATE_p[0] - FMS_U.INS_Out.x_R) +
             rtb_MathFunction_h_idx_0 * (FMS_DW.Delay_DSTATE_p[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Add4_d);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Saturation_n = -1.0F;
        rtb_Divide_lr_idx_1 = 0.0F;
        rtb_MathFunction_p_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          rtb_MathFunction_h_idx_1 = sqrtf(D);
          D = (-B + rtb_MathFunction_h_idx_1) / (2.0F * rtb_Add4_d);
          rtb_Add4_d = (-B - rtb_MathFunction_h_idx_1) / (2.0F * rtb_Add4_d);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Add4_d >= 0.0F) && (rtb_Add4_d <=
               1.0F)) {
            rtb_Saturation_n = fmaxf(D, rtb_Add4_d);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Saturation_n = D;
            guard1 = true;
          } else {
            if ((rtb_Add4_d >= 0.0F) && (rtb_Add4_d <= 1.0F)) {
              rtb_Saturation_n = rtb_Add4_d;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Add4_d);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Saturation_n = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_Divide_lr_idx_1 = rtb_P_l_idx_0 * rtb_Saturation_n +
            FMS_DW.Delay_DSTATE_p[0];
          rtb_MathFunction_p_idx_1 = rtb_MathFunction_h_idx_0 * rtb_Saturation_n
            + FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S424>/OutRegionRegWP' incorporates:
         *  Delay: '<S403>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add4_d = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
                      rtb_MathFunction_h_idx_0 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE_p[0]) * rtb_P_l_idx_0) / (rtb_P_l_idx_0 *
          rtb_P_l_idx_0 + rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Add4_d <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Add4_d >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_l_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_a4) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_P_l_idx_0 = rtb_Add4_d * rtb_P_l_idx_0 + FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S424>/Switch1' incorporates:
         *  Constant: '<S461>/Constant'
         *  RelationalOperator: '<S461>/Compare'
         */
        if (rtb_a_l <= 0.0F) {
          /* Switch: '<S424>/Switch' incorporates:
           *  Constant: '<S460>/Constant'
           *  MATLAB Function: '<S424>/SearchL1RefWP'
           *  RelationalOperator: '<S460>/Compare'
           */
          if (rtb_Saturation_n >= 0.0F) {
            rtb_Sum_ff[0] = rtb_Divide_lr_idx_1;
            rtb_Sum_ff[1] = rtb_MathFunction_p_idx_1;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S424>/OutRegionRegWP' incorporates:
             *  Delay: '<S403>/Delay'
             *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_ff[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_a4) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else {
              rtb_Sum_ff[1] = rtb_Add4_d * rtb_MathFunction_h_idx_0 +
                FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S424>/Switch' */
        }

        /* End of Switch: '<S424>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S425>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Add4_d = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Add4_d;
        rtb_Saturation_n = rtb_Add4_d * rtb_Add4_d;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S425>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S469>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Add4_d = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S469>/Math Function' incorporates:
         *  Math: '<S467>/Square'
         */
        D = rtb_Add4_d * rtb_Add4_d;

        /* Sum: '<S469>/Sum of Elements' incorporates:
         *  Math: '<S469>/Math Function'
         */
        rtb_Saturation_n += D;

        /* Math: '<S469>/Math Function1' incorporates:
         *  Sum: '<S469>/Sum of Elements'
         *
         * About '<S469>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          B = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          B = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S469>/Math Function1' */

        /* Switch: '<S469>/Switch' incorporates:
         *  Constant: '<S469>/Constant'
         *  Product: '<S469>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Add4_d;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S469>/Switch' */

        /* Product: '<S469>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S472>/Sum of Elements' incorporates:
         *  Math: '<S472>/Math Function'
         *  SignalConversion: '<S472>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_n = rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 +
          rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Math: '<S472>/Math Function1' incorporates:
         *  Sum: '<S472>/Sum of Elements'
         *
         * About '<S472>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          B = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          B = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S472>/Math Function1' */

        /* Switch: '<S472>/Switch' incorporates:
         *  Constant: '<S472>/Constant'
         *  Product: '<S472>/Product'
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

        /* End of Switch: '<S472>/Switch' */

        /* Product: '<S472>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S467>/Square' */
        rtb_Saturation_n = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S418>/Divide' */
        rtb_Divide_lr_idx_1 = rtb_Switch_f3_idx_0 / rtb_Switch_f3_idx_2;

        /* Product: '<S481>/Divide' */
        rtb_P_l_idx_0 = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S480>/Divide' */
        rtb_Switch_mp_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;

        /* Product: '<S472>/Divide' incorporates:
         *  Product: '<S471>/Divide'
         */
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S471>/Divide' */
        rtb_Add4_d = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S418>/Divide' */
        rtb_MathFunction_p_idx_1 = rtb_Switch_f3_idx_1 / rtb_Switch_f3_idx_2;

        /* Product: '<S481>/Divide' */
        rtb_MathFunction_f_idx_0 = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S480>/Divide' */
        rtb_MathFunction_f_idx_1 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S479>/Subtract' incorporates:
         *  Product: '<S479>/Multiply'
         *  Product: '<S479>/Multiply1'
         */
        B = rtb_P_l_idx_0 * rtb_MathFunction_f_idx_1 - rtb_MathFunction_f_idx_0 *
          rtb_Switch_mp_idx_0;

        /* Signum: '<S475>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S475>/Sign1' */

        /* Switch: '<S475>/Switch2' incorporates:
         *  Constant: '<S475>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S475>/Switch2' */

        /* DotProduct: '<S475>/Dot Product' */
        rtb_MathFunction_f_idx_1 = rtb_Switch_mp_idx_0 * rtb_P_l_idx_0 +
          rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_0;

        /* Trigonometry: '<S475>/Acos' incorporates:
         *  DotProduct: '<S475>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_1 > 1.0F) {
          rtb_MathFunction_f_idx_1 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_1 < -1.0F) {
            rtb_MathFunction_f_idx_1 = -1.0F;
          }
        }

        /* Product: '<S475>/Multiply' incorporates:
         *  Trigonometry: '<S475>/Acos'
         */
        B *= acosf(rtb_MathFunction_f_idx_1);

        /* Abs: '<S426>/Abs' */
        B = fabsf(B);

        /* RelationalOperator: '<S473>/Compare' incorporates:
         *  Constant: '<S473>/Constant'
         *  Delay: '<S426>/Delay1'
         */
        FMS_DW.Delay1_DSTATE_b = (B > 1.57079637F);

        /* Sqrt: '<S466>/Sqrt' */
        rtb_Divide_lr_idx_0 = sqrtf(rtb_Divide_lr_idx_0);

        /* Math: '<S425>/Square' */
        rtb_a_l = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_0;

        /* Sum: '<S470>/Subtract' incorporates:
         *  Product: '<S470>/Multiply'
         *  Product: '<S470>/Multiply1'
         */
        rtb_Divide_lr_idx_0 = rtb_MathFunction_h_idx_0 * rtb_Add4_d -
          rtb_MathFunction_h_idx_1 * rtb_Sum_ff[0];

        /* Signum: '<S465>/Sign1' */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Divide_lr_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_0 > 0.0F) {
            rtb_Divide_lr_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S465>/Sign1' */

        /* Switch: '<S465>/Switch2' incorporates:
         *  Constant: '<S465>/Constant4'
         */
        if (rtb_Divide_lr_idx_0 == 0.0F) {
          rtb_Divide_lr_idx_0 = 1.0F;
        }

        /* End of Switch: '<S465>/Switch2' */

        /* DotProduct: '<S465>/Dot Product' */
        rtb_Add4_d = rtb_Sum_ff[0] * rtb_MathFunction_h_idx_0 + rtb_Add4_d *
          rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S465>/Acos' incorporates:
         *  DotProduct: '<S465>/Dot Product'
         */
        if (rtb_Add4_d > 1.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          if (rtb_Add4_d < -1.0F) {
            rtb_Add4_d = -1.0F;
          }
        }

        /* Product: '<S465>/Multiply' incorporates:
         *  Trigonometry: '<S465>/Acos'
         */
        rtb_Divide_lr_idx_0 *= acosf(rtb_Add4_d);

        /* Saturate: '<S425>/Saturation' */
        if (rtb_Divide_lr_idx_0 > 1.57079637F) {
          rtb_Divide_lr_idx_0 = 1.57079637F;
        } else {
          if (rtb_Divide_lr_idx_0 < -1.57079637F) {
            rtb_Divide_lr_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S425>/Saturation' */

        /* Switch: '<S477>/Switch2' incorporates:
         *  Constant: '<S426>/Constant1'
         *  RelationalOperator: '<S477>/LowerRelop1'
         *  RelationalOperator: '<S477>/UpperRelop'
         *  Switch: '<S477>/Switch'
         */
        if (rtb_Integrator1_a > rtb_Switch2_i) {
          rtb_Integrator1_a = rtb_Switch2_i;
        } else {
          if (rtb_Integrator1_a < 0.5F) {
            /* Switch: '<S477>/Switch' incorporates:
             *  Constant: '<S426>/Constant1'
             */
            rtb_Integrator1_a = 0.5F;
          }
        }

        /* End of Switch: '<S477>/Switch2' */

        /* Product: '<S426>/Divide1' incorporates:
         *  Constant: '<S351>/L1'
         *  Constant: '<S425>/Constant'
         *  Gain: '<S425>/Gain'
         *  MinMax: '<S425>/Max'
         *  MinMax: '<S425>/Min'
         *  Product: '<S425>/Divide'
         *  Product: '<S425>/Multiply1'
         *  Sqrt: '<S467>/Sqrt'
         *  Sum: '<S467>/Sum of Elements'
         *  Trigonometry: '<S425>/Sin'
         */
        rtb_Divide_lr_idx_0 = 2.0F * rtb_a_l * arm_sin_f32(rtb_Divide_lr_idx_0) /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(D + rtb_Saturation_n), 0.5F)) /
          rtb_Integrator1_a;

        /* Saturate: '<S426>/Saturation' */
        if (rtb_Divide_lr_idx_0 > 0.314159274F) {
          rtb_Integrator1_a = 0.314159274F;
        } else if (rtb_Divide_lr_idx_0 < -0.314159274F) {
          rtb_Integrator1_a = -0.314159274F;
        } else {
          rtb_Integrator1_a = rtb_Divide_lr_idx_0;
        }

        /* End of Saturate: '<S426>/Saturation' */

        /* Sum: '<S416>/Subtract' incorporates:
         *  Product: '<S416>/Multiply'
         *  Product: '<S416>/Multiply1'
         */
        rtb_Divide_lr_idx_0 = rtb_Divide_lr_idx_1 * FMS_ConstB.Divide_d[1] -
          rtb_MathFunction_p_idx_1 * FMS_ConstB.Divide_d[0];

        /* Signum: '<S405>/Sign1' */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Divide_lr_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_0 > 0.0F) {
            rtb_Divide_lr_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S405>/Sign1' */

        /* Switch: '<S405>/Switch2' incorporates:
         *  Constant: '<S405>/Constant4'
         */
        if (rtb_Divide_lr_idx_0 == 0.0F) {
          rtb_Divide_lr_idx_0 = 1.0F;
        }

        /* End of Switch: '<S405>/Switch2' */

        /* DotProduct: '<S405>/Dot Product' */
        rtb_Add4_d = FMS_ConstB.Divide_d[0] * rtb_Divide_lr_idx_1 +
          FMS_ConstB.Divide_d[1] * rtb_MathFunction_p_idx_1;

        /* Trigonometry: '<S405>/Acos' incorporates:
         *  DotProduct: '<S405>/Dot Product'
         */
        if (rtb_Add4_d > 1.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          if (rtb_Add4_d < -1.0F) {
            rtb_Add4_d = -1.0F;
          }
        }

        /* Product: '<S405>/Multiply' incorporates:
         *  Trigonometry: '<S405>/Acos'
         */
        rtb_Divide_lr_idx_0 *= acosf(rtb_Add4_d);

        /* Math: '<S408>/Rem' incorporates:
         *  Constant: '<S408>/Constant1'
         *  Delay: '<S404>/Delay'
         *  Sum: '<S404>/Sum2'
         */
        B = rt_remf(rtb_Divide_lr_idx_0 - FMS_DW.Delay_DSTATE_a, 6.28318548F);

        /* Switch: '<S408>/Switch' incorporates:
         *  Abs: '<S408>/Abs'
         *  Constant: '<S408>/Constant'
         *  Constant: '<S414>/Constant'
         *  Product: '<S408>/Multiply'
         *  RelationalOperator: '<S414>/Compare'
         *  Sum: '<S408>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S408>/Sign' */
          if (B < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (B > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = B;
          }

          /* End of Signum: '<S408>/Sign' */
          B -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S408>/Switch' */

        /* Sum: '<S404>/Sum' incorporates:
         *  Delay: '<S404>/Delay'
         */
        rtb_Saturation_n = B + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S413>/Multiply1' incorporates:
         *  Constant: '<S413>/const1'
         *  DiscreteIntegrator: '<S407>/Integrator'
         */
        B = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S413>/Add' incorporates:
         *  DiscreteIntegrator: '<S407>/Integrator1'
         *  Sum: '<S407>/Subtract'
         */
        rtb_Add4_d = (FMS_DW.Integrator1_DSTATE_e - rtb_Saturation_n) + B;

        /* Signum: '<S413>/Sign' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Add4_d > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Add4_d;
        }

        /* End of Signum: '<S413>/Sign' */

        /* Sum: '<S413>/Add2' incorporates:
         *  Abs: '<S413>/Abs'
         *  Gain: '<S413>/Gain'
         *  Gain: '<S413>/Gain1'
         *  Product: '<S413>/Multiply2'
         *  Product: '<S413>/Multiply3'
         *  Sqrt: '<S413>/Sqrt'
         *  Sum: '<S413>/Add1'
         *  Sum: '<S413>/Subtract'
         */
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Add4_d) + FMS_ConstB.d_l) *
                         FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Saturation_n + B;

        /* Sum: '<S413>/Add4' */
        rtb_Switch2_i = (rtb_Add4_d - rtb_a_l) + B;

        /* Sum: '<S413>/Add3' */
        rtb_Saturation_n = rtb_Add4_d + FMS_ConstB.d_l;

        /* Sum: '<S413>/Subtract1' */
        rtb_Add4_d -= FMS_ConstB.d_l;

        /* Signum: '<S413>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S413>/Sign1' */

        /* Signum: '<S413>/Sign2' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S413>/Sign2' */

        /* Sum: '<S413>/Add5' incorporates:
         *  Gain: '<S413>/Gain2'
         *  Product: '<S413>/Multiply4'
         *  Sum: '<S413>/Subtract2'
         */
        rtb_a_l += (rtb_Saturation_n - rtb_Add4_d) * 0.5F * rtb_Switch2_i;

        /* Sum: '<S413>/Add6' */
        rtb_Saturation_n = rtb_a_l + FMS_ConstB.d_l;

        /* Sum: '<S413>/Subtract3' */
        rtb_Add4_d = rtb_a_l - FMS_ConstB.d_l;

        /* Product: '<S413>/Divide' */
        rtb_Divide_lr_idx_1 = rtb_a_l / FMS_ConstB.d_l;

        /* Signum: '<S413>/Sign5' incorporates:
         *  Signum: '<S413>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_MathFunction_p_idx_1 = -1.0F;

          /* Signum: '<S413>/Sign6' */
          rtb_Switch2_i = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_MathFunction_p_idx_1 = 1.0F;

          /* Signum: '<S413>/Sign6' */
          rtb_Switch2_i = 1.0F;
        } else {
          rtb_MathFunction_p_idx_1 = rtb_a_l;

          /* Signum: '<S413>/Sign6' */
          rtb_Switch2_i = rtb_a_l;
        }

        /* End of Signum: '<S413>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S404>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Divide_lr_idx_0 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S409>/Rem' incorporates:
         *  Constant: '<S409>/Constant1'
         */
        rtb_a_l = rt_remf(rtb_Divide_lr_idx_0, 6.28318548F);

        /* Switch: '<S409>/Switch' incorporates:
         *  Abs: '<S409>/Abs'
         *  Constant: '<S409>/Constant'
         *  Constant: '<S415>/Constant'
         *  Product: '<S409>/Multiply'
         *  RelationalOperator: '<S415>/Compare'
         *  Sum: '<S409>/Add'
         */
        if (fabsf(rtb_a_l) > 3.14159274F) {
          /* Signum: '<S409>/Sign' */
          if (rtb_a_l < 0.0F) {
            rtb_Divide_lr_idx_0 = -1.0F;
          } else if (rtb_a_l > 0.0F) {
            rtb_Divide_lr_idx_0 = 1.0F;
          } else {
            rtb_Divide_lr_idx_0 = rtb_a_l;
          }

          /* End of Signum: '<S409>/Sign' */
          rtb_a_l -= 6.28318548F * rtb_Divide_lr_idx_0;
        }

        /* End of Switch: '<S409>/Switch' */

        /* Abs: '<S402>/Abs' */
        rtb_a_l = fabsf(rtb_a_l);

        /* Update for DiscreteIntegrator: '<S427>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S420>/Constant'
         *  RelationalOperator: '<S420>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_m = (uint8_T)((uint32_T)(rtb_a_l <=
          0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_m);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_m >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S427>/Discrete-Time Integrator' */

        /* Update for Delay: '<S426>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S422>/Acceleration_Speed' incorporates:
         *  Constant: '<S422>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S476>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_Integrator1_a;
        FMS_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)rtb_LogicalOperator_aa;

        /* Update for Delay: '<S404>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S407>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S407>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S403>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S413>/Sign3' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S413>/Sign3' */

        /* Signum: '<S413>/Sign4' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S413>/Sign4' */

        /* Update for DiscreteIntegrator: '<S407>/Integrator' incorporates:
         *  Constant: '<S413>/const'
         *  Gain: '<S413>/Gain3'
         *  Product: '<S413>/Multiply5'
         *  Product: '<S413>/Multiply6'
         *  Sum: '<S413>/Subtract4'
         *  Sum: '<S413>/Subtract5'
         *  Sum: '<S413>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Divide_lr_idx_1 -
          rtb_MathFunction_p_idx_1) * FMS_ConstB.Gain4_n * ((rtb_Saturation_n -
          rtb_Add4_d) * 0.5F) - rtb_Switch2_i * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S407>/Integrator' */
        /* End of Outputs for SubSystem: '<S39>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S39>/Hold' incorporates:
           *  ActionPort: '<S349>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S39>/Switch Case' incorporates:
           *  Chart: '<S358>/Motion Status'
           *  Chart: '<S368>/Motion State'
           *  Chart: '<S380>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S39>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S39>/Hold' incorporates:
         *  ActionPort: '<S349>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S358>/Motion Status' incorporates:
         *  Abs: '<S358>/Abs'
         *  Constant: '<S358>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S368>/Motion State' incorporates:
         *  Abs: '<S368>/Abs'
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

        /* End of Chart: '<S368>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S380>/Motion State' incorporates:
         *  Constant: '<S380>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S380>/Square'
         *  Math: '<S380>/Square1'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sqrt: '<S380>/Sqrt'
         *  Sum: '<S380>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S379>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S379>/Hold Control' incorporates:
             *  ActionPort: '<S382>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S379>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S379>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S379>/Hold Control' incorporates:
           *  ActionPort: '<S382>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S379>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S379>/Brake Control' incorporates:
           *  ActionPort: '<S381>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S379>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S379>/Move Control' incorporates:
             *  ActionPort: '<S383>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S379>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S379>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S379>/Move Control' incorporates:
           *  ActionPort: '<S383>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S379>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S379>/Switch Case' */

        /* SwitchCase: '<S357>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S357>/Hold Control' incorporates:
             *  ActionPort: '<S360>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S357>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S357>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S357>/Hold Control' incorporates:
           *  ActionPort: '<S360>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S357>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S357>/Brake Control' incorporates:
           *  ActionPort: '<S359>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S357>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S357>/Move Control' incorporates:
             *  ActionPort: '<S361>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S357>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S357>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S357>/Move Control' incorporates:
           *  ActionPort: '<S361>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S357>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S357>/Switch Case' */

        /* SwitchCase: '<S367>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S367>/Hold Control' incorporates:
             *  ActionPort: '<S370>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S367>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S367>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S367>/Hold Control' incorporates:
           *  ActionPort: '<S370>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S367>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S367>/Brake Control' incorporates:
           *  ActionPort: '<S369>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S367>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S367>/Move Control' incorporates:
             *  ActionPort: '<S371>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S367>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S367>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S367>/Move Control' incorporates:
           *  ActionPort: '<S371>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S367>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S367>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S349>/Bus Assignment'
         *  Constant: '<S349>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S349>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S367>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S367>/Saturation' */

        /* Saturate: '<S379>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S379>/Saturation1' */

        /* Saturate: '<S357>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S349>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S357>/Saturation1' */
        /* End of Outputs for SubSystem: '<S39>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S39>/Unknown' incorporates:
         *  ActionPort: '<S353>/Action Port'
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
        /* Gain: '<S326>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S329>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S330>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S330>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S330>/Multiply1' incorporates:
         *  Product: '<S330>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S330>/Divide' incorporates:
         *  Constant: '<S330>/Constant'
         *  Constant: '<S330>/R'
         *  Sqrt: '<S330>/Sqrt'
         *  Sum: '<S330>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S330>/Product3' incorporates:
         *  Constant: '<S330>/Constant1'
         *  Product: '<S330>/Multiply1'
         *  Sum: '<S330>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S330>/Multiply2' incorporates:
         *  Trigonometry: '<S330>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S329>/Sum' incorporates:
         *  Gain: '<S326>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S334>/Abs' incorporates:
         *  Abs: '<S337>/Abs1'
         *  Switch: '<S334>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S334>/Switch1' incorporates:
         *  Abs: '<S334>/Abs'
         *  Bias: '<S334>/Bias2'
         *  Bias: '<S334>/Bias3'
         *  Constant: '<S331>/Constant'
         *  Constant: '<S331>/Constant1'
         *  Constant: '<S336>/Constant'
         *  Gain: '<S334>/Gain1'
         *  Product: '<S334>/Multiply'
         *  RelationalOperator: '<S336>/Compare'
         *  Switch: '<S331>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S337>/Switch1' incorporates:
           *  Bias: '<S337>/Bias2'
           *  Bias: '<S337>/Bias3'
           *  Constant: '<S337>/Constant'
           *  Constant: '<S338>/Constant'
           *  Math: '<S337>/Math Function'
           *  RelationalOperator: '<S338>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S337>/Switch1' */

          /* Signum: '<S334>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S334>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S331>/Sum' incorporates:
         *  Gain: '<S326>/Gain1'
         *  Gain: '<S326>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S329>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S329>/Multiply' incorporates:
         *  Gain: '<S329>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S333>/Switch1' incorporates:
         *  Abs: '<S333>/Abs1'
         *  Bias: '<S333>/Bias2'
         *  Bias: '<S333>/Bias3'
         *  Constant: '<S333>/Constant'
         *  Constant: '<S335>/Constant'
         *  Math: '<S333>/Math Function'
         *  RelationalOperator: '<S335>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S333>/Switch1' */

        /* Product: '<S329>/Multiply' incorporates:
         *  Gain: '<S329>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S320>/Trigonometric Function1' incorporates:
         *  Gain: '<S319>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S320>/Trigonometric Function' incorporates:
         *  Gain: '<S319>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S320>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S320>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S320>/Gain' incorporates:
         *  Gain: '<S319>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S320>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S320>/Trigonometric Function3' incorporates:
         *  Gain: '<S319>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S320>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S320>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S320>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S304>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S309>/Multiply1'
         *  Product: '<S310>/Multiply3'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Switch: '<S313>/Switch' incorporates:
           *  Constant: '<S328>/Constant'
           *  DataTypeConversion: '<S326>/Data Type Conversion1'
           *  Product: '<S332>/Multiply1'
           *  Product: '<S332>/Multiply2'
           *  RelationalOperator: '<S328>/Compare'
           *  S-Function (sfix_bitop): '<S325>/lat_cmd valid'
           *  Sum: '<S332>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Divide_lr_idx_0 = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Divide_lr_idx_0 = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  Constant: '<S318>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S317>/Compare'
           *  RelationalOperator: '<S318>/Compare'
           *  S-Function (sfix_bitop): '<S308>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Switch2_i = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Divide_lr_idx_0 -
            FMS_U.INS_Out.x_R : 0.0F;

          /* Switch: '<S313>/Switch' incorporates:
           *  Constant: '<S328>/Constant'
           *  DataTypeConversion: '<S326>/Data Type Conversion1'
           *  Product: '<S332>/Multiply3'
           *  Product: '<S332>/Multiply4'
           *  RelationalOperator: '<S328>/Compare'
           *  S-Function (sfix_bitop): '<S325>/lon_cmd valid'
           *  Sum: '<S332>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Divide_lr_idx_0 = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Divide_lr_idx_0 = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  Constant: '<S318>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S317>/Compare'
           *  RelationalOperator: '<S318>/Compare'
           *  S-Function (sfix_bitop): '<S308>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Divide_lr_idx_0 -
            FMS_U.INS_Out.y_R : 0.0F;

          /* Switch: '<S313>/Switch' incorporates:
           *  Constant: '<S328>/Constant'
           *  DataTypeConversion: '<S326>/Data Type Conversion'
           *  DataTypeConversion: '<S326>/Data Type Conversion1'
           *  Gain: '<S326>/Gain2'
           *  Gain: '<S329>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S328>/Compare'
           *  S-Function (sfix_bitop): '<S325>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S329>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Divide_lr_idx_0 = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Divide_lr_idx_0 = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  Constant: '<S318>/Constant'
           *  Gain: '<S314>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S317>/Compare'
           *  RelationalOperator: '<S318>/Compare'
           *  S-Function (sfix_bitop): '<S308>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Divide_lr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Divide_lr_idx_0 -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_lr_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_i);
          }
          break;

         case 1:
          /* Switch: '<S313>/Switch' incorporates:
           *  Constant: '<S328>/Constant'
           *  DataTypeConversion: '<S326>/Data Type Conversion1'
           *  Product: '<S332>/Multiply1'
           *  Product: '<S332>/Multiply2'
           *  RelationalOperator: '<S328>/Compare'
           *  S-Function (sfix_bitop): '<S325>/lat_cmd valid'
           *  Sum: '<S332>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Divide_lr_idx_0 = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Divide_lr_idx_0 = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  Constant: '<S318>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S317>/Compare'
           *  RelationalOperator: '<S318>/Compare'
           *  S-Function (sfix_bitop): '<S308>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/x_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Switch2_i = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Divide_lr_idx_0 -
            FMS_U.INS_Out.x_R : 0.0F;

          /* Switch: '<S313>/Switch' incorporates:
           *  Constant: '<S328>/Constant'
           *  DataTypeConversion: '<S326>/Data Type Conversion1'
           *  Product: '<S332>/Multiply3'
           *  Product: '<S332>/Multiply4'
           *  RelationalOperator: '<S328>/Compare'
           *  S-Function (sfix_bitop): '<S325>/lon_cmd valid'
           *  Sum: '<S332>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Divide_lr_idx_0 = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Divide_lr_idx_0 = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  Constant: '<S318>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S317>/Compare'
           *  RelationalOperator: '<S318>/Compare'
           *  S-Function (sfix_bitop): '<S308>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/y_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Divide_lr_idx_0 -
            FMS_U.INS_Out.y_R : 0.0F;

          /* Switch: '<S313>/Switch' incorporates:
           *  Constant: '<S328>/Constant'
           *  DataTypeConversion: '<S326>/Data Type Conversion'
           *  DataTypeConversion: '<S326>/Data Type Conversion1'
           *  Gain: '<S326>/Gain2'
           *  Gain: '<S329>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S328>/Compare'
           *  S-Function (sfix_bitop): '<S325>/alt_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S329>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Divide_lr_idx_0 = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Divide_lr_idx_0 = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S309>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  Constant: '<S318>/Constant'
           *  Gain: '<S314>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  RelationalOperator: '<S317>/Compare'
           *  RelationalOperator: '<S318>/Compare'
           *  S-Function (sfix_bitop): '<S308>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/z_cmd valid'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S309>/Sum1'
           */
          rtb_Divide_lr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Divide_lr_idx_0 -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_lr_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_i);
          }
          break;

         case 2:
          /* SignalConversion: '<S323>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S323>/Constant4'
           */
          rtb_VectorConcatenate_ia[5] = 0.0F;

          /* Trigonometry: '<S323>/Trigonometric Function3' incorporates:
           *  DataStoreRead: '<S310>/Data Store Read'
           *  Gain: '<S321>/Gain'
           *  Trigonometry: '<S323>/Trigonometric Function1'
           */
          rtb_Saturation_n = arm_cos_f32(-FMS_DW.home[3]);
          rtb_VectorConcatenate_ia[4] = rtb_Saturation_n;

          /* Trigonometry: '<S323>/Trigonometric Function2' incorporates:
           *  DataStoreRead: '<S310>/Data Store Read'
           *  Gain: '<S321>/Gain'
           *  Trigonometry: '<S323>/Trigonometric Function'
           */
          rtb_Divide_lr_idx_0 = arm_sin_f32(-FMS_DW.home[3]);

          /* Gain: '<S323>/Gain' incorporates:
           *  Trigonometry: '<S323>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ia[3] = -rtb_Divide_lr_idx_0;

          /* SignalConversion: '<S323>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S323>/Constant3'
           */
          rtb_VectorConcatenate_ia[2] = 0.0F;

          /* Trigonometry: '<S323>/Trigonometric Function' */
          rtb_VectorConcatenate_ia[1] = rtb_Divide_lr_idx_0;

          /* Trigonometry: '<S323>/Trigonometric Function1' */
          rtb_VectorConcatenate_ia[0] = rtb_Saturation_n;

          /* SignalConversion: '<S323>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[6] = FMS_ConstB.VectorConcatenate3_ny[0];

          /* SignalConversion: '<S324>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ei[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S323>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[7] = FMS_ConstB.VectorConcatenate3_ny[1];

          /* SignalConversion: '<S324>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ei[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S323>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[8] = FMS_ConstB.VectorConcatenate3_ny[2];

          /* SignalConversion: '<S324>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ei[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S324>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S324>/Constant4'
           */
          rtb_VectorConcatenate_ei[5] = 0.0F;

          /* Gain: '<S322>/Gain' incorporates:
           *  DataStoreRead: '<S310>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S310>/Subtract'
           */
          rtb_Divide_lr_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S324>/Trigonometric Function3' incorporates:
           *  Gain: '<S322>/Gain'
           *  Trigonometry: '<S324>/Trigonometric Function1'
           */
          rtb_Saturation_n = arm_cos_f32(rtb_Divide_lr_idx_0);
          rtb_VectorConcatenate_ei[4] = rtb_Saturation_n;

          /* Trigonometry: '<S324>/Trigonometric Function2' incorporates:
           *  Gain: '<S322>/Gain'
           *  Trigonometry: '<S324>/Trigonometric Function'
           */
          rtb_Divide_lr_idx_0 = arm_sin_f32(rtb_Divide_lr_idx_0);

          /* Gain: '<S324>/Gain' incorporates:
           *  Trigonometry: '<S324>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ei[3] = -rtb_Divide_lr_idx_0;

          /* SignalConversion: '<S324>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S324>/Constant3'
           */
          rtb_VectorConcatenate_ei[2] = 0.0F;

          /* Trigonometry: '<S324>/Trigonometric Function' */
          rtb_VectorConcatenate_ei[1] = rtb_Divide_lr_idx_0;

          /* Trigonometry: '<S324>/Trigonometric Function1' */
          rtb_VectorConcatenate_ei[0] = rtb_Saturation_n;

          /* RelationalOperator: '<S328>/Compare' incorporates:
           *  Constant: '<S328>/Constant'
           *  S-Function (sfix_bitop): '<S325>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S325>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S325>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S326>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S326>/Data Type Conversion'
           *  Gain: '<S326>/Gain2'
           *  Gain: '<S329>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S332>/Multiply1'
           *  Product: '<S332>/Multiply2'
           *  Product: '<S332>/Multiply3'
           *  Product: '<S332>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S329>/Sum1'
           *  Sum: '<S332>/Sum2'
           *  Sum: '<S332>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S313>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S317>/Compare' incorporates:
           *  Constant: '<S317>/Constant'
           *  S-Function (sfix_bitop): '<S308>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S318>/Compare' incorporates:
           *  Constant: '<S318>/Constant'
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
             *  Switch: '<S313>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Divide_lr_idx_0 = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Divide_lr_idx_0 = tmp_0[rtb_Compare_bv_0];
            }

            /* Product: '<S310>/Multiply' incorporates:
             *  Gain: '<S314>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S308>/Logical Operator'
             *  Product: '<S310>/Multiply2'
             *  SignalConversion: '<S31>/Signal Copy1'
             *  Sum: '<S310>/Sum2'
             */
            tmp_3[rtb_Compare_bv_0] = tmp_1[rtb_Compare_bv_0] ||
              tmp_2[rtb_Compare_bv_0] ? rtb_Divide_lr_idx_0 -
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
          /* SignalConversion: '<S316>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ia[6] = FMS_ConstB.VectorConcatenate3_n[0];
          rtb_VectorConcatenate_ia[7] = FMS_ConstB.VectorConcatenate3_n[1];
          rtb_VectorConcatenate_ia[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S316>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S316>/Constant4'
           */
          rtb_VectorConcatenate_ia[5] = 0.0F;

          /* Trigonometry: '<S316>/Trigonometric Function3' incorporates:
           *  Gain: '<S315>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_VectorConcatenate_ia[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S316>/Gain' incorporates:
           *  Gain: '<S315>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Trigonometry: '<S316>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ia[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S316>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S316>/Constant3'
           */
          rtb_VectorConcatenate_ia[2] = 0.0F;

          /* Trigonometry: '<S316>/Trigonometric Function' incorporates:
           *  Gain: '<S315>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_VectorConcatenate_ia[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S316>/Trigonometric Function1' incorporates:
           *  Gain: '<S315>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          rtb_VectorConcatenate_ia[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S325>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S308>/lat_cmd valid'
           */
          tmp_6 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S328>/Compare' incorporates:
           *  Constant: '<S328>/Constant'
           *  S-Function (sfix_bitop): '<S325>/lat_cmd valid'
           */
          tmp[0] = (tmp_6 > 0U);

          /* S-Function (sfix_bitop): '<S325>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S308>/lon_cmd valid'
           */
          tmp_7 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S328>/Compare' incorporates:
           *  Constant: '<S328>/Constant'
           *  S-Function (sfix_bitop): '<S325>/lon_cmd valid'
           */
          tmp[1] = (tmp_7 > 0U);

          /* S-Function (sfix_bitop): '<S325>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S308>/alt_cmd valid'
           */
          tmp_8 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S328>/Compare' incorporates:
           *  Constant: '<S328>/Constant'
           *  S-Function (sfix_bitop): '<S325>/alt_cmd valid'
           */
          tmp[2] = (tmp_8 > 0U);

          /* DataTypeConversion: '<S326>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S326>/Data Type Conversion'
           *  Gain: '<S326>/Gain2'
           *  Gain: '<S329>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S332>/Multiply1'
           *  Product: '<S332>/Multiply2'
           *  Product: '<S332>/Multiply3'
           *  Product: '<S332>/Multiply4'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S329>/Sum1'
           *  Sum: '<S332>/Sum2'
           *  Sum: '<S332>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S313>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S317>/Compare' incorporates:
           *  Constant: '<S317>/Constant'
           *  S-Function (sfix_bitop): '<S308>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S318>/Compare' incorporates:
           *  Constant: '<S318>/Constant'
           */
          tmp_2[0] = (tmp_6 > 0U);
          tmp_2[1] = (tmp_7 > 0U);
          tmp_2[2] = (tmp_8 > 0U);

          /* Sum: '<S306>/Sum2' incorporates:
           *  Gain: '<S314>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S308>/Logical Operator'
           *  Product: '<S306>/Multiply'
           *  Product: '<S306>/Multiply2'
           *  SignalConversion: '<S31>/Signal Copy1'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S313>/Switch' incorporates:
             *  Product: '<S306>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Divide_lr_idx_0 = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Divide_lr_idx_0 = tmp_0[rtb_Compare_bv_0];
            }

            rtb_MatrixConcatenate3[rtb_Compare_bv_0] = tmp_1[rtb_Compare_bv_0] ||
              tmp_2[rtb_Compare_bv_0] ? rtb_Divide_lr_idx_0 -
              ((rtb_VectorConcatenate_ia[rtb_Compare_bv_0 + 3] *
                FMS_U.INS_Out.y_R + rtb_VectorConcatenate_ia[rtb_Compare_bv_0] *
                FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_ia[rtb_Compare_bv_0 +
               6] * -FMS_U.INS_Out.h_R) : 0.0F;
          }

          /* End of Sum: '<S306>/Sum2' */
          break;
        }

        /* End of MultiPortSwitch: '<S304>/Index Vector' */

        /* Trigonometry: '<S250>/Trigonometric Function1' incorporates:
         *  Gain: '<S249>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S250>/Trigonometric Function' incorporates:
         *  Gain: '<S249>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S250>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S250>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S250>/Gain' incorporates:
         *  Gain: '<S249>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S250>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S250>/Trigonometric Function3' incorporates:
         *  Gain: '<S249>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S250>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S250>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S250>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S239>/Index Vector' incorporates:
         *  Constant: '<S248>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S239>/Multiply'
         *  Product: '<S246>/Multiply'
         *  Product: '<S247>/Multiply3'
         *  RelationalOperator: '<S248>/Compare'
         *  S-Function (sfix_bitop): '<S245>/ax_cmd valid'
         *  S-Function (sfix_bitop): '<S245>/ay_cmd valid'
         *  S-Function (sfix_bitop): '<S245>/az_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S248>/Constant'
           *  RelationalOperator: '<S248>/Compare'
           *  S-Function (sfix_bitop): '<S245>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S245>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S245>/az_cmd valid'
           */
          rtb_Switch2_i = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_lr_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_i);
          }
          break;

         case 1:
          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S248>/Constant'
           *  RelationalOperator: '<S248>/Compare'
           *  S-Function (sfix_bitop): '<S245>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S245>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S245>/az_cmd valid'
           */
          rtb_Switch2_i = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_lr_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_i);
          }
          break;

         case 2:
          /* SignalConversion: '<S252>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S252>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S251>/Gain' incorporates:
           *  DataStoreRead: '<S247>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S247>/Subtract'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S252>/Trigonometric Function3' incorporates:
           *  Gain: '<S251>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S252>/Gain' incorporates:
           *  Gain: '<S251>/Gain'
           *  Trigonometry: '<S252>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S252>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S252>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S252>/Trigonometric Function' incorporates:
           *  Gain: '<S251>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S252>/Trigonometric Function1' incorporates:
           *  Gain: '<S251>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* SignalConversion: '<S252>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S248>/Constant'
           *  RelationalOperator: '<S248>/Compare'
           *  S-Function (sfix_bitop): '<S245>/ax_cmd valid'
           */
          rtb_Switch2_i = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S252>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S248>/Constant'
           *  RelationalOperator: '<S248>/Compare'
           *  S-Function (sfix_bitop): '<S245>/ay_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S252>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S239>/Multiply' incorporates:
           *  Constant: '<S248>/Constant'
           *  RelationalOperator: '<S248>/Compare'
           *  S-Function (sfix_bitop): '<S245>/az_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_lr_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_i);
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

        /* End of MultiPortSwitch: '<S239>/Index Vector' */

        /* Sum: '<S300>/Sum1' incorporates:
         *  Constant: '<S300>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S300>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Divide_lr_idx_0 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S301>/Abs' */
        rtb_Saturation_n = fabsf(rtb_Divide_lr_idx_0);

        /* Switch: '<S301>/Switch' incorporates:
         *  Constant: '<S301>/Constant'
         *  Constant: '<S302>/Constant'
         *  Product: '<S301>/Multiply'
         *  RelationalOperator: '<S302>/Compare'
         *  Sum: '<S301>/Subtract'
         */
        if (rtb_Saturation_n > 3.14159274F) {
          /* Signum: '<S301>/Sign' */
          if (rtb_Divide_lr_idx_0 < 0.0F) {
            rtb_Divide_lr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_0 > 0.0F) {
              rtb_Divide_lr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S301>/Sign' */
          rtb_Divide_lr_idx_0 *= rtb_Saturation_n - 6.28318548F;
        }

        /* End of Switch: '<S301>/Switch' */

        /* Saturate: '<S300>/Saturation' */
        if (rtb_Divide_lr_idx_0 > 0.314159274F) {
          rtb_Divide_lr_idx_0 = 0.314159274F;
        } else {
          if (rtb_Divide_lr_idx_0 < -0.314159274F) {
            rtb_Divide_lr_idx_0 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S300>/Saturation' */

        /* Gain: '<S297>/Gain2' */
        rtb_Divide_lr_idx_0 *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S241>/Sum' incorporates:
         *  Constant: '<S299>/Constant'
         *  Constant: '<S303>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S297>/Multiply2'
         *  Product: '<S298>/Multiply1'
         *  RelationalOperator: '<S299>/Compare'
         *  RelationalOperator: '<S303>/Compare'
         *  S-Function (sfix_bitop): '<S297>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S298>/psi_rate_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        rtb_Add4_d = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Divide_lr_idx_0
                      : 0.0F) + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
          FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S304>/Gain1' */
        rtb_Saturation_n = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_a_l = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S304>/Gain2' */
        rtb_Divide_lr_idx_0 = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S346>/Trigonometric Function1' incorporates:
         *  Gain: '<S345>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S346>/Trigonometric Function' incorporates:
         *  Gain: '<S345>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S346>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S346>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S346>/Gain' incorporates:
         *  Gain: '<S345>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Trigonometry: '<S346>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S346>/Trigonometric Function3' incorporates:
         *  Gain: '<S345>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S346>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S346>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S346>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S305>/Index Vector' incorporates:
         *  Constant: '<S344>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S305>/Multiply'
         *  Product: '<S341>/Multiply'
         *  Product: '<S342>/Multiply3'
         *  RelationalOperator: '<S344>/Compare'
         *  S-Function (sfix_bitop): '<S340>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S340>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S340>/w_cmd valid'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S305>/Multiply' incorporates:
           *  Constant: '<S344>/Constant'
           *  RelationalOperator: '<S344>/Compare'
           *  S-Function (sfix_bitop): '<S340>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S340>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S340>/w_cmd valid'
           */
          rtb_Switch2_i = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_lr_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_i);
          }
          break;

         case 1:
          /* Product: '<S305>/Multiply' incorporates:
           *  Constant: '<S344>/Constant'
           *  RelationalOperator: '<S344>/Compare'
           *  S-Function (sfix_bitop): '<S340>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S340>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S340>/w_cmd valid'
           */
          rtb_Switch2_i = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_lr_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_i);
          }
          break;

         case 2:
          /* SignalConversion: '<S348>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S348>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S347>/Gain' incorporates:
           *  DataStoreRead: '<S342>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S342>/Subtract'
           */
          rtb_Switch2_i = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S348>/Trigonometric Function3' incorporates:
           *  Gain: '<S347>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Switch2_i);

          /* Gain: '<S348>/Gain' incorporates:
           *  Gain: '<S347>/Gain'
           *  Trigonometry: '<S348>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Switch2_i);

          /* SignalConversion: '<S348>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S348>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S348>/Trigonometric Function' incorporates:
           *  Gain: '<S347>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Switch2_i);

          /* Trigonometry: '<S348>/Trigonometric Function1' incorporates:
           *  Gain: '<S347>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Switch2_i);

          /* SignalConversion: '<S348>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S305>/Multiply' incorporates:
           *  Constant: '<S344>/Constant'
           *  RelationalOperator: '<S344>/Compare'
           *  S-Function (sfix_bitop): '<S340>/u_cmd valid'
           */
          rtb_Switch2_i = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S348>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S305>/Multiply' incorporates:
           *  Constant: '<S344>/Constant'
           *  RelationalOperator: '<S344>/Compare'
           *  S-Function (sfix_bitop): '<S340>/v_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S348>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S305>/Multiply' incorporates:
           *  Constant: '<S344>/Constant'
           *  RelationalOperator: '<S344>/Compare'
           *  S-Function (sfix_bitop): '<S340>/w_cmd valid'
           */
          rtb_Divide_lr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_lr_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Switch2_i);
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

        /* End of MultiPortSwitch: '<S305>/Index Vector' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Saturation_n;
        rtb_MatrixConcatenate3[1] += rtb_a_l;

        /* Sum: '<S242>/Sum1' */
        rtb_Saturation_n = rtb_Divide_lr_idx_0 + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S260>/Switch' incorporates:
         *  Constant: '<S275>/Constant'
         *  Constant: '<S277>/Constant'
         *  Constant: '<S278>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S275>/Compare'
         *  RelationalOperator: '<S277>/Compare'
         *  RelationalOperator: '<S278>/Compare'
         *  S-Function (sfix_bitop): '<S260>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S260>/y_v_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S260>/Logical Operator' incorporates:
           *  Constant: '<S276>/Constant'
           *  Constant: '<S277>/Constant'
           *  Constant: '<S278>/Constant'
           *  RelationalOperator: '<S276>/Compare'
           *  RelationalOperator: '<S277>/Compare'
           *  RelationalOperator: '<S278>/Compare'
           *  S-Function (sfix_bitop): '<S260>/lat_lon_cmd valid'
           *  S-Function (sfix_bitop): '<S260>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S260>/y_v_cmd'
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

        /* End of Switch: '<S260>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S240>/u_cmd_valid' */
        /* MATLAB Function: '<S272>/bit_shift' incorporates:
         *  DataTypeConversion: '<S240>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_a4 << 6);

        /* End of Outputs for SubSystem: '<S240>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S240>/v_cmd_valid' */
        /* MATLAB Function: '<S273>/bit_shift' incorporates:
         *  DataTypeConversion: '<S240>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S240>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S261>/Switch' incorporates:
         *  Constant: '<S280>/Constant'
         *  Constant: '<S281>/Constant'
         *  Constant: '<S283>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S280>/Compare'
         *  RelationalOperator: '<S281>/Compare'
         *  RelationalOperator: '<S283>/Compare'
         *  S-Function (sfix_bitop): '<S261>/ax_cmd'
         *  S-Function (sfix_bitop): '<S261>/ay_cmd'
         *  SignalConversion: '<S31>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S261>/Logical Operator' incorporates:
           *  Constant: '<S281>/Constant'
           *  Constant: '<S283>/Constant'
           *  RelationalOperator: '<S281>/Compare'
           *  RelationalOperator: '<S283>/Compare'
           *  S-Function (sfix_bitop): '<S261>/ax_cmd'
           *  S-Function (sfix_bitop): '<S261>/ay_cmd'
           */
          rtb_LogicalOperator_a4 = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_a4;
        } else {
          rtb_LogicalOperator_a4 = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S261>/Switch' */
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

        /* Saturate: '<S241>/Saturation' */
        if (rtb_Add4_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Add4_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S151>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Add4_d;
        }

        /* End of Saturate: '<S241>/Saturation' */

        /* Saturate: '<S242>/Saturation2' */
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

        /* End of Saturate: '<S242>/Saturation2' */

        /* Saturate: '<S242>/Saturation1' */
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

        /* End of Saturate: '<S242>/Saturation1' */

        /* Saturate: '<S242>/Saturation3' */
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
        /* BusAssignment: '<S151>/Bus Assignment' incorporates:
         *  Constant: '<S253>/Constant'
         *  Constant: '<S254>/Constant'
         *  Constant: '<S255>/Constant'
         *  Constant: '<S256>/Constant'
         *  Constant: '<S257>/Constant'
         *  Constant: '<S258>/Constant'
         *  Constant: '<S259>/Constant'
         *  Constant: '<S279>/Constant'
         *  Constant: '<S282>/Constant'
         *  DataTypeConversion: '<S240>/Data Type Conversion10'
         *  DataTypeConversion: '<S240>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S262>/bit_shift'
         *  MATLAB Function: '<S263>/bit_shift'
         *  MATLAB Function: '<S264>/bit_shift'
         *  MATLAB Function: '<S266>/bit_shift'
         *  MATLAB Function: '<S267>/bit_shift'
         *  MATLAB Function: '<S268>/bit_shift'
         *  MATLAB Function: '<S269>/bit_shift'
         *  MATLAB Function: '<S270>/bit_shift'
         *  MATLAB Function: '<S271>/bit_shift'
         *  MATLAB Function: '<S274>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S253>/Compare'
         *  RelationalOperator: '<S254>/Compare'
         *  RelationalOperator: '<S255>/Compare'
         *  RelationalOperator: '<S256>/Compare'
         *  RelationalOperator: '<S257>/Compare'
         *  RelationalOperator: '<S258>/Compare'
         *  RelationalOperator: '<S259>/Compare'
         *  RelationalOperator: '<S279>/Compare'
         *  RelationalOperator: '<S282>/Compare'
         *  S-Function (sfix_bitop): '<S240>/p_cmd'
         *  S-Function (sfix_bitop): '<S240>/phi_cmd'
         *  S-Function (sfix_bitop): '<S240>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S240>/q_cmd'
         *  S-Function (sfix_bitop): '<S240>/r_cmd'
         *  S-Function (sfix_bitop): '<S240>/theta_cmd'
         *  S-Function (sfix_bitop): '<S240>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S260>/alt_z_w_cmd'
         *  S-Function (sfix_bitop): '<S261>/az_cmd'
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
          (rtb_LogicalOperator_a4 << 9)) + (rtb_FixPtRelationalOperator_me << 10))
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
           *  Delay: '<S180>/Delay1'
           *  DiscreteIntegrator: '<S161>/Integrator'
           *  DiscreteIntegrator: '<S161>/Integrator1'
           *  DiscreteIntegrator: '<S176>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator'
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

          /* InitializeConditions for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for Delay: '<S180>/Delay1' */
          FMS_DW.Delay1_DSTATE = false;

          /* InitializeConditions for Delay: '<S180>/Delay' */
          FMS_DW.icLoad_h = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S176>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S230>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

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

        /* DiscreteIntegrator: '<S181>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S153>/Delay Input1'
         *
         * Block description for '<S153>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S175>/Compare' incorporates:
         *  Constant: '<S238>/Constant'
         *  RelationalOperator: '<S238>/Compare'
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
        /* RelationalOperator: '<S185>/Compare' incorporates:
         *  Constant: '<S185>/Constant'
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
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_c[0];

        /* Sum: '<S176>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add4_d = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* Sum: '<S180>/Sum' incorporates:
         *  Delay: '<S180>/Delay'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Integrator1_a = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_c
          [1];

        /* Sum: '<S176>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint
          [1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S188>/Sqrt' incorporates:
         *  Math: '<S188>/Square'
         *  Sum: '<S176>/Sum'
         *  Sum: '<S188>/Sum of Elements'
         */
        rtb_Divide_lr_idx_0 = sqrtf(rtb_Add4_d * rtb_Add4_d +
          rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0);

        /* Switch: '<S176>/Switch' */
        if (rtb_Divide_lr_idx_0 > FMS_PARAM.L1) {
          rtb_Add4_d = rtb_a_l;
        } else {
          /* Gain: '<S176>/Gain' */
          rtb_Add4_d = 0.5F * rtb_Divide_lr_idx_0;

          /* Switch: '<S186>/Switch2' incorporates:
           *  Constant: '<S176>/Constant1'
           *  RelationalOperator: '<S186>/LowerRelop1'
           *  RelationalOperator: '<S186>/UpperRelop'
           *  Switch: '<S186>/Switch'
           */
          if (rtb_Add4_d > rtb_a_l) {
            rtb_Add4_d = rtb_a_l;
          } else {
            if (rtb_Add4_d < 0.5F) {
              /* Switch: '<S186>/Switch' incorporates:
               *  Constant: '<S176>/Constant1'
               */
              rtb_Add4_d = 0.5F;
            }
          }

          /* End of Switch: '<S186>/Switch2' */
        }

        /* End of Switch: '<S176>/Switch' */

        /* DiscreteIntegrator: '<S176>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Switch: '<S187>/Switch2' incorporates:
         *  Constant: '<S176>/Constant2'
         *  DiscreteIntegrator: '<S176>/Acceleration_Speed'
         *  RelationalOperator: '<S187>/LowerRelop1'
         *  RelationalOperator: '<S187>/UpperRelop'
         *  Switch: '<S187>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE > rtb_a_l) {
          rtb_Switch2_i = rtb_a_l;
        } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
          /* Switch: '<S187>/Switch' incorporates:
           *  Constant: '<S176>/Constant2'
           */
          rtb_Switch2_i = 0.0F;
        } else {
          rtb_Switch2_i = FMS_DW.Acceleration_Speed_DSTATE;
        }

        /* End of Switch: '<S187>/Switch2' */

        /* Switch: '<S176>/Switch1' incorporates:
         *  Sum: '<S176>/Sum1'
         */
        if (rtb_Switch2_i - rtb_Add4_d >= 0.0F) {
          rtb_Switch2_i = rtb_Add4_d;
        }

        /* End of Switch: '<S176>/Switch1' */

        /* DiscreteIntegrator: '<S230>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRese !=
             0)) {
          FMS_DW.l1_heading = 0.0F;
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
          /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S237>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S236>/Gain' incorporates:
           *  DiscreteIntegrator: '<S230>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  Sum: '<S230>/Add'
           */
          rtb_MathFunction_p_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S237>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_MathFunction_p_idx_1);

          /* Gain: '<S237>/Gain' incorporates:
           *  Trigonometry: '<S237>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_MathFunction_p_idx_1);

          /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S237>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S237>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_MathFunction_p_idx_1);

          /* Trigonometry: '<S237>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_MathFunction_p_idx_1);

          /* SignalConversion: '<S237>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_d[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_d[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_d[2];

          /* Sum: '<S232>/Sum of Elements' incorporates:
           *  Math: '<S232>/Math Function'
           *  SignalConversion: '<S232>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_0 = rtb_Saturation_n * rtb_Saturation_n +
            rtb_Integrator1_a * rtb_Integrator1_a;

          /* Math: '<S232>/Math Function1' incorporates:
           *  Sum: '<S232>/Sum of Elements'
           *
           * About '<S232>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_0 < 0.0F) {
            rtb_MathFunction_p_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
          } else {
            rtb_MathFunction_p_idx_1 = sqrtf(rtb_Divide_lr_idx_0);
          }

          /* End of Math: '<S232>/Math Function1' */

          /* Switch: '<S232>/Switch' incorporates:
           *  Constant: '<S232>/Constant'
           *  Product: '<S232>/Product'
           */
          if (rtb_MathFunction_p_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_0 = rtb_Saturation_n;
            rtb_Divide_lr_idx_1 = rtb_Integrator1_a;
          } else {
            rtb_Divide_lr_idx_0 = 0.0F;
            rtb_Divide_lr_idx_1 = 0.0F;
            rtb_MathFunction_p_idx_1 = 1.0F;
          }

          /* End of Switch: '<S232>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S182>/Sum1' incorporates:
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_f_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S182>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S31>/Signal Copy1'
           *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_f_idx_2 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

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
          rtb_Add4_d = sqrtf(rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_1
                             + rtb_MathFunction_f_idx_2 *
                             rtb_MathFunction_f_idx_2) / sqrtf(rtb_Add4_d *
            rtb_Add4_d + rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0);

          /* Saturate: '<S182>/Saturation' */
          if (rtb_Add4_d > 1.0F) {
            rtb_Add4_d = 1.0F;
          } else {
            if (rtb_Add4_d < 0.0F) {
              rtb_Add4_d = 0.0F;
            }
          }

          /* End of Saturate: '<S182>/Saturation' */

          /* Product: '<S228>/Multiply2' incorporates:
           *  Product: '<S232>/Divide'
           */
          rtb_Divide_lr_idx_0 = rtb_Divide_lr_idx_0 / rtb_MathFunction_p_idx_1 *
            rtb_Switch2_i;
          rtb_Divide_lr_idx_1 = rtb_Divide_lr_idx_1 / rtb_MathFunction_p_idx_1 *
            rtb_Switch2_i;

          /* Product: '<S180>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Divide_lr_idx_1 + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Divide_lr_idx_0;
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
          rtb_Add4_d = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Add4_d +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S173>/Saturation1' incorporates:
           *  Product: '<S180>/Multiply'
           */
          if (rtb_Add4_d > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Add4_d < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Add4_d;
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
        rtb_Add4_d = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi,
                             6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S165>/Switch' incorporates:
         *  Abs: '<S165>/Abs'
         *  Constant: '<S165>/Constant'
         *  Constant: '<S166>/Constant'
         *  Product: '<S165>/Multiply'
         *  RelationalOperator: '<S166>/Compare'
         *  Sum: '<S165>/Add'
         */
        if (fabsf(rtb_Add4_d) > 3.14159274F) {
          /* Signum: '<S165>/Sign' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Divide_lr_idx_0 = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_Divide_lr_idx_0 = 1.0F;
          } else {
            rtb_Divide_lr_idx_0 = rtb_Add4_d;
          }

          /* End of Signum: '<S165>/Sign' */
          rtb_Add4_d -= 6.28318548F * rtb_Divide_lr_idx_0;
        }

        /* End of Switch: '<S165>/Switch' */

        /* Gain: '<S160>/Gain2' */
        rtb_Add4_d *= FMS_PARAM.YAW_P;

        /* Saturate: '<S160>/Saturation' */
        if (rtb_Add4_d > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Add4_d = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Add4_d < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Add4_d = -FMS_PARAM.YAW_RATE_LIM;
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
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Add4_d;

        /* Sum: '<S234>/Sum of Elements' incorporates:
         *  Math: '<S234>/Math Function'
         *  SignalConversion: '<S234>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_0 = rtb_Integrator1_a * rtb_Integrator1_a +
          rtb_Saturation_n * rtb_Saturation_n;

        /* Math: '<S234>/Math Function1' incorporates:
         *  Sum: '<S234>/Sum of Elements'
         *
         * About '<S234>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Add4_d = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
        } else {
          rtb_Add4_d = sqrtf(rtb_Divide_lr_idx_0);
        }

        /* End of Math: '<S234>/Math Function1' */

        /* Switch: '<S234>/Switch' incorporates:
         *  Constant: '<S234>/Constant'
         *  Product: '<S234>/Product'
         */
        if (rtb_Add4_d > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Integrator1_a;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Saturation_n;
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Add4_d;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S234>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S222>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S222>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Divide_lr_idx_0 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S222>/Math Function1' incorporates:
         *  Sum: '<S222>/Sum of Elements'
         *
         * About '<S222>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Add4_d = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
        } else {
          rtb_Add4_d = sqrtf(rtb_Divide_lr_idx_0);
        }

        /* End of Math: '<S222>/Math Function1' */

        /* Switch: '<S222>/Switch' incorporates:
         *  Constant: '<S222>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S222>/Product'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        if (rtb_Add4_d > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_2 = rtb_Add4_d;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S222>/Switch' */

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
        rtb_Divide_lr_idx_0 = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 +
          rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1;

        /* Math: '<S172>/Math Function1' incorporates:
         *  Sum: '<S172>/Sum of Elements'
         *
         * About '<S172>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Add4_d = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
        } else {
          rtb_Add4_d = sqrtf(rtb_Divide_lr_idx_0);
        }

        /* End of Math: '<S172>/Math Function1' */

        /* Switch: '<S172>/Switch' incorporates:
         *  Constant: '<S172>/Constant'
         *  Product: '<S172>/Product'
         */
        if (rtb_Add4_d > 0.0F) {
          rtb_Switch_mp_idx_2 = rtb_Add4_d;
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
        rtb_Sum_ff[0] = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Switch_f3_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;
        rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S235>/Sum of Elements' incorporates:
         *  Math: '<S235>/Math Function'
         *  Sum: '<S180>/Sum1'
         */
        rtb_Divide_lr_idx_0 = rtb_Switch_f3_idx_0 * rtb_Switch_f3_idx_0 +
          rtb_Switch_f3_idx_1 * rtb_Switch_f3_idx_1;

        /* Math: '<S235>/Math Function1' incorporates:
         *  Sum: '<S235>/Sum of Elements'
         *
         * About '<S235>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Add4_d = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
        } else {
          rtb_Add4_d = sqrtf(rtb_Divide_lr_idx_0);
        }

        /* End of Math: '<S235>/Math Function1' */

        /* Switch: '<S235>/Switch' incorporates:
         *  Constant: '<S235>/Constant'
         *  Product: '<S235>/Product'
         */
        if (rtb_Add4_d > 0.0F) {
          rtb_Switch_f3_idx_2 = rtb_Add4_d;
        } else {
          rtb_Switch_f3_idx_0 = 0.0F;
          rtb_Switch_f3_idx_1 = 0.0F;
          rtb_Switch_f3_idx_2 = 1.0F;
        }

        /* End of Switch: '<S235>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S178>/NearbyRefWP' incorporates:
         *  Constant: '<S154>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_ff,
                        &rtb_Divide_lr_idx_0);

        /* MATLAB Function: '<S178>/SearchL1RefWP' incorporates:
         *  Constant: '<S154>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  SignalConversion: '<S31>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Add4_d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Add4_d = rtb_Saturation_n * rtb_Saturation_n + rtb_Add4_d *
          rtb_Add4_d;

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
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Add4_d);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Saturation_n = -1.0F;
        rtb_Divide_lr_idx_1 = 0.0F;
        rtb_MathFunction_p_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          rtb_MathFunction_h_idx_1 = sqrtf(D);
          D = (-B + rtb_MathFunction_h_idx_1) / (2.0F * rtb_Add4_d);
          rtb_Add4_d = (-B - rtb_MathFunction_h_idx_1) / (2.0F * rtb_Add4_d);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Add4_d >= 0.0F) && (rtb_Add4_d <=
               1.0F)) {
            rtb_Saturation_n = fmaxf(D, rtb_Add4_d);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Saturation_n = D;
            guard1 = true;
          } else {
            if ((rtb_Add4_d >= 0.0F) && (rtb_Add4_d <= 1.0F)) {
              rtb_Saturation_n = rtb_Add4_d;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Add4_d);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Saturation_n = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Divide_lr_idx_1 = (FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Saturation_n +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_p_idx_1 = (FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Saturation_n +
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
        rtb_Integrator1_a = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Add4_d = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                      rtb_Integrator1_a + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_P_l_idx_0) / (rtb_P_l_idx_0 *
          rtb_P_l_idx_0 + rtb_Integrator1_a * rtb_Integrator1_a);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Add4_d <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Add4_d >= 1.0F);
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
          rtb_P_l_idx_0 = rtb_Add4_d * rtb_P_l_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Switch: '<S178>/Switch1' incorporates:
         *  Constant: '<S215>/Constant'
         *  RelationalOperator: '<S215>/Compare'
         */
        if (rtb_Divide_lr_idx_0 <= 0.0F) {
          /* Switch: '<S178>/Switch' incorporates:
           *  Constant: '<S214>/Constant'
           *  MATLAB Function: '<S178>/SearchL1RefWP'
           *  RelationalOperator: '<S214>/Compare'
           */
          if (rtb_Saturation_n >= 0.0F) {
            rtb_Sum_ff[0] = rtb_Divide_lr_idx_1;
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
              rtb_Sum_ff[1] = rtb_Add4_d * rtb_Integrator1_a +
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
        rtb_Integrator1_a = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Integrator1_a * rtb_Integrator1_a;
        rtb_Saturation_n = rtb_Integrator1_a;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S179>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S223>/Math Function'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Integrator1_a = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S223>/Math Function' incorporates:
         *  Math: '<S221>/Square'
         */
        rtb_Divide_lr_idx_0 = rtb_Integrator1_a * rtb_Integrator1_a;

        /* Sum: '<S223>/Sum of Elements' incorporates:
         *  Math: '<S223>/Math Function'
         */
        D = rtb_Divide_lr_idx_0 + rtb_Sum_ff[0];

        /* Math: '<S223>/Math Function1' incorporates:
         *  Sum: '<S223>/Sum of Elements'
         *
         * About '<S223>/Math Function1':
         *  Operator: sqrt
         */
        if (D < 0.0F) {
          rtb_Add4_d = -sqrtf(fabsf(D));
        } else {
          rtb_Add4_d = sqrtf(D);
        }

        /* End of Math: '<S223>/Math Function1' */

        /* Switch: '<S223>/Switch' incorporates:
         *  Constant: '<S223>/Constant'
         *  Product: '<S223>/Product'
         */
        if (rtb_Add4_d > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Saturation_n;
          rtb_MatrixConcatenate3[1] = rtb_Integrator1_a;
          rtb_MatrixConcatenate3[2] = rtb_Add4_d;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S223>/Switch' */

        /* Product: '<S222>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MathFunction_f_idx_0 /
          rtb_MathFunction_f_idx_2;
        rtb_MathFunction_h_idx_1 = rtb_MathFunction_f_idx_1 /
          rtb_MathFunction_f_idx_2;

        /* Sum: '<S225>/Sum of Elements' incorporates:
         *  Math: '<S225>/Math Function'
         *  SignalConversion: '<S225>/TmpSignal ConversionAtMath FunctionInport1'
         */
        D = rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 +
          rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Math: '<S225>/Math Function1' incorporates:
         *  Sum: '<S225>/Sum of Elements'
         *
         * About '<S225>/Math Function1':
         *  Operator: sqrt
         */
        if (D < 0.0F) {
          rtb_Add4_d = -sqrtf(fabsf(D));
        } else {
          rtb_Add4_d = sqrtf(D);
        }

        /* End of Math: '<S225>/Math Function1' */

        /* Switch: '<S225>/Switch' incorporates:
         *  Constant: '<S225>/Constant'
         *  Product: '<S225>/Product'
         */
        if (rtb_Add4_d > 0.0F) {
          rtb_MathFunction_f_idx_0 = rtb_MathFunction_h_idx_1;
          rtb_MathFunction_f_idx_1 = rtb_MathFunction_h_idx_0;
          rtb_MathFunction_f_idx_2 = rtb_Add4_d;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S225>/Switch' */

        /* Product: '<S223>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S226>/Sum of Elements' incorporates:
         *  Math: '<S226>/Math Function'
         *  SignalConversion: '<S226>/TmpSignal ConversionAtMath FunctionInport1'
         */
        D = rtb_MathFunction_h_idx_1 * rtb_MathFunction_h_idx_1 +
          rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Math: '<S226>/Math Function1' incorporates:
         *  Sum: '<S226>/Sum of Elements'
         *
         * About '<S226>/Math Function1':
         *  Operator: sqrt
         */
        if (D < 0.0F) {
          rtb_Add4_d = -sqrtf(fabsf(D));
        } else {
          rtb_Add4_d = sqrtf(D);
        }

        /* End of Math: '<S226>/Math Function1' */

        /* Switch: '<S226>/Switch' incorporates:
         *  Constant: '<S226>/Constant'
         *  Product: '<S226>/Product'
         */
        if (rtb_Add4_d > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_MathFunction_h_idx_1;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_h_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Add4_d;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S226>/Switch' */

        /* Product: '<S226>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S225>/Divide' */
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;

        /* Product: '<S235>/Divide' */
        rtb_Divide_lr_idx_1 = rtb_Switch_f3_idx_0 / rtb_Switch_f3_idx_2;

        /* Product: '<S172>/Divide' */
        rtb_P_l_idx_0 = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S234>/Divide' */
        rtb_Switch_mp_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Saturation_n *= rtb_Saturation_n;

        /* Product: '<S226>/Divide' incorporates:
         *  Math: '<S221>/Square'
         */
        rtb_MathFunction_h_idx_1 = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S225>/Divide' */
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S235>/Divide' */
        rtb_MathFunction_p_idx_1 = rtb_Switch_f3_idx_1 / rtb_Switch_f3_idx_2;

        /* Product: '<S172>/Divide' */
        rtb_MathFunction_f_idx_0 = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S234>/Divide' */
        rtb_MathFunction_f_idx_1 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S233>/Subtract' incorporates:
         *  Product: '<S233>/Multiply'
         *  Product: '<S233>/Multiply1'
         */
        rtb_Add4_d = rtb_Divide_lr_idx_1 * rtb_MathFunction_f_idx_1 -
          rtb_MathFunction_p_idx_1 * rtb_Switch_mp_idx_0;

        /* Signum: '<S229>/Sign1' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S229>/Sign1' */

        /* Switch: '<S229>/Switch2' incorporates:
         *  Constant: '<S229>/Constant4'
         */
        if (rtb_Add4_d == 0.0F) {
          rtb_Add4_d = 1.0F;
        }

        /* End of Switch: '<S229>/Switch2' */

        /* DotProduct: '<S229>/Dot Product' */
        rtb_MathFunction_f_idx_1 = rtb_Switch_mp_idx_0 * rtb_Divide_lr_idx_1 +
          rtb_MathFunction_f_idx_1 * rtb_MathFunction_p_idx_1;

        /* Trigonometry: '<S229>/Acos' incorporates:
         *  DotProduct: '<S229>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_1 > 1.0F) {
          rtb_MathFunction_f_idx_1 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_1 < -1.0F) {
            rtb_MathFunction_f_idx_1 = -1.0F;
          }
        }

        /* Product: '<S229>/Multiply' incorporates:
         *  Trigonometry: '<S229>/Acos'
         */
        rtb_Add4_d *= acosf(rtb_MathFunction_f_idx_1);

        /* Abs: '<S180>/Abs' */
        rtb_Add4_d = fabsf(rtb_Add4_d);

        /* RelationalOperator: '<S227>/Compare' incorporates:
         *  Constant: '<S227>/Constant'
         *  Delay: '<S180>/Delay1'
         */
        FMS_DW.Delay1_DSTATE = (rtb_Add4_d > 1.57079637F);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sqrt: '<S220>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S220>/Square'
         *  SignalConversion: '<S31>/Signal Copy1'
         *  Sum: '<S220>/Sum of Elements'
         */
        rtb_Integrator1_a = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S179>/Square' */
        rtb_Divide_lr_idx_1 = rtb_Integrator1_a * rtb_Integrator1_a;

        /* Sum: '<S224>/Subtract' incorporates:
         *  Product: '<S224>/Multiply'
         *  Product: '<S224>/Multiply1'
         */
        rtb_Integrator1_a = rtb_MathFunction_h_idx_0 * rtb_Sum_ff[1] -
          rtb_MathFunction_h_idx_1 * rtb_Sum_ff[0];

        /* Signum: '<S219>/Sign1' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S219>/Sign1' */

        /* Switch: '<S219>/Switch2' incorporates:
         *  Constant: '<S219>/Constant4'
         */
        if (rtb_Integrator1_a == 0.0F) {
          rtb_Integrator1_a = 1.0F;
        }

        /* End of Switch: '<S219>/Switch2' */

        /* DotProduct: '<S219>/Dot Product' */
        rtb_Add4_d = rtb_Sum_ff[0] * rtb_MathFunction_h_idx_0 + rtb_Sum_ff[1] *
          rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S219>/Acos' incorporates:
         *  DotProduct: '<S219>/Dot Product'
         */
        if (rtb_Add4_d > 1.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          if (rtb_Add4_d < -1.0F) {
            rtb_Add4_d = -1.0F;
          }
        }

        /* Product: '<S219>/Multiply' incorporates:
         *  Trigonometry: '<S219>/Acos'
         */
        rtb_Integrator1_a *= acosf(rtb_Add4_d);

        /* Saturate: '<S179>/Saturation' */
        if (rtb_Integrator1_a > 1.57079637F) {
          rtb_Integrator1_a = 1.57079637F;
        } else {
          if (rtb_Integrator1_a < -1.57079637F) {
            rtb_Integrator1_a = -1.57079637F;
          }
        }

        /* End of Saturate: '<S179>/Saturation' */

        /* Switch: '<S231>/Switch2' incorporates:
         *  Constant: '<S180>/Constant1'
         *  RelationalOperator: '<S231>/LowerRelop1'
         *  RelationalOperator: '<S231>/UpperRelop'
         *  Switch: '<S231>/Switch'
         */
        if (rtb_Switch2_i > rtb_a_l) {
          rtb_Switch2_i = rtb_a_l;
        } else {
          if (rtb_Switch2_i < 0.5F) {
            /* Switch: '<S231>/Switch' incorporates:
             *  Constant: '<S180>/Constant1'
             */
            rtb_Switch2_i = 0.5F;
          }
        }

        /* End of Switch: '<S231>/Switch2' */

        /* Product: '<S180>/Divide1' incorporates:
         *  Constant: '<S154>/L1'
         *  Constant: '<S179>/Constant'
         *  Gain: '<S179>/Gain'
         *  MinMax: '<S179>/Max'
         *  MinMax: '<S179>/Min'
         *  Product: '<S179>/Divide'
         *  Product: '<S179>/Multiply1'
         *  Sqrt: '<S221>/Sqrt'
         *  Sum: '<S221>/Sum of Elements'
         *  Trigonometry: '<S179>/Sin'
         */
        rtb_Integrator1_a = 2.0F * rtb_Divide_lr_idx_1 * arm_sin_f32
          (rtb_Integrator1_a) / fminf(FMS_PARAM.L1, fmaxf(sqrtf
          (rtb_Divide_lr_idx_0 + rtb_Saturation_n), 0.5F)) / rtb_Switch2_i;

        /* Saturate: '<S180>/Saturation' */
        if (rtb_Integrator1_a > 0.314159274F) {
          rtb_a_l = 0.314159274F;
        } else if (rtb_Integrator1_a < -0.314159274F) {
          rtb_a_l = -0.314159274F;
        } else {
          rtb_a_l = rtb_Integrator1_a;
        }

        /* End of Saturate: '<S180>/Saturation' */

        /* Sum: '<S170>/Subtract' incorporates:
         *  Product: '<S170>/Multiply'
         *  Product: '<S170>/Multiply1'
         */
        rtb_Integrator1_a = rtb_P_l_idx_0 * FMS_ConstB.Divide[1] -
          rtb_MathFunction_f_idx_0 * FMS_ConstB.Divide[0];

        /* Signum: '<S159>/Sign1' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S159>/Sign1' */

        /* Switch: '<S159>/Switch2' incorporates:
         *  Constant: '<S159>/Constant4'
         */
        if (rtb_Integrator1_a == 0.0F) {
          rtb_Integrator1_a = 1.0F;
        }

        /* End of Switch: '<S159>/Switch2' */

        /* DotProduct: '<S159>/Dot Product' */
        rtb_Add4_d = FMS_ConstB.Divide[0] * rtb_P_l_idx_0 + FMS_ConstB.Divide[1]
          * rtb_MathFunction_f_idx_0;

        /* Trigonometry: '<S159>/Acos' incorporates:
         *  DotProduct: '<S159>/Dot Product'
         */
        if (rtb_Add4_d > 1.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          if (rtb_Add4_d < -1.0F) {
            rtb_Add4_d = -1.0F;
          }
        }

        /* Product: '<S159>/Multiply' incorporates:
         *  Trigonometry: '<S159>/Acos'
         */
        rtb_Integrator1_a *= acosf(rtb_Add4_d);

        /* Math: '<S162>/Rem' incorporates:
         *  Constant: '<S162>/Constant1'
         *  Delay: '<S158>/Delay'
         *  Sum: '<S158>/Sum2'
         */
        rtb_Add4_d = rt_remf(rtb_Integrator1_a - FMS_DW.Delay_DSTATE_h,
                             6.28318548F);

        /* Switch: '<S162>/Switch' incorporates:
         *  Abs: '<S162>/Abs'
         *  Constant: '<S162>/Constant'
         *  Constant: '<S168>/Constant'
         *  Product: '<S162>/Multiply'
         *  RelationalOperator: '<S168>/Compare'
         *  Sum: '<S162>/Add'
         */
        if (fabsf(rtb_Add4_d) > 3.14159274F) {
          /* Signum: '<S162>/Sign' */
          if (rtb_Add4_d < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Add4_d > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Add4_d;
          }

          /* End of Signum: '<S162>/Sign' */
          rtb_Add4_d -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S162>/Switch' */

        /* Sum: '<S158>/Sum' incorporates:
         *  Delay: '<S158>/Delay'
         */
        rtb_Saturation_n = rtb_Add4_d + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S167>/Multiply1' incorporates:
         *  Constant: '<S167>/const1'
         *  DiscreteIntegrator: '<S161>/Integrator'
         */
        rtb_Add4_d = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S167>/Add' incorporates:
         *  DiscreteIntegrator: '<S161>/Integrator1'
         *  Sum: '<S161>/Subtract'
         */
        rtb_Switch2_i = (FMS_DW.Integrator1_DSTATE_p - rtb_Saturation_n) +
          rtb_Add4_d;

        /* Signum: '<S167>/Sign' */
        if (rtb_Switch2_i < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Switch2_i > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Switch2_i;
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
        rtb_Divide_lr_idx_0 = (sqrtf((8.0F * fabsf(rtb_Switch2_i) + FMS_ConstB.d)
          * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Saturation_n + rtb_Add4_d;

        /* Sum: '<S167>/Add4' */
        rtb_Add4_d += rtb_Switch2_i - rtb_Divide_lr_idx_0;

        /* Sum: '<S167>/Add3' */
        rtb_Saturation_n = rtb_Switch2_i + FMS_ConstB.d;

        /* Sum: '<S167>/Subtract1' */
        rtb_Switch2_i -= FMS_ConstB.d;

        /* Signum: '<S167>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S167>/Sign1' */

        /* Signum: '<S167>/Sign2' */
        if (rtb_Switch2_i < 0.0F) {
          rtb_Switch2_i = -1.0F;
        } else {
          if (rtb_Switch2_i > 0.0F) {
            rtb_Switch2_i = 1.0F;
          }
        }

        /* End of Signum: '<S167>/Sign2' */

        /* Sum: '<S167>/Add5' incorporates:
         *  Gain: '<S167>/Gain2'
         *  Product: '<S167>/Multiply4'
         *  Sum: '<S167>/Subtract2'
         */
        rtb_Divide_lr_idx_0 += (rtb_Saturation_n - rtb_Switch2_i) * 0.5F *
          rtb_Add4_d;

        /* Sum: '<S167>/Add6' */
        rtb_Saturation_n = rtb_Divide_lr_idx_0 + FMS_ConstB.d;

        /* Sum: '<S167>/Subtract3' */
        rtb_Add4_d = rtb_Divide_lr_idx_0 - FMS_ConstB.d;

        /* Product: '<S167>/Divide' */
        rtb_Divide_lr_idx_1 = rtb_Divide_lr_idx_0 / FMS_ConstB.d;

        /* Signum: '<S167>/Sign5' incorporates:
         *  Signum: '<S167>/Sign6'
         */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_MathFunction_p_idx_1 = -1.0F;

          /* Signum: '<S167>/Sign6' */
          rtb_Switch2_i = -1.0F;
        } else if (rtb_Divide_lr_idx_0 > 0.0F) {
          rtb_MathFunction_p_idx_1 = 1.0F;

          /* Signum: '<S167>/Sign6' */
          rtb_Switch2_i = 1.0F;
        } else {
          rtb_MathFunction_p_idx_1 = rtb_Divide_lr_idx_0;

          /* Signum: '<S167>/Sign6' */
          rtb_Switch2_i = rtb_Divide_lr_idx_0;
        }

        /* End of Signum: '<S167>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S158>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S31>/Signal Copy1'
         */
        rtb_Integrator1_a -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S163>/Rem' incorporates:
         *  Constant: '<S163>/Constant1'
         */
        rtb_Divide_lr_idx_0 = rt_remf(rtb_Integrator1_a, 6.28318548F);

        /* Switch: '<S163>/Switch' incorporates:
         *  Abs: '<S163>/Abs'
         *  Constant: '<S163>/Constant'
         *  Constant: '<S169>/Constant'
         *  Product: '<S163>/Multiply'
         *  RelationalOperator: '<S169>/Compare'
         *  Sum: '<S163>/Add'
         */
        if (fabsf(rtb_Divide_lr_idx_0) > 3.14159274F) {
          /* Signum: '<S163>/Sign' */
          if (rtb_Divide_lr_idx_0 < 0.0F) {
            rtb_Integrator1_a = -1.0F;
          } else if (rtb_Divide_lr_idx_0 > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          } else {
            rtb_Integrator1_a = rtb_Divide_lr_idx_0;
          }

          /* End of Signum: '<S163>/Sign' */
          rtb_Divide_lr_idx_0 -= 6.28318548F * rtb_Integrator1_a;
        }

        /* End of Switch: '<S163>/Switch' */

        /* Abs: '<S156>/Abs' */
        rtb_Divide_lr_idx_0 = fabsf(rtb_Divide_lr_idx_0);

        /* Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S174>/Constant'
         *  RelationalOperator: '<S174>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)
          (rtb_Divide_lr_idx_0 <= 0.17453292F) +
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */

        /* Update for Delay: '<S180>/Delay' */
        FMS_DW.icLoad_h = 0U;

        /* Update for DiscreteIntegrator: '<S176>/Acceleration_Speed' incorporates:
         *  Constant: '<S176>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S230>/Discrete-Time Integrator' */
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
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S167>/Sign3' */

        /* Signum: '<S167>/Sign4' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
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
        FMS_DW.Integrator_DSTATE_i += ((rtb_Divide_lr_idx_1 -
          rtb_MathFunction_p_idx_1) * FMS_ConstB.Gain4 * ((rtb_Saturation_n -
          rtb_Add4_d) * 0.5F) - rtb_Switch2_i * 1.04719758F) * 0.004F;
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
          rtb_Divide_lr_idx_0 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Divide_lr_idx_0 = 0.0F;
        } else {
          rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
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
          rtb_Divide_lr_idx_0), 65536.0F) + 1000U);

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
          rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Divide_lr_idx_0 = 0.0F;
        } else {
          rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S130>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S130>/Gain' */
        rtb_Saturation_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Divide_lr_idx_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S131>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Divide_lr_idx_0 = 0.0F;
        } else {
          rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S131>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S131>/Gain' */
        rtb_a_l = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Divide_lr_idx_0;

        /* Sum: '<S134>/Sum of Elements' incorporates:
         *  Math: '<S134>/Square'
         *  SignalConversion: '<S134>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S135>/Sum of Elements'
         *  Switch: '<S126>/Switch'
         */
        rtb_Divide_lr_idx_0 = rtb_Saturation_n * rtb_Saturation_n + rtb_a_l *
          rtb_a_l;

        /* Switch: '<S126>/Switch' incorporates:
         *  Constant: '<S129>/Constant'
         *  Product: '<S135>/Divide'
         *  RelationalOperator: '<S129>/Compare'
         *  Sqrt: '<S134>/Sqrt'
         *  Sum: '<S134>/Sum of Elements'
         */
        if (sqrtf(rtb_Divide_lr_idx_0) > 1.0F) {
          /* Math: '<S135>/Math Function1'
           *
           * About '<S135>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_0 < 0.0F) {
            rtb_Divide_lr_idx_0 = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
          } else {
            rtb_Divide_lr_idx_0 = sqrtf(rtb_Divide_lr_idx_0);
          }

          /* End of Math: '<S135>/Math Function1' */

          /* Switch: '<S135>/Switch' incorporates:
           *  Constant: '<S135>/Constant'
           *  Product: '<S135>/Product'
           */
          if (rtb_Divide_lr_idx_0 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Saturation_n;
            rtb_MatrixConcatenate3[1] = rtb_a_l;
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_0;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S135>/Switch' */
          rtb_Saturation_n = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3
            [2];
          rtb_a_l = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
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
        rtb_Integrator1_a = FMS_DW.Integrator_DSTATE_a * 0.04F;

        /* Sum: '<S136>/Add' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion'
         *  DiscreteIntegrator: '<S132>/Integrator1'
         *  Gain: '<S126>/Gain'
         *  Product: '<S126>/Multiply'
         *  Sum: '<S132>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_k -
          FMS_PARAM.ROLL_PITCH_LIM * rtb_Saturation_n * (real32_T)
          rtb_FixPtRelationalOperator_me) + rtb_Integrator1_a;

        /* Saturate: '<S136>/Saturation' incorporates:
         *  Constant: '<S132>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Divide_lr_idx_0 = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Divide_lr_idx_0 = 0.0F;
        } else {
          rtb_Divide_lr_idx_0 = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S136>/Saturation' */

        /* Product: '<S136>/Multiply7' incorporates:
         *  Constant: '<S136>/const'
         */
        rtb_Switch2_i = 31.415926F * rtb_Divide_lr_idx_0;

        /* Product: '<S136>/Multiply' */
        rtb_MathFunction_p_idx_1 = rtb_Switch2_i * FMS_ConstB.Square_c;

        /* Signum: '<S136>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_lr_idx_1;
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
        rtb_Divide_lr_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) +
          rtb_MathFunction_p_idx_1) * rtb_MathFunction_p_idx_1) -
          rtb_MathFunction_p_idx_1) * 0.5F * rtb_Saturation_n +
          rtb_Integrator1_a;

        /* Sum: '<S136>/Add4' */
        rtb_Add4_d = (rtb_Divide_lr_idx_1 - rtb_Divide_lr_idx_0) +
          rtb_Integrator1_a;

        /* Sum: '<S136>/Add3' */
        rtb_Saturation_n = rtb_Divide_lr_idx_1 + rtb_MathFunction_p_idx_1;

        /* Sum: '<S136>/Subtract1' */
        rtb_Divide_lr_idx_1 -= rtb_MathFunction_p_idx_1;

        /* Signum: '<S136>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign1' */

        /* Signum: '<S136>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign2' */

        /* Sum: '<S136>/Add5' incorporates:
         *  Gain: '<S136>/Gain2'
         *  Product: '<S136>/Multiply4'
         *  Sum: '<S136>/Subtract2'
         */
        rtb_Divide_lr_idx_0 += (rtb_Saturation_n - rtb_Divide_lr_idx_1) * 0.5F *
          rtb_Add4_d;

        /* Sum: '<S136>/Add6' */
        rtb_Saturation_n = rtb_Divide_lr_idx_0 + rtb_MathFunction_p_idx_1;

        /* Sum: '<S136>/Subtract3' */
        rtb_Add4_d = rtb_Divide_lr_idx_0 - rtb_MathFunction_p_idx_1;

        /* Signum: '<S136>/Sign5' */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else if (rtb_Divide_lr_idx_0 > 0.0F) {
          rtb_Integrator1_a = 1.0F;
        } else {
          rtb_Integrator1_a = rtb_Divide_lr_idx_0;
        }

        /* End of Signum: '<S136>/Sign5' */

        /* Signum: '<S136>/Sign3' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
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
        rtb_Add4_d = (rtb_Divide_lr_idx_0 / rtb_MathFunction_p_idx_1 -
                      rtb_Integrator1_a) * -rtb_Switch2_i * ((rtb_Saturation_n -
          rtb_Add4_d) * 0.5F);

        /* Signum: '<S136>/Sign6' */
        if (rtb_Divide_lr_idx_0 < 0.0F) {
          rtb_Divide_lr_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_0 > 0.0F) {
            rtb_Divide_lr_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S136>/Sign6' */

        /* Product: '<S136>/Multiply6' */
        rtb_MathFunction_f_idx_0 = rtb_Divide_lr_idx_0 * rtb_Switch2_i;

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
            rtb_Divide_lr_idx_0 = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            /* Saturate: '<S128>/Saturation' */
            rtb_Divide_lr_idx_0 = 0.0F;
          } else {
            /* Saturate: '<S128>/Saturation' incorporates:
             *  Constant: '<S128>/Constant4'
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S31>/Signal Copy2'
             *  Sum: '<S128>/Sum'
             */
            rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          rtb_y_md = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_Divide_lr_idx_0), 65536.0F) + 1000U);
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
        rtb_MathFunction_p_idx_1 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Sum: '<S137>/Add' incorporates:
         *  DataTypeConversion: '<S126>/Data Type Conversion'
         *  DiscreteIntegrator: '<S133>/Integrator1'
         *  Gain: '<S126>/Gain1'
         *  Product: '<S126>/Multiply1'
         *  Sum: '<S133>/Subtract'
         */
        rtb_Switch2_i = (FMS_DW.Integrator1_DSTATE_nf -
                         -FMS_PARAM.ROLL_PITCH_LIM * rtb_a_l * (real32_T)
                         rtb_FixPtRelationalOperator_me) +
          rtb_MathFunction_p_idx_1;

        /* Saturate: '<S137>/Saturation' incorporates:
         *  Constant: '<S133>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Divide_lr_idx_0 = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Divide_lr_idx_0 = 0.0F;
        } else {
          rtb_Divide_lr_idx_0 = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S137>/Saturation' */

        /* Product: '<S137>/Multiply7' incorporates:
         *  Constant: '<S137>/const'
         */
        rtb_Divide_lr_idx_1 = 31.415926F * rtb_Divide_lr_idx_0;

        /* Product: '<S137>/Multiply' */
        rtb_Integrator1_a = rtb_Divide_lr_idx_1 * FMS_ConstB.Square_b;

        /* Signum: '<S137>/Sign' */
        if (rtb_Switch2_i < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Switch2_i > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Switch2_i;
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
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Switch2_i) + rtb_Integrator1_a) *
                         rtb_Integrator1_a) - rtb_Integrator1_a) * 0.5F *
          rtb_Saturation_n + rtb_MathFunction_p_idx_1;

        /* Sum: '<S137>/Add4' */
        rtb_Divide_lr_idx_0 = (rtb_Switch2_i - rtb_a_l) +
          rtb_MathFunction_p_idx_1;

        /* Sum: '<S137>/Add3' */
        rtb_Saturation_n = rtb_Switch2_i + rtb_Integrator1_a;

        /* Sum: '<S137>/Subtract1' */
        rtb_Switch2_i -= rtb_Integrator1_a;

        /* Signum: '<S137>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign1' */

        /* Signum: '<S137>/Sign2' */
        if (rtb_Switch2_i < 0.0F) {
          rtb_Switch2_i = -1.0F;
        } else {
          if (rtb_Switch2_i > 0.0F) {
            rtb_Switch2_i = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign2' */

        /* Sum: '<S137>/Add5' incorporates:
         *  Gain: '<S137>/Gain2'
         *  Product: '<S137>/Multiply4'
         *  Sum: '<S137>/Subtract2'
         */
        rtb_a_l += (rtb_Saturation_n - rtb_Switch2_i) * 0.5F *
          rtb_Divide_lr_idx_0;

        /* Update for DiscreteIntegrator: '<S132>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S132>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_k += 0.004F * FMS_DW.Integrator_DSTATE_a;

        /* Update for DiscreteIntegrator: '<S132>/Integrator' incorporates:
         *  Sum: '<S136>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_a += (rtb_Add4_d - rtb_MathFunction_f_idx_0) *
          0.004F;

        /* Update for DiscreteIntegrator: '<S133>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S133>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_nf += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S137>/Subtract3' */
        rtb_Saturation_n = rtb_a_l - rtb_Integrator1_a;

        /* Sum: '<S137>/Add6' */
        rtb_Add4_d = rtb_a_l + rtb_Integrator1_a;

        /* Signum: '<S137>/Sign5' incorporates:
         *  Signum: '<S137>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Switch2_i = -1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_Divide_lr_idx_0 = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Switch2_i = 1.0F;

          /* Signum: '<S137>/Sign6' */
          rtb_Divide_lr_idx_0 = 1.0F;
        } else {
          rtb_Switch2_i = rtb_a_l;

          /* Signum: '<S137>/Sign6' */
          rtb_Divide_lr_idx_0 = rtb_a_l;
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
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
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
        FMS_DW.Integrator_DSTATE_b += ((rtb_a_l / rtb_Integrator1_a -
          rtb_Switch2_i) * -rtb_Divide_lr_idx_1 * ((rtb_Add4_d -
          rtb_Saturation_n) * 0.5F) - rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_1)
          * 0.004F;

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
          rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Divide_lr_idx_0 = 0.0F;
        } else {
          rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S63>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S63>/Gain' */
        rtb_Saturation_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Divide_lr_idx_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S64>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S31>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Divide_lr_idx_0 = 0.0F;
        } else {
          rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S64>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S64>/Gain' */
        rtb_a_l = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Divide_lr_idx_0;

        /* Sum: '<S67>/Sum of Elements' incorporates:
         *  Math: '<S67>/Square'
         *  SignalConversion: '<S67>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S68>/Sum of Elements'
         *  Switch: '<S49>/Switch'
         */
        rtb_Divide_lr_idx_0 = rtb_Saturation_n * rtb_Saturation_n + rtb_a_l *
          rtb_a_l;

        /* Switch: '<S49>/Switch' incorporates:
         *  Constant: '<S62>/Constant'
         *  Product: '<S68>/Divide'
         *  RelationalOperator: '<S62>/Compare'
         *  Sqrt: '<S67>/Sqrt'
         *  Sum: '<S67>/Sum of Elements'
         */
        if (sqrtf(rtb_Divide_lr_idx_0) > 1.0F) {
          /* Math: '<S68>/Math Function1'
           *
           * About '<S68>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_0 < 0.0F) {
            rtb_Divide_lr_idx_0 = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
          } else {
            rtb_Divide_lr_idx_0 = sqrtf(rtb_Divide_lr_idx_0);
          }

          /* End of Math: '<S68>/Math Function1' */

          /* Switch: '<S68>/Switch' incorporates:
           *  Constant: '<S68>/Constant'
           *  Product: '<S68>/Product'
           */
          if (rtb_Divide_lr_idx_0 > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Saturation_n;
            rtb_MatrixConcatenate3[1] = rtb_a_l;
            rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_0;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S68>/Switch' */
          rtb_Saturation_n = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3
            [2];
          rtb_a_l = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
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
        rtb_Integrator1_a = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Sum: '<S69>/Add' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S65>/Integrator1'
         *  Gain: '<S49>/Gain'
         *  Product: '<S49>/Multiply'
         *  Sum: '<S65>/Subtract'
         */
        rtb_Divide_lr_idx_1 = (FMS_DW.Integrator1_DSTATE_n -
          FMS_PARAM.ROLL_PITCH_LIM * rtb_Saturation_n * (real32_T)
          rtb_FixPtRelationalOperator_me) + rtb_Integrator1_a;

        /* Saturate: '<S69>/Saturation' incorporates:
         *  Constant: '<S65>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Divide_lr_idx_0 = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Divide_lr_idx_0 = 0.0F;
        } else {
          rtb_Divide_lr_idx_0 = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S69>/Saturation' */

        /* Product: '<S69>/Multiply7' incorporates:
         *  Constant: '<S69>/const'
         */
        rtb_Switch2_i = 31.415926F * rtb_Divide_lr_idx_0;

        /* Product: '<S69>/Multiply' */
        rtb_Divide_lr_idx_0 = rtb_Switch2_i * FMS_ConstB.Square_m;

        /* Signum: '<S69>/Sign' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_lr_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_lr_idx_1;
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
        rtb_MathFunction_p_idx_1 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_1) +
          rtb_Divide_lr_idx_0) * rtb_Divide_lr_idx_0) - rtb_Divide_lr_idx_0) *
          0.5F * rtb_Saturation_n + rtb_Integrator1_a;

        /* Sum: '<S69>/Add4' */
        rtb_Add4_d = (rtb_Divide_lr_idx_1 - rtb_MathFunction_p_idx_1) +
          rtb_Integrator1_a;

        /* Sum: '<S69>/Add3' */
        rtb_Saturation_n = rtb_Divide_lr_idx_1 + rtb_Divide_lr_idx_0;

        /* Sum: '<S69>/Subtract1' */
        rtb_Divide_lr_idx_1 -= rtb_Divide_lr_idx_0;

        /* Signum: '<S69>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign1' */

        /* Signum: '<S69>/Sign2' */
        if (rtb_Divide_lr_idx_1 < 0.0F) {
          rtb_Divide_lr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Divide_lr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign2' */

        /* Sum: '<S69>/Add5' incorporates:
         *  Gain: '<S69>/Gain2'
         *  Product: '<S69>/Multiply4'
         *  Sum: '<S69>/Subtract2'
         */
        rtb_MathFunction_p_idx_1 += (rtb_Saturation_n - rtb_Divide_lr_idx_1) *
          0.5F * rtb_Add4_d;

        /* Sum: '<S69>/Add6' */
        rtb_Saturation_n = rtb_MathFunction_p_idx_1 + rtb_Divide_lr_idx_0;

        /* Sum: '<S69>/Subtract3' */
        rtb_Add4_d = rtb_MathFunction_p_idx_1 - rtb_Divide_lr_idx_0;

        /* Signum: '<S69>/Sign5' */
        if (rtb_MathFunction_p_idx_1 < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else if (rtb_MathFunction_p_idx_1 > 0.0F) {
          rtb_Integrator1_a = 1.0F;
        } else {
          rtb_Integrator1_a = rtb_MathFunction_p_idx_1;
        }

        /* End of Signum: '<S69>/Sign5' */

        /* Signum: '<S69>/Sign3' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
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
        rtb_Add4_d = (rtb_MathFunction_p_idx_1 / rtb_Divide_lr_idx_0 -
                      rtb_Integrator1_a) * -rtb_Switch2_i * ((rtb_Saturation_n -
          rtb_Add4_d) * 0.5F);

        /* Signum: '<S69>/Sign6' */
        if (rtb_MathFunction_p_idx_1 < 0.0F) {
          rtb_MathFunction_p_idx_1 = -1.0F;
        } else {
          if (rtb_MathFunction_p_idx_1 > 0.0F) {
            rtb_MathFunction_p_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S69>/Sign6' */

        /* Product: '<S69>/Multiply6' */
        rtb_MathFunction_f_idx_0 = rtb_MathFunction_p_idx_1 * rtb_Switch2_i;

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
          rtb_MathFunction_p_idx_1 = 0.5F;
        } else if (FMS_B.Merge_lf > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_MathFunction_p_idx_1 = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_lf < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S51>/Saturation1' */
          rtb_MathFunction_p_idx_1 = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S51>/Saturation1' */
          rtb_MathFunction_p_idx_1 = FMS_B.Merge_lf;
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
        FMS_Y.FMS_Out.w_cmd = rtb_MathFunction_p_idx_1;

        /* Product: '<S70>/Multiply1' incorporates:
         *  Constant: '<S70>/const1'
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        rtb_MathFunction_p_idx_1 = FMS_DW.Integrator_DSTATE_g * 0.04F;

        /* Sum: '<S70>/Add' incorporates:
         *  DataTypeConversion: '<S49>/Data Type Conversion'
         *  DiscreteIntegrator: '<S66>/Integrator1'
         *  Gain: '<S49>/Gain1'
         *  Product: '<S49>/Multiply1'
         *  Sum: '<S66>/Subtract'
         */
        rtb_Switch2_i = (FMS_DW.Integrator1_DSTATE_i - -FMS_PARAM.ROLL_PITCH_LIM
                         * rtb_a_l * (real32_T)rtb_FixPtRelationalOperator_me) +
          rtb_MathFunction_p_idx_1;

        /* Saturate: '<S70>/Saturation' incorporates:
         *  Constant: '<S66>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Divide_lr_idx_0 = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Divide_lr_idx_0 = 0.0F;
        } else {
          rtb_Divide_lr_idx_0 = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S70>/Saturation' */

        /* Product: '<S70>/Multiply7' incorporates:
         *  Constant: '<S70>/const'
         */
        rtb_Divide_lr_idx_1 = 31.415926F * rtb_Divide_lr_idx_0;

        /* Product: '<S70>/Multiply' */
        rtb_Integrator1_a = rtb_Divide_lr_idx_1 * FMS_ConstB.Square_i;

        /* Signum: '<S70>/Sign' */
        if (rtb_Switch2_i < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Switch2_i > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Switch2_i;
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
        rtb_a_l = (sqrtf((8.0F * fabsf(rtb_Switch2_i) + rtb_Integrator1_a) *
                         rtb_Integrator1_a) - rtb_Integrator1_a) * 0.5F *
          rtb_Saturation_n + rtb_MathFunction_p_idx_1;

        /* Sum: '<S70>/Add4' */
        rtb_Divide_lr_idx_0 = (rtb_Switch2_i - rtb_a_l) +
          rtb_MathFunction_p_idx_1;

        /* Sum: '<S70>/Add3' */
        rtb_Saturation_n = rtb_Switch2_i + rtb_Integrator1_a;

        /* Sum: '<S70>/Subtract1' */
        rtb_Switch2_i -= rtb_Integrator1_a;

        /* Signum: '<S70>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign1' */

        /* Signum: '<S70>/Sign2' */
        if (rtb_Switch2_i < 0.0F) {
          rtb_Switch2_i = -1.0F;
        } else {
          if (rtb_Switch2_i > 0.0F) {
            rtb_Switch2_i = 1.0F;
          }
        }

        /* End of Signum: '<S70>/Sign2' */

        /* Sum: '<S70>/Add5' incorporates:
         *  Gain: '<S70>/Gain2'
         *  Product: '<S70>/Multiply4'
         *  Sum: '<S70>/Subtract2'
         */
        rtb_a_l += (rtb_Saturation_n - rtb_Switch2_i) * 0.5F *
          rtb_Divide_lr_idx_0;

        /* Update for DiscreteIntegrator: '<S65>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S65>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Update for DiscreteIntegrator: '<S65>/Integrator' incorporates:
         *  Sum: '<S69>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += (rtb_Add4_d - rtb_MathFunction_f_idx_0) *
          0.004F;

        /* Update for DiscreteIntegrator: '<S66>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S66>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_i += 0.004F * FMS_DW.Integrator_DSTATE_g;

        /* Sum: '<S70>/Subtract3' */
        rtb_Saturation_n = rtb_a_l - rtb_Integrator1_a;

        /* Sum: '<S70>/Add6' */
        rtb_Add4_d = rtb_a_l + rtb_Integrator1_a;

        /* Signum: '<S70>/Sign5' incorporates:
         *  Signum: '<S70>/Sign6'
         */
        if (rtb_a_l < 0.0F) {
          rtb_Switch2_i = -1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_Divide_lr_idx_0 = -1.0F;
        } else if (rtb_a_l > 0.0F) {
          rtb_Switch2_i = 1.0F;

          /* Signum: '<S70>/Sign6' */
          rtb_Divide_lr_idx_0 = 1.0F;
        } else {
          rtb_Switch2_i = rtb_a_l;

          /* Signum: '<S70>/Sign6' */
          rtb_Divide_lr_idx_0 = rtb_a_l;
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
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
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
        FMS_DW.Integrator_DSTATE_g += ((rtb_a_l / rtb_Integrator1_a -
          rtb_Switch2_i) * -rtb_Divide_lr_idx_1 * ((rtb_Add4_d -
          rtb_Saturation_n) * 0.5F) - rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_1)
          * 0.004F;

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
          rtb_Switch2_i = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_Integrator1_a = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S111>/Multiply' incorporates:
           *  SignalConversion: '<S111>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Integrator1_a + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Switch2_i;
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
            rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
              FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Divide_lr_idx_0 = 0.0F;
          } else {
            rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S117>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S117>/Gain' */
          rtb_Saturation_n = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
            rtb_Divide_lr_idx_0;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S118>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S31>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Divide_lr_idx_0 = 0.0F;
          } else {
            rtb_Divide_lr_idx_0 = FMS_U.Pilot_Cmd.stick_roll -
              (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S118>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S118>/Gain' */
          rtb_a_l = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Divide_lr_idx_0;

          /* Sum: '<S120>/Sum of Elements' incorporates:
           *  Math: '<S120>/Square'
           *  SignalConversion: '<S120>/TmpSignal ConversionAtSquareInport1'
           *  Sum: '<S121>/Sum of Elements'
           *  Switch: '<S112>/Switch'
           */
          rtb_Divide_lr_idx_0 = rtb_Saturation_n * rtb_Saturation_n + rtb_a_l *
            rtb_a_l;

          /* Switch: '<S112>/Switch' incorporates:
           *  Constant: '<S116>/Constant'
           *  Product: '<S121>/Divide'
           *  RelationalOperator: '<S116>/Compare'
           *  Sqrt: '<S120>/Sqrt'
           *  Sum: '<S120>/Sum of Elements'
           */
          if (sqrtf(rtb_Divide_lr_idx_0) > 1.0F) {
            /* Math: '<S121>/Math Function1'
             *
             * About '<S121>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Divide_lr_idx_0 < 0.0F) {
              rtb_Divide_lr_idx_0 = -sqrtf(fabsf(rtb_Divide_lr_idx_0));
            } else {
              rtb_Divide_lr_idx_0 = sqrtf(rtb_Divide_lr_idx_0);
            }

            /* End of Math: '<S121>/Math Function1' */

            /* Switch: '<S121>/Switch' incorporates:
             *  Constant: '<S121>/Constant'
             *  Product: '<S121>/Product'
             */
            if (rtb_Divide_lr_idx_0 > 0.0F) {
              rtb_MatrixConcatenate3[0] = rtb_Saturation_n;
              rtb_MatrixConcatenate3[1] = rtb_a_l;
              rtb_MatrixConcatenate3[2] = rtb_Divide_lr_idx_0;
            } else {
              rtb_MatrixConcatenate3[0] = 0.0F;
              rtb_MatrixConcatenate3[1] = 0.0F;
              rtb_MatrixConcatenate3[2] = 1.0F;
            }

            /* End of Switch: '<S121>/Switch' */
            rtb_Saturation_n = rtb_MatrixConcatenate3[0] /
              rtb_MatrixConcatenate3[2];
            rtb_a_l = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];
          }

          /* Saturate: '<S122>/Saturation' incorporates:
           *  Constant: '<S119>/Constant'
           */
          if (FMS_PARAM.STICK_SENS > 1.0F) {
            rtb_Divide_lr_idx_0 = 1.0F;
          } else if (FMS_PARAM.STICK_SENS < 0.0F) {
            rtb_Divide_lr_idx_0 = 0.0F;
          } else {
            rtb_Divide_lr_idx_0 = FMS_PARAM.STICK_SENS;
          }

          /* End of Saturate: '<S122>/Saturation' */

          /* Product: '<S122>/Multiply7' incorporates:
           *  Constant: '<S122>/const'
           */
          rtb_Divide_lr_idx_0 *= 980.6F;

          /* Product: '<S122>/Multiply' */
          rtb_Switch2_i = rtb_Divide_lr_idx_0 * FMS_ConstB.Square;

          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          rtb_Add4_d = FMS_DW.Integrator_DSTATE[0] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE[0] -
                               FMS_PARAM.VEL_XY_LIM * rtb_Saturation_n) +
            rtb_Add4_d;

          /* Signum: '<S122>/Sign' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Integrator1_a;
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
          rtb_Divide_lr_idx_1 = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) +
            rtb_Switch2_i) * rtb_Switch2_i) - rtb_Switch2_i) * 0.5F *
            rtb_Saturation_n + rtb_Add4_d;

          /* Sum: '<S122>/Add4' */
          rtb_Add4_d += rtb_Integrator1_a - rtb_Divide_lr_idx_1;

          /* Sum: '<S122>/Add3' */
          rtb_Saturation_n = rtb_Integrator1_a + rtb_Switch2_i;

          /* Sum: '<S122>/Subtract1' */
          rtb_Integrator1_a -= rtb_Switch2_i;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Integrator1_a = -1.0F;
          } else {
            if (rtb_Integrator1_a > 0.0F) {
              rtb_Integrator1_a = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Divide_lr_idx_1 += (rtb_Saturation_n - rtb_Integrator1_a) * 0.5F *
            rtb_Add4_d;

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
          rtb_Saturation_n = rtb_Divide_lr_idx_1 - rtb_Switch2_i;

          /* Signum: '<S122>/Sign3' incorporates:
           *  Sum: '<S122>/Add6'
           */
          rtb_Add4_d = rtb_Divide_lr_idx_1 + rtb_Switch2_i;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Integrator1_a = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          } else {
            rtb_Integrator1_a = rtb_Divide_lr_idx_1;
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
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign6' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_MathFunction_p_idx_1 = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_MathFunction_p_idx_1 = 1.0F;
          } else {
            rtb_MathFunction_p_idx_1 = rtb_Divide_lr_idx_1;
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
          FMS_DW.Integrator_DSTATE[0] += ((rtb_Divide_lr_idx_1 / rtb_Switch2_i -
            rtb_Integrator1_a) * -rtb_Divide_lr_idx_0 * ((rtb_Add4_d -
            rtb_Saturation_n) * 0.5F) - rtb_MathFunction_p_idx_1 *
            rtb_Divide_lr_idx_0) * 0.004F;

          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S119>/Integrator'
           */
          rtb_Add4_d = FMS_DW.Integrator_DSTATE[1] * 0.05F;

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  Gain: '<S112>/Gain6'
           *  Sum: '<S119>/Subtract'
           */
          rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE[1] -
                               FMS_PARAM.VEL_XY_LIM * rtb_a_l) + rtb_Add4_d;

          /* Signum: '<S122>/Sign' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Integrator1_a;
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
          rtb_Divide_lr_idx_1 = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) +
            rtb_Switch2_i) * rtb_Switch2_i) - rtb_Switch2_i) * 0.5F *
            rtb_Saturation_n + rtb_Add4_d;

          /* Sum: '<S122>/Add4' */
          rtb_Add4_d += rtb_Integrator1_a - rtb_Divide_lr_idx_1;

          /* Sum: '<S122>/Add3' */
          rtb_Saturation_n = rtb_Integrator1_a + rtb_Switch2_i;

          /* Sum: '<S122>/Subtract1' */
          rtb_Integrator1_a -= rtb_Switch2_i;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign2' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Integrator1_a = -1.0F;
          } else {
            if (rtb_Integrator1_a > 0.0F) {
              rtb_Integrator1_a = 1.0F;
            }
          }

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Divide_lr_idx_1 += (rtb_Saturation_n - rtb_Integrator1_a) * 0.5F *
            rtb_Add4_d;

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
          rtb_Saturation_n = rtb_Divide_lr_idx_1 - rtb_Switch2_i;

          /* Signum: '<S122>/Sign3' incorporates:
           *  Sum: '<S122>/Add6'
           */
          rtb_Add4_d = rtb_Divide_lr_idx_1 + rtb_Switch2_i;

          /* Signum: '<S122>/Sign5' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_Integrator1_a = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          } else {
            rtb_Integrator1_a = rtb_Divide_lr_idx_1;
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
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* Signum: '<S122>/Sign6' */
          if (rtb_Divide_lr_idx_1 < 0.0F) {
            rtb_MathFunction_p_idx_1 = -1.0F;
          } else if (rtb_Divide_lr_idx_1 > 0.0F) {
            rtb_MathFunction_p_idx_1 = 1.0F;
          } else {
            rtb_MathFunction_p_idx_1 = rtb_Divide_lr_idx_1;
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
          FMS_DW.Integrator_DSTATE[1] += ((rtb_Divide_lr_idx_1 / rtb_Switch2_i -
            rtb_Integrator1_a) * -rtb_Divide_lr_idx_0 * ((rtb_Add4_d -
            rtb_Saturation_n) * 0.5F) - rtb_MathFunction_p_idx_1 *
            rtb_Divide_lr_idx_0) * 0.004F;

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
   *  DiscreteIntegrator: '<S496>/Discrete-Time Integrator'
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
  rtb_Divide_lr_idx_0 = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Divide_lr_idx_0 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Divide_lr_idx_0;
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

  /* Update for DiscreteIntegrator: '<S511>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S511>/Gain'
   *  Sum: '<S511>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_ft[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_ft[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_ft[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S513>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S513>/Gain'
   *  Sum: '<S513>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S512>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S512>/Gain'
   *  Sum: '<S512>/Sum5'
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
  rtb_Divide_lr_idx_0 = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Divide_lr_idx_0 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_Divide_lr_idx_0;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S11>/Delay' */
  FMS_DW.Delay_DSTATE_o = rtb_Switch_ga;

  /* Update for DiscreteIntegrator: '<S496>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S496>/Constant'
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
  /* Start for SwitchCase: '<S447>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S437>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;

  /* End of Start for SubSystem: '<S39>/Return' */

  /* Start for IfAction SubSystem: '<S39>/Hold' */
  /* Start for SwitchCase: '<S379>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S357>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S367>/Switch Case' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S511>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S513>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S512>/Discrete-Time Integrator5' */
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
  /* InitializeConditions for Delay: '<S493>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S489>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S489>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Return' */
  /* InitializeConditions for DiscreteIntegrator: '<S427>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for Delay: '<S426>/Delay1' */
  FMS_DW.Delay1_DSTATE_b = false;

  /* InitializeConditions for Delay: '<S426>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S422>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S476>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* InitializeConditions for Delay: '<S404>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S407>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S403>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S407>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S448>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S447>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S447>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S447>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S447>/Move Control' */

  /* SystemInitialize for Merge: '<S447>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S438>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S437>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S437>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S437>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S437>/Move Control' */

  /* SystemInitialize for Merge: '<S437>/Merge' */
  FMS_B.Merge_jj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S39>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S39>/Hold' */
  /* SystemInitialize for Chart: '<S358>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S368>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S380>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S379>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S379>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S379>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S379>/Move Control' */

  /* SystemInitialize for Merge: '<S379>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S357>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S357>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S357>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S357>/Move Control' */

  /* SystemInitialize for Merge: '<S357>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S367>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S367>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S367>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S367>/Move Control' */

  /* SystemInitialize for Merge: '<S367>/Merge' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for Delay: '<S180>/Delay1' */
  FMS_DW.Delay1_DSTATE = false;

  /* InitializeConditions for Delay: '<S180>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S176>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S230>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

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
