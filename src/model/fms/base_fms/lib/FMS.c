/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1871
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Oct 14 08:38:55 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S376>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S386>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

/* Named constants for Chart: '<S124>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S43>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S320>/Motion State' */
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
  0U                                   /* reserved */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_z8TbXuqo9JNiexfZo6b1iC FMS_PARAM = {
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
  1.5F,
  0.5F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S426>/Constant'
                                        *   '<S303>/L1'
                                        *   '<S40>/Gain'
                                        *   '<S40>/Gain1'
                                        *   '<S114>/Gain'
                                        *   '<S114>/Gain1'
                                        *   '<S140>/L1'
                                        *   '<S214>/Saturation'
                                        *   '<S215>/Saturation1'
                                        *   '<S215>/Saturation2'
                                        *   '<S215>/Saturation3'
                                        *   '<S344>/Saturation1'
                                        *   '<S417>/Gain2'
                                        *   '<S417>/Saturation1'
                                        *   '<S42>/Saturation1'
                                        *   '<S53>/Dead Zone'
                                        *   '<S53>/Gain'
                                        *   '<S54>/Dead Zone'
                                        *   '<S54>/Gain'
                                        *   '<S59>/Saturation'
                                        *   '<S75>/Saturation1'
                                        *   '<S86>/Saturation'
                                        *   '<S99>/Saturation1'
                                        *   '<S117>/Dead Zone'
                                        *   '<S117>/Gain'
                                        *   '<S118>/Dead Zone'
                                        *   '<S118>/Gain'
                                        *   '<S123>/Saturation'
                                        *   '<S268>/Gain2'
                                        *   '<S275>/Gain1'
                                        *   '<S275>/Gain2'
                                        *   '<S309>/Saturation1'
                                        *   '<S319>/Saturation'
                                        *   '<S331>/Saturation1'
                                        *   '<S345>/Gain2'
                                        *   '<S367>/vel'
                                        *   '<S367>/Saturation'
                                        *   '<S367>/Switch'
                                        *   '<S45>/Gain2'
                                        *   '<S46>/Gain1'
                                        *   '<S51>/Constant'
                                        *   '<S62>/Gain2'
                                        *   '<S63>/Gain1'
                                        *   '<S70>/Constant'
                                        *   '<S78>/Gain2'
                                        *   '<S79>/Gain1'
                                        *   '<S84>/Constant'
                                        *   '<S89>/Gain2'
                                        *   '<S90>/Gain1'
                                        *   '<S97>/Constant'
                                        *   '<S102>/Gain2'
                                        *   '<S103>/Gain6'
                                        *   '<S111>/Constant'
                                        *   '<S112>/Constant'
                                        *   '<S126>/Gain2'
                                        *   '<S127>/Gain1'
                                        *   '<S134>/Constant'
                                        *   '<S159>/Gain'
                                        *   '<S159>/Saturation1'
                                        *   '<S160>/vel'
                                        *   '<S160>/Saturation'
                                        *   '<S160>/Switch'
                                        *   '<S312>/Gain2'
                                        *   '<S313>/Gain1'
                                        *   '<S322>/Gain2'
                                        *   '<S323>/Gain1'
                                        *   '<S334>/Gain2'
                                        *   '<S335>/Gain6'
                                        *   '<S354>/Gain2'
                                        *   '<S354>/Saturation'
                                        *   '<S355>/Integrator'
                                        *   '<S48>/Dead Zone'
                                        *   '<S48>/Gain'
                                        *   '<S67>/Dead Zone'
                                        *   '<S67>/Gain'
                                        *   '<S81>/Dead Zone'
                                        *   '<S81>/Gain'
                                        *   '<S94>/Dead Zone'
                                        *   '<S94>/Gain'
                                        *   '<S107>/Dead Zone'
                                        *   '<S107>/Gain'
                                        *   '<S108>/Dead Zone'
                                        *   '<S108>/Gain'
                                        *   '<S131>/Dead Zone'
                                        *   '<S131>/Gain'
                                        *   '<S146>/Gain2'
                                        *   '<S146>/Saturation'
                                        *   '<S147>/Integrator'
                                        *   '<S315>/Dead Zone'
                                        *   '<S315>/Gain'
                                        *   '<S327>/Dead Zone'
                                        *   '<S327>/Gain'
                                        *   '<S339>/Dead Zone'
                                        *   '<S339>/Gain'
                                        *   '<S340>/Dead Zone'
                                        *   '<S340>/Gain'
                                        *   '<S375>/Saturation1'
                                        *   '<S385>/Saturation1'
                                        *   '<S171>/Saturation1'
                                        *   '<S181>/Saturation1'
                                        *   '<S378>/Gain2'
                                        *   '<S379>/Gain1'
                                        *   '<S388>/Gain2'
                                        *   '<S389>/Gain6'
                                        *   '<S174>/Gain2'
                                        *   '<S175>/Gain1'
                                        *   '<S184>/Gain2'
                                        *   '<S185>/Gain6'
                                        *   '<S381>/Dead Zone'
                                        *   '<S381>/Gain'
                                        *   '<S393>/Dead Zone'
                                        *   '<S393>/Gain'
                                        *   '<S394>/Dead Zone'
                                        *   '<S394>/Gain'
                                        *   '<S177>/Dead Zone'
                                        *   '<S177>/Gain'
                                        *   '<S189>/Dead Zone'
                                        *   '<S189>/Gain'
                                        *   '<S190>/Dead Zone'
                                        *   '<S190>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 48, 46, 52, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S11>/Constant1'
                                        *   '<S424>/Constant'
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
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode);
static void FMS_Standby(void);
static void FMS_Vehicle(void);
static void FMS_c11_FMS(void);
static void FMS_sf_msg_discard_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for action system:
 *    '<S21>/Disarm'
 *    '<S30>/Unknown'
 *    '<S28>/Unknown'
 *    '<S27>/Unknown'
 *    '<S23>/Unknown'
 */
void FMS_Disarm(FMS_Out_Bus *rty_FMS_Out, const ConstB_Disarm_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S25>/Bus Assignment' incorporates:
   *  Constant: '<S25>/Constant'
   *  Constant: '<S25>/Constant2'
   *  SignalConversion: '<S25>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S25>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S375>/Hold Control'
 *    '<S309>/Hold Control'
 *    '<S171>/Hold Control'
 *    '<S42>/Hold Control'
 *    '<S75>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S378>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S375>/Hold Control'
 *    '<S309>/Hold Control'
 *    '<S171>/Hold Control'
 *    '<S42>/Hold Control'
 *    '<S75>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S378>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S375>/Hold Control'
 *    '<S309>/Hold Control'
 *    '<S171>/Hold Control'
 *    '<S42>/Hold Control'
 *    '<S75>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S378>/Delay' incorporates:
   *  Gain: '<S380>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S378>/Gain2' incorporates:
   *  Delay: '<S378>/Delay'
   *  Gain: '<S380>/Gain'
   *  Sum: '<S378>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S378>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S375>/Brake Control'
 *    '<S309>/Brake Control'
 *    '<S319>/Brake Control'
 *    '<S171>/Brake Control'
 *    '<S123>/Brake Control'
 *    '<S42>/Brake Control'
 *    '<S59>/Brake Control'
 *    '<S75>/Brake Control'
 *    '<S86>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S377>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S377>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S375>/Move Control'
 *    '<S309>/Move Control'
 *    '<S171>/Move Control'
 *    '<S42>/Move Control'
 *    '<S75>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S375>/Move Control'
 *    '<S309>/Move Control'
 *    '<S171>/Move Control'
 *    '<S42>/Move Control'
 *    '<S75>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S375>/Move Control'
 *    '<S309>/Move Control'
 *    '<S171>/Move Control'
 *    '<S42>/Move Control'
 *    '<S75>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3_c;
  real32_T rtb_Subtract3_dn;
  real32_T rtb_a_hr;
  real32_T rtb_Add4_g;
  real32_T rtb_a_b;

  /* Product: '<S383>/Multiply1' incorporates:
   *  Constant: '<S383>/const1'
   *  DiscreteIntegrator: '<S382>/Integrator'
   */
  rtb_Add3_c = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S381>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = 0.0F;
  } else {
    rtb_a_hr = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S381>/Dead Zone' */

  /* Sum: '<S383>/Add' incorporates:
   *  DiscreteIntegrator: '<S382>/Integrator1'
   *  Gain: '<S379>/Gain1'
   *  Gain: '<S381>/Gain'
   *  Sum: '<S382>/Subtract'
   */
  rtb_Subtract3_dn = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_hr * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_c;

  /* Signum: '<S383>/Sign' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_a_hr = -1.0F;
  } else if (rtb_Subtract3_dn > 0.0F) {
    rtb_a_hr = 1.0F;
  } else {
    rtb_a_hr = rtb_Subtract3_dn;
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
  rtb_a_hr = (sqrtf((8.0F * fabsf(rtb_Subtract3_dn) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_hr + rtb_Add3_c;

  /* Sum: '<S383>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_dn - rtb_a_hr) + rtb_Add3_c;

  /* Sum: '<S383>/Add3' */
  rtb_Add3_c = rtb_Subtract3_dn + localC->d;

  /* Sum: '<S383>/Subtract1' */
  rtb_Subtract3_dn -= localC->d;

  /* Signum: '<S383>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S383>/Sign1' */

  /* Signum: '<S383>/Sign2' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S383>/Sign2' */

  /* Sum: '<S383>/Add5' incorporates:
   *  Gain: '<S383>/Gain2'
   *  Product: '<S383>/Multiply4'
   *  Sum: '<S383>/Subtract2'
   */
  rtb_a_hr += (rtb_Add3_c - rtb_Subtract3_dn) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S379>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S382>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S382>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S382>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S383>/Add6' */
  rtb_Add3_c = rtb_a_hr + localC->d;

  /* Sum: '<S383>/Subtract3' */
  rtb_Subtract3_dn = rtb_a_hr - localC->d;

  /* Signum: '<S383>/Sign5' */
  if (rtb_a_hr < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_hr;
  }

  /* End of Signum: '<S383>/Sign5' */

  /* Signum: '<S383>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S383>/Sign3' */

  /* Signum: '<S383>/Sign4' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S383>/Sign4' */

  /* Signum: '<S383>/Sign6' */
  if (rtb_a_hr < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_a_hr;
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
  localDW->Integrator_DSTATE += ((rtb_a_hr / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3_c - rtb_Subtract3_dn) * 0.5F) - rtb_a_b * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S376>/Motion Status'
 *    '<S310>/Motion Status'
 *    '<S172>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S376>/Motion Status'
 *    '<S310>/Motion Status'
 *    '<S172>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S376>/Motion Status'
 *    '<S310>/Motion Status'
 *    '<S172>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S376>/Motion Status' */
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

  /* End of Chart: '<S376>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S385>/Hold Control'
 *    '<S331>/Hold Control'
 *    '<S181>/Hold Control'
 *    '<S99>/Hold Control'
 */
void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S388>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S385>/Hold Control'
 *    '<S331>/Hold Control'
 *    '<S181>/Hold Control'
 *    '<S99>/Hold Control'
 */
void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S388>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S385>/Hold Control'
 *    '<S331>/Hold Control'
 *    '<S181>/Hold Control'
 *    '<S99>/Hold Control'
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

  /* Delay: '<S388>/Delay' incorporates:
   *  SignalConversion: '<S388>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_p;
  }

  /* Trigonometry: '<S392>/Trigonometric Function1' incorporates:
   *  Gain: '<S391>/Gain'
   *  Trigonometry: '<S392>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bl_tmp_0 = arm_cos_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_bl_tmp_0;

  /* Trigonometry: '<S392>/Trigonometric Function' incorporates:
   *  Gain: '<S391>/Gain'
   *  Trigonometry: '<S392>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bl_tmp = arm_sin_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_bl_tmp;

  /* SignalConversion: '<S392>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S392>/Constant3'
   */
  rtb_VectorConcatenate_k[2] = 0.0F;

  /* Gain: '<S392>/Gain' */
  rtb_VectorConcatenate_k[3] = -rtb_VectorConcatenate_bl_tmp;

  /* Trigonometry: '<S392>/Trigonometric Function3' */
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_bl_tmp_0;

  /* SignalConversion: '<S392>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S392>/Constant4'
   */
  rtb_VectorConcatenate_k[5] = 0.0F;

  /* SignalConversion: '<S392>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_k[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_k[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_k[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S388>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S388>/Delay'
   *  SignalConversion: '<S388>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S388>/Sum'
   */
  rtb_VectorConcatenate_bl_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bl_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_p;

  /* Product: '<S388>/Multiply' incorporates:
   *  SignalConversion: '<S388>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bl[i] = rtb_VectorConcatenate_k[i + 3] *
      rtb_VectorConcatenate_bl_tmp + rtb_VectorConcatenate_k[i] *
      rtb_VectorConcatenate_bl_tmp_0;
  }

  /* End of Product: '<S388>/Multiply' */

  /* Gain: '<S388>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[1];

  /* Update for Delay: '<S388>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S385>/Brake Control'
 *    '<S331>/Brake Control'
 *    '<S181>/Brake Control'
 *    '<S99>/Brake Control'
 */
void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S387>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S385>/Move Control'
 *    '<S331>/Move Control'
 *    '<S181>/Move Control'
 *    '<S99>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S385>/Move Control'
 *    '<S331>/Move Control'
 *    '<S181>/Move Control'
 *    '<S99>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S395>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S385>/Move Control'
 *    '<S331>/Move Control'
 *    '<S181>/Move Control'
 *    '<S99>/Move Control'
 */
void FMS_MoveControl_o(real32_T rtu_FMS_In, real32_T rtu_FMS_In_g, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_k_T *localC,
  DW_MoveControl_FMS_d_T *localDW)
{
  real32_T rtb_Subtract3_nv;
  real32_T rtb_Add3_e1_idx_0;
  real32_T rtb_Subtract3_h_idx_0;
  real32_T rtb_Add3_e1_idx_1;
  real32_T rtb_Subtract3_h_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_h_idx_0_0;

  /* SignalConversion: '<S389>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S395>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S396>/Multiply1' incorporates:
   *  Constant: '<S396>/const1'
   *  DiscreteIntegrator: '<S395>/Integrator'
   */
  rtb_Add3_e1_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S389>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S395>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S396>/Multiply1' incorporates:
   *  Constant: '<S396>/const1'
   *  DiscreteIntegrator: '<S395>/Integrator'
   */
  rtb_Add3_e1_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S393>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S393>/Dead Zone' */

  /* Sum: '<S396>/Add' incorporates:
   *  DiscreteIntegrator: '<S395>/Integrator1'
   *  Gain: '<S389>/Gain6'
   *  Gain: '<S393>/Gain'
   *  Sum: '<S395>/Subtract'
   */
  rtb_Subtract3_h_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_0;

  /* DeadZone: '<S394>/Dead Zone' */
  if (rtu_FMS_In_g > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_g >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S394>/Dead Zone' */

  /* Sum: '<S396>/Add' incorporates:
   *  DiscreteIntegrator: '<S395>/Integrator1'
   *  Gain: '<S389>/Gain6'
   *  Gain: '<S394>/Gain'
   *  Sum: '<S395>/Subtract'
   */
  rtb_Subtract3_h_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_1;

  /* Signum: '<S396>/Sign' */
  if (rtb_Subtract3_h_idx_0 < 0.0F) {
    rtb_Subtract3_h_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0 > 0.0F) {
    rtb_Subtract3_h_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0_0 = rtb_Subtract3_h_idx_0;
  }

  /* Sum: '<S396>/Add2' incorporates:
   *  Abs: '<S396>/Abs'
   *  Gain: '<S396>/Gain'
   *  Gain: '<S396>/Gain1'
   *  Product: '<S396>/Multiply2'
   *  Product: '<S396>/Multiply3'
   *  Signum: '<S396>/Sign'
   *  Sqrt: '<S396>/Sqrt'
   *  Sum: '<S396>/Add1'
   *  Sum: '<S396>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_h_idx_0_0 +
    rtb_Add3_e1_idx_0;

  /* Sum: '<S396>/Add3' incorporates:
   *  Signum: '<S396>/Sign'
   */
  u = rtb_Subtract3_h_idx_0 + localC->d;

  /* Sum: '<S396>/Subtract1' incorporates:
   *  Signum: '<S396>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_0 - localC->d;

  /* Signum: '<S396>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S396>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S396>/Add5' incorporates:
   *  Gain: '<S396>/Gain2'
   *  Product: '<S396>/Multiply4'
   *  Signum: '<S396>/Sign'
   *  Sum: '<S396>/Add2'
   *  Sum: '<S396>/Add4'
   *  Sum: '<S396>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_0 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_0) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S395>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S395>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S396>/Sign3' incorporates:
   *  Sum: '<S396>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S396>/Sign4' incorporates:
   *  Sum: '<S396>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S396>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S396>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S396>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S396>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

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
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;

  /* Signum: '<S396>/Sign' */
  if (rtb_Subtract3_h_idx_1 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_1 > 0.0F) {
    rtb_Add3_e1_idx_0 = 1.0F;
  } else {
    rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_1;
  }

  /* Sum: '<S396>/Add2' incorporates:
   *  Abs: '<S396>/Abs'
   *  Gain: '<S396>/Gain'
   *  Gain: '<S396>/Gain1'
   *  Product: '<S396>/Multiply2'
   *  Product: '<S396>/Multiply3'
   *  Signum: '<S396>/Sign'
   *  Sqrt: '<S396>/Sqrt'
   *  Sum: '<S396>/Add1'
   *  Sum: '<S396>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_e1_idx_0 +
    rtb_Add3_e1_idx_1;

  /* Sum: '<S396>/Add3' incorporates:
   *  Signum: '<S396>/Sign'
   */
  u = rtb_Subtract3_h_idx_1 + localC->d;

  /* Sum: '<S396>/Subtract1' incorporates:
   *  Signum: '<S396>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_1 - localC->d;

  /* Signum: '<S396>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S396>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S396>/Add5' incorporates:
   *  Gain: '<S396>/Gain2'
   *  Product: '<S396>/Multiply4'
   *  Signum: '<S396>/Sign'
   *  Sum: '<S396>/Add2'
   *  Sum: '<S396>/Add4'
   *  Sum: '<S396>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_1 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_1) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S395>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S395>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S396>/Sign3' incorporates:
   *  Sum: '<S396>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S396>/Sign4' incorporates:
   *  Sum: '<S396>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S396>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S396>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S396>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S396>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

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
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S386>/Motion State'
 *    '<S332>/Motion State'
 *    '<S182>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * System reset for atomic system:
 *    '<S386>/Motion State'
 *    '<S332>/Motion State'
 *    '<S182>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * Output and update for atomic system:
 *    '<S386>/Motion State'
 *    '<S332>/Motion State'
 *    '<S182>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S386>/Motion State' */
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

  /* End of Chart: '<S386>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S369>/NearbyRefWP'
 *    '<S162>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S400>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S319>/Hold Control'
 *    '<S123>/Hold Control'
 *    '<S59>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S322>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S319>/Hold Control'
 *    '<S123>/Hold Control'
 *    '<S59>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S322>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S319>/Hold Control'
 *    '<S123>/Hold Control'
 *    '<S59>/Hold Control'
 *    '<S86>/Hold Control'
 */
void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S322>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S322>/Sum' incorporates:
   *  Delay: '<S322>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S325>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S325>/Switch' incorporates:
   *  Constant: '<S325>/Constant'
   *  Constant: '<S326>/Constant'
   *  Product: '<S325>/Multiply'
   *  RelationalOperator: '<S326>/Compare'
   *  Sum: '<S325>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S325>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S325>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S325>/Switch' */

  /* Gain: '<S322>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S322>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S319>/Move Control'
 *    '<S123>/Move Control'
 *    '<S59>/Move Control'
 *    '<S86>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S328>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S328>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S319>/Move Control'
 *    '<S123>/Move Control'
 *    '<S59>/Move Control'
 *    '<S86>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S328>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S328>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S319>/Move Control'
 *    '<S123>/Move Control'
 *    '<S59>/Move Control'
 *    '<S86>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_a;
  real32_T rtb_Subtract3_i;
  real32_T rtb_a_b;
  real32_T rtb_Add4_bf;
  real32_T rtb_a_p;

  /* Product: '<S329>/Multiply1' incorporates:
   *  Constant: '<S329>/const1'
   *  DiscreteIntegrator: '<S328>/Integrator'
   */
  rtb_Add3_a = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S327>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_b = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_b = 0.0F;
  } else {
    rtb_a_b = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S327>/Dead Zone' */

  /* Sum: '<S329>/Add' incorporates:
   *  DiscreteIntegrator: '<S328>/Integrator1'
   *  Gain: '<S323>/Gain1'
   *  Gain: '<S327>/Gain'
   *  Sum: '<S328>/Subtract'
   */
  rtb_Subtract3_i = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_b * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_a;

  /* Signum: '<S329>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_Subtract3_i;
  }

  /* End of Signum: '<S329>/Sign' */

  /* Sum: '<S329>/Add2' incorporates:
   *  Abs: '<S329>/Abs'
   *  Gain: '<S329>/Gain'
   *  Gain: '<S329>/Gain1'
   *  Product: '<S329>/Multiply2'
   *  Product: '<S329>/Multiply3'
   *  Sqrt: '<S329>/Sqrt'
   *  Sum: '<S329>/Add1'
   *  Sum: '<S329>/Subtract'
   */
  rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_b + rtb_Add3_a;

  /* Sum: '<S329>/Add4' */
  rtb_Add4_bf = (rtb_Subtract3_i - rtb_a_b) + rtb_Add3_a;

  /* Sum: '<S329>/Add3' */
  rtb_Add3_a = rtb_Subtract3_i + localC->d;

  /* Sum: '<S329>/Subtract1' */
  rtb_Subtract3_i -= localC->d;

  /* Signum: '<S329>/Sign1' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S329>/Sign1' */

  /* Signum: '<S329>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S329>/Sign2' */

  /* Sum: '<S329>/Add5' incorporates:
   *  Gain: '<S329>/Gain2'
   *  Product: '<S329>/Multiply4'
   *  Sum: '<S329>/Subtract2'
   */
  rtb_a_b += (rtb_Add3_a - rtb_Subtract3_i) * 0.5F * rtb_Add4_bf;

  /* SignalConversion: '<S323>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S328>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S328>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S328>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S329>/Add6' */
  rtb_Add3_a = rtb_a_b + localC->d;

  /* Sum: '<S329>/Subtract3' */
  rtb_Subtract3_i = rtb_a_b - localC->d;

  /* Signum: '<S329>/Sign5' */
  if (rtb_a_b < 0.0F) {
    rtb_Add4_bf = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_Add4_bf = 1.0F;
  } else {
    rtb_Add4_bf = rtb_a_b;
  }

  /* End of Signum: '<S329>/Sign5' */

  /* Signum: '<S329>/Sign3' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S329>/Sign3' */

  /* Signum: '<S329>/Sign4' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S329>/Sign4' */

  /* Signum: '<S329>/Sign6' */
  if (rtb_a_b < 0.0F) {
    rtb_a_p = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_a_p = 1.0F;
  } else {
    rtb_a_p = rtb_a_b;
  }

  /* End of Signum: '<S329>/Sign6' */

  /* Update for DiscreteIntegrator: '<S328>/Integrator' incorporates:
   *  Constant: '<S329>/const'
   *  Gain: '<S329>/Gain3'
   *  Product: '<S329>/Divide'
   *  Product: '<S329>/Multiply5'
   *  Product: '<S329>/Multiply6'
   *  Sum: '<S329>/Subtract4'
   *  Sum: '<S329>/Subtract5'
   *  Sum: '<S329>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_b / localC->d - rtb_Add4_bf) *
    localC->Gain4 * ((rtb_Add3_a - rtb_Subtract3_i) * 0.5F) - rtb_a_p *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S124>/Motion State'
 *    '<S60>/Motion State'
 *    '<S87>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S124>/Motion State'
 *    '<S60>/Motion State'
 *    '<S87>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S124>/Motion State'
 *    '<S60>/Motion State'
 *    '<S87>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S124>/Motion State' */
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

  /* End of Chart: '<S124>/Motion State' */
}

/*
 * System initialize for atomic system:
 *    '<S43>/Motion Status'
 *    '<S76>/Motion Status'
 */
void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S43>/Motion Status'
 *    '<S76>/Motion Status'
 */
void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S43>/Motion Status'
 *    '<S76>/Motion Status'
 */
void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW)
{
  /* Chart: '<S43>/Motion Status' */
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

  /* End of Chart: '<S43>/Motion Status' */
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

/* Output and update for function-call system: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
void F_VehicleArmAutoMissionLLA2FLAT(const real_T rtu_lla[3], const real_T
  rtu_llo[2], real_T rtu_href, real_T rtu_psio, real32_T rty_pos[3], const
  ConstB_VehicleArmAutoMissionL_T *localC)
{
  real_T rtb_Sum2_ee;
  real_T rtb_Gain_d;
  real_T rtb_Sum3;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S428>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S429>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S429>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S429>/Multiply1' incorporates:
   *  Product: '<S429>/Multiply'
   */
  rtb_Gain_d = localC->ff * rtb_Sum2_ee;

  /* Product: '<S429>/Divide' incorporates:
   *  Constant: '<S429>/Constant'
   *  Constant: '<S429>/R'
   *  Sqrt: '<S429>/Sqrt'
   *  Sum: '<S429>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_d);

  /* Product: '<S429>/Product3' incorporates:
   *  Constant: '<S429>/Constant1'
   *  Product: '<S429>/Multiply1'
   *  Sum: '<S429>/Sum2'
   */
  rtb_Gain_d = 1.0 / (1.0 - rtb_Gain_d) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S429>/Multiply2' incorporates:
   *  Trigonometry: '<S429>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S428>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S433>/Abs' incorporates:
   *  Abs: '<S436>/Abs1'
   *  Switch: '<S433>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S433>/Switch1' incorporates:
   *  Abs: '<S433>/Abs'
   *  Bias: '<S433>/Bias2'
   *  Bias: '<S433>/Bias3'
   *  Constant: '<S430>/Constant'
   *  Constant: '<S430>/Constant1'
   *  Constant: '<S435>/Constant'
   *  Gain: '<S433>/Gain1'
   *  Product: '<S433>/Multiply'
   *  RelationalOperator: '<S435>/Compare'
   *  Switch: '<S430>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S436>/Switch1' incorporates:
     *  Bias: '<S436>/Bias2'
     *  Bias: '<S436>/Bias3'
     *  Constant: '<S436>/Constant'
     *  Constant: '<S437>/Constant'
     *  Math: '<S436>/Math Function'
     *  RelationalOperator: '<S437>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S436>/Switch1' */

    /* Signum: '<S433>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S433>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S430>/Sum' incorporates:
   *  Sum: '<S428>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S428>/Multiply' incorporates:
   *  Gain: '<S428>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_d;

  /* Switch: '<S432>/Switch1' incorporates:
   *  Abs: '<S432>/Abs1'
   *  Bias: '<S432>/Bias2'
   *  Bias: '<S432>/Bias3'
   *  Constant: '<S432>/Constant'
   *  Constant: '<S434>/Constant'
   *  Math: '<S432>/Math Function'
   *  RelationalOperator: '<S434>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S432>/Switch1' */

  /* Product: '<S428>/Multiply' incorporates:
   *  Gain: '<S428>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S428>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S431>/SinCos' */
  rtb_Sum3 = sin(rtb_Sum2_ee);
  rtb_Gain_d = cos(rtb_Sum2_ee);

  /* Sum: '<S431>/Sum2' incorporates:
   *  Product: '<S431>/Multiply1'
   *  Product: '<S431>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_d + rtb_Sum_d * rtb_Sum3;

  /* Product: '<S431>/Multiply3' */
  rtb_Sum3 *= rtb_Sum_e_idx_0;

  /* Product: '<S431>/Multiply4' */
  rtb_Gain_d *= rtb_Sum_d;

  /* Sum: '<S431>/Sum3' */
  rtb_Sum3 = rtb_Gain_d - rtb_Sum3;

  /* DataTypeConversion: '<S425>/Data Type Conversion' incorporates:
   *  Gain: '<S428>/Gain'
   *  Sum: '<S428>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_ee;
  rty_pos[1] = (real32_T)rtb_Sum3;
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

    /* End of Delay: '<S13>/Delay' */
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

    /* End of Delay: '<S13>/Delay' */
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
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_i, &FMS_DW.M_msgReservedData);
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_i, &FMS_DW.Msg_FMS_Cmd_l
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_l[0] : NULL;
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

            /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
            F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
              FMS_B.psio, FMS_B.DataTypeConversion,
              &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

            /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
            FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
            FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
            FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
            FMS_B.state = VehicleState_Takeoff;
          } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Waypoint) {
            FMS_DW.is_Mission = FMS_IN_Waypoint;

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

            /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
            F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
              FMS_B.psio, FMS_B.DataTypeConversion,
              &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

            /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
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
            FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
            FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
            FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
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
            FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
            FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
            FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
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

  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S438>/Compare' incorporates:
   *  Abs: '<S427>/Abs'
   *  Constant: '<S438>/Constant'
   *  MinMax: '<S427>/Max'
   *  Sum: '<S427>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S4>/Vehicle.StickMoved' */
  if (FMS_B.Compare && (FMS_B.target_mode != PilotMode_None)) {
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
        if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_l = FMS_B.on_ground;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_n >= 500) {
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
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_SubMode = FMS_IN_Land;
          FMS_B.state = VehicleState_Land;
          FMS_DW.condWasTrueAtLastTimeStep_1_l = FMS_B.on_ground;
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
static void FMS_Standby(void)
{
  boolean_T condIsTrue;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  guard1 = false;
  guard2 = false;
  if ((FMS_ManualArmEvent(FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
                          FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
      (FMS_B.target_mode != PilotMode_None)) {
    guard1 = true;
  } else {
    condIsTrue = (FMS_DW.prep_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
      FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1_j = condIsTrue;
    if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_f >=
        500) {
      guard2 = true;
    } else {
      if (FMS_sf_msg_pop_M()) {
        condIsTrue = (FMS_DW.M_msgReservedData == FMS_Cmd_Takeoff);
      } else {
        condIsTrue = false;
      }

      if (condIsTrue) {
        guard2 = true;
      } else if ((FMS_DW.temporalCounter_i1 >= 2500U) || (FMS_DW.sfEvent ==
                  FMS_event_DisarmEvent)) {
        FMS_DW.prep_takeoff = 0.0;
        condIsTrue = (FMS_DW.prep_takeoff == 1.0);
        if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
          FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_j = condIsTrue;
        FMS_DW.prep_mission_takeoff = 0.0;
        condIsTrue = (FMS_DW.prep_mission_takeoff == 1.0);
        if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_2 = condIsTrue;
        FMS_DW.is_Vehicle = FMS_IN_Disarm;
        FMS_B.state = VehicleState_Disarm;
      } else {
        condIsTrue = (FMS_DW.prep_mission_takeoff == 1.0);
        if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_2 = condIsTrue;
        if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_2
            >= 500) {
          guard1 = true;
        }
      }
    }
  }

  if (guard2) {
    FMS_B.xy_R[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
    FMS_B.xy_R[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;

    /* Outputs for Function Call SubSystem: '<S4>/Vehicle.PrepTakeoff' */
    /* Reshape: '<S426>/Reshape' incorporates:
     *  Constant: '<S426>/Constant'
     */
    FMS_B.Reshape[0] = FMS_B.xy_R[0];
    FMS_B.Reshape[1] = FMS_B.xy_R[1];
    FMS_B.Reshape[2] = FMS_PARAM.TAKEOFF_H;

    /* End of Outputs for SubSystem: '<S4>/Vehicle.PrepTakeoff' */
    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.Reshape[0];
    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.Reshape[1];
    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.Reshape[2];
    FMS_B.Cmd_In.sp_waypoint[2] += FMS_DW.home[2];
    FMS_DW.prep_takeoff = 0.0;
    condIsTrue = (FMS_DW.prep_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
      FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1_j = condIsTrue;
    FMS_DW.prep_mission_takeoff = 0.0;
    condIsTrue = (FMS_DW.prep_mission_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_2 = condIsTrue;
    FMS_DW.durationLastReferenceTick_1_o = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Vehicle = FMS_IN_Arm;
    FMS_DW.condWasTrueAtLastTimeStep_1_a = FMS_B.on_ground;
    FMS_DW.is_Arm = FMS_IN_SubMode;
    FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
    FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
    FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
    FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
    FMS_DW.is_SubMode = FMS_IN_Takeoff;
    FMS_B.state = VehicleState_Takeoff;
  }

  if (guard1) {
    FMS_DW.prep_takeoff = 0.0;
    condIsTrue = (FMS_DW.prep_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
      FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1_j = condIsTrue;
    FMS_DW.prep_mission_takeoff = 0.0;
    condIsTrue = (FMS_DW.prep_mission_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_2 = condIsTrue;
    FMS_DW.durationLastReferenceTick_1_o = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Vehicle = FMS_IN_Arm;
    FMS_DW.condWasTrueAtLastTimeStep_1_a = FMS_B.on_ground;
    FMS_enter_internal_Arm();
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Vehicle(void)
{
  boolean_T sf_internal_predicateOutput;
  int32_T b_previousEvent;
  real_T tmp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
        FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_j = sf_internal_predicateOutput;
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
    switch (FMS_DW.is_Vehicle) {
     case FMS_IN_Arm:
      if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_a)) {
        FMS_DW.durationLastReferenceTick_1_o = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_a = FMS_B.on_ground;
      if ((FMS_DW.chartAbsoluteTimeCounter -
           FMS_DW.durationLastReferenceTick_1_o >= 500) && (FMS_B.target_mode !=
           PilotMode_Mission)) {
        FMS_exit_internal_Arm();
        FMS_DW.is_Vehicle = FMS_IN_Disarm;
        FMS_B.state = VehicleState_Disarm;
      } else if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.target_mode
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
          sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
            FMS_Cmd_Land);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          FMS_B.Cmd_In.sp_waypoint[0] =
            FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
          FMS_B.Cmd_In.sp_waypoint[1] =
            FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
          FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_SubMode;
          FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
          FMS_DW.stick_val[1] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
          FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
          FMS_DW.stick_val[3] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_SubMode = FMS_IN_Land;
          FMS_B.state = VehicleState_Land;
          FMS_DW.condWasTrueAtLastTimeStep_1_l = FMS_B.on_ground;
        } else {
          if (FMS_sf_msg_pop_M()) {
            sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Return);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
            FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
            FMS_B.Cmd_In.sp_waypoint[2] =
              FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
            FMS_exit_internal_Arm();
            FMS_DW.is_Arm = FMS_IN_SubMode;
            FMS_DW.stick_val[0] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
            FMS_DW.stick_val[1] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
            FMS_DW.stick_val[2] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
            FMS_DW.stick_val[3] =
              FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
            FMS_DW.is_SubMode = FMS_IN_Return;
            FMS_B.state = VehicleState_Return;
          } else {
            switch (FMS_DW.is_Arm) {
             case FMS_IN_Assist:
              if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
                FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
                FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
                FMS_DW.is_Vehicle = FMS_IN_Disarm;
                FMS_B.state = VehicleState_Disarm;
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
              (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
            FMS_DW.durationLastReferenceTick_1_f =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_j = sf_internal_predicateOutput;
          guard1 = true;
        }
      }
      break;

     case FMS_IN_Standby:
      FMS_Standby();
      break;
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_j = false;
      FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      guard2 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if ((FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          FMS_DW.prep_mission_takeoff = 1.0;
          FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff ==
            1.0);
          FMS_DW.prep_takeoff = 0.0;
          FMS_DW.condWasTrueAtLastTimeStep_1_j = (FMS_DW.prep_takeoff == 1.0);
          guard2 = true;
        } else {
          b_previousEvent = FMS_DW.sfEvent;
          FMS_DW.sfEvent = FMS_event_DisarmEvent;

          /* Chart: '<Root>/FMS State Machine' */
          FMS_c11_FMS();
          FMS_DW.sfEvent = b_previousEvent;
          if (FMS_DW.is_Vehicle != FMS_IN_Standby) {
          } else {
            guard2 = true;
          }
        }
      } else {
        guard2 = true;
      }

      if (guard2) {
        FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.state = VehicleState_Standby;
      }

      if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
          FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_j = sf_internal_predicateOutput;
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
    FMS_DW.durationLastReferenceTick_2_b = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_f5 = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_i = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2_f = FMS_DW.bl;
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
          FMS_DW.durationLastReferenceTick_2_b = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_f5 =
            FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_i = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_f = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_b = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_f5 =
            FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_i = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_f = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
          FMS_DW.durationLastReferenceTick_1_f5 =
            FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_i = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_f5 > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_f)) {
            FMS_DW.durationLastReferenceTick_2_b =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2_f = FMS_DW.bl;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2_b > 375) {
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
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_f)) {
              FMS_DW.durationLastReferenceTick_2_b =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2_f = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
              FMS_DW.durationLastReferenceTick_1_f5 =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_i = FMS_DW.br;
          }
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_i, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_l[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T B;
  real32_T D;
  real32_T rtb_Square2;
  real32_T rtb_Transpose[9];
  real32_T rtb_MatrixConcatenate3[3];
  real32_T rtb_Multiply[3];
  uint16_T rtb_Divide_b;
  uint8_T rtb_Switch_m;
  int8_T rtPrevAction;
  real32_T rtb_Saturation1_ln[2];
  MotionState rtb_state_a;
  real32_T rtb_Switch_ec[3];
  real32_T rtb_Rem_k;
  real32_T rtb_Gain_a;
  real32_T rtb_Rem_o;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_TmpSignalConversionAtDela_a[2];
  real32_T rtb_VectorConcatenate_dd[9];
  boolean_T rtb_LogicalOperator_e;
  int32_T i;
  boolean_T tmp[3];
  real32_T rtb_Transpose_0[3];
  real32_T tmp_0[3];
  real32_T rtb_MathFunction_iq_idx_0;
  real32_T rtb_MathFunction_h_idx_1;
  real32_T rtb_MathFunction_h_idx_0;
  real32_T rtb_P_d_idx_0;
  real32_T rtb_Divide_l_idx_2;
  real32_T rtb_Divide_l_idx_1;
  boolean_T rtb_Switch_p_idx_1;
  real32_T u1_tmp;
  boolean_T guard1 = false;

  /* Sqrt: '<S448>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S448>/Square'
   *  Sum: '<S448>/Sum of Elements'
   */
  rtb_Square2 = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
                        FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
                       FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) +
                      FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S444>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Rem_k = FMS_U.INS_Out.quat[0] / rtb_Square2;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Square2;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Square2;
  rtb_Gain_a = FMS_U.INS_Out.quat[3] / rtb_Square2;

  /* Math: '<S445>/Square' incorporates:
   *  Math: '<S446>/Square'
   *  Math: '<S447>/Square'
   */
  rtb_MathFunction_h_idx_0 = rtb_Rem_k * rtb_Rem_k;

  /* Math: '<S445>/Square2' incorporates:
   *  Math: '<S446>/Square2'
   *  Math: '<S447>/Square2'
   */
  rtb_MathFunction_h_idx_1 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S445>/Square1' incorporates:
   *  Math: '<S446>/Square1'
   *  Math: '<S447>/Square1'
   */
  rtb_Square2 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S445>/Square3' incorporates:
   *  Math: '<S446>/Square3'
   *  Math: '<S447>/Square3'
   */
  rtb_MathFunction_iq_idx_0 = rtb_Gain_a * rtb_Gain_a;

  /* Sum: '<S445>/Subtract' incorporates:
   *  Math: '<S445>/Square'
   *  Math: '<S445>/Square1'
   *  Math: '<S445>/Square2'
   *  Math: '<S445>/Square3'
   *  Sum: '<S445>/Add'
   *  Sum: '<S445>/Add1'
   */
  rtb_Transpose[0] = (rtb_MathFunction_h_idx_0 + rtb_Square2) -
    (rtb_MathFunction_h_idx_1 + rtb_MathFunction_iq_idx_0);

  /* Product: '<S445>/Multiply' incorporates:
   *  Product: '<S446>/Multiply'
   */
  rtb_P_d_idx_0 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S445>/Multiply1' incorporates:
   *  Product: '<S446>/Multiply1'
   */
  rtb_Rem_o = rtb_Rem_k * rtb_Gain_a;

  /* Gain: '<S445>/Gain' incorporates:
   *  Product: '<S445>/Multiply'
   *  Product: '<S445>/Multiply1'
   *  Sum: '<S445>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_P_d_idx_0 - rtb_Rem_o) * 2.0F;

  /* Product: '<S445>/Multiply2' incorporates:
   *  Product: '<S447>/Multiply'
   */
  B = rtb_Divide_l_idx_1 * rtb_Gain_a;

  /* Product: '<S445>/Multiply3' incorporates:
   *  Product: '<S447>/Multiply1'
   */
  D = rtb_Rem_k * rtb_Divide_l_idx_2;

  /* Gain: '<S445>/Gain1' incorporates:
   *  Product: '<S445>/Multiply2'
   *  Product: '<S445>/Multiply3'
   *  Sum: '<S445>/Add2'
   */
  rtb_Transpose[2] = (B + D) * 2.0F;

  /* Gain: '<S446>/Gain' incorporates:
   *  Sum: '<S446>/Add3'
   */
  rtb_Transpose[3] = (rtb_P_d_idx_0 + rtb_Rem_o) * 2.0F;

  /* Sum: '<S446>/Subtract' incorporates:
   *  Sum: '<S446>/Add'
   *  Sum: '<S446>/Add1'
   */
  rtb_Transpose[4] = (rtb_MathFunction_h_idx_0 + rtb_MathFunction_h_idx_1) -
    (rtb_Square2 + rtb_MathFunction_iq_idx_0);

  /* Product: '<S446>/Multiply2' incorporates:
   *  Product: '<S447>/Multiply2'
   */
  rtb_P_d_idx_0 = rtb_Divide_l_idx_2 * rtb_Gain_a;

  /* Product: '<S446>/Multiply3' incorporates:
   *  Product: '<S447>/Multiply3'
   */
  rtb_Rem_o = rtb_Rem_k * rtb_Divide_l_idx_1;

  /* Gain: '<S446>/Gain1' incorporates:
   *  Product: '<S446>/Multiply2'
   *  Product: '<S446>/Multiply3'
   *  Sum: '<S446>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_P_d_idx_0 - rtb_Rem_o) * 2.0F;

  /* Gain: '<S447>/Gain' incorporates:
   *  Sum: '<S447>/Subtract2'
   */
  rtb_Transpose[6] = (B - D) * 2.0F;

  /* Gain: '<S447>/Gain1' incorporates:
   *  Sum: '<S447>/Add2'
   */
  rtb_Transpose[7] = (rtb_P_d_idx_0 + rtb_Rem_o) * 2.0F;

  /* Sum: '<S447>/Subtract' incorporates:
   *  Sum: '<S447>/Add'
   *  Sum: '<S447>/Add1'
   */
  rtb_Transpose[8] = (rtb_MathFunction_h_idx_0 + rtb_MathFunction_iq_idx_0) -
    (rtb_Square2 + rtb_MathFunction_h_idx_1);

  /* Math: '<S5>/Transpose' */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_dd[3 * i] = rtb_Transpose[i];
    rtb_VectorConcatenate_dd[1 + 3 * i] = rtb_Transpose[i + 3];
    rtb_VectorConcatenate_dd[2 + 3 * i] = rtb_Transpose[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_Transpose[i] = rtb_VectorConcatenate_dd[i];
  }

  /* End of Math: '<S5>/Transpose' */

  /* Product: '<S5>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply[i] = rtb_Transpose[i + 6] * FMS_U.INS_Out.az + (rtb_Transpose[i
      + 3] * FMS_U.INS_Out.ay + rtb_Transpose[i] * FMS_U.INS_Out.ax);
  }

  /* End of Product: '<S5>/Multiply' */

  /* DiscreteIntegrator: '<S440>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Multiply[0];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply[1];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply[2];
  }

  /* Product: '<S5>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S5>/Sum of Elements'
   */
  rtb_Divide_b = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S441>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S441>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  Constant: '<S439>/Constant'
   *  DiscreteIntegrator: '<S440>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S441>/Discrete-Time Integrator5'
   *  Logic: '<S442>/AND'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S439>/Compare'
   *  RelationalOperator: '<S442>/Lower Test'
   *  RelationalOperator: '<S442>/Upper Test'
   */
  FMS_B.on_ground = ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] <= 0.5F) &&
                     ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] <= 0.5F)) &&
                     ((-10.306F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] <= -9.306F)) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTAT_d < 1250.0F));

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
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0U;
  }

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  DataTypeConversion: '<S13>/Data Type Conversion2'
   *  Delay: '<S13>/Delay'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S13>/Logical Operator1'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S20>/FixPt Relational Operator'
   *  Switch: '<S13>/Switch1'
   *  UnitDelay: '<S20>/Delay Input1'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTATE <
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

  /* Switch: '<S12>/Switch1' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S16>/FixPt Relational Operator'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  Switch: '<S12>/Switch2'
   *  UnitDelay: '<S16>/Delay Input1'
   *  UnitDelay: '<S17>/Delay Input1'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S12>/Switch2' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion1'
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;
  } else {
    /* Switch: '<S12>/Switch2' incorporates:
     *  Constant: '<S12>/Constant1'
     */
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_3' incorporates:
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
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 0U;
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
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE < 500U) &&
    (rtb_Switch_m != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_l)) {
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_l = FMS_B.on_ground;
  rtb_Switch_p_idx_1 = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_Switch_p_idx_1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
    FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_j = rtb_Switch_p_idx_1;
  rtb_Switch_p_idx_1 = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_Switch_p_idx_1) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_Switch_p_idx_1;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_a)) {
    FMS_DW.durationLastReferenceTick_1_o = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_a = FMS_B.on_ground;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_i)) {
    FMS_DW.durationLastReferenceTick_1_f5 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_i = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_f)) {
    FMS_DW.durationLastReferenceTick_2_b = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2_f = FMS_DW.bl;
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
  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  /* SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_MatrixConcatenate3[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_MatrixConcatenate3[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_MatrixConcatenate3[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

  /* SwitchCase: '<S21>/Switch Case' incorporates:
   *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy6Inport1'
   */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;

  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S23>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S30>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S385>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S375>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S331>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S309>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S319>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S28>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S136>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S181>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S171>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S136>/Mission_SubSystem' */
      }

      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S27>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 4:
        break;

       case 1:
        /* Disable for SwitchCase: '<S123>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S42>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S59>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S99>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S75>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S86>/Switch Case' */
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

    /* End of Disable for SwitchCase: '<S23>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S21>/Disarm' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S24>/Bus Assignment'
     */
    FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Disarm);

    /* End of Outputs for SubSystem: '<S21>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S21>/Standby' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S24>/Bus Assignment'
     *  BusAssignment: '<S26>/Bus Assignment'
     *  Constant: '<S26>/Constant'
     *  SignalConversion: '<S26>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S26>/Bus Assignment' incorporates:
     *  BusAssignment: '<S24>/Bus Assignment'
     *  Constant: '<S26>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;
    FMS_Y.FMS_Out.actuator_cmd[0] = 1150U;
    FMS_Y.FMS_Out.actuator_cmd[1] = 1150U;
    FMS_Y.FMS_Out.actuator_cmd[2] = 1150U;
    FMS_Y.FMS_Out.actuator_cmd[3] = 1150U;
    for (i = 0; i < 12; i++) {
      FMS_Y.FMS_Out.actuator_cmd[i + 4] = 0U;
    }

    /* End of Outputs for SubSystem: '<S21>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S21>/Arm' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* SwitchCase: '<S23>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;

    /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

    /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S30>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S385>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S375>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S331>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S309>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S319>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S28>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S136>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S181>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S171>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S136>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S27>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S123>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S42>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S59>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S99>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S75>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S86>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S23>/SubMode' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      /* SwitchCase: '<S30>/Switch Case' incorporates:
       *  Math: '<S407>/Math Function'
       *  Product: '<S409>/Divide'
       *  Sum: '<S370>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_at;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_at) {
        switch (rtPrevAction) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S385>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S375>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S331>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S309>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S319>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S30>/Takeoff' incorporates:
         *  ActionPort: '<S304>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S422>/Sum2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S416>/Sum'
         */
        rtb_Divide_l_idx_2 = FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2];

        /* Product: '<S422>/Divide' incorporates:
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S422>/Sum1'
         *  Sum: '<S422>/Sum2'
         */
        rtb_Divide_l_idx_1 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_l_idx_2;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S422>/Saturation' */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Divide_l_idx_1 = 0.0F;
          }
        }

        /* End of Saturate: '<S422>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S423>/Trigonometric Function1' incorporates:
         *  Gain: '<S421>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Trigonometry: '<S423>/Trigonometric Function3'
         */
        rtb_MathFunction_h_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S423>/Trigonometric Function' incorporates:
         *  Gain: '<S421>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Trigonometry: '<S423>/Trigonometric Function2'
         */
        rtb_MathFunction_h_idx_1 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

        /* SignalConversion: '<S423>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S423>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S423>/Gain' */
        rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S423>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

        /* SignalConversion: '<S423>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S423>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S423>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S417>/Saturation1' */
        rtb_Rem_k = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_MathFunction_iq_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* SignalConversion: '<S417>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S422>/Multiply'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S417>/Sum'
         *  Sum: '<S422>/Sum3'
         *  Sum: '<S422>/Sum4'
         */
        rtb_Square2 = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
                        [0]) * rtb_Divide_l_idx_1 + FMS_B.Cmd_In.cur_waypoint[0])
          - FMS_U.INS_Out.x_R;
        rtb_Gain_a = ((FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1])
                      * rtb_Divide_l_idx_1 + FMS_B.Cmd_In.cur_waypoint[1]) -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S417>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_Gain_a +
            rtb_Transpose[i] * rtb_Square2;
        }

        /* Saturate: '<S417>/Saturation1' incorporates:
         *  Gain: '<S417>/Gain2'
         *  Product: '<S417>/Multiply'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Square2 = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  BusAssignment: '<S304>/Bus Assignment1'
         *  Constant: '<S304>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S304>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Constant: '<S304>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S417>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Rem_k) {
          /* BusAssignment: '<S304>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else if (rtb_Divide_l_idx_1 < rtb_MathFunction_iq_idx_0) {
          /* BusAssignment: '<S304>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_iq_idx_0;
        } else {
          /* BusAssignment: '<S304>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_Square2 > rtb_Rem_k) {
          /* BusAssignment: '<S304>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else if (rtb_Square2 < rtb_MathFunction_iq_idx_0) {
          /* BusAssignment: '<S304>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_iq_idx_0;
        } else {
          /* BusAssignment: '<S304>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Square2;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S416>/Switch' incorporates:
         *  Abs: '<S416>/Abs'
         *  Abs: '<S416>/Abs1'
         *  Constant: '<S418>/Constant'
         *  Constant: '<S419>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S416>/Logical Operator'
         *  RelationalOperator: '<S418>/Compare'
         *  RelationalOperator: '<S419>/Compare'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S416>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(rtb_Divide_l_idx_2) > 2.0F)) {
          /* BusAssignment: '<S304>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Constant: '<S416>/Constant6'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -1.0F;
        } else {
          /* BusAssignment: '<S304>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Constant: '<S416>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -0.5F;
        }

        /* End of Switch: '<S416>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S30>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S30>/Land' incorporates:
         *  ActionPort: '<S302>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S348>/Trigonometric Function1' incorporates:
         *  Gain: '<S347>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S348>/Trigonometric Function' incorporates:
         *  Gain: '<S347>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SignalConversion: '<S348>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S348>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S348>/Gain' incorporates:
         *  Gain: '<S347>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Trigonometry: '<S348>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S348>/Trigonometric Function3' incorporates:
         *  Gain: '<S347>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SignalConversion: '<S348>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S348>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S348>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S344>/Saturation1' */
        rtb_Divide_l_idx_2 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Rem_k = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* SignalConversion: '<S345>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S345>/Sum'
         */
        rtb_Square2 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Gain_a = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S345>/Multiply' incorporates:
         *  SignalConversion: '<S345>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_Gain_a +
            rtb_Transpose[i] * rtb_Square2;
        }

        /* End of Product: '<S345>/Multiply' */

        /* Saturate: '<S344>/Saturation1' incorporates:
         *  Gain: '<S345>/Gain2'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Square2 = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  BusAssignment: '<S302>/Bus Assignment1'
         *  Constant: '<S302>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S302>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Constant: '<S302>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S344>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Divide_l_idx_2) {
          /* BusAssignment: '<S302>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_2;
        } else if (rtb_Divide_l_idx_1 < rtb_Rem_k) {
          /* BusAssignment: '<S302>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S302>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_Square2 > rtb_Divide_l_idx_2) {
          /* BusAssignment: '<S302>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_2;
        } else if (rtb_Square2 < rtb_Rem_k) {
          /* BusAssignment: '<S302>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S302>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Square2;
        }

        /* BusAssignment: '<S302>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Constant: '<S302>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S30>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S30>/Return' incorporates:
           *  ActionPort: '<S303>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S30>/Switch Case' incorporates:
           *  Delay: '<S351>/Delay'
           *  Delay: '<S352>/Delay'
           *  Delay: '<S371>/Delay'
           *  DiscreteIntegrator: '<S355>/Integrator'
           *  DiscreteIntegrator: '<S355>/Integrator1'
           *  DiscreteIntegrator: '<S412>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_o = 1U;
          FMS_DW.l1_heading_p = 0.0F;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S30>/Return' */

          /* SystemReset for IfAction SubSystem: '<S30>/Return' incorporates:
           *  ActionPort: '<S303>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S30>/Switch Case' incorporates:
           *  Chart: '<S376>/Motion Status'
           *  Chart: '<S386>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S30>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S30>/Return' incorporates:
         *  ActionPort: '<S303>/Action Port'
         */
        /* Delay: '<S371>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        if (FMS_DW.icLoad_o != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S367>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];
        rtb_MathFunction_iq_idx_0 = FMS_U.INS_Out.y_R -
          FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sqrt: '<S372>/Sqrt' incorporates:
         *  Math: '<S372>/Square'
         *  Sum: '<S367>/Sum'
         *  Sum: '<S372>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

        /* Switch: '<S367>/Switch' incorporates:
         *  Constant: '<S367>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Divide_l_idx_2 = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S367>/Gain' */
          rtb_Divide_l_idx_2 = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S367>/Saturation' */
          if (rtb_Divide_l_idx_2 > FMS_PARAM.CRUISE_SPEED) {
            rtb_Divide_l_idx_2 = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Divide_l_idx_2 < 0.5F) {
              rtb_Divide_l_idx_2 = 0.5F;
            }
          }

          /* End of Saturate: '<S367>/Saturation' */
        }

        /* End of Switch: '<S367>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S386>/Motion State' incorporates:
         *  Constant: '<S386>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S386>/Square'
         *  Math: '<S386>/Square1'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sqrt: '<S386>/Sqrt'
         *  Sum: '<S386>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S385>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S385>/Hold Control' incorporates:
             *  ActionPort: '<S388>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S385>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S385>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S385>/Hold Control' incorporates:
           *  ActionPort: '<S388>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_mv,
                            &FMS_ConstB.HoldControl_k, &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S385>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S385>/Brake Control' incorporates:
           *  ActionPort: '<S387>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_mv);

          /* End of Outputs for SubSystem: '<S385>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S385>/Move Control' incorporates:
             *  ActionPort: '<S389>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S385>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S385>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S385>/Move Control' incorporates:
           *  ActionPort: '<S389>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_mv,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S385>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S385>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S376>/Motion Status' incorporates:
         *  Abs: '<S376>/Abs'
         *  Constant: '<S376>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S375>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S375>/Hold Control' incorporates:
             *  ActionPort: '<S378>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S375>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S375>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S375>/Hold Control' incorporates:
           *  ActionPort: '<S378>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S375>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S375>/Brake Control' incorporates:
           *  ActionPort: '<S377>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S375>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S375>/Move Control' incorporates:
             *  ActionPort: '<S379>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S375>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S375>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S375>/Move Control' incorporates:
           *  ActionPort: '<S379>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S375>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S375>/Switch Case' */

        /* Delay: '<S351>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S303>/Sum' incorporates:
         *  Delay: '<S351>/Delay'
         *  MATLAB Function: '<S369>/OutRegionRegWP'
         *  MATLAB Function: '<S369>/SearchL1RefWP'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_MathFunction_iq_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S366>/Sum of Elements' incorporates:
         *  Math: '<S366>/Math Function'
         *  Sum: '<S303>/Sum'
         */
        rtb_Gain_a = rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0 +
          rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Math: '<S366>/Math Function1' incorporates:
         *  Sum: '<S366>/Sum of Elements'
         *
         * About '<S366>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_a < 0.0F) {
          rtb_Square2 = -sqrtf(fabsf(rtb_Gain_a));
        } else {
          rtb_Square2 = sqrtf(rtb_Gain_a);
        }

        /* End of Math: '<S366>/Math Function1' */

        /* Switch: '<S366>/Switch' incorporates:
         *  Constant: '<S366>/Constant'
         *  Product: '<S366>/Product'
         *  Sum: '<S303>/Sum'
         */
        if (rtb_Square2 > 0.0F) {
          rtb_Switch_ec[0] = rtb_MathFunction_iq_idx_0;
          rtb_Switch_ec[1] = rtb_P_d_idx_0;
          rtb_Switch_ec[2] = rtb_Square2;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S366>/Switch' */

        /* Product: '<S366>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S364>/Subtract' incorporates:
         *  Product: '<S364>/Multiply'
         *  Product: '<S364>/Multiply1'
         */
        rtb_Square2 = rtb_Saturation1_ln[0] * FMS_ConstB.Divide_d[1] -
          rtb_Saturation1_ln[1] * FMS_ConstB.Divide_d[0];

        /* Signum: '<S353>/Sign1' */
        if (rtb_Square2 < 0.0F) {
          rtb_Square2 = -1.0F;
        } else {
          if (rtb_Square2 > 0.0F) {
            rtb_Square2 = 1.0F;
          }
        }

        /* End of Signum: '<S353>/Sign1' */

        /* Switch: '<S353>/Switch2' incorporates:
         *  Constant: '<S353>/Constant4'
         */
        if (rtb_Square2 == 0.0F) {
          rtb_Square2 = 1.0F;
        }

        /* End of Switch: '<S353>/Switch2' */

        /* DotProduct: '<S353>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide_d[0] * rtb_Saturation1_ln[0] +
          FMS_ConstB.Divide_d[1] * rtb_Saturation1_ln[1];

        /* Trigonometry: '<S353>/Acos' incorporates:
         *  DotProduct: '<S353>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S353>/Multiply' incorporates:
         *  Trigonometry: '<S353>/Acos'
         */
        rtb_Square2 *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S357>/Rem' incorporates:
         *  Constant: '<S357>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sum: '<S352>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_Square2 - FMS_U.INS_Out.psi,
          6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S357>/Switch' incorporates:
         *  Abs: '<S357>/Abs'
         *  Constant: '<S357>/Constant'
         *  Constant: '<S363>/Constant'
         *  Product: '<S357>/Multiply'
         *  RelationalOperator: '<S363>/Compare'
         *  Sum: '<S357>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S357>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Gain_a = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Gain_a = 1.0F;
          } else {
            rtb_Gain_a = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S357>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Gain_a;
        }

        /* End of Switch: '<S357>/Switch' */

        /* Abs: '<S350>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S350>/Switch' incorporates:
         *  Product: '<S371>/Multiply'
         *  Sum: '<S371>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S385>/Saturation1' */
          if (FMS_B.Merge_mv[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_ec[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_ec[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_ec[0] = FMS_B.Merge_mv[0];
          }

          if (FMS_B.Merge_mv[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_ec[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_ec[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_ec[1] = FMS_B.Merge_mv[1];
          }

          /* End of Saturate: '<S385>/Saturation1' */

          /* Saturate: '<S375>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S375>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S371>/Sum' incorporates:
           *  Delay: '<S371>/Delay'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S413>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_ec[0] = rtb_Divide_l_idx_1;
          rtb_Saturation1_ln[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S371>/Sum' incorporates:
           *  Delay: '<S371>/Delay'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S415>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S415>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S414>/Gain' incorporates:
           *  DiscreteIntegrator: '<S412>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  Sum: '<S412>/Add'
           */
          rtb_Gain_a = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_p);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Trigonometry: '<S415>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S415>/Trigonometric Function1'
           */
          rtb_MathFunction_h_idx_0 = arm_cos_f32(rtb_Gain_a);
          rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

          /* Trigonometry: '<S415>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S415>/Trigonometric Function'
           */
          rtb_MathFunction_h_idx_1 = arm_sin_f32(rtb_Gain_a);

          /* Gain: '<S415>/Gain' incorporates:
           *  Trigonometry: '<S415>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

          /* SignalConversion: '<S415>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S415>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S415>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

          /* Trigonometry: '<S415>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

          /* SignalConversion: '<S415>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_k[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_k[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_k[2];

          /* Sum: '<S413>/Sum of Elements' incorporates:
           *  Math: '<S413>/Math Function'
           */
          rtb_Gain_a = rtb_Switch_ec[0] * rtb_Switch_ec[0] + rtb_Divide_l_idx_1 *
            rtb_Divide_l_idx_1;

          /* Math: '<S413>/Math Function1' incorporates:
           *  Sum: '<S413>/Sum of Elements'
           *
           * About '<S413>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain_a < 0.0F) {
            rtb_Gain_a = -sqrtf(fabsf(rtb_Gain_a));
          } else {
            rtb_Gain_a = sqrtf(rtb_Gain_a);
          }

          /* End of Math: '<S413>/Math Function1' */

          /* Switch: '<S413>/Switch' incorporates:
           *  Constant: '<S413>/Constant'
           *  Product: '<S413>/Product'
           */
          if (rtb_Gain_a > 0.0F) {
            rtb_Rem_k = rtb_Saturation1_ln[0];
          } else {
            rtb_Rem_k = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Gain_a = 1.0F;
          }

          /* End of Switch: '<S413>/Switch' */

          /* Product: '<S411>/Multiply2' incorporates:
           *  Product: '<S413>/Divide'
           */
          rtb_Rem_k = rtb_Rem_k / rtb_Gain_a * rtb_Divide_l_idx_2;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_Gain_a *
            rtb_Divide_l_idx_2;
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[i] * rtb_Rem_k;
          }
        }

        /* End of Switch: '<S350>/Switch' */

        /* Delay: '<S352>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S355>/Integrator1' incorporates:
         *  Delay: '<S352>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S359>/Rem' incorporates:
         *  Constant: '<S359>/Constant1'
         *  DiscreteIntegrator: '<S355>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sum: '<S354>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S359>/Switch' incorporates:
         *  Abs: '<S359>/Abs'
         *  Constant: '<S359>/Constant'
         *  Constant: '<S360>/Constant'
         *  Product: '<S359>/Multiply'
         *  RelationalOperator: '<S360>/Compare'
         *  Sum: '<S359>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S359>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_k;
          }

          /* End of Signum: '<S359>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S359>/Switch' */

        /* Gain: '<S354>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S354>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S354>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  BusAssignment: '<S303>/Bus Assignment1'
         *  Constant: '<S303>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S303>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_ec[0];
        FMS_Y.FMS_Out.v_cmd = rtb_Switch_ec[1];
        FMS_Y.FMS_Out.w_cmd = rtb_Switch_ec[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S406>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S406>/Math Function'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sum: '<S404>/Sum of Elements'
         */
        rtb_Gain_a = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S406>/Math Function1' incorporates:
         *  Sum: '<S406>/Sum of Elements'
         *
         * About '<S406>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_a < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Gain_a));
        } else {
          rtb_Rem_k = sqrtf(rtb_Gain_a);
        }

        /* End of Math: '<S406>/Math Function1' */

        /* Switch: '<S406>/Switch' incorporates:
         *  Constant: '<S406>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S406>/Product'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        if (rtb_Rem_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_ec[0] = FMS_U.INS_Out.vn;
          rtb_Switch_ec[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_ec[2] = rtb_Rem_k;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S406>/Switch' */

        /* Product: '<S406>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S409>/Sum of Elements' incorporates:
         *  Math: '<S409>/Math Function'
         *  SignalConversion: '<S409>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Saturation1_ln[1] * rtb_Saturation1_ln[1] +
          rtb_Saturation1_ln[0] * rtb_Saturation1_ln[0];

        /* Math: '<S409>/Math Function1' incorporates:
         *  Sum: '<S409>/Sum of Elements'
         *
         * About '<S409>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S409>/Math Function1' */

        /* Switch: '<S409>/Switch' incorporates:
         *  Constant: '<S409>/Constant'
         *  Product: '<S409>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_Switch_ec[0] = rtb_Saturation1_ln[1];
          rtb_Switch_ec[1] = rtb_Saturation1_ln[0];
          rtb_Switch_ec[2] = rtb_Rem_k;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S409>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S369>/NearbyRefWP' incorporates:
         *  Constant: '<S303>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Saturation1_ln,
                        &rtb_Rem_o);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* MATLAB Function: '<S369>/SearchL1RefWP' incorporates:
         *  Constant: '<S303>/L1'
         *  Delay: '<S351>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_Rem_k = rtb_P_d_idx_0 * rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        B = (rtb_P_d_idx_0 * (FMS_DW.Delay_DSTATE_p[0] - FMS_U.INS_Out.x_R) +
             rtb_MathFunction_iq_idx_0 * (FMS_DW.Delay_DSTATE_p[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Rem_k);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Divide_l_idx_1 = -1.0F;
        rtb_MathFunction_h_idx_0 = 0.0F;
        rtb_MathFunction_h_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Rem_k);
          rtb_Rem_k = (-B - u1_tmp) / (2.0F * rtb_Rem_k);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Rem_k >= 0.0F) && (rtb_Rem_k <=
               1.0F)) {
            rtb_Divide_l_idx_1 = fmaxf(D, rtb_Rem_k);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Divide_l_idx_1 = D;
            guard1 = true;
          } else {
            if ((rtb_Rem_k >= 0.0F) && (rtb_Rem_k <= 1.0F)) {
              rtb_Divide_l_idx_1 = rtb_Rem_k;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Rem_k);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Divide_l_idx_1 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_MathFunction_h_idx_0 = rtb_P_d_idx_0 * rtb_Divide_l_idx_1 +
            FMS_DW.Delay_DSTATE_p[0];
          rtb_MathFunction_h_idx_1 = rtb_MathFunction_iq_idx_0 *
            rtb_Divide_l_idx_1 + FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S369>/OutRegionRegWP' incorporates:
         *  Delay: '<S351>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_k = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
                     rtb_MathFunction_iq_idx_0 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE_p[0]) * rtb_P_d_idx_0) / (rtb_P_d_idx_0 *
          rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Switch_p_idx_1 = (rtb_Rem_k <= 0.0F);
        rtb_LogicalOperator_e = (rtb_Rem_k >= 1.0F);
        if (rtb_Switch_p_idx_1) {
          rtb_P_d_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_e) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else {
          rtb_P_d_idx_0 = rtb_Rem_k * rtb_P_d_idx_0 + FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S369>/Switch1' incorporates:
         *  Constant: '<S399>/Constant'
         *  RelationalOperator: '<S399>/Compare'
         */
        if (rtb_Rem_o <= 0.0F) {
          /* Switch: '<S369>/Switch' incorporates:
           *  Constant: '<S398>/Constant'
           *  MATLAB Function: '<S369>/SearchL1RefWP'
           *  RelationalOperator: '<S398>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;
            rtb_Saturation1_ln[1] = rtb_MathFunction_h_idx_1;
          } else {
            rtb_Saturation1_ln[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S369>/OutRegionRegWP' incorporates:
             *  Delay: '<S351>/Delay'
             *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Switch_p_idx_1) {
              rtb_Saturation1_ln[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_e) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_Saturation1_ln[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            } else {
              rtb_Saturation1_ln[1] = rtb_Rem_k * rtb_MathFunction_iq_idx_0 +
                FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S369>/Switch' */
        }

        /* End of Switch: '<S369>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S370>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S370>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S407>/Math Function'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S407>/Math Function' incorporates:
         *  Math: '<S405>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Sum: '<S407>/Sum of Elements' incorporates:
         *  Math: '<S407>/Math Function'
         */
        rtb_Rem_k = rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S407>/Math Function1' incorporates:
         *  Sum: '<S407>/Sum of Elements'
         *
         * About '<S407>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S407>/Math Function1' */

        /* Switch: '<S407>/Switch' incorporates:
         *  Constant: '<S407>/Constant'
         *  Product: '<S407>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Saturation1_ln[0];
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_h_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Rem_k;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S407>/Switch' */

        /* Product: '<S407>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S410>/Sum of Elements' incorporates:
         *  Math: '<S410>/Math Function'
         *  SignalConversion: '<S410>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_k = rtb_P_d_idx_0 * rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;

        /* Math: '<S410>/Math Function1' incorporates:
         *  Sum: '<S410>/Sum of Elements'
         *
         * About '<S410>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S410>/Math Function1' */

        /* Switch: '<S410>/Switch' incorporates:
         *  Constant: '<S410>/Constant'
         *  Product: '<S410>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_P_d_idx_0;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_iq_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Rem_k;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S410>/Switch' */

        /* Product: '<S410>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S405>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Saturation1_ln[0] *
          rtb_Saturation1_ln[0];
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];

        /* Product: '<S410>/Divide' incorporates:
         *  Product: '<S409>/Divide'
         */
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S409>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sqrt: '<S404>/Sqrt' */
        rtb_Rem_k = sqrtf(rtb_Gain_a);

        /* Gain: '<S370>/Gain' incorporates:
         *  Math: '<S370>/Square'
         */
        rtb_Gain_a = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S408>/Subtract' incorporates:
         *  Product: '<S408>/Multiply'
         *  Product: '<S408>/Multiply1'
         */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 * rtb_MathFunction_h_idx_0 -
          rtb_P_d_idx_0 * rtb_Saturation1_ln[0];

        /* Signum: '<S403>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S403>/Sign1' */

        /* Switch: '<S403>/Switch2' incorporates:
         *  Constant: '<S403>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S403>/Switch2' */

        /* DotProduct: '<S403>/Dot Product' */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[0] *
          rtb_MathFunction_iq_idx_0 + rtb_MathFunction_h_idx_0 * rtb_P_d_idx_0;

        /* Trigonometry: '<S403>/Acos' incorporates:
         *  DotProduct: '<S403>/Dot Product'
         */
        if (rtb_MathFunction_h_idx_0 > 1.0F) {
          rtb_MathFunction_h_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_h_idx_0 < -1.0F) {
            rtb_MathFunction_h_idx_0 = -1.0F;
          }
        }

        /* Product: '<S403>/Multiply' incorporates:
         *  Trigonometry: '<S403>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_MathFunction_h_idx_0);

        /* Saturate: '<S370>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S370>/Saturation' */

        /* Product: '<S370>/Divide' incorporates:
         *  Constant: '<S303>/L1'
         *  Constant: '<S370>/Constant'
         *  MinMax: '<S370>/Max'
         *  MinMax: '<S370>/Min'
         *  Product: '<S370>/Multiply1'
         *  Sqrt: '<S405>/Sqrt'
         *  Sum: '<S405>/Sum of Elements'
         *  Trigonometry: '<S370>/Sin'
         */
        rtb_Gain_a = arm_sin_f32(rtb_Rem_k) * rtb_Gain_a / fminf(FMS_PARAM.L1,
          fmaxf(sqrtf(rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0]),
                0.5F));

        /* Sum: '<S352>/Sum2' incorporates:
         *  Delay: '<S352>/Delay'
         */
        rtb_Square2 -= FMS_DW.Delay_DSTATE_a;

        /* Math: '<S356>/Rem' incorporates:
         *  Constant: '<S356>/Constant1'
         */
        rtb_Rem_o = rt_remf(rtb_Square2, 6.28318548F);

        /* Switch: '<S356>/Switch' incorporates:
         *  Abs: '<S356>/Abs'
         *  Constant: '<S356>/Constant'
         *  Constant: '<S362>/Constant'
         *  Product: '<S356>/Multiply'
         *  RelationalOperator: '<S362>/Compare'
         *  Sum: '<S356>/Add'
         */
        if (fabsf(rtb_Rem_o) > 3.14159274F) {
          /* Signum: '<S356>/Sign' */
          if (rtb_Rem_o < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_o > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_o;
          }

          /* End of Signum: '<S356>/Sign' */
          rtb_Rem_o -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S356>/Switch' */

        /* Sum: '<S352>/Sum' incorporates:
         *  Delay: '<S352>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Rem_o + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S361>/Multiply1' incorporates:
         *  Constant: '<S361>/const1'
         *  DiscreteIntegrator: '<S355>/Integrator'
         */
        rtb_Rem_o = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S361>/Add' incorporates:
         *  DiscreteIntegrator: '<S355>/Integrator1'
         *  Sum: '<S355>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_e - rtb_Divide_l_idx_1) +
          rtb_Rem_o;

        /* Signum: '<S361>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S361>/Sign' */

        /* Sum: '<S361>/Add2' incorporates:
         *  Abs: '<S361>/Abs'
         *  Gain: '<S361>/Gain'
         *  Gain: '<S361>/Gain1'
         *  Product: '<S361>/Multiply2'
         *  Product: '<S361>/Multiply3'
         *  Sqrt: '<S361>/Sqrt'
         *  Sum: '<S361>/Add1'
         *  Sum: '<S361>/Subtract'
         */
        rtb_Square2 = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_l) *
                             FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Rem_o;

        /* Sum: '<S361>/Add4' */
        rtb_MathFunction_iq_idx_0 = (rtb_Rem_k - rtb_Square2) + rtb_Rem_o;

        /* Sum: '<S361>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_l;

        /* Sum: '<S361>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_l;

        /* Signum: '<S361>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S361>/Sign1' */

        /* Signum: '<S361>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S361>/Sign2' */

        /* Sum: '<S361>/Add5' incorporates:
         *  Gain: '<S361>/Gain2'
         *  Product: '<S361>/Multiply4'
         *  Sum: '<S361>/Subtract2'
         */
        rtb_Square2 += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F *
          rtb_MathFunction_iq_idx_0;

        /* Update for Delay: '<S371>/Delay' */
        FMS_DW.icLoad_o = 0U;

        /* Update for DiscreteIntegrator: '<S412>/Discrete-Time Integrator' incorporates:
         *  Product: '<S371>/Divide1'
         */
        FMS_DW.l1_heading_p += rtb_Gain_a / rtb_Divide_l_idx_2 * 0.004F;

        /* Update for Delay: '<S351>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Update for Delay: '<S352>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S355>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S355>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S361>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Square2 + FMS_ConstB.d_l;

        /* Sum: '<S361>/Subtract3' */
        rtb_Rem_k = rtb_Square2 - FMS_ConstB.d_l;

        /* Signum: '<S361>/Sign5' */
        if (rtb_Square2 < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_Divide_l_idx_2 = rtb_Square2;
        }

        /* End of Signum: '<S361>/Sign5' */

        /* Signum: '<S361>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S361>/Sign3' */

        /* Signum: '<S361>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S361>/Sign4' */

        /* Signum: '<S361>/Sign6' */
        if (rtb_Square2 < 0.0F) {
          rtb_Gain_a = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Gain_a = 1.0F;
        } else {
          rtb_Gain_a = rtb_Square2;
        }

        /* End of Signum: '<S361>/Sign6' */

        /* Update for DiscreteIntegrator: '<S355>/Integrator' incorporates:
         *  Constant: '<S361>/const'
         *  Gain: '<S361>/Gain3'
         *  Product: '<S361>/Divide'
         *  Product: '<S361>/Multiply5'
         *  Product: '<S361>/Multiply6'
         *  Sum: '<S361>/Subtract4'
         *  Sum: '<S361>/Subtract5'
         *  Sum: '<S361>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Square2 / FMS_ConstB.d_l -
          rtb_Divide_l_idx_2) * FMS_ConstB.Gain4_np * ((rtb_Divide_l_idx_1 -
          rtb_Rem_k) * 0.5F) - rtb_Gain_a * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S355>/Integrator' */
        /* End of Outputs for SubSystem: '<S30>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S30>/Hold' incorporates:
           *  ActionPort: '<S301>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S30>/Switch Case' incorporates:
           *  Chart: '<S310>/Motion Status'
           *  Chart: '<S320>/Motion State'
           *  Chart: '<S332>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S30>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S30>/Hold' incorporates:
         *  ActionPort: '<S301>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S310>/Motion Status' incorporates:
         *  Abs: '<S310>/Abs'
         *  Constant: '<S310>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S320>/Motion State' incorporates:
         *  Abs: '<S320>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
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

            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_a >=
                 250U)) {
              FMS_DW.is_c15_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
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

        /* End of Chart: '<S320>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S332>/Motion State' incorporates:
         *  Constant: '<S332>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S332>/Square'
         *  Math: '<S332>/Square1'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sqrt: '<S332>/Sqrt'
         *  Sum: '<S332>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S331>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S331>/Hold Control' incorporates:
             *  ActionPort: '<S334>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S331>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S331>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S331>/Hold Control' incorporates:
           *  ActionPort: '<S334>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S331>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S331>/Brake Control' incorporates:
           *  ActionPort: '<S333>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S331>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S331>/Move Control' incorporates:
             *  ActionPort: '<S335>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S331>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S331>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S331>/Move Control' incorporates:
           *  ActionPort: '<S335>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S331>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S331>/Switch Case' */

        /* SwitchCase: '<S309>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S309>/Hold Control' incorporates:
             *  ActionPort: '<S312>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S309>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S309>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S309>/Hold Control' incorporates:
           *  ActionPort: '<S312>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S309>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S309>/Brake Control' incorporates:
           *  ActionPort: '<S311>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S309>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S309>/Move Control' incorporates:
             *  ActionPort: '<S313>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S309>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S309>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S309>/Move Control' incorporates:
           *  ActionPort: '<S313>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S309>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S309>/Switch Case' */

        /* SwitchCase: '<S319>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S319>/Hold Control' incorporates:
             *  ActionPort: '<S322>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S319>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_kq);

            /* End of SystemReset for SubSystem: '<S319>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S319>/Hold Control' incorporates:
           *  ActionPort: '<S322>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                             &FMS_DW.HoldControl_kq);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S319>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S319>/Brake Control' incorporates:
           *  ActionPort: '<S321>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S319>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S319>/Move Control' incorporates:
             *  ActionPort: '<S323>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S319>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S319>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S319>/Move Control' incorporates:
           *  ActionPort: '<S323>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S319>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S319>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  BusAssignment: '<S301>/Bus Assignment'
         *  Constant: '<S301>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S301>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S319>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S319>/Saturation' */

        /* Saturate: '<S331>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S331>/Saturation1' */

        /* Saturate: '<S309>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S309>/Saturation1' */
        /* End of Outputs for SubSystem: '<S30>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S30>/Unknown' incorporates:
         *  ActionPort: '<S305>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S30>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S30>/Switch Case' */
      /* End of Outputs for SubSystem: '<S23>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S23>/Auto' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      /* SwitchCase: '<S28>/Switch Case' incorporates:
       *  Math: '<S201>/Square'
       *  Math: '<S203>/Math Function'
       *  Sum: '<S163>/Subtract'
       *  Sum: '<S215>/Sum1'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_i) && (rtPrevAction
           == 1)) {
        /* Disable for Resettable SubSystem: '<S136>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S181>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S171>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S136>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S28>/Offboard' incorporates:
         *  ActionPort: '<S137>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MultiPortSwitch: '<S275>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S281>/Multiply1'
         *  SignalConversion: '<S22>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S287>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S287>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S287>/Trigonometric Function3' incorporates:
           *  Gain: '<S286>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S287>/Gain' incorporates:
           *  Gain: '<S286>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  Trigonometry: '<S287>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S287>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S287>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S287>/Trigonometric Function' incorporates:
           *  Gain: '<S286>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S287>/Trigonometric Function1' incorporates:
           *  Gain: '<S286>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S287>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S281>/Saturation' incorporates:
           *  Constant: '<S285>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S281>/Multiply'
           *  RelationalOperator: '<S285>/Compare'
           *  S-Function (sfix_bitop): '<S280>/x_cmd valid'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  Sum: '<S281>/Sum1'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U ?
            FMS_U.Auto_Cmd.x_cmd - FMS_U.INS_Out.x_R : 0.0F;
          if (rtb_Divide_l_idx_1 > 4.0F) {
            rtb_Divide_l_idx_1 = 4.0F;
          } else {
            if (rtb_Divide_l_idx_1 < -4.0F) {
              rtb_Divide_l_idx_1 = -4.0F;
            }
          }

          /* SignalConversion: '<S287>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S281>/Saturation' incorporates:
           *  Constant: '<S285>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S281>/Multiply'
           *  RelationalOperator: '<S285>/Compare'
           *  S-Function (sfix_bitop): '<S280>/y_cmd valid'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  Sum: '<S281>/Sum1'
           */
          rtb_Square2 = (FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U ?
            FMS_U.Auto_Cmd.y_cmd - FMS_U.INS_Out.y_R : 0.0F;
          if (rtb_Square2 > 4.0F) {
            rtb_Square2 = 4.0F;
          } else {
            if (rtb_Square2 < -4.0F) {
              rtb_Square2 = -4.0F;
            }
          }

          /* SignalConversion: '<S287>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S281>/Saturation' incorporates:
           *  Constant: '<S285>/Constant'
           *  Gain: '<S278>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S281>/Multiply'
           *  RelationalOperator: '<S285>/Compare'
           *  S-Function (sfix_bitop): '<S280>/z_cmd valid'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  Sum: '<S281>/Sum1'
           */
          rtb_Divide_l_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U ?
            FMS_U.Auto_Cmd.z_cmd - (-FMS_U.INS_Out.h_R) : 0.0F;
          if (rtb_Divide_l_idx_2 > 2.0F) {
            rtb_Divide_l_idx_2 = 2.0F;
          } else {
            if (rtb_Divide_l_idx_2 < -2.0F) {
              rtb_Divide_l_idx_2 = -2.0F;
            }
          }

          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] *
              rtb_Divide_l_idx_2 + (rtb_Transpose[i + 3] * rtb_Square2 +
              rtb_Transpose[i] * rtb_Divide_l_idx_1);
          }

          /* SignalConversion: '<S222>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S222>/Constant4'
           *  MultiPortSwitch: '<S212>/Index Vector'
           *  Product: '<S281>/Multiply1'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S222>/Trigonometric Function3' incorporates:
           *  Gain: '<S221>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S212>/Index Vector'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S222>/Gain' incorporates:
           *  Gain: '<S221>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S212>/Index Vector'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  Trigonometry: '<S222>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S222>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S222>/Constant3'
           *  MultiPortSwitch: '<S212>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S222>/Trigonometric Function' incorporates:
           *  Gain: '<S221>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S212>/Index Vector'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S222>/Trigonometric Function1' incorporates:
           *  Gain: '<S221>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S212>/Index Vector'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S222>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S212>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S212>/Multiply' incorporates:
           *  Constant: '<S220>/Constant'
           *  RelationalOperator: '<S220>/Compare'
           *  S-Function (sfix_bitop): '<S217>/ax_cmd valid'
           */
          rtb_Square2 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S222>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S212>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S212>/Multiply' incorporates:
           *  Constant: '<S220>/Constant'
           *  RelationalOperator: '<S220>/Compare'
           *  S-Function (sfix_bitop): '<S217>/ay_cmd valid'
           */
          rtb_Gain_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S222>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S212>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S212>/Multiply' incorporates:
           *  Constant: '<S220>/Constant'
           *  RelationalOperator: '<S220>/Compare'
           *  S-Function (sfix_bitop): '<S217>/az_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S212>/Index Vector' incorporates:
           *  Product: '<S218>/Multiply'
           */
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_Gain_a + rtb_Transpose[i] *
               rtb_Square2);
          }
          break;

         case 1:
          /* SignalConversion: '<S290>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S290>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S290>/Trigonometric Function3' incorporates:
           *  Gain: '<S288>/Gain'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S290>/Trigonometric Function1'
           */
          rtb_MathFunction_h_idx_0 = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
          rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

          /* Trigonometry: '<S290>/Trigonometric Function2' incorporates:
           *  Gain: '<S288>/Gain'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S290>/Trigonometric Function'
           */
          rtb_MathFunction_h_idx_1 = arm_sin_f32(-FMS_B.Cmd_In.offboard_psi_0);

          /* Gain: '<S290>/Gain' incorporates:
           *  Trigonometry: '<S290>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

          /* SignalConversion: '<S290>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S290>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S290>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

          /* Trigonometry: '<S290>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

          /* SignalConversion: '<S290>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S291>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_dd[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S290>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S291>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_dd[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S290>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S291>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_dd[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S291>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S291>/Constant4'
           */
          rtb_VectorConcatenate_dd[5] = 0.0F;

          /* Gain: '<S289>/Gain' incorporates:
           *  Gain: '<S223>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S212>/Index Vector'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S282>/Subtract'
           */
          rtb_Divide_l_idx_2 = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S291>/Trigonometric Function3' incorporates:
           *  Gain: '<S289>/Gain'
           *  Trigonometry: '<S291>/Trigonometric Function1'
           */
          rtb_Divide_l_idx_1 = arm_cos_f32(rtb_Divide_l_idx_2);
          rtb_VectorConcatenate_dd[4] = rtb_Divide_l_idx_1;

          /* Trigonometry: '<S291>/Trigonometric Function2' incorporates:
           *  Gain: '<S289>/Gain'
           *  Trigonometry: '<S291>/Trigonometric Function'
           */
          rtb_Square2 = arm_sin_f32(rtb_Divide_l_idx_2);

          /* Gain: '<S291>/Gain' incorporates:
           *  Trigonometry: '<S291>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_dd[3] = -rtb_Square2;

          /* SignalConversion: '<S291>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S291>/Constant3'
           */
          rtb_VectorConcatenate_dd[2] = 0.0F;

          /* Trigonometry: '<S291>/Trigonometric Function' */
          rtb_VectorConcatenate_dd[1] = rtb_Square2;

          /* Trigonometry: '<S291>/Trigonometric Function1' */
          rtb_VectorConcatenate_dd[0] = rtb_Divide_l_idx_1;

          /* Sum: '<S282>/Sum2' */
          rtb_Transpose_0[0] = FMS_U.Auto_Cmd.x_cmd;
          rtb_Transpose_0[1] = FMS_U.Auto_Cmd.y_cmd;
          rtb_Transpose_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S285>/Compare' incorporates:
           *  Constant: '<S285>/Constant'
           *  S-Function (sfix_bitop): '<S280>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/z_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);
          for (i = 0; i < 3; i++) {
            /* Saturate: '<S282>/Saturation1' incorporates:
             *  Gain: '<S278>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S282>/Multiply'
             *  Product: '<S282>/Multiply2'
             *  SignalConversion: '<S22>/Signal Copy1'
             *  Sum: '<S282>/Sum2'
             */
            rtb_Divide_l_idx_1 = tmp[i] ? rtb_Transpose_0[i] - (rtb_Transpose[i
              + 6] * -FMS_U.INS_Out.h_R + (rtb_Transpose[i + 3] *
              FMS_U.INS_Out.y_R + rtb_Transpose[i] * FMS_U.INS_Out.x_R)) : 0.0F;
            if (rtb_Divide_l_idx_1 > FMS_ConstP.pooled14[i]) {
              rtb_Switch_ec[i] = FMS_ConstP.pooled14[i];
            } else if (rtb_Divide_l_idx_1 < FMS_ConstP.pooled15[i]) {
              rtb_Switch_ec[i] = FMS_ConstP.pooled15[i];
            } else {
              rtb_Switch_ec[i] = rtb_Divide_l_idx_1;
            }

            /* End of Saturate: '<S282>/Saturation1' */
          }

          /* SignalConversion: '<S224>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S224>/Constant4'
           *  MultiPortSwitch: '<S212>/Index Vector'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S224>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S212>/Index Vector'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Divide_l_idx_2);

          /* Gain: '<S224>/Gain' incorporates:
           *  MultiPortSwitch: '<S212>/Index Vector'
           *  Trigonometry: '<S224>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Divide_l_idx_2);

          /* SignalConversion: '<S224>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S224>/Constant3'
           *  MultiPortSwitch: '<S212>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S224>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S212>/Index Vector'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Divide_l_idx_2);

          /* Trigonometry: '<S224>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S212>/Index Vector'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Divide_l_idx_2);

          /* Product: '<S212>/Multiply' */
          rtb_Transpose_0[0] = FMS_U.Auto_Cmd.ax_cmd;
          rtb_Transpose_0[1] = FMS_U.Auto_Cmd.ay_cmd;
          rtb_Transpose_0[2] = FMS_U.Auto_Cmd.az_cmd;

          /* RelationalOperator: '<S220>/Compare' incorporates:
           *  Constant: '<S220>/Constant'
           *  S-Function (sfix_bitop): '<S217>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S217>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S217>/az_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
          for (i = 0; i < 3; i++) {
            /* SignalConversion: '<S224>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S212>/Index Vector'
             */
            rtb_Transpose[i + 6] = FMS_ConstB.VectorConcatenate3_o[i];

            /* Product: '<S212>/Multiply' */
            tmp_0[i] = tmp[i] ? rtb_Transpose_0[i] : 0.0F;
            rtb_MatrixConcatenate3[i] = rtb_VectorConcatenate_dd[i + 6] *
              rtb_Switch_ec[2] + (rtb_VectorConcatenate_dd[i + 3] *
                                  rtb_Switch_ec[1] + rtb_VectorConcatenate_dd[i]
                                  * rtb_Switch_ec[0]);
          }

          /* MultiPortSwitch: '<S212>/Index Vector' incorporates:
           *  Product: '<S219>/Multiply3'
           *  Product: '<S282>/Multiply3'
           */
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 6] * tmp_0[2] +
              (rtb_Transpose[i + 3] * tmp_0[1] + rtb_Transpose[i] * tmp_0[0]);
          }
          break;

         default:
          /* SignalConversion: '<S284>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S284>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S284>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S284>/Trigonometric Function3' incorporates:
           *  Gain: '<S283>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S284>/Gain' incorporates:
           *  Gain: '<S283>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  Trigonometry: '<S284>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S284>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S284>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S284>/Trigonometric Function' incorporates:
           *  Gain: '<S283>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S284>/Trigonometric Function1' incorporates:
           *  Gain: '<S283>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Sum: '<S277>/Sum2' */
          rtb_Transpose_0[0] = FMS_U.Auto_Cmd.x_cmd;
          rtb_Transpose_0[1] = FMS_U.Auto_Cmd.y_cmd;
          rtb_Transpose_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S285>/Compare' incorporates:
           *  Constant: '<S285>/Constant'
           *  S-Function (sfix_bitop): '<S280>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/z_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* Product: '<S277>/Multiply2' */
          for (i = 0; i < 3; i++) {
            /* Saturate: '<S277>/Saturation1' incorporates:
             *  Gain: '<S278>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S277>/Multiply'
             *  SignalConversion: '<S22>/Signal Copy1'
             *  Sum: '<S277>/Sum2'
             */
            rtb_Divide_l_idx_1 = tmp[i] ? rtb_Transpose_0[i] - (rtb_Transpose[i
              + 6] * -FMS_U.INS_Out.h_R + (rtb_Transpose[i + 3] *
              FMS_U.INS_Out.y_R + rtb_Transpose[i] * FMS_U.INS_Out.x_R)) : 0.0F;
            if (rtb_Divide_l_idx_1 > FMS_ConstP.pooled14[i]) {
              rtb_MatrixConcatenate3[i] = FMS_ConstP.pooled14[i];
            } else if (rtb_Divide_l_idx_1 < FMS_ConstP.pooled15[i]) {
              rtb_MatrixConcatenate3[i] = FMS_ConstP.pooled15[i];
            } else {
              rtb_MatrixConcatenate3[i] = rtb_Divide_l_idx_1;
            }

            /* End of Saturate: '<S277>/Saturation1' */
          }

          /* End of Product: '<S277>/Multiply2' */

          /* MultiPortSwitch: '<S212>/Index Vector' incorporates:
           *  Constant: '<S220>/Constant'
           *  Product: '<S212>/Multiply'
           *  RelationalOperator: '<S220>/Compare'
           *  S-Function (sfix_bitop): '<S217>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S217>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S217>/az_cmd valid'
           */
          rtb_Switch_ec[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Switch_ec[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Switch_ec[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S275>/Index Vector' */

        /* Sum: '<S271>/Sum1' incorporates:
         *  Constant: '<S271>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S271>/Math Function'
         *  SignalConversion: '<S22>/Signal Copy'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_Divide_l_idx_2 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Abs: '<S272>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_2);

        /* Switch: '<S272>/Switch' incorporates:
         *  Constant: '<S272>/Constant'
         *  Constant: '<S273>/Constant'
         *  Product: '<S272>/Multiply'
         *  RelationalOperator: '<S273>/Compare'
         *  Sum: '<S272>/Subtract'
         */
        if (rtb_Divide_l_idx_1 > 3.14159274F) {
          /* Signum: '<S272>/Sign' */
          if (rtb_Divide_l_idx_2 < 0.0F) {
            rtb_Divide_l_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_2 > 0.0F) {
              rtb_Divide_l_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S272>/Sign' */
          rtb_Divide_l_idx_2 *= rtb_Divide_l_idx_1 - 6.28318548F;
        }

        /* End of Switch: '<S272>/Switch' */

        /* Saturate: '<S271>/Saturation' */
        if (rtb_Divide_l_idx_2 > 0.314159274F) {
          rtb_Divide_l_idx_2 = 0.314159274F;
        } else {
          if (rtb_Divide_l_idx_2 < -0.314159274F) {
            rtb_Divide_l_idx_2 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S271>/Saturation' */

        /* Gain: '<S268>/Gain2' */
        rtb_Divide_l_idx_2 *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S214>/Sum' incorporates:
         *  Constant: '<S270>/Constant'
         *  Constant: '<S274>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S268>/Multiply2'
         *  Product: '<S269>/Multiply1'
         *  RelationalOperator: '<S270>/Compare'
         *  RelationalOperator: '<S274>/Compare'
         *  S-Function (sfix_bitop): '<S268>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S269>/psi_rate_cmd valid'
         *  SignalConversion: '<S22>/Signal Copy'
         */
        rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                              rtb_Divide_l_idx_2 : 0.0F) +
          ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
           0.0F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S275>/Gain1' */
        rtb_Saturation1_ln[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_Saturation1_ln[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S275>/Gain2' */
        rtb_Divide_l_idx_2 = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MultiPortSwitch: '<S276>/Index Vector' incorporates:
         *  Constant: '<S296>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S276>/Multiply'
         *  Product: '<S294>/Multiply'
         *  Product: '<S295>/Multiply3'
         *  RelationalOperator: '<S296>/Compare'
         *  S-Function (sfix_bitop): '<S293>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S293>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S293>/w_cmd valid'
         *  SignalConversion: '<S22>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S298>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S298>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S298>/Trigonometric Function3' incorporates:
           *  Gain: '<S297>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S298>/Gain' incorporates:
           *  Gain: '<S297>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  Trigonometry: '<S298>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S298>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S298>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S298>/Trigonometric Function' incorporates:
           *  Gain: '<S297>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S298>/Trigonometric Function1' incorporates:
           *  Gain: '<S297>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S298>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S276>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/u_cmd valid'
           */
          rtb_Square2 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S298>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S276>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/v_cmd valid'
           */
          rtb_Gain_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S298>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S276>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/w_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_Gain_a + rtb_Transpose[i] *
               rtb_Square2);
          }
          break;

         case 1:
          /* SignalConversion: '<S300>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S300>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S299>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S295>/Subtract'
           */
          rtb_Square2 = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S300>/Trigonometric Function3' incorporates:
           *  Gain: '<S299>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Square2);

          /* Gain: '<S300>/Gain' incorporates:
           *  Gain: '<S299>/Gain'
           *  Trigonometry: '<S300>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Square2);

          /* SignalConversion: '<S300>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S300>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S300>/Trigonometric Function' incorporates:
           *  Gain: '<S299>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Square2);

          /* Trigonometry: '<S300>/Trigonometric Function1' incorporates:
           *  Gain: '<S299>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Square2);

          /* SignalConversion: '<S300>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S276>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/u_cmd valid'
           */
          rtb_Square2 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S300>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S276>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/v_cmd valid'
           */
          rtb_Gain_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S300>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S276>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/w_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_Gain_a + rtb_Transpose[i] *
               rtb_Square2);
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

        /* End of MultiPortSwitch: '<S276>/Index Vector' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Saturation1_ln[0];
        rtb_MatrixConcatenate3[1] += rtb_Saturation1_ln[1];

        /* Sum: '<S215>/Sum1' */
        rtb_Divide_l_idx_2 += rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S232>/Switch' incorporates:
         *  Constant: '<S247>/Constant'
         *  Constant: '<S248>/Constant'
         *  Constant: '<S249>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S247>/Compare'
         *  RelationalOperator: '<S248>/Compare'
         *  RelationalOperator: '<S249>/Compare'
         *  S-Function (sfix_bitop): '<S232>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S232>/y_v_cmd'
         *  SignalConversion: '<S22>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S232>/Logical Operator' incorporates:
           *  Constant: '<S248>/Constant'
           *  Constant: '<S249>/Constant'
           *  RelationalOperator: '<S248>/Compare'
           *  RelationalOperator: '<S249>/Compare'
           *  S-Function (sfix_bitop): '<S232>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S232>/y_v_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_Switch_p_idx_1 = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_Switch_p_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U);
        }

        /* End of Switch: '<S232>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S213>/u_cmd_valid' */
        /* MATLAB Function: '<S244>/bit_shift' incorporates:
         *  DataTypeConversion: '<S213>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_e << 6);

        /* End of Outputs for SubSystem: '<S213>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S213>/v_cmd_valid' */
        /* MATLAB Function: '<S245>/bit_shift' incorporates:
         *  DataTypeConversion: '<S213>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_Switch_p_idx_1 << 7);

        /* End of Outputs for SubSystem: '<S213>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S233>/Switch' incorporates:
         *  Constant: '<S251>/Constant'
         *  Constant: '<S252>/Constant'
         *  Constant: '<S254>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S251>/Compare'
         *  RelationalOperator: '<S252>/Compare'
         *  RelationalOperator: '<S254>/Compare'
         *  S-Function (sfix_bitop): '<S233>/ax_cmd'
         *  S-Function (sfix_bitop): '<S233>/ay_cmd'
         *  SignalConversion: '<S22>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S233>/Logical Operator' incorporates:
           *  Constant: '<S252>/Constant'
           *  Constant: '<S254>/Constant'
           *  RelationalOperator: '<S252>/Compare'
           *  RelationalOperator: '<S254>/Compare'
           *  S-Function (sfix_bitop): '<S233>/ax_cmd'
           *  S-Function (sfix_bitop): '<S233>/ay_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_Switch_p_idx_1 = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_Switch_p_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
        }

        /* End of Switch: '<S233>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S137>/Bus Assignment'
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Constant: '<S137>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S137>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Inport: '<Root>/Auto_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S22>/Signal Copy'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = FMS_U.Auto_Cmd.p_cmd;
        FMS_Y.FMS_Out.q_cmd = FMS_U.Auto_Cmd.q_cmd;
        FMS_Y.FMS_Out.r_cmd = FMS_U.Auto_Cmd.r_cmd;
        FMS_Y.FMS_Out.phi_cmd = FMS_U.Auto_Cmd.phi_cmd;
        FMS_Y.FMS_Out.theta_cmd = FMS_U.Auto_Cmd.theta_cmd;
        FMS_Y.FMS_Out.throttle_cmd = FMS_U.Auto_Cmd.throttle_cmd;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        FMS_Y.FMS_Out.ax_cmd = rtb_Switch_ec[0];
        FMS_Y.FMS_Out.ay_cmd = rtb_Switch_ec[1];
        FMS_Y.FMS_Out.az_cmd = rtb_Switch_ec[2];

        /* Saturate: '<S214>/Saturation' */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Divide_l_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_l_idx_1;
        }

        /* End of Saturate: '<S214>/Saturation' */

        /* Saturate: '<S215>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S215>/Saturation2' */

        /* Saturate: '<S215>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S215>/Saturation1' */

        /* Saturate: '<S215>/Saturation3' */
        if (rtb_Divide_l_idx_2 > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Divide_l_idx_2 < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S137>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Divide_l_idx_2;
        }

        /* End of Saturate: '<S215>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S213>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S213>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S213>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S213>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S213>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S213>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S213>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S213>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S213>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S213>/throttle_cmd_valid' */
        /* BusAssignment: '<S137>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Constant: '<S225>/Constant'
         *  Constant: '<S226>/Constant'
         *  Constant: '<S227>/Constant'
         *  Constant: '<S228>/Constant'
         *  Constant: '<S229>/Constant'
         *  Constant: '<S230>/Constant'
         *  Constant: '<S231>/Constant'
         *  Constant: '<S250>/Constant'
         *  Constant: '<S253>/Constant'
         *  DataTypeConversion: '<S213>/Data Type Conversion10'
         *  DataTypeConversion: '<S213>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S234>/bit_shift'
         *  MATLAB Function: '<S235>/bit_shift'
         *  MATLAB Function: '<S236>/bit_shift'
         *  MATLAB Function: '<S238>/bit_shift'
         *  MATLAB Function: '<S239>/bit_shift'
         *  MATLAB Function: '<S240>/bit_shift'
         *  MATLAB Function: '<S241>/bit_shift'
         *  MATLAB Function: '<S242>/bit_shift'
         *  MATLAB Function: '<S243>/bit_shift'
         *  MATLAB Function: '<S246>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S225>/Compare'
         *  RelationalOperator: '<S226>/Compare'
         *  RelationalOperator: '<S227>/Compare'
         *  RelationalOperator: '<S228>/Compare'
         *  RelationalOperator: '<S229>/Compare'
         *  RelationalOperator: '<S230>/Compare'
         *  RelationalOperator: '<S231>/Compare'
         *  RelationalOperator: '<S250>/Compare'
         *  RelationalOperator: '<S253>/Compare'
         *  S-Function (sfix_bitop): '<S213>/p_cmd'
         *  S-Function (sfix_bitop): '<S213>/phi_cmd'
         *  S-Function (sfix_bitop): '<S213>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S213>/q_cmd'
         *  S-Function (sfix_bitop): '<S213>/r_cmd'
         *  S-Function (sfix_bitop): '<S213>/theta_cmd'
         *  S-Function (sfix_bitop): '<S213>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S232>/z_w_cmd'
         *  S-Function (sfix_bitop): '<S233>/az_cmd'
         *  SignalConversion: '<S22>/Signal Copy'
         *  Sum: '<S213>/Add'
         */
        FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
          ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
           ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
          (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) + rtb_y_md) + rtb_y_c1)
          + (((FMS_U.Auto_Cmd.cmd_mask & 33280U) > 0U) << 8)) +
          (rtb_LogicalOperator_e << 9)) + (rtb_Switch_p_idx_1 << 10)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

        /* End of Outputs for SubSystem: '<S213>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S213>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S213>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S213>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S213>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S213>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S213>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S213>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S213>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S213>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S28>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S28>/Mission' incorporates:
           *  ActionPort: '<S136>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S28>/Switch Case' incorporates:
           *  UnitDelay: '<S139>/Delay Input1'
           *
           * Block description for '<S139>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S28>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S28>/Mission' incorporates:
           *  ActionPort: '<S136>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S136>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S28>/Switch Case' incorporates:
           *  Chart: '<S172>/Motion Status'
           *  Chart: '<S182>/Motion State'
           *  Delay: '<S144>/Delay'
           *  Delay: '<S164>/Delay'
           *  DiscreteIntegrator: '<S147>/Integrator'
           *  DiscreteIntegrator: '<S147>/Integrator1'
           *  DiscreteIntegrator: '<S208>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_i = 0.0F;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S136>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S28>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S28>/Mission' incorporates:
         *  ActionPort: '<S136>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* RelationalOperator: '<S139>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S139>/Delay Input1'
         *
         * Block description for '<S139>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Switch_p_idx_1 = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S136>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S140>/Reset'
         */
        if (rtb_Switch_p_idx_1 && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE !=
             POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S181>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S171>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S164>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S208>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S144>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S147>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S147>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S182>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S172>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_Switch_p_idx_1;

        /* Delay: '<S164>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        if (FMS_DW.icLoad != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S160>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_iq_idx_0 = FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.sp_waypoint[0];
        rtb_Divide_l_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sqrt: '<S168>/Sqrt' incorporates:
         *  Math: '<S168>/Square'
         *  Sum: '<S160>/Sum'
         *  Sum: '<S168>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0 + rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1);

        /* Switch: '<S160>/Switch' incorporates:
         *  Constant: '<S160>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Divide_l_idx_2 = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S160>/Gain' */
          rtb_Divide_l_idx_2 = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S160>/Saturation' */
          if (rtb_Divide_l_idx_2 > FMS_PARAM.CRUISE_SPEED) {
            rtb_Divide_l_idx_2 = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Divide_l_idx_2 < 0.5F) {
              rtb_Divide_l_idx_2 = 0.5F;
            }
          }

          /* End of Saturate: '<S160>/Saturation' */
        }

        /* End of Switch: '<S160>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S182>/Motion State' incorporates:
         *  Constant: '<S182>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S182>/Square'
         *  Math: '<S182>/Square1'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sqrt: '<S182>/Sqrt'
         *  Sum: '<S182>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S181>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S181>/Hold Control' incorporates:
             *  ActionPort: '<S184>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S181>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S181>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S181>/Hold Control' incorporates:
           *  ActionPort: '<S184>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S181>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S181>/Brake Control' incorporates:
           *  ActionPort: '<S183>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S181>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S181>/Move Control' incorporates:
             *  ActionPort: '<S185>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S181>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S181>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S181>/Move Control' incorporates:
           *  ActionPort: '<S185>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S181>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S181>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S172>/Motion Status' incorporates:
         *  Abs: '<S172>/Abs'
         *  Constant: '<S172>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S171>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S171>/Hold Control' incorporates:
             *  ActionPort: '<S174>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S171>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S171>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S171>/Hold Control' incorporates:
           *  ActionPort: '<S174>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S171>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S171>/Brake Control' incorporates:
           *  ActionPort: '<S173>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S171>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S171>/Move Control' incorporates:
             *  ActionPort: '<S175>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S171>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S171>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S171>/Move Control' incorporates:
           *  ActionPort: '<S175>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S171>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S171>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S140>/Sum' incorporates:
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Gain_a = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S158>/Sum of Elements' incorporates:
         *  Math: '<S158>/Math Function'
         *  Sum: '<S140>/Sum'
         */
        rtb_Rem_k = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1 + rtb_Gain_a *
          rtb_Gain_a;

        /* Math: '<S158>/Math Function1' incorporates:
         *  Sum: '<S158>/Sum of Elements'
         *
         * About '<S158>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Square2 = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Square2 = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S158>/Math Function1' */

        /* Switch: '<S158>/Switch' incorporates:
         *  Constant: '<S158>/Constant'
         *  Product: '<S158>/Product'
         *  Sum: '<S140>/Sum'
         */
        if (rtb_Square2 > 0.0F) {
          rtb_Switch_ec[0] = rtb_Divide_l_idx_1;
          rtb_Switch_ec[1] = rtb_Gain_a;
          rtb_Switch_ec[2] = rtb_Square2;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S158>/Switch' */

        /* Product: '<S158>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_TmpSignalConversionAtDela_a[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S156>/Subtract' incorporates:
         *  Product: '<S156>/Multiply'
         *  Product: '<S156>/Multiply1'
         */
        rtb_Square2 = rtb_TmpSignalConversionAtDela_a[0] * FMS_ConstB.Divide[1]
          - rtb_TmpSignalConversionAtDela_a[1] * FMS_ConstB.Divide[0];

        /* Signum: '<S145>/Sign1' */
        if (rtb_Square2 < 0.0F) {
          rtb_Square2 = -1.0F;
        } else {
          if (rtb_Square2 > 0.0F) {
            rtb_Square2 = 1.0F;
          }
        }

        /* End of Signum: '<S145>/Sign1' */

        /* Switch: '<S145>/Switch2' incorporates:
         *  Constant: '<S145>/Constant4'
         */
        if (rtb_Square2 == 0.0F) {
          rtb_Square2 = 1.0F;
        }

        /* End of Switch: '<S145>/Switch2' */

        /* DotProduct: '<S145>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide[0] *
          rtb_TmpSignalConversionAtDela_a[0] + FMS_ConstB.Divide[1] *
          rtb_TmpSignalConversionAtDela_a[1];

        /* Trigonometry: '<S145>/Acos' incorporates:
         *  DotProduct: '<S145>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S145>/Multiply' incorporates:
         *  Trigonometry: '<S145>/Acos'
         */
        rtb_Square2 *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S149>/Rem' incorporates:
         *  Constant: '<S149>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sum: '<S144>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_Square2 - FMS_U.INS_Out.psi,
          6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S149>/Switch' incorporates:
         *  Abs: '<S149>/Abs'
         *  Constant: '<S149>/Constant'
         *  Constant: '<S155>/Constant'
         *  Product: '<S149>/Multiply'
         *  RelationalOperator: '<S155>/Compare'
         *  Sum: '<S149>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S149>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Gain_a = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Gain_a = 1.0F;
          } else {
            rtb_Gain_a = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S149>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Gain_a;
        }

        /* End of Switch: '<S149>/Switch' */

        /* Abs: '<S142>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S142>/Switch' incorporates:
         *  Product: '<S164>/Multiply'
         *  Sum: '<S164>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S181>/Saturation1' */
          if (FMS_B.Merge_n[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_ec[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_n[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_ec[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_ec[0] = FMS_B.Merge_n[0];
          }

          if (FMS_B.Merge_n[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_ec[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_n[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_ec[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_ec[1] = FMS_B.Merge_n[1];
          }

          /* End of Saturate: '<S181>/Saturation1' */

          /* Saturate: '<S171>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S171>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S164>/Sum' incorporates:
           *  Delay: '<S164>/Delay'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S209>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_ec[0] = rtb_Divide_l_idx_1;
          rtb_Rem_k = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S164>/Sum' incorporates:
           *  Delay: '<S164>/Delay'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S211>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S211>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S210>/Gain' incorporates:
           *  DiscreteIntegrator: '<S208>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  Sum: '<S208>/Add'
           */
          rtb_Gain_a = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Trigonometry: '<S211>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_Gain_a);

          /* Gain: '<S211>/Gain' incorporates:
           *  Trigonometry: '<S211>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Gain_a);

          /* SignalConversion: '<S211>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S211>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S211>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_Gain_a);

          /* Trigonometry: '<S211>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_Gain_a);

          /* SignalConversion: '<S211>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Sum: '<S209>/Sum of Elements' incorporates:
           *  Math: '<S209>/Math Function'
           */
          rtb_Gain_a = rtb_Switch_ec[0] * rtb_Switch_ec[0] + rtb_Divide_l_idx_1 *
            rtb_Divide_l_idx_1;

          /* Math: '<S209>/Math Function1' incorporates:
           *  Sum: '<S209>/Sum of Elements'
           *
           * About '<S209>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain_a < 0.0F) {
            rtb_Gain_a = -sqrtf(fabsf(rtb_Gain_a));
          } else {
            rtb_Gain_a = sqrtf(rtb_Gain_a);
          }

          /* End of Math: '<S209>/Math Function1' */

          /* Switch: '<S209>/Switch' incorporates:
           *  Constant: '<S209>/Constant'
           *  Product: '<S209>/Product'
           */
          if (rtb_Gain_a <= 0.0F) {
            rtb_Rem_k = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Gain_a = 1.0F;
          }

          /* End of Switch: '<S209>/Switch' */

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S165>/Sum1' incorporates:
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_iq_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S165>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_h_idx_0 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_1 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Product: '<S165>/Divide' incorporates:
           *  Math: '<S166>/Square'
           *  Math: '<S167>/Square'
           *  Sqrt: '<S166>/Sqrt'
           *  Sqrt: '<S167>/Sqrt'
           *  Sum: '<S165>/Sum'
           *  Sum: '<S165>/Sum1'
           *  Sum: '<S166>/Sum of Elements'
           *  Sum: '<S167>/Sum of Elements'
           */
          rtb_MathFunction_iq_idx_0 = sqrtf(rtb_MathFunction_h_idx_0 *
            rtb_MathFunction_h_idx_0 + rtb_MathFunction_h_idx_1 *
            rtb_MathFunction_h_idx_1) / sqrtf(rtb_MathFunction_iq_idx_0 *
            rtb_MathFunction_iq_idx_0 + rtb_P_d_idx_0 * rtb_P_d_idx_0);

          /* Saturate: '<S165>/Saturation' */
          if (rtb_MathFunction_iq_idx_0 > 1.0F) {
            rtb_MathFunction_iq_idx_0 = 1.0F;
          } else {
            if (rtb_MathFunction_iq_idx_0 < 0.0F) {
              rtb_MathFunction_iq_idx_0 = 0.0F;
            }
          }

          /* End of Saturate: '<S165>/Saturation' */

          /* Product: '<S207>/Multiply2' incorporates:
           *  Product: '<S209>/Divide'
           */
          rtb_Rem_k = rtb_Rem_k / rtb_Gain_a * rtb_Divide_l_idx_2;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_Gain_a *
            rtb_Divide_l_idx_2;

          /* Product: '<S164>/Multiply' */
          for (i = 0; i < 3; i++) {
            rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[i] * rtb_Rem_k;
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S159>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S165>/Multiply'
           *  SignalConversion: '<S22>/Signal Copy1'
           *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S159>/Sum2'
           *  Sum: '<S165>/Add'
           *  Sum: '<S165>/Subtract'
           */
          rtb_Divide_l_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_MathFunction_iq_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_ec[0] = rtb_Transpose_0[0];
          rtb_Switch_ec[1] = rtb_Transpose_0[1];

          /* Saturate: '<S159>/Saturation1' incorporates:
           *  Product: '<S164>/Multiply'
           */
          if (rtb_Divide_l_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_l_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = rtb_Divide_l_idx_1;
          }

          /* End of Saturate: '<S159>/Saturation1' */
        }

        /* End of Switch: '<S142>/Switch' */

        /* Delay: '<S144>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S147>/Integrator1' incorporates:
         *  Delay: '<S144>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S151>/Rem' incorporates:
         *  Constant: '<S151>/Constant1'
         *  DiscreteIntegrator: '<S147>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sum: '<S146>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S151>/Switch' incorporates:
         *  Abs: '<S151>/Abs'
         *  Constant: '<S151>/Constant'
         *  Constant: '<S152>/Constant'
         *  Product: '<S151>/Multiply'
         *  RelationalOperator: '<S152>/Compare'
         *  Sum: '<S151>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S151>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_k;
          }

          /* End of Signum: '<S151>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S151>/Switch' */

        /* Gain: '<S146>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S146>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S146>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S140>/Bus Assignment'
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Constant: '<S140>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S140>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_ec[0];
        FMS_Y.FMS_Out.v_cmd = rtb_Switch_ec[1];
        FMS_Y.FMS_Out.w_cmd = rtb_Switch_ec[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S202>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtDela_a[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_TmpSignalConversionAtDela_a[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S202>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S202>/Math Function'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_Gain_a = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S202>/Math Function1' incorporates:
         *  Sum: '<S202>/Sum of Elements'
         *
         * About '<S202>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_a < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Gain_a));
        } else {
          rtb_Rem_k = sqrtf(rtb_Gain_a);
        }

        /* End of Math: '<S202>/Math Function1' */

        /* Switch: '<S202>/Switch' incorporates:
         *  Constant: '<S202>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S202>/Product'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        if (rtb_Rem_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_ec[0] = FMS_U.INS_Out.vn;
          rtb_Switch_ec[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_ec[2] = rtb_Rem_k;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S202>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S162>/NearbyRefWP' incorporates:
         *  Constant: '<S140>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                        rtb_TmpSignalConversionAtDela_a, &rtb_Gain_a);

        /* MATLAB Function: '<S162>/SearchL1RefWP' incorporates:
         *  Constant: '<S140>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Rem_k = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Rem_k = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1 + rtb_Rem_k *
          rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Rem_k);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Divide_l_idx_1 = -1.0F;
        rtb_MathFunction_h_idx_0 = 0.0F;
        rtb_MathFunction_h_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Rem_k);
          rtb_Rem_k = (-B - u1_tmp) / (2.0F * rtb_Rem_k);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Rem_k >= 0.0F) && (rtb_Rem_k <=
               1.0F)) {
            rtb_Divide_l_idx_1 = fmaxf(D, rtb_Rem_k);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Divide_l_idx_1 = D;
            guard1 = true;
          } else {
            if ((rtb_Rem_k >= 0.0F) && (rtb_Rem_k <= 1.0F)) {
              rtb_Divide_l_idx_1 = rtb_Rem_k;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Rem_k);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Divide_l_idx_1 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_MathFunction_h_idx_0 = (FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Divide_l_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_1 = (FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Divide_l_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S162>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
          [0];
        rtb_MathFunction_iq_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Rem_k = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                     rtb_MathFunction_iq_idx_0 + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_P_d_idx_0) / (rtb_P_d_idx_0 *
          rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Switch_p_idx_1 = (rtb_Rem_k <= 0.0F);
        rtb_LogicalOperator_e = (rtb_Rem_k >= 1.0F);
        if (rtb_Switch_p_idx_1) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else if (rtb_LogicalOperator_e) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          rtb_P_d_idx_0 = rtb_Rem_k * rtb_P_d_idx_0 + FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Switch: '<S162>/Switch1' incorporates:
         *  Constant: '<S195>/Constant'
         *  RelationalOperator: '<S195>/Compare'
         */
        if (rtb_Gain_a <= 0.0F) {
          /* Switch: '<S162>/Switch' incorporates:
           *  Constant: '<S194>/Constant'
           *  MATLAB Function: '<S162>/SearchL1RefWP'
           *  RelationalOperator: '<S194>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_h_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S162>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Switch_p_idx_1) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            } else if (rtb_LogicalOperator_e) {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = rtb_Rem_k *
                rtb_MathFunction_iq_idx_0 + FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            }
          }

          /* End of Switch: '<S162>/Switch' */
        }

        /* End of Switch: '<S162>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S163>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_TmpSignalConversionAtDela_a[0] -
          FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;
        rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S163>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S203>/Math Function'
         *  SignalConversion: '<S22>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_TmpSignalConversionAtDela_a[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S203>/Math Function' incorporates:
         *  Math: '<S201>/Square'
         */
        rtb_Gain_a = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Sum: '<S203>/Sum of Elements' incorporates:
         *  Math: '<S203>/Math Function'
         */
        rtb_Divide_l_idx_1 = rtb_Gain_a + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S203>/Math Function1' incorporates:
         *  Sum: '<S203>/Sum of Elements'
         *
         * About '<S203>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S203>/Math Function1' */

        /* Switch: '<S203>/Switch' incorporates:
         *  Constant: '<S203>/Constant'
         *  Product: '<S203>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Saturation1_ln[0];
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_h_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Rem_k;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S203>/Switch' */

        /* Product: '<S202>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_P_d_idx_0 = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S205>/Sum of Elements' incorporates:
         *  Math: '<S205>/Math Function'
         *  SignalConversion: '<S205>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0;

        /* Math: '<S205>/Math Function1' incorporates:
         *  Sum: '<S205>/Sum of Elements'
         *
         * About '<S205>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S205>/Math Function1' */

        /* Switch: '<S205>/Switch' incorporates:
         *  Constant: '<S205>/Constant'
         *  Product: '<S205>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_Switch_ec[0] = rtb_P_d_idx_0;
          rtb_Switch_ec[1] = rtb_MathFunction_iq_idx_0;
          rtb_Switch_ec[2] = rtb_Rem_k;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S205>/Switch' */

        /* Product: '<S203>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S206>/Sum of Elements' incorporates:
         *  Math: '<S206>/Math Function'
         *  SignalConversion: '<S206>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0;

        /* Math: '<S206>/Math Function1' incorporates:
         *  Sum: '<S206>/Sum of Elements'
         *
         * About '<S206>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S206>/Math Function1' */

        /* Switch: '<S206>/Switch' incorporates:
         *  Constant: '<S206>/Constant'
         *  Product: '<S206>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_P_d_idx_0;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_iq_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Rem_k;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S206>/Switch' */

        /* Product: '<S206>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S205>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[0] *= rtb_Saturation1_ln[0];

        /* Product: '<S206>/Divide' incorporates:
         *  Math: '<S201>/Square'
         */
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S205>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S200>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S200>/Square'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sum: '<S200>/Sum of Elements'
         */
        rtb_Rem_k = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve
                          * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S163>/Gain' incorporates:
         *  Math: '<S163>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S204>/Subtract' incorporates:
         *  Product: '<S204>/Multiply'
         *  Product: '<S204>/Multiply1'
         */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 * rtb_TmpSignalConversionAtDela_a
          [1] - rtb_P_d_idx_0 * rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S199>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S199>/Sign1' */

        /* Switch: '<S199>/Switch2' incorporates:
         *  Constant: '<S199>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S199>/Switch2' */

        /* DotProduct: '<S199>/Dot Product' */
        rtb_MathFunction_iq_idx_0 = rtb_TmpSignalConversionAtDela_a[0] *
          rtb_MathFunction_iq_idx_0 + rtb_TmpSignalConversionAtDela_a[1] *
          rtb_P_d_idx_0;

        /* Trigonometry: '<S199>/Acos' incorporates:
         *  DotProduct: '<S199>/Dot Product'
         */
        if (rtb_MathFunction_iq_idx_0 > 1.0F) {
          rtb_MathFunction_iq_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_0 < -1.0F) {
            rtb_MathFunction_iq_idx_0 = -1.0F;
          }
        }

        /* Product: '<S199>/Multiply' incorporates:
         *  Trigonometry: '<S199>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_MathFunction_iq_idx_0);

        /* Saturate: '<S163>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S163>/Saturation' */

        /* Product: '<S163>/Divide' incorporates:
         *  Constant: '<S140>/L1'
         *  Constant: '<S163>/Constant'
         *  MinMax: '<S163>/Max'
         *  MinMax: '<S163>/Min'
         *  Product: '<S163>/Multiply1'
         *  Sqrt: '<S201>/Sqrt'
         *  Sum: '<S201>/Sum of Elements'
         *  Trigonometry: '<S163>/Sin'
         */
        rtb_MathFunction_iq_idx_0 = arm_sin_f32(rtb_Rem_k) * rtb_Divide_l_idx_1 /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Gain_a + rtb_Saturation1_ln[0]),
                 0.5F));

        /* Sum: '<S144>/Sum2' incorporates:
         *  Delay: '<S144>/Delay'
         */
        rtb_Square2 -= FMS_DW.Delay_DSTATE_h;

        /* Math: '<S148>/Rem' incorporates:
         *  Constant: '<S148>/Constant1'
         */
        rtb_Gain_a = rt_remf(rtb_Square2, 6.28318548F);

        /* Switch: '<S148>/Switch' incorporates:
         *  Abs: '<S148>/Abs'
         *  Constant: '<S148>/Constant'
         *  Constant: '<S154>/Constant'
         *  Product: '<S148>/Multiply'
         *  RelationalOperator: '<S154>/Compare'
         *  Sum: '<S148>/Add'
         */
        if (fabsf(rtb_Gain_a) > 3.14159274F) {
          /* Signum: '<S148>/Sign' */
          if (rtb_Gain_a < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Gain_a > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Gain_a;
          }

          /* End of Signum: '<S148>/Sign' */
          rtb_Gain_a -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S148>/Switch' */

        /* Sum: '<S144>/Sum' incorporates:
         *  Delay: '<S144>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Gain_a + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S153>/Multiply1' incorporates:
         *  Constant: '<S153>/const1'
         *  DiscreteIntegrator: '<S147>/Integrator'
         */
        rtb_Gain_a = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S153>/Add' incorporates:
         *  DiscreteIntegrator: '<S147>/Integrator1'
         *  Sum: '<S147>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_p - rtb_Divide_l_idx_1) +
          rtb_Gain_a;

        /* Signum: '<S153>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S153>/Sign' */

        /* Sum: '<S153>/Add2' incorporates:
         *  Abs: '<S153>/Abs'
         *  Gain: '<S153>/Gain'
         *  Gain: '<S153>/Gain1'
         *  Product: '<S153>/Multiply2'
         *  Product: '<S153>/Multiply3'
         *  Sqrt: '<S153>/Sqrt'
         *  Sum: '<S153>/Add1'
         *  Sum: '<S153>/Subtract'
         */
        rtb_Square2 = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_j) *
                             FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Gain_a;

        /* Sum: '<S153>/Add4' */
        rtb_Gain_a += rtb_Rem_k - rtb_Square2;

        /* Sum: '<S153>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_j;

        /* Sum: '<S153>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_j;

        /* Signum: '<S153>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S153>/Sign1' */

        /* Signum: '<S153>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S153>/Sign2' */

        /* Sum: '<S153>/Add5' incorporates:
         *  Gain: '<S153>/Gain2'
         *  Product: '<S153>/Multiply4'
         *  Sum: '<S153>/Subtract2'
         */
        rtb_Square2 += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F * rtb_Gain_a;

        /* Update for Delay: '<S164>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S208>/Discrete-Time Integrator' incorporates:
         *  Product: '<S164>/Divide1'
         */
        FMS_DW.l1_heading += rtb_MathFunction_iq_idx_0 / rtb_Divide_l_idx_2 *
          0.004F;

        /* Update for Delay: '<S144>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S147>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S147>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Sum: '<S153>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Square2 + FMS_ConstB.d_j;

        /* Sum: '<S153>/Subtract3' */
        rtb_Rem_k = rtb_Square2 - FMS_ConstB.d_j;

        /* Signum: '<S153>/Sign5' */
        if (rtb_Square2 < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_Divide_l_idx_2 = rtb_Square2;
        }

        /* End of Signum: '<S153>/Sign5' */

        /* Signum: '<S153>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S153>/Sign3' */

        /* Signum: '<S153>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S153>/Sign4' */

        /* Signum: '<S153>/Sign6' */
        if (rtb_Square2 < 0.0F) {
          rtb_Gain_a = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Gain_a = 1.0F;
        } else {
          rtb_Gain_a = rtb_Square2;
        }

        /* End of Signum: '<S153>/Sign6' */

        /* Update for DiscreteIntegrator: '<S147>/Integrator' incorporates:
         *  Constant: '<S153>/const'
         *  Gain: '<S153>/Gain3'
         *  Product: '<S153>/Divide'
         *  Product: '<S153>/Multiply5'
         *  Product: '<S153>/Multiply6'
         *  Sum: '<S153>/Subtract4'
         *  Sum: '<S153>/Subtract5'
         *  Sum: '<S153>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_Square2 / FMS_ConstB.d_j -
          rtb_Divide_l_idx_2) * FMS_ConstB.Gain4_c * ((rtb_Divide_l_idx_1 -
          rtb_Rem_k) * 0.5F) - rtb_Gain_a * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S147>/Integrator' */
        /* End of Outputs for SubSystem: '<S136>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Update for UnitDelay: '<S139>/Delay Input1' incorporates:
         *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S139>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S28>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S28>/Unknown' incorporates:
         *  ActionPort: '<S138>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S28>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S28>/Switch Case' */
      /* End of Outputs for SubSystem: '<S23>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S23>/Assist' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      /* SwitchCase: '<S27>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S123>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S42>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S59>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S99>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S75>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S86>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S27>/Acro' incorporates:
         *  ActionPort: '<S32>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  BusAssignment: '<S32>/Bus Assignment'
         *  Constant: '<S32>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Gain: '<S37>/Gain'
         *  Gain: '<S37>/Gain1'
         *  Gain: '<S37>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S38>/Saturation' incorporates:
         *  Constant: '<S38>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy2'
         *  Sum: '<S38>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Gain_a = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S38>/Saturation' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S32>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Constant: '<S38>/Constant5'
         *  Gain: '<S38>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S38>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Gain_a), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S27>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S27>/Stabilize' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S27>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S119>/Integrator'
           *  DiscreteIntegrator: '<S119>/Integrator1'
           *  DiscreteIntegrator: '<S120>/Integrator'
           *  DiscreteIntegrator: '<S120>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_jt = 0.0F;
          FMS_DW.Integrator_DSTATE_cq = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S27>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S27>/Stabilize' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S27>/Switch Case' incorporates:
           *  Chart: '<S124>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S27>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S27>/Stabilize' incorporates:
         *  ActionPort: '<S35>/Action Port'
         */
        /* Product: '<S121>/Multiply1' incorporates:
         *  Constant: '<S121>/const1'
         *  DiscreteIntegrator: '<S119>/Integrator'
         */
        rtb_Rem_k = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S117>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S117>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S121>/Add' incorporates:
         *  DiscreteIntegrator: '<S119>/Integrator1'
         *  Gain: '<S114>/Gain'
         *  Gain: '<S117>/Gain'
         *  Sum: '<S119>/Subtract'
         */
        rtb_MathFunction_iq_idx_0 = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F
          - FMS_PARAM.ROLL_DZ) * rtb_Gain_a * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Rem_k;

        /* Signum: '<S121>/Sign' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_MathFunction_iq_idx_0 > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_MathFunction_iq_idx_0;
        }

        /* End of Signum: '<S121>/Sign' */

        /* Sum: '<S121>/Add2' incorporates:
         *  Abs: '<S121>/Abs'
         *  Gain: '<S121>/Gain'
         *  Gain: '<S121>/Gain1'
         *  Product: '<S121>/Multiply2'
         *  Product: '<S121>/Multiply3'
         *  Sqrt: '<S121>/Sqrt'
         *  Sum: '<S121>/Add1'
         *  Sum: '<S121>/Subtract'
         */
        rtb_Divide_l_idx_2 = (sqrtf((8.0F * fabsf(rtb_MathFunction_iq_idx_0) +
          FMS_ConstB.d_d) * FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Rem_k;

        /* Sum: '<S121>/Add4' */
        rtb_Square2 = (rtb_MathFunction_iq_idx_0 - rtb_Divide_l_idx_2) +
          rtb_Rem_k;

        /* Sum: '<S121>/Add3' */
        rtb_Divide_l_idx_1 = rtb_MathFunction_iq_idx_0 + FMS_ConstB.d_d;

        /* Sum: '<S121>/Subtract1' */
        rtb_MathFunction_iq_idx_0 -= FMS_ConstB.d_d;

        /* Signum: '<S121>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S121>/Sign1' */

        /* Signum: '<S121>/Sign2' */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_MathFunction_iq_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_0 > 0.0F) {
            rtb_MathFunction_iq_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S121>/Sign2' */

        /* Sum: '<S121>/Add5' incorporates:
         *  Gain: '<S121>/Gain2'
         *  Product: '<S121>/Multiply4'
         *  Sum: '<S121>/Subtract2'
         */
        rtb_Divide_l_idx_2 += (rtb_Divide_l_idx_1 - rtb_MathFunction_iq_idx_0) *
          0.5F * rtb_Square2;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S124>/Motion State' incorporates:
         *  Abs: '<S124>/Abs'
         *  Abs: '<S124>/Abs1'
         *  Constant: '<S134>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S134>/Compare'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S123>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S123>/Hold Control' incorporates:
             *  ActionPort: '<S126>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S123>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S123>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S123>/Hold Control' incorporates:
           *  ActionPort: '<S126>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                             &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S123>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S123>/Brake Control' incorporates:
           *  ActionPort: '<S125>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S123>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S123>/Move Control' incorporates:
             *  ActionPort: '<S127>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S123>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S123>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S123>/Move Control' incorporates:
           *  ActionPort: '<S127>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S123>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S123>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  BusAssignment: '<S35>/Bus Assignment'
         *  Constant: '<S35>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S35>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  DiscreteIntegrator: '<S119>/Integrator1'
         *  DiscreteIntegrator: '<S120>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_j;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_jt;

        /* Saturate: '<S123>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S123>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Saturate: '<S116>/Saturation' incorporates:
         *  Constant: '<S116>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy2'
         *  Sum: '<S116>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Gain_a = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S116>/Saturation' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S35>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Constant: '<S116>/Constant5'
         *  Gain: '<S116>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S116>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Gain_a), 65536.0F) + 1000U);

        /* Product: '<S122>/Multiply1' incorporates:
         *  Constant: '<S122>/const1'
         *  DiscreteIntegrator: '<S120>/Integrator'
         */
        rtb_MathFunction_iq_idx_0 = FMS_DW.Integrator_DSTATE_cq * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S118>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S118>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S122>/Add' incorporates:
         *  DiscreteIntegrator: '<S120>/Integrator1'
         *  Gain: '<S114>/Gain1'
         *  Gain: '<S118>/Gain'
         *  Sum: '<S120>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_jt - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * rtb_Gain_a * -FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_MathFunction_iq_idx_0;

        /* Signum: '<S122>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S122>/Sign' */

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
        rtb_Square2 = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_o) *
                             FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_MathFunction_iq_idx_0;

        /* Sum: '<S122>/Add4' */
        rtb_Gain_a = (rtb_Rem_k - rtb_Square2) + rtb_MathFunction_iq_idx_0;

        /* Sum: '<S122>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_o;

        /* Sum: '<S122>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_o;

        /* Signum: '<S122>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S122>/Sign1' */

        /* Signum: '<S122>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S122>/Sign2' */

        /* Sum: '<S122>/Add5' incorporates:
         *  Gain: '<S122>/Gain2'
         *  Product: '<S122>/Multiply4'
         *  Sum: '<S122>/Subtract2'
         */
        rtb_Square2 += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F * rtb_Gain_a;

        /* Update for DiscreteIntegrator: '<S119>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S119>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S121>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Divide_l_idx_2 + FMS_ConstB.d_d;

        /* Sum: '<S121>/Subtract3' */
        rtb_Rem_k = rtb_Divide_l_idx_2 - FMS_ConstB.d_d;

        /* Signum: '<S121>/Sign5' */
        if (rtb_Divide_l_idx_2 < 0.0F) {
          rtb_Gain_a = -1.0F;
        } else if (rtb_Divide_l_idx_2 > 0.0F) {
          rtb_Gain_a = 1.0F;
        } else {
          rtb_Gain_a = rtb_Divide_l_idx_2;
        }

        /* End of Signum: '<S121>/Sign5' */

        /* Signum: '<S121>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S121>/Sign3' */

        /* Signum: '<S121>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S121>/Sign4' */

        /* Signum: '<S121>/Sign6' */
        if (rtb_Divide_l_idx_2 < 0.0F) {
          rtb_MathFunction_iq_idx_0 = -1.0F;
        } else if (rtb_Divide_l_idx_2 > 0.0F) {
          rtb_MathFunction_iq_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_0 = rtb_Divide_l_idx_2;
        }

        /* End of Signum: '<S121>/Sign6' */

        /* Update for DiscreteIntegrator: '<S119>/Integrator' incorporates:
         *  Constant: '<S121>/const'
         *  Gain: '<S121>/Gain3'
         *  Product: '<S121>/Divide'
         *  Product: '<S121>/Multiply5'
         *  Product: '<S121>/Multiply6'
         *  Sum: '<S121>/Subtract4'
         *  Sum: '<S121>/Subtract5'
         *  Sum: '<S121>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Divide_l_idx_2 / FMS_ConstB.d_d -
          rtb_Gain_a) * FMS_ConstB.Gain4_n * ((rtb_Divide_l_idx_1 - rtb_Rem_k) *
          0.5F) - rtb_MathFunction_iq_idx_0 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S120>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S120>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_jt += 0.004F * FMS_DW.Integrator_DSTATE_cq;

        /* Sum: '<S122>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Square2 + FMS_ConstB.d_o;

        /* Sum: '<S122>/Subtract3' */
        rtb_Rem_k = rtb_Square2 - FMS_ConstB.d_o;

        /* Signum: '<S122>/Sign5' */
        if (rtb_Square2 < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_Divide_l_idx_2 = rtb_Square2;
        }

        /* End of Signum: '<S122>/Sign5' */

        /* Signum: '<S122>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S122>/Sign3' */

        /* Signum: '<S122>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S122>/Sign4' */

        /* Signum: '<S122>/Sign6' */
        if (rtb_Square2 < 0.0F) {
          rtb_Gain_a = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Gain_a = 1.0F;
        } else {
          rtb_Gain_a = rtb_Square2;
        }

        /* End of Signum: '<S122>/Sign6' */

        /* Update for DiscreteIntegrator: '<S120>/Integrator' incorporates:
         *  Constant: '<S122>/const'
         *  Gain: '<S122>/Gain3'
         *  Product: '<S122>/Divide'
         *  Product: '<S122>/Multiply5'
         *  Product: '<S122>/Multiply6'
         *  Sum: '<S122>/Subtract4'
         *  Sum: '<S122>/Subtract5'
         *  Sum: '<S122>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_cq += ((rtb_Square2 / FMS_ConstB.d_o -
          rtb_Divide_l_idx_2) * FMS_ConstB.Gain4_n3 * ((rtb_Divide_l_idx_1 -
          rtb_Rem_k) * 0.5F) - rtb_Gain_a * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S27>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S27>/Altitude' incorporates:
           *  ActionPort: '<S33>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S27>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S55>/Integrator'
           *  DiscreteIntegrator: '<S55>/Integrator1'
           *  DiscreteIntegrator: '<S56>/Integrator'
           *  DiscreteIntegrator: '<S56>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S27>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S27>/Altitude' incorporates:
           *  ActionPort: '<S33>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S27>/Switch Case' incorporates:
           *  Chart: '<S43>/Motion Status'
           *  Chart: '<S60>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S27>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S27>/Altitude' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S43>/Motion Status' incorporates:
         *  Abs: '<S43>/Abs'
         *  Abs: '<S43>/Abs1'
         *  Constant: '<S51>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S51>/Compare'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S42>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S42>/Hold Control' incorporates:
             *  ActionPort: '<S45>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S42>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S42>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S42>/Hold Control' incorporates:
           *  ActionPort: '<S45>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S42>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S42>/Brake Control' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S42>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S42>/Move Control' incorporates:
             *  ActionPort: '<S46>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S42>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

            /* End of SystemReset for SubSystem: '<S42>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S42>/Move Control' incorporates:
           *  ActionPort: '<S46>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_l,
                          &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S42>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S42>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S60>/Motion State' incorporates:
         *  Abs: '<S60>/Abs'
         *  Abs: '<S60>/Abs1'
         *  Constant: '<S70>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S70>/Compare'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S59>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S59>/Hold Control' incorporates:
             *  ActionPort: '<S62>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S59>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S59>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S59>/Hold Control' incorporates:
           *  ActionPort: '<S62>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                             &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S59>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S59>/Brake Control' incorporates:
           *  ActionPort: '<S61>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S59>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S59>/Move Control' incorporates:
             *  ActionPort: '<S63>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S59>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_cr);

            /* End of SystemReset for SubSystem: '<S59>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S59>/Move Control' incorporates:
           *  ActionPort: '<S63>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_cr, &FMS_DW.MoveControl_cr);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S59>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S59>/Switch Case' */

        /* Product: '<S57>/Multiply1' incorporates:
         *  Constant: '<S57>/const1'
         *  DiscreteIntegrator: '<S55>/Integrator'
         */
        rtb_Square2 = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S53>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S53>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S57>/Add' incorporates:
         *  DiscreteIntegrator: '<S55>/Integrator1'
         *  Gain: '<S40>/Gain'
         *  Gain: '<S53>/Gain'
         *  Sum: '<S55>/Subtract'
         */
        rtb_Divide_l_idx_2 = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Gain_a * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Square2;

        /* Signum: '<S57>/Sign' */
        if (rtb_Divide_l_idx_2 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Divide_l_idx_2 > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_2;
        }

        /* End of Signum: '<S57>/Sign' */

        /* Sum: '<S57>/Add2' incorporates:
         *  Abs: '<S57>/Abs'
         *  Gain: '<S57>/Gain'
         *  Gain: '<S57>/Gain1'
         *  Product: '<S57>/Multiply2'
         *  Product: '<S57>/Multiply3'
         *  Sqrt: '<S57>/Sqrt'
         *  Sum: '<S57>/Add1'
         *  Sum: '<S57>/Subtract'
         */
        rtb_MathFunction_iq_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_2) +
          FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Square2;

        /* Sum: '<S57>/Add4' */
        rtb_Square2 += rtb_Divide_l_idx_2 - rtb_MathFunction_iq_idx_0;

        /* Sum: '<S57>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Divide_l_idx_2 + FMS_ConstB.d;

        /* Sum: '<S57>/Subtract1' */
        rtb_Divide_l_idx_2 -= FMS_ConstB.d;

        /* Signum: '<S57>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S57>/Sign1' */

        /* Signum: '<S57>/Sign2' */
        if (rtb_Divide_l_idx_2 < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S57>/Sign2' */

        /* Sum: '<S57>/Add5' incorporates:
         *  Gain: '<S57>/Gain2'
         *  Product: '<S57>/Multiply4'
         *  Sum: '<S57>/Subtract2'
         */
        rtb_MathFunction_iq_idx_0 += (rtb_Divide_l_idx_1 - rtb_Divide_l_idx_2) *
          0.5F * rtb_Square2;

        /* Sum: '<S57>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_MathFunction_iq_idx_0 - FMS_ConstB.d;

        /* Sum: '<S57>/Add6' */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 + FMS_ConstB.d;

        /* Product: '<S57>/Divide' */
        rtb_P_d_idx_0 = rtb_MathFunction_iq_idx_0 / FMS_ConstB.d;

        /* Signum: '<S57>/Sign5' incorporates:
         *  Signum: '<S57>/Sign6'
         */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_MathFunction_h_idx_0 = -1.0F;
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_MathFunction_iq_idx_0 > 0.0F) {
          rtb_MathFunction_h_idx_0 = 1.0F;
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_MathFunction_h_idx_0 = rtb_MathFunction_iq_idx_0;
          rtb_Divide_l_idx_2 = rtb_MathFunction_iq_idx_0;
        }

        /* End of Signum: '<S57>/Sign5' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  BusAssignment: '<S33>/Bus Assignment'
         *  Constant: '<S33>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S33>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  DiscreteIntegrator: '<S55>/Integrator1'
         *  DiscreteIntegrator: '<S56>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S59>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S33>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S33>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S33>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S59>/Saturation' */

        /* Saturate: '<S42>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S33>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S33>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S33>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S42>/Saturation1' */

        /* Product: '<S58>/Multiply1' incorporates:
         *  Constant: '<S58>/const1'
         *  DiscreteIntegrator: '<S56>/Integrator'
         */
        rtb_MathFunction_iq_idx_0 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S54>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S54>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S58>/Add' incorporates:
         *  DiscreteIntegrator: '<S56>/Integrator1'
         *  Gain: '<S40>/Gain1'
         *  Gain: '<S54>/Gain'
         *  Sum: '<S56>/Subtract'
         */
        rtb_Square2 = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * rtb_Gain_a * -FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_MathFunction_iq_idx_0;

        /* Signum: '<S58>/Sign' */
        if (rtb_Square2 < 0.0F) {
          rtb_Gain_a = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Gain_a = 1.0F;
        } else {
          rtb_Gain_a = rtb_Square2;
        }

        /* End of Signum: '<S58>/Sign' */

        /* Sum: '<S58>/Add2' incorporates:
         *  Abs: '<S58>/Abs'
         *  Gain: '<S58>/Gain'
         *  Gain: '<S58>/Gain1'
         *  Product: '<S58>/Multiply2'
         *  Product: '<S58>/Multiply3'
         *  Sqrt: '<S58>/Sqrt'
         *  Sum: '<S58>/Add1'
         *  Sum: '<S58>/Subtract'
         */
        rtb_Gain_a = (sqrtf((8.0F * fabsf(rtb_Square2) + FMS_ConstB.d_c) *
                            FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
          rtb_Gain_a + rtb_MathFunction_iq_idx_0;

        /* Sum: '<S58>/Add4' */
        rtb_MathFunction_iq_idx_0 += rtb_Square2 - rtb_Gain_a;

        /* Sum: '<S58>/Add3' */
        rtb_MathFunction_h_idx_1 = rtb_Square2 + FMS_ConstB.d_c;

        /* Sum: '<S58>/Subtract1' */
        rtb_Square2 -= FMS_ConstB.d_c;

        /* Signum: '<S58>/Sign1' */
        if (rtb_MathFunction_h_idx_1 < 0.0F) {
          rtb_MathFunction_h_idx_1 = -1.0F;
        } else {
          if (rtb_MathFunction_h_idx_1 > 0.0F) {
            rtb_MathFunction_h_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S58>/Sign1' */

        /* Signum: '<S58>/Sign2' */
        if (rtb_Square2 < 0.0F) {
          rtb_Square2 = -1.0F;
        } else {
          if (rtb_Square2 > 0.0F) {
            rtb_Square2 = 1.0F;
          }
        }

        /* End of Signum: '<S58>/Sign2' */

        /* Sum: '<S58>/Add5' incorporates:
         *  Gain: '<S58>/Gain2'
         *  Product: '<S58>/Multiply4'
         *  Sum: '<S58>/Subtract2'
         */
        rtb_Gain_a += (rtb_MathFunction_h_idx_1 - rtb_Square2) * 0.5F *
          rtb_MathFunction_iq_idx_0;

        /* Update for DiscreteIntegrator: '<S55>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S55>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S57>/Sign3' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S57>/Sign3' */

        /* Signum: '<S57>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S57>/Sign4' */

        /* Update for DiscreteIntegrator: '<S55>/Integrator' incorporates:
         *  Constant: '<S57>/const'
         *  Gain: '<S57>/Gain3'
         *  Product: '<S57>/Multiply5'
         *  Product: '<S57>/Multiply6'
         *  Sum: '<S57>/Subtract4'
         *  Sum: '<S57>/Subtract5'
         *  Sum: '<S57>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_P_d_idx_0 - rtb_MathFunction_h_idx_0) *
          FMS_ConstB.Gain4 * ((rtb_Rem_k - rtb_Divide_l_idx_1) * 0.5F) -
          rtb_Divide_l_idx_2 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S56>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S56>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S58>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Gain_a + FMS_ConstB.d_c;

        /* Sum: '<S58>/Subtract3' */
        rtb_Rem_k = rtb_Gain_a - FMS_ConstB.d_c;

        /* Signum: '<S58>/Sign5' */
        if (rtb_Gain_a < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_Gain_a > 0.0F) {
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_Divide_l_idx_2 = rtb_Gain_a;
        }

        /* End of Signum: '<S58>/Sign5' */

        /* Signum: '<S58>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S58>/Sign3' */

        /* Signum: '<S58>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S58>/Sign4' */

        /* Signum: '<S58>/Sign6' */
        if (rtb_Gain_a < 0.0F) {
          rtb_Square2 = -1.0F;
        } else if (rtb_Gain_a > 0.0F) {
          rtb_Square2 = 1.0F;
        } else {
          rtb_Square2 = rtb_Gain_a;
        }

        /* End of Signum: '<S58>/Sign6' */

        /* Update for DiscreteIntegrator: '<S56>/Integrator' incorporates:
         *  Constant: '<S58>/const'
         *  Gain: '<S58>/Gain3'
         *  Product: '<S58>/Divide'
         *  Product: '<S58>/Multiply5'
         *  Product: '<S58>/Multiply6'
         *  Sum: '<S58>/Subtract4'
         *  Sum: '<S58>/Subtract5'
         *  Sum: '<S58>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Gain_a / FMS_ConstB.d_c -
          rtb_Divide_l_idx_2) * FMS_ConstB.Gain4_m * ((rtb_Divide_l_idx_1 -
          rtb_Rem_k) * 0.5F) - rtb_Square2 * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S27>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S27>/Position' incorporates:
           *  ActionPort: '<S34>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S27>/Switch Case' incorporates:
           *  Chart: '<S100>/Motion State'
           *  Chart: '<S76>/Motion Status'
           *  Chart: '<S87>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_i);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S27>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S27>/Position' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S76>/Motion Status' incorporates:
         *  Abs: '<S76>/Abs'
         *  Abs: '<S76>/Abs1'
         *  Constant: '<S84>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S84>/Compare'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_i);

        /* Chart: '<S87>/Motion State' incorporates:
         *  Abs: '<S87>/Abs'
         *  Abs: '<S87>/Abs1'
         *  Constant: '<S97>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S97>/Compare'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_ki,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S100>/Logical Operator' incorporates:
         *  Abs: '<S100>/Abs1'
         *  Abs: '<S100>/Abs2'
         *  Constant: '<S111>/Constant'
         *  Constant: '<S112>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S111>/Compare'
         *  RelationalOperator: '<S112>/Compare'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        rtb_Switch_p_idx_1 = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S100>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S100>/Square'
         *  Math: '<S100>/Square1'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  Sqrt: '<S100>/Sqrt'
         *  Sum: '<S100>/Add'
         */
        if (FMS_DW.temporalCounter_i1_i < 1023U) {
          FMS_DW.temporalCounter_i1_i++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move_n;
          rtb_state_l = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_l = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_i
                 >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_d;
              rtb_state_l = MotionState_Hold;
            } else {
              if (rtb_Switch_p_idx_1) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_n;
                rtb_state_l = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_l = MotionState_Hold;
            if (rtb_Switch_p_idx_1) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_n;
              rtb_state_l = MotionState_Move;
            }
            break;

           default:
            rtb_state_l = MotionState_Move;
            if (!rtb_Switch_p_idx_1) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_l = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S100>/Motion State' */

        /* SwitchCase: '<S99>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state_l) {
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
            /* SystemReset for IfAction SubSystem: '<S99>/Hold Control' incorporates:
             *  ActionPort: '<S102>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S99>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S99>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S99>/Hold Control' incorporates:
           *  ActionPort: '<S102>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S99>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S99>/Brake Control' incorporates:
           *  ActionPort: '<S101>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S99>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S99>/Move Control' incorporates:
             *  ActionPort: '<S103>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S99>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S99>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S99>/Move Control' incorporates:
           *  ActionPort: '<S103>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S99>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S99>/Switch Case' */

        /* SwitchCase: '<S75>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S75>/Hold Control' incorporates:
             *  ActionPort: '<S78>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S75>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S75>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S75>/Hold Control' incorporates:
           *  ActionPort: '<S78>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S75>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S75>/Brake Control' incorporates:
           *  ActionPort: '<S77>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S75>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S75>/Move Control' incorporates:
             *  ActionPort: '<S79>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S75>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_be);

            /* End of SystemReset for SubSystem: '<S75>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S75>/Move Control' incorporates:
           *  ActionPort: '<S79>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_k,
                          &FMS_ConstB.MoveControl_be, &FMS_DW.MoveControl_be);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S75>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S75>/Switch Case' */

        /* SwitchCase: '<S86>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S22>/Signal Copy1'
         *  SignalConversion: '<S22>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_j;
        FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
        switch (rtb_state_ki) {
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
            /* SystemReset for IfAction SubSystem: '<S86>/Hold Control' incorporates:
             *  ActionPort: '<S89>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S86>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S86>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S86>/Hold Control' incorporates:
           *  ActionPort: '<S89>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                             &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S86>/Brake Control' incorporates:
           *  ActionPort: '<S88>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S86>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S86>/Move Control' incorporates:
             *  ActionPort: '<S90>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S86>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_mr);

            /* End of SystemReset for SubSystem: '<S86>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S86>/Move Control' incorporates:
           *  ActionPort: '<S90>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_mr, &FMS_DW.MoveControl_mr);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S86>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  BusAssignment: '<S34>/Bus Assignment'
         *  Constant: '<S34>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S34>/Bus Assignment' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S86>/Saturation' */
        if (FMS_B.Merge_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_d;
        }

        /* End of Saturate: '<S86>/Saturation' */

        /* Saturate: '<S99>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S99>/Saturation1' */

        /* Saturate: '<S75>/Saturation1' */
        if (FMS_B.Merge_k > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_k < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S34>/Bus Assignment' incorporates:
           *  BusAssignment: '<S24>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_k;
        }

        /* End of Saturate: '<S75>/Saturation1' */
        /* End of Outputs for SubSystem: '<S27>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S27>/Unknown' incorporates:
         *  ActionPort: '<S36>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S24>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S27>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S27>/Switch Case' */
      /* End of Outputs for SubSystem: '<S23>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S23>/Manual' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S24>/Bus Assignment'
       *  BusAssignment: '<S29>/Bus Assignment'
       *  Constant: '<S29>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S29>/Bus Assignment' incorporates:
       *  BusAssignment: '<S24>/Bus Assignment'
       *  Constant: '<S29>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S23>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S23>/Unknown' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S24>/Bus Assignment'
       */
      FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S23>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S23>/Switch Case' */
    /* End of Outputs for SubSystem: '<S21>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S21>/Switch Case' */

  /* BusAssignment: '<S24>/Bus Assignment' incorporates:
   *  Constant: '<S24>/Constant'
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   *  DiscreteIntegrator: '<S424>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S22>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S24>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

  /* Update for DiscreteIntegrator: '<S424>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S424>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Update for DiscreteIntegrator: '<S440>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S440>/Gain'
   *  Sum: '<S440>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S441>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S441>/Gain'
   *  Sum: '<S441>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

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
  rtb_Gain_a = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain_a < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Gain_a;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S20>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S16>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S17>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

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
  rtb_Gain_a = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain_a < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = (uint32_T)rtb_Gain_a;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = MAX_uint32_T;
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
  /* Start for SwitchCase: '<S21>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S21>/Arm' */
  /* Start for SwitchCase: '<S23>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S23>/SubMode' */
  /* Start for SwitchCase: '<S30>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_at = -1;

  /* Start for IfAction SubSystem: '<S30>/Return' */
  /* Start for SwitchCase: '<S385>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S375>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S30>/Return' */

  /* Start for IfAction SubSystem: '<S30>/Hold' */
  /* Start for SwitchCase: '<S331>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S309>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S319>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S30>/Hold' */
  /* End of Start for SubSystem: '<S23>/SubMode' */

  /* Start for IfAction SubSystem: '<S23>/Auto' */
  /* Start for SwitchCase: '<S28>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S28>/Mission' */
  /* Start for Resettable SubSystem: '<S136>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S181>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S171>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S136>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S28>/Mission' */
  /* End of Start for SubSystem: '<S23>/Auto' */

  /* Start for IfAction SubSystem: '<S23>/Assist' */
  /* Start for SwitchCase: '<S27>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S27>/Stabilize' */
  /* Start for SwitchCase: '<S123>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S27>/Stabilize' */

  /* Start for IfAction SubSystem: '<S27>/Altitude' */
  /* Start for SwitchCase: '<S42>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S59>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S27>/Altitude' */

  /* Start for IfAction SubSystem: '<S27>/Position' */
  /* Start for SwitchCase: '<S99>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S75>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S86>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S27>/Position' */
  /* End of Start for SubSystem: '<S23>/Assist' */
  /* End of Start for SubSystem: '<S21>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S440>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S441>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

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
  /* SystemInitialize for IfAction SubSystem: '<S21>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S23>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S30>/Return' */
  /* InitializeConditions for Delay: '<S371>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S412>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_p = 0.0F;

  /* InitializeConditions for Delay: '<S351>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for Delay: '<S352>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S355>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S355>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S386>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S385>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S385>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S385>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S385>/Move Control' */

  /* SystemInitialize for Merge: '<S385>/Merge' */
  FMS_B.Merge_mv[0] = 0.0F;
  FMS_B.Merge_mv[1] = 0.0F;

  /* SystemInitialize for Chart: '<S376>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S375>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S375>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S375>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S375>/Move Control' */

  /* SystemInitialize for Merge: '<S375>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S30>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S30>/Hold' */
  /* SystemInitialize for Chart: '<S310>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S320>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S332>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S331>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S331>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S331>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S331>/Move Control' */

  /* SystemInitialize for Merge: '<S331>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S309>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S309>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S309>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S309>/Move Control' */

  /* SystemInitialize for Merge: '<S309>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S319>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_kq);

  /* End of SystemInitialize for SubSystem: '<S319>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S319>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S319>/Move Control' */

  /* SystemInitialize for Merge: '<S319>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S30>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S23>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S23>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S28>/Mission' */
  /* InitializeConditions for UnitDelay: '<S139>/Delay Input1'
   *
   * Block description for '<S139>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S136>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S164>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S208>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S144>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S147>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S147>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S182>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S181>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S181>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S181>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S181>/Move Control' */

  /* SystemInitialize for Merge: '<S181>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S172>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S171>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S171>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S171>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S171>/Move Control' */

  /* SystemInitialize for Merge: '<S171>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S136>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S28>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S23>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S23>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S27>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jt = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
  FMS_DW.Integrator_DSTATE_cq = 0.0F;

  /* SystemInitialize for Chart: '<S124>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S123>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S123>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S123>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S123>/Move Control' */

  /* SystemInitialize for Merge: '<S123>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S27>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S27>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S55>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S55>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S56>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S56>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S43>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S42>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S42>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S42>/Move Control' */

  /* SystemInitialize for Chart: '<S60>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S59>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S59>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S59>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_cr);

  /* End of SystemInitialize for SubSystem: '<S59>/Move Control' */

  /* SystemInitialize for Merge: '<S42>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Merge: '<S59>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S27>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S27>/Position' */
  /* SystemInitialize for Chart: '<S76>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for Chart: '<S87>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S100>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S99>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S99>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S99>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S99>/Move Control' */

  /* SystemInitialize for Merge: '<S99>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S75>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S75>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S75>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_be);

  /* End of SystemInitialize for SubSystem: '<S75>/Move Control' */

  /* SystemInitialize for Merge: '<S75>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S86>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S86>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S86>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_mr);

  /* End of SystemInitialize for SubSystem: '<S86>/Move Control' */

  /* SystemInitialize for Merge: '<S86>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S27>/Position' */
  /* End of SystemInitialize for SubSystem: '<S23>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S21>/Arm' */
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
