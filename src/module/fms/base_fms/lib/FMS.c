/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1018
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Dec 21 14:39:40 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S107>/Motion State' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S26>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S131>/Motion Status' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_a                  ((uint8_T)2U)
#define FMS_IN_Move_j                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_p       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude                ((uint8_T)2U)
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Hold_b                  ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)3U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Land                    ((uint8_T)2U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_b                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)5U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_event_DisarmEvent          (0)

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
  0U,                                  /* mode */
  0U,                                  /* ctrl_mode */
  0U                                   /* reset */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_5vUBwe4VfGkNikzOx8lYKF FMS_PARAM = {
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
  0.52359879F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S23>/Gain'
                                        *   '<S23>/Gain1'
                                        *   '<S97>/Gain'
                                        *   '<S97>/Gain1'
                                        *   '<S165>/Saturation1'
                                        *   '<S206>/Gain2'
                                        *   '<S206>/Saturation1'
                                        *   '<S25>/Saturation1'
                                        *   '<S36>/Dead Zone'
                                        *   '<S36>/Gain'
                                        *   '<S37>/Dead Zone'
                                        *   '<S37>/Gain'
                                        *   '<S42>/Saturation'
                                        *   '<S58>/Saturation1'
                                        *   '<S69>/Saturation'
                                        *   '<S82>/Saturation1'
                                        *   '<S100>/Dead Zone'
                                        *   '<S100>/Gain'
                                        *   '<S101>/Dead Zone'
                                        *   '<S101>/Gain'
                                        *   '<S106>/Saturation'
                                        *   '<S130>/Saturation1'
                                        *   '<S140>/Saturation'
                                        *   '<S152>/Saturation1'
                                        *   '<S166>/Gain2'
                                        *   '<S28>/Gain2'
                                        *   '<S29>/Gain1'
                                        *   '<S34>/Constant'
                                        *   '<S45>/Gain2'
                                        *   '<S46>/Gain1'
                                        *   '<S53>/Constant'
                                        *   '<S61>/Gain2'
                                        *   '<S62>/Gain1'
                                        *   '<S67>/Constant'
                                        *   '<S72>/Gain2'
                                        *   '<S73>/Gain1'
                                        *   '<S80>/Constant'
                                        *   '<S85>/Gain2'
                                        *   '<S86>/Gain6'
                                        *   '<S94>/Constant'
                                        *   '<S95>/Constant'
                                        *   '<S109>/Gain2'
                                        *   '<S110>/Gain1'
                                        *   '<S117>/Constant'
                                        *   '<S133>/Gain2'
                                        *   '<S134>/Gain1'
                                        *   '<S143>/Gain2'
                                        *   '<S144>/Gain1'
                                        *   '<S155>/Gain2'
                                        *   '<S156>/Gain6'
                                        *   '<S175>/Gain2'
                                        *   '<S175>/Saturation'
                                        *   '<S176>/Integrator'
                                        *   '<S31>/Dead Zone'
                                        *   '<S31>/Gain'
                                        *   '<S50>/Dead Zone'
                                        *   '<S50>/Gain'
                                        *   '<S64>/Dead Zone'
                                        *   '<S64>/Gain'
                                        *   '<S77>/Dead Zone'
                                        *   '<S77>/Gain'
                                        *   '<S90>/Dead Zone'
                                        *   '<S90>/Gain'
                                        *   '<S91>/Dead Zone'
                                        *   '<S91>/Gain'
                                        *   '<S114>/Dead Zone'
                                        *   '<S114>/Gain'
                                        *   '<S136>/Dead Zone'
                                        *   '<S136>/Gain'
                                        *   '<S148>/Dead Zone'
                                        *   '<S148>/Gain'
                                        *   '<S160>/Dead Zone'
                                        *   '<S160>/Gain'
                                        *   '<S161>/Dead Zone'
                                        *   '<S161>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 32, 118, 48, 46, 50, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by: '<S9>/Constant'
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
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static void FMS_sf_msg_send_M(void);
static boolean_T FMS_sf_msg_pop_M(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
static void FMS_SubMode(void);
static void FMS_exit_internal_Arm(void);
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode);
static void FMS_Mode_Manager(void);
static void FMS_c11_FMS(void);
static void FMS_sf_msg_discard_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for action system:
 *    '<S2>/Disarm'
 *    '<S13>/Unknown'
 *    '<S11>/Unknown'
 *    '<S10>/Unknown'
 *    '<S6>/Unknown'
 */
void FMS_Disarm(FMS_Out_Bus *rty_FMS_Out, const ConstB_Disarm_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S7>/Bus Assignment' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant2'
   *  SignalConversion: '<S7>/TmpHiddenBufferAtBus AssignmentInport1'
   */
  *rty_FMS_Out = FMS_rtZFMS_Out_Bus;
  rty_FMS_Out->reset = 1U;
  rty_FMS_Out->status = localC->DataTypeConversion;
  rty_FMS_Out->mode = localC->DataTypeConversion1;
  rty_FMS_Out->actuator_cmd[0] = 1000U;
  rty_FMS_Out->actuator_cmd[1] = 1000U;
  rty_FMS_Out->actuator_cmd[2] = 1000U;
  rty_FMS_Out->actuator_cmd[3] = 1000U;
  for (i = 0; i < 12; i++) {
    rty_FMS_Out->actuator_cmd[i + 4] = 0U;
  }

  /* End of BusAssignment: '<S7>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S130>/Hold Control'
 *    '<S25>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S133>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S130>/Hold Control'
 *    '<S25>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S133>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S130>/Hold Control'
 *    '<S25>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S133>/Delay' incorporates:
   *  Gain: '<S135>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S133>/Gain2' incorporates:
   *  Delay: '<S133>/Delay'
   *  Gain: '<S135>/Gain'
   *  Sum: '<S133>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S133>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S130>/Brake Control'
 *    '<S140>/Brake Control'
 *    '<S106>/Brake Control'
 *    '<S25>/Brake Control'
 *    '<S42>/Brake Control'
 *    '<S58>/Brake Control'
 *    '<S69>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S132>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S132>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S130>/Move Control'
 *    '<S25>/Move Control'
 *    '<S58>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S130>/Move Control'
 *    '<S25>/Move Control'
 *    '<S58>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S130>/Move Control'
 *    '<S25>/Move Control'
 *    '<S58>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3;
  real32_T rtb_Subtract3_pn;
  real32_T rtb_a_k;
  real32_T rtb_Add4_k;
  real32_T rtb_a_d;

  /* Product: '<S138>/Multiply1' incorporates:
   *  Constant: '<S138>/const1'
   *  DiscreteIntegrator: '<S137>/Integrator'
   */
  rtb_Add3 = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S136>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_k = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_k = 0.0F;
  } else {
    rtb_a_k = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S136>/Dead Zone' */

  /* Sum: '<S138>/Add' incorporates:
   *  DiscreteIntegrator: '<S137>/Integrator1'
   *  Gain: '<S134>/Gain1'
   *  Gain: '<S136>/Gain'
   *  Sum: '<S137>/Subtract'
   */
  rtb_Subtract3_pn = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_k * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3;

  /* Signum: '<S138>/Sign' */
  if (rtb_Subtract3_pn < 0.0F) {
    rtb_a_k = -1.0F;
  } else if (rtb_Subtract3_pn > 0.0F) {
    rtb_a_k = 1.0F;
  } else {
    rtb_a_k = rtb_Subtract3_pn;
  }

  /* End of Signum: '<S138>/Sign' */

  /* Sum: '<S138>/Add2' incorporates:
   *  Abs: '<S138>/Abs'
   *  Gain: '<S138>/Gain'
   *  Gain: '<S138>/Gain1'
   *  Product: '<S138>/Multiply2'
   *  Product: '<S138>/Multiply3'
   *  Sqrt: '<S138>/Sqrt'
   *  Sum: '<S138>/Add1'
   *  Sum: '<S138>/Subtract'
   */
  rtb_a_k = (sqrtf((8.0F * fabsf(rtb_Subtract3_pn) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_k + rtb_Add3;

  /* Sum: '<S138>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_pn - rtb_a_k) + rtb_Add3;

  /* Sum: '<S138>/Add3' */
  rtb_Add3 = rtb_Subtract3_pn + localC->d;

  /* Sum: '<S138>/Subtract1' */
  rtb_Subtract3_pn -= localC->d;

  /* Signum: '<S138>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S138>/Sign1' */

  /* Signum: '<S138>/Sign2' */
  if (rtb_Subtract3_pn < 0.0F) {
    rtb_Subtract3_pn = -1.0F;
  } else {
    if (rtb_Subtract3_pn > 0.0F) {
      rtb_Subtract3_pn = 1.0F;
    }
  }

  /* End of Signum: '<S138>/Sign2' */

  /* Sum: '<S138>/Add5' incorporates:
   *  Gain: '<S138>/Gain2'
   *  Product: '<S138>/Multiply4'
   *  Sum: '<S138>/Subtract2'
   */
  rtb_a_k += (rtb_Add3 - rtb_Subtract3_pn) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S134>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S137>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S137>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S137>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S138>/Add6' */
  rtb_Add3 = rtb_a_k + localC->d;

  /* Sum: '<S138>/Subtract3' */
  rtb_Subtract3_pn = rtb_a_k - localC->d;

  /* Signum: '<S138>/Sign5' */
  if (rtb_a_k < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_k > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_k;
  }

  /* End of Signum: '<S138>/Sign5' */

  /* Signum: '<S138>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S138>/Sign3' */

  /* Signum: '<S138>/Sign4' */
  if (rtb_Subtract3_pn < 0.0F) {
    rtb_Subtract3_pn = -1.0F;
  } else {
    if (rtb_Subtract3_pn > 0.0F) {
      rtb_Subtract3_pn = 1.0F;
    }
  }

  /* End of Signum: '<S138>/Sign4' */

  /* Signum: '<S138>/Sign6' */
  if (rtb_a_k < 0.0F) {
    rtb_a_d = -1.0F;
  } else if (rtb_a_k > 0.0F) {
    rtb_a_d = 1.0F;
  } else {
    rtb_a_d = rtb_a_k;
  }

  /* End of Signum: '<S138>/Sign6' */

  /* Update for DiscreteIntegrator: '<S137>/Integrator' incorporates:
   *  Constant: '<S138>/const'
   *  Gain: '<S138>/Gain3'
   *  Product: '<S138>/Divide'
   *  Product: '<S138>/Multiply5'
   *  Product: '<S138>/Multiply6'
   *  Sum: '<S138>/Subtract4'
   *  Sum: '<S138>/Subtract5'
   *  Sum: '<S138>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_k / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3 - rtb_Subtract3_pn) * 0.5F) - rtb_a_d * 78.448F) *
    0.004F;
}

/*
 * System initialize for action system:
 *    '<S140>/Hold Control'
 *    '<S106>/Hold Control'
 *    '<S42>/Hold Control'
 *    '<S69>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S143>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S140>/Hold Control'
 *    '<S106>/Hold Control'
 *    '<S42>/Hold Control'
 *    '<S69>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S143>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S140>/Hold Control'
 *    '<S106>/Hold Control'
 *    '<S42>/Hold Control'
 *    '<S69>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad_o;
  real32_T rtb_Abs_l;

  /* Delay: '<S143>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S143>/Sum' incorporates:
   *  Delay: '<S143>/Delay'
   */
  rtb_psi_error_rad_o = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S146>/Abs' */
  rtb_Abs_l = fabsf(rtb_psi_error_rad_o);

  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S146>/Constant'
   *  Constant: '<S147>/Constant'
   *  Product: '<S146>/Multiply'
   *  RelationalOperator: '<S147>/Compare'
   *  Sum: '<S146>/Subtract'
   */
  if (rtb_Abs_l > 3.14159274F) {
    /* Signum: '<S146>/Sign' */
    if (rtb_psi_error_rad_o < 0.0F) {
      rtb_psi_error_rad_o = -1.0F;
    } else {
      if (rtb_psi_error_rad_o > 0.0F) {
        rtb_psi_error_rad_o = 1.0F;
      }
    }

    /* End of Signum: '<S146>/Sign' */
    rtb_psi_error_rad_o *= rtb_Abs_l - 6.28318548F;
  }

  /* End of Switch: '<S146>/Switch' */

  /* Gain: '<S143>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad_o;

  /* Update for Delay: '<S143>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S140>/Move Control'
 *    '<S106>/Move Control'
 *    '<S42>/Move Control'
 *    '<S69>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S140>/Move Control'
 *    '<S106>/Move Control'
 *    '<S42>/Move Control'
 *    '<S69>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S140>/Move Control'
 *    '<S106>/Move Control'
 *    '<S42>/Move Control'
 *    '<S69>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3;
  real32_T rtb_Subtract3_hi;
  real32_T rtb_a_m;
  real32_T rtb_Add4_bf;
  real32_T rtb_a_p;

  /* Product: '<S150>/Multiply1' incorporates:
   *  Constant: '<S150>/const1'
   *  DiscreteIntegrator: '<S149>/Integrator'
   */
  rtb_Add3 = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S148>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S148>/Dead Zone' */

  /* Sum: '<S150>/Add' incorporates:
   *  DiscreteIntegrator: '<S149>/Integrator1'
   *  Gain: '<S144>/Gain1'
   *  Gain: '<S148>/Gain'
   *  Sum: '<S149>/Subtract'
   */
  rtb_Subtract3_hi = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3;

  /* Signum: '<S150>/Sign' */
  if (rtb_Subtract3_hi < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_hi > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_hi;
  }

  /* End of Signum: '<S150>/Sign' */

  /* Sum: '<S150>/Add2' incorporates:
   *  Abs: '<S150>/Abs'
   *  Gain: '<S150>/Gain'
   *  Gain: '<S150>/Gain1'
   *  Product: '<S150>/Multiply2'
   *  Product: '<S150>/Multiply3'
   *  Sqrt: '<S150>/Sqrt'
   *  Sum: '<S150>/Add1'
   *  Sum: '<S150>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_hi) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3;

  /* Sum: '<S150>/Add4' */
  rtb_Add4_bf = (rtb_Subtract3_hi - rtb_a_m) + rtb_Add3;

  /* Sum: '<S150>/Add3' */
  rtb_Add3 = rtb_Subtract3_hi + localC->d;

  /* Sum: '<S150>/Subtract1' */
  rtb_Subtract3_hi -= localC->d;

  /* Signum: '<S150>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S150>/Sign1' */

  /* Signum: '<S150>/Sign2' */
  if (rtb_Subtract3_hi < 0.0F) {
    rtb_Subtract3_hi = -1.0F;
  } else {
    if (rtb_Subtract3_hi > 0.0F) {
      rtb_Subtract3_hi = 1.0F;
    }
  }

  /* End of Signum: '<S150>/Sign2' */

  /* Sum: '<S150>/Add5' incorporates:
   *  Gain: '<S150>/Gain2'
   *  Product: '<S150>/Multiply4'
   *  Sum: '<S150>/Subtract2'
   */
  rtb_a_m += (rtb_Add3 - rtb_Subtract3_hi) * 0.5F * rtb_Add4_bf;

  /* SignalConversion: '<S144>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S149>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S149>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S149>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S150>/Add6' */
  rtb_Add3 = rtb_a_m + localC->d;

  /* Sum: '<S150>/Subtract3' */
  rtb_Subtract3_hi = rtb_a_m - localC->d;

  /* Signum: '<S150>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_bf = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_bf = 1.0F;
  } else {
    rtb_Add4_bf = rtb_a_m;
  }

  /* End of Signum: '<S150>/Sign5' */

  /* Signum: '<S150>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S150>/Sign3' */

  /* Signum: '<S150>/Sign4' */
  if (rtb_Subtract3_hi < 0.0F) {
    rtb_Subtract3_hi = -1.0F;
  } else {
    if (rtb_Subtract3_hi > 0.0F) {
      rtb_Subtract3_hi = 1.0F;
    }
  }

  /* End of Signum: '<S150>/Sign4' */

  /* Signum: '<S150>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p = 1.0F;
  } else {
    rtb_a_p = rtb_a_m;
  }

  /* End of Signum: '<S150>/Sign6' */

  /* Update for DiscreteIntegrator: '<S149>/Integrator' incorporates:
   *  Constant: '<S150>/const'
   *  Gain: '<S150>/Gain3'
   *  Product: '<S150>/Divide'
   *  Product: '<S150>/Multiply5'
   *  Product: '<S150>/Multiply6'
   *  Sum: '<S150>/Subtract4'
   *  Sum: '<S150>/Subtract5'
   *  Sum: '<S150>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_bf) *
    localC->Gain4 * ((rtb_Add3 - rtb_Subtract3_hi) * 0.5F) - rtb_a_p *
    15.707963F) * 0.004F;
}

/*
 * System initialize for action system:
 *    '<S152>/Hold Control'
 *    '<S82>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S155>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S152>/Hold Control'
 *    '<S82>/Hold Control'
 */
void FMS_HoldControl_n_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S155>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S152>/Hold Control'
 *    '<S82>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, real32_T
  rtu_FMS_In_l, real32_T rty_uv_cmd_mPs[2], const ConstB_HoldControl_FMS_k_T
  *localC, DW_HoldControl_FMS_f_T *localDW)
{
  real32_T rtb_VectorConcatenate_e[9];
  real32_T rtb_VectorConcatenate_j[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_j_tmp;
  real32_T rtb_VectorConcatenate_j_tmp_0;

  /* Delay: '<S155>/Delay' incorporates:
   *  SignalConversion: '<S155>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_b;
  }

  /* Trigonometry: '<S159>/Trigonometric Function1' incorporates:
   *  Gain: '<S158>/Gain'
   *  Trigonometry: '<S159>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_j_tmp_0 = arm_cos_f32(-rtu_FMS_In_l);
  rtb_VectorConcatenate_e[0] = rtb_VectorConcatenate_j_tmp_0;

  /* Trigonometry: '<S159>/Trigonometric Function' incorporates:
   *  Gain: '<S158>/Gain'
   *  Trigonometry: '<S159>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_j_tmp = arm_sin_f32(-rtu_FMS_In_l);
  rtb_VectorConcatenate_e[1] = rtb_VectorConcatenate_j_tmp;

  /* SignalConversion: '<S159>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S159>/Constant3'
   */
  rtb_VectorConcatenate_e[2] = 0.0F;

  /* Gain: '<S159>/Gain' */
  rtb_VectorConcatenate_e[3] = -rtb_VectorConcatenate_j_tmp;

  /* Trigonometry: '<S159>/Trigonometric Function3' */
  rtb_VectorConcatenate_e[4] = rtb_VectorConcatenate_j_tmp_0;

  /* SignalConversion: '<S159>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S159>/Constant4'
   */
  rtb_VectorConcatenate_e[5] = 0.0F;

  /* SignalConversion: '<S159>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_e[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_e[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_e[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S155>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S155>/Delay'
   *  SignalConversion: '<S155>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S155>/Sum'
   */
  rtb_VectorConcatenate_j_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_j_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_b;

  /* Product: '<S155>/Multiply' incorporates:
   *  SignalConversion: '<S155>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_j[i] = rtb_VectorConcatenate_e[i + 3] *
      rtb_VectorConcatenate_j_tmp + rtb_VectorConcatenate_e[i] *
      rtb_VectorConcatenate_j_tmp_0;
  }

  /* End of Product: '<S155>/Multiply' */

  /* Gain: '<S155>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_j[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_j[1];

  /* Update for Delay: '<S155>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S152>/Brake Control'
 *    '<S82>/Brake Control'
 */
void FMS_BrakeControl_b(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S154>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S152>/Move Control'
 *    '<S82>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_k_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S162>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S152>/Move Control'
 *    '<S82>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_k_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S162>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S152>/Move Control'
 *    '<S82>/Move Control'
 */
void FMS_MoveControl_i(real32_T rtu_FMS_In, real32_T rtu_FMS_In_f, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_o_T *localC,
  DW_MoveControl_FMS_k_T *localDW)
{
  real32_T rtb_Subtract3_b;
  real32_T rtb_Add3_k_idx_0;
  real32_T rtb_Subtract3_l_idx_0;
  real32_T rtb_Add3_k_idx_1;
  real32_T rtb_Subtract3_l_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_l_idx_0_0;

  /* SignalConversion: '<S156>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S162>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S163>/Multiply1' incorporates:
   *  Constant: '<S163>/const1'
   *  DiscreteIntegrator: '<S162>/Integrator'
   */
  rtb_Add3_k_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S156>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S162>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S163>/Multiply1' incorporates:
   *  Constant: '<S163>/const1'
   *  DiscreteIntegrator: '<S162>/Integrator'
   */
  rtb_Add3_k_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S160>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S160>/Dead Zone' */

  /* Sum: '<S163>/Add' incorporates:
   *  DiscreteIntegrator: '<S162>/Integrator1'
   *  Gain: '<S156>/Gain6'
   *  Gain: '<S160>/Gain'
   *  Sum: '<S162>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_k_idx_0;

  /* DeadZone: '<S161>/Dead Zone' */
  if (rtu_FMS_In_f > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_f - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_f >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_f - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S161>/Dead Zone' */

  /* Sum: '<S163>/Add' incorporates:
   *  DiscreteIntegrator: '<S162>/Integrator1'
   *  Gain: '<S156>/Gain6'
   *  Gain: '<S161>/Gain'
   *  Sum: '<S162>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_k_idx_1;

  /* Signum: '<S163>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S163>/Add2' incorporates:
   *  Abs: '<S163>/Abs'
   *  Gain: '<S163>/Gain'
   *  Gain: '<S163>/Gain1'
   *  Product: '<S163>/Multiply2'
   *  Product: '<S163>/Multiply3'
   *  Signum: '<S163>/Sign'
   *  Sqrt: '<S163>/Sqrt'
   *  Sum: '<S163>/Add1'
   *  Sum: '<S163>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_k_idx_0;

  /* Sum: '<S163>/Add3' incorporates:
   *  Signum: '<S163>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S163>/Subtract1' incorporates:
   *  Signum: '<S163>/Sign'
   */
  rtb_Subtract3_b = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S163>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S163>/Sign2' */
  if (rtb_Subtract3_b < 0.0F) {
    rtb_Subtract3_b = -1.0F;
  } else {
    if (rtb_Subtract3_b > 0.0F) {
      rtb_Subtract3_b = 1.0F;
    }
  }

  /* Sum: '<S163>/Add5' incorporates:
   *  Gain: '<S163>/Gain2'
   *  Product: '<S163>/Multiply4'
   *  Signum: '<S163>/Sign'
   *  Sum: '<S163>/Add2'
   *  Sum: '<S163>/Add4'
   *  Sum: '<S163>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_k_idx_0) * ((u - rtb_Subtract3_b) * 0.5F);

  /* Update for DiscreteIntegrator: '<S162>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S162>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S163>/Sign3' incorporates:
   *  Sum: '<S163>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S163>/Sign4' incorporates:
   *  Sum: '<S163>/Subtract3'
   */
  rtb_Add3_k_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S163>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S163>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S163>/Sign4' */
  if (rtb_Add3_k_idx_0 < 0.0F) {
    rtb_Add3_k_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_k_idx_0 > 0.0F) {
      rtb_Add3_k_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S163>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_b = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_b = 1.0F;
  } else {
    rtb_Subtract3_b = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S162>/Integrator' incorporates:
   *  Constant: '<S163>/const'
   *  Gain: '<S163>/Gain3'
   *  Product: '<S163>/Divide'
   *  Product: '<S163>/Multiply5'
   *  Product: '<S163>/Multiply6'
   *  Sum: '<S163>/Subtract4'
   *  Sum: '<S163>/Subtract5'
   *  Sum: '<S163>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_k_idx_0) * 0.5F) -
    rtb_Subtract3_b * 58.836F) * 0.004F;

  /* Signum: '<S163>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_k_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_k_idx_0 = 1.0F;
  } else {
    rtb_Add3_k_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S163>/Add2' incorporates:
   *  Abs: '<S163>/Abs'
   *  Gain: '<S163>/Gain'
   *  Gain: '<S163>/Gain1'
   *  Product: '<S163>/Multiply2'
   *  Product: '<S163>/Multiply3'
   *  Signum: '<S163>/Sign'
   *  Sqrt: '<S163>/Sqrt'
   *  Sum: '<S163>/Add1'
   *  Sum: '<S163>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_k_idx_0 +
    rtb_Add3_k_idx_1;

  /* Sum: '<S163>/Add3' incorporates:
   *  Signum: '<S163>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S163>/Subtract1' incorporates:
   *  Signum: '<S163>/Sign'
   */
  rtb_Subtract3_b = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S163>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S163>/Sign2' */
  if (rtb_Subtract3_b < 0.0F) {
    rtb_Subtract3_b = -1.0F;
  } else {
    if (rtb_Subtract3_b > 0.0F) {
      rtb_Subtract3_b = 1.0F;
    }
  }

  /* Sum: '<S163>/Add5' incorporates:
   *  Gain: '<S163>/Gain2'
   *  Product: '<S163>/Multiply4'
   *  Signum: '<S163>/Sign'
   *  Sum: '<S163>/Add2'
   *  Sum: '<S163>/Add4'
   *  Sum: '<S163>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_k_idx_1) * ((u - rtb_Subtract3_b) * 0.5F);

  /* Update for DiscreteIntegrator: '<S162>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S162>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S163>/Sign3' incorporates:
   *  Sum: '<S163>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S163>/Sign4' incorporates:
   *  Sum: '<S163>/Subtract3'
   */
  rtb_Add3_k_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S163>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S163>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S163>/Sign4' */
  if (rtb_Add3_k_idx_0 < 0.0F) {
    rtb_Add3_k_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_k_idx_0 > 0.0F) {
      rtb_Add3_k_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S163>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_b = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_b = 1.0F;
  } else {
    rtb_Subtract3_b = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S162>/Integrator' incorporates:
   *  Constant: '<S163>/const'
   *  Gain: '<S163>/Gain3'
   *  Product: '<S163>/Divide'
   *  Product: '<S163>/Multiply5'
   *  Product: '<S163>/Multiply6'
   *  Sum: '<S163>/Subtract4'
   *  Sum: '<S163>/Subtract5'
   *  Sum: '<S163>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_k_idx_0) * 0.5F) -
    rtb_Subtract3_b * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S107>/Motion State'
 *    '<S43>/Motion State'
 *    '<S70>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S107>/Motion State'
 *    '<S43>/Motion State'
 *    '<S70>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S107>/Motion State'
 *    '<S43>/Motion State'
 *    '<S70>/Motion State'
 */
void FMS_MotionState(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S107>/Motion State' */
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c19_FMS == 0U) {
    localDW->is_active_c19_FMS = 1U;
    localDW->is_c19_FMS = FMS_IN_Move;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c19_FMS) {
     case FMS_IN_Brake:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.1) || (localDW->temporalCounter_i1 >= 250U)) {
        localDW->is_c19_FMS = FMS_IN_Hold;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c19_FMS = FMS_IN_Move;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c19_FMS = FMS_IN_Move;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c19_FMS = FMS_IN_Brake;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S107>/Motion State' */
}

/*
 * System initialize for atomic system:
 *    '<S26>/Motion Status'
 *    '<S59>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S26>/Motion Status'
 *    '<S59>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S26>/Motion Status'
 *    '<S59>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S26>/Motion Status' */
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

  /* End of Chart: '<S26>/Motion Status' */
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_p, &FMS_DW.Msg_FMS_Cmd_m
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_m[0] : NULL;
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
static void FMS_SubMode(void)
{
  boolean_T sf_internal_predicateOutput;
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  real_T tmp;
  if (FMS_sf_msg_pop_M()) {
    sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Pause);
  } else {
    sf_internal_predicateOutput = false;
  }

  if (sf_internal_predicateOutput) {
    FMS_DW.is_SubMode = FMS_IN_Hold_b;
    FMS_B.VehicleMode_e = VehicleMode_Hold;
  } else {
    switch (FMS_DW.is_SubMode) {
     case FMS_IN_Hold_b:
      if (FMS_sf_msg_pop_M()) {
        sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Continue);
      } else {
        sf_internal_predicateOutput = false;
      }

      if (sf_internal_predicateOutput) {
        tmp = FMS_getArmMode(FMS_B.DataTypeConversion1);
        if (tmp == 3.0) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_Auto;
          switch (FMS_B.DataTypeConversion1) {
           case PilotMode_Offboard:
            FMS_DW.is_Auto = FMS_IN_Offboard;
            FMS_B.VehicleMode_e = VehicleMode_Offboard;
            break;

           case PilotMode_Mission:
            FMS_DW.is_Auto = FMS_IN_Mission;
            FMS_B.VehicleMode_e = VehicleMode_Mission;
            break;

           default:
            FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAutoMode;
            break;
          }
        } else if (tmp == 2.0) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_Assist;
          switch (FMS_B.DataTypeConversion1) {
           case PilotMode_Acro:
            FMS_DW.is_Assist = FMS_IN_Acro;
            FMS_B.VehicleMode_e = VehicleMode_Acro;
            break;

           case PilotMode_Stabilize:
            FMS_DW.is_Assist = FMS_IN_Stabilize;
            FMS_B.VehicleMode_e = VehicleMode_Stabilize;
            break;

           case PilotMode_Altitude:
            FMS_DW.is_Assist = FMS_IN_Altitude;
            FMS_B.VehicleMode_e = VehicleMode_Altitude;
            break;

           case PilotMode_Position:
            FMS_DW.is_Assist = FMS_IN_Position;
            FMS_B.VehicleMode_e = VehicleMode_Position;
            break;

           default:
            FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAssistMode;
            break;
          }
        } else if (tmp == 1.0) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_Manual;
          if (FMS_B.DataTypeConversion1 == PilotMode_Manual) {
            FMS_DW.is_Manual = FMS_IN_Manual_b;
            FMS_B.VehicleMode_e = VehicleMode_Manual;
          } else {
            FMS_DW.is_Manual = FMS_IN_InValidManualMode;
            FMS_B.VehicleMode_e = VehicleMode_InValidManualMode;
          }
        } else {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
          FMS_B.VehicleMode_e = VehicleMode_InvalidArmMode;
        }
      }
      break;

     case FMS_IN_Land:
      if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
      if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1 >=
          500) {
        FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
        FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
        FMS_DW.is_Mode_Manager = FMS_IN_Disarm;
        FMS_B.VehicleMode_e = VehicleMode_Disarm;
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
      if (y < 1.0F) {
        FMS_B.Cmd_In.p_land[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.p_land[1] = FMS_DW.home[1];
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
        FMS_DW.is_SubMode = FMS_IN_Land;
        FMS_B.VehicleMode_e = VehicleMode_Land;
        FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
      }
      break;

     case FMS_IN_Takeoff:
      if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R - FMS_DW.home[2] > 2.0F) {
        if (FMS_getArmMode(FMS_B.DataTypeConversion1) == 3.0) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_Auto;
          switch (FMS_B.DataTypeConversion1) {
           case PilotMode_Offboard:
            FMS_DW.is_Auto = FMS_IN_Offboard;
            FMS_B.VehicleMode_e = VehicleMode_Offboard;
            break;

           case PilotMode_Mission:
            FMS_DW.is_Auto = FMS_IN_Mission;
            FMS_B.VehicleMode_e = VehicleMode_Mission;
            break;

           default:
            FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAutoMode;
            break;
          }
        } else if (FMS_getArmMode(FMS_B.DataTypeConversion1) == 2.0) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_Assist;
          switch (FMS_B.DataTypeConversion1) {
           case PilotMode_Acro:
            FMS_DW.is_Assist = FMS_IN_Acro;
            FMS_B.VehicleMode_e = VehicleMode_Acro;
            break;

           case PilotMode_Stabilize:
            FMS_DW.is_Assist = FMS_IN_Stabilize;
            FMS_B.VehicleMode_e = VehicleMode_Stabilize;
            break;

           case PilotMode_Altitude:
            FMS_DW.is_Assist = FMS_IN_Altitude;
            FMS_B.VehicleMode_e = VehicleMode_Altitude;
            break;

           case PilotMode_Position:
            FMS_DW.is_Assist = FMS_IN_Position;
            FMS_B.VehicleMode_e = VehicleMode_Position;
            break;

           default:
            FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAssistMode;
            break;
          }
        } else if (FMS_getArmMode(FMS_B.DataTypeConversion1) == 1.0) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_Manual;
          if (FMS_B.DataTypeConversion1 == PilotMode_Manual) {
            FMS_DW.is_Manual = FMS_IN_Manual_b;
            FMS_B.VehicleMode_e = VehicleMode_Manual;
          } else {
            FMS_DW.is_Manual = FMS_IN_InValidManualMode;
            FMS_B.VehicleMode_e = VehicleMode_InValidManualMode;
          }
        } else {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
          FMS_B.VehicleMode_e = VehicleMode_InvalidArmMode;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_Arm(void)
{
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
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
static void FMS_Mode_Manager(void)
{
  boolean_T sf_internal_predicateOutput;
  real_T tmp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  if (FMS_sf_msg_pop_M()) {
    sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Disarm);
  } else {
    sf_internal_predicateOutput = false;
  }

  if (sf_internal_predicateOutput) {
    FMS_exit_internal_Arm();
    FMS_DW.is_Mode_Manager = FMS_IN_Disarm;
    FMS_B.VehicleMode_e = VehicleMode_Disarm;
  } else {
    guard1 = false;
    guard2 = false;
    switch (FMS_DW.is_Mode_Manager) {
     case FMS_IN_Arm:
      if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_g))
      {
        FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_B.LogicalOperator1;
      if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_n
          >= 500) {
        FMS_exit_internal_Arm();
        FMS_DW.is_Mode_Manager = FMS_IN_Disarm;
        FMS_B.VehicleMode_e = VehicleMode_Disarm;
      } else if (FMS_DW.mode_prev != FMS_DW.mode_start) {
        tmp = FMS_getArmMode(FMS_B.DataTypeConversion1);
        if (tmp == 3.0) {
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_Auto;
          switch (FMS_B.DataTypeConversion1) {
           case PilotMode_Offboard:
            FMS_DW.is_Auto = FMS_IN_Offboard;
            FMS_B.VehicleMode_e = VehicleMode_Offboard;
            break;

           case PilotMode_Mission:
            FMS_DW.is_Auto = FMS_IN_Mission;
            FMS_B.VehicleMode_e = VehicleMode_Mission;
            break;

           default:
            FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAutoMode;
            break;
          }
        } else if (tmp == 2.0) {
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_Assist;
          switch (FMS_B.DataTypeConversion1) {
           case PilotMode_Acro:
            FMS_DW.is_Assist = FMS_IN_Acro;
            FMS_B.VehicleMode_e = VehicleMode_Acro;
            break;

           case PilotMode_Stabilize:
            FMS_DW.is_Assist = FMS_IN_Stabilize;
            FMS_B.VehicleMode_e = VehicleMode_Stabilize;
            break;

           case PilotMode_Altitude:
            FMS_DW.is_Assist = FMS_IN_Altitude;
            FMS_B.VehicleMode_e = VehicleMode_Altitude;
            break;

           case PilotMode_Position:
            FMS_DW.is_Assist = FMS_IN_Position;
            FMS_B.VehicleMode_e = VehicleMode_Position;
            break;

           default:
            FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAssistMode;
            break;
          }
        } else if (tmp == 1.0) {
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_Manual;
          if (FMS_B.DataTypeConversion1 == PilotMode_Manual) {
            FMS_DW.is_Manual = FMS_IN_Manual_b;
            FMS_B.VehicleMode_e = VehicleMode_Manual;
          } else {
            FMS_DW.is_Manual = FMS_IN_InValidManualMode;
            FMS_B.VehicleMode_e = VehicleMode_InValidManualMode;
          }
        } else {
          FMS_exit_internal_Arm();
          FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
          FMS_B.VehicleMode_e = VehicleMode_InvalidArmMode;
        }
      } else {
        if (FMS_sf_msg_pop_M()) {
          sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Return);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          FMS_exit_internal_Arm();
          FMS_B.Cmd_In.p_return[0] = FMS_DW.home[0];
          FMS_B.Cmd_In.p_return[1] = FMS_DW.home[1];
          FMS_DW.is_Arm = FMS_IN_SubMode;
          FMS_DW.is_SubMode = FMS_IN_Return;
          FMS_B.VehicleMode_e = VehicleMode_Return;
        } else {
          if (FMS_sf_msg_pop_M()) {
            sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Land);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            FMS_exit_internal_Arm();
            FMS_B.Cmd_In.p_land[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.p_land[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_DW.is_Arm = FMS_IN_SubMode;
            FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
            FMS_DW.is_SubMode = FMS_IN_Land;
            FMS_B.VehicleMode_e = VehicleMode_Land;
            FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
          } else {
            switch (FMS_DW.is_Arm) {
             case FMS_IN_Assist:
              if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
                FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
                FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
                FMS_DW.is_Mode_Manager = FMS_IN_Disarm;
                FMS_B.VehicleMode_e = VehicleMode_Disarm;
              }
              break;

             case FMS_IN_Auto:
              if (FMS_sf_msg_pop_M()) {
                sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
                  CMD_Pause);
              } else {
                sf_internal_predicateOutput = false;
              }

              if (sf_internal_predicateOutput) {
                FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
                FMS_DW.is_Arm = FMS_IN_SubMode;
                FMS_DW.is_SubMode = FMS_IN_Hold_b;
                FMS_B.VehicleMode_e = VehicleMode_Hold;
              } else {
                if (FMS_DW.is_Auto == FMS_IN_InvalidAutoMode) {
                  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
                  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
                  FMS_DW.is_Mode_Manager = FMS_IN_Disarm;
                  FMS_B.VehicleMode_e = VehicleMode_Disarm;
                }
              }
              break;

             case FMS_IN_InvalidArmMode:
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Mode_Manager = FMS_IN_Disarm;
              FMS_B.VehicleMode_e = VehicleMode_Disarm;
              break;

             case FMS_IN_Manual:
              if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
                FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
                FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
                FMS_DW.is_Mode_Manager = FMS_IN_Disarm;
                FMS_B.VehicleMode_e = VehicleMode_Disarm;
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
        sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_PreArm);
      } else {
        sf_internal_predicateOutput = false;
      }

      if (sf_internal_predicateOutput) {
        guard1 = true;
      } else {
        if (FMS_sf_msg_pop_M()) {
          sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == CMD_Takeoff);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          FMS_DW.prep_takeoff = 1.0;
          sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
          if ((!sf_internal_predicateOutput) ||
              (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
            FMS_DW.durationLastReferenceTick_1_d =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
          guard1 = true;
        }
      }
      break;

     case FMS_IN_Standby:
      if ((FMS_ManualArmEvent
           (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
            FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
          (FMS_DW.prep_takeoff == 0.0)) {
        FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
        FMS_DW.is_Mode_Manager = FMS_IN_Arm;
        FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_B.LogicalOperator1;
        if (FMS_getArmMode(FMS_B.DataTypeConversion1) == 3.0) {
          FMS_DW.is_Arm = FMS_IN_Auto;
          switch (FMS_B.DataTypeConversion1) {
           case PilotMode_Offboard:
            FMS_DW.is_Auto = FMS_IN_Offboard;
            FMS_B.VehicleMode_e = VehicleMode_Offboard;
            break;

           case PilotMode_Mission:
            FMS_DW.is_Auto = FMS_IN_Mission;
            FMS_B.VehicleMode_e = VehicleMode_Mission;
            break;

           default:
            FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAutoMode;
            break;
          }
        } else if (FMS_getArmMode(FMS_B.DataTypeConversion1) == 2.0) {
          FMS_DW.is_Arm = FMS_IN_Assist;
          switch (FMS_B.DataTypeConversion1) {
           case PilotMode_Acro:
            FMS_DW.is_Assist = FMS_IN_Acro;
            FMS_B.VehicleMode_e = VehicleMode_Acro;
            break;

           case PilotMode_Stabilize:
            FMS_DW.is_Assist = FMS_IN_Stabilize;
            FMS_B.VehicleMode_e = VehicleMode_Stabilize;
            break;

           case PilotMode_Altitude:
            FMS_DW.is_Assist = FMS_IN_Altitude;
            FMS_B.VehicleMode_e = VehicleMode_Altitude;
            break;

           case PilotMode_Position:
            FMS_DW.is_Assist = FMS_IN_Position;
            FMS_B.VehicleMode_e = VehicleMode_Position;
            break;

           default:
            FMS_DW.is_Assist = FMS_IN_InvalidAssistMode;
            FMS_B.VehicleMode_e = VehicleMode_InvalidAssistMode;
            break;
          }
        } else if (FMS_getArmMode(FMS_B.DataTypeConversion1) == 1.0) {
          FMS_DW.is_Arm = FMS_IN_Manual;
          if (FMS_B.DataTypeConversion1 == PilotMode_Manual) {
            FMS_DW.is_Manual = FMS_IN_Manual_b;
            FMS_B.VehicleMode_e = VehicleMode_Manual;
          } else {
            FMS_DW.is_Manual = FMS_IN_InValidManualMode;
            FMS_B.VehicleMode_e = VehicleMode_InValidManualMode;
          }
        } else {
          FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
          FMS_B.VehicleMode_e = VehicleMode_InvalidArmMode;
        }
      } else {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
          FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_d > 500) {
          guard2 = true;
        } else {
          if (FMS_sf_msg_pop_M()) {
            sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              CMD_Takeoff);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            guard2 = true;
          } else {
            if ((FMS_DW.temporalCounter_i1 >= 7500U) || (FMS_DW.sfEvent ==
                 FMS_event_DisarmEvent)) {
              FMS_DW.is_Mode_Manager = FMS_IN_Disarm;
              FMS_B.VehicleMode_e = VehicleMode_Disarm;
            }
          }
        }
      }
      break;
    }

    if (guard2) {
      FMS_B.Cmd_In.p_takeoff[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.p_takeoff[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Mode_Manager = FMS_IN_Arm;
      FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_B.LogicalOperator1;
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.is_SubMode = FMS_IN_Takeoff;
      FMS_B.VehicleMode_e = VehicleMode_Takeoff;
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
        FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
    }

    if (guard1) {
      FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Mode_Manager = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      FMS_B.VehicleMode_e = VehicleMode_Standby;
      FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_DW.condWasTrueAtLastTimeStep_1_o = (FMS_DW.prep_takeoff == 1.0);
    }
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_c11_FMS(void)
{
  int32_T b_previousEvent;
  boolean_T condIsTrue;

  /* Chart: '<Root>/FMS State Machine' */
  if (FMS_DW.is_active_c11_FMS == 0U) {
    FMS_DW.cmd_prev = FMS_B.DataTypeConversion;
    FMS_DW.cmd_start = FMS_B.DataTypeConversion;
    FMS_DW.mode_prev = FMS_B.DataTypeConversion1;
    FMS_DW.mode_start = FMS_B.DataTypeConversion1;
    FMS_DW.chartAbsoluteTimeCounter = 0;
    FMS_DW.is_active_c11_FMS = 1U;
    FMS_DW.is_active_Command_Listener = 1U;
    FMS_DW.is_Command_Listener = FMS_IN_Listen;
    FMS_DW.is_active_Mode_Manager = 1U;
    FMS_DW.is_Mode_Manager = FMS_IN_Disarm;
    FMS_B.VehicleMode_e = VehicleMode_Disarm;
    FMS_DW.is_active_Combo_Stick = 1U;
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_e = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_om = FMS_BottomRight
      (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
       FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
    FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_BottomLeft
      (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
       FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
  } else {
    if (FMS_DW.is_active_Command_Listener != 0U) {
      switch (FMS_DW.is_Command_Listener) {
       case FMS_IN_Check:
        if (FMS_DW.valid_cmd == 1.0) {
          FMS_DW.is_Command_Listener = FMS_IN_Send;
          FMS_DW.M_msgReservedData = FMS_B.DataTypeConversion;
          FMS_sf_msg_send_M();
        } else {
          FMS_DW.is_Command_Listener = FMS_IN_Listen;
        }
        break;

       case FMS_IN_Listen:
        if (FMS_DW.cmd_prev != FMS_DW.cmd_start) {
          FMS_DW.is_Command_Listener = FMS_IN_Check;
          FMS_DW.valid_cmd = 1.0;
        }
        break;

       case FMS_IN_Send:
        FMS_DW.is_Command_Listener = FMS_IN_Listen;
        break;
      }
    }

    if (FMS_DW.is_active_Mode_Manager != 0U) {
      FMS_Mode_Manager();
    }

    if (FMS_DW.is_active_Combo_Stick != 0U) {
      switch (FMS_DW.is_Combo_Stick) {
       case FMS_IN_Arm:
        condIsTrue = FMS_BottomRight
          (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
           FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
        if (!condIsTrue) {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_e = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_om = condIsTrue;
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_BottomLeft
            (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
             FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_e = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_om = FMS_BottomRight
            (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
             FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
          FMS_DW.condWasTrueAtLastTimeStep_2 = FMS_BottomLeft
            (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
             FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
        }
        break;

       case FMS_IN_Idle:
        condIsTrue = FMS_BottomRight
          (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
           FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
        if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_1_om)) {
          FMS_DW.durationLastReferenceTick_1_e = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_om = condIsTrue;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_e > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = CMD_PreArm;
          FMS_sf_msg_send_M();
        } else {
          condIsTrue = FMS_BottomLeft
            (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
             FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
          if ((!condIsTrue) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
            FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2 = condIsTrue;
          if (FMS_DW.chartAbsoluteTimeCounter -
              FMS_DW.durationLastReferenceTick_2 > 375) {
            FMS_DW.is_Combo_Stick = FMS_IN_Disarm;
            b_previousEvent = FMS_DW.sfEvent;
            FMS_DW.sfEvent = FMS_event_DisarmEvent;
            FMS_c11_FMS();
            FMS_DW.sfEvent = b_previousEvent;
          }
        }
        break;
      }
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
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_m[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T dis;
  real32_T B;
  real32_T D;
  uint16_T rtb_Divide_b;
  int8_T rtPrevAction;
  real32_T rtb_VectorConcatenate_m[9];
  real32_T tmp;
  real32_T rtb_a_b;
  real32_T rtb_Integrator1_a;
  MotionState rtb_state_m2;
  MotionState rtb_state_di;
  MotionState rtb_state_dm;
  boolean_T rtb_LogicalOperator_n;
  real32_T rtb_TmpSignalConversionAtMathFu[3];
  int32_T i;
  boolean_T u;
  real32_T rtb_TmpSignalConversionAtSqua_0;
  real32_T rtb_MathFunction_idx_2;
  real32_T rtb_MathFunction_idx_1;
  real32_T rtb_Switch_h_idx_1;
  real32_T rtb_Saturation1_i_idx_0;
  real32_T rtb_MathFunction_idx_0;
  real32_T rtb_MathFunction_i_idx_0;
  real32_T rtb_Switch_b_idx_1;
  real32_T rtb_Switch_b_idx_0;
  real32_T rtb_Switch_b_idx_3;
  real32_T u1_tmp;
  boolean_T guard1 = false;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.DataTypeConversion = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.DataTypeConversion1 = (PilotMode)FMS_U.Pilot_Cmd.mode;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_3' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S211>/Discrete-Time Integrator5' incorporates:
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

  /* DiscreteIntegrator: '<S212>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S212>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_b;
  }

  /* Logic: '<S5>/Logical Operator1' incorporates:
   *  Constant: '<S210>/Constant'
   *  DiscreteIntegrator: '<S211>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S212>/Discrete-Time Integrator5'
   *  Logic: '<S213>/AND'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S210>/Compare'
   *  RelationalOperator: '<S213>/Lower Test'
   *  RelationalOperator: '<S213>/Upper Test'
   */
  FMS_B.LogicalOperator1 = ((-0.5F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] <= 0.5F) && ((-0.5F <=
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] <= 0.5F)) && ((-10.306F <=
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] <= -9.306F)) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTAT_d < 1200.0F));

  /* Chart: '<Root>/FMS State Machine' */
  FMS_DW.chartAbsoluteTimeCounter++;
  if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1)) {
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1 = FMS_B.LogicalOperator1;
  rtb_LogicalOperator_n = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_LogicalOperator_n) || (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
    FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_o = rtb_LogicalOperator_n;
  if ((!FMS_B.LogicalOperator1) || (!FMS_DW.condWasTrueAtLastTimeStep_1_g)) {
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_g = FMS_B.LogicalOperator1;
  rtb_LogicalOperator_n = FMS_BottomRight
    (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
     FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
  if ((!rtb_LogicalOperator_n) || (!FMS_DW.condWasTrueAtLastTimeStep_1_om)) {
    FMS_DW.durationLastReferenceTick_1_e = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_om = rtb_LogicalOperator_n;
  rtb_LogicalOperator_n = FMS_BottomLeft
    (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
     FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
  if ((!rtb_LogicalOperator_n) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_LogicalOperator_n;
  if (FMS_DW.temporalCounter_i1 < 8191U) {
    FMS_DW.temporalCounter_i1++;
  }

  FMS_DW.sfEvent = -1;
  FMS_DW.cmd_prev = FMS_DW.cmd_start;
  FMS_DW.cmd_start = FMS_B.DataTypeConversion;
  FMS_DW.mode_prev = FMS_DW.mode_start;
  FMS_DW.mode_start = FMS_B.DataTypeConversion1;
  FMS_DW.M_isValid = false;
  FMS_c11_FMS();
  FMS_sf_msg_discard_M();

  /* End of Chart: '<Root>/FMS State Machine' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SwitchCase: '<S2>/Switch Case' */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;
  switch (FMS_B.VehicleMode_e) {
   case VehicleMode_Disarm:
   case VehicleMode_None:
    FMS_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case VehicleMode_Standby:
    FMS_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   default:
    FMS_DW.SwitchCase_ActiveSubsystem = 2;
    break;
  }

  if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem) && (rtPrevAction == 2))
  {
    /* Disable for SwitchCase: '<S6>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S13>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_a == 3) {
        /* Disable for SwitchCase: '<S152>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S130>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S140>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
     case 3:
     case 4:
      break;

     case 2:
      /* Disable for SwitchCase: '<S10>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 4:
        break;

       case 1:
        /* Disable for SwitchCase: '<S106>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S25>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S42>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S82>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S58>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

        /* Disable for SwitchCase: '<S69>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S6>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/Disarm' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     */
    FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Disarm);

    /* End of Outputs for SubSystem: '<S2>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/Standby' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  BusAssignment: '<S8>/Bus Assignment'
     *  Constant: '<S8>/Constant'
     *  SignalConversion: '<S8>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S8>/Bus Assignment' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S8>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_f;
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
     *  ActionPort: '<S6>/Action Port'
     */
    /* SwitchCase: '<S6>/Switch Case' */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b;
    switch (FMS_B.VehicleMode_e) {
     case VehicleMode_Land:
     case VehicleMode_Return:
     case VehicleMode_Takeoff:
     case VehicleMode_Hold:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 0;
      break;

     case VehicleMode_Offboard:
     case VehicleMode_Mission:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 1;
      break;

     case VehicleMode_Acro:
     case VehicleMode_Stabilize:
     case VehicleMode_Altitude:
     case VehicleMode_Position:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 2;
      break;

     case VehicleMode_Manual:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 3;
      break;

     default:
      FMS_DW.SwitchCase_ActiveSubsystem_b = 4;
      break;
    }

    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S13>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_a == 3) {
          /* Disable for SwitchCase: '<S152>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S130>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S140>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
       case 3:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S10>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S106>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S25>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S42>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S82>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S58>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S69>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S6>/SubMode' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      /* SwitchCase: '<S13>/Switch Case' incorporates:
       *  Math: '<S197>/Math Function'
       *  Sum: '<S186>/Subtract'
       */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;
      switch (FMS_B.VehicleMode_e) {
       case VehicleMode_Takeoff:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
        break;

       case VehicleMode_Land:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
        break;

       case VehicleMode_Return:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
        break;

       case VehicleMode_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_a = 4;
        break;
      }

      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_a) && (rtPrevAction
           == 3)) {
        /* Disable for SwitchCase: '<S152>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S130>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S140>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S13>/Takeoff' incorporates:
         *  ActionPort: '<S125>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S209>/Trigonometric Function1' incorporates:
         *  Gain: '<S208>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S209>/Trigonometric Function3'
         */
        rtb_Saturation1_i_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_VectorConcatenate_m[0] = rtb_Saturation1_i_idx_0;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S209>/Trigonometric Function' incorporates:
         *  Gain: '<S208>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S209>/Trigonometric Function2'
         */
        rtb_Integrator1_a = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_VectorConcatenate_m[1] = rtb_Integrator1_a;

        /* SignalConversion: '<S209>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S209>/Constant3'
         */
        rtb_VectorConcatenate_m[2] = 0.0F;

        /* Gain: '<S209>/Gain' */
        rtb_VectorConcatenate_m[3] = -rtb_Integrator1_a;

        /* Trigonometry: '<S209>/Trigonometric Function3' */
        rtb_VectorConcatenate_m[4] = rtb_Saturation1_i_idx_0;

        /* SignalConversion: '<S209>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S209>/Constant4'
         */
        rtb_VectorConcatenate_m[5] = 0.0F;

        /* SignalConversion: '<S209>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S206>/Saturation1' */
        rtb_a_b = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Switch_b_idx_1 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* SignalConversion: '<S206>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S206>/Sum'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.p_takeoff[0] - FMS_U.INS_Out.x_R;
        dis = FMS_B.Cmd_In.p_takeoff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Product: '<S206>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_TmpSignalConversionAtMathFu[i] = rtb_VectorConcatenate_m[i + 3] *
            dis + rtb_VectorConcatenate_m[i] * rtb_Switch_b_idx_0;
        }

        /* Saturate: '<S206>/Saturation1' incorporates:
         *  Gain: '<S206>/Gain2'
         *  Product: '<S206>/Multiply'
         */
        rtb_Switch_b_idx_0 = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMathFu[0];
        dis = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMathFu[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S125>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S125>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S125>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S125>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S206>/Saturation1' */
        if (rtb_Switch_b_idx_0 > rtb_a_b) {
          /* BusAssignment: '<S125>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_a_b;
        } else if (rtb_Switch_b_idx_0 < rtb_Switch_b_idx_1) {
          /* BusAssignment: '<S125>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_b_idx_1;
        } else {
          /* BusAssignment: '<S125>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_b_idx_0;
        }

        if (dis > rtb_a_b) {
          /* BusAssignment: '<S125>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_b;
        } else if (dis < rtb_Switch_b_idx_1) {
          /* BusAssignment: '<S125>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_b_idx_1;
        } else {
          /* BusAssignment: '<S125>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = dis;
        }

        /* BusAssignment: '<S125>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S125>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = -0.5F;

        /* End of Outputs for SubSystem: '<S13>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S13>/Land' incorporates:
         *  ActionPort: '<S123>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Trigonometry: '<S169>/Trigonometric Function1' incorporates:
         *  Gain: '<S168>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S169>/Trigonometric Function' incorporates:
         *  Gain: '<S168>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SignalConversion: '<S169>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S169>/Constant3'
         */
        rtb_VectorConcatenate_m[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Gain: '<S169>/Gain' incorporates:
         *  Gain: '<S168>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Trigonometry: '<S169>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_m[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S169>/Trigonometric Function3' incorporates:
         *  Gain: '<S168>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_VectorConcatenate_m[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SignalConversion: '<S169>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S169>/Constant4'
         */
        rtb_VectorConcatenate_m[5] = 0.0F;

        /* SignalConversion: '<S169>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S165>/Saturation1' */
        rtb_a_b = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Switch_b_idx_1 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* SignalConversion: '<S166>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S166>/Sum'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.p_land[0] - FMS_U.INS_Out.x_R;
        dis = FMS_B.Cmd_In.p_land[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Product: '<S166>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_TmpSignalConversionAtMathFu[i] = rtb_VectorConcatenate_m[i + 3] *
            dis + rtb_VectorConcatenate_m[i] * rtb_Switch_b_idx_0;
        }

        /* Saturate: '<S165>/Saturation1' incorporates:
         *  Gain: '<S166>/Gain2'
         *  Product: '<S166>/Multiply'
         */
        rtb_Switch_b_idx_0 = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMathFu[0];
        dis = FMS_PARAM.XY_P * rtb_TmpSignalConversionAtMathFu[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S123>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S123>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S123>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S123>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S165>/Saturation1' */
        if (rtb_Switch_b_idx_0 > rtb_a_b) {
          /* BusAssignment: '<S123>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_a_b;
        } else if (rtb_Switch_b_idx_0 < rtb_Switch_b_idx_1) {
          /* BusAssignment: '<S123>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_b_idx_1;
        } else {
          /* BusAssignment: '<S123>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_b_idx_0;
        }

        if (dis > rtb_a_b) {
          /* BusAssignment: '<S123>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_a_b;
        } else if (dis < rtb_Switch_b_idx_1) {
          /* BusAssignment: '<S123>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_b_idx_1;
        } else {
          /* BusAssignment: '<S123>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = dis;
        }

        /* BusAssignment: '<S123>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S123>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S13>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S13>/Return' incorporates:
           *  ActionPort: '<S124>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S13>/Switch Case' incorporates:
           *  Delay: '<S170>/Delay'
           *  DiscreteIntegrator: '<S176>/Integrator'
           *  DiscreteIntegrator: '<S176>/Integrator1'
           *  DiscreteIntegrator: '<S202>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE_bs = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S13>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S13>/Return' incorporates:
         *  ActionPort: '<S124>/Action Port'
         */
        /* Delay: '<S170>/Delay' incorporates:
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
        /* Sum: '<S187>/Sum' incorporates:
         *  Delay: '<S170>/Delay'
         *  MATLAB Function: '<S185>/OutRegionRegWP'
         *  MATLAB Function: '<S185>/SearchL1RefWP'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_i_idx_0 = FMS_B.Cmd_In.p_return[0] -
          FMS_DW.Delay_DSTATE[0];
        rtb_Switch_h_idx_1 = FMS_B.Cmd_In.p_return[1] - FMS_DW.Delay_DSTATE[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S203>/Math Function' incorporates:
         *  Math: '<S183>/Math Function'
         *  Sum: '<S187>/Sum'
         */
        dis = rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1;

        /* Sum: '<S203>/Sum of Elements' incorporates:
         *  Math: '<S203>/Math Function'
         *  Sum: '<S187>/Sum'
         */
        tmp = rtb_MathFunction_i_idx_0 * rtb_MathFunction_i_idx_0 + dis;

        /* Math: '<S203>/Math Function1' incorporates:
         *  Sum: '<S203>/Sum of Elements'
         *
         * About '<S203>/Math Function1':
         *  Operator: sqrt
         */
        if (tmp < 0.0F) {
          rtb_a_b = -sqrtf(fabsf(tmp));
        } else {
          rtb_a_b = sqrtf(tmp);
        }

        /* End of Math: '<S203>/Math Function1' */

        /* Switch: '<S203>/Switch' incorporates:
         *  Constant: '<S203>/Constant'
         *  Product: '<S203>/Product'
         *  Sum: '<S187>/Sum'
         */
        if (rtb_a_b > 0.0F) {
          rtb_Switch_b_idx_0 = rtb_MathFunction_i_idx_0;
          rtb_Switch_b_idx_1 = rtb_Switch_h_idx_1;
          rtb_Switch_b_idx_3 = rtb_a_b;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_3 = 1.0F;
        }

        /* End of Switch: '<S203>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S184>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S188>/Square'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_a_b = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.p_return[0];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_Saturation1_i_idx_0 = rtb_a_b * rtb_a_b;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        rtb_a_b = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.p_return[1];

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S188>/Square' */
        rtb_a_b *= rtb_a_b;

        /* Sqrt: '<S188>/Sqrt' incorporates:
         *  Sum: '<S188>/Sum of Elements'
         */
        rtb_a_b = sqrtf(rtb_Saturation1_i_idx_0 + rtb_a_b);

        /* Switch: '<S184>/Switch' incorporates:
         *  Constant: '<S184>/vel'
         */
        if (rtb_a_b > 10.0F) {
          rtb_a_b = 5.0F;
        } else {
          /* Gain: '<S184>/Gain' */
          rtb_a_b *= 0.5F;

          /* Saturate: '<S184>/Saturation' */
          if (rtb_a_b < 0.5F) {
            rtb_a_b = 0.5F;
          }

          /* End of Saturate: '<S184>/Saturation' */
        }

        /* End of Switch: '<S184>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Gain: '<S204>/Gain' incorporates:
         *  DiscreteIntegrator: '<S202>/Discrete-Time Integrator'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S202>/Add'
         */
        rtb_Integrator1_a = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Trigonometry: '<S205>/Trigonometric Function1' incorporates:
         *  Trigonometry: '<S205>/Trigonometric Function3'
         */
        rtb_Saturation1_i_idx_0 = arm_cos_f32(rtb_Integrator1_a);
        rtb_VectorConcatenate_m[0] = rtb_Saturation1_i_idx_0;

        /* Trigonometry: '<S205>/Trigonometric Function' incorporates:
         *  Trigonometry: '<S205>/Trigonometric Function2'
         */
        rtb_Integrator1_a = arm_sin_f32(rtb_Integrator1_a);
        rtb_VectorConcatenate_m[1] = rtb_Integrator1_a;

        /* SignalConversion: '<S205>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S205>/Constant3'
         */
        rtb_VectorConcatenate_m[2] = 0.0F;

        /* Gain: '<S205>/Gain' */
        rtb_VectorConcatenate_m[3] = -rtb_Integrator1_a;

        /* Trigonometry: '<S205>/Trigonometric Function3' */
        rtb_VectorConcatenate_m[4] = rtb_Saturation1_i_idx_0;

        /* SignalConversion: '<S205>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S205>/Constant4'
         */
        rtb_VectorConcatenate_m[5] = 0.0F;

        /* SignalConversion: '<S205>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[6] = FMS_ConstB.VectorConcatenate3[0];

        /* Product: '<S201>/Multiply2' incorporates:
         *  Product: '<S203>/Divide'
         */
        rtb_Switch_b_idx_0 = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_3 * rtb_a_b;

        /* SignalConversion: '<S205>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[7] = FMS_ConstB.VectorConcatenate3[1];

        /* Product: '<S201>/Multiply2' incorporates:
         *  Product: '<S203>/Divide'
         */
        rtb_Switch_b_idx_1 = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_3 * rtb_a_b;

        /* SignalConversion: '<S205>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_m[8] = FMS_ConstB.VectorConcatenate3[2];

        /* Product: '<S187>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_TmpSignalConversionAtMathFu[i] = rtb_VectorConcatenate_m[i + 3] *
            rtb_Switch_b_idx_1 + rtb_VectorConcatenate_m[i] * rtb_Switch_b_idx_0;
        }

        /* End of Product: '<S187>/Multiply' */

        /* DiscreteIntegrator: '<S176>/Integrator1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_DW.Integrator1_DSTATE_e = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S175>/Sum' incorporates:
         *  DiscreteIntegrator: '<S176>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Switch_b_idx_1 = FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Abs: '<S178>/Abs' */
        rtb_Switch_b_idx_0 = fabsf(rtb_Switch_b_idx_1);

        /* Switch: '<S178>/Switch' incorporates:
         *  Constant: '<S178>/Constant'
         *  Constant: '<S179>/Constant'
         *  Product: '<S178>/Multiply'
         *  RelationalOperator: '<S179>/Compare'
         *  Sum: '<S178>/Subtract'
         */
        if (rtb_Switch_b_idx_0 > 3.14159274F) {
          /* Signum: '<S178>/Sign' */
          if (rtb_Switch_b_idx_1 < 0.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_b_idx_1 > 0.0F) {
              rtb_Switch_b_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S178>/Sign' */
          rtb_Switch_b_idx_1 *= rtb_Switch_b_idx_0 - 6.28318548F;
        }

        /* End of Switch: '<S178>/Switch' */

        /* Gain: '<S175>/Gain2' */
        rtb_Switch_b_idx_1 *= FMS_PARAM.YAW_P;

        /* Saturate: '<S175>/Saturation' */
        if (rtb_Switch_b_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Switch_b_idx_1 = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Switch_b_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Switch_b_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S175>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S124>/Bus Assignment1'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S124>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S124>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMathFu[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMathFu[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMathFu[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Switch_b_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S196>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S196>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sum: '<S195>/Sum of Elements'
         */
        tmp = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
          FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Math: '<S196>/Math Function1' incorporates:
         *  Sum: '<S196>/Sum of Elements'
         *
         * About '<S196>/Math Function1':
         *  Operator: sqrt
         */
        if (tmp < 0.0F) {
          rtb_Switch_b_idx_1 = -sqrtf(fabsf(tmp));
        } else {
          rtb_Switch_b_idx_1 = sqrtf(tmp);
        }

        /* End of Math: '<S196>/Math Function1' */

        /* Switch: '<S196>/Switch' incorporates:
         *  Constant: '<S196>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S196>/Product'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (rtb_Switch_b_idx_1 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_TmpSignalConversionAtMathFu[0] = FMS_U.INS_Out.vn;
          rtb_TmpSignalConversionAtMathFu[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          rtb_TmpSignalConversionAtMathFu[2] = rtb_Switch_b_idx_1;
        } else {
          rtb_TmpSignalConversionAtMathFu[0] = 0.0F;
          rtb_TmpSignalConversionAtMathFu[1] = 0.0F;
          rtb_TmpSignalConversionAtMathFu[2] = 1.0F;
        }

        /* End of Switch: '<S196>/Switch' */

        /* Sum: '<S183>/Sum of Elements' incorporates:
         *  Math: '<S183>/Math Function'
         *  Sum: '<S187>/Sum'
         */
        dis += rtb_MathFunction_i_idx_0 * rtb_MathFunction_i_idx_0;

        /* Math: '<S183>/Math Function1' incorporates:
         *  Sum: '<S183>/Sum of Elements'
         *
         * About '<S183>/Math Function1':
         *  Operator: sqrt
         */
        if (dis < 0.0F) {
          rtb_Switch_b_idx_1 = -sqrtf(fabsf(dis));
        } else {
          rtb_Switch_b_idx_1 = sqrtf(dis);
        }

        /* End of Math: '<S183>/Math Function1' */

        /* Switch: '<S183>/Switch' incorporates:
         *  Constant: '<S183>/Constant'
         *  Product: '<S183>/Product'
         *  Sum: '<S187>/Sum'
         */
        if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_MathFunction_idx_0 = rtb_Switch_h_idx_1;
          rtb_MathFunction_idx_1 = rtb_MathFunction_i_idx_0;
          rtb_MathFunction_idx_2 = rtb_Switch_b_idx_1;
        } else {
          rtb_MathFunction_idx_0 = 0.0F;
          rtb_MathFunction_idx_1 = 0.0F;
          rtb_MathFunction_idx_2 = 1.0F;
        }

        /* End of Switch: '<S183>/Switch' */

        /* Product: '<S196>/Divide' */
        rtb_Switch_b_idx_3 = rtb_TmpSignalConversionAtMathFu[0] /
          rtb_TmpSignalConversionAtMathFu[2];
        rtb_Saturation1_i_idx_0 = rtb_TmpSignalConversionAtMathFu[1] /
          rtb_TmpSignalConversionAtMathFu[2];

        /* Sum: '<S199>/Sum of Elements' incorporates:
         *  Math: '<S199>/Math Function'
         *  SignalConversion: '<S199>/TmpSignal ConversionAtMath FunctionInport1'
         */
        dis = rtb_Saturation1_i_idx_0 * rtb_Saturation1_i_idx_0 +
          rtb_Switch_b_idx_3 * rtb_Switch_b_idx_3;

        /* Math: '<S199>/Math Function1' incorporates:
         *  Sum: '<S199>/Sum of Elements'
         *
         * About '<S199>/Math Function1':
         *  Operator: sqrt
         */
        if (dis < 0.0F) {
          rtb_Switch_b_idx_1 = -sqrtf(fabsf(dis));
        } else {
          rtb_Switch_b_idx_1 = sqrtf(dis);
        }

        /* End of Math: '<S199>/Math Function1' */

        /* Switch: '<S199>/Switch' incorporates:
         *  Constant: '<S199>/Constant'
         *  Product: '<S199>/Product'
         */
        if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_TmpSignalConversionAtMathFu[0] = rtb_Saturation1_i_idx_0;
          rtb_TmpSignalConversionAtMathFu[1] = rtb_Switch_b_idx_3;
          rtb_TmpSignalConversionAtMathFu[2] = rtb_Switch_b_idx_1;
        } else {
          rtb_TmpSignalConversionAtMathFu[0] = 0.0F;
          rtb_TmpSignalConversionAtMathFu[1] = 0.0F;
          rtb_TmpSignalConversionAtMathFu[2] = 1.0F;
        }

        /* End of Switch: '<S199>/Switch' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* MATLAB Function: '<S185>/NearbyRefWP' incorporates:
         *  Constant: '<S124>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_3 = FMS_B.Cmd_In.p_return[0] - FMS_U.INS_Out.x_R;
        rtb_Saturation1_i_idx_0 = FMS_B.Cmd_In.p_return[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        dis = sqrtf(rtb_Switch_b_idx_3 * rtb_Switch_b_idx_3 +
                    rtb_Saturation1_i_idx_0 * rtb_Saturation1_i_idx_0);
        if (dis <= 10.0F) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_Switch_b_idx_3 = FMS_B.Cmd_In.p_return[0];
          rtb_Saturation1_i_idx_0 = FMS_B.Cmd_In.p_return[1];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        } else {
          dis = -1.0F;
          rtb_Switch_b_idx_3 = 0.0F;
          rtb_Saturation1_i_idx_0 = 0.0F;
        }

        /* End of MATLAB Function: '<S185>/NearbyRefWP' */

        /* MATLAB Function: '<S185>/SearchL1RefWP' incorporates:
         *  Constant: '<S124>/L1'
         *  Delay: '<S170>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Switch_b_idx_1 = rtb_MathFunction_i_idx_0 * rtb_MathFunction_i_idx_0
          + rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        B = (rtb_MathFunction_i_idx_0 * (FMS_DW.Delay_DSTATE[0] -
              FMS_U.INS_Out.x_R) + rtb_Switch_h_idx_1 * (FMS_DW.Delay_DSTATE[1]
              - FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE[0] * FMS_DW.Delay_DSTATE[0]) +
                       FMS_DW.Delay_DSTATE[1] * FMS_DW.Delay_DSTATE[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE[1]) * 2.0F) -
                     100.0F) * (4.0F * rtb_Switch_b_idx_1);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_Switch_b_idx_0 = -1.0F;
        rtb_Integrator1_a = 0.0F;
        rtb_TmpSignalConversionAtSqua_0 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Switch_b_idx_1);
          rtb_Switch_b_idx_1 = (-B - u1_tmp) / (2.0F * rtb_Switch_b_idx_1);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Switch_b_idx_1 >= 0.0F) &&
              (rtb_Switch_b_idx_1 <= 1.0F)) {
            rtb_Switch_b_idx_0 = fmaxf(D, rtb_Switch_b_idx_1);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Switch_b_idx_0 = D;
            guard1 = true;
          } else {
            if ((rtb_Switch_b_idx_1 >= 0.0F) && (rtb_Switch_b_idx_1 <= 1.0F)) {
              rtb_Switch_b_idx_0 = rtb_Switch_b_idx_1;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Switch_b_idx_1);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Switch_b_idx_0 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_Integrator1_a = rtb_MathFunction_i_idx_0 * rtb_Switch_b_idx_0 +
            FMS_DW.Delay_DSTATE[0];
          rtb_TmpSignalConversionAtSqua_0 = rtb_Switch_h_idx_1 *
            rtb_Switch_b_idx_0 + FMS_DW.Delay_DSTATE[1];
        }

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* MATLAB Function: '<S185>/OutRegionRegWP' incorporates:
         *  Delay: '<S170>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE[1]) *
                              rtb_Switch_h_idx_1 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE[0]) * rtb_MathFunction_i_idx_0) /
          (rtb_MathFunction_i_idx_0 * rtb_MathFunction_i_idx_0 +
           rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_LogicalOperator_n = (rtb_Switch_b_idx_1 <= 0.0F);
        u = (rtb_Switch_b_idx_1 >= 1.0F);
        if (rtb_LogicalOperator_n) {
          rtb_MathFunction_i_idx_0 = FMS_DW.Delay_DSTATE[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          rtb_MathFunction_i_idx_0 = FMS_B.Cmd_In.p_return[0];

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        } else {
          rtb_MathFunction_i_idx_0 = rtb_Switch_b_idx_1 *
            rtb_MathFunction_i_idx_0 + FMS_DW.Delay_DSTATE[0];
        }

        /* Switch: '<S185>/Switch1' incorporates:
         *  Constant: '<S190>/Constant'
         *  RelationalOperator: '<S190>/Compare'
         */
        if (dis <= 0.0F) {
          /* Switch: '<S185>/Switch' incorporates:
           *  Constant: '<S189>/Constant'
           *  MATLAB Function: '<S185>/SearchL1RefWP'
           *  RelationalOperator: '<S189>/Compare'
           */
          if (rtb_Switch_b_idx_0 >= 0.0F) {
            rtb_Switch_b_idx_3 = rtb_Integrator1_a;
            rtb_Saturation1_i_idx_0 = rtb_TmpSignalConversionAtSqua_0;
          } else {
            rtb_Switch_b_idx_3 = rtb_MathFunction_i_idx_0;

            /* MATLAB Function: '<S185>/OutRegionRegWP' incorporates:
             *  Delay: '<S170>/Delay'
             *  SignalConversion: '<S3>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_LogicalOperator_n) {
              rtb_Saturation1_i_idx_0 = FMS_DW.Delay_DSTATE[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
              rtb_Saturation1_i_idx_0 = FMS_B.Cmd_In.p_return[1];

              /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            } else {
              rtb_Saturation1_i_idx_0 = rtb_Switch_b_idx_1 * rtb_Switch_h_idx_1
                + FMS_DW.Delay_DSTATE[1];
            }
          }

          /* End of Switch: '<S185>/Switch' */
        }

        /* End of Switch: '<S185>/Switch1' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S186>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Switch_h_idx_1 = rtb_Switch_b_idx_3 - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */
        rtb_Switch_b_idx_3 = rtb_Switch_h_idx_1;
        rtb_Switch_b_idx_0 = rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Sum: '<S186>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S197>/Math Function'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        rtb_Switch_h_idx_1 = rtb_Saturation1_i_idx_0 - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S197>/Sum of Elements' incorporates:
         *  Math: '<S197>/Math Function'
         */
        dis = rtb_Switch_h_idx_1 * rtb_Switch_h_idx_1 + rtb_Switch_b_idx_0;

        /* Math: '<S197>/Math Function1' incorporates:
         *  Sum: '<S197>/Sum of Elements'
         *
         * About '<S197>/Math Function1':
         *  Operator: sqrt
         */
        if (dis < 0.0F) {
          rtb_Switch_b_idx_1 = -sqrtf(fabsf(dis));
        } else {
          rtb_Switch_b_idx_1 = sqrtf(dis);
        }

        /* End of Math: '<S197>/Math Function1' */

        /* Switch: '<S197>/Switch' incorporates:
         *  Constant: '<S197>/Constant'
         *  Product: '<S197>/Product'
         */
        if (rtb_Switch_b_idx_1 <= 0.0F) {
          rtb_Switch_b_idx_3 = 0.0F;
          rtb_Switch_h_idx_1 = 0.0F;
          rtb_Switch_b_idx_1 = 1.0F;
        }

        /* End of Switch: '<S197>/Switch' */

        /* Product: '<S197>/Divide' */
        rtb_Integrator1_a = rtb_Switch_b_idx_3 / rtb_Switch_b_idx_1;
        rtb_TmpSignalConversionAtSqua_0 = rtb_Switch_h_idx_1 /
          rtb_Switch_b_idx_1;

        /* Sum: '<S200>/Sum of Elements' incorporates:
         *  Math: '<S200>/Math Function'
         *  SignalConversion: '<S200>/TmpSignal ConversionAtMath FunctionInport1'
         */
        dis = rtb_TmpSignalConversionAtSqua_0 * rtb_TmpSignalConversionAtSqua_0
          + rtb_Integrator1_a * rtb_Integrator1_a;

        /* Math: '<S200>/Math Function1' incorporates:
         *  Sum: '<S200>/Sum of Elements'
         *
         * About '<S200>/Math Function1':
         *  Operator: sqrt
         */
        if (dis < 0.0F) {
          rtb_Switch_b_idx_1 = -sqrtf(fabsf(dis));
        } else {
          rtb_Switch_b_idx_1 = sqrtf(dis);
        }

        /* End of Math: '<S200>/Math Function1' */

        /* Switch: '<S200>/Switch' incorporates:
         *  Constant: '<S200>/Constant'
         *  Product: '<S200>/Product'
         */
        if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_Switch_b_idx_3 = rtb_TmpSignalConversionAtSqua_0;
          rtb_Switch_h_idx_1 = rtb_Integrator1_a;
        } else {
          rtb_Switch_b_idx_3 = 0.0F;
          rtb_Switch_h_idx_1 = 0.0F;
          rtb_Switch_b_idx_1 = 1.0F;
        }

        /* End of Switch: '<S200>/Switch' */

        /* Product: '<S200>/Divide' */
        rtb_Integrator1_a = rtb_Switch_b_idx_3 / rtb_Switch_b_idx_1;

        /* Product: '<S199>/Divide' */
        rtb_Switch_b_idx_3 = rtb_TmpSignalConversionAtMathFu[0] /
          rtb_TmpSignalConversionAtMathFu[2];

        /* Product: '<S183>/Divide' */
        rtb_Switch_b_idx_0 = rtb_MathFunction_idx_0 / rtb_MathFunction_idx_2;

        /* Product: '<S200>/Divide' */
        rtb_TmpSignalConversionAtSqua_0 = rtb_Switch_h_idx_1 /
          rtb_Switch_b_idx_1;

        /* Product: '<S199>/Divide' */
        rtb_Saturation1_i_idx_0 = rtb_TmpSignalConversionAtMathFu[1] /
          rtb_TmpSignalConversionAtMathFu[2];

        /* Product: '<S183>/Divide' */
        dis = rtb_MathFunction_idx_1 / rtb_MathFunction_idx_2;

        /* Sqrt: '<S195>/Sqrt' */
        rtb_Switch_b_idx_1 = sqrtf(tmp);

        /* Math: '<S186>/Square' */
        rtb_Switch_h_idx_1 = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1;

        /* Sum: '<S198>/Subtract' incorporates:
         *  Product: '<S198>/Multiply'
         *  Product: '<S198>/Multiply1'
         */
        rtb_Switch_b_idx_1 = rtb_Integrator1_a * rtb_Saturation1_i_idx_0 -
          rtb_TmpSignalConversionAtSqua_0 * rtb_Switch_b_idx_3;

        /* Signum: '<S194>/Sign1' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_1 > 0.0F) {
            rtb_Switch_b_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S194>/Sign1' */

        /* Switch: '<S194>/Switch2' incorporates:
         *  Constant: '<S194>/Constant4'
         */
        if (rtb_Switch_b_idx_1 == 0.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        }

        /* End of Switch: '<S194>/Switch2' */

        /* DotProduct: '<S194>/Dot Product' */
        rtb_MathFunction_i_idx_0 = rtb_Switch_b_idx_3 * rtb_Integrator1_a +
          rtb_Saturation1_i_idx_0 * rtb_TmpSignalConversionAtSqua_0;

        /* Trigonometry: '<S194>/Acos' incorporates:
         *  DotProduct: '<S194>/Dot Product'
         */
        if (rtb_MathFunction_i_idx_0 > 1.0F) {
          rtb_MathFunction_i_idx_0 = 1.0F;
        } else {
          if (rtb_MathFunction_i_idx_0 < -1.0F) {
            rtb_MathFunction_i_idx_0 = -1.0F;
          }
        }

        /* Product: '<S194>/Multiply' incorporates:
         *  Trigonometry: '<S194>/Acos'
         */
        rtb_Switch_b_idx_1 *= acosf(rtb_MathFunction_i_idx_0);

        /* Saturate: '<S186>/Saturation' */
        if (rtb_Switch_b_idx_1 > 1.57079637F) {
          rtb_Switch_b_idx_1 = 1.57079637F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.57079637F) {
            rtb_Switch_b_idx_1 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S186>/Saturation' */

        /* Product: '<S187>/Divide1' incorporates:
         *  Constant: '<S124>/L1'
         *  Gain: '<S186>/Gain'
         *  Product: '<S186>/Divide'
         *  Product: '<S186>/Multiply1'
         *  Trigonometry: '<S186>/Sin'
         */
        rtb_Switch_h_idx_1 = 2.0F * rtb_Switch_h_idx_1 * arm_sin_f32
          (rtb_Switch_b_idx_1) / 10.0F / rtb_a_b;

        /* Sum: '<S181>/Subtract' incorporates:
         *  Product: '<S181>/Multiply'
         *  Product: '<S181>/Multiply1'
         */
        rtb_a_b = rtb_Switch_b_idx_0 * FMS_ConstB.Divide[1] - dis *
          FMS_ConstB.Divide[0];

        /* Signum: '<S174>/Sign1' */
        if (rtb_a_b < 0.0F) {
          rtb_a_b = -1.0F;
        } else {
          if (rtb_a_b > 0.0F) {
            rtb_a_b = 1.0F;
          }
        }

        /* End of Signum: '<S174>/Sign1' */

        /* Switch: '<S174>/Switch2' incorporates:
         *  Constant: '<S174>/Constant4'
         */
        if (rtb_a_b == 0.0F) {
          rtb_a_b = 1.0F;
        }

        /* End of Switch: '<S174>/Switch2' */

        /* DotProduct: '<S174>/Dot Product' */
        rtb_Switch_b_idx_0 = FMS_ConstB.Divide[0] * rtb_Switch_b_idx_0 +
          FMS_ConstB.Divide[1] * dis;

        /* Trigonometry: '<S174>/Acos' incorporates:
         *  DotProduct: '<S174>/Dot Product'
         */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < -1.0F) {
            rtb_Switch_b_idx_0 = -1.0F;
          }
        }

        /* Sum: '<S180>/Add' incorporates:
         *  DiscreteIntegrator: '<S176>/Integrator'
         *  DiscreteIntegrator: '<S176>/Integrator1'
         *  Product: '<S174>/Multiply'
         *  Sum: '<S176>/Subtract'
         *  Trigonometry: '<S174>/Acos'
         */
        rtb_Switch_b_idx_1 = (FMS_DW.Integrator1_DSTATE_e - acosf
                              (rtb_Switch_b_idx_0) * rtb_a_b) +
          FMS_DW.Integrator_DSTATE_bs;

        /* Signum: '<S180>/Sign' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          rtb_Switch_b_idx_0 = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S180>/Sign' */

        /* Sum: '<S180>/Add2' incorporates:
         *  Abs: '<S180>/Abs'
         *  DiscreteIntegrator: '<S176>/Integrator'
         *  Gain: '<S180>/Gain'
         *  Gain: '<S180>/Gain1'
         *  Product: '<S180>/Multiply2'
         *  Product: '<S180>/Multiply3'
         *  Sqrt: '<S180>/Sqrt'
         *  Sum: '<S180>/Add1'
         *  Sum: '<S180>/Subtract'
         */
        rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Switch_b_idx_1) + FMS_ConstB.d_l) *
                         FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Switch_b_idx_0 + FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S180>/Add4' incorporates:
         *  DiscreteIntegrator: '<S176>/Integrator'
         */
        dis = (rtb_Switch_b_idx_1 - rtb_a_b) + FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S180>/Add3' */
        rtb_Switch_b_idx_0 = rtb_Switch_b_idx_1 + FMS_ConstB.d_l;

        /* Sum: '<S180>/Subtract1' */
        rtb_Switch_b_idx_1 -= FMS_ConstB.d_l;

        /* Signum: '<S180>/Sign1' */
        if (rtb_Switch_b_idx_0 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S180>/Sign1' */

        /* Signum: '<S180>/Sign2' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_1 > 0.0F) {
            rtb_Switch_b_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S180>/Sign2' */

        /* Sum: '<S180>/Add5' incorporates:
         *  Gain: '<S180>/Gain2'
         *  Product: '<S180>/Multiply4'
         *  Sum: '<S180>/Subtract2'
         */
        rtb_a_b += (rtb_Switch_b_idx_0 - rtb_Switch_b_idx_1) * 0.5F * dis;

        /* Update for Delay: '<S170>/Delay' */
        FMS_DW.icLoad = 0U;

        /* Update for DiscreteIntegrator: '<S202>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Switch_h_idx_1;

        /* Update for DiscreteIntegrator: '<S176>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S176>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Sum: '<S180>/Add6' */
        rtb_Switch_b_idx_0 = rtb_a_b + FMS_ConstB.d_l;

        /* Sum: '<S180>/Subtract3' */
        rtb_Switch_b_idx_1 = rtb_a_b - FMS_ConstB.d_l;

        /* Signum: '<S180>/Sign5' */
        if (rtb_a_b < 0.0F) {
          dis = -1.0F;
        } else if (rtb_a_b > 0.0F) {
          dis = 1.0F;
        } else {
          dis = rtb_a_b;
        }

        /* End of Signum: '<S180>/Sign5' */

        /* Signum: '<S180>/Sign3' */
        if (rtb_Switch_b_idx_0 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S180>/Sign3' */

        /* Signum: '<S180>/Sign4' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_1 > 0.0F) {
            rtb_Switch_b_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S180>/Sign4' */

        /* Signum: '<S180>/Sign6' */
        if (rtb_a_b < 0.0F) {
          rtb_Switch_h_idx_1 = -1.0F;
        } else if (rtb_a_b > 0.0F) {
          rtb_Switch_h_idx_1 = 1.0F;
        } else {
          rtb_Switch_h_idx_1 = rtb_a_b;
        }

        /* End of Signum: '<S180>/Sign6' */

        /* Update for DiscreteIntegrator: '<S176>/Integrator' incorporates:
         *  Constant: '<S180>/const'
         *  Gain: '<S180>/Gain3'
         *  Product: '<S180>/Divide'
         *  Product: '<S180>/Multiply5'
         *  Product: '<S180>/Multiply6'
         *  Sum: '<S180>/Subtract4'
         *  Sum: '<S180>/Subtract5'
         *  Sum: '<S180>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_a_b / FMS_ConstB.d_l - dis) *
          FMS_ConstB.Gain4_np * ((rtb_Switch_b_idx_0 - rtb_Switch_b_idx_1) *
          0.5F) - rtb_Switch_h_idx_1 * 0.785398185F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S176>/Integrator' */
        /* End of Outputs for SubSystem: '<S13>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S13>/Hold' incorporates:
           *  ActionPort: '<S122>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S13>/Switch Case' incorporates:
           *  Chart: '<S131>/Motion Status'
           *  Chart: '<S141>/Motion State'
           *  Chart: '<S153>/Motion State'
           */
          FMS_DW.temporalCounter_i1_n = 0U;
          FMS_DW.is_active_c14_FMS = 0U;
          FMS_DW.is_c14_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.temporalCounter_i1_ai = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c22_FMS = 0U;
          FMS_DW.is_c22_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

          /* End of SystemReset for SubSystem: '<S13>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S13>/Hold' incorporates:
         *  ActionPort: '<S122>/Action Port'
         */
        /* Chart: '<S131>/Motion Status' incorporates:
         *  Abs: '<S131>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.temporalCounter_i1_n < 511U) {
          FMS_DW.temporalCounter_i1_n++;
        }

        if (FMS_DW.is_active_c14_FMS == 0U) {
          FMS_DW.is_active_c14_FMS = 1U;
          FMS_DW.is_c14_FMS = FMS_IN_Move_j;
          rtb_state_di = MotionState_Move;
        } else {
          switch (FMS_DW.is_c14_FMS) {
           case FMS_IN_Brake_p:
            rtb_state_di = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
            if ((fabsf(FMS_U.INS_Out.vd) <= 0.15) ||
                (FMS_DW.temporalCounter_i1_n >= 375U)) {
              FMS_DW.is_c14_FMS = FMS_IN_Hold_a;
              rtb_state_di = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            break;

           case FMS_IN_Hold_a:
            rtb_state_di = MotionState_Hold;
            break;

           default:
            FMS_DW.is_c14_FMS = FMS_IN_Brake_p;
            FMS_DW.temporalCounter_i1_n = 0U;
            rtb_state_di = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S131>/Motion Status' */

        /* Chart: '<S141>/Motion State' incorporates:
         *  Abs: '<S141>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S3>/Signal Copy1'
         */
        if (FMS_DW.temporalCounter_i1_ai < 255U) {
          FMS_DW.temporalCounter_i1_ai++;
        }

        if (FMS_DW.is_active_c15_FMS == 0U) {
          FMS_DW.is_active_c15_FMS = 1U;
          FMS_DW.is_c15_FMS = FMS_IN_Move_j;
          rtb_state_dm = MotionState_Move;
        } else {
          switch (FMS_DW.is_c15_FMS) {
           case FMS_IN_Brake_p:
            rtb_state_dm = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
            if ((fabsf(FMS_U.INS_Out.r) <= 0.1) || (FMS_DW.temporalCounter_i1_ai
                 >= 250U)) {
              FMS_DW.is_c15_FMS = FMS_IN_Hold_a;
              rtb_state_dm = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            break;

           case FMS_IN_Hold_a:
            rtb_state_dm = MotionState_Hold;
            break;

           default:
            FMS_DW.is_c15_FMS = FMS_IN_Brake_p;
            FMS_DW.temporalCounter_i1_ai = 0U;
            rtb_state_dm = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S141>/Motion State' */

        /* Chart: '<S153>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S153>/Square'
         *  Math: '<S153>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S153>/Sqrt'
         *  Sum: '<S153>/Add'
         */
        if (FMS_DW.temporalCounter_i1_a < 1023U) {
          FMS_DW.temporalCounter_i1_a++;
        }

        if (FMS_DW.is_active_c22_FMS == 0U) {
          FMS_DW.is_active_c22_FMS = 1U;
          FMS_DW.is_c22_FMS = FMS_IN_Move_j;
          rtb_state_m2 = MotionState_Move;
        } else {
          switch (FMS_DW.is_c22_FMS) {
           case FMS_IN_Brake_p:
            rtb_state_m2 = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_a
                 >= 625U)) {
              FMS_DW.is_c22_FMS = FMS_IN_Hold_a;
              rtb_state_m2 = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            break;

           case FMS_IN_Hold_a:
            rtb_state_m2 = MotionState_Hold;
            break;

           default:
            FMS_DW.is_c22_FMS = FMS_IN_Brake_p;
            FMS_DW.temporalCounter_i1_a = 0U;
            rtb_state_m2 = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S153>/Motion State' */

        /* SwitchCase: '<S152>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_p;
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
        switch (rtb_state_m2) {
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
            /* SystemReset for IfAction SubSystem: '<S152>/Hold Control' incorporates:
             *  ActionPort: '<S155>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S152>/Switch Case' */
            FMS_HoldControl_n_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S152>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S152>/Hold Control' incorporates:
           *  ActionPort: '<S155>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_f(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S152>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S152>/Brake Control' incorporates:
           *  ActionPort: '<S154>/Action Port'
           */
          FMS_BrakeControl_b(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S152>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S152>/Move Control' incorporates:
             *  ActionPort: '<S156>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S152>/Switch Case' */
            FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S152>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S152>/Move Control' incorporates:
           *  ActionPort: '<S156>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_i(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S152>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S152>/Switch Case' */

        /* SwitchCase: '<S130>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_pp;
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;
        switch (rtb_state_di) {
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
            /* SystemReset for IfAction SubSystem: '<S130>/Hold Control' incorporates:
             *  ActionPort: '<S133>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S130>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S130>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S130>/Hold Control' incorporates:
           *  ActionPort: '<S133>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e, &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S130>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S130>/Brake Control' incorporates:
           *  ActionPort: '<S132>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e);

          /* End of Outputs for SubSystem: '<S130>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S130>/Move Control' incorporates:
             *  ActionPort: '<S134>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S130>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S130>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S130>/Move Control' incorporates:
           *  ActionPort: '<S134>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S130>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S130>/Switch Case' */

        /* SwitchCase: '<S140>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_bn;
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        switch (rtb_state_dm) {
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
            /* SystemReset for IfAction SubSystem: '<S140>/Hold Control' incorporates:
             *  ActionPort: '<S143>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S140>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S140>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S140>/Hold Control' incorporates:
           *  ActionPort: '<S143>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S140>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S140>/Brake Control' incorporates:
           *  ActionPort: '<S142>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S140>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S140>/Move Control' incorporates:
             *  ActionPort: '<S144>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S140>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S140>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S140>/Move Control' incorporates:
           *  ActionPort: '<S144>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S140>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S140>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S122>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S122>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S122>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S140>/Saturation' */
        if (FMS_B.Merge_n > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n;
        }

        /* End of Saturate: '<S140>/Saturation' */

        /* Saturate: '<S152>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S152>/Saturation1' */

        /* Saturate: '<S130>/Saturation1' */
        if (FMS_B.Merge_e > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_e < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S122>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_e;
        }

        /* End of Saturate: '<S130>/Saturation1' */
        /* End of Outputs for SubSystem: '<S13>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S13>/Unknown' incorporates:
         *  ActionPort: '<S126>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S13>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S13>/Switch Case' */
      /* End of Outputs for SubSystem: '<S6>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S6>/Auto' incorporates:
       *  ActionPort: '<S11>/Action Port'
       */
      /* SwitchCase: '<S11>/Switch Case' */
      switch (FMS_B.VehicleMode_e) {
       case VehicleMode_Offboard:
        /* Outputs for IfAction SubSystem: '<S11>/Offboard' incorporates:
         *  ActionPort: '<S120>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S120>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S120>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S120>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_n;

        /* End of Outputs for SubSystem: '<S11>/Offboard' */
        break;

       case VehicleMode_Mission:
        /* Outputs for IfAction SubSystem: '<S11>/Mission' incorporates:
         *  ActionPort: '<S119>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S119>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S119>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S119>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_b;

        /* End of Outputs for SubSystem: '<S11>/Mission' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S11>/Unknown' incorporates:
         *  ActionPort: '<S121>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S11>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S11>/Switch Case' */
      /* End of Outputs for SubSystem: '<S6>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S6>/Assist' incorporates:
       *  ActionPort: '<S10>/Action Port'
       */
      /* SwitchCase: '<S10>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;
      switch (FMS_B.VehicleMode_e) {
       case VehicleMode_Acro:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
        break;

       case VehicleMode_Stabilize:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
        break;

       case VehicleMode_Altitude:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
        break;

       case VehicleMode_Position:
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
          /* Disable for SwitchCase: '<S106>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S25>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S42>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S82>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S58>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

          /* Disable for SwitchCase: '<S69>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S10>/Acro' incorporates:
         *  ActionPort: '<S15>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S15>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S15>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S15>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Gain: '<S20>/Gain'
         *  Gain: '<S20>/Gain1'
         *  Gain: '<S20>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S21>/Saturation' incorporates:
         *  Constant: '<S21>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         *  Sum: '<S21>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          dis = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          dis = 0.0F;
        } else {
          dis = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S21>/Saturation' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* BusAssignment: '<S15>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S21>/Constant5'
         *  Gain: '<S21>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S21>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F * dis),
          4.2949673E+9F) + 1000U;

        /* End of Outputs for SubSystem: '<S10>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S10>/Stabilize' incorporates:
           *  ActionPort: '<S18>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S10>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S102>/Integrator'
           *  DiscreteIntegrator: '<S102>/Integrator1'
           *  DiscreteIntegrator: '<S103>/Integrator'
           *  DiscreteIntegrator: '<S103>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_jt = 0.0F;
          FMS_DW.Integrator_DSTATE_cq = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S10>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S10>/Stabilize' incorporates:
           *  ActionPort: '<S18>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S10>/Switch Case' incorporates:
           *  Chart: '<S107>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S10>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S10>/Stabilize' incorporates:
         *  ActionPort: '<S18>/Action Port'
         */
        /* Product: '<S104>/Multiply1' incorporates:
         *  Constant: '<S104>/const1'
         *  DiscreteIntegrator: '<S102>/Integrator'
         */
        rtb_Switch_b_idx_1 = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S100>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          dis = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          dis = 0.0F;
        } else {
          dis = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S100>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S104>/Add' incorporates:
         *  DiscreteIntegrator: '<S102>/Integrator1'
         *  Gain: '<S100>/Gain'
         *  Gain: '<S97>/Gain'
         *  Sum: '<S102>/Subtract'
         */
        rtb_Switch_h_idx_1 = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
          FMS_PARAM.ROLL_DZ) * dis * FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Switch_b_idx_1;

        /* Signum: '<S104>/Sign' */
        if (rtb_Switch_h_idx_1 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else if (rtb_Switch_h_idx_1 > 0.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          rtb_Switch_b_idx_0 = rtb_Switch_h_idx_1;
        }

        /* End of Signum: '<S104>/Sign' */

        /* Sum: '<S104>/Add2' incorporates:
         *  Abs: '<S104>/Abs'
         *  Gain: '<S104>/Gain'
         *  Gain: '<S104>/Gain1'
         *  Product: '<S104>/Multiply2'
         *  Product: '<S104>/Multiply3'
         *  Sqrt: '<S104>/Sqrt'
         *  Sum: '<S104>/Add1'
         *  Sum: '<S104>/Subtract'
         */
        rtb_a_b = (sqrtf((8.0F * fabsf(rtb_Switch_h_idx_1) + FMS_ConstB.d_d) *
                         FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1;

        /* Sum: '<S104>/Add4' */
        rtb_Switch_b_idx_1 += rtb_Switch_h_idx_1 - rtb_a_b;

        /* Sum: '<S104>/Add3' */
        rtb_Switch_b_idx_0 = rtb_Switch_h_idx_1 + FMS_ConstB.d_d;

        /* Sum: '<S104>/Subtract1' */
        rtb_Switch_h_idx_1 -= FMS_ConstB.d_d;

        /* Signum: '<S104>/Sign1' */
        if (rtb_Switch_b_idx_0 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S104>/Sign1' */

        /* Signum: '<S104>/Sign2' */
        if (rtb_Switch_h_idx_1 < 0.0F) {
          rtb_Switch_h_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_h_idx_1 > 0.0F) {
            rtb_Switch_h_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S104>/Sign2' */

        /* Sum: '<S104>/Add5' incorporates:
         *  Gain: '<S104>/Gain2'
         *  Product: '<S104>/Multiply4'
         *  Sum: '<S104>/Subtract2'
         */
        rtb_a_b += (rtb_Switch_b_idx_0 - rtb_Switch_h_idx_1) * 0.5F *
          rtb_Switch_b_idx_1;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S107>/Motion State' incorporates:
         *  Abs: '<S107>/Abs'
         *  Abs: '<S107>/Abs1'
         *  Constant: '<S117>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S117>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                        fabsf(FMS_U.INS_Out.r), &rtb_state_di,
                        &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S106>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_fs;
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        switch (rtb_state_di) {
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
            /* SystemReset for IfAction SubSystem: '<S106>/Hold Control' incorporates:
             *  ActionPort: '<S109>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S106>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S106>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S106>/Hold Control' incorporates:
           *  ActionPort: '<S109>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S106>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S106>/Brake Control' incorporates:
           *  ActionPort: '<S108>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_j);

          /* End of Outputs for SubSystem: '<S106>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S106>/Move Control' incorporates:
             *  ActionPort: '<S110>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S106>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S106>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S106>/Move Control' incorporates:
           *  ActionPort: '<S110>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S106>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S106>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S18>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S18>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  DiscreteIntegrator: '<S102>/Integrator1'
         *  DiscreteIntegrator: '<S103>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_j;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_jt;

        /* Saturate: '<S106>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S18>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S18>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S18>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S106>/Saturation' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Saturate: '<S99>/Saturation' incorporates:
         *  Constant: '<S99>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         *  Sum: '<S99>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          dis = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          dis = 0.0F;
        } else {
          dis = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S99>/Saturation' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* BusAssignment: '<S18>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S99>/Constant5'
         *  Gain: '<S99>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S99>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F * dis),
          4.2949673E+9F) + 1000U;

        /* Product: '<S105>/Multiply1' incorporates:
         *  Constant: '<S105>/const1'
         *  DiscreteIntegrator: '<S103>/Integrator'
         */
        rtb_Switch_h_idx_1 = FMS_DW.Integrator_DSTATE_cq * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S101>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          dis = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          dis = 0.0F;
        } else {
          dis = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S101>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S105>/Add' incorporates:
         *  DiscreteIntegrator: '<S103>/Integrator1'
         *  Gain: '<S101>/Gain'
         *  Gain: '<S97>/Gain1'
         *  Sum: '<S103>/Subtract'
         */
        rtb_Switch_b_idx_1 = (FMS_DW.Integrator1_DSTATE_jt - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * dis * -FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_Switch_h_idx_1;

        /* Signum: '<S105>/Sign' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else if (rtb_Switch_b_idx_1 > 0.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          rtb_Switch_b_idx_0 = rtb_Switch_b_idx_1;
        }

        /* End of Signum: '<S105>/Sign' */

        /* Sum: '<S105>/Add2' incorporates:
         *  Abs: '<S105>/Abs'
         *  Gain: '<S105>/Gain'
         *  Gain: '<S105>/Gain1'
         *  Product: '<S105>/Multiply2'
         *  Product: '<S105>/Multiply3'
         *  Sqrt: '<S105>/Sqrt'
         *  Sum: '<S105>/Add1'
         *  Sum: '<S105>/Subtract'
         */
        dis = (sqrtf((8.0F * fabsf(rtb_Switch_b_idx_1) + FMS_ConstB.d_o) *
                     FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
          rtb_Switch_b_idx_0 + rtb_Switch_h_idx_1;

        /* Sum: '<S105>/Add4' */
        rtb_Switch_h_idx_1 += rtb_Switch_b_idx_1 - dis;

        /* Sum: '<S105>/Add3' */
        rtb_Switch_b_idx_0 = rtb_Switch_b_idx_1 + FMS_ConstB.d_o;

        /* Sum: '<S105>/Subtract1' */
        rtb_Switch_b_idx_1 -= FMS_ConstB.d_o;

        /* Signum: '<S105>/Sign1' */
        if (rtb_Switch_b_idx_0 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S105>/Sign1' */

        /* Signum: '<S105>/Sign2' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_1 > 0.0F) {
            rtb_Switch_b_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S105>/Sign2' */

        /* Sum: '<S105>/Add5' incorporates:
         *  Gain: '<S105>/Gain2'
         *  Product: '<S105>/Multiply4'
         *  Sum: '<S105>/Subtract2'
         */
        dis += (rtb_Switch_b_idx_0 - rtb_Switch_b_idx_1) * 0.5F *
          rtb_Switch_h_idx_1;

        /* Update for DiscreteIntegrator: '<S102>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S102>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Sum: '<S104>/Add6' */
        rtb_Switch_b_idx_0 = rtb_a_b + FMS_ConstB.d_d;

        /* Sum: '<S104>/Subtract3' */
        rtb_Switch_b_idx_1 = rtb_a_b - FMS_ConstB.d_d;

        /* Signum: '<S104>/Sign5' */
        if (rtb_a_b < 0.0F) {
          rtb_Switch_h_idx_1 = -1.0F;
        } else if (rtb_a_b > 0.0F) {
          rtb_Switch_h_idx_1 = 1.0F;
        } else {
          rtb_Switch_h_idx_1 = rtb_a_b;
        }

        /* End of Signum: '<S104>/Sign5' */

        /* Signum: '<S104>/Sign3' */
        if (rtb_Switch_b_idx_0 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S104>/Sign3' */

        /* Signum: '<S104>/Sign4' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_1 > 0.0F) {
            rtb_Switch_b_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S104>/Sign4' */

        /* Signum: '<S104>/Sign6' */
        if (rtb_a_b < 0.0F) {
          rtb_MathFunction_i_idx_0 = -1.0F;
        } else if (rtb_a_b > 0.0F) {
          rtb_MathFunction_i_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_i_idx_0 = rtb_a_b;
        }

        /* End of Signum: '<S104>/Sign6' */

        /* Update for DiscreteIntegrator: '<S102>/Integrator' incorporates:
         *  Constant: '<S104>/const'
         *  Gain: '<S104>/Gain3'
         *  Product: '<S104>/Divide'
         *  Product: '<S104>/Multiply5'
         *  Product: '<S104>/Multiply6'
         *  Sum: '<S104>/Subtract4'
         *  Sum: '<S104>/Subtract5'
         *  Sum: '<S104>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += ((rtb_a_b / FMS_ConstB.d_d -
          rtb_Switch_h_idx_1) * FMS_ConstB.Gain4_n * ((rtb_Switch_b_idx_0 -
          rtb_Switch_b_idx_1) * 0.5F) - rtb_MathFunction_i_idx_0 * 12.566371F) *
          0.004F;

        /* Update for DiscreteIntegrator: '<S103>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S103>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_jt += 0.004F * FMS_DW.Integrator_DSTATE_cq;

        /* Sum: '<S105>/Add6' */
        rtb_Switch_b_idx_0 = dis + FMS_ConstB.d_o;

        /* Sum: '<S105>/Subtract3' */
        rtb_Switch_b_idx_1 = dis - FMS_ConstB.d_o;

        /* Signum: '<S105>/Sign5' */
        if (dis < 0.0F) {
          rtb_a_b = -1.0F;
        } else if (dis > 0.0F) {
          rtb_a_b = 1.0F;
        } else {
          rtb_a_b = dis;
        }

        /* End of Signum: '<S105>/Sign5' */

        /* Signum: '<S105>/Sign3' */
        if (rtb_Switch_b_idx_0 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S105>/Sign3' */

        /* Signum: '<S105>/Sign4' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_1 > 0.0F) {
            rtb_Switch_b_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S105>/Sign4' */

        /* Signum: '<S105>/Sign6' */
        if (dis < 0.0F) {
          rtb_Switch_h_idx_1 = -1.0F;
        } else if (dis > 0.0F) {
          rtb_Switch_h_idx_1 = 1.0F;
        } else {
          rtb_Switch_h_idx_1 = dis;
        }

        /* End of Signum: '<S105>/Sign6' */

        /* Update for DiscreteIntegrator: '<S103>/Integrator' incorporates:
         *  Constant: '<S105>/const'
         *  Gain: '<S105>/Gain3'
         *  Product: '<S105>/Divide'
         *  Product: '<S105>/Multiply5'
         *  Product: '<S105>/Multiply6'
         *  Sum: '<S105>/Subtract4'
         *  Sum: '<S105>/Subtract5'
         *  Sum: '<S105>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_cq += ((dis / FMS_ConstB.d_o - rtb_a_b) *
          FMS_ConstB.Gain4_n3 * ((rtb_Switch_b_idx_0 - rtb_Switch_b_idx_1) *
          0.5F) - rtb_Switch_h_idx_1 * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S10>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S10>/Altitude' incorporates:
           *  ActionPort: '<S16>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S10>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S38>/Integrator'
           *  DiscreteIntegrator: '<S38>/Integrator1'
           *  DiscreteIntegrator: '<S39>/Integrator'
           *  DiscreteIntegrator: '<S39>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE = 0.0F;
          FMS_DW.Integrator_DSTATE = 0.0F;
          FMS_DW.Integrator1_DSTATE_o = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S10>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S10>/Altitude' incorporates:
           *  ActionPort: '<S16>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S10>/Switch Case' incorporates:
           *  Chart: '<S26>/Motion Status'
           *  Chart: '<S43>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S10>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S10>/Altitude' incorporates:
         *  ActionPort: '<S16>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S26>/Motion Status' incorporates:
         *  Abs: '<S26>/Abs'
         *  Abs: '<S26>/Abs1'
         *  Constant: '<S34>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S34>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                         FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                         &rtb_state_di, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S25>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_m;
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        switch (rtb_state_di) {
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
            /* SystemReset for IfAction SubSystem: '<S25>/Hold Control' incorporates:
             *  ActionPort: '<S28>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S25>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S25>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S25>/Hold Control' incorporates:
           *  ActionPort: '<S28>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S25>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S25>/Brake Control' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S25>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_m != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S25>/Move Control' incorporates:
             *  ActionPort: '<S29>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S25>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

            /* End of SystemReset for SubSystem: '<S25>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S25>/Move Control' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_l,
                          &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S25>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S25>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S43>/Motion State' incorporates:
         *  Abs: '<S43>/Abs'
         *  Abs: '<S43>/Abs1'
         *  Constant: '<S53>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S53>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                        fabsf(FMS_U.INS_Out.r), &rtb_state_di,
                        &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* SwitchCase: '<S42>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_h;
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        switch (rtb_state_di) {
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
            /* SystemReset for IfAction SubSystem: '<S42>/Hold Control' incorporates:
             *  ActionPort: '<S45>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S42>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_o);

            /* End of SystemReset for SubSystem: '<S42>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S42>/Hold Control' incorporates:
           *  ActionPort: '<S45>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_m,
                            &FMS_DW.HoldControl_o);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S42>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S42>/Brake Control' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_m);

          /* End of Outputs for SubSystem: '<S42>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S42>/Move Control' incorporates:
             *  ActionPort: '<S46>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S42>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S42>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S42>/Move Control' incorporates:
           *  ActionPort: '<S46>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_m,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S42>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S42>/Switch Case' */

        /* Product: '<S40>/Multiply1' incorporates:
         *  Constant: '<S40>/const1'
         *  DiscreteIntegrator: '<S38>/Integrator'
         */
        rtb_Switch_h_idx_1 = FMS_DW.Integrator_DSTATE * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S36>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          dis = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          dis = 0.0F;
        } else {
          dis = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S36>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S40>/Add' incorporates:
         *  DiscreteIntegrator: '<S38>/Integrator1'
         *  Gain: '<S23>/Gain'
         *  Gain: '<S36>/Gain'
         *  Sum: '<S38>/Subtract'
         */
        rtb_a_b = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F - FMS_PARAM.ROLL_DZ)
                   * dis * FMS_PARAM.ROLL_PITCH_LIM) + rtb_Switch_h_idx_1;

        /* Signum: '<S40>/Sign' */
        if (rtb_a_b < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else if (rtb_a_b > 0.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          rtb_Switch_b_idx_0 = rtb_a_b;
        }

        /* End of Signum: '<S40>/Sign' */

        /* Sum: '<S40>/Add2' incorporates:
         *  Abs: '<S40>/Abs'
         *  Gain: '<S40>/Gain'
         *  Gain: '<S40>/Gain1'
         *  Product: '<S40>/Multiply2'
         *  Product: '<S40>/Multiply3'
         *  Sqrt: '<S40>/Sqrt'
         *  Sum: '<S40>/Add1'
         *  Sum: '<S40>/Subtract'
         */
        rtb_MathFunction_i_idx_0 = (sqrtf((8.0F * fabsf(rtb_a_b) + FMS_ConstB.d)
          * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Switch_b_idx_0 +
          rtb_Switch_h_idx_1;

        /* Sum: '<S40>/Add4' */
        rtb_Switch_b_idx_1 = (rtb_a_b - rtb_MathFunction_i_idx_0) +
          rtb_Switch_h_idx_1;

        /* Sum: '<S40>/Add3' */
        rtb_Switch_b_idx_0 = rtb_a_b + FMS_ConstB.d;

        /* Sum: '<S40>/Subtract1' */
        rtb_a_b -= FMS_ConstB.d;

        /* Signum: '<S40>/Sign1' */
        if (rtb_Switch_b_idx_0 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S40>/Sign1' */

        /* Signum: '<S40>/Sign2' */
        if (rtb_a_b < 0.0F) {
          rtb_a_b = -1.0F;
        } else {
          if (rtb_a_b > 0.0F) {
            rtb_a_b = 1.0F;
          }
        }

        /* End of Signum: '<S40>/Sign2' */

        /* Sum: '<S40>/Add5' incorporates:
         *  Gain: '<S40>/Gain2'
         *  Product: '<S40>/Multiply4'
         *  Sum: '<S40>/Subtract2'
         */
        rtb_MathFunction_i_idx_0 += (rtb_Switch_b_idx_0 - rtb_a_b) * 0.5F *
          rtb_Switch_b_idx_1;

        /* Sum: '<S40>/Subtract3' */
        rtb_Switch_b_idx_0 = rtb_MathFunction_i_idx_0 - FMS_ConstB.d;

        /* Sum: '<S40>/Add6' */
        rtb_Switch_b_idx_1 = rtb_MathFunction_i_idx_0 + FMS_ConstB.d;

        /* Product: '<S40>/Divide' */
        rtb_Switch_b_idx_3 = rtb_MathFunction_i_idx_0 / FMS_ConstB.d;

        /* Signum: '<S40>/Sign5' incorporates:
         *  Signum: '<S40>/Sign6'
         */
        if (rtb_MathFunction_i_idx_0 < 0.0F) {
          rtb_Saturation1_i_idx_0 = -1.0F;
          rtb_a_b = -1.0F;
        } else if (rtb_MathFunction_i_idx_0 > 0.0F) {
          rtb_Saturation1_i_idx_0 = 1.0F;
          rtb_a_b = 1.0F;
        } else {
          rtb_Saturation1_i_idx_0 = rtb_MathFunction_i_idx_0;
          rtb_a_b = rtb_MathFunction_i_idx_0;
        }

        /* End of Signum: '<S40>/Sign5' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S16>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S16>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S16>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  DiscreteIntegrator: '<S38>/Integrator1'
         *  DiscreteIntegrator: '<S39>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;

        /* Saturate: '<S42>/Saturation' */
        if (FMS_B.Merge_m > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S16>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_m < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S16>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S16>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_m;
        }

        /* End of Saturate: '<S42>/Saturation' */

        /* Saturate: '<S25>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S16>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S16>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S16>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S25>/Saturation1' */

        /* Product: '<S41>/Multiply1' incorporates:
         *  Constant: '<S41>/const1'
         *  DiscreteIntegrator: '<S39>/Integrator'
         */
        rtb_MathFunction_i_idx_0 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* DeadZone: '<S37>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          dis = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          dis = 0.0F;
        } else {
          dis = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S37>/Dead Zone' */
        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Sum: '<S41>/Add' incorporates:
         *  DiscreteIntegrator: '<S39>/Integrator1'
         *  Gain: '<S23>/Gain1'
         *  Gain: '<S37>/Gain'
         *  Sum: '<S39>/Subtract'
         */
        rtb_Switch_h_idx_1 = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
          FMS_PARAM.PITCH_DZ) * dis * -FMS_PARAM.ROLL_PITCH_LIM) +
          rtb_MathFunction_i_idx_0;

        /* Signum: '<S41>/Sign' */
        if (rtb_Switch_h_idx_1 < 0.0F) {
          dis = -1.0F;
        } else if (rtb_Switch_h_idx_1 > 0.0F) {
          dis = 1.0F;
        } else {
          dis = rtb_Switch_h_idx_1;
        }

        /* End of Signum: '<S41>/Sign' */

        /* Sum: '<S41>/Add2' incorporates:
         *  Abs: '<S41>/Abs'
         *  Gain: '<S41>/Gain'
         *  Gain: '<S41>/Gain1'
         *  Product: '<S41>/Multiply2'
         *  Product: '<S41>/Multiply3'
         *  Sqrt: '<S41>/Sqrt'
         *  Sum: '<S41>/Add1'
         *  Sum: '<S41>/Subtract'
         */
        dis = (sqrtf((8.0F * fabsf(rtb_Switch_h_idx_1) + FMS_ConstB.d_c) *
                     FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F * dis +
          rtb_MathFunction_i_idx_0;

        /* Sum: '<S41>/Add4' */
        rtb_MathFunction_i_idx_0 += rtb_Switch_h_idx_1 - dis;

        /* Sum: '<S41>/Add3' */
        rtb_Integrator1_a = rtb_Switch_h_idx_1 + FMS_ConstB.d_c;

        /* Sum: '<S41>/Subtract1' */
        rtb_Switch_h_idx_1 -= FMS_ConstB.d_c;

        /* Signum: '<S41>/Sign1' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S41>/Sign1' */

        /* Signum: '<S41>/Sign2' */
        if (rtb_Switch_h_idx_1 < 0.0F) {
          rtb_Switch_h_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_h_idx_1 > 0.0F) {
            rtb_Switch_h_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S41>/Sign2' */

        /* Sum: '<S41>/Add5' incorporates:
         *  Gain: '<S41>/Gain2'
         *  Product: '<S41>/Multiply4'
         *  Sum: '<S41>/Subtract2'
         */
        dis += (rtb_Integrator1_a - rtb_Switch_h_idx_1) * 0.5F *
          rtb_MathFunction_i_idx_0;

        /* Update for DiscreteIntegrator: '<S38>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S38>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Signum: '<S40>/Sign3' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_1 > 0.0F) {
            rtb_Switch_b_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S40>/Sign3' */

        /* Signum: '<S40>/Sign4' */
        if (rtb_Switch_b_idx_0 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S40>/Sign4' */

        /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
         *  Constant: '<S40>/const'
         *  Gain: '<S40>/Gain3'
         *  Product: '<S40>/Multiply5'
         *  Product: '<S40>/Multiply6'
         *  Sum: '<S40>/Subtract4'
         *  Sum: '<S40>/Subtract5'
         *  Sum: '<S40>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_Switch_b_idx_3 -
          rtb_Saturation1_i_idx_0) * FMS_ConstB.Gain4 * ((rtb_Switch_b_idx_1 -
          rtb_Switch_b_idx_0) * 0.5F) - rtb_a_b * 12.566371F) * 0.004F;

        /* Update for DiscreteIntegrator: '<S39>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S39>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S41>/Add6' */
        rtb_Switch_b_idx_0 = dis + FMS_ConstB.d_c;

        /* Sum: '<S41>/Subtract3' */
        rtb_Switch_b_idx_1 = dis - FMS_ConstB.d_c;

        /* Signum: '<S41>/Sign5' */
        if (dis < 0.0F) {
          rtb_a_b = -1.0F;
        } else if (dis > 0.0F) {
          rtb_a_b = 1.0F;
        } else {
          rtb_a_b = dis;
        }

        /* End of Signum: '<S41>/Sign5' */

        /* Signum: '<S41>/Sign3' */
        if (rtb_Switch_b_idx_0 < 0.0F) {
          rtb_Switch_b_idx_0 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_0 > 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S41>/Sign3' */

        /* Signum: '<S41>/Sign4' */
        if (rtb_Switch_b_idx_1 < 0.0F) {
          rtb_Switch_b_idx_1 = -1.0F;
        } else {
          if (rtb_Switch_b_idx_1 > 0.0F) {
            rtb_Switch_b_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S41>/Sign4' */

        /* Signum: '<S41>/Sign6' */
        if (dis < 0.0F) {
          rtb_Switch_h_idx_1 = -1.0F;
        } else if (dis > 0.0F) {
          rtb_Switch_h_idx_1 = 1.0F;
        } else {
          rtb_Switch_h_idx_1 = dis;
        }

        /* End of Signum: '<S41>/Sign6' */

        /* Update for DiscreteIntegrator: '<S39>/Integrator' incorporates:
         *  Constant: '<S41>/const'
         *  Gain: '<S41>/Gain3'
         *  Product: '<S41>/Divide'
         *  Product: '<S41>/Multiply5'
         *  Product: '<S41>/Multiply6'
         *  Sum: '<S41>/Subtract4'
         *  Sum: '<S41>/Subtract5'
         *  Sum: '<S41>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((dis / FMS_ConstB.d_c - rtb_a_b) *
          FMS_ConstB.Gain4_m * ((rtb_Switch_b_idx_0 - rtb_Switch_b_idx_1) * 0.5F)
          - rtb_Switch_h_idx_1 * 12.566371F) * 0.004F;

        /* End of Outputs for SubSystem: '<S10>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S10>/Position' incorporates:
           *  ActionPort: '<S17>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S10>/Switch Case' incorporates:
           *  Chart: '<S59>/Motion Status'
           *  Chart: '<S70>/Motion State'
           *  Chart: '<S83>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_i);
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

          /* End of SystemReset for SubSystem: '<S10>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S10>/Position' incorporates:
         *  ActionPort: '<S17>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
        /* Chart: '<S59>/Motion Status' incorporates:
         *  Abs: '<S59>/Abs'
         *  Abs: '<S59>/Abs1'
         *  Constant: '<S67>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S67>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                         FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                         &rtb_state_di, &FMS_DW.sf_MotionStatus_i);

        /* Chart: '<S70>/Motion State' incorporates:
         *  Abs: '<S70>/Abs'
         *  Abs: '<S70>/Abs1'
         *  Constant: '<S80>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S80>/Compare'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        FMS_MotionState(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                        fabsf(FMS_U.INS_Out.r), &rtb_state_dm,
                        &FMS_DW.sf_MotionState_j);

        /* Logic: '<S83>/Logical Operator' incorporates:
         *  Abs: '<S83>/Abs1'
         *  Abs: '<S83>/Abs2'
         *  Constant: '<S94>/Constant'
         *  Constant: '<S95>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S94>/Compare'
         *  RelationalOperator: '<S95>/Compare'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtb_LogicalOperator_n = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
          FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
          FMS_PARAM.ROLL_DZ));

        /* End of Outputs for SubSystem: '<Root>/FMS Input' */

        /* Chart: '<S83>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S83>/Square'
         *  Math: '<S83>/Square1'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  Sqrt: '<S83>/Sqrt'
         *  Sum: '<S83>/Add'
         */
        if (FMS_DW.temporalCounter_i1_i < 1023U) {
          FMS_DW.temporalCounter_i1_i++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move_j;
          rtb_state_m2 = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake_p:
            rtb_state_m2 = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_i
                 >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_a;
              rtb_state_m2 = MotionState_Hold;
            } else {
              if (rtb_LogicalOperator_n) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_j;
                rtb_state_m2 = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<Root>/FMS Input' */
            break;

           case FMS_IN_Hold_a:
            rtb_state_m2 = MotionState_Hold;
            if (rtb_LogicalOperator_n) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_j;
              rtb_state_m2 = MotionState_Move;
            }
            break;

           default:
            rtb_state_m2 = MotionState_Move;
            if (!rtb_LogicalOperator_n) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_p;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state_m2 = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S83>/Motion State' */

        /* SwitchCase: '<S82>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state_m2) {
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
            /* SystemReset for IfAction SubSystem: '<S82>/Hold Control' incorporates:
             *  ActionPort: '<S85>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S82>/Switch Case' */
            FMS_HoldControl_n_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S82>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S82>/Hold Control' incorporates:
           *  ActionPort: '<S85>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_f(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_a, &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S82>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S82>/Brake Control' incorporates:
           *  ActionPort: '<S84>/Action Port'
           */
          FMS_BrakeControl_b(FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S82>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S82>/Move Control' incorporates:
             *  ActionPort: '<S86>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S82>/Switch Case' */
            FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S82>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S82>/Move Control' incorporates:
           *  ActionPort: '<S86>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_i(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S82>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S82>/Switch Case' */

        /* SwitchCase: '<S58>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_o;
        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;
        switch (rtb_state_di) {
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
            /* SystemReset for IfAction SubSystem: '<S58>/Hold Control' incorporates:
             *  ActionPort: '<S61>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S58>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_p);

            /* End of SystemReset for SubSystem: '<S58>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S58>/Hold Control' incorporates:
           *  ActionPort: '<S61>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_k,
                          &FMS_DW.HoldControl_p);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S58>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S58>/Brake Control' incorporates:
           *  ActionPort: '<S60>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_k);

          /* End of Outputs for SubSystem: '<S58>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S58>/Move Control' incorporates:
             *  ActionPort: '<S62>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S58>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_be);

            /* End of SystemReset for SubSystem: '<S58>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S58>/Move Control' incorporates:
           *  ActionPort: '<S62>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_k,
                          &FMS_ConstB.MoveControl_be, &FMS_DW.MoveControl_be);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S58>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S58>/Switch Case' */

        /* SwitchCase: '<S69>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S3>/Signal Copy1'
         *  SignalConversion: '<S3>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_j;
        FMS_DW.SwitchCase_ActiveSubsystem_j = -1;
        switch (rtb_state_dm) {
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
            /* SystemReset for IfAction SubSystem: '<S69>/Hold Control' incorporates:
             *  ActionPort: '<S72>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S69>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

            /* End of SystemReset for SubSystem: '<S69>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S69>/Hold Control' incorporates:
           *  ActionPort: '<S72>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_d,
                            &FMS_DW.HoldControl_e);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S69>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S69>/Brake Control' incorporates:
           *  ActionPort: '<S71>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_d);

          /* End of Outputs for SubSystem: '<S69>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_j != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S69>/Move Control' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S69>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S69>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S69>/Move Control' incorporates:
           *  ActionPort: '<S73>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<Root>/FMS Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_d,
                            &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<Root>/FMS Input' */
          /* End of Outputs for SubSystem: '<S69>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S69>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S17>/Bus Assignment'
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Constant: '<S17>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S17>/Bus Assignment' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S69>/Saturation' */
        if (FMS_B.Merge_d > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_d < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_d;
        }

        /* End of Saturate: '<S69>/Saturation' */

        /* Saturate: '<S82>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S82>/Saturation1' */

        /* Saturate: '<S58>/Saturation1' */
        if (FMS_B.Merge_k > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_k < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S17>/Bus Assignment' incorporates:
           *  BusAssignment: '<S2>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_k;
        }

        /* End of Saturate: '<S58>/Saturation1' */
        /* End of Outputs for SubSystem: '<S10>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S10>/Unknown' incorporates:
         *  ActionPort: '<S19>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S2>/Bus Assignment'
         */
        FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S10>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S10>/Switch Case' */
      /* End of Outputs for SubSystem: '<S6>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S6>/Manual' incorporates:
       *  ActionPort: '<S12>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S12>/Bus Assignment'
       *  BusAssignment: '<S2>/Bus Assignment'
       *  Constant: '<S12>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S12>/Bus Assignment' incorporates:
       *  BusAssignment: '<S2>/Bus Assignment'
       *  Constant: '<S12>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.mode = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S6>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S6>/Unknown' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S2>/Bus Assignment'
       */
      FMS_Disarm(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S6>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S6>/Switch Case' */
    /* End of Outputs for SubSystem: '<S2>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S9>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Update for DiscreteIntegrator: '<S211>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S211>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S5>/ConcatBufferAtMatrix Concatenate3In3'
   *  Sum: '<S211>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (FMS_U.INS_Out.ax -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (FMS_U.INS_Out.ay -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (FMS_U.INS_Out.az -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S212>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S212>/Gain'
   *  Sum: '<S212>/Sum5'
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
    FMS_B.VehicleMode_e = VehicleMode_None;
    FMS_B.DataTypeConversion1 = PilotMode_None;
    FMS_B.DataTypeConversion = CMD_None;
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
  /* Start for SwitchCase: '<S6>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S6>/SubMode' */
  /* Start for SwitchCase: '<S13>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S13>/Hold' */
  /* Start for SwitchCase: '<S152>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S130>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S140>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S13>/Hold' */
  /* End of Start for SubSystem: '<S6>/SubMode' */

  /* Start for IfAction SubSystem: '<S6>/Assist' */
  /* Start for SwitchCase: '<S10>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S10>/Stabilize' */
  /* Start for SwitchCase: '<S106>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S10>/Stabilize' */

  /* Start for IfAction SubSystem: '<S10>/Altitude' */
  /* Start for SwitchCase: '<S25>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S42>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S10>/Altitude' */

  /* Start for IfAction SubSystem: '<S10>/Position' */
  /* Start for SwitchCase: '<S82>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S58>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for SwitchCase: '<S69>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S10>/Position' */
  /* End of Start for SubSystem: '<S6>/Assist' */
  /* End of Start for SubSystem: '<S2>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */

  /* InitializeConditions for DiscreteIntegrator: '<S211>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S212>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_active_Mode_Manager = 0U;
  FMS_DW.is_Mode_Manager = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c11_FMS = 0U;
  FMS_DW.M_msgReservedData = CMD_None;
  FMS_DW.prep_takeoff = 0.0;
  FMS_B.VehicleMode_e = VehicleMode_None;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S2>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S6>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S13>/Return' */
  /* InitializeConditions for Delay: '<S170>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S202>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S176>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S176>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S13>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/Hold' */
  /* SystemInitialize for Chart: '<S131>/Motion Status' */
  FMS_DW.temporalCounter_i1_n = 0U;
  FMS_DW.is_active_c14_FMS = 0U;
  FMS_DW.is_c14_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<S141>/Motion State' */
  FMS_DW.temporalCounter_i1_ai = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<S153>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c22_FMS = 0U;
  FMS_DW.is_c22_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S152>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S152>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S152>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S152>/Move Control' */

  /* SystemInitialize for Merge: '<S152>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S130>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S130>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S130>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S130>/Move Control' */

  /* SystemInitialize for Merge: '<S130>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S140>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S140>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S140>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S140>/Move Control' */

  /* SystemInitialize for Merge: '<S140>/Merge' */
  FMS_B.Merge_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S13>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S6>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S6>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S10>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S102>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S102>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S103>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_jt = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S103>/Integrator' */
  FMS_DW.Integrator_DSTATE_cq = 0.0F;

  /* SystemInitialize for Chart: '<S107>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S106>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S106>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S106>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S106>/Move Control' */

  /* SystemInitialize for Merge: '<S106>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S10>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S10>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S26>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S25>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S25>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S25>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S25>/Move Control' */

  /* SystemInitialize for Chart: '<S43>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S42>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S42>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S42>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S42>/Move Control' */

  /* SystemInitialize for Merge: '<S25>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Merge: '<S42>/Merge' */
  FMS_B.Merge_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S10>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S10>/Position' */
  /* SystemInitialize for Chart: '<S59>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_i);

  /* SystemInitialize for Chart: '<S70>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_j);

  /* SystemInitialize for Chart: '<S83>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S82>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S82>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S82>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S82>/Move Control' */

  /* SystemInitialize for Merge: '<S82>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S58>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S58>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S58>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_be);

  /* End of SystemInitialize for SubSystem: '<S58>/Move Control' */

  /* SystemInitialize for Merge: '<S58>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S69>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S69>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S69>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S69>/Move Control' */

  /* SystemInitialize for Merge: '<S69>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S10>/Position' */
  /* End of SystemInitialize for SubSystem: '<S6>/Assist' */
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
