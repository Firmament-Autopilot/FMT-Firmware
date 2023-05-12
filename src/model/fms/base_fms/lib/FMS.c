/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1932
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 12 16:41:44 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S398>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S408>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

/* Named constants for Chart: '<S130>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S45>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S341>/Motion State' */
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
  0U,                                  /* reserved */

  {
    0.0F, 0.0F, 0.0F, 0.0F }
  /* home */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_Ei9mCZP18TFowG5Mu3SiqG FMS_PARAM = {
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
  0.3F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S448>/Constant'
                                        *   '<S324>/L1'
                                        *   '<S42>/Gain'
                                        *   '<S42>/Gain1'
                                        *   '<S120>/Gain'
                                        *   '<S120>/Gain1'
                                        *   '<S146>/L1'
                                        *   '<S220>/Saturation'
                                        *   '<S221>/Saturation1'
                                        *   '<S221>/Saturation2'
                                        *   '<S221>/Saturation3'
                                        *   '<S365>/Constant'
                                        *   '<S366>/Saturation1'
                                        *   '<S439>/Gain2'
                                        *   '<S439>/Saturation1'
                                        *   '<S44>/Saturation1'
                                        *   '<S55>/Dead Zone'
                                        *   '<S55>/Gain'
                                        *   '<S56>/Dead Zone'
                                        *   '<S56>/Gain'
                                        *   '<S61>/Saturation'
                                        *   '<S77>/Saturation1'
                                        *   '<S92>/Saturation'
                                        *   '<S105>/Saturation1'
                                        *   '<S123>/Dead Zone'
                                        *   '<S123>/Gain'
                                        *   '<S124>/Dead Zone'
                                        *   '<S124>/Gain'
                                        *   '<S129>/Saturation'
                                        *   '<S274>/Gain2'
                                        *   '<S281>/Gain1'
                                        *   '<S281>/Gain2'
                                        *   '<S330>/Saturation1'
                                        *   '<S340>/Saturation'
                                        *   '<S352>/Saturation1'
                                        *   '<S367>/Gain2'
                                        *   '<S389>/vel'
                                        *   '<S389>/Saturation'
                                        *   '<S389>/Switch'
                                        *   '<S47>/Gain2'
                                        *   '<S48>/Gain1'
                                        *   '<S53>/Constant'
                                        *   '<S64>/Gain2'
                                        *   '<S65>/Gain1'
                                        *   '<S72>/Constant'
                                        *   '<S80>/Gain2'
                                        *   '<S81>/Gain1'
                                        *   '<S90>/Constant'
                                        *   '<S95>/Gain2'
                                        *   '<S96>/Gain1'
                                        *   '<S103>/Constant'
                                        *   '<S108>/Gain2'
                                        *   '<S109>/Gain6'
                                        *   '<S117>/Constant'
                                        *   '<S118>/Constant'
                                        *   '<S132>/Gain2'
                                        *   '<S133>/Gain1'
                                        *   '<S140>/Constant'
                                        *   '<S165>/Gain'
                                        *   '<S165>/Saturation1'
                                        *   '<S166>/vel'
                                        *   '<S166>/Saturation'
                                        *   '<S166>/Switch'
                                        *   '<S333>/Gain2'
                                        *   '<S334>/Gain1'
                                        *   '<S343>/Gain2'
                                        *   '<S344>/Gain1'
                                        *   '<S355>/Gain2'
                                        *   '<S356>/Gain6'
                                        *   '<S376>/Gain2'
                                        *   '<S376>/Saturation'
                                        *   '<S377>/Integrator'
                                        *   '<S50>/Constant'
                                        *   '<S52>/Dead Zone'
                                        *   '<S52>/Gain'
                                        *   '<S69>/Dead Zone'
                                        *   '<S69>/Gain'
                                        *   '<S84>/Constant'
                                        *   '<S86>/Dead Zone'
                                        *   '<S86>/Gain'
                                        *   '<S100>/Dead Zone'
                                        *   '<S100>/Gain'
                                        *   '<S113>/Dead Zone'
                                        *   '<S113>/Gain'
                                        *   '<S114>/Dead Zone'
                                        *   '<S114>/Gain'
                                        *   '<S137>/Dead Zone'
                                        *   '<S137>/Gain'
                                        *   '<S152>/Gain2'
                                        *   '<S152>/Saturation'
                                        *   '<S153>/Integrator'
                                        *   '<S336>/Dead Zone'
                                        *   '<S336>/Gain'
                                        *   '<S348>/Dead Zone'
                                        *   '<S348>/Gain'
                                        *   '<S360>/Dead Zone'
                                        *   '<S360>/Gain'
                                        *   '<S361>/Dead Zone'
                                        *   '<S361>/Gain'
                                        *   '<S397>/Saturation1'
                                        *   '<S407>/Saturation1'
                                        *   '<S177>/Saturation1'
                                        *   '<S187>/Saturation1'
                                        *   '<S400>/Gain2'
                                        *   '<S401>/Gain1'
                                        *   '<S410>/Gain2'
                                        *   '<S411>/Gain6'
                                        *   '<S180>/Gain2'
                                        *   '<S181>/Gain1'
                                        *   '<S190>/Gain2'
                                        *   '<S191>/Gain6'
                                        *   '<S403>/Dead Zone'
                                        *   '<S403>/Gain'
                                        *   '<S415>/Dead Zone'
                                        *   '<S415>/Gain'
                                        *   '<S416>/Dead Zone'
                                        *   '<S416>/Gain'
                                        *   '<S183>/Dead Zone'
                                        *   '<S183>/Gain'
                                        *   '<S195>/Dead Zone'
                                        *   '<S195>/Gain'
                                        *   '<S196>/Dead Zone'
                                        *   '<S196>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 48, 46, 52, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S11>/Constant1'
                                        *   '<S446>/Constant'
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
 *    '<S23>/Disarm'
 *    '<S32>/Unknown'
 *    '<S30>/Unknown'
 *    '<S29>/Unknown'
 *    '<S25>/Unknown'
 */
void FMS_Disarm(FMS_Out_Bus *rty_FMS_Out, const ConstB_Disarm_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S27>/Bus Assignment' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S27>/Constant2'
   *  SignalConversion: '<S27>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S27>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S397>/Hold Control'
 *    '<S330>/Hold Control'
 *    '<S177>/Hold Control'
 *    '<S44>/Hold Control'
 *    '<S77>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S400>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S397>/Hold Control'
 *    '<S330>/Hold Control'
 *    '<S177>/Hold Control'
 *    '<S44>/Hold Control'
 *    '<S77>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S400>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S397>/Hold Control'
 *    '<S330>/Hold Control'
 *    '<S177>/Hold Control'
 *    '<S44>/Hold Control'
 *    '<S77>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S400>/Delay' incorporates:
   *  Gain: '<S402>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S400>/Gain2' incorporates:
   *  Delay: '<S400>/Delay'
   *  Gain: '<S402>/Gain'
   *  Sum: '<S400>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S400>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S397>/Brake Control'
 *    '<S330>/Brake Control'
 *    '<S340>/Brake Control'
 *    '<S177>/Brake Control'
 *    '<S129>/Brake Control'
 *    '<S44>/Brake Control'
 *    '<S61>/Brake Control'
 *    '<S77>/Brake Control'
 *    '<S92>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S399>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S399>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S397>/Move Control'
 *    '<S330>/Move Control'
 *    '<S177>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S404>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S404>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S397>/Move Control'
 *    '<S330>/Move Control'
 *    '<S177>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S404>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S404>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S397>/Move Control'
 *    '<S330>/Move Control'
 *    '<S177>/Move Control'
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

  /* Product: '<S405>/Multiply1' incorporates:
   *  Constant: '<S405>/const1'
   *  DiscreteIntegrator: '<S404>/Integrator'
   */
  rtb_Add3_c = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S403>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = 0.0F;
  } else {
    rtb_a_hr = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S403>/Dead Zone' */

  /* Sum: '<S405>/Add' incorporates:
   *  DiscreteIntegrator: '<S404>/Integrator1'
   *  Gain: '<S401>/Gain1'
   *  Gain: '<S403>/Gain'
   *  Sum: '<S404>/Subtract'
   */
  rtb_Subtract3_dn = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_hr * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_c;

  /* Signum: '<S405>/Sign' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_a_hr = -1.0F;
  } else if (rtb_Subtract3_dn > 0.0F) {
    rtb_a_hr = 1.0F;
  } else {
    rtb_a_hr = rtb_Subtract3_dn;
  }

  /* End of Signum: '<S405>/Sign' */

  /* Sum: '<S405>/Add2' incorporates:
   *  Abs: '<S405>/Abs'
   *  Gain: '<S405>/Gain'
   *  Gain: '<S405>/Gain1'
   *  Product: '<S405>/Multiply2'
   *  Product: '<S405>/Multiply3'
   *  Sqrt: '<S405>/Sqrt'
   *  Sum: '<S405>/Add1'
   *  Sum: '<S405>/Subtract'
   */
  rtb_a_hr = (sqrtf((8.0F * fabsf(rtb_Subtract3_dn) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_hr + rtb_Add3_c;

  /* Sum: '<S405>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_dn - rtb_a_hr) + rtb_Add3_c;

  /* Sum: '<S405>/Add3' */
  rtb_Add3_c = rtb_Subtract3_dn + localC->d;

  /* Sum: '<S405>/Subtract1' */
  rtb_Subtract3_dn -= localC->d;

  /* Signum: '<S405>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S405>/Sign1' */

  /* Signum: '<S405>/Sign2' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S405>/Sign2' */

  /* Sum: '<S405>/Add5' incorporates:
   *  Gain: '<S405>/Gain2'
   *  Product: '<S405>/Multiply4'
   *  Sum: '<S405>/Subtract2'
   */
  rtb_a_hr += (rtb_Add3_c - rtb_Subtract3_dn) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S401>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S404>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S404>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S404>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S405>/Add6' */
  rtb_Add3_c = rtb_a_hr + localC->d;

  /* Sum: '<S405>/Subtract3' */
  rtb_Subtract3_dn = rtb_a_hr - localC->d;

  /* Signum: '<S405>/Sign5' */
  if (rtb_a_hr < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_hr;
  }

  /* End of Signum: '<S405>/Sign5' */

  /* Signum: '<S405>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S405>/Sign3' */

  /* Signum: '<S405>/Sign4' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S405>/Sign4' */

  /* Signum: '<S405>/Sign6' */
  if (rtb_a_hr < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_a_hr;
  }

  /* End of Signum: '<S405>/Sign6' */

  /* Update for DiscreteIntegrator: '<S404>/Integrator' incorporates:
   *  Constant: '<S405>/const'
   *  Gain: '<S405>/Gain3'
   *  Product: '<S405>/Divide'
   *  Product: '<S405>/Multiply5'
   *  Product: '<S405>/Multiply6'
   *  Sum: '<S405>/Subtract4'
   *  Sum: '<S405>/Subtract5'
   *  Sum: '<S405>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_hr / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3_c - rtb_Subtract3_dn) * 0.5F) - rtb_a_b * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S398>/Motion Status'
 *    '<S331>/Motion Status'
 *    '<S178>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S398>/Motion Status'
 *    '<S331>/Motion Status'
 *    '<S178>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S398>/Motion Status'
 *    '<S331>/Motion Status'
 *    '<S178>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S398>/Motion Status' */
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

  /* End of Chart: '<S398>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S407>/Hold Control'
 *    '<S352>/Hold Control'
 *    '<S187>/Hold Control'
 *    '<S105>/Hold Control'
 */
void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S410>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S407>/Hold Control'
 *    '<S352>/Hold Control'
 *    '<S187>/Hold Control'
 *    '<S105>/Hold Control'
 */
void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S410>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S407>/Hold Control'
 *    '<S352>/Hold Control'
 *    '<S187>/Hold Control'
 *    '<S105>/Hold Control'
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

  /* Delay: '<S410>/Delay' incorporates:
   *  SignalConversion: '<S410>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_p;
  }

  /* Trigonometry: '<S414>/Trigonometric Function1' incorporates:
   *  Gain: '<S413>/Gain'
   *  Trigonometry: '<S414>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bl_tmp_0 = arm_cos_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_bl_tmp_0;

  /* Trigonometry: '<S414>/Trigonometric Function' incorporates:
   *  Gain: '<S413>/Gain'
   *  Trigonometry: '<S414>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bl_tmp = arm_sin_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_bl_tmp;

  /* SignalConversion: '<S414>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S414>/Constant3'
   */
  rtb_VectorConcatenate_k[2] = 0.0F;

  /* Gain: '<S414>/Gain' */
  rtb_VectorConcatenate_k[3] = -rtb_VectorConcatenate_bl_tmp;

  /* Trigonometry: '<S414>/Trigonometric Function3' */
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_bl_tmp_0;

  /* SignalConversion: '<S414>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S414>/Constant4'
   */
  rtb_VectorConcatenate_k[5] = 0.0F;

  /* SignalConversion: '<S414>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_k[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_k[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_k[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S410>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S410>/Delay'
   *  SignalConversion: '<S410>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S410>/Sum'
   */
  rtb_VectorConcatenate_bl_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bl_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_p;

  /* Product: '<S410>/Multiply' incorporates:
   *  SignalConversion: '<S410>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bl[i] = rtb_VectorConcatenate_k[i + 3] *
      rtb_VectorConcatenate_bl_tmp + rtb_VectorConcatenate_k[i] *
      rtb_VectorConcatenate_bl_tmp_0;
  }

  /* End of Product: '<S410>/Multiply' */

  /* Gain: '<S410>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[1];

  /* Update for Delay: '<S410>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S407>/Brake Control'
 *    '<S352>/Brake Control'
 *    '<S187>/Brake Control'
 *    '<S105>/Brake Control'
 */
void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S409>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S407>/Move Control'
 *    '<S352>/Move Control'
 *    '<S187>/Move Control'
 *    '<S105>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S407>/Move Control'
 *    '<S352>/Move Control'
 *    '<S187>/Move Control'
 *    '<S105>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S417>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S407>/Move Control'
 *    '<S352>/Move Control'
 *    '<S187>/Move Control'
 *    '<S105>/Move Control'
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

  /* SignalConversion: '<S411>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S417>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S418>/Multiply1' incorporates:
   *  Constant: '<S418>/const1'
   *  DiscreteIntegrator: '<S417>/Integrator'
   */
  rtb_Add3_e1_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S411>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S417>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S418>/Multiply1' incorporates:
   *  Constant: '<S418>/const1'
   *  DiscreteIntegrator: '<S417>/Integrator'
   */
  rtb_Add3_e1_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S415>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S415>/Dead Zone' */

  /* Sum: '<S418>/Add' incorporates:
   *  DiscreteIntegrator: '<S417>/Integrator1'
   *  Gain: '<S411>/Gain6'
   *  Gain: '<S415>/Gain'
   *  Sum: '<S417>/Subtract'
   */
  rtb_Subtract3_h_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_0;

  /* DeadZone: '<S416>/Dead Zone' */
  if (rtu_FMS_In_g > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_g >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S416>/Dead Zone' */

  /* Sum: '<S418>/Add' incorporates:
   *  DiscreteIntegrator: '<S417>/Integrator1'
   *  Gain: '<S411>/Gain6'
   *  Gain: '<S416>/Gain'
   *  Sum: '<S417>/Subtract'
   */
  rtb_Subtract3_h_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_1;

  /* Signum: '<S418>/Sign' */
  if (rtb_Subtract3_h_idx_0 < 0.0F) {
    rtb_Subtract3_h_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0 > 0.0F) {
    rtb_Subtract3_h_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0_0 = rtb_Subtract3_h_idx_0;
  }

  /* Sum: '<S418>/Add2' incorporates:
   *  Abs: '<S418>/Abs'
   *  Gain: '<S418>/Gain'
   *  Gain: '<S418>/Gain1'
   *  Product: '<S418>/Multiply2'
   *  Product: '<S418>/Multiply3'
   *  Signum: '<S418>/Sign'
   *  Sqrt: '<S418>/Sqrt'
   *  Sum: '<S418>/Add1'
   *  Sum: '<S418>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_h_idx_0_0 +
    rtb_Add3_e1_idx_0;

  /* Sum: '<S418>/Add3' incorporates:
   *  Signum: '<S418>/Sign'
   */
  u = rtb_Subtract3_h_idx_0 + localC->d;

  /* Sum: '<S418>/Subtract1' incorporates:
   *  Signum: '<S418>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_0 - localC->d;

  /* Signum: '<S418>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S418>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S418>/Add5' incorporates:
   *  Gain: '<S418>/Gain2'
   *  Product: '<S418>/Multiply4'
   *  Signum: '<S418>/Sign'
   *  Sum: '<S418>/Add2'
   *  Sum: '<S418>/Add4'
   *  Sum: '<S418>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_0 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_0) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S417>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S417>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S418>/Sign3' incorporates:
   *  Sum: '<S418>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S418>/Sign4' incorporates:
   *  Sum: '<S418>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S418>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S418>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S418>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S418>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S417>/Integrator' incorporates:
   *  Constant: '<S418>/const'
   *  Gain: '<S418>/Gain3'
   *  Product: '<S418>/Divide'
   *  Product: '<S418>/Multiply5'
   *  Product: '<S418>/Multiply6'
   *  Sum: '<S418>/Subtract4'
   *  Sum: '<S418>/Subtract5'
   *  Sum: '<S418>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;

  /* Signum: '<S418>/Sign' */
  if (rtb_Subtract3_h_idx_1 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_1 > 0.0F) {
    rtb_Add3_e1_idx_0 = 1.0F;
  } else {
    rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_1;
  }

  /* Sum: '<S418>/Add2' incorporates:
   *  Abs: '<S418>/Abs'
   *  Gain: '<S418>/Gain'
   *  Gain: '<S418>/Gain1'
   *  Product: '<S418>/Multiply2'
   *  Product: '<S418>/Multiply3'
   *  Signum: '<S418>/Sign'
   *  Sqrt: '<S418>/Sqrt'
   *  Sum: '<S418>/Add1'
   *  Sum: '<S418>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_e1_idx_0 +
    rtb_Add3_e1_idx_1;

  /* Sum: '<S418>/Add3' incorporates:
   *  Signum: '<S418>/Sign'
   */
  u = rtb_Subtract3_h_idx_1 + localC->d;

  /* Sum: '<S418>/Subtract1' incorporates:
   *  Signum: '<S418>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_1 - localC->d;

  /* Signum: '<S418>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S418>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S418>/Add5' incorporates:
   *  Gain: '<S418>/Gain2'
   *  Product: '<S418>/Multiply4'
   *  Signum: '<S418>/Sign'
   *  Sum: '<S418>/Add2'
   *  Sum: '<S418>/Add4'
   *  Sum: '<S418>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_1 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_1) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S417>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S417>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S418>/Sign3' incorporates:
   *  Sum: '<S418>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S418>/Sign4' incorporates:
   *  Sum: '<S418>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S418>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S418>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S418>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S418>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S417>/Integrator' incorporates:
   *  Constant: '<S418>/const'
   *  Gain: '<S418>/Gain3'
   *  Product: '<S418>/Divide'
   *  Product: '<S418>/Multiply5'
   *  Product: '<S418>/Multiply6'
   *  Sum: '<S418>/Subtract4'
   *  Sum: '<S418>/Subtract5'
   *  Sum: '<S418>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S408>/Motion State'
 *    '<S353>/Motion State'
 *    '<S188>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * System reset for atomic system:
 *    '<S408>/Motion State'
 *    '<S353>/Motion State'
 *    '<S188>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * Output and update for atomic system:
 *    '<S408>/Motion State'
 *    '<S353>/Motion State'
 *    '<S188>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S408>/Motion State' */
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

  /* End of Chart: '<S408>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S391>/NearbyRefWP'
 *    '<S168>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S422>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S340>/Hold Control'
 *    '<S129>/Hold Control'
 *    '<S61>/Hold Control'
 *    '<S92>/Hold Control'
 */
void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S343>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S340>/Hold Control'
 *    '<S129>/Hold Control'
 *    '<S61>/Hold Control'
 *    '<S92>/Hold Control'
 */
void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S343>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S340>/Hold Control'
 *    '<S129>/Hold Control'
 *    '<S61>/Hold Control'
 *    '<S92>/Hold Control'
 */
void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S343>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S343>/Sum' incorporates:
   *  Delay: '<S343>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S346>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S346>/Switch' incorporates:
   *  Constant: '<S346>/Constant'
   *  Constant: '<S347>/Constant'
   *  Product: '<S346>/Multiply'
   *  RelationalOperator: '<S347>/Compare'
   *  Sum: '<S346>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S346>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S346>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S346>/Switch' */

  /* Gain: '<S343>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S343>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S340>/Move Control'
 *    '<S129>/Move Control'
 *    '<S61>/Move Control'
 *    '<S92>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S349>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S349>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S340>/Move Control'
 *    '<S129>/Move Control'
 *    '<S61>/Move Control'
 *    '<S92>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S349>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S349>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S340>/Move Control'
 *    '<S129>/Move Control'
 *    '<S61>/Move Control'
 *    '<S92>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_a;
  real32_T rtb_Subtract3_i;
  real32_T rtb_a_b;
  real32_T rtb_Add4_bf;
  real32_T rtb_a_p;

  /* Product: '<S350>/Multiply1' incorporates:
   *  Constant: '<S350>/const1'
   *  DiscreteIntegrator: '<S349>/Integrator'
   */
  rtb_Add3_a = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S348>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_b = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_b = 0.0F;
  } else {
    rtb_a_b = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S348>/Dead Zone' */

  /* Sum: '<S350>/Add' incorporates:
   *  DiscreteIntegrator: '<S349>/Integrator1'
   *  Gain: '<S344>/Gain1'
   *  Gain: '<S348>/Gain'
   *  Sum: '<S349>/Subtract'
   */
  rtb_Subtract3_i = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_b * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_a;

  /* Signum: '<S350>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_Subtract3_i;
  }

  /* End of Signum: '<S350>/Sign' */

  /* Sum: '<S350>/Add2' incorporates:
   *  Abs: '<S350>/Abs'
   *  Gain: '<S350>/Gain'
   *  Gain: '<S350>/Gain1'
   *  Product: '<S350>/Multiply2'
   *  Product: '<S350>/Multiply3'
   *  Sqrt: '<S350>/Sqrt'
   *  Sum: '<S350>/Add1'
   *  Sum: '<S350>/Subtract'
   */
  rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_b + rtb_Add3_a;

  /* Sum: '<S350>/Add4' */
  rtb_Add4_bf = (rtb_Subtract3_i - rtb_a_b) + rtb_Add3_a;

  /* Sum: '<S350>/Add3' */
  rtb_Add3_a = rtb_Subtract3_i + localC->d;

  /* Sum: '<S350>/Subtract1' */
  rtb_Subtract3_i -= localC->d;

  /* Signum: '<S350>/Sign1' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S350>/Sign1' */

  /* Signum: '<S350>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S350>/Sign2' */

  /* Sum: '<S350>/Add5' incorporates:
   *  Gain: '<S350>/Gain2'
   *  Product: '<S350>/Multiply4'
   *  Sum: '<S350>/Subtract2'
   */
  rtb_a_b += (rtb_Add3_a - rtb_Subtract3_i) * 0.5F * rtb_Add4_bf;

  /* SignalConversion: '<S344>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S349>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S349>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S349>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S350>/Add6' */
  rtb_Add3_a = rtb_a_b + localC->d;

  /* Sum: '<S350>/Subtract3' */
  rtb_Subtract3_i = rtb_a_b - localC->d;

  /* Signum: '<S350>/Sign5' */
  if (rtb_a_b < 0.0F) {
    rtb_Add4_bf = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_Add4_bf = 1.0F;
  } else {
    rtb_Add4_bf = rtb_a_b;
  }

  /* End of Signum: '<S350>/Sign5' */

  /* Signum: '<S350>/Sign3' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S350>/Sign3' */

  /* Signum: '<S350>/Sign4' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S350>/Sign4' */

  /* Signum: '<S350>/Sign6' */
  if (rtb_a_b < 0.0F) {
    rtb_a_p = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_a_p = 1.0F;
  } else {
    rtb_a_p = rtb_a_b;
  }

  /* End of Signum: '<S350>/Sign6' */

  /* Update for DiscreteIntegrator: '<S349>/Integrator' incorporates:
   *  Constant: '<S350>/const'
   *  Gain: '<S350>/Gain3'
   *  Product: '<S350>/Divide'
   *  Product: '<S350>/Multiply5'
   *  Product: '<S350>/Multiply6'
   *  Sum: '<S350>/Subtract4'
   *  Sum: '<S350>/Subtract5'
   *  Sum: '<S350>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_b / localC->d - rtb_Add4_bf) *
    localC->Gain4 * ((rtb_Add3_a - rtb_Subtract3_i) * 0.5F) - rtb_a_p *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S130>/Motion State'
 *    '<S62>/Motion State'
 *    '<S93>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S130>/Motion State'
 *    '<S62>/Motion State'
 *    '<S93>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S130>/Motion State'
 *    '<S62>/Motion State'
 *    '<S93>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S130>/Motion State' */
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

  /* End of Chart: '<S130>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S44>/Move Control'
 *    '<S77>/Move Control'
 */
void FMS_MoveControl_l(real32_T rtu_FMS_In, real32_T rtu_FMS_In_l, uint32_T
  rtu_FMS_In_i, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_hp;

  /* DeadZone: '<S52>/Dead Zone' */
  if (rtu_FMS_In_l > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_hp = rtu_FMS_In_l - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In_l >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_hp = 0.0F;
  } else {
    rtb_Gain1_hp = rtu_FMS_In_l - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S52>/Dead Zone' */

  /* Gain: '<S48>/Gain1' incorporates:
   *  Gain: '<S52>/Gain'
   */
  rtb_Gain1_hp = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_hp *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S50>/Constant'
   *  Constant: '<S51>/Constant'
   *  Gain: '<S48>/Gain'
   *  Logic: '<S48>/Logical Operator'
   *  RelationalOperator: '<S50>/Compare'
   *  RelationalOperator: '<S51>/Compare'
   *  S-Function (sfix_bitop): '<S48>/cmd_p valid'
   */
  if ((rtb_Gain1_hp > 0.0F) && ((rtu_FMS_In_i & 256U) != 0U) && (rtu_FMS_In <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * rtb_Gain1_hp;
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_hp;
  }

  /* End of Switch: '<S48>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S45>/Motion Status'
 *    '<S78>/Motion Status'
 */
void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S45>/Motion Status'
 *    '<S78>/Motion Status'
 */
void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S45>/Motion Status'
 *    '<S78>/Motion Status'
 */
void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW)
{
  /* Chart: '<S45>/Motion Status' */
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

  /* End of Chart: '<S45>/Motion Status' */
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
  real_T rtb_Sum3_l;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S450>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S451>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S451>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S451>/Multiply1' incorporates:
   *  Product: '<S451>/Multiply'
   */
  rtb_Gain_d = localC->ff * rtb_Sum2_ee;

  /* Product: '<S451>/Divide' incorporates:
   *  Constant: '<S451>/Constant'
   *  Constant: '<S451>/R'
   *  Sqrt: '<S451>/Sqrt'
   *  Sum: '<S451>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_d);

  /* Product: '<S451>/Product3' incorporates:
   *  Constant: '<S451>/Constant1'
   *  Product: '<S451>/Multiply1'
   *  Sum: '<S451>/Sum2'
   */
  rtb_Gain_d = 1.0 / (1.0 - rtb_Gain_d) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S451>/Multiply2' incorporates:
   *  Trigonometry: '<S451>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S450>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S455>/Abs' incorporates:
   *  Abs: '<S458>/Abs1'
   *  Switch: '<S455>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S455>/Switch1' incorporates:
   *  Abs: '<S455>/Abs'
   *  Bias: '<S455>/Bias2'
   *  Bias: '<S455>/Bias3'
   *  Constant: '<S452>/Constant'
   *  Constant: '<S452>/Constant1'
   *  Constant: '<S457>/Constant'
   *  Gain: '<S455>/Gain1'
   *  Product: '<S455>/Multiply'
   *  RelationalOperator: '<S457>/Compare'
   *  Switch: '<S452>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S458>/Switch1' incorporates:
     *  Bias: '<S458>/Bias2'
     *  Bias: '<S458>/Bias3'
     *  Constant: '<S458>/Constant'
     *  Constant: '<S459>/Constant'
     *  Math: '<S458>/Math Function'
     *  RelationalOperator: '<S459>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S458>/Switch1' */

    /* Signum: '<S455>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S455>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S452>/Sum' incorporates:
   *  Sum: '<S450>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S450>/Multiply' incorporates:
   *  Gain: '<S450>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_d;

  /* Switch: '<S454>/Switch1' incorporates:
   *  Abs: '<S454>/Abs1'
   *  Bias: '<S454>/Bias2'
   *  Bias: '<S454>/Bias3'
   *  Constant: '<S454>/Constant'
   *  Constant: '<S456>/Constant'
   *  Math: '<S454>/Math Function'
   *  RelationalOperator: '<S456>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S454>/Switch1' */

  /* Product: '<S450>/Multiply' incorporates:
   *  Gain: '<S450>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S450>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S453>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_d = cos(rtb_Sum2_ee);

  /* Sum: '<S453>/Sum2' incorporates:
   *  Product: '<S453>/Multiply1'
   *  Product: '<S453>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_d + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S453>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S453>/Multiply4' */
  rtb_Gain_d *= rtb_Sum_d;

  /* Sum: '<S453>/Sum3' */
  rtb_Sum3_l = rtb_Gain_d - rtb_Sum3_l;

  /* DataTypeConversion: '<S447>/Data Type Conversion' incorporates:
   *  Gain: '<S450>/Gain'
   *  Sum: '<S450>/Sum1'
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

  /* Outputs for Function Call SubSystem: '<S4>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S460>/Compare' incorporates:
   *  Abs: '<S449>/Abs'
   *  Constant: '<S460>/Constant'
   *  MinMax: '<S449>/Max'
   *  Sum: '<S449>/Sum'
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
          FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
          FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
          FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_SubMode = FMS_IN_Land;
          FMS_B.state = VehicleState_Land;
          FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
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

    /* Outputs for Function Call SubSystem: '<S4>/Vehicle.PrepTakeoff' */
    /* Reshape: '<S448>/Reshape' incorporates:
     *  Constant: '<S448>/Constant'
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
    FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
    FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
    FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
    FMS_DW.home[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
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
    FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
    FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
    FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
    FMS_DW.home[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
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
      if (FMS_B.target_mode == PilotMode_Mission) {
        /* Inport: '<Root>/Mission_Data' */
        if ((FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          FMS_DW.prep_mission_takeoff = 1.0;
          FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff ==
            1.0);
          FMS_DW.prep_takeoff = 0.0;
          FMS_DW.condWasTrueAtLastTimeStep_1_k = (FMS_DW.prep_takeoff == 1.0);
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
  real32_T B;
  real32_T D;
  real32_T rtb_Saturation_n;
  real32_T rtb_Transpose[9];
  real32_T rtb_MatrixConcatenate3[3];
  real32_T rtb_Multiply_o[3];
  uint16_T rtb_Divide_b;
  FMS_Cmd rtb_DataTypeConversion1_m;
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
  boolean_T rtb_Switch_p_idx_1;
  real_T rtb_Multiply_l5_idx_0;
  real32_T u1_tmp;
  uint32_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;
  boolean_T guard1 = false;

  /* Sqrt: '<S470>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S470>/Square'
   *  Sum: '<S470>/Sum of Elements'
   */
  rtb_Saturation_n = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
    FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
    FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S466>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Rem_k = FMS_U.INS_Out.quat[0] / rtb_Saturation_n;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Saturation_n;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_n;
  rtb_Saturation_n = FMS_U.INS_Out.quat[3] / rtb_Saturation_n;

  /* Math: '<S467>/Square' incorporates:
   *  Math: '<S468>/Square'
   *  Math: '<S469>/Square'
   */
  rtb_MathFunction_h_idx_0 = rtb_Rem_k * rtb_Rem_k;

  /* Math: '<S467>/Square2' incorporates:
   *  Math: '<S468>/Square2'
   *  Math: '<S469>/Square2'
   */
  rtb_MathFunction_h_idx_1 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S467>/Square1' incorporates:
   *  Math: '<S468>/Square1'
   *  Math: '<S469>/Square1'
   */
  rtb_Switch_k = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S467>/Square3' incorporates:
   *  Math: '<S468>/Square3'
   *  Math: '<S469>/Square3'
   */
  rtb_a_i = rtb_Saturation_n * rtb_Saturation_n;

  /* Sum: '<S467>/Subtract' incorporates:
   *  Math: '<S467>/Square'
   *  Math: '<S467>/Square1'
   *  Math: '<S467>/Square2'
   *  Math: '<S467>/Square3'
   *  Sum: '<S467>/Add'
   *  Sum: '<S467>/Add1'
   */
  rtb_Transpose[0] = (rtb_MathFunction_h_idx_0 + rtb_Switch_k) -
    (rtb_MathFunction_h_idx_1 + rtb_a_i);

  /* Product: '<S467>/Multiply' incorporates:
   *  Product: '<S468>/Multiply'
   */
  rtb_MathFunction_iq_idx_0 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S467>/Multiply1' incorporates:
   *  Product: '<S468>/Multiply1'
   */
  rtb_P_d_idx_0 = rtb_Rem_k * rtb_Saturation_n;

  /* Gain: '<S467>/Gain' incorporates:
   *  Product: '<S467>/Multiply'
   *  Product: '<S467>/Multiply1'
   *  Sum: '<S467>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_MathFunction_iq_idx_0 - rtb_P_d_idx_0) * 2.0F;

  /* Product: '<S467>/Multiply2' incorporates:
   *  Product: '<S469>/Multiply'
   */
  rtb_Rem_o = rtb_Divide_l_idx_1 * rtb_Saturation_n;

  /* Product: '<S467>/Multiply3' incorporates:
   *  Product: '<S469>/Multiply1'
   */
  B = rtb_Rem_k * rtb_Divide_l_idx_2;

  /* Gain: '<S467>/Gain1' incorporates:
   *  Product: '<S467>/Multiply2'
   *  Product: '<S467>/Multiply3'
   *  Sum: '<S467>/Add2'
   */
  rtb_Transpose[2] = (rtb_Rem_o + B) * 2.0F;

  /* Gain: '<S468>/Gain' incorporates:
   *  Sum: '<S468>/Add3'
   */
  rtb_Transpose[3] = (rtb_MathFunction_iq_idx_0 + rtb_P_d_idx_0) * 2.0F;

  /* Sum: '<S468>/Subtract' incorporates:
   *  Sum: '<S468>/Add'
   *  Sum: '<S468>/Add1'
   */
  rtb_Transpose[4] = (rtb_MathFunction_h_idx_0 + rtb_MathFunction_h_idx_1) -
    (rtb_Switch_k + rtb_a_i);

  /* Product: '<S468>/Multiply2' incorporates:
   *  Product: '<S469>/Multiply2'
   */
  rtb_MathFunction_iq_idx_0 = rtb_Divide_l_idx_2 * rtb_Saturation_n;

  /* Product: '<S468>/Multiply3' incorporates:
   *  Product: '<S469>/Multiply3'
   */
  rtb_P_d_idx_0 = rtb_Rem_k * rtb_Divide_l_idx_1;

  /* Gain: '<S468>/Gain1' incorporates:
   *  Product: '<S468>/Multiply2'
   *  Product: '<S468>/Multiply3'
   *  Sum: '<S468>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_MathFunction_iq_idx_0 - rtb_P_d_idx_0) * 2.0F;

  /* Gain: '<S469>/Gain' incorporates:
   *  Sum: '<S469>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Rem_o - B) * 2.0F;

  /* Gain: '<S469>/Gain1' incorporates:
   *  Sum: '<S469>/Add2'
   */
  rtb_Transpose[7] = (rtb_MathFunction_iq_idx_0 + rtb_P_d_idx_0) * 2.0F;

  /* Sum: '<S469>/Subtract' incorporates:
   *  Sum: '<S469>/Add'
   *  Sum: '<S469>/Add1'
   */
  rtb_Transpose[8] = (rtb_MathFunction_h_idx_0 + rtb_a_i) - (rtb_Switch_k +
    rtb_MathFunction_h_idx_1);

  /* Math: '<S5>/Transpose' */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bl[3 * i] = rtb_Transpose[i];
    rtb_VectorConcatenate_bl[1 + 3 * i] = rtb_Transpose[i + 3];
    rtb_VectorConcatenate_bl[2 + 3 * i] = rtb_Transpose[i + 6];
  }

  for (i = 0; i < 9; i++) {
    rtb_Transpose[i] = rtb_VectorConcatenate_bl[i];
  }

  /* End of Math: '<S5>/Transpose' */

  /* Product: '<S5>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply_o[i] = rtb_Transpose[i + 6] * FMS_U.INS_Out.az +
      (rtb_Transpose[i + 3] * FMS_U.INS_Out.ay + rtb_Transpose[i] *
       FMS_U.INS_Out.ax);
  }

  /* End of Product: '<S5>/Multiply' */

  /* DiscreteIntegrator: '<S461>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Multiply_o[0];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply_o[1];
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply_o[2];
  }

  /* Product: '<S5>/Divide' incorporates:
   *  Inport: '<Root>/Control_Out'
   *  Sum: '<S5>/Sum of Elements'
   */
  rtb_Divide_b = (uint16_T)((uint32_T)(uint16_T)((((uint32_T)
    FMS_U.Control_Out.actuator_cmd[0] + FMS_U.Control_Out.actuator_cmd[1]) +
    FMS_U.Control_Out.actuator_cmd[2]) + FMS_U.Control_Out.actuator_cmd[3]) >> 2);

  /* DiscreteIntegrator: '<S463>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S463>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Product: '<S5>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S5>/Cos'
   *  Trigonometry: '<S5>/Cos1'
   */
  rtb_Divide_l_idx_1 = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32
    (FMS_U.INS_Out.theta);

  /* Saturate: '<S5>/Saturation' */
  if (rtb_Divide_l_idx_1 > 1.0F) {
    rtb_Divide_l_idx_1 = 1.0F;
  } else {
    if (rtb_Divide_l_idx_1 < 0.9F) {
      rtb_Divide_l_idx_1 = 0.9F;
    }
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Product: '<S5>/Divide1' */
  rtb_Divide_l_idx_2 = 1250.0F / rtb_Divide_l_idx_1;

  /* DiscreteIntegrator: '<S462>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_l_idx_2;
  }

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S461>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S462>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S463>/Discrete-Time Integrator5'
   *  Logic: '<S464>/AND'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S464>/Lower Test'
   *  RelationalOperator: '<S464>/Upper Test'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  FMS_B.on_ground = ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] <= 0.5F) &&
                     ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] <= 0.5F)) &&
                     ((-10.306F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) &&
                      (FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] <= -9.306F)) &&
                     (FMS_DW.DiscreteTimeIntegrator5_DSTAT_d <
                      FMS_DW.DiscreteTimeIntegrator5_DSTAT_k));

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

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
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

         case PilotMode_Offboard:
          FMS_DW.is_c3_FMS = FMS_IN_Offboard_p;
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
  if ((!FMS_B.on_ground) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d = FMS_B.on_ground;
  rtb_Switch_p_idx_1 = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_Switch_p_idx_1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
    FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_k = rtb_Switch_p_idx_1;
  rtb_Switch_p_idx_1 = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_Switch_p_idx_1) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_Switch_p_idx_1;
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
  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  /* SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_MatrixConcatenate3[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_MatrixConcatenate3[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_MatrixConcatenate3[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

  /* SwitchCase: '<S23>/Switch Case' incorporates:
   *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S25>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S32>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S407>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S397>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S352>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S330>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S340>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S30>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S142>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S187>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S177>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S142>/Mission_SubSystem' */
      }

      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S29>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 4:
        break;

       case 1:
        /* Disable for SwitchCase: '<S129>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S44>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S61>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S77>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S105>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S92>/Switch Case' */
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

    /* End of Disable for SwitchCase: '<S25>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S23>/Disarm' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S26>/Bus Assignment'
     */
    FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Disarm);

    /* End of Outputs for SubSystem: '<S23>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S23>/Standby' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S26>/Bus Assignment'
     *  BusAssignment: '<S28>/Bus Assignment'
     *  Constant: '<S28>/Constant'
     *  SignalConversion: '<S28>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S28>/Bus Assignment' incorporates:
     *  BusAssignment: '<S26>/Bus Assignment'
     *  Constant: '<S28>/Constant2'
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

    /* End of Outputs for SubSystem: '<S23>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S23>/Arm' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* SwitchCase: '<S25>/Switch Case' */
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
        /* Disable for SwitchCase: '<S32>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S407>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S397>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S352>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S330>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S340>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S30>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S142>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S187>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S177>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S142>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S29>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S129>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S44>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S61>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S77>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S105>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S92>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S25>/SubMode' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      /* SwitchCase: '<S32>/Switch Case' incorporates:
       *  Math: '<S429>/Math Function'
       *  Product: '<S431>/Divide'
       *  Sum: '<S392>/Subtract'
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
          /* Disable for SwitchCase: '<S407>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S397>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S352>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S330>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S340>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S32>/Takeoff' incorporates:
           *  ActionPort: '<S325>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S32>/Switch Case' incorporates:
           *  Delay: '<S444>/cur_waypoint'
           */
          FMS_DW.icLoad_j1 = 1U;

          /* End of InitializeConditions for SubSystem: '<S32>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S32>/Takeoff' incorporates:
         *  ActionPort: '<S325>/Action Port'
         */
        /* Delay: '<S444>/cur_waypoint' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j1 != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
          FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Product: '<S444>/Divide' incorporates:
         *  Delay: '<S444>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S444>/Sum1'
         *  Sum: '<S444>/Sum2'
         */
        rtb_Divide_l_idx_1 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
          FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S444>/Saturation' */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Divide_l_idx_1 = 0.0F;
          }
        }

        /* End of Saturate: '<S444>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S445>/Trigonometric Function1' incorporates:
         *  Gain: '<S443>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Trigonometry: '<S445>/Trigonometric Function3'
         */
        rtb_MathFunction_h_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S445>/Trigonometric Function' incorporates:
         *  Gain: '<S443>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Trigonometry: '<S445>/Trigonometric Function2'
         */
        rtb_MathFunction_h_idx_1 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

        /* SignalConversion: '<S445>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S445>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S445>/Gain' */
        rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S445>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

        /* SignalConversion: '<S445>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S445>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S445>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S439>/Saturation1' */
        rtb_Switch_k = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Rem_k = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* SignalConversion: '<S439>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S444>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S444>/Multiply'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S439>/Sum'
         *  Sum: '<S444>/Sum3'
         *  Sum: '<S444>/Sum4'
         */
        rtb_Saturation_n = ((FMS_B.Cmd_In.sp_waypoint[0] -
                             FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_l_idx_1
                            + FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_a_i = ((FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.cur_waypoint_DSTATE[1])
                   * rtb_Divide_l_idx_1 + FMS_DW.cur_waypoint_DSTATE[1]) -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S439>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i]
            * rtb_Saturation_n;
        }

        /* Saturate: '<S439>/Saturation1' incorporates:
         *  Gain: '<S439>/Gain2'
         *  Product: '<S439>/Multiply'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_a_i = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S325>/Bus Assignment1'
         *  Constant: '<S325>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S325>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S325>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S439>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Switch_k) {
          /* BusAssignment: '<S325>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_k;
        } else if (rtb_Divide_l_idx_1 < rtb_Rem_k) {
          /* BusAssignment: '<S325>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S325>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_a_i > rtb_Switch_k) {
          /* BusAssignment: '<S325>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_k;
        } else if (rtb_a_i < rtb_Rem_k) {
          /* BusAssignment: '<S325>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S325>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_i;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S438>/Switch' incorporates:
         *  Abs: '<S438>/Abs'
         *  Abs: '<S438>/Abs1'
         *  Constant: '<S440>/Constant'
         *  Constant: '<S441>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S438>/Logical Operator'
         *  RelationalOperator: '<S440>/Compare'
         *  RelationalOperator: '<S441>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S438>/Sum'
         *  Sum: '<S438>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          /* BusAssignment: '<S325>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Constant: '<S438>/Constant6'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -1.0F;
        } else {
          /* BusAssignment: '<S325>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Constant: '<S438>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -0.5F;
        }

        /* End of Switch: '<S438>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Update for Delay: '<S444>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* End of Outputs for SubSystem: '<S32>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S32>/Land' incorporates:
         *  ActionPort: '<S323>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S370>/Trigonometric Function1' incorporates:
         *  Gain: '<S369>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S370>/Trigonometric Function' incorporates:
         *  Gain: '<S369>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SignalConversion: '<S370>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S370>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S370>/Gain' incorporates:
         *  Gain: '<S369>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Trigonometry: '<S370>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S370>/Trigonometric Function3' incorporates:
         *  Gain: '<S369>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SignalConversion: '<S370>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S370>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S370>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S366>/Saturation1' */
        rtb_Switch_k = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Rem_k = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* SignalConversion: '<S367>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S367>/Sum'
         */
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_a_i = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S367>/Multiply' incorporates:
         *  SignalConversion: '<S367>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i]
            * rtb_Saturation_n;
        }

        /* End of Product: '<S367>/Multiply' */

        /* Saturate: '<S366>/Saturation1' incorporates:
         *  Gain: '<S367>/Gain2'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_a_i = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S323>/Bus Assignment1'
         *  Constant: '<S323>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S323>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S323>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S366>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Switch_k) {
          /* BusAssignment: '<S323>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_k;
        } else if (rtb_Divide_l_idx_1 < rtb_Rem_k) {
          /* BusAssignment: '<S323>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S323>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_a_i > rtb_Switch_k) {
          /* BusAssignment: '<S323>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_k;
        } else if (rtb_a_i < rtb_Rem_k) {
          /* BusAssignment: '<S323>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S323>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_i;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S323>/Switch' incorporates:
         *  Constant: '<S365>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S323>/Logical Operator'
         *  RelationalOperator: '<S365>/Compare'
         *  S-Function (sfix_bitop): '<S323>/cmd_p valid'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          /* BusAssignment: '<S323>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Constant: '<S323>/Constant5'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = 0.25F;
        } else {
          /* BusAssignment: '<S323>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Constant: '<S323>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = 0.5F;
        }

        /* End of Switch: '<S323>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S32>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S32>/Return' incorporates:
           *  ActionPort: '<S324>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S32>/Switch Case' incorporates:
           *  Delay: '<S373>/Delay'
           *  Delay: '<S374>/Delay'
           *  Delay: '<S393>/Delay'
           *  DiscreteIntegrator: '<S377>/Integrator'
           *  DiscreteIntegrator: '<S377>/Integrator1'
           *  DiscreteIntegrator: '<S434>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_o = 1U;
          FMS_DW.l1_heading_p = 0.0F;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S32>/Return' */

          /* SystemReset for IfAction SubSystem: '<S32>/Return' incorporates:
           *  ActionPort: '<S324>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S32>/Switch Case' incorporates:
           *  Chart: '<S398>/Motion Status'
           *  Chart: '<S408>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S32>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S32>/Return' incorporates:
         *  ActionPort: '<S324>/Action Port'
         */
        /* Delay: '<S393>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        if (FMS_DW.icLoad_o != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S389>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];
        rtb_MathFunction_iq_idx_0 = FMS_U.INS_Out.y_R -
          FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sqrt: '<S394>/Sqrt' incorporates:
         *  Math: '<S394>/Square'
         *  Sum: '<S389>/Sum'
         *  Sum: '<S394>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

        /* Switch: '<S389>/Switch' incorporates:
         *  Constant: '<S389>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S389>/Gain' */
          rtb_Switch_k = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S389>/Saturation' */
          if (rtb_Switch_k > FMS_PARAM.CRUISE_SPEED) {
            rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Switch_k < 0.5F) {
              rtb_Switch_k = 0.5F;
            }
          }

          /* End of Saturate: '<S389>/Saturation' */
        }

        /* End of Switch: '<S389>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S408>/Motion State' incorporates:
         *  Constant: '<S408>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S408>/Square'
         *  Math: '<S408>/Square1'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sqrt: '<S408>/Sqrt'
         *  Sum: '<S408>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S407>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S407>/Hold Control' incorporates:
             *  ActionPort: '<S410>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S407>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S407>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S407>/Hold Control' incorporates:
           *  ActionPort: '<S410>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_mv,
                            &FMS_ConstB.HoldControl_k, &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S407>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S407>/Brake Control' incorporates:
           *  ActionPort: '<S409>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_mv);

          /* End of Outputs for SubSystem: '<S407>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S407>/Move Control' incorporates:
             *  ActionPort: '<S411>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S407>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S407>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S407>/Move Control' incorporates:
           *  ActionPort: '<S411>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_mv,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S407>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S407>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S398>/Motion Status' incorporates:
         *  Abs: '<S398>/Abs'
         *  Constant: '<S398>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S397>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S397>/Hold Control' incorporates:
             *  ActionPort: '<S400>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S397>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S397>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S397>/Hold Control' incorporates:
           *  ActionPort: '<S400>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S397>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S397>/Brake Control' incorporates:
           *  ActionPort: '<S399>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S397>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S397>/Move Control' incorporates:
             *  ActionPort: '<S401>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S397>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S397>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S397>/Move Control' incorporates:
           *  ActionPort: '<S401>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S397>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S397>/Switch Case' */

        /* Delay: '<S373>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S324>/Sum' incorporates:
         *  Delay: '<S373>/Delay'
         *  MATLAB Function: '<S391>/OutRegionRegWP'
         *  MATLAB Function: '<S391>/SearchL1RefWP'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_MathFunction_iq_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S388>/Sum of Elements' incorporates:
         *  Math: '<S388>/Math Function'
         *  Sum: '<S324>/Sum'
         */
        rtb_Saturation_n = rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0
          + rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Math: '<S388>/Math Function1' incorporates:
         *  Sum: '<S388>/Sum of Elements'
         *
         * About '<S388>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_a_i = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_a_i = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S388>/Math Function1' */

        /* Switch: '<S388>/Switch' incorporates:
         *  Constant: '<S388>/Constant'
         *  Product: '<S388>/Product'
         *  Sum: '<S324>/Sum'
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

        /* End of Switch: '<S388>/Switch' */

        /* Product: '<S388>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S386>/Subtract' incorporates:
         *  Product: '<S386>/Multiply'
         *  Product: '<S386>/Multiply1'
         */
        rtb_a_i = rtb_Saturation1_ln[0] * FMS_ConstB.Divide_d[1] -
          rtb_Saturation1_ln[1] * FMS_ConstB.Divide_d[0];

        /* Signum: '<S375>/Sign1' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S375>/Sign1' */

        /* Switch: '<S375>/Switch2' incorporates:
         *  Constant: '<S375>/Constant4'
         */
        if (rtb_a_i == 0.0F) {
          rtb_a_i = 1.0F;
        }

        /* End of Switch: '<S375>/Switch2' */

        /* DotProduct: '<S375>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide_d[0] * rtb_Saturation1_ln[0] +
          FMS_ConstB.Divide_d[1] * rtb_Saturation1_ln[1];

        /* Trigonometry: '<S375>/Acos' incorporates:
         *  DotProduct: '<S375>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S375>/Multiply' incorporates:
         *  Trigonometry: '<S375>/Acos'
         */
        rtb_a_i *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S379>/Rem' incorporates:
         *  Constant: '<S379>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S374>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_a_i - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S379>/Switch' incorporates:
         *  Abs: '<S379>/Abs'
         *  Constant: '<S379>/Constant'
         *  Constant: '<S385>/Constant'
         *  Product: '<S379>/Multiply'
         *  RelationalOperator: '<S385>/Compare'
         *  Sum: '<S379>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S379>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S379>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S379>/Switch' */

        /* Abs: '<S372>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S372>/Switch' incorporates:
         *  Product: '<S393>/Multiply'
         *  Sum: '<S393>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S407>/Saturation1' */
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

          /* End of Saturate: '<S407>/Saturation1' */

          /* Saturate: '<S397>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S397>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S393>/Sum' incorporates:
           *  Delay: '<S393>/Delay'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S435>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_ec[0] = rtb_Divide_l_idx_1;
          rtb_Saturation1_ln[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S393>/Sum' incorporates:
           *  Delay: '<S393>/Delay'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S437>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S437>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S436>/Gain' incorporates:
           *  DiscreteIntegrator: '<S434>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S434>/Add'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_p);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Trigonometry: '<S437>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S437>/Trigonometric Function1'
           */
          rtb_MathFunction_h_idx_0 = arm_cos_f32(rtb_Saturation_n);
          rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

          /* Trigonometry: '<S437>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S437>/Trigonometric Function'
           */
          rtb_MathFunction_h_idx_1 = arm_sin_f32(rtb_Saturation_n);

          /* Gain: '<S437>/Gain' incorporates:
           *  Trigonometry: '<S437>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

          /* SignalConversion: '<S437>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S437>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S437>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

          /* Trigonometry: '<S437>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

          /* SignalConversion: '<S437>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_k[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_k[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_k[2];

          /* Sum: '<S435>/Sum of Elements' incorporates:
           *  Math: '<S435>/Math Function'
           */
          rtb_Saturation_n = rtb_Switch_ec[0] * rtb_Switch_ec[0] +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

          /* Math: '<S435>/Math Function1' incorporates:
           *  Sum: '<S435>/Sum of Elements'
           *
           * About '<S435>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S435>/Math Function1' */

          /* Switch: '<S435>/Switch' incorporates:
           *  Constant: '<S435>/Constant'
           *  Product: '<S435>/Product'
           */
          if (rtb_Saturation_n > 0.0F) {
            rtb_Rem_k = rtb_Saturation1_ln[0];
          } else {
            rtb_Rem_k = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Saturation_n = 1.0F;
          }

          /* End of Switch: '<S435>/Switch' */

          /* Product: '<S433>/Multiply2' incorporates:
           *  Product: '<S435>/Divide'
           */
          rtb_Rem_k = rtb_Rem_k / rtb_Saturation_n * rtb_Switch_k;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_Saturation_n *
            rtb_Switch_k;
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[i] * rtb_Rem_k;
          }
        }

        /* End of Switch: '<S372>/Switch' */

        /* Delay: '<S374>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S377>/Integrator1' incorporates:
         *  Delay: '<S374>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S381>/Rem' incorporates:
         *  Constant: '<S381>/Constant1'
         *  DiscreteIntegrator: '<S377>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S376>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S381>/Switch' incorporates:
         *  Abs: '<S381>/Abs'
         *  Constant: '<S381>/Constant'
         *  Constant: '<S382>/Constant'
         *  Product: '<S381>/Multiply'
         *  RelationalOperator: '<S382>/Compare'
         *  Sum: '<S381>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S381>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_k;
          }

          /* End of Signum: '<S381>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S381>/Switch' */

        /* Gain: '<S376>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S376>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S376>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S324>/Bus Assignment1'
         *  Constant: '<S324>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S324>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
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
        /* Sum: '<S428>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S428>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S426>/Sum of Elements'
         */
        rtb_Saturation_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S428>/Math Function1' incorporates:
         *  Sum: '<S428>/Sum of Elements'
         *
         * About '<S428>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Rem_k = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S428>/Math Function1' */

        /* Switch: '<S428>/Switch' incorporates:
         *  Constant: '<S428>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S428>/Product'
         *  SignalConversion: '<S24>/Signal Copy1'
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

        /* End of Switch: '<S428>/Switch' */

        /* Product: '<S428>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S431>/Sum of Elements' incorporates:
         *  Math: '<S431>/Math Function'
         *  SignalConversion: '<S431>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Saturation1_ln[1] * rtb_Saturation1_ln[1] +
          rtb_Saturation1_ln[0] * rtb_Saturation1_ln[0];

        /* Math: '<S431>/Math Function1' incorporates:
         *  Sum: '<S431>/Sum of Elements'
         *
         * About '<S431>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S431>/Math Function1' */

        /* Switch: '<S431>/Switch' incorporates:
         *  Constant: '<S431>/Constant'
         *  Product: '<S431>/Product'
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

        /* End of Switch: '<S431>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S391>/NearbyRefWP' incorporates:
         *  Constant: '<S324>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Saturation1_ln,
                        &rtb_Rem_o);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* MATLAB Function: '<S391>/SearchL1RefWP' incorporates:
         *  Constant: '<S324>/L1'
         *  Delay: '<S373>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
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
        /* MATLAB Function: '<S391>/OutRegionRegWP' incorporates:
         *  Delay: '<S373>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
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

        /* Switch: '<S391>/Switch1' incorporates:
         *  Constant: '<S421>/Constant'
         *  RelationalOperator: '<S421>/Compare'
         */
        if (rtb_Rem_o <= 0.0F) {
          /* Switch: '<S391>/Switch' incorporates:
           *  Constant: '<S420>/Constant'
           *  MATLAB Function: '<S391>/SearchL1RefWP'
           *  RelationalOperator: '<S420>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;
            rtb_Saturation1_ln[1] = rtb_MathFunction_h_idx_1;
          } else {
            rtb_Saturation1_ln[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S391>/OutRegionRegWP' incorporates:
             *  Delay: '<S373>/Delay'
             *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
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

          /* End of Switch: '<S391>/Switch' */
        }

        /* End of Switch: '<S391>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S392>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S392>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S429>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S429>/Math Function' incorporates:
         *  Math: '<S427>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Sum: '<S429>/Sum of Elements' incorporates:
         *  Math: '<S429>/Math Function'
         */
        rtb_Rem_k = rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S429>/Math Function1' incorporates:
         *  Sum: '<S429>/Sum of Elements'
         *
         * About '<S429>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S429>/Math Function1' */

        /* Switch: '<S429>/Switch' incorporates:
         *  Constant: '<S429>/Constant'
         *  Product: '<S429>/Product'
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

        /* End of Switch: '<S429>/Switch' */

        /* Product: '<S429>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S432>/Sum of Elements' incorporates:
         *  Math: '<S432>/Math Function'
         *  SignalConversion: '<S432>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_k = rtb_P_d_idx_0 * rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;

        /* Math: '<S432>/Math Function1' incorporates:
         *  Sum: '<S432>/Sum of Elements'
         *
         * About '<S432>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S432>/Math Function1' */

        /* Switch: '<S432>/Switch' incorporates:
         *  Constant: '<S432>/Constant'
         *  Product: '<S432>/Product'
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

        /* End of Switch: '<S432>/Switch' */

        /* Product: '<S432>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S427>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Saturation1_ln[0] *
          rtb_Saturation1_ln[0];
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];

        /* Product: '<S432>/Divide' incorporates:
         *  Product: '<S431>/Divide'
         */
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S431>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sqrt: '<S426>/Sqrt' */
        rtb_Rem_k = sqrtf(rtb_Saturation_n);

        /* Gain: '<S392>/Gain' incorporates:
         *  Math: '<S392>/Square'
         */
        rtb_Saturation_n = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S430>/Subtract' incorporates:
         *  Product: '<S430>/Multiply'
         *  Product: '<S430>/Multiply1'
         */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 * rtb_MathFunction_h_idx_0 -
          rtb_P_d_idx_0 * rtb_Saturation1_ln[0];

        /* Signum: '<S425>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S425>/Sign1' */

        /* Switch: '<S425>/Switch2' incorporates:
         *  Constant: '<S425>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S425>/Switch2' */

        /* DotProduct: '<S425>/Dot Product' */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[0] *
          rtb_MathFunction_iq_idx_0 + rtb_MathFunction_h_idx_0 * rtb_P_d_idx_0;

        /* Trigonometry: '<S425>/Acos' incorporates:
         *  DotProduct: '<S425>/Dot Product'
         */
        if (rtb_MathFunction_h_idx_0 > 1.0F) {
          rtb_MathFunction_h_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_h_idx_0 < -1.0F) {
            rtb_MathFunction_h_idx_0 = -1.0F;
          }
        }

        /* Product: '<S425>/Multiply' incorporates:
         *  Trigonometry: '<S425>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_MathFunction_h_idx_0);

        /* Saturate: '<S392>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S392>/Saturation' */

        /* Product: '<S392>/Divide' incorporates:
         *  Constant: '<S324>/L1'
         *  Constant: '<S392>/Constant'
         *  MinMax: '<S392>/Max'
         *  MinMax: '<S392>/Min'
         *  Product: '<S392>/Multiply1'
         *  Sqrt: '<S427>/Sqrt'
         *  Sum: '<S427>/Sum of Elements'
         *  Trigonometry: '<S392>/Sin'
         */
        rtb_Saturation_n = arm_sin_f32(rtb_Rem_k) * rtb_Saturation_n / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Divide_l_idx_1 +
             rtb_TmpSignalConversionAtDela_a[0]), 0.5F));

        /* Sum: '<S374>/Sum2' incorporates:
         *  Delay: '<S374>/Delay'
         */
        rtb_a_i -= FMS_DW.Delay_DSTATE_a;

        /* Math: '<S378>/Rem' incorporates:
         *  Constant: '<S378>/Constant1'
         */
        rtb_Rem_o = rt_remf(rtb_a_i, 6.28318548F);

        /* Switch: '<S378>/Switch' incorporates:
         *  Abs: '<S378>/Abs'
         *  Constant: '<S378>/Constant'
         *  Constant: '<S384>/Constant'
         *  Product: '<S378>/Multiply'
         *  RelationalOperator: '<S384>/Compare'
         *  Sum: '<S378>/Add'
         */
        if (fabsf(rtb_Rem_o) > 3.14159274F) {
          /* Signum: '<S378>/Sign' */
          if (rtb_Rem_o < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_o > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_o;
          }

          /* End of Signum: '<S378>/Sign' */
          rtb_Rem_o -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S378>/Switch' */

        /* Sum: '<S374>/Sum' incorporates:
         *  Delay: '<S374>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Rem_o + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S383>/Multiply1' incorporates:
         *  Constant: '<S383>/const1'
         *  DiscreteIntegrator: '<S377>/Integrator'
         */
        rtb_Rem_o = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S383>/Add' incorporates:
         *  DiscreteIntegrator: '<S377>/Integrator1'
         *  Sum: '<S377>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_e - rtb_Divide_l_idx_1) +
          rtb_Rem_o;

        /* Signum: '<S383>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
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
        rtb_a_i = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_l) *
                         FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Rem_o;

        /* Sum: '<S383>/Add4' */
        rtb_MathFunction_iq_idx_0 = (rtb_Rem_k - rtb_a_i) + rtb_Rem_o;

        /* Sum: '<S383>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_l;

        /* Sum: '<S383>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_l;

        /* Signum: '<S383>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S383>/Sign1' */

        /* Signum: '<S383>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S383>/Sign2' */

        /* Sum: '<S383>/Add5' incorporates:
         *  Gain: '<S383>/Gain2'
         *  Product: '<S383>/Multiply4'
         *  Sum: '<S383>/Subtract2'
         */
        rtb_a_i += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F *
          rtb_MathFunction_iq_idx_0;

        /* Update for Delay: '<S393>/Delay' */
        FMS_DW.icLoad_o = 0U;

        /* Update for DiscreteIntegrator: '<S434>/Discrete-Time Integrator' incorporates:
         *  Product: '<S393>/Divide1'
         */
        FMS_DW.l1_heading_p += rtb_Saturation_n / rtb_Switch_k * 0.004F;

        /* Update for Delay: '<S373>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Update for Delay: '<S374>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S377>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S377>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S383>/Add6' */
        rtb_Divide_l_idx_1 = rtb_a_i + FMS_ConstB.d_l;

        /* Sum: '<S383>/Subtract3' */
        rtb_Rem_k = rtb_a_i - FMS_ConstB.d_l;

        /* Signum: '<S383>/Sign5' */
        if (rtb_a_i < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_a_i;
        }

        /* End of Signum: '<S383>/Sign5' */

        /* Signum: '<S383>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S383>/Sign3' */

        /* Signum: '<S383>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S383>/Sign4' */

        /* Signum: '<S383>/Sign6' */
        if (rtb_a_i < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_a_i;
        }

        /* End of Signum: '<S383>/Sign6' */

        /* Update for DiscreteIntegrator: '<S377>/Integrator' incorporates:
         *  Constant: '<S383>/const'
         *  Gain: '<S383>/Gain3'
         *  Product: '<S383>/Divide'
         *  Product: '<S383>/Multiply5'
         *  Product: '<S383>/Multiply6'
         *  Sum: '<S383>/Subtract4'
         *  Sum: '<S383>/Subtract5'
         *  Sum: '<S383>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_a_i / FMS_ConstB.d_l -
          rtb_Saturation_n) * FMS_ConstB.Gain4_np * ((rtb_Divide_l_idx_1 -
          rtb_Rem_k) * 0.5F) - rtb_Switch_k * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S377>/Integrator' */
        /* End of Outputs for SubSystem: '<S32>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S32>/Hold' incorporates:
           *  ActionPort: '<S322>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S32>/Switch Case' incorporates:
           *  Chart: '<S331>/Motion Status'
           *  Chart: '<S341>/Motion State'
           *  Chart: '<S353>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S32>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S32>/Hold' incorporates:
         *  ActionPort: '<S322>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S331>/Motion Status' incorporates:
         *  Abs: '<S331>/Abs'
         *  Constant: '<S331>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S341>/Motion State' incorporates:
         *  Abs: '<S341>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
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

        /* End of Chart: '<S341>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S353>/Motion State' incorporates:
         *  Constant: '<S353>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S353>/Square'
         *  Math: '<S353>/Square1'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sqrt: '<S353>/Sqrt'
         *  Sum: '<S353>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S352>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S352>/Hold Control' incorporates:
             *  ActionPort: '<S355>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S352>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S352>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S352>/Hold Control' incorporates:
           *  ActionPort: '<S355>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S352>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S352>/Brake Control' incorporates:
           *  ActionPort: '<S354>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S352>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S352>/Move Control' incorporates:
             *  ActionPort: '<S356>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S352>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S352>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S352>/Move Control' incorporates:
           *  ActionPort: '<S356>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S352>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S352>/Switch Case' */

        /* SwitchCase: '<S330>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S330>/Hold Control' incorporates:
             *  ActionPort: '<S333>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S330>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S330>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S330>/Hold Control' incorporates:
           *  ActionPort: '<S333>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S330>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S330>/Brake Control' incorporates:
           *  ActionPort: '<S332>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S330>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S330>/Move Control' incorporates:
             *  ActionPort: '<S334>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S330>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S330>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S330>/Move Control' incorporates:
           *  ActionPort: '<S334>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S330>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S330>/Switch Case' */

        /* SwitchCase: '<S340>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S340>/Hold Control' incorporates:
             *  ActionPort: '<S343>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S340>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_kq);

            /* End of SystemReset for SubSystem: '<S340>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S340>/Hold Control' incorporates:
           *  ActionPort: '<S343>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                             &FMS_DW.HoldControl_kq);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S340>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S340>/Brake Control' incorporates:
           *  ActionPort: '<S342>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S340>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S340>/Move Control' incorporates:
             *  ActionPort: '<S344>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S340>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S340>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S340>/Move Control' incorporates:
           *  ActionPort: '<S344>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S340>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S340>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S322>/Bus Assignment'
         *  Constant: '<S322>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S322>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S340>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S340>/Saturation' */

        /* Saturate: '<S352>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S352>/Saturation1' */

        /* Saturate: '<S330>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S322>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S330>/Saturation1' */
        /* End of Outputs for SubSystem: '<S32>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S32>/Unknown' incorporates:
         *  ActionPort: '<S326>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S32>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S32>/Switch Case' */
      /* End of Outputs for SubSystem: '<S25>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S25>/Auto' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      /* SwitchCase: '<S30>/Switch Case' incorporates:
       *  Math: '<S207>/Square'
       *  Math: '<S209>/Math Function'
       *  Sum: '<S169>/Subtract'
       *  Sum: '<S221>/Sum1'
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
        /* Disable for Resettable SubSystem: '<S142>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S187>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S177>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S142>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S30>/Offboard' incorporates:
         *  ActionPort: '<S143>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S300>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S303>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S304>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S304>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S304>/Multiply1' incorporates:
         *  Product: '<S304>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S304>/Divide' incorporates:
         *  Constant: '<S304>/Constant'
         *  Constant: '<S304>/R'
         *  Sqrt: '<S304>/Sqrt'
         *  Sum: '<S304>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S304>/Product3' incorporates:
         *  Constant: '<S304>/Constant1'
         *  Product: '<S304>/Multiply1'
         *  Sum: '<S304>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S304>/Multiply2' incorporates:
         *  Trigonometry: '<S304>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S303>/Sum' incorporates:
         *  Gain: '<S300>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Abs: '<S308>/Abs' incorporates:
         *  Abs: '<S311>/Abs1'
         *  Switch: '<S308>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S308>/Switch1' incorporates:
         *  Abs: '<S308>/Abs'
         *  Bias: '<S308>/Bias2'
         *  Bias: '<S308>/Bias3'
         *  Constant: '<S305>/Constant'
         *  Constant: '<S305>/Constant1'
         *  Constant: '<S310>/Constant'
         *  Gain: '<S308>/Gain1'
         *  Product: '<S308>/Multiply'
         *  RelationalOperator: '<S310>/Compare'
         *  Switch: '<S305>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S311>/Switch1' incorporates:
           *  Bias: '<S311>/Bias2'
           *  Bias: '<S311>/Bias3'
           *  Constant: '<S311>/Constant'
           *  Constant: '<S312>/Constant'
           *  Math: '<S311>/Math Function'
           *  RelationalOperator: '<S312>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S311>/Switch1' */

          /* Signum: '<S308>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S308>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          i = 180;
        } else {
          i = 0;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S305>/Sum' incorporates:
         *  Gain: '<S300>/Gain1'
         *  Gain: '<S300>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S303>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)i;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S303>/Multiply' incorporates:
         *  Gain: '<S303>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S307>/Switch1' incorporates:
         *  Abs: '<S307>/Abs1'
         *  Bias: '<S307>/Bias2'
         *  Bias: '<S307>/Bias3'
         *  Constant: '<S307>/Constant'
         *  Constant: '<S309>/Constant'
         *  Math: '<S307>/Math Function'
         *  RelationalOperator: '<S309>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S307>/Switch1' */

        /* Product: '<S303>/Multiply' incorporates:
         *  Gain: '<S303>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MultiPortSwitch: '<S281>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S285>/Multiply1'
         *  Product: '<S286>/Multiply3'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S294>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S294>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S294>/Trigonometric Function3' incorporates:
           *  Gain: '<S293>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S294>/Gain' incorporates:
           *  Gain: '<S293>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Trigonometry: '<S294>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S294>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S294>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S294>/Trigonometric Function' incorporates:
           *  Gain: '<S293>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S294>/Trigonometric Function1' incorporates:
           *  Gain: '<S293>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S294>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S285>/Saturation' incorporates:
           *  Constant: '<S291>/Constant'
           *  Constant: '<S292>/Constant'
           *  Constant: '<S302>/Constant'
           *  DataTypeConversion: '<S300>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S284>/Logical Operator'
           *  Product: '<S285>/Multiply'
           *  Product: '<S306>/Multiply1'
           *  Product: '<S306>/Multiply2'
           *  RelationalOperator: '<S291>/Compare'
           *  RelationalOperator: '<S292>/Compare'
           *  RelationalOperator: '<S302>/Compare'
           *  S-Function (sfix_bitop): '<S284>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S284>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S299>/lat_cmd valid'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S285>/Sum1'
           *  Sum: '<S306>/Sum2'
           *  Switch: '<S287>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.x_cmd;
          }

          rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.x_R : 0.0F;
          if (rtb_Divide_l_idx_1 > 4.0F) {
            rtb_Divide_l_idx_1 = 4.0F;
          } else {
            if (rtb_Divide_l_idx_1 < -4.0F) {
              rtb_Divide_l_idx_1 = -4.0F;
            }
          }

          /* SignalConversion: '<S294>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S285>/Saturation' incorporates:
           *  Constant: '<S291>/Constant'
           *  Constant: '<S292>/Constant'
           *  Constant: '<S302>/Constant'
           *  DataTypeConversion: '<S300>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S284>/Logical Operator'
           *  Product: '<S285>/Multiply'
           *  Product: '<S306>/Multiply3'
           *  Product: '<S306>/Multiply4'
           *  RelationalOperator: '<S291>/Compare'
           *  RelationalOperator: '<S292>/Compare'
           *  RelationalOperator: '<S302>/Compare'
           *  S-Function (sfix_bitop): '<S284>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S284>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S299>/lon_cmd valid'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S285>/Sum1'
           *  Sum: '<S306>/Sum3'
           *  Switch: '<S287>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Saturation_n = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.y_cmd;
          }

          rtb_a_i = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_n -
            FMS_U.INS_Out.y_R : 0.0F;
          if (rtb_a_i > 4.0F) {
            rtb_a_i = 4.0F;
          } else {
            if (rtb_a_i < -4.0F) {
              rtb_a_i = -4.0F;
            }
          }

          /* SignalConversion: '<S294>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S285>/Saturation' incorporates:
           *  Constant: '<S291>/Constant'
           *  Constant: '<S292>/Constant'
           *  Constant: '<S302>/Constant'
           *  DataTypeConversion: '<S300>/Data Type Conversion'
           *  DataTypeConversion: '<S300>/Data Type Conversion1'
           *  Gain: '<S288>/Gain'
           *  Gain: '<S300>/Gain2'
           *  Gain: '<S303>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S284>/Logical Operator'
           *  Product: '<S285>/Multiply'
           *  RelationalOperator: '<S291>/Compare'
           *  RelationalOperator: '<S292>/Compare'
           *  RelationalOperator: '<S302>/Compare'
           *  S-Function (sfix_bitop): '<S284>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S284>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S299>/alt_cmd valid'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S285>/Sum1'
           *  Sum: '<S303>/Sum1'
           *  Switch: '<S287>/Switch'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Saturation_n = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Saturation_n = FMS_U.Auto_Cmd.z_cmd;
          }

          rtb_Saturation_n = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_n -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          if (rtb_Saturation_n > 2.0F) {
            rtb_Saturation_n = 2.0F;
          } else {
            if (rtb_Saturation_n < -2.0F) {
              rtb_Saturation_n = -2.0F;
            }
          }

          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Saturation_n
              + (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
                 rtb_Divide_l_idx_1);
          }

          /* SignalConversion: '<S228>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S228>/Constant4'
           *  MultiPortSwitch: '<S218>/Index Vector'
           *  Product: '<S285>/Multiply1'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S228>/Trigonometric Function3' incorporates:
           *  Gain: '<S227>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S218>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S228>/Gain' incorporates:
           *  Gain: '<S227>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S218>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Trigonometry: '<S228>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S228>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S228>/Constant3'
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S228>/Trigonometric Function' incorporates:
           *  Gain: '<S227>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S218>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S228>/Trigonometric Function1' incorporates:
           *  Gain: '<S227>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S218>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S228>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S218>/Multiply' incorporates:
           *  Constant: '<S226>/Constant'
           *  RelationalOperator: '<S226>/Compare'
           *  S-Function (sfix_bitop): '<S223>/ax_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S228>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S218>/Multiply' incorporates:
           *  Constant: '<S226>/Constant'
           *  RelationalOperator: '<S226>/Compare'
           *  S-Function (sfix_bitop): '<S223>/ay_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S228>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S218>/Multiply' incorporates:
           *  Constant: '<S226>/Constant'
           *  RelationalOperator: '<S226>/Compare'
           *  S-Function (sfix_bitop): '<S223>/az_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S218>/Index Vector' incorporates:
           *  Product: '<S224>/Multiply'
           */
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_Saturation_n);
          }
          break;

         case 1:
          /* SignalConversion: '<S298>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S298>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S296>/Gain' incorporates:
           *  Gain: '<S229>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S218>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S286>/Subtract'
           */
          rtb_Switch_k = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S298>/Trigonometric Function3' incorporates:
           *  Gain: '<S296>/Gain'
           *  Trigonometry: '<S298>/Trigonometric Function1'
           */
          rtb_MathFunction_h_idx_0 = arm_cos_f32(rtb_Switch_k);
          rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

          /* Trigonometry: '<S298>/Trigonometric Function2' incorporates:
           *  Gain: '<S296>/Gain'
           *  Trigonometry: '<S298>/Trigonometric Function'
           */
          rtb_MathFunction_h_idx_1 = arm_sin_f32(rtb_Switch_k);

          /* Gain: '<S298>/Gain' incorporates:
           *  Trigonometry: '<S298>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

          /* SignalConversion: '<S298>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S298>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S298>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

          /* Trigonometry: '<S298>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

          /* SignalConversion: '<S298>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S297>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S298>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S297>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S298>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S297>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S297>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S297>/Constant4'
           */
          rtb_VectorConcatenate_bl[5] = 0.0F;

          /* Trigonometry: '<S297>/Trigonometric Function3' incorporates:
           *  Gain: '<S295>/Gain'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S297>/Trigonometric Function1'
           */
          rtb_Divide_l_idx_1 = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
          rtb_VectorConcatenate_bl[4] = rtb_Divide_l_idx_1;

          /* Trigonometry: '<S297>/Trigonometric Function2' incorporates:
           *  Gain: '<S295>/Gain'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S297>/Trigonometric Function'
           */
          rtb_Saturation_n = arm_sin_f32(-FMS_B.Cmd_In.offboard_psi_0);

          /* Gain: '<S297>/Gain' incorporates:
           *  Trigonometry: '<S297>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_bl[3] = -rtb_Saturation_n;

          /* SignalConversion: '<S297>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S297>/Constant3'
           */
          rtb_VectorConcatenate_bl[2] = 0.0F;

          /* Trigonometry: '<S297>/Trigonometric Function' */
          rtb_VectorConcatenate_bl[1] = rtb_Saturation_n;

          /* Trigonometry: '<S297>/Trigonometric Function1' */
          rtb_VectorConcatenate_bl[0] = rtb_Divide_l_idx_1;

          /* RelationalOperator: '<S302>/Compare' incorporates:
           *  Constant: '<S302>/Constant'
           *  S-Function (sfix_bitop): '<S299>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S299>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S299>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S300>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S300>/Data Type Conversion'
           *  Gain: '<S300>/Gain2'
           *  Gain: '<S303>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S306>/Multiply1'
           *  Product: '<S306>/Multiply2'
           *  Product: '<S306>/Multiply3'
           *  Product: '<S306>/Multiply4'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S303>/Sum1'
           *  Sum: '<S306>/Sum2'
           *  Sum: '<S306>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S287>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S291>/Compare' incorporates:
           *  Constant: '<S291>/Constant'
           *  S-Function (sfix_bitop): '<S284>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S284>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S284>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S292>/Compare' incorporates:
           *  Constant: '<S292>/Constant'
           *  S-Function (sfix_bitop): '<S284>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S284>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S284>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (i = 0; i < 3; i++) {
            /* Sum: '<S286>/Sum2' incorporates:
             *  Product: '<S286>/Multiply2'
             *  Switch: '<S287>/Switch'
             */
            if (tmp[i]) {
              rtb_Saturation_n = rtb_Transpose_0[i];
            } else {
              rtb_Saturation_n = tmp_0[i];
            }

            /* Saturate: '<S286>/Saturation1' incorporates:
             *  Gain: '<S288>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S284>/Logical Operator'
             *  Product: '<S286>/Multiply'
             *  Product: '<S286>/Multiply2'
             *  SignalConversion: '<S24>/Signal Copy1'
             *  Sum: '<S286>/Sum2'
             */
            rtb_Divide_l_idx_1 = tmp_1[i] || tmp_2[i] ? rtb_Saturation_n -
              ((rtb_VectorConcatenate_bl[i + 3] * FMS_U.INS_Out.y_R +
                rtb_VectorConcatenate_bl[i] * FMS_U.INS_Out.x_R) +
               rtb_VectorConcatenate_bl[i + 6] * -FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Divide_l_idx_1 > FMS_ConstP.pooled20[i]) {
              rtb_Switch_ec[i] = FMS_ConstP.pooled20[i];
            } else if (rtb_Divide_l_idx_1 < FMS_ConstP.pooled21[i]) {
              rtb_Switch_ec[i] = FMS_ConstP.pooled21[i];
            } else {
              rtb_Switch_ec[i] = rtb_Divide_l_idx_1;
            }

            /* End of Saturate: '<S286>/Saturation1' */
          }

          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Switch_ec[2]
              + (rtb_Transpose[i + 3] * rtb_Switch_ec[1] + rtb_Transpose[i] *
                 rtb_Switch_ec[0]);
          }

          /* SignalConversion: '<S230>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S230>/Constant4'
           *  MultiPortSwitch: '<S218>/Index Vector'
           *  Product: '<S286>/Multiply3'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S230>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Switch_k);

          /* Gain: '<S230>/Gain' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           *  Trigonometry: '<S230>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Switch_k);

          /* SignalConversion: '<S230>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S230>/Constant3'
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S230>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Switch_k);

          /* Trigonometry: '<S230>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Switch_k);

          /* SignalConversion: '<S230>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S218>/Multiply' incorporates:
           *  Constant: '<S226>/Constant'
           *  RelationalOperator: '<S226>/Compare'
           *  S-Function (sfix_bitop): '<S223>/ax_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S230>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S218>/Multiply' incorporates:
           *  Constant: '<S226>/Constant'
           *  RelationalOperator: '<S226>/Compare'
           *  S-Function (sfix_bitop): '<S223>/ay_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S230>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S218>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S218>/Multiply' incorporates:
           *  Constant: '<S226>/Constant'
           *  RelationalOperator: '<S226>/Compare'
           *  S-Function (sfix_bitop): '<S223>/az_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S218>/Index Vector' incorporates:
           *  Product: '<S225>/Multiply3'
           */
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_Saturation_n);
          }
          break;

         default:
          /* SignalConversion: '<S290>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S290>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S290>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S290>/Trigonometric Function3' incorporates:
           *  Gain: '<S289>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S290>/Gain' incorporates:
           *  Gain: '<S289>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Trigonometry: '<S290>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S290>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S290>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S290>/Trigonometric Function' incorporates:
           *  Gain: '<S289>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S290>/Trigonometric Function1' incorporates:
           *  Gain: '<S289>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S299>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S284>/lat_cmd valid'
           */
          tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S302>/Compare' incorporates:
           *  Constant: '<S302>/Constant'
           *  S-Function (sfix_bitop): '<S299>/lat_cmd valid'
           */
          tmp[0] = (tmp_3 > 0U);

          /* S-Function (sfix_bitop): '<S299>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S284>/lon_cmd valid'
           */
          tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S302>/Compare' incorporates:
           *  Constant: '<S302>/Constant'
           *  S-Function (sfix_bitop): '<S299>/lon_cmd valid'
           */
          tmp[1] = (tmp_4 > 0U);

          /* S-Function (sfix_bitop): '<S299>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S284>/alt_cmd valid'
           */
          tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S302>/Compare' incorporates:
           *  Constant: '<S302>/Constant'
           *  S-Function (sfix_bitop): '<S299>/alt_cmd valid'
           */
          tmp[2] = (tmp_5 > 0U);

          /* DataTypeConversion: '<S300>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S300>/Data Type Conversion'
           *  Gain: '<S300>/Gain2'
           *  Gain: '<S303>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S306>/Multiply1'
           *  Product: '<S306>/Multiply2'
           *  Product: '<S306>/Multiply3'
           *  Product: '<S306>/Multiply4'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S303>/Sum1'
           *  Sum: '<S306>/Sum2'
           *  Sum: '<S306>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S287>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S291>/Compare' incorporates:
           *  Constant: '<S291>/Constant'
           *  S-Function (sfix_bitop): '<S284>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S284>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S284>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S292>/Compare' incorporates:
           *  Constant: '<S292>/Constant'
           */
          tmp_2[0] = (tmp_3 > 0U);
          tmp_2[1] = (tmp_4 > 0U);
          tmp_2[2] = (tmp_5 > 0U);

          /* Sum: '<S283>/Sum2' */
          for (i = 0; i < 3; i++) {
            /* Switch: '<S287>/Switch' incorporates:
             *  Product: '<S283>/Multiply2'
             */
            if (tmp[i]) {
              rtb_Saturation_n = rtb_Transpose_0[i];
            } else {
              rtb_Saturation_n = tmp_0[i];
            }

            /* Saturate: '<S283>/Saturation1' incorporates:
             *  Gain: '<S288>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S284>/Logical Operator'
             *  Product: '<S283>/Multiply'
             *  Product: '<S283>/Multiply2'
             *  SignalConversion: '<S24>/Signal Copy1'
             */
            rtb_Divide_l_idx_1 = tmp_1[i] || tmp_2[i] ? rtb_Saturation_n -
              ((rtb_Transpose[i + 3] * FMS_U.INS_Out.y_R + rtb_Transpose[i] *
                FMS_U.INS_Out.x_R) + rtb_Transpose[i + 6] * -FMS_U.INS_Out.h_R) :
              0.0F;
            if (rtb_Divide_l_idx_1 > FMS_ConstP.pooled20[i]) {
              rtb_MatrixConcatenate3[i] = FMS_ConstP.pooled20[i];
            } else if (rtb_Divide_l_idx_1 < FMS_ConstP.pooled21[i]) {
              rtb_MatrixConcatenate3[i] = FMS_ConstP.pooled21[i];
            } else {
              rtb_MatrixConcatenate3[i] = rtb_Divide_l_idx_1;
            }

            /* End of Saturate: '<S283>/Saturation1' */
          }

          /* End of Sum: '<S283>/Sum2' */

          /* MultiPortSwitch: '<S218>/Index Vector' incorporates:
           *  Constant: '<S226>/Constant'
           *  Product: '<S218>/Multiply'
           *  RelationalOperator: '<S226>/Compare'
           *  S-Function (sfix_bitop): '<S223>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S223>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S223>/az_cmd valid'
           */
          rtb_Switch_ec[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Switch_ec[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Switch_ec[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S281>/Index Vector' */

        /* Sum: '<S277>/Sum1' incorporates:
         *  Constant: '<S277>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S277>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Switch_k = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Abs: '<S278>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Switch_k);

        /* Switch: '<S278>/Switch' incorporates:
         *  Constant: '<S278>/Constant'
         *  Constant: '<S279>/Constant'
         *  Product: '<S278>/Multiply'
         *  RelationalOperator: '<S279>/Compare'
         *  Sum: '<S278>/Subtract'
         */
        if (rtb_Divide_l_idx_1 > 3.14159274F) {
          /* Signum: '<S278>/Sign' */
          if (rtb_Switch_k < 0.0F) {
            rtb_Switch_k = -1.0F;
          } else {
            if (rtb_Switch_k > 0.0F) {
              rtb_Switch_k = 1.0F;
            }
          }

          /* End of Signum: '<S278>/Sign' */
          rtb_Switch_k *= rtb_Divide_l_idx_1 - 6.28318548F;
        }

        /* End of Switch: '<S278>/Switch' */

        /* Saturate: '<S277>/Saturation' */
        if (rtb_Switch_k > 0.314159274F) {
          rtb_Switch_k = 0.314159274F;
        } else {
          if (rtb_Switch_k < -0.314159274F) {
            rtb_Switch_k = -0.314159274F;
          }
        }

        /* End of Saturate: '<S277>/Saturation' */

        /* Gain: '<S274>/Gain2' */
        rtb_Switch_k *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S220>/Sum' incorporates:
         *  Constant: '<S276>/Constant'
         *  Constant: '<S280>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S274>/Multiply2'
         *  Product: '<S275>/Multiply1'
         *  RelationalOperator: '<S276>/Compare'
         *  RelationalOperator: '<S280>/Compare'
         *  S-Function (sfix_bitop): '<S274>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S275>/psi_rate_cmd valid'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                              rtb_Switch_k : 0.0F) + ((FMS_U.Auto_Cmd.cmd_mask &
          64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S281>/Gain1' */
        rtb_Saturation1_ln[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_Saturation1_ln[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S281>/Gain2' */
        rtb_Switch_k = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MultiPortSwitch: '<S282>/Index Vector' incorporates:
         *  Constant: '<S317>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S282>/Multiply'
         *  Product: '<S315>/Multiply'
         *  Product: '<S316>/Multiply3'
         *  RelationalOperator: '<S317>/Compare'
         *  S-Function (sfix_bitop): '<S314>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S314>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S314>/w_cmd valid'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S319>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S319>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S319>/Trigonometric Function3' incorporates:
           *  Gain: '<S318>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S319>/Gain' incorporates:
           *  Gain: '<S318>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Trigonometry: '<S319>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S319>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S319>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S319>/Trigonometric Function' incorporates:
           *  Gain: '<S318>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S319>/Trigonometric Function1' incorporates:
           *  Gain: '<S318>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S319>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S282>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  RelationalOperator: '<S317>/Compare'
           *  S-Function (sfix_bitop): '<S314>/u_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S319>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S282>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  RelationalOperator: '<S317>/Compare'
           *  S-Function (sfix_bitop): '<S314>/v_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S319>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S282>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  RelationalOperator: '<S317>/Compare'
           *  S-Function (sfix_bitop): '<S314>/w_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_Saturation_n);
          }
          break;

         case 1:
          /* SignalConversion: '<S321>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S321>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S320>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S316>/Subtract'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S321>/Trigonometric Function3' incorporates:
           *  Gain: '<S320>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S321>/Gain' incorporates:
           *  Gain: '<S320>/Gain'
           *  Trigonometry: '<S321>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S321>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S321>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S321>/Trigonometric Function' incorporates:
           *  Gain: '<S320>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S321>/Trigonometric Function1' incorporates:
           *  Gain: '<S320>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* SignalConversion: '<S321>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S282>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  RelationalOperator: '<S317>/Compare'
           *  S-Function (sfix_bitop): '<S314>/u_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S321>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S282>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  RelationalOperator: '<S317>/Compare'
           *  S-Function (sfix_bitop): '<S314>/v_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S321>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S282>/Multiply' incorporates:
           *  Constant: '<S317>/Constant'
           *  RelationalOperator: '<S317>/Compare'
           *  S-Function (sfix_bitop): '<S314>/w_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_Saturation_n);
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

        /* End of MultiPortSwitch: '<S282>/Index Vector' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Saturation1_ln[0];
        rtb_MatrixConcatenate3[1] += rtb_Saturation1_ln[1];

        /* Sum: '<S221>/Sum1' */
        rtb_Saturation_n = rtb_Switch_k + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S238>/Switch' incorporates:
         *  Constant: '<S253>/Constant'
         *  Constant: '<S254>/Constant'
         *  Constant: '<S255>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S253>/Compare'
         *  RelationalOperator: '<S254>/Compare'
         *  RelationalOperator: '<S255>/Compare'
         *  S-Function (sfix_bitop): '<S238>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S238>/y_v_cmd'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S238>/Logical Operator' incorporates:
           *  Constant: '<S254>/Constant'
           *  Constant: '<S255>/Constant'
           *  RelationalOperator: '<S254>/Compare'
           *  RelationalOperator: '<S255>/Compare'
           *  S-Function (sfix_bitop): '<S238>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S238>/y_v_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_Switch_p_idx_1 = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_Switch_p_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U);
        }

        /* End of Switch: '<S238>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S219>/u_cmd_valid' */
        /* MATLAB Function: '<S250>/bit_shift' incorporates:
         *  DataTypeConversion: '<S219>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_e << 6);

        /* End of Outputs for SubSystem: '<S219>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S219>/v_cmd_valid' */
        /* MATLAB Function: '<S251>/bit_shift' incorporates:
         *  DataTypeConversion: '<S219>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_Switch_p_idx_1 << 7);

        /* End of Outputs for SubSystem: '<S219>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S239>/Switch' incorporates:
         *  Constant: '<S257>/Constant'
         *  Constant: '<S258>/Constant'
         *  Constant: '<S260>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S257>/Compare'
         *  RelationalOperator: '<S258>/Compare'
         *  RelationalOperator: '<S260>/Compare'
         *  S-Function (sfix_bitop): '<S239>/ax_cmd'
         *  S-Function (sfix_bitop): '<S239>/ay_cmd'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S239>/Logical Operator' incorporates:
           *  Constant: '<S258>/Constant'
           *  Constant: '<S260>/Constant'
           *  RelationalOperator: '<S258>/Compare'
           *  RelationalOperator: '<S260>/Compare'
           *  S-Function (sfix_bitop): '<S239>/ax_cmd'
           *  S-Function (sfix_bitop): '<S239>/ay_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_Switch_p_idx_1 = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_Switch_p_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
        }

        /* End of Switch: '<S239>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S143>/Bus Assignment'
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S143>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S143>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Inport: '<Root>/Auto_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S24>/Signal Copy'
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

        /* Saturate: '<S220>/Saturation' */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Divide_l_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_l_idx_1;
        }

        /* End of Saturate: '<S220>/Saturation' */

        /* Saturate: '<S221>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S221>/Saturation2' */

        /* Saturate: '<S221>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S221>/Saturation1' */

        /* Saturate: '<S221>/Saturation3' */
        if (rtb_Saturation_n > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_n < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S143>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_n;
        }

        /* End of Saturate: '<S221>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S219>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S219>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S219>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S219>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S219>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S219>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S219>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S219>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S219>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S219>/throttle_cmd_valid' */
        /* BusAssignment: '<S143>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S231>/Constant'
         *  Constant: '<S232>/Constant'
         *  Constant: '<S233>/Constant'
         *  Constant: '<S234>/Constant'
         *  Constant: '<S235>/Constant'
         *  Constant: '<S236>/Constant'
         *  Constant: '<S237>/Constant'
         *  Constant: '<S256>/Constant'
         *  Constant: '<S259>/Constant'
         *  DataTypeConversion: '<S219>/Data Type Conversion10'
         *  DataTypeConversion: '<S219>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S240>/bit_shift'
         *  MATLAB Function: '<S241>/bit_shift'
         *  MATLAB Function: '<S242>/bit_shift'
         *  MATLAB Function: '<S244>/bit_shift'
         *  MATLAB Function: '<S245>/bit_shift'
         *  MATLAB Function: '<S246>/bit_shift'
         *  MATLAB Function: '<S247>/bit_shift'
         *  MATLAB Function: '<S248>/bit_shift'
         *  MATLAB Function: '<S249>/bit_shift'
         *  MATLAB Function: '<S252>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S231>/Compare'
         *  RelationalOperator: '<S232>/Compare'
         *  RelationalOperator: '<S233>/Compare'
         *  RelationalOperator: '<S234>/Compare'
         *  RelationalOperator: '<S235>/Compare'
         *  RelationalOperator: '<S236>/Compare'
         *  RelationalOperator: '<S237>/Compare'
         *  RelationalOperator: '<S256>/Compare'
         *  RelationalOperator: '<S259>/Compare'
         *  S-Function (sfix_bitop): '<S219>/p_cmd'
         *  S-Function (sfix_bitop): '<S219>/phi_cmd'
         *  S-Function (sfix_bitop): '<S219>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S219>/q_cmd'
         *  S-Function (sfix_bitop): '<S219>/r_cmd'
         *  S-Function (sfix_bitop): '<S219>/theta_cmd'
         *  S-Function (sfix_bitop): '<S219>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S238>/z_w_cmd'
         *  S-Function (sfix_bitop): '<S239>/az_cmd'
         *  SignalConversion: '<S24>/Signal Copy'
         *  Sum: '<S219>/Add'
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

        /* End of Outputs for SubSystem: '<S219>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S219>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S219>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S219>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S219>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S219>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S219>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S219>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S219>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S219>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S30>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S30>/Mission' incorporates:
           *  ActionPort: '<S142>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S30>/Switch Case' incorporates:
           *  UnitDelay: '<S145>/Delay Input1'
           *
           * Block description for '<S145>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S30>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S30>/Mission' incorporates:
           *  ActionPort: '<S142>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S142>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S30>/Switch Case' incorporates:
           *  Chart: '<S178>/Motion Status'
           *  Chart: '<S188>/Motion State'
           *  Delay: '<S150>/Delay'
           *  Delay: '<S170>/Delay'
           *  DiscreteIntegrator: '<S153>/Integrator'
           *  DiscreteIntegrator: '<S153>/Integrator1'
           *  DiscreteIntegrator: '<S214>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_i = 0.0F;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S142>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S30>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S30>/Mission' incorporates:
         *  ActionPort: '<S142>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* RelationalOperator: '<S145>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S145>/Delay Input1'
         *
         * Block description for '<S145>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Switch_p_idx_1 = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S142>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S146>/Reset'
         */
        if (rtb_Switch_p_idx_1 && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE !=
             POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S187>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S177>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S170>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S214>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S150>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S188>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S178>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_Switch_p_idx_1;

        /* Delay: '<S170>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        if (FMS_DW.icLoad != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S166>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_iq_idx_0 = FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.sp_waypoint[0];
        rtb_Divide_l_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sqrt: '<S174>/Sqrt' incorporates:
         *  Math: '<S174>/Square'
         *  Sum: '<S166>/Sum'
         *  Sum: '<S174>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0 + rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1);

        /* Switch: '<S166>/Switch' incorporates:
         *  Constant: '<S166>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S166>/Gain' */
          rtb_Switch_k = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S166>/Saturation' */
          if (rtb_Switch_k > FMS_PARAM.CRUISE_SPEED) {
            rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Switch_k < 0.5F) {
              rtb_Switch_k = 0.5F;
            }
          }

          /* End of Saturate: '<S166>/Saturation' */
        }

        /* End of Switch: '<S166>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S188>/Motion State' incorporates:
         *  Constant: '<S188>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S188>/Square'
         *  Math: '<S188>/Square1'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sqrt: '<S188>/Sqrt'
         *  Sum: '<S188>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S187>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S187>/Hold Control' incorporates:
             *  ActionPort: '<S190>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S187>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S187>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S187>/Hold Control' incorporates:
           *  ActionPort: '<S190>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S187>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S187>/Brake Control' incorporates:
           *  ActionPort: '<S189>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S187>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S187>/Move Control' incorporates:
             *  ActionPort: '<S191>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S187>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S187>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S187>/Move Control' incorporates:
           *  ActionPort: '<S191>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S187>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S187>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S178>/Motion Status' incorporates:
         *  Abs: '<S178>/Abs'
         *  Constant: '<S178>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S177>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S177>/Hold Control' incorporates:
             *  ActionPort: '<S180>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S177>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S177>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S177>/Hold Control' incorporates:
           *  ActionPort: '<S180>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S177>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S177>/Brake Control' incorporates:
           *  ActionPort: '<S179>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S177>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S177>/Move Control' incorporates:
             *  ActionPort: '<S181>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S177>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S177>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S177>/Move Control' incorporates:
           *  ActionPort: '<S181>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S177>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S177>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S146>/Sum' incorporates:
         *  MATLAB Function: '<S168>/OutRegionRegWP'
         *  MATLAB Function: '<S168>/SearchL1RefWP'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S171>/Sum1'
         *  Switch: '<S148>/Switch'
         */
        rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
          [0];
        rtb_MathFunction_iq_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S164>/Sum of Elements' incorporates:
         *  Math: '<S164>/Math Function'
         *  Sum: '<S146>/Sum'
         */
        rtb_Saturation_n = rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0
          + rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Math: '<S164>/Math Function1' incorporates:
         *  Sum: '<S164>/Sum of Elements'
         *
         * About '<S164>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_a_i = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_a_i = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S164>/Math Function1' */

        /* Switch: '<S164>/Switch' incorporates:
         *  Constant: '<S164>/Constant'
         *  Product: '<S164>/Product'
         *  Sum: '<S146>/Sum'
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

        /* End of Switch: '<S164>/Switch' */

        /* Product: '<S164>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_TmpSignalConversionAtDela_a[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S162>/Subtract' incorporates:
         *  Product: '<S162>/Multiply'
         *  Product: '<S162>/Multiply1'
         */
        rtb_a_i = rtb_TmpSignalConversionAtDela_a[0] * FMS_ConstB.Divide[1] -
          rtb_TmpSignalConversionAtDela_a[1] * FMS_ConstB.Divide[0];

        /* Signum: '<S151>/Sign1' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S151>/Sign1' */

        /* Switch: '<S151>/Switch2' incorporates:
         *  Constant: '<S151>/Constant4'
         */
        if (rtb_a_i == 0.0F) {
          rtb_a_i = 1.0F;
        }

        /* End of Switch: '<S151>/Switch2' */

        /* DotProduct: '<S151>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide[0] *
          rtb_TmpSignalConversionAtDela_a[0] + FMS_ConstB.Divide[1] *
          rtb_TmpSignalConversionAtDela_a[1];

        /* Trigonometry: '<S151>/Acos' incorporates:
         *  DotProduct: '<S151>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S151>/Multiply' incorporates:
         *  Trigonometry: '<S151>/Acos'
         */
        rtb_a_i *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S155>/Rem' incorporates:
         *  Constant: '<S155>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S150>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_a_i - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S155>/Switch' incorporates:
         *  Abs: '<S155>/Abs'
         *  Constant: '<S155>/Constant'
         *  Constant: '<S161>/Constant'
         *  Product: '<S155>/Multiply'
         *  RelationalOperator: '<S161>/Compare'
         *  Sum: '<S155>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S155>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S155>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S155>/Switch' */

        /* Abs: '<S148>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S148>/Switch' incorporates:
         *  Product: '<S170>/Multiply'
         *  Sum: '<S170>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S187>/Saturation1' */
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

          /* End of Saturate: '<S187>/Saturation1' */

          /* Saturate: '<S177>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S177>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S170>/Sum' incorporates:
           *  Delay: '<S170>/Delay'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S215>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_ec[0] = rtb_Divide_l_idx_1;
          rtb_Rem_k = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S170>/Sum' incorporates:
           *  Delay: '<S170>/Delay'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S217>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S217>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S216>/Gain' incorporates:
           *  DiscreteIntegrator: '<S214>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S214>/Add'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Trigonometry: '<S217>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S217>/Gain' incorporates:
           *  Trigonometry: '<S217>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S217>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S217>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S217>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S217>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* SignalConversion: '<S217>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Sum: '<S215>/Sum of Elements' incorporates:
           *  Math: '<S215>/Math Function'
           */
          rtb_Saturation_n = rtb_Switch_ec[0] * rtb_Switch_ec[0] +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

          /* Math: '<S215>/Math Function1' incorporates:
           *  Sum: '<S215>/Sum of Elements'
           *
           * About '<S215>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S215>/Math Function1' */

          /* Switch: '<S215>/Switch' incorporates:
           *  Constant: '<S215>/Constant'
           *  Product: '<S215>/Product'
           */
          if (rtb_Saturation_n <= 0.0F) {
            rtb_Rem_k = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Saturation_n = 1.0F;
          }

          /* End of Switch: '<S215>/Switch' */

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S171>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_h_idx_0 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_1 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Product: '<S171>/Divide' incorporates:
           *  Math: '<S172>/Square'
           *  Math: '<S173>/Square'
           *  Sqrt: '<S172>/Sqrt'
           *  Sqrt: '<S173>/Sqrt'
           *  Sum: '<S171>/Sum'
           *  Sum: '<S172>/Sum of Elements'
           *  Sum: '<S173>/Sum of Elements'
           */
          rtb_MathFunction_h_idx_0 = sqrtf(rtb_MathFunction_h_idx_0 *
            rtb_MathFunction_h_idx_0 + rtb_MathFunction_h_idx_1 *
            rtb_MathFunction_h_idx_1) / sqrtf(rtb_P_d_idx_0 * rtb_P_d_idx_0 +
            rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

          /* Saturate: '<S171>/Saturation' */
          if (rtb_MathFunction_h_idx_0 > 1.0F) {
            rtb_MathFunction_h_idx_0 = 1.0F;
          } else {
            if (rtb_MathFunction_h_idx_0 < 0.0F) {
              rtb_MathFunction_h_idx_0 = 0.0F;
            }
          }

          /* End of Saturate: '<S171>/Saturation' */

          /* Product: '<S213>/Multiply2' incorporates:
           *  Product: '<S215>/Divide'
           */
          rtb_Rem_k = rtb_Rem_k / rtb_Saturation_n * rtb_Switch_k;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_Saturation_n *
            rtb_Switch_k;

          /* Product: '<S170>/Multiply' */
          for (i = 0; i < 3; i++) {
            rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[i] * rtb_Rem_k;
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S165>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S171>/Multiply'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S165>/Sum2'
           *  Sum: '<S171>/Add'
           *  Sum: '<S171>/Subtract'
           */
          rtb_Divide_l_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_MathFunction_h_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_ec[0] = rtb_Transpose_0[0];
          rtb_Switch_ec[1] = rtb_Transpose_0[1];

          /* Saturate: '<S165>/Saturation1' incorporates:
           *  Product: '<S170>/Multiply'
           */
          if (rtb_Divide_l_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_l_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = rtb_Divide_l_idx_1;
          }

          /* End of Saturate: '<S165>/Saturation1' */
        }

        /* Delay: '<S150>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S153>/Integrator1' incorporates:
         *  Delay: '<S150>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S157>/Rem' incorporates:
         *  Constant: '<S157>/Constant1'
         *  DiscreteIntegrator: '<S153>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S152>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S157>/Switch' incorporates:
         *  Abs: '<S157>/Abs'
         *  Constant: '<S157>/Constant'
         *  Constant: '<S158>/Constant'
         *  Product: '<S157>/Multiply'
         *  RelationalOperator: '<S158>/Compare'
         *  Sum: '<S157>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S157>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_k;
          }

          /* End of Signum: '<S157>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S157>/Switch' */

        /* Gain: '<S152>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S152>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S152>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S146>/Bus Assignment'
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S146>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S146>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
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
        /* Math: '<S208>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtDela_a[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_TmpSignalConversionAtDela_a[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S208>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S208>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Saturation_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S208>/Math Function1' incorporates:
         *  Sum: '<S208>/Sum of Elements'
         *
         * About '<S208>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Rem_k = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S208>/Math Function1' */

        /* Switch: '<S208>/Switch' incorporates:
         *  Constant: '<S208>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S208>/Product'
         *  SignalConversion: '<S24>/Signal Copy1'
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

        /* End of Switch: '<S208>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S168>/NearbyRefWP' incorporates:
         *  Constant: '<S146>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                        rtb_TmpSignalConversionAtDela_a, &rtb_Saturation_n);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* MATLAB Function: '<S168>/SearchL1RefWP' incorporates:
         *  Constant: '<S146>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Rem_k = rtb_P_d_idx_0 * rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
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
          rtb_MathFunction_h_idx_0 = rtb_P_d_idx_0 * rtb_Divide_l_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_1 = rtb_MathFunction_iq_idx_0 *
            rtb_Divide_l_idx_1 + FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S168>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
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

        /* Switch: '<S168>/Switch1' incorporates:
         *  Constant: '<S201>/Constant'
         *  RelationalOperator: '<S201>/Compare'
         */
        if (rtb_Saturation_n <= 0.0F) {
          /* Switch: '<S168>/Switch' incorporates:
           *  Constant: '<S200>/Constant'
           *  MATLAB Function: '<S168>/SearchL1RefWP'
           *  RelationalOperator: '<S200>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_h_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S168>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
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

          /* End of Switch: '<S168>/Switch' */
        }

        /* End of Switch: '<S168>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S169>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_TmpSignalConversionAtDela_a[0] -
          FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;
        rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S169>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S209>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_TmpSignalConversionAtDela_a[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S209>/Math Function' incorporates:
         *  Math: '<S207>/Square'
         */
        rtb_Saturation_n = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Sum: '<S209>/Sum of Elements' incorporates:
         *  Math: '<S209>/Math Function'
         */
        rtb_Divide_l_idx_1 = rtb_Saturation_n + rtb_TmpSignalConversionAtDela_a
          [0];

        /* Math: '<S209>/Math Function1' incorporates:
         *  Sum: '<S209>/Sum of Elements'
         *
         * About '<S209>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S209>/Math Function1' */

        /* Switch: '<S209>/Switch' incorporates:
         *  Constant: '<S209>/Constant'
         *  Product: '<S209>/Product'
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

        /* End of Switch: '<S209>/Switch' */

        /* Product: '<S208>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_P_d_idx_0 = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S211>/Sum of Elements' incorporates:
         *  Math: '<S211>/Math Function'
         *  SignalConversion: '<S211>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0;

        /* Math: '<S211>/Math Function1' incorporates:
         *  Sum: '<S211>/Sum of Elements'
         *
         * About '<S211>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S211>/Math Function1' */

        /* Switch: '<S211>/Switch' incorporates:
         *  Constant: '<S211>/Constant'
         *  Product: '<S211>/Product'
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

        /* End of Switch: '<S211>/Switch' */

        /* Product: '<S209>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S212>/Sum of Elements' incorporates:
         *  Math: '<S212>/Math Function'
         *  SignalConversion: '<S212>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0;

        /* Math: '<S212>/Math Function1' incorporates:
         *  Sum: '<S212>/Sum of Elements'
         *
         * About '<S212>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S212>/Math Function1' */

        /* Switch: '<S212>/Switch' incorporates:
         *  Constant: '<S212>/Constant'
         *  Product: '<S212>/Product'
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

        /* End of Switch: '<S212>/Switch' */

        /* Product: '<S212>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S211>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[0] *= rtb_Saturation1_ln[0];

        /* Product: '<S212>/Divide' incorporates:
         *  Math: '<S207>/Square'
         */
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S211>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S206>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S206>/Square'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S206>/Sum of Elements'
         */
        rtb_Rem_k = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve
                          * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S169>/Gain' incorporates:
         *  Math: '<S169>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S210>/Subtract' incorporates:
         *  Product: '<S210>/Multiply'
         *  Product: '<S210>/Multiply1'
         */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 * rtb_TmpSignalConversionAtDela_a
          [1] - rtb_P_d_idx_0 * rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S205>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S205>/Sign1' */

        /* Switch: '<S205>/Switch2' incorporates:
         *  Constant: '<S205>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S205>/Switch2' */

        /* DotProduct: '<S205>/Dot Product' */
        rtb_MathFunction_iq_idx_0 = rtb_TmpSignalConversionAtDela_a[0] *
          rtb_MathFunction_iq_idx_0 + rtb_TmpSignalConversionAtDela_a[1] *
          rtb_P_d_idx_0;

        /* Trigonometry: '<S205>/Acos' incorporates:
         *  DotProduct: '<S205>/Dot Product'
         */
        if (rtb_MathFunction_iq_idx_0 > 1.0F) {
          rtb_MathFunction_iq_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_0 < -1.0F) {
            rtb_MathFunction_iq_idx_0 = -1.0F;
          }
        }

        /* Product: '<S205>/Multiply' incorporates:
         *  Trigonometry: '<S205>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_MathFunction_iq_idx_0);

        /* Saturate: '<S169>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S169>/Saturation' */

        /* Product: '<S169>/Divide' incorporates:
         *  Constant: '<S146>/L1'
         *  Constant: '<S169>/Constant'
         *  MinMax: '<S169>/Max'
         *  MinMax: '<S169>/Min'
         *  Product: '<S169>/Multiply1'
         *  Sqrt: '<S207>/Sqrt'
         *  Sum: '<S207>/Sum of Elements'
         *  Trigonometry: '<S169>/Sin'
         */
        rtb_MathFunction_iq_idx_0 = arm_sin_f32(rtb_Rem_k) * rtb_Divide_l_idx_1 /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_n + rtb_Saturation1_ln
                  [0]), 0.5F));

        /* Sum: '<S150>/Sum2' incorporates:
         *  Delay: '<S150>/Delay'
         */
        rtb_a_i -= FMS_DW.Delay_DSTATE_h;

        /* Math: '<S154>/Rem' incorporates:
         *  Constant: '<S154>/Constant1'
         */
        rtb_Saturation_n = rt_remf(rtb_a_i, 6.28318548F);

        /* Switch: '<S154>/Switch' incorporates:
         *  Abs: '<S154>/Abs'
         *  Constant: '<S154>/Constant'
         *  Constant: '<S160>/Constant'
         *  Product: '<S154>/Multiply'
         *  RelationalOperator: '<S160>/Compare'
         *  Sum: '<S154>/Add'
         */
        if (fabsf(rtb_Saturation_n) > 3.14159274F) {
          /* Signum: '<S154>/Sign' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Saturation_n > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Saturation_n;
          }

          /* End of Signum: '<S154>/Sign' */
          rtb_Saturation_n -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S154>/Switch' */

        /* Sum: '<S150>/Sum' incorporates:
         *  Delay: '<S150>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Saturation_n + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S159>/Multiply1' incorporates:
         *  Constant: '<S159>/const1'
         *  DiscreteIntegrator: '<S153>/Integrator'
         */
        rtb_Saturation_n = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S159>/Add' incorporates:
         *  DiscreteIntegrator: '<S153>/Integrator1'
         *  Sum: '<S153>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_p - rtb_Divide_l_idx_1) +
          rtb_Saturation_n;

        /* Signum: '<S159>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S159>/Sign' */

        /* Sum: '<S159>/Add2' incorporates:
         *  Abs: '<S159>/Abs'
         *  Gain: '<S159>/Gain'
         *  Gain: '<S159>/Gain1'
         *  Product: '<S159>/Multiply2'
         *  Product: '<S159>/Multiply3'
         *  Sqrt: '<S159>/Sqrt'
         *  Sum: '<S159>/Add1'
         *  Sum: '<S159>/Subtract'
         */
        rtb_a_i = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_j) *
                         FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Saturation_n;

        /* Sum: '<S159>/Add4' */
        rtb_Saturation_n += rtb_Rem_k - rtb_a_i;

        /* Sum: '<S159>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_j;

        /* Sum: '<S159>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_j;

        /* Signum: '<S159>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S159>/Sign1' */

        /* Signum: '<S159>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S159>/Sign2' */

        /* Sum: '<S159>/Add5' incorporates:
         *  Gain: '<S159>/Gain2'
         *  Product: '<S159>/Multiply4'
         *  Sum: '<S159>/Subtract2'
         */
        rtb_a_i += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F * rtb_Saturation_n;

        /* Update for Delay: '<S170>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S214>/Discrete-Time Integrator' incorporates:
         *  Product: '<S170>/Divide1'
         */
        FMS_DW.l1_heading += rtb_MathFunction_iq_idx_0 / rtb_Switch_k * 0.004F;

        /* Update for Delay: '<S150>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S153>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S153>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Sum: '<S159>/Add6' */
        rtb_Divide_l_idx_1 = rtb_a_i + FMS_ConstB.d_j;

        /* Sum: '<S159>/Subtract3' */
        rtb_Rem_k = rtb_a_i - FMS_ConstB.d_j;

        /* Signum: '<S159>/Sign5' */
        if (rtb_a_i < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_a_i;
        }

        /* End of Signum: '<S159>/Sign5' */

        /* Signum: '<S159>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S159>/Sign3' */

        /* Signum: '<S159>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S159>/Sign4' */

        /* Signum: '<S159>/Sign6' */
        if (rtb_a_i < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_a_i;
        }

        /* End of Signum: '<S159>/Sign6' */

        /* Update for DiscreteIntegrator: '<S153>/Integrator' incorporates:
         *  Constant: '<S159>/const'
         *  Gain: '<S159>/Gain3'
         *  Product: '<S159>/Divide'
         *  Product: '<S159>/Multiply5'
         *  Product: '<S159>/Multiply6'
         *  Sum: '<S159>/Subtract4'
         *  Sum: '<S159>/Subtract5'
         *  Sum: '<S159>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_a_i / FMS_ConstB.d_j -
          rtb_Saturation_n) * FMS_ConstB.Gain4_c * ((rtb_Divide_l_idx_1 -
          rtb_Rem_k) * 0.5F) - rtb_Switch_k * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S153>/Integrator' */
        /* End of Outputs for SubSystem: '<S142>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Update for UnitDelay: '<S145>/Delay Input1' incorporates:
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S145>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S30>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S30>/Unknown' incorporates:
         *  ActionPort: '<S144>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S30>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S30>/Switch Case' */
      /* End of Outputs for SubSystem: '<S25>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S25>/Assist' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* SwitchCase: '<S29>/Switch Case' */
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
          /* Disable for SwitchCase: '<S129>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S44>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S61>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S77>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S105>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S92>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S29>/Acro' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S34>/Bus Assignment'
         *  Constant: '<S34>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S34>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Gain: '<S39>/Gain'
         *  Gain: '<S39>/Gain1'
         *  Gain: '<S39>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S40>/Saturation' incorporates:
         *  Constant: '<S40>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy2'
         *  Sum: '<S40>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Saturation_n = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S40>/Saturation' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S34>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S40>/Constant5'
         *  Gain: '<S40>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S40>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Saturation_n), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S29>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S29>/Stabilize' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S29>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S125>/Integrator'
           *  DiscreteIntegrator: '<S125>/Integrator1'
           *  DiscreteIntegrator: '<S126>/Integrator'
           *  DiscreteIntegrator: '<S126>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_jt = 0.0F;
          FMS_DW.Integrator_DSTATE_cq = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S29>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S29>/Stabilize' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S29>/Switch Case' incorporates:
           *  Chart: '<S130>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S29>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S29>/Stabilize' incorporates:
         *  ActionPort: '<S37>/Action Port'
         */
        /* Product: '<S127>/Multiply1' incorporates:
         *  Constant: '<S127>/const1'
         *  DiscreteIntegrator: '<S125>/Integrator'
         */
        rtb_a_i = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S123>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S123>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S127>/Add' incorporates:
         *  DiscreteIntegrator: '<S125>/Integrator1'
         *  Gain: '<S120>/Gain'
         *  Gain: '<S123>/Gain'
         *  Sum: '<S125>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Saturation_n * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_a_i;

        /* Signum: '<S127>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S127>/Sign' */

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
        rtb_Switch_k = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_d) *
                              FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_a_i;

        /* Sum: '<S127>/Add4' */
        rtb_Saturation_n = (rtb_Rem_k - rtb_Switch_k) + rtb_a_i;

        /* Sum: '<S127>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_d;

        /* Sum: '<S127>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_d;

        /* Signum: '<S127>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S127>/Sign1' */

        /* Signum: '<S127>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S127>/Sign2' */

        /* Sum: '<S127>/Add5' incorporates:
         *  Gain: '<S127>/Gain2'
         *  Product: '<S127>/Multiply4'
         *  Sum: '<S127>/Subtract2'
         */
        rtb_Switch_k += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F *
          rtb_Saturation_n;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S130>/Motion State' incorporates:
         *  Abs: '<S130>/Abs'
         *  Abs: '<S130>/Abs1'
         *  Constant: '<S140>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S140>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S129>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S129>/Hold Control' incorporates:
             *  ActionPort: '<S132>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S129>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S129>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S129>/Hold Control' incorporates:
           *  ActionPort: '<S132>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                             &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S129>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S129>/Brake Control' incorporates:
           *  ActionPort: '<S131>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S129>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S129>/Move Control' incorporates:
             *  ActionPort: '<S133>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S129>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S129>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S129>/Move Control' incorporates:
           *  ActionPort: '<S133>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S129>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S129>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S37>/Bus Assignment'
         *  Constant: '<S37>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S37>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  DiscreteIntegrator: '<S125>/Integrator1'
         *  DiscreteIntegrator: '<S126>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_j;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_jt;

        /* Saturate: '<S129>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S37>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S37>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S37>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S129>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Saturate: '<S122>/Saturation' incorporates:
         *  Constant: '<S122>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy2'
         *  Sum: '<S122>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Saturation_n = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S122>/Saturation' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S37>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S122>/Constant5'
         *  Gain: '<S122>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S122>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Saturation_n), 65536.0F) + 1000U);

        /* Product: '<S128>/Multiply1' incorporates:
         *  Constant: '<S128>/const1'
         *  DiscreteIntegrator: '<S126>/Integrator'
         */
        rtb_Rem_k = FMS_DW.Integrator_DSTATE_cq * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S124>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S124>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S128>/Add' incorporates:
         *  DiscreteIntegrator: '<S126>/Integrator1'
         *  Gain: '<S120>/Gain1'
         *  Gain: '<S124>/Gain'
         *  Sum: '<S126>/Subtract'
         */
        rtb_a_i = (FMS_DW.Integrator1_DSTATE_jt - 1.0F / (1.0F -
                    FMS_PARAM.PITCH_DZ) * rtb_Saturation_n *
                   -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Rem_k;

        /* Signum: '<S128>/Sign' */
        if (rtb_a_i < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_a_i;
        }

        /* End of Signum: '<S128>/Sign' */

        /* Sum: '<S128>/Add2' incorporates:
         *  Abs: '<S128>/Abs'
         *  Gain: '<S128>/Gain'
         *  Gain: '<S128>/Gain1'
         *  Product: '<S128>/Multiply2'
         *  Product: '<S128>/Multiply3'
         *  Sqrt: '<S128>/Sqrt'
         *  Sum: '<S128>/Add1'
         *  Sum: '<S128>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_a_i) + FMS_ConstB.d_o) *
          FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F * rtb_Divide_l_idx_1 +
          rtb_Rem_k;

        /* Sum: '<S128>/Add4' */
        rtb_Rem_k += rtb_a_i - rtb_Saturation_n;

        /* Sum: '<S128>/Add3' */
        rtb_Divide_l_idx_1 = rtb_a_i + FMS_ConstB.d_o;

        /* Sum: '<S128>/Subtract1' */
        rtb_a_i -= FMS_ConstB.d_o;

        /* Signum: '<S128>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S128>/Sign1' */

        /* Signum: '<S128>/Sign2' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S128>/Sign2' */

        /* Sum: '<S128>/Add5' incorporates:
         *  Gain: '<S128>/Gain2'
         *  Product: '<S128>/Multiply4'
         *  Sum: '<S128>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Divide_l_idx_1 - rtb_a_i) * 0.5F * rtb_Rem_k;

        /* Update for DiscreteIntegrator: '<S125>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S125>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S127>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Switch_k + FMS_ConstB.d_d;

        /* Sum: '<S127>/Subtract3' */
        rtb_Rem_k = rtb_Switch_k - FMS_ConstB.d_d;

        /* Signum: '<S127>/Sign5' */
        if (rtb_Switch_k < 0.0F) {
          rtb_a_i = -1.0F;
        } else if (rtb_Switch_k > 0.0F) {
          rtb_a_i = 1.0F;
        } else {
          rtb_a_i = rtb_Switch_k;
        }

        /* End of Signum: '<S127>/Sign5' */

        /* Signum: '<S127>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S127>/Sign3' */

        /* Signum: '<S127>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S127>/Sign4' */

        /* Signum: '<S127>/Sign6' */
        if (rtb_Switch_k < 0.0F) {
          rtb_MathFunction_iq_idx_0 = -1.0F;
        } else if (rtb_Switch_k > 0.0F) {
          rtb_MathFunction_iq_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_0 = rtb_Switch_k;
        }

        /* End of Signum: '<S127>/Sign6' */

        /* Update for DiscreteIntegrator: '<S125>/Integrator' incorporates:
         *  Constant: '<S127>/const'
         *  Gain: '<S127>/Gain3'
         *  Product: '<S127>/Divide'
         *  Product: '<S127>/Multiply5'
         *  Product: '<S127>/Multiply6'
         *  Sum: '<S127>/Subtract4'
         *  Sum: '<S127>/Subtract5'
         *  Sum: '<S127>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Switch_k / FMS_ConstB.d_d - rtb_a_i)
          * FMS_ConstB.Gain4_n * ((rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F) -
          rtb_MathFunction_iq_idx_0 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S126>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S126>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_jt += 0.004F * FMS_DW.Integrator_DSTATE_cq;

        /* Sum: '<S128>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Saturation_n + FMS_ConstB.d_o;

        /* Sum: '<S128>/Subtract3' */
        rtb_Rem_k = rtb_Saturation_n - FMS_ConstB.d_o;

        /* Signum: '<S128>/Sign5' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_Saturation_n;
        }

        /* End of Signum: '<S128>/Sign5' */

        /* Signum: '<S128>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S128>/Sign3' */

        /* Signum: '<S128>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S128>/Sign4' */

        /* Signum: '<S128>/Sign6' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_a_i = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_a_i = 1.0F;
        } else {
          rtb_a_i = rtb_Saturation_n;
        }

        /* End of Signum: '<S128>/Sign6' */

        /* Update for DiscreteIntegrator: '<S126>/Integrator' incorporates:
         *  Constant: '<S128>/const'
         *  Gain: '<S128>/Gain3'
         *  Product: '<S128>/Divide'
         *  Product: '<S128>/Multiply5'
         *  Product: '<S128>/Multiply6'
         *  Sum: '<S128>/Subtract4'
         *  Sum: '<S128>/Subtract5'
         *  Sum: '<S128>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_cq += ((rtb_Saturation_n / FMS_ConstB.d_o -
          rtb_Switch_k) * FMS_ConstB.Gain4_n3 * ((rtb_Divide_l_idx_1 - rtb_Rem_k)
          * 0.5F) - rtb_a_i * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S29>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S29>/Altitude' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S29>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S57>/Integrator'
           *  DiscreteIntegrator: '<S57>/Integrator1'
           *  DiscreteIntegrator: '<S58>/Integrator'
           *  DiscreteIntegrator: '<S58>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S29>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S29>/Altitude' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S29>/Switch Case' incorporates:
           *  Chart: '<S45>/Motion Status'
           *  Chart: '<S62>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S29>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S29>/Altitude' incorporates:
         *  ActionPort: '<S35>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S45>/Motion Status' incorporates:
         *  Abs: '<S45>/Abs'
         *  Abs: '<S45>/Abs1'
         *  Constant: '<S53>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S53>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S44>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S44>/Hold Control' incorporates:
             *  ActionPort: '<S47>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S44>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S44>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S44>/Hold Control' incorporates:
           *  ActionPort: '<S47>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S44>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S44>/Brake Control' incorporates:
           *  ActionPort: '<S46>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S44>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S44>/Move Control' incorporates:
           *  ActionPort: '<S48>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.INS_Out.h_AGL, FMS_U.Pilot_Cmd.stick_throttle,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S44>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S44>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S62>/Motion State' incorporates:
         *  Abs: '<S62>/Abs'
         *  Abs: '<S62>/Abs1'
         *  Constant: '<S72>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S72>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S61>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S61>/Hold Control' incorporates:
             *  ActionPort: '<S64>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S61>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S61>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S61>/Hold Control' incorporates:
           *  ActionPort: '<S64>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                             &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S61>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S61>/Brake Control' incorporates:
           *  ActionPort: '<S63>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S61>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S61>/Move Control' incorporates:
             *  ActionPort: '<S65>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S61>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_cr);

            /* End of SystemReset for SubSystem: '<S61>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S61>/Move Control' incorporates:
           *  ActionPort: '<S65>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_cr, &FMS_DW.MoveControl_cr);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S61>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S61>/Switch Case' */

        /* Product: '<S59>/Multiply1' incorporates:
         *  Constant: '<S59>/const1'
         *  DiscreteIntegrator: '<S57>/Integrator'
         */
        rtb_a_i = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S55>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S55>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S59>/Add' incorporates:
         *  DiscreteIntegrator: '<S57>/Integrator1'
         *  Gain: '<S42>/Gain'
         *  Gain: '<S55>/Gain'
         *  Sum: '<S57>/Subtract'
         */
        rtb_Saturation_n = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Saturation_n * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_a_i;

        /* Signum: '<S59>/Sign' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Saturation_n;
        }

        /* End of Signum: '<S59>/Sign' */

        /* Sum: '<S59>/Add2' incorporates:
         *  Abs: '<S59>/Abs'
         *  Gain: '<S59>/Gain'
         *  Gain: '<S59>/Gain1'
         *  Product: '<S59>/Multiply2'
         *  Product: '<S59>/Multiply3'
         *  Sqrt: '<S59>/Sqrt'
         *  Sum: '<S59>/Add1'
         *  Sum: '<S59>/Subtract'
         */
        rtb_MathFunction_iq_idx_0 = (sqrtf((8.0F * fabsf(rtb_Saturation_n) +
          FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_a_i;

        /* Sum: '<S59>/Add4' */
        rtb_Switch_k = (rtb_Saturation_n - rtb_MathFunction_iq_idx_0) + rtb_a_i;

        /* Sum: '<S59>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Saturation_n + FMS_ConstB.d;

        /* Sum: '<S59>/Subtract1' */
        rtb_Saturation_n -= FMS_ConstB.d;

        /* Signum: '<S59>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S59>/Sign1' */

        /* Signum: '<S59>/Sign2' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S59>/Sign2' */

        /* Sum: '<S59>/Add5' incorporates:
         *  Gain: '<S59>/Gain2'
         *  Product: '<S59>/Multiply4'
         *  Sum: '<S59>/Subtract2'
         */
        rtb_MathFunction_iq_idx_0 += (rtb_Divide_l_idx_1 - rtb_Saturation_n) *
          0.5F * rtb_Switch_k;

        /* Sum: '<S59>/Subtract3' */
        rtb_Divide_l_idx_1 = rtb_MathFunction_iq_idx_0 - FMS_ConstB.d;

        /* Sum: '<S59>/Add6' */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 + FMS_ConstB.d;

        /* Product: '<S59>/Divide' */
        rtb_P_d_idx_0 = rtb_MathFunction_iq_idx_0 / FMS_ConstB.d;

        /* Signum: '<S59>/Sign5' incorporates:
         *  Signum: '<S59>/Sign6'
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

        /* End of Signum: '<S59>/Sign5' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S35>/Bus Assignment'
         *  Constant: '<S35>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S35>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  DiscreteIntegrator: '<S57>/Integrator1'
         *  DiscreteIntegrator: '<S58>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S61>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S61>/Saturation' */

        /* Saturate: '<S44>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S35>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S44>/Saturation1' */

        /* Product: '<S60>/Multiply1' incorporates:
         *  Constant: '<S60>/const1'
         *  DiscreteIntegrator: '<S58>/Integrator'
         */
        rtb_MathFunction_iq_idx_0 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S56>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S56>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S60>/Add' incorporates:
         *  DiscreteIntegrator: '<S58>/Integrator1'
         *  Gain: '<S42>/Gain1'
         *  Gain: '<S56>/Gain'
         *  Sum: '<S58>/Subtract'
         */
        rtb_a_i = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
                    FMS_PARAM.PITCH_DZ) * rtb_Saturation_n *
                   -FMS_PARAM.ROLL_PITCH_LIM) + rtb_MathFunction_iq_idx_0;

        /* Signum: '<S60>/Sign' */
        if (rtb_a_i < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_a_i;
        }

        /* End of Signum: '<S60>/Sign' */

        /* Sum: '<S60>/Add2' incorporates:
         *  Abs: '<S60>/Abs'
         *  Gain: '<S60>/Gain'
         *  Gain: '<S60>/Gain1'
         *  Product: '<S60>/Multiply2'
         *  Product: '<S60>/Multiply3'
         *  Sqrt: '<S60>/Sqrt'
         *  Sum: '<S60>/Add1'
         *  Sum: '<S60>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_a_i) + FMS_ConstB.d_c) *
          FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F * rtb_Saturation_n +
          rtb_MathFunction_iq_idx_0;

        /* Sum: '<S60>/Add4' */
        rtb_MathFunction_iq_idx_0 += rtb_a_i - rtb_Saturation_n;

        /* Sum: '<S60>/Add3' */
        rtb_MathFunction_h_idx_1 = rtb_a_i + FMS_ConstB.d_c;

        /* Sum: '<S60>/Subtract1' */
        rtb_a_i -= FMS_ConstB.d_c;

        /* Signum: '<S60>/Sign1' */
        if (rtb_MathFunction_h_idx_1 < 0.0F) {
          rtb_MathFunction_h_idx_1 = -1.0F;
        } else {
          if (rtb_MathFunction_h_idx_1 > 0.0F) {
            rtb_MathFunction_h_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S60>/Sign1' */

        /* Signum: '<S60>/Sign2' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S60>/Sign2' */

        /* Sum: '<S60>/Add5' incorporates:
         *  Gain: '<S60>/Gain2'
         *  Product: '<S60>/Multiply4'
         *  Sum: '<S60>/Subtract2'
         */
        rtb_Saturation_n += (rtb_MathFunction_h_idx_1 - rtb_a_i) * 0.5F *
          rtb_MathFunction_iq_idx_0;

        /* Update for DiscreteIntegrator: '<S57>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S57>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S59>/Sign3' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S59>/Sign3' */

        /* Signum: '<S59>/Sign4' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S59>/Sign4' */

        /* Update for DiscreteIntegrator: '<S57>/Integrator' incorporates:
         *  Constant: '<S59>/const'
         *  Gain: '<S59>/Gain3'
         *  Product: '<S59>/Multiply5'
         *  Product: '<S59>/Multiply6'
         *  Sum: '<S59>/Subtract4'
         *  Sum: '<S59>/Subtract5'
         *  Sum: '<S59>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_P_d_idx_0 - rtb_MathFunction_h_idx_0) *
          FMS_ConstB.Gain4 * ((rtb_Rem_k - rtb_Divide_l_idx_1) * 0.5F) -
          rtb_Switch_k * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S58>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S58>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S60>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Saturation_n + FMS_ConstB.d_c;

        /* Sum: '<S60>/Subtract3' */
        rtb_Rem_k = rtb_Saturation_n - FMS_ConstB.d_c;

        /* Signum: '<S60>/Sign5' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_Saturation_n;
        }

        /* End of Signum: '<S60>/Sign5' */

        /* Signum: '<S60>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S60>/Sign3' */

        /* Signum: '<S60>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S60>/Sign4' */

        /* Signum: '<S60>/Sign6' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_a_i = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_a_i = 1.0F;
        } else {
          rtb_a_i = rtb_Saturation_n;
        }

        /* End of Signum: '<S60>/Sign6' */

        /* Update for DiscreteIntegrator: '<S58>/Integrator' incorporates:
         *  Constant: '<S60>/const'
         *  Gain: '<S60>/Gain3'
         *  Product: '<S60>/Divide'
         *  Product: '<S60>/Multiply5'
         *  Product: '<S60>/Multiply6'
         *  Sum: '<S60>/Subtract4'
         *  Sum: '<S60>/Subtract5'
         *  Sum: '<S60>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Saturation_n / FMS_ConstB.d_c -
          rtb_Switch_k) * FMS_ConstB.Gain4_m * ((rtb_Divide_l_idx_1 - rtb_Rem_k)
          * 0.5F) - rtb_a_i * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S29>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S29>/Position' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S29>/Switch Case' incorporates:
           *  Chart: '<S106>/Motion State'
           *  Chart: '<S78>/Motion Status'
           *  Chart: '<S93>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_i);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

          /* End of SystemReset for SubSystem: '<S29>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S29>/Position' incorporates:
         *  ActionPort: '<S36>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S78>/Motion Status' incorporates:
         *  Abs: '<S78>/Abs'
         *  Abs: '<S78>/Abs1'
         *  Constant: '<S90>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S90>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_i);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S77>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S77>/Hold Control' incorporates:
             *  ActionPort: '<S80>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S77>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S77>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S77>/Hold Control' incorporates:
           *  ActionPort: '<S80>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S77>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S77>/Brake Control' incorporates:
           *  ActionPort: '<S79>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S77>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S77>/Move Control' incorporates:
           *  ActionPort: '<S81>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.INS_Out.h_AGL, FMS_U.Pilot_Cmd.stick_throttle,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S77>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S77>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S93>/Motion State' incorporates:
         *  Abs: '<S93>/Abs'
         *  Abs: '<S93>/Abs1'
         *  Constant: '<S103>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S103>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S106>/Logical Operator' incorporates:
         *  Abs: '<S106>/Abs1'
         *  Abs: '<S106>/Abs2'
         *  Constant: '<S117>/Constant'
         *  Constant: '<S118>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S117>/Compare'
         *  RelationalOperator: '<S118>/Compare'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        rtb_Switch_p_idx_1 = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S106>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S106>/Square'
         *  Math: '<S106>/Square1'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sqrt: '<S106>/Sqrt'
         *  Sum: '<S106>/Add'
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

            /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_i
                 >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            } else {
              if (rtb_Switch_p_idx_1) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_n;
                rtb_state_ki = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_ki = MotionState_Hold;
            if (rtb_Switch_p_idx_1) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_n;
              rtb_state_ki = MotionState_Move;
            }
            break;

           default:
            rtb_state_ki = MotionState_Move;
            if (!rtb_Switch_p_idx_1) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_ki = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S106>/Motion State' */

        /* SwitchCase: '<S105>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S105>/Hold Control' incorporates:
             *  ActionPort: '<S108>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S105>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S105>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S105>/Hold Control' incorporates:
           *  ActionPort: '<S108>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S105>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S105>/Brake Control' incorporates:
           *  ActionPort: '<S107>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S105>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S105>/Move Control' incorporates:
             *  ActionPort: '<S109>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S105>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S105>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S105>/Move Control' incorporates:
           *  ActionPort: '<S109>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S105>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S105>/Switch Case' */

        /* SwitchCase: '<S92>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S92>/Hold Control' incorporates:
             *  ActionPort: '<S95>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S92>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S92>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S92>/Hold Control' incorporates:
           *  ActionPort: '<S95>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                             &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S92>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S92>/Brake Control' incorporates:
           *  ActionPort: '<S94>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S92>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S92>/Move Control' incorporates:
             *  ActionPort: '<S96>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S92>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_mr);

            /* End of SystemReset for SubSystem: '<S92>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S92>/Move Control' incorporates:
           *  ActionPort: '<S96>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_mr, &FMS_DW.MoveControl_mr);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S92>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S92>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S36>/Bus Assignment'
         *  Constant: '<S36>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S36>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S92>/Saturation' */
        if (FMS_B.Merge_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_d;
        }

        /* End of Saturate: '<S92>/Saturation' */

        /* Saturate: '<S105>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S105>/Saturation1' */

        /* Saturate: '<S77>/Saturation1' */
        if (FMS_B.Merge_k > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_k < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S36>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_k;
        }

        /* End of Saturate: '<S77>/Saturation1' */
        /* End of Outputs for SubSystem: '<S29>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S29>/Unknown' incorporates:
         *  ActionPort: '<S38>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S29>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S29>/Switch Case' */
      /* End of Outputs for SubSystem: '<S25>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S25>/Manual' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S26>/Bus Assignment'
       *  BusAssignment: '<S31>/Bus Assignment'
       *  Constant: '<S31>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S31>/Bus Assignment' incorporates:
       *  BusAssignment: '<S26>/Bus Assignment'
       *  Constant: '<S31>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S25>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S25>/Unknown' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S26>/Bus Assignment'
       */
      FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S25>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S25>/Switch Case' */
    /* End of Outputs for SubSystem: '<S23>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S23>/Switch Case' */

  /* BusAssignment: '<S26>/Bus Assignment' incorporates:
   *  Constant: '<S26>/Constant'
   *  DataStoreRead: '<S26>/Data Store Read'
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   *  DiscreteIntegrator: '<S446>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  Sum: '<S26>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
  FMS_Y.FMS_Out.home[0] = FMS_DW.home[0];
  FMS_Y.FMS_Out.home[1] = FMS_DW.home[1];
  FMS_Y.FMS_Out.home[2] = FMS_DW.home[2];
  FMS_Y.FMS_Out.home[3] = FMS_DW.home[3];

  /* Update for DiscreteIntegrator: '<S446>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S446>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_Switch_p_idx_1 = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S12>/SetHome' incorporates:
   *  TriggerPort: '<S19>/Trigger'
   */
  if (rtb_Switch_p_idx_1 && (FMS_PrevZCX.SetHome_Trig_ZCE != POS_ZCSIG)) {
    /* DataStoreWrite: '<S19>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_Switch_p_idx_1;

  /* End of Outputs for SubSystem: '<S12>/SetHome' */

  /* Update for DiscreteIntegrator: '<S461>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S461>/Gain'
   *  Sum: '<S461>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_o[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_o[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_o[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S463>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S463>/Gain'
   *  Sum: '<S463>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S462>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S462>/Gain'
   *  Sum: '<S462>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_k += (rtb_Divide_l_idx_2 -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k) * 10.0F * 0.004F;

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
  rtb_Saturation_n = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Saturation_n < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Saturation_n;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = MAX_uint32_T;
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
  rtb_Saturation_n = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE + (real32_T)
    FMS_EXPORT.period;
  if (rtb_Saturation_n < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = (uint32_T)rtb_Saturation_n;
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
  /* Start for SwitchCase: '<S23>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S23>/Arm' */
  /* Start for SwitchCase: '<S25>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S25>/SubMode' */
  /* Start for SwitchCase: '<S32>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_at = -1;

  /* Start for IfAction SubSystem: '<S32>/Return' */
  /* Start for SwitchCase: '<S407>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S397>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S32>/Return' */

  /* Start for IfAction SubSystem: '<S32>/Hold' */
  /* Start for SwitchCase: '<S352>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S330>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S340>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S32>/Hold' */
  /* End of Start for SubSystem: '<S25>/SubMode' */

  /* Start for IfAction SubSystem: '<S25>/Auto' */
  /* Start for SwitchCase: '<S30>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S30>/Mission' */
  /* Start for Resettable SubSystem: '<S142>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S187>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S177>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S142>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S30>/Mission' */
  /* End of Start for SubSystem: '<S25>/Auto' */

  /* Start for IfAction SubSystem: '<S25>/Assist' */
  /* Start for SwitchCase: '<S29>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S29>/Stabilize' */
  /* Start for SwitchCase: '<S129>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S29>/Stabilize' */

  /* Start for IfAction SubSystem: '<S29>/Altitude' */
  /* Start for SwitchCase: '<S44>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S61>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S29>/Altitude' */

  /* Start for IfAction SubSystem: '<S29>/Position' */
  /* Start for SwitchCase: '<S77>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S105>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S92>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S29>/Position' */
  /* End of Start for SubSystem: '<S25>/Assist' */
  /* End of Start for SubSystem: '<S23>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S461>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S463>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S462>/Discrete-Time Integrator5' */
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
  /* SystemInitialize for IfAction SubSystem: '<S23>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S25>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S32>/Takeoff' */
  /* InitializeConditions for Delay: '<S444>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* End of SystemInitialize for SubSystem: '<S32>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S32>/Return' */
  /* InitializeConditions for Delay: '<S393>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S434>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_p = 0.0F;

  /* InitializeConditions for Delay: '<S373>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for Delay: '<S374>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S377>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S377>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S408>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S407>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S407>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S407>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S407>/Move Control' */

  /* SystemInitialize for Merge: '<S407>/Merge' */
  FMS_B.Merge_mv[0] = 0.0F;
  FMS_B.Merge_mv[1] = 0.0F;

  /* SystemInitialize for Chart: '<S398>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S397>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S397>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S397>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S397>/Move Control' */

  /* SystemInitialize for Merge: '<S397>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S32>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S32>/Hold' */
  /* SystemInitialize for Chart: '<S331>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S341>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S353>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S352>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S352>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S352>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S352>/Move Control' */

  /* SystemInitialize for Merge: '<S352>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S330>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S330>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S330>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S330>/Move Control' */

  /* SystemInitialize for Merge: '<S330>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S340>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_kq);

  /* End of SystemInitialize for SubSystem: '<S340>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S340>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S340>/Move Control' */

  /* SystemInitialize for Merge: '<S340>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S32>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S25>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S25>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S30>/Mission' */
  /* InitializeConditions for UnitDelay: '<S145>/Delay Input1'
   *
   * Block description for '<S145>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S142>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S170>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S214>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S150>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S188>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S187>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S187>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S187>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S187>/Move Control' */

  /* SystemInitialize for Merge: '<S187>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S178>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S177>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S177>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S177>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S177>/Move Control' */

  /* SystemInitialize for Merge: '<S177>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S142>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S30>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S25>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S25>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S29>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S125>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S125>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S126>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jt = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S126>/Integrator' */
  FMS_DW.Integrator_DSTATE_cq = 0.0F;

  /* SystemInitialize for Chart: '<S130>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S129>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S129>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S129>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S129>/Move Control' */

  /* SystemInitialize for Merge: '<S129>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S29>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S29>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S58>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S58>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S45>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S44>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S44>/Hold Control' */

  /* SystemInitialize for Chart: '<S62>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S61>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S61>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S61>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_cr);

  /* End of SystemInitialize for SubSystem: '<S61>/Move Control' */

  /* SystemInitialize for Merge: '<S44>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Merge: '<S61>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S29>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S29>/Position' */
  /* SystemInitialize for Chart: '<S78>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for IfAction SubSystem: '<S77>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S77>/Hold Control' */

  /* SystemInitialize for Chart: '<S93>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S106>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S105>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S105>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S105>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S105>/Move Control' */

  /* SystemInitialize for Merge: '<S105>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S77>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S92>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S92>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S92>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_mr);

  /* End of SystemInitialize for SubSystem: '<S92>/Move Control' */

  /* SystemInitialize for Merge: '<S92>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S29>/Position' */
  /* End of SystemInitialize for SubSystem: '<S25>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S23>/Arm' */
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
