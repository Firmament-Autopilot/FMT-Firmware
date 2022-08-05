/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1752
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug  5 21:43:03 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S282>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S292>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

/* Named constants for Chart: '<S119>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S38>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S226>/Motion State' */
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
#define FMS_IN_Loiter                  ((uint8_T)3U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)4U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_h                ((uint8_T)5U)
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
#define FMS_IN_Other                   ((uint8_T)5U)
#define FMS_IN_Position_f              ((uint8_T)6U)
#define FMS_IN_Stabilize_j             ((uint8_T)7U)

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
  0U,                                  /* throttle_cmd */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  ,                                    /* actuator_cmd */
  0U,                                  /* status */
  0U,                                  /* state */
  0U,                                  /* ctrl_mode */
  0U,                                  /* reset */
  0U,                                  /* mode */
  0U,                                  /* reserved1 */
  0U,                                  /* wp_consume */
  0U                                   /* wp_current */
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
                                        *   '<S332>/Constant'
                                        *   '<S209>/L1'
                                        *   '<S35>/Gain'
                                        *   '<S35>/Gain1'
                                        *   '<S109>/Gain'
                                        *   '<S109>/Gain1'
                                        *   '<S135>/L1'
                                        *   '<S250>/Saturation1'
                                        *   '<S323>/Gain2'
                                        *   '<S323>/Saturation1'
                                        *   '<S37>/Saturation1'
                                        *   '<S48>/Dead Zone'
                                        *   '<S48>/Gain'
                                        *   '<S49>/Dead Zone'
                                        *   '<S49>/Gain'
                                        *   '<S54>/Saturation'
                                        *   '<S70>/Saturation1'
                                        *   '<S81>/Saturation'
                                        *   '<S94>/Saturation1'
                                        *   '<S112>/Dead Zone'
                                        *   '<S112>/Gain'
                                        *   '<S113>/Dead Zone'
                                        *   '<S113>/Gain'
                                        *   '<S118>/Saturation'
                                        *   '<S215>/Saturation1'
                                        *   '<S225>/Saturation'
                                        *   '<S237>/Saturation1'
                                        *   '<S251>/Gain2'
                                        *   '<S273>/vel'
                                        *   '<S273>/Saturation'
                                        *   '<S273>/Switch'
                                        *   '<S40>/Gain2'
                                        *   '<S41>/Gain1'
                                        *   '<S46>/Constant'
                                        *   '<S57>/Gain2'
                                        *   '<S58>/Gain1'
                                        *   '<S65>/Constant'
                                        *   '<S73>/Gain2'
                                        *   '<S74>/Gain1'
                                        *   '<S79>/Constant'
                                        *   '<S84>/Gain2'
                                        *   '<S85>/Gain1'
                                        *   '<S92>/Constant'
                                        *   '<S97>/Gain2'
                                        *   '<S98>/Gain6'
                                        *   '<S106>/Constant'
                                        *   '<S107>/Constant'
                                        *   '<S121>/Gain2'
                                        *   '<S122>/Gain1'
                                        *   '<S129>/Constant'
                                        *   '<S154>/Gain'
                                        *   '<S154>/Saturation1'
                                        *   '<S155>/vel'
                                        *   '<S155>/Saturation'
                                        *   '<S155>/Switch'
                                        *   '<S218>/Gain2'
                                        *   '<S219>/Gain1'
                                        *   '<S228>/Gain2'
                                        *   '<S229>/Gain1'
                                        *   '<S240>/Gain2'
                                        *   '<S241>/Gain6'
                                        *   '<S260>/Gain2'
                                        *   '<S260>/Saturation'
                                        *   '<S261>/Integrator'
                                        *   '<S43>/Dead Zone'
                                        *   '<S43>/Gain'
                                        *   '<S62>/Dead Zone'
                                        *   '<S62>/Gain'
                                        *   '<S76>/Dead Zone'
                                        *   '<S76>/Gain'
                                        *   '<S89>/Dead Zone'
                                        *   '<S89>/Gain'
                                        *   '<S102>/Dead Zone'
                                        *   '<S102>/Gain'
                                        *   '<S103>/Dead Zone'
                                        *   '<S103>/Gain'
                                        *   '<S126>/Dead Zone'
                                        *   '<S126>/Gain'
                                        *   '<S141>/Gain2'
                                        *   '<S141>/Saturation'
                                        *   '<S142>/Integrator'
                                        *   '<S221>/Dead Zone'
                                        *   '<S221>/Gain'
                                        *   '<S233>/Dead Zone'
                                        *   '<S233>/Gain'
                                        *   '<S245>/Dead Zone'
                                        *   '<S245>/Gain'
                                        *   '<S246>/Dead Zone'
                                        *   '<S246>/Gain'
                                        *   '<S281>/Saturation1'
                                        *   '<S291>/Saturation1'
                                        *   '<S166>/Saturation1'
                                        *   '<S176>/Saturation1'
                                        *   '<S284>/Gain2'
                                        *   '<S285>/Gain1'
                                        *   '<S294>/Gain2'
                                        *   '<S295>/Gain6'
                                        *   '<S169>/Gain2'
                                        *   '<S170>/Gain1'
                                        *   '<S179>/Gain2'
                                        *   '<S180>/Gain6'
                                        *   '<S287>/Dead Zone'
                                        *   '<S287>/Gain'
                                        *   '<S299>/Dead Zone'
                                        *   '<S299>/Gain'
                                        *   '<S300>/Dead Zone'
                                        *   '<S300>/Gain'
                                        *   '<S172>/Dead Zone'
                                        *   '<S172>/Gain'
                                        *   '<S184>/Dead Zone'
                                        *   '<S184>/Gain'
                                        *   '<S185>/Dead Zone'
                                        *   '<S185>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 48, 46, 51, 46, 55, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S6>/Constant1'
                                        *   '<S330>/Constant'
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
 *    '<S16>/Disarm'
 *    '<S25>/Unknown'
 *    '<S23>/Unknown'
 *    '<S22>/Unknown'
 *    '<S18>/Unknown'
 */
void FMS_Disarm(FMS_Out_Bus *rty_FMS_Out, const ConstB_Disarm_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S20>/Bus Assignment' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant2'
   *  SignalConversion: '<S20>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S20>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S281>/Hold Control'
 *    '<S215>/Hold Control'
 *    '<S166>/Hold Control'
 *    '<S37>/Hold Control'
 *    '<S70>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S284>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S281>/Hold Control'
 *    '<S215>/Hold Control'
 *    '<S166>/Hold Control'
 *    '<S37>/Hold Control'
 *    '<S70>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S284>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S281>/Hold Control'
 *    '<S215>/Hold Control'
 *    '<S166>/Hold Control'
 *    '<S37>/Hold Control'
 *    '<S70>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S284>/Delay' incorporates:
   *  Gain: '<S286>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S284>/Gain2' incorporates:
   *  Delay: '<S284>/Delay'
   *  Gain: '<S286>/Gain'
   *  Sum: '<S284>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S284>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S281>/Brake Control'
 *    '<S215>/Brake Control'
 *    '<S225>/Brake Control'
 *    '<S166>/Brake Control'
 *    '<S118>/Brake Control'
 *    '<S37>/Brake Control'
 *    '<S54>/Brake Control'
 *    '<S70>/Brake Control'
 *    '<S81>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S283>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S283>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S281>/Move Control'
 *    '<S215>/Move Control'
 *    '<S166>/Move Control'
 *    '<S37>/Move Control'
 *    '<S70>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S288>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S288>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S281>/Move Control'
 *    '<S215>/Move Control'
 *    '<S166>/Move Control'
 *    '<S37>/Move Control'
 *    '<S70>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S288>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S288>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S281>/Move Control'
 *    '<S215>/Move Control'
 *    '<S166>/Move Control'
 *    '<S37>/Move Control'
 *    '<S70>/Move Control'
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

  /* Product: '<S289>/Multiply1' incorporates:
   *  Constant: '<S289>/const1'
   *  DiscreteIntegrator: '<S288>/Integrator'
   */
  rtb_Add3_c = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S287>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = 0.0F;
  } else {
    rtb_a_hr = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S287>/Dead Zone' */

  /* Sum: '<S289>/Add' incorporates:
   *  DiscreteIntegrator: '<S288>/Integrator1'
   *  Gain: '<S285>/Gain1'
   *  Gain: '<S287>/Gain'
   *  Sum: '<S288>/Subtract'
   */
  rtb_Subtract3_dn = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_hr * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_c;

  /* Signum: '<S289>/Sign' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_a_hr = -1.0F;
  } else if (rtb_Subtract3_dn > 0.0F) {
    rtb_a_hr = 1.0F;
  } else {
    rtb_a_hr = rtb_Subtract3_dn;
  }

  /* End of Signum: '<S289>/Sign' */

  /* Sum: '<S289>/Add2' incorporates:
   *  Abs: '<S289>/Abs'
   *  Gain: '<S289>/Gain'
   *  Gain: '<S289>/Gain1'
   *  Product: '<S289>/Multiply2'
   *  Product: '<S289>/Multiply3'
   *  Sqrt: '<S289>/Sqrt'
   *  Sum: '<S289>/Add1'
   *  Sum: '<S289>/Subtract'
   */
  rtb_a_hr = (sqrtf((8.0F * fabsf(rtb_Subtract3_dn) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_hr + rtb_Add3_c;

  /* Sum: '<S289>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_dn - rtb_a_hr) + rtb_Add3_c;

  /* Sum: '<S289>/Add3' */
  rtb_Add3_c = rtb_Subtract3_dn + localC->d;

  /* Sum: '<S289>/Subtract1' */
  rtb_Subtract3_dn -= localC->d;

  /* Signum: '<S289>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S289>/Sign1' */

  /* Signum: '<S289>/Sign2' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S289>/Sign2' */

  /* Sum: '<S289>/Add5' incorporates:
   *  Gain: '<S289>/Gain2'
   *  Product: '<S289>/Multiply4'
   *  Sum: '<S289>/Subtract2'
   */
  rtb_a_hr += (rtb_Add3_c - rtb_Subtract3_dn) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S285>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S288>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S288>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S288>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S289>/Add6' */
  rtb_Add3_c = rtb_a_hr + localC->d;

  /* Sum: '<S289>/Subtract3' */
  rtb_Subtract3_dn = rtb_a_hr - localC->d;

  /* Signum: '<S289>/Sign5' */
  if (rtb_a_hr < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_hr;
  }

  /* End of Signum: '<S289>/Sign5' */

  /* Signum: '<S289>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S289>/Sign3' */

  /* Signum: '<S289>/Sign4' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S289>/Sign4' */

  /* Signum: '<S289>/Sign6' */
  if (rtb_a_hr < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_a_hr;
  }

  /* End of Signum: '<S289>/Sign6' */

  /* Update for DiscreteIntegrator: '<S288>/Integrator' incorporates:
   *  Constant: '<S289>/const'
   *  Gain: '<S289>/Gain3'
   *  Product: '<S289>/Divide'
   *  Product: '<S289>/Multiply5'
   *  Product: '<S289>/Multiply6'
   *  Sum: '<S289>/Subtract4'
   *  Sum: '<S289>/Subtract5'
   *  Sum: '<S289>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_hr / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3_c - rtb_Subtract3_dn) * 0.5F) - rtb_a_b * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S282>/Motion Status'
 *    '<S216>/Motion Status'
 *    '<S167>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S282>/Motion Status'
 *    '<S216>/Motion Status'
 *    '<S167>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S282>/Motion Status'
 *    '<S216>/Motion Status'
 *    '<S167>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S282>/Motion Status' */
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

  /* End of Chart: '<S282>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S291>/Hold Control'
 *    '<S237>/Hold Control'
 *    '<S176>/Hold Control'
 *    '<S94>/Hold Control'
 */
void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S294>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S291>/Hold Control'
 *    '<S237>/Hold Control'
 *    '<S176>/Hold Control'
 *    '<S94>/Hold Control'
 */
void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S294>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S291>/Hold Control'
 *    '<S237>/Hold Control'
 *    '<S176>/Hold Control'
 *    '<S94>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T rtu_FMS_In_p, real32_T
  rtu_FMS_In_b, real32_T rty_uv_cmd_mPs[2], const ConstB_HoldControl_FMS_k_T
  *localC, DW_HoldControl_FMS_l_T *localDW)
{
  real32_T rtb_VectorConcatenate_k[9];
  real32_T rtb_VectorConcatenate_b[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_b_tmp;
  real32_T rtb_VectorConcatenate_b_tmp_0;

  /* Delay: '<S294>/Delay' incorporates:
   *  SignalConversion: '<S294>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_p;
  }

  /* Trigonometry: '<S298>/Trigonometric Function1' incorporates:
   *  Gain: '<S297>/Gain'
   *  Trigonometry: '<S298>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_b_tmp_0 = arm_cos_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_b_tmp_0;

  /* Trigonometry: '<S298>/Trigonometric Function' incorporates:
   *  Gain: '<S297>/Gain'
   *  Trigonometry: '<S298>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_b_tmp = arm_sin_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_b_tmp;

  /* SignalConversion: '<S298>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S298>/Constant3'
   */
  rtb_VectorConcatenate_k[2] = 0.0F;

  /* Gain: '<S298>/Gain' */
  rtb_VectorConcatenate_k[3] = -rtb_VectorConcatenate_b_tmp;

  /* Trigonometry: '<S298>/Trigonometric Function3' */
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_b_tmp_0;

  /* SignalConversion: '<S298>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S298>/Constant4'
   */
  rtb_VectorConcatenate_k[5] = 0.0F;

  /* SignalConversion: '<S298>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_k[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_k[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_k[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S294>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S294>/Delay'
   *  SignalConversion: '<S294>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S294>/Sum'
   */
  rtb_VectorConcatenate_b_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_b_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_p;

  /* Product: '<S294>/Multiply' incorporates:
   *  SignalConversion: '<S294>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_b[i] = rtb_VectorConcatenate_k[i + 3] *
      rtb_VectorConcatenate_b_tmp + rtb_VectorConcatenate_k[i] *
      rtb_VectorConcatenate_b_tmp_0;
  }

  /* End of Product: '<S294>/Multiply' */

  /* Gain: '<S294>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_b[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_b[1];

  /* Update for Delay: '<S294>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S291>/Brake Control'
 *    '<S237>/Brake Control'
 *    '<S176>/Brake Control'
 *    '<S94>/Brake Control'
 */
void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S293>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S291>/Move Control'
 *    '<S237>/Move Control'
 *    '<S176>/Move Control'
 *    '<S94>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S291>/Move Control'
 *    '<S237>/Move Control'
 *    '<S176>/Move Control'
 *    '<S94>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S291>/Move Control'
 *    '<S237>/Move Control'
 *    '<S176>/Move Control'
 *    '<S94>/Move Control'
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

  /* SignalConversion: '<S295>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S301>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S302>/Multiply1' incorporates:
   *  Constant: '<S302>/const1'
   *  DiscreteIntegrator: '<S301>/Integrator'
   */
  rtb_Add3_e1_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S295>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S301>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S302>/Multiply1' incorporates:
   *  Constant: '<S302>/const1'
   *  DiscreteIntegrator: '<S301>/Integrator'
   */
  rtb_Add3_e1_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S299>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S299>/Dead Zone' */

  /* Sum: '<S302>/Add' incorporates:
   *  DiscreteIntegrator: '<S301>/Integrator1'
   *  Gain: '<S295>/Gain6'
   *  Gain: '<S299>/Gain'
   *  Sum: '<S301>/Subtract'
   */
  rtb_Subtract3_h_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_0;

  /* DeadZone: '<S300>/Dead Zone' */
  if (rtu_FMS_In_g > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_g >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S300>/Dead Zone' */

  /* Sum: '<S302>/Add' incorporates:
   *  DiscreteIntegrator: '<S301>/Integrator1'
   *  Gain: '<S295>/Gain6'
   *  Gain: '<S300>/Gain'
   *  Sum: '<S301>/Subtract'
   */
  rtb_Subtract3_h_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_1;

  /* Signum: '<S302>/Sign' */
  if (rtb_Subtract3_h_idx_0 < 0.0F) {
    rtb_Subtract3_h_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0 > 0.0F) {
    rtb_Subtract3_h_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0_0 = rtb_Subtract3_h_idx_0;
  }

  /* Sum: '<S302>/Add2' incorporates:
   *  Abs: '<S302>/Abs'
   *  Gain: '<S302>/Gain'
   *  Gain: '<S302>/Gain1'
   *  Product: '<S302>/Multiply2'
   *  Product: '<S302>/Multiply3'
   *  Signum: '<S302>/Sign'
   *  Sqrt: '<S302>/Sqrt'
   *  Sum: '<S302>/Add1'
   *  Sum: '<S302>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_h_idx_0_0 +
    rtb_Add3_e1_idx_0;

  /* Sum: '<S302>/Add3' incorporates:
   *  Signum: '<S302>/Sign'
   */
  u = rtb_Subtract3_h_idx_0 + localC->d;

  /* Sum: '<S302>/Subtract1' incorporates:
   *  Signum: '<S302>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_0 - localC->d;

  /* Signum: '<S302>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S302>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S302>/Add5' incorporates:
   *  Gain: '<S302>/Gain2'
   *  Product: '<S302>/Multiply4'
   *  Signum: '<S302>/Sign'
   *  Sum: '<S302>/Add2'
   *  Sum: '<S302>/Add4'
   *  Sum: '<S302>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_0 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_0) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S301>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S301>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S302>/Sign3' incorporates:
   *  Sum: '<S302>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S302>/Sign4' incorporates:
   *  Sum: '<S302>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S302>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S302>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S302>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S302>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S301>/Integrator' incorporates:
   *  Constant: '<S302>/const'
   *  Gain: '<S302>/Gain3'
   *  Product: '<S302>/Divide'
   *  Product: '<S302>/Multiply5'
   *  Product: '<S302>/Multiply6'
   *  Sum: '<S302>/Subtract4'
   *  Sum: '<S302>/Subtract5'
   *  Sum: '<S302>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;

  /* Signum: '<S302>/Sign' */
  if (rtb_Subtract3_h_idx_1 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_1 > 0.0F) {
    rtb_Add3_e1_idx_0 = 1.0F;
  } else {
    rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_1;
  }

  /* Sum: '<S302>/Add2' incorporates:
   *  Abs: '<S302>/Abs'
   *  Gain: '<S302>/Gain'
   *  Gain: '<S302>/Gain1'
   *  Product: '<S302>/Multiply2'
   *  Product: '<S302>/Multiply3'
   *  Signum: '<S302>/Sign'
   *  Sqrt: '<S302>/Sqrt'
   *  Sum: '<S302>/Add1'
   *  Sum: '<S302>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_e1_idx_0 +
    rtb_Add3_e1_idx_1;

  /* Sum: '<S302>/Add3' incorporates:
   *  Signum: '<S302>/Sign'
   */
  u = rtb_Subtract3_h_idx_1 + localC->d;

  /* Sum: '<S302>/Subtract1' incorporates:
   *  Signum: '<S302>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_1 - localC->d;

  /* Signum: '<S302>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S302>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S302>/Add5' incorporates:
   *  Gain: '<S302>/Gain2'
   *  Product: '<S302>/Multiply4'
   *  Signum: '<S302>/Sign'
   *  Sum: '<S302>/Add2'
   *  Sum: '<S302>/Add4'
   *  Sum: '<S302>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_1 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_1) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S301>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S301>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S302>/Sign3' incorporates:
   *  Sum: '<S302>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S302>/Sign4' incorporates:
   *  Sum: '<S302>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S302>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S302>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S302>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S302>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S301>/Integrator' incorporates:
   *  Constant: '<S302>/const'
   *  Gain: '<S302>/Gain3'
   *  Product: '<S302>/Divide'
   *  Product: '<S302>/Multiply5'
   *  Product: '<S302>/Multiply6'
   *  Sum: '<S302>/Subtract4'
   *  Sum: '<S302>/Subtract5'
   *  Sum: '<S302>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S292>/Motion State'
 *    '<S238>/Motion State'
 *    '<S177>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * System reset for atomic system:
 *    '<S292>/Motion State'
 *    '<S238>/Motion State'
 *    '<S177>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * Output and update for atomic system:
 *    '<S292>/Motion State'
 *    '<S238>/Motion State'
 *    '<S177>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S292>/Motion State' */
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

  /* End of Chart: '<S292>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S275>/NearbyRefWP'
 *    '<S157>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S306>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S225>/Hold Control'
 *    '<S118>/Hold Control'
 *    '<S54>/Hold Control'
 *    '<S81>/Hold Control'
 */
void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S228>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S225>/Hold Control'
 *    '<S118>/Hold Control'
 *    '<S54>/Hold Control'
 *    '<S81>/Hold Control'
 */
void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S228>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S225>/Hold Control'
 *    '<S118>/Hold Control'
 *    '<S54>/Hold Control'
 *    '<S81>/Hold Control'
 */
void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S228>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S228>/Sum' incorporates:
   *  Delay: '<S228>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S231>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S231>/Switch' incorporates:
   *  Constant: '<S231>/Constant'
   *  Constant: '<S232>/Constant'
   *  Product: '<S231>/Multiply'
   *  RelationalOperator: '<S232>/Compare'
   *  Sum: '<S231>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S231>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S231>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S231>/Switch' */

  /* Gain: '<S228>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S228>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S225>/Move Control'
 *    '<S118>/Move Control'
 *    '<S54>/Move Control'
 *    '<S81>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S225>/Move Control'
 *    '<S118>/Move Control'
 *    '<S54>/Move Control'
 *    '<S81>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S225>/Move Control'
 *    '<S118>/Move Control'
 *    '<S54>/Move Control'
 *    '<S81>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_a;
  real32_T rtb_Subtract3_i;
  real32_T rtb_a_b;
  real32_T rtb_Add4_bf;
  real32_T rtb_a_p;

  /* Product: '<S235>/Multiply1' incorporates:
   *  Constant: '<S235>/const1'
   *  DiscreteIntegrator: '<S234>/Integrator'
   */
  rtb_Add3_a = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S233>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_b = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_b = 0.0F;
  } else {
    rtb_a_b = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S233>/Dead Zone' */

  /* Sum: '<S235>/Add' incorporates:
   *  DiscreteIntegrator: '<S234>/Integrator1'
   *  Gain: '<S229>/Gain1'
   *  Gain: '<S233>/Gain'
   *  Sum: '<S234>/Subtract'
   */
  rtb_Subtract3_i = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_b * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_a;

  /* Signum: '<S235>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_Subtract3_i;
  }

  /* End of Signum: '<S235>/Sign' */

  /* Sum: '<S235>/Add2' incorporates:
   *  Abs: '<S235>/Abs'
   *  Gain: '<S235>/Gain'
   *  Gain: '<S235>/Gain1'
   *  Product: '<S235>/Multiply2'
   *  Product: '<S235>/Multiply3'
   *  Sqrt: '<S235>/Sqrt'
   *  Sum: '<S235>/Add1'
   *  Sum: '<S235>/Subtract'
   */
  rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_b + rtb_Add3_a;

  /* Sum: '<S235>/Add4' */
  rtb_Add4_bf = (rtb_Subtract3_i - rtb_a_b) + rtb_Add3_a;

  /* Sum: '<S235>/Add3' */
  rtb_Add3_a = rtb_Subtract3_i + localC->d;

  /* Sum: '<S235>/Subtract1' */
  rtb_Subtract3_i -= localC->d;

  /* Signum: '<S235>/Sign1' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S235>/Sign1' */

  /* Signum: '<S235>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S235>/Sign2' */

  /* Sum: '<S235>/Add5' incorporates:
   *  Gain: '<S235>/Gain2'
   *  Product: '<S235>/Multiply4'
   *  Sum: '<S235>/Subtract2'
   */
  rtb_a_b += (rtb_Add3_a - rtb_Subtract3_i) * 0.5F * rtb_Add4_bf;

  /* SignalConversion: '<S229>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S234>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S234>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S234>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S235>/Add6' */
  rtb_Add3_a = rtb_a_b + localC->d;

  /* Sum: '<S235>/Subtract3' */
  rtb_Subtract3_i = rtb_a_b - localC->d;

  /* Signum: '<S235>/Sign5' */
  if (rtb_a_b < 0.0F) {
    rtb_Add4_bf = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_Add4_bf = 1.0F;
  } else {
    rtb_Add4_bf = rtb_a_b;
  }

  /* End of Signum: '<S235>/Sign5' */

  /* Signum: '<S235>/Sign3' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S235>/Sign3' */

  /* Signum: '<S235>/Sign4' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S235>/Sign4' */

  /* Signum: '<S235>/Sign6' */
  if (rtb_a_b < 0.0F) {
    rtb_a_p = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_a_p = 1.0F;
  } else {
    rtb_a_p = rtb_a_b;
  }

  /* End of Signum: '<S235>/Sign6' */

  /* Update for DiscreteIntegrator: '<S234>/Integrator' incorporates:
   *  Constant: '<S235>/const'
   *  Gain: '<S235>/Gain3'
   *  Product: '<S235>/Divide'
   *  Product: '<S235>/Multiply5'
   *  Product: '<S235>/Multiply6'
   *  Sum: '<S235>/Subtract4'
   *  Sum: '<S235>/Subtract5'
   *  Sum: '<S235>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_b / localC->d - rtb_Add4_bf) *
    localC->Gain4 * ((rtb_Add3_a - rtb_Subtract3_i) * 0.5F) - rtb_a_p *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S119>/Motion State'
 *    '<S55>/Motion State'
 *    '<S82>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S119>/Motion State'
 *    '<S55>/Motion State'
 *    '<S82>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S119>/Motion State'
 *    '<S55>/Motion State'
 *    '<S82>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S119>/Motion State' */
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

  /* End of Chart: '<S119>/Motion State' */
}

/*
 * System initialize for atomic system:
 *    '<S38>/Motion Status'
 *    '<S71>/Motion Status'
 */
void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S38>/Motion Status'
 *    '<S71>/Motion Status'
 */
void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S38>/Motion Status'
 *    '<S71>/Motion Status'
 */
void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW)
{
  /* Chart: '<S38>/Motion Status' */
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

  /* End of Chart: '<S38>/Motion Status' */
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

/* Output and update for function-call system: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
void F_VehicleArmAutoMissionLLA2FLAT(const real_T rtu_lla[3], const real_T
  rtu_llo[2], real_T rtu_href, real_T rtu_psio, real32_T rty_pos[3], const
  ConstB_VehicleArmAutoMissionL_T *localC)
{
  real_T rtb_Sum2_m;
  real_T rtb_Gain_d;
  real_T rtb_Sum3;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S334>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S335>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S335>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S335>/Multiply1' incorporates:
   *  Product: '<S335>/Multiply'
   */
  rtb_Gain_d = localC->ff * rtb_Sum2_m;

  /* Product: '<S335>/Divide' incorporates:
   *  Constant: '<S335>/Constant'
   *  Constant: '<S335>/R'
   *  Sqrt: '<S335>/Sqrt'
   *  Sum: '<S335>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_d);

  /* Product: '<S335>/Product3' incorporates:
   *  Constant: '<S335>/Constant1'
   *  Product: '<S335>/Multiply1'
   *  Sum: '<S335>/Sum2'
   */
  rtb_Gain_d = 1.0 / (1.0 - rtb_Gain_d) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S335>/Multiply2' incorporates:
   *  Trigonometry: '<S335>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S334>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S339>/Abs' incorporates:
   *  Abs: '<S342>/Abs1'
   *  Switch: '<S339>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S339>/Switch1' incorporates:
   *  Abs: '<S339>/Abs'
   *  Bias: '<S339>/Bias2'
   *  Bias: '<S339>/Bias3'
   *  Constant: '<S336>/Constant'
   *  Constant: '<S336>/Constant1'
   *  Constant: '<S341>/Constant'
   *  Gain: '<S339>/Gain1'
   *  Product: '<S339>/Multiply'
   *  RelationalOperator: '<S341>/Compare'
   *  Switch: '<S336>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S342>/Switch1' incorporates:
     *  Bias: '<S342>/Bias2'
     *  Bias: '<S342>/Bias3'
     *  Constant: '<S342>/Constant'
     *  Constant: '<S343>/Constant'
     *  Math: '<S342>/Math Function'
     *  RelationalOperator: '<S343>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S342>/Switch1' */

    /* Signum: '<S339>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S339>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S336>/Sum' incorporates:
   *  Sum: '<S334>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S334>/Multiply' incorporates:
   *  Gain: '<S334>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_d;

  /* Switch: '<S338>/Switch1' incorporates:
   *  Abs: '<S338>/Abs1'
   *  Bias: '<S338>/Bias2'
   *  Bias: '<S338>/Bias3'
   *  Constant: '<S338>/Constant'
   *  Constant: '<S340>/Constant'
   *  Math: '<S338>/Math Function'
   *  RelationalOperator: '<S340>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S338>/Switch1' */

  /* Product: '<S334>/Multiply' incorporates:
   *  Gain: '<S334>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

  /* Gain: '<S334>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S337>/SinCos' */
  rtb_Sum3 = sin(rtb_Sum2_m);
  rtb_Gain_d = cos(rtb_Sum2_m);

  /* Sum: '<S337>/Sum2' incorporates:
   *  Product: '<S337>/Multiply1'
   *  Product: '<S337>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_d + rtb_Sum_d * rtb_Sum3;

  /* Product: '<S337>/Multiply3' */
  rtb_Sum3 *= rtb_Sum_e_idx_0;

  /* Product: '<S337>/Multiply4' */
  rtb_Gain_d *= rtb_Sum_d;

  /* Sum: '<S337>/Sum3' */
  rtb_Sum3 = rtb_Gain_d - rtb_Sum3;

  /* DataTypeConversion: '<S331>/Data Type Conversion' incorporates:
   *  Gain: '<S334>/Gain'
   *  Sum: '<S334>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_m;
  rty_pos[1] = (real32_T)rtb_Sum3;
  rty_pos[2] = (real32_T)-(rtu_lla[2] + rtu_href);
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Stabilize(void)
{
  /* Inport: '<Root>/INS_Out' */
  if ((FMS_U.INS_Out.flag & 4U) != 0U) {
    FMS_B.target_mode = PilotMode_Stabilize;

    /* Delay: '<S8>/Delay' */
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

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S8>/Delay' */
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

    /* Delay: '<S8>/Delay' */
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

     default:
      FMS_DW.is_c3_FMS = FMS_IN_Other;
      break;
    }

    /* End of Delay: '<S8>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
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
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_p, &FMS_DW.M_msgReservedData);
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_p, &FMS_DW.Msg_FMS_Cmd_c
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_c[0] : NULL;
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

         case FMS_IN_Loiter:
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

            /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
            F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
              FMS_B.psio, FMS_B.DataTypeConversion,
              &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

            /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
            FMS_B.Cmd_In.sp_takeoff[0] = FMS_B.DataTypeConversion[0];
            FMS_B.Cmd_In.sp_takeoff[1] = FMS_B.DataTypeConversion[1];
            FMS_B.Cmd_In.sp_takeoff[2] = FMS_B.DataTypeConversion[2];
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

            /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
            F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
              FMS_B.psio, FMS_B.DataTypeConversion,
              &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

            /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
            FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
            FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
            FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
            FMS_B.state = VehicleState_Mission;
          } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Land) {
            FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
            FMS_DW.is_Mission = FMS_IN_Land;
            FMS_B.Cmd_In.sp_land[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.sp_land[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_B.state = VehicleState_Land;
            FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
          } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
            FMS_DW.is_Mission = FMS_IN_Return_h;
            FMS_B.Cmd_In.sp_return[0] = FMS_DW.home[0];
            FMS_B.Cmd_In.sp_return[1] = FMS_DW.home[1];
            FMS_B.state = VehicleState_Return;
          } else if (FMS_B.on_ground) {
            FMS_DW.is_Mission = FMS_IN_Disarming;
          } else {
            FMS_DW.is_Mission = FMS_IN_Loiter;
            FMS_B.state = VehicleState_Hold;
          }
          break;

         case FMS_IN_Return_h:
          tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
            FMS_B.Cmd_In.sp_return[0];
          tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
            FMS_B.Cmd_In.sp_return[1];
          if (FMS_norm(tmp) < 0.5F) {
            FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
            FMS_DW.is_Mission = FMS_IN_Land;
            FMS_B.Cmd_In.sp_land[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.sp_land[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_B.state = VehicleState_Land;
            FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
          }
          break;

         case FMS_IN_Takeoff_d:
          if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
              FMS_B.Cmd_In.sp_takeoff[2]) {
            FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_takeoff[0];
            FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_takeoff[1];
            FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_takeoff[2];
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
    FMS_B.state = VehicleState_Offboard;
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

  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S344>/Compare' incorporates:
   *  Abs: '<S333>/Abs'
   *  Constant: '<S344>/Constant'
   *  MinMax: '<S333>/Max'
   *  Sum: '<S333>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S3>/Vehicle.StickMoved' */
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
        if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_j >= 500) {
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
          FMS_B.Cmd_In.sp_land[0] = FMS_DW.home[0];
          FMS_B.Cmd_In.sp_land[1] = FMS_DW.home[1];
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_SubMode = FMS_IN_Land;
          FMS_B.state = VehicleState_Land;
          FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
        }

        /* End of Constant: '<Root>/ACCEPT_R' */
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_takeoff[2]) {
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
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
      FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1_k = condIsTrue;
    if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_k >=
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
        if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = condIsTrue;
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

    /* Outputs for Function Call SubSystem: '<S3>/Vehicle.PrepTakeoff' */
    /* Reshape: '<S332>/Reshape' incorporates:
     *  Constant: '<S332>/Constant'
     */
    FMS_B.Reshape[0] = FMS_B.xy_R[0];
    FMS_B.Reshape[1] = FMS_B.xy_R[1];
    FMS_B.Reshape[2] = FMS_PARAM.TAKEOFF_H;

    /* End of Outputs for SubSystem: '<S3>/Vehicle.PrepTakeoff' */
    FMS_B.Cmd_In.sp_takeoff[0] = FMS_B.Reshape[0];
    FMS_B.Cmd_In.sp_takeoff[1] = FMS_B.Reshape[1];
    FMS_B.Cmd_In.sp_takeoff[2] = FMS_B.Reshape[2];
    FMS_B.Cmd_In.sp_takeoff[2] += FMS_DW.home[2];
    FMS_DW.prep_takeoff = 0.0;
    condIsTrue = (FMS_DW.prep_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
      FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1_k = condIsTrue;
    FMS_DW.prep_mission_takeoff = 0.0;
    condIsTrue = (FMS_DW.prep_mission_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_2 = condIsTrue;
    FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Vehicle = FMS_IN_Arm;
    FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_B.on_ground;
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
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
      FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1_k = condIsTrue;
    FMS_DW.prep_mission_takeoff = 0.0;
    condIsTrue = (FMS_DW.prep_mission_takeoff == 1.0);
    if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_2 = condIsTrue;
    FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Vehicle = FMS_IN_Arm;
    FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_B.on_ground;
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
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
      if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d0)) {
        FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_B.on_ground;
      if ((FMS_DW.chartAbsoluteTimeCounter -
           FMS_DW.durationLastReferenceTick_1_c >= 500) && (FMS_B.target_mode !=
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
          FMS_B.Cmd_In.sp_land[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
          FMS_B.Cmd_In.sp_land[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_SubMode;
          FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
          FMS_DW.stick_val[1] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
          FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
          FMS_DW.stick_val[3] =
            FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_SubMode = FMS_IN_Land;
          FMS_B.state = VehicleState_Land;
          FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
        } else {
          if (FMS_sf_msg_pop_M()) {
            sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Return);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            FMS_B.Cmd_In.sp_return[0] = FMS_DW.home[0];
            FMS_B.Cmd_In.sp_return[1] = FMS_DW.home[1];
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
              (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
            FMS_DW.durationLastReferenceTick_1_k =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
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
      FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
      FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
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
          FMS_DW.condWasTrueAtLastTimeStep_1_k = (FMS_DW.prep_takeoff == 1.0);
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
            (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
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
    FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
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
          FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_n > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
            FMS_DW.durationLastReferenceTick_2_a =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2_a > 375) {
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
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
              FMS_DW.durationLastReferenceTick_2_a =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
              FMS_DW.durationLastReferenceTick_1_n =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_p, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_c[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T A;
  real32_T B;
  real32_T D;
  real32_T rtb_Square2;
  real32_T rtb_Transpose[9];
  real32_T rtb_MatrixConcatenate3[3];
  real32_T rtb_Multiply[3];
  uint16_T rtb_Divide_b;
  int8_T rtPrevAction;
  real32_T rtb_Saturation_l;
  real32_T rtb_Saturation1_ln[2];
  MotionState rtb_state_a;
  real32_T rtb_Rem_k;
  real32_T rtb_Divide_o[2];
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  boolean_T rtb_FixPtRelationalOperator_n;
  real32_T rtb_Divide;
  real32_T rtb_TmpSignalConversionAtDela_a[2];
  int32_T i;
  real32_T rtb_Transpose_0[9];
  real32_T rtb_Transpose_1[3];
  boolean_T u;
  real32_T rtb_MathFunction_cr_idx_1;
  real32_T rtb_MathFunction_cr_idx_0;
  real32_T rtb_MathFunction_iq_idx_1;
  real32_T rtb_MathFunction_iq_idx_0;
  real32_T rtb_MathFunction_h_idx_0;
  real32_T rtb_Divide_l_idx_2;
  real32_T rtb_Divide_l_idx_1;
  real32_T u1_tmp;
  boolean_T guard1 = false;

  /* Sqrt: '<S354>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S354>/Square'
   *  Sum: '<S354>/Sum of Elements'
   */
  rtb_Square2 = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
                        FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
                       FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) +
                      FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S350>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  A = FMS_U.INS_Out.quat[0] / rtb_Square2;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Square2;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Square2;
  rtb_Square2 = FMS_U.INS_Out.quat[3] / rtb_Square2;

  /* Math: '<S351>/Square' incorporates:
   *  Math: '<S352>/Square'
   *  Math: '<S353>/Square'
   */
  rtb_Rem_k = A * A;

  /* Math: '<S351>/Square2' incorporates:
   *  Math: '<S352>/Square2'
   *  Math: '<S353>/Square2'
   */
  rtb_MathFunction_cr_idx_0 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S351>/Square1' incorporates:
   *  Math: '<S352>/Square1'
   *  Math: '<S353>/Square1'
   */
  rtb_Saturation_l = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S351>/Square3' incorporates:
   *  Math: '<S352>/Square3'
   *  Math: '<S353>/Square3'
   */
  rtb_Divide = rtb_Square2 * rtb_Square2;

  /* Sum: '<S351>/Subtract' incorporates:
   *  Math: '<S351>/Square'
   *  Math: '<S351>/Square1'
   *  Math: '<S351>/Square2'
   *  Math: '<S351>/Square3'
   *  Sum: '<S351>/Add'
   *  Sum: '<S351>/Add1'
   */
  rtb_Transpose[0] = (rtb_Rem_k + rtb_Saturation_l) - (rtb_MathFunction_cr_idx_0
    + rtb_Divide);

  /* Product: '<S351>/Multiply' incorporates:
   *  Product: '<S352>/Multiply'
   */
  rtb_MathFunction_h_idx_0 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S351>/Multiply1' incorporates:
   *  Product: '<S352>/Multiply1'
   */
  rtb_MathFunction_cr_idx_1 = A * rtb_Square2;

  /* Gain: '<S351>/Gain' incorporates:
   *  Product: '<S351>/Multiply'
   *  Product: '<S351>/Multiply1'
   *  Sum: '<S351>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_MathFunction_h_idx_0 - rtb_MathFunction_cr_idx_1) *
    2.0F;

  /* Product: '<S351>/Multiply2' incorporates:
   *  Product: '<S353>/Multiply'
   */
  rtb_MathFunction_iq_idx_0 = rtb_Divide_l_idx_1 * rtb_Square2;

  /* Product: '<S351>/Multiply3' incorporates:
   *  Product: '<S353>/Multiply1'
   */
  rtb_MathFunction_iq_idx_1 = A * rtb_Divide_l_idx_2;

  /* Gain: '<S351>/Gain1' incorporates:
   *  Product: '<S351>/Multiply2'
   *  Product: '<S351>/Multiply3'
   *  Sum: '<S351>/Add2'
   */
  rtb_Transpose[2] = (rtb_MathFunction_iq_idx_0 + rtb_MathFunction_iq_idx_1) *
    2.0F;

  /* Gain: '<S352>/Gain' incorporates:
   *  Sum: '<S352>/Add3'
   */
  rtb_Transpose[3] = (rtb_MathFunction_h_idx_0 + rtb_MathFunction_cr_idx_1) *
    2.0F;

  /* Sum: '<S352>/Subtract' incorporates:
   *  Sum: '<S352>/Add'
   *  Sum: '<S352>/Add1'
   */
  rtb_Transpose[4] = (rtb_Rem_k + rtb_MathFunction_cr_idx_0) - (rtb_Saturation_l
    + rtb_Divide);

  /* Product: '<S352>/Multiply2' incorporates:
   *  Product: '<S353>/Multiply2'
   */
  rtb_MathFunction_h_idx_0 = rtb_Divide_l_idx_2 * rtb_Square2;

  /* Product: '<S352>/Multiply3' incorporates:
   *  Product: '<S353>/Multiply3'
   */
  rtb_MathFunction_cr_idx_1 = A * rtb_Divide_l_idx_1;

  /* Gain: '<S352>/Gain1' incorporates:
   *  Product: '<S352>/Multiply2'
   *  Product: '<S352>/Multiply3'
   *  Sum: '<S352>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_MathFunction_h_idx_0 - rtb_MathFunction_cr_idx_1) *
    2.0F;

  /* Gain: '<S353>/Gain' incorporates:
   *  Sum: '<S353>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_MathFunction_iq_idx_0 - rtb_MathFunction_iq_idx_1) *
    2.0F;

  /* Gain: '<S353>/Gain1' incorporates:
   *  Sum: '<S353>/Add2'
   */
  rtb_Transpose[7] = (rtb_MathFunction_h_idx_0 + rtb_MathFunction_cr_idx_1) *
    2.0F;

  /* Sum: '<S353>/Subtract' incorporates:
   *  Sum: '<S353>/Add'
   *  Sum: '<S353>/Add1'
   */
  rtb_Transpose[8] = (rtb_Rem_k + rtb_Divide) - (rtb_Saturation_l +
    rtb_MathFunction_cr_idx_0);

  /* Math: '<S4>/Transpose' */
  for (i = 0; i < 3; i++) {
    rtb_Transpose_0[3 * i] = rtb_Transpose[i];
    rtb_Transpose_0[1 + 3 * i] = rtb_Transpose[i + 3];
    rtb_Transpose_0[2 + 3 * i] = rtb_Transpose[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_Transpose[i] = rtb_Transpose_0[i];
  }

  /* End of Math: '<S4>/Transpose' */

  /* Product: '<S4>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S4>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S4>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S4>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply[i] = rtb_Transpose[i + 6] * FMS_U.INS_Out.az + (rtb_Transpose[i
      + 3] * FMS_U.INS_Out.ay + rtb_Transpose[i] * FMS_U.INS_Out.ax);
  }

  /* End of Product: '<S4>/Multiply' */

  /* DiscreteIntegrator: '<S346>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Multiply[0];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply[1];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply[2];
  }

  /* Product: '<S4>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S4>/Sum of Elements'
   */
  rtb_Divide_b = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S347>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S347>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Logic: '<S4>/Logical Operator1' incorporates:
   *  Constant: '<S345>/Constant'
   *  DiscreteIntegrator: '<S346>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S347>/Discrete-Time Integrator5'
   *  Logic: '<S348>/AND'
   *  Logic: '<S4>/Logical Operator'
   *  RelationalOperator: '<S345>/Compare'
   *  RelationalOperator: '<S348>/Lower Test'
   *  RelationalOperator: '<S348>/Upper Test'
   */
  FMS_B.on_ground = ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] <= 0.5F) &&
                     ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] <= 0.5F)) &&
                     ((-10.306F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] <= -9.306F)) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTAT_d < 1250.0F));

  /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0U;
  }

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S9>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   *  Delay: '<S8>/Delay'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/FixPt Relational Operator'
   *  RelationalOperator: '<S9>/Compare'
   *  Switch: '<S8>/Switch1'
   *  UnitDelay: '<S15>/Delay Input1'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTATE <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S8>/Switch1' incorporates:
       *  DataTypeConversion: '<S8>/Data Type Conversion1'
       *  Delay: '<S8>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S8>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S8>/Delay'
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
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 128U) !=
           0U)) {
        FMS_B.target_mode = PilotMode_Altitude;
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

         default:
          FMS_DW.is_c3_FMS = FMS_IN_Other;
          break;
        }
      } else {
        FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
      }
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

  /* Switch: '<S7>/Switch1' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  RelationalOperator: '<S12>/FixPt Relational Operator'
   *  Switch: '<S7>/Switch2'
   *  UnitDelay: '<S11>/Delay Input1'
   *  UnitDelay: '<S12>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S7>/Switch2' incorporates:
     *  DataTypeConversion: '<S7>/Data Type Conversion1'
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;
  } else {
    /* Switch: '<S7>/Switch2' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_3' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.on_ground;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
  rtb_FixPtRelationalOperator_n = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_n) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k))
  {
    FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_k = rtb_FixPtRelationalOperator_n;
  rtb_FixPtRelationalOperator_n = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_n) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
  {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_FixPtRelationalOperator_n;
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d0)) {
    FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_B.on_ground;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
    FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
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
  /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
  /* SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Divide_o[0] = FMS_B.Cmd_In.sp_return[0];
  rtb_Divide_o[1] = FMS_B.Cmd_In.sp_return[1];
  rtb_MatrixConcatenate3[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_MatrixConcatenate3[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_MatrixConcatenate3[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

  /* SwitchCase: '<S16>/Switch Case' incorporates:
   *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy6Inport1'
   */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;

  /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
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

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S18>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S25>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S291>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S281>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S237>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S215>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S225>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S23>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S131>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S176>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S166>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S131>/Mission_SubSystem' */
      }

      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S22>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 4:
        break;

       case 1:
        /* Disable for SwitchCase: '<S118>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S54>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S94>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S70>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S81>/Switch Case' */
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

    /* End of Disable for SwitchCase: '<S18>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S16>/Disarm' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S19>/Bus Assignment'
     */
    FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Disarm);

    /* End of Outputs for SubSystem: '<S16>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S16>/Standby' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S19>/Bus Assignment'
     *  BusAssignment: '<S21>/Bus Assignment'
     *  Constant: '<S21>/Constant'
     *  SignalConversion: '<S21>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S21>/Bus Assignment' incorporates:
     *  BusAssignment: '<S19>/Bus Assignment'
     *  Constant: '<S21>/Constant2'
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

    /* End of Outputs for SubSystem: '<S16>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S16>/Arm' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* SwitchCase: '<S18>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;

    /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
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

    /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S25>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S291>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S281>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S237>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S215>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S225>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S23>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S131>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S176>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S166>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S131>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S22>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S118>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S37>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S54>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S94>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S70>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S81>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S18>/SubMode' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* SwitchCase: '<S25>/Switch Case' incorporates:
       *  Math: '<S313>/Math Function'
       *  Product: '<S315>/Divide'
       *  Sum: '<S276>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_at;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_at) {
        switch (rtPrevAction) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S291>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S281>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S237>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S215>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S225>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S25>/Takeoff' incorporates:
         *  ActionPort: '<S210>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S328>/Sum2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S322>/Sum'
         */
        rtb_Divide_l_idx_2 = FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2];

        /* Product: '<S328>/Divide' incorporates:
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S328>/Sum1'
         *  Sum: '<S328>/Sum2'
         */
        rtb_Saturation_l = 1.0F / (FMS_B.Cmd_In.sp_takeoff[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_l_idx_2;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S328>/Saturation' */
        if (rtb_Saturation_l > 1.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = 0.0F;
          }
        }

        /* End of Saturate: '<S328>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S329>/Trigonometric Function1' incorporates:
         *  Gain: '<S327>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Trigonometry: '<S329>/Trigonometric Function3'
         */
        rtb_Rem_k = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Transpose[0] = rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S329>/Trigonometric Function' incorporates:
         *  Gain: '<S327>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Trigonometry: '<S329>/Trigonometric Function2'
         */
        rtb_MathFunction_cr_idx_0 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Transpose[1] = rtb_MathFunction_cr_idx_0;

        /* SignalConversion: '<S329>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S329>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S329>/Gain' */
        rtb_Transpose[3] = -rtb_MathFunction_cr_idx_0;

        /* Trigonometry: '<S329>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_Rem_k;

        /* SignalConversion: '<S329>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S329>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S329>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S323>/Saturation1' */
        rtb_Square2 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        A = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SignalConversion: '<S323>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S328>/Multiply'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S323>/Sum'
         *  Sum: '<S328>/Sum3'
         *  Sum: '<S328>/Sum4'
         */
        rtb_Divide_l_idx_1 = ((FMS_B.Cmd_In.sp_takeoff[0] -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Saturation_l +
                              FMS_B.Cmd_In.cur_waypoint[0]) - FMS_U.INS_Out.x_R;
        rtb_Saturation_l = ((FMS_B.Cmd_In.sp_takeoff[1] -
                             FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Saturation_l +
                            FMS_B.Cmd_In.cur_waypoint[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S323>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_1[i] = rtb_Transpose[i + 3] * rtb_Saturation_l +
            rtb_Transpose[i] * rtb_Divide_l_idx_1;
        }

        /* Saturate: '<S323>/Saturation1' incorporates:
         *  Gain: '<S323>/Gain2'
         *  Product: '<S323>/Multiply'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_1[0];
        rtb_Saturation_l = FMS_PARAM.XY_P * rtb_Transpose_1[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  BusAssignment: '<S210>/Bus Assignment1'
         *  Constant: '<S210>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S210>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Constant: '<S210>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S323>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Square2) {
          /* BusAssignment: '<S210>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Square2;
        } else if (rtb_Divide_l_idx_1 < A) {
          /* BusAssignment: '<S210>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = A;
        } else {
          /* BusAssignment: '<S210>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_Saturation_l > rtb_Square2) {
          /* BusAssignment: '<S210>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Square2;
        } else if (rtb_Saturation_l < A) {
          /* BusAssignment: '<S210>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = A;
        } else {
          /* BusAssignment: '<S210>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_l;
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Switch: '<S322>/Switch' incorporates:
         *  Abs: '<S322>/Abs'
         *  Abs: '<S322>/Abs1'
         *  Constant: '<S324>/Constant'
         *  Constant: '<S325>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S322>/Logical Operator'
         *  RelationalOperator: '<S324>/Compare'
         *  RelationalOperator: '<S325>/Compare'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S322>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_takeoff[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(rtb_Divide_l_idx_2) > 2.0F)) {
          /* BusAssignment: '<S210>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Constant: '<S322>/Constant6'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -1.0F;
        } else {
          /* BusAssignment: '<S210>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Constant: '<S322>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -0.5F;
        }

        /* End of Switch: '<S322>/Switch' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S25>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S25>/Land' incorporates:
         *  ActionPort: '<S208>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S254>/Trigonometric Function1' incorporates:
         *  Gain: '<S253>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S254>/Trigonometric Function' incorporates:
         *  Gain: '<S253>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S254>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S254>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S254>/Gain' incorporates:
         *  Gain: '<S253>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Trigonometry: '<S254>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S254>/Trigonometric Function3' incorporates:
         *  Gain: '<S253>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S254>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S254>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S254>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S250>/Saturation1' */
        rtb_Divide_l_idx_2 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Square2 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SignalConversion: '<S251>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S251>/Sum'
         */
        rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_land[0] - FMS_U.INS_Out.x_R;
        rtb_Saturation_l = FMS_B.Cmd_In.sp_land[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S251>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_1[i] = rtb_Transpose[i + 3] * rtb_Saturation_l +
            rtb_Transpose[i] * rtb_Divide_l_idx_1;
        }

        /* Saturate: '<S250>/Saturation1' incorporates:
         *  Gain: '<S251>/Gain2'
         *  Product: '<S251>/Multiply'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_1[0];
        rtb_Saturation_l = FMS_PARAM.XY_P * rtb_Transpose_1[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  BusAssignment: '<S208>/Bus Assignment1'
         *  Constant: '<S208>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S208>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Constant: '<S208>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S250>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Divide_l_idx_2) {
          /* BusAssignment: '<S208>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_2;
        } else if (rtb_Divide_l_idx_1 < rtb_Square2) {
          /* BusAssignment: '<S208>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Square2;
        } else {
          /* BusAssignment: '<S208>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_Saturation_l > rtb_Divide_l_idx_2) {
          /* BusAssignment: '<S208>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_2;
        } else if (rtb_Saturation_l < rtb_Square2) {
          /* BusAssignment: '<S208>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Square2;
        } else {
          /* BusAssignment: '<S208>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_l;
        }

        /* BusAssignment: '<S208>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Constant: '<S208>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S25>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S25>/Return' incorporates:
           *  ActionPort: '<S209>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S25>/Switch Case' incorporates:
           *  Delay: '<S257>/Delay'
           *  Delay: '<S258>/Delay'
           *  Delay: '<S277>/Delay'
           *  DiscreteIntegrator: '<S261>/Integrator'
           *  DiscreteIntegrator: '<S261>/Integrator1'
           *  DiscreteIntegrator: '<S318>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_o = 1U;
          FMS_DW.l1_heading_p = 0.0F;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S25>/Return' */

          /* SystemReset for IfAction SubSystem: '<S25>/Return' incorporates:
           *  ActionPort: '<S209>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S25>/Switch Case' incorporates:
           *  Chart: '<S282>/Motion Status'
           *  Chart: '<S292>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S25>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S25>/Return' incorporates:
         *  ActionPort: '<S209>/Action Port'
         */
        /* Delay: '<S277>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        if (FMS_DW.icLoad_o != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S273>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S278>/Square'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Divide = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_return[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Saturation1_ln[0] = rtb_Divide * rtb_Divide;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Divide = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_return[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S278>/Square' */
        rtb_Divide *= rtb_Divide;

        /* Sqrt: '<S278>/Sqrt' incorporates:
         *  Sum: '<S278>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_Saturation1_ln[0] + rtb_Divide);

        /* Switch: '<S273>/Switch' incorporates:
         *  Constant: '<S273>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Divide_l_idx_2 = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S273>/Gain' */
          rtb_Divide_l_idx_2 = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S273>/Saturation' */
          if (rtb_Divide_l_idx_2 > FMS_PARAM.CRUISE_SPEED) {
            rtb_Divide_l_idx_2 = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Divide_l_idx_2 < 0.5F) {
              rtb_Divide_l_idx_2 = 0.5F;
            }
          }

          /* End of Saturate: '<S273>/Saturation' */
        }

        /* End of Switch: '<S273>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S292>/Motion State' incorporates:
         *  Constant: '<S292>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S292>/Square'
         *  Math: '<S292>/Square1'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sqrt: '<S292>/Sqrt'
         *  Sum: '<S292>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S291>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S291>/Hold Control' incorporates:
             *  ActionPort: '<S294>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S291>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S291>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S291>/Hold Control' incorporates:
           *  ActionPort: '<S294>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_mv,
                            &FMS_ConstB.HoldControl_k, &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S291>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S291>/Brake Control' incorporates:
           *  ActionPort: '<S293>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_mv);

          /* End of Outputs for SubSystem: '<S291>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S291>/Move Control' incorporates:
             *  ActionPort: '<S295>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S291>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S291>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S291>/Move Control' incorporates:
           *  ActionPort: '<S295>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_mv,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S291>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S291>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S282>/Motion Status' incorporates:
         *  Abs: '<S282>/Abs'
         *  Constant: '<S282>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S281>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S281>/Hold Control' incorporates:
             *  ActionPort: '<S284>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S281>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S281>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S281>/Hold Control' incorporates:
           *  ActionPort: '<S284>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S281>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S281>/Brake Control' incorporates:
           *  ActionPort: '<S283>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S281>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S281>/Move Control' incorporates:
             *  ActionPort: '<S285>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S281>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S281>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S281>/Move Control' incorporates:
           *  ActionPort: '<S285>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S281>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S281>/Switch Case' */

        /* Delay: '<S257>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S209>/Sum' incorporates:
         *  Delay: '<S257>/Delay'
         *  MATLAB Function: '<S275>/OutRegionRegWP'
         *  MATLAB Function: '<S275>/SearchL1RefWP'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_return[0] -
          FMS_DW.Delay_DSTATE_p[0];
        rtb_Divide = FMS_B.Cmd_In.sp_return[1] - FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S272>/Sum of Elements' incorporates:
         *  Math: '<S272>/Math Function'
         *  Sum: '<S209>/Sum'
         */
        rtb_Square2 = rtb_Divide * rtb_Divide + rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Math: '<S272>/Math Function1' incorporates:
         *  Sum: '<S272>/Sum of Elements'
         *
         * About '<S272>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Square2 < 0.0F) {
          rtb_Saturation_l = -sqrtf(fabsf(rtb_Square2));
        } else {
          rtb_Saturation_l = sqrtf(rtb_Square2);
        }

        /* End of Math: '<S272>/Math Function1' */

        /* Switch: '<S272>/Switch' incorporates:
         *  Constant: '<S272>/Constant'
         *  Product: '<S272>/Product'
         *  Sum: '<S209>/Sum'
         */
        if (rtb_Saturation_l > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Divide;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_h_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Saturation_l;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S272>/Switch' */

        /* Product: '<S272>/Divide' */
        rtb_Saturation1_ln[0] = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_Saturation1_ln[1] = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S270>/Subtract' incorporates:
         *  Product: '<S270>/Multiply'
         *  Product: '<S270>/Multiply1'
         */
        rtb_Saturation_l = rtb_Saturation1_ln[0] * FMS_ConstB.Divide_d[1] -
          rtb_Saturation1_ln[1] * FMS_ConstB.Divide_d[0];

        /* Signum: '<S259>/Sign1' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S259>/Sign1' */

        /* Switch: '<S259>/Switch2' incorporates:
         *  Constant: '<S259>/Constant4'
         */
        if (rtb_Saturation_l == 0.0F) {
          rtb_Saturation_l = 1.0F;
        }

        /* End of Switch: '<S259>/Switch2' */

        /* DotProduct: '<S259>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide_d[0] * rtb_Saturation1_ln[0] +
          FMS_ConstB.Divide_d[1] * rtb_Saturation1_ln[1];

        /* Trigonometry: '<S259>/Acos' incorporates:
         *  DotProduct: '<S259>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S259>/Multiply' incorporates:
         *  Trigonometry: '<S259>/Acos'
         */
        rtb_Saturation_l *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S263>/Rem' incorporates:
         *  Constant: '<S263>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sum: '<S258>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_Saturation_l - FMS_U.INS_Out.psi,
          6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S263>/Switch' incorporates:
         *  Abs: '<S263>/Abs'
         *  Constant: '<S263>/Constant'
         *  Constant: '<S269>/Constant'
         *  Product: '<S263>/Multiply'
         *  RelationalOperator: '<S269>/Compare'
         *  Sum: '<S263>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S263>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Square2 = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Square2 = 1.0F;
          } else {
            rtb_Square2 = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S263>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Square2;
        }

        /* End of Switch: '<S263>/Switch' */

        /* Abs: '<S256>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S256>/Switch' incorporates:
         *  Product: '<S277>/Multiply'
         *  Sum: '<S277>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S291>/Saturation1' */
          if (FMS_B.Merge_mv[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_MatrixConcatenate3[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_MatrixConcatenate3[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_MatrixConcatenate3[0] = FMS_B.Merge_mv[0];
          }

          if (FMS_B.Merge_mv[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_MatrixConcatenate3[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_MatrixConcatenate3[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_MatrixConcatenate3[1] = FMS_B.Merge_mv[1];
          }

          /* End of Saturate: '<S291>/Saturation1' */

          /* Saturate: '<S281>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_MatrixConcatenate3[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_MatrixConcatenate3[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_MatrixConcatenate3[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S281>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S277>/Sum' incorporates:
           *  Delay: '<S277>/Delay'
           *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_return[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S319>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_MatrixConcatenate3[0] = rtb_Divide_l_idx_1;
          rtb_Saturation1_ln[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S277>/Sum' incorporates:
           *  Delay: '<S277>/Delay'
           *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_return[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S321>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S321>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S320>/Gain' incorporates:
           *  DiscreteIntegrator: '<S318>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S17>/Signal Copy1'
           *  Sum: '<S318>/Add'
           */
          rtb_Square2 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_p);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Trigonometry: '<S321>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S321>/Trigonometric Function1'
           */
          rtb_Rem_k = arm_cos_f32(rtb_Square2);
          rtb_Transpose[4] = rtb_Rem_k;

          /* Trigonometry: '<S321>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S321>/Trigonometric Function'
           */
          rtb_MathFunction_cr_idx_0 = arm_sin_f32(rtb_Square2);

          /* Gain: '<S321>/Gain' incorporates:
           *  Trigonometry: '<S321>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_cr_idx_0;

          /* SignalConversion: '<S321>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S321>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S321>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_cr_idx_0;

          /* Trigonometry: '<S321>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_Rem_k;

          /* SignalConversion: '<S321>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_k[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_k[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_k[2];

          /* Sum: '<S319>/Sum of Elements' incorporates:
           *  Math: '<S319>/Math Function'
           */
          rtb_Square2 = rtb_MatrixConcatenate3[0] * rtb_MatrixConcatenate3[0] +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

          /* Math: '<S319>/Math Function1' incorporates:
           *  Sum: '<S319>/Sum of Elements'
           *
           * About '<S319>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Square2 < 0.0F) {
            rtb_Square2 = -sqrtf(fabsf(rtb_Square2));
          } else {
            rtb_Square2 = sqrtf(rtb_Square2);
          }

          /* End of Math: '<S319>/Math Function1' */

          /* Switch: '<S319>/Switch' incorporates:
           *  Constant: '<S319>/Constant'
           *  Product: '<S319>/Product'
           */
          if (rtb_Square2 > 0.0F) {
            A = rtb_Saturation1_ln[0];
          } else {
            A = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Square2 = 1.0F;
          }

          /* End of Switch: '<S319>/Switch' */

          /* Product: '<S317>/Multiply2' incorporates:
           *  Product: '<S319>/Divide'
           */
          A = A / rtb_Square2 * rtb_Divide_l_idx_2;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_Square2 *
            rtb_Divide_l_idx_2;
          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 3] *
              rtb_Divide_l_idx_1 + rtb_Transpose[i] * A;
          }
        }

        /* End of Switch: '<S256>/Switch' */

        /* Delay: '<S258>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S261>/Integrator1' incorporates:
         *  Delay: '<S258>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S265>/Rem' incorporates:
         *  Constant: '<S265>/Constant1'
         *  DiscreteIntegrator: '<S261>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sum: '<S260>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S265>/Switch' incorporates:
         *  Abs: '<S265>/Abs'
         *  Constant: '<S265>/Constant'
         *  Constant: '<S266>/Constant'
         *  Product: '<S265>/Multiply'
         *  RelationalOperator: '<S266>/Compare'
         *  Sum: '<S265>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S265>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_k;
          }

          /* End of Signum: '<S265>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S265>/Switch' */

        /* Gain: '<S260>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S260>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S260>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  BusAssignment: '<S209>/Bus Assignment1'
         *  Constant: '<S209>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S209>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        FMS_Y.FMS_Out.w_cmd = rtb_MatrixConcatenate3[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S312>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S312>/Math Function'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sum: '<S310>/Sum of Elements'
         */
        rtb_Square2 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S312>/Math Function1' incorporates:
         *  Sum: '<S312>/Sum of Elements'
         *
         * About '<S312>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Square2 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Square2));
        } else {
          rtb_Rem_k = sqrtf(rtb_Square2);
        }

        /* End of Math: '<S312>/Math Function1' */

        /* Switch: '<S312>/Switch' incorporates:
         *  Constant: '<S312>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S312>/Product'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        if (rtb_Rem_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_MatrixConcatenate3[0] = FMS_U.INS_Out.vn;
          rtb_MatrixConcatenate3[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_MatrixConcatenate3[2] = rtb_Rem_k;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S312>/Switch' */

        /* Product: '<S312>/Divide' */
        rtb_Saturation1_ln[0] = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_Saturation1_ln[1] = rtb_MatrixConcatenate3[1] /
          rtb_MatrixConcatenate3[2];

        /* Sum: '<S315>/Sum of Elements' incorporates:
         *  Math: '<S315>/Math Function'
         *  SignalConversion: '<S315>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Saturation1_ln[1] * rtb_Saturation1_ln[1] +
          rtb_Saturation1_ln[0] * rtb_Saturation1_ln[0];

        /* Math: '<S315>/Math Function1' incorporates:
         *  Sum: '<S315>/Sum of Elements'
         *
         * About '<S315>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S315>/Math Function1' */

        /* Switch: '<S315>/Switch' incorporates:
         *  Constant: '<S315>/Constant'
         *  Product: '<S315>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Saturation1_ln[1];
          rtb_MatrixConcatenate3[1] = rtb_Saturation1_ln[0];
          rtb_MatrixConcatenate3[2] = rtb_Rem_k;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S315>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S275>/NearbyRefWP' incorporates:
         *  Constant: '<S209>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        FMS_NearbyRefWP(rtb_Divide_o, FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Saturation1_ln,
                        &rtb_MathFunction_cr_idx_0);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* MATLAB Function: '<S275>/SearchL1RefWP' incorporates:
         *  Constant: '<S209>/L1'
         *  Delay: '<S257>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        A = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 + rtb_Divide *
          rtb_Divide;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        B = (rtb_MathFunction_h_idx_0 * (FMS_DW.Delay_DSTATE_p[0] -
              FMS_U.INS_Out.x_R) + rtb_Divide * (FMS_DW.Delay_DSTATE_p[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Divide_l_idx_1 = -1.0F;
        rtb_MathFunction_iq_idx_0 = 0.0F;
        rtb_MathFunction_iq_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          A = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
            rtb_Divide_l_idx_1 = fmaxf(D, A);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Divide_l_idx_1 = D;
            guard1 = true;
          } else {
            if ((A >= 0.0F) && (A <= 1.0F)) {
              rtb_Divide_l_idx_1 = A;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Divide_l_idx_1 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_MathFunction_iq_idx_0 = rtb_MathFunction_h_idx_0 *
            rtb_Divide_l_idx_1 + FMS_DW.Delay_DSTATE_p[0];
          rtb_MathFunction_iq_idx_1 = rtb_Divide * rtb_Divide_l_idx_1 +
            FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S275>/OutRegionRegWP' incorporates:
         *  Delay: '<S257>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        A = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) * rtb_Divide +
             (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE_p[0]) *
             rtb_MathFunction_h_idx_0) / (rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0 + rtb_Divide * rtb_Divide);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_FixPtRelationalOperator_n = (A <= 0.0F);
        u = (A >= 1.0F);
        if (rtb_FixPtRelationalOperator_n) {
          rtb_MathFunction_h_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_return[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          rtb_MathFunction_h_idx_0 = A * rtb_MathFunction_h_idx_0 +
            FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S275>/Switch1' incorporates:
         *  Constant: '<S305>/Constant'
         *  RelationalOperator: '<S305>/Compare'
         */
        if (rtb_MathFunction_cr_idx_0 <= 0.0F) {
          /* Switch: '<S275>/Switch' incorporates:
           *  Constant: '<S304>/Constant'
           *  MATLAB Function: '<S275>/SearchL1RefWP'
           *  RelationalOperator: '<S304>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_Saturation1_ln[0] = rtb_MathFunction_iq_idx_0;
            rtb_Saturation1_ln[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;

            /* MATLAB Function: '<S275>/OutRegionRegWP' incorporates:
             *  Delay: '<S257>/Delay'
             *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_n) {
              rtb_Saturation1_ln[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Saturation1_ln[1] = FMS_B.Cmd_In.sp_return[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              rtb_Saturation1_ln[1] = A * rtb_Divide + FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S275>/Switch' */
        }

        /* End of Switch: '<S275>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S276>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        rtb_MathFunction_cr_idx_1 = rtb_Saturation1_ln[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Saturation1_ln[0] = rtb_MathFunction_cr_idx_1;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_cr_idx_1 *
          rtb_MathFunction_cr_idx_1;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S276>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S313>/Math Function'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        rtb_MathFunction_cr_idx_1 = rtb_Saturation1_ln[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S313>/Math Function' incorporates:
         *  Math: '<S311>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_MathFunction_cr_idx_1 *
          rtb_MathFunction_cr_idx_1;

        /* Sum: '<S313>/Sum of Elements' incorporates:
         *  Math: '<S313>/Math Function'
         */
        A = rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S313>/Math Function1' incorporates:
         *  Sum: '<S313>/Sum of Elements'
         *
         * About '<S313>/Math Function1':
         *  Operator: sqrt
         */
        if (A < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(A));
        } else {
          rtb_Rem_k = sqrtf(A);
        }

        /* End of Math: '<S313>/Math Function1' */

        /* Switch: '<S313>/Switch' incorporates:
         *  Constant: '<S313>/Constant'
         *  Product: '<S313>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MathFunction_cr_idx_0 = rtb_Saturation1_ln[0];
        } else {
          rtb_MathFunction_cr_idx_0 = 0.0F;
          rtb_MathFunction_cr_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S313>/Switch' */

        /* Product: '<S313>/Divide' */
        rtb_Divide_o[0] = rtb_MathFunction_cr_idx_0 / rtb_Rem_k;
        rtb_Divide_o[1] = rtb_MathFunction_cr_idx_1 / rtb_Rem_k;

        /* Sum: '<S316>/Sum of Elements' incorporates:
         *  Math: '<S316>/Math Function'
         *  SignalConversion: '<S316>/TmpSignal ConversionAtMath FunctionInport1'
         */
        A = rtb_Divide_o[1] * rtb_Divide_o[1] + rtb_Divide_o[0] * rtb_Divide_o[0];

        /* Math: '<S316>/Math Function1' incorporates:
         *  Sum: '<S316>/Sum of Elements'
         *
         * About '<S316>/Math Function1':
         *  Operator: sqrt
         */
        if (A < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(A));
        } else {
          rtb_Rem_k = sqrtf(A);
        }

        /* End of Math: '<S316>/Math Function1' */

        /* Switch: '<S316>/Switch' incorporates:
         *  Constant: '<S316>/Constant'
         *  Product: '<S316>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MathFunction_cr_idx_0 = rtb_Divide_o[1];
          rtb_MathFunction_cr_idx_1 = rtb_Divide_o[0];
        } else {
          rtb_MathFunction_cr_idx_0 = 0.0F;
          rtb_MathFunction_cr_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S316>/Switch' */

        /* Product: '<S316>/Divide' */
        rtb_Divide_o[0] = rtb_MathFunction_cr_idx_0 / rtb_Rem_k;

        /* Math: '<S311>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Saturation1_ln[0] *
          rtb_Saturation1_ln[0];
        rtb_Saturation1_ln[0] = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S316>/Divide' incorporates:
         *  Product: '<S315>/Divide'
         */
        rtb_Divide_o[1] = rtb_MathFunction_cr_idx_1 / rtb_Rem_k;

        /* Product: '<S315>/Divide' */
        rtb_Divide = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sqrt: '<S310>/Sqrt' */
        rtb_Rem_k = sqrtf(rtb_Square2);

        /* Gain: '<S276>/Gain' incorporates:
         *  Math: '<S276>/Square'
         */
        rtb_Square2 = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S314>/Subtract' incorporates:
         *  Product: '<S314>/Multiply'
         *  Product: '<S314>/Multiply1'
         */
        rtb_Rem_k = rtb_Divide_o[0] * rtb_Divide - rtb_Divide_o[1] *
          rtb_Saturation1_ln[0];

        /* Signum: '<S309>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S309>/Sign1' */

        /* Switch: '<S309>/Switch2' incorporates:
         *  Constant: '<S309>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S309>/Switch2' */

        /* DotProduct: '<S309>/Dot Product' */
        rtb_Divide = rtb_Saturation1_ln[0] * rtb_Divide_o[0] + rtb_Divide *
          rtb_Divide_o[1];

        /* Trigonometry: '<S309>/Acos' incorporates:
         *  DotProduct: '<S309>/Dot Product'
         */
        if (rtb_Divide > 1.0F) {
          rtb_Divide = 1.0F;
        } else {
          if (rtb_Divide < -1.0F) {
            rtb_Divide = -1.0F;
          }
        }

        /* Product: '<S309>/Multiply' incorporates:
         *  Trigonometry: '<S309>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_Divide);

        /* Saturate: '<S276>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S276>/Saturation' */

        /* Product: '<S276>/Divide' incorporates:
         *  Constant: '<S209>/L1'
         *  Constant: '<S276>/Constant'
         *  MinMax: '<S276>/Max'
         *  MinMax: '<S276>/Min'
         *  Product: '<S276>/Multiply1'
         *  Sqrt: '<S311>/Sqrt'
         *  Sum: '<S311>/Sum of Elements'
         *  Trigonometry: '<S276>/Sin'
         */
        rtb_Square2 = arm_sin_f32(rtb_Rem_k) * rtb_Square2 / fminf(FMS_PARAM.L1,
          fmaxf(sqrtf(rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0]),
                0.5F));

        /* Sum: '<S258>/Sum2' incorporates:
         *  Delay: '<S258>/Delay'
         */
        rtb_Saturation_l -= FMS_DW.Delay_DSTATE_a;

        /* Math: '<S262>/Rem' incorporates:
         *  Constant: '<S262>/Constant1'
         */
        rtb_MathFunction_cr_idx_0 = rt_remf(rtb_Saturation_l, 6.28318548F);

        /* Switch: '<S262>/Switch' incorporates:
         *  Abs: '<S262>/Abs'
         *  Constant: '<S262>/Constant'
         *  Constant: '<S268>/Constant'
         *  Product: '<S262>/Multiply'
         *  RelationalOperator: '<S268>/Compare'
         *  Sum: '<S262>/Add'
         */
        if (fabsf(rtb_MathFunction_cr_idx_0) > 3.14159274F) {
          /* Signum: '<S262>/Sign' */
          if (rtb_MathFunction_cr_idx_0 < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_MathFunction_cr_idx_0 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_MathFunction_cr_idx_0;
          }

          /* End of Signum: '<S262>/Sign' */
          rtb_MathFunction_cr_idx_0 -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S262>/Switch' */

        /* Sum: '<S258>/Sum' incorporates:
         *  Delay: '<S258>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_MathFunction_cr_idx_0 + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S267>/Multiply1' incorporates:
         *  Constant: '<S267>/const1'
         *  DiscreteIntegrator: '<S261>/Integrator'
         */
        rtb_MathFunction_cr_idx_0 = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S267>/Add' incorporates:
         *  DiscreteIntegrator: '<S261>/Integrator1'
         *  Sum: '<S261>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_e - rtb_Divide_l_idx_1) +
          rtb_MathFunction_cr_idx_0;

        /* Signum: '<S267>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S267>/Sign' */

        /* Sum: '<S267>/Add2' incorporates:
         *  Abs: '<S267>/Abs'
         *  Gain: '<S267>/Gain'
         *  Gain: '<S267>/Gain1'
         *  Product: '<S267>/Multiply2'
         *  Product: '<S267>/Multiply3'
         *  Sqrt: '<S267>/Sqrt'
         *  Sum: '<S267>/Add1'
         *  Sum: '<S267>/Subtract'
         */
        rtb_Saturation_l = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_l) *
          FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Divide_l_idx_1 +
          rtb_MathFunction_cr_idx_0;

        /* Sum: '<S267>/Add4' */
        A = (rtb_Rem_k - rtb_Saturation_l) + rtb_MathFunction_cr_idx_0;

        /* Sum: '<S267>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_l;

        /* Sum: '<S267>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_l;

        /* Signum: '<S267>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S267>/Sign1' */

        /* Signum: '<S267>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S267>/Sign2' */

        /* Sum: '<S267>/Add5' incorporates:
         *  Gain: '<S267>/Gain2'
         *  Product: '<S267>/Multiply4'
         *  Sum: '<S267>/Subtract2'
         */
        rtb_Saturation_l += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F * A;

        /* Update for Delay: '<S277>/Delay' */
        FMS_DW.icLoad_o = 0U;

        /* Update for DiscreteIntegrator: '<S318>/Discrete-Time Integrator' incorporates:
         *  Product: '<S277>/Divide1'
         */
        FMS_DW.l1_heading_p += rtb_Square2 / rtb_Divide_l_idx_2 * 0.004F;

        /* Update for Delay: '<S257>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Update for Delay: '<S258>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S261>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S261>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S267>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Saturation_l + FMS_ConstB.d_l;

        /* Sum: '<S267>/Subtract3' */
        A = rtb_Saturation_l - FMS_ConstB.d_l;

        /* Signum: '<S267>/Sign5' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_Divide_l_idx_2 = rtb_Saturation_l;
        }

        /* End of Signum: '<S267>/Sign5' */

        /* Signum: '<S267>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S267>/Sign3' */

        /* Signum: '<S267>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S267>/Sign4' */

        /* Signum: '<S267>/Sign6' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Square2 = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Square2 = 1.0F;
        } else {
          rtb_Square2 = rtb_Saturation_l;
        }

        /* End of Signum: '<S267>/Sign6' */

        /* Update for DiscreteIntegrator: '<S261>/Integrator' incorporates:
         *  Constant: '<S267>/const'
         *  Gain: '<S267>/Gain3'
         *  Product: '<S267>/Divide'
         *  Product: '<S267>/Multiply5'
         *  Product: '<S267>/Multiply6'
         *  Sum: '<S267>/Subtract4'
         *  Sum: '<S267>/Subtract5'
         *  Sum: '<S267>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Saturation_l / FMS_ConstB.d_l -
          rtb_Divide_l_idx_2) * FMS_ConstB.Gain4_np * ((rtb_Divide_l_idx_1 - A) *
          0.5F) - rtb_Square2 * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S261>/Integrator' */
        /* End of Outputs for SubSystem: '<S25>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S25>/Hold' incorporates:
           *  ActionPort: '<S207>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S25>/Switch Case' incorporates:
           *  Chart: '<S216>/Motion Status'
           *  Chart: '<S226>/Motion State'
           *  Chart: '<S238>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S25>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S25>/Hold' incorporates:
         *  ActionPort: '<S207>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S216>/Motion Status' incorporates:
         *  Abs: '<S216>/Abs'
         *  Constant: '<S216>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Chart: '<S226>/Motion State' incorporates:
         *  Abs: '<S226>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
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

            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_a >=
                 250U)) {
              FMS_DW.is_c15_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
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

        /* End of Chart: '<S226>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S238>/Motion State' incorporates:
         *  Constant: '<S238>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S238>/Square'
         *  Math: '<S238>/Square1'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sqrt: '<S238>/Sqrt'
         *  Sum: '<S238>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S237>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S237>/Hold Control' incorporates:
             *  ActionPort: '<S240>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S237>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S237>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S237>/Hold Control' incorporates:
           *  ActionPort: '<S240>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S237>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S237>/Brake Control' incorporates:
           *  ActionPort: '<S239>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S237>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S237>/Move Control' incorporates:
             *  ActionPort: '<S241>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S237>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S237>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S237>/Move Control' incorporates:
           *  ActionPort: '<S241>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S237>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S237>/Switch Case' */

        /* SwitchCase: '<S215>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S215>/Hold Control' incorporates:
             *  ActionPort: '<S218>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S215>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S215>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S215>/Hold Control' incorporates:
           *  ActionPort: '<S218>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S215>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S215>/Brake Control' incorporates:
           *  ActionPort: '<S217>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S215>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S215>/Move Control' incorporates:
             *  ActionPort: '<S219>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S215>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S215>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S215>/Move Control' incorporates:
           *  ActionPort: '<S219>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S215>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S215>/Switch Case' */

        /* SwitchCase: '<S225>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S225>/Hold Control' incorporates:
             *  ActionPort: '<S228>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S225>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_kq);

            /* End of SystemReset for SubSystem: '<S225>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S225>/Hold Control' incorporates:
           *  ActionPort: '<S228>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                             &FMS_DW.HoldControl_kq);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S225>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S225>/Brake Control' incorporates:
           *  ActionPort: '<S227>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S225>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S225>/Move Control' incorporates:
             *  ActionPort: '<S229>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S225>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S225>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S225>/Move Control' incorporates:
           *  ActionPort: '<S229>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S225>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S225>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  BusAssignment: '<S207>/Bus Assignment'
         *  Constant: '<S207>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S207>/Bus Assignment' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S225>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S225>/Saturation' */

        /* Saturate: '<S237>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S237>/Saturation1' */

        /* Saturate: '<S215>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S207>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S215>/Saturation1' */
        /* End of Outputs for SubSystem: '<S25>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S25>/Unknown' incorporates:
         *  ActionPort: '<S211>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S25>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S25>/Switch Case' */
      /* End of Outputs for SubSystem: '<S18>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S18>/Auto' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* SwitchCase: '<S23>/Switch Case' incorporates:
       *  Math: '<S196>/Square'
       *  Math: '<S198>/Math Function'
       *  Sum: '<S158>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_i) && (rtPrevAction
           == 1)) {
        /* Disable for Resettable SubSystem: '<S131>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S176>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S166>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S131>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S23>/Offboard' incorporates:
         *  ActionPort: '<S132>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S132>/Bus Assignment'
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Constant: '<S132>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S132>/Bus Assignment' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;

        /* End of Outputs for SubSystem: '<S23>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S23>/Mission' incorporates:
           *  ActionPort: '<S131>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S23>/Switch Case' incorporates:
           *  UnitDelay: '<S134>/Delay Input1'
           *
           * Block description for '<S134>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S23>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S23>/Mission' incorporates:
           *  ActionPort: '<S131>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S131>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S23>/Switch Case' incorporates:
           *  Chart: '<S167>/Motion Status'
           *  Chart: '<S177>/Motion State'
           *  Delay: '<S139>/Delay'
           *  Delay: '<S159>/Delay'
           *  DiscreteIntegrator: '<S142>/Integrator'
           *  DiscreteIntegrator: '<S142>/Integrator1'
           *  DiscreteIntegrator: '<S203>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_i = 0.0F;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S131>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S23>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S23>/Mission' incorporates:
         *  ActionPort: '<S131>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* RelationalOperator: '<S134>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S134>/Delay Input1'
         *
         * Block description for '<S134>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator_n = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S131>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S135>/Reset'
         */
        if (rtb_FixPtRelationalOperator_n &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S176>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S166>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S159>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S203>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S139>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S177>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S167>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_n;

        /* Delay: '<S159>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        if (FMS_DW.icLoad != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S155>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S163>/Square'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Divide_l_idx_1 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Divide_l_idx_1 *
          rtb_Divide_l_idx_1;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Divide_l_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S163>/Square' */
        rtb_Divide_l_idx_1 *= rtb_Divide_l_idx_1;

        /* Sqrt: '<S163>/Sqrt' incorporates:
         *  Sum: '<S163>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_TmpSignalConversionAtDela_a[0] +
          rtb_Divide_l_idx_1);

        /* Switch: '<S155>/Switch' incorporates:
         *  Constant: '<S155>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Divide_l_idx_2 = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S155>/Gain' */
          rtb_Divide_l_idx_2 = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S155>/Saturation' */
          if (rtb_Divide_l_idx_2 > FMS_PARAM.CRUISE_SPEED) {
            rtb_Divide_l_idx_2 = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Divide_l_idx_2 < 0.5F) {
              rtb_Divide_l_idx_2 = 0.5F;
            }
          }

          /* End of Saturate: '<S155>/Saturation' */
        }

        /* End of Switch: '<S155>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S177>/Motion State' incorporates:
         *  Constant: '<S177>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S177>/Square'
         *  Math: '<S177>/Square1'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sqrt: '<S177>/Sqrt'
         *  Sum: '<S177>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S176>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S176>/Hold Control' incorporates:
             *  ActionPort: '<S179>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S176>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S176>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S176>/Hold Control' incorporates:
           *  ActionPort: '<S179>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S176>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S176>/Brake Control' incorporates:
           *  ActionPort: '<S178>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S176>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S176>/Move Control' incorporates:
             *  ActionPort: '<S180>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S176>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S176>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S176>/Move Control' incorporates:
           *  ActionPort: '<S180>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S176>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S176>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S167>/Motion Status' incorporates:
         *  Abs: '<S167>/Abs'
         *  Constant: '<S167>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S166>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S166>/Hold Control' incorporates:
             *  ActionPort: '<S169>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S166>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S166>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S166>/Hold Control' incorporates:
           *  ActionPort: '<S169>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S166>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S166>/Brake Control' incorporates:
           *  ActionPort: '<S168>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S166>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S166>/Move Control' incorporates:
             *  ActionPort: '<S170>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S166>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S166>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S166>/Move Control' incorporates:
           *  ActionPort: '<S170>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S166>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S166>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S135>/Sum' incorporates:
         *  MATLAB Function: '<S157>/OutRegionRegWP'
         *  MATLAB Function: '<S157>/SearchL1RefWP'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S160>/Sum1'
         *  Switch: '<S137>/Switch'
         */
        rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Divide = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S153>/Sum of Elements' incorporates:
         *  Math: '<S153>/Math Function'
         *  Sum: '<S135>/Sum'
         */
        rtb_Square2 = rtb_Divide * rtb_Divide + rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Math: '<S153>/Math Function1' incorporates:
         *  Sum: '<S153>/Sum of Elements'
         *
         * About '<S153>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Square2 < 0.0F) {
          rtb_Saturation_l = -sqrtf(fabsf(rtb_Square2));
        } else {
          rtb_Saturation_l = sqrtf(rtb_Square2);
        }

        /* End of Math: '<S153>/Math Function1' */

        /* Switch: '<S153>/Switch' incorporates:
         *  Constant: '<S153>/Constant'
         *  Product: '<S153>/Product'
         *  Sum: '<S135>/Sum'
         */
        if (rtb_Saturation_l > 0.0F) {
          rtb_MathFunction_cr_idx_0 = rtb_Divide;
          rtb_MathFunction_cr_idx_1 = rtb_MathFunction_h_idx_0;
          rtb_Rem_k = rtb_Saturation_l;
        } else {
          rtb_MathFunction_cr_idx_0 = 0.0F;
          rtb_MathFunction_cr_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S153>/Switch' */

        /* Product: '<S153>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_cr_idx_0 /
          rtb_Rem_k;
        rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_cr_idx_1 /
          rtb_Rem_k;

        /* Sum: '<S151>/Subtract' incorporates:
         *  Product: '<S151>/Multiply'
         *  Product: '<S151>/Multiply1'
         */
        rtb_Saturation_l = rtb_TmpSignalConversionAtDela_a[0] *
          FMS_ConstB.Divide[1] - rtb_TmpSignalConversionAtDela_a[1] *
          FMS_ConstB.Divide[0];

        /* Signum: '<S140>/Sign1' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S140>/Sign1' */

        /* Switch: '<S140>/Switch2' incorporates:
         *  Constant: '<S140>/Constant4'
         */
        if (rtb_Saturation_l == 0.0F) {
          rtb_Saturation_l = 1.0F;
        }

        /* End of Switch: '<S140>/Switch2' */

        /* DotProduct: '<S140>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide[0] *
          rtb_TmpSignalConversionAtDela_a[0] + FMS_ConstB.Divide[1] *
          rtb_TmpSignalConversionAtDela_a[1];

        /* Trigonometry: '<S140>/Acos' incorporates:
         *  DotProduct: '<S140>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S140>/Multiply' incorporates:
         *  Trigonometry: '<S140>/Acos'
         */
        rtb_Saturation_l *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S144>/Rem' incorporates:
         *  Constant: '<S144>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sum: '<S139>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_Saturation_l - FMS_U.INS_Out.psi,
          6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S144>/Switch' incorporates:
         *  Abs: '<S144>/Abs'
         *  Constant: '<S144>/Constant'
         *  Constant: '<S150>/Constant'
         *  Product: '<S144>/Multiply'
         *  RelationalOperator: '<S150>/Compare'
         *  Sum: '<S144>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S144>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Square2 = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Square2 = 1.0F;
          } else {
            rtb_Square2 = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S144>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Square2;
        }

        /* End of Switch: '<S144>/Switch' */

        /* Abs: '<S137>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S137>/Switch' incorporates:
         *  Product: '<S159>/Multiply'
         *  Sum: '<S159>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S176>/Saturation1' */
          if (FMS_B.Merge_n[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_MathFunction_cr_idx_0 = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_n[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_MathFunction_cr_idx_0 = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_MathFunction_cr_idx_0 = FMS_B.Merge_n[0];
          }

          if (FMS_B.Merge_n[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_MathFunction_cr_idx_1 = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_n[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_MathFunction_cr_idx_1 = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_MathFunction_cr_idx_1 = FMS_B.Merge_n[1];
          }

          /* End of Saturate: '<S176>/Saturation1' */

          /* Saturate: '<S166>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_Rem_k = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Rem_k = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Rem_k = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S166>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S159>/Sum' incorporates:
           *  Delay: '<S159>/Delay'
           *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S204>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_MathFunction_cr_idx_0 = rtb_Divide_l_idx_1;
          A = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S159>/Sum' incorporates:
           *  Delay: '<S159>/Delay'
           *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S206>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S206>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S205>/Gain' incorporates:
           *  DiscreteIntegrator: '<S203>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S17>/Signal Copy1'
           *  Sum: '<S203>/Add'
           */
          rtb_Square2 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Trigonometry: '<S206>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_Square2);

          /* Gain: '<S206>/Gain' incorporates:
           *  Trigonometry: '<S206>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Square2);

          /* SignalConversion: '<S206>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S206>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S206>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_Square2);

          /* Trigonometry: '<S206>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_Square2);

          /* SignalConversion: '<S206>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Sum: '<S204>/Sum of Elements' incorporates:
           *  Math: '<S204>/Math Function'
           */
          rtb_Square2 = rtb_MathFunction_cr_idx_0 * rtb_MathFunction_cr_idx_0 +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

          /* Math: '<S204>/Math Function1' incorporates:
           *  Sum: '<S204>/Sum of Elements'
           *
           * About '<S204>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Square2 < 0.0F) {
            rtb_Square2 = -sqrtf(fabsf(rtb_Square2));
          } else {
            rtb_Square2 = sqrtf(rtb_Square2);
          }

          /* End of Math: '<S204>/Math Function1' */

          /* Switch: '<S204>/Switch' incorporates:
           *  Constant: '<S204>/Constant'
           *  Product: '<S204>/Product'
           */
          if (rtb_Square2 <= 0.0F) {
            A = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Square2 = 1.0F;
          }

          /* End of Switch: '<S204>/Switch' */

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S160>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S17>/Signal Copy1'
           *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Rem_k = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_cr_idx_0 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S160>/Divide' incorporates:
           *  Math: '<S161>/Square'
           *  Math: '<S162>/Square'
           *  Sqrt: '<S161>/Sqrt'
           *  Sqrt: '<S162>/Sqrt'
           *  Sum: '<S160>/Sum'
           *  Sum: '<S161>/Sum of Elements'
           *  Sum: '<S162>/Sum of Elements'
           */
          rtb_Rem_k = sqrtf(rtb_Rem_k * rtb_Rem_k + rtb_MathFunction_cr_idx_0 *
                            rtb_MathFunction_cr_idx_0) / sqrtf
            (rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 + rtb_Divide *
             rtb_Divide);

          /* Saturate: '<S160>/Saturation' */
          if (rtb_Rem_k > 1.0F) {
            rtb_Rem_k = 1.0F;
          } else {
            if (rtb_Rem_k < 0.0F) {
              rtb_Rem_k = 0.0F;
            }
          }

          /* End of Saturate: '<S160>/Saturation' */

          /* Product: '<S202>/Multiply2' incorporates:
           *  Product: '<S204>/Divide'
           */
          A = A / rtb_Square2 * rtb_Divide_l_idx_2;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_Square2 *
            rtb_Divide_l_idx_2;

          /* Product: '<S159>/Multiply' */
          for (i = 0; i < 3; i++) {
            rtb_Transpose_1[i] = rtb_Transpose[i + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[i] * A;
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S154>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S160>/Multiply'
           *  SignalConversion: '<S17>/Signal Copy1'
           *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S154>/Sum2'
           *  Sum: '<S160>/Add'
           *  Sum: '<S160>/Subtract'
           */
          rtb_Rem_k = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Rem_k +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction_cr_idx_0 = rtb_Transpose_1[0];
          rtb_MathFunction_cr_idx_1 = rtb_Transpose_1[1];

          /* Saturate: '<S154>/Saturation1' incorporates:
           *  Product: '<S159>/Multiply'
           */
          if (rtb_Rem_k > FMS_PARAM.VEL_Z_LIM) {
            rtb_Rem_k = FMS_PARAM.VEL_Z_LIM;
          } else {
            if (rtb_Rem_k < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Rem_k = -FMS_PARAM.VEL_Z_LIM;
            }
          }

          /* End of Saturate: '<S154>/Saturation1' */
        }

        /* Delay: '<S139>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S142>/Integrator1' incorporates:
         *  Delay: '<S139>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S146>/Rem' incorporates:
         *  Constant: '<S146>/Constant1'
         *  DiscreteIntegrator: '<S142>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sum: '<S141>/Sum'
         */
        A = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S146>/Switch' incorporates:
         *  Abs: '<S146>/Abs'
         *  Constant: '<S146>/Constant'
         *  Constant: '<S147>/Constant'
         *  Product: '<S146>/Multiply'
         *  RelationalOperator: '<S147>/Compare'
         *  Sum: '<S146>/Add'
         */
        if (fabsf(A) > 3.14159274F) {
          /* Signum: '<S146>/Sign' */
          if (A < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (A > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = A;
          }

          /* End of Signum: '<S146>/Sign' */
          A -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S146>/Switch' */

        /* Gain: '<S141>/Gain2' */
        A *= FMS_PARAM.YAW_P;

        /* Saturate: '<S141>/Saturation' */
        if (A > FMS_PARAM.YAW_RATE_LIM) {
          A = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (A < -FMS_PARAM.YAW_RATE_LIM) {
            A = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S141>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S135>/Bus Assignment'
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Constant: '<S135>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S135>/Bus Assignment' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_cr_idx_0;
        FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_cr_idx_1;
        FMS_Y.FMS_Out.w_cmd = rtb_Rem_k;
        FMS_Y.FMS_Out.psi_rate_cmd = A;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S197>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtDela_a[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_TmpSignalConversionAtDela_a[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S197>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S197>/Math Function'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        rtb_Square2 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S197>/Math Function1' incorporates:
         *  Sum: '<S197>/Sum of Elements'
         *
         * About '<S197>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Square2 < 0.0F) {
          A = -sqrtf(fabsf(rtb_Square2));
        } else {
          A = sqrtf(rtb_Square2);
        }

        /* End of Math: '<S197>/Math Function1' */

        /* Switch: '<S197>/Switch' incorporates:
         *  Constant: '<S197>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S197>/Product'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        if (A > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction_cr_idx_0 = FMS_U.INS_Out.vn;
          rtb_MathFunction_cr_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Rem_k = A;
        } else {
          rtb_MathFunction_cr_idx_0 = 0.0F;
          rtb_MathFunction_cr_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S197>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S157>/NearbyRefWP' incorporates:
         *  Constant: '<S135>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                        rtb_TmpSignalConversionAtDela_a, &rtb_Square2);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* MATLAB Function: '<S157>/SearchL1RefWP' incorporates:
         *  Constant: '<S135>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        A = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 + rtb_Divide *
          rtb_Divide;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        B = (rtb_MathFunction_h_idx_0 * (FMS_B.Cmd_In.cur_waypoint[0] -
              FMS_U.INS_Out.x_R) + rtb_Divide * (FMS_B.Cmd_In.cur_waypoint[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_B.Cmd_In.cur_waypoint[0] *
                        FMS_B.Cmd_In.cur_waypoint[0]) +
                       FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint
                       [1]) - (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0]
          + FMS_U.INS_Out.y_R * FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Divide_l_idx_1 = -1.0F;
        rtb_MathFunction_iq_idx_0 = 0.0F;
        rtb_MathFunction_iq_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          A = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
            rtb_Divide_l_idx_1 = fmaxf(D, A);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Divide_l_idx_1 = D;
            guard1 = true;
          } else {
            if ((A >= 0.0F) && (A <= 1.0F)) {
              rtb_Divide_l_idx_1 = A;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Divide_l_idx_1 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction_iq_idx_0 = rtb_MathFunction_h_idx_0 *
            rtb_Divide_l_idx_1 + FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_iq_idx_1 = rtb_Divide * rtb_Divide_l_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S157>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        A = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Divide +
             (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0]) *
             rtb_MathFunction_h_idx_0) / (rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0 + rtb_Divide * rtb_Divide);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_FixPtRelationalOperator_n = (A <= 0.0F);
        u = (A >= 1.0F);
        if (rtb_FixPtRelationalOperator_n) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction_h_idx_0 = A * rtb_MathFunction_h_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Switch: '<S157>/Switch1' incorporates:
         *  Constant: '<S190>/Constant'
         *  RelationalOperator: '<S190>/Compare'
         */
        if (rtb_Square2 <= 0.0F) {
          /* Switch: '<S157>/Switch' incorporates:
           *  Constant: '<S189>/Constant'
           *  MATLAB Function: '<S157>/SearchL1RefWP'
           *  RelationalOperator: '<S189>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_iq_idx_0;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0;

            /* MATLAB Function: '<S157>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_n) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = A * rtb_Divide +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }
          }

          /* End of Switch: '<S157>/Switch' */
        }

        /* End of Switch: '<S157>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S158>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        rtb_Divide = rtb_TmpSignalConversionAtDela_a[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Divide * rtb_Divide;
        rtb_Saturation1_ln[0] = rtb_Divide;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S158>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S198>/Math Function'
         *  SignalConversion: '<S17>/Signal Copy1'
         */
        rtb_Divide = rtb_TmpSignalConversionAtDela_a[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S198>/Math Function' incorporates:
         *  Math: '<S196>/Square'
         */
        rtb_Square2 = rtb_Divide * rtb_Divide;

        /* Sum: '<S198>/Sum of Elements' incorporates:
         *  Math: '<S198>/Math Function'
         */
        rtb_Divide_l_idx_1 = rtb_Square2 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S198>/Math Function1' incorporates:
         *  Sum: '<S198>/Sum of Elements'
         *
         * About '<S198>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          A = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          A = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S198>/Math Function1' */

        /* Switch: '<S198>/Switch' incorporates:
         *  Constant: '<S198>/Constant'
         *  Product: '<S198>/Product'
         */
        if (A > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Saturation1_ln[0];
          rtb_MatrixConcatenate3[1] = rtb_Divide;
          rtb_MatrixConcatenate3[2] = A;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S198>/Switch' */

        /* Product: '<S197>/Divide' */
        rtb_Divide_o[0] = rtb_MathFunction_cr_idx_0 / rtb_Rem_k;
        rtb_Divide_o[1] = rtb_MathFunction_cr_idx_1 / rtb_Rem_k;

        /* Sum: '<S200>/Sum of Elements' incorporates:
         *  Math: '<S200>/Math Function'
         *  SignalConversion: '<S200>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Divide_o[1] * rtb_Divide_o[1] + rtb_Divide_o[0]
          * rtb_Divide_o[0];

        /* Math: '<S200>/Math Function1' incorporates:
         *  Sum: '<S200>/Sum of Elements'
         *
         * About '<S200>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          A = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          A = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S200>/Math Function1' */

        /* Switch: '<S200>/Switch' incorporates:
         *  Constant: '<S200>/Constant'
         *  Product: '<S200>/Product'
         */
        if (A > 0.0F) {
          rtb_MathFunction_cr_idx_0 = rtb_Divide_o[1];
          rtb_MathFunction_cr_idx_1 = rtb_Divide_o[0];
          rtb_Rem_k = A;
        } else {
          rtb_MathFunction_cr_idx_0 = 0.0F;
          rtb_MathFunction_cr_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S200>/Switch' */

        /* Product: '<S198>/Divide' */
        rtb_Divide_o[0] = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];
        rtb_Divide_o[1] = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S201>/Sum of Elements' incorporates:
         *  Math: '<S201>/Math Function'
         *  SignalConversion: '<S201>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Divide_o[1] * rtb_Divide_o[1] + rtb_Divide_o[0]
          * rtb_Divide_o[0];

        /* Math: '<S201>/Math Function1' incorporates:
         *  Sum: '<S201>/Sum of Elements'
         *
         * About '<S201>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          A = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          A = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S201>/Math Function1' */

        /* Switch: '<S201>/Switch' incorporates:
         *  Constant: '<S201>/Constant'
         *  Product: '<S201>/Product'
         */
        if (A > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Divide_o[1];
          rtb_MatrixConcatenate3[1] = rtb_Divide_o[0];
          rtb_MatrixConcatenate3[2] = A;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S201>/Switch' */

        /* Product: '<S201>/Divide' */
        rtb_Divide_o[0] = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3[2];

        /* Product: '<S200>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_cr_idx_0 /
          rtb_Rem_k;
        rtb_Saturation1_ln[0] *= rtb_Saturation1_ln[0];

        /* Product: '<S201>/Divide' incorporates:
         *  Math: '<S196>/Square'
         */
        rtb_Divide_o[1] = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S200>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_cr_idx_1 /
          rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S195>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S195>/Square'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sum: '<S195>/Sum of Elements'
         */
        A = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                  FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Gain: '<S158>/Gain' incorporates:
         *  Math: '<S158>/Square'
         */
        rtb_Rem_k = A * A * 2.0F;

        /* Sum: '<S199>/Subtract' incorporates:
         *  Product: '<S199>/Multiply'
         *  Product: '<S199>/Multiply1'
         */
        A = rtb_Divide_o[0] * rtb_TmpSignalConversionAtDela_a[1] - rtb_Divide_o
          [1] * rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S194>/Sign1' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S194>/Sign1' */

        /* Switch: '<S194>/Switch2' incorporates:
         *  Constant: '<S194>/Constant4'
         */
        if (A == 0.0F) {
          A = 1.0F;
        }

        /* End of Switch: '<S194>/Switch2' */

        /* DotProduct: '<S194>/Dot Product' */
        rtb_Divide_l_idx_1 = rtb_TmpSignalConversionAtDela_a[0] * rtb_Divide_o[0]
          + rtb_TmpSignalConversionAtDela_a[1] * rtb_Divide_o[1];

        /* Trigonometry: '<S194>/Acos' incorporates:
         *  DotProduct: '<S194>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S194>/Multiply' incorporates:
         *  Trigonometry: '<S194>/Acos'
         */
        A *= acosf(rtb_Divide_l_idx_1);

        /* Saturate: '<S158>/Saturation' */
        if (A > 1.57079637F) {
          A = 1.57079637F;
        } else {
          if (A < -1.57079637F) {
            A = -1.57079637F;
          }
        }

        /* End of Saturate: '<S158>/Saturation' */

        /* Product: '<S158>/Divide' incorporates:
         *  Constant: '<S135>/L1'
         *  Constant: '<S158>/Constant'
         *  MinMax: '<S158>/Max'
         *  MinMax: '<S158>/Min'
         *  Product: '<S158>/Multiply1'
         *  Sqrt: '<S196>/Sqrt'
         *  Sum: '<S196>/Sum of Elements'
         *  Trigonometry: '<S158>/Sin'
         */
        rtb_Rem_k = arm_sin_f32(A) * rtb_Rem_k / fminf(FMS_PARAM.L1, fmaxf(sqrtf
          (rtb_Square2 + rtb_Saturation1_ln[0]), 0.5F));

        /* Sum: '<S139>/Sum2' incorporates:
         *  Delay: '<S139>/Delay'
         */
        rtb_Saturation_l -= FMS_DW.Delay_DSTATE_h;

        /* Math: '<S143>/Rem' incorporates:
         *  Constant: '<S143>/Constant1'
         */
        rtb_Square2 = rt_remf(rtb_Saturation_l, 6.28318548F);

        /* Switch: '<S143>/Switch' incorporates:
         *  Abs: '<S143>/Abs'
         *  Constant: '<S143>/Constant'
         *  Constant: '<S149>/Constant'
         *  Product: '<S143>/Multiply'
         *  RelationalOperator: '<S149>/Compare'
         *  Sum: '<S143>/Add'
         */
        if (fabsf(rtb_Square2) > 3.14159274F) {
          /* Signum: '<S143>/Sign' */
          if (rtb_Square2 < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Square2 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Square2;
          }

          /* End of Signum: '<S143>/Sign' */
          rtb_Square2 -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S143>/Switch' */

        /* Sum: '<S139>/Sum' incorporates:
         *  Delay: '<S139>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Square2 + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S148>/Multiply1' incorporates:
         *  Constant: '<S148>/const1'
         *  DiscreteIntegrator: '<S142>/Integrator'
         */
        rtb_Square2 = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S148>/Add' incorporates:
         *  DiscreteIntegrator: '<S142>/Integrator1'
         *  Sum: '<S142>/Subtract'
         */
        A = (FMS_DW.Integrator1_DSTATE_p - rtb_Divide_l_idx_1) + rtb_Square2;

        /* Signum: '<S148>/Sign' */
        if (A < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (A > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = A;
        }

        /* End of Signum: '<S148>/Sign' */

        /* Sum: '<S148>/Add2' incorporates:
         *  Abs: '<S148>/Abs'
         *  Gain: '<S148>/Gain'
         *  Gain: '<S148>/Gain1'
         *  Product: '<S148>/Multiply2'
         *  Product: '<S148>/Multiply3'
         *  Sqrt: '<S148>/Sqrt'
         *  Sum: '<S148>/Add1'
         *  Sum: '<S148>/Subtract'
         */
        rtb_Saturation_l = (sqrtf((8.0F * fabsf(A) + FMS_ConstB.d_j) *
          FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_Divide_l_idx_1 +
          rtb_Square2;

        /* Sum: '<S148>/Add4' */
        rtb_Square2 += A - rtb_Saturation_l;

        /* Sum: '<S148>/Add3' */
        rtb_Divide_l_idx_1 = A + FMS_ConstB.d_j;

        /* Sum: '<S148>/Subtract1' */
        A -= FMS_ConstB.d_j;

        /* Signum: '<S148>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S148>/Sign1' */

        /* Signum: '<S148>/Sign2' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S148>/Sign2' */

        /* Sum: '<S148>/Add5' incorporates:
         *  Gain: '<S148>/Gain2'
         *  Product: '<S148>/Multiply4'
         *  Sum: '<S148>/Subtract2'
         */
        rtb_Saturation_l += (rtb_Divide_l_idx_1 - A) * 0.5F * rtb_Square2;

        /* Update for Delay: '<S159>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S203>/Discrete-Time Integrator' incorporates:
         *  Product: '<S159>/Divide1'
         */
        FMS_DW.l1_heading += rtb_Rem_k / rtb_Divide_l_idx_2 * 0.004F;

        /* Update for Delay: '<S139>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S142>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S142>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Sum: '<S148>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Saturation_l + FMS_ConstB.d_j;

        /* Sum: '<S148>/Subtract3' */
        A = rtb_Saturation_l - FMS_ConstB.d_j;

        /* Signum: '<S148>/Sign5' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_Divide_l_idx_2 = rtb_Saturation_l;
        }

        /* End of Signum: '<S148>/Sign5' */

        /* Signum: '<S148>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S148>/Sign3' */

        /* Signum: '<S148>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S148>/Sign4' */

        /* Signum: '<S148>/Sign6' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Square2 = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Square2 = 1.0F;
        } else {
          rtb_Square2 = rtb_Saturation_l;
        }

        /* End of Signum: '<S148>/Sign6' */

        /* Update for DiscreteIntegrator: '<S142>/Integrator' incorporates:
         *  Constant: '<S148>/const'
         *  Gain: '<S148>/Gain3'
         *  Product: '<S148>/Divide'
         *  Product: '<S148>/Multiply5'
         *  Product: '<S148>/Multiply6'
         *  Sum: '<S148>/Subtract4'
         *  Sum: '<S148>/Subtract5'
         *  Sum: '<S148>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_Saturation_l / FMS_ConstB.d_j -
          rtb_Divide_l_idx_2) * FMS_ConstB.Gain4_c * ((rtb_Divide_l_idx_1 - A) *
          0.5F) - rtb_Square2 * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S142>/Integrator' */
        /* End of Outputs for SubSystem: '<S131>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Update for UnitDelay: '<S134>/Delay Input1' incorporates:
         *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S134>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S23>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S23>/Unknown' incorporates:
         *  ActionPort: '<S133>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S23>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S23>/Switch Case' */
      /* End of Outputs for SubSystem: '<S18>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S18>/Assist' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* SwitchCase: '<S22>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
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

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S118>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S37>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S54>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S94>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S70>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S81>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S22>/Acro' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  BusAssignment: '<S27>/Bus Assignment'
         *  Constant: '<S27>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Gain: '<S32>/Gain'
         *  Gain: '<S32>/Gain1'
         *  Gain: '<S32>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S33>/Saturation' incorporates:
         *  Constant: '<S33>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy2'
         *  Sum: '<S33>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Square2 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Square2 = 0.0F;
        } else {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S33>/Saturation' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Constant: '<S33>/Constant5'
         *  Gain: '<S33>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S33>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F * rtb_Square2),
          4.2949673E+9F) + 1000U;

        /* End of Outputs for SubSystem: '<S22>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S22>/Stabilize' incorporates:
           *  ActionPort: '<S30>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S22>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S114>/Integrator'
           *  DiscreteIntegrator: '<S114>/Integrator1'
           *  DiscreteIntegrator: '<S115>/Integrator'
           *  DiscreteIntegrator: '<S115>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_jt = 0.0F;
          FMS_DW.Integrator_DSTATE_cq = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S22>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S22>/Stabilize' incorporates:
           *  ActionPort: '<S30>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S22>/Switch Case' incorporates:
           *  Chart: '<S119>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S22>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Stabilize' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        /* Product: '<S116>/Multiply1' incorporates:
         *  Constant: '<S116>/const1'
         *  DiscreteIntegrator: '<S114>/Integrator'
         */
        A = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S112>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Square2 = 0.0F;
        } else {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S112>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S116>/Add' incorporates:
         *  DiscreteIntegrator: '<S114>/Integrator1'
         *  Gain: '<S109>/Gain'
         *  Gain: '<S112>/Gain'
         *  Sum: '<S114>/Subtract'
         */
        rtb_Saturation_l = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Square2 * FMS_PARAM.ROLL_PITCH_LIM) + A;

        /* Signum: '<S116>/Sign' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Saturation_l;
        }

        /* End of Signum: '<S116>/Sign' */

        /* Sum: '<S116>/Add2' incorporates:
         *  Abs: '<S116>/Abs'
         *  Gain: '<S116>/Gain'
         *  Gain: '<S116>/Gain1'
         *  Product: '<S116>/Multiply2'
         *  Product: '<S116>/Multiply3'
         *  Sqrt: '<S116>/Sqrt'
         *  Sum: '<S116>/Add1'
         *  Sum: '<S116>/Subtract'
         */
        rtb_Divide_l_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_l) +
          FMS_ConstB.d_d) * FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
          rtb_Divide_l_idx_1 + A;

        /* Sum: '<S116>/Add4' */
        rtb_Square2 = (rtb_Saturation_l - rtb_Divide_l_idx_2) + A;

        /* Sum: '<S116>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Saturation_l + FMS_ConstB.d_d;

        /* Sum: '<S116>/Subtract1' */
        rtb_Saturation_l -= FMS_ConstB.d_d;

        /* Signum: '<S116>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign1' */

        /* Signum: '<S116>/Sign2' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign2' */

        /* Sum: '<S116>/Add5' incorporates:
         *  Gain: '<S116>/Gain2'
         *  Product: '<S116>/Multiply4'
         *  Sum: '<S116>/Subtract2'
         */
        rtb_Divide_l_idx_2 += (rtb_Divide_l_idx_1 - rtb_Saturation_l) * 0.5F *
          rtb_Square2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S119>/Motion State' incorporates:
         *  Abs: '<S119>/Abs'
         *  Abs: '<S119>/Abs1'
         *  Constant: '<S129>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S129>/Compare'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S118>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S118>/Hold Control' incorporates:
             *  ActionPort: '<S121>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S118>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S118>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S118>/Hold Control' incorporates:
           *  ActionPort: '<S121>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                             &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S118>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S118>/Brake Control' incorporates:
           *  ActionPort: '<S120>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S118>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S118>/Move Control' incorporates:
             *  ActionPort: '<S122>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S118>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S118>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S118>/Move Control' incorporates:
           *  ActionPort: '<S122>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S118>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S118>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S30>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S30>/Bus Assignment' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  DiscreteIntegrator: '<S114>/Integrator1'
         *  DiscreteIntegrator: '<S115>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_j;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_jt;

        /* Saturate: '<S118>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S30>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S30>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S30>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S118>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Saturate: '<S111>/Saturation' incorporates:
         *  Constant: '<S111>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy2'
         *  Sum: '<S111>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Square2 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Square2 = 0.0F;
        } else {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S111>/Saturation' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S30>/Bus Assignment' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Constant: '<S111>/Constant5'
         *  Gain: '<S111>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S111>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F * rtb_Square2),
          4.2949673E+9F) + 1000U;

        /* Product: '<S117>/Multiply1' incorporates:
         *  Constant: '<S117>/const1'
         *  DiscreteIntegrator: '<S115>/Integrator'
         */
        rtb_Saturation_l = FMS_DW.Integrator_DSTATE_cq * 0.04F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S113>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Square2 = 0.0F;
        } else {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S113>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S117>/Add' incorporates:
         *  DiscreteIntegrator: '<S115>/Integrator1'
         *  Gain: '<S109>/Gain1'
         *  Gain: '<S113>/Gain'
         *  Sum: '<S115>/Subtract'
         */
        A = (FMS_DW.Integrator1_DSTATE_jt - 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
             rtb_Square2 * -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Saturation_l;

        /* Signum: '<S117>/Sign' */
        if (A < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (A > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = A;
        }

        /* End of Signum: '<S117>/Sign' */

        /* Sum: '<S117>/Add2' incorporates:
         *  Abs: '<S117>/Abs'
         *  Gain: '<S117>/Gain'
         *  Gain: '<S117>/Gain1'
         *  Product: '<S117>/Multiply2'
         *  Product: '<S117>/Multiply3'
         *  Sqrt: '<S117>/Sqrt'
         *  Sum: '<S117>/Add1'
         *  Sum: '<S117>/Subtract'
         */
        rtb_Square2 = (sqrtf((8.0F * fabsf(A) + FMS_ConstB.d_o) * FMS_ConstB.d_o)
                       - FMS_ConstB.d_o) * 0.5F * rtb_Divide_l_idx_1 +
          rtb_Saturation_l;

        /* Sum: '<S117>/Add4' */
        rtb_Saturation_l += A - rtb_Square2;

        /* Sum: '<S117>/Add3' */
        rtb_Divide_l_idx_1 = A + FMS_ConstB.d_o;

        /* Sum: '<S117>/Subtract1' */
        A -= FMS_ConstB.d_o;

        /* Signum: '<S117>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S117>/Sign1' */

        /* Signum: '<S117>/Sign2' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S117>/Sign2' */

        /* Sum: '<S117>/Add5' incorporates:
         *  Gain: '<S117>/Gain2'
         *  Product: '<S117>/Multiply4'
         *  Sum: '<S117>/Subtract2'
         */
        rtb_Square2 += (rtb_Divide_l_idx_1 - A) * 0.5F * rtb_Saturation_l;

        /* Update for DiscreteIntegrator: '<S114>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S114>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S116>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Divide_l_idx_2 + FMS_ConstB.d_d;

        /* Sum: '<S116>/Subtract3' */
        A = rtb_Divide_l_idx_2 - FMS_ConstB.d_d;

        /* Signum: '<S116>/Sign5' */
        if (rtb_Divide_l_idx_2 < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else if (rtb_Divide_l_idx_2 > 0.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          rtb_Saturation_l = rtb_Divide_l_idx_2;
        }

        /* End of Signum: '<S116>/Sign5' */

        /* Signum: '<S116>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign3' */

        /* Signum: '<S116>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign4' */

        /* Signum: '<S116>/Sign6' */
        if (rtb_Divide_l_idx_2 < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else if (rtb_Divide_l_idx_2 > 0.0F) {
          rtb_Rem_k = 1.0F;
        } else {
          rtb_Rem_k = rtb_Divide_l_idx_2;
        }

        /* End of Signum: '<S116>/Sign6' */

        /* Update for DiscreteIntegrator: '<S114>/Integrator' incorporates:
         *  Constant: '<S116>/const'
         *  Gain: '<S116>/Gain3'
         *  Product: '<S116>/Divide'
         *  Product: '<S116>/Multiply5'
         *  Product: '<S116>/Multiply6'
         *  Sum: '<S116>/Subtract4'
         *  Sum: '<S116>/Subtract5'
         *  Sum: '<S116>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Divide_l_idx_2 / FMS_ConstB.d_d -
          rtb_Saturation_l) * FMS_ConstB.Gain4_n * ((rtb_Divide_l_idx_1 - A) *
          0.5F) - rtb_Rem_k * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S115>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S115>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_jt += 0.004F * FMS_DW.Integrator_DSTATE_cq;

        /* Sum: '<S117>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Square2 + FMS_ConstB.d_o;

        /* Sum: '<S117>/Subtract3' */
        A = rtb_Square2 - FMS_ConstB.d_o;

        /* Signum: '<S117>/Sign5' */
        if (rtb_Square2 < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_Divide_l_idx_2 = rtb_Square2;
        }

        /* End of Signum: '<S117>/Sign5' */

        /* Signum: '<S117>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S117>/Sign3' */

        /* Signum: '<S117>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S117>/Sign4' */

        /* Signum: '<S117>/Sign6' */
        if (rtb_Square2 < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          rtb_Saturation_l = rtb_Square2;
        }

        /* End of Signum: '<S117>/Sign6' */

        /* Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
         *  Constant: '<S117>/const'
         *  Gain: '<S117>/Gain3'
         *  Product: '<S117>/Divide'
         *  Product: '<S117>/Multiply5'
         *  Product: '<S117>/Multiply6'
         *  Sum: '<S117>/Subtract4'
         *  Sum: '<S117>/Subtract5'
         *  Sum: '<S117>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_cq += ((rtb_Square2 / FMS_ConstB.d_o -
          rtb_Divide_l_idx_2) * FMS_ConstB.Gain4_n3 * ((rtb_Divide_l_idx_1 - A) *
          0.5F) - rtb_Saturation_l * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S22>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S22>/Altitude' incorporates:
           *  ActionPort: '<S28>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S22>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S50>/Integrator'
           *  DiscreteIntegrator: '<S50>/Integrator1'
           *  DiscreteIntegrator: '<S51>/Integrator'
           *  DiscreteIntegrator: '<S51>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S22>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S22>/Altitude' incorporates:
           *  ActionPort: '<S28>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S22>/Switch Case' incorporates:
           *  Chart: '<S38>/Motion Status'
           *  Chart: '<S55>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S22>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Altitude' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S38>/Motion Status' incorporates:
         *  Abs: '<S38>/Abs'
         *  Abs: '<S38>/Abs1'
         *  Constant: '<S46>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S46>/Compare'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S37>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S37>/Hold Control' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S37>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S37>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S37>/Hold Control' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S37>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S37>/Brake Control' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S37>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S37>/Move Control' incorporates:
             *  ActionPort: '<S41>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S37>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

            /* End of SystemReset for SubSystem: '<S37>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S37>/Move Control' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_l,
                          &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S37>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S37>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S55>/Motion State' incorporates:
         *  Abs: '<S55>/Abs'
         *  Abs: '<S55>/Abs1'
         *  Constant: '<S65>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S65>/Compare'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S54>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S54>/Hold Control' incorporates:
             *  ActionPort: '<S57>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S54>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S54>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S54>/Hold Control' incorporates:
           *  ActionPort: '<S57>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                             &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S54>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S54>/Brake Control' incorporates:
           *  ActionPort: '<S56>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S54>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S54>/Move Control' incorporates:
             *  ActionPort: '<S58>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S54>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_cr);

            /* End of SystemReset for SubSystem: '<S54>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S54>/Move Control' incorporates:
           *  ActionPort: '<S58>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_cr, &FMS_DW.MoveControl_cr);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S54>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S54>/Switch Case' */

        /* Product: '<S52>/Multiply1' incorporates:
         *  Constant: '<S52>/const1'
         *  DiscreteIntegrator: '<S50>/Integrator'
         */
        rtb_Saturation_l = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S48>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Square2 = 0.0F;
        } else {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S48>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S52>/Add' incorporates:
         *  DiscreteIntegrator: '<S50>/Integrator1'
         *  Gain: '<S35>/Gain'
         *  Gain: '<S48>/Gain'
         *  Sum: '<S50>/Subtract'
         */
        rtb_Divide_l_idx_2 = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Square2 * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Saturation_l;

        /* Signum: '<S52>/Sign' */
        if (rtb_Divide_l_idx_2 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Divide_l_idx_2 > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_2;
        }

        /* End of Signum: '<S52>/Sign' */

        /* Sum: '<S52>/Add2' incorporates:
         *  Abs: '<S52>/Abs'
         *  Gain: '<S52>/Gain'
         *  Gain: '<S52>/Gain1'
         *  Product: '<S52>/Multiply2'
         *  Product: '<S52>/Multiply3'
         *  Sqrt: '<S52>/Sqrt'
         *  Sum: '<S52>/Add1'
         *  Sum: '<S52>/Subtract'
         */
        rtb_Rem_k = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_2) + FMS_ConstB.d) *
                           FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Saturation_l;

        /* Sum: '<S52>/Add4' */
        rtb_Square2 = (rtb_Divide_l_idx_2 - rtb_Rem_k) + rtb_Saturation_l;

        /* Sum: '<S52>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Divide_l_idx_2 + FMS_ConstB.d;

        /* Sum: '<S52>/Subtract1' */
        rtb_Divide_l_idx_2 -= FMS_ConstB.d;

        /* Signum: '<S52>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign1' */

        /* Signum: '<S52>/Sign2' */
        if (rtb_Divide_l_idx_2 < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_2 > 0.0F) {
            rtb_Divide_l_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign2' */

        /* Sum: '<S52>/Add5' incorporates:
         *  Gain: '<S52>/Gain2'
         *  Product: '<S52>/Multiply4'
         *  Sum: '<S52>/Subtract2'
         */
        rtb_Rem_k += (rtb_Divide_l_idx_1 - rtb_Divide_l_idx_2) * 0.5F *
          rtb_Square2;

        /* Sum: '<S52>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k - FMS_ConstB.d;

        /* Sum: '<S52>/Add6' */
        A = rtb_Rem_k + FMS_ConstB.d;

        /* Product: '<S52>/Divide' */
        rtb_Divide = rtb_Rem_k / FMS_ConstB.d;

        /* Signum: '<S52>/Sign5' incorporates:
         *  Signum: '<S52>/Sign6'
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_MathFunction_h_idx_0 = -1.0F;
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_MathFunction_h_idx_0 = 1.0F;
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_MathFunction_h_idx_0 = rtb_Rem_k;
          rtb_Divide_l_idx_2 = rtb_Rem_k;
        }

        /* End of Signum: '<S52>/Sign5' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S28>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  DiscreteIntegrator: '<S50>/Integrator1'
         *  DiscreteIntegrator: '<S51>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S54>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S54>/Saturation' */

        /* Saturate: '<S37>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S37>/Saturation1' */

        /* Product: '<S53>/Multiply1' incorporates:
         *  Constant: '<S53>/const1'
         *  DiscreteIntegrator: '<S51>/Integrator'
         */
        rtb_Rem_k = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S49>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Square2 = 0.0F;
        } else {
          rtb_Square2 = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S49>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S53>/Add' incorporates:
         *  DiscreteIntegrator: '<S51>/Integrator1'
         *  Gain: '<S35>/Gain1'
         *  Gain: '<S49>/Gain'
         *  Sum: '<S51>/Subtract'
         */
        rtb_Saturation_l = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * rtb_Square2 * -FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Rem_k;

        /* Signum: '<S53>/Sign' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Square2 = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Square2 = 1.0F;
        } else {
          rtb_Square2 = rtb_Saturation_l;
        }

        /* End of Signum: '<S53>/Sign' */

        /* Sum: '<S53>/Add2' incorporates:
         *  Abs: '<S53>/Abs'
         *  Gain: '<S53>/Gain'
         *  Gain: '<S53>/Gain1'
         *  Product: '<S53>/Multiply2'
         *  Product: '<S53>/Multiply3'
         *  Sqrt: '<S53>/Sqrt'
         *  Sum: '<S53>/Add1'
         *  Sum: '<S53>/Subtract'
         */
        rtb_Square2 = (sqrtf((8.0F * fabsf(rtb_Saturation_l) + FMS_ConstB.d_c) *
                             FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
          rtb_Square2 + rtb_Rem_k;

        /* Sum: '<S53>/Add4' */
        rtb_Rem_k += rtb_Saturation_l - rtb_Square2;

        /* Sum: '<S53>/Add3' */
        rtb_MathFunction_cr_idx_0 = rtb_Saturation_l + FMS_ConstB.d_c;

        /* Sum: '<S53>/Subtract1' */
        rtb_Saturation_l -= FMS_ConstB.d_c;

        /* Signum: '<S53>/Sign1' */
        if (rtb_MathFunction_cr_idx_0 < 0.0F) {
          rtb_MathFunction_cr_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_cr_idx_0 > 0.0F) {
            rtb_MathFunction_cr_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S53>/Sign1' */

        /* Signum: '<S53>/Sign2' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S53>/Sign2' */

        /* Sum: '<S53>/Add5' incorporates:
         *  Gain: '<S53>/Gain2'
         *  Product: '<S53>/Multiply4'
         *  Sum: '<S53>/Subtract2'
         */
        rtb_Square2 += (rtb_MathFunction_cr_idx_0 - rtb_Saturation_l) * 0.5F *
          rtb_Rem_k;

        /* Update for DiscreteIntegrator: '<S50>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S50>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S52>/Sign3' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign3' */

        /* Signum: '<S52>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign4' */

        /* Update for DiscreteIntegrator: '<S50>/Integrator' incorporates:
         *  Constant: '<S52>/const'
         *  Gain: '<S52>/Gain3'
         *  Product: '<S52>/Multiply5'
         *  Product: '<S52>/Multiply6'
         *  Sum: '<S52>/Subtract4'
         *  Sum: '<S52>/Subtract5'
         *  Sum: '<S52>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_Divide - rtb_MathFunction_h_idx_0) *
          FMS_ConstB.Gain4 * ((A - rtb_Divide_l_idx_1) * 0.5F) -
          rtb_Divide_l_idx_2 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S51>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S51>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S53>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Square2 + FMS_ConstB.d_c;

        /* Sum: '<S53>/Subtract3' */
        A = rtb_Square2 - FMS_ConstB.d_c;

        /* Signum: '<S53>/Sign5' */
        if (rtb_Square2 < 0.0F) {
          rtb_Divide_l_idx_2 = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Divide_l_idx_2 = 1.0F;
        } else {
          rtb_Divide_l_idx_2 = rtb_Square2;
        }

        /* End of Signum: '<S53>/Sign5' */

        /* Signum: '<S53>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S53>/Sign3' */

        /* Signum: '<S53>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S53>/Sign4' */

        /* Signum: '<S53>/Sign6' */
        if (rtb_Square2 < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else if (rtb_Square2 > 0.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          rtb_Saturation_l = rtb_Square2;
        }

        /* End of Signum: '<S53>/Sign6' */

        /* Update for DiscreteIntegrator: '<S51>/Integrator' incorporates:
         *  Constant: '<S53>/const'
         *  Gain: '<S53>/Gain3'
         *  Product: '<S53>/Divide'
         *  Product: '<S53>/Multiply5'
         *  Product: '<S53>/Multiply6'
         *  Sum: '<S53>/Subtract4'
         *  Sum: '<S53>/Subtract5'
         *  Sum: '<S53>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Square2 / FMS_ConstB.d_c -
          rtb_Divide_l_idx_2) * FMS_ConstB.Gain4_m * ((rtb_Divide_l_idx_1 - A) *
          0.5F) - rtb_Saturation_l * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S22>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S22>/Position' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S22>/Switch Case' incorporates:
           *  Chart: '<S71>/Motion Status'
           *  Chart: '<S82>/Motion State'
           *  Chart: '<S95>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_i);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S22>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Position' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S71>/Motion Status' incorporates:
         *  Abs: '<S71>/Abs'
         *  Abs: '<S71>/Abs1'
         *  Constant: '<S79>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S79>/Compare'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_i);

        /* Chart: '<S82>/Motion State' incorporates:
         *  Abs: '<S82>/Abs'
         *  Abs: '<S82>/Abs1'
         *  Constant: '<S92>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S92>/Compare'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_ki,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S95>/Logical Operator' incorporates:
         *  Abs: '<S95>/Abs1'
         *  Abs: '<S95>/Abs2'
         *  Constant: '<S106>/Constant'
         *  Constant: '<S107>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S106>/Compare'
         *  RelationalOperator: '<S107>/Compare'
         *  SignalConversion: '<S17>/Signal Copy2'
         */
        rtb_FixPtRelationalOperator_n = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Chart: '<S95>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S95>/Square'
         *  Math: '<S95>/Square1'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  Sqrt: '<S95>/Sqrt'
         *  Sum: '<S95>/Add'
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

            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_i
                 >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_d;
              rtb_state_l = MotionState_Hold;
            } else {
              if (rtb_FixPtRelationalOperator_n) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_n;
                rtb_state_l = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_l = MotionState_Hold;
            if (rtb_FixPtRelationalOperator_n) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_n;
              rtb_state_l = MotionState_Move;
            }
            break;

           default:
            rtb_state_l = MotionState_Move;
            if (!rtb_FixPtRelationalOperator_n) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_l = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S95>/Motion State' */

        /* SwitchCase: '<S94>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S94>/Hold Control' incorporates:
             *  ActionPort: '<S97>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S94>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S94>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S94>/Hold Control' incorporates:
           *  ActionPort: '<S97>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S94>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S94>/Brake Control' incorporates:
           *  ActionPort: '<S96>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S94>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S94>/Move Control' incorporates:
             *  ActionPort: '<S98>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S94>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S94>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S94>/Move Control' incorporates:
           *  ActionPort: '<S98>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S94>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S94>/Switch Case' */

        /* SwitchCase: '<S70>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S70>/Hold Control' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S70>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S70>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S70>/Hold Control' incorporates:
           *  ActionPort: '<S73>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S70>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S70>/Brake Control' incorporates:
           *  ActionPort: '<S72>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S70>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S70>/Move Control' incorporates:
             *  ActionPort: '<S74>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S70>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_be);

            /* End of SystemReset for SubSystem: '<S70>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S70>/Move Control' incorporates:
           *  ActionPort: '<S74>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_k,
                          &FMS_ConstB.MoveControl_be, &FMS_DW.MoveControl_be);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S70>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S70>/Switch Case' */

        /* SwitchCase: '<S81>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S17>/Signal Copy1'
         *  SignalConversion: '<S17>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S81>/Hold Control' incorporates:
             *  ActionPort: '<S84>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S81>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S81>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S81>/Hold Control' incorporates:
           *  ActionPort: '<S84>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                             &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S81>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S81>/Brake Control' incorporates:
           *  ActionPort: '<S83>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S81>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S81>/Move Control' incorporates:
             *  ActionPort: '<S85>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S81>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_mr);

            /* End of SystemReset for SubSystem: '<S81>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S81>/Move Control' incorporates:
           *  ActionPort: '<S85>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_mr, &FMS_DW.MoveControl_mr);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S81>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S81>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  BusAssignment: '<S29>/Bus Assignment'
         *  Constant: '<S29>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S81>/Saturation' */
        if (FMS_B.Merge_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_d;
        }

        /* End of Saturate: '<S81>/Saturation' */

        /* Saturate: '<S94>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S94>/Saturation1' */

        /* Saturate: '<S70>/Saturation1' */
        if (FMS_B.Merge_k > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_k < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S19>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_k;
        }

        /* End of Saturate: '<S70>/Saturation1' */
        /* End of Outputs for SubSystem: '<S22>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
         *  ActionPort: '<S31>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S19>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S22>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S22>/Switch Case' */
      /* End of Outputs for SubSystem: '<S18>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S18>/Manual' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S19>/Bus Assignment'
       *  BusAssignment: '<S24>/Bus Assignment'
       *  Constant: '<S24>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S24>/Bus Assignment' incorporates:
       *  BusAssignment: '<S19>/Bus Assignment'
       *  Constant: '<S24>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S18>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S18>/Unknown' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S19>/Bus Assignment'
       */
      FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S18>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S18>/Switch Case' */
    /* End of Outputs for SubSystem: '<S16>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S16>/Switch Case' */

  /* BusAssignment: '<S19>/Bus Assignment' incorporates:
   *  Constant: '<S19>/Constant'
   *  DataTypeConversion: '<S19>/Data Type Conversion'
   *  DiscreteIntegrator: '<S330>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S17>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S19>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

  /* Update for DiscreteIntegrator: '<S330>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S330>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Update for DiscreteIntegrator: '<S346>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S346>/Gain'
   *  Sum: '<S346>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S347>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S347>/Gain'
   *  Sum: '<S347>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  rtb_Square2 = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Square2 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Square2;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S15>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S11>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S12>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;
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
  /* Start for SwitchCase: '<S16>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S16>/Arm' */
  /* Start for SwitchCase: '<S18>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S18>/SubMode' */
  /* Start for SwitchCase: '<S25>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_at = -1;

  /* Start for IfAction SubSystem: '<S25>/Return' */
  /* Start for SwitchCase: '<S291>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S281>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S25>/Return' */

  /* Start for IfAction SubSystem: '<S25>/Hold' */
  /* Start for SwitchCase: '<S237>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S215>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S225>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S25>/Hold' */
  /* End of Start for SubSystem: '<S18>/SubMode' */

  /* Start for IfAction SubSystem: '<S18>/Auto' */
  /* Start for SwitchCase: '<S23>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S23>/Mission' */
  /* Start for Resettable SubSystem: '<S131>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S176>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S166>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S131>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S23>/Mission' */
  /* End of Start for SubSystem: '<S18>/Auto' */

  /* Start for IfAction SubSystem: '<S18>/Assist' */
  /* Start for SwitchCase: '<S22>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S22>/Stabilize' */
  /* Start for SwitchCase: '<S118>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S22>/Stabilize' */

  /* Start for IfAction SubSystem: '<S22>/Altitude' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S54>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S22>/Altitude' */

  /* Start for IfAction SubSystem: '<S22>/Position' */
  /* Start for SwitchCase: '<S94>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S70>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S81>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S22>/Position' */
  /* End of Start for SubSystem: '<S18>/Assist' */
  /* End of Start for SubSystem: '<S16>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S346>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S347>/Discrete-Time Integrator5' */
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
  /* SystemInitialize for IfAction SubSystem: '<S16>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S18>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S25>/Return' */
  /* InitializeConditions for Delay: '<S277>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S318>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_p = 0.0F;

  /* InitializeConditions for Delay: '<S257>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for Delay: '<S258>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S261>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S261>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S292>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S291>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S291>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S291>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S291>/Move Control' */

  /* SystemInitialize for Merge: '<S291>/Merge' */
  FMS_B.Merge_mv[0] = 0.0F;
  FMS_B.Merge_mv[1] = 0.0F;

  /* SystemInitialize for Chart: '<S282>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S281>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S281>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S281>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S281>/Move Control' */

  /* SystemInitialize for Merge: '<S281>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S25>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S25>/Hold' */
  /* SystemInitialize for Chart: '<S216>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S226>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S238>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S237>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S237>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S237>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S237>/Move Control' */

  /* SystemInitialize for Merge: '<S237>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S215>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S215>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S215>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S215>/Move Control' */

  /* SystemInitialize for Merge: '<S215>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S225>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_kq);

  /* End of SystemInitialize for SubSystem: '<S225>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S225>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S225>/Move Control' */

  /* SystemInitialize for Merge: '<S225>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S25>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S18>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S18>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S23>/Mission' */
  /* InitializeConditions for UnitDelay: '<S134>/Delay Input1'
   *
   * Block description for '<S134>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S131>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S159>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S203>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S139>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S177>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S176>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S176>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S176>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S176>/Move Control' */

  /* SystemInitialize for Merge: '<S176>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S167>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S166>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S166>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S166>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S166>/Move Control' */

  /* SystemInitialize for Merge: '<S166>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S131>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S23>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S18>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S18>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jt = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator' */
  FMS_DW.Integrator_DSTATE_cq = 0.0F;

  /* SystemInitialize for Chart: '<S119>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S118>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S118>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S118>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S118>/Move Control' */

  /* SystemInitialize for Merge: '<S118>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S22>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S22>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S50>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S38>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S37>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S37>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S37>/Move Control' */

  /* SystemInitialize for Chart: '<S55>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S54>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S54>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S54>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_cr);

  /* End of SystemInitialize for SubSystem: '<S54>/Move Control' */

  /* SystemInitialize for Merge: '<S37>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Merge: '<S54>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S22>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S22>/Position' */
  /* SystemInitialize for Chart: '<S71>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for Chart: '<S82>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S95>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S94>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S94>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S94>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S94>/Move Control' */

  /* SystemInitialize for Merge: '<S94>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S70>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S70>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S70>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_be);

  /* End of SystemInitialize for SubSystem: '<S70>/Move Control' */

  /* SystemInitialize for Merge: '<S70>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S81>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S81>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S81>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_mr);

  /* End of SystemInitialize for SubSystem: '<S81>/Move Control' */

  /* SystemInitialize for Merge: '<S81>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S22>/Position' */
  /* End of SystemInitialize for SubSystem: '<S18>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S16>/Arm' */
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
