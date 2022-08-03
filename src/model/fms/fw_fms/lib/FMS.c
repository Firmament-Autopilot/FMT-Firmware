/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1863
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug  3 14:36:12 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S265>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S38>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S275>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

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
struct_iFzoGS6ezHkwxeSA09xa0B FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.95F,
  1.0F,
  2.5F,
  2.5F,
  1.04719758F,
  0.52359879F,
  10.0F,
  13.0F,
  1.5F,
  0.5F,
  0.95F,
  5.0F,
  0.52359879F,
  0.52359879F,
  20.0F,

  { 1000.0F, 1000.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 1000.0F, 1000.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },
  5.0F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S315>/Constant'
                                        *   '<S19>/Constant6'
                                        *   '<S20>/Constant6'
                                        *   '<S192>/L1'
                                        *   '<S33>/Gain'
                                        *   '<S35>/Gain'
                                        *   '<S36>/Gain1'
                                        *   '<S54>/Gain'
                                        *   '<S56>/Gain1'
                                        *   '<S100>/Gain'
                                        *   '<S100>/Gain1'
                                        *   '<S101>/Gain1'
                                        *   '<S116>/L1'
                                        *   '<S233>/Saturation1'
                                        *   '<S306>/Gain2'
                                        *   '<S306>/Saturation1'
                                        *   '<S37>/Saturation1'
                                        *   '<S48>/Dead Zone'
                                        *   '<S48>/Gain'
                                        *   '<S51>/Dead Zone'
                                        *   '<S51>/Gain'
                                        *   '<S58>/Saturation1'
                                        *   '<S69>/Dead Zone'
                                        *   '<S69>/Gain'
                                        *   '<S72>/Saturation1'
                                        *   '<S103>/Dead Zone'
                                        *   '<S103>/Gain'
                                        *   '<S104>/Dead Zone'
                                        *   '<S104>/Gain'
                                        *   '<S109>/Dead Zone'
                                        *   '<S109>/Gain'
                                        *   '<S198>/Saturation1'
                                        *   '<S208>/Saturation'
                                        *   '<S234>/Gain2'
                                        *   '<S256>/vel'
                                        *   '<S256>/Saturation'
                                        *   '<S256>/Switch'
                                        *   '<S40>/Gain2'
                                        *   '<S41>/Gain1'
                                        *   '<S46>/Constant'
                                        *   '<S61>/Gain2'
                                        *   '<S62>/Gain1'
                                        *   '<S67>/Constant'
                                        *   '<S75>/L1'
                                        *   '<S76>/Gain6'
                                        *   '<S96>/Constant'
                                        *   '<S135>/Gain'
                                        *   '<S135>/Saturation1'
                                        *   '<S136>/vel'
                                        *   '<S136>/Saturation'
                                        *   '<S136>/Switch'
                                        *   '<S201>/Gain2'
                                        *   '<S202>/Gain1'
                                        *   '<S211>/Gain2'
                                        *   '<S212>/Gain1'
                                        *   '<S243>/Gain2'
                                        *   '<S243>/Saturation'
                                        *   '<S244>/Integrator'
                                        *   '<S43>/Dead Zone'
                                        *   '<S43>/Gain'
                                        *   '<S64>/Dead Zone'
                                        *   '<S64>/Gain'
                                        *   '<S93>/Dead Zone'
                                        *   '<S93>/Gain'
                                        *   '<S122>/Gain2'
                                        *   '<S122>/Saturation'
                                        *   '<S123>/Integrator'
                                        *   '<S204>/Dead Zone'
                                        *   '<S204>/Gain'
                                        *   '<S216>/Dead Zone'
                                        *   '<S216>/Gain'
                                        *   '<S264>/Saturation1'
                                        *   '<S274>/Saturation1'
                                        *   '<S267>/Gain2'
                                        *   '<S268>/Gain1'
                                        *   '<S277>/Gain2'
                                        *   '<S278>/Gain6'
                                        *   '<S270>/Dead Zone'
                                        *   '<S270>/Gain'
                                        *   '<S282>/Dead Zone'
                                        *   '<S282>/Gain'
                                        *   '<S283>/Dead Zone'
                                        *   '<S283>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 70, 87, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S313>/Constant'
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
 * System initialize for action system:
 *    '<S264>/Hold Control'
 *    '<S198>/Hold Control'
 *    '<S37>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S267>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S264>/Hold Control'
 *    '<S198>/Hold Control'
 *    '<S37>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S267>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S264>/Hold Control'
 *    '<S198>/Hold Control'
 *    '<S37>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S267>/Delay' incorporates:
   *  Gain: '<S269>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S267>/Gain2' incorporates:
   *  Delay: '<S267>/Delay'
   *  Gain: '<S269>/Gain'
   *  Sum: '<S267>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S267>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S264>/Brake Control'
 *    '<S198>/Brake Control'
 *    '<S208>/Brake Control'
 *    '<S37>/Brake Control'
 *    '<S58>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S266>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S266>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S264>/Move Control'
 *    '<S198>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S271>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S271>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S264>/Move Control'
 *    '<S198>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S271>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S271>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S264>/Move Control'
 *    '<S198>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3_c;
  real32_T rtb_Subtract3_dn;
  real32_T rtb_a_hr;
  real32_T rtb_Add4_g;
  real32_T rtb_a_ba;

  /* Product: '<S272>/Multiply1' incorporates:
   *  Constant: '<S272>/const1'
   *  DiscreteIntegrator: '<S271>/Integrator'
   */
  rtb_Add3_c = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S270>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = 0.0F;
  } else {
    rtb_a_hr = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S270>/Dead Zone' */

  /* Sum: '<S272>/Add' incorporates:
   *  DiscreteIntegrator: '<S271>/Integrator1'
   *  Gain: '<S268>/Gain1'
   *  Gain: '<S270>/Gain'
   *  Sum: '<S271>/Subtract'
   */
  rtb_Subtract3_dn = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_hr * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_c;

  /* Signum: '<S272>/Sign' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_a_hr = -1.0F;
  } else if (rtb_Subtract3_dn > 0.0F) {
    rtb_a_hr = 1.0F;
  } else {
    rtb_a_hr = rtb_Subtract3_dn;
  }

  /* End of Signum: '<S272>/Sign' */

  /* Sum: '<S272>/Add2' incorporates:
   *  Abs: '<S272>/Abs'
   *  Gain: '<S272>/Gain'
   *  Gain: '<S272>/Gain1'
   *  Product: '<S272>/Multiply2'
   *  Product: '<S272>/Multiply3'
   *  Sqrt: '<S272>/Sqrt'
   *  Sum: '<S272>/Add1'
   *  Sum: '<S272>/Subtract'
   */
  rtb_a_hr = (sqrtf((8.0F * fabsf(rtb_Subtract3_dn) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_hr + rtb_Add3_c;

  /* Sum: '<S272>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_dn - rtb_a_hr) + rtb_Add3_c;

  /* Sum: '<S272>/Add3' */
  rtb_Add3_c = rtb_Subtract3_dn + localC->d;

  /* Sum: '<S272>/Subtract1' */
  rtb_Subtract3_dn -= localC->d;

  /* Signum: '<S272>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S272>/Sign1' */

  /* Signum: '<S272>/Sign2' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S272>/Sign2' */

  /* Sum: '<S272>/Add5' incorporates:
   *  Gain: '<S272>/Gain2'
   *  Product: '<S272>/Multiply4'
   *  Sum: '<S272>/Subtract2'
   */
  rtb_a_hr += (rtb_Add3_c - rtb_Subtract3_dn) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S268>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S271>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S271>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S271>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S272>/Add6' */
  rtb_Add3_c = rtb_a_hr + localC->d;

  /* Sum: '<S272>/Subtract3' */
  rtb_Subtract3_dn = rtb_a_hr - localC->d;

  /* Signum: '<S272>/Sign5' */
  if (rtb_a_hr < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_hr;
  }

  /* End of Signum: '<S272>/Sign5' */

  /* Signum: '<S272>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S272>/Sign3' */

  /* Signum: '<S272>/Sign4' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S272>/Sign4' */

  /* Signum: '<S272>/Sign6' */
  if (rtb_a_hr < 0.0F) {
    rtb_a_ba = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_a_ba = 1.0F;
  } else {
    rtb_a_ba = rtb_a_hr;
  }

  /* End of Signum: '<S272>/Sign6' */

  /* Update for DiscreteIntegrator: '<S271>/Integrator' incorporates:
   *  Constant: '<S272>/const'
   *  Gain: '<S272>/Gain3'
   *  Product: '<S272>/Divide'
   *  Product: '<S272>/Multiply5'
   *  Product: '<S272>/Multiply6'
   *  Sum: '<S272>/Subtract4'
   *  Sum: '<S272>/Subtract5'
   *  Sum: '<S272>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_hr / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3_c - rtb_Subtract3_dn) * 0.5F) - rtb_a_ba *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S265>/Motion Status'
 *    '<S199>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S265>/Motion Status'
 *    '<S199>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S265>/Motion Status'
 *    '<S199>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S265>/Motion Status' */
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

  /* End of Chart: '<S265>/Motion Status' */
}

/*
 * Output and update for atomic system:
 *    '<S258>/NearbyRefWP'
 *    '<S138>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S289>/TmpSignal ConversionAt SFunction Inport2' */
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
 * Output and update for action system:
 *    '<S24>/Unknown'
 *    '<S22>/Unknown'
 *    '<S21>/Unknown'
 *    '<S17>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S194>/Bus Assignment' incorporates:
   *  Constant: '<S194>/Constant'
   *  Constant: '<S194>/Constant2'
   *  SignalConversion: '<S194>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S194>/Bus Assignment' */
}

/*
 * Output and update for action system:
 *    '<S37>/Move Control'
 *    '<S58>/Move Control'
 */
void FMS_MoveControl_l(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs)
{
  real32_T rtu_FMS_In_0;

  /* DeadZone: '<S43>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtu_FMS_In_0 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtu_FMS_In_0 = 0.0F;
  } else {
    rtu_FMS_In_0 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S43>/Dead Zone' */

  /* Gain: '<S41>/Gain1' incorporates:
   *  Gain: '<S43>/Gain'
   */
  *rty_w_cmd_mPs = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtu_FMS_In_0 *
    FMS_PARAM.VEL_Z_LIM;
}

/*
 * System initialize for atomic system:
 *    '<S38>/Motion Status'
 *    '<S59>/Motion Status'
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
 *    '<S59>/Motion Status'
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
 *    '<S59>/Motion Status'
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
  real_T rtb_Gain_lq;
  real_T rtb_Sum3;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S317>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S318>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S318>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S318>/Multiply1' incorporates:
   *  Product: '<S318>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S318>/Divide' incorporates:
   *  Constant: '<S318>/Constant'
   *  Constant: '<S318>/R'
   *  Sqrt: '<S318>/Sqrt'
   *  Sum: '<S318>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S318>/Product3' incorporates:
   *  Constant: '<S318>/Constant1'
   *  Product: '<S318>/Multiply1'
   *  Sum: '<S318>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S318>/Multiply2' incorporates:
   *  Trigonometry: '<S318>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S317>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S322>/Abs' incorporates:
   *  Abs: '<S325>/Abs1'
   *  Switch: '<S322>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S322>/Switch1' incorporates:
   *  Abs: '<S322>/Abs'
   *  Bias: '<S322>/Bias2'
   *  Bias: '<S322>/Bias3'
   *  Constant: '<S319>/Constant'
   *  Constant: '<S319>/Constant1'
   *  Constant: '<S324>/Constant'
   *  Gain: '<S322>/Gain1'
   *  Product: '<S322>/Multiply'
   *  RelationalOperator: '<S324>/Compare'
   *  Switch: '<S319>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S325>/Switch1' incorporates:
     *  Bias: '<S325>/Bias2'
     *  Bias: '<S325>/Bias3'
     *  Constant: '<S325>/Constant'
     *  Constant: '<S326>/Constant'
     *  Math: '<S325>/Math Function'
     *  RelationalOperator: '<S326>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S325>/Switch1' */

    /* Signum: '<S322>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S322>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S319>/Sum' incorporates:
   *  Sum: '<S317>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S317>/Multiply' incorporates:
   *  Gain: '<S317>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S321>/Switch1' incorporates:
   *  Abs: '<S321>/Abs1'
   *  Bias: '<S321>/Bias2'
   *  Bias: '<S321>/Bias3'
   *  Constant: '<S321>/Constant'
   *  Constant: '<S323>/Constant'
   *  Math: '<S321>/Math Function'
   *  RelationalOperator: '<S323>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S321>/Switch1' */

  /* Product: '<S317>/Multiply' incorporates:
   *  Gain: '<S317>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

  /* Gain: '<S317>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S320>/SinCos' */
  rtb_Sum3 = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S320>/Sum2' incorporates:
   *  Product: '<S320>/Multiply1'
   *  Product: '<S320>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3;

  /* Product: '<S320>/Multiply3' */
  rtb_Sum3 *= rtb_Sum_e_idx_0;

  /* Product: '<S320>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S320>/Sum3' */
  rtb_Sum3 = rtb_Gain_lq - rtb_Sum3;

  /* DataTypeConversion: '<S314>/Data Type Conversion' incorporates:
   *  Gain: '<S317>/Gain'
   *  Sum: '<S317>/Sum1'
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
    FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_d;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_d;
  } else {
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_d;
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

  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S327>/Compare' incorporates:
   *  Abs: '<S316>/Abs'
   *  Constant: '<S327>/Constant'
   *  MinMax: '<S316>/Max'
   *  Sum: '<S316>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S3>/Vehicle.StickMoved' */
  if (FMS_B.Compare && (FMS_B.target_mode != PilotMode_None)) {
    if (FMS_getArmMode(FMS_B.target_mode) == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
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
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
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
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
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
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Land:
        FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_j >= 500) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
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

          /* Constant: '<Root>/Constant' */
          FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
        }

        /* End of Constant: '<Root>/ACCEPT_R' */
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_takeoff[2]) {
          if (FMS_B.target_mode != PilotMode_None) {
            tmp = FMS_getArmMode(FMS_B.target_mode);
            if (tmp == 3.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
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
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
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
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
              FMS_DW.is_Arm = FMS_IN_Manual;
              if (FMS_B.target_mode == PilotMode_Manual) {
                FMS_DW.is_Manual = FMS_IN_Manual_g;
                FMS_B.state = VehicleState_Manual;
              } else {
                FMS_DW.is_Manual = FMS_IN_InValidManualMode;
              }
            } else {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
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
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_d;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_d;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T c_sf_internal_predicateOutput;
  real32_T tmp[2];
  uint32_T qY;
  int32_T tmp_0;
  real_T tmp_1;
  FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_d0 = false;
  if ((FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_c >=
       500) && (FMS_B.target_mode != PilotMode_Mission)) {
    FMS_exit_internal_Arm();
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.target_mode !=
              PilotMode_None)) {
    tmp_1 = FMS_getArmMode(FMS_B.target_mode);
    if (tmp_1 == 3.0) {
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
    } else if (tmp_1 == 2.0) {
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
    } else if (tmp_1 == 1.0) {
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

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
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
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_d;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
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
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_d;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
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
                  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_d;
                  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_d;
                  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
                  FMS_DW.is_Vehicle = FMS_IN_Disarm;
                  FMS_B.state = VehicleState_Disarm;
                  break;

                 case FMS_IN_Land:
                  FMS_DW.durationLastReferenceTick_1 =
                    FMS_DW.chartAbsoluteTimeCounter;

                  /* Constant: '<Root>/Constant' */
                  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
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

                    /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo,
                      FMS_B.href, FMS_B.psio, FMS_B.DataTypeConversion,
                      &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

                    /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
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

                    /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo,
                      FMS_B.href, FMS_B.psio, FMS_B.DataTypeConversion,
                      &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

                    /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
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

                    /* Constant: '<Root>/Constant' */
                    FMS_DW.condWasTrueAtLastTimeStep_1 = false;
                  } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
                    FMS_DW.is_Mission = FMS_IN_Return_h;
                    FMS_B.Cmd_In.sp_return[0] = FMS_DW.home[0];
                    FMS_B.Cmd_In.sp_return[1] = FMS_DW.home[1];
                    FMS_B.state = VehicleState_Return;
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

                    /* Constant: '<Root>/Constant' */
                    FMS_DW.condWasTrueAtLastTimeStep_1 = false;
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
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
          break;

         case FMS_IN_Manual:
          if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
            FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_d;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_d;
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_d;
      break;

     default:
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_d;
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

      /* Outputs for Function Call SubSystem: '<S3>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S315>/Reshape' incorporates:
       *  Constant: '<S315>/Constant'
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

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d0 = false;
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

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d0 = false;
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
  int8_T rtPrevAction;
  uint16_T rtb_DataTypeConversion;
  uint16_T rtb_DataTypeConversion1_l;
  real32_T rtb_Saturation_l;
  real32_T rtb_VectorConcatenate_hm[9];
  real32_T rtb_a_pr;
  real32_T rtb_Sqrt_d;
  MotionState rtb_state_a;
  real32_T rtb_Switch_l[3];
  real32_T rtb_Divide_gz[2];
  real32_T rtb_Rem_k;
  real32_T rtb_Divide_lq[2];
  boolean_T rtb_FixPtRelationalOperator;
  MotionState rtb_state;
  real32_T rtb_Subtract3_f[2];
  int32_T i;
  real32_T rtb_VectorConcatenate_a[3];
  boolean_T u;
  real32_T rtb_Saturation1_i_idx_0;
  real32_T rtb_MathFunction_crm_idx_1;
  real32_T rtb_MathFunction_crm_idx_0;
  real32_T rtb_a_b_idx_1;
  real32_T rtb_a_b_idx_0;
  real32_T rtb_Sign1_n_idx_0;
  real32_T rtb_Switch_e_idx_0;
  real32_T u1_tmp;
  boolean_T guard1 = false;

  /* Outputs for Atomic SubSystem: '<Root>/CommandProcess' */
  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S9>/FixPt Relational Operator'
   *  UnitDelay: '<S9>/Delay Input1'
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0U;
  }

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S8>/Constant'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  Delay: '<S7>/Delay'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S7>/Logical Operator'
   *  Logic: '<S7>/Logical Operator1'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  RelationalOperator: '<S14>/FixPt Relational Operator'
   *  RelationalOperator: '<S8>/Compare'
   *  Switch: '<S7>/Switch1'
   *  UnitDelay: '<S14>/Delay Input1'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTATE <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S7>/Switch1' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       *  Delay: '<S7>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S7>/Switch' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  Switch: '<S6>/Switch2'
   *  UnitDelay: '<S10>/Delay Input1'
   *  UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S6>/Switch2' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion1'
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;
  } else {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Update for UnitDelay: '<S9>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S9>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  rtb_Switch_e_idx_0 = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Switch_e_idx_0 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Switch_e_idx_0;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S14>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S11>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* End of Outputs for SubSystem: '<Root>/CommandProcess' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S7>/Delay'
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

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_3' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
  rtb_FixPtRelationalOperator = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k))
  {
    FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_k = rtb_FixPtRelationalOperator;
  rtb_FixPtRelationalOperator = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_FixPtRelationalOperator;
  FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_d0 = false;
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
  /* SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Divide_lq[0] = FMS_B.Cmd_In.sp_return[0];
  rtb_Divide_lq[1] = FMS_B.Cmd_In.sp_return[1];
  rtb_Switch_l[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_l[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_l[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

  /* SwitchCase: '<S15>/Switch Case' incorporates:
   *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S17>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S24>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S274>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S264>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S198>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S208>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S22>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S21>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S72>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S58>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
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
    /* Outputs for IfAction SubSystem: '<S15>/Disarm' incorporates:
     *  ActionPort: '<S19>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  BusAssignment: '<S19>/Bus Assignment'
     *  Constant: '<S19>/Constant'
     *  SignalConversion: '<S19>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S19>/Bus Assignment' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  Constant: '<S19>/Constant2'
     *  DataTypeConversion: '<S19>/Data Type Conversion2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S19>/Data Type Conversion2' incorporates:
       *  Constant: '<S19>/Constant6'
       */
      rtb_Switch_e_idx_0 = fmodf(floorf(FMS_PARAM.DISARM_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Switch_e_idx_0 < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_e_idx_0 : (int32_T)
        (uint16_T)rtb_Switch_e_idx_0);
    }

    /* End of Outputs for SubSystem: '<S15>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S15>/Standby' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  BusAssignment: '<S20>/Bus Assignment'
     *  Constant: '<S20>/Constant'
     *  SignalConversion: '<S20>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S20>/Bus Assignment' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment'
     *  Constant: '<S20>/Constant2'
     *  DataTypeConversion: '<S20>/Data Type Conversion3'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;
    for (i = 0; i < 16; i++) {
      /* DataTypeConversion: '<S20>/Data Type Conversion3' incorporates:
       *  Constant: '<S20>/Constant6'
       */
      rtb_Switch_e_idx_0 = fmodf(floorf(FMS_PARAM.STANDBY_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Switch_e_idx_0 < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_e_idx_0 : (int32_T)
        (uint16_T)rtb_Switch_e_idx_0);
    }

    /* End of Outputs for SubSystem: '<S15>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S15>/Arm' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* SwitchCase: '<S17>/Switch Case' */
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
        /* Disable for SwitchCase: '<S24>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S274>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S264>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S198>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S208>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S22>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S21>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S37>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S72>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S58>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
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
       *  Math: '<S296>/Math Function'
       *  Product: '<S298>/Divide'
       *  Sum: '<S259>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Takeoff:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
        break;

       case VehicleState_Land:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
        break;

       case VehicleState_Return:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
        break;

       case VehicleState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 4;
        break;
      }

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_a) {
        switch (rtPrevAction) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S274>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S264>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S198>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S208>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S24>/Takeoff' incorporates:
         *  ActionPort: '<S193>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S311>/Sum2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S305>/Sum'
         */
        rtb_Sqrt_d = FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2];

        /* Product: '<S311>/Divide' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S311>/Sum1'
         *  Sum: '<S311>/Sum2'
         */
        rtb_Saturation_l = 1.0F / (FMS_B.Cmd_In.sp_takeoff[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Sqrt_d;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S311>/Saturation' */
        if (rtb_Saturation_l > 1.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = 0.0F;
          }
        }

        /* End of Saturate: '<S311>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S312>/Trigonometric Function1' incorporates:
         *  Gain: '<S310>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S312>/Trigonometric Function3'
         */
        rtb_Switch_e_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_VectorConcatenate_hm[0] = rtb_Switch_e_idx_0;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S312>/Trigonometric Function' incorporates:
         *  Gain: '<S310>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S312>/Trigonometric Function2'
         */
        rtb_Rem_k = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_VectorConcatenate_hm[1] = rtb_Rem_k;

        /* SignalConversion: '<S312>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S312>/Constant3'
         */
        rtb_VectorConcatenate_hm[2] = 0.0F;

        /* Gain: '<S312>/Gain' */
        rtb_VectorConcatenate_hm[3] = -rtb_Rem_k;

        /* Trigonometry: '<S312>/Trigonometric Function3' */
        rtb_VectorConcatenate_hm[4] = rtb_Switch_e_idx_0;

        /* SignalConversion: '<S312>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S312>/Constant4'
         */
        rtb_VectorConcatenate_hm[5] = 0.0F;

        /* SignalConversion: '<S312>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S306>/Saturation1' */
        rtb_Rem_k = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Switch_e_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SignalConversion: '<S306>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S311>/Multiply'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S306>/Sum'
         *  Sum: '<S311>/Sum3'
         *  Sum: '<S311>/Sum4'
         */
        rtb_a_pr = ((FMS_B.Cmd_In.sp_takeoff[0] - FMS_B.Cmd_In.cur_waypoint[0]) *
                    rtb_Saturation_l + FMS_B.Cmd_In.cur_waypoint[0]) -
          FMS_U.INS_Out.x_R;
        rtb_Saturation_l = ((FMS_B.Cmd_In.sp_takeoff[1] -
                             FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Saturation_l +
                            FMS_B.Cmd_In.cur_waypoint[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S306>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_hm[i + 3] *
            rtb_Saturation_l + rtb_VectorConcatenate_hm[i] * rtb_a_pr;
        }

        /* Saturate: '<S306>/Saturation1' incorporates:
         *  Gain: '<S306>/Gain2'
         *  Product: '<S306>/Multiply'
         */
        rtb_Saturation_l = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[0];
        rtb_a_pr = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S193>/Bus Assignment1'
         *  Constant: '<S193>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S193>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S193>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S306>/Saturation1' */
        if (rtb_Saturation_l > rtb_Rem_k) {
          /* BusAssignment: '<S193>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else if (rtb_Saturation_l < rtb_Switch_e_idx_0) {
          /* BusAssignment: '<S193>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_e_idx_0;
        } else {
          /* BusAssignment: '<S193>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Saturation_l;
        }

        if (rtb_a_pr > rtb_Rem_k) {
          /* BusAssignment: '<S193>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else if (rtb_a_pr < rtb_Switch_e_idx_0) {
          /* BusAssignment: '<S193>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_e_idx_0;
        } else {
          /* BusAssignment: '<S193>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_pr;
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Switch: '<S305>/Switch' incorporates:
         *  Abs: '<S305>/Abs'
         *  Abs: '<S305>/Abs1'
         *  Constant: '<S307>/Constant'
         *  Constant: '<S308>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S305>/Logical Operator'
         *  RelationalOperator: '<S307>/Compare'
         *  RelationalOperator: '<S308>/Compare'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S305>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_takeoff[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(rtb_Sqrt_d) > 2.0F)) {
          /* BusAssignment: '<S193>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Constant: '<S305>/Constant6'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -1.0F;
        } else {
          /* BusAssignment: '<S193>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Constant: '<S305>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -0.5F;
        }

        /* End of Switch: '<S305>/Switch' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S24>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S24>/Land' incorporates:
         *  ActionPort: '<S191>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S237>/Trigonometric Function1' incorporates:
         *  Gain: '<S236>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S237>/Trigonometric Function' incorporates:
         *  Gain: '<S236>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S237>/Constant3'
         */
        rtb_VectorConcatenate_hm[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S237>/Gain' incorporates:
         *  Gain: '<S236>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S237>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_hm[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S237>/Trigonometric Function3' incorporates:
         *  Gain: '<S236>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S237>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S237>/Constant4'
         */
        rtb_VectorConcatenate_hm[5] = 0.0F;

        /* SignalConversion: '<S237>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S233>/Saturation1' */
        rtb_Sqrt_d = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Rem_k = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SignalConversion: '<S234>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S234>/Sum'
         */
        rtb_a_pr = FMS_B.Cmd_In.sp_land[0] - FMS_U.INS_Out.x_R;
        rtb_Saturation_l = FMS_B.Cmd_In.sp_land[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S234>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_hm[i + 3] *
            rtb_Saturation_l + rtb_VectorConcatenate_hm[i] * rtb_a_pr;
        }

        /* Saturate: '<S233>/Saturation1' incorporates:
         *  Gain: '<S234>/Gain2'
         *  Product: '<S234>/Multiply'
         */
        rtb_Saturation_l = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[0];
        rtb_a_pr = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S191>/Bus Assignment1'
         *  Constant: '<S191>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S191>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S191>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_ml;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S233>/Saturation1' */
        if (rtb_Saturation_l > rtb_Sqrt_d) {
          /* BusAssignment: '<S191>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_d;
        } else if (rtb_Saturation_l < rtb_Rem_k) {
          /* BusAssignment: '<S191>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S191>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Saturation_l;
        }

        if (rtb_a_pr > rtb_Sqrt_d) {
          /* BusAssignment: '<S191>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Sqrt_d;
        } else if (rtb_a_pr < rtb_Rem_k) {
          /* BusAssignment: '<S191>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S191>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_pr;
        }

        /* BusAssignment: '<S191>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S191>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S24>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S24>/Return' incorporates:
           *  ActionPort: '<S192>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Delay: '<S240>/Delay'
           *  Delay: '<S241>/Delay'
           *  Delay: '<S260>/Delay'
           *  DiscreteIntegrator: '<S244>/Integrator'
           *  DiscreteIntegrator: '<S244>/Integrator1'
           *  DiscreteIntegrator: '<S301>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_o = 1U;
          FMS_DW.l1_heading_p = 0.0F;
          FMS_DW.icLoad_cg = 1U;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S24>/Return' */

          /* SystemReset for IfAction SubSystem: '<S24>/Return' incorporates:
           *  ActionPort: '<S192>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Chart: '<S265>/Motion Status'
           *  Chart: '<S275>/Motion State'
           */
          FMS_DW.temporalCounter_i1_j = 0U;
          FMS_DW.is_active_c2_FMS = 0U;
          FMS_DW.is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S24>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Return' incorporates:
         *  ActionPort: '<S192>/Action Port'
         */
        /* Delay: '<S260>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_o != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S256>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S261>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_crm_idx_1 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_return
          [0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Divide_gz[0] = rtb_MathFunction_crm_idx_1 *
          rtb_MathFunction_crm_idx_1;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_MathFunction_crm_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_return
          [1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S261>/Square' */
        rtb_MathFunction_crm_idx_1 *= rtb_MathFunction_crm_idx_1;

        /* Sqrt: '<S261>/Sqrt' incorporates:
         *  Sum: '<S261>/Sum of Elements'
         */
        rtb_Sqrt_d = sqrtf(rtb_Divide_gz[0] + rtb_MathFunction_crm_idx_1);

        /* Switch: '<S256>/Switch' incorporates:
         *  Constant: '<S256>/vel'
         */
        if (rtb_Sqrt_d > FMS_PARAM.L1) {
          rtb_Sqrt_d = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S256>/Gain' */
          rtb_Sqrt_d *= 0.5F;

          /* Saturate: '<S256>/Saturation' */
          if (rtb_Sqrt_d > FMS_PARAM.CRUISE_SPEED) {
            rtb_Sqrt_d = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Sqrt_d < 0.5F) {
              rtb_Sqrt_d = 0.5F;
            }
          }

          /* End of Saturate: '<S256>/Saturation' */
        }

        /* End of Switch: '<S256>/Switch' */

        /* Chart: '<S275>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S275>/Square'
         *  Math: '<S275>/Square1'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sqrt: '<S275>/Sqrt'
         *  Sum: '<S275>/Add'
         */
        if (FMS_DW.temporalCounter_i1_j < 1023U) {
          FMS_DW.temporalCounter_i1_j++;
        }

        if (FMS_DW.is_active_c2_FMS == 0U) {
          FMS_DW.is_active_c2_FMS = 1U;
          FMS_DW.is_c2_FMS = FMS_IN_Move_c;
          rtb_state_a = MotionState_Move;
        } else {
          switch (FMS_DW.is_c2_FMS) {
           case FMS_IN_Brake_b:
            rtb_state_a = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_j
                 >= 625U)) {
              FMS_DW.is_c2_FMS = FMS_IN_Hold_m;
              rtb_state_a = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            break;

           case FMS_IN_Hold_m:
            rtb_state_a = MotionState_Hold;
            break;

           default:
            FMS_DW.is_c2_FMS = FMS_IN_Brake_b;
            FMS_DW.temporalCounter_i1_j = 0U;
            rtb_state_a = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S275>/Motion State' */

        /* SwitchCase: '<S274>/Switch Case' incorporates:
         *  DiscreteIntegrator: '<S284>/Integrator1'
         *  Gain: '<S278>/Gain6'
         *  Gain: '<S282>/Gain'
         *  Gain: '<S283>/Gain'
         *  Sum: '<S284>/Subtract'
         *  Sum: '<S285>/Add'
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
            /* InitializeConditions for IfAction SubSystem: '<S274>/Hold Control' incorporates:
             *  ActionPort: '<S277>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S274>/Switch Case' incorporates:
             *  Delay: '<S277>/Delay'
             */
            FMS_DW.icLoad_if = 1U;

            /* End of InitializeConditions for SubSystem: '<S274>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S274>/Hold Control' incorporates:
           *  ActionPort: '<S277>/Action Port'
           */
          /* Delay: '<S277>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (FMS_DW.icLoad_if != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_n[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Trigonometry: '<S281>/Trigonometric Function1' incorporates:
           *  Gain: '<S280>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_VectorConcatenate_hm[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S281>/Trigonometric Function' incorporates:
           *  Gain: '<S280>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_VectorConcatenate_hm[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S281>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S281>/Constant3'
           */
          rtb_VectorConcatenate_hm[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S281>/Gain' incorporates:
           *  Gain: '<S280>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Trigonometry: '<S281>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_hm[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S281>/Trigonometric Function3' incorporates:
           *  Gain: '<S280>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_VectorConcatenate_hm[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S281>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S281>/Constant4'
           */
          rtb_VectorConcatenate_hm[5] = 0.0F;

          /* SignalConversion: '<S281>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3_g[0];
          rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3_g[1];
          rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3_g[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* SignalConversion: '<S277>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S277>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S277>/Sum'
           */
          rtb_a_pr = FMS_DW.Delay_DSTATE_n[0] - FMS_U.INS_Out.x_R;
          rtb_Saturation_l = FMS_DW.Delay_DSTATE_n[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S277>/Multiply' incorporates:
           *  SignalConversion: '<S277>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (i = 0; i < 3; i++) {
            rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_hm[i + 3] *
              rtb_Saturation_l + rtb_VectorConcatenate_hm[i] * rtb_a_pr;
          }

          /* End of Product: '<S277>/Multiply' */

          /* Gain: '<S277>/Gain2' */
          FMS_B.Merge_m[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[0];
          FMS_B.Merge_m[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[1];

          /* Update for Delay: '<S277>/Delay' */
          FMS_DW.icLoad_if = 0U;

          /* End of Outputs for SubSystem: '<S274>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S274>/Brake Control' incorporates:
           *  ActionPort: '<S276>/Action Port'
           */
          /* SignalConversion: '<S276>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
          FMS_B.Merge_m[0] = 0.0F;
          FMS_B.Merge_m[1] = 0.0F;

          /* End of Outputs for SubSystem: '<S274>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S274>/Move Control' incorporates:
             *  ActionPort: '<S278>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S274>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S284>/Integrator'
             *  DiscreteIntegrator: '<S284>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_p[0] = 0.0F;
            FMS_DW.Integrator_DSTATE_p[0] = 0.0F;
            FMS_DW.Integrator1_DSTATE_p[1] = 0.0F;
            FMS_DW.Integrator_DSTATE_p[1] = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S274>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S274>/Move Control' incorporates:
           *  ActionPort: '<S278>/Action Port'
           */
          /* SignalConversion: '<S278>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S284>/Integrator1'
           */
          FMS_B.Merge_m[0] = FMS_DW.Integrator1_DSTATE_p[0];

          /* Product: '<S285>/Multiply1' incorporates:
           *  Constant: '<S285>/const1'
           *  DiscreteIntegrator: '<S284>/Integrator'
           */
          rtb_Divide_gz[0] = FMS_DW.Integrator_DSTATE_p[0] * 0.05F;

          /* SignalConversion: '<S278>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S284>/Integrator1'
           */
          FMS_B.Merge_m[1] = FMS_DW.Integrator1_DSTATE_p[1];

          /* Product: '<S285>/Multiply1' incorporates:
           *  Constant: '<S285>/const1'
           *  DiscreteIntegrator: '<S284>/Integrator'
           */
          rtb_Divide_gz[1] = FMS_DW.Integrator_DSTATE_p[1] * 0.05F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S282>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
              FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Switch_e_idx_0 = 0.0F;
          } else {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S282>/Gain' */
          rtb_Sign1_n_idx_0 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ);

          /* Sum: '<S285>/Add' incorporates:
           *  DiscreteIntegrator: '<S284>/Integrator1'
           *  Gain: '<S278>/Gain6'
           *  Gain: '<S282>/Gain'
           *  Sum: '<S284>/Subtract'
           */
          rtb_Subtract3_f[0] = (FMS_DW.Integrator1_DSTATE_p[0] -
                                rtb_Sign1_n_idx_0 * rtb_Switch_e_idx_0 *
                                FMS_PARAM.VEL_XY_LIM) + rtb_Divide_gz[0];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S283>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Switch_e_idx_0 = 0.0F;
          } else {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll -
              (-FMS_PARAM.ROLL_DZ);
          }

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S283>/Gain' */
          rtb_Saturation1_i_idx_0 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ);

          /* Sum: '<S285>/Add' incorporates:
           *  DiscreteIntegrator: '<S284>/Integrator1'
           *  Gain: '<S278>/Gain6'
           *  Gain: '<S283>/Gain'
           *  Sum: '<S284>/Subtract'
           */
          rtb_Subtract3_f[1] = (FMS_DW.Integrator1_DSTATE_p[1] -
                                rtb_Saturation1_i_idx_0 * rtb_Switch_e_idx_0 *
                                FMS_PARAM.VEL_XY_LIM) + rtb_Divide_gz[1];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S282>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
              FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Switch_e_idx_0 = 0.0F;
          } else {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_p[0] - rtb_Sign1_n_idx_0 *
                       rtb_Switch_e_idx_0 * FMS_PARAM.VEL_XY_LIM) +
            rtb_Divide_gz[0];

          /* Signum: '<S285>/Sign' incorporates:
           *  DiscreteIntegrator: '<S284>/Integrator1'
           *  Gain: '<S278>/Gain6'
           *  Gain: '<S282>/Gain'
           *  Sum: '<S284>/Subtract'
           *  Sum: '<S285>/Add'
           */
          if (rtb_Rem_k < 0.0F) {
            rtb_Rem_k = -1.0F;
          } else {
            if (rtb_Rem_k > 0.0F) {
              rtb_Rem_k = 1.0F;
            }
          }

          /* Sum: '<S285>/Add2' incorporates:
           *  Abs: '<S285>/Abs'
           *  Gain: '<S285>/Gain'
           *  Gain: '<S285>/Gain1'
           *  Product: '<S285>/Multiply2'
           *  Product: '<S285>/Multiply3'
           *  Signum: '<S285>/Sign'
           *  Sqrt: '<S285>/Sqrt'
           *  Sum: '<S285>/Add1'
           *  Sum: '<S285>/Subtract'
           */
          rtb_a_pr = (sqrtf((8.0F * fabsf(rtb_Subtract3_f[0]) + FMS_ConstB.d_n) *
                            FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F * rtb_Rem_k
            + rtb_Divide_gz[0];

          /* Sum: '<S285>/Add3' incorporates:
           *  Signum: '<S285>/Sign'
           */
          rtb_Saturation_l = rtb_Subtract3_f[0] + FMS_ConstB.d_n;

          /* Sum: '<S285>/Subtract1' incorporates:
           *  Signum: '<S285>/Sign'
           */
          rtb_Rem_k = rtb_Subtract3_f[0] - FMS_ConstB.d_n;

          /* Signum: '<S285>/Sign1' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else {
            if (rtb_Saturation_l > 0.0F) {
              rtb_Saturation_l = 1.0F;
            }
          }

          /* Signum: '<S285>/Sign2' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Rem_k = -1.0F;
          } else {
            if (rtb_Rem_k > 0.0F) {
              rtb_Rem_k = 1.0F;
            }
          }

          /* Sum: '<S285>/Add5' incorporates:
           *  Gain: '<S285>/Gain2'
           *  Product: '<S285>/Multiply4'
           *  Signum: '<S285>/Sign'
           *  Sum: '<S285>/Add2'
           *  Sum: '<S285>/Add4'
           *  Sum: '<S285>/Subtract2'
           */
          rtb_a_pr += ((rtb_Subtract3_f[0] - rtb_a_pr) + rtb_Divide_gz[0]) *
            ((rtb_Saturation_l - rtb_Rem_k) * 0.5F);

          /* Update for DiscreteIntegrator: '<S284>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S284>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_p[0] += 0.004F * FMS_DW.Integrator_DSTATE_p
            [0];

          /* Signum: '<S285>/Sign4' incorporates:
           *  Sum: '<S285>/Subtract3'
           */
          rtb_Saturation_l = rtb_a_pr - FMS_ConstB.d_n;

          /* Signum: '<S285>/Sign3' incorporates:
           *  Sum: '<S285>/Add6'
           */
          B = rtb_a_pr + FMS_ConstB.d_n;

          /* Signum: '<S285>/Sign5' */
          if (rtb_a_pr < 0.0F) {
            rtb_Rem_k = -1.0F;
          } else if (rtb_a_pr > 0.0F) {
            rtb_Rem_k = 1.0F;
          } else {
            rtb_Rem_k = rtb_a_pr;
          }

          /* Signum: '<S285>/Sign3' */
          if (B < 0.0F) {
            B = -1.0F;
          } else {
            if (B > 0.0F) {
              B = 1.0F;
            }
          }

          /* Signum: '<S285>/Sign4' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else {
            if (rtb_Saturation_l > 0.0F) {
              rtb_Saturation_l = 1.0F;
            }
          }

          /* Signum: '<S285>/Sign6' */
          if (rtb_a_pr < 0.0F) {
            rtb_Switch_e_idx_0 = -1.0F;
          } else if (rtb_a_pr > 0.0F) {
            rtb_Switch_e_idx_0 = 1.0F;
          } else {
            rtb_Switch_e_idx_0 = rtb_a_pr;
          }

          /* Update for DiscreteIntegrator: '<S284>/Integrator' incorporates:
           *  Constant: '<S285>/const'
           *  Gain: '<S285>/Gain3'
           *  Product: '<S285>/Divide'
           *  Product: '<S285>/Multiply5'
           *  Product: '<S285>/Multiply6'
           *  Sum: '<S285>/Subtract4'
           *  Sum: '<S285>/Subtract5'
           *  Sum: '<S285>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_p[0] += ((rtb_a_pr / FMS_ConstB.d_n -
            rtb_Rem_k) * FMS_ConstB.Gain4_a * ((B - rtb_Saturation_l) * 0.5F) -
            rtb_Switch_e_idx_0 * 58.836F) * 0.004F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S283>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Switch_e_idx_0 = 0.0F;
          } else {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll -
              (-FMS_PARAM.ROLL_DZ);
          }

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_p[1] - rtb_Saturation1_i_idx_0 *
                       rtb_Switch_e_idx_0 * FMS_PARAM.VEL_XY_LIM) +
            rtb_Divide_gz[1];

          /* Signum: '<S285>/Sign' incorporates:
           *  DiscreteIntegrator: '<S284>/Integrator1'
           *  Gain: '<S278>/Gain6'
           *  Gain: '<S283>/Gain'
           *  Sum: '<S284>/Subtract'
           *  Sum: '<S285>/Add'
           */
          if (rtb_Rem_k < 0.0F) {
            rtb_Rem_k = -1.0F;
          } else {
            if (rtb_Rem_k > 0.0F) {
              rtb_Rem_k = 1.0F;
            }
          }

          /* Sum: '<S285>/Add2' incorporates:
           *  Abs: '<S285>/Abs'
           *  Gain: '<S285>/Gain'
           *  Gain: '<S285>/Gain1'
           *  Product: '<S285>/Multiply2'
           *  Product: '<S285>/Multiply3'
           *  Signum: '<S285>/Sign'
           *  Sqrt: '<S285>/Sqrt'
           *  Sum: '<S285>/Add1'
           *  Sum: '<S285>/Subtract'
           */
          rtb_a_pr = (sqrtf((8.0F * fabsf(rtb_Subtract3_f[1]) + FMS_ConstB.d_n) *
                            FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F * rtb_Rem_k
            + rtb_Divide_gz[1];

          /* Sum: '<S285>/Add3' incorporates:
           *  Signum: '<S285>/Sign'
           */
          rtb_Saturation_l = rtb_Subtract3_f[1] + FMS_ConstB.d_n;

          /* Sum: '<S285>/Subtract1' incorporates:
           *  Signum: '<S285>/Sign'
           */
          rtb_Rem_k = rtb_Subtract3_f[1] - FMS_ConstB.d_n;

          /* Signum: '<S285>/Sign1' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else {
            if (rtb_Saturation_l > 0.0F) {
              rtb_Saturation_l = 1.0F;
            }
          }

          /* Signum: '<S285>/Sign2' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Rem_k = -1.0F;
          } else {
            if (rtb_Rem_k > 0.0F) {
              rtb_Rem_k = 1.0F;
            }
          }

          /* Sum: '<S285>/Add5' incorporates:
           *  Gain: '<S285>/Gain2'
           *  Product: '<S285>/Multiply4'
           *  Signum: '<S285>/Sign'
           *  Sum: '<S285>/Add2'
           *  Sum: '<S285>/Add4'
           *  Sum: '<S285>/Subtract2'
           */
          rtb_a_pr += ((rtb_Subtract3_f[1] - rtb_a_pr) + rtb_Divide_gz[1]) *
            ((rtb_Saturation_l - rtb_Rem_k) * 0.5F);

          /* Update for DiscreteIntegrator: '<S284>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S284>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_p[1] += 0.004F * FMS_DW.Integrator_DSTATE_p
            [1];

          /* Signum: '<S285>/Sign4' incorporates:
           *  Sum: '<S285>/Subtract3'
           */
          rtb_Saturation_l = rtb_a_pr - FMS_ConstB.d_n;

          /* Signum: '<S285>/Sign3' incorporates:
           *  Sum: '<S285>/Add6'
           */
          B = rtb_a_pr + FMS_ConstB.d_n;

          /* Signum: '<S285>/Sign5' */
          if (rtb_a_pr < 0.0F) {
            rtb_Rem_k = -1.0F;
          } else if (rtb_a_pr > 0.0F) {
            rtb_Rem_k = 1.0F;
          } else {
            rtb_Rem_k = rtb_a_pr;
          }

          /* Signum: '<S285>/Sign3' */
          if (B < 0.0F) {
            B = -1.0F;
          } else {
            if (B > 0.0F) {
              B = 1.0F;
            }
          }

          /* Signum: '<S285>/Sign4' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else {
            if (rtb_Saturation_l > 0.0F) {
              rtb_Saturation_l = 1.0F;
            }
          }

          /* Signum: '<S285>/Sign6' */
          if (rtb_a_pr < 0.0F) {
            rtb_Switch_e_idx_0 = -1.0F;
          } else if (rtb_a_pr > 0.0F) {
            rtb_Switch_e_idx_0 = 1.0F;
          } else {
            rtb_Switch_e_idx_0 = rtb_a_pr;
          }

          /* Update for DiscreteIntegrator: '<S284>/Integrator' incorporates:
           *  Constant: '<S285>/const'
           *  Gain: '<S285>/Gain3'
           *  Product: '<S285>/Divide'
           *  Product: '<S285>/Multiply5'
           *  Product: '<S285>/Multiply6'
           *  Sum: '<S285>/Subtract4'
           *  Sum: '<S285>/Subtract5'
           *  Sum: '<S285>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_p[1] += ((rtb_a_pr / FMS_ConstB.d_n -
            rtb_Rem_k) * FMS_ConstB.Gain4_a * ((B - rtb_Saturation_l) * 0.5F) -
            rtb_Switch_e_idx_0 * 58.836F) * 0.004F;

          /* End of Outputs for SubSystem: '<S274>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S274>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S265>/Motion Status' incorporates:
         *  Abs: '<S265>/Abs'
         *  Constant: '<S265>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S264>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S264>/Hold Control' incorporates:
             *  ActionPort: '<S267>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S264>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S264>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S264>/Hold Control' incorporates:
           *  ActionPort: '<S267>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S264>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S264>/Brake Control' incorporates:
           *  ActionPort: '<S266>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S264>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S264>/Move Control' incorporates:
             *  ActionPort: '<S268>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S264>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S264>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S264>/Move Control' incorporates:
           *  ActionPort: '<S268>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S264>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S264>/Switch Case' */

        /* Delay: '<S240>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_cg != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S192>/Sum' incorporates:
         *  Delay: '<S240>/Delay'
         *  MATLAB Function: '<S258>/OutRegionRegWP'
         *  MATLAB Function: '<S258>/SearchL1RefWP'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_crm_idx_0 = FMS_B.Cmd_In.sp_return[0] -
          FMS_DW.Delay_DSTATE_p[0];
        rtb_MathFunction_crm_idx_1 = FMS_B.Cmd_In.sp_return[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S255>/Sum of Elements' incorporates:
         *  Math: '<S255>/Math Function'
         *  Sum: '<S192>/Sum'
         */
        rtb_Switch_e_idx_0 = rtb_MathFunction_crm_idx_1 *
          rtb_MathFunction_crm_idx_1 + rtb_MathFunction_crm_idx_0 *
          rtb_MathFunction_crm_idx_0;

        /* Math: '<S255>/Math Function1' incorporates:
         *  Sum: '<S255>/Sum of Elements'
         *
         * About '<S255>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch_e_idx_0 < 0.0F) {
          rtb_a_pr = -sqrtf(fabsf(rtb_Switch_e_idx_0));
        } else {
          rtb_a_pr = sqrtf(rtb_Switch_e_idx_0);
        }

        /* End of Math: '<S255>/Math Function1' */

        /* Switch: '<S255>/Switch' incorporates:
         *  Constant: '<S255>/Constant'
         *  Product: '<S255>/Product'
         *  Sum: '<S192>/Sum'
         */
        if (rtb_a_pr > 0.0F) {
          rtb_Switch_l[0] = rtb_MathFunction_crm_idx_1;
          rtb_Switch_l[1] = rtb_MathFunction_crm_idx_0;
          rtb_Switch_l[2] = rtb_a_pr;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S255>/Switch' */

        /* Product: '<S255>/Divide' */
        rtb_Divide_gz[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Divide_gz[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S253>/Subtract' incorporates:
         *  Product: '<S253>/Multiply'
         *  Product: '<S253>/Multiply1'
         */
        rtb_a_pr = rtb_Divide_gz[0] * FMS_ConstB.Divide_d[1] - rtb_Divide_gz[1] *
          FMS_ConstB.Divide_d[0];

        /* Signum: '<S242>/Sign1' */
        if (rtb_a_pr < 0.0F) {
          rtb_a_pr = -1.0F;
        } else {
          if (rtb_a_pr > 0.0F) {
            rtb_a_pr = 1.0F;
          }
        }

        /* End of Signum: '<S242>/Sign1' */

        /* Switch: '<S242>/Switch2' incorporates:
         *  Constant: '<S242>/Constant4'
         */
        if (rtb_a_pr == 0.0F) {
          rtb_a_pr = 1.0F;
        }

        /* End of Switch: '<S242>/Switch2' */

        /* DotProduct: '<S242>/Dot Product' */
        rtb_Saturation_l = FMS_ConstB.Divide_d[0] * rtb_Divide_gz[0] +
          FMS_ConstB.Divide_d[1] * rtb_Divide_gz[1];

        /* Trigonometry: '<S242>/Acos' incorporates:
         *  DotProduct: '<S242>/Dot Product'
         */
        if (rtb_Saturation_l > 1.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          if (rtb_Saturation_l < -1.0F) {
            rtb_Saturation_l = -1.0F;
          }
        }

        /* Product: '<S242>/Multiply' incorporates:
         *  Trigonometry: '<S242>/Acos'
         */
        rtb_a_pr *= acosf(rtb_Saturation_l);

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S246>/Rem' incorporates:
         *  Constant: '<S246>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S241>/Sum1'
         */
        rtb_Saturation_l = rt_remf(rtb_a_pr - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S246>/Switch' incorporates:
         *  Abs: '<S246>/Abs'
         *  Constant: '<S246>/Constant'
         *  Constant: '<S252>/Constant'
         *  Product: '<S246>/Multiply'
         *  RelationalOperator: '<S252>/Compare'
         *  Sum: '<S246>/Add'
         */
        if (fabsf(rtb_Saturation_l) > 3.14159274F) {
          /* Signum: '<S246>/Sign' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Rem_k = -1.0F;
          } else if (rtb_Saturation_l > 0.0F) {
            rtb_Rem_k = 1.0F;
          } else {
            rtb_Rem_k = rtb_Saturation_l;
          }

          /* End of Signum: '<S246>/Sign' */
          rtb_Saturation_l -= 6.28318548F * rtb_Rem_k;
        }

        /* End of Switch: '<S246>/Switch' */

        /* Abs: '<S239>/Abs' */
        rtb_Saturation_l = fabsf(rtb_Saturation_l);

        /* Switch: '<S239>/Switch' incorporates:
         *  Product: '<S260>/Multiply'
         *  Sum: '<S260>/Sum'
         */
        if (rtb_Saturation_l > 0.34906584F) {
          /* Saturate: '<S274>/Saturation1' */
          if (FMS_B.Merge_m[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_m[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_l[0] = FMS_B.Merge_m[0];
          }

          if (FMS_B.Merge_m[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_m[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_l[1] = FMS_B.Merge_m[1];
          }

          /* End of Saturate: '<S274>/Saturation1' */

          /* Saturate: '<S264>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_l[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S264>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S260>/Sum' incorporates:
           *  Delay: '<S260>/Delay'
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_l = FMS_B.Cmd_In.sp_return[0] - FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S302>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_l[0] = rtb_Saturation_l;
          rtb_Divide_gz[0] = rtb_Saturation_l;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S260>/Sum' incorporates:
           *  Delay: '<S260>/Delay'
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_l = FMS_B.Cmd_In.sp_return[1] - FMS_DW.Delay_DSTATE_e[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S304>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S304>/Constant4'
           */
          rtb_VectorConcatenate_hm[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S303>/Gain' incorporates:
           *  DiscreteIntegrator: '<S301>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S301>/Add'
           */
          rtb_Rem_k = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_p);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Trigonometry: '<S304>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S304>/Trigonometric Function1'
           */
          rtb_Switch_e_idx_0 = arm_cos_f32(rtb_Rem_k);
          rtb_VectorConcatenate_hm[4] = rtb_Switch_e_idx_0;

          /* Trigonometry: '<S304>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S304>/Trigonometric Function'
           */
          rtb_Rem_k = arm_sin_f32(rtb_Rem_k);

          /* Gain: '<S304>/Gain' incorporates:
           *  Trigonometry: '<S304>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_hm[3] = -rtb_Rem_k;

          /* SignalConversion: '<S304>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S304>/Constant3'
           */
          rtb_VectorConcatenate_hm[2] = 0.0F;

          /* Trigonometry: '<S304>/Trigonometric Function' */
          rtb_VectorConcatenate_hm[1] = rtb_Rem_k;

          /* Trigonometry: '<S304>/Trigonometric Function1' */
          rtb_VectorConcatenate_hm[0] = rtb_Switch_e_idx_0;

          /* SignalConversion: '<S304>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3_k[0];
          rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3_k[1];
          rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3_k[2];

          /* Sum: '<S302>/Sum of Elements' incorporates:
           *  Math: '<S302>/Math Function'
           */
          rtb_Switch_e_idx_0 = rtb_Switch_l[0] * rtb_Switch_l[0] +
            rtb_Saturation_l * rtb_Saturation_l;

          /* Math: '<S302>/Math Function1' incorporates:
           *  Sum: '<S302>/Sum of Elements'
           *
           * About '<S302>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch_e_idx_0 < 0.0F) {
            rtb_Rem_k = -sqrtf(fabsf(rtb_Switch_e_idx_0));
          } else {
            rtb_Rem_k = sqrtf(rtb_Switch_e_idx_0);
          }

          /* End of Math: '<S302>/Math Function1' */

          /* Switch: '<S302>/Switch' incorporates:
           *  Constant: '<S302>/Constant'
           *  Product: '<S302>/Product'
           */
          if (rtb_Rem_k > 0.0F) {
            rtb_Switch_e_idx_0 = rtb_Divide_gz[0];
          } else {
            rtb_Switch_e_idx_0 = 0.0F;
            rtb_Saturation_l = 0.0F;
            rtb_Rem_k = 1.0F;
          }

          /* End of Switch: '<S302>/Switch' */

          /* Product: '<S300>/Multiply2' incorporates:
           *  Product: '<S302>/Divide'
           */
          rtb_Switch_e_idx_0 = rtb_Switch_e_idx_0 / rtb_Rem_k * rtb_Sqrt_d;
          rtb_Saturation_l = rtb_Saturation_l / rtb_Rem_k * rtb_Sqrt_d;
          for (i = 0; i < 3; i++) {
            rtb_Switch_l[i] = rtb_VectorConcatenate_hm[i + 3] * rtb_Saturation_l
              + rtb_VectorConcatenate_hm[i] * rtb_Switch_e_idx_0;
          }
        }

        /* End of Switch: '<S239>/Switch' */

        /* Delay: '<S241>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S244>/Integrator1' incorporates:
         *  Delay: '<S241>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S248>/Rem' incorporates:
         *  Constant: '<S248>/Constant1'
         *  DiscreteIntegrator: '<S244>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S243>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S248>/Switch' incorporates:
         *  Abs: '<S248>/Abs'
         *  Constant: '<S248>/Constant'
         *  Constant: '<S249>/Constant'
         *  Product: '<S248>/Multiply'
         *  RelationalOperator: '<S249>/Compare'
         *  Sum: '<S248>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S248>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Saturation_l = 1.0F;
          } else {
            rtb_Saturation_l = rtb_Rem_k;
          }

          /* End of Signum: '<S248>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Saturation_l;
        }

        /* End of Switch: '<S248>/Switch' */

        /* Gain: '<S243>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S243>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S243>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S192>/Bus Assignment1'
         *  Constant: '<S192>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S192>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_l[0];
        FMS_Y.FMS_Out.v_cmd = rtb_Switch_l[1];
        FMS_Y.FMS_Out.w_cmd = rtb_Switch_l[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S295>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S295>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S293>/Sum of Elements'
         */
        rtb_Switch_e_idx_0 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S295>/Math Function1' incorporates:
         *  Sum: '<S295>/Sum of Elements'
         *
         * About '<S295>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch_e_idx_0 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Switch_e_idx_0));
        } else {
          rtb_Rem_k = sqrtf(rtb_Switch_e_idx_0);
        }

        /* End of Math: '<S295>/Math Function1' */

        /* Switch: '<S295>/Switch' incorporates:
         *  Constant: '<S295>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S295>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Rem_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_l[0] = FMS_U.INS_Out.vn;
          rtb_Switch_l[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_l[2] = rtb_Rem_k;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S295>/Switch' */

        /* Product: '<S295>/Divide' */
        rtb_Divide_gz[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Divide_gz[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S298>/Sum of Elements' incorporates:
         *  Math: '<S298>/Math Function'
         *  SignalConversion: '<S298>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_l = rtb_Divide_gz[1] * rtb_Divide_gz[1] + rtb_Divide_gz[0]
          * rtb_Divide_gz[0];

        /* Math: '<S298>/Math Function1' incorporates:
         *  Sum: '<S298>/Sum of Elements'
         *
         * About '<S298>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Saturation_l));
        } else {
          rtb_Rem_k = sqrtf(rtb_Saturation_l);
        }

        /* End of Math: '<S298>/Math Function1' */

        /* Switch: '<S298>/Switch' incorporates:
         *  Constant: '<S298>/Constant'
         *  Product: '<S298>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_Switch_l[0] = rtb_Divide_gz[1];
          rtb_Switch_l[1] = rtb_Divide_gz[0];
          rtb_Switch_l[2] = rtb_Rem_k;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S298>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S258>/NearbyRefWP' incorporates:
         *  Constant: '<S192>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(rtb_Divide_lq, FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_gz, &rtb_Saturation1_i_idx_0);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* MATLAB Function: '<S258>/SearchL1RefWP' incorporates:
         *  Constant: '<S192>/L1'
         *  Delay: '<S240>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        A = rtb_MathFunction_crm_idx_0 * rtb_MathFunction_crm_idx_0 +
          rtb_MathFunction_crm_idx_1 * rtb_MathFunction_crm_idx_1;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        B = (rtb_MathFunction_crm_idx_0 * (FMS_DW.Delay_DSTATE_p[0] -
              FMS_U.INS_Out.x_R) + rtb_MathFunction_crm_idx_1 *
             (FMS_DW.Delay_DSTATE_p[1] - FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Saturation_l = -1.0F;
        rtb_a_b_idx_0 = 0.0F;
        rtb_a_b_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          B = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (B >= 0.0F) && (B <= 1.0F)) {
            rtb_Saturation_l = fmaxf(D, B);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Saturation_l = D;
            guard1 = true;
          } else {
            if ((B >= 0.0F) && (B <= 1.0F)) {
              rtb_Saturation_l = B;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Saturation_l = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_a_b_idx_0 = rtb_MathFunction_crm_idx_0 * rtb_Saturation_l +
            FMS_DW.Delay_DSTATE_p[0];
          rtb_a_b_idx_1 = rtb_MathFunction_crm_idx_1 * rtb_Saturation_l +
            FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S258>/OutRegionRegWP' incorporates:
         *  Delay: '<S240>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        B = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
             rtb_MathFunction_crm_idx_1 + (FMS_U.INS_Out.x_R -
              FMS_DW.Delay_DSTATE_p[0]) * rtb_MathFunction_crm_idx_0) /
          (rtb_MathFunction_crm_idx_0 * rtb_MathFunction_crm_idx_0 +
           rtb_MathFunction_crm_idx_1 * rtb_MathFunction_crm_idx_1);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_FixPtRelationalOperator = (B <= 0.0F);
        u = (B >= 1.0F);
        if (rtb_FixPtRelationalOperator) {
          rtb_Sign1_n_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Sign1_n_idx_0 = FMS_B.Cmd_In.sp_return[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          rtb_Sign1_n_idx_0 = B * rtb_MathFunction_crm_idx_0 +
            FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S258>/Switch1' incorporates:
         *  Constant: '<S288>/Constant'
         *  RelationalOperator: '<S288>/Compare'
         */
        if (rtb_Saturation1_i_idx_0 <= 0.0F) {
          /* Switch: '<S258>/Switch' incorporates:
           *  Constant: '<S287>/Constant'
           *  MATLAB Function: '<S258>/SearchL1RefWP'
           *  RelationalOperator: '<S287>/Compare'
           */
          if (rtb_Saturation_l >= 0.0F) {
            rtb_Divide_gz[0] = rtb_a_b_idx_0;
            rtb_Divide_gz[1] = rtb_a_b_idx_1;
          } else {
            rtb_Divide_gz[0] = rtb_Sign1_n_idx_0;

            /* MATLAB Function: '<S258>/OutRegionRegWP' incorporates:
             *  Delay: '<S240>/Delay'
             *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator) {
              rtb_Divide_gz[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Divide_gz[1] = FMS_B.Cmd_In.sp_return[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              rtb_Divide_gz[1] = B * rtb_MathFunction_crm_idx_1 +
                FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S258>/Switch' */
        }

        /* End of Switch: '<S258>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S259>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_MathFunction_crm_idx_1 = rtb_Divide_gz[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Divide_gz[0] = rtb_MathFunction_crm_idx_1;
        rtb_Saturation1_i_idx_0 = rtb_MathFunction_crm_idx_1 *
          rtb_MathFunction_crm_idx_1;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S259>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S296>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_MathFunction_crm_idx_1 = rtb_Divide_gz[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S296>/Math Function' incorporates:
         *  Math: '<S294>/Square'
         */
        rtb_Saturation_l = rtb_MathFunction_crm_idx_1 *
          rtb_MathFunction_crm_idx_1;

        /* Sum: '<S296>/Sum of Elements' incorporates:
         *  Math: '<S296>/Math Function'
         */
        rtb_Rem_k = rtb_Saturation_l + rtb_Saturation1_i_idx_0;

        /* Math: '<S296>/Math Function1' incorporates:
         *  Sum: '<S296>/Sum of Elements'
         *
         * About '<S296>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S296>/Math Function1' */

        /* Switch: '<S296>/Switch' incorporates:
         *  Constant: '<S296>/Constant'
         *  Product: '<S296>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MathFunction_crm_idx_0 = rtb_Divide_gz[0];
        } else {
          rtb_MathFunction_crm_idx_0 = 0.0F;
          rtb_MathFunction_crm_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S296>/Switch' */

        /* Product: '<S296>/Divide' */
        rtb_Divide_lq[0] = rtb_MathFunction_crm_idx_0 / rtb_Rem_k;
        rtb_Divide_lq[1] = rtb_MathFunction_crm_idx_1 / rtb_Rem_k;

        /* Sum: '<S299>/Sum of Elements' incorporates:
         *  Math: '<S299>/Math Function'
         *  SignalConversion: '<S299>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_k = rtb_Divide_lq[1] * rtb_Divide_lq[1] + rtb_Divide_lq[0] *
          rtb_Divide_lq[0];

        /* Math: '<S299>/Math Function1' incorporates:
         *  Sum: '<S299>/Sum of Elements'
         *
         * About '<S299>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S299>/Math Function1' */

        /* Switch: '<S299>/Switch' incorporates:
         *  Constant: '<S299>/Constant'
         *  Product: '<S299>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MathFunction_crm_idx_0 = rtb_Divide_lq[1];
          rtb_MathFunction_crm_idx_1 = rtb_Divide_lq[0];
        } else {
          rtb_MathFunction_crm_idx_0 = 0.0F;
          rtb_MathFunction_crm_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S299>/Switch' */

        /* Product: '<S299>/Divide' */
        rtb_Divide_lq[0] = rtb_MathFunction_crm_idx_0 / rtb_Rem_k;

        /* Math: '<S294>/Square' */
        rtb_Saturation1_i_idx_0 = rtb_Divide_gz[0] * rtb_Divide_gz[0];
        rtb_Divide_gz[0] = rtb_Switch_l[0] / rtb_Switch_l[2];

        /* Product: '<S299>/Divide' incorporates:
         *  Product: '<S298>/Divide'
         */
        rtb_Divide_lq[1] = rtb_MathFunction_crm_idx_1 / rtb_Rem_k;

        /* Product: '<S298>/Divide' */
        rtb_MathFunction_crm_idx_1 = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sqrt: '<S293>/Sqrt' */
        rtb_Rem_k = sqrtf(rtb_Switch_e_idx_0);

        /* Gain: '<S259>/Gain' incorporates:
         *  Math: '<S259>/Square'
         */
        rtb_Switch_e_idx_0 = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S297>/Subtract' incorporates:
         *  Product: '<S297>/Multiply'
         *  Product: '<S297>/Multiply1'
         */
        rtb_Rem_k = rtb_Divide_lq[0] * rtb_MathFunction_crm_idx_1 -
          rtb_Divide_lq[1] * rtb_Divide_gz[0];

        /* Signum: '<S292>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S292>/Sign1' */

        /* Switch: '<S292>/Switch2' incorporates:
         *  Constant: '<S292>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S292>/Switch2' */

        /* DotProduct: '<S292>/Dot Product' */
        rtb_MathFunction_crm_idx_1 = rtb_Divide_gz[0] * rtb_Divide_lq[0] +
          rtb_MathFunction_crm_idx_1 * rtb_Divide_lq[1];

        /* Trigonometry: '<S292>/Acos' incorporates:
         *  DotProduct: '<S292>/Dot Product'
         */
        if (rtb_MathFunction_crm_idx_1 > 1.0F) {
          rtb_MathFunction_crm_idx_1 = 1.0F;
        } else {
          if (rtb_MathFunction_crm_idx_1 < -1.0F) {
            rtb_MathFunction_crm_idx_1 = -1.0F;
          }
        }

        /* Product: '<S292>/Multiply' incorporates:
         *  Trigonometry: '<S292>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_MathFunction_crm_idx_1);

        /* Saturate: '<S259>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S259>/Saturation' */

        /* Product: '<S259>/Divide' incorporates:
         *  Constant: '<S192>/L1'
         *  Constant: '<S259>/Constant'
         *  MinMax: '<S259>/Max'
         *  MinMax: '<S259>/Min'
         *  Product: '<S259>/Multiply1'
         *  Sqrt: '<S294>/Sqrt'
         *  Sum: '<S294>/Sum of Elements'
         *  Trigonometry: '<S259>/Sin'
         */
        rtb_Switch_e_idx_0 = arm_sin_f32(rtb_Rem_k) * rtb_Switch_e_idx_0 / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_l + rtb_Saturation1_i_idx_0),
            0.5F));

        /* Sum: '<S241>/Sum2' incorporates:
         *  Delay: '<S241>/Delay'
         */
        rtb_a_pr -= FMS_DW.Delay_DSTATE_a;

        /* Math: '<S245>/Rem' incorporates:
         *  Constant: '<S245>/Constant1'
         */
        rtb_Saturation1_i_idx_0 = rt_remf(rtb_a_pr, 6.28318548F);

        /* Switch: '<S245>/Switch' incorporates:
         *  Abs: '<S245>/Abs'
         *  Constant: '<S245>/Constant'
         *  Constant: '<S251>/Constant'
         *  Product: '<S245>/Multiply'
         *  RelationalOperator: '<S251>/Compare'
         *  Sum: '<S245>/Add'
         */
        if (fabsf(rtb_Saturation1_i_idx_0) > 3.14159274F) {
          /* Signum: '<S245>/Sign' */
          if (rtb_Saturation1_i_idx_0 < 0.0F) {
            rtb_a_pr = -1.0F;
          } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
            rtb_a_pr = 1.0F;
          } else {
            rtb_a_pr = rtb_Saturation1_i_idx_0;
          }

          /* End of Signum: '<S245>/Sign' */
          rtb_Saturation1_i_idx_0 -= 6.28318548F * rtb_a_pr;
        }

        /* End of Switch: '<S245>/Switch' */

        /* Sum: '<S241>/Sum' incorporates:
         *  Delay: '<S241>/Delay'
         */
        rtb_a_pr = rtb_Saturation1_i_idx_0 + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S250>/Multiply1' incorporates:
         *  Constant: '<S250>/const1'
         *  DiscreteIntegrator: '<S244>/Integrator'
         */
        rtb_Saturation1_i_idx_0 = FMS_DW.Integrator_DSTATE_b * 0.785398185F;

        /* Sum: '<S250>/Add' incorporates:
         *  DiscreteIntegrator: '<S244>/Integrator1'
         *  Sum: '<S244>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_e - rtb_a_pr) +
          rtb_Saturation1_i_idx_0;

        /* Signum: '<S250>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_a_pr = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_a_pr = 1.0F;
        } else {
          rtb_a_pr = rtb_Rem_k;
        }

        /* End of Signum: '<S250>/Sign' */

        /* Sum: '<S250>/Add2' incorporates:
         *  Abs: '<S250>/Abs'
         *  Gain: '<S250>/Gain'
         *  Gain: '<S250>/Gain1'
         *  Product: '<S250>/Multiply2'
         *  Product: '<S250>/Multiply3'
         *  Sqrt: '<S250>/Sqrt'
         *  Sum: '<S250>/Add1'
         *  Sum: '<S250>/Subtract'
         */
        rtb_a_pr = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_l) *
                          FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_a_pr +
          rtb_Saturation1_i_idx_0;

        /* Sum: '<S250>/Add4' */
        rtb_Saturation1_i_idx_0 += rtb_Rem_k - rtb_a_pr;

        /* Sum: '<S250>/Add3' */
        rtb_Saturation_l = rtb_Rem_k + FMS_ConstB.d_l;

        /* Sum: '<S250>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_l;

        /* Signum: '<S250>/Sign1' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S250>/Sign1' */

        /* Signum: '<S250>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S250>/Sign2' */

        /* Sum: '<S250>/Add5' incorporates:
         *  Gain: '<S250>/Gain2'
         *  Product: '<S250>/Multiply4'
         *  Sum: '<S250>/Subtract2'
         */
        rtb_a_pr += (rtb_Saturation_l - rtb_Rem_k) * 0.5F *
          rtb_Saturation1_i_idx_0;

        /* Update for Delay: '<S260>/Delay' */
        FMS_DW.icLoad_o = 0U;

        /* Update for DiscreteIntegrator: '<S301>/Discrete-Time Integrator' incorporates:
         *  Product: '<S260>/Divide1'
         */
        FMS_DW.l1_heading_p += rtb_Switch_e_idx_0 / rtb_Sqrt_d * 0.004F;

        /* Update for Delay: '<S240>/Delay' */
        FMS_DW.icLoad_cg = 0U;

        /* Update for Delay: '<S241>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S244>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S244>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S250>/Subtract3' */
        rtb_Saturation_l = rtb_a_pr - FMS_ConstB.d_l;

        /* Sum: '<S250>/Add6' */
        B = rtb_a_pr + FMS_ConstB.d_l;

        /* Signum: '<S250>/Sign5' incorporates:
         *  Signum: '<S250>/Sign6'
         */
        if (rtb_a_pr < 0.0F) {
          rtb_Sqrt_d = -1.0F;

          /* Signum: '<S250>/Sign6' */
          rtb_Rem_k = -1.0F;
        } else if (rtb_a_pr > 0.0F) {
          rtb_Sqrt_d = 1.0F;

          /* Signum: '<S250>/Sign6' */
          rtb_Rem_k = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_a_pr;

          /* Signum: '<S250>/Sign6' */
          rtb_Rem_k = rtb_a_pr;
        }

        /* End of Signum: '<S250>/Sign5' */

        /* Signum: '<S250>/Sign3' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S250>/Sign3' */

        /* Signum: '<S250>/Sign4' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S250>/Sign4' */

        /* Update for DiscreteIntegrator: '<S244>/Integrator' incorporates:
         *  Constant: '<S250>/const'
         *  Gain: '<S250>/Gain3'
         *  Product: '<S250>/Divide'
         *  Product: '<S250>/Multiply5'
         *  Product: '<S250>/Multiply6'
         *  Sum: '<S250>/Subtract4'
         *  Sum: '<S250>/Subtract5'
         *  Sum: '<S250>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_a_pr / FMS_ConstB.d_l - rtb_Sqrt_d) *
          FMS_ConstB.Gain4_n * ((B - rtb_Saturation_l) * 0.5F) - rtb_Rem_k *
          1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_b >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_b = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_b <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_b = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S244>/Integrator' */
        /* End of Outputs for SubSystem: '<S24>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S24>/Hold' incorporates:
           *  ActionPort: '<S190>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Chart: '<S199>/Motion Status'
           *  Chart: '<S209>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_d;

          /* End of SystemReset for SubSystem: '<S24>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Hold' incorporates:
         *  ActionPort: '<S190>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S199>/Motion Status' incorporates:
         *  Abs: '<S199>/Abs'
         *  Constant: '<S199>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S198>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_p;
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
        switch (rtb_state_a) {
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
            /* SystemReset for IfAction SubSystem: '<S198>/Hold Control' incorporates:
             *  ActionPort: '<S201>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S198>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S198>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S198>/Hold Control' incorporates:
           *  ActionPort: '<S201>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S198>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S198>/Brake Control' incorporates:
           *  ActionPort: '<S200>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S198>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S198>/Move Control' incorporates:
             *  ActionPort: '<S202>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S198>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S198>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S198>/Move Control' incorporates:
           *  ActionPort: '<S202>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S198>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S198>/Switch Case' */

        /* Chart: '<S209>/Motion State' incorporates:
         *  Abs: '<S209>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.temporalCounter_i1_a < 255U) {
          FMS_DW.temporalCounter_i1_a++;
        }

        if (FMS_DW.is_active_c15_FMS == 0U) {
          FMS_DW.is_active_c15_FMS = 1U;
          FMS_DW.is_c15_FMS = FMS_IN_Move_c;
          rtb_state_a = MotionState_Move;
        } else {
          switch (FMS_DW.is_c15_FMS) {
           case FMS_IN_Brake_b:
            rtb_state_a = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_a >=
                 250U)) {
              FMS_DW.is_c15_FMS = FMS_IN_Hold_m;
              rtb_state_a = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            break;

           case FMS_IN_Hold_m:
            rtb_state_a = MotionState_Hold;
            break;

           default:
            FMS_DW.is_c15_FMS = FMS_IN_Brake_b;
            FMS_DW.temporalCounter_i1_a = 0U;
            rtb_state_a = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S209>/Motion State' */

        /* SwitchCase: '<S208>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_bn;
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        switch (rtb_state_a) {
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
            /* InitializeConditions for IfAction SubSystem: '<S208>/Hold Control' incorporates:
             *  ActionPort: '<S211>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S208>/Switch Case' incorporates:
             *  Delay: '<S211>/Delay'
             */
            FMS_DW.icLoad_g = 1U;

            /* End of InitializeConditions for SubSystem: '<S208>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S208>/Hold Control' incorporates:
           *  ActionPort: '<S211>/Action Port'
           */
          /* Delay: '<S211>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (FMS_DW.icLoad_g != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.Delay_DSTATE_g = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S211>/Sum' incorporates:
           *  Delay: '<S211>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Sqrt_d = FMS_DW.Delay_DSTATE_g - FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Abs: '<S214>/Abs' */
          rtb_a_pr = fabsf(rtb_Sqrt_d);

          /* Switch: '<S214>/Switch' incorporates:
           *  Constant: '<S214>/Constant'
           *  Constant: '<S215>/Constant'
           *  Product: '<S214>/Multiply'
           *  RelationalOperator: '<S215>/Compare'
           *  Sum: '<S214>/Subtract'
           */
          if (rtb_a_pr > 3.14159274F) {
            /* Signum: '<S214>/Sign' */
            if (rtb_Sqrt_d < 0.0F) {
              rtb_Sqrt_d = -1.0F;
            } else {
              if (rtb_Sqrt_d > 0.0F) {
                rtb_Sqrt_d = 1.0F;
              }
            }

            /* End of Signum: '<S214>/Sign' */
            rtb_Sqrt_d *= rtb_a_pr - 6.28318548F;
          }

          /* End of Switch: '<S214>/Switch' */

          /* Gain: '<S211>/Gain2' */
          FMS_B.Merge_n = FMS_PARAM.YAW_P * rtb_Sqrt_d;

          /* Update for Delay: '<S211>/Delay' */
          FMS_DW.icLoad_g = 0U;

          /* End of Outputs for SubSystem: '<S208>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S208>/Brake Control' incorporates:
           *  ActionPort: '<S210>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S208>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S208>/Move Control' incorporates:
             *  ActionPort: '<S212>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S208>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S217>/Integrator'
             *  DiscreteIntegrator: '<S217>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_k = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S208>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S208>/Move Control' incorporates:
           *  ActionPort: '<S212>/Action Port'
           */
          /* Product: '<S218>/Multiply1' incorporates:
           *  Constant: '<S218>/const1'
           *  DiscreteIntegrator: '<S217>/Integrator'
           */
          rtb_Saturation_l = FMS_DW.Integrator_DSTATE_h * 0.02F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S216>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Switch_e_idx_0 = 0.0F;
          } else {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S216>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Sum: '<S218>/Add' incorporates:
           *  DiscreteIntegrator: '<S217>/Integrator1'
           *  Gain: '<S212>/Gain1'
           *  Gain: '<S216>/Gain'
           *  Sum: '<S217>/Subtract'
           */
          rtb_Sqrt_d = (FMS_DW.Integrator1_DSTATE_k - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Switch_e_idx_0 * FMS_PARAM.YAW_RATE_LIM) +
            rtb_Saturation_l;

          /* Signum: '<S218>/Sign' */
          if (rtb_Sqrt_d < 0.0F) {
            rtb_a_pr = -1.0F;
          } else if (rtb_Sqrt_d > 0.0F) {
            rtb_a_pr = 1.0F;
          } else {
            rtb_a_pr = rtb_Sqrt_d;
          }

          /* End of Signum: '<S218>/Sign' */

          /* Sum: '<S218>/Add2' incorporates:
           *  Abs: '<S218>/Abs'
           *  Gain: '<S218>/Gain'
           *  Gain: '<S218>/Gain1'
           *  Product: '<S218>/Multiply2'
           *  Product: '<S218>/Multiply3'
           *  Sqrt: '<S218>/Sqrt'
           *  Sum: '<S218>/Add1'
           *  Sum: '<S218>/Subtract'
           */
          rtb_a_pr = (sqrtf((8.0F * fabsf(rtb_Sqrt_d) + FMS_ConstB.d_j) *
                            FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_a_pr
            + rtb_Saturation_l;

          /* Sum: '<S218>/Add4' */
          rtb_Rem_k = (rtb_Sqrt_d - rtb_a_pr) + rtb_Saturation_l;

          /* Sum: '<S218>/Add3' */
          rtb_Saturation_l = rtb_Sqrt_d + FMS_ConstB.d_j;

          /* Sum: '<S218>/Subtract1' */
          rtb_Sqrt_d -= FMS_ConstB.d_j;

          /* Signum: '<S218>/Sign1' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else {
            if (rtb_Saturation_l > 0.0F) {
              rtb_Saturation_l = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign1' */

          /* Signum: '<S218>/Sign2' */
          if (rtb_Sqrt_d < 0.0F) {
            rtb_Sqrt_d = -1.0F;
          } else {
            if (rtb_Sqrt_d > 0.0F) {
              rtb_Sqrt_d = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign2' */

          /* Sum: '<S218>/Add5' incorporates:
           *  Gain: '<S218>/Gain2'
           *  Product: '<S218>/Multiply4'
           *  Sum: '<S218>/Subtract2'
           */
          rtb_a_pr += (rtb_Saturation_l - rtb_Sqrt_d) * 0.5F * rtb_Rem_k;

          /* SignalConversion: '<S212>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
           *  DiscreteIntegrator: '<S217>/Integrator1'
           */
          FMS_B.Merge_n = FMS_DW.Integrator1_DSTATE_k;

          /* Update for DiscreteIntegrator: '<S217>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S217>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_k += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Sum: '<S218>/Subtract3' */
          rtb_Saturation_l = rtb_a_pr - FMS_ConstB.d_j;

          /* Sum: '<S218>/Add6' */
          B = rtb_a_pr + FMS_ConstB.d_j;

          /* Signum: '<S218>/Sign5' incorporates:
           *  Signum: '<S218>/Sign6'
           */
          if (rtb_a_pr < 0.0F) {
            rtb_Sqrt_d = -1.0F;

            /* Signum: '<S218>/Sign6' */
            rtb_Rem_k = -1.0F;
          } else if (rtb_a_pr > 0.0F) {
            rtb_Sqrt_d = 1.0F;

            /* Signum: '<S218>/Sign6' */
            rtb_Rem_k = 1.0F;
          } else {
            rtb_Sqrt_d = rtb_a_pr;

            /* Signum: '<S218>/Sign6' */
            rtb_Rem_k = rtb_a_pr;
          }

          /* End of Signum: '<S218>/Sign5' */

          /* Signum: '<S218>/Sign3' */
          if (B < 0.0F) {
            B = -1.0F;
          } else {
            if (B > 0.0F) {
              B = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign3' */

          /* Signum: '<S218>/Sign4' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else {
            if (rtb_Saturation_l > 0.0F) {
              rtb_Saturation_l = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign4' */

          /* Update for DiscreteIntegrator: '<S217>/Integrator' incorporates:
           *  Constant: '<S218>/const'
           *  Gain: '<S218>/Gain3'
           *  Product: '<S218>/Divide'
           *  Product: '<S218>/Multiply5'
           *  Product: '<S218>/Multiply6'
           *  Sum: '<S218>/Subtract4'
           *  Sum: '<S218>/Subtract5'
           *  Sum: '<S218>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_a_pr / FMS_ConstB.d_j - rtb_Sqrt_d)
            * FMS_ConstB.Gain4_c * ((B - rtb_Saturation_l) * 0.5F) - rtb_Rem_k *
            15.707963F) * 0.004F;

          /* End of Outputs for SubSystem: '<S208>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S208>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S190>/Bus Assignment'
         *  Constant: '<S190>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S190>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S208>/Saturation' */
        if (FMS_B.Merge_n > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S190>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S190>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S190>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n;
        }

        /* End of Saturate: '<S208>/Saturation' */

        /* BusAssignment: '<S190>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.v_cmd = 0.0F;

        /* Saturate: '<S198>/Saturation1' */
        if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S190>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S190>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S190>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_e;
        }

        /* End of Saturate: '<S198>/Saturation1' */
        /* End of Outputs for SubSystem: '<S24>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S24>/Unknown' incorporates:
         *  ActionPort: '<S194>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

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
       *  Math: '<S177>/Square'
       *  Sum: '<S139>/Subtract'
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
      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S22>/Offboard' incorporates:
         *  ActionPort: '<S113>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S113>/Bus Assignment'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S113>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S113>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n;

        /* End of Outputs for SubSystem: '<S22>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S22>/Mission' incorporates:
           *  ActionPort: '<S112>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S22>/Switch Case' incorporates:
           *  UnitDelay: '<S115>/Delay Input1'
           *
           * Block description for '<S115>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S22>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S22>/Mission' incorporates:
           *  ActionPort: '<S112>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S112>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S22>/Switch Case' incorporates:
           *  Delay: '<S120>/Delay'
           *  Delay: '<S140>/Delay'
           *  DiscreteIntegrator: '<S123>/Integrator'
           *  DiscreteIntegrator: '<S123>/Integrator1'
           *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_i = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE = 0.0F;

          /* End of SystemReset for SubSystem: '<S112>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S22>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Mission' incorporates:
         *  ActionPort: '<S112>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* RelationalOperator: '<S115>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S115>/Delay Input1'
         *
         * Block description for '<S115>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S112>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S116>/Reset'
         */
        if (rtb_FixPtRelationalOperator &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* InitializeConditions for Delay: '<S140>/Delay' */
          FMS_DW.icLoad_i = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S120>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S123>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S123>/Integrator' */
          FMS_DW.Integrator_DSTATE = 0.0F;
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator;

        /* Delay: '<S140>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_i != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S136>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S144>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_k = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Subtract3_f[0] = rtb_Rem_k * rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Rem_k = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S144>/Square' */
        rtb_Rem_k *= rtb_Rem_k;

        /* Sqrt: '<S144>/Sqrt' incorporates:
         *  Sum: '<S144>/Sum of Elements'
         */
        rtb_Sqrt_d = sqrtf(rtb_Subtract3_f[0] + rtb_Rem_k);

        /* Switch: '<S136>/Switch' incorporates:
         *  Constant: '<S136>/vel'
         */
        if (rtb_Sqrt_d > FMS_PARAM.L1) {
          rtb_Sqrt_d = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S136>/Gain' */
          rtb_Sqrt_d *= 0.5F;

          /* Saturate: '<S136>/Saturation' */
          if (rtb_Sqrt_d > FMS_PARAM.CRUISE_SPEED) {
            rtb_Sqrt_d = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Sqrt_d < 0.5F) {
              rtb_Sqrt_d = 0.5F;
            }
          }

          /* End of Saturate: '<S136>/Saturation' */
        }

        /* End of Switch: '<S136>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S116>/Sum' incorporates:
         *  MATLAB Function: '<S138>/OutRegionRegWP'
         *  MATLAB Function: '<S138>/SearchL1RefWP'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S141>/Sum1'
         *  Switch: '<S118>/Switch'
         */
        rtb_Sign1_n_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation1_i_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S134>/Sum of Elements' incorporates:
         *  Math: '<S134>/Math Function'
         *  Sum: '<S116>/Sum'
         */
        rtb_Switch_e_idx_0 = rtb_Saturation1_i_idx_0 * rtb_Saturation1_i_idx_0 +
          rtb_Sign1_n_idx_0 * rtb_Sign1_n_idx_0;

        /* Math: '<S134>/Math Function1' incorporates:
         *  Sum: '<S134>/Sum of Elements'
         *
         * About '<S134>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch_e_idx_0 < 0.0F) {
          rtb_a_pr = -sqrtf(fabsf(rtb_Switch_e_idx_0));
        } else {
          rtb_a_pr = sqrtf(rtb_Switch_e_idx_0);
        }

        /* End of Math: '<S134>/Math Function1' */

        /* Switch: '<S134>/Switch' incorporates:
         *  Constant: '<S134>/Constant'
         *  Product: '<S134>/Product'
         *  Sum: '<S116>/Sum'
         */
        if (rtb_a_pr > 0.0F) {
          rtb_MathFunction_crm_idx_0 = rtb_Saturation1_i_idx_0;
          rtb_MathFunction_crm_idx_1 = rtb_Sign1_n_idx_0;
          rtb_Rem_k = rtb_a_pr;
        } else {
          rtb_MathFunction_crm_idx_0 = 0.0F;
          rtb_MathFunction_crm_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S134>/Switch' */

        /* Product: '<S134>/Divide' */
        rtb_Subtract3_f[0] = rtb_MathFunction_crm_idx_0 / rtb_Rem_k;
        rtb_Subtract3_f[1] = rtb_MathFunction_crm_idx_1 / rtb_Rem_k;

        /* Sum: '<S132>/Subtract' incorporates:
         *  Product: '<S132>/Multiply'
         *  Product: '<S132>/Multiply1'
         */
        rtb_a_pr = rtb_Subtract3_f[0] * FMS_ConstB.Divide[1] - rtb_Subtract3_f[1]
          * FMS_ConstB.Divide[0];

        /* Signum: '<S121>/Sign1' */
        if (rtb_a_pr < 0.0F) {
          rtb_a_pr = -1.0F;
        } else {
          if (rtb_a_pr > 0.0F) {
            rtb_a_pr = 1.0F;
          }
        }

        /* End of Signum: '<S121>/Sign1' */

        /* Switch: '<S121>/Switch2' incorporates:
         *  Constant: '<S121>/Constant4'
         */
        if (rtb_a_pr == 0.0F) {
          rtb_a_pr = 1.0F;
        }

        /* End of Switch: '<S121>/Switch2' */

        /* DotProduct: '<S121>/Dot Product' */
        rtb_Saturation_l = FMS_ConstB.Divide[0] * rtb_Subtract3_f[0] +
          FMS_ConstB.Divide[1] * rtb_Subtract3_f[1];

        /* Trigonometry: '<S121>/Acos' incorporates:
         *  DotProduct: '<S121>/Dot Product'
         */
        if (rtb_Saturation_l > 1.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          if (rtb_Saturation_l < -1.0F) {
            rtb_Saturation_l = -1.0F;
          }
        }

        /* Product: '<S121>/Multiply' incorporates:
         *  Trigonometry: '<S121>/Acos'
         */
        rtb_a_pr *= acosf(rtb_Saturation_l);

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S125>/Rem' incorporates:
         *  Constant: '<S125>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S120>/Sum1'
         */
        rtb_Saturation_l = rt_remf(rtb_a_pr - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S125>/Switch' incorporates:
         *  Abs: '<S125>/Abs'
         *  Constant: '<S125>/Constant'
         *  Constant: '<S131>/Constant'
         *  Product: '<S125>/Multiply'
         *  RelationalOperator: '<S131>/Compare'
         *  Sum: '<S125>/Add'
         */
        if (fabsf(rtb_Saturation_l) > 3.14159274F) {
          /* Signum: '<S125>/Sign' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Rem_k = -1.0F;
          } else if (rtb_Saturation_l > 0.0F) {
            rtb_Rem_k = 1.0F;
          } else {
            rtb_Rem_k = rtb_Saturation_l;
          }

          /* End of Signum: '<S125>/Sign' */
          rtb_Saturation_l -= 6.28318548F * rtb_Rem_k;
        }

        /* End of Switch: '<S125>/Switch' */

        /* Abs: '<S118>/Abs' */
        rtb_Saturation_l = fabsf(rtb_Saturation_l);

        /* Switch: '<S118>/Switch' incorporates:
         *  Constant: '<S118>/Constant'
         *  Product: '<S140>/Multiply'
         *  Sum: '<S140>/Sum'
         */
        if (rtb_Saturation_l > 0.34906584F) {
          rtb_MathFunction_crm_idx_0 = 0.0F;
          rtb_MathFunction_crm_idx_1 = 0.0F;
          rtb_Rem_k = 0.0F;
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S140>/Sum' incorporates:
           *  Delay: '<S140>/Delay'
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_l = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S185>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_MathFunction_crm_idx_0 = rtb_Saturation_l;
          rtb_Divide_gz[0] = rtb_Saturation_l;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S140>/Sum' incorporates:
           *  Delay: '<S140>/Delay'
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_l = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S187>/Constant4'
           */
          rtb_VectorConcatenate_hm[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S186>/Gain' incorporates:
           *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S184>/Add'
           */
          rtb_Rem_k = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Trigonometry: '<S187>/Trigonometric Function3' */
          rtb_VectorConcatenate_hm[4] = arm_cos_f32(rtb_Rem_k);

          /* Gain: '<S187>/Gain' incorporates:
           *  Trigonometry: '<S187>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_hm[3] = -arm_sin_f32(rtb_Rem_k);

          /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S187>/Constant3'
           */
          rtb_VectorConcatenate_hm[2] = 0.0F;

          /* Trigonometry: '<S187>/Trigonometric Function' */
          rtb_VectorConcatenate_hm[1] = arm_sin_f32(rtb_Rem_k);

          /* Trigonometry: '<S187>/Trigonometric Function1' */
          rtb_VectorConcatenate_hm[0] = arm_cos_f32(rtb_Rem_k);

          /* SignalConversion: '<S187>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3_e[0];
          rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3_e[1];
          rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* Sum: '<S185>/Sum of Elements' incorporates:
           *  Math: '<S185>/Math Function'
           */
          rtb_Switch_e_idx_0 = rtb_MathFunction_crm_idx_0 *
            rtb_MathFunction_crm_idx_0 + rtb_Saturation_l * rtb_Saturation_l;

          /* Math: '<S185>/Math Function1' incorporates:
           *  Sum: '<S185>/Sum of Elements'
           *
           * About '<S185>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch_e_idx_0 < 0.0F) {
            rtb_Rem_k = -sqrtf(fabsf(rtb_Switch_e_idx_0));
          } else {
            rtb_Rem_k = sqrtf(rtb_Switch_e_idx_0);
          }

          /* End of Math: '<S185>/Math Function1' */

          /* Switch: '<S185>/Switch' incorporates:
           *  Constant: '<S185>/Constant'
           *  Product: '<S185>/Product'
           */
          if (rtb_Rem_k > 0.0F) {
            rtb_Switch_e_idx_0 = rtb_Divide_gz[0];
          } else {
            rtb_Switch_e_idx_0 = 0.0F;
            rtb_Saturation_l = 0.0F;
            rtb_Rem_k = 1.0F;
          }

          /* End of Switch: '<S185>/Switch' */

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S141>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_crm_idx_0 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_crm_idx_1 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S141>/Divide' incorporates:
           *  Math: '<S142>/Square'
           *  Math: '<S143>/Square'
           *  Sqrt: '<S142>/Sqrt'
           *  Sqrt: '<S143>/Sqrt'
           *  Sum: '<S141>/Sum'
           *  Sum: '<S142>/Sum of Elements'
           *  Sum: '<S143>/Sum of Elements'
           */
          rtb_MathFunction_crm_idx_1 = sqrtf(rtb_MathFunction_crm_idx_0 *
            rtb_MathFunction_crm_idx_0 + rtb_MathFunction_crm_idx_1 *
            rtb_MathFunction_crm_idx_1) / sqrtf(rtb_Sign1_n_idx_0 *
            rtb_Sign1_n_idx_0 + rtb_Saturation1_i_idx_0 *
            rtb_Saturation1_i_idx_0);

          /* Saturate: '<S141>/Saturation' */
          if (rtb_MathFunction_crm_idx_1 > 1.0F) {
            rtb_MathFunction_crm_idx_1 = 1.0F;
          } else {
            if (rtb_MathFunction_crm_idx_1 < 0.0F) {
              rtb_MathFunction_crm_idx_1 = 0.0F;
            }
          }

          /* End of Saturate: '<S141>/Saturation' */

          /* Product: '<S183>/Multiply2' incorporates:
           *  Product: '<S185>/Divide'
           */
          rtb_Switch_e_idx_0 = rtb_Switch_e_idx_0 / rtb_Rem_k * rtb_Sqrt_d;
          rtb_Saturation_l = rtb_Saturation_l / rtb_Rem_k * rtb_Sqrt_d;

          /* Product: '<S140>/Multiply' */
          for (i = 0; i < 3; i++) {
            rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_hm[i + 3] *
              rtb_Saturation_l + rtb_VectorConcatenate_hm[i] *
              rtb_Switch_e_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S135>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S141>/Multiply'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S135>/Sum2'
           *  Sum: '<S141>/Add'
           *  Sum: '<S141>/Subtract'
           */
          rtb_Rem_k = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_B.Cmd_In.cur_waypoint[2]) * rtb_MathFunction_crm_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction_crm_idx_0 = rtb_VectorConcatenate_a[0];
          rtb_MathFunction_crm_idx_1 = rtb_VectorConcatenate_a[1];

          /* Saturate: '<S135>/Saturation1' incorporates:
           *  Product: '<S140>/Multiply'
           */
          if (rtb_Rem_k > FMS_PARAM.VEL_Z_LIM) {
            rtb_Rem_k = FMS_PARAM.VEL_Z_LIM;
          } else {
            if (rtb_Rem_k < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Rem_k = -FMS_PARAM.VEL_Z_LIM;
            }
          }

          /* End of Saturate: '<S135>/Saturation1' */
        }

        /* Delay: '<S120>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S123>/Integrator1' incorporates:
         *  Delay: '<S120>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S127>/Rem' incorporates:
         *  Constant: '<S127>/Constant1'
         *  DiscreteIntegrator: '<S123>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S122>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S127>/Switch' incorporates:
         *  Abs: '<S127>/Abs'
         *  Constant: '<S127>/Constant'
         *  Constant: '<S128>/Constant'
         *  Product: '<S127>/Multiply'
         *  RelationalOperator: '<S128>/Compare'
         *  Sum: '<S127>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S127>/Sign' */
          if (B < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else if (B > 0.0F) {
            rtb_Saturation_l = 1.0F;
          } else {
            rtb_Saturation_l = B;
          }

          /* End of Signum: '<S127>/Sign' */
          B -= 6.28318548F * rtb_Saturation_l;
        }

        /* End of Switch: '<S127>/Switch' */

        /* Gain: '<S122>/Gain2' */
        B *= FMS_PARAM.YAW_P;

        /* Saturate: '<S122>/Saturation' */
        if (B > FMS_PARAM.YAW_RATE_LIM) {
          B = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (B < -FMS_PARAM.YAW_RATE_LIM) {
            B = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S122>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S116>/Bus Assignment'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S116>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S116>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_crm_idx_0;
        FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_crm_idx_1;
        FMS_Y.FMS_Out.w_cmd = rtb_Rem_k;
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S178>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S178>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Switch_e_idx_0 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S178>/Math Function1' incorporates:
         *  Sum: '<S178>/Sum of Elements'
         *
         * About '<S178>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Switch_e_idx_0 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Switch_e_idx_0));
        } else {
          B = sqrtf(rtb_Switch_e_idx_0);
        }

        /* End of Math: '<S178>/Math Function1' */

        /* Switch: '<S178>/Switch' incorporates:
         *  Constant: '<S178>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S178>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (B > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction_crm_idx_0 = FMS_U.INS_Out.vn;
          rtb_MathFunction_crm_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Rem_k = B;
        } else {
          rtb_MathFunction_crm_idx_0 = 0.0F;
          rtb_MathFunction_crm_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S178>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S138>/NearbyRefWP' incorporates:
         *  Constant: '<S116>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_l[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Subtract3_f, &rtb_Switch_e_idx_0);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* MATLAB Function: '<S138>/SearchL1RefWP' incorporates:
         *  Constant: '<S116>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        A = rtb_Sign1_n_idx_0 * rtb_Sign1_n_idx_0 + rtb_Saturation1_i_idx_0 *
          rtb_Saturation1_i_idx_0;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        B = (rtb_Sign1_n_idx_0 * (FMS_B.Cmd_In.cur_waypoint[0] -
              FMS_U.INS_Out.x_R) + rtb_Saturation1_i_idx_0 *
             (FMS_B.Cmd_In.cur_waypoint[1] - FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_B.Cmd_In.cur_waypoint[0] *
                        FMS_B.Cmd_In.cur_waypoint[0]) +
                       FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint
                       [1]) - (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0]
          + FMS_U.INS_Out.y_R * FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Saturation_l = -1.0F;
        rtb_a_b_idx_0 = 0.0F;
        rtb_a_b_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          B = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (B >= 0.0F) && (B <= 1.0F)) {
            rtb_Saturation_l = fmaxf(D, B);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Saturation_l = D;
            guard1 = true;
          } else {
            if ((B >= 0.0F) && (B <= 1.0F)) {
              rtb_Saturation_l = B;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Saturation_l = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_a_b_idx_0 = rtb_Sign1_n_idx_0 * rtb_Saturation_l +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_a_b_idx_1 = rtb_Saturation1_i_idx_0 * rtb_Saturation_l +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S138>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        B = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
             rtb_Saturation1_i_idx_0 + (FMS_U.INS_Out.x_R -
              FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Sign1_n_idx_0) /
          (rtb_Sign1_n_idx_0 * rtb_Sign1_n_idx_0 + rtb_Saturation1_i_idx_0 *
           rtb_Saturation1_i_idx_0);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_FixPtRelationalOperator = (B <= 0.0F);
        u = (B >= 1.0F);
        if (rtb_FixPtRelationalOperator) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Sign1_n_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Sign1_n_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Sign1_n_idx_0 = B * rtb_Sign1_n_idx_0 + FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Switch: '<S138>/Switch1' incorporates:
         *  Constant: '<S171>/Constant'
         *  RelationalOperator: '<S171>/Compare'
         */
        if (rtb_Switch_e_idx_0 <= 0.0F) {
          /* Switch: '<S138>/Switch' incorporates:
           *  Constant: '<S170>/Constant'
           *  MATLAB Function: '<S138>/SearchL1RefWP'
           *  RelationalOperator: '<S170>/Compare'
           */
          if (rtb_Saturation_l >= 0.0F) {
            rtb_Subtract3_f[0] = rtb_a_b_idx_0;
            rtb_Subtract3_f[1] = rtb_a_b_idx_1;
          } else {
            rtb_Subtract3_f[0] = rtb_Sign1_n_idx_0;

            /* MATLAB Function: '<S138>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Subtract3_f[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Subtract3_f[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Subtract3_f[1] = B * rtb_Saturation1_i_idx_0 +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }
          }

          /* End of Switch: '<S138>/Switch' */
        }

        /* End of Switch: '<S138>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S139>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Sign1_n_idx_0 = rtb_Subtract3_f[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S179>/Math Function' */
        rtb_Divide_lq[0] = rtb_Sign1_n_idx_0 * rtb_Sign1_n_idx_0;
        rtb_Saturation1_i_idx_0 = rtb_Sign1_n_idx_0;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S139>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Sign1_n_idx_0 = rtb_Subtract3_f[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S179>/Math Function' incorporates:
         *  Math: '<S177>/Square'
         */
        rtb_Switch_e_idx_0 = rtb_Sign1_n_idx_0 * rtb_Sign1_n_idx_0;

        /* Sum: '<S179>/Sum of Elements' incorporates:
         *  Math: '<S179>/Math Function'
         */
        rtb_Saturation_l = rtb_Switch_e_idx_0 + rtb_Divide_lq[0];

        /* Math: '<S179>/Math Function1' incorporates:
         *  Sum: '<S179>/Sum of Elements'
         *
         * About '<S179>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_l < 0.0F) {
          B = -sqrtf(fabsf(rtb_Saturation_l));
        } else {
          B = sqrtf(rtb_Saturation_l);
        }

        /* End of Math: '<S179>/Math Function1' */

        /* Switch: '<S179>/Switch' incorporates:
         *  Constant: '<S179>/Constant'
         *  Product: '<S179>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_l[0] = rtb_Saturation1_i_idx_0;
          rtb_Switch_l[1] = rtb_Sign1_n_idx_0;
          rtb_Switch_l[2] = B;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S179>/Switch' */

        /* Product: '<S178>/Divide' */
        rtb_Divide_lq[0] = rtb_MathFunction_crm_idx_0 / rtb_Rem_k;
        rtb_Divide_lq[1] = rtb_MathFunction_crm_idx_1 / rtb_Rem_k;

        /* Sum: '<S181>/Sum of Elements' incorporates:
         *  Math: '<S181>/Math Function'
         *  SignalConversion: '<S181>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_l = rtb_Divide_lq[1] * rtb_Divide_lq[1] + rtb_Divide_lq[0]
          * rtb_Divide_lq[0];

        /* Math: '<S181>/Math Function1' incorporates:
         *  Sum: '<S181>/Sum of Elements'
         *
         * About '<S181>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_l < 0.0F) {
          B = -sqrtf(fabsf(rtb_Saturation_l));
        } else {
          B = sqrtf(rtb_Saturation_l);
        }

        /* End of Math: '<S181>/Math Function1' */

        /* Switch: '<S181>/Switch' incorporates:
         *  Constant: '<S181>/Constant'
         *  Product: '<S181>/Product'
         */
        if (B > 0.0F) {
          rtb_MathFunction_crm_idx_0 = rtb_Divide_lq[1];
          rtb_MathFunction_crm_idx_1 = rtb_Divide_lq[0];
          rtb_Rem_k = B;
        } else {
          rtb_MathFunction_crm_idx_0 = 0.0F;
          rtb_MathFunction_crm_idx_1 = 0.0F;
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S181>/Switch' */

        /* Product: '<S179>/Divide' */
        rtb_Divide_lq[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Divide_lq[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S182>/Sum of Elements' incorporates:
         *  Math: '<S182>/Math Function'
         *  SignalConversion: '<S182>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_l = rtb_Divide_lq[1] * rtb_Divide_lq[1] + rtb_Divide_lq[0]
          * rtb_Divide_lq[0];

        /* Math: '<S182>/Math Function1' incorporates:
         *  Sum: '<S182>/Sum of Elements'
         *
         * About '<S182>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_l < 0.0F) {
          B = -sqrtf(fabsf(rtb_Saturation_l));
        } else {
          B = sqrtf(rtb_Saturation_l);
        }

        /* End of Math: '<S182>/Math Function1' */

        /* Switch: '<S182>/Switch' incorporates:
         *  Constant: '<S182>/Constant'
         *  Product: '<S182>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_l[0] = rtb_Divide_lq[1];
          rtb_Switch_l[1] = rtb_Divide_lq[0];
          rtb_Switch_l[2] = B;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S182>/Switch' */

        /* Product: '<S182>/Divide' */
        rtb_Divide_lq[0] = rtb_Switch_l[0] / rtb_Switch_l[2];

        /* Product: '<S181>/Divide' */
        rtb_Subtract3_f[0] = rtb_MathFunction_crm_idx_0 / rtb_Rem_k;
        rtb_Saturation1_i_idx_0 *= rtb_Saturation1_i_idx_0;

        /* Product: '<S182>/Divide' incorporates:
         *  Math: '<S177>/Square'
         */
        rtb_Divide_lq[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Product: '<S181>/Divide' */
        rtb_Subtract3_f[1] = rtb_MathFunction_crm_idx_1 / rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S176>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S176>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S176>/Sum of Elements'
         */
        rtb_Saturation_l = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S180>/Subtract' incorporates:
         *  Product: '<S180>/Multiply'
         *  Product: '<S180>/Multiply1'
         */
        B = rtb_Divide_lq[0] * rtb_Subtract3_f[1] - rtb_Divide_lq[1] *
          rtb_Subtract3_f[0];

        /* Signum: '<S175>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S175>/Sign1' */

        /* Switch: '<S175>/Switch2' incorporates:
         *  Constant: '<S175>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S175>/Switch2' */

        /* DotProduct: '<S175>/Dot Product' */
        rtb_Rem_k = rtb_Subtract3_f[0] * rtb_Divide_lq[0] + rtb_Subtract3_f[1] *
          rtb_Divide_lq[1];

        /* Trigonometry: '<S175>/Acos' incorporates:
         *  DotProduct: '<S175>/Dot Product'
         */
        if (rtb_Rem_k > 1.0F) {
          rtb_Rem_k = 1.0F;
        } else {
          if (rtb_Rem_k < -1.0F) {
            rtb_Rem_k = -1.0F;
          }
        }

        /* Product: '<S175>/Multiply' incorporates:
         *  Trigonometry: '<S175>/Acos'
         */
        B *= acosf(rtb_Rem_k);

        /* Saturate: '<S139>/Saturation' */
        if (B > 1.57079637F) {
          B = 1.57079637F;
        } else {
          if (B < -1.57079637F) {
            B = -1.57079637F;
          }
        }

        /* End of Saturate: '<S139>/Saturation' */

        /* Product: '<S139>/Divide' incorporates:
         *  Constant: '<S116>/L1'
         *  Constant: '<S139>/Constant'
         *  Gain: '<S139>/Gain'
         *  Math: '<S139>/Square'
         *  MinMax: '<S139>/Max'
         *  MinMax: '<S139>/Min'
         *  Product: '<S139>/Multiply1'
         *  Sqrt: '<S176>/Sqrt'
         *  Sqrt: '<S177>/Sqrt'
         *  Sum: '<S177>/Sum of Elements'
         *  Trigonometry: '<S139>/Sin'
         */
        rtb_Rem_k = arm_sin_f32(B) * (rtb_Saturation_l * rtb_Saturation_l * 2.0F)
          / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Switch_e_idx_0 +
                    rtb_Saturation1_i_idx_0), 0.5F));

        /* Sum: '<S120>/Sum2' incorporates:
         *  Delay: '<S120>/Delay'
         */
        rtb_a_pr -= FMS_DW.Delay_DSTATE_h;

        /* Math: '<S124>/Rem' incorporates:
         *  Constant: '<S124>/Constant1'
         */
        rtb_Switch_e_idx_0 = rt_remf(rtb_a_pr, 6.28318548F);

        /* Switch: '<S124>/Switch' incorporates:
         *  Abs: '<S124>/Abs'
         *  Constant: '<S124>/Constant'
         *  Constant: '<S130>/Constant'
         *  Product: '<S124>/Multiply'
         *  RelationalOperator: '<S130>/Compare'
         *  Sum: '<S124>/Add'
         */
        if (fabsf(rtb_Switch_e_idx_0) > 3.14159274F) {
          /* Signum: '<S124>/Sign' */
          if (rtb_Switch_e_idx_0 < 0.0F) {
            rtb_a_pr = -1.0F;
          } else if (rtb_Switch_e_idx_0 > 0.0F) {
            rtb_a_pr = 1.0F;
          } else {
            rtb_a_pr = rtb_Switch_e_idx_0;
          }

          /* End of Signum: '<S124>/Sign' */
          rtb_Switch_e_idx_0 -= 6.28318548F * rtb_a_pr;
        }

        /* End of Switch: '<S124>/Switch' */

        /* Sum: '<S120>/Sum' incorporates:
         *  Delay: '<S120>/Delay'
         */
        rtb_a_pr = rtb_Switch_e_idx_0 + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S129>/Multiply1' incorporates:
         *  Constant: '<S129>/const1'
         *  DiscreteIntegrator: '<S123>/Integrator'
         */
        rtb_Switch_e_idx_0 = FMS_DW.Integrator_DSTATE * 0.785398185F;

        /* Sum: '<S129>/Add' incorporates:
         *  DiscreteIntegrator: '<S123>/Integrator1'
         *  Sum: '<S123>/Subtract'
         */
        B = (FMS_DW.Integrator1_DSTATE - rtb_a_pr) + rtb_Switch_e_idx_0;

        /* Signum: '<S129>/Sign' */
        if (B < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else if (B > 0.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          rtb_Saturation_l = B;
        }

        /* End of Signum: '<S129>/Sign' */

        /* Sum: '<S129>/Add2' incorporates:
         *  Abs: '<S129>/Abs'
         *  Gain: '<S129>/Gain'
         *  Gain: '<S129>/Gain1'
         *  Product: '<S129>/Multiply2'
         *  Product: '<S129>/Multiply3'
         *  Sqrt: '<S129>/Sqrt'
         *  Sum: '<S129>/Add1'
         *  Sum: '<S129>/Subtract'
         */
        rtb_a_pr = (sqrtf((8.0F * fabsf(B) + FMS_ConstB.d) * FMS_ConstB.d) -
                    FMS_ConstB.d) * 0.5F * rtb_Saturation_l + rtb_Switch_e_idx_0;

        /* Sum: '<S129>/Add4' */
        rtb_Switch_e_idx_0 += B - rtb_a_pr;

        /* Sum: '<S129>/Add3' */
        rtb_Saturation_l = B + FMS_ConstB.d;

        /* Sum: '<S129>/Subtract1' */
        B -= FMS_ConstB.d;

        /* Signum: '<S129>/Sign1' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S129>/Sign1' */

        /* Signum: '<S129>/Sign2' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S129>/Sign2' */

        /* Sum: '<S129>/Add5' incorporates:
         *  Gain: '<S129>/Gain2'
         *  Product: '<S129>/Multiply4'
         *  Sum: '<S129>/Subtract2'
         */
        rtb_a_pr += (rtb_Saturation_l - B) * 0.5F * rtb_Switch_e_idx_0;

        /* Update for Delay: '<S140>/Delay' */
        FMS_DW.icLoad_i = 0U;

        /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' incorporates:
         *  Product: '<S140>/Divide1'
         */
        FMS_DW.l1_heading += rtb_Rem_k / rtb_Sqrt_d * 0.004F;

        /* Update for Delay: '<S120>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S123>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S123>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Sum: '<S129>/Subtract3' */
        rtb_Saturation_l = rtb_a_pr - FMS_ConstB.d;

        /* Sum: '<S129>/Add6' */
        B = rtb_a_pr + FMS_ConstB.d;

        /* Signum: '<S129>/Sign5' incorporates:
         *  Signum: '<S129>/Sign6'
         */
        if (rtb_a_pr < 0.0F) {
          rtb_Sqrt_d = -1.0F;

          /* Signum: '<S129>/Sign6' */
          rtb_Rem_k = -1.0F;
        } else if (rtb_a_pr > 0.0F) {
          rtb_Sqrt_d = 1.0F;

          /* Signum: '<S129>/Sign6' */
          rtb_Rem_k = 1.0F;
        } else {
          rtb_Sqrt_d = rtb_a_pr;

          /* Signum: '<S129>/Sign6' */
          rtb_Rem_k = rtb_a_pr;
        }

        /* End of Signum: '<S129>/Sign5' */

        /* Signum: '<S129>/Sign3' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S129>/Sign3' */

        /* Signum: '<S129>/Sign4' */
        if (rtb_Saturation_l < 0.0F) {
          rtb_Saturation_l = -1.0F;
        } else {
          if (rtb_Saturation_l > 0.0F) {
            rtb_Saturation_l = 1.0F;
          }
        }

        /* End of Signum: '<S129>/Sign4' */

        /* Update for DiscreteIntegrator: '<S123>/Integrator' incorporates:
         *  Constant: '<S129>/const'
         *  Gain: '<S129>/Gain3'
         *  Product: '<S129>/Divide'
         *  Product: '<S129>/Multiply5'
         *  Product: '<S129>/Multiply6'
         *  Sum: '<S129>/Subtract4'
         *  Sum: '<S129>/Subtract5'
         *  Sum: '<S129>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_a_pr / FMS_ConstB.d - rtb_Sqrt_d) *
          FMS_ConstB.Gain4 * ((B - rtb_Saturation_l) * 0.5F) - rtb_Rem_k *
          1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S123>/Integrator' */
        /* End of Outputs for SubSystem: '<S112>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Update for UnitDelay: '<S115>/Delay Input1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S115>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S22>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
         *  ActionPort: '<S114>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

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
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S37>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S72>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S58>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S21>/Acro' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S26>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S31>/Gain'
         *  Gain: '<S31>/Gain1'
         *  Gain: '<S31>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S32>/Saturation' incorporates:
         *  Constant: '<S32>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         *  Sum: '<S32>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Switch_e_idx_0 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Switch_e_idx_0 = 0.0F;
        } else {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S32>/Saturation' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S32>/Constant5'
         *  Gain: '<S32>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S32>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F *
          rtb_Switch_e_idx_0), 4.2949673E+9F) + 1000U;

        /* End of Outputs for SubSystem: '<S21>/Acro' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S21>/Stabilize' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S29>/Bus Assignment'
         *  Constant: '<S29>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S103>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Switch_e_idx_0 = 0.0F;
        } else {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S103>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S100>/Gain'
         *  Gain: '<S103>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.phi_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Switch_e_idx_0 * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S104>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Switch_e_idx_0 = 0.0F;
        } else {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S104>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S100>/Gain1'
         *  Gain: '<S104>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.theta_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_Switch_e_idx_0 * -FMS_PARAM.PITCH_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S109>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Switch_e_idx_0 = 0.0F;
        } else {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S109>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S101>/Gain1'
         *  Gain: '<S109>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Switch_e_idx_0 * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Saturate: '<S102>/Saturation' incorporates:
         *  Constant: '<S102>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         *  Sum: '<S102>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Switch_e_idx_0 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Switch_e_idx_0 = 0.0F;
        } else {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S102>/Saturation' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S102>/Constant5'
         *  Gain: '<S102>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S102>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F *
          rtb_Switch_e_idx_0), 4.2949673E+9F) + 1000U;

        /* End of Outputs for SubSystem: '<S21>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Altitude' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S38>/Motion Status'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);

          /* End of SystemReset for SubSystem: '<S21>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Altitude' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S38>/Motion Status' incorporates:
         *  Abs: '<S38>/Abs'
         *  Abs: '<S38>/Abs1'
         *  Constant: '<S46>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S46>/Compare'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S37>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
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
          /* Outputs for IfAction SubSystem: '<S37>/Move Control' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S37>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S37>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S27>/Bus Assignment'
         *  Constant: '<S27>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S48>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Switch_e_idx_0 = 0.0F;
        } else {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S48>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S35>/Gain'
         *  Gain: '<S48>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.phi_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Switch_e_idx_0 * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S51>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Switch_e_idx_0 = 0.0F;
        } else {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S51>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S36>/Gain1'
         *  Gain: '<S51>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Switch_e_idx_0 * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S33>/Gain1' incorporates:
         *  Bias: '<S33>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Sqrt_d = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S33>/Saturation' incorporates:
         *  Gain: '<S33>/Gain1'
         */
        if (rtb_Sqrt_d > 1.0F) {
          rtb_Sqrt_d = 1.0F;
        } else {
          if (rtb_Sqrt_d < 0.0F) {
            rtb_Sqrt_d = 0.0F;
          }
        }

        /* End of Saturate: '<S33>/Saturation' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S33>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Sqrt_d;

        /* Saturate: '<S37>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S37>/Saturation1' */
        /* End of Outputs for SubSystem: '<S21>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Position' incorporates:
           *  ActionPort: '<S28>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S59>/Motion Status'
           *  Chart: '<S73>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_jn);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_d;

          /* End of SystemReset for SubSystem: '<S21>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Position' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S99>/Trigonometric Function1' incorporates:
         *  Gain: '<S98>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S99>/Trigonometric Function' incorporates:
         *  Gain: '<S98>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S99>/Constant3'
         */
        rtb_VectorConcatenate_hm[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S99>/Gain' incorporates:
         *  Gain: '<S98>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S99>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_hm[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S99>/Trigonometric Function3' incorporates:
         *  Gain: '<S98>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S99>/Constant4'
         */
        rtb_VectorConcatenate_hm[5] = 0.0F;

        /* SignalConversion: '<S99>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3[0];
        rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3[1];
        rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S59>/Motion Status' incorporates:
         *  Abs: '<S59>/Abs'
         *  Abs: '<S59>/Abs1'
         *  Constant: '<S67>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S67>/Compare'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_jn);

        /* RelationalOperator: '<S96>/Compare' incorporates:
         *  Abs: '<S73>/Abs1'
         *  Constant: '<S96>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_FixPtRelationalOperator = (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Chart: '<S73>/Motion State' incorporates:
         *  Abs: '<S73>/Abs'
         */
        if (FMS_DW.temporalCounter_i1_i < 1023U) {
          FMS_DW.temporalCounter_i1_i++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move_c;
          rtb_state = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake_b:
            rtb_state = MotionState_Brake;

            /* Product: '<S73>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S16>/Signal Copy1'
             */
            for (i = 0; i < 3; i++) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_hm[i + 6] *
                FMS_U.INS_Out.vd + (rtb_VectorConcatenate_hm[i + 3] *
                                    FMS_U.INS_Out.ve +
                                    rtb_VectorConcatenate_hm[i] *
                                    FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }

            /* End of Product: '<S73>/Multiply' */
            if ((fabsf(rtb_VectorConcatenate_a[1]) <= 0.2) ||
                (FMS_DW.temporalCounter_i1_i >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_m;
              rtb_state = MotionState_Hold;
            } else {
              if (rtb_FixPtRelationalOperator) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_c;
                rtb_state = MotionState_Move;
              }
            }
            break;

           case FMS_IN_Hold_m:
            rtb_state = MotionState_Hold;
            if (rtb_FixPtRelationalOperator) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_c;
              rtb_state = MotionState_Move;
            }
            break;

           default:
            rtb_state = MotionState_Move;
            if (!rtb_FixPtRelationalOperator) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_b;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S73>/Motion State' */

        /* SwitchCase: '<S72>/Switch Case' incorporates:
         *  Math: '<S86>/Square'
         *  Product: '<S92>/Divide'
         *  Sum: '<S78>/Subtract'
         *  Switch: '<S77>/Switch'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state) {
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
            /* InitializeConditions for IfAction SubSystem: '<S72>/Hold Control' incorporates:
             *  ActionPort: '<S75>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S72>/Switch Case' incorporates:
             *  Delay: '<S79>/start_vel'
             *  Delay: '<S79>/start_wp'
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.icLoad_c = 1U;

            /* End of InitializeConditions for SubSystem: '<S72>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S72>/Hold Control' incorporates:
           *  ActionPort: '<S75>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S87>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S87>/Math Function'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Switch_e_idx_0 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S87>/Math Function1' incorporates:
           *  Sum: '<S87>/Sum of Elements'
           *
           * About '<S87>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch_e_idx_0 < 0.0F) {
            rtb_Sqrt_d = -sqrtf(fabsf(rtb_Switch_e_idx_0));
          } else {
            rtb_Sqrt_d = sqrtf(rtb_Switch_e_idx_0);
          }

          /* End of Math: '<S87>/Math Function1' */

          /* Switch: '<S87>/Switch' incorporates:
           *  Constant: '<S87>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S87>/Product'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (rtb_Sqrt_d > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_l[0] = FMS_U.INS_Out.vn;
            rtb_Switch_l[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_l[2] = rtb_Sqrt_d;
          } else {
            rtb_Switch_l[0] = 0.0F;
            rtb_Switch_l[1] = 0.0F;
            rtb_Switch_l[2] = 1.0F;
          }

          /* End of Switch: '<S87>/Switch' */

          /* Delay: '<S79>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Sum: '<S92>/Sum of Elements' incorporates:
           *  Delay: '<S79>/start_vel'
           *  Math: '<S92>/Math Function'
           */
          rtb_Switch_e_idx_0 = FMS_DW.start_vel_DSTATE[0] *
            FMS_DW.start_vel_DSTATE[0] + FMS_DW.start_vel_DSTATE[1] *
            FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S92>/Math Function1' incorporates:
           *  Sum: '<S92>/Sum of Elements'
           *
           * About '<S92>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch_e_idx_0 < 0.0F) {
            rtb_Sqrt_d = -sqrtf(fabsf(rtb_Switch_e_idx_0));
          } else {
            rtb_Sqrt_d = sqrtf(rtb_Switch_e_idx_0);
          }

          /* End of Math: '<S92>/Math Function1' */

          /* Switch: '<S92>/Switch' incorporates:
           *  Constant: '<S92>/Constant'
           *  Delay: '<S79>/start_vel'
           *  Product: '<S92>/Product'
           */
          if (rtb_Sqrt_d > 0.0F) {
            rtb_MathFunction_crm_idx_0 = FMS_DW.start_vel_DSTATE[0];
            rtb_MathFunction_crm_idx_1 = FMS_DW.start_vel_DSTATE[1];
            rtb_Rem_k = rtb_Sqrt_d;
          } else {
            rtb_MathFunction_crm_idx_0 = 0.0F;
            rtb_MathFunction_crm_idx_1 = 0.0F;
            rtb_Rem_k = 1.0F;
          }

          /* End of Switch: '<S92>/Switch' */

          /* Product: '<S87>/Divide' */
          rtb_Divide_gz[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
          rtb_Divide_gz[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

          /* Sum: '<S90>/Sum of Elements' incorporates:
           *  Math: '<S90>/Math Function'
           *  SignalConversion: '<S90>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Switch_e_idx_0 = rtb_Divide_gz[1] * rtb_Divide_gz[1] +
            rtb_Divide_gz[0] * rtb_Divide_gz[0];

          /* Math: '<S90>/Math Function1' incorporates:
           *  Sum: '<S90>/Sum of Elements'
           *
           * About '<S90>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Switch_e_idx_0 < 0.0F) {
            rtb_Sqrt_d = -sqrtf(fabsf(rtb_Switch_e_idx_0));
          } else {
            rtb_Sqrt_d = sqrtf(rtb_Switch_e_idx_0);
          }

          /* End of Math: '<S90>/Math Function1' */

          /* Switch: '<S90>/Switch' incorporates:
           *  Constant: '<S90>/Constant'
           *  Product: '<S90>/Product'
           */
          if (rtb_Sqrt_d > 0.0F) {
            rtb_Switch_l[0] = rtb_Divide_gz[1];
            rtb_Switch_l[1] = rtb_Divide_gz[0];
            rtb_Switch_l[2] = rtb_Sqrt_d;
          } else {
            rtb_Switch_l[0] = 0.0F;
            rtb_Switch_l[1] = 0.0F;
            rtb_Switch_l[2] = 1.0F;
          }

          /* End of Switch: '<S90>/Switch' */

          /* Delay: '<S79>/start_wp' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S77>/SearchL1RefWP' incorporates:
           *  Delay: '<S79>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Divide_gz[0] = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_gz[1] = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S92>/Divide' */
          rtb_Sqrt_d = rtb_MathFunction_crm_idx_0 / rtb_Rem_k;

          /* MATLAB Function: '<S77>/SearchL1RefWP' */
          rtb_a_pr = rtb_Sqrt_d * rtb_Divide_gz[0];
          rtb_Sign1_n_idx_0 = rtb_Sqrt_d;

          /* Product: '<S92>/Divide' */
          rtb_Sqrt_d = rtb_MathFunction_crm_idx_1 / rtb_Rem_k;

          /* MATLAB Function: '<S77>/SearchL1RefWP' incorporates:
           *  Constant: '<S75>/L1'
           *  Delay: '<S79>/start_wp'
           */
          rtb_a_pr += rtb_Sqrt_d * rtb_Divide_gz[1];
          B = 2.0F * rtb_a_pr;
          rtb_Subtract3_f[0] = 0.0F;
          rtb_Subtract3_f[1] = 0.0F;
          D = B * B - ((rtb_Divide_gz[0] * rtb_Divide_gz[0] + rtb_Divide_gz[1] *
                        rtb_Divide_gz[1]) - FMS_PARAM.L1 * FMS_PARAM.L1) * 4.0F;
          rtb_a_pr = -1.0F;
          if (D > 0.0F) {
            rtb_a_pr = sqrtf(D);
            rtb_a_pr = fmaxf((-B + rtb_a_pr) / 2.0F, (-B - rtb_a_pr) / 2.0F);
            rtb_Subtract3_f[0] = rtb_a_pr * rtb_Sign1_n_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
            rtb_Subtract3_f[1] = rtb_a_pr * rtb_Sqrt_d + FMS_DW.start_wp_DSTATE
              [1];
          } else {
            if (D == 0.0F) {
              rtb_a_pr = -B / 2.0F;
              rtb_Subtract3_f[0] = rtb_a_pr * rtb_Sign1_n_idx_0 +
                FMS_DW.start_wp_DSTATE[0];
              rtb_Subtract3_f[1] = rtb_a_pr * rtb_Sqrt_d +
                FMS_DW.start_wp_DSTATE[1];
            }
          }

          /* RelationalOperator: '<S80>/Compare' incorporates:
           *  Constant: '<S80>/Constant'
           *  MATLAB Function: '<S77>/SearchL1RefWP'
           */
          rtb_FixPtRelationalOperator = (rtb_a_pr > 0.0F);

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S77>/OutRegionRefWP' incorporates:
           *  Delay: '<S79>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_a_pr = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
            rtb_Sign1_n_idx_0 + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1]) *
            rtb_Sqrt_d;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Saturation_l = 1.29246971E-26F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Rem_k = fabsf((rtb_a_pr * rtb_Sign1_n_idx_0 +
                             FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Rem_k > 1.29246971E-26F) {
            rtb_Saturation1_i_idx_0 = 1.0F;
            rtb_Saturation_l = rtb_Rem_k;
          } else {
            rtb_Switch_e_idx_0 = rtb_Rem_k / 1.29246971E-26F;
            rtb_Saturation1_i_idx_0 = rtb_Switch_e_idx_0 * rtb_Switch_e_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Rem_k = fabsf((rtb_a_pr * rtb_Sqrt_d + FMS_DW.start_wp_DSTATE[1])
                            - FMS_U.INS_Out.y_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Rem_k > rtb_Saturation_l) {
            rtb_Switch_e_idx_0 = rtb_Saturation_l / rtb_Rem_k;
            rtb_Saturation1_i_idx_0 = rtb_Saturation1_i_idx_0 *
              rtb_Switch_e_idx_0 * rtb_Switch_e_idx_0 + 1.0F;
            rtb_Saturation_l = rtb_Rem_k;
          } else {
            rtb_Switch_e_idx_0 = rtb_Rem_k / rtb_Saturation_l;
            rtb_Saturation1_i_idx_0 += rtb_Switch_e_idx_0 * rtb_Switch_e_idx_0;
          }

          rtb_Saturation1_i_idx_0 = rtb_Saturation_l * sqrtf
            (rtb_Saturation1_i_idx_0);
          rtb_a_pr += rtb_Saturation1_i_idx_0 * 0.577350259F;

          /* Switch: '<S77>/Switch' incorporates:
           *  Delay: '<S79>/start_wp'
           *  MATLAB Function: '<S77>/OutRegionRefWP'
           */
          if (rtb_FixPtRelationalOperator) {
            rtb_Saturation_l = rtb_Subtract3_f[0];
          } else {
            rtb_Saturation_l = rtb_a_pr * rtb_Sign1_n_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S78>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_MathFunction_crm_idx_1 = rtb_Saturation_l - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S88>/Math Function' */
          rtb_Divide_gz[0] = rtb_MathFunction_crm_idx_1 *
            rtb_MathFunction_crm_idx_1;
          rtb_Subtract3_f[0] = rtb_MathFunction_crm_idx_1;

          /* Switch: '<S77>/Switch' incorporates:
           *  Delay: '<S79>/start_wp'
           *  MATLAB Function: '<S77>/OutRegionRefWP'
           *  Sum: '<S78>/Subtract'
           */
          if (rtb_FixPtRelationalOperator) {
            rtb_Saturation_l = rtb_Subtract3_f[1];
          } else {
            rtb_Saturation_l = rtb_a_pr * rtb_Sqrt_d + FMS_DW.start_wp_DSTATE[1];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S78>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_MathFunction_crm_idx_1 = rtb_Saturation_l - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S88>/Math Function' incorporates:
           *  Math: '<S86>/Square'
           */
          rtb_Switch_e_idx_0 = rtb_MathFunction_crm_idx_1 *
            rtb_MathFunction_crm_idx_1;

          /* Sum: '<S88>/Sum of Elements' incorporates:
           *  Math: '<S88>/Math Function'
           */
          rtb_Saturation_l = rtb_Switch_e_idx_0 + rtb_Divide_gz[0];

          /* Math: '<S88>/Math Function1' incorporates:
           *  Sum: '<S88>/Sum of Elements'
           *
           * About '<S88>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Sqrt_d = -sqrtf(fabsf(rtb_Saturation_l));
          } else {
            rtb_Sqrt_d = sqrtf(rtb_Saturation_l);
          }

          /* End of Math: '<S88>/Math Function1' */

          /* Switch: '<S88>/Switch' incorporates:
           *  Constant: '<S88>/Constant'
           *  Product: '<S88>/Product'
           */
          if (rtb_Sqrt_d > 0.0F) {
            rtb_MathFunction_crm_idx_0 = rtb_Subtract3_f[0];
            rtb_Rem_k = rtb_Sqrt_d;
          } else {
            rtb_MathFunction_crm_idx_0 = 0.0F;
            rtb_MathFunction_crm_idx_1 = 0.0F;
            rtb_Rem_k = 1.0F;
          }

          /* End of Switch: '<S88>/Switch' */

          /* Product: '<S88>/Divide' */
          rtb_Divide_gz[0] = rtb_MathFunction_crm_idx_0 / rtb_Rem_k;
          rtb_Divide_gz[1] = rtb_MathFunction_crm_idx_1 / rtb_Rem_k;

          /* Sum: '<S91>/Sum of Elements' incorporates:
           *  Math: '<S91>/Math Function'
           *  SignalConversion: '<S91>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_l = rtb_Divide_gz[1] * rtb_Divide_gz[1] +
            rtb_Divide_gz[0] * rtb_Divide_gz[0];

          /* Math: '<S91>/Math Function1' incorporates:
           *  Sum: '<S91>/Sum of Elements'
           *
           * About '<S91>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Sqrt_d = -sqrtf(fabsf(rtb_Saturation_l));
          } else {
            rtb_Sqrt_d = sqrtf(rtb_Saturation_l);
          }

          /* End of Math: '<S91>/Math Function1' */

          /* Switch: '<S91>/Switch' incorporates:
           *  Constant: '<S91>/Constant'
           *  Product: '<S91>/Product'
           */
          if (rtb_Sqrt_d > 0.0F) {
            rtb_MathFunction_crm_idx_0 = rtb_Divide_gz[1];
            rtb_MathFunction_crm_idx_1 = rtb_Divide_gz[0];
            rtb_Rem_k = rtb_Sqrt_d;
          } else {
            rtb_MathFunction_crm_idx_0 = 0.0F;
            rtb_MathFunction_crm_idx_1 = 0.0F;
            rtb_Rem_k = 1.0F;
          }

          /* End of Switch: '<S91>/Switch' */

          /* Product: '<S91>/Divide' */
          rtb_Divide_gz[0] = rtb_MathFunction_crm_idx_0 / rtb_Rem_k;

          /* Product: '<S90>/Divide' */
          rtb_Divide_lq[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
          rtb_Subtract3_f[0] *= rtb_Subtract3_f[0];

          /* Product: '<S91>/Divide' incorporates:
           *  Math: '<S86>/Square'
           */
          rtb_Divide_gz[1] = rtb_MathFunction_crm_idx_1 / rtb_Rem_k;

          /* Product: '<S90>/Divide' */
          rtb_Divide_lq[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sqrt: '<S85>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S85>/Square'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S85>/Sum of Elements'
           */
          rtb_a_pr = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                           FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Sum: '<S89>/Subtract' incorporates:
           *  Product: '<S89>/Multiply'
           *  Product: '<S89>/Multiply1'
           */
          rtb_Sqrt_d = rtb_Divide_gz[0] * rtb_Divide_lq[1] - rtb_Divide_gz[1] *
            rtb_Divide_lq[0];

          /* Signum: '<S84>/Sign1' */
          if (rtb_Sqrt_d < 0.0F) {
            rtb_Sqrt_d = -1.0F;
          } else {
            if (rtb_Sqrt_d > 0.0F) {
              rtb_Sqrt_d = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign1' */

          /* Switch: '<S84>/Switch2' incorporates:
           *  Constant: '<S84>/Constant4'
           */
          if (rtb_Sqrt_d == 0.0F) {
            rtb_Sqrt_d = 1.0F;
          }

          /* End of Switch: '<S84>/Switch2' */

          /* DotProduct: '<S84>/Dot Product' */
          rtb_Saturation_l = rtb_Divide_lq[0] * rtb_Divide_gz[0] +
            rtb_Divide_lq[1] * rtb_Divide_gz[1];

          /* Trigonometry: '<S84>/Acos' incorporates:
           *  DotProduct: '<S84>/Dot Product'
           */
          if (rtb_Saturation_l > 1.0F) {
            rtb_Saturation_l = 1.0F;
          } else {
            if (rtb_Saturation_l < -1.0F) {
              rtb_Saturation_l = -1.0F;
            }
          }

          /* Product: '<S84>/Multiply' incorporates:
           *  Trigonometry: '<S84>/Acos'
           */
          rtb_Sqrt_d *= acosf(rtb_Saturation_l);

          /* Saturate: '<S83>/Saturation' */
          if (rtb_Sqrt_d > 1.57079637F) {
            rtb_Sqrt_d = 1.57079637F;
          } else {
            if (rtb_Sqrt_d < -1.57079637F) {
              rtb_Sqrt_d = -1.57079637F;
            }
          }

          /* End of Saturate: '<S83>/Saturation' */

          /* Product: '<S83>/Divide' incorporates:
           *  Constant: '<S75>/L1'
           *  Constant: '<S83>/Constant'
           *  Gain: '<S83>/Gain'
           *  Math: '<S83>/Square'
           *  MinMax: '<S83>/Max'
           *  MinMax: '<S83>/Min'
           *  Product: '<S83>/Multiply1'
           *  Sqrt: '<S85>/Sqrt'
           *  Sqrt: '<S86>/Sqrt'
           *  Sum: '<S86>/Sum of Elements'
           *  Trigonometry: '<S83>/Sin'
           */
          FMS_B.Merge_p = arm_sin_f32(rtb_Sqrt_d) * (rtb_a_pr * rtb_a_pr * 2.0F)
            / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Switch_e_idx_0 +
                      rtb_Subtract3_f[0]), 0.5F));

          /* Update for Delay: '<S79>/start_vel' */
          FMS_DW.icLoad = 0U;

          /* Update for Delay: '<S79>/start_wp' */
          FMS_DW.icLoad_c = 0U;

          /* End of Outputs for SubSystem: '<S72>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S72>/Brake Control' incorporates:
           *  ActionPort: '<S74>/Action Port'
           */
          /* SignalConversion: '<S74>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
           *  Constant: '<S74>/Brake Speed'
           */
          FMS_B.Merge_p = 0.0F;

          /* End of Outputs for SubSystem: '<S72>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S72>/Move Control' incorporates:
           *  ActionPort: '<S76>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S93>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Switch_e_idx_0 = 0.0F;
          } else {
            rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_roll -
              (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S93>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S76>/Gain6' incorporates:
           *  Gain: '<S93>/Gain'
           */
          FMS_B.Merge_p = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Switch_e_idx_0
            * FMS_PARAM.ACC_Y_LIM;

          /* End of Outputs for SubSystem: '<S72>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S72>/Switch Case' */

        /* SwitchCase: '<S58>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ba;
        FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
        switch (rtb_state_a) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_ba = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_ba = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_ba = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_ba) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ba != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S58>/Hold Control' incorporates:
             *  ActionPort: '<S61>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S58>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_l);

            /* End of SystemReset for SubSystem: '<S58>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S58>/Hold Control' incorporates:
           *  ActionPort: '<S61>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge, &FMS_DW.HoldControl_l);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S58>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S58>/Brake Control' incorporates:
           *  ActionPort: '<S60>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S58>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S58>/Move Control' incorporates:
           *  ActionPort: '<S62>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S58>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S58>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S28>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S69>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Switch_e_idx_0 = 0.0F;
        } else {
          rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S69>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S56>/Gain1'
         *  Gain: '<S69>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Switch_e_idx_0 * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S54>/Gain1' incorporates:
         *  Bias: '<S54>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Saturation_l = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S54>/Saturation' incorporates:
         *  Gain: '<S54>/Gain1'
         */
        if (rtb_Saturation_l > 1.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = 0.0F;
          }
        }

        /* End of Saturate: '<S54>/Saturation' */

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S54>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Saturation_l;

        /* Saturate: '<S72>/Saturation1' */
        if (FMS_B.Merge_p > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (FMS_B.Merge_p < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_p;
        }

        /* End of Saturate: '<S72>/Saturation1' */

        /* Saturate: '<S58>/Saturation1' */
        if (FMS_B.Merge > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge;
        }

        /* End of Saturate: '<S58>/Saturation1' */
        /* End of Outputs for SubSystem: '<S21>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S21>/Unknown' incorporates:
         *  ActionPort: '<S30>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

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
      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* Saturate: '<S189>/Saturation' incorporates:
       *  Constant: '<S189>/Constant4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       *  Sum: '<S189>/Sum'
       */
      if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
        rtb_Switch_e_idx_0 = 2.0F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
        rtb_Switch_e_idx_0 = 0.0F;
      } else {
        rtb_Switch_e_idx_0 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
      }

      /* End of Saturate: '<S189>/Saturation' */
      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* DataTypeConversion: '<S188>/Data Type Conversion' incorporates:
       *  Constant: '<S189>/Constant5'
       *  Gain: '<S189>/Gain4'
       *  Sum: '<S189>/Add'
       */
      rtb_DataTypeConversion = (uint16_T)fmodf(floorf(500.0F *
        rtb_Switch_e_idx_0 + 1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S188>/Data Type Conversion1' incorporates:
       *  Bias: '<S188>/Bias1'
       *  Gain: '<S188>/Gain1'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_Switch_e_idx_0 = fmodf(floorf(-500.0F * FMS_U.Pilot_Cmd.stick_roll +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      rtb_DataTypeConversion1_l = (uint16_T)(rtb_Switch_e_idx_0 < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_e_idx_0 : (int32_T)
        (uint16_T)rtb_Switch_e_idx_0);

      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  BusAssignment: '<S23>/Bus Assignment'
       *  Constant: '<S23>/Constant'
       *  SignalConversion: '<S23>/TmpHiddenBufferAtBus AssignmentInport1'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  Constant: '<S23>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;
      FMS_Y.FMS_Out.actuator_cmd[0] = rtb_DataTypeConversion;
      FMS_Y.FMS_Out.actuator_cmd[1] = rtb_DataTypeConversion;
      FMS_Y.FMS_Out.actuator_cmd[2] = rtb_DataTypeConversion1_l;
      FMS_Y.FMS_Out.actuator_cmd[3] = rtb_DataTypeConversion1_l;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S188>/Data Type Conversion2' incorporates:
       *  Bias: '<S188>/Bias2'
       *  Gain: '<S188>/Gain2'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_Switch_e_idx_0 = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_pitch +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  DataTypeConversion: '<S188>/Data Type Conversion2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[4] = (uint16_T)(rtb_Switch_e_idx_0 < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_e_idx_0 : (int32_T)
        (uint16_T)rtb_Switch_e_idx_0);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S188>/Data Type Conversion3' incorporates:
       *  Bias: '<S188>/Bias3'
       *  Gain: '<S188>/Gain3'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_Switch_e_idx_0 = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_yaw +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  DataTypeConversion: '<S188>/Data Type Conversion3'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[5] = (uint16_T)(rtb_Switch_e_idx_0 < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Switch_e_idx_0 : (int32_T)
        (uint16_T)rtb_Switch_e_idx_0);
      for (i = 0; i < 10; i++) {
        FMS_Y.FMS_Out.actuator_cmd[i + 6] = 0U;
      }

      /* End of Outputs for SubSystem: '<S17>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S17>/Unknown' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S17>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S17>/Switch Case' */
    /* End of Outputs for SubSystem: '<S15>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S15>/Switch Case' */

  /* BusAssignment: '<S18>/Bus Assignment' incorporates:
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   *  DiscreteIntegrator: '<S313>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S18>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

  /* Update for DiscreteIntegrator: '<S313>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S313>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */
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
  /* Start for SwitchCase: '<S15>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S15>/Arm' */
  /* Start for SwitchCase: '<S17>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S17>/SubMode' */
  /* Start for SwitchCase: '<S24>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S24>/Return' */
  /* Start for SwitchCase: '<S274>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S264>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S24>/Return' */

  /* Start for IfAction SubSystem: '<S24>/Hold' */
  /* Start for SwitchCase: '<S198>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S208>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S24>/Hold' */
  /* End of Start for SubSystem: '<S17>/SubMode' */

  /* Start for IfAction SubSystem: '<S17>/Auto' */
  /* Start for SwitchCase: '<S22>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S17>/Auto' */

  /* Start for IfAction SubSystem: '<S17>/Assist' */
  /* Start for SwitchCase: '<S21>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S21>/Altitude' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* End of Start for SubSystem: '<S21>/Altitude' */

  /* Start for IfAction SubSystem: '<S21>/Position' */
  /* Start for SwitchCase: '<S72>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S58>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;

  /* End of Start for SubSystem: '<S21>/Position' */
  /* End of Start for SubSystem: '<S17>/Assist' */
  /* End of Start for SubSystem: '<S15>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_d;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD_d;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD_d;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_d;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_d;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_d;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_d;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_d;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_d;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_d;
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
  /* SystemInitialize for IfAction SubSystem: '<S15>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S17>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S24>/Return' */
  /* InitializeConditions for Delay: '<S260>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S301>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_p = 0.0F;

  /* InitializeConditions for Delay: '<S240>/Delay' */
  FMS_DW.icLoad_cg = 1U;

  /* InitializeConditions for Delay: '<S241>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S244>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S244>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S275>/Motion State' */
  FMS_DW.temporalCounter_i1_j = 0U;
  FMS_DW.is_active_c2_FMS = 0U;
  FMS_DW.is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;

  /* SystemInitialize for IfAction SubSystem: '<S274>/Hold Control' */
  /* InitializeConditions for Delay: '<S277>/Delay' */
  FMS_DW.icLoad_if = 1U;

  /* End of SystemInitialize for SubSystem: '<S274>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S274>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S284>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_p[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S284>/Integrator' */
  FMS_DW.Integrator_DSTATE_p[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S274>/Move Control' */

  /* SystemInitialize for Merge: '<S274>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S274>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S284>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_p[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S284>/Integrator' */
  FMS_DW.Integrator_DSTATE_p[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S274>/Move Control' */

  /* SystemInitialize for Merge: '<S274>/Merge' */
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S265>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S264>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S264>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S264>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S264>/Move Control' */

  /* SystemInitialize for Merge: '<S264>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S24>/Hold' */
  /* SystemInitialize for Chart: '<S199>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for IfAction SubSystem: '<S198>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S198>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S198>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S198>/Move Control' */

  /* SystemInitialize for Chart: '<S209>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_d;

  /* SystemInitialize for IfAction SubSystem: '<S208>/Hold Control' */
  /* InitializeConditions for Delay: '<S211>/Delay' */
  FMS_DW.icLoad_g = 1U;

  /* End of SystemInitialize for SubSystem: '<S208>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S208>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_k = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S208>/Move Control' */

  /* SystemInitialize for Merge: '<S198>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* SystemInitialize for Merge: '<S208>/Merge' */
  FMS_B.Merge_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S17>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Mission' */
  /* InitializeConditions for UnitDelay: '<S115>/Delay Input1'
   *
   * Block description for '<S115>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S112>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S140>/Delay' */
  FMS_DW.icLoad_i = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S120>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S123>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S123>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S112>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S22>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S17>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S21>/Altitude' */
  /* SystemInitialize for Chart: '<S38>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S37>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S37>/Hold Control' */

  /* SystemInitialize for Merge: '<S37>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/Position' */
  /* SystemInitialize for Chart: '<S59>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_jn);

  /* SystemInitialize for Chart: '<S73>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_d;

  /* SystemInitialize for IfAction SubSystem: '<S72>/Hold Control' */
  /* InitializeConditions for Delay: '<S79>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S79>/start_wp' */
  FMS_DW.icLoad_c = 1U;

  /* End of SystemInitialize for SubSystem: '<S72>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S58>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_l);

  /* End of SystemInitialize for SubSystem: '<S58>/Hold Control' */

  /* SystemInitialize for Merge: '<S58>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for Merge: '<S72>/Merge' */
  FMS_B.Merge_p = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Position' */
  /* End of SystemInitialize for SubSystem: '<S17>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S15>/Arm' */
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
