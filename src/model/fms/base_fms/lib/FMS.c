/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1722
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Apr 26 07:59:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S279>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S289>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

/* Named constants for Chart: '<S118>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S37>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S223>/Motion State' */
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
                                        *   '<S328>/Constant'
                                        *   '<S130>/L1'
                                        *   '<S206>/L1'
                                        *   '<S34>/Gain'
                                        *   '<S34>/Gain1'
                                        *   '<S108>/Gain'
                                        *   '<S108>/Gain1'
                                        *   '<S247>/Saturation1'
                                        *   '<S320>/Gain2'
                                        *   '<S320>/Saturation1'
                                        *   '<S36>/Saturation1'
                                        *   '<S47>/Dead Zone'
                                        *   '<S47>/Gain'
                                        *   '<S48>/Dead Zone'
                                        *   '<S48>/Gain'
                                        *   '<S53>/Saturation'
                                        *   '<S69>/Saturation1'
                                        *   '<S80>/Saturation'
                                        *   '<S93>/Saturation1'
                                        *   '<S111>/Dead Zone'
                                        *   '<S111>/Gain'
                                        *   '<S112>/Dead Zone'
                                        *   '<S112>/Gain'
                                        *   '<S117>/Saturation'
                                        *   '<S151>/Gain'
                                        *   '<S151>/Saturation1'
                                        *   '<S152>/vel'
                                        *   '<S152>/Saturation'
                                        *   '<S152>/Switch'
                                        *   '<S212>/Saturation1'
                                        *   '<S222>/Saturation'
                                        *   '<S234>/Saturation1'
                                        *   '<S248>/Gain2'
                                        *   '<S270>/vel'
                                        *   '<S270>/Saturation'
                                        *   '<S270>/Switch'
                                        *   '<S39>/Gain2'
                                        *   '<S40>/Gain1'
                                        *   '<S45>/Constant'
                                        *   '<S56>/Gain2'
                                        *   '<S57>/Gain1'
                                        *   '<S64>/Constant'
                                        *   '<S72>/Gain2'
                                        *   '<S73>/Gain1'
                                        *   '<S78>/Constant'
                                        *   '<S83>/Gain2'
                                        *   '<S84>/Gain1'
                                        *   '<S91>/Constant'
                                        *   '<S96>/Gain2'
                                        *   '<S97>/Gain6'
                                        *   '<S105>/Constant'
                                        *   '<S106>/Constant'
                                        *   '<S120>/Gain2'
                                        *   '<S121>/Gain1'
                                        *   '<S128>/Constant'
                                        *   '<S138>/Gain2'
                                        *   '<S138>/Saturation'
                                        *   '<S139>/Integrator'
                                        *   '<S215>/Gain2'
                                        *   '<S216>/Gain1'
                                        *   '<S225>/Gain2'
                                        *   '<S226>/Gain1'
                                        *   '<S237>/Gain2'
                                        *   '<S238>/Gain6'
                                        *   '<S257>/Gain2'
                                        *   '<S257>/Saturation'
                                        *   '<S258>/Integrator'
                                        *   '<S42>/Dead Zone'
                                        *   '<S42>/Gain'
                                        *   '<S61>/Dead Zone'
                                        *   '<S61>/Gain'
                                        *   '<S75>/Dead Zone'
                                        *   '<S75>/Gain'
                                        *   '<S88>/Dead Zone'
                                        *   '<S88>/Gain'
                                        *   '<S101>/Dead Zone'
                                        *   '<S101>/Gain'
                                        *   '<S102>/Dead Zone'
                                        *   '<S102>/Gain'
                                        *   '<S125>/Dead Zone'
                                        *   '<S125>/Gain'
                                        *   '<S163>/Saturation1'
                                        *   '<S173>/Saturation1'
                                        *   '<S218>/Dead Zone'
                                        *   '<S218>/Gain'
                                        *   '<S230>/Dead Zone'
                                        *   '<S230>/Gain'
                                        *   '<S242>/Dead Zone'
                                        *   '<S242>/Gain'
                                        *   '<S243>/Dead Zone'
                                        *   '<S243>/Gain'
                                        *   '<S278>/Saturation1'
                                        *   '<S288>/Saturation1'
                                        *   '<S166>/Gain2'
                                        *   '<S167>/Gain1'
                                        *   '<S176>/Gain2'
                                        *   '<S177>/Gain6'
                                        *   '<S281>/Gain2'
                                        *   '<S282>/Gain1'
                                        *   '<S291>/Gain2'
                                        *   '<S292>/Gain6'
                                        *   '<S169>/Dead Zone'
                                        *   '<S169>/Gain'
                                        *   '<S181>/Dead Zone'
                                        *   '<S181>/Gain'
                                        *   '<S182>/Dead Zone'
                                        *   '<S182>/Gain'
                                        *   '<S284>/Dead Zone'
                                        *   '<S284>/Gain'
                                        *   '<S296>/Dead Zone'
                                        *   '<S296>/Gain'
                                        *   '<S297>/Dead Zone'
                                        *   '<S297>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 48, 46, 51, 46, 54, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S7>/Constant1'
                                        *   '<S20>/Constant'
                                        */

/* Block signals (default storage) */
B_FMS_T FMS_B;

/* Block states (default storage) */
DW_FMS_T FMS_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FMS_T FMS_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FMS_T FMS_Y;

/* Real-time model */
RT_MODEL_FMS_T FMS_M_;
RT_MODEL_FMS_T *const FMS_M = &FMS_M_;

/* Forward declaration for local functions */
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
static real_T FMS_getArmMode(PilotMode pilotMode);
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
 *    '<S2>/Disarm'
 *    '<S24>/Unknown'
 *    '<S22>/Unknown'
 *    '<S21>/Unknown'
 *    '<S17>/Unknown'
 */
void FMS_Disarm(FMS_Out_Bus *rty_FMS_Out, const ConstB_Disarm_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S18>/Bus Assignment' incorporates:
   *  Constant: '<S18>/Constant'
   *  Constant: '<S18>/Constant2'
   *  SignalConversion: '<S18>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S18>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S278>/Hold Control'
 *    '<S212>/Hold Control'
 *    '<S163>/Hold Control'
 *    '<S36>/Hold Control'
 *    '<S69>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S281>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S278>/Hold Control'
 *    '<S212>/Hold Control'
 *    '<S163>/Hold Control'
 *    '<S36>/Hold Control'
 *    '<S69>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S281>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S278>/Hold Control'
 *    '<S212>/Hold Control'
 *    '<S163>/Hold Control'
 *    '<S36>/Hold Control'
 *    '<S69>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S281>/Delay' incorporates:
   *  Gain: '<S283>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S281>/Gain2' incorporates:
   *  Delay: '<S281>/Delay'
   *  Gain: '<S283>/Gain'
   *  Sum: '<S281>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S281>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S278>/Brake Control'
 *    '<S212>/Brake Control'
 *    '<S222>/Brake Control'
 *    '<S163>/Brake Control'
 *    '<S117>/Brake Control'
 *    '<S36>/Brake Control'
 *    '<S53>/Brake Control'
 *    '<S69>/Brake Control'
 *    '<S80>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S280>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S280>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S278>/Move Control'
 *    '<S212>/Move Control'
 *    '<S163>/Move Control'
 *    '<S36>/Move Control'
 *    '<S69>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S285>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S285>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S278>/Move Control'
 *    '<S212>/Move Control'
 *    '<S163>/Move Control'
 *    '<S36>/Move Control'
 *    '<S69>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S285>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S285>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S278>/Move Control'
 *    '<S212>/Move Control'
 *    '<S163>/Move Control'
 *    '<S36>/Move Control'
 *    '<S69>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3;
  real32_T rtb_Subtract3_dn;
  real32_T rtb_a_hr;
  real32_T rtb_Add4_g;
  real32_T rtb_a_b;

  /* Product: '<S286>/Multiply1' incorporates:
   *  Constant: '<S286>/const1'
   *  DiscreteIntegrator: '<S285>/Integrator'
   */
  rtb_Add3 = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S284>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = 0.0F;
  } else {
    rtb_a_hr = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S284>/Dead Zone' */

  /* Sum: '<S286>/Add' incorporates:
   *  DiscreteIntegrator: '<S285>/Integrator1'
   *  Gain: '<S282>/Gain1'
   *  Gain: '<S284>/Gain'
   *  Sum: '<S285>/Subtract'
   */
  rtb_Subtract3_dn = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_hr * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3;

  /* Signum: '<S286>/Sign' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_a_hr = -1.0F;
  } else if (rtb_Subtract3_dn > 0.0F) {
    rtb_a_hr = 1.0F;
  } else {
    rtb_a_hr = rtb_Subtract3_dn;
  }

  /* End of Signum: '<S286>/Sign' */

  /* Sum: '<S286>/Add2' incorporates:
   *  Abs: '<S286>/Abs'
   *  Gain: '<S286>/Gain'
   *  Gain: '<S286>/Gain1'
   *  Product: '<S286>/Multiply2'
   *  Product: '<S286>/Multiply3'
   *  Sqrt: '<S286>/Sqrt'
   *  Sum: '<S286>/Add1'
   *  Sum: '<S286>/Subtract'
   */
  rtb_a_hr = (sqrtf((8.0F * fabsf(rtb_Subtract3_dn) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_hr + rtb_Add3;

  /* Sum: '<S286>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_dn - rtb_a_hr) + rtb_Add3;

  /* Sum: '<S286>/Add3' */
  rtb_Add3 = rtb_Subtract3_dn + localC->d;

  /* Sum: '<S286>/Subtract1' */
  rtb_Subtract3_dn -= localC->d;

  /* Signum: '<S286>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S286>/Sign1' */

  /* Signum: '<S286>/Sign2' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S286>/Sign2' */

  /* Sum: '<S286>/Add5' incorporates:
   *  Gain: '<S286>/Gain2'
   *  Product: '<S286>/Multiply4'
   *  Sum: '<S286>/Subtract2'
   */
  rtb_a_hr += (rtb_Add3 - rtb_Subtract3_dn) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S282>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S285>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S285>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S285>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S286>/Add6' */
  rtb_Add3 = rtb_a_hr + localC->d;

  /* Sum: '<S286>/Subtract3' */
  rtb_Subtract3_dn = rtb_a_hr - localC->d;

  /* Signum: '<S286>/Sign5' */
  if (rtb_a_hr < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_hr;
  }

  /* End of Signum: '<S286>/Sign5' */

  /* Signum: '<S286>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S286>/Sign3' */

  /* Signum: '<S286>/Sign4' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S286>/Sign4' */

  /* Signum: '<S286>/Sign6' */
  if (rtb_a_hr < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_a_hr;
  }

  /* End of Signum: '<S286>/Sign6' */

  /* Update for DiscreteIntegrator: '<S285>/Integrator' incorporates:
   *  Constant: '<S286>/const'
   *  Gain: '<S286>/Gain3'
   *  Product: '<S286>/Divide'
   *  Product: '<S286>/Multiply5'
   *  Product: '<S286>/Multiply6'
   *  Sum: '<S286>/Subtract4'
   *  Sum: '<S286>/Subtract5'
   *  Sum: '<S286>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_hr / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3 - rtb_Subtract3_dn) * 0.5F) - rtb_a_b * 78.448F) *
    0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S279>/Motion Status'
 *    '<S213>/Motion Status'
 *    '<S164>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S279>/Motion Status'
 *    '<S213>/Motion Status'
 *    '<S164>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S279>/Motion Status'
 *    '<S213>/Motion Status'
 *    '<S164>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S279>/Motion Status' */
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

  /* End of Chart: '<S279>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S288>/Hold Control'
 *    '<S234>/Hold Control'
 *    '<S173>/Hold Control'
 *    '<S93>/Hold Control'
 */
void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S291>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S288>/Hold Control'
 *    '<S234>/Hold Control'
 *    '<S173>/Hold Control'
 *    '<S93>/Hold Control'
 */
void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S291>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S288>/Hold Control'
 *    '<S234>/Hold Control'
 *    '<S173>/Hold Control'
 *    '<S93>/Hold Control'
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

  /* Delay: '<S291>/Delay' incorporates:
   *  SignalConversion: '<S291>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_p;
  }

  /* Trigonometry: '<S295>/Trigonometric Function1' incorporates:
   *  Gain: '<S294>/Gain'
   *  Trigonometry: '<S295>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_b_tmp_0 = arm_cos_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_b_tmp_0;

  /* Trigonometry: '<S295>/Trigonometric Function' incorporates:
   *  Gain: '<S294>/Gain'
   *  Trigonometry: '<S295>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_b_tmp = arm_sin_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_b_tmp;

  /* SignalConversion: '<S295>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S295>/Constant3'
   */
  rtb_VectorConcatenate_k[2] = 0.0F;

  /* Gain: '<S295>/Gain' */
  rtb_VectorConcatenate_k[3] = -rtb_VectorConcatenate_b_tmp;

  /* Trigonometry: '<S295>/Trigonometric Function3' */
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_b_tmp_0;

  /* SignalConversion: '<S295>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S295>/Constant4'
   */
  rtb_VectorConcatenate_k[5] = 0.0F;

  /* SignalConversion: '<S295>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_k[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_k[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_k[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S291>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S291>/Delay'
   *  SignalConversion: '<S291>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S291>/Sum'
   */
  rtb_VectorConcatenate_b_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_b_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_p;

  /* Product: '<S291>/Multiply' incorporates:
   *  SignalConversion: '<S291>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_b[i] = rtb_VectorConcatenate_k[i + 3] *
      rtb_VectorConcatenate_b_tmp + rtb_VectorConcatenate_k[i] *
      rtb_VectorConcatenate_b_tmp_0;
  }

  /* End of Product: '<S291>/Multiply' */

  /* Gain: '<S291>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_b[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_b[1];

  /* Update for Delay: '<S291>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S288>/Brake Control'
 *    '<S234>/Brake Control'
 *    '<S173>/Brake Control'
 *    '<S93>/Brake Control'
 */
void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S290>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S288>/Move Control'
 *    '<S234>/Move Control'
 *    '<S173>/Move Control'
 *    '<S93>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S298>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S298>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S298>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S298>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S288>/Move Control'
 *    '<S234>/Move Control'
 *    '<S173>/Move Control'
 *    '<S93>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S298>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S298>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S298>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S298>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S288>/Move Control'
 *    '<S234>/Move Control'
 *    '<S173>/Move Control'
 *    '<S93>/Move Control'
 */
void FMS_MoveControl_o(real32_T rtu_FMS_In, real32_T rtu_FMS_In_g, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_k_T *localC,
  DW_MoveControl_FMS_d_T *localDW)
{
  real32_T rtb_Subtract3_nv;
  real32_T rtb_Add3_e_idx_0;
  real32_T rtb_Subtract3_h_idx_0;
  real32_T rtb_Add3_e_idx_1;
  real32_T rtb_Subtract3_h_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_h_idx_0_0;

  /* SignalConversion: '<S292>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S298>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S299>/Multiply1' incorporates:
   *  Constant: '<S299>/const1'
   *  DiscreteIntegrator: '<S298>/Integrator'
   */
  rtb_Add3_e_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S292>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S298>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S299>/Multiply1' incorporates:
   *  Constant: '<S299>/const1'
   *  DiscreteIntegrator: '<S298>/Integrator'
   */
  rtb_Add3_e_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S296>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S296>/Dead Zone' */

  /* Sum: '<S299>/Add' incorporates:
   *  DiscreteIntegrator: '<S298>/Integrator1'
   *  Gain: '<S292>/Gain6'
   *  Gain: '<S296>/Gain'
   *  Sum: '<S298>/Subtract'
   */
  rtb_Subtract3_h_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e_idx_0;

  /* DeadZone: '<S297>/Dead Zone' */
  if (rtu_FMS_In_g > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_g >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S297>/Dead Zone' */

  /* Sum: '<S299>/Add' incorporates:
   *  DiscreteIntegrator: '<S298>/Integrator1'
   *  Gain: '<S292>/Gain6'
   *  Gain: '<S297>/Gain'
   *  Sum: '<S298>/Subtract'
   */
  rtb_Subtract3_h_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e_idx_1;

  /* Signum: '<S299>/Sign' */
  if (rtb_Subtract3_h_idx_0 < 0.0F) {
    rtb_Subtract3_h_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0 > 0.0F) {
    rtb_Subtract3_h_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0_0 = rtb_Subtract3_h_idx_0;
  }

  /* Sum: '<S299>/Add2' incorporates:
   *  Abs: '<S299>/Abs'
   *  Gain: '<S299>/Gain'
   *  Gain: '<S299>/Gain1'
   *  Product: '<S299>/Multiply2'
   *  Product: '<S299>/Multiply3'
   *  Signum: '<S299>/Sign'
   *  Sqrt: '<S299>/Sqrt'
   *  Sum: '<S299>/Add1'
   *  Sum: '<S299>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_h_idx_0_0 +
    rtb_Add3_e_idx_0;

  /* Sum: '<S299>/Add3' incorporates:
   *  Signum: '<S299>/Sign'
   */
  u = rtb_Subtract3_h_idx_0 + localC->d;

  /* Sum: '<S299>/Subtract1' incorporates:
   *  Signum: '<S299>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_0 - localC->d;

  /* Signum: '<S299>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S299>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S299>/Add5' incorporates:
   *  Gain: '<S299>/Gain2'
   *  Product: '<S299>/Multiply4'
   *  Signum: '<S299>/Sign'
   *  Sum: '<S299>/Add2'
   *  Sum: '<S299>/Add4'
   *  Sum: '<S299>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_0 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e_idx_0) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S298>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S298>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S299>/Sign3' incorporates:
   *  Sum: '<S299>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S299>/Sign4' incorporates:
   *  Sum: '<S299>/Subtract3'
   */
  rtb_Add3_e_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S299>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S299>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S299>/Sign4' */
  if (rtb_Add3_e_idx_0 < 0.0F) {
    rtb_Add3_e_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e_idx_0 > 0.0F) {
      rtb_Add3_e_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S299>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S298>/Integrator' incorporates:
   *  Constant: '<S299>/const'
   *  Gain: '<S299>/Gain3'
   *  Product: '<S299>/Divide'
   *  Product: '<S299>/Multiply5'
   *  Product: '<S299>/Multiply6'
   *  Sum: '<S299>/Subtract4'
   *  Sum: '<S299>/Subtract5'
   *  Sum: '<S299>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;

  /* Signum: '<S299>/Sign' */
  if (rtb_Subtract3_h_idx_1 < 0.0F) {
    rtb_Add3_e_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_1 > 0.0F) {
    rtb_Add3_e_idx_0 = 1.0F;
  } else {
    rtb_Add3_e_idx_0 = rtb_Subtract3_h_idx_1;
  }

  /* Sum: '<S299>/Add2' incorporates:
   *  Abs: '<S299>/Abs'
   *  Gain: '<S299>/Gain'
   *  Gain: '<S299>/Gain1'
   *  Product: '<S299>/Multiply2'
   *  Product: '<S299>/Multiply3'
   *  Signum: '<S299>/Sign'
   *  Sqrt: '<S299>/Sqrt'
   *  Sum: '<S299>/Add1'
   *  Sum: '<S299>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_e_idx_0 +
    rtb_Add3_e_idx_1;

  /* Sum: '<S299>/Add3' incorporates:
   *  Signum: '<S299>/Sign'
   */
  u = rtb_Subtract3_h_idx_1 + localC->d;

  /* Sum: '<S299>/Subtract1' incorporates:
   *  Signum: '<S299>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_1 - localC->d;

  /* Signum: '<S299>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S299>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S299>/Add5' incorporates:
   *  Gain: '<S299>/Gain2'
   *  Product: '<S299>/Multiply4'
   *  Signum: '<S299>/Sign'
   *  Sum: '<S299>/Add2'
   *  Sum: '<S299>/Add4'
   *  Sum: '<S299>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_1 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e_idx_1) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S298>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S298>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S299>/Sign3' incorporates:
   *  Sum: '<S299>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S299>/Sign4' incorporates:
   *  Sum: '<S299>/Subtract3'
   */
  rtb_Add3_e_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S299>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S299>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S299>/Sign4' */
  if (rtb_Add3_e_idx_0 < 0.0F) {
    rtb_Add3_e_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e_idx_0 > 0.0F) {
      rtb_Add3_e_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S299>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S298>/Integrator' incorporates:
   *  Constant: '<S299>/const'
   *  Gain: '<S299>/Gain3'
   *  Product: '<S299>/Divide'
   *  Product: '<S299>/Multiply5'
   *  Product: '<S299>/Multiply6'
   *  Sum: '<S299>/Subtract4'
   *  Sum: '<S299>/Subtract5'
   *  Sum: '<S299>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S289>/Motion State'
 *    '<S235>/Motion State'
 *    '<S174>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * System reset for atomic system:
 *    '<S289>/Motion State'
 *    '<S235>/Motion State'
 *    '<S174>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * Output and update for atomic system:
 *    '<S289>/Motion State'
 *    '<S235>/Motion State'
 *    '<S174>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S289>/Motion State' */
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

  /* End of Chart: '<S289>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S272>/NearbyRefWP'
 *    '<S154>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S303>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S222>/Hold Control'
 *    '<S117>/Hold Control'
 *    '<S53>/Hold Control'
 *    '<S80>/Hold Control'
 */
void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S225>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S222>/Hold Control'
 *    '<S117>/Hold Control'
 *    '<S53>/Hold Control'
 *    '<S80>/Hold Control'
 */
void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S225>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S222>/Hold Control'
 *    '<S117>/Hold Control'
 *    '<S53>/Hold Control'
 *    '<S80>/Hold Control'
 */
void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S225>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S225>/Sum' incorporates:
   *  Delay: '<S225>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S228>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S228>/Switch' incorporates:
   *  Constant: '<S228>/Constant'
   *  Constant: '<S229>/Constant'
   *  Product: '<S228>/Multiply'
   *  RelationalOperator: '<S229>/Compare'
   *  Sum: '<S228>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S228>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S228>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S228>/Switch' */

  /* Gain: '<S225>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S225>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S222>/Move Control'
 *    '<S117>/Move Control'
 *    '<S53>/Move Control'
 *    '<S80>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S222>/Move Control'
 *    '<S117>/Move Control'
 *    '<S53>/Move Control'
 *    '<S80>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S222>/Move Control'
 *    '<S117>/Move Control'
 *    '<S53>/Move Control'
 *    '<S80>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3;
  real32_T rtb_Subtract3_i;
  real32_T rtb_a_b;
  real32_T rtb_Add4_bf;
  real32_T rtb_a_p;

  /* Product: '<S232>/Multiply1' incorporates:
   *  Constant: '<S232>/const1'
   *  DiscreteIntegrator: '<S231>/Integrator'
   */
  rtb_Add3 = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S230>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_b = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_b = 0.0F;
  } else {
    rtb_a_b = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S230>/Dead Zone' */

  /* Sum: '<S232>/Add' incorporates:
   *  DiscreteIntegrator: '<S231>/Integrator1'
   *  Gain: '<S226>/Gain1'
   *  Gain: '<S230>/Gain'
   *  Sum: '<S231>/Subtract'
   */
  rtb_Subtract3_i = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_b * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3;

  /* Signum: '<S232>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_Subtract3_i;
  }

  /* End of Signum: '<S232>/Sign' */

  /* Sum: '<S232>/Add2' incorporates:
   *  Abs: '<S232>/Abs'
   *  Gain: '<S232>/Gain'
   *  Gain: '<S232>/Gain1'
   *  Product: '<S232>/Multiply2'
   *  Product: '<S232>/Multiply3'
   *  Sqrt: '<S232>/Sqrt'
   *  Sum: '<S232>/Add1'
   *  Sum: '<S232>/Subtract'
   */
  rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_b + rtb_Add3;

  /* Sum: '<S232>/Add4' */
  rtb_Add4_bf = (rtb_Subtract3_i - rtb_a_b) + rtb_Add3;

  /* Sum: '<S232>/Add3' */
  rtb_Add3 = rtb_Subtract3_i + localC->d;

  /* Sum: '<S232>/Subtract1' */
  rtb_Subtract3_i -= localC->d;

  /* Signum: '<S232>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S232>/Sign1' */

  /* Signum: '<S232>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S232>/Sign2' */

  /* Sum: '<S232>/Add5' incorporates:
   *  Gain: '<S232>/Gain2'
   *  Product: '<S232>/Multiply4'
   *  Sum: '<S232>/Subtract2'
   */
  rtb_a_b += (rtb_Add3 - rtb_Subtract3_i) * 0.5F * rtb_Add4_bf;

  /* SignalConversion: '<S226>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S231>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S231>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S231>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S232>/Add6' */
  rtb_Add3 = rtb_a_b + localC->d;

  /* Sum: '<S232>/Subtract3' */
  rtb_Subtract3_i = rtb_a_b - localC->d;

  /* Signum: '<S232>/Sign5' */
  if (rtb_a_b < 0.0F) {
    rtb_Add4_bf = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_Add4_bf = 1.0F;
  } else {
    rtb_Add4_bf = rtb_a_b;
  }

  /* End of Signum: '<S232>/Sign5' */

  /* Signum: '<S232>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S232>/Sign3' */

  /* Signum: '<S232>/Sign4' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S232>/Sign4' */

  /* Signum: '<S232>/Sign6' */
  if (rtb_a_b < 0.0F) {
    rtb_a_p = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_a_p = 1.0F;
  } else {
    rtb_a_p = rtb_a_b;
  }

  /* End of Signum: '<S232>/Sign6' */

  /* Update for DiscreteIntegrator: '<S231>/Integrator' incorporates:
   *  Constant: '<S232>/const'
   *  Gain: '<S232>/Gain3'
   *  Product: '<S232>/Divide'
   *  Product: '<S232>/Multiply5'
   *  Product: '<S232>/Multiply6'
   *  Sum: '<S232>/Subtract4'
   *  Sum: '<S232>/Subtract5'
   *  Sum: '<S232>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_b / localC->d - rtb_Add4_bf) *
    localC->Gain4 * ((rtb_Add3 - rtb_Subtract3_i) * 0.5F) - rtb_a_p * 15.707963F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S118>/Motion State'
 *    '<S54>/Motion State'
 *    '<S81>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S118>/Motion State'
 *    '<S54>/Motion State'
 *    '<S81>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S118>/Motion State'
 *    '<S54>/Motion State'
 *    '<S81>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S118>/Motion State' */
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

  /* End of Chart: '<S118>/Motion State' */
}

/*
 * System initialize for atomic system:
 *    '<S37>/Motion Status'
 *    '<S70>/Motion Status'
 */
void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S37>/Motion Status'
 *    '<S70>/Motion Status'
 */
void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S37>/Motion Status'
 *    '<S70>/Motion Status'
 */
void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW)
{
  /* Chart: '<S37>/Motion Status' */
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

  /* End of Chart: '<S37>/Motion Status' */
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
  real_T rtb_Sum2_m;
  real_T rtb_Gain_d;
  real_T rtb_Sum3;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S330>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S331>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S331>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S331>/Multiply1' incorporates:
   *  Product: '<S331>/Multiply'
   */
  rtb_Gain_d = localC->ff * rtb_Sum2_m;

  /* Product: '<S331>/Divide' incorporates:
   *  Constant: '<S331>/Constant'
   *  Constant: '<S331>/R'
   *  Sqrt: '<S331>/Sqrt'
   *  Sum: '<S331>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_d);

  /* Product: '<S331>/Product3' incorporates:
   *  Constant: '<S331>/Constant1'
   *  Product: '<S331>/Multiply1'
   *  Sum: '<S331>/Sum2'
   */
  rtb_Gain_d = 1.0 / (1.0 - rtb_Gain_d) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S331>/Multiply2' incorporates:
   *  Trigonometry: '<S331>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S330>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S335>/Abs' incorporates:
   *  Abs: '<S338>/Abs1'
   *  Switch: '<S335>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S335>/Switch1' incorporates:
   *  Abs: '<S335>/Abs'
   *  Bias: '<S335>/Bias2'
   *  Bias: '<S335>/Bias3'
   *  Constant: '<S332>/Constant'
   *  Constant: '<S332>/Constant1'
   *  Constant: '<S337>/Constant'
   *  Gain: '<S335>/Gain1'
   *  Product: '<S335>/Multiply'
   *  RelationalOperator: '<S337>/Compare'
   *  Switch: '<S332>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S338>/Switch1' incorporates:
     *  Bias: '<S338>/Bias2'
     *  Bias: '<S338>/Bias3'
     *  Constant: '<S338>/Constant'
     *  Constant: '<S339>/Constant'
     *  Math: '<S338>/Math Function'
     *  RelationalOperator: '<S339>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S338>/Switch1' */

    /* Signum: '<S335>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S335>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S332>/Sum' incorporates:
   *  Sum: '<S330>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S330>/Multiply' incorporates:
   *  Gain: '<S330>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_d;

  /* Switch: '<S334>/Switch1' incorporates:
   *  Abs: '<S334>/Abs1'
   *  Bias: '<S334>/Bias2'
   *  Bias: '<S334>/Bias3'
   *  Constant: '<S334>/Constant'
   *  Constant: '<S336>/Constant'
   *  Math: '<S334>/Math Function'
   *  RelationalOperator: '<S336>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S334>/Switch1' */

  /* Product: '<S330>/Multiply' incorporates:
   *  Gain: '<S330>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

  /* Gain: '<S330>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S333>/SinCos' */
  rtb_Sum3 = sin(rtb_Sum2_m);
  rtb_Gain_d = cos(rtb_Sum2_m);

  /* Sum: '<S333>/Sum2' incorporates:
   *  Product: '<S333>/Multiply1'
   *  Product: '<S333>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_d + rtb_Sum_d * rtb_Sum3;

  /* Product: '<S333>/Multiply3' */
  rtb_Sum3 *= rtb_Sum_e_idx_0;

  /* Product: '<S333>/Multiply4' */
  rtb_Gain_d *= rtb_Sum_d;

  /* Sum: '<S333>/Sum3' */
  rtb_Sum3 = rtb_Gain_d - rtb_Sum3;

  /* DataTypeConversion: '<S327>/Data Type Conversion' incorporates:
   *  Gain: '<S330>/Gain'
   *  Sum: '<S330>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_m;
  rty_pos[1] = (real32_T)rtb_Sum3;
  rty_pos[2] = (real32_T)-(rtu_lla[2] + rtu_href);
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
static void FMS_enter_internal_Arm(void)
{
  uint32_T qY;
  real_T tmp;
  tmp = FMS_getArmMode(FMS_B.target_mode);
  if (tmp == 3.0) {
    FMS_DW.is_Arm = FMS_IN_Auto;
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
  uint32_T qY_tmp;
  FMS_B.stick_val[0] = FMS_DW.stick_val[0];
  FMS_B.stick_val[1] = FMS_DW.stick_val[1];
  FMS_B.stick_val[2] = FMS_DW.stick_val[2];
  FMS_B.stick_val[3] = FMS_DW.stick_val[3];
  FMS_B.pilot_cmd = FMS_B.BusConversion_InsertedFor_FMS_f;

  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S340>/Compare' incorporates:
   *  Abs: '<S329>/Abs'
   *  Constant: '<S340>/Constant'
   *  MinMax: '<S329>/Max'
   *  Sum: '<S329>/Sum'
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
          qY_tmp = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
          if (qY_tmp > FMS_B.wp_index) {
            qY_tmp = 0U;
          }

          FMS_B.wp_consume = (uint8_T)qY_tmp;
        }
        break;

       default:
        FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
        break;
      }
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
        if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d))
        {
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.LogicalOperator1;
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
          FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.LogicalOperator1;
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
                  qY_tmp = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
                  if (qY_tmp > FMS_B.wp_index) {
                    qY_tmp = 0U;
                  }

                  FMS_B.wp_consume = (uint8_T)qY_tmp;
                }
                break;

               default:
                FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
                break;
              }
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
  real32_T tmp[2];
  uint32_T qY;
  int32_T tmp_0;
  boolean_T tmp_1;
  real_T tmp_2;
  tmp_1 = !FMS_B.LogicalOperator1;
  if (tmp_1 || (!FMS_DW.condWasTrueAtLastTimeStep_1_d0)) {
    FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_B.LogicalOperator1;
  if ((FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_c >=
       500) && (FMS_B.target_mode != PilotMode_Mission)) {
    FMS_exit_internal_Arm();
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.target_mode !=
              PilotMode_None)) {
    tmp_2 = FMS_getArmMode(FMS_B.target_mode);
    if (tmp_2 == 3.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Auto;
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
        break;

       default:
        FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
        break;
      }
    } else if (tmp_2 == 2.0) {
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
    } else if (tmp_2 == 1.0) {
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
      FMS_B.Cmd_In.sp_land[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.sp_land[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_SubMode = FMS_IN_Land;
      FMS_B.state = VehicleState_Land;
      FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.LogicalOperator1;
    } else {
      if (FMS_sf_msg_pop_M()) {
        c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
          FMS_Cmd_Return);
      } else {
        c_sf_internal_predicateOutput = false;
      }

      if (c_sf_internal_predicateOutput) {
        FMS_B.Cmd_In.sp_return[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_return[1] = FMS_DW.home[1];
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
          if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
            FMS_DW.is_Vehicle = FMS_IN_Disarm;
            FMS_B.state = VehicleState_Disarm;
          }
          break;

         case FMS_IN_Auto:
          if (FMS_sf_msg_pop_M()) {
            c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Pause);
          } else {
            c_sf_internal_predicateOutput = false;
          }

          if (c_sf_internal_predicateOutput) {
            FMS_exit_internal_Auto();
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
            switch (FMS_DW.is_Auto) {
             case FMS_IN_InvalidAutoMode:
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_h;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.state = VehicleState_Disarm;
              break;

             case FMS_IN_Mission:
              if (FMS_DW.mission_timestamp_prev !=
                  FMS_DW.mission_timestamp_start) {
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
                  if (tmp_1 || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
                    FMS_DW.durationLastReferenceTick_1 =
                      FMS_DW.chartAbsoluteTimeCounter;
                  }

                  FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
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
                      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index
                        - 1];
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
                    FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index -
                      1] * 1.0E-7;
                    FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index -
                      1] * 1.0E-7;
                    FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] +
                                     FMS_DW.home[2]);
                    FMS_B.llo[0] = FMS_DW.llo[0];
                    FMS_B.llo[1] = FMS_DW.llo[1];
                    FMS_B.href = 0.0;
                    FMS_B.psio = 0.0;

                    /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo,
                      FMS_B.href, FMS_B.psio, FMS_B.DataTypeConversion,
                      &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

                    /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    FMS_B.Cmd_In.sp_takeoff[0] = FMS_B.DataTypeConversion[0];
                    FMS_B.Cmd_In.sp_takeoff[1] = FMS_B.DataTypeConversion[1];
                    FMS_B.Cmd_In.sp_takeoff[2] = FMS_B.DataTypeConversion[2];
                    FMS_B.state = VehicleState_Takeoff;
                  } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Waypoint) {
                    FMS_DW.is_Mission = FMS_IN_Waypoint;

                    /* Inport: '<Root>/Mission_Data' */
                    FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index -
                      1] * 1.0E-7;
                    FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index -
                      1] * 1.0E-7;
                    FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] +
                                     FMS_DW.home[2]);
                    FMS_B.llo[0] = FMS_DW.llo[0];
                    FMS_B.llo[1] = FMS_DW.llo[1];
                    FMS_B.href = 0.0;
                    FMS_B.psio = 0.0;

                    /* Outputs for Function Call SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo,
                      FMS_B.href, FMS_B.psio, FMS_B.DataTypeConversion,
                      &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

                    /* End of Outputs for SubSystem: '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
                    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
                    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
                    FMS_B.state = VehicleState_Mission;
                  } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Land) {
                    FMS_DW.durationLastReferenceTick_1 =
                      FMS_DW.chartAbsoluteTimeCounter;
                    FMS_DW.is_Mission = FMS_IN_Land;
                    FMS_B.Cmd_In.sp_land[0] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
                    FMS_B.Cmd_In.sp_land[1] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
                    FMS_B.state = VehicleState_Land;
                    FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
                  } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
                    FMS_DW.is_Mission = FMS_IN_Return_h;
                    FMS_B.Cmd_In.sp_return[0] = FMS_DW.home[0];
                    FMS_B.Cmd_In.sp_return[1] = FMS_DW.home[1];
                    FMS_B.state = VehicleState_Return;
                  } else if (FMS_B.LogicalOperator1) {
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
                    FMS_DW.durationLastReferenceTick_1 =
                      FMS_DW.chartAbsoluteTimeCounter;
                    FMS_DW.is_Mission = FMS_IN_Land;
                    FMS_B.Cmd_In.sp_land[0] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
                    FMS_B.Cmd_In.sp_land[1] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
                    FMS_B.state = VehicleState_Land;
                    FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
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
                      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index
                        - 1];
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
                    FMS_B.state = VehicleState_Hold;
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
                      FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index
                        - 1];
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
  boolean_T guard4 = false;
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
      if ((FMS_ManualArmEvent
           (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
            FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
          (FMS_B.target_mode != PilotMode_None)) {
        guard2 = true;
      } else {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_k >= 500) {
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
                (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
              FMS_DW.durationLastReferenceTick_1_k =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
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

      /* Outputs for Function Call SubSystem: '<S4>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S328>/Reshape' incorporates:
       *  Constant: '<S328>/Constant'
       */
      FMS_B.Reshape[0] = FMS_B.xy_R[0];
      FMS_B.Reshape[1] = FMS_B.xy_R[1];
      FMS_B.Reshape[2] = FMS_PARAM.TAKEOFF_H;

      /* End of Outputs for SubSystem: '<S4>/Vehicle.PrepTakeoff' */
      FMS_B.Cmd_In.sp_takeoff[0] = FMS_B.Reshape[0];
      FMS_B.Cmd_In.sp_takeoff[1] = FMS_B.Reshape[1];
      FMS_B.Cmd_In.sp_takeoff[2] = FMS_B.Reshape[2];
      FMS_B.Cmd_In.sp_takeoff[2] += FMS_DW.home[2];
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
      FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;
      FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_B.LogicalOperator1;
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
      FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;
      FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_B.LogicalOperator1;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
      FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      guard4 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if ((FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          FMS_DW.prep_mission_takeoff = 1.0;
          FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff ==
            1.0);
          FMS_DW.prep_takeoff = 0.0;
          FMS_DW.condWasTrueAtLastTimeStep_1_k = (FMS_DW.prep_takeoff == 1.0);
          guard4 = true;
        } else {
          b_previousEvent = FMS_DW.sfEvent;
          FMS_DW.sfEvent = FMS_event_DisarmEvent;

          /* Chart: '<Root>/FMS State Machine' */
          FMS_c11_FMS();
          FMS_DW.sfEvent = b_previousEvent;
          if (FMS_DW.is_Vehicle != FMS_IN_Standby) {
          } else {
            guard4 = true;
          }
        }
      } else {
        guard4 = true;
      }

      if (guard4) {
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
  uint16_T rtb_Divide_b;
  int8_T rtPrevAction;
  real32_T rtb_Saturation_l;
  real32_T rtb_VectorConcatenate_m[9];
  real32_T rtb_Saturation1_ln[2];
  real32_T rtb_Sqrt_k0;
  MotionState rtb_state_a;
  real32_T rtb_Switch_l[3];
  real32_T rtb_Rem_k;
  real32_T rtb_Divide_o[2];
  real32_T rtb_Gain_a;
  real32_T rtb_Switch_k;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real32_T rtb_Divide;
  boolean_T rtb_LogicalOperator_at;
  real32_T rtb_TmpSignalConversionAtDela_a[2];
  int32_T i;
  real32_T rtb_VectorConcatenate_a[3];
  boolean_T u;
  real32_T rtb_MathFunction_cr_idx_1;
  real32_T rtb_MathFunction_cr_idx_0;
  real32_T rtb_MathFunction_iq_idx_1;
  real32_T rtb_MathFunction_iq_idx_0;
  real32_T rtb_MathFunction_h_idx_0;
  real32_T u1_tmp;
  boolean_T guard1 = false;

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0U;
  }

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  DataTypeConversion: '<S9>/Data Type Conversion2'
   *  Delay: '<S9>/Delay'
   *  DiscreteIntegrator: '<S7>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S9>/Logical Operator'
   *  Logic: '<S9>/Logical Operator1'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S16>/FixPt Relational Operator'
   *  Switch: '<S9>/Switch1'
   *  UnitDelay: '<S16>/Delay Input1'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTATE <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S9>/Switch1' incorporates:
       *  DataTypeConversion: '<S9>/Data Type Conversion1'
       *  Delay: '<S9>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S9>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S9>/Delay'
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
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_B.target_mode = PilotMode_Acro;
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
        FMS_DW.is_c3_FMS = FMS_IN_Manual_e;
      }
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
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_B.target_mode = PilotMode_Stabilize;
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
        FMS_DW.is_c3_FMS = FMS_IN_Acro;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/SafeMode' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S12>/FixPt Relational Operator'
   *  RelationalOperator: '<S13>/FixPt Relational Operator'
   *  Switch: '<S8>/Switch2'
   *  UnitDelay: '<S12>/Delay Input1'
   *  UnitDelay: '<S13>/Delay Input1'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S8>/Switch2' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion1'
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;
  } else {
    /* Switch: '<S8>/Switch2' incorporates:
     *  Constant: '<S8>/Constant1'
     */
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_3' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S342>/Discrete-Time Integrator5' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In3'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = FMS_U.INS_Out.ax;
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = FMS_U.INS_Out.ay;
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = FMS_U.INS_Out.az;
  }

  /* Product: '<S5>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S5>/Sum of Elements'
   */
  rtb_Divide_b = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S343>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S343>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  Constant: '<S341>/Constant'
   *  DiscreteIntegrator: '<S342>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S343>/Discrete-Time Integrator5'
   *  Logic: '<S344>/AND'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S341>/Compare'
   *  RelationalOperator: '<S344>/Lower Test'
   *  RelationalOperator: '<S344>/Upper Test'
   */
  FMS_B.LogicalOperator1 = ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] <= 0.5F) && ((-0.5F <=
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] <= 0.5F)) && ((-10.306F <=
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] <= -9.306F)) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTAT_d < 1200.0F));

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
  if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.LogicalOperator1;
  rtb_LogicalOperator_at = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_LogicalOperator_at) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
    FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_k = rtb_LogicalOperator_at;
  rtb_LogicalOperator_at = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_LogicalOperator_at) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_LogicalOperator_at;
  if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d0)) {
    FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d0 = FMS_B.LogicalOperator1;
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

  /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
  /* SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Divide_o[0] = FMS_B.Cmd_In.sp_return[0];
  rtb_Divide_o[1] = FMS_B.Cmd_In.sp_return[1];
  rtb_Switch_l[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_l[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_l[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<Root>/FMS Input' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SwitchCase: '<S2>/Switch Case' */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;
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

  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S17>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S24>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S288>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S278>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S234>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S212>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S222>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S22>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for SwitchCase: '<S173>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S163>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S21>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 4:
        break;

       case 1:
        /* Disable for SwitchCase: '<S117>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S53>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S93>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S69>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S80>/Switch Case' */
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

    /* End of Disable for SwitchCase: '<S17>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/Disarm' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     */
    FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Disarm);

    /* End of Outputs for SubSystem: '<S2>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/Standby' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S19>/Bus Assignment'
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S19>/Constant'
     *  SignalConversion: '<S19>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S19>/Bus Assignment' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S19>/Constant2'
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

    /* End of Outputs for SubSystem: '<S2>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/Arm' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* SwitchCase: '<S17>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;
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

    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S24>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S288>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S278>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S234>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S212>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S222>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S22>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for SwitchCase: '<S173>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S163>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S21>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S117>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S36>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S53>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S93>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S69>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S80>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S17>/SubMode' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* SwitchCase: '<S24>/Switch Case' incorporates:
       *  Math: '<S310>/Math Function'
       *  Product: '<S312>/Divide'
       *  Sum: '<S273>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_at;
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

      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_at) {
        switch (rtPrevAction) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S288>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S278>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S234>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S212>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S222>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S24>/Takeoff' incorporates:
         *  ActionPort: '<S207>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S325>/Sum2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S319>/Sum'
         */
        rtb_Switch_k = FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2];

        /* Product: '<S325>/Divide' incorporates:
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S325>/Sum1'
         *  Sum: '<S325>/Sum2'
         */
        rtb_Saturation_l = 1.0F / (FMS_B.Cmd_In.sp_takeoff[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_k;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Saturate: '<S325>/Saturation' */
        if (rtb_Saturation_l > 1.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = 0.0F;
          }
        }

        /* End of Saturate: '<S325>/Saturation' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S326>/Trigonometric Function1' incorporates:
         *  Gain: '<S324>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S326>/Trigonometric Function3'
         */
        A = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_VectorConcatenate_m[0] = A;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S326>/Trigonometric Function' incorporates:
         *  Gain: '<S324>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S326>/Trigonometric Function2'
         */
        rtb_Gain_a = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_VectorConcatenate_m[1] = rtb_Gain_a;

        /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S326>/Constant3'
         */
        rtb_VectorConcatenate_m[2] = 0.0F;

        /* Gain: '<S326>/Gain' */
        rtb_VectorConcatenate_m[3] = -rtb_Gain_a;

        /* Trigonometry: '<S326>/Trigonometric Function3' */
        rtb_VectorConcatenate_m[4] = A;

        /* SignalConversion: '<S326>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S326>/Constant4'
         */
        rtb_VectorConcatenate_m[5] = 0.0F;

        /* SignalConversion: '<S326>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S320>/Saturation1' */
        rtb_Gain_a = FMS_PARAM.VEL_XY_LIM / 5.0F;
        A = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* SignalConversion: '<S320>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S325>/Multiply'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S320>/Sum'
         *  Sum: '<S325>/Sum3'
         *  Sum: '<S325>/Sum4'
         */
        rtb_Sqrt_k0 = ((FMS_B.Cmd_In.sp_takeoff[0] - FMS_B.Cmd_In.cur_waypoint[0])
                       * rtb_Saturation_l + FMS_B.Cmd_In.cur_waypoint[0]) -
          FMS_U.INS_Out.x_R;
        rtb_Saturation_l = ((FMS_B.Cmd_In.sp_takeoff[1] -
                             FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Saturation_l +
                            FMS_B.Cmd_In.cur_waypoint[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Product: '<S320>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_m[i + 3] *
            rtb_Saturation_l + rtb_VectorConcatenate_m[i] * rtb_Sqrt_k0;
        }

        /* Saturate: '<S320>/Saturation1' incorporates:
         *  Gain: '<S320>/Gain2'
         *  Product: '<S320>/Multiply'
         */
        rtb_Sqrt_k0 = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[0];
        rtb_Saturation_l = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S207>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S207>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S207>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S207>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S320>/Saturation1' */
        if (rtb_Sqrt_k0 > rtb_Gain_a) {
          /* BusAssignment: '<S207>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_a;
        } else if (rtb_Sqrt_k0 < A) {
          /* BusAssignment: '<S207>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = A;
        } else {
          /* BusAssignment: '<S207>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_k0;
        }

        if (rtb_Saturation_l > rtb_Gain_a) {
          /* BusAssignment: '<S207>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Gain_a;
        } else if (rtb_Saturation_l < A) {
          /* BusAssignment: '<S207>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = A;
        } else {
          /* BusAssignment: '<S207>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_l;
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Switch: '<S319>/Switch' incorporates:
         *  Abs: '<S319>/Abs'
         *  Abs: '<S319>/Abs1'
         *  Constant: '<S321>/Constant'
         *  Constant: '<S322>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S319>/Logical Operator'
         *  RelationalOperator: '<S321>/Compare'
         *  RelationalOperator: '<S322>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S319>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_takeoff[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(rtb_Switch_k) > 2.0F)) {
          /* BusAssignment: '<S207>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Constant: '<S319>/Constant6'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -1.0F;
        } else {
          /* BusAssignment: '<S207>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Constant: '<S319>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -0.5F;
        }

        /* End of Switch: '<S319>/Switch' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        /* End of Outputs for SubSystem: '<S24>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S24>/Land' incorporates:
         *  ActionPort: '<S205>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S251>/Trigonometric Function1' incorporates:
         *  Gain: '<S250>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S251>/Trigonometric Function' incorporates:
         *  Gain: '<S250>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S251>/Constant3'
         */
        rtb_VectorConcatenate_m[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Gain: '<S251>/Gain' incorporates:
         *  Gain: '<S250>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S251>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_m[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S251>/Trigonometric Function3' incorporates:
         *  Gain: '<S250>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S251>/Constant4'
         */
        rtb_VectorConcatenate_m[5] = 0.0F;

        /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S247>/Saturation1' */
        rtb_Switch_k = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Gain_a = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* SignalConversion: '<S248>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S248>/Sum'
         */
        rtb_Sqrt_k0 = FMS_B.Cmd_In.sp_land[0] - FMS_U.INS_Out.x_R;
        rtb_Saturation_l = FMS_B.Cmd_In.sp_land[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Product: '<S248>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_m[i + 3] *
            rtb_Saturation_l + rtb_VectorConcatenate_m[i] * rtb_Sqrt_k0;
        }

        /* Saturate: '<S247>/Saturation1' incorporates:
         *  Gain: '<S248>/Gain2'
         *  Product: '<S248>/Multiply'
         */
        rtb_Sqrt_k0 = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[0];
        rtb_Saturation_l = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S205>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S205>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S205>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S205>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S247>/Saturation1' */
        if (rtb_Sqrt_k0 > rtb_Switch_k) {
          /* BusAssignment: '<S205>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_k;
        } else if (rtb_Sqrt_k0 < rtb_Gain_a) {
          /* BusAssignment: '<S205>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Gain_a;
        } else {
          /* BusAssignment: '<S205>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_k0;
        }

        if (rtb_Saturation_l > rtb_Switch_k) {
          /* BusAssignment: '<S205>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_k;
        } else if (rtb_Saturation_l < rtb_Gain_a) {
          /* BusAssignment: '<S205>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Gain_a;
        } else {
          /* BusAssignment: '<S205>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_l;
        }

        /* BusAssignment: '<S205>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S205>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S24>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S24>/Return' incorporates:
           *  ActionPort: '<S206>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Delay: '<S254>/Delay'
           *  Delay: '<S255>/Delay'
           *  Delay: '<S274>/Delay'
           *  DiscreteIntegrator: '<S258>/Integrator'
           *  DiscreteIntegrator: '<S258>/Integrator1'
           *  DiscreteIntegrator: '<S315>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_o = 1U;
          FMS_DW.l1_heading_p = 0.0F;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S24>/Return' */

          /* SystemReset for IfAction SubSystem: '<S24>/Return' incorporates:
           *  ActionPort: '<S206>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Chart: '<S279>/Motion Status'
           *  Chart: '<S289>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S24>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Return' incorporates:
         *  ActionPort: '<S206>/Action Port'
         */
        /* Delay: '<S274>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.icLoad_o != 0) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S270>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S275>/Square'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Divide = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_return[0];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_Saturation1_ln[0] = rtb_Divide * rtb_Divide;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        rtb_Divide = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_return[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S275>/Square' */
        rtb_Divide *= rtb_Divide;

        /* Sqrt: '<S275>/Sqrt' incorporates:
         *  Sum: '<S275>/Sum of Elements'
         */
        rtb_Sqrt_k0 = sqrtf(rtb_Saturation1_ln[0] + rtb_Divide);

        /* Switch: '<S270>/Switch' incorporates:
         *  Constant: '<S270>/vel'
         */
        if (rtb_Sqrt_k0 > FMS_PARAM.L1) {
          rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S270>/Gain' */
          rtb_Switch_k = 0.5F * rtb_Sqrt_k0;

          /* Saturate: '<S270>/Saturation' */
          if (rtb_Switch_k > FMS_PARAM.CRUISE_SPEED) {
            rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Switch_k < 0.5F) {
              rtb_Switch_k = 0.5F;
            }
          }

          /* End of Saturate: '<S270>/Saturation' */
        }

        /* End of Switch: '<S270>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S289>/Motion State' incorporates:
         *  Constant: '<S289>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S289>/Square'
         *  Math: '<S289>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S289>/Sqrt'
         *  Sum: '<S289>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S288>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S288>/Hold Control' incorporates:
             *  ActionPort: '<S291>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S288>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S288>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S288>/Hold Control' incorporates:
           *  ActionPort: '<S291>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_mv,
                            &FMS_ConstB.HoldControl_k, &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S288>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S288>/Brake Control' incorporates:
           *  ActionPort: '<S290>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_mv);

          /* End of Outputs for SubSystem: '<S288>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S288>/Move Control' incorporates:
             *  ActionPort: '<S292>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S288>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S288>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S288>/Move Control' incorporates:
           *  ActionPort: '<S292>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_mv,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S288>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S288>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S279>/Motion Status' incorporates:
         *  Abs: '<S279>/Abs'
         *  Constant: '<S279>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S278>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S278>/Hold Control' incorporates:
             *  ActionPort: '<S281>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S278>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S278>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S278>/Hold Control' incorporates:
           *  ActionPort: '<S281>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S278>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S278>/Brake Control' incorporates:
           *  ActionPort: '<S280>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S278>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S278>/Move Control' incorporates:
             *  ActionPort: '<S282>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S278>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S278>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S278>/Move Control' incorporates:
           *  ActionPort: '<S282>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S278>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S278>/Switch Case' */

        /* Delay: '<S254>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S206>/Sum' incorporates:
         *  Delay: '<S254>/Delay'
         *  MATLAB Function: '<S272>/OutRegionRegWP'
         *  MATLAB Function: '<S272>/SearchL1RefWP'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_return[0] -
          FMS_DW.Delay_DSTATE_p[0];
        rtb_Divide = FMS_B.Cmd_In.sp_return[1] - FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S269>/Sum of Elements' incorporates:
         *  Math: '<S269>/Math Function'
         *  Sum: '<S206>/Sum'
         */
        rtb_Gain_a = rtb_Divide * rtb_Divide + rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Math: '<S269>/Math Function1' incorporates:
         *  Sum: '<S269>/Sum of Elements'
         *
         * About '<S269>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_a < 0.0F) {
          rtb_Saturation_l = -sqrtf(fabsf(rtb_Gain_a));
        } else {
          rtb_Saturation_l = sqrtf(rtb_Gain_a);
        }

        /* End of Math: '<S269>/Math Function1' */

        /* Switch: '<S269>/Switch' incorporates:
         *  Constant: '<S269>/Constant'
         *  Product: '<S269>/Product'
         *  Sum: '<S206>/Sum'
         */
        if (rtb_Saturation_l > 0.0F) {
          rtb_Switch_l[0] = rtb_Divide;
          rtb_Switch_l[1] = rtb_MathFunction_h_idx_0;
          rtb_Switch_l[2] = rtb_Saturation_l;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S269>/Switch' */

        /* Product: '<S269>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Saturation1_ln[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S267>/Subtract' incorporates:
         *  Product: '<S267>/Multiply'
         *  Product: '<S267>/Multiply1'
         */
        rtb_Saturation_l = rtb_Saturation1_ln[0] * FMS_ConstB.Divide_d[1] -
          rtb_Saturation1_ln[1] * FMS_ConstB.Divide_d[0];

        /* Signum: '<S256>/Sign1' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S256>/Sign1' */

        /* Switch: '<S256>/Switch2' incorporates:
         *  Constant: '<S256>/Constant4'
         */
        if (rtb_Saturation_l == 0.0F) {
          rtb_Saturation_l = 1.0F;
        }

        /* End of Switch: '<S256>/Switch2' */

        /* DotProduct: '<S256>/Dot Product' */
        rtb_Sqrt_k0 = FMS_ConstB.Divide_d[0] * rtb_Saturation1_ln[0] +
          FMS_ConstB.Divide_d[1] * rtb_Saturation1_ln[1];

        /* Trigonometry: '<S256>/Acos' incorporates:
         *  DotProduct: '<S256>/Dot Product'
         */
        if (rtb_Sqrt_k0 > 1.0F) {
          rtb_Sqrt_k0 = 1.0F;
        } else {
          if (rtb_Sqrt_k0 < -1.0F) {
            rtb_Sqrt_k0 = -1.0F;
          }
        }

        /* Product: '<S256>/Multiply' incorporates:
         *  Trigonometry: '<S256>/Acos'
         */
        rtb_Saturation_l *= acosf(rtb_Sqrt_k0);

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Math: '<S260>/Rem' incorporates:
         *  Constant: '<S260>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S255>/Sum1'
         */
        rtb_Sqrt_k0 = rt_remf(rtb_Saturation_l - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Switch: '<S260>/Switch' incorporates:
         *  Abs: '<S260>/Abs'
         *  Constant: '<S260>/Constant'
         *  Constant: '<S266>/Constant'
         *  Product: '<S260>/Multiply'
         *  RelationalOperator: '<S266>/Compare'
         *  Sum: '<S260>/Add'
         */
        if (fabsf(rtb_Sqrt_k0) > 3.14159274F) {
          /* Signum: '<S260>/Sign' */
          if (rtb_Sqrt_k0 < 0.0F) {
            rtb_Gain_a = -1.0F;
          } else if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Gain_a = 1.0F;
          } else {
            rtb_Gain_a = rtb_Sqrt_k0;
          }

          /* End of Signum: '<S260>/Sign' */
          rtb_Sqrt_k0 -= 6.28318548F * rtb_Gain_a;
        }

        /* End of Switch: '<S260>/Switch' */

        /* Abs: '<S253>/Abs' */
        rtb_Sqrt_k0 = fabsf(rtb_Sqrt_k0);

        /* Switch: '<S253>/Switch' incorporates:
         *  Product: '<S274>/Multiply'
         *  Sum: '<S274>/Sum'
         */
        if (rtb_Sqrt_k0 > 0.34906584F) {
          /* Saturate: '<S288>/Saturation1' */
          if (FMS_B.Merge_mv[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_l[0] = FMS_B.Merge_mv[0];
          }

          if (FMS_B.Merge_mv[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_mv[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_l[1] = FMS_B.Merge_mv[1];
          }

          /* End of Saturate: '<S288>/Saturation1' */

          /* Saturate: '<S278>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_l[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S278>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          /* Sum: '<S274>/Sum' incorporates:
           *  Delay: '<S274>/Delay'
           *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sqrt_k0 = FMS_B.Cmd_In.sp_return[0] - FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */

          /* SignalConversion: '<S316>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_l[0] = rtb_Sqrt_k0;
          rtb_Saturation1_ln[0] = rtb_Sqrt_k0;

          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          /* Sum: '<S274>/Sum' incorporates:
           *  Delay: '<S274>/Delay'
           *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sqrt_k0 = FMS_B.Cmd_In.sp_return[1] - FMS_DW.Delay_DSTATE_e[1];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */

          /* SignalConversion: '<S318>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S318>/Constant4'
           */
          rtb_VectorConcatenate_m[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          /* Gain: '<S317>/Gain' incorporates:
           *  DiscreteIntegrator: '<S315>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S3>/Signal Copy1'
           *  Sum: '<S315>/Add'
           */
          rtb_Gain_a = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_p);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */

          /* Trigonometry: '<S318>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S318>/Trigonometric Function1'
           */
          A = arm_cos_f32(rtb_Gain_a);
          rtb_VectorConcatenate_m[4] = A;

          /* Trigonometry: '<S318>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S318>/Trigonometric Function'
           */
          rtb_Gain_a = arm_sin_f32(rtb_Gain_a);

          /* Gain: '<S318>/Gain' incorporates:
           *  Trigonometry: '<S318>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_m[3] = -rtb_Gain_a;

          /* SignalConversion: '<S318>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S318>/Constant3'
           */
          rtb_VectorConcatenate_m[2] = 0.0F;

          /* Trigonometry: '<S318>/Trigonometric Function' */
          rtb_VectorConcatenate_m[1] = rtb_Gain_a;

          /* Trigonometry: '<S318>/Trigonometric Function1' */
          rtb_VectorConcatenate_m[0] = A;

          /* SignalConversion: '<S318>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_k[0];
          rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_k[1];
          rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_k[2];

          /* Sum: '<S316>/Sum of Elements' incorporates:
           *  Math: '<S316>/Math Function'
           */
          rtb_Gain_a = rtb_Switch_l[0] * rtb_Switch_l[0] + rtb_Sqrt_k0 *
            rtb_Sqrt_k0;

          /* Math: '<S316>/Math Function1' incorporates:
           *  Sum: '<S316>/Sum of Elements'
           *
           * About '<S316>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain_a < 0.0F) {
            rtb_Gain_a = -sqrtf(fabsf(rtb_Gain_a));
          } else {
            rtb_Gain_a = sqrtf(rtb_Gain_a);
          }

          /* End of Math: '<S316>/Math Function1' */

          /* Switch: '<S316>/Switch' incorporates:
           *  Constant: '<S316>/Constant'
           *  Product: '<S316>/Product'
           */
          if (rtb_Gain_a > 0.0F) {
            A = rtb_Saturation1_ln[0];
          } else {
            A = 0.0F;
            rtb_Sqrt_k0 = 0.0F;
            rtb_Gain_a = 1.0F;
          }

          /* End of Switch: '<S316>/Switch' */

          /* Product: '<S314>/Multiply2' incorporates:
           *  Product: '<S316>/Divide'
           */
          A = A / rtb_Gain_a * rtb_Switch_k;
          rtb_Sqrt_k0 = rtb_Sqrt_k0 / rtb_Gain_a * rtb_Switch_k;
          for (i = 0; i < 3; i++) {
            rtb_Switch_l[i] = rtb_VectorConcatenate_m[i + 3] * rtb_Sqrt_k0 +
              rtb_VectorConcatenate_m[i] * A;
          }
        }

        /* End of Switch: '<S253>/Switch' */

        /* Delay: '<S255>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* DiscreteIntegrator: '<S258>/Integrator1' incorporates:
         *  Delay: '<S255>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Math: '<S262>/Rem' incorporates:
         *  Constant: '<S262>/Constant1'
         *  DiscreteIntegrator: '<S258>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S257>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Switch: '<S262>/Switch' incorporates:
         *  Abs: '<S262>/Abs'
         *  Constant: '<S262>/Constant'
         *  Constant: '<S263>/Constant'
         *  Product: '<S262>/Multiply'
         *  RelationalOperator: '<S263>/Compare'
         *  Sum: '<S262>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S262>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Sqrt_k0 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          } else {
            rtb_Sqrt_k0 = rtb_Rem_k;
          }

          /* End of Signum: '<S262>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Sqrt_k0;
        }

        /* End of Switch: '<S262>/Switch' */

        /* Gain: '<S257>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S257>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S257>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S206>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S206>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S206>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_l[0];
        FMS_Y.FMS_Out.v_cmd = rtb_Switch_l[1];
        FMS_Y.FMS_Out.w_cmd = rtb_Switch_l[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S309>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S309>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S307>/Sum of Elements'
         */
        rtb_Gain_a = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S309>/Math Function1' incorporates:
         *  Sum: '<S309>/Sum of Elements'
         *
         * About '<S309>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_a < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Gain_a));
        } else {
          rtb_Rem_k = sqrtf(rtb_Gain_a);
        }

        /* End of Math: '<S309>/Math Function1' */

        /* Switch: '<S309>/Switch' incorporates:
         *  Constant: '<S309>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S309>/Product'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (rtb_Rem_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_Switch_l[0] = FMS_U.INS_Out.vn;
          rtb_Switch_l[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          rtb_Switch_l[2] = rtb_Rem_k;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S309>/Switch' */

        /* Product: '<S309>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Saturation1_ln[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S312>/Sum of Elements' incorporates:
         *  Math: '<S312>/Math Function'
         *  SignalConversion: '<S312>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Sqrt_k0 = rtb_Saturation1_ln[1] * rtb_Saturation1_ln[1] +
          rtb_Saturation1_ln[0] * rtb_Saturation1_ln[0];

        /* Math: '<S312>/Math Function1' incorporates:
         *  Sum: '<S312>/Sum of Elements'
         *
         * About '<S312>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Sqrt_k0));
        } else {
          rtb_Rem_k = sqrtf(rtb_Sqrt_k0);
        }

        /* End of Math: '<S312>/Math Function1' */

        /* Switch: '<S312>/Switch' incorporates:
         *  Constant: '<S312>/Constant'
         *  Product: '<S312>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_Switch_l[0] = rtb_Saturation1_ln[1];
          rtb_Switch_l[1] = rtb_Saturation1_ln[0];
          rtb_Switch_l[2] = rtb_Rem_k;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S312>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* MATLAB Function: '<S272>/NearbyRefWP' incorporates:
         *  Constant: '<S206>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        FMS_NearbyRefWP(rtb_Divide_o, FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Saturation1_ln,
                        &rtb_MathFunction_cr_idx_0);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* MATLAB Function: '<S272>/SearchL1RefWP' incorporates:
         *  Constant: '<S206>/L1'
         *  Delay: '<S254>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        A = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 + rtb_Divide *
          rtb_Divide;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
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

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_Sqrt_k0 = -1.0F;
        rtb_MathFunction_iq_idx_0 = 0.0F;
        rtb_MathFunction_iq_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          A = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
            rtb_Sqrt_k0 = fmaxf(D, A);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Sqrt_k0 = D;
            guard1 = true;
          } else {
            if ((A >= 0.0F) && (A <= 1.0F)) {
              rtb_Sqrt_k0 = A;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Sqrt_k0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_MathFunction_iq_idx_0 = rtb_MathFunction_h_idx_0 * rtb_Sqrt_k0 +
            FMS_DW.Delay_DSTATE_p[0];
          rtb_MathFunction_iq_idx_1 = rtb_Divide * rtb_Sqrt_k0 +
            FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* MATLAB Function: '<S272>/OutRegionRegWP' incorporates:
         *  Delay: '<S254>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        A = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) * rtb_Divide +
             (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE_p[0]) *
             rtb_MathFunction_h_idx_0) / (rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0 + rtb_Divide * rtb_Divide);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_LogicalOperator_at = (A <= 0.0F);
        u = (A >= 1.0F);
        if (rtb_LogicalOperator_at) {
          rtb_MathFunction_h_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_return[0];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        } else {
          rtb_MathFunction_h_idx_0 = A * rtb_MathFunction_h_idx_0 +
            FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S272>/Switch1' incorporates:
         *  Constant: '<S302>/Constant'
         *  RelationalOperator: '<S302>/Compare'
         */
        if (rtb_MathFunction_cr_idx_0 <= 0.0F) {
          /* Switch: '<S272>/Switch' incorporates:
           *  Constant: '<S301>/Constant'
           *  MATLAB Function: '<S272>/SearchL1RefWP'
           *  RelationalOperator: '<S301>/Compare'
           */
          if (rtb_Sqrt_k0 >= 0.0F) {
            rtb_Saturation1_ln[0] = rtb_MathFunction_iq_idx_0;
            rtb_Saturation1_ln[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;

            /* MATLAB Function: '<S272>/OutRegionRegWP' incorporates:
             *  Delay: '<S254>/Delay'
             *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_LogicalOperator_at) {
              rtb_Saturation1_ln[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
              rtb_Saturation1_ln[1] = FMS_B.Cmd_In.sp_return[1];

              /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            } else {
              rtb_Saturation1_ln[1] = A * rtb_Divide + FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S272>/Switch' */
        }

        /* End of Switch: '<S272>/Switch1' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S273>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_MathFunction_cr_idx_1 = rtb_Saturation1_ln[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_Saturation1_ln[0] = rtb_MathFunction_cr_idx_1;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_cr_idx_1 *
          rtb_MathFunction_cr_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S273>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S310>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_MathFunction_cr_idx_1 = rtb_Saturation1_ln[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S310>/Math Function' incorporates:
         *  Math: '<S308>/Square'
         */
        rtb_Sqrt_k0 = rtb_MathFunction_cr_idx_1 * rtb_MathFunction_cr_idx_1;

        /* Sum: '<S310>/Sum of Elements' incorporates:
         *  Math: '<S310>/Math Function'
         */
        A = rtb_Sqrt_k0 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S310>/Math Function1' incorporates:
         *  Sum: '<S310>/Sum of Elements'
         *
         * About '<S310>/Math Function1':
         *  Operator: sqrt
         */
        if (A < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(A));
        } else {
          rtb_Rem_k = sqrtf(A);
        }

        /* End of Math: '<S310>/Math Function1' */

        /* Switch: '<S310>/Switch' incorporates:
         *  Constant: '<S310>/Constant'
         *  Product: '<S310>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MathFunction_cr_idx_0 = rtb_Saturation1_ln[0];
        } else {
          rtb_MathFunction_cr_idx_0 = 0.0F;
          rtb_MathFunction_cr_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S310>/Switch' */

        /* Product: '<S310>/Divide' */
        rtb_Divide_o[0] = rtb_MathFunction_cr_idx_0 / rtb_Rem_k;
        rtb_Divide_o[1] = rtb_MathFunction_cr_idx_1 / rtb_Rem_k;

        /* Sum: '<S313>/Sum of Elements' incorporates:
         *  Math: '<S313>/Math Function'
         *  SignalConversion: '<S313>/TmpSignal ConversionAtMath FunctionInport1'
         */
        A = rtb_Divide_o[1] * rtb_Divide_o[1] + rtb_Divide_o[0] * rtb_Divide_o[0];

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
          rtb_MathFunction_cr_idx_0 = rtb_Divide_o[1];
          rtb_MathFunction_cr_idx_1 = rtb_Divide_o[0];
        } else {
          rtb_MathFunction_cr_idx_0 = 0.0F;
          rtb_MathFunction_cr_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S313>/Switch' */

        /* Product: '<S313>/Divide' */
        rtb_Divide_o[0] = rtb_MathFunction_cr_idx_0 / rtb_Rem_k;

        /* Math: '<S308>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Saturation1_ln[0] *
          rtb_Saturation1_ln[0];
        rtb_Saturation1_ln[0] = rtb_Switch_l[0] / rtb_Switch_l[2];

        /* Product: '<S313>/Divide' incorporates:
         *  Product: '<S312>/Divide'
         */
        rtb_Divide_o[1] = rtb_MathFunction_cr_idx_1 / rtb_Rem_k;

        /* Product: '<S312>/Divide' */
        rtb_Divide = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sqrt: '<S307>/Sqrt' */
        rtb_Rem_k = sqrtf(rtb_Gain_a);

        /* Gain: '<S273>/Gain' incorporates:
         *  Math: '<S273>/Square'
         */
        rtb_Gain_a = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S311>/Subtract' incorporates:
         *  Product: '<S311>/Multiply'
         *  Product: '<S311>/Multiply1'
         */
        rtb_Rem_k = rtb_Divide_o[0] * rtb_Divide - rtb_Divide_o[1] *
          rtb_Saturation1_ln[0];

        /* Signum: '<S306>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S306>/Sign1' */

        /* Switch: '<S306>/Switch2' incorporates:
         *  Constant: '<S306>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S306>/Switch2' */

        /* DotProduct: '<S306>/Dot Product' */
        rtb_Divide = rtb_Saturation1_ln[0] * rtb_Divide_o[0] + rtb_Divide *
          rtb_Divide_o[1];

        /* Trigonometry: '<S306>/Acos' incorporates:
         *  DotProduct: '<S306>/Dot Product'
         */
        if (rtb_Divide > 1.0F) {
          rtb_Divide = 1.0F;
        } else {
          if (rtb_Divide < -1.0F) {
            rtb_Divide = -1.0F;
          }
        }

        /* Product: '<S306>/Multiply' incorporates:
         *  Trigonometry: '<S306>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_Divide);

        /* Saturate: '<S273>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S273>/Saturation' */

        /* Product: '<S273>/Divide' incorporates:
         *  Constant: '<S206>/L1'
         *  Constant: '<S273>/Constant'
         *  MinMax: '<S273>/Max'
         *  MinMax: '<S273>/Min'
         *  Product: '<S273>/Multiply1'
         *  Sqrt: '<S308>/Sqrt'
         *  Sum: '<S308>/Sum of Elements'
         *  Trigonometry: '<S273>/Sin'
         */
        rtb_Gain_a = arm_sin_f32(rtb_Rem_k) * rtb_Gain_a / fminf(FMS_PARAM.L1,
          fmaxf(sqrtf(rtb_Sqrt_k0 + rtb_TmpSignalConversionAtDela_a[0]), 0.5F));

        /* Sum: '<S255>/Sum2' incorporates:
         *  Delay: '<S255>/Delay'
         */
        rtb_Saturation_l -= FMS_DW.Delay_DSTATE_a;

        /* Math: '<S259>/Rem' incorporates:
         *  Constant: '<S259>/Constant1'
         */
        rtb_MathFunction_cr_idx_0 = rt_remf(rtb_Saturation_l, 6.28318548F);

        /* Switch: '<S259>/Switch' incorporates:
         *  Abs: '<S259>/Abs'
         *  Constant: '<S259>/Constant'
         *  Constant: '<S265>/Constant'
         *  Product: '<S259>/Multiply'
         *  RelationalOperator: '<S265>/Compare'
         *  Sum: '<S259>/Add'
         */
        if (fabsf(rtb_MathFunction_cr_idx_0) > 3.14159274F) {
          /* Signum: '<S259>/Sign' */
          if (rtb_MathFunction_cr_idx_0 < 0.0F) {
            rtb_Sqrt_k0 = -1.0F;
          } else if (rtb_MathFunction_cr_idx_0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          } else {
            rtb_Sqrt_k0 = rtb_MathFunction_cr_idx_0;
          }

          /* End of Signum: '<S259>/Sign' */
          rtb_MathFunction_cr_idx_0 -= 6.28318548F * rtb_Sqrt_k0;
        }

        /* End of Switch: '<S259>/Switch' */

        /* Sum: '<S255>/Sum' incorporates:
         *  Delay: '<S255>/Delay'
         */
        rtb_Sqrt_k0 = rtb_MathFunction_cr_idx_0 + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S264>/Multiply1' incorporates:
         *  Constant: '<S264>/const1'
         *  DiscreteIntegrator: '<S258>/Integrator'
         */
        rtb_MathFunction_cr_idx_0 = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S264>/Add' incorporates:
         *  DiscreteIntegrator: '<S258>/Integrator1'
         *  Sum: '<S258>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_e - rtb_Sqrt_k0) +
          rtb_MathFunction_cr_idx_0;

        /* Signum: '<S264>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Sqrt_k0 = 1.0F;
        } else {
          rtb_Sqrt_k0 = rtb_Rem_k;
        }

        /* End of Signum: '<S264>/Sign' */

        /* Sum: '<S264>/Add2' incorporates:
         *  Abs: '<S264>/Abs'
         *  Gain: '<S264>/Gain'
         *  Gain: '<S264>/Gain1'
         *  Product: '<S264>/Multiply2'
         *  Product: '<S264>/Multiply3'
         *  Sqrt: '<S264>/Sqrt'
         *  Sum: '<S264>/Add1'
         *  Sum: '<S264>/Subtract'
         */
        rtb_Saturation_l = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_l) *
          FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Sqrt_k0 +
          rtb_MathFunction_cr_idx_0;

        /* Sum: '<S264>/Add4' */
        A = (rtb_Rem_k - rtb_Saturation_l) + rtb_MathFunction_cr_idx_0;

        /* Sum: '<S264>/Add3' */
        rtb_Sqrt_k0 = rtb_Rem_k + FMS_ConstB.d_l;

        /* Sum: '<S264>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_l;

        /* Signum: '<S264>/Sign1' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S264>/Sign1' */

        /* Signum: '<S264>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S264>/Sign2' */

        /* Sum: '<S264>/Add5' incorporates:
         *  Gain: '<S264>/Gain2'
         *  Product: '<S264>/Multiply4'
         *  Sum: '<S264>/Subtract2'
         */
        rtb_Saturation_l += (rtb_Sqrt_k0 - rtb_Rem_k) * 0.5F * A;

        /* Update for Delay: '<S274>/Delay' */
        FMS_DW.icLoad_o = 0U;

        /* Update for DiscreteIntegrator: '<S315>/Discrete-Time Integrator' incorporates:
         *  Product: '<S274>/Divide1'
         */
        FMS_DW.l1_heading_p += rtb_Gain_a / rtb_Switch_k * 0.004F;

        /* Update for Delay: '<S254>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Update for Delay: '<S255>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S258>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S258>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S264>/Add6' */
        rtb_Sqrt_k0 = rtb_Saturation_l + FMS_ConstB.d_l;

        /* Sum: '<S264>/Subtract3' */
        A = rtb_Saturation_l - FMS_ConstB.d_l;

        /* Signum: '<S264>/Sign5' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_Saturation_l;
        }

        /* End of Signum: '<S264>/Sign5' */

        /* Signum: '<S264>/Sign3' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S264>/Sign3' */

        /* Signum: '<S264>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S264>/Sign4' */

        /* Signum: '<S264>/Sign6' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Gain_a = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Gain_a = 1.0F;
        } else {
          rtb_Gain_a = rtb_Saturation_l;
        }

        /* End of Signum: '<S264>/Sign6' */

        /* Update for DiscreteIntegrator: '<S258>/Integrator' incorporates:
         *  Constant: '<S264>/const'
         *  Gain: '<S264>/Gain3'
         *  Product: '<S264>/Divide'
         *  Product: '<S264>/Multiply5'
         *  Product: '<S264>/Multiply6'
         *  Sum: '<S264>/Subtract4'
         *  Sum: '<S264>/Subtract5'
         *  Sum: '<S264>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_Saturation_l / FMS_ConstB.d_l -
          rtb_Switch_k) * FMS_ConstB.Gain4_np * ((rtb_Sqrt_k0 - A) * 0.5F) -
          rtb_Gain_a * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S258>/Integrator' */
        /* End of Outputs for SubSystem: '<S24>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S24>/Hold' incorporates:
           *  ActionPort: '<S204>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Chart: '<S213>/Motion Status'
           *  Chart: '<S223>/Motion State'
           *  Chart: '<S235>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S24>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Hold' incorporates:
         *  ActionPort: '<S204>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S213>/Motion Status' incorporates:
         *  Abs: '<S213>/Abs'
         *  Constant: '<S213>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Chart: '<S223>/Motion State' incorporates:
         *  Abs: '<S223>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
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

            /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_a >=
                 250U)) {
              FMS_DW.is_c15_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<Root>/FMS Input' */
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

        /* End of Chart: '<S223>/Motion State' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S235>/Motion State' incorporates:
         *  Constant: '<S235>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S235>/Square'
         *  Math: '<S235>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S235>/Sqrt'
         *  Sum: '<S235>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S234>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S234>/Hold Control' incorporates:
             *  ActionPort: '<S237>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S234>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S234>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S234>/Hold Control' incorporates:
           *  ActionPort: '<S237>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S234>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S234>/Brake Control' incorporates:
           *  ActionPort: '<S236>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S234>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S234>/Move Control' incorporates:
             *  ActionPort: '<S238>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S234>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S234>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S234>/Move Control' incorporates:
           *  ActionPort: '<S238>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S234>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S234>/Switch Case' */

        /* SwitchCase: '<S212>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S212>/Hold Control' incorporates:
             *  ActionPort: '<S215>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S212>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S212>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S212>/Hold Control' incorporates:
           *  ActionPort: '<S215>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S212>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S212>/Brake Control' incorporates:
           *  ActionPort: '<S214>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S212>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S212>/Move Control' incorporates:
             *  ActionPort: '<S216>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S212>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S212>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S212>/Move Control' incorporates:
           *  ActionPort: '<S216>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S212>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S212>/Switch Case' */

        /* SwitchCase: '<S222>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S222>/Hold Control' incorporates:
             *  ActionPort: '<S225>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S222>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_kq);

            /* End of SystemReset for SubSystem: '<S222>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S222>/Hold Control' incorporates:
           *  ActionPort: '<S225>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                             &FMS_DW.HoldControl_kq);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S222>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S222>/Brake Control' incorporates:
           *  ActionPort: '<S224>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S222>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S222>/Move Control' incorporates:
             *  ActionPort: '<S226>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S222>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S222>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S222>/Move Control' incorporates:
           *  ActionPort: '<S226>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S222>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S222>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S204>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S204>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S204>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S222>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S222>/Saturation' */

        /* Saturate: '<S234>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S234>/Saturation1' */

        /* Saturate: '<S212>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S204>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S212>/Saturation1' */
        /* End of Outputs for SubSystem: '<S24>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S24>/Unknown' incorporates:
         *  ActionPort: '<S208>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S24>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S24>/Switch Case' */
      /* End of Outputs for SubSystem: '<S17>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S17>/Auto' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* SwitchCase: '<S22>/Switch Case' incorporates:
       *  Math: '<S193>/Square'
       *  Math: '<S195>/Math Function'
       *  Sum: '<S155>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;
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

      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_i) && (rtPrevAction
           == 1)) {
        /* Disable for SwitchCase: '<S173>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S163>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S22>/Offboard' incorporates:
         *  ActionPort: '<S131>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S131>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S131>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S131>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;

        /* End of Outputs for SubSystem: '<S22>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S22>/Mission' incorporates:
           *  ActionPort: '<S130>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S22>/Switch Case' incorporates:
           *  Delay: '<S136>/Delay'
           *  Delay: '<S156>/Delay'
           *  DiscreteIntegrator: '<S139>/Integrator'
           *  DiscreteIntegrator: '<S139>/Integrator1'
           *  DiscreteIntegrator: '<S200>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S22>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S22>/Mission' incorporates:
           *  ActionPort: '<S130>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S22>/Switch Case' incorporates:
           *  Chart: '<S164>/Motion Status'
           *  Chart: '<S174>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S22>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Mission' incorporates:
         *  ActionPort: '<S130>/Action Port'
         */
        /* Delay: '<S156>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.icLoad != 0) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S152>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S160>/Square'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Sqrt_k0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Sqrt_k0 * rtb_Sqrt_k0;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        rtb_Sqrt_k0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S160>/Square' */
        rtb_Sqrt_k0 *= rtb_Sqrt_k0;

        /* Sqrt: '<S160>/Sqrt' incorporates:
         *  Sum: '<S160>/Sum of Elements'
         */
        rtb_Sqrt_k0 = sqrtf(rtb_TmpSignalConversionAtDela_a[0] + rtb_Sqrt_k0);

        /* Switch: '<S152>/Switch' incorporates:
         *  Constant: '<S152>/vel'
         */
        if (rtb_Sqrt_k0 > FMS_PARAM.L1) {
          rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S152>/Gain' */
          rtb_Switch_k = 0.5F * rtb_Sqrt_k0;

          /* Saturate: '<S152>/Saturation' */
          if (rtb_Switch_k > FMS_PARAM.CRUISE_SPEED) {
            rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Switch_k < 0.5F) {
              rtb_Switch_k = 0.5F;
            }
          }

          /* End of Saturate: '<S152>/Saturation' */
        }

        /* End of Switch: '<S152>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S174>/Motion State' incorporates:
         *  Constant: '<S174>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S174>/Square'
         *  Math: '<S174>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S174>/Sqrt'
         *  Sum: '<S174>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S173>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S173>/Hold Control' incorporates:
             *  ActionPort: '<S176>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S173>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S173>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S173>/Hold Control' incorporates:
           *  ActionPort: '<S176>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S173>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S173>/Brake Control' incorporates:
           *  ActionPort: '<S175>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S173>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S173>/Move Control' incorporates:
             *  ActionPort: '<S177>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S173>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S173>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S173>/Move Control' incorporates:
           *  ActionPort: '<S177>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S173>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S173>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S164>/Motion Status' incorporates:
         *  Abs: '<S164>/Abs'
         *  Constant: '<S164>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S163>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S163>/Hold Control' incorporates:
             *  ActionPort: '<S166>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S163>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S163>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S163>/Hold Control' incorporates:
           *  ActionPort: '<S166>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S163>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S163>/Brake Control' incorporates:
           *  ActionPort: '<S165>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S163>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S163>/Move Control' incorporates:
             *  ActionPort: '<S167>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S163>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S163>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S163>/Move Control' incorporates:
           *  ActionPort: '<S167>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S163>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S163>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S130>/Sum' incorporates:
         *  MATLAB Function: '<S154>/OutRegionRegWP'
         *  MATLAB Function: '<S154>/SearchL1RefWP'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S157>/Sum1'
         *  Switch: '<S134>/Switch'
         */
        rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Divide = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S150>/Sum of Elements' incorporates:
         *  Math: '<S150>/Math Function'
         *  Sum: '<S130>/Sum'
         */
        rtb_Gain_a = rtb_Divide * rtb_Divide + rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Math: '<S150>/Math Function1' incorporates:
         *  Sum: '<S150>/Sum of Elements'
         *
         * About '<S150>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_a < 0.0F) {
          rtb_Saturation_l = -sqrtf(fabsf(rtb_Gain_a));
        } else {
          rtb_Saturation_l = sqrtf(rtb_Gain_a);
        }

        /* End of Math: '<S150>/Math Function1' */

        /* Switch: '<S150>/Switch' incorporates:
         *  Constant: '<S150>/Constant'
         *  Product: '<S150>/Product'
         *  Sum: '<S130>/Sum'
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

        /* End of Switch: '<S150>/Switch' */

        /* Product: '<S150>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_cr_idx_0 /
          rtb_Rem_k;
        rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_cr_idx_1 /
          rtb_Rem_k;

        /* Sum: '<S148>/Subtract' incorporates:
         *  Product: '<S148>/Multiply'
         *  Product: '<S148>/Multiply1'
         */
        rtb_Saturation_l = rtb_TmpSignalConversionAtDela_a[0] *
          FMS_ConstB.Divide[1] - rtb_TmpSignalConversionAtDela_a[1] *
          FMS_ConstB.Divide[0];

        /* Signum: '<S137>/Sign1' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S137>/Sign1' */

        /* Switch: '<S137>/Switch2' incorporates:
         *  Constant: '<S137>/Constant4'
         */
        if (rtb_Saturation_l == 0.0F) {
          rtb_Saturation_l = 1.0F;
        }

        /* End of Switch: '<S137>/Switch2' */

        /* DotProduct: '<S137>/Dot Product' */
        rtb_Sqrt_k0 = FMS_ConstB.Divide[0] * rtb_TmpSignalConversionAtDela_a[0]
          + FMS_ConstB.Divide[1] * rtb_TmpSignalConversionAtDela_a[1];

        /* Trigonometry: '<S137>/Acos' incorporates:
         *  DotProduct: '<S137>/Dot Product'
         */
        if (rtb_Sqrt_k0 > 1.0F) {
          rtb_Sqrt_k0 = 1.0F;
        } else {
          if (rtb_Sqrt_k0 < -1.0F) {
            rtb_Sqrt_k0 = -1.0F;
          }
        }

        /* Product: '<S137>/Multiply' incorporates:
         *  Trigonometry: '<S137>/Acos'
         */
        rtb_Saturation_l *= acosf(rtb_Sqrt_k0);

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Math: '<S141>/Rem' incorporates:
         *  Constant: '<S141>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S136>/Sum1'
         */
        rtb_Sqrt_k0 = rt_remf(rtb_Saturation_l - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Switch: '<S141>/Switch' incorporates:
         *  Abs: '<S141>/Abs'
         *  Constant: '<S141>/Constant'
         *  Constant: '<S147>/Constant'
         *  Product: '<S141>/Multiply'
         *  RelationalOperator: '<S147>/Compare'
         *  Sum: '<S141>/Add'
         */
        if (fabsf(rtb_Sqrt_k0) > 3.14159274F) {
          /* Signum: '<S141>/Sign' */
          if (rtb_Sqrt_k0 < 0.0F) {
            rtb_Gain_a = -1.0F;
          } else if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Gain_a = 1.0F;
          } else {
            rtb_Gain_a = rtb_Sqrt_k0;
          }

          /* End of Signum: '<S141>/Sign' */
          rtb_Sqrt_k0 -= 6.28318548F * rtb_Gain_a;
        }

        /* End of Switch: '<S141>/Switch' */

        /* Abs: '<S134>/Abs' */
        rtb_Sqrt_k0 = fabsf(rtb_Sqrt_k0);

        /* Switch: '<S134>/Switch' incorporates:
         *  Product: '<S156>/Multiply'
         *  Sum: '<S156>/Sum'
         */
        if (rtb_Sqrt_k0 > 0.34906584F) {
          /* Saturate: '<S173>/Saturation1' */
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

          /* End of Saturate: '<S173>/Saturation1' */

          /* Saturate: '<S163>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_Rem_k = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Rem_k = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Rem_k = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S163>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          /* Sum: '<S156>/Sum' incorporates:
           *  Delay: '<S156>/Delay'
           *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sqrt_k0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */

          /* SignalConversion: '<S201>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_MathFunction_cr_idx_0 = rtb_Sqrt_k0;
          A = rtb_Sqrt_k0;

          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          /* Sum: '<S156>/Sum' incorporates:
           *  Delay: '<S156>/Delay'
           *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sqrt_k0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE[1];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */

          /* SignalConversion: '<S203>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S203>/Constant4'
           */
          rtb_VectorConcatenate_m[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          /* Gain: '<S202>/Gain' incorporates:
           *  DiscreteIntegrator: '<S200>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S3>/Signal Copy1'
           *  Sum: '<S200>/Add'
           */
          rtb_Gain_a = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */

          /* Trigonometry: '<S203>/Trigonometric Function3' */
          rtb_VectorConcatenate_m[4] = arm_cos_f32(rtb_Gain_a);

          /* Gain: '<S203>/Gain' incorporates:
           *  Trigonometry: '<S203>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_m[3] = -arm_sin_f32(rtb_Gain_a);

          /* SignalConversion: '<S203>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S203>/Constant3'
           */
          rtb_VectorConcatenate_m[2] = 0.0F;

          /* Trigonometry: '<S203>/Trigonometric Function' */
          rtb_VectorConcatenate_m[1] = arm_sin_f32(rtb_Gain_a);

          /* Trigonometry: '<S203>/Trigonometric Function1' */
          rtb_VectorConcatenate_m[0] = arm_cos_f32(rtb_Gain_a);

          /* SignalConversion: '<S203>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Sum: '<S201>/Sum of Elements' incorporates:
           *  Math: '<S201>/Math Function'
           */
          rtb_Gain_a = rtb_MathFunction_cr_idx_0 * rtb_MathFunction_cr_idx_0 +
            rtb_Sqrt_k0 * rtb_Sqrt_k0;

          /* Math: '<S201>/Math Function1' incorporates:
           *  Sum: '<S201>/Sum of Elements'
           *
           * About '<S201>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Gain_a < 0.0F) {
            rtb_Gain_a = -sqrtf(fabsf(rtb_Gain_a));
          } else {
            rtb_Gain_a = sqrtf(rtb_Gain_a);
          }

          /* End of Math: '<S201>/Math Function1' */

          /* Switch: '<S201>/Switch' incorporates:
           *  Constant: '<S201>/Constant'
           *  Product: '<S201>/Product'
           */
          if (rtb_Gain_a <= 0.0F) {
            A = 0.0F;
            rtb_Sqrt_k0 = 0.0F;
            rtb_Gain_a = 1.0F;
          }

          /* End of Switch: '<S201>/Switch' */

          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          /* Sum: '<S157>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S3>/Signal Copy1'
           *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Rem_k = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_cr_idx_0 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */

          /* Product: '<S157>/Divide' incorporates:
           *  Math: '<S158>/Square'
           *  Math: '<S159>/Square'
           *  Sqrt: '<S158>/Sqrt'
           *  Sqrt: '<S159>/Sqrt'
           *  Sum: '<S157>/Sum'
           *  Sum: '<S158>/Sum of Elements'
           *  Sum: '<S159>/Sum of Elements'
           */
          rtb_Rem_k = sqrtf(rtb_Rem_k * rtb_Rem_k + rtb_MathFunction_cr_idx_0 *
                            rtb_MathFunction_cr_idx_0) / sqrtf
            (rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 + rtb_Divide *
             rtb_Divide);

          /* Saturate: '<S157>/Saturation' */
          if (rtb_Rem_k > 1.0F) {
            rtb_Rem_k = 1.0F;
          } else {
            if (rtb_Rem_k < 0.0F) {
              rtb_Rem_k = 0.0F;
            }
          }

          /* End of Saturate: '<S157>/Saturation' */

          /* Product: '<S199>/Multiply2' incorporates:
           *  Product: '<S201>/Divide'
           */
          A = A / rtb_Gain_a * rtb_Switch_k;
          rtb_Sqrt_k0 = rtb_Sqrt_k0 / rtb_Gain_a * rtb_Switch_k;

          /* Product: '<S156>/Multiply' */
          for (i = 0; i < 3; i++) {
            rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_m[i + 3] *
              rtb_Sqrt_k0 + rtb_VectorConcatenate_m[i] * A;
          }

          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          /* Gain: '<S151>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S157>/Multiply'
           *  SignalConversion: '<S3>/Signal Copy1'
           *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S151>/Sum2'
           *  Sum: '<S157>/Add'
           *  Sum: '<S157>/Subtract'
           */
          rtb_Rem_k = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Rem_k +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_cr_idx_0 = rtb_VectorConcatenate_a[0];
          rtb_MathFunction_cr_idx_1 = rtb_VectorConcatenate_a[1];

          /* Saturate: '<S151>/Saturation1' incorporates:
           *  Product: '<S156>/Multiply'
           */
          if (rtb_Rem_k > FMS_PARAM.VEL_Z_LIM) {
            rtb_Rem_k = FMS_PARAM.VEL_Z_LIM;
          } else {
            if (rtb_Rem_k < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Rem_k = -FMS_PARAM.VEL_Z_LIM;
            }
          }

          /* End of Saturate: '<S151>/Saturation1' */
        }

        /* Delay: '<S136>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* DiscreteIntegrator: '<S139>/Integrator1' incorporates:
         *  Delay: '<S136>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Math: '<S143>/Rem' incorporates:
         *  Constant: '<S143>/Constant1'
         *  DiscreteIntegrator: '<S139>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S138>/Sum'
         */
        A = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Switch: '<S143>/Switch' incorporates:
         *  Abs: '<S143>/Abs'
         *  Constant: '<S143>/Constant'
         *  Constant: '<S144>/Constant'
         *  Product: '<S143>/Multiply'
         *  RelationalOperator: '<S144>/Compare'
         *  Sum: '<S143>/Add'
         */
        if (fabsf(A) > 3.14159274F) {
          /* Signum: '<S143>/Sign' */
          if (A < 0.0F) {
            rtb_Sqrt_k0 = -1.0F;
          } else if (A > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          } else {
            rtb_Sqrt_k0 = A;
          }

          /* End of Signum: '<S143>/Sign' */
          A -= 6.28318548F * rtb_Sqrt_k0;
        }

        /* End of Switch: '<S143>/Switch' */

        /* Gain: '<S138>/Gain2' */
        A *= FMS_PARAM.YAW_P;

        /* Saturate: '<S138>/Saturation' */
        if (A > FMS_PARAM.YAW_RATE_LIM) {
          A = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (A < -FMS_PARAM.YAW_RATE_LIM) {
            A = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S138>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S130>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S130>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S130>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_cr_idx_0;
        FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_cr_idx_1;
        FMS_Y.FMS_Out.w_cmd = rtb_Rem_k;
        FMS_Y.FMS_Out.psi_rate_cmd = A;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Math: '<S194>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtDela_a[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_TmpSignalConversionAtDela_a[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S194>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S194>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Gain_a = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S194>/Math Function1' incorporates:
         *  Sum: '<S194>/Sum of Elements'
         *
         * About '<S194>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Gain_a < 0.0F) {
          A = -sqrtf(fabsf(rtb_Gain_a));
        } else {
          A = sqrtf(rtb_Gain_a);
        }

        /* End of Math: '<S194>/Math Function1' */

        /* Switch: '<S194>/Switch' incorporates:
         *  Constant: '<S194>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S194>/Product'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (A > 0.0F) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_cr_idx_0 = FMS_U.INS_Out.vn;
          rtb_MathFunction_cr_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          rtb_Rem_k = A;
        } else {
          rtb_MathFunction_cr_idx_0 = 0.0F;
          rtb_MathFunction_cr_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S194>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* MATLAB Function: '<S154>/NearbyRefWP' incorporates:
         *  Constant: '<S130>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_l[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_TmpSignalConversionAtDela_a,
                        &rtb_Gain_a);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* MATLAB Function: '<S154>/SearchL1RefWP' incorporates:
         *  Constant: '<S130>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        A = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 + rtb_Divide *
          rtb_Divide;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
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

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_Sqrt_k0 = -1.0F;
        rtb_MathFunction_iq_idx_0 = 0.0F;
        rtb_MathFunction_iq_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          A = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
            rtb_Sqrt_k0 = fmaxf(D, A);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Sqrt_k0 = D;
            guard1 = true;
          } else {
            if ((A >= 0.0F) && (A <= 1.0F)) {
              rtb_Sqrt_k0 = A;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Sqrt_k0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_iq_idx_0 = rtb_MathFunction_h_idx_0 * rtb_Sqrt_k0 +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_iq_idx_1 = rtb_Divide * rtb_Sqrt_k0 +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* MATLAB Function: '<S154>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        A = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Divide +
             (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0]) *
             rtb_MathFunction_h_idx_0) / (rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0 + rtb_Divide * rtb_Divide);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_LogicalOperator_at = (A <= 0.0F);
        u = (A >= 1.0F);
        if (rtb_LogicalOperator_at) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_h_idx_0 = A * rtb_MathFunction_h_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* Switch: '<S154>/Switch1' incorporates:
         *  Constant: '<S187>/Constant'
         *  RelationalOperator: '<S187>/Compare'
         */
        if (rtb_Gain_a <= 0.0F) {
          /* Switch: '<S154>/Switch' incorporates:
           *  Constant: '<S186>/Constant'
           *  MATLAB Function: '<S154>/SearchL1RefWP'
           *  RelationalOperator: '<S186>/Compare'
           */
          if (rtb_Sqrt_k0 >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_iq_idx_0;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_iq_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0;

            /* MATLAB Function: '<S154>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_LogicalOperator_at) {
              /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
              rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
              rtb_TmpSignalConversionAtDela_a[1] = A * rtb_Divide +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            }
          }

          /* End of Switch: '<S154>/Switch' */
        }

        /* End of Switch: '<S154>/Switch1' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S155>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Divide = rtb_TmpSignalConversionAtDela_a[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Divide * rtb_Divide;
        rtb_Saturation1_ln[0] = rtb_Divide;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S155>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S195>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Divide = rtb_TmpSignalConversionAtDela_a[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S195>/Math Function' incorporates:
         *  Math: '<S193>/Square'
         */
        rtb_Gain_a = rtb_Divide * rtb_Divide;

        /* Sum: '<S195>/Sum of Elements' incorporates:
         *  Math: '<S195>/Math Function'
         */
        rtb_Sqrt_k0 = rtb_Gain_a + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S195>/Math Function1' incorporates:
         *  Sum: '<S195>/Sum of Elements'
         *
         * About '<S195>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_k0 < 0.0F) {
          A = -sqrtf(fabsf(rtb_Sqrt_k0));
        } else {
          A = sqrtf(rtb_Sqrt_k0);
        }

        /* End of Math: '<S195>/Math Function1' */

        /* Switch: '<S195>/Switch' incorporates:
         *  Constant: '<S195>/Constant'
         *  Product: '<S195>/Product'
         */
        if (A > 0.0F) {
          rtb_Switch_l[0] = rtb_Saturation1_ln[0];
          rtb_Switch_l[1] = rtb_Divide;
          rtb_Switch_l[2] = A;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S195>/Switch' */

        /* Product: '<S194>/Divide' */
        rtb_Divide_o[0] = rtb_MathFunction_cr_idx_0 / rtb_Rem_k;
        rtb_Divide_o[1] = rtb_MathFunction_cr_idx_1 / rtb_Rem_k;

        /* Sum: '<S197>/Sum of Elements' incorporates:
         *  Math: '<S197>/Math Function'
         *  SignalConversion: '<S197>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Sqrt_k0 = rtb_Divide_o[1] * rtb_Divide_o[1] + rtb_Divide_o[0] *
          rtb_Divide_o[0];

        /* Math: '<S197>/Math Function1' incorporates:
         *  Sum: '<S197>/Sum of Elements'
         *
         * About '<S197>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_k0 < 0.0F) {
          A = -sqrtf(fabsf(rtb_Sqrt_k0));
        } else {
          A = sqrtf(rtb_Sqrt_k0);
        }

        /* End of Math: '<S197>/Math Function1' */

        /* Switch: '<S197>/Switch' incorporates:
         *  Constant: '<S197>/Constant'
         *  Product: '<S197>/Product'
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

        /* End of Switch: '<S197>/Switch' */

        /* Product: '<S195>/Divide' */
        rtb_Divide_o[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Divide_o[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S198>/Sum of Elements' incorporates:
         *  Math: '<S198>/Math Function'
         *  SignalConversion: '<S198>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Sqrt_k0 = rtb_Divide_o[1] * rtb_Divide_o[1] + rtb_Divide_o[0] *
          rtb_Divide_o[0];

        /* Math: '<S198>/Math Function1' incorporates:
         *  Sum: '<S198>/Sum of Elements'
         *
         * About '<S198>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sqrt_k0 < 0.0F) {
          A = -sqrtf(fabsf(rtb_Sqrt_k0));
        } else {
          A = sqrtf(rtb_Sqrt_k0);
        }

        /* End of Math: '<S198>/Math Function1' */

        /* Switch: '<S198>/Switch' incorporates:
         *  Constant: '<S198>/Constant'
         *  Product: '<S198>/Product'
         */
        if (A > 0.0F) {
          rtb_Switch_l[0] = rtb_Divide_o[1];
          rtb_Switch_l[1] = rtb_Divide_o[0];
          rtb_Switch_l[2] = A;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S198>/Switch' */

        /* Product: '<S198>/Divide' */
        rtb_Divide_o[0] = rtb_Switch_l[0] / rtb_Switch_l[2];

        /* Product: '<S197>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_cr_idx_0 /
          rtb_Rem_k;
        rtb_Saturation1_ln[0] *= rtb_Saturation1_ln[0];

        /* Product: '<S198>/Divide' incorporates:
         *  Math: '<S193>/Square'
         */
        rtb_Divide_o[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Product: '<S197>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_cr_idx_1 /
          rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sqrt: '<S192>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S192>/Square'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S192>/Sum of Elements'
         */
        A = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                  FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Gain: '<S155>/Gain' incorporates:
         *  Math: '<S155>/Square'
         */
        rtb_Rem_k = A * A * 2.0F;

        /* Sum: '<S196>/Subtract' incorporates:
         *  Product: '<S196>/Multiply'
         *  Product: '<S196>/Multiply1'
         */
        A = rtb_Divide_o[0] * rtb_TmpSignalConversionAtDela_a[1] - rtb_Divide_o
          [1] * rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S191>/Sign1' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S191>/Sign1' */

        /* Switch: '<S191>/Switch2' incorporates:
         *  Constant: '<S191>/Constant4'
         */
        if (A == 0.0F) {
          A = 1.0F;
        }

        /* End of Switch: '<S191>/Switch2' */

        /* DotProduct: '<S191>/Dot Product' */
        rtb_Sqrt_k0 = rtb_TmpSignalConversionAtDela_a[0] * rtb_Divide_o[0] +
          rtb_TmpSignalConversionAtDela_a[1] * rtb_Divide_o[1];

        /* Trigonometry: '<S191>/Acos' incorporates:
         *  DotProduct: '<S191>/Dot Product'
         */
        if (rtb_Sqrt_k0 > 1.0F) {
          rtb_Sqrt_k0 = 1.0F;
        } else {
          if (rtb_Sqrt_k0 < -1.0F) {
            rtb_Sqrt_k0 = -1.0F;
          }
        }

        /* Product: '<S191>/Multiply' incorporates:
         *  Trigonometry: '<S191>/Acos'
         */
        A *= acosf(rtb_Sqrt_k0);

        /* Saturate: '<S155>/Saturation' */
        if (A > 1.57079637F) {
          A = 1.57079637F;
        } else {
          if (A < -1.57079637F) {
            A = -1.57079637F;
          }
        }

        /* End of Saturate: '<S155>/Saturation' */

        /* Product: '<S155>/Divide' incorporates:
         *  Constant: '<S130>/L1'
         *  Constant: '<S155>/Constant'
         *  MinMax: '<S155>/Max'
         *  MinMax: '<S155>/Min'
         *  Product: '<S155>/Multiply1'
         *  Sqrt: '<S193>/Sqrt'
         *  Sum: '<S193>/Sum of Elements'
         *  Trigonometry: '<S155>/Sin'
         */
        rtb_Rem_k = arm_sin_f32(A) * rtb_Rem_k / fminf(FMS_PARAM.L1, fmaxf(sqrtf
          (rtb_Gain_a + rtb_Saturation1_ln[0]), 0.5F));

        /* Sum: '<S136>/Sum2' incorporates:
         *  Delay: '<S136>/Delay'
         */
        rtb_Saturation_l -= FMS_DW.Delay_DSTATE_h;

        /* Math: '<S140>/Rem' incorporates:
         *  Constant: '<S140>/Constant1'
         */
        rtb_Gain_a = rt_remf(rtb_Saturation_l, 6.28318548F);

        /* Switch: '<S140>/Switch' incorporates:
         *  Abs: '<S140>/Abs'
         *  Constant: '<S140>/Constant'
         *  Constant: '<S146>/Constant'
         *  Product: '<S140>/Multiply'
         *  RelationalOperator: '<S146>/Compare'
         *  Sum: '<S140>/Add'
         */
        if (fabsf(rtb_Gain_a) > 3.14159274F) {
          /* Signum: '<S140>/Sign' */
          if (rtb_Gain_a < 0.0F) {
            rtb_Sqrt_k0 = -1.0F;
          } else if (rtb_Gain_a > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          } else {
            rtb_Sqrt_k0 = rtb_Gain_a;
          }

          /* End of Signum: '<S140>/Sign' */
          rtb_Gain_a -= 6.28318548F * rtb_Sqrt_k0;
        }

        /* End of Switch: '<S140>/Switch' */

        /* Sum: '<S136>/Sum' incorporates:
         *  Delay: '<S136>/Delay'
         */
        rtb_Sqrt_k0 = rtb_Gain_a + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S145>/Multiply1' incorporates:
         *  Constant: '<S145>/const1'
         *  DiscreteIntegrator: '<S139>/Integrator'
         */
        rtb_Gain_a = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S145>/Add' incorporates:
         *  DiscreteIntegrator: '<S139>/Integrator1'
         *  Sum: '<S139>/Subtract'
         */
        A = (FMS_DW.Integrator1_DSTATE_p - rtb_Sqrt_k0) + rtb_Gain_a;

        /* Signum: '<S145>/Sign' */
        if (A < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else if (A > 0.0F) {
          rtb_Sqrt_k0 = 1.0F;
        } else {
          rtb_Sqrt_k0 = A;
        }

        /* End of Signum: '<S145>/Sign' */

        /* Sum: '<S145>/Add2' incorporates:
         *  Abs: '<S145>/Abs'
         *  Gain: '<S145>/Gain'
         *  Gain: '<S145>/Gain1'
         *  Product: '<S145>/Multiply2'
         *  Product: '<S145>/Multiply3'
         *  Sqrt: '<S145>/Sqrt'
         *  Sum: '<S145>/Add1'
         *  Sum: '<S145>/Subtract'
         */
        rtb_Saturation_l = (sqrtf((8.0F * fabsf(A) + FMS_ConstB.d_j) *
          FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_Sqrt_k0 + rtb_Gain_a;

        /* Sum: '<S145>/Add4' */
        rtb_Gain_a += A - rtb_Saturation_l;

        /* Sum: '<S145>/Add3' */
        rtb_Sqrt_k0 = A + FMS_ConstB.d_j;

        /* Sum: '<S145>/Subtract1' */
        A -= FMS_ConstB.d_j;

        /* Signum: '<S145>/Sign1' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S145>/Sign1' */

        /* Signum: '<S145>/Sign2' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S145>/Sign2' */

        /* Sum: '<S145>/Add5' incorporates:
         *  Gain: '<S145>/Gain2'
         *  Product: '<S145>/Multiply4'
         *  Sum: '<S145>/Subtract2'
         */
        rtb_Saturation_l += (rtb_Sqrt_k0 - A) * 0.5F * rtb_Gain_a;

        /* Update for Delay: '<S156>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S200>/Discrete-Time Integrator' incorporates:
         *  Product: '<S156>/Divide1'
         */
        FMS_DW.l1_heading += rtb_Rem_k / rtb_Switch_k * 0.004F;

        /* Update for Delay: '<S136>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S139>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S139>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Sum: '<S145>/Add6' */
        rtb_Sqrt_k0 = rtb_Saturation_l + FMS_ConstB.d_j;

        /* Sum: '<S145>/Subtract3' */
        A = rtb_Saturation_l - FMS_ConstB.d_j;

        /* Signum: '<S145>/Sign5' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_Saturation_l;
        }

        /* End of Signum: '<S145>/Sign5' */

        /* Signum: '<S145>/Sign3' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S145>/Sign3' */

        /* Signum: '<S145>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S145>/Sign4' */

        /* Signum: '<S145>/Sign6' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Gain_a = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Gain_a = 1.0F;
        } else {
          rtb_Gain_a = rtb_Saturation_l;
        }

        /* End of Signum: '<S145>/Sign6' */

        /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
         *  Constant: '<S145>/const'
         *  Gain: '<S145>/Gain3'
         *  Product: '<S145>/Divide'
         *  Product: '<S145>/Multiply5'
         *  Product: '<S145>/Multiply6'
         *  Sum: '<S145>/Subtract4'
         *  Sum: '<S145>/Subtract5'
         *  Sum: '<S145>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_Saturation_l / FMS_ConstB.d_j -
          rtb_Switch_k) * FMS_ConstB.Gain4_c * ((rtb_Sqrt_k0 - A) * 0.5F) -
          rtb_Gain_a * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S139>/Integrator' */
        /* End of Outputs for SubSystem: '<S22>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
         *  ActionPort: '<S132>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S22>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S22>/Switch Case' */
      /* End of Outputs for SubSystem: '<S17>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S17>/Assist' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* SwitchCase: '<S21>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;
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

      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S117>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S36>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S53>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S93>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S69>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S80>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S21>/Acro' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S26>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Gain: '<S31>/Gain'
         *  Gain: '<S31>/Gain1'
         *  Gain: '<S31>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S32>/Saturation' incorporates:
         *  Constant: '<S32>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         *  Sum: '<S32>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Gain_a = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S32>/Saturation' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S32>/Constant5'
         *  Gain: '<S32>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S32>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F * rtb_Gain_a),
          4.2949673E+9F) + 1000U;

        /* End of Outputs for SubSystem: '<S21>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S21>/Stabilize' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S21>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S113>/Integrator'
           *  DiscreteIntegrator: '<S113>/Integrator1'
           *  DiscreteIntegrator: '<S114>/Integrator'
           *  DiscreteIntegrator: '<S114>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_jt = 0.0F;
          FMS_DW.Integrator_DSTATE_cq = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S21>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S21>/Stabilize' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S118>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S21>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Stabilize' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        /* Product: '<S115>/Multiply1' incorporates:
         *  Constant: '<S115>/const1'
         *  DiscreteIntegrator: '<S113>/Integrator'
         */
        A = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S111>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S111>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S115>/Add' incorporates:
         *  DiscreteIntegrator: '<S113>/Integrator1'
         *  Gain: '<S108>/Gain'
         *  Gain: '<S111>/Gain'
         *  Sum: '<S113>/Subtract'
         */
        rtb_Saturation_l = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Gain_a * FMS_PARAM.ROLL_PITCH_LIM) + A;

        /* Signum: '<S115>/Sign' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Sqrt_k0 = 1.0F;
        } else {
          rtb_Sqrt_k0 = rtb_Saturation_l;
        }

        /* End of Signum: '<S115>/Sign' */

        /* Sum: '<S115>/Add2' incorporates:
         *  Abs: '<S115>/Abs'
         *  Gain: '<S115>/Gain'
         *  Gain: '<S115>/Gain1'
         *  Product: '<S115>/Multiply2'
         *  Product: '<S115>/Multiply3'
         *  Sqrt: '<S115>/Sqrt'
         *  Sum: '<S115>/Add1'
         *  Sum: '<S115>/Subtract'
         */
        rtb_Switch_k = (sqrtf((8.0F * fabsf(rtb_Saturation_l) + FMS_ConstB.d_d) *
                              FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
          rtb_Sqrt_k0 + A;

        /* Sum: '<S115>/Add4' */
        rtb_Gain_a = (rtb_Saturation_l - rtb_Switch_k) + A;

        /* Sum: '<S115>/Add3' */
        rtb_Sqrt_k0 = rtb_Saturation_l + FMS_ConstB.d_d;

        /* Sum: '<S115>/Subtract1' */
        rtb_Saturation_l -= FMS_ConstB.d_d;

        /* Signum: '<S115>/Sign1' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S115>/Sign1' */

        /* Signum: '<S115>/Sign2' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S115>/Sign2' */

        /* Sum: '<S115>/Add5' incorporates:
         *  Gain: '<S115>/Gain2'
         *  Product: '<S115>/Multiply4'
         *  Sum: '<S115>/Subtract2'
         */
        rtb_Switch_k += (rtb_Sqrt_k0 - rtb_Saturation_l) * 0.5F * rtb_Gain_a;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S118>/Motion State' incorporates:
         *  Abs: '<S118>/Abs'
         *  Abs: '<S118>/Abs1'
         *  Constant: '<S128>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S128>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S117>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S117>/Hold Control' incorporates:
             *  ActionPort: '<S120>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S117>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S117>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S117>/Hold Control' incorporates:
           *  ActionPort: '<S120>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                             &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S117>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S117>/Brake Control' incorporates:
           *  ActionPort: '<S119>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S117>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S117>/Move Control' incorporates:
             *  ActionPort: '<S121>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S117>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S117>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S117>/Move Control' incorporates:
           *  ActionPort: '<S121>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S117>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S117>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S29>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S29>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  DiscreteIntegrator: '<S113>/Integrator1'
         *  DiscreteIntegrator: '<S114>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_j;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_jt;

        /* Saturate: '<S117>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S29>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S117>/Saturation' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Saturate: '<S110>/Saturation' incorporates:
         *  Constant: '<S110>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         *  Sum: '<S110>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Gain_a = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S110>/Saturation' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S110>/Constant5'
         *  Gain: '<S110>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S110>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F * rtb_Gain_a),
          4.2949673E+9F) + 1000U;

        /* Product: '<S116>/Multiply1' incorporates:
         *  Constant: '<S116>/const1'
         *  DiscreteIntegrator: '<S114>/Integrator'
         */
        rtb_Saturation_l = FMS_DW.Integrator_DSTATE_cq * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S112>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S112>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S116>/Add' incorporates:
         *  DiscreteIntegrator: '<S114>/Integrator1'
         *  Gain: '<S108>/Gain1'
         *  Gain: '<S112>/Gain'
         *  Sum: '<S114>/Subtract'
         */
        A = (FMS_DW.Integrator1_DSTATE_jt - 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
             rtb_Gain_a * -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Saturation_l;

        /* Signum: '<S116>/Sign' */
        if (A < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else if (A > 0.0F) {
          rtb_Sqrt_k0 = 1.0F;
        } else {
          rtb_Sqrt_k0 = A;
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
        rtb_Gain_a = (sqrtf((8.0F * fabsf(A) + FMS_ConstB.d_o) * FMS_ConstB.d_o)
                      - FMS_ConstB.d_o) * 0.5F * rtb_Sqrt_k0 + rtb_Saturation_l;

        /* Sum: '<S116>/Add4' */
        rtb_Saturation_l += A - rtb_Gain_a;

        /* Sum: '<S116>/Add3' */
        rtb_Sqrt_k0 = A + FMS_ConstB.d_o;

        /* Sum: '<S116>/Subtract1' */
        A -= FMS_ConstB.d_o;

        /* Signum: '<S116>/Sign1' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign1' */

        /* Signum: '<S116>/Sign2' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S116>/Sign2' */

        /* Sum: '<S116>/Add5' incorporates:
         *  Gain: '<S116>/Gain2'
         *  Product: '<S116>/Multiply4'
         *  Sum: '<S116>/Subtract2'
         */
        rtb_Gain_a += (rtb_Sqrt_k0 - A) * 0.5F * rtb_Saturation_l;

        /* Update for DiscreteIntegrator: '<S113>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S113>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S115>/Add6' */
        rtb_Sqrt_k0 = rtb_Switch_k + FMS_ConstB.d_d;

        /* Sum: '<S115>/Subtract3' */
        A = rtb_Switch_k - FMS_ConstB.d_d;

        /* Signum: '<S115>/Sign5' */
        if (rtb_Switch_k < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else if (rtb_Switch_k > 0.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          rtb_Saturation_l = rtb_Switch_k;
        }

        /* End of Signum: '<S115>/Sign5' */

        /* Signum: '<S115>/Sign3' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S115>/Sign3' */

        /* Signum: '<S115>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S115>/Sign4' */

        /* Signum: '<S115>/Sign6' */
        if (rtb_Switch_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else if (rtb_Switch_k > 0.0F) {
          rtb_Rem_k = 1.0F;
        } else {
          rtb_Rem_k = rtb_Switch_k;
        }

        /* End of Signum: '<S115>/Sign6' */

        /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
         *  Constant: '<S115>/const'
         *  Gain: '<S115>/Gain3'
         *  Product: '<S115>/Divide'
         *  Product: '<S115>/Multiply5'
         *  Product: '<S115>/Multiply6'
         *  Sum: '<S115>/Subtract4'
         *  Sum: '<S115>/Subtract5'
         *  Sum: '<S115>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Switch_k / FMS_ConstB.d_d -
          rtb_Saturation_l) * FMS_ConstB.Gain4_n * ((rtb_Sqrt_k0 - A) * 0.5F) -
          rtb_Rem_k * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S114>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S114>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_jt += 0.004F * FMS_DW.Integrator_DSTATE_cq;

        /* Sum: '<S116>/Add6' */
        rtb_Sqrt_k0 = rtb_Gain_a + FMS_ConstB.d_o;

        /* Sum: '<S116>/Subtract3' */
        A = rtb_Gain_a - FMS_ConstB.d_o;

        /* Signum: '<S116>/Sign5' */
        if (rtb_Gain_a < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_Gain_a > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_Gain_a;
        }

        /* End of Signum: '<S116>/Sign5' */

        /* Signum: '<S116>/Sign3' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
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
        if (rtb_Gain_a < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else if (rtb_Gain_a > 0.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          rtb_Saturation_l = rtb_Gain_a;
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
        FMS_DW.Integrator_DSTATE_cq += ((rtb_Gain_a / FMS_ConstB.d_o -
          rtb_Switch_k) * FMS_ConstB.Gain4_n3 * ((rtb_Sqrt_k0 - A) * 0.5F) -
          rtb_Saturation_l * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S21>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S21>/Altitude' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S21>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S49>/Integrator'
           *  DiscreteIntegrator: '<S49>/Integrator1'
           *  DiscreteIntegrator: '<S50>/Integrator'
           *  DiscreteIntegrator: '<S50>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S21>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S21>/Altitude' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S37>/Motion Status'
           *  Chart: '<S54>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S21>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Altitude' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S37>/Motion Status' incorporates:
         *  Abs: '<S37>/Abs'
         *  Abs: '<S37>/Abs1'
         *  Constant: '<S45>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S45>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S36>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S36>/Hold Control' incorporates:
             *  ActionPort: '<S39>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S36>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S36>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S36>/Hold Control' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S36>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S36>/Brake Control' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S36>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S36>/Move Control' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S36>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

            /* End of SystemReset for SubSystem: '<S36>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S36>/Move Control' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_l,
                          &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S36>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S36>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S54>/Motion State' incorporates:
         *  Abs: '<S54>/Abs'
         *  Abs: '<S54>/Abs1'
         *  Constant: '<S64>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S64>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S53>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S53>/Hold Control' incorporates:
             *  ActionPort: '<S56>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S53>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S53>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S53>/Hold Control' incorporates:
           *  ActionPort: '<S56>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                             &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S53>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S53>/Brake Control' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S53>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S53>/Move Control' incorporates:
             *  ActionPort: '<S57>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S53>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_cr);

            /* End of SystemReset for SubSystem: '<S53>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S53>/Move Control' incorporates:
           *  ActionPort: '<S57>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_cr, &FMS_DW.MoveControl_cr);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S53>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S53>/Switch Case' */

        /* Product: '<S51>/Multiply1' incorporates:
         *  Constant: '<S51>/const1'
         *  DiscreteIntegrator: '<S49>/Integrator'
         */
        rtb_Saturation_l = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S47>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S47>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S51>/Add' incorporates:
         *  DiscreteIntegrator: '<S49>/Integrator1'
         *  Gain: '<S34>/Gain'
         *  Gain: '<S47>/Gain'
         *  Sum: '<S49>/Subtract'
         */
        rtb_Switch_k = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Gain_a * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Saturation_l;

        /* Signum: '<S51>/Sign' */
        if (rtb_Switch_k < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else if (rtb_Switch_k > 0.0F) {
          rtb_Sqrt_k0 = 1.0F;
        } else {
          rtb_Sqrt_k0 = rtb_Switch_k;
        }

        /* End of Signum: '<S51>/Sign' */

        /* Sum: '<S51>/Add2' incorporates:
         *  Abs: '<S51>/Abs'
         *  Gain: '<S51>/Gain'
         *  Gain: '<S51>/Gain1'
         *  Product: '<S51>/Multiply2'
         *  Product: '<S51>/Multiply3'
         *  Sqrt: '<S51>/Sqrt'
         *  Sum: '<S51>/Add1'
         *  Sum: '<S51>/Subtract'
         */
        rtb_Rem_k = (sqrtf((8.0F * fabsf(rtb_Switch_k) + FMS_ConstB.d) *
                           FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Sqrt_k0 +
          rtb_Saturation_l;

        /* Sum: '<S51>/Add4' */
        rtb_Gain_a = (rtb_Switch_k - rtb_Rem_k) + rtb_Saturation_l;

        /* Sum: '<S51>/Add3' */
        rtb_Sqrt_k0 = rtb_Switch_k + FMS_ConstB.d;

        /* Sum: '<S51>/Subtract1' */
        rtb_Switch_k -= FMS_ConstB.d;

        /* Signum: '<S51>/Sign1' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S51>/Sign1' */

        /* Signum: '<S51>/Sign2' */
        if (rtb_Switch_k < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else {
          if (rtb_Switch_k > 0.0F) {
            rtb_Switch_k = 1.0F;
          }
        }

        /* End of Signum: '<S51>/Sign2' */

        /* Sum: '<S51>/Add5' incorporates:
         *  Gain: '<S51>/Gain2'
         *  Product: '<S51>/Multiply4'
         *  Sum: '<S51>/Subtract2'
         */
        rtb_Rem_k += (rtb_Sqrt_k0 - rtb_Switch_k) * 0.5F * rtb_Gain_a;

        /* Sum: '<S51>/Subtract3' */
        rtb_Sqrt_k0 = rtb_Rem_k - FMS_ConstB.d;

        /* Sum: '<S51>/Add6' */
        A = rtb_Rem_k + FMS_ConstB.d;

        /* Product: '<S51>/Divide' */
        rtb_Divide = rtb_Rem_k / FMS_ConstB.d;

        /* Signum: '<S51>/Sign5' incorporates:
         *  Signum: '<S51>/Sign6'
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_MathFunction_h_idx_0 = -1.0F;
          rtb_Switch_k = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_MathFunction_h_idx_0 = 1.0F;
          rtb_Switch_k = 1.0F;
        } else {
          rtb_MathFunction_h_idx_0 = rtb_Rem_k;
          rtb_Switch_k = rtb_Rem_k;
        }

        /* End of Signum: '<S51>/Sign5' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S27>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S27>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  DiscreteIntegrator: '<S49>/Integrator1'
         *  DiscreteIntegrator: '<S50>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S53>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S53>/Saturation' */

        /* Saturate: '<S36>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S36>/Saturation1' */

        /* Product: '<S52>/Multiply1' incorporates:
         *  Constant: '<S52>/const1'
         *  DiscreteIntegrator: '<S50>/Integrator'
         */
        rtb_Rem_k = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S48>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Gain_a = 0.0F;
        } else {
          rtb_Gain_a = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S48>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S52>/Add' incorporates:
         *  DiscreteIntegrator: '<S50>/Integrator1'
         *  Gain: '<S34>/Gain1'
         *  Gain: '<S48>/Gain'
         *  Sum: '<S50>/Subtract'
         */
        rtb_Saturation_l = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * rtb_Gain_a * -FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Rem_k;

        /* Signum: '<S52>/Sign' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Gain_a = -1.0F;
        } else if (rtb_Saturation_l > 0.0F) {
          rtb_Gain_a = 1.0F;
        } else {
          rtb_Gain_a = rtb_Saturation_l;
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
        rtb_Gain_a = (sqrtf((8.0F * fabsf(rtb_Saturation_l) + FMS_ConstB.d_c) *
                            FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
          rtb_Gain_a + rtb_Rem_k;

        /* Sum: '<S52>/Add4' */
        rtb_Rem_k += rtb_Saturation_l - rtb_Gain_a;

        /* Sum: '<S52>/Add3' */
        rtb_MathFunction_cr_idx_0 = rtb_Saturation_l + FMS_ConstB.d_c;

        /* Sum: '<S52>/Subtract1' */
        rtb_Saturation_l -= FMS_ConstB.d_c;

        /* Signum: '<S52>/Sign1' */
        if (rtb_MathFunction_cr_idx_0 < 0.0F) {
          rtb_MathFunction_cr_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_cr_idx_0 > 0.0F) {
            rtb_MathFunction_cr_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign1' */

        /* Signum: '<S52>/Sign2' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign2' */

        /* Sum: '<S52>/Add5' incorporates:
         *  Gain: '<S52>/Gain2'
         *  Product: '<S52>/Multiply4'
         *  Sum: '<S52>/Subtract2'
         */
        rtb_Gain_a += (rtb_MathFunction_cr_idx_0 - rtb_Saturation_l) * 0.5F *
          rtb_Rem_k;

        /* Update for DiscreteIntegrator: '<S49>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S49>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S51>/Sign3' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S51>/Sign3' */

        /* Signum: '<S51>/Sign4' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S51>/Sign4' */

        /* Update for DiscreteIntegrator: '<S49>/Integrator' incorporates:
         *  Constant: '<S51>/const'
         *  Gain: '<S51>/Gain3'
         *  Product: '<S51>/Multiply5'
         *  Product: '<S51>/Multiply6'
         *  Sum: '<S51>/Subtract4'
         *  Sum: '<S51>/Subtract5'
         *  Sum: '<S51>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_Divide - rtb_MathFunction_h_idx_0) *
          FMS_ConstB.Gain4 * ((A - rtb_Sqrt_k0) * 0.5F) - rtb_Switch_k *
          12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S50>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S50>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S52>/Add6' */
        rtb_Sqrt_k0 = rtb_Gain_a + FMS_ConstB.d_c;

        /* Sum: '<S52>/Subtract3' */
        A = rtb_Gain_a - FMS_ConstB.d_c;

        /* Signum: '<S52>/Sign5' */
        if (rtb_Gain_a < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_Gain_a > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_Gain_a;
        }

        /* End of Signum: '<S52>/Sign5' */

        /* Signum: '<S52>/Sign3' */
        if (rtb_Sqrt_k0 < 0.0F) {
          rtb_Sqrt_k0 = -1.0F;
        } else {
          if (rtb_Sqrt_k0 > 0.0F) {
            rtb_Sqrt_k0 = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign3' */

        /* Signum: '<S52>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S52>/Sign4' */

        /* Signum: '<S52>/Sign6' */
        if (rtb_Gain_a < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else if (rtb_Gain_a > 0.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          rtb_Saturation_l = rtb_Gain_a;
        }

        /* End of Signum: '<S52>/Sign6' */

        /* Update for DiscreteIntegrator: '<S50>/Integrator' incorporates:
         *  Constant: '<S52>/const'
         *  Gain: '<S52>/Gain3'
         *  Product: '<S52>/Divide'
         *  Product: '<S52>/Multiply5'
         *  Product: '<S52>/Multiply6'
         *  Sum: '<S52>/Subtract4'
         *  Sum: '<S52>/Subtract5'
         *  Sum: '<S52>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Gain_a / FMS_ConstB.d_c -
          rtb_Switch_k) * FMS_ConstB.Gain4_m * ((rtb_Sqrt_k0 - A) * 0.5F) -
          rtb_Saturation_l * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S21>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Position' incorporates:
           *  ActionPort: '<S28>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S70>/Motion Status'
           *  Chart: '<S81>/Motion State'
           *  Chart: '<S94>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_i);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S21>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Position' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S70>/Motion Status' incorporates:
         *  Abs: '<S70>/Abs'
         *  Abs: '<S70>/Abs1'
         *  Constant: '<S78>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S78>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_i);

        /* Chart: '<S81>/Motion State' incorporates:
         *  Abs: '<S81>/Abs'
         *  Abs: '<S81>/Abs1'
         *  Constant: '<S91>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S91>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_ki,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S94>/Logical Operator' incorporates:
         *  Abs: '<S94>/Abs1'
         *  Abs: '<S94>/Abs2'
         *  Constant: '<S105>/Constant'
         *  Constant: '<S106>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S105>/Compare'
         *  RelationalOperator: '<S106>/Compare'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtb_LogicalOperator_at = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Chart: '<S94>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S94>/Square'
         *  Math: '<S94>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S94>/Sqrt'
         *  Sum: '<S94>/Add'
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

            /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_i
                 >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_d;
              rtb_state_l = MotionState_Hold;
            } else {
              if (rtb_LogicalOperator_at) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_n;
                rtb_state_l = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_l = MotionState_Hold;
            if (rtb_LogicalOperator_at) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_n;
              rtb_state_l = MotionState_Move;
            }
            break;

           default:
            rtb_state_l = MotionState_Move;
            if (!rtb_LogicalOperator_at) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_l = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S94>/Motion State' */

        /* SwitchCase: '<S93>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S93>/Hold Control' incorporates:
             *  ActionPort: '<S96>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S93>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S93>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S93>/Hold Control' incorporates:
           *  ActionPort: '<S96>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S93>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S93>/Brake Control' incorporates:
           *  ActionPort: '<S95>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S93>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S93>/Move Control' incorporates:
             *  ActionPort: '<S97>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S93>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S93>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S93>/Move Control' incorporates:
           *  ActionPort: '<S97>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S93>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S93>/Switch Case' */

        /* SwitchCase: '<S69>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S69>/Hold Control' incorporates:
             *  ActionPort: '<S72>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S69>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S69>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S69>/Hold Control' incorporates:
           *  ActionPort: '<S72>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S69>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S69>/Brake Control' incorporates:
           *  ActionPort: '<S71>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S69>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S69>/Move Control' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S69>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_be);

            /* End of SystemReset for SubSystem: '<S69>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S69>/Move Control' incorporates:
           *  ActionPort: '<S73>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_k,
                          &FMS_ConstB.MoveControl_be, &FMS_DW.MoveControl_be);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S69>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S69>/Switch Case' */

        /* SwitchCase: '<S80>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S80>/Hold Control' incorporates:
             *  ActionPort: '<S83>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S80>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S80>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S80>/Hold Control' incorporates:
           *  ActionPort: '<S83>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                             &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S80>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S80>/Brake Control' incorporates:
           *  ActionPort: '<S82>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S80>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S80>/Move Control' incorporates:
             *  ActionPort: '<S84>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S80>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_mr);

            /* End of SystemReset for SubSystem: '<S80>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S80>/Move Control' incorporates:
           *  ActionPort: '<S84>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_mr, &FMS_DW.MoveControl_mr);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S80>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S80>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S28>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S28>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S80>/Saturation' */
        if (FMS_B.Merge_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_d;
        }

        /* End of Saturate: '<S80>/Saturation' */

        /* Saturate: '<S93>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S93>/Saturation1' */

        /* Saturate: '<S69>/Saturation1' */
        if (FMS_B.Merge_k > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_k < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_k;
        }

        /* End of Saturate: '<S69>/Saturation1' */
        /* End of Outputs for SubSystem: '<S21>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S21>/Unknown' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S21>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S21>/Switch Case' */
      /* End of Outputs for SubSystem: '<S17>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S17>/Manual' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S23>/Bus Assignment'
       *  BusAssignment: '<S2>/Bus Assignment'
       *  Constant: '<S23>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S2>/Bus Assignment'
       *  Constant: '<S23>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S17>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S17>/Unknown' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S2>/Bus Assignment'
       */
      FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S17>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S17>/Switch Case' */
    /* End of Outputs for SubSystem: '<S2>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  Sum: '<S2>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S20>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Update for UnitDelay: '<S11>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  rtb_Gain_a = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Gain_a < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Gain_a;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S16>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S12>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S12>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S13>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S13>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for DiscreteIntegrator: '<S342>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S342>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In3'
   *  Sum: '<S342>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (FMS_U.INS_Out.ax -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (FMS_U.INS_Out.ay -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (FMS_U.INS_Out.az -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S343>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S343>/Gain'
   *  Sum: '<S343>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;
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
  /* Start for SwitchCase: '<S2>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S2>/Arm' */
  /* Start for SwitchCase: '<S17>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S17>/SubMode' */
  /* Start for SwitchCase: '<S24>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_at = -1;

  /* Start for IfAction SubSystem: '<S24>/Return' */
  /* Start for SwitchCase: '<S288>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S278>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S24>/Return' */

  /* Start for IfAction SubSystem: '<S24>/Hold' */
  /* Start for SwitchCase: '<S234>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S212>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S222>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S24>/Hold' */
  /* End of Start for SubSystem: '<S17>/SubMode' */

  /* Start for IfAction SubSystem: '<S17>/Auto' */
  /* Start for SwitchCase: '<S22>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S22>/Mission' */
  /* Start for SwitchCase: '<S173>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S163>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S22>/Mission' */
  /* End of Start for SubSystem: '<S17>/Auto' */

  /* Start for IfAction SubSystem: '<S17>/Assist' */
  /* Start for SwitchCase: '<S21>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S21>/Stabilize' */
  /* Start for SwitchCase: '<S117>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S21>/Stabilize' */

  /* Start for IfAction SubSystem: '<S21>/Altitude' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S53>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S21>/Altitude' */

  /* Start for IfAction SubSystem: '<S21>/Position' */
  /* Start for SwitchCase: '<S93>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S69>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S80>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S21>/Position' */
  /* End of Start for SubSystem: '<S17>/Assist' */
  /* End of Start for SubSystem: '<S2>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */

  /* InitializeConditions for DiscreteIntegrator: '<S342>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S343>/Discrete-Time Integrator5' */
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
  /* SystemInitialize for IfAction SubSystem: '<S2>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S17>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S24>/Return' */
  /* InitializeConditions for Delay: '<S274>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S315>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_p = 0.0F;

  /* InitializeConditions for Delay: '<S254>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for Delay: '<S255>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S258>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S258>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S289>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S288>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S288>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S288>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S288>/Move Control' */

  /* SystemInitialize for Merge: '<S288>/Merge' */
  FMS_B.Merge_mv[0] = 0.0F;
  FMS_B.Merge_mv[1] = 0.0F;

  /* SystemInitialize for Chart: '<S279>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S278>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S278>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S278>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S278>/Move Control' */

  /* SystemInitialize for Merge: '<S278>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S24>/Hold' */
  /* SystemInitialize for Chart: '<S213>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S223>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S235>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S234>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S234>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S234>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S234>/Move Control' */

  /* SystemInitialize for Merge: '<S234>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S212>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S212>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S212>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S212>/Move Control' */

  /* SystemInitialize for Merge: '<S212>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S222>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_kq);

  /* End of SystemInitialize for SubSystem: '<S222>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S222>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S222>/Move Control' */

  /* SystemInitialize for Merge: '<S222>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S17>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Mission' */
  /* InitializeConditions for Delay: '<S156>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S200>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S136>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S174>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S173>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S173>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S173>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S173>/Move Control' */

  /* SystemInitialize for Merge: '<S173>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S164>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S163>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S163>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S163>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S163>/Move Control' */

  /* SystemInitialize for Merge: '<S163>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S22>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S17>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S21>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jt = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator' */
  FMS_DW.Integrator_DSTATE_cq = 0.0F;

  /* SystemInitialize for Chart: '<S118>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S117>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S117>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S117>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S117>/Move Control' */

  /* SystemInitialize for Merge: '<S117>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S49>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S37>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S36>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S36>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S36>/Move Control' */

  /* SystemInitialize for Chart: '<S54>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S53>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S53>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S53>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_cr);

  /* End of SystemInitialize for SubSystem: '<S53>/Move Control' */

  /* SystemInitialize for Merge: '<S36>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Merge: '<S53>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/Position' */
  /* SystemInitialize for Chart: '<S70>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for Chart: '<S81>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S94>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S93>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S93>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S93>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S93>/Move Control' */

  /* SystemInitialize for Merge: '<S93>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S69>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S69>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S69>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_be);

  /* End of SystemInitialize for SubSystem: '<S69>/Move Control' */

  /* SystemInitialize for Merge: '<S69>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S80>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S80>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S80>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_mr);

  /* End of SystemInitialize for SubSystem: '<S80>/Move Control' */

  /* SystemInitialize for Merge: '<S80>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Position' */
  /* End of SystemInitialize for SubSystem: '<S17>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S2>/Arm' */
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
