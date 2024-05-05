/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2127
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May  4 16:24:12 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S369>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S379>/Motion State' */
#define FMS_IN_Brake_c                 ((uint8_T)1U)
#define FMS_IN_Hold_c                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S46>/Motion Status' */
#define FMS_IN_Brake_e                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_d                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_c       ((uint8_T)0U)

/* Named constants for Chart: '<S299>/Motion State' */
#define FMS_IN_Brake_o                 ((uint8_T)1U)
#define FMS_IN_Hold_d                  ((uint8_T)2U)
#define FMS_IN_Move_n                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_h       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Altitude                ((uint8_T)1U)
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
#define FMS_IN_InvalidAssistMode       ((uint8_T)2U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Land                    ((uint8_T)2U)
#define FMS_IN_Land_j                  ((uint8_T)3U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)1U)
#define FMS_IN_Loiter_p                ((uint8_T)4U)
#define FMS_IN_Lost                    ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)5U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)3U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_h                ((uint8_T)6U)
#define FMS_IN_Run                     ((uint8_T)2U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_SetSpeed                ((uint8_T)7U)
#define FMS_IN_Stabilize               ((uint8_T)4U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_IN_Takeoff_d               ((uint8_T)8U)
#define FMS_IN_Waypoint                ((uint8_T)9U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude_e              ((uint8_T)2U)
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
struct_pJ9vX14fiEgD1ptfg18n3D FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.95F,
  1.0F,
  8.0F,
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
  8.0F,
  0.95F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S3>/Constant1'
                                        *   '<S25>/Constant'
                                        *   '<S422>/Constant'
                                        *   '<S282>/L1'
                                        *   '<S43>/Gain6'
                                        *   '<S44>/Gain6'
                                        *   '<S57>/Gain6'
                                        *   '<S87>/Gain6'
                                        *   '<S88>/Gain6'
                                        *   '<S89>/Gain6'
                                        *   '<S97>/L1'
                                        *   '<S178>/Saturation'
                                        *   '<S179>/Saturation1'
                                        *   '<S179>/Saturation2'
                                        *   '<S179>/Saturation3'
                                        *   '<S323>/Land_Speed'
                                        *   '<S324>/Saturation1'
                                        *   '<S410>/Takeoff_Speed'
                                        *   '<S411>/Gain2'
                                        *   '<S411>/Saturation1'
                                        *   '<S45>/Saturation1'
                                        *   '<S54>/Dead Zone'
                                        *   '<S54>/Gain'
                                        *   '<S55>/Dead Zone'
                                        *   '<S55>/Gain'
                                        *   '<S59>/Saturation1'
                                        *   '<S68>/Dead Zone'
                                        *   '<S68>/Gain'
                                        *   '<S69>/Saturation1'
                                        *   '<S90>/Dead Zone'
                                        *   '<S90>/Gain'
                                        *   '<S91>/Dead Zone'
                                        *   '<S91>/Gain'
                                        *   '<S92>/Dead Zone'
                                        *   '<S92>/Gain'
                                        *   '<S232>/Gain2'
                                        *   '<S239>/Gain1'
                                        *   '<S239>/Gain2'
                                        *   '<S288>/Saturation1'
                                        *   '<S298>/Saturation'
                                        *   '<S310>/Saturation1'
                                        *   '<S325>/Constant'
                                        *   '<S328>/Gain2'
                                        *   '<S350>/Gain'
                                        *   '<S350>/Saturation1'
                                        *   '<S353>/Constant'
                                        *   '<S353>/vel'
                                        *   '<S353>/Switch'
                                        *   '<S48>/Gain2'
                                        *   '<S49>/Gain1'
                                        *   '<S52>/Constant'
                                        *   '<S62>/Gain2'
                                        *   '<S63>/Gain1'
                                        *   '<S66>/Constant'
                                        *   '<S72>/Gain2'
                                        *   '<S73>/Gain6'
                                        *   '<S79>/Constant'
                                        *   '<S116>/Gain'
                                        *   '<S116>/Saturation1'
                                        *   '<S119>/Constant'
                                        *   '<S119>/vel'
                                        *   '<S119>/Switch'
                                        *   '<S291>/Gain2'
                                        *   '<S292>/Gain1'
                                        *   '<S301>/Gain2'
                                        *   '<S302>/Gain1'
                                        *   '<S313>/Gain2'
                                        *   '<S314>/Gain6'
                                        *   '<S337>/Gain2'
                                        *   '<S337>/Saturation'
                                        *   '<S338>/Integrator'
                                        *   '<S51>/Dead Zone'
                                        *   '<S51>/Gain'
                                        *   '<S65>/Dead Zone'
                                        *   '<S65>/Gain'
                                        *   '<S77>/Dead Zone'
                                        *   '<S77>/Gain'
                                        *   '<S103>/Gain2'
                                        *   '<S103>/Saturation'
                                        *   '<S104>/Integrator'
                                        *   '<S294>/Dead Zone'
                                        *   '<S294>/Gain'
                                        *   '<S306>/Dead Zone'
                                        *   '<S306>/Gain'
                                        *   '<S318>/Dead Zone'
                                        *   '<S318>/Gain'
                                        *   '<S319>/Dead Zone'
                                        *   '<S319>/Gain'
                                        *   '<S368>/Saturation1'
                                        *   '<S378>/Saturation1'
                                        *   '<S134>/Saturation1'
                                        *   '<S144>/Saturation1'
                                        *   '<S371>/Gain2'
                                        *   '<S372>/Gain1'
                                        *   '<S381>/Gain2'
                                        *   '<S382>/Gain6'
                                        *   '<S137>/Gain2'
                                        *   '<S138>/Gain1'
                                        *   '<S147>/Gain2'
                                        *   '<S148>/Gain6'
                                        *   '<S374>/Dead Zone'
                                        *   '<S374>/Gain'
                                        *   '<S386>/Dead Zone'
                                        *   '<S386>/Gain'
                                        *   '<S387>/Dead Zone'
                                        *   '<S387>/Gain'
                                        *   '<S140>/Dead Zone'
                                        *   '<S140>/Gain'
                                        *   '<S152>/Dead Zone'
                                        *   '<S152>/Gain'
                                        *   '<S153>/Dead Zone'
                                        *   '<S153>/Gain'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB FMS_EXPORT = {
  4U,

  { 83, 117, 98, 109, 97, 114, 105, 110, 101, 32, 70, 77, 83, 32, 118, 48, 46,
    48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S11>/Constant1'
                                        *   '<S420>/Constant'
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
static void FMS_exit_internal_Auto(void);
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
 *    '<S368>/Hold Control'
 *    '<S288>/Hold Control'
 *    '<S134>/Hold Control'
 *    '<S45>/Hold Control'
 *    '<S59>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S371>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S368>/Hold Control'
 *    '<S288>/Hold Control'
 *    '<S134>/Hold Control'
 *    '<S45>/Hold Control'
 *    '<S59>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S371>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S368>/Hold Control'
 *    '<S288>/Hold Control'
 *    '<S134>/Hold Control'
 *    '<S45>/Hold Control'
 *    '<S59>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S371>/Delay' incorporates:
   *  Gain: '<S373>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S371>/Gain2' incorporates:
   *  Delay: '<S371>/Delay'
   *  Gain: '<S373>/Gain'
   *  Sum: '<S371>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S371>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S368>/Brake Control'
 *    '<S288>/Brake Control'
 *    '<S298>/Brake Control'
 *    '<S134>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S370>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S370>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S368>/Move Control'
 *    '<S288>/Move Control'
 *    '<S134>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S368>/Move Control'
 *    '<S288>/Move Control'
 *    '<S134>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S368>/Move Control'
 *    '<S288>/Move Control'
 *    '<S134>/Move Control'
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

  /* Product: '<S376>/Multiply1' incorporates:
   *  Constant: '<S376>/const1'
   *  DiscreteIntegrator: '<S375>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S374>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S374>/Dead Zone' */

  /* Sum: '<S376>/Add' incorporates:
   *  DiscreteIntegrator: '<S375>/Integrator1'
   *  Gain: '<S372>/Gain1'
   *  Gain: '<S374>/Gain'
   *  Sum: '<S375>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S376>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
  }

  /* End of Signum: '<S376>/Sign' */

  /* Sum: '<S376>/Add2' incorporates:
   *  Abs: '<S376>/Abs'
   *  Gain: '<S376>/Gain'
   *  Gain: '<S376>/Gain1'
   *  Product: '<S376>/Multiply2'
   *  Product: '<S376>/Multiply3'
   *  Sqrt: '<S376>/Sqrt'
   *  Sum: '<S376>/Add1'
   *  Sum: '<S376>/Subtract'
   */
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S376>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S376>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S376>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S376>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S376>/Sign1' */

  /* Signum: '<S376>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S376>/Sign2' */

  /* Sum: '<S376>/Add5' incorporates:
   *  Gain: '<S376>/Gain2'
   *  Product: '<S376>/Multiply4'
   *  Sum: '<S376>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S372>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S375>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S375>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S375>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S376>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S376>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S376>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_g;
  }

  /* End of Signum: '<S376>/Sign5' */

  /* Signum: '<S376>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S376>/Sign3' */

  /* Signum: '<S376>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S376>/Sign4' */

  /* Signum: '<S376>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S376>/Sign6' */

  /* Update for DiscreteIntegrator: '<S375>/Integrator' incorporates:
   *  Constant: '<S376>/const'
   *  Gain: '<S376>/Gain3'
   *  Product: '<S376>/Divide'
   *  Product: '<S376>/Multiply5'
   *  Product: '<S376>/Multiply6'
   *  Sum: '<S376>/Subtract4'
   *  Sum: '<S376>/Subtract5'
   *  Sum: '<S376>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S369>/Motion Status'
 *    '<S289>/Motion Status'
 *    '<S135>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S369>/Motion Status'
 *    '<S289>/Motion Status'
 *    '<S135>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S369>/Motion Status'
 *    '<S289>/Motion Status'
 *    '<S135>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S369>/Motion Status' */
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

  /* End of Chart: '<S369>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S378>/Hold Control'
 *    '<S310>/Hold Control'
 *    '<S144>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S381>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S378>/Hold Control'
 *    '<S310>/Hold Control'
 *    '<S144>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S381>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S378>/Hold Control'
 *    '<S310>/Hold Control'
 *    '<S144>/Hold Control'
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

  /* Delay: '<S381>/Delay' incorporates:
   *  SignalConversion: '<S381>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S385>/Trigonometric Function1' incorporates:
   *  Gain: '<S384>/Gain'
   *  Trigonometry: '<S385>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S385>/Trigonometric Function' incorporates:
   *  Gain: '<S384>/Gain'
   *  Trigonometry: '<S385>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S385>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S385>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S385>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S385>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S385>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S385>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S385>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S381>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S381>/Delay'
   *  SignalConversion: '<S381>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S381>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S381>/Multiply' incorporates:
   *  SignalConversion: '<S381>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S381>/Multiply' */

  /* Gain: '<S381>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S381>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S378>/Brake Control'
 *    '<S310>/Brake Control'
 *    '<S144>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S380>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for atomic system:
 *    '<S379>/Motion State'
 *    '<S311>/Motion State'
 *    '<S145>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S379>/Motion State'
 *    '<S311>/Motion State'
 *    '<S145>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S379>/Motion State'
 *    '<S311>/Motion State'
 *    '<S145>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S379>/Motion State' */
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

  /* End of Chart: '<S379>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S355>/NearbyRefWP'
 *    '<S121>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S393>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S310>/Move Control'
 *    '<S144>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_k_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S310>/Move Control'
 *    '<S144>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_k_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S310>/Move Control'
 *    '<S144>/Move Control'
 */
void FMS_MoveControl_i(real32_T rtu_FMS_In, real32_T rtu_FMS_In_f, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_o_T *localC,
  DW_MoveControl_FMS_k_T *localDW)
{
  real32_T rtb_Subtract3_j;
  real32_T rtb_Add3_k_idx_0;
  real32_T rtb_Subtract3_ln_idx_0;
  real32_T rtb_Add3_k_idx_1;
  real32_T rtb_Subtract3_ln_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_ln_idx_0_0;

  /* SignalConversion: '<S314>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S320>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S321>/Multiply1' incorporates:
   *  Constant: '<S321>/const1'
   *  DiscreteIntegrator: '<S320>/Integrator'
   */
  rtb_Add3_k_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S314>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S320>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S321>/Multiply1' incorporates:
   *  Constant: '<S321>/const1'
   *  DiscreteIntegrator: '<S320>/Integrator'
   */
  rtb_Add3_k_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S318>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_ln_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_ln_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_ln_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S318>/Dead Zone' */

  /* Sum: '<S321>/Add' incorporates:
   *  DiscreteIntegrator: '<S320>/Integrator1'
   *  Gain: '<S314>/Gain6'
   *  Gain: '<S318>/Gain'
   *  Sum: '<S320>/Subtract'
   */
  rtb_Subtract3_ln_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_ln_idx_1 * FMS_PARAM.VEL_X_LIM) +
    rtb_Add3_k_idx_0;

  /* DeadZone: '<S319>/Dead Zone' */
  if (rtu_FMS_In_f > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_ln_idx_1 = rtu_FMS_In_f - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_f >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_ln_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_ln_idx_1 = rtu_FMS_In_f - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S319>/Dead Zone' */

  /* Sum: '<S321>/Add' incorporates:
   *  DiscreteIntegrator: '<S320>/Integrator1'
   *  Gain: '<S314>/Gain6'
   *  Gain: '<S319>/Gain'
   *  Sum: '<S320>/Subtract'
   */
  rtb_Subtract3_ln_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_ln_idx_1 * FMS_PARAM.VEL_X_LIM) +
    rtb_Add3_k_idx_1;

  /* Signum: '<S321>/Sign' */
  if (rtb_Subtract3_ln_idx_0 < 0.0F) {
    rtb_Subtract3_ln_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0 > 0.0F) {
    rtb_Subtract3_ln_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_ln_idx_0_0 = rtb_Subtract3_ln_idx_0;
  }

  /* Sum: '<S321>/Add2' incorporates:
   *  Abs: '<S321>/Abs'
   *  Gain: '<S321>/Gain'
   *  Gain: '<S321>/Gain1'
   *  Product: '<S321>/Multiply2'
   *  Product: '<S321>/Multiply3'
   *  Signum: '<S321>/Sign'
   *  Sqrt: '<S321>/Sqrt'
   *  Sum: '<S321>/Add1'
   *  Sum: '<S321>/Subtract'
   */
  rtb_Subtract3_ln_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_ln_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_ln_idx_0_0 +
    rtb_Add3_k_idx_0;

  /* Sum: '<S321>/Add3' incorporates:
   *  Signum: '<S321>/Sign'
   */
  u = rtb_Subtract3_ln_idx_0 + localC->d;

  /* Sum: '<S321>/Subtract1' incorporates:
   *  Signum: '<S321>/Sign'
   */
  rtb_Subtract3_j = rtb_Subtract3_ln_idx_0 - localC->d;

  /* Signum: '<S321>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S321>/Sign2' */
  if (rtb_Subtract3_j < 0.0F) {
    rtb_Subtract3_j = -1.0F;
  } else {
    if (rtb_Subtract3_j > 0.0F) {
      rtb_Subtract3_j = 1.0F;
    }
  }

  /* Sum: '<S321>/Add5' incorporates:
   *  Gain: '<S321>/Gain2'
   *  Product: '<S321>/Multiply4'
   *  Signum: '<S321>/Sign'
   *  Sum: '<S321>/Add2'
   *  Sum: '<S321>/Add4'
   *  Sum: '<S321>/Subtract2'
   */
  rtb_Subtract3_ln_idx_0_0 += ((rtb_Subtract3_ln_idx_0 -
    rtb_Subtract3_ln_idx_0_0) + rtb_Add3_k_idx_0) * ((u - rtb_Subtract3_j) *
    0.5F);

  /* Update for DiscreteIntegrator: '<S320>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S320>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S321>/Sign3' incorporates:
   *  Sum: '<S321>/Add6'
   */
  u = rtb_Subtract3_ln_idx_0_0 + localC->d;

  /* Signum: '<S321>/Sign4' incorporates:
   *  Sum: '<S321>/Subtract3'
   */
  rtb_Add3_k_idx_0 = rtb_Subtract3_ln_idx_0_0 - localC->d;

  /* Signum: '<S321>/Sign5' */
  if (rtb_Subtract3_ln_idx_0_0 < 0.0F) {
    rtb_Subtract3_ln_idx_0 = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0_0 > 0.0F) {
    rtb_Subtract3_ln_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_ln_idx_0 = rtb_Subtract3_ln_idx_0_0;
  }

  /* Signum: '<S321>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S321>/Sign4' */
  if (rtb_Add3_k_idx_0 < 0.0F) {
    rtb_Add3_k_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_k_idx_0 > 0.0F) {
      rtb_Add3_k_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S321>/Sign6' */
  if (rtb_Subtract3_ln_idx_0_0 < 0.0F) {
    rtb_Subtract3_j = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0_0 > 0.0F) {
    rtb_Subtract3_j = 1.0F;
  } else {
    rtb_Subtract3_j = rtb_Subtract3_ln_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S320>/Integrator' incorporates:
   *  Constant: '<S321>/const'
   *  Gain: '<S321>/Gain3'
   *  Product: '<S321>/Divide'
   *  Product: '<S321>/Multiply5'
   *  Product: '<S321>/Multiply6'
   *  Sum: '<S321>/Subtract4'
   *  Sum: '<S321>/Subtract5'
   *  Sum: '<S321>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_ln_idx_0_0 / localC->d -
    rtb_Subtract3_ln_idx_0) * localC->Gain4 * ((u - rtb_Add3_k_idx_0) * 0.5F) -
    rtb_Subtract3_j * 58.836F) * 0.004F;

  /* Signum: '<S321>/Sign' */
  if (rtb_Subtract3_ln_idx_1 < 0.0F) {
    rtb_Add3_k_idx_0 = -1.0F;
  } else if (rtb_Subtract3_ln_idx_1 > 0.0F) {
    rtb_Add3_k_idx_0 = 1.0F;
  } else {
    rtb_Add3_k_idx_0 = rtb_Subtract3_ln_idx_1;
  }

  /* Sum: '<S321>/Add2' incorporates:
   *  Abs: '<S321>/Abs'
   *  Gain: '<S321>/Gain'
   *  Gain: '<S321>/Gain1'
   *  Product: '<S321>/Multiply2'
   *  Product: '<S321>/Multiply3'
   *  Signum: '<S321>/Sign'
   *  Sqrt: '<S321>/Sqrt'
   *  Sum: '<S321>/Add1'
   *  Sum: '<S321>/Subtract'
   */
  rtb_Subtract3_ln_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_ln_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_k_idx_0 +
    rtb_Add3_k_idx_1;

  /* Sum: '<S321>/Add3' incorporates:
   *  Signum: '<S321>/Sign'
   */
  u = rtb_Subtract3_ln_idx_1 + localC->d;

  /* Sum: '<S321>/Subtract1' incorporates:
   *  Signum: '<S321>/Sign'
   */
  rtb_Subtract3_j = rtb_Subtract3_ln_idx_1 - localC->d;

  /* Signum: '<S321>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S321>/Sign2' */
  if (rtb_Subtract3_j < 0.0F) {
    rtb_Subtract3_j = -1.0F;
  } else {
    if (rtb_Subtract3_j > 0.0F) {
      rtb_Subtract3_j = 1.0F;
    }
  }

  /* Sum: '<S321>/Add5' incorporates:
   *  Gain: '<S321>/Gain2'
   *  Product: '<S321>/Multiply4'
   *  Signum: '<S321>/Sign'
   *  Sum: '<S321>/Add2'
   *  Sum: '<S321>/Add4'
   *  Sum: '<S321>/Subtract2'
   */
  rtb_Subtract3_ln_idx_0_0 += ((rtb_Subtract3_ln_idx_1 -
    rtb_Subtract3_ln_idx_0_0) + rtb_Add3_k_idx_1) * ((u - rtb_Subtract3_j) *
    0.5F);

  /* Update for DiscreteIntegrator: '<S320>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S320>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S321>/Sign3' incorporates:
   *  Sum: '<S321>/Add6'
   */
  u = rtb_Subtract3_ln_idx_0_0 + localC->d;

  /* Signum: '<S321>/Sign4' incorporates:
   *  Sum: '<S321>/Subtract3'
   */
  rtb_Add3_k_idx_0 = rtb_Subtract3_ln_idx_0_0 - localC->d;

  /* Signum: '<S321>/Sign5' */
  if (rtb_Subtract3_ln_idx_0_0 < 0.0F) {
    rtb_Subtract3_ln_idx_0 = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0_0 > 0.0F) {
    rtb_Subtract3_ln_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_ln_idx_0 = rtb_Subtract3_ln_idx_0_0;
  }

  /* Signum: '<S321>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S321>/Sign4' */
  if (rtb_Add3_k_idx_0 < 0.0F) {
    rtb_Add3_k_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_k_idx_0 > 0.0F) {
      rtb_Add3_k_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S321>/Sign6' */
  if (rtb_Subtract3_ln_idx_0_0 < 0.0F) {
    rtb_Subtract3_j = -1.0F;
  } else if (rtb_Subtract3_ln_idx_0_0 > 0.0F) {
    rtb_Subtract3_j = 1.0F;
  } else {
    rtb_Subtract3_j = rtb_Subtract3_ln_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S320>/Integrator' incorporates:
   *  Constant: '<S321>/const'
   *  Gain: '<S321>/Gain3'
   *  Product: '<S321>/Divide'
   *  Product: '<S321>/Multiply5'
   *  Product: '<S321>/Multiply6'
   *  Sum: '<S321>/Subtract4'
   *  Sum: '<S321>/Subtract5'
   *  Sum: '<S321>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_ln_idx_0_0 / localC->d -
    rtb_Subtract3_ln_idx_0) * localC->Gain4 * ((u - rtb_Add3_k_idx_0) * 0.5F) -
    rtb_Subtract3_j * 58.836F) * 0.004F;
}

/*
 * Output and update for action system:
 *    '<S36>/Unknown'
 *    '<S34>/Unknown'
 *    '<S33>/Unknown'
 *    '<S29>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S284>/Bus Assignment' incorporates:
   *  Constant: '<S284>/Constant'
   *  Constant: '<S284>/Constant2'
   *  SignalConversion: '<S284>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S284>/Bus Assignment' */
}

/*
 * Output and update for action system:
 *    '<S45>/Brake Control'
 *    '<S59>/Brake Control'
 */
void FMS_BrakeControl_b(real32_T *rty_w_cmd_mPs)
{
  /* SignalConversion: '<S47>/OutportBuffer_InsertedFor_w_cmd_mPs_at_inport_0' incorporates:
   *  Constant: '<S47>/Brake Speed'
   */
  *rty_w_cmd_mPs = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S45>/Move Control'
 *    '<S59>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs)
{
  real32_T rtu_FMS_In_0;

  /* DeadZone: '<S51>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtu_FMS_In_0 = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtu_FMS_In_0 = 0.0F;
  } else {
    rtu_FMS_In_0 = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S51>/Dead Zone' */

  /* Gain: '<S49>/Gain1' incorporates:
   *  Gain: '<S51>/Gain'
   */
  *rty_w_cmd_mPs = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtu_FMS_In_0 *
    -FMS_PARAM.VEL_Z_LIM;
}

/*
 * System initialize for atomic system:
 *    '<S46>/Motion Status'
 *    '<S60>/Motion Status'
 */
void FMS_MotionStatus_h_Init(DW_MotionStatus_FMS_b_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_c;
}

/*
 * System reset for atomic system:
 *    '<S46>/Motion Status'
 *    '<S60>/Motion Status'
 */
void FMS_MotionStatus_b_Reset(DW_MotionStatus_FMS_b_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_c;
}

/*
 * Output and update for atomic system:
 *    '<S46>/Motion Status'
 *    '<S60>/Motion Status'
 */
void FMS_MotionStatus_n(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_b_T *localDW)
{
  /* Chart: '<S46>/Motion Status' */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c17_FMS == 0U) {
    localDW->is_active_c17_FMS = 1U;
    localDW->is_c17_FMS = FMS_IN_Move_d;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c17_FMS) {
     case FMS_IN_Brake_e:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.1) || (localDW->temporalCounter_i1 >= 375U)) {
        localDW->is_c17_FMS = FMS_IN_Hold_j;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c17_FMS = FMS_IN_Move_d;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_j:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Move_d;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Brake_e;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S46>/Motion Status' */
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

  /* Gain: '<S424>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S425>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S425>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S425>/Multiply1' incorporates:
   *  Product: '<S425>/Multiply'
   */
  rtb_Gain_d = localC->ff * rtb_Sum2_ee;

  /* Product: '<S425>/Divide' incorporates:
   *  Constant: '<S425>/Constant'
   *  Constant: '<S425>/R'
   *  Sqrt: '<S425>/Sqrt'
   *  Sum: '<S425>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_d);

  /* Product: '<S425>/Product3' incorporates:
   *  Constant: '<S425>/Constant1'
   *  Product: '<S425>/Multiply1'
   *  Sum: '<S425>/Sum2'
   */
  rtb_Gain_d = 1.0 / (1.0 - rtb_Gain_d) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S425>/Multiply2' incorporates:
   *  Trigonometry: '<S425>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S424>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S429>/Abs' incorporates:
   *  Abs: '<S432>/Abs1'
   *  Switch: '<S429>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S429>/Switch1' incorporates:
   *  Abs: '<S429>/Abs'
   *  Bias: '<S429>/Bias2'
   *  Bias: '<S429>/Bias3'
   *  Constant: '<S426>/Constant'
   *  Constant: '<S426>/Constant1'
   *  Constant: '<S431>/Constant'
   *  Gain: '<S429>/Gain1'
   *  Product: '<S429>/Multiply'
   *  RelationalOperator: '<S431>/Compare'
   *  Switch: '<S426>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S432>/Switch1' incorporates:
     *  Bias: '<S432>/Bias2'
     *  Bias: '<S432>/Bias3'
     *  Constant: '<S432>/Constant'
     *  Constant: '<S433>/Constant'
     *  Math: '<S432>/Math Function'
     *  RelationalOperator: '<S433>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S432>/Switch1' */

    /* Signum: '<S429>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S429>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S426>/Sum' incorporates:
   *  Sum: '<S424>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S424>/Multiply' incorporates:
   *  Gain: '<S424>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_d;

  /* Switch: '<S428>/Switch1' incorporates:
   *  Abs: '<S428>/Abs1'
   *  Bias: '<S428>/Bias2'
   *  Bias: '<S428>/Bias3'
   *  Constant: '<S428>/Constant'
   *  Constant: '<S430>/Constant'
   *  Math: '<S428>/Math Function'
   *  RelationalOperator: '<S430>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S428>/Switch1' */

  /* Product: '<S424>/Multiply' incorporates:
   *  Gain: '<S424>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S424>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S427>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_d = cos(rtb_Sum2_ee);

  /* Sum: '<S427>/Sum2' incorporates:
   *  Product: '<S427>/Multiply1'
   *  Product: '<S427>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_d + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S427>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S427>/Multiply4' */
  rtb_Gain_d *= rtb_Sum_d;

  /* Sum: '<S427>/Sum3' */
  rtb_Sum3_l = rtb_Gain_d - rtb_Sum3_l;

  /* DataTypeConversion: '<S421>/Data Type Conversion' incorporates:
   *  Gain: '<S424>/Gain'
   *  Sum: '<S424>/Sum1'
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Manual(void)
{
  FMS_B.target_mode = PilotMode_Manual;

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
    FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
  if (!(mode_in == PilotMode_None)) {
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
      if (((ins_flag & 1U) == 0U) || ((ins_flag & 4U) == 0U) || ((ins_flag & 8U)
           == 0U)) {
      } else {
        switch (mode_in) {
         case PilotMode_Position:
         case PilotMode_Mission:
         case PilotMode_Offboard:
          if (((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) && ((ins_flag
                & 128U) != 0U)) {
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
      FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1 = false;
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
        FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] + FMS_DW.home
                         [2]);
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

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
        FMS_DW.is_Mission = FMS_IN_Return_h;
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.state = VehicleState_Return;
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

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
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
    FMS_DW.is_Manual = FMS_IN_InValidManualMode;
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
  /* RelationalOperator: '<S434>/Compare' incorporates:
   *  Abs: '<S423>/Abs'
   *  Constant: '<S434>/Constant'
   *  MinMax: '<S423>/Max'
   *  Sum: '<S423>/Sum'
   */
  FMS_B.Compare_k = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S5>/Vehicle.StickMoved' */
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
      FMS_DW.is_Manual = FMS_IN_InValidManualMode;
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
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
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

          /* Constant: '<Root>/Constant' */
          FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
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
              switch (FMS_B.target_mode) {
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
              FMS_DW.is_Manual = FMS_IN_InValidManualMode;
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
  FMS_DW.durationLastReferenceTick_1_n5 = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_h = false;
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
      switch (FMS_B.target_mode) {
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
      FMS_DW.is_Manual = FMS_IN_InValidManualMode;
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

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
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
          if (FMS_B.Compare && ((int32_T)
                                (FMS_B.BusConversion_InsertedFor_FMSSt.flag &
                                 212U) == 212)) {
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_h;
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
  int32_T tmp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
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
            if ((FMS_DW.chartAbsoluteTimeCounter -
                 FMS_DW.durationLastReferenceTick_2 >= 500) ||
                ((FMS_B.target_mode == PilotMode_Offboard) &&
                 FMS_B.LogicalOperator)) {
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
      /* Reshape: '<S422>/Reshape' incorporates:
       *  Constant: '<S422>/Constant'
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

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_h = false;
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

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_h = false;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_b = false;
      FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      guard4 = false;
      guard5 = false;
      guard6 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if ((FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          guard6 = true;
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
              guard6 = true;
            } else {
              guard5 = true;
            }
          } else {
            guard5 = true;
          }
        }
      } else {
        guard4 = true;
      }

      if (guard6) {
        FMS_DW.prep_mission_takeoff = 1.0;
        FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff == 1.0);
        FMS_DW.prep_takeoff = 0.0;
        FMS_DW.condWasTrueAtLastTimeStep_1_b = (FMS_DW.prep_takeoff == 1.0);
        guard4 = true;
      }

      if (guard5) {
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

      if (guard4) {
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
  real32_T A;
  real32_T B;
  real32_T D;
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_m;
  int8_T rtPrevAction;
  real32_T rtb_Add3_c;
  real32_T rtb_VectorConcatenate_i[9];
  real32_T rtb_Subtract3_d5;
  real32_T rtb_a_a;
  real32_T rtb_Add4_p;
  boolean_T rtb_Compare_on;
  MotionState rtb_state_c;
  real32_T rtb_Switch_dw[3];
  real32_T rtb_l1_a_cmd_j;
  real32_T rtb_Rem_p;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real_T rtb_Switch1_p;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_VectorConcatenate_k[9];
  real32_T rtb_Rem_n;
  real32_T rtb_Sqrt_b;
  boolean_T rtb_LogicalOperator_e;
  real32_T rtb_Subtract3_lb[2];
  real32_T rtb_TmpSignalConversionAtMath_c[3];
  real32_T rtb_VectorConcatenate_ar[3];
  boolean_T tmp[3];
  real32_T tmp_0[3];
  boolean_T tmp_1[3];
  boolean_T tmp_2[3];
  int32_T rtb_Compare_bv_0;
  real32_T rtb_Sign1_c_idx_1;
  real32_T rtb_a_c_idx_0;
  real32_T rtb_MathFunction_f_idx_2;
  real_T rtb_Multiply_l5_idx_0;
  real32_T u1_tmp;
  uint32_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;
  boolean_T guard1 = false;

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
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  DataTypeConversion: '<S13>/Data Type Conversion2'
   *  Delay: '<S13>/Delay'
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S13>/Logical Operator1'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/FixPt Relational Operator'
   *  Switch: '<S13>/Switch1'
   *  UnitDelay: '<S22>/Delay Input1'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
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
      FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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

     case FMS_IN_Altitude_e:
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
          FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
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
        FMS_DW.is_c3_FMS = FMS_IN_Altitude_e;
      }
      break;

     default:
      FMS_Stabilize();
      break;
    }
  }

  /* End of Chart: '<Root>/SafeMode' */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_m = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  RelationalOperator: '<S18>/FixPt Relational Operator'
   *  Switch: '<S12>/Switch2'
   *  UnitDelay: '<S17>/Delay Input1'
   *  UnitDelay: '<S18>/Delay Input1'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S12>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_m;
  } else {
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S24>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
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
   *  RelationalOperator: '<S23>/FixPt Relational Operator'
   *  UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
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
   *  Constant: '<S25>/Constant'
   *  Constant: '<S3>/Constant1'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  RelationalOperator: '<S25>/Compare'
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

  /* RelationalOperator: '<S26>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
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
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = 0U;
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
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_b < 1000U) &&
    (rtb_Switch_m != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
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
  FMS_DW.durationLastReferenceTick_1_n5 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_h = false;
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

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
  /* SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_dw[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_dw[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_dw[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

  /* SwitchCase: '<S27>/Switch Case' incorporates:
   *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S29>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S36>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S378>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S368>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S310>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;

        /* Disable for SwitchCase: '<S288>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S298>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S34>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S93>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S144>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S134>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S93>/Mission_SubSystem' */
      }

      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S33>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 3:
        break;

       case 1:
        /* Disable for SwitchCase: '<S45>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S69>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

        /* Disable for SwitchCase: '<S59>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S29>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S27>/Disarm' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S30>/Bus Assignment'
     *  BusAssignment: '<S31>/Bus Assignment'
     *  Constant: '<S31>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S31>/Bus Assignment' incorporates:
     *  BusAssignment: '<S30>/Bus Assignment'
     *  Constant: '<S31>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;

    /* End of Outputs for SubSystem: '<S27>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S27>/Standby' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S30>/Bus Assignment'
     *  BusAssignment: '<S32>/Bus Assignment'
     *  Constant: '<S32>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S32>/Bus Assignment' incorporates:
     *  BusAssignment: '<S30>/Bus Assignment'
     *  Constant: '<S32>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;

    /* End of Outputs for SubSystem: '<S27>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S27>/Arm' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* SwitchCase: '<S29>/Switch Case' */
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
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S378>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S368>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S310>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;

          /* Disable for SwitchCase: '<S288>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S298>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S34>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S93>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S144>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S134>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S93>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S33>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S45>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S69>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* Disable for SwitchCase: '<S59>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;
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
      /* Outputs for IfAction SubSystem: '<S29>/SubMode' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* SwitchCase: '<S36>/Switch Case' incorporates:
       *  Math: '<S400>/Math Function'
       *  Product: '<S402>/Divide'
       *  Sum: '<S356>/Subtract'
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
          /* Disable for SwitchCase: '<S378>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S368>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S310>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;

          /* Disable for SwitchCase: '<S288>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S298>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S36>/Takeoff' incorporates:
           *  ActionPort: '<S283>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Delay: '<S418>/cur_waypoint'
           *  DiscreteIntegrator: '<S414>/Integrator'
           *  DiscreteIntegrator: '<S414>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Takeoff' incorporates:
         *  ActionPort: '<S283>/Action Port'
         */
        /* Delay: '<S418>/cur_waypoint' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j1 != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
          FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Product: '<S418>/Divide' incorporates:
         *  Delay: '<S418>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S418>/Sum1'
         *  Sum: '<S418>/Sum2'
         */
        rtb_Add3_c = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                             FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R
          - FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Saturate: '<S418>/Saturation' */
        if (rtb_Add3_c > 1.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = 0.0F;
          }
        }

        /* End of Saturate: '<S418>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S419>/Trigonometric Function1' incorporates:
         *  Gain: '<S417>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Trigonometry: '<S419>/Trigonometric Function3'
         */
        rtb_Add4_p = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_VectorConcatenate_i[0] = rtb_Add4_p;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S419>/Trigonometric Function' incorporates:
         *  Gain: '<S417>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Trigonometry: '<S419>/Trigonometric Function2'
         */
        A = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_VectorConcatenate_i[1] = A;

        /* SignalConversion: '<S419>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S419>/Constant3'
         */
        rtb_VectorConcatenate_i[2] = 0.0F;

        /* Gain: '<S419>/Gain' */
        rtb_VectorConcatenate_i[3] = -A;

        /* Trigonometry: '<S419>/Trigonometric Function3' */
        rtb_VectorConcatenate_i[4] = rtb_Add4_p;

        /* SignalConversion: '<S419>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S419>/Constant4'
         */
        rtb_VectorConcatenate_i[5] = 0.0F;

        /* SignalConversion: '<S419>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S411>/Saturation1' */
        rtb_Add4_p = FMS_PARAM.VEL_XY_LIM / 5.0F;
        A = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S411>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S418>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S418>/Multiply'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S411>/Sum'
         *  Sum: '<S418>/Sum3'
         *  Sum: '<S418>/Sum4'
         */
        rtb_a_a = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.cur_waypoint_DSTATE[0])
                   * rtb_Add3_c + FMS_DW.cur_waypoint_DSTATE[0]) -
          FMS_U.INS_Out.x_R;
        rtb_l1_a_cmd_j = ((FMS_B.Cmd_In.sp_waypoint[1] -
                           FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Add3_c +
                          FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S411>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
            rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_l1_a_cmd_j +
            rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_a;
        }

        /* Saturate: '<S411>/Saturation1' incorporates:
         *  Gain: '<S411>/Gain2'
         *  Product: '<S411>/Multiply'
         */
        rtb_Subtract3_d5 = FMS_PARAM.XY_P * rtb_VectorConcatenate_ar[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_VectorConcatenate_ar[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S283>/Bus Assignment1'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S283>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S283>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S283>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S411>/Saturation1' */
        if (rtb_Subtract3_d5 > rtb_Add4_p) {
          /* BusAssignment: '<S283>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_p;
        } else if (rtb_Subtract3_d5 < A) {
          /* BusAssignment: '<S283>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = A;
        } else {
          /* BusAssignment: '<S283>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_d5;
        }

        if (rtb_Add3_c > rtb_Add4_p) {
          /* BusAssignment: '<S283>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_p;
        } else if (rtb_Add3_c < A) {
          /* BusAssignment: '<S283>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = A;
        } else {
          /* BusAssignment: '<S283>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S283>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  DiscreteIntegrator: '<S414>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S415>/Multiply1' incorporates:
         *  Constant: '<S415>/const1'
         *  DiscreteIntegrator: '<S414>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S410>/Switch' incorporates:
         *  Abs: '<S410>/Abs'
         *  Abs: '<S410>/Abs1'
         *  Constant: '<S410>/Takeoff_Speed'
         *  Constant: '<S412>/Constant'
         *  Constant: '<S413>/Constant'
         *  Gain: '<S410>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S410>/Logical Operator'
         *  RelationalOperator: '<S412>/Compare'
         *  RelationalOperator: '<S413>/Compare'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S410>/Sum'
         *  Sum: '<S410>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_l1_a_cmd_j = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_l1_a_cmd_j = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S410>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S415>/Add' incorporates:
         *  DiscreteIntegrator: '<S414>/Integrator1'
         *  Sum: '<S414>/Subtract'
         */
        rtb_Subtract3_d5 = (FMS_DW.Integrator1_DSTATE_a - rtb_l1_a_cmd_j) +
          rtb_Add3_c;

        /* Signum: '<S415>/Sign' */
        if (rtb_Subtract3_d5 < 0.0F) {
          rtb_a_a = -1.0F;
        } else if (rtb_Subtract3_d5 > 0.0F) {
          rtb_a_a = 1.0F;
        } else {
          rtb_a_a = rtb_Subtract3_d5;
        }

        /* End of Signum: '<S415>/Sign' */

        /* Sum: '<S415>/Add2' incorporates:
         *  Abs: '<S415>/Abs'
         *  Gain: '<S415>/Gain'
         *  Gain: '<S415>/Gain1'
         *  Product: '<S415>/Multiply2'
         *  Product: '<S415>/Multiply3'
         *  Sqrt: '<S415>/Sqrt'
         *  Sum: '<S415>/Add1'
         *  Sum: '<S415>/Subtract'
         */
        rtb_a_a = (sqrtf((8.0F * fabsf(rtb_Subtract3_d5) + FMS_ConstB.d_m) *
                         FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F * rtb_a_a +
          rtb_Add3_c;

        /* Sum: '<S415>/Add4' */
        rtb_Add4_p = (rtb_Subtract3_d5 - rtb_a_a) + rtb_Add3_c;

        /* Sum: '<S415>/Add3' */
        rtb_Add3_c = rtb_Subtract3_d5 + FMS_ConstB.d_m;

        /* Sum: '<S415>/Subtract1' */
        rtb_Subtract3_d5 -= FMS_ConstB.d_m;

        /* Signum: '<S415>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S415>/Sign1' */

        /* Signum: '<S415>/Sign2' */
        if (rtb_Subtract3_d5 < 0.0F) {
          rtb_Subtract3_d5 = -1.0F;
        } else {
          if (rtb_Subtract3_d5 > 0.0F) {
            rtb_Subtract3_d5 = 1.0F;
          }
        }

        /* End of Signum: '<S415>/Sign2' */

        /* Sum: '<S415>/Add5' incorporates:
         *  Gain: '<S415>/Gain2'
         *  Product: '<S415>/Multiply4'
         *  Sum: '<S415>/Subtract2'
         */
        rtb_a_a += (rtb_Add3_c - rtb_Subtract3_d5) * 0.5F * rtb_Add4_p;

        /* Update for Delay: '<S418>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S414>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S414>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S415>/Subtract3' */
        rtb_Add3_c = rtb_a_a - FMS_ConstB.d_m;

        /* Sum: '<S415>/Add6' */
        A = rtb_a_a + FMS_ConstB.d_m;

        /* Signum: '<S415>/Sign5' incorporates:
         *  Signum: '<S415>/Sign6'
         */
        if (rtb_a_a < 0.0F) {
          rtb_Add4_p = -1.0F;

          /* Signum: '<S415>/Sign6' */
          rtb_Sqrt_b = -1.0F;
        } else if (rtb_a_a > 0.0F) {
          rtb_Add4_p = 1.0F;

          /* Signum: '<S415>/Sign6' */
          rtb_Sqrt_b = 1.0F;
        } else {
          rtb_Add4_p = rtb_a_a;

          /* Signum: '<S415>/Sign6' */
          rtb_Sqrt_b = rtb_a_a;
        }

        /* End of Signum: '<S415>/Sign5' */

        /* Signum: '<S415>/Sign3' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S415>/Sign3' */

        /* Signum: '<S415>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S415>/Sign4' */

        /* Update for DiscreteIntegrator: '<S414>/Integrator' incorporates:
         *  Constant: '<S415>/const'
         *  Gain: '<S415>/Gain3'
         *  Product: '<S415>/Divide'
         *  Product: '<S415>/Multiply5'
         *  Product: '<S415>/Multiply6'
         *  Sum: '<S415>/Subtract4'
         *  Sum: '<S415>/Subtract5'
         *  Sum: '<S415>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_a_a / FMS_ConstB.d_m - rtb_Add4_p) *
          FMS_ConstB.Gain4_a * ((A - rtb_Add3_c) * 0.5F) - rtb_Sqrt_b * 9.806F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S36>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S36>/Land' incorporates:
           *  ActionPort: '<S281>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S326>/Integrator'
           *  DiscreteIntegrator: '<S326>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Land' incorporates:
         *  ActionPort: '<S281>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Trigonometry: '<S331>/Trigonometric Function1' incorporates:
         *  Gain: '<S330>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S331>/Trigonometric Function' incorporates:
         *  Gain: '<S330>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S331>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S331>/Constant3'
         */
        rtb_VectorConcatenate_i[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S331>/Gain' incorporates:
         *  Gain: '<S330>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Trigonometry: '<S331>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S331>/Trigonometric Function3' incorporates:
         *  Gain: '<S330>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SignalConversion: '<S331>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S331>/Constant4'
         */
        rtb_VectorConcatenate_i[5] = 0.0F;

        /* SignalConversion: '<S331>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S324>/Saturation1' */
        rtb_Add4_p = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Sqrt_b = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* SignalConversion: '<S328>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S328>/Sum'
         */
        rtb_a_a = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_l1_a_cmd_j = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S328>/Multiply' incorporates:
         *  SignalConversion: '<S328>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
            rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_l1_a_cmd_j +
            rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_a;
        }

        /* End of Product: '<S328>/Multiply' */

        /* Saturate: '<S324>/Saturation1' incorporates:
         *  Gain: '<S328>/Gain2'
         */
        rtb_Subtract3_d5 = FMS_PARAM.XY_P * rtb_VectorConcatenate_ar[0];
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_VectorConcatenate_ar[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S281>/Bus Assignment1'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S281>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S281>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S281>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S324>/Saturation1' */
        if (rtb_Subtract3_d5 > rtb_Add4_p) {
          /* BusAssignment: '<S281>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_p;
        } else if (rtb_Subtract3_d5 < rtb_Sqrt_b) {
          /* BusAssignment: '<S281>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_b;
        } else {
          /* BusAssignment: '<S281>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_d5;
        }

        if (rtb_Add3_c > rtb_Add4_p) {
          /* BusAssignment: '<S281>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_p;
        } else if (rtb_Add3_c < rtb_Sqrt_b) {
          /* BusAssignment: '<S281>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Sqrt_b;
        } else {
          /* BusAssignment: '<S281>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3_c;
        }

        /* BusAssignment: '<S281>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  DiscreteIntegrator: '<S326>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S327>/Multiply1' incorporates:
         *  Constant: '<S327>/const1'
         *  DiscreteIntegrator: '<S326>/Integrator'
         */
        rtb_Add3_c = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S323>/Switch' incorporates:
         *  Constant: '<S323>/Land_Speed'
         *  Constant: '<S325>/Constant'
         *  Gain: '<S323>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S323>/Logical Operator'
         *  RelationalOperator: '<S325>/Compare'
         *  S-Function (sfix_bitop): '<S323>/cmd_p valid'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_l1_a_cmd_j = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_l1_a_cmd_j = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S323>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S327>/Add' incorporates:
         *  DiscreteIntegrator: '<S326>/Integrator1'
         *  Sum: '<S326>/Subtract'
         */
        rtb_Subtract3_d5 = (FMS_DW.Integrator1_DSTATE_j - rtb_l1_a_cmd_j) +
          rtb_Add3_c;

        /* Signum: '<S327>/Sign' */
        if (rtb_Subtract3_d5 < 0.0F) {
          rtb_a_a = -1.0F;
        } else if (rtb_Subtract3_d5 > 0.0F) {
          rtb_a_a = 1.0F;
        } else {
          rtb_a_a = rtb_Subtract3_d5;
        }

        /* End of Signum: '<S327>/Sign' */

        /* Sum: '<S327>/Add2' incorporates:
         *  Abs: '<S327>/Abs'
         *  Gain: '<S327>/Gain'
         *  Gain: '<S327>/Gain1'
         *  Product: '<S327>/Multiply2'
         *  Product: '<S327>/Multiply3'
         *  Sqrt: '<S327>/Sqrt'
         *  Sum: '<S327>/Add1'
         *  Sum: '<S327>/Subtract'
         */
        rtb_a_a = (sqrtf((8.0F * fabsf(rtb_Subtract3_d5) + FMS_ConstB.d_p) *
                         FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F * rtb_a_a +
          rtb_Add3_c;

        /* Sum: '<S327>/Add4' */
        rtb_Add4_p = (rtb_Subtract3_d5 - rtb_a_a) + rtb_Add3_c;

        /* Sum: '<S327>/Add3' */
        rtb_Add3_c = rtb_Subtract3_d5 + FMS_ConstB.d_p;

        /* Sum: '<S327>/Subtract1' */
        rtb_Subtract3_d5 -= FMS_ConstB.d_p;

        /* Signum: '<S327>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S327>/Sign1' */

        /* Signum: '<S327>/Sign2' */
        if (rtb_Subtract3_d5 < 0.0F) {
          rtb_Subtract3_d5 = -1.0F;
        } else {
          if (rtb_Subtract3_d5 > 0.0F) {
            rtb_Subtract3_d5 = 1.0F;
          }
        }

        /* End of Signum: '<S327>/Sign2' */

        /* Sum: '<S327>/Add5' incorporates:
         *  Gain: '<S327>/Gain2'
         *  Product: '<S327>/Multiply4'
         *  Sum: '<S327>/Subtract2'
         */
        rtb_a_a += (rtb_Add3_c - rtb_Subtract3_d5) * 0.5F * rtb_Add4_p;

        /* Update for DiscreteIntegrator: '<S326>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S326>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S327>/Subtract3' */
        rtb_Add3_c = rtb_a_a - FMS_ConstB.d_p;

        /* Sum: '<S327>/Add6' */
        A = rtb_a_a + FMS_ConstB.d_p;

        /* Signum: '<S327>/Sign5' incorporates:
         *  Signum: '<S327>/Sign6'
         */
        if (rtb_a_a < 0.0F) {
          rtb_Add4_p = -1.0F;

          /* Signum: '<S327>/Sign6' */
          rtb_Sqrt_b = -1.0F;
        } else if (rtb_a_a > 0.0F) {
          rtb_Add4_p = 1.0F;

          /* Signum: '<S327>/Sign6' */
          rtb_Sqrt_b = 1.0F;
        } else {
          rtb_Add4_p = rtb_a_a;

          /* Signum: '<S327>/Sign6' */
          rtb_Sqrt_b = rtb_a_a;
        }

        /* End of Signum: '<S327>/Sign5' */

        /* Signum: '<S327>/Sign3' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S327>/Sign3' */

        /* Signum: '<S327>/Sign4' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S327>/Sign4' */

        /* Update for DiscreteIntegrator: '<S326>/Integrator' incorporates:
         *  Constant: '<S327>/const'
         *  Gain: '<S327>/Gain3'
         *  Product: '<S327>/Divide'
         *  Product: '<S327>/Multiply5'
         *  Product: '<S327>/Multiply6'
         *  Sum: '<S327>/Subtract4'
         *  Sum: '<S327>/Subtract5'
         *  Sum: '<S327>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_a_a / FMS_ConstB.d_p - rtb_Add4_p) *
          FMS_ConstB.Gain4_e * ((A - rtb_Add3_c) * 0.5F) - rtb_Sqrt_b * 9.806F) *
          0.004F;

        /* End of Outputs for SubSystem: '<S36>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S36>/Return' incorporates:
           *  ActionPort: '<S282>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Delay: '<S334>/Delay'
           *  Delay: '<S335>/Delay'
           *  Delay: '<S357>/Delay'
           *  DiscreteIntegrator: '<S338>/Integrator'
           *  DiscreteIntegrator: '<S338>/Integrator1'
           *  DiscreteIntegrator: '<S353>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S358>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S405>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_l = 1U;
          FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
          FMS_DW.l1_heading_e = 0.0F;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S36>/Return' */

          /* SystemReset for IfAction SubSystem: '<S36>/Return' incorporates:
           *  ActionPort: '<S282>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S369>/Motion Status'
           *  Chart: '<S379>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S36>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Return' incorporates:
         *  ActionPort: '<S282>/Action Port'
         */
        /* Delay: '<S357>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_l != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S353>/Switch2' incorporates:
         *  Constant: '<S353>/vel'
         *  Constant: '<S362>/Constant'
         *  RelationalOperator: '<S362>/Compare'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_a_a = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_a_a = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S353>/Switch2' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* RelationalOperator: '<S352>/Compare' incorporates:
         *  Constant: '<S409>/Constant'
         *  DiscreteIntegrator: '<S358>/Discrete-Time Integrator'
         *  RelationalOperator: '<S409>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTATE_m <= 3);

        /* DiscreteIntegrator: '<S353>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S379>/Motion State' incorporates:
         *  Constant: '<S379>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S379>/Square'
         *  Math: '<S379>/Square1'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sqrt: '<S379>/Sqrt'
         *  Sum: '<S379>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S378>/Switch Case' incorporates:
         *  DiscreteIntegrator: '<S388>/Integrator1'
         *  Gain: '<S382>/Gain6'
         *  Gain: '<S386>/Gain'
         *  Gain: '<S387>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S388>/Subtract'
         *  Sum: '<S389>/Add'
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
            /* SystemReset for IfAction SubSystem: '<S378>/Hold Control' incorporates:
             *  ActionPort: '<S381>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S378>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S378>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S378>/Hold Control' incorporates:
           *  ActionPort: '<S381>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_a,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S378>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S378>/Brake Control' incorporates:
           *  ActionPort: '<S380>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S378>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S378>/Move Control' incorporates:
             *  ActionPort: '<S382>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S378>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S388>/Integrator'
             *  DiscreteIntegrator: '<S388>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m[0] = 0.0F;
            FMS_DW.Integrator_DSTATE_bz[0] = 0.0F;
            FMS_DW.Integrator1_DSTATE_m[1] = 0.0F;
            FMS_DW.Integrator_DSTATE_bz[1] = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S378>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S378>/Move Control' incorporates:
           *  ActionPort: '<S382>/Action Port'
           */
          /* SignalConversion: '<S382>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator1'
           */
          FMS_B.Merge_a[0] = FMS_DW.Integrator1_DSTATE_m[0];

          /* Product: '<S389>/Multiply1' incorporates:
           *  Constant: '<S389>/const1'
           *  DiscreteIntegrator: '<S388>/Integrator'
           */
          rtb_Subtract3_d5 = FMS_DW.Integrator_DSTATE_bz[0] * 0.05F;

          /* SignalConversion: '<S382>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator1'
           */
          FMS_B.Merge_a[1] = FMS_DW.Integrator1_DSTATE_m[1];

          /* Product: '<S389>/Multiply1' incorporates:
           *  Constant: '<S389>/const1'
           *  DiscreteIntegrator: '<S388>/Integrator'
           */
          rtb_Add4_p = FMS_DW.Integrator_DSTATE_bz[1] * 0.05F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S386>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_l1_a_cmd_j = 0.0F;
          } else {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S386>/Gain' */
          rtb_a_c_idx_0 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ);

          /* Sum: '<S389>/Add' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator1'
           *  Gain: '<S382>/Gain6'
           *  Gain: '<S386>/Gain'
           *  Sum: '<S388>/Subtract'
           */
          rtb_Subtract3_lb[0] = (FMS_DW.Integrator1_DSTATE_m[0] - rtb_a_c_idx_0 *
            rtb_l1_a_cmd_j * FMS_PARAM.VEL_XY_LIM) + rtb_Subtract3_d5;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S387>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_l1_a_cmd_j = 0.0F;
          } else {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S387>/Gain' */
          rtb_Rem_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ);

          /* Sum: '<S389>/Add' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator1'
           *  Gain: '<S382>/Gain6'
           *  Gain: '<S387>/Gain'
           *  Sum: '<S388>/Subtract'
           */
          rtb_Subtract3_lb[1] = (FMS_DW.Integrator1_DSTATE_m[1] - rtb_Rem_n *
            rtb_l1_a_cmd_j * FMS_PARAM.VEL_XY_LIM) + rtb_Add4_p;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S386>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_l1_a_cmd_j = 0.0F;
          } else {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          A = (FMS_DW.Integrator1_DSTATE_m[0] - rtb_a_c_idx_0 * rtb_l1_a_cmd_j *
               FMS_PARAM.VEL_XY_LIM) + rtb_Subtract3_d5;

          /* Signum: '<S389>/Sign' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator1'
           *  Gain: '<S382>/Gain6'
           *  Gain: '<S386>/Gain'
           *  Sum: '<S388>/Subtract'
           *  Sum: '<S389>/Add'
           */
          if (A < 0.0F) {
            A = -1.0F;
          } else {
            if (A > 0.0F) {
              A = 1.0F;
            }
          }

          /* Sum: '<S389>/Add2' incorporates:
           *  Abs: '<S389>/Abs'
           *  Gain: '<S389>/Gain'
           *  Gain: '<S389>/Gain1'
           *  Product: '<S389>/Multiply2'
           *  Product: '<S389>/Multiply3'
           *  Signum: '<S389>/Sign'
           *  Sqrt: '<S389>/Sqrt'
           *  Sum: '<S389>/Add1'
           *  Sum: '<S389>/Subtract'
           */
          rtb_l1_a_cmd_j = (sqrtf((8.0F * fabsf(rtb_Subtract3_lb[0]) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F * A +
            rtb_Subtract3_d5;

          /* Sum: '<S389>/Add3' incorporates:
           *  Signum: '<S389>/Sign'
           */
          rtb_Add3_c = rtb_Subtract3_lb[0] + FMS_ConstB.d_a;

          /* Sum: '<S389>/Subtract1' incorporates:
           *  Signum: '<S389>/Sign'
           */
          A = rtb_Subtract3_lb[0] - FMS_ConstB.d_a;

          /* Signum: '<S389>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S389>/Sign2' */
          if (A < 0.0F) {
            A = -1.0F;
          } else {
            if (A > 0.0F) {
              A = 1.0F;
            }
          }

          /* Sum: '<S389>/Add5' incorporates:
           *  Gain: '<S389>/Gain2'
           *  Product: '<S389>/Multiply4'
           *  Signum: '<S389>/Sign'
           *  Sum: '<S389>/Add2'
           *  Sum: '<S389>/Add4'
           *  Sum: '<S389>/Subtract2'
           */
          rtb_l1_a_cmd_j += ((rtb_Subtract3_lb[0] - rtb_l1_a_cmd_j) +
                             rtb_Subtract3_d5) * ((rtb_Add3_c - A) * 0.5F);

          /* Update for DiscreteIntegrator: '<S388>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m[0] += 0.004F *
            FMS_DW.Integrator_DSTATE_bz[0];

          /* Signum: '<S389>/Sign4' incorporates:
           *  Sum: '<S389>/Subtract3'
           */
          rtb_Add3_c = rtb_l1_a_cmd_j - FMS_ConstB.d_a;

          /* Signum: '<S389>/Sign3' incorporates:
           *  Sum: '<S389>/Add6'
           */
          A = rtb_l1_a_cmd_j + FMS_ConstB.d_a;

          /* Signum: '<S389>/Sign5' */
          if (rtb_l1_a_cmd_j < 0.0F) {
            rtb_Subtract3_d5 = -1.0F;
          } else if (rtb_l1_a_cmd_j > 0.0F) {
            rtb_Subtract3_d5 = 1.0F;
          } else {
            rtb_Subtract3_d5 = rtb_l1_a_cmd_j;
          }

          /* Signum: '<S389>/Sign3' */
          if (A < 0.0F) {
            A = -1.0F;
          } else {
            if (A > 0.0F) {
              A = 1.0F;
            }
          }

          /* Signum: '<S389>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S389>/Sign6' */
          if (rtb_l1_a_cmd_j < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (rtb_l1_a_cmd_j > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = rtb_l1_a_cmd_j;
          }

          /* Update for DiscreteIntegrator: '<S388>/Integrator' incorporates:
           *  Constant: '<S389>/const'
           *  Gain: '<S389>/Gain3'
           *  Product: '<S389>/Divide'
           *  Product: '<S389>/Multiply5'
           *  Product: '<S389>/Multiply6'
           *  Sum: '<S389>/Subtract4'
           *  Sum: '<S389>/Subtract5'
           *  Sum: '<S389>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_bz[0] += ((rtb_l1_a_cmd_j / FMS_ConstB.d_a -
            rtb_Subtract3_d5) * FMS_ConstB.Gain4_m * ((A - rtb_Add3_c) * 0.5F) -
            rtb_Sqrt_b * 58.836F) * 0.004F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S387>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_l1_a_cmd_j = 0.0F;
          } else {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          A = (FMS_DW.Integrator1_DSTATE_m[1] - rtb_Rem_n * rtb_l1_a_cmd_j *
               FMS_PARAM.VEL_XY_LIM) + rtb_Add4_p;

          /* Signum: '<S389>/Sign' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator1'
           *  Gain: '<S382>/Gain6'
           *  Gain: '<S387>/Gain'
           *  Sum: '<S388>/Subtract'
           *  Sum: '<S389>/Add'
           */
          if (A < 0.0F) {
            A = -1.0F;
          } else {
            if (A > 0.0F) {
              A = 1.0F;
            }
          }

          /* Sum: '<S389>/Add2' incorporates:
           *  Abs: '<S389>/Abs'
           *  Gain: '<S389>/Gain'
           *  Gain: '<S389>/Gain1'
           *  Product: '<S389>/Multiply2'
           *  Product: '<S389>/Multiply3'
           *  Signum: '<S389>/Sign'
           *  Sqrt: '<S389>/Sqrt'
           *  Sum: '<S389>/Add1'
           *  Sum: '<S389>/Subtract'
           */
          rtb_l1_a_cmd_j = (sqrtf((8.0F * fabsf(rtb_Subtract3_lb[1]) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F * A +
            rtb_Add4_p;

          /* Sum: '<S389>/Add3' incorporates:
           *  Signum: '<S389>/Sign'
           */
          rtb_Add3_c = rtb_Subtract3_lb[1] + FMS_ConstB.d_a;

          /* Sum: '<S389>/Subtract1' incorporates:
           *  Signum: '<S389>/Sign'
           */
          A = rtb_Subtract3_lb[1] - FMS_ConstB.d_a;

          /* Signum: '<S389>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S389>/Sign2' */
          if (A < 0.0F) {
            A = -1.0F;
          } else {
            if (A > 0.0F) {
              A = 1.0F;
            }
          }

          /* Sum: '<S389>/Add5' incorporates:
           *  Gain: '<S389>/Gain2'
           *  Product: '<S389>/Multiply4'
           *  Signum: '<S389>/Sign'
           *  Sum: '<S389>/Add2'
           *  Sum: '<S389>/Add4'
           *  Sum: '<S389>/Subtract2'
           */
          rtb_l1_a_cmd_j += ((rtb_Subtract3_lb[1] - rtb_l1_a_cmd_j) + rtb_Add4_p)
            * ((rtb_Add3_c - A) * 0.5F);

          /* Update for DiscreteIntegrator: '<S388>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m[1] += 0.004F *
            FMS_DW.Integrator_DSTATE_bz[1];

          /* Signum: '<S389>/Sign4' incorporates:
           *  Sum: '<S389>/Subtract3'
           */
          rtb_Add3_c = rtb_l1_a_cmd_j - FMS_ConstB.d_a;

          /* Signum: '<S389>/Sign3' incorporates:
           *  Sum: '<S389>/Add6'
           */
          A = rtb_l1_a_cmd_j + FMS_ConstB.d_a;

          /* Signum: '<S389>/Sign5' */
          if (rtb_l1_a_cmd_j < 0.0F) {
            rtb_Subtract3_d5 = -1.0F;
          } else if (rtb_l1_a_cmd_j > 0.0F) {
            rtb_Subtract3_d5 = 1.0F;
          } else {
            rtb_Subtract3_d5 = rtb_l1_a_cmd_j;
          }

          /* Signum: '<S389>/Sign3' */
          if (A < 0.0F) {
            A = -1.0F;
          } else {
            if (A > 0.0F) {
              A = 1.0F;
            }
          }

          /* Signum: '<S389>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* Signum: '<S389>/Sign6' */
          if (rtb_l1_a_cmd_j < 0.0F) {
            rtb_Sqrt_b = -1.0F;
          } else if (rtb_l1_a_cmd_j > 0.0F) {
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Sqrt_b = rtb_l1_a_cmd_j;
          }

          /* Update for DiscreteIntegrator: '<S388>/Integrator' incorporates:
           *  Constant: '<S389>/const'
           *  Gain: '<S389>/Gain3'
           *  Product: '<S389>/Divide'
           *  Product: '<S389>/Multiply5'
           *  Product: '<S389>/Multiply6'
           *  Sum: '<S389>/Subtract4'
           *  Sum: '<S389>/Subtract5'
           *  Sum: '<S389>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_bz[1] += ((rtb_l1_a_cmd_j / FMS_ConstB.d_a -
            rtb_Subtract3_d5) * FMS_ConstB.Gain4_m * ((A - rtb_Add3_c) * 0.5F) -
            rtb_Sqrt_b * 58.836F) * 0.004F;

          /* End of Outputs for SubSystem: '<S378>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S378>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S369>/Motion Status' incorporates:
         *  Abs: '<S369>/Abs'
         *  Constant: '<S369>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S368>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state_c) {
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
            /* SystemReset for IfAction SubSystem: '<S368>/Hold Control' incorporates:
             *  ActionPort: '<S371>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S368>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S368>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S368>/Hold Control' incorporates:
           *  ActionPort: '<S371>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_j, &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S368>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S368>/Brake Control' incorporates:
           *  ActionPort: '<S370>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S368>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S368>/Move Control' incorporates:
             *  ActionPort: '<S372>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S368>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S368>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S368>/Move Control' incorporates:
           *  ActionPort: '<S372>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_j,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S368>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S368>/Switch Case' */

        /* Switch: '<S333>/Switch' incorporates:
         *  Product: '<S357>/Multiply'
         *  Sum: '<S357>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S378>/Saturation1' */
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

          /* End of Saturate: '<S378>/Saturation1' */

          /* Saturate: '<S368>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S368>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S357>/Sum' incorporates:
           *  Delay: '<S357>/Delay'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S406>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Add3_c;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S353>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_c_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Subtract3_d5 = rtb_Add3_c;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S357>/Sum' incorporates:
           *  Delay: '<S357>/Delay'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_e[1];

          /* Sum: '<S353>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Rem_n = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sqrt: '<S365>/Sqrt' incorporates:
           *  Math: '<S365>/Square'
           *  Sum: '<S353>/Sum'
           *  Sum: '<S365>/Sum of Elements'
           */
          rtb_Sqrt_b = sqrtf(rtb_a_c_idx_0 * rtb_a_c_idx_0 + rtb_Rem_n *
                             rtb_Rem_n);

          /* SignalConversion: '<S408>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* SignalConversion: '<S408>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S408>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S407>/Gain' incorporates:
           *  DiscreteIntegrator: '<S405>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S405>/Add'
           */
          rtb_l1_a_cmd_j = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S408>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S408>/Trigonometric Function1'
           */
          rtb_Add4_p = arm_cos_f32(rtb_l1_a_cmd_j);
          rtb_VectorConcatenate_i[4] = rtb_Add4_p;

          /* Trigonometry: '<S408>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S408>/Trigonometric Function'
           */
          A = arm_sin_f32(rtb_l1_a_cmd_j);

          /* Gain: '<S408>/Gain' incorporates:
           *  Trigonometry: '<S408>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -A;

          /* SignalConversion: '<S408>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S408>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S408>/Trigonometric Function' */
          rtb_VectorConcatenate_i[1] = A;

          /* Trigonometry: '<S408>/Trigonometric Function1' */
          rtb_VectorConcatenate_i[0] = rtb_Add4_p;

          /* Switch: '<S364>/Switch2' incorporates:
           *  Constant: '<S353>/Constant2'
           *  DiscreteIntegrator: '<S353>/Acceleration_Speed'
           *  RelationalOperator: '<S364>/LowerRelop1'
           *  RelationalOperator: '<S364>/UpperRelop'
           *  Switch: '<S364>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_a_a) {
            rtb_l1_a_cmd_j = rtb_a_a;
          } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
            /* Switch: '<S364>/Switch' incorporates:
             *  Constant: '<S353>/Constant2'
             */
            rtb_l1_a_cmd_j = 0.0F;
          } else {
            rtb_l1_a_cmd_j = FMS_DW.Acceleration_Speed_DSTATE_j;
          }

          /* End of Switch: '<S364>/Switch2' */

          /* Switch: '<S353>/Switch' */
          if (rtb_Sqrt_b > FMS_PARAM.L1) {
            rtb_Add4_p = rtb_a_a;
          } else {
            /* Gain: '<S353>/Gain' */
            rtb_Add4_p = 0.5F * rtb_Sqrt_b;

            /* Switch: '<S363>/Switch2' incorporates:
             *  Constant: '<S353>/Constant1'
             *  RelationalOperator: '<S363>/LowerRelop1'
             *  RelationalOperator: '<S363>/UpperRelop'
             *  Switch: '<S363>/Switch'
             */
            if (rtb_Add4_p > rtb_a_a) {
              rtb_Add4_p = rtb_a_a;
            } else {
              if (rtb_Add4_p < 0.5F) {
                /* Switch: '<S363>/Switch' incorporates:
                 *  Constant: '<S353>/Constant1'
                 */
                rtb_Add4_p = 0.5F;
              }
            }

            /* End of Switch: '<S363>/Switch2' */
          }

          /* End of Switch: '<S353>/Switch' */

          /* Switch: '<S353>/Switch1' incorporates:
           *  Sum: '<S353>/Sum1'
           */
          if (rtb_l1_a_cmd_j - rtb_Add4_p < 0.0F) {
            rtb_Add4_p = rtb_l1_a_cmd_j;
          }

          /* End of Switch: '<S353>/Switch1' */

          /* Sum: '<S406>/Sum of Elements' incorporates:
           *  Math: '<S406>/Math Function'
           */
          rtb_l1_a_cmd_j = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Add3_c * rtb_Add3_c;

          /* Math: '<S406>/Math Function1' incorporates:
           *  Sum: '<S406>/Sum of Elements'
           *
           * About '<S406>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_l1_a_cmd_j < 0.0F) {
            rtb_l1_a_cmd_j = -sqrtf(fabsf(rtb_l1_a_cmd_j));
          } else {
            rtb_l1_a_cmd_j = sqrtf(rtb_l1_a_cmd_j);
          }

          /* End of Math: '<S406>/Math Function1' */

          /* Switch: '<S406>/Switch' incorporates:
           *  Constant: '<S406>/Constant'
           *  Product: '<S406>/Product'
           */
          if (rtb_l1_a_cmd_j <= 0.0F) {
            rtb_Subtract3_d5 = 0.0F;
            rtb_Add3_c = 0.0F;
            rtb_l1_a_cmd_j = 1.0F;
          }

          /* End of Switch: '<S406>/Switch' */

          /* Product: '<S404>/Multiply2' incorporates:
           *  Product: '<S406>/Divide'
           */
          rtb_Subtract3_d5 = rtb_Subtract3_d5 / rtb_l1_a_cmd_j * rtb_Add4_p;
          rtb_Add4_p *= rtb_Add3_c / rtb_l1_a_cmd_j;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S359>/Sum1' incorporates:
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_l1_a_cmd_j = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S359>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          A = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sqrt_b = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S359>/Divide' incorporates:
           *  Math: '<S360>/Square'
           *  Math: '<S361>/Square'
           *  Sqrt: '<S360>/Sqrt'
           *  Sqrt: '<S361>/Sqrt'
           *  Sum: '<S359>/Sum'
           *  Sum: '<S359>/Sum1'
           *  Sum: '<S360>/Sum of Elements'
           *  Sum: '<S361>/Sum of Elements'
           */
          rtb_l1_a_cmd_j = sqrtf(A * A + rtb_Sqrt_b * rtb_Sqrt_b) / sqrtf
            (rtb_Add3_c * rtb_Add3_c + rtb_l1_a_cmd_j * rtb_l1_a_cmd_j);

          /* Saturate: '<S359>/Saturation' */
          if (rtb_l1_a_cmd_j > 1.0F) {
            rtb_l1_a_cmd_j = 1.0F;
          } else {
            if (rtb_l1_a_cmd_j < 0.0F) {
              rtb_l1_a_cmd_j = 0.0F;
            }
          }

          /* End of Saturate: '<S359>/Saturation' */

          /* Product: '<S357>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add4_p +
              rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_Subtract3_d5;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S350>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S359>/Multiply'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S350>/Sum2'
           *  Sum: '<S359>/Add'
           *  Sum: '<S359>/Subtract'
           */
          rtb_Subtract3_d5 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_l1_a_cmd_j +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_VectorConcatenate_ar[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_VectorConcatenate_ar[1];

          /* Saturate: '<S350>/Saturation1' incorporates:
           *  Product: '<S357>/Multiply'
           */
          if (rtb_Subtract3_d5 > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Subtract3_d5 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Subtract3_d5;
          }

          /* End of Saturate: '<S350>/Saturation1' */
        }

        /* End of Switch: '<S333>/Switch' */

        /* Delay: '<S335>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S338>/Integrator1' incorporates:
         *  Delay: '<S335>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S342>/Rem' incorporates:
         *  Constant: '<S342>/Constant1'
         *  DiscreteIntegrator: '<S338>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S337>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S342>/Switch' incorporates:
         *  Abs: '<S342>/Abs'
         *  Constant: '<S342>/Constant'
         *  Constant: '<S343>/Constant'
         *  Product: '<S342>/Multiply'
         *  RelationalOperator: '<S343>/Compare'
         *  Sum: '<S342>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S342>/Sign' */
          if (B < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S342>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S342>/Switch' */

        /* Gain: '<S337>/Gain2' */
        B *= FMS_PARAM.YAW_P;

        /* Saturate: '<S337>/Saturation' */
        if (B > FMS_PARAM.YAW_RATE_LIM) {
          B = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (B < -FMS_PARAM.YAW_RATE_LIM) {
            B = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S337>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S282>/Bus Assignment1'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S282>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S282>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S399>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S399>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S397>/Sum of Elements'
         */
        rtb_l1_a_cmd_j = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S399>/Math Function1' incorporates:
         *  Sum: '<S399>/Sum of Elements'
         *
         * About '<S399>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_l1_a_cmd_j < 0.0F) {
          B = -sqrtf(fabsf(rtb_l1_a_cmd_j));
        } else {
          B = sqrtf(rtb_l1_a_cmd_j);
        }

        /* End of Math: '<S399>/Math Function1' */

        /* Switch: '<S399>/Switch' incorporates:
         *  Constant: '<S399>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S399>/Product'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (B > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMath_c[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[2] = B;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S399>/Switch' */

        /* Delay: '<S334>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_px[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_px[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S282>/Sum' incorporates:
         *  Delay: '<S334>/Delay'
         *  MATLAB Function: '<S355>/OutRegionRegWP'
         *  MATLAB Function: '<S355>/SearchL1RefWP'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_a_c_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_px[0];
        rtb_Rem_n = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_px[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S349>/Sum of Elements' incorporates:
         *  Math: '<S349>/Math Function'
         *  Sum: '<S282>/Sum'
         */
        rtb_Rem_p = rtb_Rem_n * rtb_Rem_n + rtb_a_c_idx_0 * rtb_a_c_idx_0;

        /* Math: '<S349>/Math Function1' incorporates:
         *  Sum: '<S349>/Sum of Elements'
         *
         * About '<S349>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S349>/Math Function1' */

        /* Switch: '<S349>/Switch' incorporates:
         *  Constant: '<S349>/Constant'
         *  Product: '<S349>/Product'
         *  Sum: '<S282>/Sum'
         */
        if (B > 0.0F) {
          rtb_Subtract3_d5 = rtb_Rem_n;
          rtb_Add4_p = rtb_a_c_idx_0;
          rtb_MathFunction_f_idx_2 = B;
        } else {
          rtb_Subtract3_d5 = 0.0F;
          rtb_Add4_p = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S349>/Switch' */

        /* Product: '<S399>/Divide' */
        rtb_Subtract3_lb[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Subtract3_lb[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S402>/Sum of Elements' incorporates:
         *  Math: '<S402>/Math Function'
         *  SignalConversion: '<S402>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = rtb_Subtract3_lb[1] * rtb_Subtract3_lb[1] +
          rtb_Subtract3_lb[0] * rtb_Subtract3_lb[0];

        /* Math: '<S402>/Math Function1' incorporates:
         *  Sum: '<S402>/Sum of Elements'
         *
         * About '<S402>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S402>/Math Function1' */

        /* Switch: '<S402>/Switch' incorporates:
         *  Constant: '<S402>/Constant'
         *  Product: '<S402>/Product'
         */
        if (B > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Subtract3_lb[1];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Subtract3_lb[0];
          rtb_TmpSignalConversionAtMath_c[2] = B;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S402>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S355>/NearbyRefWP' incorporates:
         *  Constant: '<S282>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_dw[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Subtract3_lb, &rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* MATLAB Function: '<S355>/SearchL1RefWP' incorporates:
         *  Constant: '<S282>/L1'
         *  Delay: '<S334>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        A = rtb_a_c_idx_0 * rtb_a_c_idx_0 + rtb_Rem_n * rtb_Rem_n;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        B = (rtb_a_c_idx_0 * (FMS_DW.Delay_DSTATE_px[0] - FMS_U.INS_Out.x_R) +
             rtb_Rem_n * (FMS_DW.Delay_DSTATE_px[1] - FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_px[0] * FMS_DW.Delay_DSTATE_px[0]) +
                       FMS_DW.Delay_DSTATE_px[1] * FMS_DW.Delay_DSTATE_px[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_px[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_px[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_Sqrt_b = 0.0F;
        rtb_Sign1_c_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          A = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, A);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((A >= 0.0F) && (A <= 1.0F)) {
              rtb_Add3_c = A;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_Sqrt_b = rtb_a_c_idx_0 * rtb_Add3_c + FMS_DW.Delay_DSTATE_px[0];
          rtb_Sign1_c_idx_1 = rtb_Rem_n * rtb_Add3_c + FMS_DW.Delay_DSTATE_px[1];
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S355>/OutRegionRegWP' incorporates:
         *  Delay: '<S334>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        A = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_px[1]) * rtb_Rem_n +
             (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE_px[0]) * rtb_a_c_idx_0) /
          (rtb_a_c_idx_0 * rtb_a_c_idx_0 + rtb_Rem_n * rtb_Rem_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (A <= 0.0F);
        rtb_LogicalOperator_e = (A >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          B = FMS_DW.Delay_DSTATE_px[0];
        } else if (rtb_LogicalOperator_e) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          B = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          B = A * rtb_a_c_idx_0 + FMS_DW.Delay_DSTATE_px[0];
        }

        /* Switch: '<S355>/Switch1' incorporates:
         *  Constant: '<S392>/Constant'
         *  RelationalOperator: '<S392>/Compare'
         */
        if (rtb_Rem_p <= 0.0F) {
          /* Switch: '<S355>/Switch' incorporates:
           *  Constant: '<S391>/Constant'
           *  MATLAB Function: '<S355>/SearchL1RefWP'
           *  RelationalOperator: '<S391>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Subtract3_lb[0] = rtb_Sqrt_b;
            rtb_Subtract3_lb[1] = rtb_Sign1_c_idx_1;
          } else {
            rtb_Subtract3_lb[0] = B;

            /* MATLAB Function: '<S355>/OutRegionRegWP' incorporates:
             *  Delay: '<S334>/Delay'
             *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Subtract3_lb[1] = FMS_DW.Delay_DSTATE_px[1];
            } else if (rtb_LogicalOperator_e) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Subtract3_lb[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              rtb_Subtract3_lb[1] = A * rtb_Rem_n + FMS_DW.Delay_DSTATE_px[1];
            }
          }

          /* End of Switch: '<S355>/Switch' */
        }

        /* End of Switch: '<S355>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S356>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        A = rtb_Subtract3_lb[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Subtract3_lb[0] = A;
        rtb_Add3_c = A * A;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S356>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S400>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        A = rtb_Subtract3_lb[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S400>/Math Function' incorporates:
         *  Math: '<S398>/Square'
         */
        rtb_Rem_p = A * A;

        /* Sum: '<S400>/Sum of Elements' incorporates:
         *  Math: '<S400>/Math Function'
         */
        rtb_Add3_c += rtb_Rem_p;

        /* Math: '<S400>/Math Function1' incorporates:
         *  Sum: '<S400>/Sum of Elements'
         *
         * About '<S400>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          B = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S400>/Math Function1' */

        /* Switch: '<S400>/Switch' incorporates:
         *  Constant: '<S400>/Constant'
         *  Product: '<S400>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_dw[0] = rtb_Subtract3_lb[0];
          rtb_Switch_dw[1] = A;
          rtb_Switch_dw[2] = B;
        } else {
          rtb_Switch_dw[0] = 0.0F;
          rtb_Switch_dw[1] = 0.0F;
          rtb_Switch_dw[2] = 1.0F;
        }

        /* End of Switch: '<S400>/Switch' */

        /* Product: '<S400>/Divide' */
        rtb_a_c_idx_0 = rtb_Switch_dw[0] / rtb_Switch_dw[2];
        D = rtb_Switch_dw[1] / rtb_Switch_dw[2];

        /* Sum: '<S403>/Sum of Elements' incorporates:
         *  Math: '<S403>/Math Function'
         *  SignalConversion: '<S403>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Add3_c = D * D + rtb_a_c_idx_0 * rtb_a_c_idx_0;

        /* Math: '<S403>/Math Function1' incorporates:
         *  Sum: '<S403>/Sum of Elements'
         *
         * About '<S403>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Add3_c < 0.0F) {
          B = -sqrtf(fabsf(rtb_Add3_c));
        } else {
          B = sqrtf(rtb_Add3_c);
        }

        /* End of Math: '<S403>/Math Function1' */

        /* Switch: '<S403>/Switch' incorporates:
         *  Constant: '<S403>/Constant'
         *  Product: '<S403>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_dw[0] = D;
          rtb_Switch_dw[1] = rtb_a_c_idx_0;
          rtb_Switch_dw[2] = B;
        } else {
          rtb_Switch_dw[0] = 0.0F;
          rtb_Switch_dw[1] = 0.0F;
          rtb_Switch_dw[2] = 1.0F;
        }

        /* End of Switch: '<S403>/Switch' */

        /* Product: '<S403>/Divide' */
        rtb_a_c_idx_0 = rtb_Switch_dw[0] / rtb_Switch_dw[2];

        /* Math: '<S398>/Square' */
        rtb_Add3_c = rtb_Subtract3_lb[0] * rtb_Subtract3_lb[0];

        /* Product: '<S349>/Divide' */
        rtb_Sqrt_b = rtb_Subtract3_d5 / rtb_MathFunction_f_idx_2;
        rtb_Subtract3_lb[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S403>/Divide' incorporates:
         *  Product: '<S402>/Divide'
         */
        D = rtb_Switch_dw[1] / rtb_Switch_dw[2];

        /* Product: '<S402>/Divide' */
        A = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S349>/Divide' */
        rtb_Sign1_c_idx_1 = rtb_Add4_p / rtb_MathFunction_f_idx_2;

        /* Sqrt: '<S397>/Sqrt' */
        B = sqrtf(rtb_l1_a_cmd_j);

        /* Gain: '<S356>/Gain' incorporates:
         *  Math: '<S356>/Square'
         */
        rtb_Subtract3_d5 = B * B * 2.0F;

        /* Sum: '<S401>/Subtract' incorporates:
         *  Product: '<S401>/Multiply'
         *  Product: '<S401>/Multiply1'
         */
        B = rtb_a_c_idx_0 * A - D * rtb_Subtract3_lb[0];

        /* Signum: '<S396>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S396>/Sign1' */

        /* Switch: '<S396>/Switch2' incorporates:
         *  Constant: '<S396>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S396>/Switch2' */

        /* DotProduct: '<S396>/Dot Product' */
        A = rtb_Subtract3_lb[0] * rtb_a_c_idx_0 + A * D;

        /* Trigonometry: '<S396>/Acos' incorporates:
         *  DotProduct: '<S396>/Dot Product'
         */
        if (A > 1.0F) {
          A = 1.0F;
        } else {
          if (A < -1.0F) {
            A = -1.0F;
          }
        }

        /* Product: '<S396>/Multiply' incorporates:
         *  Trigonometry: '<S396>/Acos'
         */
        B *= acosf(A);

        /* Saturate: '<S356>/Saturation' */
        if (B > 1.57079637F) {
          B = 1.57079637F;
        } else {
          if (B < -1.57079637F) {
            B = -1.57079637F;
          }
        }

        /* End of Saturate: '<S356>/Saturation' */

        /* Product: '<S356>/Divide' incorporates:
         *  Constant: '<S282>/L1'
         *  Constant: '<S356>/Constant'
         *  MinMax: '<S356>/Max'
         *  MinMax: '<S356>/Min'
         *  Product: '<S356>/Multiply1'
         *  Sqrt: '<S398>/Sqrt'
         *  Sum: '<S398>/Sum of Elements'
         *  Trigonometry: '<S356>/Sin'
         */
        rtb_l1_a_cmd_j = arm_sin_f32(B) * rtb_Subtract3_d5 / fminf(FMS_PARAM.L1,
          fmaxf(sqrtf(rtb_Rem_p + rtb_Add3_c), 0.5F));

        /* Sum: '<S347>/Subtract' incorporates:
         *  Product: '<S347>/Multiply'
         *  Product: '<S347>/Multiply1'
         */
        rtb_MathFunction_f_idx_2 = rtb_Sqrt_b * FMS_ConstB.Divide_d[1] -
          rtb_Sign1_c_idx_1 * FMS_ConstB.Divide_d[0];

        /* Signum: '<S336>/Sign1' */
        if (rtb_MathFunction_f_idx_2 < 0.0F) {
          rtb_MathFunction_f_idx_2 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_2 > 0.0F) {
            rtb_MathFunction_f_idx_2 = 1.0F;
          }
        }

        /* End of Signum: '<S336>/Sign1' */

        /* Switch: '<S336>/Switch2' incorporates:
         *  Constant: '<S336>/Constant4'
         */
        if (rtb_MathFunction_f_idx_2 == 0.0F) {
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S336>/Switch2' */

        /* DotProduct: '<S336>/Dot Product' */
        rtb_Subtract3_d5 = FMS_ConstB.Divide_d[0] * rtb_Sqrt_b +
          FMS_ConstB.Divide_d[1] * rtb_Sign1_c_idx_1;

        /* Trigonometry: '<S336>/Acos' incorporates:
         *  DotProduct: '<S336>/Dot Product'
         */
        if (rtb_Subtract3_d5 > 1.0F) {
          rtb_Subtract3_d5 = 1.0F;
        } else {
          if (rtb_Subtract3_d5 < -1.0F) {
            rtb_Subtract3_d5 = -1.0F;
          }
        }

        /* Product: '<S336>/Multiply' incorporates:
         *  Trigonometry: '<S336>/Acos'
         */
        rtb_MathFunction_f_idx_2 *= acosf(rtb_Subtract3_d5);

        /* Math: '<S339>/Rem' incorporates:
         *  Constant: '<S339>/Constant1'
         *  Delay: '<S335>/Delay'
         *  Sum: '<S335>/Sum2'
         */
        B = rt_remf(rtb_MathFunction_f_idx_2 - FMS_DW.Delay_DSTATE_a,
                    6.28318548F);

        /* Switch: '<S339>/Switch' incorporates:
         *  Abs: '<S339>/Abs'
         *  Constant: '<S339>/Constant'
         *  Constant: '<S345>/Constant'
         *  Product: '<S339>/Multiply'
         *  RelationalOperator: '<S345>/Compare'
         *  Sum: '<S339>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S339>/Sign' */
          if (B < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (B > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = B;
          }

          /* End of Signum: '<S339>/Sign' */
          B -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S339>/Switch' */

        /* Sum: '<S335>/Sum' incorporates:
         *  Delay: '<S335>/Delay'
         */
        rtb_Add3_c = B + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S344>/Multiply1' incorporates:
         *  Constant: '<S344>/const1'
         *  DiscreteIntegrator: '<S338>/Integrator'
         */
        B = FMS_DW.Integrator_DSTATE_b * 0.785398185F;

        /* Sum: '<S344>/Add' incorporates:
         *  DiscreteIntegrator: '<S338>/Integrator1'
         *  Sum: '<S338>/Subtract'
         */
        rtb_Subtract3_d5 = (FMS_DW.Integrator1_DSTATE_e - rtb_Add3_c) + B;

        /* Signum: '<S344>/Sign' */
        if (rtb_Subtract3_d5 < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Subtract3_d5 > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Subtract3_d5;
        }

        /* End of Signum: '<S344>/Sign' */

        /* Sum: '<S344>/Add2' incorporates:
         *  Abs: '<S344>/Abs'
         *  Gain: '<S344>/Gain'
         *  Gain: '<S344>/Gain1'
         *  Product: '<S344>/Multiply2'
         *  Product: '<S344>/Multiply3'
         *  Sqrt: '<S344>/Sqrt'
         *  Sum: '<S344>/Add1'
         *  Sum: '<S344>/Subtract'
         */
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Subtract3_d5) + FMS_ConstB.d_l) *
                           FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Add3_c
          + B;

        /* Sum: '<S344>/Add4' */
        rtb_Add4_p = (rtb_Subtract3_d5 - rtb_Rem_p) + B;

        /* Sum: '<S344>/Add3' */
        rtb_Add3_c = rtb_Subtract3_d5 + FMS_ConstB.d_l;

        /* Sum: '<S344>/Subtract1' */
        rtb_Subtract3_d5 -= FMS_ConstB.d_l;

        /* Signum: '<S344>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S344>/Sign1' */

        /* Signum: '<S344>/Sign2' */
        if (rtb_Subtract3_d5 < 0.0F) {
          rtb_Subtract3_d5 = -1.0F;
        } else {
          if (rtb_Subtract3_d5 > 0.0F) {
            rtb_Subtract3_d5 = 1.0F;
          }
        }

        /* End of Signum: '<S344>/Sign2' */

        /* Sum: '<S344>/Add5' incorporates:
         *  Gain: '<S344>/Gain2'
         *  Product: '<S344>/Multiply4'
         *  Sum: '<S344>/Subtract2'
         */
        rtb_Rem_p += (rtb_Add3_c - rtb_Subtract3_d5) * 0.5F * rtb_Add4_p;

        /* Sum: '<S344>/Add6' */
        rtb_Add3_c = rtb_Rem_p + FMS_ConstB.d_l;

        /* Sum: '<S344>/Subtract3' */
        A = rtb_Rem_p - FMS_ConstB.d_l;

        /* Product: '<S344>/Divide' */
        rtb_Sqrt_b = rtb_Rem_p / FMS_ConstB.d_l;

        /* Signum: '<S344>/Sign5' incorporates:
         *  Signum: '<S344>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Sign1_c_idx_1 = -1.0F;

          /* Signum: '<S344>/Sign6' */
          rtb_Add4_p = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_Sign1_c_idx_1 = 1.0F;

          /* Signum: '<S344>/Sign6' */
          rtb_Add4_p = 1.0F;
        } else {
          rtb_Sign1_c_idx_1 = rtb_Rem_p;

          /* Signum: '<S344>/Sign6' */
          rtb_Add4_p = rtb_Rem_p;
        }

        /* End of Signum: '<S344>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S335>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_MathFunction_f_idx_2 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S340>/Rem' incorporates:
         *  Constant: '<S340>/Constant1'
         */
        rtb_Rem_p = rt_remf(rtb_MathFunction_f_idx_2, 6.28318548F);

        /* Switch: '<S340>/Switch' incorporates:
         *  Abs: '<S340>/Abs'
         *  Constant: '<S340>/Constant'
         *  Constant: '<S346>/Constant'
         *  Product: '<S340>/Multiply'
         *  RelationalOperator: '<S346>/Compare'
         *  Sum: '<S340>/Add'
         */
        if (fabsf(rtb_Rem_p) > 3.14159274F) {
          /* Signum: '<S340>/Sign' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Subtract3_d5 = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Subtract3_d5 = 1.0F;
          } else {
            rtb_Subtract3_d5 = rtb_Rem_p;
          }

          /* End of Signum: '<S340>/Sign' */
          rtb_Rem_p -= 6.28318548F * rtb_Subtract3_d5;
        }

        /* End of Switch: '<S340>/Switch' */

        /* Abs: '<S333>/Abs' */
        rtb_Rem_p = fabsf(rtb_Rem_p);

        /* Update for Delay: '<S357>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S358>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S351>/Constant'
         *  RelationalOperator: '<S351>/Compare'
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

        /* End of Update for DiscreteIntegrator: '<S358>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S353>/Acceleration_Speed' incorporates:
         *  Constant: '<S353>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Product: '<S357>/Divide1' */
        rtb_Subtract3_d5 = rtb_l1_a_cmd_j / rtb_a_a;

        /* Saturate: '<S357>/Saturation' */
        if (rtb_Subtract3_d5 > 0.314159274F) {
          rtb_Subtract3_d5 = 0.314159274F;
        } else {
          if (rtb_Subtract3_d5 < -0.314159274F) {
            rtb_Subtract3_d5 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S357>/Saturation' */

        /* Update for DiscreteIntegrator: '<S405>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_Subtract3_d5;

        /* Update for Delay: '<S335>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S338>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S338>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Update for Delay: '<S334>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S344>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S344>/Sign3' */

        /* Signum: '<S344>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S344>/Sign4' */

        /* Update for DiscreteIntegrator: '<S338>/Integrator' incorporates:
         *  Constant: '<S344>/const'
         *  Gain: '<S344>/Gain3'
         *  Product: '<S344>/Multiply5'
         *  Product: '<S344>/Multiply6'
         *  Sum: '<S344>/Subtract4'
         *  Sum: '<S344>/Subtract5'
         *  Sum: '<S344>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Sqrt_b - rtb_Sign1_c_idx_1) *
          FMS_ConstB.Gain4_n * ((rtb_Add3_c - A) * 0.5F) - rtb_Add4_p *
          1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_b >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_b = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_b <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_b = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S338>/Integrator' */
        /* End of Outputs for SubSystem: '<S36>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S36>/Hold' incorporates:
           *  ActionPort: '<S280>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S36>/Switch Case' incorporates:
           *  Chart: '<S289>/Motion Status'
           *  Chart: '<S299>/Motion State'
           *  Chart: '<S311>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S36>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S36>/Hold' incorporates:
         *  ActionPort: '<S280>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S289>/Motion Status' incorporates:
         *  Abs: '<S289>/Abs'
         *  Constant: '<S289>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S299>/Motion State' incorporates:
         *  Abs: '<S299>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
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

        /* End of Chart: '<S299>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S311>/Motion State' incorporates:
         *  Constant: '<S311>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S311>/Square'
         *  Math: '<S311>/Square1'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sqrt: '<S311>/Sqrt'
         *  Sum: '<S311>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S310>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_pv;
        FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;
        switch (rtb_state_l) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_pv = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_pv = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_pv = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_pv) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pv != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S310>/Hold Control' incorporates:
             *  ActionPort: '<S313>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S310>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S310>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S310>/Hold Control' incorporates:
           *  ActionPort: '<S313>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S310>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S310>/Brake Control' incorporates:
           *  ActionPort: '<S312>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S310>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pv != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S310>/Move Control' incorporates:
             *  ActionPort: '<S314>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S310>/Switch Case' */
            FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S310>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S310>/Move Control' incorporates:
           *  ActionPort: '<S314>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_i(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S310>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S310>/Switch Case' */

        /* SwitchCase: '<S288>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S288>/Hold Control' incorporates:
             *  ActionPort: '<S291>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S288>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S288>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S288>/Hold Control' incorporates:
           *  ActionPort: '<S291>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S288>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S288>/Brake Control' incorporates:
           *  ActionPort: '<S290>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S288>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S288>/Move Control' incorporates:
             *  ActionPort: '<S292>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S288>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S288>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S288>/Move Control' incorporates:
           *  ActionPort: '<S292>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S288>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S288>/Switch Case' */

        /* SwitchCase: '<S298>/Switch Case' */
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
            /* InitializeConditions for IfAction SubSystem: '<S298>/Hold Control' incorporates:
             *  ActionPort: '<S301>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S298>/Switch Case' incorporates:
             *  Delay: '<S301>/Delay'
             */
            FMS_DW.icLoad_g = 1U;

            /* End of InitializeConditions for SubSystem: '<S298>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S298>/Hold Control' incorporates:
           *  ActionPort: '<S301>/Action Port'
           */
          /* Delay: '<S301>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          if (FMS_DW.icLoad_g != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_g = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S301>/Sum' incorporates:
           *  Delay: '<S301>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_Add3_c = FMS_DW.Delay_DSTATE_g - FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Abs: '<S304>/Abs' */
          rtb_a_a = fabsf(rtb_Add3_c);

          /* Switch: '<S304>/Switch' incorporates:
           *  Constant: '<S304>/Constant'
           *  Constant: '<S305>/Constant'
           *  Product: '<S304>/Multiply'
           *  RelationalOperator: '<S305>/Compare'
           *  Sum: '<S304>/Subtract'
           */
          if (rtb_a_a > 3.14159274F) {
            /* Signum: '<S304>/Sign' */
            if (rtb_Add3_c < 0.0F) {
              rtb_Add3_c = -1.0F;
            } else {
              if (rtb_Add3_c > 0.0F) {
                rtb_Add3_c = 1.0F;
              }
            }

            /* End of Signum: '<S304>/Sign' */
            rtb_Add3_c *= rtb_a_a - 6.28318548F;
          }

          /* End of Switch: '<S304>/Switch' */

          /* Gain: '<S301>/Gain2' */
          FMS_B.Merge_n1 = FMS_PARAM.YAW_P * rtb_Add3_c;

          /* Update for Delay: '<S301>/Delay' */
          FMS_DW.icLoad_g = 0U;

          /* End of Outputs for SubSystem: '<S298>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S298>/Brake Control' incorporates:
           *  ActionPort: '<S300>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S298>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S298>/Move Control' incorporates:
             *  ActionPort: '<S302>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S298>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S307>/Integrator'
             *  DiscreteIntegrator: '<S307>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_k = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S298>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S298>/Move Control' incorporates:
           *  ActionPort: '<S302>/Action Port'
           */
          /* Product: '<S308>/Multiply1' incorporates:
           *  Constant: '<S308>/const1'
           *  DiscreteIntegrator: '<S307>/Integrator'
           */
          rtb_Add3_c = FMS_DW.Integrator_DSTATE_h * 0.02F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S306>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_l1_a_cmd_j = 0.0F;
          } else {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S306>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S308>/Add' incorporates:
           *  DiscreteIntegrator: '<S307>/Integrator1'
           *  Gain: '<S302>/Gain1'
           *  Gain: '<S306>/Gain'
           *  Sum: '<S307>/Subtract'
           */
          rtb_Subtract3_d5 = (FMS_DW.Integrator1_DSTATE_k - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_l1_a_cmd_j * FMS_PARAM.YAW_RATE_LIM) +
            rtb_Add3_c;

          /* Signum: '<S308>/Sign' */
          if (rtb_Subtract3_d5 < 0.0F) {
            rtb_a_a = -1.0F;
          } else if (rtb_Subtract3_d5 > 0.0F) {
            rtb_a_a = 1.0F;
          } else {
            rtb_a_a = rtb_Subtract3_d5;
          }

          /* End of Signum: '<S308>/Sign' */

          /* Sum: '<S308>/Add2' incorporates:
           *  Abs: '<S308>/Abs'
           *  Gain: '<S308>/Gain'
           *  Gain: '<S308>/Gain1'
           *  Product: '<S308>/Multiply2'
           *  Product: '<S308>/Multiply3'
           *  Sqrt: '<S308>/Sqrt'
           *  Sum: '<S308>/Add1'
           *  Sum: '<S308>/Subtract'
           */
          rtb_a_a = (sqrtf((8.0F * fabsf(rtb_Subtract3_d5) + FMS_ConstB.d_j) *
                           FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_a_a +
            rtb_Add3_c;

          /* Sum: '<S308>/Add4' */
          rtb_Add4_p = (rtb_Subtract3_d5 - rtb_a_a) + rtb_Add3_c;

          /* Sum: '<S308>/Add3' */
          rtb_Add3_c = rtb_Subtract3_d5 + FMS_ConstB.d_j;

          /* Sum: '<S308>/Subtract1' */
          rtb_Subtract3_d5 -= FMS_ConstB.d_j;

          /* Signum: '<S308>/Sign1' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* End of Signum: '<S308>/Sign1' */

          /* Signum: '<S308>/Sign2' */
          if (rtb_Subtract3_d5 < 0.0F) {
            rtb_Subtract3_d5 = -1.0F;
          } else {
            if (rtb_Subtract3_d5 > 0.0F) {
              rtb_Subtract3_d5 = 1.0F;
            }
          }

          /* End of Signum: '<S308>/Sign2' */

          /* Sum: '<S308>/Add5' incorporates:
           *  Gain: '<S308>/Gain2'
           *  Product: '<S308>/Multiply4'
           *  Sum: '<S308>/Subtract2'
           */
          rtb_a_a += (rtb_Add3_c - rtb_Subtract3_d5) * 0.5F * rtb_Add4_p;

          /* SignalConversion: '<S302>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
           *  DiscreteIntegrator: '<S307>/Integrator1'
           */
          FMS_B.Merge_n1 = FMS_DW.Integrator1_DSTATE_k;

          /* Update for DiscreteIntegrator: '<S307>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S307>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_k += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Sum: '<S308>/Subtract3' */
          rtb_Add3_c = rtb_a_a - FMS_ConstB.d_j;

          /* Sum: '<S308>/Add6' */
          A = rtb_a_a + FMS_ConstB.d_j;

          /* Signum: '<S308>/Sign5' incorporates:
           *  Signum: '<S308>/Sign6'
           */
          if (rtb_a_a < 0.0F) {
            rtb_Add4_p = -1.0F;

            /* Signum: '<S308>/Sign6' */
            rtb_Sqrt_b = -1.0F;
          } else if (rtb_a_a > 0.0F) {
            rtb_Add4_p = 1.0F;

            /* Signum: '<S308>/Sign6' */
            rtb_Sqrt_b = 1.0F;
          } else {
            rtb_Add4_p = rtb_a_a;

            /* Signum: '<S308>/Sign6' */
            rtb_Sqrt_b = rtb_a_a;
          }

          /* End of Signum: '<S308>/Sign5' */

          /* Signum: '<S308>/Sign3' */
          if (A < 0.0F) {
            A = -1.0F;
          } else {
            if (A > 0.0F) {
              A = 1.0F;
            }
          }

          /* End of Signum: '<S308>/Sign3' */

          /* Signum: '<S308>/Sign4' */
          if (rtb_Add3_c < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else {
            if (rtb_Add3_c > 0.0F) {
              rtb_Add3_c = 1.0F;
            }
          }

          /* End of Signum: '<S308>/Sign4' */

          /* Update for DiscreteIntegrator: '<S307>/Integrator' incorporates:
           *  Constant: '<S308>/const'
           *  Gain: '<S308>/Gain3'
           *  Product: '<S308>/Divide'
           *  Product: '<S308>/Multiply5'
           *  Product: '<S308>/Multiply6'
           *  Sum: '<S308>/Subtract4'
           *  Sum: '<S308>/Subtract5'
           *  Sum: '<S308>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_a_a / FMS_ConstB.d_j - rtb_Add4_p)
            * FMS_ConstB.Gain4_c * ((A - rtb_Add3_c) * 0.5F) - rtb_Sqrt_b *
            15.707963F) * 0.004F;

          /* End of Outputs for SubSystem: '<S298>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S298>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S280>/Bus Assignment'
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S280>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S280>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S298>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S298>/Saturation' */

        /* Saturate: '<S310>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S310>/Saturation1' */

        /* Saturate: '<S288>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S280>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S288>/Saturation1' */
        /* End of Outputs for SubSystem: '<S36>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S36>/Unknown' incorporates:
         *  ActionPort: '<S284>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S36>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S36>/Switch Case' */
      /* End of Outputs for SubSystem: '<S29>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S29>/Auto' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* SwitchCase: '<S34>/Switch Case' incorporates:
       *  Math: '<S164>/Square'
       *  Math: '<S166>/Math Function'
       *  Sum: '<S122>/Subtract'
       *  Sum: '<S179>/Sum1'
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
        /* Disable for Resettable SubSystem: '<S93>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S144>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S134>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S93>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S34>/Offboard' incorporates:
         *  ActionPort: '<S94>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Gain: '<S258>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S261>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S262>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S262>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S262>/Multiply1' incorporates:
         *  Product: '<S262>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S262>/Divide' incorporates:
         *  Constant: '<S262>/Constant'
         *  Constant: '<S262>/R'
         *  Sqrt: '<S262>/Sqrt'
         *  Sum: '<S262>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S262>/Product3' incorporates:
         *  Constant: '<S262>/Constant1'
         *  Product: '<S262>/Multiply1'
         *  Sum: '<S262>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S262>/Multiply2' incorporates:
         *  Trigonometry: '<S262>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S261>/Sum' incorporates:
         *  Gain: '<S258>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S266>/Abs' incorporates:
         *  Abs: '<S269>/Abs1'
         *  Switch: '<S266>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S266>/Switch1' incorporates:
         *  Abs: '<S266>/Abs'
         *  Bias: '<S266>/Bias2'
         *  Bias: '<S266>/Bias3'
         *  Constant: '<S263>/Constant'
         *  Constant: '<S263>/Constant1'
         *  Constant: '<S268>/Constant'
         *  Gain: '<S266>/Gain1'
         *  Product: '<S266>/Multiply'
         *  RelationalOperator: '<S268>/Compare'
         *  Switch: '<S263>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S269>/Switch1' incorporates:
           *  Bias: '<S269>/Bias2'
           *  Bias: '<S269>/Bias3'
           *  Constant: '<S269>/Constant'
           *  Constant: '<S270>/Constant'
           *  Math: '<S269>/Math Function'
           *  RelationalOperator: '<S270>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S269>/Switch1' */

          /* Signum: '<S266>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S266>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S263>/Sum' incorporates:
         *  Gain: '<S258>/Gain1'
         *  Gain: '<S258>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S261>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Product: '<S261>/Multiply' incorporates:
         *  Gain: '<S261>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S265>/Switch1' incorporates:
         *  Abs: '<S265>/Abs1'
         *  Bias: '<S265>/Bias2'
         *  Bias: '<S265>/Bias3'
         *  Constant: '<S265>/Constant'
         *  Constant: '<S267>/Constant'
         *  Math: '<S265>/Math Function'
         *  RelationalOperator: '<S267>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S265>/Switch1' */

        /* Product: '<S261>/Multiply' incorporates:
         *  Gain: '<S261>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S239>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S243>/Multiply1'
         *  Product: '<S244>/Multiply3'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S252>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S252>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S252>/Trigonometric Function3' incorporates:
           *  Gain: '<S251>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S252>/Gain' incorporates:
           *  Gain: '<S251>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Trigonometry: '<S252>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S252>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S252>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S252>/Trigonometric Function' incorporates:
           *  Gain: '<S251>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S252>/Trigonometric Function1' incorporates:
           *  Gain: '<S251>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S252>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S243>/Saturation' incorporates:
           *  Constant: '<S249>/Constant'
           *  Constant: '<S250>/Constant'
           *  Constant: '<S260>/Constant'
           *  DataTypeConversion: '<S258>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S242>/Logical Operator'
           *  Product: '<S243>/Multiply'
           *  Product: '<S264>/Multiply1'
           *  Product: '<S264>/Multiply2'
           *  RelationalOperator: '<S249>/Compare'
           *  RelationalOperator: '<S250>/Compare'
           *  RelationalOperator: '<S260>/Compare'
           *  S-Function (sfix_bitop): '<S242>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S257>/lat_cmd valid'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S243>/Sum1'
           *  Sum: '<S264>/Sum2'
           *  Switch: '<S245>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_l1_a_cmd_j = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_l1_a_cmd_j = FMS_U.Auto_Cmd.x_cmd;
          }

          rtb_Subtract3_d5 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_l1_a_cmd_j -
            FMS_U.INS_Out.x_R : 0.0F;
          if (rtb_Subtract3_d5 > 4.0F) {
            rtb_Subtract3_d5 = 4.0F;
          } else {
            if (rtb_Subtract3_d5 < -4.0F) {
              rtb_Subtract3_d5 = -4.0F;
            }
          }

          /* SignalConversion: '<S252>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S243>/Saturation' incorporates:
           *  Constant: '<S249>/Constant'
           *  Constant: '<S250>/Constant'
           *  Constant: '<S260>/Constant'
           *  DataTypeConversion: '<S258>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S242>/Logical Operator'
           *  Product: '<S243>/Multiply'
           *  Product: '<S264>/Multiply3'
           *  Product: '<S264>/Multiply4'
           *  RelationalOperator: '<S249>/Compare'
           *  RelationalOperator: '<S250>/Compare'
           *  RelationalOperator: '<S260>/Compare'
           *  S-Function (sfix_bitop): '<S242>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S257>/lon_cmd valid'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S243>/Sum1'
           *  Sum: '<S264>/Sum3'
           *  Switch: '<S245>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_l1_a_cmd_j = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_l1_a_cmd_j = FMS_U.Auto_Cmd.y_cmd;
          }

          rtb_Add3_c = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_l1_a_cmd_j -
            FMS_U.INS_Out.y_R : 0.0F;
          if (rtb_Add3_c > 4.0F) {
            rtb_Add3_c = 4.0F;
          } else {
            if (rtb_Add3_c < -4.0F) {
              rtb_Add3_c = -4.0F;
            }
          }

          /* SignalConversion: '<S252>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S243>/Saturation' incorporates:
           *  Constant: '<S249>/Constant'
           *  Constant: '<S250>/Constant'
           *  Constant: '<S260>/Constant'
           *  DataTypeConversion: '<S258>/Data Type Conversion'
           *  DataTypeConversion: '<S258>/Data Type Conversion1'
           *  Gain: '<S246>/Gain'
           *  Gain: '<S258>/Gain2'
           *  Gain: '<S261>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S242>/Logical Operator'
           *  Product: '<S243>/Multiply'
           *  RelationalOperator: '<S249>/Compare'
           *  RelationalOperator: '<S250>/Compare'
           *  RelationalOperator: '<S260>/Compare'
           *  S-Function (sfix_bitop): '<S242>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S257>/alt_cmd valid'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S243>/Sum1'
           *  Sum: '<S261>/Sum1'
           *  Switch: '<S245>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_l1_a_cmd_j = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_l1_a_cmd_j = FMS_U.Auto_Cmd.z_cmd;
          }

          rtb_a_a = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_l1_a_cmd_j -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          if (rtb_a_a > 2.0F) {
            rtb_a_a = 2.0F;
          } else {
            if (rtb_a_a < -2.0F) {
              rtb_a_a = -2.0F;
            }
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Switch_dw[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_a_a +
              (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add3_c +
               rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_Subtract3_d5);
          }

          /* SignalConversion: '<S186>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S186>/Constant4'
           *  MultiPortSwitch: '<S176>/Index Vector'
           *  Product: '<S243>/Multiply1'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S186>/Trigonometric Function3' incorporates:
           *  Gain: '<S185>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S176>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S186>/Gain' incorporates:
           *  Gain: '<S185>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S176>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Trigonometry: '<S186>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S186>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S186>/Constant3'
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S186>/Trigonometric Function' incorporates:
           *  Gain: '<S185>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S176>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S186>/Trigonometric Function1' incorporates:
           *  Gain: '<S185>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S176>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S186>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S176>/Multiply' incorporates:
           *  Constant: '<S184>/Constant'
           *  RelationalOperator: '<S184>/Compare'
           *  S-Function (sfix_bitop): '<S181>/ax_cmd valid'
           */
          rtb_a_a = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S186>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S176>/Multiply' incorporates:
           *  Constant: '<S184>/Constant'
           *  RelationalOperator: '<S184>/Compare'
           *  S-Function (sfix_bitop): '<S181>/ay_cmd valid'
           */
          rtb_l1_a_cmd_j = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S186>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S176>/Multiply' incorporates:
           *  Constant: '<S184>/Constant'
           *  RelationalOperator: '<S184>/Compare'
           *  S-Function (sfix_bitop): '<S181>/az_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S176>/Index Vector' incorporates:
           *  Product: '<S182>/Multiply'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_l1_a_cmd_j +
               rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_a);
          }
          break;

         case 1:
          /* SignalConversion: '<S256>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S256>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Gain: '<S254>/Gain' incorporates:
           *  Gain: '<S187>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S176>/Index Vector'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S244>/Subtract'
           */
          rtb_Add3_c = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S256>/Trigonometric Function3' incorporates:
           *  Gain: '<S254>/Gain'
           *  Trigonometry: '<S256>/Trigonometric Function1'
           */
          rtb_Add4_p = arm_cos_f32(rtb_Add3_c);
          rtb_VectorConcatenate_i[4] = rtb_Add4_p;

          /* Trigonometry: '<S256>/Trigonometric Function2' incorporates:
           *  Gain: '<S254>/Gain'
           *  Trigonometry: '<S256>/Trigonometric Function'
           */
          A = arm_sin_f32(rtb_Add3_c);

          /* Gain: '<S256>/Gain' incorporates:
           *  Trigonometry: '<S256>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -A;

          /* SignalConversion: '<S256>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S256>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S256>/Trigonometric Function' */
          rtb_VectorConcatenate_i[1] = A;

          /* Trigonometry: '<S256>/Trigonometric Function1' */
          rtb_VectorConcatenate_i[0] = rtb_Add4_p;

          /* SignalConversion: '<S256>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_e0[0];

          /* SignalConversion: '<S255>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_k[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S256>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_e0[1];

          /* SignalConversion: '<S255>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_k[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S256>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_e0[2];

          /* SignalConversion: '<S255>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_k[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S255>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S255>/Constant4'
           */
          rtb_VectorConcatenate_k[5] = 0.0F;

          /* Trigonometry: '<S255>/Trigonometric Function3' incorporates:
           *  Gain: '<S253>/Gain'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S255>/Trigonometric Function1'
           */
          rtb_a_a = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
          rtb_VectorConcatenate_k[4] = rtb_a_a;

          /* Trigonometry: '<S255>/Trigonometric Function2' incorporates:
           *  Gain: '<S253>/Gain'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S255>/Trigonometric Function'
           */
          rtb_Subtract3_d5 = arm_sin_f32(-FMS_B.Cmd_In.offboard_psi_0);

          /* Gain: '<S255>/Gain' incorporates:
           *  Trigonometry: '<S255>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_k[3] = -rtb_Subtract3_d5;

          /* SignalConversion: '<S255>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S255>/Constant3'
           */
          rtb_VectorConcatenate_k[2] = 0.0F;

          /* Trigonometry: '<S255>/Trigonometric Function' */
          rtb_VectorConcatenate_k[1] = rtb_Subtract3_d5;

          /* Trigonometry: '<S255>/Trigonometric Function1' */
          rtb_VectorConcatenate_k[0] = rtb_a_a;

          /* RelationalOperator: '<S260>/Compare' incorporates:
           *  Constant: '<S260>/Constant'
           *  S-Function (sfix_bitop): '<S257>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S257>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S257>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S258>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S258>/Data Type Conversion'
           *  Gain: '<S258>/Gain2'
           *  Gain: '<S261>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S264>/Multiply1'
           *  Product: '<S264>/Multiply2'
           *  Product: '<S264>/Multiply3'
           *  Product: '<S264>/Multiply4'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S261>/Sum1'
           *  Sum: '<S264>/Sum2'
           *  Sum: '<S264>/Sum3'
           */
          rtb_VectorConcatenate_ar[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_VectorConcatenate_ar[1] = (real32_T)(rtb_Gain *
            FMS_ConstB.SinCos_o2 - rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_VectorConcatenate_ar[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S245>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S249>/Compare' incorporates:
           *  Constant: '<S249>/Constant'
           *  S-Function (sfix_bitop): '<S242>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S250>/Compare' incorporates:
           *  Constant: '<S250>/Constant'
           *  S-Function (sfix_bitop): '<S242>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S244>/Sum2' incorporates:
             *  Product: '<S244>/Multiply2'
             *  Switch: '<S245>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_l1_a_cmd_j = rtb_VectorConcatenate_ar[rtb_Compare_bv_0];
            } else {
              rtb_l1_a_cmd_j = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S244>/Saturation1' incorporates:
             *  Gain: '<S246>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S242>/Logical Operator'
             *  Product: '<S244>/Multiply'
             *  Product: '<S244>/Multiply2'
             *  SignalConversion: '<S28>/Signal Copy1'
             *  Sum: '<S244>/Sum2'
             */
            rtb_Subtract3_d5 = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0]
              ? rtb_l1_a_cmd_j - ((rtb_VectorConcatenate_k[rtb_Compare_bv_0 + 3]
              * FMS_U.INS_Out.y_R + rtb_VectorConcatenate_k[rtb_Compare_bv_0] *
              FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_k[rtb_Compare_bv_0 + 6]
                                  * -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Subtract3_d5 > FMS_ConstP.pooled22[rtb_Compare_bv_0]) {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
                FMS_ConstP.pooled22[rtb_Compare_bv_0];
            } else if (rtb_Subtract3_d5 < FMS_ConstP.pooled23[rtb_Compare_bv_0])
            {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else {
              rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
                rtb_Subtract3_d5;
            }

            /* End of Saturate: '<S244>/Saturation1' */
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Switch_dw[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] *
              rtb_TmpSignalConversionAtMath_c[2] +
              (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] *
               rtb_TmpSignalConversionAtMath_c[1] +
               rtb_VectorConcatenate_i[rtb_Compare_bv_0] *
               rtb_TmpSignalConversionAtMath_c[0]);
          }

          /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S188>/Constant4'
           *  MultiPortSwitch: '<S176>/Index Vector'
           *  Product: '<S244>/Multiply3'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S188>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(rtb_Add3_c);

          /* Gain: '<S188>/Gain' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           *  Trigonometry: '<S188>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(rtb_Add3_c);

          /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S188>/Constant3'
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S188>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(rtb_Add3_c);

          /* Trigonometry: '<S188>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(rtb_Add3_c);

          /* SignalConversion: '<S188>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S176>/Multiply' incorporates:
           *  Constant: '<S184>/Constant'
           *  RelationalOperator: '<S184>/Compare'
           *  S-Function (sfix_bitop): '<S181>/ax_cmd valid'
           */
          rtb_a_a = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S188>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S176>/Multiply' incorporates:
           *  Constant: '<S184>/Constant'
           *  RelationalOperator: '<S184>/Compare'
           *  S-Function (sfix_bitop): '<S181>/ay_cmd valid'
           */
          rtb_l1_a_cmd_j = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S188>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S176>/Index Vector'
           */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S176>/Multiply' incorporates:
           *  Constant: '<S184>/Constant'
           *  RelationalOperator: '<S184>/Compare'
           *  S-Function (sfix_bitop): '<S181>/az_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S176>/Index Vector' incorporates:
           *  Product: '<S183>/Multiply3'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_l1_a_cmd_j +
               rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_a);
          }
          break;

         default:
          /* SignalConversion: '<S248>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S248>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S248>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S248>/Trigonometric Function3' incorporates:
           *  Gain: '<S247>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S248>/Gain' incorporates:
           *  Gain: '<S247>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Trigonometry: '<S248>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S248>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S248>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S248>/Trigonometric Function' incorporates:
           *  Gain: '<S247>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S248>/Trigonometric Function1' incorporates:
           *  Gain: '<S247>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S257>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S242>/lat_cmd valid'
           */
          tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S260>/Compare' incorporates:
           *  Constant: '<S260>/Constant'
           *  S-Function (sfix_bitop): '<S257>/lat_cmd valid'
           */
          tmp[0] = (tmp_3 > 0U);

          /* S-Function (sfix_bitop): '<S257>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S242>/lon_cmd valid'
           */
          tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S260>/Compare' incorporates:
           *  Constant: '<S260>/Constant'
           *  S-Function (sfix_bitop): '<S257>/lon_cmd valid'
           */
          tmp[1] = (tmp_4 > 0U);

          /* S-Function (sfix_bitop): '<S257>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S242>/alt_cmd valid'
           */
          tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S260>/Compare' incorporates:
           *  Constant: '<S260>/Constant'
           *  S-Function (sfix_bitop): '<S257>/alt_cmd valid'
           */
          tmp[2] = (tmp_5 > 0U);

          /* DataTypeConversion: '<S258>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S258>/Data Type Conversion'
           *  Gain: '<S258>/Gain2'
           *  Gain: '<S261>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S264>/Multiply1'
           *  Product: '<S264>/Multiply2'
           *  Product: '<S264>/Multiply3'
           *  Product: '<S264>/Multiply4'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S261>/Sum1'
           *  Sum: '<S264>/Sum2'
           *  Sum: '<S264>/Sum3'
           */
          rtb_VectorConcatenate_ar[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_VectorConcatenate_ar[1] = (real32_T)(rtb_Gain *
            FMS_ConstB.SinCos_o2 - rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_VectorConcatenate_ar[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S245>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S249>/Compare' incorporates:
           *  Constant: '<S249>/Constant'
           *  S-Function (sfix_bitop): '<S242>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S242>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S250>/Compare' incorporates:
           *  Constant: '<S250>/Constant'
           */
          tmp_2[0] = (tmp_3 > 0U);
          tmp_2[1] = (tmp_4 > 0U);
          tmp_2[2] = (tmp_5 > 0U);

          /* Sum: '<S241>/Sum2' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S245>/Switch' incorporates:
             *  Product: '<S241>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_l1_a_cmd_j = rtb_VectorConcatenate_ar[rtb_Compare_bv_0];
            } else {
              rtb_l1_a_cmd_j = tmp_0[rtb_Compare_bv_0];
            }

            /* Saturate: '<S241>/Saturation1' incorporates:
             *  Gain: '<S246>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S242>/Logical Operator'
             *  Product: '<S241>/Multiply'
             *  Product: '<S241>/Multiply2'
             *  SignalConversion: '<S28>/Signal Copy1'
             */
            rtb_Subtract3_d5 = tmp_1[rtb_Compare_bv_0] || tmp_2[rtb_Compare_bv_0]
              ? rtb_l1_a_cmd_j - ((rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3]
              * FMS_U.INS_Out.y_R + rtb_VectorConcatenate_i[rtb_Compare_bv_0] *
              FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6]
                                  * -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Subtract3_d5 > FMS_ConstP.pooled22[rtb_Compare_bv_0]) {
              rtb_Switch_dw[rtb_Compare_bv_0] =
                FMS_ConstP.pooled22[rtb_Compare_bv_0];
            } else if (rtb_Subtract3_d5 < FMS_ConstP.pooled23[rtb_Compare_bv_0])
            {
              rtb_Switch_dw[rtb_Compare_bv_0] =
                FMS_ConstP.pooled23[rtb_Compare_bv_0];
            } else {
              rtb_Switch_dw[rtb_Compare_bv_0] = rtb_Subtract3_d5;
            }

            /* End of Saturate: '<S241>/Saturation1' */
          }

          /* End of Sum: '<S241>/Sum2' */

          /* MultiPortSwitch: '<S176>/Index Vector' incorporates:
           *  Constant: '<S184>/Constant'
           *  Product: '<S176>/Multiply'
           *  RelationalOperator: '<S184>/Compare'
           *  S-Function (sfix_bitop): '<S181>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S181>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S181>/az_cmd valid'
           */
          rtb_TmpSignalConversionAtMath_c[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U)
            > 0U ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = (FMS_U.Auto_Cmd.cmd_mask &
            131072U) > 0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = (FMS_U.Auto_Cmd.cmd_mask &
            262144U) > 0U ? FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S239>/Index Vector' */

        /* Sum: '<S235>/Sum1' incorporates:
         *  Constant: '<S235>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S235>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Add4_p = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Abs: '<S236>/Abs' */
        rtb_Add3_c = fabsf(rtb_Add4_p);

        /* Switch: '<S236>/Switch' incorporates:
         *  Constant: '<S236>/Constant'
         *  Constant: '<S237>/Constant'
         *  Product: '<S236>/Multiply'
         *  RelationalOperator: '<S237>/Compare'
         *  Sum: '<S236>/Subtract'
         */
        if (rtb_Add3_c > 3.14159274F) {
          /* Signum: '<S236>/Sign' */
          if (rtb_Add4_p < 0.0F) {
            rtb_Add4_p = -1.0F;
          } else {
            if (rtb_Add4_p > 0.0F) {
              rtb_Add4_p = 1.0F;
            }
          }

          /* End of Signum: '<S236>/Sign' */
          rtb_Add4_p *= rtb_Add3_c - 6.28318548F;
        }

        /* End of Switch: '<S236>/Switch' */

        /* Saturate: '<S235>/Saturation' */
        if (rtb_Add4_p > 0.314159274F) {
          rtb_Add4_p = 0.314159274F;
        } else {
          if (rtb_Add4_p < -0.314159274F) {
            rtb_Add4_p = -0.314159274F;
          }
        }

        /* End of Saturate: '<S235>/Saturation' */

        /* Gain: '<S232>/Gain2' */
        rtb_Add4_p *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S178>/Sum' incorporates:
         *  Constant: '<S234>/Constant'
         *  Constant: '<S238>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S232>/Multiply2'
         *  Product: '<S233>/Multiply1'
         *  RelationalOperator: '<S234>/Compare'
         *  RelationalOperator: '<S238>/Compare'
         *  S-Function (sfix_bitop): '<S232>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S233>/psi_rate_cmd valid'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        rtb_Subtract3_d5 = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ? rtb_Add4_p :
                            0.0F) + ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ?
          FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S239>/Gain1' */
        rtb_Add3_c = FMS_PARAM.XY_P * rtb_Switch_dw[0];
        A = FMS_PARAM.XY_P * rtb_Switch_dw[1];

        /* Gain: '<S239>/Gain2' */
        rtb_Add4_p = FMS_PARAM.Z_P * rtb_Switch_dw[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MultiPortSwitch: '<S240>/Index Vector' incorporates:
         *  Constant: '<S275>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S240>/Multiply'
         *  Product: '<S273>/Multiply'
         *  Product: '<S274>/Multiply3'
         *  RelationalOperator: '<S275>/Compare'
         *  S-Function (sfix_bitop): '<S272>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S272>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S272>/w_cmd valid'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S277>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S277>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Trigonometry: '<S277>/Trigonometric Function3' incorporates:
           *  Gain: '<S276>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S277>/Gain' incorporates:
           *  Gain: '<S276>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Trigonometry: '<S277>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S277>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S277>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S277>/Trigonometric Function' incorporates:
           *  Gain: '<S276>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S277>/Trigonometric Function1' incorporates:
           *  Gain: '<S276>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S277>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S275>/Constant'
           *  RelationalOperator: '<S275>/Compare'
           *  S-Function (sfix_bitop): '<S272>/u_cmd valid'
           */
          rtb_a_a = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S277>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S275>/Constant'
           *  RelationalOperator: '<S275>/Compare'
           *  S-Function (sfix_bitop): '<S272>/v_cmd valid'
           */
          rtb_l1_a_cmd_j = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S277>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S275>/Constant'
           *  RelationalOperator: '<S275>/Compare'
           *  S-Function (sfix_bitop): '<S272>/w_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Switch_dw[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_l1_a_cmd_j +
               rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_a);
          }
          break;

         case 1:
          /* SignalConversion: '<S279>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S279>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Gain: '<S278>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S274>/Subtract'
           */
          rtb_a_a = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S279>/Trigonometric Function3' incorporates:
           *  Gain: '<S278>/Gain'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(rtb_a_a);

          /* Gain: '<S279>/Gain' incorporates:
           *  Gain: '<S278>/Gain'
           *  Trigonometry: '<S279>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(rtb_a_a);

          /* SignalConversion: '<S279>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S279>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S279>/Trigonometric Function' incorporates:
           *  Gain: '<S278>/Gain'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(rtb_a_a);

          /* Trigonometry: '<S279>/Trigonometric Function1' incorporates:
           *  Gain: '<S278>/Gain'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(rtb_a_a);

          /* SignalConversion: '<S279>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S275>/Constant'
           *  RelationalOperator: '<S275>/Compare'
           *  S-Function (sfix_bitop): '<S272>/u_cmd valid'
           */
          rtb_a_a = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S279>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S275>/Constant'
           *  RelationalOperator: '<S275>/Compare'
           *  S-Function (sfix_bitop): '<S272>/v_cmd valid'
           */
          rtb_l1_a_cmd_j = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S279>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S240>/Multiply' incorporates:
           *  Constant: '<S275>/Constant'
           *  RelationalOperator: '<S275>/Compare'
           *  S-Function (sfix_bitop): '<S272>/w_cmd valid'
           */
          rtb_Sqrt_b = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Switch_dw[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * rtb_Sqrt_b +
              (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_l1_a_cmd_j +
               rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_a);
          }
          break;

         default:
          rtb_Switch_dw[0] = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Switch_dw[1] = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Switch_dw[2] = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S240>/Index Vector' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Switch_dw[0] += rtb_Add3_c;
        rtb_Switch_dw[1] += A;

        /* Sum: '<S179>/Sum1' */
        rtb_Add3_c = rtb_Add4_p + rtb_Switch_dw[2];

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S196>/Switch' incorporates:
         *  Constant: '<S211>/Constant'
         *  Constant: '<S212>/Constant'
         *  Constant: '<S213>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S211>/Compare'
         *  RelationalOperator: '<S212>/Compare'
         *  RelationalOperator: '<S213>/Compare'
         *  S-Function (sfix_bitop): '<S196>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S196>/y_v_cmd'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S196>/Logical Operator' incorporates:
           *  Constant: '<S212>/Constant'
           *  Constant: '<S213>/Constant'
           *  RelationalOperator: '<S212>/Compare'
           *  RelationalOperator: '<S213>/Compare'
           *  S-Function (sfix_bitop): '<S196>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S196>/y_v_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) >
            0U);
        }

        /* End of Switch: '<S196>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S177>/u_cmd_valid' */
        /* MATLAB Function: '<S208>/bit_shift' incorporates:
         *  DataTypeConversion: '<S177>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_e << 6);

        /* End of Outputs for SubSystem: '<S177>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S177>/v_cmd_valid' */
        /* MATLAB Function: '<S209>/bit_shift' incorporates:
         *  DataTypeConversion: '<S177>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S177>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S197>/Switch' incorporates:
         *  Constant: '<S215>/Constant'
         *  Constant: '<S216>/Constant'
         *  Constant: '<S218>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S215>/Compare'
         *  RelationalOperator: '<S216>/Compare'
         *  RelationalOperator: '<S218>/Compare'
         *  S-Function (sfix_bitop): '<S197>/ax_cmd'
         *  S-Function (sfix_bitop): '<S197>/ay_cmd'
         *  SignalConversion: '<S28>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S197>/Logical Operator' incorporates:
           *  Constant: '<S216>/Constant'
           *  Constant: '<S218>/Constant'
           *  RelationalOperator: '<S216>/Compare'
           *  RelationalOperator: '<S218>/Compare'
           *  S-Function (sfix_bitop): '<S197>/ax_cmd'
           *  S-Function (sfix_bitop): '<S197>/ay_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S197>/Switch' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S94>/Bus Assignment'
         *  Constant: '<S94>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S94>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Inport: '<Root>/Auto_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S28>/Signal Copy'
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
        FMS_Y.FMS_Out.ax_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.ay_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.az_cmd = rtb_TmpSignalConversionAtMath_c[2];

        /* Saturate: '<S178>/Saturation' */
        if (rtb_Subtract3_d5 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Subtract3_d5 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Subtract3_d5;
        }

        /* End of Saturate: '<S178>/Saturation' */

        /* Saturate: '<S179>/Saturation2' */
        if (rtb_Switch_dw[0] > FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_X_LIM;
        } else if (rtb_Switch_dw[0] < -FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_X_LIM;
        } else {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_dw[0];
        }

        /* End of Saturate: '<S179>/Saturation2' */

        /* Saturate: '<S179>/Saturation1' */
        if (rtb_Switch_dw[1] > FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_X_LIM;
        } else if (rtb_Switch_dw[1] < -FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_X_LIM;
        } else {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_dw[1];
        }

        /* End of Saturate: '<S179>/Saturation1' */

        /* Saturate: '<S179>/Saturation3' */
        if (rtb_Add3_c > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Add3_c < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S94>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Add3_c;
        }

        /* End of Saturate: '<S179>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S177>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S177>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S177>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S177>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S177>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S177>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S177>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S177>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S177>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S177>/throttle_cmd_valid' */
        /* BusAssignment: '<S94>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S189>/Constant'
         *  Constant: '<S190>/Constant'
         *  Constant: '<S191>/Constant'
         *  Constant: '<S192>/Constant'
         *  Constant: '<S193>/Constant'
         *  Constant: '<S194>/Constant'
         *  Constant: '<S195>/Constant'
         *  Constant: '<S214>/Constant'
         *  Constant: '<S217>/Constant'
         *  DataTypeConversion: '<S177>/Data Type Conversion10'
         *  DataTypeConversion: '<S177>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S198>/bit_shift'
         *  MATLAB Function: '<S199>/bit_shift'
         *  MATLAB Function: '<S200>/bit_shift'
         *  MATLAB Function: '<S202>/bit_shift'
         *  MATLAB Function: '<S203>/bit_shift'
         *  MATLAB Function: '<S204>/bit_shift'
         *  MATLAB Function: '<S205>/bit_shift'
         *  MATLAB Function: '<S206>/bit_shift'
         *  MATLAB Function: '<S207>/bit_shift'
         *  MATLAB Function: '<S210>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S189>/Compare'
         *  RelationalOperator: '<S190>/Compare'
         *  RelationalOperator: '<S191>/Compare'
         *  RelationalOperator: '<S192>/Compare'
         *  RelationalOperator: '<S193>/Compare'
         *  RelationalOperator: '<S194>/Compare'
         *  RelationalOperator: '<S195>/Compare'
         *  RelationalOperator: '<S214>/Compare'
         *  RelationalOperator: '<S217>/Compare'
         *  S-Function (sfix_bitop): '<S177>/p_cmd'
         *  S-Function (sfix_bitop): '<S177>/phi_cmd'
         *  S-Function (sfix_bitop): '<S177>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S177>/q_cmd'
         *  S-Function (sfix_bitop): '<S177>/r_cmd'
         *  S-Function (sfix_bitop): '<S177>/theta_cmd'
         *  S-Function (sfix_bitop): '<S177>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S196>/z_w_cmd'
         *  S-Function (sfix_bitop): '<S197>/az_cmd'
         *  SignalConversion: '<S28>/Signal Copy'
         *  Sum: '<S177>/Add'
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

        /* End of Outputs for SubSystem: '<S177>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S177>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S177>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S177>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S177>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S177>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S177>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S177>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S177>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S177>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S34>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S34>/Mission' incorporates:
           *  ActionPort: '<S93>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S34>/Switch Case' incorporates:
           *  UnitDelay: '<S96>/Delay Input1'
           *
           * Block description for '<S96>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S34>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S34>/Mission' incorporates:
           *  ActionPort: '<S93>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S93>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S34>/Switch Case' incorporates:
           *  Chart: '<S135>/Motion Status'
           *  Chart: '<S145>/Motion State'
           *  Delay: '<S101>/Delay'
           *  Delay: '<S123>/Delay'
           *  DiscreteIntegrator: '<S104>/Integrator'
           *  DiscreteIntegrator: '<S104>/Integrator1'
           *  DiscreteIntegrator: '<S119>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S124>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_i = 1U;
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S93>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S34>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S34>/Mission' incorporates:
         *  ActionPort: '<S93>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* RelationalOperator: '<S96>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S96>/Delay Input1'
         *
         * Block description for '<S96>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S93>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S97>/Reset'
         */
        if (rtb_FixPtRelationalOperator_me &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S144>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S134>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S123>/Delay' */
          FMS_DW.icLoad_i = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for DiscreteIntegrator: '<S119>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S101>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator' */
          FMS_DW.Integrator_DSTATE = 0.0F;

          /* SystemReset for Chart: '<S145>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S135>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_me;

        /* Delay: '<S123>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_i != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Switch: '<S119>/Switch2' incorporates:
         *  Constant: '<S119>/vel'
         *  Constant: '<S128>/Constant'
         *  RelationalOperator: '<S128>/Compare'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_B.Cmd_In.set_speed > 0.0F) {
          rtb_a_a = FMS_B.Cmd_In.set_speed;
        } else {
          rtb_a_a = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S119>/Switch2' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* DiscreteIntegrator: '<S124>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S96>/Delay Input1'
         *
         * Block description for '<S96>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S118>/Compare' incorporates:
         *  Constant: '<S175>/Constant'
         *  RelationalOperator: '<S175>/Compare'
         *  UnitDelay: '<S96>/Delay Input1'
         *
         * Block description for '<S96>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_on = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* DiscreteIntegrator: '<S119>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S145>/Motion State' incorporates:
         *  Constant: '<S145>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S145>/Square'
         *  Math: '<S145>/Square1'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sqrt: '<S145>/Sqrt'
         *  Sum: '<S145>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S144>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S144>/Hold Control' incorporates:
             *  ActionPort: '<S147>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S144>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S144>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S144>/Hold Control' incorporates:
           *  ActionPort: '<S147>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S144>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S144>/Brake Control' incorporates:
           *  ActionPort: '<S146>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S144>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S144>/Move Control' incorporates:
             *  ActionPort: '<S148>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S144>/Switch Case' */
            FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S144>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S144>/Move Control' incorporates:
           *  ActionPort: '<S148>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_i(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S144>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S144>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S135>/Motion Status' incorporates:
         *  Abs: '<S135>/Abs'
         *  Constant: '<S135>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S134>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S134>/Hold Control' incorporates:
             *  ActionPort: '<S137>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S134>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S134>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S134>/Hold Control' incorporates:
           *  ActionPort: '<S137>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S134>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S134>/Brake Control' incorporates:
           *  ActionPort: '<S136>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S134>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S134>/Move Control' incorporates:
             *  ActionPort: '<S138>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S134>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S134>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S134>/Move Control' incorporates:
           *  ActionPort: '<S138>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S134>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S134>/Switch Case' */

        /* Switch: '<S99>/Switch' incorporates:
         *  Product: '<S123>/Multiply'
         *  Sum: '<S123>/Sum'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S144>/Saturation1' */
          if (FMS_B.Merge_n[0] > FMS_PARAM.VEL_X_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_PARAM.VEL_X_LIM;
          } else if (FMS_B.Merge_n[0] < -FMS_PARAM.VEL_X_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = -FMS_PARAM.VEL_X_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_B.Merge_n[0];
          }

          if (FMS_B.Merge_n[1] > FMS_PARAM.VEL_X_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_PARAM.VEL_X_LIM;
          } else if (FMS_B.Merge_n[1] < -FMS_PARAM.VEL_X_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = -FMS_PARAM.VEL_X_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_B.Merge_n[1];
          }

          /* End of Saturate: '<S144>/Saturation1' */

          /* Saturate: '<S134>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S134>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S123>/Sum' incorporates:
           *  Delay: '<S123>/Delay'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S172>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Add3_c;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S119>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          A = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Subtract3_d5 = rtb_Add3_c;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S123>/Sum' incorporates:
           *  Delay: '<S123>/Delay'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_p[1];

          /* Sum: '<S119>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_p = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sqrt: '<S131>/Sqrt' incorporates:
           *  Math: '<S131>/Square'
           *  Sum: '<S119>/Sum'
           *  Sum: '<S131>/Sum of Elements'
           */
          rtb_Add4_p = sqrtf(A * A + rtb_Add4_p * rtb_Add4_p);

          /* SignalConversion: '<S174>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3_e[0];
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3_e[1];
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S174>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S174>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S173>/Gain' incorporates:
           *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S171>/Add'
           */
          rtb_l1_a_cmd_j = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Trigonometry: '<S174>/Trigonometric Function3' */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(rtb_l1_a_cmd_j);

          /* Gain: '<S174>/Gain' incorporates:
           *  Trigonometry: '<S174>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(rtb_l1_a_cmd_j);

          /* SignalConversion: '<S174>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S174>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Trigonometry: '<S174>/Trigonometric Function' */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(rtb_l1_a_cmd_j);

          /* Trigonometry: '<S174>/Trigonometric Function1' */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(rtb_l1_a_cmd_j);

          /* Switch: '<S130>/Switch2' incorporates:
           *  Constant: '<S119>/Constant2'
           *  DiscreteIntegrator: '<S119>/Acceleration_Speed'
           *  RelationalOperator: '<S130>/LowerRelop1'
           *  RelationalOperator: '<S130>/UpperRelop'
           *  Switch: '<S130>/Switch'
           */
          if (FMS_DW.Acceleration_Speed_DSTATE > rtb_a_a) {
            rtb_l1_a_cmd_j = rtb_a_a;
          } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
            /* Switch: '<S130>/Switch' incorporates:
             *  Constant: '<S119>/Constant2'
             */
            rtb_l1_a_cmd_j = 0.0F;
          } else {
            rtb_l1_a_cmd_j = FMS_DW.Acceleration_Speed_DSTATE;
          }

          /* End of Switch: '<S130>/Switch2' */

          /* Switch: '<S119>/Switch' */
          if (rtb_Add4_p > FMS_PARAM.L1) {
            rtb_Add4_p = rtb_a_a;
          } else {
            /* Gain: '<S119>/Gain' */
            rtb_Add4_p *= 0.5F;

            /* Switch: '<S129>/Switch2' incorporates:
             *  Constant: '<S119>/Constant1'
             *  RelationalOperator: '<S129>/LowerRelop1'
             *  RelationalOperator: '<S129>/UpperRelop'
             *  Switch: '<S129>/Switch'
             */
            if (rtb_Add4_p > rtb_a_a) {
              rtb_Add4_p = rtb_a_a;
            } else {
              if (rtb_Add4_p < 0.5F) {
                /* Switch: '<S129>/Switch' incorporates:
                 *  Constant: '<S119>/Constant1'
                 */
                rtb_Add4_p = 0.5F;
              }
            }

            /* End of Switch: '<S129>/Switch2' */
          }

          /* End of Switch: '<S119>/Switch' */

          /* Switch: '<S119>/Switch1' incorporates:
           *  Sum: '<S119>/Sum1'
           */
          if (rtb_l1_a_cmd_j - rtb_Add4_p < 0.0F) {
            rtb_Add4_p = rtb_l1_a_cmd_j;
          }

          /* End of Switch: '<S119>/Switch1' */

          /* Sum: '<S172>/Sum of Elements' incorporates:
           *  Math: '<S172>/Math Function'
           */
          rtb_l1_a_cmd_j = rtb_TmpSignalConversionAtMath_c[0] *
            rtb_TmpSignalConversionAtMath_c[0] + rtb_Add3_c * rtb_Add3_c;

          /* Math: '<S172>/Math Function1' incorporates:
           *  Sum: '<S172>/Sum of Elements'
           *
           * About '<S172>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_l1_a_cmd_j < 0.0F) {
            rtb_l1_a_cmd_j = -sqrtf(fabsf(rtb_l1_a_cmd_j));
          } else {
            rtb_l1_a_cmd_j = sqrtf(rtb_l1_a_cmd_j);
          }

          /* End of Math: '<S172>/Math Function1' */

          /* Switch: '<S172>/Switch' incorporates:
           *  Constant: '<S172>/Constant'
           *  Product: '<S172>/Product'
           */
          if (rtb_l1_a_cmd_j <= 0.0F) {
            rtb_Subtract3_d5 = 0.0F;
            rtb_Add3_c = 0.0F;
            rtb_l1_a_cmd_j = 1.0F;
          }

          /* End of Switch: '<S172>/Switch' */

          /* Product: '<S170>/Multiply2' incorporates:
           *  Product: '<S172>/Divide'
           */
          rtb_Subtract3_d5 = rtb_Subtract3_d5 / rtb_l1_a_cmd_j * rtb_Add4_p;
          rtb_Add4_p *= rtb_Add3_c / rtb_l1_a_cmd_j;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S125>/Sum1' incorporates:
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_l1_a_cmd_j = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S125>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          A = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sqrt_b = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S125>/Divide' incorporates:
           *  Math: '<S126>/Square'
           *  Math: '<S127>/Square'
           *  Sqrt: '<S126>/Sqrt'
           *  Sqrt: '<S127>/Sqrt'
           *  Sum: '<S125>/Sum'
           *  Sum: '<S125>/Sum1'
           *  Sum: '<S126>/Sum of Elements'
           *  Sum: '<S127>/Sum of Elements'
           */
          rtb_l1_a_cmd_j = sqrtf(A * A + rtb_Sqrt_b * rtb_Sqrt_b) / sqrtf
            (rtb_Add3_c * rtb_Add3_c + rtb_l1_a_cmd_j * rtb_l1_a_cmd_j);

          /* Saturate: '<S125>/Saturation' */
          if (rtb_l1_a_cmd_j > 1.0F) {
            rtb_l1_a_cmd_j = 1.0F;
          } else {
            if (rtb_l1_a_cmd_j < 0.0F) {
              rtb_l1_a_cmd_j = 0.0F;
            }
          }

          /* End of Saturate: '<S125>/Saturation' */

          /* Product: '<S123>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] * rtb_Add4_p +
              rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_Subtract3_d5;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S116>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S125>/Multiply'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S116>/Sum2'
           *  Sum: '<S125>/Add'
           *  Sum: '<S125>/Subtract'
           */
          rtb_Subtract3_d5 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_l1_a_cmd_j +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_VectorConcatenate_ar[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_VectorConcatenate_ar[1];

          /* Saturate: '<S116>/Saturation1' incorporates:
           *  Product: '<S123>/Multiply'
           */
          if (rtb_Subtract3_d5 > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Subtract3_d5 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Subtract3_d5;
          }

          /* End of Saturate: '<S116>/Saturation1' */
        }

        /* End of Switch: '<S99>/Switch' */

        /* Delay: '<S101>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S104>/Integrator1' incorporates:
         *  Delay: '<S101>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Math: '<S108>/Rem' incorporates:
         *  Constant: '<S108>/Constant1'
         *  DiscreteIntegrator: '<S104>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S103>/Sum'
         */
        rtb_Rem_n = rt_remf(FMS_DW.Integrator1_DSTATE - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Switch: '<S108>/Switch' incorporates:
         *  Abs: '<S108>/Abs'
         *  Constant: '<S108>/Constant'
         *  Constant: '<S109>/Constant'
         *  Product: '<S108>/Multiply'
         *  RelationalOperator: '<S109>/Compare'
         *  Sum: '<S108>/Add'
         */
        if (fabsf(rtb_Rem_n) > 3.14159274F) {
          /* Signum: '<S108>/Sign' */
          if (rtb_Rem_n < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Rem_n > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Rem_n;
          }

          /* End of Signum: '<S108>/Sign' */
          rtb_Rem_n -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S108>/Switch' */

        /* Gain: '<S103>/Gain2' */
        rtb_Rem_n *= FMS_PARAM.YAW_P;

        /* Saturate: '<S103>/Saturation' */
        if (rtb_Rem_n > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_n = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_n < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_n = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S103>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S97>/Bus Assignment'
         *  Constant: '<S97>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S97>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_n;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S165>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S165>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_l1_a_cmd_j = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S165>/Math Function1' incorporates:
         *  Sum: '<S165>/Sum of Elements'
         *
         * About '<S165>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_l1_a_cmd_j < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_l1_a_cmd_j));
        } else {
          rtb_Rem_n = sqrtf(rtb_l1_a_cmd_j);
        }

        /* End of Math: '<S165>/Math Function1' */

        /* Switch: '<S165>/Switch' incorporates:
         *  Constant: '<S165>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S165>/Product'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        if (rtb_Rem_n > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMath_c[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Rem_n;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S165>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S97>/Sum' incorporates:
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add4_p = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Subtract3_lb[0] = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Subtract3_d5 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Subtract3_lb[1] = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Sum: '<S115>/Sum of Elements' incorporates:
         *  Math: '<S115>/Math Function'
         *  Sum: '<S97>/Sum'
         */
        rtb_l1_a_cmd_j = rtb_Subtract3_d5 * rtb_Subtract3_d5 + rtb_Add4_p *
          rtb_Add4_p;

        /* Math: '<S115>/Math Function1' incorporates:
         *  Sum: '<S115>/Sum of Elements'
         *
         * About '<S115>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_l1_a_cmd_j < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_l1_a_cmd_j));
        } else {
          rtb_Rem_n = sqrtf(rtb_l1_a_cmd_j);
        }

        /* End of Math: '<S115>/Math Function1' */

        /* Switch: '<S115>/Switch' incorporates:
         *  Constant: '<S115>/Constant'
         *  Product: '<S115>/Product'
         */
        if (rtb_Rem_n > 0.0F) {
          rtb_MathFunction_f_idx_2 = rtb_Rem_n;
        } else {
          rtb_Subtract3_d5 = 0.0F;
          rtb_Add4_p = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S115>/Switch' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S121>/NearbyRefWP' incorporates:
         *  Constant: '<S97>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_dw[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Subtract3_lb, &rtb_l1_a_cmd_j);

        /* MATLAB Function: '<S121>/SearchL1RefWP' incorporates:
         *  Constant: '<S97>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Add3_c = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        A = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        A = rtb_Add3_c * rtb_Add3_c + A * A;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
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
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Add3_c = -1.0F;
        rtb_Sqrt_b = 0.0F;
        rtb_Sign1_c_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          A = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
            rtb_Add3_c = fmaxf(D, A);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Add3_c = D;
            guard1 = true;
          } else {
            if ((A >= 0.0F) && (A <= 1.0F)) {
              rtb_Add3_c = A;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_c = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Sqrt_b = (FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
                        [0]) * rtb_Add3_c + FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Sign1_c_idx_1 = (FMS_B.Cmd_In.sp_waypoint[1] -
                               FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Add3_c +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* MATLAB Function: '<S121>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_p = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Rem_n = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        A = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Rem_n +
             (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Rem_p) /
          (rtb_Rem_p * rtb_Rem_p + rtb_Rem_n * rtb_Rem_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (A <= 0.0F);
        rtb_LogicalOperator_e = (A >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          B = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else if (rtb_LogicalOperator_e) {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          B = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          B = A * rtb_Rem_p + FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        }

        /* Switch: '<S121>/Switch1' incorporates:
         *  Constant: '<S158>/Constant'
         *  RelationalOperator: '<S158>/Compare'
         */
        if (rtb_l1_a_cmd_j <= 0.0F) {
          /* Switch: '<S121>/Switch' incorporates:
           *  Constant: '<S157>/Constant'
           *  MATLAB Function: '<S121>/SearchL1RefWP'
           *  RelationalOperator: '<S157>/Compare'
           */
          if (rtb_Add3_c >= 0.0F) {
            rtb_Subtract3_lb[0] = rtb_Sqrt_b;
            rtb_Subtract3_lb[1] = rtb_Sign1_c_idx_1;
          } else {
            rtb_Subtract3_lb[0] = B;

            /* MATLAB Function: '<S121>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Subtract3_lb[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else if (rtb_LogicalOperator_e) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Subtract3_lb[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Subtract3_lb[1] = A * rtb_Rem_n + FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            }
          }

          /* End of Switch: '<S121>/Switch' */
        }

        /* End of Switch: '<S121>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S122>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        A = rtb_Subtract3_lb[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_Subtract3_lb[0] = A * A;
        rtb_Add3_c = A;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S122>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S166>/Math Function'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        A = rtb_Subtract3_lb[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S166>/Math Function' incorporates:
         *  Math: '<S164>/Square'
         */
        rtb_l1_a_cmd_j = A * A;

        /* Sum: '<S166>/Sum of Elements' incorporates:
         *  Math: '<S166>/Math Function'
         */
        rtb_Rem_p = rtb_l1_a_cmd_j + rtb_Subtract3_lb[0];

        /* Math: '<S166>/Math Function1' incorporates:
         *  Sum: '<S166>/Sum of Elements'
         *
         * About '<S166>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          rtb_Rem_n = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S166>/Math Function1' */

        /* Switch: '<S166>/Switch' incorporates:
         *  Constant: '<S166>/Constant'
         *  Product: '<S166>/Product'
         */
        if (rtb_Rem_n > 0.0F) {
          rtb_Switch_dw[0] = rtb_Add3_c;
          rtb_Switch_dw[1] = A;
          rtb_Switch_dw[2] = rtb_Rem_n;
        } else {
          rtb_Switch_dw[0] = 0.0F;
          rtb_Switch_dw[1] = 0.0F;
          rtb_Switch_dw[2] = 1.0F;
        }

        /* End of Switch: '<S166>/Switch' */

        /* Product: '<S165>/Divide' */
        rtb_a_c_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        D = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S168>/Sum of Elements' incorporates:
         *  Math: '<S168>/Math Function'
         *  SignalConversion: '<S168>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = D * D + rtb_a_c_idx_0 * rtb_a_c_idx_0;

        /* Math: '<S168>/Math Function1' incorporates:
         *  Sum: '<S168>/Sum of Elements'
         *
         * About '<S168>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          rtb_Rem_n = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S168>/Math Function1' */

        /* Switch: '<S168>/Switch' incorporates:
         *  Constant: '<S168>/Constant'
         *  Product: '<S168>/Product'
         */
        if (rtb_Rem_n > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = D;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_a_c_idx_0;
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Rem_n;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S168>/Switch' */

        /* Product: '<S166>/Divide' */
        rtb_a_c_idx_0 = rtb_Switch_dw[0] / rtb_Switch_dw[2];
        D = rtb_Switch_dw[1] / rtb_Switch_dw[2];

        /* Sum: '<S169>/Sum of Elements' incorporates:
         *  Math: '<S169>/Math Function'
         *  SignalConversion: '<S169>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = D * D + rtb_a_c_idx_0 * rtb_a_c_idx_0;

        /* Math: '<S169>/Math Function1' incorporates:
         *  Sum: '<S169>/Sum of Elements'
         *
         * About '<S169>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_n = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          rtb_Rem_n = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S169>/Math Function1' */

        /* Switch: '<S169>/Switch' incorporates:
         *  Constant: '<S169>/Constant'
         *  Product: '<S169>/Product'
         */
        if (rtb_Rem_n > 0.0F) {
          rtb_Switch_dw[0] = D;
          rtb_Switch_dw[1] = rtb_a_c_idx_0;
          rtb_Switch_dw[2] = rtb_Rem_n;
        } else {
          rtb_Switch_dw[0] = 0.0F;
          rtb_Switch_dw[1] = 0.0F;
          rtb_Switch_dw[2] = 1.0F;
        }

        /* End of Switch: '<S169>/Switch' */

        /* Product: '<S169>/Divide' */
        rtb_a_c_idx_0 = rtb_Switch_dw[0] / rtb_Switch_dw[2];

        /* Product: '<S168>/Divide' */
        rtb_Subtract3_lb[0] = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S115>/Divide' */
        rtb_Sqrt_b = rtb_Subtract3_d5 / rtb_MathFunction_f_idx_2;
        rtb_Add3_c *= rtb_Add3_c;

        /* Product: '<S169>/Divide' incorporates:
         *  Math: '<S164>/Square'
         */
        D = rtb_Switch_dw[1] / rtb_Switch_dw[2];

        /* Product: '<S168>/Divide' */
        rtb_Subtract3_lb[1] = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Product: '<S115>/Divide' */
        rtb_Sign1_c_idx_1 = rtb_Add4_p / rtb_MathFunction_f_idx_2;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sqrt: '<S163>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S163>/Square'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S163>/Sum of Elements'
         */
        rtb_Rem_n = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve
                          * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Gain: '<S122>/Gain' incorporates:
         *  Math: '<S122>/Square'
         */
        rtb_Subtract3_d5 = rtb_Rem_n * rtb_Rem_n * 2.0F;

        /* Sum: '<S167>/Subtract' incorporates:
         *  Product: '<S167>/Multiply'
         *  Product: '<S167>/Multiply1'
         */
        rtb_Rem_n = rtb_a_c_idx_0 * rtb_Subtract3_lb[1] - D * rtb_Subtract3_lb[0];

        /* Signum: '<S162>/Sign1' */
        if (rtb_Rem_n < 0.0F) {
          rtb_Rem_n = -1.0F;
        } else {
          if (rtb_Rem_n > 0.0F) {
            rtb_Rem_n = 1.0F;
          }
        }

        /* End of Signum: '<S162>/Sign1' */

        /* Switch: '<S162>/Switch2' incorporates:
         *  Constant: '<S162>/Constant4'
         */
        if (rtb_Rem_n == 0.0F) {
          rtb_Rem_n = 1.0F;
        }

        /* End of Switch: '<S162>/Switch2' */

        /* DotProduct: '<S162>/Dot Product' */
        A = rtb_Subtract3_lb[0] * rtb_a_c_idx_0 + rtb_Subtract3_lb[1] * D;

        /* Trigonometry: '<S162>/Acos' incorporates:
         *  DotProduct: '<S162>/Dot Product'
         */
        if (A > 1.0F) {
          A = 1.0F;
        } else {
          if (A < -1.0F) {
            A = -1.0F;
          }
        }

        /* Product: '<S162>/Multiply' incorporates:
         *  Trigonometry: '<S162>/Acos'
         */
        rtb_Rem_n *= acosf(A);

        /* Saturate: '<S122>/Saturation' */
        if (rtb_Rem_n > 1.57079637F) {
          rtb_Rem_n = 1.57079637F;
        } else {
          if (rtb_Rem_n < -1.57079637F) {
            rtb_Rem_n = -1.57079637F;
          }
        }

        /* End of Saturate: '<S122>/Saturation' */

        /* Product: '<S122>/Divide' incorporates:
         *  Constant: '<S122>/Constant'
         *  Constant: '<S97>/L1'
         *  MinMax: '<S122>/Max'
         *  MinMax: '<S122>/Min'
         *  Product: '<S122>/Multiply1'
         *  Sqrt: '<S164>/Sqrt'
         *  Sum: '<S164>/Sum of Elements'
         *  Trigonometry: '<S122>/Sin'
         */
        rtb_MathFunction_f_idx_2 = arm_sin_f32(rtb_Rem_n) * rtb_Subtract3_d5 /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_l1_a_cmd_j + rtb_Add3_c), 0.5F));

        /* Sum: '<S113>/Subtract' incorporates:
         *  Product: '<S113>/Multiply'
         *  Product: '<S113>/Multiply1'
         */
        rtb_Rem_p = rtb_Sqrt_b * FMS_ConstB.Divide[1] - rtb_Sign1_c_idx_1 *
          FMS_ConstB.Divide[0];

        /* Signum: '<S102>/Sign1' */
        if (rtb_Rem_p < 0.0F) {
          rtb_Rem_p = -1.0F;
        } else {
          if (rtb_Rem_p > 0.0F) {
            rtb_Rem_p = 1.0F;
          }
        }

        /* End of Signum: '<S102>/Sign1' */

        /* Switch: '<S102>/Switch2' incorporates:
         *  Constant: '<S102>/Constant4'
         */
        if (rtb_Rem_p == 0.0F) {
          rtb_Rem_p = 1.0F;
        }

        /* End of Switch: '<S102>/Switch2' */

        /* DotProduct: '<S102>/Dot Product' */
        rtb_Subtract3_d5 = FMS_ConstB.Divide[0] * rtb_Sqrt_b +
          FMS_ConstB.Divide[1] * rtb_Sign1_c_idx_1;

        /* Trigonometry: '<S102>/Acos' incorporates:
         *  DotProduct: '<S102>/Dot Product'
         */
        if (rtb_Subtract3_d5 > 1.0F) {
          rtb_Subtract3_d5 = 1.0F;
        } else {
          if (rtb_Subtract3_d5 < -1.0F) {
            rtb_Subtract3_d5 = -1.0F;
          }
        }

        /* Product: '<S102>/Multiply' incorporates:
         *  Trigonometry: '<S102>/Acos'
         */
        rtb_Rem_p *= acosf(rtb_Subtract3_d5);

        /* Math: '<S105>/Rem' incorporates:
         *  Constant: '<S105>/Constant1'
         *  Delay: '<S101>/Delay'
         *  Sum: '<S101>/Sum2'
         */
        rtb_Rem_n = rt_remf(rtb_Rem_p - FMS_DW.Delay_DSTATE_h, 6.28318548F);

        /* Switch: '<S105>/Switch' incorporates:
         *  Abs: '<S105>/Abs'
         *  Constant: '<S105>/Constant'
         *  Constant: '<S111>/Constant'
         *  Product: '<S105>/Multiply'
         *  RelationalOperator: '<S111>/Compare'
         *  Sum: '<S105>/Add'
         */
        if (fabsf(rtb_Rem_n) > 3.14159274F) {
          /* Signum: '<S105>/Sign' */
          if (rtb_Rem_n < 0.0F) {
            rtb_Add3_c = -1.0F;
          } else if (rtb_Rem_n > 0.0F) {
            rtb_Add3_c = 1.0F;
          } else {
            rtb_Add3_c = rtb_Rem_n;
          }

          /* End of Signum: '<S105>/Sign' */
          rtb_Rem_n -= 6.28318548F * rtb_Add3_c;
        }

        /* End of Switch: '<S105>/Switch' */

        /* Sum: '<S101>/Sum' incorporates:
         *  Delay: '<S101>/Delay'
         */
        rtb_Add3_c = rtb_Rem_n + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S110>/Multiply1' incorporates:
         *  Constant: '<S110>/const1'
         *  DiscreteIntegrator: '<S104>/Integrator'
         */
        rtb_Rem_n = FMS_DW.Integrator_DSTATE * 0.785398185F;

        /* Sum: '<S110>/Add' incorporates:
         *  DiscreteIntegrator: '<S104>/Integrator1'
         *  Sum: '<S104>/Subtract'
         */
        rtb_Subtract3_d5 = (FMS_DW.Integrator1_DSTATE - rtb_Add3_c) + rtb_Rem_n;

        /* Signum: '<S110>/Sign' */
        if (rtb_Subtract3_d5 < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else if (rtb_Subtract3_d5 > 0.0F) {
          rtb_Add3_c = 1.0F;
        } else {
          rtb_Add3_c = rtb_Subtract3_d5;
        }

        /* End of Signum: '<S110>/Sign' */

        /* Sum: '<S110>/Add2' incorporates:
         *  Abs: '<S110>/Abs'
         *  Gain: '<S110>/Gain'
         *  Gain: '<S110>/Gain1'
         *  Product: '<S110>/Multiply2'
         *  Product: '<S110>/Multiply3'
         *  Sqrt: '<S110>/Sqrt'
         *  Sum: '<S110>/Add1'
         *  Sum: '<S110>/Subtract'
         */
        rtb_l1_a_cmd_j = (sqrtf((8.0F * fabsf(rtb_Subtract3_d5) + FMS_ConstB.d) *
          FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Add3_c + rtb_Rem_n;

        /* Sum: '<S110>/Add4' */
        rtb_Add4_p = (rtb_Subtract3_d5 - rtb_l1_a_cmd_j) + rtb_Rem_n;

        /* Sum: '<S110>/Add3' */
        rtb_Add3_c = rtb_Subtract3_d5 + FMS_ConstB.d;

        /* Sum: '<S110>/Subtract1' */
        rtb_Subtract3_d5 -= FMS_ConstB.d;

        /* Signum: '<S110>/Sign1' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S110>/Sign1' */

        /* Signum: '<S110>/Sign2' */
        if (rtb_Subtract3_d5 < 0.0F) {
          rtb_Subtract3_d5 = -1.0F;
        } else {
          if (rtb_Subtract3_d5 > 0.0F) {
            rtb_Subtract3_d5 = 1.0F;
          }
        }

        /* End of Signum: '<S110>/Sign2' */

        /* Sum: '<S110>/Add5' incorporates:
         *  Gain: '<S110>/Gain2'
         *  Product: '<S110>/Multiply4'
         *  Sum: '<S110>/Subtract2'
         */
        rtb_l1_a_cmd_j += (rtb_Add3_c - rtb_Subtract3_d5) * 0.5F * rtb_Add4_p;

        /* Sum: '<S110>/Add6' */
        rtb_Add3_c = rtb_l1_a_cmd_j + FMS_ConstB.d;

        /* Sum: '<S110>/Subtract3' */
        A = rtb_l1_a_cmd_j - FMS_ConstB.d;

        /* Product: '<S110>/Divide' */
        rtb_Sqrt_b = rtb_l1_a_cmd_j / FMS_ConstB.d;

        /* Signum: '<S110>/Sign5' incorporates:
         *  Signum: '<S110>/Sign6'
         */
        if (rtb_l1_a_cmd_j < 0.0F) {
          rtb_Sign1_c_idx_1 = -1.0F;

          /* Signum: '<S110>/Sign6' */
          rtb_Add4_p = -1.0F;
        } else if (rtb_l1_a_cmd_j > 0.0F) {
          rtb_Sign1_c_idx_1 = 1.0F;

          /* Signum: '<S110>/Sign6' */
          rtb_Add4_p = 1.0F;
        } else {
          rtb_Sign1_c_idx_1 = rtb_l1_a_cmd_j;

          /* Signum: '<S110>/Sign6' */
          rtb_Add4_p = rtb_l1_a_cmd_j;
        }

        /* End of Signum: '<S110>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sum: '<S101>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Rem_p -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S106>/Rem' incorporates:
         *  Constant: '<S106>/Constant1'
         */
        rtb_l1_a_cmd_j = rt_remf(rtb_Rem_p, 6.28318548F);

        /* Switch: '<S106>/Switch' incorporates:
         *  Abs: '<S106>/Abs'
         *  Constant: '<S106>/Constant'
         *  Constant: '<S112>/Constant'
         *  Product: '<S106>/Multiply'
         *  RelationalOperator: '<S112>/Compare'
         *  Sum: '<S106>/Add'
         */
        if (fabsf(rtb_l1_a_cmd_j) > 3.14159274F) {
          /* Signum: '<S106>/Sign' */
          if (rtb_l1_a_cmd_j < 0.0F) {
            rtb_Subtract3_d5 = -1.0F;
          } else if (rtb_l1_a_cmd_j > 0.0F) {
            rtb_Subtract3_d5 = 1.0F;
          } else {
            rtb_Subtract3_d5 = rtb_l1_a_cmd_j;
          }

          /* End of Signum: '<S106>/Sign' */
          rtb_l1_a_cmd_j -= 6.28318548F * rtb_Subtract3_d5;
        }

        /* End of Switch: '<S106>/Switch' */

        /* Abs: '<S99>/Abs' */
        rtb_l1_a_cmd_j = fabsf(rtb_l1_a_cmd_j);

        /* Update for Delay: '<S123>/Delay' */
        FMS_DW.icLoad_i = 0U;

        /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S117>/Constant'
         *  RelationalOperator: '<S117>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)
          (rtb_l1_a_cmd_j <= 0.17453292F) +
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */

        /* Update for DiscreteIntegrator: '<S119>/Acceleration_Speed' incorporates:
         *  Constant: '<S119>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Product: '<S123>/Divide1' */
        rtb_Subtract3_d5 = rtb_MathFunction_f_idx_2 / rtb_a_a;

        /* Saturate: '<S123>/Saturation' */
        if (rtb_Subtract3_d5 > 0.314159274F) {
          rtb_Subtract3_d5 = 0.314159274F;
        } else {
          if (rtb_Subtract3_d5 < -0.314159274F) {
            rtb_Subtract3_d5 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S123>/Saturation' */

        /* Update for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Subtract3_d5;

        /* Update for Delay: '<S101>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S104>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S104>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S110>/Sign3' */
        if (rtb_Add3_c < 0.0F) {
          rtb_Add3_c = -1.0F;
        } else {
          if (rtb_Add3_c > 0.0F) {
            rtb_Add3_c = 1.0F;
          }
        }

        /* End of Signum: '<S110>/Sign3' */

        /* Signum: '<S110>/Sign4' */
        if (A < 0.0F) {
          A = -1.0F;
        } else {
          if (A > 0.0F) {
            A = 1.0F;
          }
        }

        /* End of Signum: '<S110>/Sign4' */

        /* Update for DiscreteIntegrator: '<S104>/Integrator' incorporates:
         *  Constant: '<S110>/const'
         *  Gain: '<S110>/Gain3'
         *  Product: '<S110>/Multiply5'
         *  Product: '<S110>/Multiply6'
         *  Sum: '<S110>/Subtract4'
         *  Sum: '<S110>/Subtract5'
         *  Sum: '<S110>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_Sqrt_b - rtb_Sign1_c_idx_1) *
          FMS_ConstB.Gain4 * ((rtb_Add3_c - A) * 0.5F) - rtb_Add4_p *
          1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S104>/Integrator' */
        /* End of Outputs for SubSystem: '<S93>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Update for UnitDelay: '<S96>/Delay Input1' incorporates:
         *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S96>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S34>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S34>/Unknown' incorporates:
         *  ActionPort: '<S95>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S34>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S34>/Switch Case' */
      /* End of Outputs for SubSystem: '<S29>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S29>/Assist' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* SwitchCase: '<S33>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
        break;

       case VehicleState_Altitude:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
        break;

       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 3;
        break;
      }

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S45>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S69>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* Disable for SwitchCase: '<S59>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S33>/Stabilize' incorporates:
         *  ActionPort: '<S40>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S40>/Bus Assignment'
         *  Constant: '<S40>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S40>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S92>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_l1_a_cmd_j = 0.0F;
        } else {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S92>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S89>/Gain6'
         *  Gain: '<S92>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_l1_a_cmd_j * FMS_PARAM.VEL_X_LIM;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S91>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_l1_a_cmd_j = 0.0F;
        } else {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S91>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S88>/Gain6'
         *  Gain: '<S91>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.ay_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_l1_a_cmd_j
          * FMS_PARAM.ACC_Y_LIM;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S90>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_throttle -
            FMS_PARAM.THROTTLE_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
          rtb_l1_a_cmd_j = 0.0F;
        } else {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_throttle -
            (-FMS_PARAM.THROTTLE_DZ);
        }

        /* End of DeadZone: '<S90>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S40>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S87>/Gain6'
         *  Gain: '<S90>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) *
          rtb_l1_a_cmd_j * -FMS_PARAM.VEL_Z_LIM;

        /* End of Outputs for SubSystem: '<S33>/Stabilize' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S33>/Altitude' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S33>/Switch Case' incorporates:
           *  Chart: '<S46>/Motion Status'
           */
          FMS_MotionStatus_b_Reset(&FMS_DW.sf_MotionStatus_n);

          /* End of SystemReset for SubSystem: '<S33>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S33>/Altitude' incorporates:
         *  ActionPort: '<S38>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S46>/Motion Status' incorporates:
         *  Abs: '<S46>/Abs'
         *  Abs: '<S46>/Abs1'
         *  Constant: '<S52>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S52>/Compare'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        FMS_MotionStatus_n(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_n);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* SwitchCase: '<S45>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_p;
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
        switch (rtb_state_c) {
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
            /* SystemReset for IfAction SubSystem: '<S45>/Hold Control' incorporates:
             *  ActionPort: '<S48>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S45>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_da);

            /* End of SystemReset for SubSystem: '<S45>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S45>/Hold Control' incorporates:
           *  ActionPort: '<S48>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_py,
                          &FMS_DW.HoldControl_da);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S45>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S45>/Brake Control' incorporates:
           *  ActionPort: '<S47>/Action Port'
           */
          FMS_BrakeControl_b(&FMS_B.Merge_py);

          /* End of Outputs for SubSystem: '<S45>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S45>/Move Control' incorporates:
           *  ActionPort: '<S49>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_py);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S45>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S45>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S38>/Bus Assignment'
         *  Constant: '<S38>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S38>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S38>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S55>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_l1_a_cmd_j = 0.0F;
        } else {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S55>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S38>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S44>/Gain6'
         *  Gain: '<S55>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_l1_a_cmd_j * FMS_PARAM.VEL_X_LIM;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S54>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_l1_a_cmd_j = 0.0F;
        } else {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S54>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S38>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S43>/Gain6'
         *  Gain: '<S54>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.ay_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_l1_a_cmd_j
          * FMS_PARAM.ACC_Y_LIM;

        /* Saturate: '<S45>/Saturation1' */
        if (FMS_B.Merge_py > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S38>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_py < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S38>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S38>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_py;
        }

        /* End of Saturate: '<S45>/Saturation1' */
        /* End of Outputs for SubSystem: '<S33>/Altitude' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S33>/Position' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S33>/Switch Case' incorporates:
           *  Chart: '<S60>/Motion Status'
           *  Chart: '<S70>/Motion State'
           */
          FMS_MotionStatus_b_Reset(&FMS_DW.sf_MotionStatus_h);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S33>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S33>/Position' incorporates:
         *  ActionPort: '<S39>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Sqrt: '<S86>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S86>/Square'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  Sum: '<S86>/Sum of Elements'
         */
        rtb_Add4_p = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
                             FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) +
                            FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2]) +
                           FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

        /* Product: '<S82>/Divide' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S28>/Signal Copy1'
         */
        rtb_Subtract3_d5 = FMS_U.INS_Out.quat[0] / rtb_Add4_p;
        rtb_Add3_c = FMS_U.INS_Out.quat[1] / rtb_Add4_p;
        rtb_a_a = FMS_U.INS_Out.quat[2] / rtb_Add4_p;
        rtb_l1_a_cmd_j = FMS_U.INS_Out.quat[3] / rtb_Add4_p;

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Math: '<S83>/Square' incorporates:
         *  Math: '<S84>/Square'
         *  Math: '<S85>/Square'
         */
        rtb_Add4_p = rtb_Subtract3_d5 * rtb_Subtract3_d5;

        /* Math: '<S83>/Square2' incorporates:
         *  Math: '<S84>/Square2'
         *  Math: '<S85>/Square2'
         */
        A = rtb_a_a * rtb_a_a;

        /* Math: '<S83>/Square1' incorporates:
         *  Math: '<S84>/Square1'
         *  Math: '<S85>/Square1'
         */
        rtb_Sqrt_b = rtb_Add3_c * rtb_Add3_c;

        /* Math: '<S83>/Square3' incorporates:
         *  Math: '<S84>/Square3'
         *  Math: '<S85>/Square3'
         */
        rtb_Sign1_c_idx_1 = rtb_l1_a_cmd_j * rtb_l1_a_cmd_j;

        /* Sum: '<S83>/Subtract' incorporates:
         *  Math: '<S83>/Square'
         *  Math: '<S83>/Square1'
         *  Math: '<S83>/Square2'
         *  Math: '<S83>/Square3'
         *  Sum: '<S83>/Add'
         *  Sum: '<S83>/Add1'
         */
        rtb_VectorConcatenate_i[0] = (rtb_Add4_p + rtb_Sqrt_b) - (A +
          rtb_Sign1_c_idx_1);

        /* Product: '<S83>/Multiply' incorporates:
         *  Product: '<S84>/Multiply'
         */
        rtb_MathFunction_f_idx_2 = rtb_Add3_c * rtb_a_a;

        /* Product: '<S83>/Multiply1' incorporates:
         *  Product: '<S84>/Multiply1'
         */
        rtb_Rem_n = rtb_Subtract3_d5 * rtb_l1_a_cmd_j;

        /* Gain: '<S83>/Gain' incorporates:
         *  Product: '<S83>/Multiply'
         *  Product: '<S83>/Multiply1'
         *  Sum: '<S83>/Subtract1'
         */
        rtb_VectorConcatenate_i[1] = (rtb_MathFunction_f_idx_2 - rtb_Rem_n) *
          2.0F;

        /* Product: '<S83>/Multiply2' incorporates:
         *  Product: '<S85>/Multiply'
         */
        rtb_Rem_p = rtb_Add3_c * rtb_l1_a_cmd_j;

        /* Product: '<S83>/Multiply3' incorporates:
         *  Product: '<S85>/Multiply1'
         */
        B = rtb_Subtract3_d5 * rtb_a_a;

        /* Gain: '<S83>/Gain1' incorporates:
         *  Product: '<S83>/Multiply2'
         *  Product: '<S83>/Multiply3'
         *  Sum: '<S83>/Add2'
         */
        rtb_VectorConcatenate_i[2] = (rtb_Rem_p + B) * 2.0F;

        /* Gain: '<S84>/Gain' incorporates:
         *  Sum: '<S84>/Add3'
         */
        rtb_VectorConcatenate_i[3] = (rtb_MathFunction_f_idx_2 + rtb_Rem_n) *
          2.0F;

        /* Sum: '<S84>/Subtract' incorporates:
         *  Sum: '<S84>/Add'
         *  Sum: '<S84>/Add1'
         */
        rtb_VectorConcatenate_i[4] = (rtb_Add4_p + A) - (rtb_Sqrt_b +
          rtb_Sign1_c_idx_1);

        /* Product: '<S84>/Multiply2' incorporates:
         *  Product: '<S85>/Multiply2'
         */
        rtb_MathFunction_f_idx_2 = rtb_a_a * rtb_l1_a_cmd_j;

        /* Product: '<S84>/Multiply3' incorporates:
         *  Product: '<S85>/Multiply3'
         */
        rtb_Rem_n = rtb_Subtract3_d5 * rtb_Add3_c;

        /* Gain: '<S84>/Gain1' incorporates:
         *  Product: '<S84>/Multiply2'
         *  Product: '<S84>/Multiply3'
         *  Sum: '<S84>/Subtract1'
         */
        rtb_VectorConcatenate_i[5] = (rtb_MathFunction_f_idx_2 - rtb_Rem_n) *
          2.0F;

        /* Gain: '<S85>/Gain' incorporates:
         *  Sum: '<S85>/Subtract2'
         */
        rtb_VectorConcatenate_i[6] = (rtb_Rem_p - B) * 2.0F;

        /* Gain: '<S85>/Gain1' incorporates:
         *  Sum: '<S85>/Add2'
         */
        rtb_VectorConcatenate_i[7] = (rtb_MathFunction_f_idx_2 + rtb_Rem_n) *
          2.0F;

        /* Sum: '<S85>/Subtract' incorporates:
         *  Sum: '<S85>/Add'
         *  Sum: '<S85>/Add1'
         */
        rtb_VectorConcatenate_i[8] = (rtb_Add4_p + rtb_Sign1_c_idx_1) -
          (rtb_Sqrt_b + A);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Chart: '<S60>/Motion Status' incorporates:
         *  Abs: '<S60>/Abs'
         *  Abs: '<S60>/Abs1'
         *  Constant: '<S66>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S66>/Compare'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        FMS_MotionStatus_n(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_h);

        /* RelationalOperator: '<S79>/Compare' incorporates:
         *  Abs: '<S70>/Abs2'
         *  Constant: '<S79>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        rtb_FixPtRelationalOperator_me = (fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* Chart: '<S70>/Motion State' */
        if (FMS_DW.temporalCounter_i1_i < 511U) {
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

            /* Product: '<S78>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S28>/Signal Copy1'
             */
            for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++)
            {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
                rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 6] * FMS_U.INS_Out.vd
                + (rtb_VectorConcatenate_i[rtb_Compare_bv_0 + 3] *
                   FMS_U.INS_Out.ve + rtb_VectorConcatenate_i[rtb_Compare_bv_0] *
                   FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            }

            /* End of Product: '<S78>/Multiply' */
            if ((rtb_VectorConcatenate_ar[0] <= 0.1) ||
                (FMS_DW.temporalCounter_i1_i >= 500U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            } else {
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_n;
                rtb_state_ki = MotionState_Move;
              }
            }
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

        /* End of Chart: '<S70>/Motion State' */

        /* SwitchCase: '<S69>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_h;
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        switch (rtb_state_ki) {
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
            /* InitializeConditions for IfAction SubSystem: '<S69>/Hold Control' incorporates:
             *  ActionPort: '<S72>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S69>/Switch Case' incorporates:
             *  Delay: '<S72>/Delay'
             */
            FMS_DW.icLoad = 1U;

            /* End of InitializeConditions for SubSystem: '<S69>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S69>/Hold Control' incorporates:
           *  ActionPort: '<S72>/Action Port'
           */
          /* Delay: '<S72>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE = FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Trigonometry: '<S76>/Trigonometric Function1' incorporates:
           *  Gain: '<S75>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S76>/Trigonometric Function' incorporates:
           *  Gain: '<S75>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S76>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S76>/Constant3'
           */
          rtb_VectorConcatenate_i[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S76>/Gain' incorporates:
           *  Gain: '<S75>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Trigonometry: '<S76>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_i[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S76>/Trigonometric Function3' incorporates:
           *  Gain: '<S75>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           */
          rtb_VectorConcatenate_i[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S76>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S76>/Constant4'
           */
          rtb_VectorConcatenate_i[5] = 0.0F;

          /* SignalConversion: '<S76>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_i[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_VectorConcatenate_i[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_VectorConcatenate_i[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Reshape: '<S72>/Reshape' incorporates:
           *  Delay: '<S72>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S28>/Signal Copy1'
           *  Sum: '<S72>/Sum'
           */
          rtb_a_a = FMS_DW.Delay_DSTATE - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S72>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_VectorConcatenate_ar[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_i[rtb_Compare_bv_0] * rtb_a_a;
          }

          /* Gain: '<S72>/Gain2' incorporates:
           *  Product: '<S72>/Multiply'
           */
          FMS_B.Merge_p = FMS_PARAM.X_P * rtb_VectorConcatenate_ar[0];

          /* Update for Delay: '<S72>/Delay' */
          FMS_DW.icLoad = 0U;

          /* End of Outputs for SubSystem: '<S69>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S69>/Brake Control' incorporates:
           *  ActionPort: '<S71>/Action Port'
           */
          /* SignalConversion: '<S71>/OutportBuffer_InsertedFor_u_cmd_mPs_at_inport_0' incorporates:
           *  Constant: '<S71>/Brake Speed'
           */
          FMS_B.Merge_p = 0.0F;

          /* End of Outputs for SubSystem: '<S69>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S69>/Move Control' incorporates:
           *  ActionPort: '<S73>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S77>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S28>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_l1_a_cmd_j = 0.0F;
          } else {
            rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S77>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S73>/Gain6' incorporates:
           *  Gain: '<S77>/Gain'
           */
          FMS_B.Merge_p = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_l1_a_cmd_j *
            FMS_PARAM.VEL_X_LIM;

          /* End of Outputs for SubSystem: '<S69>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S69>/Switch Case' */

        /* SwitchCase: '<S59>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy1'
         *  SignalConversion: '<S28>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S59>/Hold Control' incorporates:
             *  ActionPort: '<S62>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S59>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_kw);

            /* End of SystemReset for SubSystem: '<S59>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S59>/Hold Control' incorporates:
           *  ActionPort: '<S62>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge,
                          &FMS_DW.HoldControl_kw);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S59>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S59>/Brake Control' incorporates:
           *  ActionPort: '<S61>/Action Port'
           */
          FMS_BrakeControl_b(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S59>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S59>/Move Control' incorporates:
           *  ActionPort: '<S63>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S59>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S59>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  BusAssignment: '<S39>/Bus Assignment'
         *  Constant: '<S39>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Constant: '<S39>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;
        FMS_Y.FMS_Out.theta_cmd = 0.0F;

        /* Saturate: '<S69>/Saturation1' */
        if (FMS_B.Merge_p > FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S39>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_X_LIM;
        } else if (FMS_B.Merge_p < -FMS_PARAM.VEL_X_LIM) {
          /* BusAssignment: '<S39>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_X_LIM;
        } else {
          /* BusAssignment: '<S39>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p;
        }

        /* End of Saturate: '<S69>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DeadZone: '<S68>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S28>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_l1_a_cmd_j = 0.0F;
        } else {
          rtb_l1_a_cmd_j = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S68>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         *  Gain: '<S57>/Gain6'
         *  Gain: '<S68>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.ay_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_l1_a_cmd_j
          * FMS_PARAM.ACC_Y_LIM;

        /* Saturate: '<S59>/Saturation1' */
        if (FMS_B.Merge > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S39>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S39>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S39>/Bus Assignment' incorporates:
           *  BusAssignment: '<S30>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge;
        }

        /* End of Saturate: '<S59>/Saturation1' */
        /* End of Outputs for SubSystem: '<S33>/Position' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S33>/Unknown' incorporates:
         *  ActionPort: '<S41>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S30>/Bus Assignment'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S33>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S33>/Switch Case' */
      /* End of Outputs for SubSystem: '<S29>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S29>/Manual' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S30>/Bus Assignment'
       *  BusAssignment: '<S35>/Bus Assignment'
       *  Constant: '<S35>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S35>/Bus Assignment' incorporates:
       *  BusAssignment: '<S30>/Bus Assignment'
       *  Constant: '<S35>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S29>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S29>/Unknown' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S30>/Bus Assignment'
       */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S29>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S29>/Switch Case' */
    /* End of Outputs for SubSystem: '<S27>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S27>/Switch Case' */

  /* BusAssignment: '<S30>/Bus Assignment' incorporates:
   *  Constant: '<S30>/Constant'
   *  DataStoreRead: '<S30>/Data Store Read'
   *  DataTypeConversion: '<S30>/Data Type Conversion'
   *  DiscreteIntegrator: '<S420>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S28>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S30>/Sum'
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

  /* Update for DiscreteIntegrator: '<S420>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S420>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S12>/SetHome' incorporates:
   *  TriggerPort: '<S19>/Trigger'
   */
  if (rtb_FixPtRelationalOperator_me && (FMS_PrevZCX.SetHome_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S19>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_FixPtRelationalOperator_me;

  /* End of Outputs for SubSystem: '<S12>/SetHome' */

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
  rtb_l1_a_cmd_j = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_l1_a_cmd_j < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_l1_a_cmd_j;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S22>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S22>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S17>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S18>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S23>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S24>/Delay Input1':
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
  rtb_l1_a_cmd_j = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_l1_a_cmd_j < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_l1_a_cmd_j;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
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
  /* Start for SwitchCase: '<S27>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S27>/Arm' */
  /* Start for SwitchCase: '<S29>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S29>/SubMode' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_at = -1;

  /* Start for IfAction SubSystem: '<S36>/Return' */
  /* Start for SwitchCase: '<S378>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S368>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* End of Start for SubSystem: '<S36>/Return' */

  /* Start for IfAction SubSystem: '<S36>/Hold' */
  /* Start for SwitchCase: '<S310>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;

  /* Start for SwitchCase: '<S288>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S298>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S36>/Hold' */
  /* End of Start for SubSystem: '<S29>/SubMode' */

  /* Start for IfAction SubSystem: '<S29>/Auto' */
  /* Start for SwitchCase: '<S34>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S34>/Mission' */
  /* Start for Resettable SubSystem: '<S93>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S144>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S134>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S93>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S34>/Mission' */
  /* End of Start for SubSystem: '<S29>/Auto' */

  /* Start for IfAction SubSystem: '<S29>/Assist' */
  /* Start for SwitchCase: '<S33>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S33>/Altitude' */
  /* Start for SwitchCase: '<S45>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S33>/Altitude' */

  /* Start for IfAction SubSystem: '<S33>/Position' */
  /* Start for SwitchCase: '<S69>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* Start for SwitchCase: '<S59>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* End of Start for SubSystem: '<S33>/Position' */
  /* End of Start for SubSystem: '<S29>/Assist' */
  /* End of Start for SubSystem: '<S27>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

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
  /* SystemInitialize for IfAction SubSystem: '<S27>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S29>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S36>/Takeoff' */
  /* InitializeConditions for Delay: '<S418>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S414>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S414>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S326>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S326>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Return' */
  /* InitializeConditions for Delay: '<S357>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S358>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S353>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S405>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;

  /* InitializeConditions for Delay: '<S335>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S338>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S334>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S338>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S379>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S378>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S378>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S378>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S388>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S388>/Integrator' */
  FMS_DW.Integrator_DSTATE_bz[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S378>/Move Control' */

  /* SystemInitialize for Merge: '<S378>/Merge' */
  FMS_B.Merge_a[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S378>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S388>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S388>/Integrator' */
  FMS_DW.Integrator_DSTATE_bz[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S378>/Move Control' */

  /* SystemInitialize for Merge: '<S378>/Merge' */
  FMS_B.Merge_a[1] = 0.0F;

  /* SystemInitialize for Chart: '<S369>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S368>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S368>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S368>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S368>/Move Control' */

  /* SystemInitialize for Merge: '<S368>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Hold' */
  /* SystemInitialize for Chart: '<S289>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S299>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S311>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S310>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S310>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S310>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S310>/Move Control' */

  /* SystemInitialize for Merge: '<S310>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S288>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S288>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S288>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S288>/Move Control' */

  /* SystemInitialize for Merge: '<S288>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S298>/Hold Control' */
  /* InitializeConditions for Delay: '<S301>/Delay' */
  FMS_DW.icLoad_g = 1U;

  /* End of SystemInitialize for SubSystem: '<S298>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S298>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S307>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_k = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S307>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S298>/Move Control' */

  /* SystemInitialize for Merge: '<S298>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S36>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S29>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S29>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S34>/Mission' */
  /* InitializeConditions for UnitDelay: '<S96>/Delay Input1'
   *
   * Block description for '<S96>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S93>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S123>/Delay' */
  FMS_DW.icLoad_i = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S101>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* SystemInitialize for Chart: '<S145>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S144>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S144>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S144>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S144>/Move Control' */

  /* SystemInitialize for Merge: '<S144>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S135>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S134>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S134>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S134>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S134>/Move Control' */

  /* SystemInitialize for Merge: '<S134>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S93>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S34>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S29>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S29>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S33>/Altitude' */
  /* SystemInitialize for Chart: '<S46>/Motion Status' */
  FMS_MotionStatus_h_Init(&FMS_DW.sf_MotionStatus_n);

  /* SystemInitialize for IfAction SubSystem: '<S45>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_da);

  /* End of SystemInitialize for SubSystem: '<S45>/Hold Control' */

  /* SystemInitialize for Merge: '<S45>/Merge' */
  FMS_B.Merge_py = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S33>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S33>/Position' */
  /* SystemInitialize for Chart: '<S60>/Motion Status' */
  FMS_MotionStatus_h_Init(&FMS_DW.sf_MotionStatus_h);

  /* SystemInitialize for Chart: '<S70>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S69>/Hold Control' */
  /* InitializeConditions for Delay: '<S72>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S69>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S59>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_kw);

  /* End of SystemInitialize for SubSystem: '<S59>/Hold Control' */

  /* SystemInitialize for Merge: '<S59>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for Merge: '<S69>/Merge' */
  FMS_B.Merge_p = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S33>/Position' */
  /* End of SystemInitialize for SubSystem: '<S29>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S27>/Arm' */
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
