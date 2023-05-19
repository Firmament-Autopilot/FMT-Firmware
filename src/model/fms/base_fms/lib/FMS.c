/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1961
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 19 10:38:30 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S403>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S413>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

/* Named constants for Chart: '<S135>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S50>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S346>/Motion State' */
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
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)1U)
#define FMS_IN_Loiter_p                ((uint8_T)3U)
#define FMS_IN_Lost                    ((uint8_T)2U)
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
  0U,                                  /* reserved */

  {
    0.0F, 0.0F, 0.0F, 0.0F }
  /* home */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_YO5IBtWYxHURAIWIvUaGHE FMS_PARAM = {
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
  0.5F,
  0.3F,
  120U,
  0U
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S3>/Constant1'
                                        *   '<S26>/Constant'
                                        *   '<S453>/Constant'
                                        *   '<S329>/L1'
                                        *   '<S47>/Gain'
                                        *   '<S47>/Gain1'
                                        *   '<S125>/Gain'
                                        *   '<S125>/Gain1'
                                        *   '<S151>/L1'
                                        *   '<S225>/Saturation'
                                        *   '<S226>/Saturation1'
                                        *   '<S226>/Saturation2'
                                        *   '<S226>/Saturation3'
                                        *   '<S370>/Constant'
                                        *   '<S371>/Saturation1'
                                        *   '<S444>/Gain2'
                                        *   '<S444>/Saturation1'
                                        *   '<S49>/Saturation1'
                                        *   '<S60>/Dead Zone'
                                        *   '<S60>/Gain'
                                        *   '<S61>/Dead Zone'
                                        *   '<S61>/Gain'
                                        *   '<S66>/Saturation'
                                        *   '<S82>/Saturation1'
                                        *   '<S97>/Saturation'
                                        *   '<S110>/Saturation1'
                                        *   '<S128>/Dead Zone'
                                        *   '<S128>/Gain'
                                        *   '<S129>/Dead Zone'
                                        *   '<S129>/Gain'
                                        *   '<S134>/Saturation'
                                        *   '<S279>/Gain2'
                                        *   '<S286>/Gain1'
                                        *   '<S286>/Gain2'
                                        *   '<S335>/Saturation1'
                                        *   '<S345>/Saturation'
                                        *   '<S357>/Saturation1'
                                        *   '<S372>/Gain2'
                                        *   '<S394>/vel'
                                        *   '<S394>/Saturation'
                                        *   '<S394>/Switch'
                                        *   '<S52>/Gain2'
                                        *   '<S53>/Gain1'
                                        *   '<S58>/Constant'
                                        *   '<S69>/Gain2'
                                        *   '<S70>/Gain1'
                                        *   '<S77>/Constant'
                                        *   '<S85>/Gain2'
                                        *   '<S86>/Gain1'
                                        *   '<S95>/Constant'
                                        *   '<S100>/Gain2'
                                        *   '<S101>/Gain1'
                                        *   '<S108>/Constant'
                                        *   '<S113>/Gain2'
                                        *   '<S114>/Gain6'
                                        *   '<S122>/Constant'
                                        *   '<S123>/Constant'
                                        *   '<S137>/Gain2'
                                        *   '<S138>/Gain1'
                                        *   '<S145>/Constant'
                                        *   '<S170>/Gain'
                                        *   '<S170>/Saturation1'
                                        *   '<S171>/vel'
                                        *   '<S171>/Saturation'
                                        *   '<S171>/Switch'
                                        *   '<S338>/Gain2'
                                        *   '<S339>/Gain1'
                                        *   '<S348>/Gain2'
                                        *   '<S349>/Gain1'
                                        *   '<S360>/Gain2'
                                        *   '<S361>/Gain6'
                                        *   '<S381>/Gain2'
                                        *   '<S381>/Saturation'
                                        *   '<S382>/Integrator'
                                        *   '<S55>/Constant'
                                        *   '<S57>/Dead Zone'
                                        *   '<S57>/Gain'
                                        *   '<S74>/Dead Zone'
                                        *   '<S74>/Gain'
                                        *   '<S89>/Constant'
                                        *   '<S91>/Dead Zone'
                                        *   '<S91>/Gain'
                                        *   '<S105>/Dead Zone'
                                        *   '<S105>/Gain'
                                        *   '<S118>/Dead Zone'
                                        *   '<S118>/Gain'
                                        *   '<S119>/Dead Zone'
                                        *   '<S119>/Gain'
                                        *   '<S142>/Dead Zone'
                                        *   '<S142>/Gain'
                                        *   '<S157>/Gain2'
                                        *   '<S157>/Saturation'
                                        *   '<S158>/Integrator'
                                        *   '<S341>/Dead Zone'
                                        *   '<S341>/Gain'
                                        *   '<S353>/Dead Zone'
                                        *   '<S353>/Gain'
                                        *   '<S365>/Dead Zone'
                                        *   '<S365>/Gain'
                                        *   '<S366>/Dead Zone'
                                        *   '<S366>/Gain'
                                        *   '<S402>/Saturation1'
                                        *   '<S412>/Saturation1'
                                        *   '<S182>/Saturation1'
                                        *   '<S192>/Saturation1'
                                        *   '<S405>/Gain2'
                                        *   '<S406>/Gain1'
                                        *   '<S415>/Gain2'
                                        *   '<S416>/Gain6'
                                        *   '<S185>/Gain2'
                                        *   '<S186>/Gain1'
                                        *   '<S195>/Gain2'
                                        *   '<S196>/Gain6'
                                        *   '<S408>/Dead Zone'
                                        *   '<S408>/Gain'
                                        *   '<S420>/Dead Zone'
                                        *   '<S420>/Gain'
                                        *   '<S421>/Dead Zone'
                                        *   '<S421>/Gain'
                                        *   '<S188>/Dead Zone'
                                        *   '<S188>/Gain'
                                        *   '<S200>/Dead Zone'
                                        *   '<S200>/Gain'
                                        *   '<S201>/Dead Zone'
                                        *   '<S201>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 48, 46, 52, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S12>/Constant1'
                                        *   '<S451>/Constant'
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
static void FMS_Arm(void);
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode);
static void FMS_Vehicle(void);
static void FMS_c11_FMS(void);
static void FMS_sf_msg_discard_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for action system:
 *    '<S28>/Disarm'
 *    '<S37>/Unknown'
 *    '<S35>/Unknown'
 *    '<S34>/Unknown'
 *    '<S30>/Unknown'
 */
void FMS_Disarm(FMS_Out_Bus *rty_FMS_Out, const ConstB_Disarm_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S32>/Bus Assignment' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant2'
   *  SignalConversion: '<S32>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S32>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S402>/Hold Control'
 *    '<S335>/Hold Control'
 *    '<S182>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S82>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S405>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S402>/Hold Control'
 *    '<S335>/Hold Control'
 *    '<S182>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S82>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S405>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S402>/Hold Control'
 *    '<S335>/Hold Control'
 *    '<S182>/Hold Control'
 *    '<S49>/Hold Control'
 *    '<S82>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S405>/Delay' incorporates:
   *  Gain: '<S407>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S405>/Gain2' incorporates:
   *  Delay: '<S405>/Delay'
   *  Gain: '<S407>/Gain'
   *  Sum: '<S405>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S405>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S402>/Brake Control'
 *    '<S335>/Brake Control'
 *    '<S345>/Brake Control'
 *    '<S182>/Brake Control'
 *    '<S134>/Brake Control'
 *    '<S49>/Brake Control'
 *    '<S66>/Brake Control'
 *    '<S82>/Brake Control'
 *    '<S97>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S404>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S404>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S402>/Move Control'
 *    '<S335>/Move Control'
 *    '<S182>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S409>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S409>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S402>/Move Control'
 *    '<S335>/Move Control'
 *    '<S182>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S409>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S409>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S402>/Move Control'
 *    '<S335>/Move Control'
 *    '<S182>/Move Control'
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

  /* Product: '<S410>/Multiply1' incorporates:
   *  Constant: '<S410>/const1'
   *  DiscreteIntegrator: '<S409>/Integrator'
   */
  rtb_Add3_c = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S408>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = 0.0F;
  } else {
    rtb_a_hr = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S408>/Dead Zone' */

  /* Sum: '<S410>/Add' incorporates:
   *  DiscreteIntegrator: '<S409>/Integrator1'
   *  Gain: '<S406>/Gain1'
   *  Gain: '<S408>/Gain'
   *  Sum: '<S409>/Subtract'
   */
  rtb_Subtract3_dn = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_hr * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_c;

  /* Signum: '<S410>/Sign' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_a_hr = -1.0F;
  } else if (rtb_Subtract3_dn > 0.0F) {
    rtb_a_hr = 1.0F;
  } else {
    rtb_a_hr = rtb_Subtract3_dn;
  }

  /* End of Signum: '<S410>/Sign' */

  /* Sum: '<S410>/Add2' incorporates:
   *  Abs: '<S410>/Abs'
   *  Gain: '<S410>/Gain'
   *  Gain: '<S410>/Gain1'
   *  Product: '<S410>/Multiply2'
   *  Product: '<S410>/Multiply3'
   *  Sqrt: '<S410>/Sqrt'
   *  Sum: '<S410>/Add1'
   *  Sum: '<S410>/Subtract'
   */
  rtb_a_hr = (sqrtf((8.0F * fabsf(rtb_Subtract3_dn) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_hr + rtb_Add3_c;

  /* Sum: '<S410>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_dn - rtb_a_hr) + rtb_Add3_c;

  /* Sum: '<S410>/Add3' */
  rtb_Add3_c = rtb_Subtract3_dn + localC->d;

  /* Sum: '<S410>/Subtract1' */
  rtb_Subtract3_dn -= localC->d;

  /* Signum: '<S410>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S410>/Sign1' */

  /* Signum: '<S410>/Sign2' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S410>/Sign2' */

  /* Sum: '<S410>/Add5' incorporates:
   *  Gain: '<S410>/Gain2'
   *  Product: '<S410>/Multiply4'
   *  Sum: '<S410>/Subtract2'
   */
  rtb_a_hr += (rtb_Add3_c - rtb_Subtract3_dn) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S406>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S409>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S409>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S409>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S410>/Add6' */
  rtb_Add3_c = rtb_a_hr + localC->d;

  /* Sum: '<S410>/Subtract3' */
  rtb_Subtract3_dn = rtb_a_hr - localC->d;

  /* Signum: '<S410>/Sign5' */
  if (rtb_a_hr < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_hr;
  }

  /* End of Signum: '<S410>/Sign5' */

  /* Signum: '<S410>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S410>/Sign3' */

  /* Signum: '<S410>/Sign4' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S410>/Sign4' */

  /* Signum: '<S410>/Sign6' */
  if (rtb_a_hr < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_a_hr;
  }

  /* End of Signum: '<S410>/Sign6' */

  /* Update for DiscreteIntegrator: '<S409>/Integrator' incorporates:
   *  Constant: '<S410>/const'
   *  Gain: '<S410>/Gain3'
   *  Product: '<S410>/Divide'
   *  Product: '<S410>/Multiply5'
   *  Product: '<S410>/Multiply6'
   *  Sum: '<S410>/Subtract4'
   *  Sum: '<S410>/Subtract5'
   *  Sum: '<S410>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_hr / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3_c - rtb_Subtract3_dn) * 0.5F) - rtb_a_b * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S403>/Motion Status'
 *    '<S336>/Motion Status'
 *    '<S183>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S403>/Motion Status'
 *    '<S336>/Motion Status'
 *    '<S183>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S403>/Motion Status'
 *    '<S336>/Motion Status'
 *    '<S183>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S403>/Motion Status' */
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

  /* End of Chart: '<S403>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S412>/Hold Control'
 *    '<S357>/Hold Control'
 *    '<S192>/Hold Control'
 *    '<S110>/Hold Control'
 */
void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S415>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S412>/Hold Control'
 *    '<S357>/Hold Control'
 *    '<S192>/Hold Control'
 *    '<S110>/Hold Control'
 */
void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S415>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S412>/Hold Control'
 *    '<S357>/Hold Control'
 *    '<S192>/Hold Control'
 *    '<S110>/Hold Control'
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

  /* Delay: '<S415>/Delay' incorporates:
   *  SignalConversion: '<S415>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_p;
  }

  /* Trigonometry: '<S419>/Trigonometric Function1' incorporates:
   *  Gain: '<S418>/Gain'
   *  Trigonometry: '<S419>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bl_tmp_0 = arm_cos_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_bl_tmp_0;

  /* Trigonometry: '<S419>/Trigonometric Function' incorporates:
   *  Gain: '<S418>/Gain'
   *  Trigonometry: '<S419>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bl_tmp = arm_sin_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_bl_tmp;

  /* SignalConversion: '<S419>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S419>/Constant3'
   */
  rtb_VectorConcatenate_k[2] = 0.0F;

  /* Gain: '<S419>/Gain' */
  rtb_VectorConcatenate_k[3] = -rtb_VectorConcatenate_bl_tmp;

  /* Trigonometry: '<S419>/Trigonometric Function3' */
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_bl_tmp_0;

  /* SignalConversion: '<S419>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S419>/Constant4'
   */
  rtb_VectorConcatenate_k[5] = 0.0F;

  /* SignalConversion: '<S419>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_k[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_k[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_k[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S415>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S415>/Delay'
   *  SignalConversion: '<S415>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S415>/Sum'
   */
  rtb_VectorConcatenate_bl_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bl_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_p;

  /* Product: '<S415>/Multiply' incorporates:
   *  SignalConversion: '<S415>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bl[i] = rtb_VectorConcatenate_k[i + 3] *
      rtb_VectorConcatenate_bl_tmp + rtb_VectorConcatenate_k[i] *
      rtb_VectorConcatenate_bl_tmp_0;
  }

  /* End of Product: '<S415>/Multiply' */

  /* Gain: '<S415>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[1];

  /* Update for Delay: '<S415>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S412>/Brake Control'
 *    '<S357>/Brake Control'
 *    '<S192>/Brake Control'
 *    '<S110>/Brake Control'
 */
void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S414>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S412>/Move Control'
 *    '<S357>/Move Control'
 *    '<S192>/Move Control'
 *    '<S110>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S422>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S422>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S422>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S422>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S412>/Move Control'
 *    '<S357>/Move Control'
 *    '<S192>/Move Control'
 *    '<S110>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S422>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S422>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S422>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S422>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S412>/Move Control'
 *    '<S357>/Move Control'
 *    '<S192>/Move Control'
 *    '<S110>/Move Control'
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

  /* SignalConversion: '<S416>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S422>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S423>/Multiply1' incorporates:
   *  Constant: '<S423>/const1'
   *  DiscreteIntegrator: '<S422>/Integrator'
   */
  rtb_Add3_e1_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S416>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S422>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S423>/Multiply1' incorporates:
   *  Constant: '<S423>/const1'
   *  DiscreteIntegrator: '<S422>/Integrator'
   */
  rtb_Add3_e1_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S420>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S420>/Dead Zone' */

  /* Sum: '<S423>/Add' incorporates:
   *  DiscreteIntegrator: '<S422>/Integrator1'
   *  Gain: '<S416>/Gain6'
   *  Gain: '<S420>/Gain'
   *  Sum: '<S422>/Subtract'
   */
  rtb_Subtract3_h_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_0;

  /* DeadZone: '<S421>/Dead Zone' */
  if (rtu_FMS_In_g > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_g >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S421>/Dead Zone' */

  /* Sum: '<S423>/Add' incorporates:
   *  DiscreteIntegrator: '<S422>/Integrator1'
   *  Gain: '<S416>/Gain6'
   *  Gain: '<S421>/Gain'
   *  Sum: '<S422>/Subtract'
   */
  rtb_Subtract3_h_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_1;

  /* Signum: '<S423>/Sign' */
  if (rtb_Subtract3_h_idx_0 < 0.0F) {
    rtb_Subtract3_h_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0 > 0.0F) {
    rtb_Subtract3_h_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0_0 = rtb_Subtract3_h_idx_0;
  }

  /* Sum: '<S423>/Add2' incorporates:
   *  Abs: '<S423>/Abs'
   *  Gain: '<S423>/Gain'
   *  Gain: '<S423>/Gain1'
   *  Product: '<S423>/Multiply2'
   *  Product: '<S423>/Multiply3'
   *  Signum: '<S423>/Sign'
   *  Sqrt: '<S423>/Sqrt'
   *  Sum: '<S423>/Add1'
   *  Sum: '<S423>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_h_idx_0_0 +
    rtb_Add3_e1_idx_0;

  /* Sum: '<S423>/Add3' incorporates:
   *  Signum: '<S423>/Sign'
   */
  u = rtb_Subtract3_h_idx_0 + localC->d;

  /* Sum: '<S423>/Subtract1' incorporates:
   *  Signum: '<S423>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_0 - localC->d;

  /* Signum: '<S423>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S423>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S423>/Add5' incorporates:
   *  Gain: '<S423>/Gain2'
   *  Product: '<S423>/Multiply4'
   *  Signum: '<S423>/Sign'
   *  Sum: '<S423>/Add2'
   *  Sum: '<S423>/Add4'
   *  Sum: '<S423>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_0 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_0) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S422>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S422>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S423>/Sign3' incorporates:
   *  Sum: '<S423>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S423>/Sign4' incorporates:
   *  Sum: '<S423>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S423>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S423>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S423>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S423>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S422>/Integrator' incorporates:
   *  Constant: '<S423>/const'
   *  Gain: '<S423>/Gain3'
   *  Product: '<S423>/Divide'
   *  Product: '<S423>/Multiply5'
   *  Product: '<S423>/Multiply6'
   *  Sum: '<S423>/Subtract4'
   *  Sum: '<S423>/Subtract5'
   *  Sum: '<S423>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;

  /* Signum: '<S423>/Sign' */
  if (rtb_Subtract3_h_idx_1 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_1 > 0.0F) {
    rtb_Add3_e1_idx_0 = 1.0F;
  } else {
    rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_1;
  }

  /* Sum: '<S423>/Add2' incorporates:
   *  Abs: '<S423>/Abs'
   *  Gain: '<S423>/Gain'
   *  Gain: '<S423>/Gain1'
   *  Product: '<S423>/Multiply2'
   *  Product: '<S423>/Multiply3'
   *  Signum: '<S423>/Sign'
   *  Sqrt: '<S423>/Sqrt'
   *  Sum: '<S423>/Add1'
   *  Sum: '<S423>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_e1_idx_0 +
    rtb_Add3_e1_idx_1;

  /* Sum: '<S423>/Add3' incorporates:
   *  Signum: '<S423>/Sign'
   */
  u = rtb_Subtract3_h_idx_1 + localC->d;

  /* Sum: '<S423>/Subtract1' incorporates:
   *  Signum: '<S423>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_1 - localC->d;

  /* Signum: '<S423>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S423>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S423>/Add5' incorporates:
   *  Gain: '<S423>/Gain2'
   *  Product: '<S423>/Multiply4'
   *  Signum: '<S423>/Sign'
   *  Sum: '<S423>/Add2'
   *  Sum: '<S423>/Add4'
   *  Sum: '<S423>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_1 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_1) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S422>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S422>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S423>/Sign3' incorporates:
   *  Sum: '<S423>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S423>/Sign4' incorporates:
   *  Sum: '<S423>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S423>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S423>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S423>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S423>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S422>/Integrator' incorporates:
   *  Constant: '<S423>/const'
   *  Gain: '<S423>/Gain3'
   *  Product: '<S423>/Divide'
   *  Product: '<S423>/Multiply5'
   *  Product: '<S423>/Multiply6'
   *  Sum: '<S423>/Subtract4'
   *  Sum: '<S423>/Subtract5'
   *  Sum: '<S423>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S413>/Motion State'
 *    '<S358>/Motion State'
 *    '<S193>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * System reset for atomic system:
 *    '<S413>/Motion State'
 *    '<S358>/Motion State'
 *    '<S193>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * Output and update for atomic system:
 *    '<S413>/Motion State'
 *    '<S358>/Motion State'
 *    '<S193>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S413>/Motion State' */
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

  /* End of Chart: '<S413>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S396>/NearbyRefWP'
 *    '<S173>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S427>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S345>/Hold Control'
 *    '<S134>/Hold Control'
 *    '<S66>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S348>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S345>/Hold Control'
 *    '<S134>/Hold Control'
 *    '<S66>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S348>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S345>/Hold Control'
 *    '<S134>/Hold Control'
 *    '<S66>/Hold Control'
 *    '<S97>/Hold Control'
 */
void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S348>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S348>/Sum' incorporates:
   *  Delay: '<S348>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S351>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S351>/Switch' incorporates:
   *  Constant: '<S351>/Constant'
   *  Constant: '<S352>/Constant'
   *  Product: '<S351>/Multiply'
   *  RelationalOperator: '<S352>/Compare'
   *  Sum: '<S351>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S351>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S351>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S351>/Switch' */

  /* Gain: '<S348>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S348>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S345>/Move Control'
 *    '<S134>/Move Control'
 *    '<S66>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S354>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S354>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S345>/Move Control'
 *    '<S134>/Move Control'
 *    '<S66>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S354>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S354>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S345>/Move Control'
 *    '<S134>/Move Control'
 *    '<S66>/Move Control'
 *    '<S97>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_a;
  real32_T rtb_Subtract3_i;
  real32_T rtb_a_b;
  real32_T rtb_Add4_bf;
  real32_T rtb_a_p;

  /* Product: '<S355>/Multiply1' incorporates:
   *  Constant: '<S355>/const1'
   *  DiscreteIntegrator: '<S354>/Integrator'
   */
  rtb_Add3_a = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S353>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_b = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_b = 0.0F;
  } else {
    rtb_a_b = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S353>/Dead Zone' */

  /* Sum: '<S355>/Add' incorporates:
   *  DiscreteIntegrator: '<S354>/Integrator1'
   *  Gain: '<S349>/Gain1'
   *  Gain: '<S353>/Gain'
   *  Sum: '<S354>/Subtract'
   */
  rtb_Subtract3_i = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_b * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_a;

  /* Signum: '<S355>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_Subtract3_i;
  }

  /* End of Signum: '<S355>/Sign' */

  /* Sum: '<S355>/Add2' incorporates:
   *  Abs: '<S355>/Abs'
   *  Gain: '<S355>/Gain'
   *  Gain: '<S355>/Gain1'
   *  Product: '<S355>/Multiply2'
   *  Product: '<S355>/Multiply3'
   *  Sqrt: '<S355>/Sqrt'
   *  Sum: '<S355>/Add1'
   *  Sum: '<S355>/Subtract'
   */
  rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_b + rtb_Add3_a;

  /* Sum: '<S355>/Add4' */
  rtb_Add4_bf = (rtb_Subtract3_i - rtb_a_b) + rtb_Add3_a;

  /* Sum: '<S355>/Add3' */
  rtb_Add3_a = rtb_Subtract3_i + localC->d;

  /* Sum: '<S355>/Subtract1' */
  rtb_Subtract3_i -= localC->d;

  /* Signum: '<S355>/Sign1' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S355>/Sign1' */

  /* Signum: '<S355>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S355>/Sign2' */

  /* Sum: '<S355>/Add5' incorporates:
   *  Gain: '<S355>/Gain2'
   *  Product: '<S355>/Multiply4'
   *  Sum: '<S355>/Subtract2'
   */
  rtb_a_b += (rtb_Add3_a - rtb_Subtract3_i) * 0.5F * rtb_Add4_bf;

  /* SignalConversion: '<S349>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S354>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S354>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S354>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S355>/Add6' */
  rtb_Add3_a = rtb_a_b + localC->d;

  /* Sum: '<S355>/Subtract3' */
  rtb_Subtract3_i = rtb_a_b - localC->d;

  /* Signum: '<S355>/Sign5' */
  if (rtb_a_b < 0.0F) {
    rtb_Add4_bf = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_Add4_bf = 1.0F;
  } else {
    rtb_Add4_bf = rtb_a_b;
  }

  /* End of Signum: '<S355>/Sign5' */

  /* Signum: '<S355>/Sign3' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S355>/Sign3' */

  /* Signum: '<S355>/Sign4' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S355>/Sign4' */

  /* Signum: '<S355>/Sign6' */
  if (rtb_a_b < 0.0F) {
    rtb_a_p = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_a_p = 1.0F;
  } else {
    rtb_a_p = rtb_a_b;
  }

  /* End of Signum: '<S355>/Sign6' */

  /* Update for DiscreteIntegrator: '<S354>/Integrator' incorporates:
   *  Constant: '<S355>/const'
   *  Gain: '<S355>/Gain3'
   *  Product: '<S355>/Divide'
   *  Product: '<S355>/Multiply5'
   *  Product: '<S355>/Multiply6'
   *  Sum: '<S355>/Subtract4'
   *  Sum: '<S355>/Subtract5'
   *  Sum: '<S355>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_b / localC->d - rtb_Add4_bf) *
    localC->Gain4 * ((rtb_Add3_a - rtb_Subtract3_i) * 0.5F) - rtb_a_p *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S135>/Motion State'
 *    '<S67>/Motion State'
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
 *    '<S135>/Motion State'
 *    '<S67>/Motion State'
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
 *    '<S135>/Motion State'
 *    '<S67>/Motion State'
 *    '<S98>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S135>/Motion State' */
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

  /* End of Chart: '<S135>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S49>/Move Control'
 *    '<S82>/Move Control'
 */
void FMS_MoveControl_l(real32_T rtu_FMS_In, real32_T rtu_FMS_In_l, uint32_T
  rtu_FMS_In_i, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_hp;

  /* DeadZone: '<S57>/Dead Zone' */
  if (rtu_FMS_In_l > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_hp = rtu_FMS_In_l - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In_l >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_hp = 0.0F;
  } else {
    rtb_Gain1_hp = rtu_FMS_In_l - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S57>/Dead Zone' */

  /* Gain: '<S53>/Gain1' incorporates:
   *  Gain: '<S57>/Gain'
   */
  rtb_Gain1_hp = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_hp *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  Gain: '<S53>/Gain'
   *  Logic: '<S53>/Logical Operator'
   *  RelationalOperator: '<S55>/Compare'
   *  RelationalOperator: '<S56>/Compare'
   *  S-Function (sfix_bitop): '<S53>/cmd_p valid'
   */
  if ((rtb_Gain1_hp > 0.0F) && ((rtu_FMS_In_i & 256U) != 0U) && (rtu_FMS_In <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * rtb_Gain1_hp;
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_hp;
  }

  /* End of Switch: '<S53>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S50>/Motion Status'
 *    '<S83>/Motion Status'
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
 *    '<S83>/Motion Status'
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
 *    '<S83>/Motion Status'
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
  real_T rtb_Gain_d;
  real_T rtb_Sum3_l;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S455>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S456>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S456>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S456>/Multiply1' incorporates:
   *  Product: '<S456>/Multiply'
   */
  rtb_Gain_d = localC->ff * rtb_Sum2_ee;

  /* Product: '<S456>/Divide' incorporates:
   *  Constant: '<S456>/Constant'
   *  Constant: '<S456>/R'
   *  Sqrt: '<S456>/Sqrt'
   *  Sum: '<S456>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_d);

  /* Product: '<S456>/Product3' incorporates:
   *  Constant: '<S456>/Constant1'
   *  Product: '<S456>/Multiply1'
   *  Sum: '<S456>/Sum2'
   */
  rtb_Gain_d = 1.0 / (1.0 - rtb_Gain_d) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S456>/Multiply2' incorporates:
   *  Trigonometry: '<S456>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S455>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S460>/Abs' incorporates:
   *  Abs: '<S463>/Abs1'
   *  Switch: '<S460>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S460>/Switch1' incorporates:
   *  Abs: '<S460>/Abs'
   *  Bias: '<S460>/Bias2'
   *  Bias: '<S460>/Bias3'
   *  Constant: '<S457>/Constant'
   *  Constant: '<S457>/Constant1'
   *  Constant: '<S462>/Constant'
   *  Gain: '<S460>/Gain1'
   *  Product: '<S460>/Multiply'
   *  RelationalOperator: '<S462>/Compare'
   *  Switch: '<S457>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S463>/Switch1' incorporates:
     *  Bias: '<S463>/Bias2'
     *  Bias: '<S463>/Bias3'
     *  Constant: '<S463>/Constant'
     *  Constant: '<S464>/Constant'
     *  Math: '<S463>/Math Function'
     *  RelationalOperator: '<S464>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S463>/Switch1' */

    /* Signum: '<S460>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S460>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S457>/Sum' incorporates:
   *  Sum: '<S455>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S455>/Multiply' incorporates:
   *  Gain: '<S455>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_d;

  /* Switch: '<S459>/Switch1' incorporates:
   *  Abs: '<S459>/Abs1'
   *  Bias: '<S459>/Bias2'
   *  Bias: '<S459>/Bias3'
   *  Constant: '<S459>/Constant'
   *  Constant: '<S461>/Constant'
   *  Math: '<S459>/Math Function'
   *  RelationalOperator: '<S461>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S459>/Switch1' */

  /* Product: '<S455>/Multiply' incorporates:
   *  Gain: '<S455>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S455>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S458>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_d = cos(rtb_Sum2_ee);

  /* Sum: '<S458>/Sum2' incorporates:
   *  Product: '<S458>/Multiply1'
   *  Product: '<S458>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_d + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S458>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S458>/Multiply4' */
  rtb_Gain_d *= rtb_Sum_d;

  /* Sum: '<S458>/Sum3' */
  rtb_Sum3_l = rtb_Gain_d - rtb_Sum3_l;

  /* DataTypeConversion: '<S452>/Data Type Conversion' incorporates:
   *  Gain: '<S455>/Gain'
   *  Sum: '<S455>/Sum1'
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

            /* Outputs for Function Call SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
            F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href,
              FMS_B.psio, FMS_B.DataTypeConversion,
              &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

            /* End of Outputs for SubSystem: '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
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
    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
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
  /* RelationalOperator: '<S465>/Compare' incorporates:
   *  Abs: '<S454>/Abs'
   *  Constant: '<S465>/Constant'
   *  MinMax: '<S454>/Max'
   *  Sum: '<S454>/Sum'
   */
  FMS_B.Compare_k = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S5>/Vehicle.StickMoved' */
  if (FMS_B.Compare_k && (FMS_B.target_mode != PilotMode_None)) {
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
          if (FMS_B.Compare && ((FMS_B.BusConversion_InsertedFor_FMSSt.flag &
                                 221U) != 0U)) {
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
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
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
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
            if (FMS_DW.chartAbsoluteTimeCounter -
                FMS_DW.durationLastReferenceTick_2 >= 500) {
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
      /* Reshape: '<S453>/Reshape' incorporates:
       *  Constant: '<S453>/Constant'
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
      FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_DW.home[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
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
      FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_DW.home[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
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
      if (FMS_B.target_mode == PilotMode_Mission) {
        /* Inport: '<Root>/Mission_Data' */
        if ((FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          FMS_DW.prep_mission_takeoff = 1.0;
          FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff ==
            1.0);
          FMS_DW.prep_takeoff = 0.0;
          FMS_DW.condWasTrueAtLastTimeStep_1_b = (FMS_DW.prep_takeoff == 1.0);
          FMS_B.state = VehicleState_Standby;
        } else {
          b_previousEvent = FMS_DW.sfEvent;
          FMS_DW.sfEvent = FMS_event_DisarmEvent;

          /* Chart: '<Root>/FMS State Machine' */
          FMS_c11_FMS();
          FMS_DW.sfEvent = b_previousEvent;
          if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
            FMS_B.state = VehicleState_Standby;
          }
        }

        /* End of Inport: '<Root>/Mission_Data' */
      } else {
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
  real32_T rtb_Saturation1_ln[2];
  real32_T rtb_a_i;
  MotionState rtb_state_a;
  real32_T rtb_Switch_ec[3];
  real32_T rtb_Rem_k;
  real32_T rtb_Switch_k;
  real32_T rtb_Rem_o;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real_T rtb_Switch1_p;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_TmpSignalConversionAtDela_a[2];
  real32_T rtb_VectorConcatenate_bl[9];
  boolean_T rtb_LogicalOperator_e;
  int32_T i;
  real32_T rtb_Transpose_0[3];
  boolean_T tmp[3];
  real32_T tmp_0[3];
  boolean_T tmp_1[3];
  boolean_T tmp_2[3];
  real32_T rtb_MathFunction_iq_idx_0;
  real32_T rtb_MathFunction_h_idx_1;
  real32_T rtb_MathFunction_h_idx_0;
  real32_T rtb_P_d_idx_0;
  real32_T rtb_Divide_l_idx_2;
  real32_T rtb_Divide_l_idx_1;
  real_T rtb_Multiply_l5_idx_0;
  real32_T u1_tmp;
  uint32_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;
  boolean_T guard1 = false;

  /* Sqrt: '<S475>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S475>/Square'
   *  Sum: '<S475>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator_n = sqrtf(((FMS_U.INS_Out.quat[0] *
    FMS_U.INS_Out.quat[0] + FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
    FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] *
    FMS_U.INS_Out.quat[3]);

  /* Product: '<S471>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Rem_k = FMS_U.INS_Out.quat[0] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator_n;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_DiscreteTimeIntegrator_n;
  rtb_DiscreteTimeIntegrator_n = FMS_U.INS_Out.quat[3] /
    rtb_DiscreteTimeIntegrator_n;

  /* Math: '<S472>/Square' incorporates:
   *  Math: '<S473>/Square'
   *  Math: '<S474>/Square'
   */
  rtb_MathFunction_h_idx_0 = rtb_Rem_k * rtb_Rem_k;

  /* Math: '<S472>/Square2' incorporates:
   *  Math: '<S473>/Square2'
   *  Math: '<S474>/Square2'
   */
  rtb_MathFunction_h_idx_1 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S472>/Square1' incorporates:
   *  Math: '<S473>/Square1'
   *  Math: '<S474>/Square1'
   */
  rtb_Switch_k = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S472>/Square3' incorporates:
   *  Math: '<S473>/Square3'
   *  Math: '<S474>/Square3'
   */
  rtb_a_i = rtb_DiscreteTimeIntegrator_n * rtb_DiscreteTimeIntegrator_n;

  /* Sum: '<S472>/Subtract' incorporates:
   *  Math: '<S472>/Square'
   *  Math: '<S472>/Square1'
   *  Math: '<S472>/Square2'
   *  Math: '<S472>/Square3'
   *  Sum: '<S472>/Add'
   *  Sum: '<S472>/Add1'
   */
  rtb_Transpose[0] = (rtb_MathFunction_h_idx_0 + rtb_Switch_k) -
    (rtb_MathFunction_h_idx_1 + rtb_a_i);

  /* Product: '<S472>/Multiply' incorporates:
   *  Product: '<S473>/Multiply'
   */
  rtb_MathFunction_iq_idx_0 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S472>/Multiply1' incorporates:
   *  Product: '<S473>/Multiply1'
   */
  rtb_P_d_idx_0 = rtb_Rem_k * rtb_DiscreteTimeIntegrator_n;

  /* Gain: '<S472>/Gain' incorporates:
   *  Product: '<S472>/Multiply'
   *  Product: '<S472>/Multiply1'
   *  Sum: '<S472>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_MathFunction_iq_idx_0 - rtb_P_d_idx_0) * 2.0F;

  /* Product: '<S472>/Multiply2' incorporates:
   *  Product: '<S474>/Multiply'
   */
  rtb_Rem_o = rtb_Divide_l_idx_1 * rtb_DiscreteTimeIntegrator_n;

  /* Product: '<S472>/Multiply3' incorporates:
   *  Product: '<S474>/Multiply1'
   */
  B = rtb_Rem_k * rtb_Divide_l_idx_2;

  /* Gain: '<S472>/Gain1' incorporates:
   *  Product: '<S472>/Multiply2'
   *  Product: '<S472>/Multiply3'
   *  Sum: '<S472>/Add2'
   */
  rtb_Transpose[2] = (rtb_Rem_o + B) * 2.0F;

  /* Gain: '<S473>/Gain' incorporates:
   *  Sum: '<S473>/Add3'
   */
  rtb_Transpose[3] = (rtb_MathFunction_iq_idx_0 + rtb_P_d_idx_0) * 2.0F;

  /* Sum: '<S473>/Subtract' incorporates:
   *  Sum: '<S473>/Add'
   *  Sum: '<S473>/Add1'
   */
  rtb_Transpose[4] = (rtb_MathFunction_h_idx_0 + rtb_MathFunction_h_idx_1) -
    (rtb_Switch_k + rtb_a_i);

  /* Product: '<S473>/Multiply2' incorporates:
   *  Product: '<S474>/Multiply2'
   */
  rtb_MathFunction_iq_idx_0 = rtb_Divide_l_idx_2 * rtb_DiscreteTimeIntegrator_n;

  /* Product: '<S473>/Multiply3' incorporates:
   *  Product: '<S474>/Multiply3'
   */
  rtb_P_d_idx_0 = rtb_Rem_k * rtb_Divide_l_idx_1;

  /* Gain: '<S473>/Gain1' incorporates:
   *  Product: '<S473>/Multiply2'
   *  Product: '<S473>/Multiply3'
   *  Sum: '<S473>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_MathFunction_iq_idx_0 - rtb_P_d_idx_0) * 2.0F;

  /* Gain: '<S474>/Gain' incorporates:
   *  Sum: '<S474>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Rem_o - B) * 2.0F;

  /* Gain: '<S474>/Gain1' incorporates:
   *  Sum: '<S474>/Add2'
   */
  rtb_Transpose[7] = (rtb_MathFunction_iq_idx_0 + rtb_P_d_idx_0) * 2.0F;

  /* Sum: '<S474>/Subtract' incorporates:
   *  Sum: '<S474>/Add'
   *  Sum: '<S474>/Add1'
   */
  rtb_Transpose[8] = (rtb_MathFunction_h_idx_0 + rtb_a_i) - (rtb_Switch_k +
    rtb_MathFunction_h_idx_1);

  /* Math: '<S6>/Transpose' */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bl[3 * i] = rtb_Transpose[i];
    rtb_VectorConcatenate_bl[1 + 3 * i] = rtb_Transpose[i + 3];
    rtb_VectorConcatenate_bl[2 + 3 * i] = rtb_Transpose[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_Transpose[i] = rtb_VectorConcatenate_bl[i];
  }

  /* End of Math: '<S6>/Transpose' */

  /* Product: '<S6>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S6>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply_o[i] = rtb_Transpose[i + 6] * FMS_U.INS_Out.az +
      (rtb_Transpose[i + 3] * FMS_U.INS_Out.ay + rtb_Transpose[i] *
       FMS_U.INS_Out.ax);
  }

  /* End of Product: '<S6>/Multiply' */

  /* DiscreteIntegrator: '<S466>/Discrete-Time Integrator5' */
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

  /* DiscreteIntegrator: '<S468>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S468>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Product: '<S6>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S6>/Cos'
   *  Trigonometry: '<S6>/Cos1'
   */
  rtb_Divide_l_idx_1 = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32
    (FMS_U.INS_Out.theta);

  /* Saturate: '<S6>/Saturation' */
  if (rtb_Divide_l_idx_1 > 1.0F) {
    rtb_Divide_l_idx_1 = 1.0F;
  } else {
    if (rtb_Divide_l_idx_1 < 0.9F) {
      rtb_Divide_l_idx_1 = 0.9F;
    }
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Product: '<S6>/Divide1' */
  rtb_Divide_l_idx_2 = 1250.0F / rtb_Divide_l_idx_1;

  /* DiscreteIntegrator: '<S467>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_l_idx_2;
  }

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S466>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S467>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S468>/Discrete-Time Integrator5'
   *  Logic: '<S469>/AND'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S469>/Lower Test'
   *  RelationalOperator: '<S469>/Upper Test'
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
        /* Disable for SwitchCase: '<S412>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S402>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S357>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S335>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S345>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S35>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S147>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S192>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S182>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S147>/Mission_SubSystem' */
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
        /* Disable for SwitchCase: '<S134>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S49>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S66>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S82>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S110>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S97>/Switch Case' */
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
     */
    FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Disarm);

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
     *  SignalConversion: '<S33>/TmpHiddenBufferAtBus AssignmentInport1'
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
    FMS_Y.FMS_Out.actuator_cmd[0] = 1150U;
    FMS_Y.FMS_Out.actuator_cmd[1] = 1150U;
    FMS_Y.FMS_Out.actuator_cmd[2] = 1150U;
    FMS_Y.FMS_Out.actuator_cmd[3] = 1150U;
    for (i = 0; i < 12; i++) {
      FMS_Y.FMS_Out.actuator_cmd[i + 4] = 0U;
    }

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
          /* Disable for SwitchCase: '<S412>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S402>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S357>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S335>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S345>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S35>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S147>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S192>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S182>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S147>/Mission_SubSystem' */
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
          /* Disable for SwitchCase: '<S134>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S49>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S66>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S82>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S110>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S97>/Switch Case' */
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
       *  Math: '<S434>/Math Function'
       *  Product: '<S436>/Divide'
       *  Sum: '<S397>/Subtract'
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
          /* Disable for SwitchCase: '<S412>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S402>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S357>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S335>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S345>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Takeoff' incorporates:
           *  ActionPort: '<S330>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Delay: '<S449>/cur_waypoint'
           */
          FMS_DW.icLoad_j1 = 1U;

          /* End of InitializeConditions for SubSystem: '<S37>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Takeoff' incorporates:
         *  ActionPort: '<S330>/Action Port'
         */
        /* Delay: '<S449>/cur_waypoint' incorporates:
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
        /* Product: '<S449>/Divide' incorporates:
         *  Delay: '<S449>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S449>/Sum1'
         *  Sum: '<S449>/Sum2'
         */
        rtb_Divide_l_idx_1 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
          FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Saturate: '<S449>/Saturation' */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Divide_l_idx_1 = 0.0F;
          }
        }

        /* End of Saturate: '<S449>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S450>/Trigonometric Function1' incorporates:
         *  Gain: '<S448>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S450>/Trigonometric Function3'
         */
        rtb_MathFunction_h_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S450>/Trigonometric Function' incorporates:
         *  Gain: '<S448>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S450>/Trigonometric Function2'
         */
        rtb_MathFunction_h_idx_1 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

        /* SignalConversion: '<S450>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S450>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S450>/Gain' */
        rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S450>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

        /* SignalConversion: '<S450>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S450>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S450>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S444>/Saturation1' */
        rtb_Switch_k = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Rem_k = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S444>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S449>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S449>/Multiply'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S444>/Sum'
         *  Sum: '<S449>/Sum3'
         *  Sum: '<S449>/Sum4'
         */
        rtb_DiscreteTimeIntegrator_n = ((FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_l_idx_1 +
          FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_a_i = ((FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.cur_waypoint_DSTATE[1])
                   * rtb_Divide_l_idx_1 + FMS_DW.cur_waypoint_DSTATE[1]) -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S444>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i]
            * rtb_DiscreteTimeIntegrator_n;
        }

        /* Saturate: '<S444>/Saturation1' incorporates:
         *  Gain: '<S444>/Gain2'
         *  Product: '<S444>/Multiply'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_a_i = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S330>/Bus Assignment1'
         *  Constant: '<S330>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S330>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S444>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Switch_k) {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_k;
        } else if (rtb_Divide_l_idx_1 < rtb_Rem_k) {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_a_i > rtb_Switch_k) {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_k;
        } else if (rtb_a_i < rtb_Rem_k) {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_i;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S443>/Switch' incorporates:
         *  Abs: '<S443>/Abs'
         *  Abs: '<S443>/Abs1'
         *  Constant: '<S445>/Constant'
         *  Constant: '<S446>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S443>/Logical Operator'
         *  RelationalOperator: '<S445>/Compare'
         *  RelationalOperator: '<S446>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S443>/Sum'
         *  Sum: '<S443>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Constant: '<S443>/Constant6'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -1.0F;
        } else {
          /* BusAssignment: '<S330>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Constant: '<S443>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -0.5F;
        }

        /* End of Switch: '<S443>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Update for Delay: '<S449>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* End of Outputs for SubSystem: '<S37>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S37>/Land' incorporates:
         *  ActionPort: '<S328>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S375>/Trigonometric Function1' incorporates:
         *  Gain: '<S374>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S375>/Trigonometric Function' incorporates:
         *  Gain: '<S374>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S375>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S375>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S375>/Gain' incorporates:
         *  Gain: '<S374>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Trigonometry: '<S375>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S375>/Trigonometric Function3' incorporates:
         *  Gain: '<S374>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S375>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S375>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S375>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S371>/Saturation1' */
        rtb_Switch_k = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Rem_k = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S372>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S372>/Sum'
         */
        rtb_DiscreteTimeIntegrator_n = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_U.INS_Out.x_R;
        rtb_a_i = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S372>/Multiply' incorporates:
         *  SignalConversion: '<S372>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i]
            * rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Product: '<S372>/Multiply' */

        /* Saturate: '<S371>/Saturation1' incorporates:
         *  Gain: '<S372>/Gain2'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_a_i = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S328>/Bus Assignment1'
         *  Constant: '<S328>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S328>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S328>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S371>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Switch_k) {
          /* BusAssignment: '<S328>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_k;
        } else if (rtb_Divide_l_idx_1 < rtb_Rem_k) {
          /* BusAssignment: '<S328>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S328>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_a_i > rtb_Switch_k) {
          /* BusAssignment: '<S328>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_k;
        } else if (rtb_a_i < rtb_Rem_k) {
          /* BusAssignment: '<S328>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S328>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_i;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S328>/Switch' incorporates:
         *  Constant: '<S370>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S328>/Logical Operator'
         *  RelationalOperator: '<S370>/Compare'
         *  S-Function (sfix_bitop): '<S328>/cmd_p valid'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          /* BusAssignment: '<S328>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Constant: '<S328>/Constant5'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = 0.25F;
        } else {
          /* BusAssignment: '<S328>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Constant: '<S328>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = 0.5F;
        }

        /* End of Switch: '<S328>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S37>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Return' incorporates:
           *  ActionPort: '<S329>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Delay: '<S378>/Delay'
           *  Delay: '<S379>/Delay'
           *  Delay: '<S398>/Delay'
           *  DiscreteIntegrator: '<S382>/Integrator'
           *  DiscreteIntegrator: '<S382>/Integrator1'
           *  DiscreteIntegrator: '<S439>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_o = 1U;
          FMS_DW.l1_heading_p = 0.0F;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Return' */

          /* SystemReset for IfAction SubSystem: '<S37>/Return' incorporates:
           *  ActionPort: '<S329>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S403>/Motion Status'
           *  Chart: '<S413>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S37>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Return' incorporates:
         *  ActionPort: '<S329>/Action Port'
         */
        /* Delay: '<S398>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_o != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S394>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];
        rtb_MathFunction_iq_idx_0 = FMS_U.INS_Out.y_R -
          FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sqrt: '<S399>/Sqrt' incorporates:
         *  Math: '<S399>/Square'
         *  Sum: '<S394>/Sum'
         *  Sum: '<S399>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

        /* Switch: '<S394>/Switch' incorporates:
         *  Constant: '<S394>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S394>/Gain' */
          rtb_Switch_k = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S394>/Saturation' */
          if (rtb_Switch_k > FMS_PARAM.CRUISE_SPEED) {
            rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Switch_k < 0.5F) {
              rtb_Switch_k = 0.5F;
            }
          }

          /* End of Saturate: '<S394>/Saturation' */
        }

        /* End of Switch: '<S394>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S413>/Motion State' incorporates:
         *  Constant: '<S413>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S413>/Square'
         *  Math: '<S413>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S413>/Sqrt'
         *  Sum: '<S413>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S412>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S412>/Hold Control' incorporates:
             *  ActionPort: '<S415>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S412>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S412>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S412>/Hold Control' incorporates:
           *  ActionPort: '<S415>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_mv,
                            &FMS_ConstB.HoldControl_k, &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S412>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S412>/Brake Control' incorporates:
           *  ActionPort: '<S414>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_mv);

          /* End of Outputs for SubSystem: '<S412>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S412>/Move Control' incorporates:
             *  ActionPort: '<S416>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S412>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S412>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S412>/Move Control' incorporates:
           *  ActionPort: '<S416>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_mv,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S412>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S412>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S403>/Motion Status' incorporates:
         *  Abs: '<S403>/Abs'
         *  Constant: '<S403>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S402>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S402>/Hold Control' incorporates:
             *  ActionPort: '<S405>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S402>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S402>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S402>/Hold Control' incorporates:
           *  ActionPort: '<S405>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S402>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S402>/Brake Control' incorporates:
           *  ActionPort: '<S404>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S402>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S402>/Move Control' incorporates:
             *  ActionPort: '<S406>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S402>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S402>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S402>/Move Control' incorporates:
           *  ActionPort: '<S406>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S402>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S402>/Switch Case' */

        /* Delay: '<S378>/Delay' incorporates:
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
        /* Sum: '<S329>/Sum' incorporates:
         *  Delay: '<S378>/Delay'
         *  MATLAB Function: '<S396>/OutRegionRegWP'
         *  MATLAB Function: '<S396>/SearchL1RefWP'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_MathFunction_iq_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S393>/Sum of Elements' incorporates:
         *  Math: '<S393>/Math Function'
         *  Sum: '<S329>/Sum'
         */
        rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0 + rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Math: '<S393>/Math Function1' incorporates:
         *  Sum: '<S393>/Sum of Elements'
         *
         * About '<S393>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_a_i = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_n));
        } else {
          rtb_a_i = sqrtf(rtb_DiscreteTimeIntegrator_n);
        }

        /* End of Math: '<S393>/Math Function1' */

        /* Switch: '<S393>/Switch' incorporates:
         *  Constant: '<S393>/Constant'
         *  Product: '<S393>/Product'
         *  Sum: '<S329>/Sum'
         */
        if (rtb_a_i > 0.0F) {
          rtb_Switch_ec[0] = rtb_MathFunction_iq_idx_0;
          rtb_Switch_ec[1] = rtb_P_d_idx_0;
          rtb_Switch_ec[2] = rtb_a_i;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S393>/Switch' */

        /* Product: '<S393>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S391>/Subtract' incorporates:
         *  Product: '<S391>/Multiply'
         *  Product: '<S391>/Multiply1'
         */
        rtb_a_i = rtb_Saturation1_ln[0] * FMS_ConstB.Divide_d[1] -
          rtb_Saturation1_ln[1] * FMS_ConstB.Divide_d[0];

        /* Signum: '<S380>/Sign1' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S380>/Sign1' */

        /* Switch: '<S380>/Switch2' incorporates:
         *  Constant: '<S380>/Constant4'
         */
        if (rtb_a_i == 0.0F) {
          rtb_a_i = 1.0F;
        }

        /* End of Switch: '<S380>/Switch2' */

        /* DotProduct: '<S380>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide_d[0] * rtb_Saturation1_ln[0] +
          FMS_ConstB.Divide_d[1] * rtb_Saturation1_ln[1];

        /* Trigonometry: '<S380>/Acos' incorporates:
         *  DotProduct: '<S380>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S380>/Multiply' incorporates:
         *  Trigonometry: '<S380>/Acos'
         */
        rtb_a_i *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S384>/Rem' incorporates:
         *  Constant: '<S384>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S379>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_a_i - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S384>/Switch' incorporates:
         *  Abs: '<S384>/Abs'
         *  Constant: '<S384>/Constant'
         *  Constant: '<S390>/Constant'
         *  Product: '<S384>/Multiply'
         *  RelationalOperator: '<S390>/Compare'
         *  Sum: '<S384>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S384>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_DiscreteTimeIntegrator_n = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_DiscreteTimeIntegrator_n = 1.0F;
          } else {
            rtb_DiscreteTimeIntegrator_n = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S384>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Switch: '<S384>/Switch' */

        /* Abs: '<S377>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S377>/Switch' incorporates:
         *  Product: '<S398>/Multiply'
         *  Sum: '<S398>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S412>/Saturation1' */
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

          /* End of Saturate: '<S412>/Saturation1' */

          /* Saturate: '<S402>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S402>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S398>/Sum' incorporates:
           *  Delay: '<S398>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S440>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_ec[0] = rtb_Divide_l_idx_1;
          rtb_Saturation1_ln[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S398>/Sum' incorporates:
           *  Delay: '<S398>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S442>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S442>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S441>/Gain' incorporates:
           *  DiscreteIntegrator: '<S439>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S439>/Add'
           */
          rtb_DiscreteTimeIntegrator_n = -(FMS_U.INS_Out.psi -
            FMS_DW.l1_heading_p);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S442>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S442>/Trigonometric Function1'
           */
          rtb_MathFunction_h_idx_0 = arm_cos_f32(rtb_DiscreteTimeIntegrator_n);
          rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

          /* Trigonometry: '<S442>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S442>/Trigonometric Function'
           */
          rtb_MathFunction_h_idx_1 = arm_sin_f32(rtb_DiscreteTimeIntegrator_n);

          /* Gain: '<S442>/Gain' incorporates:
           *  Trigonometry: '<S442>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

          /* SignalConversion: '<S442>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S442>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S442>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

          /* Trigonometry: '<S442>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

          /* SignalConversion: '<S442>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_k[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_k[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_k[2];

          /* Sum: '<S440>/Sum of Elements' incorporates:
           *  Math: '<S440>/Math Function'
           */
          rtb_DiscreteTimeIntegrator_n = rtb_Switch_ec[0] * rtb_Switch_ec[0] +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

          /* Math: '<S440>/Math Function1' incorporates:
           *  Sum: '<S440>/Sum of Elements'
           *
           * About '<S440>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
            rtb_DiscreteTimeIntegrator_n = -sqrtf(fabsf
              (rtb_DiscreteTimeIntegrator_n));
          } else {
            rtb_DiscreteTimeIntegrator_n = sqrtf(rtb_DiscreteTimeIntegrator_n);
          }

          /* End of Math: '<S440>/Math Function1' */

          /* Switch: '<S440>/Switch' incorporates:
           *  Constant: '<S440>/Constant'
           *  Product: '<S440>/Product'
           */
          if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
            rtb_Rem_k = rtb_Saturation1_ln[0];
          } else {
            rtb_Rem_k = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_DiscreteTimeIntegrator_n = 1.0F;
          }

          /* End of Switch: '<S440>/Switch' */

          /* Product: '<S438>/Multiply2' incorporates:
           *  Product: '<S440>/Divide'
           */
          rtb_Rem_k = rtb_Rem_k / rtb_DiscreteTimeIntegrator_n * rtb_Switch_k;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_DiscreteTimeIntegrator_n
            * rtb_Switch_k;
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[i] * rtb_Rem_k;
          }
        }

        /* End of Switch: '<S377>/Switch' */

        /* Delay: '<S379>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S382>/Integrator1' incorporates:
         *  Delay: '<S379>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S386>/Rem' incorporates:
         *  Constant: '<S386>/Constant1'
         *  DiscreteIntegrator: '<S382>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S381>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S386>/Switch' incorporates:
         *  Abs: '<S386>/Abs'
         *  Constant: '<S386>/Constant'
         *  Constant: '<S387>/Constant'
         *  Product: '<S386>/Multiply'
         *  RelationalOperator: '<S387>/Compare'
         *  Sum: '<S386>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S386>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_k;
          }

          /* End of Signum: '<S386>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S386>/Switch' */

        /* Gain: '<S381>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S381>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S381>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S329>/Bus Assignment1'
         *  Constant: '<S329>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S329>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_ec[0];
        FMS_Y.FMS_Out.v_cmd = rtb_Switch_ec[1];
        FMS_Y.FMS_Out.w_cmd = rtb_Switch_ec[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S433>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S433>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S431>/Sum of Elements'
         */
        rtb_DiscreteTimeIntegrator_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S433>/Math Function1' incorporates:
         *  Sum: '<S433>/Sum of Elements'
         *
         * About '<S433>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_n));
        } else {
          rtb_Rem_k = sqrtf(rtb_DiscreteTimeIntegrator_n);
        }

        /* End of Math: '<S433>/Math Function1' */

        /* Switch: '<S433>/Switch' incorporates:
         *  Constant: '<S433>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S433>/Product'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (rtb_Rem_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_ec[0] = FMS_U.INS_Out.vn;
          rtb_Switch_ec[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_ec[2] = rtb_Rem_k;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S433>/Switch' */

        /* Product: '<S433>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S436>/Sum of Elements' incorporates:
         *  Math: '<S436>/Math Function'
         *  SignalConversion: '<S436>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Saturation1_ln[1] * rtb_Saturation1_ln[1] +
          rtb_Saturation1_ln[0] * rtb_Saturation1_ln[0];

        /* Math: '<S436>/Math Function1' incorporates:
         *  Sum: '<S436>/Sum of Elements'
         *
         * About '<S436>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S436>/Math Function1' */

        /* Switch: '<S436>/Switch' incorporates:
         *  Constant: '<S436>/Constant'
         *  Product: '<S436>/Product'
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

        /* End of Switch: '<S436>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S396>/NearbyRefWP' incorporates:
         *  Constant: '<S329>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Saturation1_ln,
                        &rtb_Rem_o);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* MATLAB Function: '<S396>/SearchL1RefWP' incorporates:
         *  Constant: '<S329>/L1'
         *  Delay: '<S378>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Rem_k = rtb_P_d_idx_0 * rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
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

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
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

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S396>/OutRegionRegWP' incorporates:
         *  Delay: '<S378>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_k = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
                     rtb_MathFunction_iq_idx_0 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE_p[0]) * rtb_P_d_idx_0) / (rtb_P_d_idx_0 *
          rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Rem_k <= 0.0F);
        rtb_LogicalOperator_e = (rtb_Rem_k >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_d_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_e) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          rtb_P_d_idx_0 = rtb_Rem_k * rtb_P_d_idx_0 + FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S396>/Switch1' incorporates:
         *  Constant: '<S426>/Constant'
         *  RelationalOperator: '<S426>/Compare'
         */
        if (rtb_Rem_o <= 0.0F) {
          /* Switch: '<S396>/Switch' incorporates:
           *  Constant: '<S425>/Constant'
           *  MATLAB Function: '<S396>/SearchL1RefWP'
           *  RelationalOperator: '<S425>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;
            rtb_Saturation1_ln[1] = rtb_MathFunction_h_idx_1;
          } else {
            rtb_Saturation1_ln[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S396>/OutRegionRegWP' incorporates:
             *  Delay: '<S378>/Delay'
             *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Saturation1_ln[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_e) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Saturation1_ln[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              rtb_Saturation1_ln[1] = rtb_Rem_k * rtb_MathFunction_iq_idx_0 +
                FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S396>/Switch' */
        }

        /* End of Switch: '<S396>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S397>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S397>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S434>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S434>/Math Function' incorporates:
         *  Math: '<S432>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Sum: '<S434>/Sum of Elements' incorporates:
         *  Math: '<S434>/Math Function'
         */
        rtb_Rem_k = rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S434>/Math Function1' incorporates:
         *  Sum: '<S434>/Sum of Elements'
         *
         * About '<S434>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S434>/Math Function1' */

        /* Switch: '<S434>/Switch' incorporates:
         *  Constant: '<S434>/Constant'
         *  Product: '<S434>/Product'
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

        /* End of Switch: '<S434>/Switch' */

        /* Product: '<S434>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S437>/Sum of Elements' incorporates:
         *  Math: '<S437>/Math Function'
         *  SignalConversion: '<S437>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_k = rtb_P_d_idx_0 * rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;

        /* Math: '<S437>/Math Function1' incorporates:
         *  Sum: '<S437>/Sum of Elements'
         *
         * About '<S437>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S437>/Math Function1' */

        /* Switch: '<S437>/Switch' incorporates:
         *  Constant: '<S437>/Constant'
         *  Product: '<S437>/Product'
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

        /* End of Switch: '<S437>/Switch' */

        /* Product: '<S437>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S432>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Saturation1_ln[0] *
          rtb_Saturation1_ln[0];
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];

        /* Product: '<S437>/Divide' incorporates:
         *  Product: '<S436>/Divide'
         */
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S436>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sqrt: '<S431>/Sqrt' */
        rtb_Rem_k = sqrtf(rtb_DiscreteTimeIntegrator_n);

        /* Gain: '<S397>/Gain' incorporates:
         *  Math: '<S397>/Square'
         */
        rtb_DiscreteTimeIntegrator_n = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S435>/Subtract' incorporates:
         *  Product: '<S435>/Multiply'
         *  Product: '<S435>/Multiply1'
         */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 * rtb_MathFunction_h_idx_0 -
          rtb_P_d_idx_0 * rtb_Saturation1_ln[0];

        /* Signum: '<S430>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S430>/Sign1' */

        /* Switch: '<S430>/Switch2' incorporates:
         *  Constant: '<S430>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S430>/Switch2' */

        /* DotProduct: '<S430>/Dot Product' */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[0] *
          rtb_MathFunction_iq_idx_0 + rtb_MathFunction_h_idx_0 * rtb_P_d_idx_0;

        /* Trigonometry: '<S430>/Acos' incorporates:
         *  DotProduct: '<S430>/Dot Product'
         */
        if (rtb_MathFunction_h_idx_0 > 1.0F) {
          rtb_MathFunction_h_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_h_idx_0 < -1.0F) {
            rtb_MathFunction_h_idx_0 = -1.0F;
          }
        }

        /* Product: '<S430>/Multiply' incorporates:
         *  Trigonometry: '<S430>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_MathFunction_h_idx_0);

        /* Saturate: '<S397>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S397>/Saturation' */

        /* Product: '<S397>/Divide' incorporates:
         *  Constant: '<S329>/L1'
         *  Constant: '<S397>/Constant'
         *  MinMax: '<S397>/Max'
         *  MinMax: '<S397>/Min'
         *  Product: '<S397>/Multiply1'
         *  Sqrt: '<S432>/Sqrt'
         *  Sum: '<S432>/Sum of Elements'
         *  Trigonometry: '<S397>/Sin'
         */
        rtb_DiscreteTimeIntegrator_n = arm_sin_f32(rtb_Rem_k) *
          rtb_DiscreteTimeIntegrator_n / fminf(FMS_PARAM.L1, fmaxf(sqrtf
          (rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0]), 0.5F));

        /* Sum: '<S379>/Sum2' incorporates:
         *  Delay: '<S379>/Delay'
         */
        rtb_a_i -= FMS_DW.Delay_DSTATE_a;

        /* Math: '<S383>/Rem' incorporates:
         *  Constant: '<S383>/Constant1'
         */
        rtb_Rem_o = rt_remf(rtb_a_i, 6.28318548F);

        /* Switch: '<S383>/Switch' incorporates:
         *  Abs: '<S383>/Abs'
         *  Constant: '<S383>/Constant'
         *  Constant: '<S389>/Constant'
         *  Product: '<S383>/Multiply'
         *  RelationalOperator: '<S389>/Compare'
         *  Sum: '<S383>/Add'
         */
        if (fabsf(rtb_Rem_o) > 3.14159274F) {
          /* Signum: '<S383>/Sign' */
          if (rtb_Rem_o < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_o > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_o;
          }

          /* End of Signum: '<S383>/Sign' */
          rtb_Rem_o -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S383>/Switch' */

        /* Sum: '<S379>/Sum' incorporates:
         *  Delay: '<S379>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Rem_o + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S388>/Multiply1' incorporates:
         *  Constant: '<S388>/const1'
         *  DiscreteIntegrator: '<S382>/Integrator'
         */
        rtb_Rem_o = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S388>/Add' incorporates:
         *  DiscreteIntegrator: '<S382>/Integrator1'
         *  Sum: '<S382>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_e - rtb_Divide_l_idx_1) +
          rtb_Rem_o;

        /* Signum: '<S388>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
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
        rtb_a_i = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_l) *
                         FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Rem_o;

        /* Sum: '<S388>/Add4' */
        rtb_MathFunction_iq_idx_0 = (rtb_Rem_k - rtb_a_i) + rtb_Rem_o;

        /* Sum: '<S388>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_l;

        /* Sum: '<S388>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_l;

        /* Signum: '<S388>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S388>/Sign1' */

        /* Signum: '<S388>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S388>/Sign2' */

        /* Sum: '<S388>/Add5' incorporates:
         *  Gain: '<S388>/Gain2'
         *  Product: '<S388>/Multiply4'
         *  Sum: '<S388>/Subtract2'
         */
        rtb_a_i += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F *
          rtb_MathFunction_iq_idx_0;

        /* Update for Delay: '<S398>/Delay' */
        FMS_DW.icLoad_o = 0U;

        /* Update for DiscreteIntegrator: '<S439>/Discrete-Time Integrator' incorporates:
         *  Product: '<S398>/Divide1'
         */
        FMS_DW.l1_heading_p += rtb_DiscreteTimeIntegrator_n / rtb_Switch_k *
          0.004F;

        /* Update for Delay: '<S378>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Update for Delay: '<S379>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S382>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S382>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S388>/Add6' */
        rtb_Divide_l_idx_1 = rtb_a_i + FMS_ConstB.d_l;

        /* Sum: '<S388>/Subtract3' */
        rtb_Rem_k = rtb_a_i - FMS_ConstB.d_l;

        /* Signum: '<S388>/Sign5' */
        if (rtb_a_i < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_a_i;
        }

        /* End of Signum: '<S388>/Sign5' */

        /* Signum: '<S388>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S388>/Sign3' */

        /* Signum: '<S388>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S388>/Sign4' */

        /* Signum: '<S388>/Sign6' */
        if (rtb_a_i < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_a_i;
        }

        /* End of Signum: '<S388>/Sign6' */

        /* Update for DiscreteIntegrator: '<S382>/Integrator' incorporates:
         *  Constant: '<S388>/const'
         *  Gain: '<S388>/Gain3'
         *  Product: '<S388>/Divide'
         *  Product: '<S388>/Multiply5'
         *  Product: '<S388>/Multiply6'
         *  Sum: '<S388>/Subtract4'
         *  Sum: '<S388>/Subtract5'
         *  Sum: '<S388>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_a_i / FMS_ConstB.d_l -
          rtb_DiscreteTimeIntegrator_n) * FMS_ConstB.Gain4_np *
          ((rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F) - rtb_Switch_k * 1.04719758F)
          * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S382>/Integrator' */
        /* End of Outputs for SubSystem: '<S37>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S37>/Hold' incorporates:
           *  ActionPort: '<S327>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S336>/Motion Status'
           *  Chart: '<S346>/Motion State'
           *  Chart: '<S358>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S37>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Hold' incorporates:
         *  ActionPort: '<S327>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S336>/Motion Status' incorporates:
         *  Abs: '<S336>/Abs'
         *  Constant: '<S336>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S346>/Motion State' incorporates:
         *  Abs: '<S346>/Abs'
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

        /* End of Chart: '<S346>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S358>/Motion State' incorporates:
         *  Constant: '<S358>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S358>/Square'
         *  Math: '<S358>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S358>/Sqrt'
         *  Sum: '<S358>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S357>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S357>/Hold Control' incorporates:
             *  ActionPort: '<S360>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S357>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S357>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S357>/Hold Control' incorporates:
           *  ActionPort: '<S360>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S357>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S357>/Brake Control' incorporates:
           *  ActionPort: '<S359>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S357>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S357>/Move Control' incorporates:
             *  ActionPort: '<S361>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S357>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S357>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S357>/Move Control' incorporates:
           *  ActionPort: '<S361>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S357>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S357>/Switch Case' */

        /* SwitchCase: '<S335>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S335>/Hold Control' incorporates:
             *  ActionPort: '<S338>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S335>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S335>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S335>/Hold Control' incorporates:
           *  ActionPort: '<S338>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S335>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S335>/Brake Control' incorporates:
           *  ActionPort: '<S337>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S335>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S335>/Move Control' incorporates:
             *  ActionPort: '<S339>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S335>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S335>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S335>/Move Control' incorporates:
           *  ActionPort: '<S339>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S335>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S335>/Switch Case' */

        /* SwitchCase: '<S345>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S345>/Hold Control' incorporates:
             *  ActionPort: '<S348>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S345>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_kq);

            /* End of SystemReset for SubSystem: '<S345>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S345>/Hold Control' incorporates:
           *  ActionPort: '<S348>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                             &FMS_DW.HoldControl_kq);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S345>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S345>/Brake Control' incorporates:
           *  ActionPort: '<S347>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S345>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S345>/Move Control' incorporates:
             *  ActionPort: '<S349>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S345>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S345>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S345>/Move Control' incorporates:
           *  ActionPort: '<S349>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S345>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S345>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S327>/Bus Assignment'
         *  Constant: '<S327>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S327>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S345>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S345>/Saturation' */

        /* Saturate: '<S357>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S357>/Saturation1' */

        /* Saturate: '<S335>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S327>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S335>/Saturation1' */
        /* End of Outputs for SubSystem: '<S37>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S37>/Unknown' incorporates:
         *  ActionPort: '<S331>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

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
       *  Math: '<S212>/Square'
       *  Math: '<S214>/Math Function'
       *  Sum: '<S174>/Subtract'
       *  Sum: '<S226>/Sum1'
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
        /* Disable for Resettable SubSystem: '<S147>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S192>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S182>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S147>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S35>/Offboard' incorporates:
         *  ActionPort: '<S148>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S305>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S308>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S309>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S309>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S309>/Multiply1' incorporates:
         *  Product: '<S309>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S309>/Divide' incorporates:
         *  Constant: '<S309>/Constant'
         *  Constant: '<S309>/R'
         *  Sqrt: '<S309>/Sqrt'
         *  Sum: '<S309>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S309>/Product3' incorporates:
         *  Constant: '<S309>/Constant1'
         *  Product: '<S309>/Multiply1'
         *  Sum: '<S309>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S309>/Multiply2' incorporates:
         *  Trigonometry: '<S309>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S308>/Sum' incorporates:
         *  Gain: '<S305>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S313>/Abs' incorporates:
         *  Abs: '<S316>/Abs1'
         *  Switch: '<S313>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S313>/Switch1' incorporates:
         *  Abs: '<S313>/Abs'
         *  Bias: '<S313>/Bias2'
         *  Bias: '<S313>/Bias3'
         *  Constant: '<S310>/Constant'
         *  Constant: '<S310>/Constant1'
         *  Constant: '<S315>/Constant'
         *  Gain: '<S313>/Gain1'
         *  Product: '<S313>/Multiply'
         *  RelationalOperator: '<S315>/Compare'
         *  Switch: '<S310>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S316>/Switch1' incorporates:
           *  Bias: '<S316>/Bias2'
           *  Bias: '<S316>/Bias3'
           *  Constant: '<S316>/Constant'
           *  Constant: '<S317>/Constant'
           *  Math: '<S316>/Math Function'
           *  RelationalOperator: '<S317>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S316>/Switch1' */

          /* Signum: '<S313>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S313>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          i = 180;
        } else {
          i = 0;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S310>/Sum' incorporates:
         *  Gain: '<S305>/Gain1'
         *  Gain: '<S305>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S308>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)i;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S308>/Multiply' incorporates:
         *  Gain: '<S308>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S312>/Switch1' incorporates:
         *  Abs: '<S312>/Abs1'
         *  Bias: '<S312>/Bias2'
         *  Bias: '<S312>/Bias3'
         *  Constant: '<S312>/Constant'
         *  Constant: '<S314>/Constant'
         *  Math: '<S312>/Math Function'
         *  RelationalOperator: '<S314>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S312>/Switch1' */

        /* Product: '<S308>/Multiply' incorporates:
         *  Gain: '<S308>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S286>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S290>/Multiply1'
         *  Product: '<S291>/Multiply3'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S299>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S299>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S299>/Trigonometric Function3' incorporates:
           *  Gain: '<S298>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S299>/Gain' incorporates:
           *  Gain: '<S298>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S299>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S299>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S299>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S299>/Trigonometric Function' incorporates:
           *  Gain: '<S298>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S299>/Trigonometric Function1' incorporates:
           *  Gain: '<S298>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S299>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S290>/Saturation' incorporates:
           *  Constant: '<S296>/Constant'
           *  Constant: '<S297>/Constant'
           *  Constant: '<S307>/Constant'
           *  DataTypeConversion: '<S305>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S289>/Logical Operator'
           *  Product: '<S290>/Multiply'
           *  Product: '<S311>/Multiply1'
           *  Product: '<S311>/Multiply2'
           *  RelationalOperator: '<S296>/Compare'
           *  RelationalOperator: '<S297>/Compare'
           *  RelationalOperator: '<S307>/Compare'
           *  S-Function (sfix_bitop): '<S289>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S289>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S304>/lat_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S290>/Sum1'
           *  Sum: '<S311>/Sum2'
           *  Switch: '<S292>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_DiscreteTimeIntegrator_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_DiscreteTimeIntegrator_n = FMS_U.Auto_Cmd.x_cmd;
          }

          rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ?
            rtb_DiscreteTimeIntegrator_n - FMS_U.INS_Out.x_R : 0.0F;
          if (rtb_Divide_l_idx_1 > 4.0F) {
            rtb_Divide_l_idx_1 = 4.0F;
          } else {
            if (rtb_Divide_l_idx_1 < -4.0F) {
              rtb_Divide_l_idx_1 = -4.0F;
            }
          }

          /* SignalConversion: '<S299>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S290>/Saturation' incorporates:
           *  Constant: '<S296>/Constant'
           *  Constant: '<S297>/Constant'
           *  Constant: '<S307>/Constant'
           *  DataTypeConversion: '<S305>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S289>/Logical Operator'
           *  Product: '<S290>/Multiply'
           *  Product: '<S311>/Multiply3'
           *  Product: '<S311>/Multiply4'
           *  RelationalOperator: '<S296>/Compare'
           *  RelationalOperator: '<S297>/Compare'
           *  RelationalOperator: '<S307>/Compare'
           *  S-Function (sfix_bitop): '<S289>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S289>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S304>/lon_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S290>/Sum1'
           *  Sum: '<S311>/Sum3'
           *  Switch: '<S292>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_DiscreteTimeIntegrator_n = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o1);
          } else {
            rtb_DiscreteTimeIntegrator_n = FMS_U.Auto_Cmd.y_cmd;
          }

          rtb_a_i = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ?
            rtb_DiscreteTimeIntegrator_n - FMS_U.INS_Out.y_R : 0.0F;
          if (rtb_a_i > 4.0F) {
            rtb_a_i = 4.0F;
          } else {
            if (rtb_a_i < -4.0F) {
              rtb_a_i = -4.0F;
            }
          }

          /* SignalConversion: '<S299>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S290>/Saturation' incorporates:
           *  Constant: '<S296>/Constant'
           *  Constant: '<S297>/Constant'
           *  Constant: '<S307>/Constant'
           *  DataTypeConversion: '<S305>/Data Type Conversion'
           *  DataTypeConversion: '<S305>/Data Type Conversion1'
           *  Gain: '<S293>/Gain'
           *  Gain: '<S305>/Gain2'
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S289>/Logical Operator'
           *  Product: '<S290>/Multiply'
           *  RelationalOperator: '<S296>/Compare'
           *  RelationalOperator: '<S297>/Compare'
           *  RelationalOperator: '<S307>/Compare'
           *  S-Function (sfix_bitop): '<S289>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S289>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S304>/alt_cmd valid'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S290>/Sum1'
           *  Sum: '<S308>/Sum1'
           *  Switch: '<S292>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_DiscreteTimeIntegrator_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_DiscreteTimeIntegrator_n = FMS_U.Auto_Cmd.z_cmd;
          }

          rtb_DiscreteTimeIntegrator_n = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U)
            || ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ?
            rtb_DiscreteTimeIntegrator_n - (-FMS_U.INS_Out.h_R) : 0.0F;
          if (rtb_DiscreteTimeIntegrator_n > 2.0F) {
            rtb_DiscreteTimeIntegrator_n = 2.0F;
          } else {
            if (rtb_DiscreteTimeIntegrator_n < -2.0F) {
              rtb_DiscreteTimeIntegrator_n = -2.0F;
            }
          }

          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] *
              rtb_DiscreteTimeIntegrator_n + (rtb_Transpose[i + 3] * rtb_a_i +
              rtb_Transpose[i] * rtb_Divide_l_idx_1);
          }

          /* SignalConversion: '<S233>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S233>/Constant4'
           *  MultiPortSwitch: '<S223>/Index Vector'
           *  Product: '<S290>/Multiply1'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S233>/Trigonometric Function3' incorporates:
           *  Gain: '<S232>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S223>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S233>/Gain' incorporates:
           *  Gain: '<S232>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S223>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S233>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S233>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S233>/Constant3'
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S233>/Trigonometric Function' incorporates:
           *  Gain: '<S232>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S223>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S233>/Trigonometric Function1' incorporates:
           *  Gain: '<S232>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S223>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S233>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S223>/Multiply' incorporates:
           *  Constant: '<S231>/Constant'
           *  RelationalOperator: '<S231>/Compare'
           *  S-Function (sfix_bitop): '<S228>/ax_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U
            ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S233>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S223>/Multiply' incorporates:
           *  Constant: '<S231>/Constant'
           *  RelationalOperator: '<S231>/Compare'
           *  S-Function (sfix_bitop): '<S228>/ay_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S233>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S223>/Multiply' incorporates:
           *  Constant: '<S231>/Constant'
           *  RelationalOperator: '<S231>/Compare'
           *  S-Function (sfix_bitop): '<S228>/az_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S223>/Index Vector' incorporates:
           *  Product: '<S229>/Multiply'
           */
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_DiscreteTimeIntegrator_n);
          }
          break;

         case 1:
          /* SignalConversion: '<S303>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S303>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S301>/Gain' incorporates:
           *  Gain: '<S234>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S223>/Index Vector'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S291>/Subtract'
           */
          rtb_Switch_k = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S303>/Trigonometric Function3' incorporates:
           *  Gain: '<S301>/Gain'
           *  Trigonometry: '<S303>/Trigonometric Function1'
           */
          rtb_MathFunction_h_idx_0 = arm_cos_f32(rtb_Switch_k);
          rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

          /* Trigonometry: '<S303>/Trigonometric Function2' incorporates:
           *  Gain: '<S301>/Gain'
           *  Trigonometry: '<S303>/Trigonometric Function'
           */
          rtb_MathFunction_h_idx_1 = arm_sin_f32(rtb_Switch_k);

          /* Gain: '<S303>/Gain' incorporates:
           *  Trigonometry: '<S303>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

          /* SignalConversion: '<S303>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S303>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S303>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

          /* Trigonometry: '<S303>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

          /* SignalConversion: '<S303>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S302>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S303>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S302>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S303>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S302>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S302>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S302>/Constant4'
           */
          rtb_VectorConcatenate_bl[5] = 0.0F;

          /* Trigonometry: '<S302>/Trigonometric Function3' incorporates:
           *  Gain: '<S300>/Gain'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S302>/Trigonometric Function1'
           */
          rtb_Divide_l_idx_1 = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
          rtb_VectorConcatenate_bl[4] = rtb_Divide_l_idx_1;

          /* Trigonometry: '<S302>/Trigonometric Function2' incorporates:
           *  Gain: '<S300>/Gain'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S302>/Trigonometric Function'
           */
          rtb_DiscreteTimeIntegrator_n = arm_sin_f32
            (-FMS_B.Cmd_In.offboard_psi_0);

          /* Gain: '<S302>/Gain' incorporates:
           *  Trigonometry: '<S302>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_bl[3] = -rtb_DiscreteTimeIntegrator_n;

          /* SignalConversion: '<S302>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S302>/Constant3'
           */
          rtb_VectorConcatenate_bl[2] = 0.0F;

          /* Trigonometry: '<S302>/Trigonometric Function' */
          rtb_VectorConcatenate_bl[1] = rtb_DiscreteTimeIntegrator_n;

          /* Trigonometry: '<S302>/Trigonometric Function1' */
          rtb_VectorConcatenate_bl[0] = rtb_Divide_l_idx_1;

          /* RelationalOperator: '<S307>/Compare' incorporates:
           *  Constant: '<S307>/Constant'
           *  S-Function (sfix_bitop): '<S304>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S304>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S304>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S305>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S305>/Data Type Conversion'
           *  Gain: '<S305>/Gain2'
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S311>/Multiply1'
           *  Product: '<S311>/Multiply2'
           *  Product: '<S311>/Multiply3'
           *  Product: '<S311>/Multiply4'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S308>/Sum1'
           *  Sum: '<S311>/Sum2'
           *  Sum: '<S311>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S292>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S296>/Compare' incorporates:
           *  Constant: '<S296>/Constant'
           *  S-Function (sfix_bitop): '<S289>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S289>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S289>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S297>/Compare' incorporates:
           *  Constant: '<S297>/Constant'
           *  S-Function (sfix_bitop): '<S289>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S289>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S289>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (i = 0; i < 3; i++) {
            /* Sum: '<S291>/Sum2' incorporates:
             *  Product: '<S291>/Multiply2'
             *  Switch: '<S292>/Switch'
             */
            if (tmp[i]) {
              rtb_DiscreteTimeIntegrator_n = rtb_Transpose_0[i];
            } else {
              rtb_DiscreteTimeIntegrator_n = tmp_0[i];
            }

            /* Saturate: '<S291>/Saturation1' incorporates:
             *  Gain: '<S293>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S289>/Logical Operator'
             *  Product: '<S291>/Multiply'
             *  Product: '<S291>/Multiply2'
             *  SignalConversion: '<S29>/Signal Copy1'
             *  Sum: '<S291>/Sum2'
             */
            rtb_Divide_l_idx_1 = tmp_1[i] || tmp_2[i] ?
              rtb_DiscreteTimeIntegrator_n - ((rtb_VectorConcatenate_bl[i + 3] *
              FMS_U.INS_Out.y_R + rtb_VectorConcatenate_bl[i] *
              FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_bl[i + 6] *
              -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Divide_l_idx_1 > FMS_ConstP.pooled20[i]) {
              rtb_Switch_ec[i] = FMS_ConstP.pooled20[i];
            } else if (rtb_Divide_l_idx_1 < FMS_ConstP.pooled21[i]) {
              rtb_Switch_ec[i] = FMS_ConstP.pooled21[i];
            } else {
              rtb_Switch_ec[i] = rtb_Divide_l_idx_1;
            }

            /* End of Saturate: '<S291>/Saturation1' */
          }

          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Switch_ec[2]
              + (rtb_Transpose[i + 3] * rtb_Switch_ec[1] + rtb_Transpose[i] *
                 rtb_Switch_ec[0]);
          }

          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S235>/Constant4'
           *  MultiPortSwitch: '<S223>/Index Vector'
           *  Product: '<S291>/Multiply3'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S235>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Switch_k);

          /* Gain: '<S235>/Gain' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           *  Trigonometry: '<S235>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Switch_k);

          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S235>/Constant3'
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S235>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Switch_k);

          /* Trigonometry: '<S235>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Switch_k);

          /* SignalConversion: '<S235>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S223>/Multiply' incorporates:
           *  Constant: '<S231>/Constant'
           *  RelationalOperator: '<S231>/Compare'
           *  S-Function (sfix_bitop): '<S228>/ax_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U
            ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S235>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S223>/Multiply' incorporates:
           *  Constant: '<S231>/Constant'
           *  RelationalOperator: '<S231>/Compare'
           *  S-Function (sfix_bitop): '<S228>/ay_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S235>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S223>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S223>/Multiply' incorporates:
           *  Constant: '<S231>/Constant'
           *  RelationalOperator: '<S231>/Compare'
           *  S-Function (sfix_bitop): '<S228>/az_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S223>/Index Vector' incorporates:
           *  Product: '<S230>/Multiply3'
           */
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_DiscreteTimeIntegrator_n);
          }
          break;

         default:
          /* SignalConversion: '<S295>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S295>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S295>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S295>/Trigonometric Function3' incorporates:
           *  Gain: '<S294>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S295>/Gain' incorporates:
           *  Gain: '<S294>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S295>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S295>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S295>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S295>/Trigonometric Function' incorporates:
           *  Gain: '<S294>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S295>/Trigonometric Function1' incorporates:
           *  Gain: '<S294>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S304>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S289>/lat_cmd valid'
           */
          tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S307>/Compare' incorporates:
           *  Constant: '<S307>/Constant'
           *  S-Function (sfix_bitop): '<S304>/lat_cmd valid'
           */
          tmp[0] = (tmp_3 > 0U);

          /* S-Function (sfix_bitop): '<S304>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S289>/lon_cmd valid'
           */
          tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S307>/Compare' incorporates:
           *  Constant: '<S307>/Constant'
           *  S-Function (sfix_bitop): '<S304>/lon_cmd valid'
           */
          tmp[1] = (tmp_4 > 0U);

          /* S-Function (sfix_bitop): '<S304>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S289>/alt_cmd valid'
           */
          tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S307>/Compare' incorporates:
           *  Constant: '<S307>/Constant'
           *  S-Function (sfix_bitop): '<S304>/alt_cmd valid'
           */
          tmp[2] = (tmp_5 > 0U);

          /* DataTypeConversion: '<S305>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S305>/Data Type Conversion'
           *  Gain: '<S305>/Gain2'
           *  Gain: '<S308>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S311>/Multiply1'
           *  Product: '<S311>/Multiply2'
           *  Product: '<S311>/Multiply3'
           *  Product: '<S311>/Multiply4'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S308>/Sum1'
           *  Sum: '<S311>/Sum2'
           *  Sum: '<S311>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S292>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S296>/Compare' incorporates:
           *  Constant: '<S296>/Constant'
           *  S-Function (sfix_bitop): '<S289>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S289>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S289>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S297>/Compare' incorporates:
           *  Constant: '<S297>/Constant'
           */
          tmp_2[0] = (tmp_3 > 0U);
          tmp_2[1] = (tmp_4 > 0U);
          tmp_2[2] = (tmp_5 > 0U);

          /* Sum: '<S288>/Sum2' */
          for (i = 0; i < 3; i++) {
            /* Switch: '<S292>/Switch' incorporates:
             *  Product: '<S288>/Multiply2'
             */
            if (tmp[i]) {
              rtb_DiscreteTimeIntegrator_n = rtb_Transpose_0[i];
            } else {
              rtb_DiscreteTimeIntegrator_n = tmp_0[i];
            }

            /* Saturate: '<S288>/Saturation1' incorporates:
             *  Gain: '<S293>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S289>/Logical Operator'
             *  Product: '<S288>/Multiply'
             *  Product: '<S288>/Multiply2'
             *  SignalConversion: '<S29>/Signal Copy1'
             */
            rtb_Divide_l_idx_1 = tmp_1[i] || tmp_2[i] ?
              rtb_DiscreteTimeIntegrator_n - ((rtb_Transpose[i + 3] *
              FMS_U.INS_Out.y_R + rtb_Transpose[i] * FMS_U.INS_Out.x_R) +
              rtb_Transpose[i + 6] * -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Divide_l_idx_1 > FMS_ConstP.pooled20[i]) {
              rtb_MatrixConcatenate3[i] = FMS_ConstP.pooled20[i];
            } else if (rtb_Divide_l_idx_1 < FMS_ConstP.pooled21[i]) {
              rtb_MatrixConcatenate3[i] = FMS_ConstP.pooled21[i];
            } else {
              rtb_MatrixConcatenate3[i] = rtb_Divide_l_idx_1;
            }

            /* End of Saturate: '<S288>/Saturation1' */
          }

          /* End of Sum: '<S288>/Sum2' */

          /* MultiPortSwitch: '<S223>/Index Vector' incorporates:
           *  Constant: '<S231>/Constant'
           *  Product: '<S223>/Multiply'
           *  RelationalOperator: '<S231>/Compare'
           *  S-Function (sfix_bitop): '<S228>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S228>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S228>/az_cmd valid'
           */
          rtb_Switch_ec[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Switch_ec[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Switch_ec[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S286>/Index Vector' */

        /* Sum: '<S282>/Sum1' incorporates:
         *  Constant: '<S282>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S282>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_Switch_k = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S283>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Switch_k);

        /* Switch: '<S283>/Switch' incorporates:
         *  Constant: '<S283>/Constant'
         *  Constant: '<S284>/Constant'
         *  Product: '<S283>/Multiply'
         *  RelationalOperator: '<S284>/Compare'
         *  Sum: '<S283>/Subtract'
         */
        if (rtb_Divide_l_idx_1 > 3.14159274F) {
          /* Signum: '<S283>/Sign' */
          if (rtb_Switch_k < 0.0F) {
            rtb_Switch_k = -1.0F;
          } else {
            if (rtb_Switch_k > 0.0F) {
              rtb_Switch_k = 1.0F;
            }
          }

          /* End of Signum: '<S283>/Sign' */
          rtb_Switch_k *= rtb_Divide_l_idx_1 - 6.28318548F;
        }

        /* End of Switch: '<S283>/Switch' */

        /* Saturate: '<S282>/Saturation' */
        if (rtb_Switch_k > 0.314159274F) {
          rtb_Switch_k = 0.314159274F;
        } else {
          if (rtb_Switch_k < -0.314159274F) {
            rtb_Switch_k = -0.314159274F;
          }
        }

        /* End of Saturate: '<S282>/Saturation' */

        /* Gain: '<S279>/Gain2' */
        rtb_Switch_k *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S225>/Sum' incorporates:
         *  Constant: '<S281>/Constant'
         *  Constant: '<S285>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S279>/Multiply2'
         *  Product: '<S280>/Multiply1'
         *  RelationalOperator: '<S281>/Compare'
         *  RelationalOperator: '<S285>/Compare'
         *  S-Function (sfix_bitop): '<S279>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S280>/psi_rate_cmd valid'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                              rtb_Switch_k : 0.0F) + ((FMS_U.Auto_Cmd.cmd_mask &
          64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S286>/Gain1' */
        rtb_Saturation1_ln[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_Saturation1_ln[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S286>/Gain2' */
        rtb_Switch_k = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S287>/Index Vector' incorporates:
         *  Constant: '<S322>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S287>/Multiply'
         *  Product: '<S320>/Multiply'
         *  Product: '<S321>/Multiply3'
         *  RelationalOperator: '<S322>/Compare'
         *  S-Function (sfix_bitop): '<S319>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S319>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S319>/w_cmd valid'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S324>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S324>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S324>/Trigonometric Function3' incorporates:
           *  Gain: '<S323>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S324>/Gain' incorporates:
           *  Gain: '<S323>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Trigonometry: '<S324>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S324>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S324>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S324>/Trigonometric Function' incorporates:
           *  Gain: '<S323>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S324>/Trigonometric Function1' incorporates:
           *  Gain: '<S323>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S324>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S322>/Constant'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/u_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S324>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S322>/Constant'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/v_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S324>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S322>/Constant'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/w_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_DiscreteTimeIntegrator_n);
          }
          break;

         case 1:
          /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S326>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S325>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S321>/Subtract'
           */
          rtb_DiscreteTimeIntegrator_n = -(FMS_U.INS_Out.psi -
            FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S326>/Trigonometric Function3' incorporates:
           *  Gain: '<S325>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_DiscreteTimeIntegrator_n);

          /* Gain: '<S326>/Gain' incorporates:
           *  Gain: '<S325>/Gain'
           *  Trigonometry: '<S326>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_DiscreteTimeIntegrator_n);

          /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S326>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S326>/Trigonometric Function' incorporates:
           *  Gain: '<S325>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_DiscreteTimeIntegrator_n);

          /* Trigonometry: '<S326>/Trigonometric Function1' incorporates:
           *  Gain: '<S325>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_DiscreteTimeIntegrator_n);

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S322>/Constant'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/u_cmd valid'
           */
          rtb_DiscreteTimeIntegrator_n = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S322>/Constant'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/v_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S322>/Constant'
           *  RelationalOperator: '<S322>/Compare'
           *  S-Function (sfix_bitop): '<S319>/w_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_DiscreteTimeIntegrator_n);
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

        /* End of MultiPortSwitch: '<S287>/Index Vector' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Saturation1_ln[0];
        rtb_MatrixConcatenate3[1] += rtb_Saturation1_ln[1];

        /* Sum: '<S226>/Sum1' */
        rtb_DiscreteTimeIntegrator_n = rtb_Switch_k + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S243>/Switch' incorporates:
         *  Constant: '<S258>/Constant'
         *  Constant: '<S259>/Constant'
         *  Constant: '<S260>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S258>/Compare'
         *  RelationalOperator: '<S259>/Compare'
         *  RelationalOperator: '<S260>/Compare'
         *  S-Function (sfix_bitop): '<S243>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S243>/y_v_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S243>/Logical Operator' incorporates:
           *  Constant: '<S259>/Constant'
           *  Constant: '<S260>/Constant'
           *  RelationalOperator: '<S259>/Compare'
           *  RelationalOperator: '<S260>/Compare'
           *  S-Function (sfix_bitop): '<S243>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S243>/y_v_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) >
            0U);
        }

        /* End of Switch: '<S243>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S224>/u_cmd_valid' */
        /* MATLAB Function: '<S255>/bit_shift' incorporates:
         *  DataTypeConversion: '<S224>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_e << 6);

        /* End of Outputs for SubSystem: '<S224>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S224>/v_cmd_valid' */
        /* MATLAB Function: '<S256>/bit_shift' incorporates:
         *  DataTypeConversion: '<S224>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S224>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S244>/Switch' incorporates:
         *  Constant: '<S262>/Constant'
         *  Constant: '<S263>/Constant'
         *  Constant: '<S265>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S262>/Compare'
         *  RelationalOperator: '<S263>/Compare'
         *  RelationalOperator: '<S265>/Compare'
         *  S-Function (sfix_bitop): '<S244>/ax_cmd'
         *  S-Function (sfix_bitop): '<S244>/ay_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S244>/Logical Operator' incorporates:
           *  Constant: '<S263>/Constant'
           *  Constant: '<S265>/Constant'
           *  RelationalOperator: '<S263>/Compare'
           *  RelationalOperator: '<S265>/Compare'
           *  S-Function (sfix_bitop): '<S244>/ax_cmd'
           *  S-Function (sfix_bitop): '<S244>/ay_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S244>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S148>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S148>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S148>/Bus Assignment' incorporates:
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
        FMS_Y.FMS_Out.ax_cmd = rtb_Switch_ec[0];
        FMS_Y.FMS_Out.ay_cmd = rtb_Switch_ec[1];
        FMS_Y.FMS_Out.az_cmd = rtb_Switch_ec[2];

        /* Saturate: '<S225>/Saturation' */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Divide_l_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_l_idx_1;
        }

        /* End of Saturate: '<S225>/Saturation' */

        /* Saturate: '<S226>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S226>/Saturation2' */

        /* Saturate: '<S226>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S226>/Saturation1' */

        /* Saturate: '<S226>/Saturation3' */
        if (rtb_DiscreteTimeIntegrator_n > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_DiscreteTimeIntegrator_n < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S148>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Saturate: '<S226>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S224>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S224>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S224>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S224>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S224>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S224>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S224>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S224>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S224>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S224>/throttle_cmd_valid' */
        /* BusAssignment: '<S148>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S236>/Constant'
         *  Constant: '<S237>/Constant'
         *  Constant: '<S238>/Constant'
         *  Constant: '<S239>/Constant'
         *  Constant: '<S240>/Constant'
         *  Constant: '<S241>/Constant'
         *  Constant: '<S242>/Constant'
         *  Constant: '<S261>/Constant'
         *  Constant: '<S264>/Constant'
         *  DataTypeConversion: '<S224>/Data Type Conversion10'
         *  DataTypeConversion: '<S224>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S245>/bit_shift'
         *  MATLAB Function: '<S246>/bit_shift'
         *  MATLAB Function: '<S247>/bit_shift'
         *  MATLAB Function: '<S249>/bit_shift'
         *  MATLAB Function: '<S250>/bit_shift'
         *  MATLAB Function: '<S251>/bit_shift'
         *  MATLAB Function: '<S252>/bit_shift'
         *  MATLAB Function: '<S253>/bit_shift'
         *  MATLAB Function: '<S254>/bit_shift'
         *  MATLAB Function: '<S257>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S236>/Compare'
         *  RelationalOperator: '<S237>/Compare'
         *  RelationalOperator: '<S238>/Compare'
         *  RelationalOperator: '<S239>/Compare'
         *  RelationalOperator: '<S240>/Compare'
         *  RelationalOperator: '<S241>/Compare'
         *  RelationalOperator: '<S242>/Compare'
         *  RelationalOperator: '<S261>/Compare'
         *  RelationalOperator: '<S264>/Compare'
         *  S-Function (sfix_bitop): '<S224>/p_cmd'
         *  S-Function (sfix_bitop): '<S224>/phi_cmd'
         *  S-Function (sfix_bitop): '<S224>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S224>/q_cmd'
         *  S-Function (sfix_bitop): '<S224>/r_cmd'
         *  S-Function (sfix_bitop): '<S224>/theta_cmd'
         *  S-Function (sfix_bitop): '<S224>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S243>/z_w_cmd'
         *  S-Function (sfix_bitop): '<S244>/az_cmd'
         *  SignalConversion: '<S29>/Signal Copy'
         *  Sum: '<S224>/Add'
         */
        FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
          ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
           ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
          (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) + rtb_y_md) + rtb_y_c1)
          + (((FMS_U.Auto_Cmd.cmd_mask & 33280U) > 0U) << 8)) +
          (rtb_LogicalOperator_e << 9)) + (rtb_FixPtRelationalOperator_me << 10))
          + (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
          (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

        /* End of Outputs for SubSystem: '<S224>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S224>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S224>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S224>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S224>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S224>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S224>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S224>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S224>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S224>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S35>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S35>/Mission' incorporates:
           *  ActionPort: '<S147>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S35>/Switch Case' incorporates:
           *  UnitDelay: '<S150>/Delay Input1'
           *
           * Block description for '<S150>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S35>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S35>/Mission' incorporates:
           *  ActionPort: '<S147>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S147>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S35>/Switch Case' incorporates:
           *  Chart: '<S183>/Motion Status'
           *  Chart: '<S193>/Motion State'
           *  Delay: '<S155>/Delay'
           *  Delay: '<S175>/Delay'
           *  DiscreteIntegrator: '<S158>/Integrator'
           *  DiscreteIntegrator: '<S158>/Integrator1'
           *  DiscreteIntegrator: '<S219>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_i = 0.0F;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S147>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S35>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S35>/Mission' incorporates:
         *  ActionPort: '<S147>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* RelationalOperator: '<S150>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S150>/Delay Input1'
         *
         * Block description for '<S150>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S147>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S151>/Reset'
         */
        if (rtb_FixPtRelationalOperator_me &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S192>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S182>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S175>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S219>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S155>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S193>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S183>/Motion Status' */
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
        /* Sum: '<S171>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_iq_idx_0 = FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.sp_waypoint[0];
        rtb_Divide_l_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sqrt: '<S179>/Sqrt' incorporates:
         *  Math: '<S179>/Square'
         *  Sum: '<S171>/Sum'
         *  Sum: '<S179>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0 + rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1);

        /* Switch: '<S171>/Switch' incorporates:
         *  Constant: '<S171>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S171>/Gain' */
          rtb_Switch_k = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S171>/Saturation' */
          if (rtb_Switch_k > FMS_PARAM.CRUISE_SPEED) {
            rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Switch_k < 0.5F) {
              rtb_Switch_k = 0.5F;
            }
          }

          /* End of Saturate: '<S171>/Saturation' */
        }

        /* End of Switch: '<S171>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S193>/Motion State' incorporates:
         *  Constant: '<S193>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S193>/Square'
         *  Math: '<S193>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S193>/Sqrt'
         *  Sum: '<S193>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S192>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S192>/Hold Control' incorporates:
             *  ActionPort: '<S195>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S192>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S192>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S192>/Hold Control' incorporates:
           *  ActionPort: '<S195>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S192>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S192>/Brake Control' incorporates:
           *  ActionPort: '<S194>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S192>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S192>/Move Control' incorporates:
             *  ActionPort: '<S196>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S192>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S192>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S192>/Move Control' incorporates:
           *  ActionPort: '<S196>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S192>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S192>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S183>/Motion Status' incorporates:
         *  Abs: '<S183>/Abs'
         *  Constant: '<S183>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S182>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S182>/Hold Control' incorporates:
             *  ActionPort: '<S185>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S182>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S182>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S182>/Hold Control' incorporates:
           *  ActionPort: '<S185>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S182>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S182>/Brake Control' incorporates:
           *  ActionPort: '<S184>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S182>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S182>/Move Control' incorporates:
             *  ActionPort: '<S186>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S182>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S182>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S182>/Move Control' incorporates:
           *  ActionPort: '<S186>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S182>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S182>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S151>/Sum' incorporates:
         *  MATLAB Function: '<S173>/OutRegionRegWP'
         *  MATLAB Function: '<S173>/SearchL1RefWP'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S176>/Sum1'
         *  Switch: '<S153>/Switch'
         */
        rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
          [0];
        rtb_MathFunction_iq_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S169>/Sum of Elements' incorporates:
         *  Math: '<S169>/Math Function'
         *  Sum: '<S151>/Sum'
         */
        rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0 + rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Math: '<S169>/Math Function1' incorporates:
         *  Sum: '<S169>/Sum of Elements'
         *
         * About '<S169>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_a_i = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_n));
        } else {
          rtb_a_i = sqrtf(rtb_DiscreteTimeIntegrator_n);
        }

        /* End of Math: '<S169>/Math Function1' */

        /* Switch: '<S169>/Switch' incorporates:
         *  Constant: '<S169>/Constant'
         *  Product: '<S169>/Product'
         *  Sum: '<S151>/Sum'
         */
        if (rtb_a_i > 0.0F) {
          rtb_Switch_ec[0] = rtb_MathFunction_iq_idx_0;
          rtb_Switch_ec[1] = rtb_P_d_idx_0;
          rtb_Switch_ec[2] = rtb_a_i;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S169>/Switch' */

        /* Product: '<S169>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_TmpSignalConversionAtDela_a[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S167>/Subtract' incorporates:
         *  Product: '<S167>/Multiply'
         *  Product: '<S167>/Multiply1'
         */
        rtb_a_i = rtb_TmpSignalConversionAtDela_a[0] * FMS_ConstB.Divide[1] -
          rtb_TmpSignalConversionAtDela_a[1] * FMS_ConstB.Divide[0];

        /* Signum: '<S156>/Sign1' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S156>/Sign1' */

        /* Switch: '<S156>/Switch2' incorporates:
         *  Constant: '<S156>/Constant4'
         */
        if (rtb_a_i == 0.0F) {
          rtb_a_i = 1.0F;
        }

        /* End of Switch: '<S156>/Switch2' */

        /* DotProduct: '<S156>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide[0] *
          rtb_TmpSignalConversionAtDela_a[0] + FMS_ConstB.Divide[1] *
          rtb_TmpSignalConversionAtDela_a[1];

        /* Trigonometry: '<S156>/Acos' incorporates:
         *  DotProduct: '<S156>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S156>/Multiply' incorporates:
         *  Trigonometry: '<S156>/Acos'
         */
        rtb_a_i *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S160>/Rem' incorporates:
         *  Constant: '<S160>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S155>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_a_i - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S160>/Switch' incorporates:
         *  Abs: '<S160>/Abs'
         *  Constant: '<S160>/Constant'
         *  Constant: '<S166>/Constant'
         *  Product: '<S160>/Multiply'
         *  RelationalOperator: '<S166>/Compare'
         *  Sum: '<S160>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S160>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_DiscreteTimeIntegrator_n = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_DiscreteTimeIntegrator_n = 1.0F;
          } else {
            rtb_DiscreteTimeIntegrator_n = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S160>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Switch: '<S160>/Switch' */

        /* Abs: '<S153>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S153>/Switch' incorporates:
         *  Product: '<S175>/Multiply'
         *  Sum: '<S175>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S192>/Saturation1' */
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

          /* End of Saturate: '<S192>/Saturation1' */

          /* Saturate: '<S182>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S182>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S175>/Sum' incorporates:
           *  Delay: '<S175>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S220>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_ec[0] = rtb_Divide_l_idx_1;
          rtb_Rem_k = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S175>/Sum' incorporates:
           *  Delay: '<S175>/Delay'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S222>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S222>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S221>/Gain' incorporates:
           *  DiscreteIntegrator: '<S219>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  Sum: '<S219>/Add'
           */
          rtb_DiscreteTimeIntegrator_n = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S222>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_DiscreteTimeIntegrator_n);

          /* Gain: '<S222>/Gain' incorporates:
           *  Trigonometry: '<S222>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_DiscreteTimeIntegrator_n);

          /* SignalConversion: '<S222>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S222>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S222>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_DiscreteTimeIntegrator_n);

          /* Trigonometry: '<S222>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_DiscreteTimeIntegrator_n);

          /* SignalConversion: '<S222>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Sum: '<S220>/Sum of Elements' incorporates:
           *  Math: '<S220>/Math Function'
           */
          rtb_DiscreteTimeIntegrator_n = rtb_Switch_ec[0] * rtb_Switch_ec[0] +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

          /* Math: '<S220>/Math Function1' incorporates:
           *  Sum: '<S220>/Sum of Elements'
           *
           * About '<S220>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
            rtb_DiscreteTimeIntegrator_n = -sqrtf(fabsf
              (rtb_DiscreteTimeIntegrator_n));
          } else {
            rtb_DiscreteTimeIntegrator_n = sqrtf(rtb_DiscreteTimeIntegrator_n);
          }

          /* End of Math: '<S220>/Math Function1' */

          /* Switch: '<S220>/Switch' incorporates:
           *  Constant: '<S220>/Constant'
           *  Product: '<S220>/Product'
           */
          if (rtb_DiscreteTimeIntegrator_n <= 0.0F) {
            rtb_Rem_k = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_DiscreteTimeIntegrator_n = 1.0F;
          }

          /* End of Switch: '<S220>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S176>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_h_idx_0 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_1 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S176>/Divide' incorporates:
           *  Math: '<S177>/Square'
           *  Math: '<S178>/Square'
           *  Sqrt: '<S177>/Sqrt'
           *  Sqrt: '<S178>/Sqrt'
           *  Sum: '<S176>/Sum'
           *  Sum: '<S177>/Sum of Elements'
           *  Sum: '<S178>/Sum of Elements'
           */
          rtb_MathFunction_h_idx_0 = sqrtf(rtb_MathFunction_h_idx_0 *
            rtb_MathFunction_h_idx_0 + rtb_MathFunction_h_idx_1 *
            rtb_MathFunction_h_idx_1) / sqrtf(rtb_P_d_idx_0 * rtb_P_d_idx_0 +
            rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

          /* Saturate: '<S176>/Saturation' */
          if (rtb_MathFunction_h_idx_0 > 1.0F) {
            rtb_MathFunction_h_idx_0 = 1.0F;
          } else {
            if (rtb_MathFunction_h_idx_0 < 0.0F) {
              rtb_MathFunction_h_idx_0 = 0.0F;
            }
          }

          /* End of Saturate: '<S176>/Saturation' */

          /* Product: '<S218>/Multiply2' incorporates:
           *  Product: '<S220>/Divide'
           */
          rtb_Rem_k = rtb_Rem_k / rtb_DiscreteTimeIntegrator_n * rtb_Switch_k;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_DiscreteTimeIntegrator_n
            * rtb_Switch_k;

          /* Product: '<S175>/Multiply' */
          for (i = 0; i < 3; i++) {
            rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[i] * rtb_Rem_k;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S170>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S176>/Multiply'
           *  SignalConversion: '<S29>/Signal Copy1'
           *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S170>/Sum2'
           *  Sum: '<S176>/Add'
           *  Sum: '<S176>/Subtract'
           */
          rtb_Divide_l_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_MathFunction_h_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_ec[0] = rtb_Transpose_0[0];
          rtb_Switch_ec[1] = rtb_Transpose_0[1];

          /* Saturate: '<S170>/Saturation1' incorporates:
           *  Product: '<S175>/Multiply'
           */
          if (rtb_Divide_l_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_l_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = rtb_Divide_l_idx_1;
          }

          /* End of Saturate: '<S170>/Saturation1' */
        }

        /* Delay: '<S155>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S158>/Integrator1' incorporates:
         *  Delay: '<S155>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S162>/Rem' incorporates:
         *  Constant: '<S162>/Constant1'
         *  DiscreteIntegrator: '<S158>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S157>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S162>/Switch' incorporates:
         *  Abs: '<S162>/Abs'
         *  Constant: '<S162>/Constant'
         *  Constant: '<S163>/Constant'
         *  Product: '<S162>/Multiply'
         *  RelationalOperator: '<S163>/Compare'
         *  Sum: '<S162>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S162>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_k;
          }

          /* End of Signum: '<S162>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S162>/Switch' */

        /* Gain: '<S157>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S157>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S157>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S151>/Bus Assignment'
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S151>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S151>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_ec[0];
        FMS_Y.FMS_Out.v_cmd = rtb_Switch_ec[1];
        FMS_Y.FMS_Out.w_cmd = rtb_Switch_ec[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S213>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtDela_a[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_TmpSignalConversionAtDela_a[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S213>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S213>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_DiscreteTimeIntegrator_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S213>/Math Function1' incorporates:
         *  Sum: '<S213>/Sum of Elements'
         *
         * About '<S213>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_DiscreteTimeIntegrator_n));
        } else {
          rtb_Rem_k = sqrtf(rtb_DiscreteTimeIntegrator_n);
        }

        /* End of Math: '<S213>/Math Function1' */

        /* Switch: '<S213>/Switch' incorporates:
         *  Constant: '<S213>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S213>/Product'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        if (rtb_Rem_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_ec[0] = FMS_U.INS_Out.vn;
          rtb_Switch_ec[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_ec[2] = rtb_Rem_k;
        } else {
          rtb_Switch_ec[0] = 0.0F;
          rtb_Switch_ec[1] = 0.0F;
          rtb_Switch_ec[2] = 1.0F;
        }

        /* End of Switch: '<S213>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S173>/NearbyRefWP' incorporates:
         *  Constant: '<S151>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                        rtb_TmpSignalConversionAtDela_a,
                        &rtb_DiscreteTimeIntegrator_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* MATLAB Function: '<S173>/SearchL1RefWP' incorporates:
         *  Constant: '<S151>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_k = rtb_P_d_idx_0 * rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        B = (rtb_P_d_idx_0 * (FMS_B.Cmd_In.cur_waypoint[0] - FMS_U.INS_Out.x_R)
             + rtb_MathFunction_iq_idx_0 * (FMS_B.Cmd_In.cur_waypoint[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_B.Cmd_In.cur_waypoint[0] *
                        FMS_B.Cmd_In.cur_waypoint[0]) +
                       FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint
                       [1]) - (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0]
          + FMS_U.INS_Out.y_R * FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Rem_k);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
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
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_MathFunction_h_idx_0 = rtb_P_d_idx_0 * rtb_Divide_l_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_1 = rtb_MathFunction_iq_idx_0 *
            rtb_Divide_l_idx_1 + FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S173>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_k = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                     rtb_MathFunction_iq_idx_0 + (FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_P_d_idx_0) / (rtb_P_d_idx_0 *
          rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Rem_k <= 0.0F);
        rtb_LogicalOperator_e = (rtb_Rem_k >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else if (rtb_LogicalOperator_e) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_P_d_idx_0 = rtb_Rem_k * rtb_P_d_idx_0 + FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Switch: '<S173>/Switch1' incorporates:
         *  Constant: '<S206>/Constant'
         *  RelationalOperator: '<S206>/Compare'
         */
        if (rtb_DiscreteTimeIntegrator_n <= 0.0F) {
          /* Switch: '<S173>/Switch' incorporates:
           *  Constant: '<S205>/Constant'
           *  MATLAB Function: '<S173>/SearchL1RefWP'
           *  RelationalOperator: '<S205>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_h_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S173>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else if (rtb_LogicalOperator_e) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_TmpSignalConversionAtDela_a[1] = rtb_Rem_k *
                rtb_MathFunction_iq_idx_0 + FMS_B.Cmd_In.cur_waypoint[1];

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
        rtb_MathFunction_h_idx_0 = rtb_TmpSignalConversionAtDela_a[0] -
          FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;
        rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S174>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S214>/Math Function'
         *  SignalConversion: '<S29>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_TmpSignalConversionAtDela_a[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S214>/Math Function' incorporates:
         *  Math: '<S212>/Square'
         */
        rtb_DiscreteTimeIntegrator_n = rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Sum: '<S214>/Sum of Elements' incorporates:
         *  Math: '<S214>/Math Function'
         */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n +
          rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S214>/Math Function1' incorporates:
         *  Sum: '<S214>/Sum of Elements'
         *
         * About '<S214>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S214>/Math Function1' */

        /* Switch: '<S214>/Switch' incorporates:
         *  Constant: '<S214>/Constant'
         *  Product: '<S214>/Product'
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

        /* End of Switch: '<S214>/Switch' */

        /* Product: '<S213>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_P_d_idx_0 = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S216>/Sum of Elements' incorporates:
         *  Math: '<S216>/Math Function'
         *  SignalConversion: '<S216>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0;

        /* Math: '<S216>/Math Function1' incorporates:
         *  Sum: '<S216>/Sum of Elements'
         *
         * About '<S216>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S216>/Math Function1' */

        /* Switch: '<S216>/Switch' incorporates:
         *  Constant: '<S216>/Constant'
         *  Product: '<S216>/Product'
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

        /* End of Switch: '<S216>/Switch' */

        /* Product: '<S214>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S217>/Sum of Elements' incorporates:
         *  Math: '<S217>/Math Function'
         *  SignalConversion: '<S217>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0;

        /* Math: '<S217>/Math Function1' incorporates:
         *  Sum: '<S217>/Sum of Elements'
         *
         * About '<S217>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S217>/Math Function1' */

        /* Switch: '<S217>/Switch' incorporates:
         *  Constant: '<S217>/Constant'
         *  Product: '<S217>/Product'
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

        /* End of Switch: '<S217>/Switch' */

        /* Product: '<S217>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S216>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[0] *= rtb_Saturation1_ln[0];

        /* Product: '<S217>/Divide' incorporates:
         *  Math: '<S212>/Square'
         */
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S216>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sqrt: '<S211>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S211>/Square'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sum: '<S211>/Sum of Elements'
         */
        rtb_Rem_k = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve
                          * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S174>/Gain' incorporates:
         *  Math: '<S174>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S215>/Subtract' incorporates:
         *  Product: '<S215>/Multiply'
         *  Product: '<S215>/Multiply1'
         */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 * rtb_TmpSignalConversionAtDela_a
          [1] - rtb_P_d_idx_0 * rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S210>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S210>/Sign1' */

        /* Switch: '<S210>/Switch2' incorporates:
         *  Constant: '<S210>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S210>/Switch2' */

        /* DotProduct: '<S210>/Dot Product' */
        rtb_MathFunction_iq_idx_0 = rtb_TmpSignalConversionAtDela_a[0] *
          rtb_MathFunction_iq_idx_0 + rtb_TmpSignalConversionAtDela_a[1] *
          rtb_P_d_idx_0;

        /* Trigonometry: '<S210>/Acos' incorporates:
         *  DotProduct: '<S210>/Dot Product'
         */
        if (rtb_MathFunction_iq_idx_0 > 1.0F) {
          rtb_MathFunction_iq_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_0 < -1.0F) {
            rtb_MathFunction_iq_idx_0 = -1.0F;
          }
        }

        /* Product: '<S210>/Multiply' incorporates:
         *  Trigonometry: '<S210>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_MathFunction_iq_idx_0);

        /* Saturate: '<S174>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S174>/Saturation' */

        /* Product: '<S174>/Divide' incorporates:
         *  Constant: '<S151>/L1'
         *  Constant: '<S174>/Constant'
         *  MinMax: '<S174>/Max'
         *  MinMax: '<S174>/Min'
         *  Product: '<S174>/Multiply1'
         *  Sqrt: '<S212>/Sqrt'
         *  Sum: '<S212>/Sum of Elements'
         *  Trigonometry: '<S174>/Sin'
         */
        rtb_MathFunction_iq_idx_0 = arm_sin_f32(rtb_Rem_k) * rtb_Divide_l_idx_1 /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_DiscreteTimeIntegrator_n +
                  rtb_Saturation1_ln[0]), 0.5F));

        /* Sum: '<S155>/Sum2' incorporates:
         *  Delay: '<S155>/Delay'
         */
        rtb_a_i -= FMS_DW.Delay_DSTATE_h;

        /* Math: '<S159>/Rem' incorporates:
         *  Constant: '<S159>/Constant1'
         */
        rtb_DiscreteTimeIntegrator_n = rt_remf(rtb_a_i, 6.28318548F);

        /* Switch: '<S159>/Switch' incorporates:
         *  Abs: '<S159>/Abs'
         *  Constant: '<S159>/Constant'
         *  Constant: '<S165>/Constant'
         *  Product: '<S159>/Multiply'
         *  RelationalOperator: '<S165>/Compare'
         *  Sum: '<S159>/Add'
         */
        if (fabsf(rtb_DiscreteTimeIntegrator_n) > 3.14159274F) {
          /* Signum: '<S159>/Sign' */
          if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n;
          }

          /* End of Signum: '<S159>/Sign' */
          rtb_DiscreteTimeIntegrator_n -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S159>/Switch' */

        /* Sum: '<S155>/Sum' incorporates:
         *  Delay: '<S155>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n +
          FMS_DW.Delay_DSTATE_h;

        /* Product: '<S164>/Multiply1' incorporates:
         *  Constant: '<S164>/const1'
         *  DiscreteIntegrator: '<S158>/Integrator'
         */
        rtb_DiscreteTimeIntegrator_n = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S164>/Add' incorporates:
         *  DiscreteIntegrator: '<S158>/Integrator1'
         *  Sum: '<S158>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_p - rtb_Divide_l_idx_1) +
          rtb_DiscreteTimeIntegrator_n;

        /* Signum: '<S164>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S164>/Sign' */

        /* Sum: '<S164>/Add2' incorporates:
         *  Abs: '<S164>/Abs'
         *  Gain: '<S164>/Gain'
         *  Gain: '<S164>/Gain1'
         *  Product: '<S164>/Multiply2'
         *  Product: '<S164>/Multiply3'
         *  Sqrt: '<S164>/Sqrt'
         *  Sum: '<S164>/Add1'
         *  Sum: '<S164>/Subtract'
         */
        rtb_a_i = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_j) *
                         FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S164>/Add4' */
        rtb_DiscreteTimeIntegrator_n += rtb_Rem_k - rtb_a_i;

        /* Sum: '<S164>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_j;

        /* Sum: '<S164>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_j;

        /* Signum: '<S164>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S164>/Sign1' */

        /* Signum: '<S164>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S164>/Sign2' */

        /* Sum: '<S164>/Add5' incorporates:
         *  Gain: '<S164>/Gain2'
         *  Product: '<S164>/Multiply4'
         *  Sum: '<S164>/Subtract2'
         */
        rtb_a_i += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F *
          rtb_DiscreteTimeIntegrator_n;

        /* Update for Delay: '<S175>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S219>/Discrete-Time Integrator' incorporates:
         *  Product: '<S175>/Divide1'
         */
        FMS_DW.l1_heading += rtb_MathFunction_iq_idx_0 / rtb_Switch_k * 0.004F;

        /* Update for Delay: '<S155>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S158>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S158>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Sum: '<S164>/Add6' */
        rtb_Divide_l_idx_1 = rtb_a_i + FMS_ConstB.d_j;

        /* Sum: '<S164>/Subtract3' */
        rtb_Rem_k = rtb_a_i - FMS_ConstB.d_j;

        /* Signum: '<S164>/Sign5' */
        if (rtb_a_i < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_a_i;
        }

        /* End of Signum: '<S164>/Sign5' */

        /* Signum: '<S164>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S164>/Sign3' */

        /* Signum: '<S164>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S164>/Sign4' */

        /* Signum: '<S164>/Sign6' */
        if (rtb_a_i < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_a_i;
        }

        /* End of Signum: '<S164>/Sign6' */

        /* Update for DiscreteIntegrator: '<S158>/Integrator' incorporates:
         *  Constant: '<S164>/const'
         *  Gain: '<S164>/Gain3'
         *  Product: '<S164>/Divide'
         *  Product: '<S164>/Multiply5'
         *  Product: '<S164>/Multiply6'
         *  Sum: '<S164>/Subtract4'
         *  Sum: '<S164>/Subtract5'
         *  Sum: '<S164>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_a_i / FMS_ConstB.d_j -
          rtb_DiscreteTimeIntegrator_n) * FMS_ConstB.Gain4_c *
          ((rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F) - rtb_Switch_k * 1.04719758F)
          * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S158>/Integrator' */
        /* End of Outputs for SubSystem: '<S147>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Update for UnitDelay: '<S150>/Delay Input1' incorporates:
         *  SignalConversion: '<S29>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S150>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S35>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S35>/Unknown' incorporates:
         *  ActionPort: '<S149>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

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
          /* Disable for SwitchCase: '<S134>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S49>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S66>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S82>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S110>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S97>/Switch Case' */
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
          rtb_DiscreteTimeIntegrator_n = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
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
          rtb_DiscreteTimeIntegrator_n), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S34>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S34>/Stabilize' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S34>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S130>/Integrator'
           *  DiscreteIntegrator: '<S130>/Integrator1'
           *  DiscreteIntegrator: '<S131>/Integrator'
           *  DiscreteIntegrator: '<S131>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_jt = 0.0F;
          FMS_DW.Integrator_DSTATE_cq = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S34>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S34>/Stabilize' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S135>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S34>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S34>/Stabilize' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        /* Product: '<S132>/Multiply1' incorporates:
         *  Constant: '<S132>/const1'
         *  DiscreteIntegrator: '<S130>/Integrator'
         */
        rtb_a_i = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S128>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_roll -
            FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_roll -
            (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S128>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S132>/Add' incorporates:
         *  DiscreteIntegrator: '<S130>/Integrator1'
         *  Gain: '<S125>/Gain'
         *  Gain: '<S128>/Gain'
         *  Sum: '<S130>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_DiscreteTimeIntegrator_n *
                     FMS_PARAM.ROLL_PITCH_LIM) + rtb_a_i;

        /* Signum: '<S132>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S132>/Sign' */

        /* Sum: '<S132>/Add2' incorporates:
         *  Abs: '<S132>/Abs'
         *  Gain: '<S132>/Gain'
         *  Gain: '<S132>/Gain1'
         *  Product: '<S132>/Multiply2'
         *  Product: '<S132>/Multiply3'
         *  Sqrt: '<S132>/Sqrt'
         *  Sum: '<S132>/Add1'
         *  Sum: '<S132>/Subtract'
         */
        rtb_Switch_k = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_d) *
                              FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_a_i;

        /* Sum: '<S132>/Add4' */
        rtb_DiscreteTimeIntegrator_n = (rtb_Rem_k - rtb_Switch_k) + rtb_a_i;

        /* Sum: '<S132>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_d;

        /* Sum: '<S132>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_d;

        /* Signum: '<S132>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign1' */

        /* Signum: '<S132>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign2' */

        /* Sum: '<S132>/Add5' incorporates:
         *  Gain: '<S132>/Gain2'
         *  Product: '<S132>/Multiply4'
         *  Sum: '<S132>/Subtract2'
         */
        rtb_Switch_k += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F *
          rtb_DiscreteTimeIntegrator_n;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S135>/Motion State' incorporates:
         *  Abs: '<S135>/Abs'
         *  Abs: '<S135>/Abs1'
         *  Constant: '<S145>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S145>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S134>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S134>/Hold Control' incorporates:
             *  ActionPort: '<S137>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S134>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S134>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S134>/Hold Control' incorporates:
           *  ActionPort: '<S137>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                             &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S134>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S134>/Brake Control' incorporates:
           *  ActionPort: '<S136>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S134>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S134>/Move Control' incorporates:
             *  ActionPort: '<S138>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S134>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S134>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S134>/Move Control' incorporates:
           *  ActionPort: '<S138>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S134>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S134>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S42>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DiscreteIntegrator: '<S130>/Integrator1'
         *  DiscreteIntegrator: '<S131>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_j;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_jt;

        /* Saturate: '<S134>/Saturation' */
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

        /* End of Saturate: '<S134>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Saturate: '<S127>/Saturation' incorporates:
         *  Constant: '<S127>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         *  Sum: '<S127>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_DiscreteTimeIntegrator_n = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S127>/Saturation' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  Constant: '<S127>/Constant5'
         *  Gain: '<S127>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S127>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_DiscreteTimeIntegrator_n), 65536.0F) + 1000U);

        /* Product: '<S133>/Multiply1' incorporates:
         *  Constant: '<S133>/const1'
         *  DiscreteIntegrator: '<S131>/Integrator'
         */
        rtb_Rem_k = FMS_DW.Integrator_DSTATE_cq * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S129>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_pitch -
            FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S129>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S133>/Add' incorporates:
         *  DiscreteIntegrator: '<S131>/Integrator1'
         *  Gain: '<S125>/Gain1'
         *  Gain: '<S129>/Gain'
         *  Sum: '<S131>/Subtract'
         */
        rtb_a_i = (FMS_DW.Integrator1_DSTATE_jt - 1.0F / (1.0F -
                    FMS_PARAM.PITCH_DZ) * rtb_DiscreteTimeIntegrator_n *
                   -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Rem_k;

        /* Signum: '<S133>/Sign' */
        if (rtb_a_i < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_a_i;
        }

        /* End of Signum: '<S133>/Sign' */

        /* Sum: '<S133>/Add2' incorporates:
         *  Abs: '<S133>/Abs'
         *  Gain: '<S133>/Gain'
         *  Gain: '<S133>/Gain1'
         *  Product: '<S133>/Multiply2'
         *  Product: '<S133>/Multiply3'
         *  Sqrt: '<S133>/Sqrt'
         *  Sum: '<S133>/Add1'
         *  Sum: '<S133>/Subtract'
         */
        rtb_DiscreteTimeIntegrator_n = (sqrtf((8.0F * fabsf(rtb_a_i) +
          FMS_ConstB.d_o) * FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Rem_k;

        /* Sum: '<S133>/Add4' */
        rtb_Rem_k += rtb_a_i - rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S133>/Add3' */
        rtb_Divide_l_idx_1 = rtb_a_i + FMS_ConstB.d_o;

        /* Sum: '<S133>/Subtract1' */
        rtb_a_i -= FMS_ConstB.d_o;

        /* Signum: '<S133>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S133>/Sign1' */

        /* Signum: '<S133>/Sign2' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S133>/Sign2' */

        /* Sum: '<S133>/Add5' incorporates:
         *  Gain: '<S133>/Gain2'
         *  Product: '<S133>/Multiply4'
         *  Sum: '<S133>/Subtract2'
         */
        rtb_DiscreteTimeIntegrator_n += (rtb_Divide_l_idx_1 - rtb_a_i) * 0.5F *
          rtb_Rem_k;

        /* Update for DiscreteIntegrator: '<S130>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S130>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S132>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Switch_k + FMS_ConstB.d_d;

        /* Sum: '<S132>/Subtract3' */
        rtb_Rem_k = rtb_Switch_k - FMS_ConstB.d_d;

        /* Signum: '<S132>/Sign5' */
        if (rtb_Switch_k < 0.0F) {
          rtb_a_i = -1.0F;
        } else if (rtb_Switch_k > 0.0F) {
          rtb_a_i = 1.0F;
        } else {
          rtb_a_i = rtb_Switch_k;
        }

        /* End of Signum: '<S132>/Sign5' */

        /* Signum: '<S132>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign3' */

        /* Signum: '<S132>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign4' */

        /* Signum: '<S132>/Sign6' */
        if (rtb_Switch_k < 0.0F) {
          rtb_MathFunction_iq_idx_0 = -1.0F;
        } else if (rtb_Switch_k > 0.0F) {
          rtb_MathFunction_iq_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_0 = rtb_Switch_k;
        }

        /* End of Signum: '<S132>/Sign6' */

        /* Update for DiscreteIntegrator: '<S130>/Integrator' incorporates:
         *  Constant: '<S132>/const'
         *  Gain: '<S132>/Gain3'
         *  Product: '<S132>/Divide'
         *  Product: '<S132>/Multiply5'
         *  Product: '<S132>/Multiply6'
         *  Sum: '<S132>/Subtract4'
         *  Sum: '<S132>/Subtract5'
         *  Sum: '<S132>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Switch_k / FMS_ConstB.d_d - rtb_a_i)
          * FMS_ConstB.Gain4_n * ((rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F) -
          rtb_MathFunction_iq_idx_0 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S131>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S131>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_jt += 0.004F * FMS_DW.Integrator_DSTATE_cq;

        /* Sum: '<S133>/Add6' */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n + FMS_ConstB.d_o;

        /* Sum: '<S133>/Subtract3' */
        rtb_Rem_k = rtb_DiscreteTimeIntegrator_n - FMS_ConstB.d_o;

        /* Signum: '<S133>/Sign5' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S133>/Sign5' */

        /* Signum: '<S133>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S133>/Sign3' */

        /* Signum: '<S133>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S133>/Sign4' */

        /* Signum: '<S133>/Sign6' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_a_i = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_a_i = 1.0F;
        } else {
          rtb_a_i = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S133>/Sign6' */

        /* Update for DiscreteIntegrator: '<S131>/Integrator' incorporates:
         *  Constant: '<S133>/const'
         *  Gain: '<S133>/Gain3'
         *  Product: '<S133>/Divide'
         *  Product: '<S133>/Multiply5'
         *  Product: '<S133>/Multiply6'
         *  Sum: '<S133>/Subtract4'
         *  Sum: '<S133>/Subtract5'
         *  Sum: '<S133>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_cq += ((rtb_DiscreteTimeIntegrator_n /
          FMS_ConstB.d_o - rtb_Switch_k) * FMS_ConstB.Gain4_n3 *
          ((rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F) - rtb_a_i * 12.566371F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S34>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S34>/Altitude' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S34>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S62>/Integrator'
           *  DiscreteIntegrator: '<S62>/Integrator1'
           *  DiscreteIntegrator: '<S63>/Integrator'
           *  DiscreteIntegrator: '<S63>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S34>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S34>/Altitude' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S50>/Motion Status'
           *  Chart: '<S67>/Motion State'
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
         *  Constant: '<S58>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S58>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S49>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
          FMS_MoveControl_l(FMS_U.INS_Out.h_AGL, FMS_U.Pilot_Cmd.stick_throttle,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S49>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S49>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S67>/Motion State' incorporates:
         *  Abs: '<S67>/Abs'
         *  Abs: '<S67>/Abs1'
         *  Constant: '<S77>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S77>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S66>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S66>/Hold Control' incorporates:
             *  ActionPort: '<S69>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S66>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S66>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S66>/Hold Control' incorporates:
           *  ActionPort: '<S69>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                             &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S66>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S66>/Brake Control' incorporates:
           *  ActionPort: '<S68>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S66>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S66>/Move Control' incorporates:
             *  ActionPort: '<S70>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S66>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_cr);

            /* End of SystemReset for SubSystem: '<S66>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S66>/Move Control' incorporates:
           *  ActionPort: '<S70>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_cr, &FMS_DW.MoveControl_cr);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S66>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S66>/Switch Case' */

        /* Product: '<S64>/Multiply1' incorporates:
         *  Constant: '<S64>/const1'
         *  DiscreteIntegrator: '<S62>/Integrator'
         */
        rtb_a_i = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S60>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_roll -
            FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_roll -
            (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S60>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S64>/Add' incorporates:
         *  DiscreteIntegrator: '<S62>/Integrator1'
         *  Gain: '<S47>/Gain'
         *  Gain: '<S60>/Gain'
         *  Sum: '<S62>/Subtract'
         */
        rtb_DiscreteTimeIntegrator_n = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F
          - FMS_PARAM.ROLL_DZ) * rtb_DiscreteTimeIntegrator_n *
          FMS_PARAM.ROLL_PITCH_LIM) + rtb_a_i;

        /* Signum: '<S64>/Sign' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S64>/Sign' */

        /* Sum: '<S64>/Add2' incorporates:
         *  Abs: '<S64>/Abs'
         *  Gain: '<S64>/Gain'
         *  Gain: '<S64>/Gain1'
         *  Product: '<S64>/Multiply2'
         *  Product: '<S64>/Multiply3'
         *  Sqrt: '<S64>/Sqrt'
         *  Sum: '<S64>/Add1'
         *  Sum: '<S64>/Subtract'
         */
        rtb_MathFunction_iq_idx_0 = (sqrtf((8.0F * fabsf
          (rtb_DiscreteTimeIntegrator_n) + FMS_ConstB.d) * FMS_ConstB.d) -
          FMS_ConstB.d) * 0.5F * rtb_Divide_l_idx_1 + rtb_a_i;

        /* Sum: '<S64>/Add4' */
        rtb_Switch_k = (rtb_DiscreteTimeIntegrator_n - rtb_MathFunction_iq_idx_0)
          + rtb_a_i;

        /* Sum: '<S64>/Add3' */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n + FMS_ConstB.d;

        /* Sum: '<S64>/Subtract1' */
        rtb_DiscreteTimeIntegrator_n -= FMS_ConstB.d;

        /* Signum: '<S64>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S64>/Sign1' */

        /* Signum: '<S64>/Sign2' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else {
          if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
            rtb_DiscreteTimeIntegrator_n = 1.0F;
          }
        }

        /* End of Signum: '<S64>/Sign2' */

        /* Sum: '<S64>/Add5' incorporates:
         *  Gain: '<S64>/Gain2'
         *  Product: '<S64>/Multiply4'
         *  Sum: '<S64>/Subtract2'
         */
        rtb_MathFunction_iq_idx_0 += (rtb_Divide_l_idx_1 -
          rtb_DiscreteTimeIntegrator_n) * 0.5F * rtb_Switch_k;

        /* Sum: '<S64>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_MathFunction_iq_idx_0 - FMS_ConstB.d;

        /* Sum: '<S64>/Add6' */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 + FMS_ConstB.d;

        /* Product: '<S64>/Divide' */
        rtb_P_d_idx_0 = rtb_MathFunction_iq_idx_0 / FMS_ConstB.d;

        /* Signum: '<S64>/Sign5' incorporates:
         *  Signum: '<S64>/Sign6'
         */
        if (rtb_MathFunction_iq_idx_0 < 0.0F) {
          rtb_MathFunction_h_idx_0 = -1.0F;
          rtb_Switch_k = -1.0F;
        } else if (rtb_MathFunction_iq_idx_0 > 0.0F) {
          rtb_MathFunction_h_idx_0 = 1.0F;
          rtb_Switch_k = 1.0F;
        } else {
          rtb_MathFunction_h_idx_0 = rtb_MathFunction_iq_idx_0;
          rtb_Switch_k = rtb_MathFunction_iq_idx_0;
        }

        /* End of Signum: '<S64>/Sign5' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  BusAssignment: '<S40>/Bus Assignment'
         *  Constant: '<S40>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         *  DiscreteIntegrator: '<S62>/Integrator1'
         *  DiscreteIntegrator: '<S63>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S66>/Saturation' */
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

        /* End of Saturate: '<S66>/Saturation' */

        /* Saturate: '<S49>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S40>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S40>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S40>/Bus Assignment' incorporates:
           *  BusAssignment: '<S31>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S49>/Saturation1' */

        /* Product: '<S65>/Multiply1' incorporates:
         *  Constant: '<S65>/const1'
         *  DiscreteIntegrator: '<S63>/Integrator'
         */
        rtb_MathFunction_iq_idx_0 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S61>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_pitch -
            FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_DiscreteTimeIntegrator_n = 0.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S61>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S65>/Add' incorporates:
         *  DiscreteIntegrator: '<S63>/Integrator1'
         *  Gain: '<S47>/Gain1'
         *  Gain: '<S61>/Gain'
         *  Sum: '<S63>/Subtract'
         */
        rtb_a_i = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
                    FMS_PARAM.PITCH_DZ) * rtb_DiscreteTimeIntegrator_n *
                   -FMS_PARAM.ROLL_PITCH_LIM) + rtb_MathFunction_iq_idx_0;

        /* Signum: '<S65>/Sign' */
        if (rtb_a_i < 0.0F) {
          rtb_DiscreteTimeIntegrator_n = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_DiscreteTimeIntegrator_n = 1.0F;
        } else {
          rtb_DiscreteTimeIntegrator_n = rtb_a_i;
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
        rtb_DiscreteTimeIntegrator_n = (sqrtf((8.0F * fabsf(rtb_a_i) +
          FMS_ConstB.d_c) * FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
          rtb_DiscreteTimeIntegrator_n + rtb_MathFunction_iq_idx_0;

        /* Sum: '<S65>/Add4' */
        rtb_MathFunction_iq_idx_0 += rtb_a_i - rtb_DiscreteTimeIntegrator_n;

        /* Sum: '<S65>/Add3' */
        rtb_MathFunction_h_idx_1 = rtb_a_i + FMS_ConstB.d_c;

        /* Sum: '<S65>/Subtract1' */
        rtb_a_i -= FMS_ConstB.d_c;

        /* Signum: '<S65>/Sign1' */
        if (rtb_MathFunction_h_idx_1 < 0.0F) {
          rtb_MathFunction_h_idx_1 = -1.0F;
        } else {
          if (rtb_MathFunction_h_idx_1 > 0.0F) {
            rtb_MathFunction_h_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign1' */

        /* Signum: '<S65>/Sign2' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign2' */

        /* Sum: '<S65>/Add5' incorporates:
         *  Gain: '<S65>/Gain2'
         *  Product: '<S65>/Multiply4'
         *  Sum: '<S65>/Subtract2'
         */
        rtb_DiscreteTimeIntegrator_n += (rtb_MathFunction_h_idx_1 - rtb_a_i) *
          0.5F * rtb_MathFunction_iq_idx_0;

        /* Update for DiscreteIntegrator: '<S62>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S62>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S64>/Sign3' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S64>/Sign3' */

        /* Signum: '<S64>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S64>/Sign4' */

        /* Update for DiscreteIntegrator: '<S62>/Integrator' incorporates:
         *  Constant: '<S64>/const'
         *  Gain: '<S64>/Gain3'
         *  Product: '<S64>/Multiply5'
         *  Product: '<S64>/Multiply6'
         *  Sum: '<S64>/Subtract4'
         *  Sum: '<S64>/Subtract5'
         *  Sum: '<S64>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_P_d_idx_0 - rtb_MathFunction_h_idx_0) *
          FMS_ConstB.Gain4 * ((rtb_Rem_k - rtb_Divide_l_idx_1) * 0.5F) -
          rtb_Switch_k * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S63>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S63>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S65>/Add6' */
        rtb_Divide_l_idx_1 = rtb_DiscreteTimeIntegrator_n + FMS_ConstB.d_c;

        /* Sum: '<S65>/Subtract3' */
        rtb_Rem_k = rtb_DiscreteTimeIntegrator_n - FMS_ConstB.d_c;

        /* Signum: '<S65>/Sign5' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_DiscreteTimeIntegrator_n;
        }

        /* End of Signum: '<S65>/Sign5' */

        /* Signum: '<S65>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign3' */

        /* Signum: '<S65>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign4' */

        /* Signum: '<S65>/Sign6' */
        if (rtb_DiscreteTimeIntegrator_n < 0.0F) {
          rtb_a_i = -1.0F;
        } else if (rtb_DiscreteTimeIntegrator_n > 0.0F) {
          rtb_a_i = 1.0F;
        } else {
          rtb_a_i = rtb_DiscreteTimeIntegrator_n;
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
        FMS_DW.Integrator_DSTATE_b += ((rtb_DiscreteTimeIntegrator_n /
          FMS_ConstB.d_c - rtb_Switch_k) * FMS_ConstB.Gain4_m *
          ((rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F) - rtb_a_i * 12.566371F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S34>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S34>/Position' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S111>/Motion State'
           *  Chart: '<S83>/Motion Status'
           *  Chart: '<S98>/Motion State'
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
        /* Chart: '<S83>/Motion Status' incorporates:
         *  Abs: '<S83>/Abs'
         *  Abs: '<S83>/Abs1'
         *  Constant: '<S95>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S95>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_i);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S82>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S82>/Hold Control' incorporates:
             *  ActionPort: '<S85>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S82>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S82>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S82>/Hold Control' incorporates:
           *  ActionPort: '<S85>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S82>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S82>/Brake Control' incorporates:
           *  ActionPort: '<S84>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S82>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S82>/Move Control' incorporates:
           *  ActionPort: '<S86>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.INS_Out.h_AGL, FMS_U.Pilot_Cmd.stick_throttle,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S82>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S82>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S98>/Motion State' incorporates:
         *  Abs: '<S98>/Abs'
         *  Abs: '<S98>/Abs1'
         *  Constant: '<S108>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S108>/Compare'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S111>/Logical Operator' incorporates:
         *  Abs: '<S111>/Abs1'
         *  Abs: '<S111>/Abs2'
         *  Constant: '<S122>/Constant'
         *  Constant: '<S123>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S122>/Compare'
         *  RelationalOperator: '<S123>/Compare'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S111>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S111>/Square'
         *  Math: '<S111>/Square1'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  Sqrt: '<S111>/Sqrt'
         *  Sum: '<S111>/Add'
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

        /* End of Chart: '<S111>/Motion State' */

        /* SwitchCase: '<S110>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S110>/Hold Control' incorporates:
             *  ActionPort: '<S113>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S110>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S110>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S110>/Hold Control' incorporates:
           *  ActionPort: '<S113>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S110>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S110>/Brake Control' incorporates:
           *  ActionPort: '<S112>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S110>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S110>/Move Control' incorporates:
             *  ActionPort: '<S114>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S110>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S110>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S110>/Move Control' incorporates:
           *  ActionPort: '<S114>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S110>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S110>/Switch Case' */

        /* SwitchCase: '<S97>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S29>/Signal Copy1'
         *  SignalConversion: '<S29>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_j;
        FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
        switch (rtb_state_a) {
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
            /* SystemReset for IfAction SubSystem: '<S97>/Hold Control' incorporates:
             *  ActionPort: '<S100>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S97>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S97>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S97>/Hold Control' incorporates:
           *  ActionPort: '<S100>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                             &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S97>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S97>/Brake Control' incorporates:
           *  ActionPort: '<S99>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S97>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S97>/Move Control' incorporates:
             *  ActionPort: '<S101>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S97>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_mr);

            /* End of SystemReset for SubSystem: '<S97>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S97>/Move Control' incorporates:
           *  ActionPort: '<S101>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_mr, &FMS_DW.MoveControl_mr);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S97>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S97>/Switch Case' */

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

        /* Saturate: '<S97>/Saturation' */
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

        /* End of Saturate: '<S97>/Saturation' */

        /* Saturate: '<S110>/Saturation1' */
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

        /* End of Saturate: '<S110>/Saturation1' */

        /* Saturate: '<S82>/Saturation1' */
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

        /* End of Saturate: '<S82>/Saturation1' */
        /* End of Outputs for SubSystem: '<S34>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S34>/Unknown' incorporates:
         *  ActionPort: '<S43>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S31>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

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
      FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

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
   *  DiscreteIntegrator: '<S451>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S451>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S451>/Constant'
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

  /* Update for DiscreteIntegrator: '<S466>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S466>/Gain'
   *  Sum: '<S466>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_o[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_o[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_o[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S468>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S468>/Gain'
   *  Sum: '<S468>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S467>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S467>/Gain'
   *  Sum: '<S467>/Sum5'
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
  rtb_DiscreteTimeIntegrator_n = (real32_T)
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)FMS_EXPORT.period;
  if (rtb_DiscreteTimeIntegrator_n < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)
      rtb_DiscreteTimeIntegrator_n;
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
  rtb_DiscreteTimeIntegrator_n = (real32_T)
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)FMS_EXPORT.period;
  if (rtb_DiscreteTimeIntegrator_n < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)
      rtb_DiscreteTimeIntegrator_n;
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
  /* Start for SwitchCase: '<S412>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S402>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S37>/Return' */

  /* Start for IfAction SubSystem: '<S37>/Hold' */
  /* Start for SwitchCase: '<S357>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S335>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S345>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S37>/Hold' */
  /* End of Start for SubSystem: '<S30>/SubMode' */

  /* Start for IfAction SubSystem: '<S30>/Auto' */
  /* Start for SwitchCase: '<S35>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S35>/Mission' */
  /* Start for Resettable SubSystem: '<S147>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S192>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S182>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S147>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S35>/Mission' */
  /* End of Start for SubSystem: '<S30>/Auto' */

  /* Start for IfAction SubSystem: '<S30>/Assist' */
  /* Start for SwitchCase: '<S34>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S34>/Stabilize' */
  /* Start for SwitchCase: '<S134>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S34>/Stabilize' */

  /* Start for IfAction SubSystem: '<S34>/Altitude' */
  /* Start for SwitchCase: '<S49>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S66>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S34>/Altitude' */

  /* Start for IfAction SubSystem: '<S34>/Position' */
  /* Start for SwitchCase: '<S82>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S110>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S97>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S34>/Position' */
  /* End of Start for SubSystem: '<S30>/Assist' */
  /* End of Start for SubSystem: '<S28>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S466>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S468>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S467>/Discrete-Time Integrator5' */
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
  /* InitializeConditions for Delay: '<S449>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* End of SystemInitialize for SubSystem: '<S37>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Return' */
  /* InitializeConditions for Delay: '<S398>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S439>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_p = 0.0F;

  /* InitializeConditions for Delay: '<S378>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for Delay: '<S379>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S382>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S413>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S412>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S412>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S412>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S412>/Move Control' */

  /* SystemInitialize for Merge: '<S412>/Merge' */
  FMS_B.Merge_mv[0] = 0.0F;
  FMS_B.Merge_mv[1] = 0.0F;

  /* SystemInitialize for Chart: '<S403>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S402>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S402>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S402>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S402>/Move Control' */

  /* SystemInitialize for Merge: '<S402>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Hold' */
  /* SystemInitialize for Chart: '<S336>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S346>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S358>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S357>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S357>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S357>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S357>/Move Control' */

  /* SystemInitialize for Merge: '<S357>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S335>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S335>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S335>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S335>/Move Control' */

  /* SystemInitialize for Merge: '<S335>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S345>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_kq);

  /* End of SystemInitialize for SubSystem: '<S345>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S345>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S345>/Move Control' */

  /* SystemInitialize for Merge: '<S345>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S30>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S30>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S35>/Mission' */
  /* InitializeConditions for UnitDelay: '<S150>/Delay Input1'
   *
   * Block description for '<S150>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S147>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S175>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S219>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S155>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S193>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S192>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S192>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S192>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S192>/Move Control' */

  /* SystemInitialize for Merge: '<S192>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S183>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S182>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S182>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S182>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S182>/Move Control' */

  /* SystemInitialize for Merge: '<S182>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S147>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S35>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S30>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S30>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S34>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S130>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S130>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S131>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jt = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S131>/Integrator' */
  FMS_DW.Integrator_DSTATE_cq = 0.0F;

  /* SystemInitialize for Chart: '<S135>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S134>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S134>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S134>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S134>/Move Control' */

  /* SystemInitialize for Merge: '<S134>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S34>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S34>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S62>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S62>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S63>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S63>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S50>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S49>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S49>/Hold Control' */

  /* SystemInitialize for Chart: '<S67>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S66>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S66>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S66>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_cr);

  /* End of SystemInitialize for SubSystem: '<S66>/Move Control' */

  /* SystemInitialize for Merge: '<S49>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Merge: '<S66>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S34>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S34>/Position' */
  /* SystemInitialize for Chart: '<S83>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for IfAction SubSystem: '<S82>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S82>/Hold Control' */

  /* SystemInitialize for Chart: '<S98>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S111>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S110>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S110>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S110>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S110>/Move Control' */

  /* SystemInitialize for Merge: '<S110>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S82>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S97>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S97>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S97>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_mr);

  /* End of SystemInitialize for SubSystem: '<S97>/Move Control' */

  /* SystemInitialize for Merge: '<S97>/Merge' */
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
