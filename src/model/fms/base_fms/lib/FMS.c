/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1916
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed May  3 13:41:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S393>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S403>/Motion State' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_m                  ((uint8_T)2U)
#define FMS_IN_Move_c                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_d       ((uint8_T)0U)

/* Named constants for Chart: '<S126>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S45>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S337>/Motion State' */
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
                                        *   '<S443>/Constant'
                                        *   '<S320>/L1'
                                        *   '<S42>/Gain'
                                        *   '<S42>/Gain1'
                                        *   '<S116>/Gain'
                                        *   '<S116>/Gain1'
                                        *   '<S142>/L1'
                                        *   '<S216>/Saturation'
                                        *   '<S217>/Saturation1'
                                        *   '<S217>/Saturation2'
                                        *   '<S217>/Saturation3'
                                        *   '<S361>/Saturation1'
                                        *   '<S434>/Gain2'
                                        *   '<S434>/Saturation1'
                                        *   '<S44>/Saturation1'
                                        *   '<S55>/Dead Zone'
                                        *   '<S55>/Gain'
                                        *   '<S56>/Dead Zone'
                                        *   '<S56>/Gain'
                                        *   '<S61>/Saturation'
                                        *   '<S77>/Saturation1'
                                        *   '<S88>/Saturation'
                                        *   '<S101>/Saturation1'
                                        *   '<S119>/Dead Zone'
                                        *   '<S119>/Gain'
                                        *   '<S120>/Dead Zone'
                                        *   '<S120>/Gain'
                                        *   '<S125>/Saturation'
                                        *   '<S270>/Gain2'
                                        *   '<S277>/Gain1'
                                        *   '<S277>/Gain2'
                                        *   '<S326>/Saturation1'
                                        *   '<S336>/Saturation'
                                        *   '<S348>/Saturation1'
                                        *   '<S362>/Gain2'
                                        *   '<S384>/vel'
                                        *   '<S384>/Saturation'
                                        *   '<S384>/Switch'
                                        *   '<S47>/Gain2'
                                        *   '<S48>/Gain1'
                                        *   '<S53>/Constant'
                                        *   '<S64>/Gain2'
                                        *   '<S65>/Gain1'
                                        *   '<S72>/Constant'
                                        *   '<S80>/Gain2'
                                        *   '<S81>/Gain1'
                                        *   '<S86>/Constant'
                                        *   '<S91>/Gain2'
                                        *   '<S92>/Gain1'
                                        *   '<S99>/Constant'
                                        *   '<S104>/Gain2'
                                        *   '<S105>/Gain6'
                                        *   '<S113>/Constant'
                                        *   '<S114>/Constant'
                                        *   '<S128>/Gain2'
                                        *   '<S129>/Gain1'
                                        *   '<S136>/Constant'
                                        *   '<S161>/Gain'
                                        *   '<S161>/Saturation1'
                                        *   '<S162>/vel'
                                        *   '<S162>/Saturation'
                                        *   '<S162>/Switch'
                                        *   '<S329>/Gain2'
                                        *   '<S330>/Gain1'
                                        *   '<S339>/Gain2'
                                        *   '<S340>/Gain1'
                                        *   '<S351>/Gain2'
                                        *   '<S352>/Gain6'
                                        *   '<S371>/Gain2'
                                        *   '<S371>/Saturation'
                                        *   '<S372>/Integrator'
                                        *   '<S50>/Dead Zone'
                                        *   '<S50>/Gain'
                                        *   '<S69>/Dead Zone'
                                        *   '<S69>/Gain'
                                        *   '<S83>/Dead Zone'
                                        *   '<S83>/Gain'
                                        *   '<S96>/Dead Zone'
                                        *   '<S96>/Gain'
                                        *   '<S109>/Dead Zone'
                                        *   '<S109>/Gain'
                                        *   '<S110>/Dead Zone'
                                        *   '<S110>/Gain'
                                        *   '<S133>/Dead Zone'
                                        *   '<S133>/Gain'
                                        *   '<S148>/Gain2'
                                        *   '<S148>/Saturation'
                                        *   '<S149>/Integrator'
                                        *   '<S332>/Dead Zone'
                                        *   '<S332>/Gain'
                                        *   '<S344>/Dead Zone'
                                        *   '<S344>/Gain'
                                        *   '<S356>/Dead Zone'
                                        *   '<S356>/Gain'
                                        *   '<S357>/Dead Zone'
                                        *   '<S357>/Gain'
                                        *   '<S392>/Saturation1'
                                        *   '<S402>/Saturation1'
                                        *   '<S173>/Saturation1'
                                        *   '<S183>/Saturation1'
                                        *   '<S395>/Gain2'
                                        *   '<S396>/Gain1'
                                        *   '<S405>/Gain2'
                                        *   '<S406>/Gain6'
                                        *   '<S176>/Gain2'
                                        *   '<S177>/Gain1'
                                        *   '<S186>/Gain2'
                                        *   '<S187>/Gain6'
                                        *   '<S398>/Dead Zone'
                                        *   '<S398>/Gain'
                                        *   '<S410>/Dead Zone'
                                        *   '<S410>/Gain'
                                        *   '<S411>/Dead Zone'
                                        *   '<S411>/Gain'
                                        *   '<S179>/Dead Zone'
                                        *   '<S179>/Gain'
                                        *   '<S191>/Dead Zone'
                                        *   '<S191>/Gain'
                                        *   '<S192>/Dead Zone'
                                        *   '<S192>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 48, 46, 52, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S11>/Constant1'
                                        *   '<S441>/Constant'
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
 *    '<S392>/Hold Control'
 *    '<S326>/Hold Control'
 *    '<S173>/Hold Control'
 *    '<S44>/Hold Control'
 *    '<S77>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S395>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S392>/Hold Control'
 *    '<S326>/Hold Control'
 *    '<S173>/Hold Control'
 *    '<S44>/Hold Control'
 *    '<S77>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S395>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S392>/Hold Control'
 *    '<S326>/Hold Control'
 *    '<S173>/Hold Control'
 *    '<S44>/Hold Control'
 *    '<S77>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S395>/Delay' incorporates:
   *  Gain: '<S397>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S395>/Gain2' incorporates:
   *  Delay: '<S395>/Delay'
   *  Gain: '<S397>/Gain'
   *  Sum: '<S395>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S395>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S392>/Brake Control'
 *    '<S326>/Brake Control'
 *    '<S336>/Brake Control'
 *    '<S173>/Brake Control'
 *    '<S125>/Brake Control'
 *    '<S44>/Brake Control'
 *    '<S61>/Brake Control'
 *    '<S77>/Brake Control'
 *    '<S88>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S394>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S394>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S392>/Move Control'
 *    '<S326>/Move Control'
 *    '<S173>/Move Control'
 *    '<S44>/Move Control'
 *    '<S77>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S399>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S399>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S392>/Move Control'
 *    '<S326>/Move Control'
 *    '<S173>/Move Control'
 *    '<S44>/Move Control'
 *    '<S77>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S399>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S399>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S392>/Move Control'
 *    '<S326>/Move Control'
 *    '<S173>/Move Control'
 *    '<S44>/Move Control'
 *    '<S77>/Move Control'
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

  /* Product: '<S400>/Multiply1' incorporates:
   *  Constant: '<S400>/const1'
   *  DiscreteIntegrator: '<S399>/Integrator'
   */
  rtb_Add3_c = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S398>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_hr = 0.0F;
  } else {
    rtb_a_hr = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S398>/Dead Zone' */

  /* Sum: '<S400>/Add' incorporates:
   *  DiscreteIntegrator: '<S399>/Integrator1'
   *  Gain: '<S396>/Gain1'
   *  Gain: '<S398>/Gain'
   *  Sum: '<S399>/Subtract'
   */
  rtb_Subtract3_dn = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_hr * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_c;

  /* Signum: '<S400>/Sign' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_a_hr = -1.0F;
  } else if (rtb_Subtract3_dn > 0.0F) {
    rtb_a_hr = 1.0F;
  } else {
    rtb_a_hr = rtb_Subtract3_dn;
  }

  /* End of Signum: '<S400>/Sign' */

  /* Sum: '<S400>/Add2' incorporates:
   *  Abs: '<S400>/Abs'
   *  Gain: '<S400>/Gain'
   *  Gain: '<S400>/Gain1'
   *  Product: '<S400>/Multiply2'
   *  Product: '<S400>/Multiply3'
   *  Sqrt: '<S400>/Sqrt'
   *  Sum: '<S400>/Add1'
   *  Sum: '<S400>/Subtract'
   */
  rtb_a_hr = (sqrtf((8.0F * fabsf(rtb_Subtract3_dn) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_hr + rtb_Add3_c;

  /* Sum: '<S400>/Add4' */
  rtb_Add4_g = (rtb_Subtract3_dn - rtb_a_hr) + rtb_Add3_c;

  /* Sum: '<S400>/Add3' */
  rtb_Add3_c = rtb_Subtract3_dn + localC->d;

  /* Sum: '<S400>/Subtract1' */
  rtb_Subtract3_dn -= localC->d;

  /* Signum: '<S400>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S400>/Sign1' */

  /* Signum: '<S400>/Sign2' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S400>/Sign2' */

  /* Sum: '<S400>/Add5' incorporates:
   *  Gain: '<S400>/Gain2'
   *  Product: '<S400>/Multiply4'
   *  Sum: '<S400>/Subtract2'
   */
  rtb_a_hr += (rtb_Add3_c - rtb_Subtract3_dn) * 0.5F * rtb_Add4_g;

  /* SignalConversion: '<S396>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S399>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S399>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S399>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S400>/Add6' */
  rtb_Add3_c = rtb_a_hr + localC->d;

  /* Sum: '<S400>/Subtract3' */
  rtb_Subtract3_dn = rtb_a_hr - localC->d;

  /* Signum: '<S400>/Sign5' */
  if (rtb_a_hr < 0.0F) {
    rtb_Add4_g = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_Add4_g = 1.0F;
  } else {
    rtb_Add4_g = rtb_a_hr;
  }

  /* End of Signum: '<S400>/Sign5' */

  /* Signum: '<S400>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S400>/Sign3' */

  /* Signum: '<S400>/Sign4' */
  if (rtb_Subtract3_dn < 0.0F) {
    rtb_Subtract3_dn = -1.0F;
  } else {
    if (rtb_Subtract3_dn > 0.0F) {
      rtb_Subtract3_dn = 1.0F;
    }
  }

  /* End of Signum: '<S400>/Sign4' */

  /* Signum: '<S400>/Sign6' */
  if (rtb_a_hr < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_a_hr > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_a_hr;
  }

  /* End of Signum: '<S400>/Sign6' */

  /* Update for DiscreteIntegrator: '<S399>/Integrator' incorporates:
   *  Constant: '<S400>/const'
   *  Gain: '<S400>/Gain3'
   *  Product: '<S400>/Divide'
   *  Product: '<S400>/Multiply5'
   *  Product: '<S400>/Multiply6'
   *  Sum: '<S400>/Subtract4'
   *  Sum: '<S400>/Subtract5'
   *  Sum: '<S400>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_hr / localC->d - rtb_Add4_g) *
    localC->Gain4 * ((rtb_Add3_c - rtb_Subtract3_dn) * 0.5F) - rtb_a_b * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S393>/Motion Status'
 *    '<S327>/Motion Status'
 *    '<S174>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S393>/Motion Status'
 *    '<S327>/Motion Status'
 *    '<S174>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S393>/Motion Status'
 *    '<S327>/Motion Status'
 *    '<S174>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S393>/Motion Status' */
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

  /* End of Chart: '<S393>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S402>/Hold Control'
 *    '<S348>/Hold Control'
 *    '<S183>/Hold Control'
 *    '<S101>/Hold Control'
 */
void FMS_HoldControl_b_Init(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S405>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S402>/Hold Control'
 *    '<S348>/Hold Control'
 *    '<S183>/Hold Control'
 *    '<S101>/Hold Control'
 */
void FMS_HoldControl_l_Reset(DW_HoldControl_FMS_l_T *localDW)
{
  /* InitializeConditions for Delay: '<S405>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S402>/Hold Control'
 *    '<S348>/Hold Control'
 *    '<S183>/Hold Control'
 *    '<S101>/Hold Control'
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

  /* Delay: '<S405>/Delay' incorporates:
   *  SignalConversion: '<S405>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_p;
  }

  /* Trigonometry: '<S409>/Trigonometric Function1' incorporates:
   *  Gain: '<S408>/Gain'
   *  Trigonometry: '<S409>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bl_tmp_0 = arm_cos_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[0] = rtb_VectorConcatenate_bl_tmp_0;

  /* Trigonometry: '<S409>/Trigonometric Function' incorporates:
   *  Gain: '<S408>/Gain'
   *  Trigonometry: '<S409>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bl_tmp = arm_sin_f32(-rtu_FMS_In_b);
  rtb_VectorConcatenate_k[1] = rtb_VectorConcatenate_bl_tmp;

  /* SignalConversion: '<S409>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S409>/Constant3'
   */
  rtb_VectorConcatenate_k[2] = 0.0F;

  /* Gain: '<S409>/Gain' */
  rtb_VectorConcatenate_k[3] = -rtb_VectorConcatenate_bl_tmp;

  /* Trigonometry: '<S409>/Trigonometric Function3' */
  rtb_VectorConcatenate_k[4] = rtb_VectorConcatenate_bl_tmp_0;

  /* SignalConversion: '<S409>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S409>/Constant4'
   */
  rtb_VectorConcatenate_k[5] = 0.0F;

  /* SignalConversion: '<S409>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_k[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_k[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_k[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S405>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S405>/Delay'
   *  SignalConversion: '<S405>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S405>/Sum'
   */
  rtb_VectorConcatenate_bl_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bl_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_p;

  /* Product: '<S405>/Multiply' incorporates:
   *  SignalConversion: '<S405>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bl[i] = rtb_VectorConcatenate_k[i + 3] *
      rtb_VectorConcatenate_bl_tmp + rtb_VectorConcatenate_k[i] *
      rtb_VectorConcatenate_bl_tmp_0;
  }

  /* End of Product: '<S405>/Multiply' */

  /* Gain: '<S405>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bl[1];

  /* Update for Delay: '<S405>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S402>/Brake Control'
 *    '<S348>/Brake Control'
 *    '<S183>/Brake Control'
 *    '<S101>/Brake Control'
 */
void FMS_BrakeControl_f(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S404>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S402>/Move Control'
 *    '<S348>/Move Control'
 *    '<S183>/Move Control'
 *    '<S101>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S412>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S412>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S412>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S412>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S402>/Move Control'
 *    '<S348>/Move Control'
 *    '<S183>/Move Control'
 *    '<S101>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_d_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S412>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S412>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S412>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S412>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S402>/Move Control'
 *    '<S348>/Move Control'
 *    '<S183>/Move Control'
 *    '<S101>/Move Control'
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

  /* SignalConversion: '<S406>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S412>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S413>/Multiply1' incorporates:
   *  Constant: '<S413>/const1'
   *  DiscreteIntegrator: '<S412>/Integrator'
   */
  rtb_Add3_e1_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S406>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S412>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S413>/Multiply1' incorporates:
   *  Constant: '<S413>/const1'
   *  DiscreteIntegrator: '<S412>/Integrator'
   */
  rtb_Add3_e1_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S410>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S410>/Dead Zone' */

  /* Sum: '<S413>/Add' incorporates:
   *  DiscreteIntegrator: '<S412>/Integrator1'
   *  Gain: '<S406>/Gain6'
   *  Gain: '<S410>/Gain'
   *  Sum: '<S412>/Subtract'
   */
  rtb_Subtract3_h_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_0;

  /* DeadZone: '<S411>/Dead Zone' */
  if (rtu_FMS_In_g > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_g >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_h_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_h_idx_1 = rtu_FMS_In_g - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S411>/Dead Zone' */

  /* Sum: '<S413>/Add' incorporates:
   *  DiscreteIntegrator: '<S412>/Integrator1'
   *  Gain: '<S406>/Gain6'
   *  Gain: '<S411>/Gain'
   *  Sum: '<S412>/Subtract'
   */
  rtb_Subtract3_h_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_h_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_e1_idx_1;

  /* Signum: '<S413>/Sign' */
  if (rtb_Subtract3_h_idx_0 < 0.0F) {
    rtb_Subtract3_h_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0 > 0.0F) {
    rtb_Subtract3_h_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0_0 = rtb_Subtract3_h_idx_0;
  }

  /* Sum: '<S413>/Add2' incorporates:
   *  Abs: '<S413>/Abs'
   *  Gain: '<S413>/Gain'
   *  Gain: '<S413>/Gain1'
   *  Product: '<S413>/Multiply2'
   *  Product: '<S413>/Multiply3'
   *  Signum: '<S413>/Sign'
   *  Sqrt: '<S413>/Sqrt'
   *  Sum: '<S413>/Add1'
   *  Sum: '<S413>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_h_idx_0_0 +
    rtb_Add3_e1_idx_0;

  /* Sum: '<S413>/Add3' incorporates:
   *  Signum: '<S413>/Sign'
   */
  u = rtb_Subtract3_h_idx_0 + localC->d;

  /* Sum: '<S413>/Subtract1' incorporates:
   *  Signum: '<S413>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_0 - localC->d;

  /* Signum: '<S413>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S413>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S413>/Add5' incorporates:
   *  Gain: '<S413>/Gain2'
   *  Product: '<S413>/Multiply4'
   *  Signum: '<S413>/Sign'
   *  Sum: '<S413>/Add2'
   *  Sum: '<S413>/Add4'
   *  Sum: '<S413>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_0 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_0) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S412>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S412>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S413>/Sign3' incorporates:
   *  Sum: '<S413>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S413>/Sign4' incorporates:
   *  Sum: '<S413>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S413>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S413>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S413>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S413>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S412>/Integrator' incorporates:
   *  Constant: '<S413>/const'
   *  Gain: '<S413>/Gain3'
   *  Product: '<S413>/Divide'
   *  Product: '<S413>/Multiply5'
   *  Product: '<S413>/Multiply6'
   *  Sum: '<S413>/Subtract4'
   *  Sum: '<S413>/Subtract5'
   *  Sum: '<S413>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;

  /* Signum: '<S413>/Sign' */
  if (rtb_Subtract3_h_idx_1 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_1 > 0.0F) {
    rtb_Add3_e1_idx_0 = 1.0F;
  } else {
    rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_1;
  }

  /* Sum: '<S413>/Add2' incorporates:
   *  Abs: '<S413>/Abs'
   *  Gain: '<S413>/Gain'
   *  Gain: '<S413>/Gain1'
   *  Product: '<S413>/Multiply2'
   *  Product: '<S413>/Multiply3'
   *  Signum: '<S413>/Sign'
   *  Sqrt: '<S413>/Sqrt'
   *  Sum: '<S413>/Add1'
   *  Sum: '<S413>/Subtract'
   */
  rtb_Subtract3_h_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_h_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_e1_idx_0 +
    rtb_Add3_e1_idx_1;

  /* Sum: '<S413>/Add3' incorporates:
   *  Signum: '<S413>/Sign'
   */
  u = rtb_Subtract3_h_idx_1 + localC->d;

  /* Sum: '<S413>/Subtract1' incorporates:
   *  Signum: '<S413>/Sign'
   */
  rtb_Subtract3_nv = rtb_Subtract3_h_idx_1 - localC->d;

  /* Signum: '<S413>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S413>/Sign2' */
  if (rtb_Subtract3_nv < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else {
    if (rtb_Subtract3_nv > 0.0F) {
      rtb_Subtract3_nv = 1.0F;
    }
  }

  /* Sum: '<S413>/Add5' incorporates:
   *  Gain: '<S413>/Gain2'
   *  Product: '<S413>/Multiply4'
   *  Signum: '<S413>/Sign'
   *  Sum: '<S413>/Add2'
   *  Sum: '<S413>/Add4'
   *  Sum: '<S413>/Subtract2'
   */
  rtb_Subtract3_h_idx_0_0 += ((rtb_Subtract3_h_idx_1 - rtb_Subtract3_h_idx_0_0)
    + rtb_Add3_e1_idx_1) * ((u - rtb_Subtract3_nv) * 0.5F);

  /* Update for DiscreteIntegrator: '<S412>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S412>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S413>/Sign3' incorporates:
   *  Sum: '<S413>/Add6'
   */
  u = rtb_Subtract3_h_idx_0_0 + localC->d;

  /* Signum: '<S413>/Sign4' incorporates:
   *  Sum: '<S413>/Subtract3'
   */
  rtb_Add3_e1_idx_0 = rtb_Subtract3_h_idx_0_0 - localC->d;

  /* Signum: '<S413>/Sign5' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_h_idx_0 = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_h_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_h_idx_0 = rtb_Subtract3_h_idx_0_0;
  }

  /* Signum: '<S413>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S413>/Sign4' */
  if (rtb_Add3_e1_idx_0 < 0.0F) {
    rtb_Add3_e1_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_e1_idx_0 > 0.0F) {
      rtb_Add3_e1_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S413>/Sign6' */
  if (rtb_Subtract3_h_idx_0_0 < 0.0F) {
    rtb_Subtract3_nv = -1.0F;
  } else if (rtb_Subtract3_h_idx_0_0 > 0.0F) {
    rtb_Subtract3_nv = 1.0F;
  } else {
    rtb_Subtract3_nv = rtb_Subtract3_h_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S412>/Integrator' incorporates:
   *  Constant: '<S413>/const'
   *  Gain: '<S413>/Gain3'
   *  Product: '<S413>/Divide'
   *  Product: '<S413>/Multiply5'
   *  Product: '<S413>/Multiply6'
   *  Sum: '<S413>/Subtract4'
   *  Sum: '<S413>/Subtract5'
   *  Sum: '<S413>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_h_idx_0_0 / localC->d -
    rtb_Subtract3_h_idx_0) * localC->Gain4 * ((u - rtb_Add3_e1_idx_0) * 0.5F) -
    rtb_Subtract3_nv * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S403>/Motion State'
 *    '<S349>/Motion State'
 *    '<S184>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * System reset for atomic system:
 *    '<S403>/Motion State'
 *    '<S349>/Motion State'
 *    '<S184>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_d;
}

/*
 * Output and update for atomic system:
 *    '<S403>/Motion State'
 *    '<S349>/Motion State'
 *    '<S184>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S403>/Motion State' */
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

  /* End of Chart: '<S403>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S386>/NearbyRefWP'
 *    '<S164>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S417>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S336>/Hold Control'
 *    '<S125>/Hold Control'
 *    '<S61>/Hold Control'
 *    '<S88>/Hold Control'
 */
void FMS_HoldControl_p_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S339>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S336>/Hold Control'
 *    '<S125>/Hold Control'
 *    '<S61>/Hold Control'
 *    '<S88>/Hold Control'
 */
void FMS_HoldControl_h_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S339>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S336>/Hold Control'
 *    '<S125>/Hold Control'
 *    '<S61>/Hold Control'
 *    '<S88>/Hold Control'
 */
void FMS_HoldControl_kq(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_l;

  /* Delay: '<S339>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S339>/Sum' incorporates:
   *  Delay: '<S339>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S342>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad);

  /* Switch: '<S342>/Switch' incorporates:
   *  Constant: '<S342>/Constant'
   *  Constant: '<S343>/Constant'
   *  Product: '<S342>/Multiply'
   *  RelationalOperator: '<S343>/Compare'
   *  Sum: '<S342>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S342>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S342>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S342>/Switch' */

  /* Gain: '<S339>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S339>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S336>/Move Control'
 *    '<S125>/Move Control'
 *    '<S61>/Move Control'
 *    '<S88>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S345>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S345>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S336>/Move Control'
 *    '<S125>/Move Control'
 *    '<S61>/Move Control'
 *    '<S88>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S345>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S345>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S336>/Move Control'
 *    '<S125>/Move Control'
 *    '<S61>/Move Control'
 *    '<S88>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_a;
  real32_T rtb_Subtract3_i;
  real32_T rtb_a_b;
  real32_T rtb_Add4_bf;
  real32_T rtb_a_p;

  /* Product: '<S346>/Multiply1' incorporates:
   *  Constant: '<S346>/const1'
   *  DiscreteIntegrator: '<S345>/Integrator'
   */
  rtb_Add3_a = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S344>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_b = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_b = 0.0F;
  } else {
    rtb_a_b = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S344>/Dead Zone' */

  /* Sum: '<S346>/Add' incorporates:
   *  DiscreteIntegrator: '<S345>/Integrator1'
   *  Gain: '<S340>/Gain1'
   *  Gain: '<S344>/Gain'
   *  Sum: '<S345>/Subtract'
   */
  rtb_Subtract3_i = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_b * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_a;

  /* Signum: '<S346>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_a_b = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_a_b = 1.0F;
  } else {
    rtb_a_b = rtb_Subtract3_i;
  }

  /* End of Signum: '<S346>/Sign' */

  /* Sum: '<S346>/Add2' incorporates:
   *  Abs: '<S346>/Abs'
   *  Gain: '<S346>/Gain'
   *  Gain: '<S346>/Gain1'
   *  Product: '<S346>/Multiply2'
   *  Product: '<S346>/Multiply3'
   *  Sqrt: '<S346>/Sqrt'
   *  Sum: '<S346>/Add1'
   *  Sum: '<S346>/Subtract'
   */
  rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_b + rtb_Add3_a;

  /* Sum: '<S346>/Add4' */
  rtb_Add4_bf = (rtb_Subtract3_i - rtb_a_b) + rtb_Add3_a;

  /* Sum: '<S346>/Add3' */
  rtb_Add3_a = rtb_Subtract3_i + localC->d;

  /* Sum: '<S346>/Subtract1' */
  rtb_Subtract3_i -= localC->d;

  /* Signum: '<S346>/Sign1' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S346>/Sign1' */

  /* Signum: '<S346>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S346>/Sign2' */

  /* Sum: '<S346>/Add5' incorporates:
   *  Gain: '<S346>/Gain2'
   *  Product: '<S346>/Multiply4'
   *  Sum: '<S346>/Subtract2'
   */
  rtb_a_b += (rtb_Add3_a - rtb_Subtract3_i) * 0.5F * rtb_Add4_bf;

  /* SignalConversion: '<S340>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S345>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S345>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S345>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S346>/Add6' */
  rtb_Add3_a = rtb_a_b + localC->d;

  /* Sum: '<S346>/Subtract3' */
  rtb_Subtract3_i = rtb_a_b - localC->d;

  /* Signum: '<S346>/Sign5' */
  if (rtb_a_b < 0.0F) {
    rtb_Add4_bf = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_Add4_bf = 1.0F;
  } else {
    rtb_Add4_bf = rtb_a_b;
  }

  /* End of Signum: '<S346>/Sign5' */

  /* Signum: '<S346>/Sign3' */
  if (rtb_Add3_a < 0.0F) {
    rtb_Add3_a = -1.0F;
  } else {
    if (rtb_Add3_a > 0.0F) {
      rtb_Add3_a = 1.0F;
    }
  }

  /* End of Signum: '<S346>/Sign3' */

  /* Signum: '<S346>/Sign4' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S346>/Sign4' */

  /* Signum: '<S346>/Sign6' */
  if (rtb_a_b < 0.0F) {
    rtb_a_p = -1.0F;
  } else if (rtb_a_b > 0.0F) {
    rtb_a_p = 1.0F;
  } else {
    rtb_a_p = rtb_a_b;
  }

  /* End of Signum: '<S346>/Sign6' */

  /* Update for DiscreteIntegrator: '<S345>/Integrator' incorporates:
   *  Constant: '<S346>/const'
   *  Gain: '<S346>/Gain3'
   *  Product: '<S346>/Divide'
   *  Product: '<S346>/Multiply5'
   *  Product: '<S346>/Multiply6'
   *  Sum: '<S346>/Subtract4'
   *  Sum: '<S346>/Subtract5'
   *  Sum: '<S346>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_b / localC->d - rtb_Add4_bf) *
    localC->Gain4 * ((rtb_Add3_a - rtb_Subtract3_i) * 0.5F) - rtb_a_p *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S126>/Motion State'
 *    '<S62>/Motion State'
 *    '<S89>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S126>/Motion State'
 *    '<S62>/Motion State'
 *    '<S89>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S126>/Motion State'
 *    '<S62>/Motion State'
 *    '<S89>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S126>/Motion State' */
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

  /* End of Chart: '<S126>/Motion State' */
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

  /* Gain: '<S445>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S446>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S446>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S446>/Multiply1' incorporates:
   *  Product: '<S446>/Multiply'
   */
  rtb_Gain_d = localC->ff * rtb_Sum2_ee;

  /* Product: '<S446>/Divide' incorporates:
   *  Constant: '<S446>/Constant'
   *  Constant: '<S446>/R'
   *  Sqrt: '<S446>/Sqrt'
   *  Sum: '<S446>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_d);

  /* Product: '<S446>/Product3' incorporates:
   *  Constant: '<S446>/Constant1'
   *  Product: '<S446>/Multiply1'
   *  Sum: '<S446>/Sum2'
   */
  rtb_Gain_d = 1.0 / (1.0 - rtb_Gain_d) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S446>/Multiply2' incorporates:
   *  Trigonometry: '<S446>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S445>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S450>/Abs' incorporates:
   *  Abs: '<S453>/Abs1'
   *  Switch: '<S450>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S450>/Switch1' incorporates:
   *  Abs: '<S450>/Abs'
   *  Bias: '<S450>/Bias2'
   *  Bias: '<S450>/Bias3'
   *  Constant: '<S447>/Constant'
   *  Constant: '<S447>/Constant1'
   *  Constant: '<S452>/Constant'
   *  Gain: '<S450>/Gain1'
   *  Product: '<S450>/Multiply'
   *  RelationalOperator: '<S452>/Compare'
   *  Switch: '<S447>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S453>/Switch1' incorporates:
     *  Bias: '<S453>/Bias2'
     *  Bias: '<S453>/Bias3'
     *  Constant: '<S453>/Constant'
     *  Constant: '<S454>/Constant'
     *  Math: '<S453>/Math Function'
     *  RelationalOperator: '<S454>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S453>/Switch1' */

    /* Signum: '<S450>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S450>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S447>/Sum' incorporates:
   *  Sum: '<S445>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S445>/Multiply' incorporates:
   *  Gain: '<S445>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_d;

  /* Switch: '<S449>/Switch1' incorporates:
   *  Abs: '<S449>/Abs1'
   *  Bias: '<S449>/Bias2'
   *  Bias: '<S449>/Bias3'
   *  Constant: '<S449>/Constant'
   *  Constant: '<S451>/Constant'
   *  Math: '<S449>/Math Function'
   *  RelationalOperator: '<S451>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S449>/Switch1' */

  /* Product: '<S445>/Multiply' incorporates:
   *  Gain: '<S445>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S445>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S448>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_d = cos(rtb_Sum2_ee);

  /* Sum: '<S448>/Sum2' incorporates:
   *  Product: '<S448>/Multiply1'
   *  Product: '<S448>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_d + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S448>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S448>/Multiply4' */
  rtb_Gain_d *= rtb_Sum_d;

  /* Sum: '<S448>/Sum3' */
  rtb_Sum3_l = rtb_Gain_d - rtb_Sum3_l;

  /* DataTypeConversion: '<S442>/Data Type Conversion' incorporates:
   *  Gain: '<S445>/Gain'
   *  Sum: '<S445>/Sum1'
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
  /* RelationalOperator: '<S455>/Compare' incorporates:
   *  Abs: '<S444>/Abs'
   *  Constant: '<S455>/Constant'
   *  MinMax: '<S444>/Max'
   *  Sum: '<S444>/Sum'
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

    /* Outputs for Function Call SubSystem: '<S4>/Vehicle.PrepTakeoff' */
    /* Reshape: '<S443>/Reshape' incorporates:
     *  Constant: '<S443>/Constant'
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

  /* Sqrt: '<S465>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S465>/Square'
   *  Sum: '<S465>/Sum of Elements'
   */
  rtb_Saturation_n = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
    FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
    FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S461>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Rem_k = FMS_U.INS_Out.quat[0] / rtb_Saturation_n;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Saturation_n;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_n;
  rtb_Saturation_n = FMS_U.INS_Out.quat[3] / rtb_Saturation_n;

  /* Math: '<S462>/Square' incorporates:
   *  Math: '<S463>/Square'
   *  Math: '<S464>/Square'
   */
  rtb_MathFunction_h_idx_0 = rtb_Rem_k * rtb_Rem_k;

  /* Math: '<S462>/Square2' incorporates:
   *  Math: '<S463>/Square2'
   *  Math: '<S464>/Square2'
   */
  rtb_MathFunction_h_idx_1 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S462>/Square1' incorporates:
   *  Math: '<S463>/Square1'
   *  Math: '<S464>/Square1'
   */
  rtb_Switch_k = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S462>/Square3' incorporates:
   *  Math: '<S463>/Square3'
   *  Math: '<S464>/Square3'
   */
  rtb_a_i = rtb_Saturation_n * rtb_Saturation_n;

  /* Sum: '<S462>/Subtract' incorporates:
   *  Math: '<S462>/Square'
   *  Math: '<S462>/Square1'
   *  Math: '<S462>/Square2'
   *  Math: '<S462>/Square3'
   *  Sum: '<S462>/Add'
   *  Sum: '<S462>/Add1'
   */
  rtb_Transpose[0] = (rtb_MathFunction_h_idx_0 + rtb_Switch_k) -
    (rtb_MathFunction_h_idx_1 + rtb_a_i);

  /* Product: '<S462>/Multiply' incorporates:
   *  Product: '<S463>/Multiply'
   */
  rtb_MathFunction_iq_idx_0 = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S462>/Multiply1' incorporates:
   *  Product: '<S463>/Multiply1'
   */
  rtb_P_d_idx_0 = rtb_Rem_k * rtb_Saturation_n;

  /* Gain: '<S462>/Gain' incorporates:
   *  Product: '<S462>/Multiply'
   *  Product: '<S462>/Multiply1'
   *  Sum: '<S462>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_MathFunction_iq_idx_0 - rtb_P_d_idx_0) * 2.0F;

  /* Product: '<S462>/Multiply2' incorporates:
   *  Product: '<S464>/Multiply'
   */
  rtb_Rem_o = rtb_Divide_l_idx_1 * rtb_Saturation_n;

  /* Product: '<S462>/Multiply3' incorporates:
   *  Product: '<S464>/Multiply1'
   */
  B = rtb_Rem_k * rtb_Divide_l_idx_2;

  /* Gain: '<S462>/Gain1' incorporates:
   *  Product: '<S462>/Multiply2'
   *  Product: '<S462>/Multiply3'
   *  Sum: '<S462>/Add2'
   */
  rtb_Transpose[2] = (rtb_Rem_o + B) * 2.0F;

  /* Gain: '<S463>/Gain' incorporates:
   *  Sum: '<S463>/Add3'
   */
  rtb_Transpose[3] = (rtb_MathFunction_iq_idx_0 + rtb_P_d_idx_0) * 2.0F;

  /* Sum: '<S463>/Subtract' incorporates:
   *  Sum: '<S463>/Add'
   *  Sum: '<S463>/Add1'
   */
  rtb_Transpose[4] = (rtb_MathFunction_h_idx_0 + rtb_MathFunction_h_idx_1) -
    (rtb_Switch_k + rtb_a_i);

  /* Product: '<S463>/Multiply2' incorporates:
   *  Product: '<S464>/Multiply2'
   */
  rtb_MathFunction_iq_idx_0 = rtb_Divide_l_idx_2 * rtb_Saturation_n;

  /* Product: '<S463>/Multiply3' incorporates:
   *  Product: '<S464>/Multiply3'
   */
  rtb_P_d_idx_0 = rtb_Rem_k * rtb_Divide_l_idx_1;

  /* Gain: '<S463>/Gain1' incorporates:
   *  Product: '<S463>/Multiply2'
   *  Product: '<S463>/Multiply3'
   *  Sum: '<S463>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_MathFunction_iq_idx_0 - rtb_P_d_idx_0) * 2.0F;

  /* Gain: '<S464>/Gain' incorporates:
   *  Sum: '<S464>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_Rem_o - B) * 2.0F;

  /* Gain: '<S464>/Gain1' incorporates:
   *  Sum: '<S464>/Add2'
   */
  rtb_Transpose[7] = (rtb_MathFunction_iq_idx_0 + rtb_P_d_idx_0) * 2.0F;

  /* Sum: '<S464>/Subtract' incorporates:
   *  Sum: '<S464>/Add'
   *  Sum: '<S464>/Add1'
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

  /* DiscreteIntegrator: '<S456>/Discrete-Time Integrator5' */
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

  /* DiscreteIntegrator: '<S458>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S458>/Data Type Conversion'
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

  /* DiscreteIntegrator: '<S457>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_l_idx_2;
  }

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S456>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S457>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S458>/Discrete-Time Integrator5'
   *  Logic: '<S459>/AND'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S459>/Lower Test'
   *  RelationalOperator: '<S459>/Upper Test'
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
        /* Disable for SwitchCase: '<S402>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S392>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S348>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S326>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S336>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S30>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S138>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S183>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S173>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S138>/Mission_SubSystem' */
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
        /* Disable for SwitchCase: '<S125>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S44>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S61>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S101>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S77>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S88>/Switch Case' */
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
          /* Disable for SwitchCase: '<S402>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S392>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S348>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S326>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S336>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S30>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S138>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S183>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S173>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S138>/Mission_SubSystem' */
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
          /* Disable for SwitchCase: '<S125>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S44>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S61>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S101>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S77>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S88>/Switch Case' */
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
       *  Math: '<S424>/Math Function'
       *  Product: '<S426>/Divide'
       *  Sum: '<S387>/Subtract'
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
          /* Disable for SwitchCase: '<S402>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S392>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S348>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S326>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S336>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S32>/Takeoff' incorporates:
           *  ActionPort: '<S321>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S32>/Switch Case' incorporates:
           *  Delay: '<S439>/cur_waypoint'
           */
          FMS_DW.icLoad_j1 = 1U;

          /* End of InitializeConditions for SubSystem: '<S32>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S32>/Takeoff' incorporates:
         *  ActionPort: '<S321>/Action Port'
         */
        /* Delay: '<S439>/cur_waypoint' incorporates:
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
        /* Product: '<S439>/Divide' incorporates:
         *  Delay: '<S439>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S439>/Sum1'
         *  Sum: '<S439>/Sum2'
         */
        rtb_Divide_l_idx_1 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
          FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Saturate: '<S439>/Saturation' */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Divide_l_idx_1 = 0.0F;
          }
        }

        /* End of Saturate: '<S439>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S440>/Trigonometric Function1' incorporates:
         *  Gain: '<S438>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Trigonometry: '<S440>/Trigonometric Function3'
         */
        rtb_MathFunction_h_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S440>/Trigonometric Function' incorporates:
         *  Gain: '<S438>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Trigonometry: '<S440>/Trigonometric Function2'
         */
        rtb_MathFunction_h_idx_1 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

        /* SignalConversion: '<S440>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S440>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S440>/Gain' */
        rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

        /* Trigonometry: '<S440>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

        /* SignalConversion: '<S440>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S440>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S440>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S434>/Saturation1' */
        rtb_Switch_k = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Rem_k = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* SignalConversion: '<S434>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S439>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S439>/Multiply'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S434>/Sum'
         *  Sum: '<S439>/Sum3'
         *  Sum: '<S439>/Sum4'
         */
        rtb_Saturation_n = ((FMS_B.Cmd_In.sp_waypoint[0] -
                             FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_l_idx_1
                            + FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
        rtb_a_i = ((FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.cur_waypoint_DSTATE[1])
                   * rtb_Divide_l_idx_1 + FMS_DW.cur_waypoint_DSTATE[1]) -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S434>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i]
            * rtb_Saturation_n;
        }

        /* Saturate: '<S434>/Saturation1' incorporates:
         *  Gain: '<S434>/Gain2'
         *  Product: '<S434>/Multiply'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_a_i = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S321>/Bus Assignment1'
         *  Constant: '<S321>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S321>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S321>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S434>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Switch_k) {
          /* BusAssignment: '<S321>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_k;
        } else if (rtb_Divide_l_idx_1 < rtb_Rem_k) {
          /* BusAssignment: '<S321>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S321>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_a_i > rtb_Switch_k) {
          /* BusAssignment: '<S321>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_k;
        } else if (rtb_a_i < rtb_Rem_k) {
          /* BusAssignment: '<S321>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S321>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_i;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S433>/Switch' incorporates:
         *  Abs: '<S433>/Abs'
         *  Abs: '<S433>/Abs1'
         *  Constant: '<S435>/Constant'
         *  Constant: '<S436>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S433>/Logical Operator'
         *  RelationalOperator: '<S435>/Compare'
         *  RelationalOperator: '<S436>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S433>/Sum'
         *  Sum: '<S433>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          /* BusAssignment: '<S321>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Constant: '<S433>/Constant6'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -1.0F;
        } else {
          /* BusAssignment: '<S321>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Constant: '<S433>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -0.5F;
        }

        /* End of Switch: '<S433>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Update for Delay: '<S439>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* End of Outputs for SubSystem: '<S32>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S32>/Land' incorporates:
         *  ActionPort: '<S319>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Trigonometry: '<S365>/Trigonometric Function1' incorporates:
         *  Gain: '<S364>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S365>/Trigonometric Function' incorporates:
         *  Gain: '<S364>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SignalConversion: '<S365>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S365>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S365>/Gain' incorporates:
         *  Gain: '<S364>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Trigonometry: '<S365>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S365>/Trigonometric Function3' incorporates:
         *  Gain: '<S364>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SignalConversion: '<S365>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S365>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S365>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S361>/Saturation1' */
        rtb_Switch_k = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Rem_k = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* SignalConversion: '<S362>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S362>/Sum'
         */
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_a_i = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S362>/Multiply' incorporates:
         *  SignalConversion: '<S362>/TmpSignal ConversionAtMultiplyInport2'
         */
        for (i = 0; i < 3; i++) {
          rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i]
            * rtb_Saturation_n;
        }

        /* End of Product: '<S362>/Multiply' */

        /* Saturate: '<S361>/Saturation1' incorporates:
         *  Gain: '<S362>/Gain2'
         */
        rtb_Divide_l_idx_1 = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_a_i = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S319>/Bus Assignment1'
         *  Constant: '<S319>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S319>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S319>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S361>/Saturation1' */
        if (rtb_Divide_l_idx_1 > rtb_Switch_k) {
          /* BusAssignment: '<S319>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_k;
        } else if (rtb_Divide_l_idx_1 < rtb_Rem_k) {
          /* BusAssignment: '<S319>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S319>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_1;
        }

        if (rtb_a_i > rtb_Switch_k) {
          /* BusAssignment: '<S319>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_k;
        } else if (rtb_a_i < rtb_Rem_k) {
          /* BusAssignment: '<S319>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Rem_k;
        } else {
          /* BusAssignment: '<S319>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_i;
        }

        /* BusAssignment: '<S319>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S319>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S32>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S32>/Return' incorporates:
           *  ActionPort: '<S320>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S32>/Switch Case' incorporates:
           *  Delay: '<S368>/Delay'
           *  Delay: '<S369>/Delay'
           *  Delay: '<S388>/Delay'
           *  DiscreteIntegrator: '<S372>/Integrator'
           *  DiscreteIntegrator: '<S372>/Integrator1'
           *  DiscreteIntegrator: '<S429>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_o = 1U;
          FMS_DW.l1_heading_p = 0.0F;
          FMS_DW.icLoad_c = 1U;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING_j = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S32>/Return' */

          /* SystemReset for IfAction SubSystem: '<S32>/Return' incorporates:
           *  ActionPort: '<S320>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S32>/Switch Case' incorporates:
           *  Chart: '<S393>/Motion Status'
           *  Chart: '<S403>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S32>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S32>/Return' incorporates:
         *  ActionPort: '<S320>/Action Port'
         */
        /* Delay: '<S388>/Delay' incorporates:
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
        /* Sum: '<S384>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];
        rtb_MathFunction_iq_idx_0 = FMS_U.INS_Out.y_R -
          FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sqrt: '<S389>/Sqrt' incorporates:
         *  Math: '<S389>/Square'
         *  Sum: '<S384>/Sum'
         *  Sum: '<S389>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

        /* Switch: '<S384>/Switch' incorporates:
         *  Constant: '<S384>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S384>/Gain' */
          rtb_Switch_k = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S384>/Saturation' */
          if (rtb_Switch_k > FMS_PARAM.CRUISE_SPEED) {
            rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Switch_k < 0.5F) {
              rtb_Switch_k = 0.5F;
            }
          }

          /* End of Saturate: '<S384>/Saturation' */
        }

        /* End of Switch: '<S384>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S403>/Motion State' incorporates:
         *  Constant: '<S403>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S403>/Square'
         *  Math: '<S403>/Square1'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sqrt: '<S403>/Sqrt'
         *  Sum: '<S403>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S402>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S402>/Hold Control' incorporates:
             *  ActionPort: '<S405>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S402>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S402>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S402>/Hold Control' incorporates:
           *  ActionPort: '<S405>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_mv,
                            &FMS_ConstB.HoldControl_k, &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S402>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S402>/Brake Control' incorporates:
           *  ActionPort: '<S404>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_mv);

          /* End of Outputs for SubSystem: '<S402>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S402>/Move Control' incorporates:
             *  ActionPort: '<S406>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S402>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S402>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S402>/Move Control' incorporates:
           *  ActionPort: '<S406>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_mv,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S402>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S402>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S393>/Motion Status' incorporates:
         *  Abs: '<S393>/Abs'
         *  Constant: '<S393>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S392>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S392>/Hold Control' incorporates:
             *  ActionPort: '<S395>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S392>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S392>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S392>/Hold Control' incorporates:
           *  ActionPort: '<S395>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S392>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S392>/Brake Control' incorporates:
           *  ActionPort: '<S394>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S392>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S392>/Move Control' incorporates:
             *  ActionPort: '<S396>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S392>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S392>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S392>/Move Control' incorporates:
           *  ActionPort: '<S396>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_mu,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S392>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S392>/Switch Case' */

        /* Delay: '<S368>/Delay' incorporates:
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
        /* Sum: '<S320>/Sum' incorporates:
         *  Delay: '<S368>/Delay'
         *  MATLAB Function: '<S386>/OutRegionRegWP'
         *  MATLAB Function: '<S386>/SearchL1RefWP'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_MathFunction_iq_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S383>/Sum of Elements' incorporates:
         *  Math: '<S383>/Math Function'
         *  Sum: '<S320>/Sum'
         */
        rtb_Saturation_n = rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0
          + rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Math: '<S383>/Math Function1' incorporates:
         *  Sum: '<S383>/Sum of Elements'
         *
         * About '<S383>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_a_i = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_a_i = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S383>/Math Function1' */

        /* Switch: '<S383>/Switch' incorporates:
         *  Constant: '<S383>/Constant'
         *  Product: '<S383>/Product'
         *  Sum: '<S320>/Sum'
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

        /* End of Switch: '<S383>/Switch' */

        /* Product: '<S383>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S381>/Subtract' incorporates:
         *  Product: '<S381>/Multiply'
         *  Product: '<S381>/Multiply1'
         */
        rtb_a_i = rtb_Saturation1_ln[0] * FMS_ConstB.Divide_d[1] -
          rtb_Saturation1_ln[1] * FMS_ConstB.Divide_d[0];

        /* Signum: '<S370>/Sign1' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S370>/Sign1' */

        /* Switch: '<S370>/Switch2' incorporates:
         *  Constant: '<S370>/Constant4'
         */
        if (rtb_a_i == 0.0F) {
          rtb_a_i = 1.0F;
        }

        /* End of Switch: '<S370>/Switch2' */

        /* DotProduct: '<S370>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide_d[0] * rtb_Saturation1_ln[0] +
          FMS_ConstB.Divide_d[1] * rtb_Saturation1_ln[1];

        /* Trigonometry: '<S370>/Acos' incorporates:
         *  DotProduct: '<S370>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S370>/Multiply' incorporates:
         *  Trigonometry: '<S370>/Acos'
         */
        rtb_a_i *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S374>/Rem' incorporates:
         *  Constant: '<S374>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S369>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_a_i - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S374>/Switch' incorporates:
         *  Abs: '<S374>/Abs'
         *  Constant: '<S374>/Constant'
         *  Constant: '<S380>/Constant'
         *  Product: '<S374>/Multiply'
         *  RelationalOperator: '<S380>/Compare'
         *  Sum: '<S374>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S374>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S374>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S374>/Switch' */

        /* Abs: '<S367>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S367>/Switch' incorporates:
         *  Product: '<S388>/Multiply'
         *  Sum: '<S388>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S402>/Saturation1' */
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

          /* End of Saturate: '<S402>/Saturation1' */

          /* Saturate: '<S392>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S392>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S388>/Sum' incorporates:
           *  Delay: '<S388>/Delay'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S430>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_ec[0] = rtb_Divide_l_idx_1;
          rtb_Saturation1_ln[0] = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S388>/Sum' incorporates:
           *  Delay: '<S388>/Delay'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S432>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S432>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S431>/Gain' incorporates:
           *  DiscreteIntegrator: '<S429>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S429>/Add'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_p);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Trigonometry: '<S432>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S432>/Trigonometric Function1'
           */
          rtb_MathFunction_h_idx_0 = arm_cos_f32(rtb_Saturation_n);
          rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

          /* Trigonometry: '<S432>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S432>/Trigonometric Function'
           */
          rtb_MathFunction_h_idx_1 = arm_sin_f32(rtb_Saturation_n);

          /* Gain: '<S432>/Gain' incorporates:
           *  Trigonometry: '<S432>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

          /* SignalConversion: '<S432>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S432>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S432>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

          /* Trigonometry: '<S432>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

          /* SignalConversion: '<S432>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_k[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_k[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_k[2];

          /* Sum: '<S430>/Sum of Elements' incorporates:
           *  Math: '<S430>/Math Function'
           */
          rtb_Saturation_n = rtb_Switch_ec[0] * rtb_Switch_ec[0] +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

          /* Math: '<S430>/Math Function1' incorporates:
           *  Sum: '<S430>/Sum of Elements'
           *
           * About '<S430>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S430>/Math Function1' */

          /* Switch: '<S430>/Switch' incorporates:
           *  Constant: '<S430>/Constant'
           *  Product: '<S430>/Product'
           */
          if (rtb_Saturation_n > 0.0F) {
            rtb_Rem_k = rtb_Saturation1_ln[0];
          } else {
            rtb_Rem_k = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Saturation_n = 1.0F;
          }

          /* End of Switch: '<S430>/Switch' */

          /* Product: '<S428>/Multiply2' incorporates:
           *  Product: '<S430>/Divide'
           */
          rtb_Rem_k = rtb_Rem_k / rtb_Saturation_n * rtb_Switch_k;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_Saturation_n *
            rtb_Switch_k;
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[i] * rtb_Rem_k;
          }
        }

        /* End of Switch: '<S367>/Switch' */

        /* Delay: '<S369>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S372>/Integrator1' incorporates:
         *  Delay: '<S369>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S376>/Rem' incorporates:
         *  Constant: '<S376>/Constant1'
         *  DiscreteIntegrator: '<S372>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S371>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S376>/Switch' incorporates:
         *  Abs: '<S376>/Abs'
         *  Constant: '<S376>/Constant'
         *  Constant: '<S377>/Constant'
         *  Product: '<S376>/Multiply'
         *  RelationalOperator: '<S377>/Compare'
         *  Sum: '<S376>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S376>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_k;
          }

          /* End of Signum: '<S376>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S376>/Switch' */

        /* Gain: '<S371>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S371>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S371>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S320>/Bus Assignment1'
         *  Constant: '<S320>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S320>/Bus Assignment1' incorporates:
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
        /* Sum: '<S423>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S423>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S421>/Sum of Elements'
         */
        rtb_Saturation_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S423>/Math Function1' incorporates:
         *  Sum: '<S423>/Sum of Elements'
         *
         * About '<S423>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Rem_k = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S423>/Math Function1' */

        /* Switch: '<S423>/Switch' incorporates:
         *  Constant: '<S423>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S423>/Product'
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

        /* End of Switch: '<S423>/Switch' */

        /* Product: '<S423>/Divide' */
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S426>/Sum of Elements' incorporates:
         *  Math: '<S426>/Math Function'
         *  SignalConversion: '<S426>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_Saturation1_ln[1] * rtb_Saturation1_ln[1] +
          rtb_Saturation1_ln[0] * rtb_Saturation1_ln[0];

        /* Math: '<S426>/Math Function1' incorporates:
         *  Sum: '<S426>/Sum of Elements'
         *
         * About '<S426>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S426>/Math Function1' */

        /* Switch: '<S426>/Switch' incorporates:
         *  Constant: '<S426>/Constant'
         *  Product: '<S426>/Product'
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

        /* End of Switch: '<S426>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S386>/NearbyRefWP' incorporates:
         *  Constant: '<S320>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Saturation1_ln,
                        &rtb_Rem_o);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* MATLAB Function: '<S386>/SearchL1RefWP' incorporates:
         *  Constant: '<S320>/L1'
         *  Delay: '<S368>/Delay'
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
        /* MATLAB Function: '<S386>/OutRegionRegWP' incorporates:
         *  Delay: '<S368>/Delay'
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

        /* Switch: '<S386>/Switch1' incorporates:
         *  Constant: '<S416>/Constant'
         *  RelationalOperator: '<S416>/Compare'
         */
        if (rtb_Rem_o <= 0.0F) {
          /* Switch: '<S386>/Switch' incorporates:
           *  Constant: '<S415>/Constant'
           *  MATLAB Function: '<S386>/SearchL1RefWP'
           *  RelationalOperator: '<S415>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;
            rtb_Saturation1_ln[1] = rtb_MathFunction_h_idx_1;
          } else {
            rtb_Saturation1_ln[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S386>/OutRegionRegWP' incorporates:
             *  Delay: '<S368>/Delay'
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

          /* End of Switch: '<S386>/Switch' */
        }

        /* End of Switch: '<S386>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S387>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_Saturation1_ln[0] = rtb_MathFunction_h_idx_0;
        rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S387>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S424>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S424>/Math Function' incorporates:
         *  Math: '<S422>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Sum: '<S424>/Sum of Elements' incorporates:
         *  Math: '<S424>/Math Function'
         */
        rtb_Rem_k = rtb_Divide_l_idx_1 + rtb_TmpSignalConversionAtDela_a[0];

        /* Math: '<S424>/Math Function1' incorporates:
         *  Sum: '<S424>/Sum of Elements'
         *
         * About '<S424>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S424>/Math Function1' */

        /* Switch: '<S424>/Switch' incorporates:
         *  Constant: '<S424>/Constant'
         *  Product: '<S424>/Product'
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

        /* End of Switch: '<S424>/Switch' */

        /* Product: '<S424>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S427>/Sum of Elements' incorporates:
         *  Math: '<S427>/Math Function'
         *  SignalConversion: '<S427>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_k = rtb_P_d_idx_0 * rtb_P_d_idx_0 + rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0;

        /* Math: '<S427>/Math Function1' incorporates:
         *  Sum: '<S427>/Sum of Elements'
         *
         * About '<S427>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Rem_k));
        } else {
          rtb_Rem_k = sqrtf(rtb_Rem_k);
        }

        /* End of Math: '<S427>/Math Function1' */

        /* Switch: '<S427>/Switch' incorporates:
         *  Constant: '<S427>/Constant'
         *  Product: '<S427>/Product'
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

        /* End of Switch: '<S427>/Switch' */

        /* Product: '<S427>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S422>/Square' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Saturation1_ln[0] *
          rtb_Saturation1_ln[0];
        rtb_Saturation1_ln[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];

        /* Product: '<S427>/Divide' incorporates:
         *  Product: '<S426>/Divide'
         */
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S426>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sqrt: '<S421>/Sqrt' */
        rtb_Rem_k = sqrtf(rtb_Saturation_n);

        /* Gain: '<S387>/Gain' incorporates:
         *  Math: '<S387>/Square'
         */
        rtb_Saturation_n = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S425>/Subtract' incorporates:
         *  Product: '<S425>/Multiply'
         *  Product: '<S425>/Multiply1'
         */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 * rtb_MathFunction_h_idx_0 -
          rtb_P_d_idx_0 * rtb_Saturation1_ln[0];

        /* Signum: '<S420>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S420>/Sign1' */

        /* Switch: '<S420>/Switch2' incorporates:
         *  Constant: '<S420>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S420>/Switch2' */

        /* DotProduct: '<S420>/Dot Product' */
        rtb_MathFunction_h_idx_0 = rtb_Saturation1_ln[0] *
          rtb_MathFunction_iq_idx_0 + rtb_MathFunction_h_idx_0 * rtb_P_d_idx_0;

        /* Trigonometry: '<S420>/Acos' incorporates:
         *  DotProduct: '<S420>/Dot Product'
         */
        if (rtb_MathFunction_h_idx_0 > 1.0F) {
          rtb_MathFunction_h_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_h_idx_0 < -1.0F) {
            rtb_MathFunction_h_idx_0 = -1.0F;
          }
        }

        /* Product: '<S420>/Multiply' incorporates:
         *  Trigonometry: '<S420>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_MathFunction_h_idx_0);

        /* Saturate: '<S387>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S387>/Saturation' */

        /* Product: '<S387>/Divide' incorporates:
         *  Constant: '<S320>/L1'
         *  Constant: '<S387>/Constant'
         *  MinMax: '<S387>/Max'
         *  MinMax: '<S387>/Min'
         *  Product: '<S387>/Multiply1'
         *  Sqrt: '<S422>/Sqrt'
         *  Sum: '<S422>/Sum of Elements'
         *  Trigonometry: '<S387>/Sin'
         */
        rtb_Saturation_n = arm_sin_f32(rtb_Rem_k) * rtb_Saturation_n / fminf
          (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Divide_l_idx_1 +
             rtb_TmpSignalConversionAtDela_a[0]), 0.5F));

        /* Sum: '<S369>/Sum2' incorporates:
         *  Delay: '<S369>/Delay'
         */
        rtb_a_i -= FMS_DW.Delay_DSTATE_a;

        /* Math: '<S373>/Rem' incorporates:
         *  Constant: '<S373>/Constant1'
         */
        rtb_Rem_o = rt_remf(rtb_a_i, 6.28318548F);

        /* Switch: '<S373>/Switch' incorporates:
         *  Abs: '<S373>/Abs'
         *  Constant: '<S373>/Constant'
         *  Constant: '<S379>/Constant'
         *  Product: '<S373>/Multiply'
         *  RelationalOperator: '<S379>/Compare'
         *  Sum: '<S373>/Add'
         */
        if (fabsf(rtb_Rem_o) > 3.14159274F) {
          /* Signum: '<S373>/Sign' */
          if (rtb_Rem_o < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_o > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_o;
          }

          /* End of Signum: '<S373>/Sign' */
          rtb_Rem_o -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S373>/Switch' */

        /* Sum: '<S369>/Sum' incorporates:
         *  Delay: '<S369>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Rem_o + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S378>/Multiply1' incorporates:
         *  Constant: '<S378>/const1'
         *  DiscreteIntegrator: '<S372>/Integrator'
         */
        rtb_Rem_o = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S378>/Add' incorporates:
         *  DiscreteIntegrator: '<S372>/Integrator1'
         *  Sum: '<S372>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_e - rtb_Divide_l_idx_1) +
          rtb_Rem_o;

        /* Signum: '<S378>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S378>/Sign' */

        /* Sum: '<S378>/Add2' incorporates:
         *  Abs: '<S378>/Abs'
         *  Gain: '<S378>/Gain'
         *  Gain: '<S378>/Gain1'
         *  Product: '<S378>/Multiply2'
         *  Product: '<S378>/Multiply3'
         *  Sqrt: '<S378>/Sqrt'
         *  Sum: '<S378>/Add1'
         *  Sum: '<S378>/Subtract'
         */
        rtb_a_i = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_l) *
                         FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Rem_o;

        /* Sum: '<S378>/Add4' */
        rtb_MathFunction_iq_idx_0 = (rtb_Rem_k - rtb_a_i) + rtb_Rem_o;

        /* Sum: '<S378>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_l;

        /* Sum: '<S378>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_l;

        /* Signum: '<S378>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S378>/Sign1' */

        /* Signum: '<S378>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S378>/Sign2' */

        /* Sum: '<S378>/Add5' incorporates:
         *  Gain: '<S378>/Gain2'
         *  Product: '<S378>/Multiply4'
         *  Sum: '<S378>/Subtract2'
         */
        rtb_a_i += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F *
          rtb_MathFunction_iq_idx_0;

        /* Update for Delay: '<S388>/Delay' */
        FMS_DW.icLoad_o = 0U;

        /* Update for DiscreteIntegrator: '<S429>/Discrete-Time Integrator' incorporates:
         *  Product: '<S388>/Divide1'
         */
        FMS_DW.l1_heading_p += rtb_Saturation_n / rtb_Switch_k * 0.004F;

        /* Update for Delay: '<S368>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Update for Delay: '<S369>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S372>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S372>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S378>/Add6' */
        rtb_Divide_l_idx_1 = rtb_a_i + FMS_ConstB.d_l;

        /* Sum: '<S378>/Subtract3' */
        rtb_Rem_k = rtb_a_i - FMS_ConstB.d_l;

        /* Signum: '<S378>/Sign5' */
        if (rtb_a_i < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_a_i;
        }

        /* End of Signum: '<S378>/Sign5' */

        /* Signum: '<S378>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S378>/Sign3' */

        /* Signum: '<S378>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S378>/Sign4' */

        /* Signum: '<S378>/Sign6' */
        if (rtb_a_i < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_a_i;
        }

        /* End of Signum: '<S378>/Sign6' */

        /* Update for DiscreteIntegrator: '<S372>/Integrator' incorporates:
         *  Constant: '<S378>/const'
         *  Gain: '<S378>/Gain3'
         *  Product: '<S378>/Divide'
         *  Product: '<S378>/Multiply5'
         *  Product: '<S378>/Multiply6'
         *  Sum: '<S378>/Subtract4'
         *  Sum: '<S378>/Subtract5'
         *  Sum: '<S378>/Subtract6'
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

        /* End of Update for DiscreteIntegrator: '<S372>/Integrator' */
        /* End of Outputs for SubSystem: '<S32>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S32>/Hold' incorporates:
           *  ActionPort: '<S318>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S32>/Switch Case' incorporates:
           *  Chart: '<S327>/Motion Status'
           *  Chart: '<S337>/Motion State'
           *  Chart: '<S349>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S32>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S32>/Hold' incorporates:
         *  ActionPort: '<S318>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S327>/Motion Status' incorporates:
         *  Abs: '<S327>/Abs'
         *  Constant: '<S327>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S337>/Motion State' incorporates:
         *  Abs: '<S337>/Abs'
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

        /* End of Chart: '<S337>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S349>/Motion State' incorporates:
         *  Constant: '<S349>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S349>/Square'
         *  Math: '<S349>/Square1'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sqrt: '<S349>/Sqrt'
         *  Sum: '<S349>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S348>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S348>/Hold Control' incorporates:
             *  ActionPort: '<S351>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S348>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S348>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S348>/Hold Control' incorporates:
           *  ActionPort: '<S351>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S348>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S348>/Brake Control' incorporates:
           *  ActionPort: '<S350>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S348>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S348>/Move Control' incorporates:
             *  ActionPort: '<S352>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S348>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S348>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S348>/Move Control' incorporates:
           *  ActionPort: '<S352>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S348>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S348>/Switch Case' */

        /* SwitchCase: '<S326>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S326>/Hold Control' incorporates:
             *  ActionPort: '<S329>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S326>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S326>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S326>/Hold Control' incorporates:
           *  ActionPort: '<S329>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S326>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S326>/Brake Control' incorporates:
           *  ActionPort: '<S328>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S326>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S326>/Move Control' incorporates:
             *  ActionPort: '<S330>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S326>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S326>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S326>/Move Control' incorporates:
           *  ActionPort: '<S330>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S326>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S326>/Switch Case' */

        /* SwitchCase: '<S336>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S336>/Hold Control' incorporates:
             *  ActionPort: '<S339>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S336>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_kq);

            /* End of SystemReset for SubSystem: '<S336>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S336>/Hold Control' incorporates:
           *  ActionPort: '<S339>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                             &FMS_DW.HoldControl_kq);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S336>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S336>/Brake Control' incorporates:
           *  ActionPort: '<S338>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S336>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S336>/Move Control' incorporates:
             *  ActionPort: '<S340>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S336>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S336>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S336>/Move Control' incorporates:
           *  ActionPort: '<S340>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S336>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S336>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S318>/Bus Assignment'
         *  Constant: '<S318>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S318>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S336>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S336>/Saturation' */

        /* Saturate: '<S348>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S348>/Saturation1' */

        /* Saturate: '<S326>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S318>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S326>/Saturation1' */
        /* End of Outputs for SubSystem: '<S32>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S32>/Unknown' incorporates:
         *  ActionPort: '<S322>/Action Port'
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
       *  Math: '<S203>/Square'
       *  Math: '<S205>/Math Function'
       *  Sum: '<S165>/Subtract'
       *  Sum: '<S217>/Sum1'
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
        /* Disable for Resettable SubSystem: '<S138>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S183>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S173>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S138>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S30>/Offboard' incorporates:
         *  ActionPort: '<S139>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Gain: '<S296>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S299>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S300>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S300>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S300>/Multiply1' incorporates:
         *  Product: '<S300>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S300>/Divide' incorporates:
         *  Constant: '<S300>/Constant'
         *  Constant: '<S300>/R'
         *  Sqrt: '<S300>/Sqrt'
         *  Sum: '<S300>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S300>/Product3' incorporates:
         *  Constant: '<S300>/Constant1'
         *  Product: '<S300>/Multiply1'
         *  Sum: '<S300>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S300>/Multiply2' incorporates:
         *  Trigonometry: '<S300>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S299>/Sum' incorporates:
         *  Gain: '<S296>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Abs: '<S304>/Abs' incorporates:
         *  Abs: '<S307>/Abs1'
         *  Switch: '<S304>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S304>/Switch1' incorporates:
         *  Abs: '<S304>/Abs'
         *  Bias: '<S304>/Bias2'
         *  Bias: '<S304>/Bias3'
         *  Constant: '<S301>/Constant'
         *  Constant: '<S301>/Constant1'
         *  Constant: '<S306>/Constant'
         *  Gain: '<S304>/Gain1'
         *  Product: '<S304>/Multiply'
         *  RelationalOperator: '<S306>/Compare'
         *  Switch: '<S301>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S307>/Switch1' incorporates:
           *  Bias: '<S307>/Bias2'
           *  Bias: '<S307>/Bias3'
           *  Constant: '<S307>/Constant'
           *  Constant: '<S308>/Constant'
           *  Math: '<S307>/Math Function'
           *  RelationalOperator: '<S308>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S307>/Switch1' */

          /* Signum: '<S304>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S304>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          i = 180;
        } else {
          i = 0;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S301>/Sum' incorporates:
         *  Gain: '<S296>/Gain1'
         *  Gain: '<S296>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S299>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)i;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Product: '<S299>/Multiply' incorporates:
         *  Gain: '<S299>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S303>/Switch1' incorporates:
         *  Abs: '<S303>/Abs1'
         *  Bias: '<S303>/Bias2'
         *  Bias: '<S303>/Bias3'
         *  Constant: '<S303>/Constant'
         *  Constant: '<S305>/Constant'
         *  Math: '<S303>/Math Function'
         *  RelationalOperator: '<S305>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S303>/Switch1' */

        /* Product: '<S299>/Multiply' incorporates:
         *  Gain: '<S299>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MultiPortSwitch: '<S277>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S281>/Multiply1'
         *  Product: '<S282>/Multiply3'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
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

          /* SignalConversion: '<S290>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];

          /* Saturate: '<S281>/Saturation' incorporates:
           *  Constant: '<S287>/Constant'
           *  Constant: '<S288>/Constant'
           *  Constant: '<S298>/Constant'
           *  DataTypeConversion: '<S296>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S280>/Logical Operator'
           *  Product: '<S281>/Multiply'
           *  Product: '<S302>/Multiply1'
           *  Product: '<S302>/Multiply2'
           *  RelationalOperator: '<S287>/Compare'
           *  RelationalOperator: '<S288>/Compare'
           *  RelationalOperator: '<S298>/Compare'
           *  S-Function (sfix_bitop): '<S280>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S295>/lat_cmd valid'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S281>/Sum1'
           *  Sum: '<S302>/Sum2'
           *  Switch: '<S283>/Switch'
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

          /* SignalConversion: '<S290>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];

          /* Saturate: '<S281>/Saturation' incorporates:
           *  Constant: '<S287>/Constant'
           *  Constant: '<S288>/Constant'
           *  Constant: '<S298>/Constant'
           *  DataTypeConversion: '<S296>/Data Type Conversion1'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S280>/Logical Operator'
           *  Product: '<S281>/Multiply'
           *  Product: '<S302>/Multiply3'
           *  Product: '<S302>/Multiply4'
           *  RelationalOperator: '<S287>/Compare'
           *  RelationalOperator: '<S288>/Compare'
           *  RelationalOperator: '<S298>/Compare'
           *  S-Function (sfix_bitop): '<S280>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S295>/lon_cmd valid'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S281>/Sum1'
           *  Sum: '<S302>/Sum3'
           *  Switch: '<S283>/Switch'
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

          /* SignalConversion: '<S290>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

          /* Saturate: '<S281>/Saturation' incorporates:
           *  Constant: '<S287>/Constant'
           *  Constant: '<S288>/Constant'
           *  Constant: '<S298>/Constant'
           *  DataTypeConversion: '<S296>/Data Type Conversion'
           *  DataTypeConversion: '<S296>/Data Type Conversion1'
           *  Gain: '<S284>/Gain'
           *  Gain: '<S296>/Gain2'
           *  Gain: '<S299>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S280>/Logical Operator'
           *  Product: '<S281>/Multiply'
           *  RelationalOperator: '<S287>/Compare'
           *  RelationalOperator: '<S288>/Compare'
           *  RelationalOperator: '<S298>/Compare'
           *  S-Function (sfix_bitop): '<S280>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/z_cmd valid'
           *  S-Function (sfix_bitop): '<S295>/alt_cmd valid'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S281>/Sum1'
           *  Sum: '<S299>/Sum1'
           *  Switch: '<S283>/Switch'
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

          /* SignalConversion: '<S224>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S224>/Constant4'
           *  MultiPortSwitch: '<S214>/Index Vector'
           *  Product: '<S281>/Multiply1'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S224>/Trigonometric Function3' incorporates:
           *  Gain: '<S223>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S214>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S224>/Gain' incorporates:
           *  Gain: '<S223>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S214>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Trigonometry: '<S224>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S224>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S224>/Constant3'
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S224>/Trigonometric Function' incorporates:
           *  Gain: '<S223>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S214>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S224>/Trigonometric Function1' incorporates:
           *  Gain: '<S223>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S214>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S224>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];

          /* Product: '<S214>/Multiply' incorporates:
           *  Constant: '<S222>/Constant'
           *  RelationalOperator: '<S222>/Compare'
           *  S-Function (sfix_bitop): '<S219>/ax_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S224>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];

          /* Product: '<S214>/Multiply' incorporates:
           *  Constant: '<S222>/Constant'
           *  RelationalOperator: '<S222>/Compare'
           *  S-Function (sfix_bitop): '<S219>/ay_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S224>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

          /* Product: '<S214>/Multiply' incorporates:
           *  Constant: '<S222>/Constant'
           *  RelationalOperator: '<S222>/Compare'
           *  S-Function (sfix_bitop): '<S219>/az_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S214>/Index Vector' incorporates:
           *  Product: '<S220>/Multiply'
           */
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_Saturation_n);
          }
          break;

         case 1:
          /* SignalConversion: '<S294>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S294>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S292>/Gain' incorporates:
           *  Gain: '<S225>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  MultiPortSwitch: '<S214>/Index Vector'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S282>/Subtract'
           */
          rtb_Switch_k = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S294>/Trigonometric Function3' incorporates:
           *  Gain: '<S292>/Gain'
           *  Trigonometry: '<S294>/Trigonometric Function1'
           */
          rtb_MathFunction_h_idx_0 = arm_cos_f32(rtb_Switch_k);
          rtb_Transpose[4] = rtb_MathFunction_h_idx_0;

          /* Trigonometry: '<S294>/Trigonometric Function2' incorporates:
           *  Gain: '<S292>/Gain'
           *  Trigonometry: '<S294>/Trigonometric Function'
           */
          rtb_MathFunction_h_idx_1 = arm_sin_f32(rtb_Switch_k);

          /* Gain: '<S294>/Gain' incorporates:
           *  Trigonometry: '<S294>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_h_idx_1;

          /* SignalConversion: '<S294>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S294>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S294>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_h_idx_1;

          /* Trigonometry: '<S294>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_MathFunction_h_idx_0;

          /* SignalConversion: '<S294>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S293>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[6] = FMS_ConstB.VectorConcatenate3_n[0];

          /* SignalConversion: '<S294>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S293>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[7] = FMS_ConstB.VectorConcatenate3_n[1];

          /* SignalConversion: '<S294>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S293>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_bl[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S293>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S293>/Constant4'
           */
          rtb_VectorConcatenate_bl[5] = 0.0F;

          /* Trigonometry: '<S293>/Trigonometric Function3' incorporates:
           *  Gain: '<S291>/Gain'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S293>/Trigonometric Function1'
           */
          rtb_Divide_l_idx_1 = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
          rtb_VectorConcatenate_bl[4] = rtb_Divide_l_idx_1;

          /* Trigonometry: '<S293>/Trigonometric Function2' incorporates:
           *  Gain: '<S291>/Gain'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Trigonometry: '<S293>/Trigonometric Function'
           */
          rtb_Saturation_n = arm_sin_f32(-FMS_B.Cmd_In.offboard_psi_0);

          /* Gain: '<S293>/Gain' incorporates:
           *  Trigonometry: '<S293>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_bl[3] = -rtb_Saturation_n;

          /* SignalConversion: '<S293>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S293>/Constant3'
           */
          rtb_VectorConcatenate_bl[2] = 0.0F;

          /* Trigonometry: '<S293>/Trigonometric Function' */
          rtb_VectorConcatenate_bl[1] = rtb_Saturation_n;

          /* Trigonometry: '<S293>/Trigonometric Function1' */
          rtb_VectorConcatenate_bl[0] = rtb_Divide_l_idx_1;

          /* RelationalOperator: '<S298>/Compare' incorporates:
           *  Constant: '<S298>/Constant'
           *  S-Function (sfix_bitop): '<S295>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S295>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S295>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S296>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S296>/Data Type Conversion'
           *  Gain: '<S296>/Gain2'
           *  Gain: '<S299>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S302>/Multiply1'
           *  Product: '<S302>/Multiply2'
           *  Product: '<S302>/Multiply3'
           *  Product: '<S302>/Multiply4'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S299>/Sum1'
           *  Sum: '<S302>/Sum2'
           *  Sum: '<S302>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S283>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S287>/Compare' incorporates:
           *  Constant: '<S287>/Constant'
           *  S-Function (sfix_bitop): '<S280>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S288>/Compare' incorporates:
           *  Constant: '<S288>/Constant'
           *  S-Function (sfix_bitop): '<S280>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (i = 0; i < 3; i++) {
            /* Sum: '<S282>/Sum2' incorporates:
             *  Product: '<S282>/Multiply2'
             *  Switch: '<S283>/Switch'
             */
            if (tmp[i]) {
              rtb_Saturation_n = rtb_Transpose_0[i];
            } else {
              rtb_Saturation_n = tmp_0[i];
            }

            /* Saturate: '<S282>/Saturation1' incorporates:
             *  Gain: '<S284>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S280>/Logical Operator'
             *  Product: '<S282>/Multiply'
             *  Product: '<S282>/Multiply2'
             *  SignalConversion: '<S24>/Signal Copy1'
             *  Sum: '<S282>/Sum2'
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

            /* End of Saturate: '<S282>/Saturation1' */
          }

          for (i = 0; i < 3; i++) {
            rtb_MatrixConcatenate3[i] = rtb_Transpose[i + 6] * rtb_Switch_ec[2]
              + (rtb_Transpose[i + 3] * rtb_Switch_ec[1] + rtb_Transpose[i] *
                 rtb_Switch_ec[0]);
          }

          /* SignalConversion: '<S226>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S226>/Constant4'
           *  MultiPortSwitch: '<S214>/Index Vector'
           *  Product: '<S282>/Multiply3'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S226>/Trigonometric Function3' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Switch_k);

          /* Gain: '<S226>/Gain' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           *  Trigonometry: '<S226>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Switch_k);

          /* SignalConversion: '<S226>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S226>/Constant3'
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S226>/Trigonometric Function' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Switch_k);

          /* Trigonometry: '<S226>/Trigonometric Function1' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Switch_k);

          /* SignalConversion: '<S226>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S214>/Multiply' incorporates:
           *  Constant: '<S222>/Constant'
           *  RelationalOperator: '<S222>/Compare'
           *  S-Function (sfix_bitop): '<S219>/ax_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S226>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S214>/Multiply' incorporates:
           *  Constant: '<S222>/Constant'
           *  RelationalOperator: '<S222>/Compare'
           *  S-Function (sfix_bitop): '<S219>/ay_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S226>/ConcatBufferAtVector ConcatenateIn3' incorporates:
           *  MultiPortSwitch: '<S214>/Index Vector'
           */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S214>/Multiply' incorporates:
           *  Constant: '<S222>/Constant'
           *  RelationalOperator: '<S222>/Compare'
           *  S-Function (sfix_bitop): '<S219>/az_cmd valid'
           */
          rtb_Rem_k = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;

          /* MultiPortSwitch: '<S214>/Index Vector' incorporates:
           *  Product: '<S221>/Multiply3'
           */
          for (i = 0; i < 3; i++) {
            rtb_Switch_ec[i] = rtb_Transpose[i + 6] * rtb_Rem_k +
              (rtb_Transpose[i + 3] * rtb_a_i + rtb_Transpose[i] *
               rtb_Saturation_n);
          }
          break;

         default:
          /* SignalConversion: '<S286>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_nj[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_nj[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_nj[2];

          /* SignalConversion: '<S286>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S286>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S286>/Trigonometric Function3' incorporates:
           *  Gain: '<S285>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S286>/Gain' incorporates:
           *  Gain: '<S285>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Trigonometry: '<S286>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S286>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S286>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S286>/Trigonometric Function' incorporates:
           *  Gain: '<S285>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S286>/Trigonometric Function1' incorporates:
           *  Gain: '<S285>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S295>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S280>/lat_cmd valid'
           */
          tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S298>/Compare' incorporates:
           *  Constant: '<S298>/Constant'
           *  S-Function (sfix_bitop): '<S295>/lat_cmd valid'
           */
          tmp[0] = (tmp_3 > 0U);

          /* S-Function (sfix_bitop): '<S295>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S280>/lon_cmd valid'
           */
          tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S298>/Compare' incorporates:
           *  Constant: '<S298>/Constant'
           *  S-Function (sfix_bitop): '<S295>/lon_cmd valid'
           */
          tmp[1] = (tmp_4 > 0U);

          /* S-Function (sfix_bitop): '<S295>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S280>/alt_cmd valid'
           */
          tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S298>/Compare' incorporates:
           *  Constant: '<S298>/Constant'
           *  S-Function (sfix_bitop): '<S295>/alt_cmd valid'
           */
          tmp[2] = (tmp_5 > 0U);

          /* DataTypeConversion: '<S296>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S296>/Data Type Conversion'
           *  Gain: '<S296>/Gain2'
           *  Gain: '<S299>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S302>/Multiply1'
           *  Product: '<S302>/Multiply2'
           *  Product: '<S302>/Multiply3'
           *  Product: '<S302>/Multiply4'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S299>/Sum1'
           *  Sum: '<S302>/Sum2'
           *  Sum: '<S302>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S283>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S287>/Compare' incorporates:
           *  Constant: '<S287>/Constant'
           *  S-Function (sfix_bitop): '<S280>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S280>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S288>/Compare' incorporates:
           *  Constant: '<S288>/Constant'
           */
          tmp_2[0] = (tmp_3 > 0U);
          tmp_2[1] = (tmp_4 > 0U);
          tmp_2[2] = (tmp_5 > 0U);

          /* Sum: '<S279>/Sum2' */
          for (i = 0; i < 3; i++) {
            /* Switch: '<S283>/Switch' incorporates:
             *  Product: '<S279>/Multiply2'
             */
            if (tmp[i]) {
              rtb_Saturation_n = rtb_Transpose_0[i];
            } else {
              rtb_Saturation_n = tmp_0[i];
            }

            /* Saturate: '<S279>/Saturation1' incorporates:
             *  Gain: '<S284>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S280>/Logical Operator'
             *  Product: '<S279>/Multiply'
             *  Product: '<S279>/Multiply2'
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

            /* End of Saturate: '<S279>/Saturation1' */
          }

          /* End of Sum: '<S279>/Sum2' */

          /* MultiPortSwitch: '<S214>/Index Vector' incorporates:
           *  Constant: '<S222>/Constant'
           *  Product: '<S214>/Multiply'
           *  RelationalOperator: '<S222>/Compare'
           *  S-Function (sfix_bitop): '<S219>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S219>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S219>/az_cmd valid'
           */
          rtb_Switch_ec[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Switch_ec[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Switch_ec[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          break;
        }

        /* End of MultiPortSwitch: '<S277>/Index Vector' */

        /* Sum: '<S273>/Sum1' incorporates:
         *  Constant: '<S273>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S273>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Switch_k = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Abs: '<S274>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Switch_k);

        /* Switch: '<S274>/Switch' incorporates:
         *  Constant: '<S274>/Constant'
         *  Constant: '<S275>/Constant'
         *  Product: '<S274>/Multiply'
         *  RelationalOperator: '<S275>/Compare'
         *  Sum: '<S274>/Subtract'
         */
        if (rtb_Divide_l_idx_1 > 3.14159274F) {
          /* Signum: '<S274>/Sign' */
          if (rtb_Switch_k < 0.0F) {
            rtb_Switch_k = -1.0F;
          } else {
            if (rtb_Switch_k > 0.0F) {
              rtb_Switch_k = 1.0F;
            }
          }

          /* End of Signum: '<S274>/Sign' */
          rtb_Switch_k *= rtb_Divide_l_idx_1 - 6.28318548F;
        }

        /* End of Switch: '<S274>/Switch' */

        /* Saturate: '<S273>/Saturation' */
        if (rtb_Switch_k > 0.314159274F) {
          rtb_Switch_k = 0.314159274F;
        } else {
          if (rtb_Switch_k < -0.314159274F) {
            rtb_Switch_k = -0.314159274F;
          }
        }

        /* End of Saturate: '<S273>/Saturation' */

        /* Gain: '<S270>/Gain2' */
        rtb_Switch_k *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S216>/Sum' incorporates:
         *  Constant: '<S272>/Constant'
         *  Constant: '<S276>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S270>/Multiply2'
         *  Product: '<S271>/Multiply1'
         *  RelationalOperator: '<S272>/Compare'
         *  RelationalOperator: '<S276>/Compare'
         *  S-Function (sfix_bitop): '<S270>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S271>/psi_rate_cmd valid'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                              rtb_Switch_k : 0.0F) + ((FMS_U.Auto_Cmd.cmd_mask &
          64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S277>/Gain1' */
        rtb_Saturation1_ln[0] = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_Saturation1_ln[1] = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S277>/Gain2' */
        rtb_Switch_k = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MultiPortSwitch: '<S278>/Index Vector' incorporates:
         *  Constant: '<S313>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S278>/Multiply'
         *  Product: '<S311>/Multiply'
         *  Product: '<S312>/Multiply3'
         *  RelationalOperator: '<S313>/Compare'
         *  S-Function (sfix_bitop): '<S310>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S310>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S310>/w_cmd valid'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* SignalConversion: '<S315>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S315>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Trigonometry: '<S315>/Trigonometric Function3' incorporates:
           *  Gain: '<S314>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S315>/Gain' incorporates:
           *  Gain: '<S314>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Trigonometry: '<S315>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S315>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S315>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S315>/Trigonometric Function' incorporates:
           *  Gain: '<S314>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S315>/Trigonometric Function1' incorporates:
           *  Gain: '<S314>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           */
          rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S315>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];

          /* Product: '<S278>/Multiply' incorporates:
           *  Constant: '<S313>/Constant'
           *  RelationalOperator: '<S313>/Compare'
           *  S-Function (sfix_bitop): '<S310>/u_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S315>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];

          /* Product: '<S278>/Multiply' incorporates:
           *  Constant: '<S313>/Constant'
           *  RelationalOperator: '<S313>/Compare'
           *  S-Function (sfix_bitop): '<S310>/v_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S315>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

          /* Product: '<S278>/Multiply' incorporates:
           *  Constant: '<S313>/Constant'
           *  RelationalOperator: '<S313>/Compare'
           *  S-Function (sfix_bitop): '<S310>/w_cmd valid'
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
          /* SignalConversion: '<S317>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S317>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S316>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S312>/Subtract'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

          /* Trigonometry: '<S317>/Trigonometric Function3' incorporates:
           *  Gain: '<S316>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S317>/Gain' incorporates:
           *  Gain: '<S316>/Gain'
           *  Trigonometry: '<S317>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S317>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S317>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S317>/Trigonometric Function' incorporates:
           *  Gain: '<S316>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S317>/Trigonometric Function1' incorporates:
           *  Gain: '<S316>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* SignalConversion: '<S317>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S278>/Multiply' incorporates:
           *  Constant: '<S313>/Constant'
           *  RelationalOperator: '<S313>/Compare'
           *  S-Function (sfix_bitop): '<S310>/u_cmd valid'
           */
          rtb_Saturation_n = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S317>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S278>/Multiply' incorporates:
           *  Constant: '<S313>/Constant'
           *  RelationalOperator: '<S313>/Compare'
           *  S-Function (sfix_bitop): '<S310>/v_cmd valid'
           */
          rtb_a_i = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S317>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S278>/Multiply' incorporates:
           *  Constant: '<S313>/Constant'
           *  RelationalOperator: '<S313>/Compare'
           *  S-Function (sfix_bitop): '<S310>/w_cmd valid'
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

        /* End of MultiPortSwitch: '<S278>/Index Vector' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Saturation1_ln[0];
        rtb_MatrixConcatenate3[1] += rtb_Saturation1_ln[1];

        /* Sum: '<S217>/Sum1' */
        rtb_Saturation_n = rtb_Switch_k + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S234>/Switch' incorporates:
         *  Constant: '<S249>/Constant'
         *  Constant: '<S250>/Constant'
         *  Constant: '<S251>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S249>/Compare'
         *  RelationalOperator: '<S250>/Compare'
         *  RelationalOperator: '<S251>/Compare'
         *  S-Function (sfix_bitop): '<S234>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S234>/y_v_cmd'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S234>/Logical Operator' incorporates:
           *  Constant: '<S250>/Constant'
           *  Constant: '<S251>/Constant'
           *  RelationalOperator: '<S250>/Compare'
           *  RelationalOperator: '<S251>/Compare'
           *  S-Function (sfix_bitop): '<S234>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S234>/y_v_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
          rtb_Switch_p_idx_1 = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
          rtb_Switch_p_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U);
        }

        /* End of Switch: '<S234>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S215>/u_cmd_valid' */
        /* MATLAB Function: '<S246>/bit_shift' incorporates:
         *  DataTypeConversion: '<S215>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_e << 6);

        /* End of Outputs for SubSystem: '<S215>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S215>/v_cmd_valid' */
        /* MATLAB Function: '<S247>/bit_shift' incorporates:
         *  DataTypeConversion: '<S215>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_Switch_p_idx_1 << 7);

        /* End of Outputs for SubSystem: '<S215>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Switch: '<S235>/Switch' incorporates:
         *  Constant: '<S253>/Constant'
         *  Constant: '<S254>/Constant'
         *  Constant: '<S256>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S253>/Compare'
         *  RelationalOperator: '<S254>/Compare'
         *  RelationalOperator: '<S256>/Compare'
         *  S-Function (sfix_bitop): '<S235>/ax_cmd'
         *  S-Function (sfix_bitop): '<S235>/ay_cmd'
         *  SignalConversion: '<S24>/Signal Copy'
         */
        if (FMS_U.Auto_Cmd.frame < 2) {
          /* Logic: '<S235>/Logical Operator' incorporates:
           *  Constant: '<S254>/Constant'
           *  Constant: '<S256>/Constant'
           *  RelationalOperator: '<S254>/Compare'
           *  RelationalOperator: '<S256>/Compare'
           *  S-Function (sfix_bitop): '<S235>/ax_cmd'
           *  S-Function (sfix_bitop): '<S235>/ay_cmd'
           */
          rtb_LogicalOperator_e = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_Switch_p_idx_1 = rtb_LogicalOperator_e;
        } else {
          rtb_LogicalOperator_e = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_Switch_p_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
        }

        /* End of Switch: '<S235>/Switch' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S139>/Bus Assignment'
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S139>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S139>/Bus Assignment' incorporates:
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

        /* Saturate: '<S216>/Saturation' */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Divide_l_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_l_idx_1;
        }

        /* End of Saturate: '<S216>/Saturation' */

        /* Saturate: '<S217>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S217>/Saturation2' */

        /* Saturate: '<S217>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S217>/Saturation1' */

        /* Saturate: '<S217>/Saturation3' */
        if (rtb_Saturation_n > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_n < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S139>/Bus Assignment' incorporates:
           *  BusAssignment: '<S26>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_n;
        }

        /* End of Saturate: '<S217>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S215>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S215>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S215>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S215>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S215>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S215>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S215>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S215>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S215>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S215>/throttle_cmd_valid' */
        /* BusAssignment: '<S139>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S227>/Constant'
         *  Constant: '<S228>/Constant'
         *  Constant: '<S229>/Constant'
         *  Constant: '<S230>/Constant'
         *  Constant: '<S231>/Constant'
         *  Constant: '<S232>/Constant'
         *  Constant: '<S233>/Constant'
         *  Constant: '<S252>/Constant'
         *  Constant: '<S255>/Constant'
         *  DataTypeConversion: '<S215>/Data Type Conversion10'
         *  DataTypeConversion: '<S215>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S236>/bit_shift'
         *  MATLAB Function: '<S237>/bit_shift'
         *  MATLAB Function: '<S238>/bit_shift'
         *  MATLAB Function: '<S240>/bit_shift'
         *  MATLAB Function: '<S241>/bit_shift'
         *  MATLAB Function: '<S242>/bit_shift'
         *  MATLAB Function: '<S243>/bit_shift'
         *  MATLAB Function: '<S244>/bit_shift'
         *  MATLAB Function: '<S245>/bit_shift'
         *  MATLAB Function: '<S248>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S227>/Compare'
         *  RelationalOperator: '<S228>/Compare'
         *  RelationalOperator: '<S229>/Compare'
         *  RelationalOperator: '<S230>/Compare'
         *  RelationalOperator: '<S231>/Compare'
         *  RelationalOperator: '<S232>/Compare'
         *  RelationalOperator: '<S233>/Compare'
         *  RelationalOperator: '<S252>/Compare'
         *  RelationalOperator: '<S255>/Compare'
         *  S-Function (sfix_bitop): '<S215>/p_cmd'
         *  S-Function (sfix_bitop): '<S215>/phi_cmd'
         *  S-Function (sfix_bitop): '<S215>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S215>/q_cmd'
         *  S-Function (sfix_bitop): '<S215>/r_cmd'
         *  S-Function (sfix_bitop): '<S215>/theta_cmd'
         *  S-Function (sfix_bitop): '<S215>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S234>/z_w_cmd'
         *  S-Function (sfix_bitop): '<S235>/az_cmd'
         *  SignalConversion: '<S24>/Signal Copy'
         *  Sum: '<S215>/Add'
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

        /* End of Outputs for SubSystem: '<S215>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S215>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S215>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S215>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S215>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S215>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S215>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S215>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S215>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S215>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S30>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S30>/Mission' incorporates:
           *  ActionPort: '<S138>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S30>/Switch Case' incorporates:
           *  UnitDelay: '<S141>/Delay Input1'
           *
           * Block description for '<S141>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S30>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S30>/Mission' incorporates:
           *  ActionPort: '<S138>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S138>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S30>/Switch Case' incorporates:
           *  Chart: '<S174>/Motion Status'
           *  Chart: '<S184>/Motion State'
           *  Delay: '<S146>/Delay'
           *  Delay: '<S166>/Delay'
           *  DiscreteIntegrator: '<S149>/Integrator'
           *  DiscreteIntegrator: '<S149>/Integrator1'
           *  DiscreteIntegrator: '<S210>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_k = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_i = 0.0F;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);

          /* End of SystemReset for SubSystem: '<S138>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S30>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S30>/Mission' incorporates:
         *  ActionPort: '<S138>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* RelationalOperator: '<S141>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S141>/Delay Input1'
         *
         * Block description for '<S141>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Switch_p_idx_1 = (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S138>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S142>/Reset'
         */
        if (rtb_Switch_p_idx_1 && (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE !=
             POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S183>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S173>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for Delay: '<S166>/Delay' */
          FMS_DW.icLoad = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S210>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;

          /* InitializeConditions for Delay: '<S146>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S184>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S174>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_Switch_p_idx_1;

        /* Delay: '<S166>/Delay' incorporates:
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
        /* Sum: '<S162>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_iq_idx_0 = FMS_U.INS_Out.x_R -
          FMS_B.Cmd_In.sp_waypoint[0];
        rtb_Divide_l_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sqrt: '<S170>/Sqrt' incorporates:
         *  Math: '<S170>/Square'
         *  Sum: '<S162>/Sum'
         *  Sum: '<S170>/Sum of Elements'
         */
        rtb_Divide_l_idx_1 = sqrtf(rtb_MathFunction_iq_idx_0 *
          rtb_MathFunction_iq_idx_0 + rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1);

        /* Switch: '<S162>/Switch' incorporates:
         *  Constant: '<S162>/vel'
         */
        if (rtb_Divide_l_idx_1 > FMS_PARAM.L1) {
          rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S162>/Gain' */
          rtb_Switch_k = 0.5F * rtb_Divide_l_idx_1;

          /* Saturate: '<S162>/Saturation' */
          if (rtb_Switch_k > FMS_PARAM.CRUISE_SPEED) {
            rtb_Switch_k = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Switch_k < 0.5F) {
              rtb_Switch_k = 0.5F;
            }
          }

          /* End of Saturate: '<S162>/Saturation' */
        }

        /* End of Switch: '<S162>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S184>/Motion State' incorporates:
         *  Constant: '<S184>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S184>/Square'
         *  Math: '<S184>/Square1'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sqrt: '<S184>/Sqrt'
         *  Sum: '<S184>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_a,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S183>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S183>/Hold Control' incorporates:
             *  ActionPort: '<S186>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S183>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S183>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S183>/Hold Control' incorporates:
           *  ActionPort: '<S186>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S183>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S183>/Brake Control' incorporates:
           *  ActionPort: '<S185>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S183>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S183>/Move Control' incorporates:
             *  ActionPort: '<S187>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S183>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S183>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S183>/Move Control' incorporates:
           *  ActionPort: '<S187>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S183>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S183>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S174>/Motion Status' incorporates:
         *  Abs: '<S174>/Abs'
         *  Constant: '<S174>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S173>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S173>/Hold Control' incorporates:
             *  ActionPort: '<S176>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S173>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S173>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S173>/Hold Control' incorporates:
           *  ActionPort: '<S176>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S173>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S173>/Brake Control' incorporates:
           *  ActionPort: '<S175>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S173>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S173>/Move Control' incorporates:
             *  ActionPort: '<S177>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S173>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S173>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S173>/Move Control' incorporates:
           *  ActionPort: '<S177>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S173>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S173>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S142>/Sum' incorporates:
         *  MATLAB Function: '<S164>/OutRegionRegWP'
         *  MATLAB Function: '<S164>/SearchL1RefWP'
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S167>/Sum1'
         *  Switch: '<S144>/Switch'
         */
        rtb_P_d_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
          [0];
        rtb_MathFunction_iq_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S160>/Sum of Elements' incorporates:
         *  Math: '<S160>/Math Function'
         *  Sum: '<S142>/Sum'
         */
        rtb_Saturation_n = rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0
          + rtb_P_d_idx_0 * rtb_P_d_idx_0;

        /* Math: '<S160>/Math Function1' incorporates:
         *  Sum: '<S160>/Sum of Elements'
         *
         * About '<S160>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_a_i = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_a_i = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S160>/Math Function1' */

        /* Switch: '<S160>/Switch' incorporates:
         *  Constant: '<S160>/Constant'
         *  Product: '<S160>/Product'
         *  Sum: '<S142>/Sum'
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

        /* End of Switch: '<S160>/Switch' */

        /* Product: '<S160>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_TmpSignalConversionAtDela_a[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S158>/Subtract' incorporates:
         *  Product: '<S158>/Multiply'
         *  Product: '<S158>/Multiply1'
         */
        rtb_a_i = rtb_TmpSignalConversionAtDela_a[0] * FMS_ConstB.Divide[1] -
          rtb_TmpSignalConversionAtDela_a[1] * FMS_ConstB.Divide[0];

        /* Signum: '<S147>/Sign1' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S147>/Sign1' */

        /* Switch: '<S147>/Switch2' incorporates:
         *  Constant: '<S147>/Constant4'
         */
        if (rtb_a_i == 0.0F) {
          rtb_a_i = 1.0F;
        }

        /* End of Switch: '<S147>/Switch2' */

        /* DotProduct: '<S147>/Dot Product' */
        rtb_Divide_l_idx_1 = FMS_ConstB.Divide[0] *
          rtb_TmpSignalConversionAtDela_a[0] + FMS_ConstB.Divide[1] *
          rtb_TmpSignalConversionAtDela_a[1];

        /* Trigonometry: '<S147>/Acos' incorporates:
         *  DotProduct: '<S147>/Dot Product'
         */
        if (rtb_Divide_l_idx_1 > 1.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          if (rtb_Divide_l_idx_1 < -1.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          }
        }

        /* Product: '<S147>/Multiply' incorporates:
         *  Trigonometry: '<S147>/Acos'
         */
        rtb_a_i *= acosf(rtb_Divide_l_idx_1);

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S151>/Rem' incorporates:
         *  Constant: '<S151>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S146>/Sum1'
         */
        rtb_Divide_l_idx_1 = rt_remf(rtb_a_i - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S151>/Switch' incorporates:
         *  Abs: '<S151>/Abs'
         *  Constant: '<S151>/Constant'
         *  Constant: '<S157>/Constant'
         *  Product: '<S151>/Multiply'
         *  RelationalOperator: '<S157>/Compare'
         *  Sum: '<S151>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_1) > 3.14159274F) {
          /* Signum: '<S151>/Sign' */
          if (rtb_Divide_l_idx_1 < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Divide_l_idx_1;
          }

          /* End of Signum: '<S151>/Sign' */
          rtb_Divide_l_idx_1 -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S151>/Switch' */

        /* Abs: '<S144>/Abs' */
        rtb_Divide_l_idx_1 = fabsf(rtb_Divide_l_idx_1);

        /* Switch: '<S144>/Switch' incorporates:
         *  Product: '<S166>/Multiply'
         *  Sum: '<S166>/Sum'
         */
        if (rtb_Divide_l_idx_1 > 0.34906584F) {
          /* Saturate: '<S183>/Saturation1' */
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

          /* End of Saturate: '<S183>/Saturation1' */

          /* Saturate: '<S173>/Saturation1' */
          if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = FMS_B.Merge_e;
          }

          /* End of Saturate: '<S173>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S166>/Sum' incorporates:
           *  Delay: '<S166>/Delay'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.Delay_DSTATE[0];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S211>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_ec[0] = rtb_Divide_l_idx_1;
          rtb_Rem_k = rtb_Divide_l_idx_1;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S166>/Sum' incorporates:
           *  Delay: '<S166>/Delay'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_l_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.Delay_DSTATE[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* SignalConversion: '<S213>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S213>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S212>/Gain' incorporates:
           *  DiscreteIntegrator: '<S210>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  Sum: '<S210>/Add'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Trigonometry: '<S213>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S213>/Gain' incorporates:
           *  Trigonometry: '<S213>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S213>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S213>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S213>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S213>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* SignalConversion: '<S213>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Sum: '<S211>/Sum of Elements' incorporates:
           *  Math: '<S211>/Math Function'
           */
          rtb_Saturation_n = rtb_Switch_ec[0] * rtb_Switch_ec[0] +
            rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

          /* Math: '<S211>/Math Function1' incorporates:
           *  Sum: '<S211>/Sum of Elements'
           *
           * About '<S211>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -sqrtf(fabsf(rtb_Saturation_n));
          } else {
            rtb_Saturation_n = sqrtf(rtb_Saturation_n);
          }

          /* End of Math: '<S211>/Math Function1' */

          /* Switch: '<S211>/Switch' incorporates:
           *  Constant: '<S211>/Constant'
           *  Product: '<S211>/Product'
           */
          if (rtb_Saturation_n <= 0.0F) {
            rtb_Rem_k = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_Saturation_n = 1.0F;
          }

          /* End of Switch: '<S211>/Switch' */

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Sum: '<S167>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_h_idx_0 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_1 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

          /* Product: '<S167>/Divide' incorporates:
           *  Math: '<S168>/Square'
           *  Math: '<S169>/Square'
           *  Sqrt: '<S168>/Sqrt'
           *  Sqrt: '<S169>/Sqrt'
           *  Sum: '<S167>/Sum'
           *  Sum: '<S168>/Sum of Elements'
           *  Sum: '<S169>/Sum of Elements'
           */
          rtb_MathFunction_h_idx_0 = sqrtf(rtb_MathFunction_h_idx_0 *
            rtb_MathFunction_h_idx_0 + rtb_MathFunction_h_idx_1 *
            rtb_MathFunction_h_idx_1) / sqrtf(rtb_P_d_idx_0 * rtb_P_d_idx_0 +
            rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0);

          /* Saturate: '<S167>/Saturation' */
          if (rtb_MathFunction_h_idx_0 > 1.0F) {
            rtb_MathFunction_h_idx_0 = 1.0F;
          } else {
            if (rtb_MathFunction_h_idx_0 < 0.0F) {
              rtb_MathFunction_h_idx_0 = 0.0F;
            }
          }

          /* End of Saturate: '<S167>/Saturation' */

          /* Product: '<S209>/Multiply2' incorporates:
           *  Product: '<S211>/Divide'
           */
          rtb_Rem_k = rtb_Rem_k / rtb_Saturation_n * rtb_Switch_k;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_Saturation_n *
            rtb_Switch_k;

          /* Product: '<S166>/Multiply' */
          for (i = 0; i < 3; i++) {
            rtb_Transpose_0[i] = rtb_Transpose[i + 3] * rtb_Divide_l_idx_1 +
              rtb_Transpose[i] * rtb_Rem_k;
          }

          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          /* Gain: '<S161>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S167>/Multiply'
           *  SignalConversion: '<S24>/Signal Copy1'
           *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S161>/Sum2'
           *  Sum: '<S167>/Add'
           *  Sum: '<S167>/Subtract'
           */
          rtb_Divide_l_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_MathFunction_h_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          rtb_Switch_ec[0] = rtb_Transpose_0[0];
          rtb_Switch_ec[1] = rtb_Transpose_0[1];

          /* Saturate: '<S161>/Saturation1' incorporates:
           *  Product: '<S166>/Multiply'
           */
          if (rtb_Divide_l_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_l_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_ec[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_ec[2] = rtb_Divide_l_idx_1;
          }

          /* End of Saturate: '<S161>/Saturation1' */
        }

        /* Delay: '<S146>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S149>/Integrator1' incorporates:
         *  Delay: '<S146>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Math: '<S153>/Rem' incorporates:
         *  Constant: '<S153>/Constant1'
         *  DiscreteIntegrator: '<S149>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S148>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE_p - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Switch: '<S153>/Switch' incorporates:
         *  Abs: '<S153>/Abs'
         *  Constant: '<S153>/Constant'
         *  Constant: '<S154>/Constant'
         *  Product: '<S153>/Multiply'
         *  RelationalOperator: '<S154>/Compare'
         *  Sum: '<S153>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S153>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Rem_k;
          }

          /* End of Signum: '<S153>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S153>/Switch' */

        /* Gain: '<S148>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S148>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S148>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S142>/Bus Assignment'
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S142>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S142>/Bus Assignment' incorporates:
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
        /* Math: '<S204>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_TmpSignalConversionAtDela_a[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_TmpSignalConversionAtDela_a[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S204>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S204>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_Saturation_n = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S204>/Math Function1' incorporates:
         *  Sum: '<S204>/Sum of Elements'
         *
         * About '<S204>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          rtb_Rem_k = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S204>/Math Function1' */

        /* Switch: '<S204>/Switch' incorporates:
         *  Constant: '<S204>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S204>/Product'
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

        /* End of Switch: '<S204>/Switch' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* MATLAB Function: '<S164>/NearbyRefWP' incorporates:
         *  Constant: '<S142>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                        rtb_TmpSignalConversionAtDela_a, &rtb_Saturation_n);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* MATLAB Function: '<S164>/SearchL1RefWP' incorporates:
         *  Constant: '<S142>/L1'
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
        /* MATLAB Function: '<S164>/OutRegionRegWP' incorporates:
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

        /* Switch: '<S164>/Switch1' incorporates:
         *  Constant: '<S197>/Constant'
         *  RelationalOperator: '<S197>/Compare'
         */
        if (rtb_Saturation_n <= 0.0F) {
          /* Switch: '<S164>/Switch' incorporates:
           *  Constant: '<S196>/Constant'
           *  MATLAB Function: '<S164>/SearchL1RefWP'
           *  RelationalOperator: '<S196>/Compare'
           */
          if (rtb_Divide_l_idx_1 >= 0.0F) {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_h_idx_0;
            rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_h_idx_1;
          } else {
            rtb_TmpSignalConversionAtDela_a[0] = rtb_P_d_idx_0;

            /* MATLAB Function: '<S164>/OutRegionRegWP' incorporates:
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

          /* End of Switch: '<S164>/Switch' */
        }

        /* End of Switch: '<S164>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sum: '<S165>/Subtract' incorporates:
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
        /* Sum: '<S165>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S205>/Math Function'
         *  SignalConversion: '<S24>/Signal Copy1'
         */
        rtb_MathFunction_h_idx_0 = rtb_TmpSignalConversionAtDela_a[1] -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Math: '<S205>/Math Function' incorporates:
         *  Math: '<S203>/Square'
         */
        rtb_Saturation_n = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Sum: '<S205>/Sum of Elements' incorporates:
         *  Math: '<S205>/Math Function'
         */
        rtb_Divide_l_idx_1 = rtb_Saturation_n + rtb_TmpSignalConversionAtDela_a
          [0];

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
          rtb_MatrixConcatenate3[0] = rtb_Saturation1_ln[0];
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_h_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Rem_k;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S205>/Switch' */

        /* Product: '<S204>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_P_d_idx_0 = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Sum: '<S207>/Sum of Elements' incorporates:
         *  Math: '<S207>/Math Function'
         *  SignalConversion: '<S207>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0;

        /* Math: '<S207>/Math Function1' incorporates:
         *  Sum: '<S207>/Sum of Elements'
         *
         * About '<S207>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S207>/Math Function1' */

        /* Switch: '<S207>/Switch' incorporates:
         *  Constant: '<S207>/Constant'
         *  Product: '<S207>/Product'
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

        /* End of Switch: '<S207>/Switch' */

        /* Product: '<S205>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S208>/Sum of Elements' incorporates:
         *  Math: '<S208>/Math Function'
         *  SignalConversion: '<S208>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_1 = rtb_P_d_idx_0 * rtb_P_d_idx_0 +
          rtb_MathFunction_iq_idx_0 * rtb_MathFunction_iq_idx_0;

        /* Math: '<S208>/Math Function1' incorporates:
         *  Sum: '<S208>/Sum of Elements'
         *
         * About '<S208>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Divide_l_idx_1));
        } else {
          rtb_Rem_k = sqrtf(rtb_Divide_l_idx_1);
        }

        /* End of Math: '<S208>/Math Function1' */

        /* Switch: '<S208>/Switch' incorporates:
         *  Constant: '<S208>/Constant'
         *  Product: '<S208>/Product'
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

        /* End of Switch: '<S208>/Switch' */

        /* Product: '<S208>/Divide' */
        rtb_MathFunction_iq_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S207>/Divide' */
        rtb_TmpSignalConversionAtDela_a[0] = rtb_Switch_ec[0] / rtb_Switch_ec[2];
        rtb_Saturation1_ln[0] *= rtb_Saturation1_ln[0];

        /* Product: '<S208>/Divide' incorporates:
         *  Math: '<S203>/Square'
         */
        rtb_P_d_idx_0 = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S207>/Divide' */
        rtb_TmpSignalConversionAtDela_a[1] = rtb_Switch_ec[1] / rtb_Switch_ec[2];

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Sqrt: '<S202>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S202>/Square'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sum: '<S202>/Sum of Elements'
         */
        rtb_Rem_k = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve
                          * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Gain: '<S165>/Gain' incorporates:
         *  Math: '<S165>/Square'
         */
        rtb_Divide_l_idx_1 = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S206>/Subtract' incorporates:
         *  Product: '<S206>/Multiply'
         *  Product: '<S206>/Multiply1'
         */
        rtb_Rem_k = rtb_MathFunction_iq_idx_0 * rtb_TmpSignalConversionAtDela_a
          [1] - rtb_P_d_idx_0 * rtb_TmpSignalConversionAtDela_a[0];

        /* Signum: '<S201>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S201>/Sign1' */

        /* Switch: '<S201>/Switch2' incorporates:
         *  Constant: '<S201>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S201>/Switch2' */

        /* DotProduct: '<S201>/Dot Product' */
        rtb_MathFunction_iq_idx_0 = rtb_TmpSignalConversionAtDela_a[0] *
          rtb_MathFunction_iq_idx_0 + rtb_TmpSignalConversionAtDela_a[1] *
          rtb_P_d_idx_0;

        /* Trigonometry: '<S201>/Acos' incorporates:
         *  DotProduct: '<S201>/Dot Product'
         */
        if (rtb_MathFunction_iq_idx_0 > 1.0F) {
          rtb_MathFunction_iq_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_iq_idx_0 < -1.0F) {
            rtb_MathFunction_iq_idx_0 = -1.0F;
          }
        }

        /* Product: '<S201>/Multiply' incorporates:
         *  Trigonometry: '<S201>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_MathFunction_iq_idx_0);

        /* Saturate: '<S165>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S165>/Saturation' */

        /* Product: '<S165>/Divide' incorporates:
         *  Constant: '<S142>/L1'
         *  Constant: '<S165>/Constant'
         *  MinMax: '<S165>/Max'
         *  MinMax: '<S165>/Min'
         *  Product: '<S165>/Multiply1'
         *  Sqrt: '<S203>/Sqrt'
         *  Sum: '<S203>/Sum of Elements'
         *  Trigonometry: '<S165>/Sin'
         */
        rtb_MathFunction_iq_idx_0 = arm_sin_f32(rtb_Rem_k) * rtb_Divide_l_idx_1 /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_n + rtb_Saturation1_ln
                  [0]), 0.5F));

        /* Sum: '<S146>/Sum2' incorporates:
         *  Delay: '<S146>/Delay'
         */
        rtb_a_i -= FMS_DW.Delay_DSTATE_h;

        /* Math: '<S150>/Rem' incorporates:
         *  Constant: '<S150>/Constant1'
         */
        rtb_Saturation_n = rt_remf(rtb_a_i, 6.28318548F);

        /* Switch: '<S150>/Switch' incorporates:
         *  Abs: '<S150>/Abs'
         *  Constant: '<S150>/Constant'
         *  Constant: '<S156>/Constant'
         *  Product: '<S150>/Multiply'
         *  RelationalOperator: '<S156>/Compare'
         *  Sum: '<S150>/Add'
         */
        if (fabsf(rtb_Saturation_n) > 3.14159274F) {
          /* Signum: '<S150>/Sign' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Saturation_n > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Saturation_n;
          }

          /* End of Signum: '<S150>/Sign' */
          rtb_Saturation_n -= 6.28318548F * rtb_Divide_l_idx_1;
        }

        /* End of Switch: '<S150>/Switch' */

        /* Sum: '<S146>/Sum' incorporates:
         *  Delay: '<S146>/Delay'
         */
        rtb_Divide_l_idx_1 = rtb_Saturation_n + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S155>/Multiply1' incorporates:
         *  Constant: '<S155>/const1'
         *  DiscreteIntegrator: '<S149>/Integrator'
         */
        rtb_Saturation_n = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S155>/Add' incorporates:
         *  DiscreteIntegrator: '<S149>/Integrator1'
         *  Sum: '<S149>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_p - rtb_Divide_l_idx_1) +
          rtb_Saturation_n;

        /* Signum: '<S155>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S155>/Sign' */

        /* Sum: '<S155>/Add2' incorporates:
         *  Abs: '<S155>/Abs'
         *  Gain: '<S155>/Gain'
         *  Gain: '<S155>/Gain1'
         *  Product: '<S155>/Multiply2'
         *  Product: '<S155>/Multiply3'
         *  Sqrt: '<S155>/Sqrt'
         *  Sum: '<S155>/Add1'
         *  Sum: '<S155>/Subtract'
         */
        rtb_a_i = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_j) *
                         FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_Saturation_n;

        /* Sum: '<S155>/Add4' */
        rtb_Saturation_n += rtb_Rem_k - rtb_a_i;

        /* Sum: '<S155>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_j;

        /* Sum: '<S155>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_j;

        /* Signum: '<S155>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S155>/Sign1' */

        /* Signum: '<S155>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S155>/Sign2' */

        /* Sum: '<S155>/Add5' incorporates:
         *  Gain: '<S155>/Gain2'
         *  Product: '<S155>/Multiply4'
         *  Sum: '<S155>/Subtract2'
         */
        rtb_a_i += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F * rtb_Saturation_n;

        /* Update for Delay: '<S166>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S210>/Discrete-Time Integrator' incorporates:
         *  Product: '<S166>/Divide1'
         */
        FMS_DW.l1_heading += rtb_MathFunction_iq_idx_0 / rtb_Switch_k * 0.004F;

        /* Update for Delay: '<S146>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S149>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S149>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Sum: '<S155>/Add6' */
        rtb_Divide_l_idx_1 = rtb_a_i + FMS_ConstB.d_j;

        /* Sum: '<S155>/Subtract3' */
        rtb_Rem_k = rtb_a_i - FMS_ConstB.d_j;

        /* Signum: '<S155>/Sign5' */
        if (rtb_a_i < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_a_i;
        }

        /* End of Signum: '<S155>/Sign5' */

        /* Signum: '<S155>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S155>/Sign3' */

        /* Signum: '<S155>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S155>/Sign4' */

        /* Signum: '<S155>/Sign6' */
        if (rtb_a_i < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_a_i;
        }

        /* End of Signum: '<S155>/Sign6' */

        /* Update for DiscreteIntegrator: '<S149>/Integrator' incorporates:
         *  Constant: '<S155>/const'
         *  Gain: '<S155>/Gain3'
         *  Product: '<S155>/Divide'
         *  Product: '<S155>/Multiply5'
         *  Product: '<S155>/Multiply6'
         *  Sum: '<S155>/Subtract4'
         *  Sum: '<S155>/Subtract5'
         *  Sum: '<S155>/Subtract6'
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

        /* End of Update for DiscreteIntegrator: '<S149>/Integrator' */
        /* End of Outputs for SubSystem: '<S138>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Update for UnitDelay: '<S141>/Delay Input1' incorporates:
         *  SignalConversion: '<S24>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S141>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S30>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S30>/Unknown' incorporates:
         *  ActionPort: '<S140>/Action Port'
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
          /* Disable for SwitchCase: '<S125>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S44>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S61>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S101>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S77>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S88>/Switch Case' */
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
           *  DiscreteIntegrator: '<S121>/Integrator'
           *  DiscreteIntegrator: '<S121>/Integrator1'
           *  DiscreteIntegrator: '<S122>/Integrator'
           *  DiscreteIntegrator: '<S122>/Integrator1'
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
           *  Chart: '<S126>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S29>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S29>/Stabilize' incorporates:
         *  ActionPort: '<S37>/Action Port'
         */
        /* Product: '<S123>/Multiply1' incorporates:
         *  Constant: '<S123>/const1'
         *  DiscreteIntegrator: '<S121>/Integrator'
         */
        rtb_a_i = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S119>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S119>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S123>/Add' incorporates:
         *  DiscreteIntegrator: '<S121>/Integrator1'
         *  Gain: '<S116>/Gain'
         *  Gain: '<S119>/Gain'
         *  Sum: '<S121>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * rtb_Saturation_n * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_a_i;

        /* Signum: '<S123>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S123>/Sign' */

        /* Sum: '<S123>/Add2' incorporates:
         *  Abs: '<S123>/Abs'
         *  Gain: '<S123>/Gain'
         *  Gain: '<S123>/Gain1'
         *  Product: '<S123>/Multiply2'
         *  Product: '<S123>/Multiply3'
         *  Sqrt: '<S123>/Sqrt'
         *  Sum: '<S123>/Add1'
         *  Sum: '<S123>/Subtract'
         */
        rtb_Switch_k = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d_d) *
                              FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
          rtb_Divide_l_idx_1 + rtb_a_i;

        /* Sum: '<S123>/Add4' */
        rtb_Saturation_n = (rtb_Rem_k - rtb_Switch_k) + rtb_a_i;

        /* Sum: '<S123>/Add3' */
        rtb_Divide_l_idx_1 = rtb_Rem_k + FMS_ConstB.d_d;

        /* Sum: '<S123>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d_d;

        /* Signum: '<S123>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S123>/Sign1' */

        /* Signum: '<S123>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S123>/Sign2' */

        /* Sum: '<S123>/Add5' incorporates:
         *  Gain: '<S123>/Gain2'
         *  Product: '<S123>/Multiply4'
         *  Sum: '<S123>/Subtract2'
         */
        rtb_Switch_k += (rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F *
          rtb_Saturation_n;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Chart: '<S126>/Motion State' incorporates:
         *  Abs: '<S126>/Abs'
         *  Abs: '<S126>/Abs1'
         *  Constant: '<S136>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S136>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_a,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* SwitchCase: '<S125>/Switch Case' incorporates:
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
            /* SystemReset for IfAction SubSystem: '<S125>/Hold Control' incorporates:
             *  ActionPort: '<S128>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S125>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S125>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S125>/Hold Control' incorporates:
           *  ActionPort: '<S128>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                             &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S125>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S125>/Brake Control' incorporates:
           *  ActionPort: '<S127>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S125>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S125>/Move Control' incorporates:
             *  ActionPort: '<S129>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S125>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S125>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S125>/Move Control' incorporates:
           *  ActionPort: '<S129>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S125>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S125>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  BusAssignment: '<S37>/Bus Assignment'
         *  Constant: '<S37>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S37>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  DiscreteIntegrator: '<S121>/Integrator1'
         *  DiscreteIntegrator: '<S122>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_j;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_jt;

        /* Saturate: '<S125>/Saturation' */
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

        /* End of Saturate: '<S125>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* Saturate: '<S118>/Saturation' incorporates:
         *  Constant: '<S118>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy2'
         *  Sum: '<S118>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Saturation_n = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Saturation_n = 0.0F;
        } else {
          rtb_Saturation_n = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S118>/Saturation' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* BusAssignment: '<S37>/Bus Assignment' incorporates:
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S118>/Constant5'
         *  Gain: '<S118>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S118>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Saturation_n), 65536.0F) + 1000U);

        /* Product: '<S124>/Multiply1' incorporates:
         *  Constant: '<S124>/const1'
         *  DiscreteIntegrator: '<S122>/Integrator'
         */
        rtb_Rem_k = FMS_DW.Integrator_DSTATE_cq * 0.04F;

        /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
        /* DeadZone: '<S120>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S120>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Sum: '<S124>/Add' incorporates:
         *  DiscreteIntegrator: '<S122>/Integrator1'
         *  Gain: '<S116>/Gain1'
         *  Gain: '<S120>/Gain'
         *  Sum: '<S122>/Subtract'
         */
        rtb_a_i = (FMS_DW.Integrator1_DSTATE_jt - 1.0F / (1.0F -
                    FMS_PARAM.PITCH_DZ) * rtb_Saturation_n *
                   -FMS_PARAM.ROLL_PITCH_LIM) + rtb_Rem_k;

        /* Signum: '<S124>/Sign' */
        if (rtb_a_i < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_a_i > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_a_i;
        }

        /* End of Signum: '<S124>/Sign' */

        /* Sum: '<S124>/Add2' incorporates:
         *  Abs: '<S124>/Abs'
         *  Gain: '<S124>/Gain'
         *  Gain: '<S124>/Gain1'
         *  Product: '<S124>/Multiply2'
         *  Product: '<S124>/Multiply3'
         *  Sqrt: '<S124>/Sqrt'
         *  Sum: '<S124>/Add1'
         *  Sum: '<S124>/Subtract'
         */
        rtb_Saturation_n = (sqrtf((8.0F * fabsf(rtb_a_i) + FMS_ConstB.d_o) *
          FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F * rtb_Divide_l_idx_1 +
          rtb_Rem_k;

        /* Sum: '<S124>/Add4' */
        rtb_Rem_k += rtb_a_i - rtb_Saturation_n;

        /* Sum: '<S124>/Add3' */
        rtb_Divide_l_idx_1 = rtb_a_i + FMS_ConstB.d_o;

        /* Sum: '<S124>/Subtract1' */
        rtb_a_i -= FMS_ConstB.d_o;

        /* Signum: '<S124>/Sign1' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S124>/Sign1' */

        /* Signum: '<S124>/Sign2' */
        if (rtb_a_i < 0.0F) {
          rtb_a_i = -1.0F;
        } else {
          if (rtb_a_i > 0.0F) {
            rtb_a_i = 1.0F;
          }
        }

        /* End of Signum: '<S124>/Sign2' */

        /* Sum: '<S124>/Add5' incorporates:
         *  Gain: '<S124>/Gain2'
         *  Product: '<S124>/Multiply4'
         *  Sum: '<S124>/Subtract2'
         */
        rtb_Saturation_n += (rtb_Divide_l_idx_1 - rtb_a_i) * 0.5F * rtb_Rem_k;

        /* Update for DiscreteIntegrator: '<S121>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S121>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S123>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Switch_k + FMS_ConstB.d_d;

        /* Sum: '<S123>/Subtract3' */
        rtb_Rem_k = rtb_Switch_k - FMS_ConstB.d_d;

        /* Signum: '<S123>/Sign5' */
        if (rtb_Switch_k < 0.0F) {
          rtb_a_i = -1.0F;
        } else if (rtb_Switch_k > 0.0F) {
          rtb_a_i = 1.0F;
        } else {
          rtb_a_i = rtb_Switch_k;
        }

        /* End of Signum: '<S123>/Sign5' */

        /* Signum: '<S123>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S123>/Sign3' */

        /* Signum: '<S123>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S123>/Sign4' */

        /* Signum: '<S123>/Sign6' */
        if (rtb_Switch_k < 0.0F) {
          rtb_MathFunction_iq_idx_0 = -1.0F;
        } else if (rtb_Switch_k > 0.0F) {
          rtb_MathFunction_iq_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_iq_idx_0 = rtb_Switch_k;
        }

        /* End of Signum: '<S123>/Sign6' */

        /* Update for DiscreteIntegrator: '<S121>/Integrator' incorporates:
         *  Constant: '<S123>/const'
         *  Gain: '<S123>/Gain3'
         *  Product: '<S123>/Divide'
         *  Product: '<S123>/Multiply5'
         *  Product: '<S123>/Multiply6'
         *  Sum: '<S123>/Subtract4'
         *  Sum: '<S123>/Subtract5'
         *  Sum: '<S123>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_Switch_k / FMS_ConstB.d_d - rtb_a_i)
          * FMS_ConstB.Gain4_n * ((rtb_Divide_l_idx_1 - rtb_Rem_k) * 0.5F) -
          rtb_MathFunction_iq_idx_0 * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S122>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S122>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_jt += 0.004F * FMS_DW.Integrator_DSTATE_cq;

        /* Sum: '<S124>/Add6' */
        rtb_Divide_l_idx_1 = rtb_Saturation_n + FMS_ConstB.d_o;

        /* Sum: '<S124>/Subtract3' */
        rtb_Rem_k = rtb_Saturation_n - FMS_ConstB.d_o;

        /* Signum: '<S124>/Sign5' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Switch_k = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_Switch_k = 1.0F;
        } else {
          rtb_Switch_k = rtb_Saturation_n;
        }

        /* End of Signum: '<S124>/Sign5' */

        /* Signum: '<S124>/Sign3' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S124>/Sign3' */

        /* Signum: '<S124>/Sign4' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S124>/Sign4' */

        /* Signum: '<S124>/Sign6' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_a_i = -1.0F;
        } else if (rtb_Saturation_n > 0.0F) {
          rtb_a_i = 1.0F;
        } else {
          rtb_a_i = rtb_Saturation_n;
        }

        /* End of Signum: '<S124>/Sign6' */

        /* Update for DiscreteIntegrator: '<S122>/Integrator' incorporates:
         *  Constant: '<S124>/const'
         *  Gain: '<S124>/Gain3'
         *  Product: '<S124>/Divide'
         *  Product: '<S124>/Multiply5'
         *  Product: '<S124>/Multiply6'
         *  Sum: '<S124>/Subtract4'
         *  Sum: '<S124>/Subtract5'
         *  Sum: '<S124>/Subtract6'
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
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S44>/Move Control' incorporates:
             *  ActionPort: '<S48>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S44>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

            /* End of SystemReset for SubSystem: '<S44>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S44>/Move Control' incorporates:
           *  ActionPort: '<S48>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_l,
                          &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

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
           *  Chart: '<S102>/Motion State'
           *  Chart: '<S78>/Motion Status'
           *  Chart: '<S89>/Motion State'
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
         *  Constant: '<S86>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S86>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_a, &FMS_DW.sf_MotionStatus_i);

        /* Chart: '<S89>/Motion State' incorporates:
         *  Abs: '<S89>/Abs'
         *  Abs: '<S89>/Abs1'
         *  Constant: '<S99>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S99>/Compare'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_ki,
                          &FMS_DW.sf_MotionState_j);

        /* Logic: '<S102>/Logical Operator' incorporates:
         *  Abs: '<S102>/Abs1'
         *  Abs: '<S102>/Abs2'
         *  Constant: '<S113>/Constant'
         *  Constant: '<S114>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S113>/Compare'
         *  RelationalOperator: '<S114>/Compare'
         *  SignalConversion: '<S24>/Signal Copy2'
         */
        rtb_Switch_p_idx_1 = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<S3>/FMS_Input' */

        /* Chart: '<S102>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S102>/Square'
         *  Math: '<S102>/Square1'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  Sqrt: '<S102>/Sqrt'
         *  Sum: '<S102>/Add'
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

        /* End of Chart: '<S102>/Motion State' */

        /* SwitchCase: '<S101>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S101>/Hold Control' incorporates:
             *  ActionPort: '<S104>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S101>/Switch Case' */
            FMS_HoldControl_l_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S101>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S101>/Hold Control' incorporates:
           *  ActionPort: '<S104>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S101>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S101>/Brake Control' incorporates:
           *  ActionPort: '<S103>/Action Port'
           */
          FMS_BrakeControl_f(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S101>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S101>/Move Control' incorporates:
             *  ActionPort: '<S105>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S101>/Switch Case' */
            FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S101>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S101>/Move Control' incorporates:
           *  ActionPort: '<S105>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S101>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S101>/Switch Case' */

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
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S77>/Move Control' incorporates:
             *  ActionPort: '<S81>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S77>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_be);

            /* End of SystemReset for SubSystem: '<S77>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S77>/Move Control' incorporates:
           *  ActionPort: '<S81>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_k,
                          &FMS_ConstB.MoveControl_be, &FMS_DW.MoveControl_be);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S77>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S77>/Switch Case' */

        /* SwitchCase: '<S88>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S24>/Signal Copy1'
         *  SignalConversion: '<S24>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S88>/Hold Control' incorporates:
             *  ActionPort: '<S91>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S88>/Switch Case' */
            FMS_HoldControl_h_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S88>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S88>/Hold Control' incorporates:
           *  ActionPort: '<S91>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_HoldControl_kq(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                             &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S88>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S88>/Brake Control' incorporates:
           *  ActionPort: '<S90>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S88>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S88>/Move Control' incorporates:
             *  ActionPort: '<S92>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S88>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_mr);

            /* End of SystemReset for SubSystem: '<S88>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S88>/Move Control' incorporates:
           *  ActionPort: '<S92>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S3>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_mr, &FMS_DW.MoveControl_mr);

          /* End of Outputs for SubSystem: '<S3>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S88>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S88>/Switch Case' */

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

        /* Saturate: '<S88>/Saturation' */
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

        /* End of Saturate: '<S88>/Saturation' */

        /* Saturate: '<S101>/Saturation1' */
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

        /* End of Saturate: '<S101>/Saturation1' */

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
   *  DiscreteIntegrator: '<S441>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S441>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S441>/Constant'
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

  /* Update for DiscreteIntegrator: '<S456>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S456>/Gain'
   *  Sum: '<S456>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_o[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_o[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_o[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S458>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S458>/Gain'
   *  Sum: '<S458>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_b -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S457>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S457>/Gain'
   *  Sum: '<S457>/Sum5'
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
  /* Start for SwitchCase: '<S402>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S392>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S32>/Return' */

  /* Start for IfAction SubSystem: '<S32>/Hold' */
  /* Start for SwitchCase: '<S348>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S326>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S336>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S32>/Hold' */
  /* End of Start for SubSystem: '<S25>/SubMode' */

  /* Start for IfAction SubSystem: '<S25>/Auto' */
  /* Start for SwitchCase: '<S30>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S30>/Mission' */
  /* Start for Resettable SubSystem: '<S138>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S183>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S173>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S138>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S30>/Mission' */
  /* End of Start for SubSystem: '<S25>/Auto' */

  /* Start for IfAction SubSystem: '<S25>/Assist' */
  /* Start for SwitchCase: '<S29>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S29>/Stabilize' */
  /* Start for SwitchCase: '<S125>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S29>/Stabilize' */

  /* Start for IfAction SubSystem: '<S29>/Altitude' */
  /* Start for SwitchCase: '<S44>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S61>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S29>/Altitude' */

  /* Start for IfAction SubSystem: '<S29>/Position' */
  /* Start for SwitchCase: '<S101>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S77>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S88>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S29>/Position' */
  /* End of Start for SubSystem: '<S25>/Assist' */
  /* End of Start for SubSystem: '<S23>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S456>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S458>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S457>/Discrete-Time Integrator5' */
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
  /* InitializeConditions for Delay: '<S439>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* End of SystemInitialize for SubSystem: '<S32>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S32>/Return' */
  /* InitializeConditions for Delay: '<S388>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S429>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_p = 0.0F;

  /* InitializeConditions for Delay: '<S368>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for Delay: '<S369>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S372>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S372>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S403>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S402>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S402>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S402>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S402>/Move Control' */

  /* SystemInitialize for Merge: '<S402>/Merge' */
  FMS_B.Merge_mv[0] = 0.0F;
  FMS_B.Merge_mv[1] = 0.0F;

  /* SystemInitialize for Chart: '<S393>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S392>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S392>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S392>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S392>/Move Control' */

  /* SystemInitialize for Merge: '<S392>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S32>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S32>/Hold' */
  /* SystemInitialize for Chart: '<S327>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S337>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S349>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S348>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S348>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S348>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S348>/Move Control' */

  /* SystemInitialize for Merge: '<S348>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S326>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S326>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S326>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S326>/Move Control' */

  /* SystemInitialize for Merge: '<S326>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S336>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_kq);

  /* End of SystemInitialize for SubSystem: '<S336>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S336>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S336>/Move Control' */

  /* SystemInitialize for Merge: '<S336>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S32>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S25>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S25>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S30>/Mission' */
  /* InitializeConditions for UnitDelay: '<S141>/Delay Input1'
   *
   * Block description for '<S141>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S138>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S166>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S210>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S146>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S184>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S183>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S183>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S183>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S183>/Move Control' */

  /* SystemInitialize for Merge: '<S183>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S174>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S173>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S173>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S173>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S173>/Move Control' */

  /* SystemInitialize for Merge: '<S173>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S138>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S30>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S25>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S25>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S29>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jt = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Integrator' */
  FMS_DW.Integrator_DSTATE_cq = 0.0F;

  /* SystemInitialize for Chart: '<S126>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S125>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S125>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S125>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S125>/Move Control' */

  /* SystemInitialize for Merge: '<S125>/Merge' */
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

  /* SystemInitialize for IfAction SubSystem: '<S44>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S44>/Move Control' */

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

  /* SystemInitialize for Chart: '<S89>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S102>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S101>/Hold Control' */
  FMS_HoldControl_b_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S101>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S101>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S101>/Move Control' */

  /* SystemInitialize for Merge: '<S101>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S77>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S77>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S77>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_be);

  /* End of SystemInitialize for SubSystem: '<S77>/Move Control' */

  /* SystemInitialize for Merge: '<S77>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S88>/Hold Control' */
  FMS_HoldControl_p_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S88>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S88>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_mr);

  /* End of SystemInitialize for SubSystem: '<S88>/Move Control' */

  /* SystemInitialize for Merge: '<S88>/Merge' */
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
