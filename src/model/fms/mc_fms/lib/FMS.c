/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2338
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Jul 20 15:54:09 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S483>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S493>/Motion State' */
#define FMS_IN_Brake_c                 ((uint8_T)1U)
#define FMS_IN_Hold_c                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S141>/Motion State' */
#define FMS_IN_Brake_f                 ((uint8_T)1U)
#define FMS_IN_Hold_j                  ((uint8_T)2U)
#define FMS_IN_Move_o4                 ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_b       ((uint8_T)0U)

/* Named constants for Chart: '<S54>/Motion Status' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_f                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_n       ((uint8_T)0U)

/* Named constants for Chart: '<S112>/Motion State' */
#define FMS_IN_Brake_d                 ((uint8_T)1U)
#define FMS_IN_Hold_l                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_p       ((uint8_T)0U)

/* Named constants for Chart: '<S413>/Motion State' */
#define FMS_IN_Brake_o                 ((uint8_T)1U)
#define FMS_IN_Hold_d                  ((uint8_T)2U)
#define FMS_IN_Move_n                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_h       ((uint8_T)0U)

/* Named constants for Chart: '<S156>/Motion Status' */
#define FMS_IN_TerrainTrack            ((uint8_T)4U)

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
#define FMS_IN_Terrain                 ((uint8_T)6U)
#define FMS_IN_Waypoint                ((uint8_T)9U)
#define FMS_event_DisarmEvent          (0)

/* Named constants for Chart: '<Root>/SafeMode' */
#define FMS_IN_Manual_b                ((uint8_T)3U)
#define FMS_IN_Mission_c               ((uint8_T)4U)
#define FMS_IN_Offboard_h              ((uint8_T)5U)
#define FMS_IN_Position_k              ((uint8_T)6U)
#define FMS_IN_Stabilize_k             ((uint8_T)7U)
#define FMS_IN_Terrain_a               ((uint8_T)8U)
#define FMS_IN_Unknown                 ((uint8_T)9U)

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
                                        *   '<S29>/Constant'
                                        *   '<S543>/Constant'
                                        *   '<S396>/L1'
                                        *   '<S51>/Gain'
                                        *   '<S51>/Gain1'
                                        *   '<S128>/Gain'
                                        *   '<S128>/Gain1'
                                        *   '<S130>/Constant'
                                        *   '<S202>/L1'
                                        *   '<S289>/Saturation'
                                        *   '<S290>/Saturation1'
                                        *   '<S290>/Saturation2'
                                        *   '<S290>/Saturation3'
                                        *   '<S437>/Land_Speed'
                                        *   '<S438>/Saturation1'
                                        *   '<S530>/Takeoff_Speed'
                                        *   '<S531>/Gain2'
                                        *   '<S531>/Saturation1'
                                        *   '<S53>/Saturation1'
                                        *   '<S65>/Dead Zone'
                                        *   '<S65>/Gain'
                                        *   '<S66>/Dead Zone'
                                        *   '<S66>/Gain'
                                        *   '<S67>/Constant'
                                        *   '<S68>/Constant'
                                        *   '<S73>/Saturation'
                                        *   '<S88>/Saturation1'
                                        *   '<S99>/Saturation'
                                        *   '<S111>/Saturation1'
                                        *   '<S132>/Dead Zone'
                                        *   '<S132>/Gain'
                                        *   '<S133>/Dead Zone'
                                        *   '<S133>/Gain'
                                        *   '<S134>/Constant'
                                        *   '<S135>/Constant'
                                        *   '<S140>/Saturation'
                                        *   '<S155>/Saturation1'
                                        *   '<S169>/Saturation'
                                        *   '<S181>/Saturation1'
                                        *   '<S345>/Gain2'
                                        *   '<S352>/Gain1'
                                        *   '<S352>/Gain2'
                                        *   '<S402>/Saturation1'
                                        *   '<S412>/Saturation'
                                        *   '<S424>/Saturation1'
                                        *   '<S439>/Constant'
                                        *   '<S442>/Gain2'
                                        *   '<S464>/Gain'
                                        *   '<S464>/Saturation1'
                                        *   '<S467>/Constant'
                                        *   '<S467>/vel'
                                        *   '<S467>/Switch'
                                        *   '<S55>/Gain2'
                                        *   '<S56>/Gain1'
                                        *   '<S62>/Constant'
                                        *   '<S75>/Gain2'
                                        *   '<S76>/Gain1'
                                        *   '<S83>/Constant'
                                        *   '<S90>/Gain2'
                                        *   '<S91>/Gain1'
                                        *   '<S97>/Constant'
                                        *   '<S101>/Gain2'
                                        *   '<S102>/Gain1'
                                        *   '<S109>/Constant'
                                        *   '<S113>/Gain2'
                                        *   '<S114>/Gain6'
                                        *   '<S125>/Constant'
                                        *   '<S126>/Constant'
                                        *   '<S142>/Gain2'
                                        *   '<S143>/Gain1'
                                        *   '<S150>/Constant'
                                        *   '<S157>/Gain2'
                                        *   '<S158>/Gain1'
                                        *   '<S159>/Gain2'
                                        *   '<S167>/Constant'
                                        *   '<S171>/Gain2'
                                        *   '<S172>/Gain1'
                                        *   '<S179>/Constant'
                                        *   '<S183>/Gain2'
                                        *   '<S184>/Gain6'
                                        *   '<S195>/Constant'
                                        *   '<S196>/Constant'
                                        *   '<S221>/Gain'
                                        *   '<S221>/Saturation1'
                                        *   '<S224>/Constant'
                                        *   '<S224>/vel'
                                        *   '<S224>/Switch'
                                        *   '<S405>/Gain2'
                                        *   '<S406>/Gain1'
                                        *   '<S415>/Gain2'
                                        *   '<S416>/Gain1'
                                        *   '<S427>/Gain2'
                                        *   '<S428>/Gain6'
                                        *   '<S451>/Gain2'
                                        *   '<S451>/Saturation'
                                        *   '<S452>/Integrator'
                                        *   '<S58>/Land_Speed'
                                        *   '<S59>/Constant'
                                        *   '<S61>/Dead Zone'
                                        *   '<S61>/Gain'
                                        *   '<S80>/Dead Zone'
                                        *   '<S80>/Gain'
                                        *   '<S93>/Land_Speed'
                                        *   '<S94>/Constant'
                                        *   '<S96>/Dead Zone'
                                        *   '<S96>/Gain'
                                        *   '<S106>/Dead Zone'
                                        *   '<S106>/Gain'
                                        *   '<S119>/Dead Zone'
                                        *   '<S119>/Gain'
                                        *   '<S120>/Dead Zone'
                                        *   '<S120>/Gain'
                                        *   '<S121>/Constant'
                                        *   '<S147>/Dead Zone'
                                        *   '<S147>/Gain'
                                        *   '<S161>/Land_Speed'
                                        *   '<S162>/Constant'
                                        *   '<S164>/Dead Zone'
                                        *   '<S164>/Gain'
                                        *   '<S165>/Constant'
                                        *   '<S176>/Dead Zone'
                                        *   '<S176>/Gain'
                                        *   '<S189>/Dead Zone'
                                        *   '<S189>/Gain'
                                        *   '<S190>/Dead Zone'
                                        *   '<S190>/Gain'
                                        *   '<S191>/Constant'
                                        *   '<S208>/Gain2'
                                        *   '<S208>/Saturation'
                                        *   '<S209>/Integrator'
                                        *   '<S408>/Dead Zone'
                                        *   '<S408>/Gain'
                                        *   '<S420>/Dead Zone'
                                        *   '<S420>/Gain'
                                        *   '<S432>/Dead Zone'
                                        *   '<S432>/Gain'
                                        *   '<S433>/Dead Zone'
                                        *   '<S433>/Gain'
                                        *   '<S482>/Saturation1'
                                        *   '<S492>/Saturation1'
                                        *   '<S239>/Saturation1'
                                        *   '<S249>/Saturation1'
                                        *   '<S485>/Gain2'
                                        *   '<S486>/Gain1'
                                        *   '<S495>/Gain2'
                                        *   '<S496>/Gain6'
                                        *   '<S242>/Gain2'
                                        *   '<S243>/Gain1'
                                        *   '<S252>/Gain2'
                                        *   '<S253>/Gain6'
                                        *   '<S488>/Dead Zone'
                                        *   '<S488>/Gain'
                                        *   '<S500>/Dead Zone'
                                        *   '<S500>/Gain'
                                        *   '<S501>/Dead Zone'
                                        *   '<S501>/Gain'
                                        *   '<S245>/Dead Zone'
                                        *   '<S245>/Gain'
                                        *   '<S257>/Dead Zone'
                                        *   '<S257>/Gain'
                                        *   '<S258>/Dead Zone'
                                        *   '<S258>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 77, 67, 32, 70, 77, 83, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S9>/Constant'
                                        *   '<S14>/Constant1'
                                        *   '<S541>/Constant'
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
static void FMS_exit_internal_Mode(void);
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
 * System initialize for action system:
 *    '<S482>/Hold Control'
 *    '<S402>/Hold Control'
 *    '<S239>/Hold Control'
 *    '<S53>/Hold Control'
 *    '<S88>/Hold Control'
 *    '<S155>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S485>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S482>/Hold Control'
 *    '<S402>/Hold Control'
 *    '<S239>/Hold Control'
 *    '<S53>/Hold Control'
 *    '<S88>/Hold Control'
 *    '<S155>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S485>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S482>/Hold Control'
 *    '<S402>/Hold Control'
 *    '<S239>/Hold Control'
 *    '<S53>/Hold Control'
 *    '<S88>/Hold Control'
 *    '<S155>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S485>/Delay' incorporates:
   *  Gain: '<S487>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S485>/Gain2' incorporates:
   *  Delay: '<S485>/Delay'
   *  Gain: '<S487>/Gain'
   *  Sum: '<S485>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S485>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S482>/Brake Control'
 *    '<S402>/Brake Control'
 *    '<S412>/Brake Control'
 *    '<S239>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S484>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S484>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S482>/Move Control'
 *    '<S402>/Move Control'
 *    '<S239>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S489>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S489>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S482>/Move Control'
 *    '<S402>/Move Control'
 *    '<S239>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S489>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S489>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S482>/Move Control'
 *    '<S402>/Move Control'
 *    '<S239>/Move Control'
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

  /* Product: '<S490>/Multiply1' incorporates:
   *  Constant: '<S490>/const1'
   *  DiscreteIntegrator: '<S489>/Integrator'
   */
  rtb_Add3_mj = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S488>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_g = 0.0F;
  } else {
    rtb_a_g = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S488>/Dead Zone' */

  /* Sum: '<S490>/Add' incorporates:
   *  DiscreteIntegrator: '<S489>/Integrator1'
   *  Gain: '<S486>/Gain1'
   *  Gain: '<S488>/Gain'
   *  Sum: '<S489>/Subtract'
   */
  rtb_Subtract3_k = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_g * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_mj;

  /* Signum: '<S490>/Sign' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_Subtract3_k > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_Subtract3_k;
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
  rtb_a_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_k) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_g + rtb_Add3_mj;

  /* Sum: '<S490>/Add4' */
  rtb_Add4_k = (rtb_Subtract3_k - rtb_a_g) + rtb_Add3_mj;

  /* Sum: '<S490>/Add3' */
  rtb_Add3_mj = rtb_Subtract3_k + localC->d;

  /* Sum: '<S490>/Subtract1' */
  rtb_Subtract3_k -= localC->d;

  /* Signum: '<S490>/Sign1' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S490>/Sign1' */

  /* Signum: '<S490>/Sign2' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S490>/Sign2' */

  /* Sum: '<S490>/Add5' incorporates:
   *  Gain: '<S490>/Gain2'
   *  Product: '<S490>/Multiply4'
   *  Sum: '<S490>/Subtract2'
   */
  rtb_a_g += (rtb_Add3_mj - rtb_Subtract3_k) * 0.5F * rtb_Add4_k;

  /* SignalConversion: '<S486>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S489>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S489>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S489>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S490>/Add6' */
  rtb_Add3_mj = rtb_a_g + localC->d;

  /* Sum: '<S490>/Subtract3' */
  rtb_Subtract3_k = rtb_a_g - localC->d;

  /* Signum: '<S490>/Sign5' */
  if (rtb_a_g < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_Add4_k = 1.0F;
  } else {
    rtb_Add4_k = rtb_a_g;
  }

  /* End of Signum: '<S490>/Sign5' */

  /* Signum: '<S490>/Sign3' */
  if (rtb_Add3_mj < 0.0F) {
    rtb_Add3_mj = -1.0F;
  } else {
    if (rtb_Add3_mj > 0.0F) {
      rtb_Add3_mj = 1.0F;
    }
  }

  /* End of Signum: '<S490>/Sign3' */

  /* Signum: '<S490>/Sign4' */
  if (rtb_Subtract3_k < 0.0F) {
    rtb_Subtract3_k = -1.0F;
  } else {
    if (rtb_Subtract3_k > 0.0F) {
      rtb_Subtract3_k = 1.0F;
    }
  }

  /* End of Signum: '<S490>/Sign4' */

  /* Signum: '<S490>/Sign6' */
  if (rtb_a_g < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_a_g > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_a_g;
  }

  /* End of Signum: '<S490>/Sign6' */

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
  localDW->Integrator_DSTATE += ((rtb_a_g / localC->d - rtb_Add4_k) *
    localC->Gain4 * ((rtb_Add3_mj - rtb_Subtract3_k) * 0.5F) - rtb_a_m * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S483>/Motion Status'
 *    '<S403>/Motion Status'
 *    '<S240>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S483>/Motion Status'
 *    '<S403>/Motion Status'
 *    '<S240>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S483>/Motion Status'
 *    '<S403>/Motion Status'
 *    '<S240>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S483>/Motion Status' */
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

  /* End of Chart: '<S483>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S492>/Hold Control'
 *    '<S424>/Hold Control'
 *    '<S249>/Hold Control'
 */
void FMS_HoldControl_c_Init(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S495>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S492>/Hold Control'
 *    '<S424>/Hold Control'
 *    '<S249>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_j_T *localDW)
{
  /* InitializeConditions for Delay: '<S495>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S492>/Hold Control'
 *    '<S424>/Hold Control'
 *    '<S249>/Hold Control'
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

  /* Delay: '<S495>/Delay' incorporates:
   *  SignalConversion: '<S495>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_o;
  }

  /* Trigonometry: '<S499>/Trigonometric Function1' incorporates:
   *  Gain: '<S498>/Gain'
   *  Trigonometry: '<S499>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_bg_tmp_0 = arm_cos_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[0] = rtb_VectorConcatenate_bg_tmp_0;

  /* Trigonometry: '<S499>/Trigonometric Function' incorporates:
   *  Gain: '<S498>/Gain'
   *  Trigonometry: '<S499>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_bg_tmp = arm_sin_f32(-rtu_FMS_In_f);
  rtb_VectorConcatenate_d4[1] = rtb_VectorConcatenate_bg_tmp;

  /* SignalConversion: '<S499>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S499>/Constant3'
   */
  rtb_VectorConcatenate_d4[2] = 0.0F;

  /* Gain: '<S499>/Gain' */
  rtb_VectorConcatenate_d4[3] = -rtb_VectorConcatenate_bg_tmp;

  /* Trigonometry: '<S499>/Trigonometric Function3' */
  rtb_VectorConcatenate_d4[4] = rtb_VectorConcatenate_bg_tmp_0;

  /* SignalConversion: '<S499>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S499>/Constant4'
   */
  rtb_VectorConcatenate_d4[5] = 0.0F;

  /* SignalConversion: '<S499>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_d4[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_d4[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_d4[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S495>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S495>/Delay'
   *  SignalConversion: '<S495>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S495>/Sum'
   */
  rtb_VectorConcatenate_bg_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_bg_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_o;

  /* Product: '<S495>/Multiply' incorporates:
   *  SignalConversion: '<S495>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_bg[i] = rtb_VectorConcatenate_d4[i + 3] *
      rtb_VectorConcatenate_bg_tmp + rtb_VectorConcatenate_d4[i] *
      rtb_VectorConcatenate_bg_tmp_0;
  }

  /* End of Product: '<S495>/Multiply' */

  /* Gain: '<S495>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_bg[1];

  /* Update for Delay: '<S495>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S492>/Brake Control'
 *    '<S424>/Brake Control'
 *    '<S249>/Brake Control'
 */
void FMS_BrakeControl_h(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S494>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S492>/Move Control'
 *    '<S424>/Move Control'
 *    '<S249>/Move Control'
 */
void FMS_MoveControl_l_Init(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S502>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S502>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S502>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S502>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S492>/Move Control'
 *    '<S424>/Move Control'
 *    '<S249>/Move Control'
 */
void FMS_MoveControl_i_Reset(DW_MoveControl_FMS_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S502>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S502>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S502>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S502>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S492>/Move Control'
 *    '<S424>/Move Control'
 *    '<S249>/Move Control'
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

  /* SignalConversion: '<S496>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S502>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Product: '<S503>/Multiply1' incorporates:
   *  Constant: '<S503>/const1'
   *  DiscreteIntegrator: '<S502>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* SignalConversion: '<S496>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S502>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Product: '<S503>/Multiply1' incorporates:
   *  Constant: '<S503>/const1'
   *  DiscreteIntegrator: '<S502>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S500>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S500>/Dead Zone' */

  /* Sum: '<S503>/Add' incorporates:
   *  DiscreteIntegrator: '<S502>/Integrator1'
   *  Gain: '<S496>/Gain6'
   *  Gain: '<S500>/Gain'
   *  Sum: '<S502>/Subtract'
   */
  rtb_Subtract3_l_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S501>/Dead Zone' */
  if (rtu_FMS_In_o > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_o >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_l_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_l_idx_1 = rtu_FMS_In_o - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S501>/Dead Zone' */

  /* Sum: '<S503>/Add' incorporates:
   *  DiscreteIntegrator: '<S502>/Integrator1'
   *  Gain: '<S496>/Gain6'
   *  Gain: '<S501>/Gain'
   *  Sum: '<S502>/Subtract'
   */
  rtb_Subtract3_l_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_l_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S503>/Sign' */
  if (rtb_Subtract3_l_idx_0 < 0.0F) {
    rtb_Subtract3_l_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0 > 0.0F) {
    rtb_Subtract3_l_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0_0 = rtb_Subtract3_l_idx_0;
  }

  /* Sum: '<S503>/Add2' incorporates:
   *  Abs: '<S503>/Abs'
   *  Gain: '<S503>/Gain'
   *  Gain: '<S503>/Gain1'
   *  Product: '<S503>/Multiply2'
   *  Product: '<S503>/Multiply3'
   *  Signum: '<S503>/Sign'
   *  Sqrt: '<S503>/Sqrt'
   *  Sum: '<S503>/Add1'
   *  Sum: '<S503>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_l_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S503>/Add3' incorporates:
   *  Signum: '<S503>/Sign'
   */
  u = rtb_Subtract3_l_idx_0 + localC->d;

  /* Sum: '<S503>/Subtract1' incorporates:
   *  Signum: '<S503>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_0 - localC->d;

  /* Signum: '<S503>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S503>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S503>/Add5' incorporates:
   *  Gain: '<S503>/Gain2'
   *  Product: '<S503>/Multiply4'
   *  Signum: '<S503>/Sign'
   *  Sum: '<S503>/Add2'
   *  Sum: '<S503>/Add4'
   *  Sum: '<S503>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_0 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S502>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S502>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S503>/Sign3' incorporates:
   *  Sum: '<S503>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S503>/Sign4' incorporates:
   *  Sum: '<S503>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S503>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S503>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S503>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S503>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S502>/Integrator' incorporates:
   *  Constant: '<S503>/const'
   *  Gain: '<S503>/Gain3'
   *  Product: '<S503>/Divide'
   *  Product: '<S503>/Multiply5'
   *  Product: '<S503>/Multiply6'
   *  Sum: '<S503>/Subtract4'
   *  Sum: '<S503>/Subtract5'
   *  Sum: '<S503>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;

  /* Signum: '<S503>/Sign' */
  if (rtb_Subtract3_l_idx_1 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_1 > 0.0F) {
    rtb_Add3_l_idx_0 = 1.0F;
  } else {
    rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_1;
  }

  /* Sum: '<S503>/Add2' incorporates:
   *  Abs: '<S503>/Abs'
   *  Gain: '<S503>/Gain'
   *  Gain: '<S503>/Gain1'
   *  Product: '<S503>/Multiply2'
   *  Product: '<S503>/Multiply3'
   *  Signum: '<S503>/Sign'
   *  Sqrt: '<S503>/Sqrt'
   *  Sum: '<S503>/Add1'
   *  Sum: '<S503>/Subtract'
   */
  rtb_Subtract3_l_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_l_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Add3_l_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S503>/Add3' incorporates:
   *  Signum: '<S503>/Sign'
   */
  u = rtb_Subtract3_l_idx_1 + localC->d;

  /* Sum: '<S503>/Subtract1' incorporates:
   *  Signum: '<S503>/Sign'
   */
  rtb_Subtract3_p = rtb_Subtract3_l_idx_1 - localC->d;

  /* Signum: '<S503>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S503>/Sign2' */
  if (rtb_Subtract3_p < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else {
    if (rtb_Subtract3_p > 0.0F) {
      rtb_Subtract3_p = 1.0F;
    }
  }

  /* Sum: '<S503>/Add5' incorporates:
   *  Gain: '<S503>/Gain2'
   *  Product: '<S503>/Multiply4'
   *  Signum: '<S503>/Sign'
   *  Sum: '<S503>/Add2'
   *  Sum: '<S503>/Add4'
   *  Sum: '<S503>/Subtract2'
   */
  rtb_Subtract3_l_idx_0_0 += ((rtb_Subtract3_l_idx_1 - rtb_Subtract3_l_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_p) * 0.5F);

  /* Update for DiscreteIntegrator: '<S502>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S502>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S503>/Sign3' incorporates:
   *  Sum: '<S503>/Add6'
   */
  u = rtb_Subtract3_l_idx_0_0 + localC->d;

  /* Signum: '<S503>/Sign4' incorporates:
   *  Sum: '<S503>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_l_idx_0_0 - localC->d;

  /* Signum: '<S503>/Sign5' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_l_idx_0 = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_l_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_l_idx_0 = rtb_Subtract3_l_idx_0_0;
  }

  /* Signum: '<S503>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S503>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S503>/Sign6' */
  if (rtb_Subtract3_l_idx_0_0 < 0.0F) {
    rtb_Subtract3_p = -1.0F;
  } else if (rtb_Subtract3_l_idx_0_0 > 0.0F) {
    rtb_Subtract3_p = 1.0F;
  } else {
    rtb_Subtract3_p = rtb_Subtract3_l_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S502>/Integrator' incorporates:
   *  Constant: '<S503>/const'
   *  Gain: '<S503>/Gain3'
   *  Product: '<S503>/Divide'
   *  Product: '<S503>/Multiply5'
   *  Product: '<S503>/Multiply6'
   *  Sum: '<S503>/Subtract4'
   *  Sum: '<S503>/Subtract5'
   *  Sum: '<S503>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_l_idx_0_0 / localC->d -
    rtb_Subtract3_l_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_p * 58.836F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S493>/Motion State'
 *    '<S425>/Motion State'
 *    '<S250>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S493>/Motion State'
 *    '<S425>/Motion State'
 *    '<S250>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c23_FMS = 0U;
  localDW->is_c23_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S493>/Motion State'
 *    '<S425>/Motion State'
 *    '<S250>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S493>/Motion State' */
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

  /* End of Chart: '<S493>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S469>/NearbyRefWP'
 *    '<S226>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_d, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S507>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S412>/Hold Control'
 *    '<S140>/Hold Control'
 *    '<S73>/Hold Control'
 *    '<S99>/Hold Control'
 *    '<S169>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S415>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S412>/Hold Control'
 *    '<S140>/Hold Control'
 *    '<S73>/Hold Control'
 *    '<S99>/Hold Control'
 *    '<S169>/Hold Control'
 */
void FMS_HoldControl_kp_Reset(DW_HoldControl_FMS_g_T *localDW)
{
  /* InitializeConditions for Delay: '<S415>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S412>/Hold Control'
 *    '<S140>/Hold Control'
 *    '<S73>/Hold Control'
 *    '<S99>/Hold Control'
 *    '<S169>/Hold Control'
 */
void FMS_HoldControl_k(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_g_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_nb;

  /* Delay: '<S415>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S415>/Sum' incorporates:
   *  Delay: '<S415>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S418>/Abs' */
  rtb_Abs_nb = fabsf(rtb_psi_error_rad);

  /* Switch: '<S418>/Switch' incorporates:
   *  Constant: '<S418>/Constant'
   *  Constant: '<S419>/Constant'
   *  Product: '<S418>/Multiply'
   *  RelationalOperator: '<S419>/Compare'
   *  Sum: '<S418>/Subtract'
   */
  if (rtb_Abs_nb > 3.14159274F) {
    /* Signum: '<S418>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S418>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_nb - 6.28318548F;
  }

  /* End of Switch: '<S418>/Switch' */

  /* Gain: '<S415>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S415>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S412>/Move Control'
 *    '<S140>/Move Control'
 *    '<S73>/Move Control'
 *    '<S99>/Move Control'
 *    '<S169>/Move Control'
 */
void FMS_MoveControl_j_Init(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S421>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S421>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S412>/Move Control'
 *    '<S140>/Move Control'
 *    '<S73>/Move Control'
 *    '<S99>/Move Control'
 *    '<S169>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_c_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S421>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S421>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S412>/Move Control'
 *    '<S140>/Move Control'
 *    '<S73>/Move Control'
 *    '<S99>/Move Control'
 *    '<S169>/Move Control'
 */
void FMS_MoveControl_b(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_f_T *localC, DW_MoveControl_FMS_c_T *localDW)
{
  real32_T rtb_Add3_ig;
  real32_T rtb_Subtract3_l;
  real32_T rtb_a_m;
  real32_T rtb_Add4_b;
  real32_T rtb_a_p4;

  /* Product: '<S422>/Multiply1' incorporates:
   *  Constant: '<S422>/const1'
   *  DiscreteIntegrator: '<S421>/Integrator'
   */
  rtb_Add3_ig = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S420>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_m = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_m = 0.0F;
  } else {
    rtb_a_m = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S420>/Dead Zone' */

  /* Sum: '<S422>/Add' incorporates:
   *  DiscreteIntegrator: '<S421>/Integrator1'
   *  Gain: '<S416>/Gain1'
   *  Gain: '<S420>/Gain'
   *  Sum: '<S421>/Subtract'
   */
  rtb_Subtract3_l = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_m * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_ig;

  /* Signum: '<S422>/Sign' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_a_m = -1.0F;
  } else if (rtb_Subtract3_l > 0.0F) {
    rtb_a_m = 1.0F;
  } else {
    rtb_a_m = rtb_Subtract3_l;
  }

  /* End of Signum: '<S422>/Sign' */

  /* Sum: '<S422>/Add2' incorporates:
   *  Abs: '<S422>/Abs'
   *  Gain: '<S422>/Gain'
   *  Gain: '<S422>/Gain1'
   *  Product: '<S422>/Multiply2'
   *  Product: '<S422>/Multiply3'
   *  Sqrt: '<S422>/Sqrt'
   *  Sum: '<S422>/Add1'
   *  Sum: '<S422>/Subtract'
   */
  rtb_a_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_l) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_m + rtb_Add3_ig;

  /* Sum: '<S422>/Add4' */
  rtb_Add4_b = (rtb_Subtract3_l - rtb_a_m) + rtb_Add3_ig;

  /* Sum: '<S422>/Add3' */
  rtb_Add3_ig = rtb_Subtract3_l + localC->d;

  /* Sum: '<S422>/Subtract1' */
  rtb_Subtract3_l -= localC->d;

  /* Signum: '<S422>/Sign1' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S422>/Sign1' */

  /* Signum: '<S422>/Sign2' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S422>/Sign2' */

  /* Sum: '<S422>/Add5' incorporates:
   *  Gain: '<S422>/Gain2'
   *  Product: '<S422>/Multiply4'
   *  Sum: '<S422>/Subtract2'
   */
  rtb_a_m += (rtb_Add3_ig - rtb_Subtract3_l) * 0.5F * rtb_Add4_b;

  /* SignalConversion: '<S416>/OutportBufferForpsi_rate_cmd_radPs' incorporates:
   *  DiscreteIntegrator: '<S421>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S421>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S421>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S422>/Add6' */
  rtb_Add3_ig = rtb_a_m + localC->d;

  /* Sum: '<S422>/Subtract3' */
  rtb_Subtract3_l = rtb_a_m - localC->d;

  /* Signum: '<S422>/Sign5' */
  if (rtb_a_m < 0.0F) {
    rtb_Add4_b = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_Add4_b = 1.0F;
  } else {
    rtb_Add4_b = rtb_a_m;
  }

  /* End of Signum: '<S422>/Sign5' */

  /* Signum: '<S422>/Sign3' */
  if (rtb_Add3_ig < 0.0F) {
    rtb_Add3_ig = -1.0F;
  } else {
    if (rtb_Add3_ig > 0.0F) {
      rtb_Add3_ig = 1.0F;
    }
  }

  /* End of Signum: '<S422>/Sign3' */

  /* Signum: '<S422>/Sign4' */
  if (rtb_Subtract3_l < 0.0F) {
    rtb_Subtract3_l = -1.0F;
  } else {
    if (rtb_Subtract3_l > 0.0F) {
      rtb_Subtract3_l = 1.0F;
    }
  }

  /* End of Signum: '<S422>/Sign4' */

  /* Signum: '<S422>/Sign6' */
  if (rtb_a_m < 0.0F) {
    rtb_a_p4 = -1.0F;
  } else if (rtb_a_m > 0.0F) {
    rtb_a_p4 = 1.0F;
  } else {
    rtb_a_p4 = rtb_a_m;
  }

  /* End of Signum: '<S422>/Sign6' */

  /* Update for DiscreteIntegrator: '<S421>/Integrator' incorporates:
   *  Constant: '<S422>/const'
   *  Gain: '<S422>/Gain3'
   *  Product: '<S422>/Divide'
   *  Product: '<S422>/Multiply5'
   *  Product: '<S422>/Multiply6'
   *  Sum: '<S422>/Subtract4'
   *  Sum: '<S422>/Subtract5'
   *  Sum: '<S422>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_m / localC->d - rtb_Add4_b) *
    localC->Gain4 * ((rtb_Add3_ig - rtb_Subtract3_l) * 0.5F) - rtb_a_p4 *
    15.707963F) * 0.004F;
}

/*
 * Output and update for action system:
 *    '<S40>/Unknown'
 *    '<S38>/Unknown'
 *    '<S37>/Unknown'
 *    '<S33>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S398>/Bus Assignment' incorporates:
   *  Constant: '<S398>/Constant'
   *  Constant: '<S398>/Constant2'
   *  SignalConversion: '<S398>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S398>/Bus Assignment' */
}

/*
 * System initialize for atomic system:
 *    '<S141>/Motion State'
 *    '<S74>/Motion State'
 *    '<S100>/Motion State'
 *    '<S170>/Motion State'
 */
void FMS_MotionState_l_Init(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * System reset for atomic system:
 *    '<S141>/Motion State'
 *    '<S74>/Motion State'
 *    '<S100>/Motion State'
 *    '<S170>/Motion State'
 */
void FMS_MotionState_j_Reset(DW_MotionState_FMS_g_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_b;
}

/*
 * Output and update for atomic system:
 *    '<S141>/Motion State'
 *    '<S74>/Motion State'
 *    '<S100>/Motion State'
 *    '<S170>/Motion State'
 */
void FMS_MotionState_e(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_g_T *localDW)
{
  /* Chart: '<S141>/Motion State' */
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

  /* End of Chart: '<S141>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S53>/Move Control'
 *    '<S88>/Move Control'
 *    '<S155>/Move Control'
 */
void FMS_MoveControl_l(real32_T rtu_FMS_In, real32_T rtu_FMS_In_l, uint32_T
  rtu_FMS_In_i, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_j;

  /* DeadZone: '<S61>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_j = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_j = 0.0F;
  } else {
    rtb_Gain1_j = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S61>/Dead Zone' */

  /* Gain: '<S56>/Gain1' incorporates:
   *  Gain: '<S61>/Gain'
   */
  rtb_Gain1_j = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_j *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S56>/Switch' incorporates:
   *  Constant: '<S58>/Land_Speed'
   *  Constant: '<S59>/Constant'
   *  Constant: '<S60>/Constant'
   *  Gain: '<S58>/Gain'
   *  Logic: '<S56>/Logical Operator'
   *  MinMax: '<S58>/Min'
   *  RelationalOperator: '<S59>/Compare'
   *  RelationalOperator: '<S60>/Compare'
   *  S-Function (sfix_bitop): '<S56>/cmd_p valid'
   */
  if ((rtb_Gain1_j > 0.0F) && ((rtu_FMS_In_i & 256U) != 0U) && (rtu_FMS_In_l <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_j);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_j;
  }

  /* End of Switch: '<S56>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S54>/Motion Status'
 *    '<S89>/Motion Status'
 */
void FMS_MotionStatus_o_Init(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * System reset for atomic system:
 *    '<S54>/Motion Status'
 *    '<S89>/Motion Status'
 */
void FMS_MotionStatus_n_Reset(DW_MotionStatus_FMS_a_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_n;
}

/*
 * Output and update for atomic system:
 *    '<S54>/Motion Status'
 *    '<S89>/Motion Status'
 */
void FMS_MotionStatus_b(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_a_T *localDW)
{
  /* Chart: '<S54>/Motion Status' */
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

  /* End of Chart: '<S54>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S111>/Hold Control'
 *    '<S181>/Hold Control'
 */
void FMS_HoldControl_n_Init(DW_HoldControl_FMS_a_T *localDW)
{
  /* InitializeConditions for Delay: '<S113>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S111>/Hold Control'
 *    '<S181>/Hold Control'
 */
void FMS_HoldControl_g_Reset(DW_HoldControl_FMS_a_T *localDW)
{
  /* InitializeConditions for Delay: '<S113>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S111>/Hold Control'
 *    '<S181>/Hold Control'
 */
void FMS_HoldControl_a(real32_T rtu_FMS_In, real32_T rtu_FMS_In_g, real32_T
  rtu_FMS_In_a, real32_T rty_uv_cmd_mPs[2], const ConstB_HoldControl_FMS_i_T
  *localC, DW_HoldControl_FMS_a_T *localDW)
{
  real32_T rtb_VectorConcatenate_n[9];
  real32_T rtb_VectorConcatenate_om[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_om_tmp;
  real32_T rtb_VectorConcatenate_om_tmp_0;

  /* Delay: '<S113>/Delay' incorporates:
   *  SignalConversion: '<S113>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S117>/Trigonometric Function1' incorporates:
   *  Gain: '<S116>/Gain'
   *  Trigonometry: '<S117>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_om_tmp_0 = arm_cos_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_n[0] = rtb_VectorConcatenate_om_tmp_0;

  /* Trigonometry: '<S117>/Trigonometric Function' incorporates:
   *  Gain: '<S116>/Gain'
   *  Trigonometry: '<S117>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_om_tmp = arm_sin_f32(-rtu_FMS_In_a);
  rtb_VectorConcatenate_n[1] = rtb_VectorConcatenate_om_tmp;

  /* SignalConversion: '<S117>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S117>/Constant3'
   */
  rtb_VectorConcatenate_n[2] = 0.0F;

  /* Gain: '<S117>/Gain' */
  rtb_VectorConcatenate_n[3] = -rtb_VectorConcatenate_om_tmp;

  /* Trigonometry: '<S117>/Trigonometric Function3' */
  rtb_VectorConcatenate_n[4] = rtb_VectorConcatenate_om_tmp_0;

  /* SignalConversion: '<S117>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S117>/Constant4'
   */
  rtb_VectorConcatenate_n[5] = 0.0F;

  /* SignalConversion: '<S117>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_n[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_n[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_n[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S113>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S113>/Delay'
   *  SignalConversion: '<S113>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S113>/Sum'
   */
  rtb_VectorConcatenate_om_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_om_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S113>/Multiply' incorporates:
   *  SignalConversion: '<S113>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_om[i] = rtb_VectorConcatenate_n[i + 3] *
      rtb_VectorConcatenate_om_tmp + rtb_VectorConcatenate_n[i] *
      rtb_VectorConcatenate_om_tmp_0;
  }

  /* End of Product: '<S113>/Multiply' */

  /* Gain: '<S113>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_om[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_om[1];

  /* Update for Delay: '<S113>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S111>/Move Control'
 *    '<S181>/Move Control'
 */
void FMS_MoveControl_n_Init(DW_MoveControl_FMS_j_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S111>/Move Control'
 *    '<S181>/Move Control'
 */
void FMS_MoveControl_lh_Reset(DW_MoveControl_FMS_j_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S111>/Move Control'
 *    '<S181>/Move Control'
 */
void FMS_MoveControl_k(real32_T rtu_FMS_In, real32_T rtu_FMS_In_j, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_b_T *localC,
  DW_MoveControl_FMS_j_T *localDW)
{
  real32_T rtb_Gain_bc;
  real32_T rtb_Gain_k1;
  real32_T rtb_d_c;
  real32_T rtb_MathFunction1_b;
  real32_T rtb_Add3_jl;
  real32_T rtb_TmpSignalConversionAtSqua_h;
  real32_T u;
  real32_T rtb_Square_me_0;

  /* DeadZone: '<S119>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Gain_k1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Gain_k1 = 0.0F;
  } else {
    rtb_Gain_k1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S119>/Dead Zone' */

  /* Gain: '<S119>/Gain' */
  rtb_Gain_bc = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Gain_k1;

  /* DeadZone: '<S120>/Dead Zone' */
  if (rtu_FMS_In_j > FMS_PARAM.ROLL_DZ) {
    rtb_Gain_k1 = rtu_FMS_In_j - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_j >= -FMS_PARAM.ROLL_DZ) {
    rtb_Gain_k1 = 0.0F;
  } else {
    rtb_Gain_k1 = rtu_FMS_In_j - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S120>/Dead Zone' */

  /* Gain: '<S120>/Gain' */
  rtb_Gain_k1 *= 1.0F / (1.0F - FMS_PARAM.ROLL_DZ);

  /* Sum: '<S122>/Sum of Elements' incorporates:
   *  Math: '<S122>/Square'
   *  SignalConversion: '<S122>/TmpSignal ConversionAtSquareInport1'
   *  Sum: '<S123>/Sum of Elements'
   *  Switch: '<S114>/Switch'
   */
  rtb_MathFunction1_b = rtb_Gain_bc * rtb_Gain_bc + rtb_Gain_k1 * rtb_Gain_k1;

  /* Switch: '<S114>/Switch' incorporates:
   *  Constant: '<S118>/Constant'
   *  Product: '<S123>/Divide'
   *  RelationalOperator: '<S118>/Compare'
   *  Sqrt: '<S122>/Sqrt'
   *  Sum: '<S122>/Sum of Elements'
   */
  if (sqrtf(rtb_MathFunction1_b) > 1.0F) {
    /* Math: '<S123>/Math Function1'
     *
     * About '<S123>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_MathFunction1_b < 0.0F) {
      rtb_MathFunction1_b = -sqrtf(fabsf(rtb_MathFunction1_b));
    } else {
      rtb_MathFunction1_b = sqrtf(rtb_MathFunction1_b);
    }

    /* End of Math: '<S123>/Math Function1' */

    /* Switch: '<S123>/Switch' incorporates:
     *  Constant: '<S123>/Constant'
     *  Product: '<S123>/Product'
     */
    if (rtb_MathFunction1_b <= 0.0F) {
      rtb_Gain_bc = 0.0F;
      rtb_Gain_k1 = 0.0F;
      rtb_MathFunction1_b = 1.0F;
    }

    /* End of Switch: '<S123>/Switch' */
    rtb_Gain_bc /= rtb_MathFunction1_b;
    rtb_Gain_k1 /= rtb_MathFunction1_b;
  }

  /* Saturate: '<S124>/Saturation' incorporates:
   *  Constant: '<S121>/Constant'
   */
  if (FMS_PARAM.STICK_SENS > 1.0F) {
    rtb_MathFunction1_b = 1.0F;
  } else if (FMS_PARAM.STICK_SENS < 0.0F) {
    rtb_MathFunction1_b = 0.0F;
  } else {
    rtb_MathFunction1_b = FMS_PARAM.STICK_SENS;
  }

  /* End of Saturate: '<S124>/Saturation' */

  /* Product: '<S124>/Multiply7' incorporates:
   *  Constant: '<S124>/const'
   */
  rtb_MathFunction1_b *= 980.6F;

  /* Product: '<S124>/Multiply' */
  rtb_d_c = rtb_MathFunction1_b * localC->Square;

  /* Product: '<S124>/Multiply1' incorporates:
   *  Constant: '<S124>/const1'
   *  DiscreteIntegrator: '<S121>/Integrator'
   */
  rtb_Add3_jl = localDW->Integrator_DSTATE[0] * 0.05F;

  /* Sum: '<S124>/Add' incorporates:
   *  DiscreteIntegrator: '<S121>/Integrator1'
   *  Gain: '<S114>/Gain6'
   *  Sum: '<S121>/Subtract'
   */
  rtb_TmpSignalConversionAtSqua_h = (localDW->Integrator1_DSTATE[0] -
    FMS_PARAM.VEL_XY_LIM * rtb_Gain_bc) + rtb_Add3_jl;

  /* Signum: '<S124>/Sign' */
  if (rtb_TmpSignalConversionAtSqua_h < 0.0F) {
    rtb_Gain_bc = -1.0F;
  } else if (rtb_TmpSignalConversionAtSqua_h > 0.0F) {
    rtb_Gain_bc = 1.0F;
  } else {
    rtb_Gain_bc = rtb_TmpSignalConversionAtSqua_h;
  }

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
  rtb_Gain_bc = (sqrtf((8.0F * fabsf(rtb_TmpSignalConversionAtSqua_h) + rtb_d_c)
                       * rtb_d_c) - rtb_d_c) * 0.5F * rtb_Gain_bc + rtb_Add3_jl;

  /* Sum: '<S124>/Add4' */
  rtb_Add3_jl += rtb_TmpSignalConversionAtSqua_h - rtb_Gain_bc;

  /* Sum: '<S124>/Add3' */
  u = rtb_TmpSignalConversionAtSqua_h + rtb_d_c;

  /* Sum: '<S124>/Subtract1' */
  rtb_TmpSignalConversionAtSqua_h -= rtb_d_c;

  /* Signum: '<S124>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S124>/Sign2' */
  if (rtb_TmpSignalConversionAtSqua_h < 0.0F) {
    rtb_TmpSignalConversionAtSqua_h = -1.0F;
  } else {
    if (rtb_TmpSignalConversionAtSqua_h > 0.0F) {
      rtb_TmpSignalConversionAtSqua_h = 1.0F;
    }
  }

  /* Sum: '<S124>/Add5' incorporates:
   *  Gain: '<S124>/Gain2'
   *  Product: '<S124>/Multiply4'
   *  Sum: '<S124>/Subtract2'
   */
  rtb_Gain_bc += (u - rtb_TmpSignalConversionAtSqua_h) * 0.5F * rtb_Add3_jl;

  /* SignalConversion: '<S114>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S121>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S121>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S121>/Integrator'
   */
  localDW->Integrator1_DSTATE[0] += 0.004F * localDW->Integrator_DSTATE[0];

  /* Signum: '<S124>/Sign3' incorporates:
   *  Sum: '<S124>/Add6'
   */
  u = rtb_Gain_bc + rtb_d_c;

  /* Signum: '<S124>/Sign4' incorporates:
   *  Sum: '<S124>/Subtract3'
   */
  rtb_Add3_jl = rtb_Gain_bc - rtb_d_c;

  /* Signum: '<S124>/Sign5' */
  if (rtb_Gain_bc < 0.0F) {
    rtb_TmpSignalConversionAtSqua_h = -1.0F;
  } else if (rtb_Gain_bc > 0.0F) {
    rtb_TmpSignalConversionAtSqua_h = 1.0F;
  } else {
    rtb_TmpSignalConversionAtSqua_h = rtb_Gain_bc;
  }

  /* Signum: '<S124>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S124>/Sign4' */
  if (rtb_Add3_jl < 0.0F) {
    rtb_Add3_jl = -1.0F;
  } else {
    if (rtb_Add3_jl > 0.0F) {
      rtb_Add3_jl = 1.0F;
    }
  }

  /* Signum: '<S124>/Sign6' */
  if (rtb_Gain_bc < 0.0F) {
    rtb_Square_me_0 = -1.0F;
  } else if (rtb_Gain_bc > 0.0F) {
    rtb_Square_me_0 = 1.0F;
  } else {
    rtb_Square_me_0 = rtb_Gain_bc;
  }

  /* Update for DiscreteIntegrator: '<S121>/Integrator' incorporates:
   *  Gain: '<S124>/Gain3'
   *  Gain: '<S124>/Gain4'
   *  Product: '<S124>/Divide'
   *  Product: '<S124>/Multiply5'
   *  Product: '<S124>/Multiply6'
   *  Sum: '<S124>/Subtract4'
   *  Sum: '<S124>/Subtract5'
   *  Sum: '<S124>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Gain_bc / rtb_d_c -
    rtb_TmpSignalConversionAtSqua_h) * -rtb_MathFunction1_b * ((u - rtb_Add3_jl)
    * 0.5F) - rtb_Square_me_0 * rtb_MathFunction1_b) * 0.004F;

  /* Product: '<S124>/Multiply1' incorporates:
   *  Constant: '<S124>/const1'
   *  DiscreteIntegrator: '<S121>/Integrator'
   */
  rtb_Add3_jl = localDW->Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S124>/Add' incorporates:
   *  DiscreteIntegrator: '<S121>/Integrator1'
   *  Gain: '<S114>/Gain6'
   *  Sum: '<S121>/Subtract'
   */
  rtb_TmpSignalConversionAtSqua_h = (localDW->Integrator1_DSTATE[1] -
    FMS_PARAM.VEL_XY_LIM * rtb_Gain_k1) + rtb_Add3_jl;

  /* Signum: '<S124>/Sign' */
  if (rtb_TmpSignalConversionAtSqua_h < 0.0F) {
    rtb_Gain_bc = -1.0F;
  } else if (rtb_TmpSignalConversionAtSqua_h > 0.0F) {
    rtb_Gain_bc = 1.0F;
  } else {
    rtb_Gain_bc = rtb_TmpSignalConversionAtSqua_h;
  }

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
  rtb_Gain_bc = (sqrtf((8.0F * fabsf(rtb_TmpSignalConversionAtSqua_h) + rtb_d_c)
                       * rtb_d_c) - rtb_d_c) * 0.5F * rtb_Gain_bc + rtb_Add3_jl;

  /* Sum: '<S124>/Add4' */
  rtb_Add3_jl += rtb_TmpSignalConversionAtSqua_h - rtb_Gain_bc;

  /* Sum: '<S124>/Add3' */
  u = rtb_TmpSignalConversionAtSqua_h + rtb_d_c;

  /* Sum: '<S124>/Subtract1' */
  rtb_TmpSignalConversionAtSqua_h -= rtb_d_c;

  /* Signum: '<S124>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S124>/Sign2' */
  if (rtb_TmpSignalConversionAtSqua_h < 0.0F) {
    rtb_TmpSignalConversionAtSqua_h = -1.0F;
  } else {
    if (rtb_TmpSignalConversionAtSqua_h > 0.0F) {
      rtb_TmpSignalConversionAtSqua_h = 1.0F;
    }
  }

  /* Sum: '<S124>/Add5' incorporates:
   *  Gain: '<S124>/Gain2'
   *  Product: '<S124>/Multiply4'
   *  Sum: '<S124>/Subtract2'
   */
  rtb_Gain_bc += (u - rtb_TmpSignalConversionAtSqua_h) * 0.5F * rtb_Add3_jl;

  /* SignalConversion: '<S114>/OutportBufferForuv_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S121>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S121>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S121>/Integrator'
   */
  localDW->Integrator1_DSTATE[1] += 0.004F * localDW->Integrator_DSTATE[1];

  /* Signum: '<S124>/Sign3' incorporates:
   *  Sum: '<S124>/Add6'
   */
  u = rtb_Gain_bc + rtb_d_c;

  /* Signum: '<S124>/Sign4' incorporates:
   *  Sum: '<S124>/Subtract3'
   */
  rtb_Add3_jl = rtb_Gain_bc - rtb_d_c;

  /* Signum: '<S124>/Sign5' */
  if (rtb_Gain_bc < 0.0F) {
    rtb_TmpSignalConversionAtSqua_h = -1.0F;
  } else if (rtb_Gain_bc > 0.0F) {
    rtb_TmpSignalConversionAtSqua_h = 1.0F;
  } else {
    rtb_TmpSignalConversionAtSqua_h = rtb_Gain_bc;
  }

  /* Signum: '<S124>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S124>/Sign4' */
  if (rtb_Add3_jl < 0.0F) {
    rtb_Add3_jl = -1.0F;
  } else {
    if (rtb_Add3_jl > 0.0F) {
      rtb_Add3_jl = 1.0F;
    }
  }

  /* Signum: '<S124>/Sign6' */
  if (rtb_Gain_bc < 0.0F) {
    rtb_Square_me_0 = -1.0F;
  } else if (rtb_Gain_bc > 0.0F) {
    rtb_Square_me_0 = 1.0F;
  } else {
    rtb_Square_me_0 = rtb_Gain_bc;
  }

  /* Update for DiscreteIntegrator: '<S121>/Integrator' incorporates:
   *  Gain: '<S124>/Gain3'
   *  Gain: '<S124>/Gain4'
   *  Product: '<S124>/Divide'
   *  Product: '<S124>/Multiply5'
   *  Product: '<S124>/Multiply6'
   *  Sum: '<S124>/Subtract4'
   *  Sum: '<S124>/Subtract5'
   *  Sum: '<S124>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Gain_bc / rtb_d_c -
    rtb_TmpSignalConversionAtSqua_h) * -rtb_MathFunction1_b * ((u - rtb_Add3_jl)
    * 0.5F) - rtb_Square_me_0 * rtb_MathFunction1_b) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S112>/Motion State'
 *    '<S182>/Motion State'
 */
void FMS_MotionState_b_Init(DW_MotionState_FMS_c_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c16_FMS = 0U;
  localDW->is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
}

/*
 * System reset for atomic system:
 *    '<S112>/Motion State'
 *    '<S182>/Motion State'
 */
void FMS_MotionState_jr_Reset(DW_MotionState_FMS_c_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c16_FMS = 0U;
  localDW->is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
}

/*
 * Output and update for atomic system:
 *    '<S112>/Motion State'
 *    '<S182>/Motion State'
 */
void FMS_MotionState_a(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_c_T *localDW)
{
  /* Chart: '<S112>/Motion State' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c16_FMS == 0U) {
    localDW->is_active_c16_FMS = 1U;
    localDW->is_c16_FMS = FMS_IN_Move_h;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c16_FMS) {
     case FMS_IN_Brake_d:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.25F) || (localDW->temporalCounter_i1 >= 750U)) {
        localDW->is_c16_FMS = FMS_IN_Hold_l;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c16_FMS = FMS_IN_Move_h;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_l:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c16_FMS = FMS_IN_Move_h;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c16_FMS = FMS_IN_Brake_d;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S112>/Motion State' */
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
  real_T rtb_Gain_om;
  real_T rtb_Sum3_l;
  real_T rtb_Sum_d;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S545>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S546>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S546>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S546>/Multiply1' incorporates:
   *  Product: '<S546>/Multiply'
   */
  rtb_Gain_om = localC->ff * rtb_Sum2_ee;

  /* Product: '<S546>/Divide' incorporates:
   *  Constant: '<S546>/Constant'
   *  Constant: '<S546>/R'
   *  Sqrt: '<S546>/Sqrt'
   *  Sum: '<S546>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_om);

  /* Product: '<S546>/Product3' incorporates:
   *  Constant: '<S546>/Constant1'
   *  Product: '<S546>/Multiply1'
   *  Sum: '<S546>/Sum2'
   */
  rtb_Gain_om = 1.0 / (1.0 - rtb_Gain_om) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S546>/Multiply2' incorporates:
   *  Trigonometry: '<S546>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S545>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S550>/Abs' incorporates:
   *  Abs: '<S553>/Abs1'
   *  Switch: '<S550>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S550>/Switch1' incorporates:
   *  Abs: '<S550>/Abs'
   *  Bias: '<S550>/Bias2'
   *  Bias: '<S550>/Bias3'
   *  Constant: '<S547>/Constant'
   *  Constant: '<S547>/Constant1'
   *  Constant: '<S552>/Constant'
   *  Gain: '<S550>/Gain1'
   *  Product: '<S550>/Multiply'
   *  RelationalOperator: '<S552>/Compare'
   *  Switch: '<S547>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S553>/Switch1' incorporates:
     *  Bias: '<S553>/Bias2'
     *  Bias: '<S553>/Bias3'
     *  Constant: '<S553>/Constant'
     *  Constant: '<S554>/Constant'
     *  Math: '<S553>/Math Function'
     *  RelationalOperator: '<S554>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S553>/Switch1' */

    /* Signum: '<S550>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S550>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S547>/Sum' incorporates:
   *  Sum: '<S545>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S545>/Multiply' incorporates:
   *  Gain: '<S545>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_om;

  /* Switch: '<S549>/Switch1' incorporates:
   *  Abs: '<S549>/Abs1'
   *  Bias: '<S549>/Bias2'
   *  Bias: '<S549>/Bias3'
   *  Constant: '<S549>/Constant'
   *  Constant: '<S551>/Constant'
   *  Math: '<S549>/Math Function'
   *  RelationalOperator: '<S551>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S549>/Switch1' */

  /* Product: '<S545>/Multiply' incorporates:
   *  Gain: '<S545>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_ee;

  /* Gain: '<S545>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S548>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_om = cos(rtb_Sum2_ee);

  /* Sum: '<S548>/Sum2' incorporates:
   *  Product: '<S548>/Multiply1'
   *  Product: '<S548>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_om + rtb_Sum_d * rtb_Sum3_l;

  /* Product: '<S548>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S548>/Multiply4' */
  rtb_Gain_om *= rtb_Sum_d;

  /* Sum: '<S548>/Sum3' */
  rtb_Sum3_l = rtb_Gain_om - rtb_Sum3_l;

  /* DataTypeConversion: '<S542>/Data Type Conversion' incorporates:
   *  Gain: '<S545>/Gain'
   *  Sum: '<S545>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_ee;
  rty_pos[1] = (real32_T)rtb_Sum3_l;
  rty_pos[2] = (real32_T)-(rtu_lla[2] + rtu_href);
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_exit_internal_Mode(void)
{
  FMS_DW.is_Mode = FMS_IN_NO_ACTIVE_CHILD_h;
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
  boolean_T guard7 = false;

  /* Delay: '<S16>/Delay' */
  if (((FMS_DW.mode_prev != FMS_DW.mode_start) || (FMS_DW.flag_prev !=
        FMS_DW.flag_start)) && (FMS_DW.Delay_DSTATE_cn != PilotMode_None)) {
    FMS_B.degrade = 0.0;
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    guard6 = false;
    guard7 = false;
    if (FMS_DW.Delay_DSTATE_cn == PilotMode_Offboard) {
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U)
           != 0U)) {
        FMS_exit_internal_Mode();
        FMS_DW.is_Mode = FMS_IN_Offboard_h;
        FMS_B.target_mode = PilotMode_Offboard;
      } else {
        FMS_B.degrade = 1.0;
        guard7 = true;
      }
    } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Mission) {
      guard7 = true;
    } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Terrain) {
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
      FMS_exit_internal_Mode();
      FMS_DW.is_Mode = FMS_IN_Unknown;
      FMS_B.target_mode = PilotMode_None;
    }

    if (guard7) {
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 32U) != 0U) && ((FMS_U.INS_Out.flag & 64U)
           != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
        FMS_exit_internal_Mode();
        FMS_DW.is_Mode = FMS_IN_Mission_c;
        FMS_B.target_mode = PilotMode_Mission;
      } else {
        FMS_B.degrade = 1.0;
        guard6 = true;
      }
    }

    if (guard6) {
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U)
           != 0U) && FMS_B.LogicalOperator) {
        FMS_exit_internal_Mode();
        FMS_DW.is_Mode = FMS_IN_Terrain_a;
        FMS_B.target_mode = PilotMode_Terrain;
      } else {
        FMS_B.degrade = 1.0;
        guard5 = true;
      }
    }

    if (guard5) {
      if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U)
          && ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U)
           != 0U)) {
        FMS_exit_internal_Mode();
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
        FMS_exit_internal_Mode();
        FMS_DW.is_Mode = FMS_IN_Stabilize_k;
        FMS_B.target_mode = PilotMode_Stabilize;
      } else {
        FMS_B.degrade = 1.0;
        guard2 = true;
      }
    }

    if (guard2) {
      if ((FMS_U.INS_Out.flag & 4U) != 0U) {
        FMS_exit_internal_Mode();
        FMS_DW.is_Mode = FMS_IN_Acro;
        FMS_B.target_mode = PilotMode_Acro;
      } else {
        FMS_B.degrade = 1.0;
        guard1 = true;
      }
    }

    if (guard1) {
      FMS_exit_internal_Mode();
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

     case FMS_IN_Terrain_a:
      FMS_B.target_mode = PilotMode_Terrain;
      break;

     default:
      FMS_B.target_mode = PilotMode_None;
      break;
    }
  }

  /* End of Delay: '<S16>/Delay' */
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
  boolean_T guard7 = false;
  FMS_B.degrade = 0.0;

  /* Delay: '<S16>/Delay' */
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  guard6 = false;
  guard7 = false;
  if (FMS_DW.Delay_DSTATE_cn == PilotMode_Offboard) {
    if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U) &&
        ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U))
    {
      FMS_DW.is_Mode = FMS_IN_Offboard_h;
      FMS_B.target_mode = PilotMode_Offboard;
    } else {
      FMS_B.degrade = 1.0;
      guard7 = true;
    }
  } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Mission) {
    guard7 = true;
  } else if (FMS_DW.Delay_DSTATE_cn == PilotMode_Terrain) {
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

  if (guard7) {
    if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U) &&
        ((FMS_U.INS_Out.flag & 32U) != 0U) && ((FMS_U.INS_Out.flag & 64U) != 0U)
        && ((FMS_U.INS_Out.flag & 128U) != 0U)) {
      FMS_DW.is_Mode = FMS_IN_Mission_c;
      FMS_B.target_mode = PilotMode_Mission;
    } else {
      FMS_B.degrade = 1.0;
      guard6 = true;
    }
  }

  if (guard6) {
    if (((FMS_U.INS_Out.flag & 4U) != 0U) && ((FMS_U.INS_Out.flag & 16U) != 0U) &&
        ((FMS_U.INS_Out.flag & 64U) != 0U) && ((FMS_U.INS_Out.flag & 128U) != 0U)
        && FMS_B.LogicalOperator) {
      FMS_DW.is_Mode = FMS_IN_Terrain_a;
      FMS_B.target_mode = PilotMode_Terrain;
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

  /* End of Delay: '<S16>/Delay' */
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

      if (mode_in == PilotMode_Terrain) {
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
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;

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

   case PilotMode_Terrain:
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

   case PilotMode_Terrain:
    FMS_DW.is_Assist = FMS_IN_Terrain;
    FMS_B.state = VehicleState_TerrainTrack;
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
    if (FMS_B.LogicalOperator_c) {
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

  /* Outputs for Function Call SubSystem: '<S6>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S555>/Compare' incorporates:
   *  Abs: '<S544>/Abs'
   *  Constant: '<S555>/Constant'
   *  MinMax: '<S544>/Max'
   *  Sum: '<S544>/Sum'
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
                if (FMS_B.LogicalOperator_c) {
                  FMS_DW.is_Offboard = FMS_IN_Run;
                  FMS_B.state = VehicleState_Offboard;
                }
                break;

               case FMS_IN_Run:
                if (!FMS_B.LogicalOperator_c) {
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
                == PilotMode_Offboard) && FMS_B.LogicalOperator_c &&
               (FMS_DW.prep_takeoff != 1.0)) || ((FMS_ManualArmEvent
                (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
                 FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
               ((FMS_B.target_mode != PilotMode_None) && (FMS_DW.prep_takeoff !=
                 1.0)))) {
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
      FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      FMS_B.xy_R[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.xy_R[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;

      /* Outputs for Function Call SubSystem: '<S6>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S543>/Reshape' incorporates:
       *  Constant: '<S543>/Constant'
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
  uint8_T rtb_Switch_mc;
  FMS_Cmd rtb_DataTypeConversion1_fu;
  boolean_T rtb_FixPtRelationalOperator_me;
  real32_T rtb_Saturation_n;
  real32_T rtb_Transpose[9];
  real32_T rtb_MatrixConcatenate3[3];
  real32_T rtb_Multiply_ft[3];
  uint16_T rtb_Divide_dr;
  int8_T rtPrevAction;
  real32_T rtb_Subtract3_od;
  real32_T rtb_Add4_d;
  boolean_T rtb_Compare_on;
  boolean_T rtb_LogicalOperator_aa;
  real32_T rtb_Integrator1_a;
  MotionState rtb_state_c;
  real32_T rtb_Rem_p;
  MotionState rtb_state_l;
  MotionState rtb_state_ki;
  real_T rtb_Switch1_p;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_md;
  uint16_T rtb_y_c1;
  real32_T rtb_VectorConcatenate_j4[9];
  real32_T rtb_VectorConcatenate_n[9];
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
  real32_T rtb_MathFunction_p_idx_0;
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
  real32_T rtb_Divide_l_idx_2;
  real32_T rtb_Divide_l_idx_1;
  real32_T rtb_Divide_l_idx_0;
  real_T rtb_Multiply_l5_idx_0;
  FMS_Error tmp_4;
  FMS_Error tmp_5;
  real32_T u1_tmp;
  uint32_T tmp_6;
  uint32_T tmp_7;
  uint32_T tmp_8;
  boolean_T guard1 = false;

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S18>/FixPt Relational Operator'
   *  UnitDelay: '<S18>/Delay Input1'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
   *  Constant: '<S23>/Constant'
   *  Constant: '<S24>/Constant'
   *  DataTypeConversion: '<S16>/Data Type Conversion2'
   *  Delay: '<S16>/Delay'
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S16>/Logical Operator'
   *  Logic: '<S16>/Logical Operator1'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S25>/FixPt Relational Operator'
   *  Switch: '<S16>/Switch1'
   *  UnitDelay: '<S25>/Delay Input1'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_cn = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S16>/Switch1' incorporates:
       *  DataTypeConversion: '<S16>/Data Type Conversion1'
       *  Delay: '<S16>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_cn = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S16>/Switch' */

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S569>/Constant1'
   *  Delay: '<S569>/Delay'
   *  Inport: '<Root>/Terrain_Info'
   *  RelationalOperator: '<S568>/FixPt Relational Operator'
   *  Switch: '<S569>/Switch'
   *  UnitDelay: '<S568>/Delay Input1'
   *
   * Block description for '<S568>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Terrain_Info.timestamp != FMS_DW.DelayInput1_DSTATE_j) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_m = 0U;
    rtb_Switch_mc = 1U;
  } else {
    rtb_Switch_mc = FMS_DW.Delay_DSTATE_o;
  }

  /* Logic: '<S9>/Logical Operator' incorporates:
   *  Constant: '<S566>/Constant'
   *  Constant: '<S567>/Constant'
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator'
   *  Inport: '<Root>/Terrain_Info'
   *  RelationalOperator: '<S566>/Compare'
   *  RelationalOperator: '<S567>/Compare'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_m < 500U) &&
    (rtb_Switch_mc != 0) && (FMS_U.Terrain_Info.range_m > 0.0F));

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S16>/Delay'
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

  /* DataTypeConversion: '<S15>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_fu = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/Constant1'
   *  DataTypeConversion: '<S15>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S20>/FixPt Relational Operator'
   *  RelationalOperator: '<S21>/FixPt Relational Operator'
   *  Switch: '<S15>/Switch2'
   *  UnitDelay: '<S20>/Delay Input1'
   *  UnitDelay: '<S21>/Delay Input1'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S21>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S15>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_fu;
  } else {
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S27>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S27>/Delay Input1'
   *
   * Block description for '<S27>/Delay Input1':
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
   *  RelationalOperator: '<S26>/FixPt Relational Operator'
   *  UnitDelay: '<S26>/Delay Input1'
   *
   * Block description for '<S26>/Delay Input1':
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
   *  Constant: '<S29>/Constant'
   *  Constant: '<S3>/Constant1'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  RelationalOperator: '<S29>/Compare'
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

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Constant: '<S30>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* Sqrt: '<S565>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S565>/Square'
   *  Sum: '<S565>/Sum of Elements'
   */
  rtb_Saturation_n = sqrtf(((FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0] +
    FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1]) + FMS_U.INS_Out.quat[2] *
    FMS_U.INS_Out.quat[2]) + FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3]);

  /* Product: '<S561>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide_l_idx_0 = FMS_U.INS_Out.quat[0] / rtb_Saturation_n;
  rtb_Divide_l_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Saturation_n;
  rtb_Divide_l_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_n;
  rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.quat[3] / rtb_Saturation_n;

  /* Math: '<S562>/Square' incorporates:
   *  Math: '<S563>/Square'
   *  Math: '<S564>/Square'
   */
  rtb_Subtract3_od = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_0;

  /* Math: '<S562>/Square2' incorporates:
   *  Math: '<S563>/Square2'
   *  Math: '<S564>/Square2'
   */
  rtb_MathFunction_f_idx_1 = rtb_Divide_l_idx_2 * rtb_Divide_l_idx_2;

  /* Math: '<S562>/Square1' incorporates:
   *  Math: '<S563>/Square1'
   *  Math: '<S564>/Square1'
   */
  rtb_Saturation_n = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_1;

  /* Math: '<S562>/Square3' incorporates:
   *  Math: '<S563>/Square3'
   *  Math: '<S564>/Square3'
   */
  rtb_Add4_d = rtb_MathFunction_f_idx_0 * rtb_MathFunction_f_idx_0;

  /* Sum: '<S562>/Subtract' incorporates:
   *  Math: '<S562>/Square'
   *  Math: '<S562>/Square1'
   *  Math: '<S562>/Square2'
   *  Math: '<S562>/Square3'
   *  Sum: '<S562>/Add'
   *  Sum: '<S562>/Add1'
   */
  rtb_Transpose[0] = (rtb_Subtract3_od + rtb_Saturation_n) -
    (rtb_MathFunction_f_idx_1 + rtb_Add4_d);

  /* Product: '<S562>/Multiply' incorporates:
   *  Product: '<S563>/Multiply'
   */
  rtb_Integrator1_a = rtb_Divide_l_idx_1 * rtb_Divide_l_idx_2;

  /* Product: '<S562>/Multiply1' incorporates:
   *  Product: '<S563>/Multiply1'
   */
  rtb_MathFunction_p_idx_0 = rtb_Divide_l_idx_0 * rtb_MathFunction_f_idx_0;

  /* Gain: '<S562>/Gain' incorporates:
   *  Product: '<S562>/Multiply'
   *  Product: '<S562>/Multiply1'
   *  Sum: '<S562>/Subtract1'
   */
  rtb_Transpose[1] = (rtb_Integrator1_a - rtb_MathFunction_p_idx_0) * 2.0F;

  /* Product: '<S562>/Multiply2' incorporates:
   *  Product: '<S564>/Multiply'
   */
  rtb_MathFunction_f_idx_2 = rtb_Divide_l_idx_1 * rtb_MathFunction_f_idx_0;

  /* Product: '<S562>/Multiply3' incorporates:
   *  Product: '<S564>/Multiply1'
   */
  rtb_Switch_mp_idx_1 = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_2;

  /* Gain: '<S562>/Gain1' incorporates:
   *  Product: '<S562>/Multiply2'
   *  Product: '<S562>/Multiply3'
   *  Sum: '<S562>/Add2'
   */
  rtb_Transpose[2] = (rtb_MathFunction_f_idx_2 + rtb_Switch_mp_idx_1) * 2.0F;

  /* Gain: '<S563>/Gain' incorporates:
   *  Sum: '<S563>/Add3'
   */
  rtb_Transpose[3] = (rtb_Integrator1_a + rtb_MathFunction_p_idx_0) * 2.0F;

  /* Sum: '<S563>/Subtract' incorporates:
   *  Sum: '<S563>/Add'
   *  Sum: '<S563>/Add1'
   */
  rtb_Transpose[4] = (rtb_Subtract3_od + rtb_MathFunction_f_idx_1) -
    (rtb_Saturation_n + rtb_Add4_d);

  /* Product: '<S563>/Multiply2' incorporates:
   *  Product: '<S564>/Multiply2'
   */
  rtb_Integrator1_a = rtb_Divide_l_idx_2 * rtb_MathFunction_f_idx_0;

  /* Product: '<S563>/Multiply3' incorporates:
   *  Product: '<S564>/Multiply3'
   */
  rtb_MathFunction_p_idx_0 = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_1;

  /* Gain: '<S563>/Gain1' incorporates:
   *  Product: '<S563>/Multiply2'
   *  Product: '<S563>/Multiply3'
   *  Sum: '<S563>/Subtract1'
   */
  rtb_Transpose[5] = (rtb_Integrator1_a - rtb_MathFunction_p_idx_0) * 2.0F;

  /* Gain: '<S564>/Gain' incorporates:
   *  Sum: '<S564>/Subtract2'
   */
  rtb_Transpose[6] = (rtb_MathFunction_f_idx_2 - rtb_Switch_mp_idx_1) * 2.0F;

  /* Gain: '<S564>/Gain1' incorporates:
   *  Sum: '<S564>/Add2'
   */
  rtb_Transpose[7] = (rtb_Integrator1_a + rtb_MathFunction_p_idx_0) * 2.0F;

  /* Sum: '<S564>/Subtract' incorporates:
   *  Sum: '<S564>/Add'
   *  Sum: '<S564>/Add1'
   */
  rtb_Transpose[8] = (rtb_Subtract3_od + rtb_Add4_d) - (rtb_Saturation_n +
    rtb_MathFunction_f_idx_1);

  /* Math: '<S7>/Transpose' */
  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
    rtb_VectorConcatenate_j4[3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0];
    rtb_VectorConcatenate_j4[1 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 3];
    rtb_VectorConcatenate_j4[2 + 3 * rtb_Compare_bv_0] =
      rtb_Transpose[rtb_Compare_bv_0 + 6];
  }

  for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 9; rtb_Compare_bv_0++) {
    rtb_Transpose[rtb_Compare_bv_0] = rtb_VectorConcatenate_j4[rtb_Compare_bv_0];
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

  /* DiscreteIntegrator: '<S556>/Discrete-Time Integrator5' */
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

  /* DiscreteIntegrator: '<S558>/Discrete-Time Integrator5' incorporates:
   *  DataTypeConversion: '<S558>/Data Type Conversion'
   */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_a != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_Divide_dr;
  }

  /* Product: '<S7>/Multiply1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S7>/Cos'
   *  Trigonometry: '<S7>/Cos1'
   */
  rtb_Subtract3_od = arm_cos_f32(FMS_U.INS_Out.phi) * arm_cos_f32
    (FMS_U.INS_Out.theta);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Subtract3_od > 1.0F) {
    rtb_Subtract3_od = 1.0F;
  } else {
    if (rtb_Subtract3_od < 0.9F) {
      rtb_Subtract3_od = 0.9F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Constant: '<S7>/Land_Lock_Thro'
   */
  rtb_Divide_l_idx_2 = (real32_T)FMS_PARAM.LAND_LOCK_THRO / rtb_Subtract3_od;

  /* DiscreteIntegrator: '<S557>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_Divide_l_idx_2;
  }

  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  DiscreteIntegrator: '<S556>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S557>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S558>/Discrete-Time Integrator5'
   *  Logic: '<S559>/AND'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S559>/Lower Test'
   *  RelationalOperator: '<S559>/Upper Test'
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
   *  Constant: '<S12>/Constant1'
   *  Delay: '<S12>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S11>/FixPt Relational Operator'
   *  Switch: '<S12>/Switch'
   *  UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Auto_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_c) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = 0U;
    FMS_DW.Delay_DSTATE_oi = 1U;
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S13>/Upper Limit'
   *  Delay: '<S12>/Delay'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S13>/Upper Test'
   */
  FMS_B.LogicalOperator_c = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_b < 1000U) &&
    (FMS_DW.Delay_DSTATE_oi != 0) && (FMS_U.Auto_Cmd.frame <= 3));

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

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Constant1'
   */
  if (FMS_B.LogicalOperator2) {
    tmp_5 = FMS_Error_LostLink;
  } else {
    tmp_5 = FMS_Error_None;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Sum: '<S540>/Add' incorporates:
   *  DataTypeConversion: '<S28>/Data Type Conversion'
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
  /* SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_MatrixConcatenate3[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_MatrixConcatenate3[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_MatrixConcatenate3[2] = FMS_B.Cmd_In.sp_waypoint[2];

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

  /* SwitchCase: '<S31>/Switch Case' incorporates:
   *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S33>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
     case 0:
      /* Disable for SwitchCase: '<S40>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S492>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S482>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S424>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

        /* Disable for SwitchCase: '<S402>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

        /* Disable for SwitchCase: '<S412>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S38>/Switch Case' */
      if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
        /* Disable for Resettable SubSystem: '<S198>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S249>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

        /* Disable for SwitchCase: '<S239>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S198>/Mission_SubSystem' */
      }

      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S37>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 5:
        break;

       case 1:
        /* Disable for SwitchCase: '<S140>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S53>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

        /* Disable for SwitchCase: '<S73>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_mn = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S88>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

        /* Disable for SwitchCase: '<S111>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_lm = -1;

        /* Disable for SwitchCase: '<S99>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_bu = -1;
        break;

       case 4:
        /* Disable for SwitchCase: '<S181>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

        /* Disable for SwitchCase: '<S155>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_fi = -1;

        /* Disable for SwitchCase: '<S169>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
      break;

     case 3:
     case 4:
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

    /* End of Disable for SwitchCase: '<S33>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S31>/Disarm' incorporates:
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
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;

    /* End of Outputs for SubSystem: '<S31>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S31>/Standby' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S36>/Bus Assignment'
     *  Constant: '<S36>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S36>/Bus Assignment' incorporates:
     *  Constant: '<S36>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_h;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;

    /* End of Outputs for SubSystem: '<S31>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S31>/Arm' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* SwitchCase: '<S33>/Switch Case' */
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
     case VehicleState_TerrainTrack:
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
        /* Disable for SwitchCase: '<S40>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S492>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S482>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S424>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S402>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S412>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_at = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S38>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_i == 1) {
          /* Disable for Resettable SubSystem: '<S198>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S249>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

          /* Disable for SwitchCase: '<S239>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* End of Disable for SubSystem: '<S198>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 5:
          break;

         case 1:
          /* Disable for SwitchCase: '<S140>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S53>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S73>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_mn = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S88>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S111>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_lm = -1;

          /* Disable for SwitchCase: '<S99>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bu = -1;
          break;

         case 4:
          /* Disable for SwitchCase: '<S181>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S155>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fi = -1;

          /* Disable for SwitchCase: '<S169>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
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
      /* Outputs for IfAction SubSystem: '<S33>/SubMode' incorporates:
       *  ActionPort: '<S40>/Action Port'
       */
      /* SwitchCase: '<S40>/Switch Case' incorporates:
       *  Math: '<S514>/Math Function'
       *  Product: '<S516>/Divide'
       *  Sum: '<S470>/Subtract'
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
          /* Disable for SwitchCase: '<S492>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

          /* Disable for SwitchCase: '<S482>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S424>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

          /* Disable for SwitchCase: '<S402>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

          /* Disable for SwitchCase: '<S412>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_at) {
       case 0:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S40>/Takeoff' incorporates:
           *  ActionPort: '<S397>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S40>/Switch Case' incorporates:
           *  Delay: '<S538>/cur_waypoint'
           *  DiscreteIntegrator: '<S534>/Integrator'
           *  DiscreteIntegrator: '<S534>/Integrator1'
           */
          FMS_DW.icLoad_j1 = 1U;
          FMS_DW.Integrator1_DSTATE_a = 0.0F;
          FMS_DW.Integrator_DSTATE_m = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S40>/Takeoff' */
        }

        /* Outputs for IfAction SubSystem: '<S40>/Takeoff' incorporates:
         *  ActionPort: '<S397>/Action Port'
         */
        /* Delay: '<S538>/cur_waypoint' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_DW.icLoad_j1 != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
          FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
          FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Product: '<S538>/Divide' incorporates:
         *  Delay: '<S538>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S538>/Sum1'
         *  Sum: '<S538>/Sum2'
         */
        rtb_Saturation_n = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
          FMS_DW.cur_waypoint_DSTATE[2]);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Saturate: '<S538>/Saturation' */
        if (rtb_Saturation_n > 1.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = 0.0F;
          }
        }

        /* End of Saturate: '<S538>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S539>/Trigonometric Function1' incorporates:
         *  Gain: '<S537>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Trigonometry: '<S539>/Trigonometric Function3'
         */
        rtb_Subtract3_od = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[0] = rtb_Subtract3_od;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S539>/Trigonometric Function' incorporates:
         *  Gain: '<S537>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Trigonometry: '<S539>/Trigonometric Function2'
         */
        rtb_MathFunction_f_idx_1 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Transpose[1] = rtb_MathFunction_f_idx_1;

        /* SignalConversion: '<S539>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S539>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Gain: '<S539>/Gain' */
        rtb_Transpose[3] = -rtb_MathFunction_f_idx_1;

        /* Trigonometry: '<S539>/Trigonometric Function3' */
        rtb_Transpose[4] = rtb_Subtract3_od;

        /* SignalConversion: '<S539>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S539>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S539>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S531>/Saturation1' */
        rtb_Divide_l_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_MathFunction_p_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S531>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Delay: '<S538>/cur_waypoint'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S538>/Multiply'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S531>/Sum'
         *  Sum: '<S538>/Sum3'
         *  Sum: '<S538>/Sum4'
         */
        rtb_Add4_d = ((FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.cur_waypoint_DSTATE
                       [0]) * rtb_Saturation_n + FMS_DW.cur_waypoint_DSTATE[0])
          - FMS_U.INS_Out.x_R;
        rtb_Integrator1_a = ((FMS_B.Cmd_In.sp_waypoint[1] -
                              FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Saturation_n
                             + FMS_DW.cur_waypoint_DSTATE[1]) -
          FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S531>/Multiply' */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Integrator1_a + rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_d;
        }

        /* Saturate: '<S531>/Saturation1' incorporates:
         *  Gain: '<S531>/Gain2'
         *  Product: '<S531>/Multiply'
         */
        rtb_Subtract3_od = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Saturation_n = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S397>/Bus Assignment1'
         *  Constant: '<S397>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S397>/Bus Assignment1' incorporates:
         *  Constant: '<S397>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S531>/Saturation1' */
        if (rtb_Subtract3_od > rtb_Divide_l_idx_0) {
          /* BusAssignment: '<S397>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_0;
        } else if (rtb_Subtract3_od < rtb_MathFunction_p_idx_0) {
          /* BusAssignment: '<S397>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MathFunction_p_idx_0;
        } else {
          /* BusAssignment: '<S397>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_od;
        }

        if (rtb_Saturation_n > rtb_Divide_l_idx_0) {
          /* BusAssignment: '<S397>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_0;
        } else if (rtb_Saturation_n < rtb_MathFunction_p_idx_0) {
          /* BusAssignment: '<S397>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction_p_idx_0;
        } else {
          /* BusAssignment: '<S397>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        }

        /* BusAssignment: '<S397>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S534>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_a;

        /* Product: '<S535>/Multiply1' incorporates:
         *  Constant: '<S535>/const1'
         *  DiscreteIntegrator: '<S534>/Integrator'
         */
        rtb_Saturation_n = FMS_DW.Integrator_DSTATE_m * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S530>/Switch' incorporates:
         *  Abs: '<S530>/Abs'
         *  Abs: '<S530>/Abs1'
         *  Constant: '<S530>/Takeoff_Speed'
         *  Constant: '<S532>/Constant'
         *  Constant: '<S533>/Constant'
         *  Gain: '<S530>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S530>/Logical Operator'
         *  RelationalOperator: '<S532>/Compare'
         *  RelationalOperator: '<S533>/Compare'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S530>/Sum'
         *  Sum: '<S530>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F)) {
          rtb_Divide_l_idx_0 = -FMS_PARAM.TAKEOFF_SPEED;
        } else {
          rtb_Divide_l_idx_0 = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
        }

        /* End of Switch: '<S530>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S535>/Add' incorporates:
         *  DiscreteIntegrator: '<S534>/Integrator1'
         *  Sum: '<S534>/Subtract'
         */
        rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE_a - rtb_Divide_l_idx_0) +
          rtb_Saturation_n;

        /* Signum: '<S535>/Sign' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Divide_l_idx_0 = -1.0F;
        } else if (rtb_Subtract3_od > 0.0F) {
          rtb_Divide_l_idx_0 = 1.0F;
        } else {
          rtb_Divide_l_idx_0 = rtb_Subtract3_od;
        }

        /* End of Signum: '<S535>/Sign' */

        /* Sum: '<S535>/Add2' incorporates:
         *  Abs: '<S535>/Abs'
         *  Gain: '<S535>/Gain'
         *  Gain: '<S535>/Gain1'
         *  Product: '<S535>/Multiply2'
         *  Product: '<S535>/Multiply3'
         *  Sqrt: '<S535>/Sqrt'
         *  Sum: '<S535>/Add1'
         *  Sum: '<S535>/Subtract'
         */
        rtb_Divide_l_idx_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
          FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
          rtb_Divide_l_idx_0 + rtb_Saturation_n;

        /* Sum: '<S535>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_od - rtb_Divide_l_idx_0) + rtb_Saturation_n;

        /* Sum: '<S535>/Add3' */
        rtb_Saturation_n = rtb_Subtract3_od + FMS_ConstB.d_m;

        /* Sum: '<S535>/Subtract1' */
        rtb_Subtract3_od -= FMS_ConstB.d_m;

        /* Signum: '<S535>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S535>/Sign1' */

        /* Signum: '<S535>/Sign2' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S535>/Sign2' */

        /* Sum: '<S535>/Add5' incorporates:
         *  Gain: '<S535>/Gain2'
         *  Product: '<S535>/Multiply4'
         *  Sum: '<S535>/Subtract2'
         */
        rtb_Divide_l_idx_0 += (rtb_Saturation_n - rtb_Subtract3_od) * 0.5F *
          rtb_Add4_d;

        /* Update for Delay: '<S538>/cur_waypoint' */
        FMS_DW.icLoad_j1 = 0U;

        /* Update for DiscreteIntegrator: '<S534>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S534>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_m;

        /* Sum: '<S535>/Add6' */
        rtb_Saturation_n = rtb_Divide_l_idx_0 + FMS_ConstB.d_m;

        /* Sum: '<S535>/Subtract3' */
        rtb_Subtract3_od = rtb_Divide_l_idx_0 - FMS_ConstB.d_m;

        /* Signum: '<S535>/Sign5' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S535>/Sign5' */

        /* Signum: '<S535>/Sign3' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S535>/Sign3' */

        /* Signum: '<S535>/Sign4' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S535>/Sign4' */

        /* Signum: '<S535>/Sign6' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_Integrator1_a = 1.0F;
        } else {
          rtb_Integrator1_a = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S535>/Sign6' */

        /* Update for DiscreteIntegrator: '<S534>/Integrator' incorporates:
         *  Constant: '<S535>/const'
         *  Gain: '<S535>/Gain3'
         *  Product: '<S535>/Divide'
         *  Product: '<S535>/Multiply5'
         *  Product: '<S535>/Multiply6'
         *  Sum: '<S535>/Subtract4'
         *  Sum: '<S535>/Subtract5'
         *  Sum: '<S535>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_m += ((rtb_Divide_l_idx_0 / FMS_ConstB.d_m -
          rtb_Add4_d) * FMS_ConstB.Gain4_a * ((rtb_Saturation_n -
          rtb_Subtract3_od) * 0.5F) - rtb_Integrator1_a * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S40>/Takeoff' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S40>/Land' incorporates:
           *  ActionPort: '<S395>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S40>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S440>/Integrator'
           *  DiscreteIntegrator: '<S440>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_j = 0.0F;
          FMS_DW.Integrator_DSTATE_d = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S40>/Land' */
        }

        /* Outputs for IfAction SubSystem: '<S40>/Land' incorporates:
         *  ActionPort: '<S395>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S445>/Trigonometric Function1' incorporates:
         *  Gain: '<S444>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S445>/Trigonometric Function' incorporates:
         *  Gain: '<S444>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S445>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S445>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S445>/Gain' incorporates:
         *  Gain: '<S444>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Trigonometry: '<S445>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S445>/Trigonometric Function3' incorporates:
         *  Gain: '<S444>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S445>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S445>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S445>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S438>/Saturation1' */
        rtb_Add4_d = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Divide_l_idx_0 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* SignalConversion: '<S442>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S442>/Sum'
         */
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Subtract3_od = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S442>/Multiply' incorporates:
         *  SignalConversion: '<S442>/TmpSignal ConversionAtMultiplyInport2'
         *  Sum: '<S442>/Sum'
         */
        for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
          rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 + 3]
            * rtb_Subtract3_od + rtb_Transpose[rtb_Compare_bv_0] *
            rtb_Saturation_n;
        }

        /* End of Product: '<S442>/Multiply' */

        /* Saturate: '<S438>/Saturation1' incorporates:
         *  Gain: '<S442>/Gain2'
         */
        rtb_Subtract3_od = FMS_PARAM.XY_P * rtb_Transpose_0[0];
        rtb_Saturation_n = FMS_PARAM.XY_P * rtb_Transpose_0[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S395>/Bus Assignment1'
         *  Constant: '<S395>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S395>/Bus Assignment1' incorporates:
         *  Constant: '<S395>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_ml;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S438>/Saturation1' */
        if (rtb_Subtract3_od > rtb_Add4_d) {
          /* BusAssignment: '<S395>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_d;
        } else if (rtb_Subtract3_od < rtb_Divide_l_idx_0) {
          /* BusAssignment: '<S395>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Divide_l_idx_0;
        } else {
          /* BusAssignment: '<S395>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_od;
        }

        if (rtb_Saturation_n > rtb_Add4_d) {
          /* BusAssignment: '<S395>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add4_d;
        } else if (rtb_Saturation_n < rtb_Divide_l_idx_0) {
          /* BusAssignment: '<S395>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Divide_l_idx_0;
        } else {
          /* BusAssignment: '<S395>/Bus Assignment1' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_n;
        }

        /* BusAssignment: '<S395>/Bus Assignment1' incorporates:
         *  DiscreteIntegrator: '<S440>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_j;

        /* Product: '<S441>/Multiply1' incorporates:
         *  Constant: '<S441>/const1'
         *  DiscreteIntegrator: '<S440>/Integrator'
         */
        rtb_Saturation_n = FMS_DW.Integrator_DSTATE_d * 0.35F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S437>/Switch' incorporates:
         *  Constant: '<S437>/Land_Speed'
         *  Constant: '<S439>/Constant'
         *  Gain: '<S437>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S437>/Logical Operator'
         *  RelationalOperator: '<S439>/Compare'
         *  S-Function (sfix_bitop): '<S437>/cmd_p valid'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
             FMS_PARAM.ASSIST_LAND_H)) {
          rtb_Divide_l_idx_0 = 0.5F * FMS_PARAM.LAND_SPEED;
        } else {
          rtb_Divide_l_idx_0 = FMS_PARAM.LAND_SPEED;
        }

        /* End of Switch: '<S437>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S441>/Add' incorporates:
         *  DiscreteIntegrator: '<S440>/Integrator1'
         *  Sum: '<S440>/Subtract'
         */
        rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE_j - rtb_Divide_l_idx_0) +
          rtb_Saturation_n;

        /* Signum: '<S441>/Sign' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Divide_l_idx_0 = -1.0F;
        } else if (rtb_Subtract3_od > 0.0F) {
          rtb_Divide_l_idx_0 = 1.0F;
        } else {
          rtb_Divide_l_idx_0 = rtb_Subtract3_od;
        }

        /* End of Signum: '<S441>/Sign' */

        /* Sum: '<S441>/Add2' incorporates:
         *  Abs: '<S441>/Abs'
         *  Gain: '<S441>/Gain'
         *  Gain: '<S441>/Gain1'
         *  Product: '<S441>/Multiply2'
         *  Product: '<S441>/Multiply3'
         *  Sqrt: '<S441>/Sqrt'
         *  Sum: '<S441>/Add1'
         *  Sum: '<S441>/Subtract'
         */
        rtb_Divide_l_idx_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
          FMS_ConstB.d_p) * FMS_ConstB.d_p) - FMS_ConstB.d_p) * 0.5F *
          rtb_Divide_l_idx_0 + rtb_Saturation_n;

        /* Sum: '<S441>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_od - rtb_Divide_l_idx_0) + rtb_Saturation_n;

        /* Sum: '<S441>/Add3' */
        rtb_Saturation_n = rtb_Subtract3_od + FMS_ConstB.d_p;

        /* Sum: '<S441>/Subtract1' */
        rtb_Subtract3_od -= FMS_ConstB.d_p;

        /* Signum: '<S441>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S441>/Sign1' */

        /* Signum: '<S441>/Sign2' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S441>/Sign2' */

        /* Sum: '<S441>/Add5' incorporates:
         *  Gain: '<S441>/Gain2'
         *  Product: '<S441>/Multiply4'
         *  Sum: '<S441>/Subtract2'
         */
        rtb_Divide_l_idx_0 += (rtb_Saturation_n - rtb_Subtract3_od) * 0.5F *
          rtb_Add4_d;

        /* Update for DiscreteIntegrator: '<S440>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S440>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_d;

        /* Sum: '<S441>/Add6' */
        rtb_Saturation_n = rtb_Divide_l_idx_0 + FMS_ConstB.d_p;

        /* Sum: '<S441>/Subtract3' */
        rtb_Subtract3_od = rtb_Divide_l_idx_0 - FMS_ConstB.d_p;

        /* Signum: '<S441>/Sign5' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S441>/Sign5' */

        /* Signum: '<S441>/Sign3' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S441>/Sign3' */

        /* Signum: '<S441>/Sign4' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S441>/Sign4' */

        /* Signum: '<S441>/Sign6' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_Integrator1_a = 1.0F;
        } else {
          rtb_Integrator1_a = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S441>/Sign6' */

        /* Update for DiscreteIntegrator: '<S440>/Integrator' incorporates:
         *  Constant: '<S441>/const'
         *  Gain: '<S441>/Gain3'
         *  Product: '<S441>/Divide'
         *  Product: '<S441>/Multiply5'
         *  Product: '<S441>/Multiply6'
         *  Sum: '<S441>/Subtract4'
         *  Sum: '<S441>/Subtract5'
         *  Sum: '<S441>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_d += ((rtb_Divide_l_idx_0 / FMS_ConstB.d_p -
          rtb_Add4_d) * FMS_ConstB.Gain4_e * ((rtb_Saturation_n -
          rtb_Subtract3_od) * 0.5F) - rtb_Integrator1_a * 9.806F) * 0.004F;

        /* End of Outputs for SubSystem: '<S40>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S40>/Return' incorporates:
           *  ActionPort: '<S396>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S40>/Switch Case' incorporates:
           *  Delay: '<S448>/Delay'
           *  Delay: '<S449>/Delay'
           *  Delay: '<S471>/Delay'
           *  Delay: '<S471>/Delay1'
           *  DiscreteIntegrator: '<S452>/Integrator'
           *  DiscreteIntegrator: '<S452>/Integrator1'
           *  DiscreteIntegrator: '<S467>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S472>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S521>/Discrete-Time Integrator'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTAT_mx = 0U;
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

          /* End of InitializeConditions for SubSystem: '<S40>/Return' */

          /* SystemReset for IfAction SubSystem: '<S40>/Return' incorporates:
           *  ActionPort: '<S396>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S40>/Switch Case' incorporates:
           *  Chart: '<S483>/Motion Status'
           *  Chart: '<S493>/Motion State'
           */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

          /* End of SystemReset for SubSystem: '<S40>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S40>/Return' incorporates:
         *  ActionPort: '<S396>/Action Port'
         */
        /* RelationalOperator: '<S466>/Compare' incorporates:
         *  Constant: '<S529>/Constant'
         *  DiscreteIntegrator: '<S472>/Discrete-Time Integrator'
         *  RelationalOperator: '<S529>/Compare'
         */
        rtb_Compare_on = (FMS_DW.DiscreteTimeIntegrator_DSTAT_mx <= 3);

        /* Logic: '<S471>/Logical Operator' incorporates:
         *  Delay: '<S471>/Delay1'
         */
        rtb_LogicalOperator_aa = (rtb_Compare_on || FMS_DW.Delay1_DSTATE_b);

        /* Delay: '<S471>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
        /* RelationalOperator: '<S476>/Compare' incorporates:
         *  Constant: '<S476>/Constant'
         *  Delay: '<S471>/Delay1'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        FMS_DW.Delay1_DSTATE_b = (FMS_B.Cmd_In.set_speed > 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S467>/Switch2' incorporates:
         *  Constant: '<S467>/vel'
         *  Delay: '<S471>/Delay1'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_DW.Delay1_DSTATE_b) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Add4_d = FMS_B.Cmd_In.set_speed;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_Add4_d = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S467>/Switch2' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S471>/Sum' incorporates:
         *  Delay: '<S471>/Delay'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_e[0];

        /* Sum: '<S467>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* Sum: '<S471>/Sum' incorporates:
         *  Delay: '<S471>/Delay'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_p_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_e[1];

        /* Sum: '<S467>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_h_idx_0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint
          [1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S479>/Sqrt' incorporates:
         *  Math: '<S479>/Square'
         *  Sum: '<S467>/Sum'
         *  Sum: '<S479>/Sum of Elements'
         */
        rtb_Subtract3_od = sqrtf(rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0);

        /* Switch: '<S467>/Switch' */
        if (rtb_Subtract3_od > FMS_PARAM.L1) {
          B = rtb_Add4_d;
        } else {
          /* Gain: '<S467>/Gain' */
          B = 0.5F * rtb_Subtract3_od;

          /* Switch: '<S477>/Switch2' incorporates:
           *  Constant: '<S467>/Constant1'
           *  RelationalOperator: '<S477>/LowerRelop1'
           *  RelationalOperator: '<S477>/UpperRelop'
           *  Switch: '<S477>/Switch'
           */
          if (B > rtb_Add4_d) {
            B = rtb_Add4_d;
          } else {
            if (B < 0.5F) {
              /* Switch: '<S477>/Switch' incorporates:
               *  Constant: '<S467>/Constant1'
               */
              B = 0.5F;
            }
          }

          /* End of Switch: '<S477>/Switch2' */
        }

        /* End of Switch: '<S467>/Switch' */

        /* DiscreteIntegrator: '<S467>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
        }

        /* Switch: '<S478>/Switch2' incorporates:
         *  Constant: '<S467>/Constant2'
         *  DiscreteIntegrator: '<S467>/Acceleration_Speed'
         *  RelationalOperator: '<S478>/LowerRelop1'
         *  RelationalOperator: '<S478>/UpperRelop'
         *  Switch: '<S478>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE_j > rtb_Add4_d) {
          rtb_Integrator1_a = rtb_Add4_d;
        } else if (FMS_DW.Acceleration_Speed_DSTATE_j < 0.0F) {
          /* Switch: '<S478>/Switch' incorporates:
           *  Constant: '<S467>/Constant2'
           */
          rtb_Integrator1_a = 0.0F;
        } else {
          rtb_Integrator1_a = FMS_DW.Acceleration_Speed_DSTATE_j;
        }

        /* End of Switch: '<S478>/Switch2' */

        /* Switch: '<S467>/Switch1' incorporates:
         *  Sum: '<S467>/Sum1'
         */
        if (rtb_Integrator1_a - B >= 0.0F) {
          rtb_Integrator1_a = B;
        }

        /* End of Switch: '<S467>/Switch1' */

        /* DiscreteIntegrator: '<S521>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRe_e !=
             0)) {
          FMS_DW.l1_heading_e = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S493>/Motion State' incorporates:
         *  Constant: '<S493>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S493>/Square'
         *  Math: '<S493>/Square1'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sqrt: '<S493>/Sqrt'
         *  Sum: '<S493>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S492>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S492>/Hold Control' incorporates:
             *  ActionPort: '<S495>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S492>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_m);

            /* End of SystemReset for SubSystem: '<S492>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S492>/Hold Control' incorporates:
           *  ActionPort: '<S495>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_ah,
                            &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S492>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S492>/Brake Control' incorporates:
           *  ActionPort: '<S494>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_ah);

          /* End of Outputs for SubSystem: '<S492>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S492>/Move Control' incorporates:
             *  ActionPort: '<S496>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S492>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_j);

            /* End of SystemReset for SubSystem: '<S492>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S492>/Move Control' incorporates:
           *  ActionPort: '<S496>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_ah,
                            &FMS_ConstB.MoveControl_j, &FMS_DW.MoveControl_j);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S492>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S492>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S483>/Motion Status' incorporates:
         *  Abs: '<S483>/Abs'
         *  Constant: '<S483>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S482>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S482>/Hold Control' incorporates:
             *  ActionPort: '<S485>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S482>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S482>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S482>/Hold Control' incorporates:
           *  ActionPort: '<S485>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_jj,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S482>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S482>/Brake Control' incorporates:
           *  ActionPort: '<S484>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_jj);

          /* End of Outputs for SubSystem: '<S482>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ld != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S482>/Move Control' incorporates:
             *  ActionPort: '<S486>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S482>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl);

            /* End of SystemReset for SubSystem: '<S482>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S482>/Move Control' incorporates:
           *  ActionPort: '<S486>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_jj,
                          &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S482>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S482>/Switch Case' */

        /* Switch: '<S447>/Switch' incorporates:
         *  Product: '<S471>/Multiply'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S492>/Saturation1' */
          if (FMS_B.Merge_ah[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_ah[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[0] = FMS_B.Merge_ah[0];
          }

          if (FMS_B.Merge_ah[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_ah[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_TmpSignalConversionAtMath_c[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[1] = FMS_B.Merge_ah[1];
          }

          /* End of Saturate: '<S492>/Saturation1' */

          /* Saturate: '<S482>/Saturation1' */
          if (FMS_B.Merge_jj > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_jj < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_jj;
          }

          /* End of Saturate: '<S482>/Saturation1' */
        } else {
          /* SignalConversion: '<S528>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S528>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S527>/Gain' incorporates:
           *  DiscreteIntegrator: '<S521>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
           *  Sum: '<S521>/Add'
           */
          rtb_MathFunction_f_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S528>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S528>/Trigonometric Function1'
           */
          rtb_Subtract3_od = arm_cos_f32(rtb_MathFunction_f_idx_0);
          rtb_Transpose[4] = rtb_Subtract3_od;

          /* Trigonometry: '<S528>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S528>/Trigonometric Function'
           */
          rtb_MathFunction_f_idx_1 = arm_sin_f32(rtb_MathFunction_f_idx_0);

          /* Gain: '<S528>/Gain' incorporates:
           *  Trigonometry: '<S528>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -rtb_MathFunction_f_idx_1;

          /* SignalConversion: '<S528>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S528>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S528>/Trigonometric Function' */
          rtb_Transpose[1] = rtb_MathFunction_f_idx_1;

          /* Trigonometry: '<S528>/Trigonometric Function1' */
          rtb_Transpose[0] = rtb_Subtract3_od;

          /* SignalConversion: '<S528>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Sum: '<S523>/Sum of Elements' incorporates:
           *  Math: '<S523>/Math Function'
           *  SignalConversion: '<S523>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_0 = rtb_Saturation_n * rtb_Saturation_n +
            rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0;

          /* Math: '<S523>/Math Function1' incorporates:
           *  Sum: '<S523>/Sum of Elements'
           *
           * About '<S523>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_MathFunction_f_idx_0 = -sqrtf(fabsf(rtb_Divide_l_idx_0));
          } else {
            rtb_MathFunction_f_idx_0 = sqrtf(rtb_Divide_l_idx_0);
          }

          /* End of Math: '<S523>/Math Function1' */

          /* Switch: '<S523>/Switch' incorporates:
           *  Constant: '<S523>/Constant'
           *  Product: '<S523>/Product'
           */
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_Divide_l_idx_0 = rtb_Saturation_n;
            rtb_Divide_l_idx_1 = rtb_MathFunction_p_idx_0;
          } else {
            rtb_Divide_l_idx_0 = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_MathFunction_f_idx_0 = 1.0F;
          }

          /* End of Switch: '<S523>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S473>/Sum1' incorporates:
           *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S473>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
           *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract3_od = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.y_R -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S473>/Divide' incorporates:
           *  Math: '<S474>/Square'
           *  Math: '<S475>/Square'
           *  Sqrt: '<S474>/Sqrt'
           *  Sqrt: '<S475>/Sqrt'
           *  Sum: '<S473>/Sum'
           *  Sum: '<S473>/Sum1'
           *  Sum: '<S474>/Sum of Elements'
           *  Sum: '<S475>/Sum of Elements'
           */
          rtb_Subtract3_od = sqrtf(rtb_Subtract3_od * rtb_Subtract3_od +
            rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_1) / sqrtf
            (rtb_P_l_idx_0 * rtb_P_l_idx_0 + rtb_MathFunction_h_idx_0 *
             rtb_MathFunction_h_idx_0);

          /* Saturate: '<S473>/Saturation' */
          if (rtb_Subtract3_od > 1.0F) {
            rtb_Subtract3_od = 1.0F;
          } else {
            if (rtb_Subtract3_od < 0.0F) {
              rtb_Subtract3_od = 0.0F;
            }
          }

          /* End of Saturate: '<S473>/Saturation' */

          /* Product: '<S519>/Multiply2' incorporates:
           *  Product: '<S523>/Divide'
           */
          rtb_Divide_l_idx_0 = rtb_Divide_l_idx_0 / rtb_MathFunction_f_idx_0 *
            rtb_Integrator1_a;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_MathFunction_f_idx_0 *
            rtb_Integrator1_a;

          /* Product: '<S471>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Divide_l_idx_1 + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Divide_l_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S464>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S473>/Multiply'
           *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
           *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S464>/Sum2'
           *  Sum: '<S473>/Add'
           *  Sum: '<S473>/Subtract'
           */
          rtb_Subtract3_od = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Subtract3_od +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S464>/Saturation1' incorporates:
           *  Product: '<S471>/Multiply'
           */
          if (rtb_Subtract3_od > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Subtract3_od < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Subtract3_od;
          }

          /* End of Saturate: '<S464>/Saturation1' */
        }

        /* End of Switch: '<S447>/Switch' */

        /* Delay: '<S449>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S452>/Integrator1' incorporates:
         *  Delay: '<S449>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING_j != 0) {
          FMS_DW.Integrator1_DSTATE_e = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S456>/Rem' incorporates:
         *  Constant: '<S456>/Constant1'
         *  DiscreteIntegrator: '<S452>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sum: '<S451>/Sum'
         */
        B = rt_remf(FMS_DW.Integrator1_DSTATE_e - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S456>/Switch' incorporates:
         *  Abs: '<S456>/Abs'
         *  Constant: '<S456>/Constant'
         *  Constant: '<S457>/Constant'
         *  Product: '<S456>/Multiply'
         *  RelationalOperator: '<S457>/Compare'
         *  Sum: '<S456>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S456>/Sign' */
          if (B < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else if (B > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          } else {
            rtb_Subtract3_od = B;
          }

          /* End of Signum: '<S456>/Sign' */
          B -= 6.28318548F * rtb_Subtract3_od;
        }

        /* End of Switch: '<S456>/Switch' */

        /* Gain: '<S451>/Gain2' */
        B *= FMS_PARAM.YAW_P;

        /* Saturate: '<S451>/Saturation' */
        if (B > FMS_PARAM.YAW_RATE_LIM) {
          B = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (B < -FMS_PARAM.YAW_RATE_LIM) {
            B = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S451>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S396>/Bus Assignment1'
         *  Constant: '<S396>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S396>/Bus Assignment1' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = B;

        /* Sum: '<S525>/Sum of Elements' incorporates:
         *  Math: '<S525>/Math Function'
         *  SignalConversion: '<S525>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_0 = rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0
          + rtb_Saturation_n * rtb_Saturation_n;

        /* Math: '<S525>/Math Function1' incorporates:
         *  Sum: '<S525>/Sum of Elements'
         *
         * About '<S525>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_l_idx_0));
        } else {
          B = sqrtf(rtb_Divide_l_idx_0);
        }

        /* End of Math: '<S525>/Math Function1' */

        /* Switch: '<S525>/Switch' incorporates:
         *  Constant: '<S525>/Constant'
         *  Product: '<S525>/Product'
         */
        if (B > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_MathFunction_p_idx_0;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Saturation_n;
          rtb_TmpSignalConversionAtMath_c[2] = B;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S525>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S513>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S513>/Math Function'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sum: '<S511>/Sum of Elements'
         */
        rtb_Divide_l_idx_0 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S513>/Math Function1' incorporates:
         *  Sum: '<S513>/Sum of Elements'
         *
         * About '<S513>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          B = -sqrtf(fabsf(rtb_Divide_l_idx_0));
        } else {
          B = sqrtf(rtb_Divide_l_idx_0);
        }

        /* End of Math: '<S513>/Math Function1' */

        /* Switch: '<S513>/Switch' incorporates:
         *  Constant: '<S513>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S513>/Product'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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

        /* End of Switch: '<S513>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S471>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_mp_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Switch_mp_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S526>/Sum of Elements' incorporates:
         *  Math: '<S526>/Math Function'
         *  Sum: '<S471>/Sum1'
         */
        rtb_Rem_p = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 +
          rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1;

        /* Math: '<S526>/Math Function1' incorporates:
         *  Sum: '<S526>/Sum of Elements'
         *
         * About '<S526>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S526>/Math Function1' */

        /* Switch: '<S526>/Switch' incorporates:
         *  Constant: '<S526>/Constant'
         *  Product: '<S526>/Product'
         */
        if (B > 0.0F) {
          rtb_Switch_mp_idx_2 = B;
        } else {
          rtb_Switch_mp_idx_0 = 0.0F;
          rtb_Switch_mp_idx_1 = 0.0F;
          rtb_Switch_mp_idx_2 = 1.0F;
        }

        /* End of Switch: '<S526>/Switch' */

        /* Delay: '<S448>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_DW.icLoad_c != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S396>/Sum' incorporates:
         *  Delay: '<S448>/Delay'
         *  MATLAB Function: '<S469>/OutRegionRegWP'
         *  MATLAB Function: '<S469>/SearchL1RefWP'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_MathFunction_h_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S463>/Sum of Elements' incorporates:
         *  Math: '<S463>/Math Function'
         *  Sum: '<S396>/Sum'
         */
        rtb_Rem_p = rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0 +
          rtb_P_l_idx_0 * rtb_P_l_idx_0;

        /* Math: '<S463>/Math Function1' incorporates:
         *  Sum: '<S463>/Sum of Elements'
         *
         * About '<S463>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S463>/Math Function1' */

        /* Switch: '<S463>/Switch' incorporates:
         *  Constant: '<S463>/Constant'
         *  Product: '<S463>/Product'
         *  Sum: '<S396>/Sum'
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

        /* End of Switch: '<S463>/Switch' */

        /* Product: '<S513>/Divide' */
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sum: '<S516>/Sum of Elements' incorporates:
         *  Math: '<S516>/Math Function'
         *  SignalConversion: '<S516>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = rtb_Sum_ff[1] * rtb_Sum_ff[1] + rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Math: '<S516>/Math Function1' incorporates:
         *  Sum: '<S516>/Sum of Elements'
         *
         * About '<S516>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          B = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          B = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S516>/Math Function1' */

        /* Switch: '<S516>/Switch' incorporates:
         *  Constant: '<S516>/Constant'
         *  Product: '<S516>/Product'
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

        /* End of Switch: '<S516>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S469>/NearbyRefWP' incorporates:
         *  Constant: '<S396>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_ff, &rtb_Rem_p);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* MATLAB Function: '<S469>/SearchL1RefWP' incorporates:
         *  Constant: '<S396>/L1'
         *  Delay: '<S448>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Subtract3_od = rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

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
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Subtract3_od);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Saturation_n = -1.0F;
        rtb_MathFunction_p_idx_0 = 0.0F;
        rtb_Divide_l_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Subtract3_od);
          rtb_Subtract3_od = (-B - u1_tmp) / (2.0F * rtb_Subtract3_od);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Subtract3_od >= 0.0F) &&
              (rtb_Subtract3_od <= 1.0F)) {
            rtb_Saturation_n = fmaxf(D, rtb_Subtract3_od);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Saturation_n = D;
            guard1 = true;
          } else {
            if ((rtb_Subtract3_od >= 0.0F) && (rtb_Subtract3_od <= 1.0F)) {
              rtb_Saturation_n = rtb_Subtract3_od;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Subtract3_od);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Saturation_n = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_MathFunction_p_idx_0 = rtb_P_l_idx_0 * rtb_Saturation_n +
            FMS_DW.Delay_DSTATE_p[0];
          rtb_Divide_l_idx_1 = rtb_MathFunction_h_idx_0 * rtb_Saturation_n +
            FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S469>/OutRegionRegWP' incorporates:
         *  Delay: '<S448>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Subtract3_od = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) *
                            rtb_MathFunction_h_idx_0 + (FMS_U.INS_Out.x_R -
          FMS_DW.Delay_DSTATE_p[0]) * rtb_P_l_idx_0) / (rtb_P_l_idx_0 *
          rtb_P_l_idx_0 + rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Subtract3_od <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Subtract3_od >= 1.0F);
        if (rtb_FixPtRelationalOperator_me) {
          rtb_P_l_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (rtb_LogicalOperator_a4) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_P_l_idx_0 = rtb_Subtract3_od * rtb_P_l_idx_0 +
            FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S469>/Switch1' incorporates:
         *  Constant: '<S506>/Constant'
         *  RelationalOperator: '<S506>/Compare'
         */
        if (rtb_Rem_p <= 0.0F) {
          /* Switch: '<S469>/Switch' incorporates:
           *  Constant: '<S505>/Constant'
           *  MATLAB Function: '<S469>/SearchL1RefWP'
           *  RelationalOperator: '<S505>/Compare'
           */
          if (rtb_Saturation_n >= 0.0F) {
            rtb_Sum_ff[0] = rtb_MathFunction_p_idx_0;
            rtb_Sum_ff[1] = rtb_Divide_l_idx_1;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S469>/OutRegionRegWP' incorporates:
             *  Delay: '<S448>/Delay'
             *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Sum_ff[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (rtb_LogicalOperator_a4) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            } else {
              rtb_Sum_ff[1] = rtb_Subtract3_od * rtb_MathFunction_h_idx_0 +
                FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S469>/Switch' */
        }

        /* End of Switch: '<S469>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S470>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Subtract3_od = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_Subtract3_od;
        rtb_Saturation_n = rtb_Subtract3_od * rtb_Subtract3_od;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S470>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S514>/Math Function'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Subtract3_od = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S514>/Math Function' incorporates:
         *  Math: '<S512>/Square'
         */
        rtb_Rem_p = rtb_Subtract3_od * rtb_Subtract3_od;

        /* Sum: '<S514>/Sum of Elements' incorporates:
         *  Math: '<S514>/Math Function'
         */
        rtb_Saturation_n += rtb_Rem_p;

        /* Math: '<S514>/Math Function1' incorporates:
         *  Sum: '<S514>/Sum of Elements'
         *
         * About '<S514>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          B = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          B = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S514>/Math Function1' */

        /* Switch: '<S514>/Switch' incorporates:
         *  Constant: '<S514>/Constant'
         *  Product: '<S514>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Sum_ff[0];
          rtb_MatrixConcatenate3[1] = rtb_Subtract3_od;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S514>/Switch' */

        /* Product: '<S514>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        D = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S517>/Sum of Elements' incorporates:
         *  Math: '<S517>/Math Function'
         *  SignalConversion: '<S517>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_n = D * D + rtb_MathFunction_h_idx_0 *
          rtb_MathFunction_h_idx_0;

        /* Math: '<S517>/Math Function1' incorporates:
         *  Sum: '<S517>/Sum of Elements'
         *
         * About '<S517>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_n < 0.0F) {
          B = -sqrtf(fabsf(rtb_Saturation_n));
        } else {
          B = sqrtf(rtb_Saturation_n);
        }

        /* End of Math: '<S517>/Math Function1' */

        /* Switch: '<S517>/Switch' incorporates:
         *  Constant: '<S517>/Constant'
         *  Product: '<S517>/Product'
         */
        if (B > 0.0F) {
          rtb_MatrixConcatenate3[0] = D;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_h_idx_0;
          rtb_MatrixConcatenate3[2] = B;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S517>/Switch' */

        /* Product: '<S517>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Math: '<S512>/Square' */
        rtb_Saturation_n = rtb_Sum_ff[0] * rtb_Sum_ff[0];

        /* Product: '<S463>/Divide' */
        rtb_MathFunction_p_idx_0 = rtb_Switch_f3_idx_0 / rtb_Switch_f3_idx_2;

        /* Product: '<S526>/Divide' */
        rtb_P_l_idx_0 = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S525>/Divide' */
        rtb_Switch_mp_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;

        /* Product: '<S517>/Divide' incorporates:
         *  Product: '<S516>/Divide'
         */
        D = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S516>/Divide' */
        rtb_Subtract3_od = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S463>/Divide' */
        rtb_Divide_l_idx_1 = rtb_Switch_f3_idx_1 / rtb_Switch_f3_idx_2;

        /* Product: '<S526>/Divide' */
        rtb_MathFunction_f_idx_0 = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S525>/Divide' */
        rtb_MathFunction_f_idx_1 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S524>/Subtract' incorporates:
         *  Product: '<S524>/Multiply'
         *  Product: '<S524>/Multiply1'
         */
        B = rtb_P_l_idx_0 * rtb_MathFunction_f_idx_1 - rtb_MathFunction_f_idx_0 *
          rtb_Switch_mp_idx_0;

        /* Signum: '<S520>/Sign1' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S520>/Sign1' */

        /* Switch: '<S520>/Switch2' incorporates:
         *  Constant: '<S520>/Constant4'
         */
        if (B == 0.0F) {
          B = 1.0F;
        }

        /* End of Switch: '<S520>/Switch2' */

        /* DotProduct: '<S520>/Dot Product' */
        rtb_MathFunction_f_idx_1 = rtb_Switch_mp_idx_0 * rtb_P_l_idx_0 +
          rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_0;

        /* Trigonometry: '<S520>/Acos' incorporates:
         *  DotProduct: '<S520>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_1 > 1.0F) {
          rtb_MathFunction_f_idx_1 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_1 < -1.0F) {
            rtb_MathFunction_f_idx_1 = -1.0F;
          }
        }

        /* Product: '<S520>/Multiply' incorporates:
         *  Trigonometry: '<S520>/Acos'
         */
        B *= acosf(rtb_MathFunction_f_idx_1);

        /* Abs: '<S471>/Abs' */
        B = fabsf(B);

        /* RelationalOperator: '<S518>/Compare' incorporates:
         *  Constant: '<S518>/Constant'
         *  Delay: '<S471>/Delay1'
         */
        FMS_DW.Delay1_DSTATE_b = (B > 1.57079637F);

        /* Sqrt: '<S511>/Sqrt' */
        rtb_Divide_l_idx_0 = sqrtf(rtb_Divide_l_idx_0);

        /* Math: '<S470>/Square' */
        rtb_MathFunction_f_idx_0 = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_0;

        /* Sum: '<S515>/Subtract' incorporates:
         *  Product: '<S515>/Multiply'
         *  Product: '<S515>/Multiply1'
         */
        rtb_Divide_l_idx_0 = rtb_MathFunction_h_idx_0 * rtb_Subtract3_od - D *
          rtb_Sum_ff[0];

        /* Signum: '<S510>/Sign1' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Divide_l_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_0 > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S510>/Sign1' */

        /* Switch: '<S510>/Switch2' incorporates:
         *  Constant: '<S510>/Constant4'
         */
        if (rtb_Divide_l_idx_0 == 0.0F) {
          rtb_Divide_l_idx_0 = 1.0F;
        }

        /* End of Switch: '<S510>/Switch2' */

        /* DotProduct: '<S510>/Dot Product' */
        rtb_Subtract3_od = rtb_Sum_ff[0] * rtb_MathFunction_h_idx_0 +
          rtb_Subtract3_od * D;

        /* Trigonometry: '<S510>/Acos' incorporates:
         *  DotProduct: '<S510>/Dot Product'
         */
        if (rtb_Subtract3_od > 1.0F) {
          rtb_Subtract3_od = 1.0F;
        } else {
          if (rtb_Subtract3_od < -1.0F) {
            rtb_Subtract3_od = -1.0F;
          }
        }

        /* Product: '<S510>/Multiply' incorporates:
         *  Trigonometry: '<S510>/Acos'
         */
        rtb_Divide_l_idx_0 *= acosf(rtb_Subtract3_od);

        /* Saturate: '<S470>/Saturation' */
        if (rtb_Divide_l_idx_0 > 1.57079637F) {
          rtb_Divide_l_idx_0 = 1.57079637F;
        } else {
          if (rtb_Divide_l_idx_0 < -1.57079637F) {
            rtb_Divide_l_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S470>/Saturation' */

        /* Switch: '<S522>/Switch2' incorporates:
         *  Constant: '<S471>/Constant1'
         *  RelationalOperator: '<S522>/LowerRelop1'
         *  RelationalOperator: '<S522>/UpperRelop'
         *  Switch: '<S522>/Switch'
         */
        if (rtb_Integrator1_a > rtb_Add4_d) {
          rtb_Integrator1_a = rtb_Add4_d;
        } else {
          if (rtb_Integrator1_a < 0.5F) {
            /* Switch: '<S522>/Switch' incorporates:
             *  Constant: '<S471>/Constant1'
             */
            rtb_Integrator1_a = 0.5F;
          }
        }

        /* End of Switch: '<S522>/Switch2' */

        /* Product: '<S471>/Divide1' incorporates:
         *  Constant: '<S396>/L1'
         *  Constant: '<S470>/Constant'
         *  Gain: '<S470>/Gain'
         *  MinMax: '<S470>/Max'
         *  MinMax: '<S470>/Min'
         *  Product: '<S470>/Divide'
         *  Product: '<S470>/Multiply1'
         *  Sqrt: '<S512>/Sqrt'
         *  Sum: '<S512>/Sum of Elements'
         *  Trigonometry: '<S470>/Sin'
         */
        rtb_Divide_l_idx_0 = 2.0F * rtb_MathFunction_f_idx_0 * arm_sin_f32
          (rtb_Divide_l_idx_0) / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Rem_p +
          rtb_Saturation_n), 0.5F)) / rtb_Integrator1_a;

        /* Saturate: '<S471>/Saturation' */
        if (rtb_Divide_l_idx_0 > 0.314159274F) {
          rtb_Integrator1_a = 0.314159274F;
        } else if (rtb_Divide_l_idx_0 < -0.314159274F) {
          rtb_Integrator1_a = -0.314159274F;
        } else {
          rtb_Integrator1_a = rtb_Divide_l_idx_0;
        }

        /* End of Saturate: '<S471>/Saturation' */

        /* Sum: '<S461>/Subtract' incorporates:
         *  Product: '<S461>/Multiply'
         *  Product: '<S461>/Multiply1'
         */
        rtb_Divide_l_idx_0 = rtb_MathFunction_p_idx_0 * FMS_ConstB.Divide_d[1] -
          rtb_Divide_l_idx_1 * FMS_ConstB.Divide_d[0];

        /* Signum: '<S450>/Sign1' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Divide_l_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_0 > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S450>/Sign1' */

        /* Switch: '<S450>/Switch2' incorporates:
         *  Constant: '<S450>/Constant4'
         */
        if (rtb_Divide_l_idx_0 == 0.0F) {
          rtb_Divide_l_idx_0 = 1.0F;
        }

        /* End of Switch: '<S450>/Switch2' */

        /* DotProduct: '<S450>/Dot Product' */
        rtb_Subtract3_od = FMS_ConstB.Divide_d[0] * rtb_MathFunction_p_idx_0 +
          FMS_ConstB.Divide_d[1] * rtb_Divide_l_idx_1;

        /* Trigonometry: '<S450>/Acos' incorporates:
         *  DotProduct: '<S450>/Dot Product'
         */
        if (rtb_Subtract3_od > 1.0F) {
          rtb_Subtract3_od = 1.0F;
        } else {
          if (rtb_Subtract3_od < -1.0F) {
            rtb_Subtract3_od = -1.0F;
          }
        }

        /* Product: '<S450>/Multiply' incorporates:
         *  Trigonometry: '<S450>/Acos'
         */
        rtb_Divide_l_idx_0 *= acosf(rtb_Subtract3_od);

        /* Math: '<S453>/Rem' incorporates:
         *  Constant: '<S453>/Constant1'
         *  Delay: '<S449>/Delay'
         *  Sum: '<S449>/Sum2'
         */
        B = rt_remf(rtb_Divide_l_idx_0 - FMS_DW.Delay_DSTATE_a, 6.28318548F);

        /* Switch: '<S453>/Switch' incorporates:
         *  Abs: '<S453>/Abs'
         *  Constant: '<S453>/Constant'
         *  Constant: '<S459>/Constant'
         *  Product: '<S453>/Multiply'
         *  RelationalOperator: '<S459>/Compare'
         *  Sum: '<S453>/Add'
         */
        if (fabsf(B) > 3.14159274F) {
          /* Signum: '<S453>/Sign' */
          if (B < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (B > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = B;
          }

          /* End of Signum: '<S453>/Sign' */
          B -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S453>/Switch' */

        /* Sum: '<S449>/Sum' incorporates:
         *  Delay: '<S449>/Delay'
         */
        rtb_Saturation_n = B + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S458>/Multiply1' incorporates:
         *  Constant: '<S458>/const1'
         *  DiscreteIntegrator: '<S452>/Integrator'
         */
        B = FMS_DW.Integrator_DSTATE_bs * 0.785398185F;

        /* Sum: '<S458>/Add' incorporates:
         *  DiscreteIntegrator: '<S452>/Integrator1'
         *  Sum: '<S452>/Subtract'
         */
        rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE_e - rtb_Saturation_n) + B;

        /* Signum: '<S458>/Sign' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Subtract3_od > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Subtract3_od;
        }

        /* End of Signum: '<S458>/Sign' */

        /* Sum: '<S458>/Add2' incorporates:
         *  Abs: '<S458>/Abs'
         *  Gain: '<S458>/Gain'
         *  Gain: '<S458>/Gain1'
         *  Product: '<S458>/Multiply2'
         *  Product: '<S458>/Multiply3'
         *  Sqrt: '<S458>/Sqrt'
         *  Sum: '<S458>/Add1'
         *  Sum: '<S458>/Subtract'
         */
        rtb_Rem_p = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) + FMS_ConstB.d_l) *
                           FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
          rtb_Saturation_n + B;

        /* Sum: '<S458>/Add4' */
        rtb_Add4_d = (rtb_Subtract3_od - rtb_Rem_p) + B;

        /* Sum: '<S458>/Add3' */
        rtb_Saturation_n = rtb_Subtract3_od + FMS_ConstB.d_l;

        /* Sum: '<S458>/Subtract1' */
        rtb_Subtract3_od -= FMS_ConstB.d_l;

        /* Signum: '<S458>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S458>/Sign1' */

        /* Signum: '<S458>/Sign2' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S458>/Sign2' */

        /* Sum: '<S458>/Add5' incorporates:
         *  Gain: '<S458>/Gain2'
         *  Product: '<S458>/Multiply4'
         *  Sum: '<S458>/Subtract2'
         */
        rtb_Rem_p += (rtb_Saturation_n - rtb_Subtract3_od) * 0.5F * rtb_Add4_d;

        /* Sum: '<S458>/Subtract3' */
        rtb_Saturation_n = rtb_Rem_p - FMS_ConstB.d_l;

        /* Sum: '<S458>/Add6' */
        rtb_Subtract3_od = rtb_Rem_p + FMS_ConstB.d_l;

        /* Product: '<S458>/Divide' */
        rtb_MathFunction_p_idx_0 = rtb_Rem_p / FMS_ConstB.d_l;

        /* Signum: '<S458>/Sign5' incorporates:
         *  Signum: '<S458>/Sign6'
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
          rtb_Add4_d = -1.0F;
        } else if (rtb_Rem_p > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Rem_p;
          rtb_Add4_d = rtb_Rem_p;
        }

        /* End of Signum: '<S458>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S449>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Divide_l_idx_0 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S454>/Rem' incorporates:
         *  Constant: '<S454>/Constant1'
         */
        rtb_Rem_p = rt_remf(rtb_Divide_l_idx_0, 6.28318548F);

        /* Switch: '<S454>/Switch' incorporates:
         *  Abs: '<S454>/Abs'
         *  Constant: '<S454>/Constant'
         *  Constant: '<S460>/Constant'
         *  Product: '<S454>/Multiply'
         *  RelationalOperator: '<S460>/Compare'
         *  Sum: '<S454>/Add'
         */
        if (fabsf(rtb_Rem_p) > 3.14159274F) {
          /* Signum: '<S454>/Sign' */
          if (rtb_Rem_p < 0.0F) {
            rtb_Divide_l_idx_0 = -1.0F;
          } else if (rtb_Rem_p > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_0 = rtb_Rem_p;
          }

          /* End of Signum: '<S454>/Sign' */
          rtb_Rem_p -= 6.28318548F * rtb_Divide_l_idx_0;
        }

        /* End of Switch: '<S454>/Switch' */

        /* Abs: '<S447>/Abs' */
        rtb_Rem_p = fabsf(rtb_Rem_p);

        /* Update for DiscreteIntegrator: '<S472>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S465>/Constant'
         *  RelationalOperator: '<S465>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTAT_mx = (uint8_T)((uint32_T)(rtb_Rem_p <=
          0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTAT_mx);
        if (FMS_DW.DiscreteTimeIntegrator_DSTAT_mx >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTAT_mx = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTAT_mx <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTAT_mx = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S472>/Discrete-Time Integrator' */

        /* Update for Delay: '<S471>/Delay' */
        FMS_DW.icLoad_l = 0U;

        /* Update for DiscreteIntegrator: '<S467>/Acceleration_Speed' incorporates:
         *  Constant: '<S467>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE_j += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S521>/Discrete-Time Integrator' */
        FMS_DW.l1_heading_e += 0.004F * rtb_Integrator1_a;
        FMS_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)rtb_LogicalOperator_aa;

        /* Update for Delay: '<S449>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S452>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S452>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING_j = 0U;
        FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_bs;

        /* Update for Delay: '<S448>/Delay' */
        FMS_DW.icLoad_c = 0U;

        /* Signum: '<S458>/Sign3' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S458>/Sign3' */

        /* Signum: '<S458>/Sign4' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S458>/Sign4' */

        /* Update for DiscreteIntegrator: '<S452>/Integrator' incorporates:
         *  Constant: '<S458>/const'
         *  Gain: '<S458>/Gain3'
         *  Product: '<S458>/Multiply5'
         *  Product: '<S458>/Multiply6'
         *  Sum: '<S458>/Subtract4'
         *  Sum: '<S458>/Subtract5'
         *  Sum: '<S458>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_bs += ((rtb_MathFunction_p_idx_0 -
          rtb_Divide_l_idx_1) * FMS_ConstB.Gain4_n * ((rtb_Subtract3_od -
          rtb_Saturation_n) * 0.5F) - rtb_Add4_d * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_bs >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_bs = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_bs <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_bs = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S452>/Integrator' */
        /* End of Outputs for SubSystem: '<S40>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_at != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S40>/Hold' incorporates:
           *  ActionPort: '<S394>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S40>/Switch Case' incorporates:
           *  Chart: '<S403>/Motion Status'
           *  Chart: '<S413>/Motion State'
           *  Chart: '<S425>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c15_FMS = 0U;
          FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

          /* End of SystemReset for SubSystem: '<S40>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S40>/Hold' incorporates:
         *  ActionPort: '<S394>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S403>/Motion Status' incorporates:
         *  Abs: '<S403>/Abs'
         *  Constant: '<S403>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_j);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S413>/Motion State' incorporates:
         *  Abs: '<S413>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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

        /* End of Chart: '<S413>/Motion State' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S425>/Motion State' incorporates:
         *  Constant: '<S425>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S425>/Square'
         *  Math: '<S425>/Square1'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sqrt: '<S425>/Sqrt'
         *  Sum: '<S425>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l,
                        &FMS_DW.sf_MotionState_g);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S424>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S424>/Hold Control' incorporates:
             *  ActionPort: '<S427>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S424>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_f);

            /* End of SystemReset for SubSystem: '<S424>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S424>/Hold Control' incorporates:
           *  ActionPort: '<S427>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_o,
                            &FMS_ConstB.HoldControl_f, &FMS_DW.HoldControl_f);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S424>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S424>/Brake Control' incorporates:
           *  ActionPort: '<S426>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_o);

          /* End of Outputs for SubSystem: '<S424>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S424>/Move Control' incorporates:
             *  ActionPort: '<S428>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S424>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_i);

            /* End of SystemReset for SubSystem: '<S424>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S424>/Move Control' incorporates:
           *  ActionPort: '<S428>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_o,
                            &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S424>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S424>/Switch Case' */

        /* SwitchCase: '<S402>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S402>/Hold Control' incorporates:
             *  ActionPort: '<S405>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S402>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_n);

            /* End of SystemReset for SubSystem: '<S402>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S402>/Hold Control' incorporates:
           *  ActionPort: '<S405>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ey,
                          &FMS_DW.HoldControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S402>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S402>/Brake Control' incorporates:
           *  ActionPort: '<S404>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_ey);

          /* End of Outputs for SubSystem: '<S402>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_pp != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S402>/Move Control' incorporates:
             *  ActionPort: '<S406>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S402>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_n);

            /* End of SystemReset for SubSystem: '<S402>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S402>/Move Control' incorporates:
           *  ActionPort: '<S406>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_ey,
                          &FMS_ConstB.MoveControl_n, &FMS_DW.MoveControl_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S402>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S402>/Switch Case' */

        /* SwitchCase: '<S412>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S412>/Hold Control' incorporates:
             *  ActionPort: '<S415>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S412>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_k);

            /* End of SystemReset for SubSystem: '<S412>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S412>/Hold Control' incorporates:
           *  ActionPort: '<S415>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_n1,
                            &FMS_DW.HoldControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S412>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S412>/Brake Control' incorporates:
           *  ActionPort: '<S414>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_n1);

          /* End of Outputs for SubSystem: '<S412>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S412>/Move Control' incorporates:
             *  ActionPort: '<S416>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S412>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_b);

            /* End of SystemReset for SubSystem: '<S412>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S412>/Move Control' incorporates:
           *  ActionPort: '<S416>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_n1,
                            &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S412>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S412>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S394>/Bus Assignment'
         *  Constant: '<S394>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S394>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ie;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;

        /* Saturate: '<S412>/Saturation' */
        if (FMS_B.Merge_n1 > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_n1 < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_n1;
        }

        /* End of Saturate: '<S412>/Saturation' */

        /* Saturate: '<S424>/Saturation1' */
        if (FMS_B.Merge_o[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_o[0];
        }

        if (FMS_B.Merge_o[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_o[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_o[1];
        }

        /* End of Saturate: '<S424>/Saturation1' */

        /* Saturate: '<S402>/Saturation1' */
        if (FMS_B.Merge_ey > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ey < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S394>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_ey;
        }

        /* End of Saturate: '<S402>/Saturation1' */
        /* End of Outputs for SubSystem: '<S40>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S40>/Unknown' incorporates:
         *  ActionPort: '<S398>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_g);

        /* End of Outputs for SubSystem: '<S40>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S40>/Switch Case' */
      /* End of Outputs for SubSystem: '<S33>/SubMode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S33>/Auto' incorporates:
       *  ActionPort: '<S38>/Action Port'
       */
      /* SwitchCase: '<S38>/Switch Case' incorporates:
       *  Math: '<S269>/Square'
       *  Math: '<S271>/Math Function'
       *  Sum: '<S227>/Subtract'
       *  Sum: '<S290>/Sum1'
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
        /* Disable for Resettable SubSystem: '<S198>/Mission_SubSystem' */
        /* Disable for SwitchCase: '<S249>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

        /* Disable for SwitchCase: '<S239>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

        /* End of Disable for SubSystem: '<S198>/Mission_SubSystem' */
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S38>/Offboard' incorporates:
         *  ActionPort: '<S199>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S371>/rad2deg' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Multiply_l5_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S374>/deg2rad' */
        rtb_Switch1_p = 0.017453292519943295 * rtb_Multiply_l5_idx_0;

        /* Trigonometry: '<S375>/Sin' */
        rtb_Gain = sin(rtb_Switch1_p);

        /* Math: '<S375>/Square1' */
        rtb_Gain *= rtb_Gain;

        /* Product: '<S375>/Multiply1' incorporates:
         *  Product: '<S375>/Multiply'
         */
        rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

        /* Product: '<S375>/Divide' incorporates:
         *  Constant: '<S375>/Constant'
         *  Constant: '<S375>/R'
         *  Sqrt: '<S375>/Sqrt'
         *  Sum: '<S375>/Sum1'
         */
        rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

        /* Product: '<S375>/Product3' incorporates:
         *  Constant: '<S375>/Constant1'
         *  Product: '<S375>/Multiply1'
         *  Sum: '<S375>/Sum2'
         */
        rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

        /* Product: '<S375>/Multiply2' incorporates:
         *  Trigonometry: '<S375>/Cos'
         */
        rtb_Gain *= cos(rtb_Switch1_p);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S374>/Sum' incorporates:
         *  Gain: '<S371>/Gain'
         *  Inport: '<Root>/Auto_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Multiply_l5_idx_0 = 1.0000000000287557E-7 * (real_T)
          FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l5_idx_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S379>/Abs' incorporates:
         *  Abs: '<S382>/Abs1'
         *  Switch: '<S379>/Switch1'
         */
        rtb_Switch1_p = fabs(rtb_Multiply_l5_idx_0);

        /* Switch: '<S379>/Switch1' incorporates:
         *  Abs: '<S379>/Abs'
         *  Bias: '<S379>/Bias2'
         *  Bias: '<S379>/Bias3'
         *  Constant: '<S376>/Constant'
         *  Constant: '<S376>/Constant1'
         *  Constant: '<S381>/Constant'
         *  Gain: '<S379>/Gain1'
         *  Product: '<S379>/Multiply'
         *  RelationalOperator: '<S381>/Compare'
         *  Switch: '<S376>/Switch'
         */
        if (rtb_Switch1_p > 90.0) {
          /* Switch: '<S382>/Switch1' incorporates:
           *  Bias: '<S382>/Bias2'
           *  Bias: '<S382>/Bias3'
           *  Constant: '<S382>/Constant'
           *  Constant: '<S383>/Constant'
           *  Math: '<S382>/Math Function'
           *  RelationalOperator: '<S383>/Compare'
           */
          if (rtb_Switch1_p > 180.0) {
            rtb_Multiply_l5_idx_0 = rt_modd(rtb_Multiply_l5_idx_0 + 180.0, 360.0)
              + -180.0;
          }

          /* End of Switch: '<S382>/Switch1' */

          /* Signum: '<S379>/Sign' */
          if (rtb_Multiply_l5_idx_0 < 0.0) {
            rtb_Multiply_l5_idx_0 = -1.0;
          } else {
            if (rtb_Multiply_l5_idx_0 > 0.0) {
              rtb_Multiply_l5_idx_0 = 1.0;
            }
          }

          /* End of Signum: '<S379>/Sign' */
          rtb_Multiply_l5_idx_0 *= -(rtb_Switch1_p + -90.0) + 90.0;
          rtb_Compare_bv_0 = 180;
        } else {
          rtb_Compare_bv_0 = 0;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S376>/Sum' incorporates:
         *  Gain: '<S371>/Gain1'
         *  Gain: '<S371>/rad2deg'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sum: '<S374>/Sum'
         */
        rtb_Switch1_p = (1.0000000000287557E-7 * (real_T)FMS_U.Auto_Cmd.lon_cmd
                         - 57.295779513082323 * FMS_U.INS_Out.lon_0) + (real_T)
          rtb_Compare_bv_0;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S374>/Multiply' incorporates:
         *  Gain: '<S374>/deg2rad1'
         */
        rtb_Multiply_l5_idx_0 = 0.017453292519943295 * rtb_Multiply_l5_idx_0 *
          rtb_Sum3;

        /* Switch: '<S378>/Switch1' incorporates:
         *  Abs: '<S378>/Abs1'
         *  Bias: '<S378>/Bias2'
         *  Bias: '<S378>/Bias3'
         *  Constant: '<S378>/Constant'
         *  Constant: '<S380>/Constant'
         *  Math: '<S378>/Math Function'
         *  RelationalOperator: '<S380>/Compare'
         */
        if (fabs(rtb_Switch1_p) > 180.0) {
          rtb_Switch1_p = rt_modd(rtb_Switch1_p + 180.0, 360.0) + -180.0;
        }

        /* End of Switch: '<S378>/Switch1' */

        /* Product: '<S374>/Multiply' incorporates:
         *  Gain: '<S374>/deg2rad1'
         */
        rtb_Gain *= 0.017453292519943295 * rtb_Switch1_p;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S365>/Trigonometric Function1' incorporates:
         *  Gain: '<S364>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S365>/Trigonometric Function' incorporates:
         *  Gain: '<S364>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S365>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S365>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S365>/Gain' incorporates:
         *  Gain: '<S364>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Trigonometry: '<S365>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S365>/Trigonometric Function3' incorporates:
         *  Gain: '<S364>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S365>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S365>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S365>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_i[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_i[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_i[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S352>/Index Vector' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S356>/Multiply1'
         *  Product: '<S357>/Multiply3'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Switch: '<S358>/Switch' incorporates:
           *  Constant: '<S373>/Constant'
           *  DataTypeConversion: '<S371>/Data Type Conversion1'
           *  Product: '<S377>/Multiply1'
           *  Product: '<S377>/Multiply2'
           *  RelationalOperator: '<S373>/Compare'
           *  S-Function (sfix_bitop): '<S370>/lat_cmd valid'
           *  Sum: '<S377>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Divide_l_idx_0 = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Divide_l_idx_0 = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S356>/Multiply' incorporates:
           *  Constant: '<S362>/Constant'
           *  Constant: '<S363>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S355>/Logical Operator'
           *  RelationalOperator: '<S362>/Compare'
           *  RelationalOperator: '<S363>/Compare'
           *  S-Function (sfix_bitop): '<S355>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/x_cmd valid'
           *  Sum: '<S356>/Sum1'
           */
          rtb_Add4_d = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Divide_l_idx_0 -
            FMS_U.INS_Out.x_R : 0.0F;

          /* Switch: '<S358>/Switch' incorporates:
           *  Constant: '<S373>/Constant'
           *  DataTypeConversion: '<S371>/Data Type Conversion1'
           *  Product: '<S377>/Multiply3'
           *  Product: '<S377>/Multiply4'
           *  RelationalOperator: '<S373>/Compare'
           *  S-Function (sfix_bitop): '<S370>/lon_cmd valid'
           *  Sum: '<S377>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Divide_l_idx_0 = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Divide_l_idx_0 = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S356>/Multiply' incorporates:
           *  Constant: '<S362>/Constant'
           *  Constant: '<S363>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S355>/Logical Operator'
           *  RelationalOperator: '<S362>/Compare'
           *  RelationalOperator: '<S363>/Compare'
           *  S-Function (sfix_bitop): '<S355>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/y_cmd valid'
           *  Sum: '<S356>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Divide_l_idx_0 -
            FMS_U.INS_Out.y_R : 0.0F;

          /* Switch: '<S358>/Switch' incorporates:
           *  Constant: '<S373>/Constant'
           *  DataTypeConversion: '<S371>/Data Type Conversion'
           *  DataTypeConversion: '<S371>/Data Type Conversion1'
           *  Gain: '<S371>/Gain2'
           *  Gain: '<S374>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S373>/Compare'
           *  S-Function (sfix_bitop): '<S370>/alt_cmd valid'
           *  Sum: '<S374>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Divide_l_idx_0 = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Divide_l_idx_0 = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S356>/Multiply' incorporates:
           *  Constant: '<S362>/Constant'
           *  Constant: '<S363>/Constant'
           *  Gain: '<S359>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S355>/Logical Operator'
           *  RelationalOperator: '<S362>/Compare'
           *  RelationalOperator: '<S363>/Compare'
           *  S-Function (sfix_bitop): '<S355>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/z_cmd valid'
           *  Sum: '<S356>/Sum1'
           */
          rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Divide_l_idx_0 -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_d);
          }
          break;

         case 1:
          /* Switch: '<S358>/Switch' incorporates:
           *  Constant: '<S373>/Constant'
           *  DataTypeConversion: '<S371>/Data Type Conversion1'
           *  Product: '<S377>/Multiply1'
           *  Product: '<S377>/Multiply2'
           *  RelationalOperator: '<S373>/Compare'
           *  S-Function (sfix_bitop): '<S370>/lat_cmd valid'
           *  Sum: '<S377>/Sum2'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
            rtb_Divide_l_idx_0 = (real32_T)(rtb_Multiply_l5_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Divide_l_idx_0 = FMS_U.Auto_Cmd.x_cmd;
          }

          /* Product: '<S356>/Multiply' incorporates:
           *  Constant: '<S362>/Constant'
           *  Constant: '<S363>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S355>/Logical Operator'
           *  RelationalOperator: '<S362>/Compare'
           *  RelationalOperator: '<S363>/Compare'
           *  S-Function (sfix_bitop): '<S355>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/x_cmd valid'
           *  Sum: '<S356>/Sum1'
           */
          rtb_Add4_d = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Divide_l_idx_0 -
            FMS_U.INS_Out.x_R : 0.0F;

          /* Switch: '<S358>/Switch' incorporates:
           *  Constant: '<S373>/Constant'
           *  DataTypeConversion: '<S371>/Data Type Conversion1'
           *  Product: '<S377>/Multiply3'
           *  Product: '<S377>/Multiply4'
           *  RelationalOperator: '<S373>/Compare'
           *  S-Function (sfix_bitop): '<S370>/lon_cmd valid'
           *  Sum: '<S377>/Sum3'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
            rtb_Divide_l_idx_0 = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          } else {
            rtb_Divide_l_idx_0 = FMS_U.Auto_Cmd.y_cmd;
          }

          /* Product: '<S356>/Multiply' incorporates:
           *  Constant: '<S362>/Constant'
           *  Constant: '<S363>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S355>/Logical Operator'
           *  RelationalOperator: '<S362>/Compare'
           *  RelationalOperator: '<S363>/Compare'
           *  S-Function (sfix_bitop): '<S355>/lon_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/y_cmd valid'
           *  Sum: '<S356>/Sum1'
           */
          rtb_Integrator1_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Divide_l_idx_0 -
            FMS_U.INS_Out.y_R : 0.0F;

          /* Switch: '<S358>/Switch' incorporates:
           *  Constant: '<S373>/Constant'
           *  DataTypeConversion: '<S371>/Data Type Conversion'
           *  DataTypeConversion: '<S371>/Data Type Conversion1'
           *  Gain: '<S371>/Gain2'
           *  Gain: '<S374>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S373>/Compare'
           *  S-Function (sfix_bitop): '<S370>/alt_cmd valid'
           *  Sum: '<S374>/Sum1'
           */
          if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
            rtb_Divide_l_idx_0 = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);
          } else {
            rtb_Divide_l_idx_0 = FMS_U.Auto_Cmd.z_cmd;
          }

          /* Product: '<S356>/Multiply' incorporates:
           *  Constant: '<S362>/Constant'
           *  Constant: '<S363>/Constant'
           *  Gain: '<S359>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S355>/Logical Operator'
           *  RelationalOperator: '<S362>/Compare'
           *  RelationalOperator: '<S363>/Compare'
           *  S-Function (sfix_bitop): '<S355>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/z_cmd valid'
           *  Sum: '<S356>/Sum1'
           */
          rtb_Divide_l_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Divide_l_idx_0 -
            (-FMS_U.INS_Out.h_R) : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_d);
          }
          break;

         case 2:
          /* SignalConversion: '<S368>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S368>/Constant4'
           */
          rtb_VectorConcatenate_j4[5] = 0.0F;

          /* Trigonometry: '<S368>/Trigonometric Function3' incorporates:
           *  DataStoreRead: '<S357>/Data Store Read'
           *  Gain: '<S366>/Gain'
           *  Trigonometry: '<S368>/Trigonometric Function1'
           */
          rtb_Saturation_n = arm_cos_f32(-FMS_DW.home[3]);
          rtb_VectorConcatenate_j4[4] = rtb_Saturation_n;

          /* Trigonometry: '<S368>/Trigonometric Function2' incorporates:
           *  DataStoreRead: '<S357>/Data Store Read'
           *  Gain: '<S366>/Gain'
           *  Trigonometry: '<S368>/Trigonometric Function'
           */
          rtb_Subtract3_od = arm_sin_f32(-FMS_DW.home[3]);

          /* Gain: '<S368>/Gain' incorporates:
           *  Trigonometry: '<S368>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_j4[3] = -rtb_Subtract3_od;

          /* SignalConversion: '<S368>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S368>/Constant3'
           */
          rtb_VectorConcatenate_j4[2] = 0.0F;

          /* Trigonometry: '<S368>/Trigonometric Function' */
          rtb_VectorConcatenate_j4[1] = rtb_Subtract3_od;

          /* Trigonometry: '<S368>/Trigonometric Function1' */
          rtb_VectorConcatenate_j4[0] = rtb_Saturation_n;

          /* SignalConversion: '<S368>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_j4[6] = FMS_ConstB.VectorConcatenate3_ny[0];

          /* SignalConversion: '<S369>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_n[6] = FMS_ConstB.VectorConcatenate3_e[0];

          /* SignalConversion: '<S368>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_j4[7] = FMS_ConstB.VectorConcatenate3_ny[1];

          /* SignalConversion: '<S369>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_n[7] = FMS_ConstB.VectorConcatenate3_e[1];

          /* SignalConversion: '<S368>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_j4[8] = FMS_ConstB.VectorConcatenate3_ny[2];

          /* SignalConversion: '<S369>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_n[8] = FMS_ConstB.VectorConcatenate3_e[2];

          /* SignalConversion: '<S369>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S369>/Constant4'
           */
          rtb_VectorConcatenate_n[5] = 0.0F;

          /* Gain: '<S367>/Gain' incorporates:
           *  DataStoreRead: '<S357>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  Sum: '<S357>/Subtract'
           */
          rtb_Subtract3_od = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S369>/Trigonometric Function3' incorporates:
           *  Gain: '<S367>/Gain'
           *  Trigonometry: '<S369>/Trigonometric Function1'
           */
          rtb_Saturation_n = arm_cos_f32(rtb_Subtract3_od);
          rtb_VectorConcatenate_n[4] = rtb_Saturation_n;

          /* Trigonometry: '<S369>/Trigonometric Function2' incorporates:
           *  Gain: '<S367>/Gain'
           *  Trigonometry: '<S369>/Trigonometric Function'
           */
          rtb_Subtract3_od = arm_sin_f32(rtb_Subtract3_od);

          /* Gain: '<S369>/Gain' incorporates:
           *  Trigonometry: '<S369>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_n[3] = -rtb_Subtract3_od;

          /* SignalConversion: '<S369>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S369>/Constant3'
           */
          rtb_VectorConcatenate_n[2] = 0.0F;

          /* Trigonometry: '<S369>/Trigonometric Function' */
          rtb_VectorConcatenate_n[1] = rtb_Subtract3_od;

          /* Trigonometry: '<S369>/Trigonometric Function1' */
          rtb_VectorConcatenate_n[0] = rtb_Saturation_n;

          /* RelationalOperator: '<S373>/Compare' incorporates:
           *  Constant: '<S373>/Constant'
           *  S-Function (sfix_bitop): '<S370>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S370>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S370>/lon_cmd valid'
           */
          tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

          /* DataTypeConversion: '<S371>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S371>/Data Type Conversion'
           *  Gain: '<S371>/Gain2'
           *  Gain: '<S374>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S377>/Multiply1'
           *  Product: '<S377>/Multiply2'
           *  Product: '<S377>/Multiply3'
           *  Product: '<S377>/Multiply4'
           *  Sum: '<S374>/Sum1'
           *  Sum: '<S377>/Sum2'
           *  Sum: '<S377>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S358>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S362>/Compare' incorporates:
           *  Constant: '<S362>/Constant'
           *  S-Function (sfix_bitop): '<S355>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S363>/Compare' incorporates:
           *  Constant: '<S363>/Constant'
           *  S-Function (sfix_bitop): '<S355>/alt_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/lat_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/lon_cmd valid'
           */
          tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
          tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
          tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Sum: '<S357>/Sum2' incorporates:
             *  Product: '<S357>/Multiply2'
             *  Switch: '<S358>/Switch'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Divide_l_idx_0 = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Divide_l_idx_0 = tmp_0[rtb_Compare_bv_0];
            }

            /* Product: '<S357>/Multiply' incorporates:
             *  Gain: '<S359>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S355>/Logical Operator'
             *  Product: '<S357>/Multiply2'
             *  Sum: '<S357>/Sum2'
             */
            tmp_3[rtb_Compare_bv_0] = tmp_1[rtb_Compare_bv_0] ||
              tmp_2[rtb_Compare_bv_0] ? rtb_Divide_l_idx_0 -
              ((rtb_VectorConcatenate_j4[rtb_Compare_bv_0 + 3] *
                FMS_U.INS_Out.y_R + rtb_VectorConcatenate_j4[rtb_Compare_bv_0] *
                FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_j4[rtb_Compare_bv_0 +
               6] * -FMS_U.INS_Out.h_R) : 0.0F;
          }

          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_VectorConcatenate_n[rtb_Compare_bv_0 + 6] * tmp_3[2] +
              (rtb_VectorConcatenate_n[rtb_Compare_bv_0 + 3] * tmp_3[1] +
               rtb_VectorConcatenate_n[rtb_Compare_bv_0] * tmp_3[0]);
          }
          break;

         default:
          /* SignalConversion: '<S361>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_j4[6] = FMS_ConstB.VectorConcatenate3_n[0];
          rtb_VectorConcatenate_j4[7] = FMS_ConstB.VectorConcatenate3_n[1];
          rtb_VectorConcatenate_j4[8] = FMS_ConstB.VectorConcatenate3_n[2];

          /* SignalConversion: '<S361>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S361>/Constant4'
           */
          rtb_VectorConcatenate_j4[5] = 0.0F;

          /* Trigonometry: '<S361>/Trigonometric Function3' incorporates:
           *  Gain: '<S360>/Gain'
           *  Inport: '<Root>/INS_Out'
           */
          rtb_VectorConcatenate_j4[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Gain: '<S361>/Gain' incorporates:
           *  Gain: '<S360>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Trigonometry: '<S361>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_j4[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* SignalConversion: '<S361>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S361>/Constant3'
           */
          rtb_VectorConcatenate_j4[2] = 0.0F;

          /* Trigonometry: '<S361>/Trigonometric Function' incorporates:
           *  Gain: '<S360>/Gain'
           *  Inport: '<Root>/INS_Out'
           */
          rtb_VectorConcatenate_j4[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S361>/Trigonometric Function1' incorporates:
           *  Gain: '<S360>/Gain'
           *  Inport: '<Root>/INS_Out'
           */
          rtb_VectorConcatenate_j4[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* S-Function (sfix_bitop): '<S370>/lat_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S355>/lat_cmd valid'
           */
          tmp_6 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

          /* RelationalOperator: '<S373>/Compare' incorporates:
           *  Constant: '<S373>/Constant'
           *  S-Function (sfix_bitop): '<S370>/lat_cmd valid'
           */
          tmp[0] = (tmp_6 > 0U);

          /* S-Function (sfix_bitop): '<S370>/lon_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S355>/lon_cmd valid'
           */
          tmp_7 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

          /* RelationalOperator: '<S373>/Compare' incorporates:
           *  Constant: '<S373>/Constant'
           *  S-Function (sfix_bitop): '<S370>/lon_cmd valid'
           */
          tmp[1] = (tmp_7 > 0U);

          /* S-Function (sfix_bitop): '<S370>/alt_cmd valid' incorporates:
           *  S-Function (sfix_bitop): '<S355>/alt_cmd valid'
           */
          tmp_8 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

          /* RelationalOperator: '<S373>/Compare' incorporates:
           *  Constant: '<S373>/Constant'
           *  S-Function (sfix_bitop): '<S370>/alt_cmd valid'
           */
          tmp[2] = (tmp_8 > 0U);

          /* DataTypeConversion: '<S371>/Data Type Conversion1' incorporates:
           *  DataTypeConversion: '<S371>/Data Type Conversion'
           *  Gain: '<S371>/Gain2'
           *  Gain: '<S374>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S377>/Multiply1'
           *  Product: '<S377>/Multiply2'
           *  Product: '<S377>/Multiply3'
           *  Product: '<S377>/Multiply4'
           *  Sum: '<S374>/Sum1'
           *  Sum: '<S377>/Sum2'
           *  Sum: '<S377>/Sum3'
           */
          rtb_Transpose_0[0] = (real32_T)(rtb_Multiply_l5_idx_0 *
            FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
            rtb_Multiply_l5_idx_0 * FMS_ConstB.SinCos_o1);
          rtb_Transpose_0[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
            -FMS_U.INS_Out.alt_0);

          /* Switch: '<S358>/Switch' */
          tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
          tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
          tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

          /* RelationalOperator: '<S362>/Compare' incorporates:
           *  Constant: '<S362>/Constant'
           *  S-Function (sfix_bitop): '<S355>/x_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/y_cmd valid'
           *  S-Function (sfix_bitop): '<S355>/z_cmd valid'
           */
          tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
          tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
          tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

          /* RelationalOperator: '<S363>/Compare' incorporates:
           *  Constant: '<S363>/Constant'
           */
          tmp_2[0] = (tmp_6 > 0U);
          tmp_2[1] = (tmp_7 > 0U);
          tmp_2[2] = (tmp_8 > 0U);

          /* Sum: '<S354>/Sum2' incorporates:
           *  Gain: '<S359>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S355>/Logical Operator'
           *  Product: '<S354>/Multiply'
           *  Product: '<S354>/Multiply2'
           */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            /* Switch: '<S358>/Switch' incorporates:
             *  Product: '<S354>/Multiply2'
             */
            if (tmp[rtb_Compare_bv_0]) {
              rtb_Divide_l_idx_0 = rtb_Transpose_0[rtb_Compare_bv_0];
            } else {
              rtb_Divide_l_idx_0 = tmp_0[rtb_Compare_bv_0];
            }

            rtb_MatrixConcatenate3[rtb_Compare_bv_0] = tmp_1[rtb_Compare_bv_0] ||
              tmp_2[rtb_Compare_bv_0] ? rtb_Divide_l_idx_0 -
              ((rtb_VectorConcatenate_j4[rtb_Compare_bv_0 + 3] *
                FMS_U.INS_Out.y_R + rtb_VectorConcatenate_j4[rtb_Compare_bv_0] *
                FMS_U.INS_Out.x_R) + rtb_VectorConcatenate_j4[rtb_Compare_bv_0 +
               6] * -FMS_U.INS_Out.h_R) : 0.0F;
          }

          /* End of Sum: '<S354>/Sum2' */
          break;
        }

        /* End of MultiPortSwitch: '<S352>/Index Vector' */

        /* Trigonometry: '<S298>/Trigonometric Function1' incorporates:
         *  Gain: '<S297>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S298>/Trigonometric Function' incorporates:
         *  Gain: '<S297>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S298>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S298>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S298>/Gain' incorporates:
         *  Gain: '<S297>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Trigonometry: '<S298>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S298>/Trigonometric Function3' incorporates:
         *  Gain: '<S297>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S298>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S298>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S298>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_e1[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_e1[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_e1[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S287>/Index Vector' incorporates:
         *  Constant: '<S296>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S287>/Multiply'
         *  Product: '<S294>/Multiply'
         *  Product: '<S295>/Multiply3'
         *  RelationalOperator: '<S296>/Compare'
         *  S-Function (sfix_bitop): '<S293>/ax_cmd valid'
         *  S-Function (sfix_bitop): '<S293>/ay_cmd valid'
         *  S-Function (sfix_bitop): '<S293>/az_cmd valid'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S293>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S293>/az_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_d);
          }
          break;

         case 1:
          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/ax_cmd valid'
           *  S-Function (sfix_bitop): '<S293>/ay_cmd valid'
           *  S-Function (sfix_bitop): '<S293>/az_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_d);
          }
          break;

         case 2:
          /* SignalConversion: '<S300>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S300>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S299>/Gain' incorporates:
           *  DataStoreRead: '<S295>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  Sum: '<S295>/Subtract'
           */
          rtb_Saturation_n = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S300>/Trigonometric Function3' incorporates:
           *  Gain: '<S299>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Saturation_n);

          /* Gain: '<S300>/Gain' incorporates:
           *  Gain: '<S299>/Gain'
           *  Trigonometry: '<S300>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Saturation_n);

          /* SignalConversion: '<S300>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S300>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S300>/Trigonometric Function' incorporates:
           *  Gain: '<S299>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Saturation_n);

          /* Trigonometry: '<S300>/Trigonometric Function1' incorporates:
           *  Gain: '<S299>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Saturation_n);

          /* SignalConversion: '<S300>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_o[0];

          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/ax_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
            FMS_U.Auto_Cmd.ax_cmd : 0.0F;

          /* SignalConversion: '<S300>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_o[1];

          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/ay_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
            FMS_U.Auto_Cmd.ay_cmd : 0.0F;

          /* SignalConversion: '<S300>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_o[2];

          /* Product: '<S287>/Multiply' incorporates:
           *  Constant: '<S296>/Constant'
           *  RelationalOperator: '<S296>/Compare'
           *  S-Function (sfix_bitop): '<S293>/az_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
            FMS_U.Auto_Cmd.az_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_TmpSignalConversionAtMath_c[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_d);
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

        /* End of MultiPortSwitch: '<S287>/Index Vector' */

        /* Sum: '<S348>/Sum1' incorporates:
         *  Constant: '<S348>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S348>/Math Function'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Divide_l_idx_0 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
          FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Abs: '<S349>/Abs' */
        rtb_Saturation_n = fabsf(rtb_Divide_l_idx_0);

        /* Switch: '<S349>/Switch' incorporates:
         *  Constant: '<S349>/Constant'
         *  Constant: '<S350>/Constant'
         *  Product: '<S349>/Multiply'
         *  RelationalOperator: '<S350>/Compare'
         *  Sum: '<S349>/Subtract'
         */
        if (rtb_Saturation_n > 3.14159274F) {
          /* Signum: '<S349>/Sign' */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_Divide_l_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_l_idx_0 > 0.0F) {
              rtb_Divide_l_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S349>/Sign' */
          rtb_Divide_l_idx_0 *= rtb_Saturation_n - 6.28318548F;
        }

        /* End of Switch: '<S349>/Switch' */

        /* Saturate: '<S348>/Saturation' */
        if (rtb_Divide_l_idx_0 > 0.314159274F) {
          rtb_Divide_l_idx_0 = 0.314159274F;
        } else {
          if (rtb_Divide_l_idx_0 < -0.314159274F) {
            rtb_Divide_l_idx_0 = -0.314159274F;
          }
        }

        /* End of Saturate: '<S348>/Saturation' */

        /* Gain: '<S345>/Gain2' */
        rtb_Divide_l_idx_0 *= FMS_PARAM.YAW_P;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S289>/Sum' incorporates:
         *  Constant: '<S347>/Constant'
         *  Constant: '<S351>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S345>/Multiply2'
         *  Product: '<S346>/Multiply1'
         *  RelationalOperator: '<S347>/Compare'
         *  RelationalOperator: '<S351>/Compare'
         *  S-Function (sfix_bitop): '<S345>/psi_cmd valid'
         *  S-Function (sfix_bitop): '<S346>/psi_rate_cmd valid'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Subtract3_od = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                            rtb_Divide_l_idx_0 : 0.0F) +
          ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
           0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S352>/Gain1' */
        rtb_Saturation_n = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[0];
        rtb_MathFunction_p_idx_0 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3[1];

        /* Gain: '<S352>/Gain2' */
        rtb_Divide_l_idx_0 = FMS_PARAM.Z_P * rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Trigonometry: '<S391>/Trigonometric Function1' incorporates:
         *  Gain: '<S390>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S391>/Trigonometric Function' incorporates:
         *  Gain: '<S390>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S391>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S391>/Constant3'
         */
        rtb_Transpose[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Gain: '<S391>/Gain' incorporates:
         *  Gain: '<S390>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Trigonometry: '<S391>/Trigonometric Function2'
         */
        rtb_Transpose[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S391>/Trigonometric Function3' incorporates:
         *  Gain: '<S390>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Transpose[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SignalConversion: '<S391>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S391>/Constant4'
         */
        rtb_Transpose[5] = 0.0F;

        /* SignalConversion: '<S391>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_l[0];
        rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_l[1];
        rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_l[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MultiPortSwitch: '<S353>/Index Vector' incorporates:
         *  Constant: '<S389>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  Product: '<S353>/Multiply'
         *  Product: '<S386>/Multiply'
         *  Product: '<S387>/Multiply3'
         *  RelationalOperator: '<S389>/Compare'
         *  S-Function (sfix_bitop): '<S385>/u_cmd valid'
         *  S-Function (sfix_bitop): '<S385>/v_cmd valid'
         *  S-Function (sfix_bitop): '<S385>/w_cmd valid'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        switch (FMS_U.Auto_Cmd.frame) {
         case 0:
          /* Product: '<S353>/Multiply' incorporates:
           *  Constant: '<S389>/Constant'
           *  RelationalOperator: '<S389>/Compare'
           *  S-Function (sfix_bitop): '<S385>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S385>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S385>/w_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_d);
          }
          break;

         case 1:
          /* Product: '<S353>/Multiply' incorporates:
           *  Constant: '<S389>/Constant'
           *  RelationalOperator: '<S389>/Compare'
           *  S-Function (sfix_bitop): '<S385>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S385>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S385>/w_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_d);
          }
          break;

         case 2:
          /* SignalConversion: '<S393>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S393>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Gain: '<S392>/Gain' incorporates:
           *  DataStoreRead: '<S387>/Data Store Read'
           *  Inport: '<Root>/INS_Out'
           *  Sum: '<S387>/Subtract'
           */
          rtb_Add4_d = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

          /* Trigonometry: '<S393>/Trigonometric Function3' incorporates:
           *  Gain: '<S392>/Gain'
           */
          rtb_Transpose[4] = arm_cos_f32(rtb_Add4_d);

          /* Gain: '<S393>/Gain' incorporates:
           *  Gain: '<S392>/Gain'
           *  Trigonometry: '<S393>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_Add4_d);

          /* SignalConversion: '<S393>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S393>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S393>/Trigonometric Function' incorporates:
           *  Gain: '<S392>/Gain'
           */
          rtb_Transpose[1] = arm_sin_f32(rtb_Add4_d);

          /* Trigonometry: '<S393>/Trigonometric Function1' incorporates:
           *  Gain: '<S392>/Gain'
           */
          rtb_Transpose[0] = arm_cos_f32(rtb_Add4_d);

          /* SignalConversion: '<S393>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3_iz[0];

          /* Product: '<S353>/Multiply' incorporates:
           *  Constant: '<S389>/Constant'
           *  RelationalOperator: '<S389>/Compare'
           *  S-Function (sfix_bitop): '<S385>/u_cmd valid'
           */
          rtb_Add4_d = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
            FMS_U.Auto_Cmd.u_cmd : 0.0F;

          /* SignalConversion: '<S393>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3_iz[1];

          /* Product: '<S353>/Multiply' incorporates:
           *  Constant: '<S389>/Constant'
           *  RelationalOperator: '<S389>/Compare'
           *  S-Function (sfix_bitop): '<S385>/v_cmd valid'
           */
          rtb_Integrator1_a = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
            FMS_U.Auto_Cmd.v_cmd : 0.0F;

          /* SignalConversion: '<S393>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3_iz[2];

          /* Product: '<S353>/Multiply' incorporates:
           *  Constant: '<S389>/Constant'
           *  RelationalOperator: '<S389>/Compare'
           *  S-Function (sfix_bitop): '<S385>/w_cmd valid'
           */
          rtb_Divide_l_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
            FMS_U.Auto_Cmd.w_cmd : 0.0F;
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_MatrixConcatenate3[rtb_Compare_bv_0] =
              rtb_Transpose[rtb_Compare_bv_0 + 6] * rtb_Divide_l_idx_1 +
              (rtb_Transpose[rtb_Compare_bv_0 + 3] * rtb_Integrator1_a +
               rtb_Transpose[rtb_Compare_bv_0] * rtb_Add4_d);
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

        /* End of MultiPortSwitch: '<S353>/Index Vector' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate3[0] += rtb_Saturation_n;
        rtb_MatrixConcatenate3[1] += rtb_MathFunction_p_idx_0;

        /* Sum: '<S290>/Sum1' */
        rtb_Saturation_n = rtb_Divide_l_idx_0 + rtb_MatrixConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S308>/Switch' incorporates:
         *  Constant: '<S323>/Constant'
         *  Constant: '<S325>/Constant'
         *  Constant: '<S326>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S323>/Compare'
         *  RelationalOperator: '<S325>/Compare'
         *  RelationalOperator: '<S326>/Compare'
         *  S-Function (sfix_bitop): '<S308>/x_u_cmd'
         *  S-Function (sfix_bitop): '<S308>/y_v_cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_U.Auto_Cmd.frame <= 2) {
          /* Logic: '<S308>/Logical Operator' incorporates:
           *  Constant: '<S324>/Constant'
           *  Constant: '<S325>/Constant'
           *  Constant: '<S326>/Constant'
           *  RelationalOperator: '<S324>/Compare'
           *  RelationalOperator: '<S325>/Compare'
           *  RelationalOperator: '<S326>/Compare'
           *  S-Function (sfix_bitop): '<S308>/lat_lon_cmd valid'
           *  S-Function (sfix_bitop): '<S308>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S308>/y_v_cmd'
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

        /* End of Switch: '<S308>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Atomic SubSystem: '<S288>/u_cmd_valid' */
        /* MATLAB Function: '<S320>/bit_shift' incorporates:
         *  DataTypeConversion: '<S288>/Data Type Conversion6'
         */
        rtb_y_md = (uint16_T)(rtb_LogicalOperator_a4 << 6);

        /* End of Outputs for SubSystem: '<S288>/u_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S288>/v_cmd_valid' */
        /* MATLAB Function: '<S321>/bit_shift' incorporates:
         *  DataTypeConversion: '<S288>/Data Type Conversion7'
         */
        rtb_y_c1 = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

        /* End of Outputs for SubSystem: '<S288>/v_cmd_valid' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S309>/Switch' incorporates:
         *  Constant: '<S328>/Constant'
         *  Constant: '<S329>/Constant'
         *  Constant: '<S331>/Constant'
         *  Inport: '<Root>/Auto_Cmd'
         *  RelationalOperator: '<S328>/Compare'
         *  RelationalOperator: '<S329>/Compare'
         *  RelationalOperator: '<S331>/Compare'
         *  S-Function (sfix_bitop): '<S309>/ax_cmd'
         *  S-Function (sfix_bitop): '<S309>/ay_cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_U.Auto_Cmd.frame <= 2) {
          /* Logic: '<S309>/Logical Operator' incorporates:
           *  Constant: '<S329>/Constant'
           *  Constant: '<S331>/Constant'
           *  RelationalOperator: '<S329>/Compare'
           *  RelationalOperator: '<S331>/Compare'
           *  S-Function (sfix_bitop): '<S309>/ax_cmd'
           *  S-Function (sfix_bitop): '<S309>/ay_cmd'
           */
          rtb_LogicalOperator_a4 = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
            ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
          rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_a4;
        } else {
          rtb_LogicalOperator_a4 = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
          rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) >
            0U);
        }

        /* End of Switch: '<S309>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S199>/Bus Assignment'
         *  Constant: '<S199>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S199>/Bus Assignment' incorporates:
         *  Inport: '<Root>/Auto_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_an;
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

        /* Saturate: '<S289>/Saturation' */
        if (rtb_Subtract3_od > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (rtb_Subtract3_od < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Subtract3_od;
        }

        /* End of Saturate: '<S289>/Saturation' */

        /* Saturate: '<S290>/Saturation2' */
        if (rtb_MatrixConcatenate3[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_MatrixConcatenate3[0];
        }

        /* End of Saturate: '<S290>/Saturation2' */

        /* Saturate: '<S290>/Saturation1' */
        if (rtb_MatrixConcatenate3[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (rtb_MatrixConcatenate3[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MatrixConcatenate3[1];
        }

        /* End of Saturate: '<S290>/Saturation1' */

        /* Saturate: '<S290>/Saturation3' */
        if (rtb_Saturation_n > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_n < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S199>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_n;
        }

        /* End of Saturate: '<S290>/Saturation3' */

        /* Outputs for Atomic SubSystem: '<S288>/q_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Outputs for Atomic SubSystem: '<S288>/r_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S288>/phi_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S288>/theta_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S288>/psi_rate_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S288>/w_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S288>/ax_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S288>/ay_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S288>/az_cmd_valid' */
        /* Outputs for Atomic SubSystem: '<S288>/throttle_cmd_valid' */
        /* BusAssignment: '<S199>/Bus Assignment' incorporates:
         *  Constant: '<S301>/Constant'
         *  Constant: '<S302>/Constant'
         *  Constant: '<S303>/Constant'
         *  Constant: '<S304>/Constant'
         *  Constant: '<S305>/Constant'
         *  Constant: '<S306>/Constant'
         *  Constant: '<S307>/Constant'
         *  Constant: '<S327>/Constant'
         *  Constant: '<S330>/Constant'
         *  DataTypeConversion: '<S288>/Data Type Conversion10'
         *  DataTypeConversion: '<S288>/Data Type Conversion9'
         *  Inport: '<Root>/Auto_Cmd'
         *  MATLAB Function: '<S310>/bit_shift'
         *  MATLAB Function: '<S311>/bit_shift'
         *  MATLAB Function: '<S312>/bit_shift'
         *  MATLAB Function: '<S314>/bit_shift'
         *  MATLAB Function: '<S315>/bit_shift'
         *  MATLAB Function: '<S316>/bit_shift'
         *  MATLAB Function: '<S317>/bit_shift'
         *  MATLAB Function: '<S318>/bit_shift'
         *  MATLAB Function: '<S319>/bit_shift'
         *  MATLAB Function: '<S322>/bit_shift'
         *  Outport: '<Root>/FMS_Out'
         *  RelationalOperator: '<S301>/Compare'
         *  RelationalOperator: '<S302>/Compare'
         *  RelationalOperator: '<S303>/Compare'
         *  RelationalOperator: '<S304>/Compare'
         *  RelationalOperator: '<S305>/Compare'
         *  RelationalOperator: '<S306>/Compare'
         *  RelationalOperator: '<S307>/Compare'
         *  RelationalOperator: '<S327>/Compare'
         *  RelationalOperator: '<S330>/Compare'
         *  S-Function (sfix_bitop): '<S288>/p_cmd'
         *  S-Function (sfix_bitop): '<S288>/phi_cmd'
         *  S-Function (sfix_bitop): '<S288>/psi_psi_rate_cmd'
         *  S-Function (sfix_bitop): '<S288>/q_cmd'
         *  S-Function (sfix_bitop): '<S288>/r_cmd'
         *  S-Function (sfix_bitop): '<S288>/theta_cmd'
         *  S-Function (sfix_bitop): '<S288>/throttle_cmd'
         *  S-Function (sfix_bitop): '<S308>/alt_z_w_cmd'
         *  S-Function (sfix_bitop): '<S309>/az_cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sum: '<S288>/Add'
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

        /* End of Outputs for SubSystem: '<S288>/throttle_cmd_valid' */
        /* End of Outputs for SubSystem: '<S288>/az_cmd_valid' */
        /* End of Outputs for SubSystem: '<S288>/ay_cmd_valid' */
        /* End of Outputs for SubSystem: '<S288>/ax_cmd_valid' */
        /* End of Outputs for SubSystem: '<S288>/w_cmd_valid' */
        /* End of Outputs for SubSystem: '<S288>/psi_rate_cmd_valid' */
        /* End of Outputs for SubSystem: '<S288>/theta_cmd_valid' */
        /* End of Outputs for SubSystem: '<S288>/phi_cmd_valid' */
        /* End of Outputs for SubSystem: '<S288>/r_cmd_valid' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S288>/q_cmd_valid' */
        /* End of Outputs for SubSystem: '<S38>/Offboard' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S38>/Mission' incorporates:
           *  ActionPort: '<S198>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S38>/Switch Case' incorporates:
           *  UnitDelay: '<S201>/Delay Input1'
           *
           * Block description for '<S201>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S38>/Mission' */

          /* SystemReset for IfAction SubSystem: '<S38>/Mission' incorporates:
           *  ActionPort: '<S198>/Action Port'
           */
          /* SystemReset for Resettable SubSystem: '<S198>/Mission_SubSystem' */
          /* SystemReset for SwitchCase: '<S38>/Switch Case' incorporates:
           *  Chart: '<S240>/Motion Status'
           *  Chart: '<S250>/Motion State'
           *  Delay: '<S206>/Delay'
           *  Delay: '<S228>/Delay'
           *  Delay: '<S228>/Delay1'
           *  DiscreteIntegrator: '<S209>/Integrator'
           *  DiscreteIntegrator: '<S209>/Integrator1'
           *  DiscreteIntegrator: '<S224>/Acceleration_Speed'
           *  DiscreteIntegrator: '<S229>/Discrete-Time Integrator'
           *  DiscreteIntegrator: '<S278>/Discrete-Time Integrator'
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

          /* End of SystemReset for SubSystem: '<S198>/Mission_SubSystem' */
          /* End of SystemReset for SubSystem: '<S38>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S38>/Mission' incorporates:
         *  ActionPort: '<S198>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* RelationalOperator: '<S201>/FixPt Relational Operator' incorporates:
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S201>/Delay Input1'
         *
         * Block description for '<S201>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outputs for Resettable SubSystem: '<S198>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S202>/Reset'
         */
        if (rtb_FixPtRelationalOperator_me &&
            (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
          /* Disable for SwitchCase: '<S249>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

          /* Disable for SwitchCase: '<S239>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

          /* InitializeConditions for DiscreteIntegrator: '<S229>/Discrete-Time Integrator' */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

          /* InitializeConditions for Delay: '<S228>/Delay1' */
          FMS_DW.Delay1_DSTATE = false;

          /* InitializeConditions for Delay: '<S228>/Delay' */
          FMS_DW.icLoad_h = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S224>/Acceleration_Speed' */
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          FMS_DW.Acceleration_Speed_PrevResetSta = 0;

          /* InitializeConditions for DiscreteIntegrator: '<S278>/Discrete-Time Integrator' */
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

          /* InitializeConditions for Delay: '<S206>/Delay' */
          FMS_DW.icLoad_k = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator1' */
          FMS_DW.Integrator1_IC_LOADING = 1U;

          /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator' */
          FMS_DW.Integrator_DSTATE_i = 0.0F;

          /* SystemReset for Chart: '<S250>/Motion State' */
          FMS_MotionState_Reset(&FMS_DW.sf_MotionState_n);

          /* SystemReset for Chart: '<S240>/Motion Status' */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_jt);
        }

        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = rtb_FixPtRelationalOperator_me;

        /* DiscreteIntegrator: '<S229>/Discrete-Time Integrator' incorporates:
         *  UnitDelay: '<S201>/Delay Input1'
         *
         * Block description for '<S201>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

        /* RelationalOperator: '<S223>/Compare' incorporates:
         *  Constant: '<S286>/Constant'
         *  RelationalOperator: '<S286>/Compare'
         *  UnitDelay: '<S201>/Delay Input1'
         *
         * Block description for '<S201>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Compare_on = (FMS_DW.DelayInput1_DSTATE_pe <= 3);

        /* Logic: '<S228>/Logical Operator' incorporates:
         *  Delay: '<S228>/Delay1'
         */
        rtb_LogicalOperator_aa = (rtb_Compare_on || FMS_DW.Delay1_DSTATE);

        /* Delay: '<S228>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
        /* RelationalOperator: '<S233>/Compare' incorporates:
         *  Constant: '<S233>/Constant'
         *  Delay: '<S228>/Delay1'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        FMS_DW.Delay1_DSTATE = (FMS_B.Cmd_In.set_speed > 0.0F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S224>/Switch2' incorporates:
         *  Constant: '<S224>/vel'
         *  Delay: '<S228>/Delay1'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        if (FMS_DW.Delay1_DSTATE) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Add4_d = FMS_B.Cmd_In.set_speed;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        } else {
          rtb_Add4_d = FMS_PARAM.CRUISE_SPEED;
        }

        /* End of Switch: '<S224>/Switch2' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S228>/Sum' incorporates:
         *  Delay: '<S228>/Delay'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_c[0];

        /* Sum: '<S224>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Subtract3_od = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

        /* Sum: '<S228>/Sum' incorporates:
         *  Delay: '<S228>/Delay'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_p_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_DW.Delay_DSTATE_c[1];

        /* Sum: '<S224>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint
          [1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sqrt: '<S236>/Sqrt' incorporates:
         *  Math: '<S236>/Square'
         *  Sum: '<S224>/Sum'
         *  Sum: '<S236>/Sum of Elements'
         */
        rtb_Subtract3_od = sqrtf(rtb_Subtract3_od * rtb_Subtract3_od +
          rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_1);

        /* Switch: '<S224>/Switch' */
        if (rtb_Subtract3_od > FMS_PARAM.L1) {
          rtb_Subtract3_od = rtb_Add4_d;
        } else {
          /* Gain: '<S224>/Gain' */
          rtb_Subtract3_od *= 0.5F;

          /* Switch: '<S234>/Switch2' incorporates:
           *  Constant: '<S224>/Constant1'
           *  RelationalOperator: '<S234>/LowerRelop1'
           *  RelationalOperator: '<S234>/UpperRelop'
           *  Switch: '<S234>/Switch'
           */
          if (rtb_Subtract3_od > rtb_Add4_d) {
            rtb_Subtract3_od = rtb_Add4_d;
          } else {
            if (rtb_Subtract3_od < 0.5F) {
              /* Switch: '<S234>/Switch' incorporates:
               *  Constant: '<S224>/Constant1'
               */
              rtb_Subtract3_od = 0.5F;
            }
          }

          /* End of Switch: '<S234>/Switch2' */
        }

        /* End of Switch: '<S224>/Switch' */

        /* DiscreteIntegrator: '<S224>/Acceleration_Speed' */
        if (rtb_Compare_on || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
          FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
        }

        /* Switch: '<S235>/Switch2' incorporates:
         *  Constant: '<S224>/Constant2'
         *  DiscreteIntegrator: '<S224>/Acceleration_Speed'
         *  RelationalOperator: '<S235>/LowerRelop1'
         *  RelationalOperator: '<S235>/UpperRelop'
         *  Switch: '<S235>/Switch'
         */
        if (FMS_DW.Acceleration_Speed_DSTATE > rtb_Add4_d) {
          rtb_Integrator1_a = rtb_Add4_d;
        } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
          /* Switch: '<S235>/Switch' incorporates:
           *  Constant: '<S224>/Constant2'
           */
          rtb_Integrator1_a = 0.0F;
        } else {
          rtb_Integrator1_a = FMS_DW.Acceleration_Speed_DSTATE;
        }

        /* End of Switch: '<S235>/Switch2' */

        /* Switch: '<S224>/Switch1' incorporates:
         *  Sum: '<S224>/Sum1'
         */
        if (rtb_Integrator1_a - rtb_Subtract3_od >= 0.0F) {
          rtb_Integrator1_a = rtb_Subtract3_od;
        }

        /* End of Switch: '<S224>/Switch1' */

        /* DiscreteIntegrator: '<S278>/Discrete-Time Integrator' */
        if (rtb_LogicalOperator_aa || (FMS_DW.DiscreteTimeIntegrator_PrevRese !=
             0)) {
          FMS_DW.l1_heading = 0.0F;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S250>/Motion State' incorporates:
         *  Constant: '<S250>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S250>/Square'
         *  Math: '<S250>/Square1'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sqrt: '<S250>/Sqrt'
         *  Sum: '<S250>/Add'
         */
        FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                        &FMS_DW.sf_MotionState_n);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S249>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S249>/Hold Control' incorporates:
             *  ActionPort: '<S252>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S249>/Switch Case' */
            FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_d);

            /* End of SystemReset for SubSystem: '<S249>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S249>/Hold Control' incorporates:
           *  ActionPort: '<S252>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_m(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_n,
                            &FMS_ConstB.HoldControl_d, &FMS_DW.HoldControl_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S249>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S249>/Brake Control' incorporates:
           *  ActionPort: '<S251>/Action Port'
           */
          FMS_BrakeControl_h(FMS_B.Merge_n);

          /* End of Outputs for SubSystem: '<S249>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_ai != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S249>/Move Control' incorporates:
             *  ActionPort: '<S253>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S249>/Switch Case' */
            FMS_MoveControl_i_Reset(&FMS_DW.MoveControl_c);

            /* End of SystemReset for SubSystem: '<S249>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S249>/Move Control' incorporates:
           *  ActionPort: '<S253>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_j(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_n,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S249>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S249>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S240>/Motion Status' incorporates:
         *  Abs: '<S240>/Abs'
         *  Constant: '<S240>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_c,
                         &FMS_DW.sf_MotionStatus_jt);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S239>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S239>/Hold Control' incorporates:
             *  ActionPort: '<S242>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S239>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_a);

            /* End of SystemReset for SubSystem: '<S239>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S239>/Hold Control' incorporates:
           *  ActionPort: '<S242>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_e3,
                          &FMS_DW.HoldControl_a);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S239>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S239>/Brake Control' incorporates:
           *  ActionPort: '<S241>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_e3);

          /* End of Outputs for SubSystem: '<S239>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S239>/Move Control' incorporates:
             *  ActionPort: '<S243>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S239>/Switch Case' */
            FMS_MoveControl_Reset(&FMS_DW.MoveControl_m);

            /* End of SystemReset for SubSystem: '<S239>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S239>/Move Control' incorporates:
           *  ActionPort: '<S243>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_e3,
                          &FMS_ConstB.MoveControl_m, &FMS_DW.MoveControl_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S239>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S239>/Switch Case' */

        /* Switch: '<S204>/Switch' incorporates:
         *  Product: '<S228>/Multiply'
         */
        if (rtb_Compare_on) {
          /* Saturate: '<S249>/Saturation1' */
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

          /* End of Saturate: '<S249>/Saturation1' */

          /* Saturate: '<S239>/Saturation1' */
          if (FMS_B.Merge_e3 > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_e3 < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_B.Merge_e3;
          }

          /* End of Saturate: '<S239>/Saturation1' */
        } else {
          /* SignalConversion: '<S285>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S285>/Constant4'
           */
          rtb_Transpose[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S284>/Gain' incorporates:
           *  DiscreteIntegrator: '<S278>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
           *  Sum: '<S278>/Add'
           */
          rtb_MathFunction_f_idx_0 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Trigonometry: '<S285>/Trigonometric Function3' */
          rtb_Transpose[4] = arm_cos_f32(rtb_MathFunction_f_idx_0);

          /* Gain: '<S285>/Gain' incorporates:
           *  Trigonometry: '<S285>/Trigonometric Function2'
           */
          rtb_Transpose[3] = -arm_sin_f32(rtb_MathFunction_f_idx_0);

          /* SignalConversion: '<S285>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S285>/Constant3'
           */
          rtb_Transpose[2] = 0.0F;

          /* Trigonometry: '<S285>/Trigonometric Function' */
          rtb_Transpose[1] = arm_sin_f32(rtb_MathFunction_f_idx_0);

          /* Trigonometry: '<S285>/Trigonometric Function1' */
          rtb_Transpose[0] = arm_cos_f32(rtb_MathFunction_f_idx_0);

          /* SignalConversion: '<S285>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_Transpose[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_Transpose[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_Transpose[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Sum: '<S280>/Sum of Elements' incorporates:
           *  Math: '<S280>/Math Function'
           *  SignalConversion: '<S280>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_l_idx_0 = rtb_Saturation_n * rtb_Saturation_n +
            rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0;

          /* Math: '<S280>/Math Function1' incorporates:
           *  Sum: '<S280>/Sum of Elements'
           *
           * About '<S280>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_MathFunction_f_idx_0 = -sqrtf(fabsf(rtb_Divide_l_idx_0));
          } else {
            rtb_MathFunction_f_idx_0 = sqrtf(rtb_Divide_l_idx_0);
          }

          /* End of Math: '<S280>/Math Function1' */

          /* Switch: '<S280>/Switch' incorporates:
           *  Constant: '<S280>/Constant'
           *  Product: '<S280>/Product'
           */
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_Divide_l_idx_0 = rtb_Saturation_n;
            rtb_Divide_l_idx_1 = rtb_MathFunction_p_idx_0;
          } else {
            rtb_Divide_l_idx_0 = 0.0F;
            rtb_Divide_l_idx_1 = 0.0F;
            rtb_MathFunction_f_idx_0 = 1.0F;
          }

          /* End of Switch: '<S280>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S230>/Sum1' incorporates:
           *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract3_od = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_MathFunction_f_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* Sum: '<S230>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
           *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_MathFunction_f_idx_2 = FMS_U.INS_Out.x_R -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Switch_mp_idx_1 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S230>/Divide' incorporates:
           *  Math: '<S231>/Square'
           *  Math: '<S232>/Square'
           *  Sqrt: '<S231>/Sqrt'
           *  Sqrt: '<S232>/Sqrt'
           *  Sum: '<S230>/Sum'
           *  Sum: '<S230>/Sum1'
           *  Sum: '<S231>/Sum of Elements'
           *  Sum: '<S232>/Sum of Elements'
           */
          rtb_Subtract3_od = sqrtf(rtb_MathFunction_f_idx_2 *
            rtb_MathFunction_f_idx_2 + rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1)
            / sqrtf(rtb_Subtract3_od * rtb_Subtract3_od +
                    rtb_MathFunction_f_idx_1 * rtb_MathFunction_f_idx_1);

          /* Saturate: '<S230>/Saturation' */
          if (rtb_Subtract3_od > 1.0F) {
            rtb_Subtract3_od = 1.0F;
          } else {
            if (rtb_Subtract3_od < 0.0F) {
              rtb_Subtract3_od = 0.0F;
            }
          }

          /* End of Saturate: '<S230>/Saturation' */

          /* Product: '<S276>/Multiply2' incorporates:
           *  Product: '<S280>/Divide'
           */
          rtb_Divide_l_idx_0 = rtb_Divide_l_idx_0 / rtb_MathFunction_f_idx_0 *
            rtb_Integrator1_a;
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_1 / rtb_MathFunction_f_idx_0 *
            rtb_Integrator1_a;

          /* Product: '<S228>/Multiply' */
          for (rtb_Compare_bv_0 = 0; rtb_Compare_bv_0 < 3; rtb_Compare_bv_0++) {
            rtb_Transpose_0[rtb_Compare_bv_0] = rtb_Transpose[rtb_Compare_bv_0 +
              3] * rtb_Divide_l_idx_1 + rtb_Transpose[rtb_Compare_bv_0] *
              rtb_Divide_l_idx_0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S221>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S230>/Multiply'
           *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
           *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S221>/Sum2'
           *  Sum: '<S230>/Add'
           *  Sum: '<S230>/Subtract'
           */
          rtb_Subtract3_od = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Subtract3_od +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_TmpSignalConversionAtMath_c[0] = rtb_Transpose_0[0];
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Transpose_0[1];

          /* Saturate: '<S221>/Saturation1' incorporates:
           *  Product: '<S228>/Multiply'
           */
          if (rtb_Subtract3_od > FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Subtract3_od < -FMS_PARAM.VEL_Z_LIM) {
            rtb_TmpSignalConversionAtMath_c[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_TmpSignalConversionAtMath_c[2] = rtb_Subtract3_od;
          }

          /* End of Saturate: '<S221>/Saturation1' */
        }

        /* End of Switch: '<S204>/Switch' */

        /* Delay: '<S206>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_DW.icLoad_k != 0) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S209>/Integrator1' incorporates:
         *  Delay: '<S206>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE_p = FMS_DW.Delay_DSTATE_h;
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Math: '<S213>/Rem' incorporates:
         *  Constant: '<S213>/Constant1'
         *  DiscreteIntegrator: '<S209>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sum: '<S208>/Sum'
         */
        rtb_Subtract3_od = rt_remf(FMS_DW.Integrator1_DSTATE_p -
          FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Switch: '<S213>/Switch' incorporates:
         *  Abs: '<S213>/Abs'
         *  Constant: '<S213>/Constant'
         *  Constant: '<S214>/Constant'
         *  Product: '<S213>/Multiply'
         *  RelationalOperator: '<S214>/Compare'
         *  Sum: '<S213>/Add'
         */
        if (fabsf(rtb_Subtract3_od) > 3.14159274F) {
          /* Signum: '<S213>/Sign' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Divide_l_idx_0 = -1.0F;
          } else if (rtb_Subtract3_od > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          } else {
            rtb_Divide_l_idx_0 = rtb_Subtract3_od;
          }

          /* End of Signum: '<S213>/Sign' */
          rtb_Subtract3_od -= 6.28318548F * rtb_Divide_l_idx_0;
        }

        /* End of Switch: '<S213>/Switch' */

        /* Gain: '<S208>/Gain2' */
        rtb_Subtract3_od *= FMS_PARAM.YAW_P;

        /* Saturate: '<S208>/Saturation' */
        if (rtb_Subtract3_od > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Subtract3_od = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Subtract3_od < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Subtract3_od = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S208>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S202>/Bus Assignment'
         *  Constant: '<S202>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S202>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_c[0];
        FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_c[1];
        FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_c[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Subtract3_od;

        /* Sum: '<S282>/Sum of Elements' incorporates:
         *  Math: '<S282>/Math Function'
         *  SignalConversion: '<S282>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_l_idx_0 = rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0
          + rtb_Saturation_n * rtb_Saturation_n;

        /* Math: '<S282>/Math Function1' incorporates:
         *  Sum: '<S282>/Sum of Elements'
         *
         * About '<S282>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Subtract3_od = -sqrtf(fabsf(rtb_Divide_l_idx_0));
        } else {
          rtb_Subtract3_od = sqrtf(rtb_Divide_l_idx_0);
        }

        /* End of Math: '<S282>/Math Function1' */

        /* Switch: '<S282>/Switch' incorporates:
         *  Constant: '<S282>/Constant'
         *  Product: '<S282>/Product'
         */
        if (rtb_Subtract3_od > 0.0F) {
          rtb_TmpSignalConversionAtMath_c[0] = rtb_MathFunction_p_idx_0;
          rtb_TmpSignalConversionAtMath_c[1] = rtb_Saturation_n;
          rtb_TmpSignalConversionAtMath_c[2] = rtb_Subtract3_od;
        } else {
          rtb_TmpSignalConversionAtMath_c[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[1] = 0.0F;
          rtb_TmpSignalConversionAtMath_c[2] = 1.0F;
        }

        /* End of Switch: '<S282>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S270>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S270>/Math Function'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_Divide_l_idx_0 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S270>/Math Function1' incorporates:
         *  Sum: '<S270>/Sum of Elements'
         *
         * About '<S270>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Subtract3_od = -sqrtf(fabsf(rtb_Divide_l_idx_0));
        } else {
          rtb_Subtract3_od = sqrtf(rtb_Divide_l_idx_0);
        }

        /* End of Math: '<S270>/Math Function1' */

        /* Switch: '<S270>/Switch' incorporates:
         *  Constant: '<S270>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S270>/Product'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (rtb_Subtract3_od > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_0 = FMS_U.INS_Out.vn;
          rtb_MathFunction_f_idx_1 = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_f_idx_2 = rtb_Subtract3_od;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S270>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S202>/Sum' incorporates:
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_mp_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Switch_mp_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S220>/Sum of Elements' incorporates:
         *  Math: '<S220>/Math Function'
         *  Sum: '<S202>/Sum'
         */
        rtb_Divide_l_idx_0 = rtb_Switch_mp_idx_0 * rtb_Switch_mp_idx_0 +
          rtb_Switch_mp_idx_1 * rtb_Switch_mp_idx_1;

        /* Math: '<S220>/Math Function1' incorporates:
         *  Sum: '<S220>/Sum of Elements'
         *
         * About '<S220>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Subtract3_od = -sqrtf(fabsf(rtb_Divide_l_idx_0));
        } else {
          rtb_Subtract3_od = sqrtf(rtb_Divide_l_idx_0);
        }

        /* End of Math: '<S220>/Math Function1' */

        /* Switch: '<S220>/Switch' incorporates:
         *  Constant: '<S220>/Constant'
         *  Product: '<S220>/Product'
         */
        if (rtb_Subtract3_od > 0.0F) {
          rtb_Switch_mp_idx_2 = rtb_Subtract3_od;
        } else {
          rtb_Switch_mp_idx_0 = 0.0F;
          rtb_Switch_mp_idx_1 = 0.0F;
          rtb_Switch_mp_idx_2 = 1.0F;
        }

        /* End of Switch: '<S220>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S228>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_f3_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Sum_ff[0] = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
        rtb_Switch_f3_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;
        rtb_Sum_ff[1] = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Sum: '<S283>/Sum of Elements' incorporates:
         *  Math: '<S283>/Math Function'
         *  Sum: '<S228>/Sum1'
         */
        rtb_Divide_l_idx_0 = rtb_Switch_f3_idx_0 * rtb_Switch_f3_idx_0 +
          rtb_Switch_f3_idx_1 * rtb_Switch_f3_idx_1;

        /* Math: '<S283>/Math Function1' incorporates:
         *  Sum: '<S283>/Sum of Elements'
         *
         * About '<S283>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Subtract3_od = -sqrtf(fabsf(rtb_Divide_l_idx_0));
        } else {
          rtb_Subtract3_od = sqrtf(rtb_Divide_l_idx_0);
        }

        /* End of Math: '<S283>/Math Function1' */

        /* Switch: '<S283>/Switch' incorporates:
         *  Constant: '<S283>/Constant'
         *  Product: '<S283>/Product'
         */
        if (rtb_Subtract3_od > 0.0F) {
          rtb_Switch_f3_idx_2 = rtb_Subtract3_od;
        } else {
          rtb_Switch_f3_idx_0 = 0.0F;
          rtb_Switch_f3_idx_1 = 0.0F;
          rtb_Switch_f3_idx_2 = 1.0F;
        }

        /* End of Switch: '<S283>/Switch' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S226>/NearbyRefWP' incorporates:
         *  Constant: '<S202>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_NearbyRefWP(&rtb_MatrixConcatenate3[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_ff,
                        &rtb_Divide_l_idx_0);

        /* MATLAB Function: '<S226>/SearchL1RefWP' incorporates:
         *  Constant: '<S202>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_n = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Subtract3_od = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Subtract3_od = rtb_Saturation_n * rtb_Saturation_n +
          rtb_Subtract3_od * rtb_Subtract3_od;

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
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Subtract3_od);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Saturation_n = -1.0F;
        rtb_MathFunction_p_idx_0 = 0.0F;
        rtb_Divide_l_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * rtb_Subtract3_od);
          rtb_Subtract3_od = (-B - u1_tmp) / (2.0F * rtb_Subtract3_od);
          if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Subtract3_od >= 0.0F) &&
              (rtb_Subtract3_od <= 1.0F)) {
            rtb_Saturation_n = fmaxf(D, rtb_Subtract3_od);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_Saturation_n = D;
            guard1 = true;
          } else {
            if ((rtb_Subtract3_od >= 0.0F) && (rtb_Subtract3_od <= 1.0F)) {
              rtb_Saturation_n = rtb_Subtract3_od;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * rtb_Subtract3_od);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Saturation_n = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_MathFunction_p_idx_0 = (FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Saturation_n +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_l_idx_1 = (FMS_B.Cmd_In.sp_waypoint[1] -
                                FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Saturation_n
            + FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* MATLAB Function: '<S226>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_P_l_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
          [0];
        B = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
        rtb_Subtract3_od = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                            B + (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0])
                            * rtb_P_l_idx_0) / (rtb_P_l_idx_0 * rtb_P_l_idx_0 +
          B * B);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_FixPtRelationalOperator_me = (rtb_Subtract3_od <= 0.0F);
        rtb_LogicalOperator_a4 = (rtb_Subtract3_od >= 1.0F);
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
          rtb_P_l_idx_0 = rtb_Subtract3_od * rtb_P_l_idx_0 +
            FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        }

        /* Switch: '<S226>/Switch1' incorporates:
         *  Constant: '<S263>/Constant'
         *  RelationalOperator: '<S263>/Compare'
         */
        if (rtb_Divide_l_idx_0 <= 0.0F) {
          /* Switch: '<S226>/Switch' incorporates:
           *  Constant: '<S262>/Constant'
           *  MATLAB Function: '<S226>/SearchL1RefWP'
           *  RelationalOperator: '<S262>/Compare'
           */
          if (rtb_Saturation_n >= 0.0F) {
            rtb_Sum_ff[0] = rtb_MathFunction_p_idx_0;
            rtb_Sum_ff[1] = rtb_Divide_l_idx_1;
          } else {
            rtb_Sum_ff[0] = rtb_P_l_idx_0;

            /* MATLAB Function: '<S226>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy3Inport1'
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
              rtb_Sum_ff[1] = rtb_Subtract3_od * B + FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }
          }

          /* End of Switch: '<S226>/Switch' */
        }

        /* End of Switch: '<S226>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S227>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_MathFunction_p_idx_0 = rtb_Sum_ff[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Sum_ff[0] = rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0;
        rtb_Saturation_n = rtb_MathFunction_p_idx_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S227>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S271>/Math Function'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_MathFunction_p_idx_0 = rtb_Sum_ff[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S271>/Math Function' incorporates:
         *  Math: '<S269>/Square'
         */
        rtb_Divide_l_idx_0 = rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0;

        /* Sum: '<S271>/Sum of Elements' incorporates:
         *  Math: '<S271>/Math Function'
         */
        rtb_Rem_p = rtb_Divide_l_idx_0 + rtb_Sum_ff[0];

        /* Math: '<S271>/Math Function1' incorporates:
         *  Sum: '<S271>/Sum of Elements'
         *
         * About '<S271>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Subtract3_od = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          rtb_Subtract3_od = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S271>/Math Function1' */

        /* Switch: '<S271>/Switch' incorporates:
         *  Constant: '<S271>/Constant'
         *  Product: '<S271>/Product'
         */
        if (rtb_Subtract3_od > 0.0F) {
          rtb_MatrixConcatenate3[0] = rtb_Saturation_n;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_p_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Subtract3_od;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S271>/Switch' */

        /* Product: '<S270>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MathFunction_f_idx_0 /
          rtb_MathFunction_f_idx_2;
        D = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Sum: '<S273>/Sum of Elements' incorporates:
         *  Math: '<S273>/Math Function'
         *  SignalConversion: '<S273>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = D * D + rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Math: '<S273>/Math Function1' incorporates:
         *  Sum: '<S273>/Sum of Elements'
         *
         * About '<S273>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Subtract3_od = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          rtb_Subtract3_od = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S273>/Math Function1' */

        /* Switch: '<S273>/Switch' incorporates:
         *  Constant: '<S273>/Constant'
         *  Product: '<S273>/Product'
         */
        if (rtb_Subtract3_od > 0.0F) {
          rtb_MathFunction_f_idx_0 = D;
          rtb_MathFunction_f_idx_1 = rtb_MathFunction_h_idx_0;
          rtb_MathFunction_f_idx_2 = rtb_Subtract3_od;
        } else {
          rtb_MathFunction_f_idx_0 = 0.0F;
          rtb_MathFunction_f_idx_1 = 0.0F;
          rtb_MathFunction_f_idx_2 = 1.0F;
        }

        /* End of Switch: '<S273>/Switch' */

        /* Product: '<S271>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];
        D = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Sum: '<S274>/Sum of Elements' incorporates:
         *  Math: '<S274>/Math Function'
         *  SignalConversion: '<S274>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Rem_p = D * D + rtb_MathFunction_h_idx_0 * rtb_MathFunction_h_idx_0;

        /* Math: '<S274>/Math Function1' incorporates:
         *  Sum: '<S274>/Sum of Elements'
         *
         * About '<S274>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Rem_p < 0.0F) {
          rtb_Subtract3_od = -sqrtf(fabsf(rtb_Rem_p));
        } else {
          rtb_Subtract3_od = sqrtf(rtb_Rem_p);
        }

        /* End of Math: '<S274>/Math Function1' */

        /* Switch: '<S274>/Switch' incorporates:
         *  Constant: '<S274>/Constant'
         *  Product: '<S274>/Product'
         */
        if (rtb_Subtract3_od > 0.0F) {
          rtb_MatrixConcatenate3[0] = D;
          rtb_MatrixConcatenate3[1] = rtb_MathFunction_h_idx_0;
          rtb_MatrixConcatenate3[2] = rtb_Subtract3_od;
        } else {
          rtb_MatrixConcatenate3[0] = 0.0F;
          rtb_MatrixConcatenate3[1] = 0.0F;
          rtb_MatrixConcatenate3[2] = 1.0F;
        }

        /* End of Switch: '<S274>/Switch' */

        /* Product: '<S274>/Divide' */
        rtb_MathFunction_h_idx_0 = rtb_MatrixConcatenate3[0] /
          rtb_MatrixConcatenate3[2];

        /* Product: '<S273>/Divide' */
        rtb_Sum_ff[0] = rtb_MathFunction_f_idx_0 / rtb_MathFunction_f_idx_2;

        /* Product: '<S283>/Divide' */
        rtb_MathFunction_p_idx_0 = rtb_Switch_f3_idx_0 / rtb_Switch_f3_idx_2;

        /* Product: '<S220>/Divide' */
        rtb_P_l_idx_0 = rtb_Switch_mp_idx_0 / rtb_Switch_mp_idx_2;

        /* Product: '<S282>/Divide' */
        rtb_Switch_mp_idx_0 = rtb_TmpSignalConversionAtMath_c[0] /
          rtb_TmpSignalConversionAtMath_c[2];
        rtb_Saturation_n *= rtb_Saturation_n;

        /* Product: '<S274>/Divide' incorporates:
         *  Math: '<S269>/Square'
         */
        D = rtb_MatrixConcatenate3[1] / rtb_MatrixConcatenate3[2];

        /* Product: '<S273>/Divide' */
        rtb_Sum_ff[1] = rtb_MathFunction_f_idx_1 / rtb_MathFunction_f_idx_2;

        /* Product: '<S283>/Divide' */
        rtb_Divide_l_idx_1 = rtb_Switch_f3_idx_1 / rtb_Switch_f3_idx_2;

        /* Product: '<S220>/Divide' */
        rtb_MathFunction_f_idx_0 = rtb_Switch_mp_idx_1 / rtb_Switch_mp_idx_2;

        /* Product: '<S282>/Divide' */
        rtb_MathFunction_f_idx_1 = rtb_TmpSignalConversionAtMath_c[1] /
          rtb_TmpSignalConversionAtMath_c[2];

        /* Sum: '<S281>/Subtract' incorporates:
         *  Product: '<S281>/Multiply'
         *  Product: '<S281>/Multiply1'
         */
        rtb_Subtract3_od = rtb_MathFunction_p_idx_0 * rtb_MathFunction_f_idx_1 -
          rtb_Divide_l_idx_1 * rtb_Switch_mp_idx_0;

        /* Signum: '<S277>/Sign1' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S277>/Sign1' */

        /* Switch: '<S277>/Switch2' incorporates:
         *  Constant: '<S277>/Constant4'
         */
        if (rtb_Subtract3_od == 0.0F) {
          rtb_Subtract3_od = 1.0F;
        }

        /* End of Switch: '<S277>/Switch2' */

        /* DotProduct: '<S277>/Dot Product' */
        rtb_MathFunction_f_idx_1 = rtb_Switch_mp_idx_0 *
          rtb_MathFunction_p_idx_0 + rtb_MathFunction_f_idx_1 *
          rtb_Divide_l_idx_1;

        /* Trigonometry: '<S277>/Acos' incorporates:
         *  DotProduct: '<S277>/Dot Product'
         */
        if (rtb_MathFunction_f_idx_1 > 1.0F) {
          rtb_MathFunction_f_idx_1 = 1.0F;
        } else {
          if (rtb_MathFunction_f_idx_1 < -1.0F) {
            rtb_MathFunction_f_idx_1 = -1.0F;
          }
        }

        /* Product: '<S277>/Multiply' incorporates:
         *  Trigonometry: '<S277>/Acos'
         */
        rtb_Subtract3_od *= acosf(rtb_MathFunction_f_idx_1);

        /* Abs: '<S228>/Abs' */
        rtb_Subtract3_od = fabsf(rtb_Subtract3_od);

        /* RelationalOperator: '<S275>/Compare' incorporates:
         *  Constant: '<S275>/Constant'
         *  Delay: '<S228>/Delay1'
         */
        FMS_DW.Delay1_DSTATE = (rtb_Subtract3_od > 1.57079637F);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sqrt: '<S268>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S268>/Square'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sum: '<S268>/Sum of Elements'
         */
        rtb_MathFunction_p_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S227>/Square' */
        rtb_Divide_l_idx_1 = rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0;

        /* Sum: '<S272>/Subtract' incorporates:
         *  Product: '<S272>/Multiply'
         *  Product: '<S272>/Multiply1'
         */
        rtb_MathFunction_p_idx_0 = rtb_MathFunction_h_idx_0 * rtb_Sum_ff[1] - D *
          rtb_Sum_ff[0];

        /* Signum: '<S267>/Sign1' */
        if (rtb_MathFunction_p_idx_0 < 0.0F) {
          rtb_MathFunction_p_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_p_idx_0 > 0.0F) {
            rtb_MathFunction_p_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S267>/Sign1' */

        /* Switch: '<S267>/Switch2' incorporates:
         *  Constant: '<S267>/Constant4'
         */
        if (rtb_MathFunction_p_idx_0 == 0.0F) {
          rtb_MathFunction_p_idx_0 = 1.0F;
        }

        /* End of Switch: '<S267>/Switch2' */

        /* DotProduct: '<S267>/Dot Product' */
        rtb_Subtract3_od = rtb_Sum_ff[0] * rtb_MathFunction_h_idx_0 +
          rtb_Sum_ff[1] * D;

        /* Trigonometry: '<S267>/Acos' incorporates:
         *  DotProduct: '<S267>/Dot Product'
         */
        if (rtb_Subtract3_od > 1.0F) {
          rtb_Subtract3_od = 1.0F;
        } else {
          if (rtb_Subtract3_od < -1.0F) {
            rtb_Subtract3_od = -1.0F;
          }
        }

        /* Product: '<S267>/Multiply' incorporates:
         *  Trigonometry: '<S267>/Acos'
         */
        rtb_MathFunction_p_idx_0 *= acosf(rtb_Subtract3_od);

        /* Saturate: '<S227>/Saturation' */
        if (rtb_MathFunction_p_idx_0 > 1.57079637F) {
          rtb_MathFunction_p_idx_0 = 1.57079637F;
        } else {
          if (rtb_MathFunction_p_idx_0 < -1.57079637F) {
            rtb_MathFunction_p_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S227>/Saturation' */

        /* Switch: '<S279>/Switch2' incorporates:
         *  Constant: '<S228>/Constant1'
         *  RelationalOperator: '<S279>/LowerRelop1'
         *  RelationalOperator: '<S279>/UpperRelop'
         *  Switch: '<S279>/Switch'
         */
        if (rtb_Integrator1_a > rtb_Add4_d) {
          rtb_Integrator1_a = rtb_Add4_d;
        } else {
          if (rtb_Integrator1_a < 0.5F) {
            /* Switch: '<S279>/Switch' incorporates:
             *  Constant: '<S228>/Constant1'
             */
            rtb_Integrator1_a = 0.5F;
          }
        }

        /* End of Switch: '<S279>/Switch2' */

        /* Product: '<S228>/Divide1' incorporates:
         *  Constant: '<S202>/L1'
         *  Constant: '<S227>/Constant'
         *  Gain: '<S227>/Gain'
         *  MinMax: '<S227>/Max'
         *  MinMax: '<S227>/Min'
         *  Product: '<S227>/Divide'
         *  Product: '<S227>/Multiply1'
         *  Sqrt: '<S269>/Sqrt'
         *  Sum: '<S269>/Sum of Elements'
         *  Trigonometry: '<S227>/Sin'
         */
        rtb_MathFunction_p_idx_0 = 2.0F * rtb_Divide_l_idx_1 * arm_sin_f32
          (rtb_MathFunction_p_idx_0) / fminf(FMS_PARAM.L1, fmaxf(sqrtf
          (rtb_Divide_l_idx_0 + rtb_Saturation_n), 0.5F)) / rtb_Integrator1_a;

        /* Saturate: '<S228>/Saturation' */
        if (rtb_MathFunction_p_idx_0 > 0.314159274F) {
          rtb_Integrator1_a = 0.314159274F;
        } else if (rtb_MathFunction_p_idx_0 < -0.314159274F) {
          rtb_Integrator1_a = -0.314159274F;
        } else {
          rtb_Integrator1_a = rtb_MathFunction_p_idx_0;
        }

        /* End of Saturate: '<S228>/Saturation' */

        /* Sum: '<S218>/Subtract' incorporates:
         *  Product: '<S218>/Multiply'
         *  Product: '<S218>/Multiply1'
         */
        rtb_MathFunction_p_idx_0 = rtb_P_l_idx_0 * FMS_ConstB.Divide[1] -
          rtb_MathFunction_f_idx_0 * FMS_ConstB.Divide[0];

        /* Signum: '<S207>/Sign1' */
        if (rtb_MathFunction_p_idx_0 < 0.0F) {
          rtb_MathFunction_p_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_p_idx_0 > 0.0F) {
            rtb_MathFunction_p_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S207>/Sign1' */

        /* Switch: '<S207>/Switch2' incorporates:
         *  Constant: '<S207>/Constant4'
         */
        if (rtb_MathFunction_p_idx_0 == 0.0F) {
          rtb_MathFunction_p_idx_0 = 1.0F;
        }

        /* End of Switch: '<S207>/Switch2' */

        /* DotProduct: '<S207>/Dot Product' */
        rtb_Subtract3_od = FMS_ConstB.Divide[0] * rtb_P_l_idx_0 +
          FMS_ConstB.Divide[1] * rtb_MathFunction_f_idx_0;

        /* Trigonometry: '<S207>/Acos' incorporates:
         *  DotProduct: '<S207>/Dot Product'
         */
        if (rtb_Subtract3_od > 1.0F) {
          rtb_Subtract3_od = 1.0F;
        } else {
          if (rtb_Subtract3_od < -1.0F) {
            rtb_Subtract3_od = -1.0F;
          }
        }

        /* Product: '<S207>/Multiply' incorporates:
         *  Trigonometry: '<S207>/Acos'
         */
        rtb_MathFunction_p_idx_0 *= acosf(rtb_Subtract3_od);

        /* Math: '<S210>/Rem' incorporates:
         *  Constant: '<S210>/Constant1'
         *  Delay: '<S206>/Delay'
         *  Sum: '<S206>/Sum2'
         */
        rtb_Subtract3_od = rt_remf(rtb_MathFunction_p_idx_0 -
          FMS_DW.Delay_DSTATE_h, 6.28318548F);

        /* Switch: '<S210>/Switch' incorporates:
         *  Abs: '<S210>/Abs'
         *  Constant: '<S210>/Constant'
         *  Constant: '<S216>/Constant'
         *  Product: '<S210>/Multiply'
         *  RelationalOperator: '<S216>/Compare'
         *  Sum: '<S210>/Add'
         */
        if (fabsf(rtb_Subtract3_od) > 3.14159274F) {
          /* Signum: '<S210>/Sign' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else if (rtb_Subtract3_od > 0.0F) {
            rtb_Saturation_n = 1.0F;
          } else {
            rtb_Saturation_n = rtb_Subtract3_od;
          }

          /* End of Signum: '<S210>/Sign' */
          rtb_Subtract3_od -= 6.28318548F * rtb_Saturation_n;
        }

        /* End of Switch: '<S210>/Switch' */

        /* Sum: '<S206>/Sum' incorporates:
         *  Delay: '<S206>/Delay'
         */
        rtb_Saturation_n = rtb_Subtract3_od + FMS_DW.Delay_DSTATE_h;

        /* Product: '<S215>/Multiply1' incorporates:
         *  Constant: '<S215>/const1'
         *  DiscreteIntegrator: '<S209>/Integrator'
         */
        rtb_Subtract3_od = FMS_DW.Integrator_DSTATE_i * 0.785398185F;

        /* Sum: '<S215>/Add' incorporates:
         *  DiscreteIntegrator: '<S209>/Integrator1'
         *  Sum: '<S209>/Subtract'
         */
        rtb_Add4_d = (FMS_DW.Integrator1_DSTATE_p - rtb_Saturation_n) +
          rtb_Subtract3_od;

        /* Signum: '<S215>/Sign' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Add4_d > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Add4_d;
        }

        /* End of Signum: '<S215>/Sign' */

        /* Sum: '<S215>/Add2' incorporates:
         *  Abs: '<S215>/Abs'
         *  Gain: '<S215>/Gain'
         *  Gain: '<S215>/Gain1'
         *  Product: '<S215>/Multiply2'
         *  Product: '<S215>/Multiply3'
         *  Sqrt: '<S215>/Sqrt'
         *  Sum: '<S215>/Add1'
         *  Sum: '<S215>/Subtract'
         */
        rtb_Divide_l_idx_0 = (sqrtf((8.0F * fabsf(rtb_Add4_d) + FMS_ConstB.d) *
          FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Saturation_n +
          rtb_Subtract3_od;

        /* Sum: '<S215>/Add4' */
        rtb_Subtract3_od += rtb_Add4_d - rtb_Divide_l_idx_0;

        /* Sum: '<S215>/Add3' */
        rtb_Saturation_n = rtb_Add4_d + FMS_ConstB.d;

        /* Sum: '<S215>/Subtract1' */
        rtb_Add4_d -= FMS_ConstB.d;

        /* Signum: '<S215>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S215>/Sign1' */

        /* Signum: '<S215>/Sign2' */
        if (rtb_Add4_d < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else {
          if (rtb_Add4_d > 0.0F) {
            rtb_Add4_d = 1.0F;
          }
        }

        /* End of Signum: '<S215>/Sign2' */

        /* Sum: '<S215>/Add5' incorporates:
         *  Gain: '<S215>/Gain2'
         *  Product: '<S215>/Multiply4'
         *  Sum: '<S215>/Subtract2'
         */
        rtb_Divide_l_idx_0 += (rtb_Saturation_n - rtb_Add4_d) * 0.5F *
          rtb_Subtract3_od;

        /* Sum: '<S215>/Subtract3' */
        rtb_Saturation_n = rtb_Divide_l_idx_0 - FMS_ConstB.d;

        /* Sum: '<S215>/Add6' */
        rtb_Subtract3_od = rtb_Divide_l_idx_0 + FMS_ConstB.d;

        /* Product: '<S215>/Divide' */
        rtb_Divide_l_idx_1 = rtb_Divide_l_idx_0 / FMS_ConstB.d;

        /* Signum: '<S215>/Sign5' incorporates:
         *  Signum: '<S215>/Sign6'
         */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
          rtb_Add4_d = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_MathFunction_f_idx_0 = 1.0F;
          rtb_Add4_d = 1.0F;
        } else {
          rtb_MathFunction_f_idx_0 = rtb_Divide_l_idx_0;
          rtb_Add4_d = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S215>/Sign5' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S206>/Sum1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_MathFunction_p_idx_0 -= FMS_U.INS_Out.psi;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S211>/Rem' incorporates:
         *  Constant: '<S211>/Constant1'
         */
        rtb_Divide_l_idx_0 = rt_remf(rtb_MathFunction_p_idx_0, 6.28318548F);

        /* Switch: '<S211>/Switch' incorporates:
         *  Abs: '<S211>/Abs'
         *  Constant: '<S211>/Constant'
         *  Constant: '<S217>/Constant'
         *  Product: '<S211>/Multiply'
         *  RelationalOperator: '<S217>/Compare'
         *  Sum: '<S211>/Add'
         */
        if (fabsf(rtb_Divide_l_idx_0) > 3.14159274F) {
          /* Signum: '<S211>/Sign' */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_MathFunction_p_idx_0 = -1.0F;
          } else if (rtb_Divide_l_idx_0 > 0.0F) {
            rtb_MathFunction_p_idx_0 = 1.0F;
          } else {
            rtb_MathFunction_p_idx_0 = rtb_Divide_l_idx_0;
          }

          /* End of Signum: '<S211>/Sign' */
          rtb_Divide_l_idx_0 -= 6.28318548F * rtb_MathFunction_p_idx_0;
        }

        /* End of Switch: '<S211>/Switch' */

        /* Abs: '<S204>/Abs' */
        rtb_Divide_l_idx_0 = fabsf(rtb_Divide_l_idx_0);

        /* Update for DiscreteIntegrator: '<S229>/Discrete-Time Integrator' incorporates:
         *  Constant: '<S222>/Constant'
         *  RelationalOperator: '<S222>/Compare'
         */
        FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)
          (rtb_Divide_l_idx_0 <= 0.17453292F) +
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S229>/Discrete-Time Integrator' */

        /* Update for Delay: '<S228>/Delay' */
        FMS_DW.icLoad_h = 0U;

        /* Update for DiscreteIntegrator: '<S224>/Acceleration_Speed' incorporates:
         *  Constant: '<S224>/Constant'
         */
        FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
        FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_on;

        /* Update for DiscreteIntegrator: '<S278>/Discrete-Time Integrator' */
        FMS_DW.l1_heading += 0.004F * rtb_Integrator1_a;
        FMS_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_LogicalOperator_aa;

        /* Update for Delay: '<S206>/Delay' */
        FMS_DW.icLoad_k = 0U;

        /* Update for DiscreteIntegrator: '<S209>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S209>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_i;

        /* Signum: '<S215>/Sign3' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S215>/Sign3' */

        /* Signum: '<S215>/Sign4' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S215>/Sign4' */

        /* Update for DiscreteIntegrator: '<S209>/Integrator' incorporates:
         *  Constant: '<S215>/const'
         *  Gain: '<S215>/Gain3'
         *  Product: '<S215>/Multiply5'
         *  Product: '<S215>/Multiply6'
         *  Sum: '<S215>/Subtract4'
         *  Sum: '<S215>/Subtract5'
         *  Sum: '<S215>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_i += ((rtb_Divide_l_idx_1 -
          rtb_MathFunction_f_idx_0) * FMS_ConstB.Gain4 * ((rtb_Subtract3_od -
          rtb_Saturation_n) * 0.5F) - rtb_Add4_d * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE_i >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE_i = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE_i <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_i = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S209>/Integrator' */
        /* End of Outputs for SubSystem: '<S198>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Update for UnitDelay: '<S201>/Delay Input1' incorporates:
         *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S201>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S38>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S38>/Unknown' incorporates:
         *  ActionPort: '<S200>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S38>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S38>/Switch Case' */
      /* End of Outputs for SubSystem: '<S33>/Auto' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S33>/Assist' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* SwitchCase: '<S37>/Switch Case' */
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

       case VehicleState_TerrainTrack:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 4;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_f = 5;
        break;
      }

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) {
        switch (rtPrevAction) {
         case 0:
         case 5:
          break;

         case 1:
          /* Disable for SwitchCase: '<S140>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S53>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

          /* Disable for SwitchCase: '<S73>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_mn = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S88>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

          /* Disable for SwitchCase: '<S111>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_lm = -1;

          /* Disable for SwitchCase: '<S99>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bu = -1;
          break;

         case 4:
          /* Disable for SwitchCase: '<S181>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S155>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fi = -1;

          /* Disable for SwitchCase: '<S169>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S37>/Acro' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S42>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  Gain: '<S48>/Gain'
         *  Gain: '<S48>/Gain1'
         *  Gain: '<S48>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S49>/Saturation' incorporates:
         *  Constant: '<S49>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sum: '<S49>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Divide_l_idx_0 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Divide_l_idx_0 = 0.0F;
        } else {
          rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S49>/Saturation' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S42>/Bus Assignment' incorporates:
         *  Constant: '<S49>/Constant5'
         *  Gain: '<S49>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S49>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Divide_l_idx_0), 65536.0F) + 1000U);

        /* End of Outputs for SubSystem: '<S37>/Acro' */
        break;

       case 1:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Stabilize' incorporates:
           *  ActionPort: '<S45>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S134>/Integrator'
           *  DiscreteIntegrator: '<S134>/Integrator1'
           *  DiscreteIntegrator: '<S135>/Integrator'
           *  DiscreteIntegrator: '<S135>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_k = 0.0F;
          FMS_DW.Integrator_DSTATE_a = 0.0F;
          FMS_DW.Integrator1_DSTATE_nf = 0.0F;
          FMS_DW.Integrator_DSTATE_b = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Stabilize' */

          /* SystemReset for IfAction SubSystem: '<S37>/Stabilize' incorporates:
           *  ActionPort: '<S45>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S141>/Motion State'
           */
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_e);

          /* End of SystemReset for SubSystem: '<S37>/Stabilize' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Stabilize' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S132>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Divide_l_idx_0 = 0.0F;
        } else {
          rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S132>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S132>/Gain' */
        rtb_Saturation_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Divide_l_idx_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S133>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Divide_l_idx_0 = 0.0F;
        } else {
          rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S133>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S133>/Gain' */
        rtb_MathFunction_p_idx_0 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_Divide_l_idx_0;

        /* Sum: '<S136>/Sum of Elements' incorporates:
         *  Math: '<S136>/Square'
         *  SignalConversion: '<S136>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S137>/Sum of Elements'
         *  Switch: '<S128>/Switch'
         */
        rtb_Divide_l_idx_0 = rtb_Saturation_n * rtb_Saturation_n +
          rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0;

        /* Switch: '<S128>/Switch' incorporates:
         *  Constant: '<S131>/Constant'
         *  Product: '<S137>/Divide'
         *  RelationalOperator: '<S131>/Compare'
         *  Sqrt: '<S136>/Sqrt'
         *  Sum: '<S136>/Sum of Elements'
         */
        if (sqrtf(rtb_Divide_l_idx_0) > 1.0F) {
          /* Math: '<S137>/Math Function1'
           *
           * About '<S137>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_Subtract3_od = -sqrtf(fabsf(rtb_Divide_l_idx_0));
          } else {
            rtb_Subtract3_od = sqrtf(rtb_Divide_l_idx_0);
          }

          /* End of Math: '<S137>/Math Function1' */

          /* Switch: '<S137>/Switch' incorporates:
           *  Constant: '<S137>/Constant'
           *  Product: '<S137>/Product'
           */
          if (rtb_Subtract3_od > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Saturation_n;
            rtb_MatrixConcatenate3[1] = rtb_MathFunction_p_idx_0;
            rtb_MatrixConcatenate3[2] = rtb_Subtract3_od;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S137>/Switch' */
          rtb_Saturation_n = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3
            [2];
          rtb_MathFunction_p_idx_0 = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Logic: '<S128>/Logical Operator' incorporates:
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S138>/Multiply1' incorporates:
         *  Constant: '<S138>/const1'
         *  DiscreteIntegrator: '<S134>/Integrator'
         */
        rtb_Add4_d = FMS_DW.Integrator_DSTATE_a * 0.04F;

        /* Sum: '<S138>/Add' incorporates:
         *  DataTypeConversion: '<S128>/Data Type Conversion'
         *  DiscreteIntegrator: '<S134>/Integrator1'
         *  Gain: '<S128>/Gain'
         *  Product: '<S128>/Multiply'
         *  Sum: '<S134>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_k -
                             FMS_PARAM.ROLL_PITCH_LIM * rtb_Saturation_n *
                             (real32_T)rtb_FixPtRelationalOperator_me) +
          rtb_Add4_d;

        /* Saturate: '<S138>/Saturation' incorporates:
         *  Constant: '<S134>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Divide_l_idx_0 = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Divide_l_idx_0 = 0.0F;
        } else {
          rtb_Divide_l_idx_0 = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S138>/Saturation' */

        /* Product: '<S138>/Multiply7' incorporates:
         *  Constant: '<S138>/const'
         */
        rtb_Divide_l_idx_1 = 31.415926F * rtb_Divide_l_idx_0;

        /* Product: '<S138>/Multiply' */
        rtb_MathFunction_f_idx_0 = rtb_Divide_l_idx_1 * FMS_ConstB.Square_c;

        /* Signum: '<S138>/Sign' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Integrator1_a > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Integrator1_a;
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
        rtb_Divide_l_idx_0 = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) +
          rtb_MathFunction_f_idx_0) * rtb_MathFunction_f_idx_0) -
                              rtb_MathFunction_f_idx_0) * 0.5F *
          rtb_Saturation_n + rtb_Add4_d;

        /* Sum: '<S138>/Add4' */
        rtb_Subtract3_od = (rtb_Integrator1_a - rtb_Divide_l_idx_0) + rtb_Add4_d;

        /* Sum: '<S138>/Add3' */
        rtb_Saturation_n = rtb_Integrator1_a + rtb_MathFunction_f_idx_0;

        /* Sum: '<S138>/Subtract1' */
        rtb_Integrator1_a -= rtb_MathFunction_f_idx_0;

        /* Signum: '<S138>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S138>/Sign1' */

        /* Signum: '<S138>/Sign2' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S138>/Sign2' */

        /* Sum: '<S138>/Add5' incorporates:
         *  Gain: '<S138>/Gain2'
         *  Product: '<S138>/Multiply4'
         *  Sum: '<S138>/Subtract2'
         */
        rtb_Divide_l_idx_0 += (rtb_Saturation_n - rtb_Integrator1_a) * 0.5F *
          rtb_Subtract3_od;

        /* Sum: '<S138>/Subtract3' */
        rtb_Saturation_n = rtb_Divide_l_idx_0 - rtb_MathFunction_f_idx_0;

        /* Sum: '<S138>/Add6' */
        rtb_Subtract3_od = rtb_Divide_l_idx_0 + rtb_MathFunction_f_idx_0;

        /* Signum: '<S138>/Sign5' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S138>/Sign5' */

        /* Signum: '<S138>/Sign3' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S138>/Sign3' */

        /* Signum: '<S138>/Sign4' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S138>/Sign4' */

        /* Product: '<S138>/Multiply5' incorporates:
         *  Gain: '<S138>/Gain3'
         *  Gain: '<S138>/Gain4'
         *  Product: '<S138>/Divide'
         *  Sum: '<S138>/Subtract4'
         *  Sum: '<S138>/Subtract5'
         */
        rtb_Subtract3_od = (rtb_Divide_l_idx_0 / rtb_MathFunction_f_idx_0 -
                            rtb_Add4_d) * -rtb_Divide_l_idx_1 *
          ((rtb_Subtract3_od - rtb_Saturation_n) * 0.5F);

        /* Signum: '<S138>/Sign6' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Divide_l_idx_0 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_0 > 0.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S138>/Sign6' */

        /* Product: '<S138>/Multiply6' */
        rtb_MathFunction_f_idx_1 = rtb_Divide_l_idx_0 * rtb_Divide_l_idx_1;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S141>/Motion State' incorporates:
         *  Abs: '<S141>/Abs'
         *  Abs: '<S141>/Abs1'
         *  Constant: '<S150>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S150>/Compare'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_e);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S140>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S140>/Hold Control' incorporates:
             *  ActionPort: '<S142>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S140>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_h);

            /* End of SystemReset for SubSystem: '<S140>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S140>/Hold Control' incorporates:
           *  ActionPort: '<S142>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl_h);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S140>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fs != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S140>/Move Control' incorporates:
             *  ActionPort: '<S143>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S140>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

            /* End of SystemReset for SubSystem: '<S140>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S140>/Move Control' incorporates:
           *  ActionPort: '<S143>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S140>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S140>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S130>/Switch' incorporates:
         *  Constant: '<S130>/Constant'
         *  Constant: '<S130>/Constant4'
         *  Constant: '<S130>/Constant5'
         *  Gain: '<S130>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Saturate: '<S130>/Saturation'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sum: '<S130>/Add'
         *  Sum: '<S130>/Sum'
         */
        if (FMS_B.Compare) {
          rtb_y_md = FMS_PARAM.LAND_LOCK_THRO;
        } else {
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            /* Saturate: '<S130>/Saturation' */
            rtb_Divide_l_idx_0 = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            /* Saturate: '<S130>/Saturation' */
            rtb_Divide_l_idx_0 = 0.0F;
          } else {
            /* Saturate: '<S130>/Saturation' incorporates:
             *  Constant: '<S130>/Constant4'
             *  Inport: '<Root>/Pilot_Cmd'
             *  Sum: '<S130>/Sum'
             */
            rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          rtb_y_md = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_Divide_l_idx_0), 65536.0F) + 1000U);
        }

        /* End of Switch: '<S130>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S45>/Bus Assignment'
         *  Constant: '<S45>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S45>/Bus Assignment' incorporates:
         *  DiscreteIntegrator: '<S134>/Integrator1'
         *  DiscreteIntegrator: '<S135>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_k;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_nf;

        /* Saturate: '<S140>/Saturation' */
        if (FMS_B.Merge_j > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S45>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_j < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S45>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S45>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_j;
        }

        /* End of Saturate: '<S140>/Saturation' */

        /* BusAssignment: '<S45>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.throttle_cmd = rtb_y_md;

        /* Product: '<S139>/Multiply1' incorporates:
         *  Constant: '<S139>/const1'
         *  DiscreteIntegrator: '<S135>/Integrator'
         */
        rtb_MathFunction_f_idx_0 = FMS_DW.Integrator_DSTATE_b * 0.04F;

        /* Sum: '<S139>/Add' incorporates:
         *  DataTypeConversion: '<S128>/Data Type Conversion'
         *  DiscreteIntegrator: '<S135>/Integrator1'
         *  Gain: '<S128>/Gain1'
         *  Product: '<S128>/Multiply1'
         *  Sum: '<S135>/Subtract'
         */
        rtb_Divide_l_idx_1 = (FMS_DW.Integrator1_DSTATE_nf -
                              -FMS_PARAM.ROLL_PITCH_LIM *
                              rtb_MathFunction_p_idx_0 * (real32_T)
                              rtb_FixPtRelationalOperator_me) +
          rtb_MathFunction_f_idx_0;

        /* Saturate: '<S139>/Saturation' incorporates:
         *  Constant: '<S135>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Divide_l_idx_0 = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Divide_l_idx_0 = 0.0F;
        } else {
          rtb_Divide_l_idx_0 = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S139>/Saturation' */

        /* Product: '<S139>/Multiply7' incorporates:
         *  Constant: '<S139>/const'
         */
        rtb_Integrator1_a = 31.415926F * rtb_Divide_l_idx_0;

        /* Product: '<S139>/Multiply' */
        rtb_Add4_d = rtb_Integrator1_a * FMS_ConstB.Square_b;

        /* Signum: '<S139>/Sign' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S139>/Sign' */

        /* Sum: '<S139>/Add2' incorporates:
         *  Abs: '<S139>/Abs'
         *  Gain: '<S139>/Gain'
         *  Gain: '<S139>/Gain1'
         *  Product: '<S139>/Multiply2'
         *  Product: '<S139>/Multiply3'
         *  Sqrt: '<S139>/Sqrt'
         *  Sum: '<S139>/Add1'
         *  Sum: '<S139>/Subtract'
         */
        rtb_Divide_l_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_1) +
          rtb_Add4_d) * rtb_Add4_d) - rtb_Add4_d) * 0.5F * rtb_Saturation_n +
          rtb_MathFunction_f_idx_0;

        /* Sum: '<S139>/Add4' */
        rtb_MathFunction_p_idx_0 = (rtb_Divide_l_idx_1 - rtb_Divide_l_idx_0) +
          rtb_MathFunction_f_idx_0;

        /* Sum: '<S139>/Add3' */
        rtb_Saturation_n = rtb_Divide_l_idx_1 + rtb_Add4_d;

        /* Sum: '<S139>/Subtract1' */
        rtb_Divide_l_idx_1 -= rtb_Add4_d;

        /* Signum: '<S139>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S139>/Sign1' */

        /* Signum: '<S139>/Sign2' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S139>/Sign2' */

        /* Sum: '<S139>/Add5' incorporates:
         *  Gain: '<S139>/Gain2'
         *  Product: '<S139>/Multiply4'
         *  Sum: '<S139>/Subtract2'
         */
        rtb_Divide_l_idx_0 += (rtb_Saturation_n - rtb_Divide_l_idx_1) * 0.5F *
          rtb_MathFunction_p_idx_0;

        /* Update for DiscreteIntegrator: '<S134>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S134>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_k += 0.004F * FMS_DW.Integrator_DSTATE_a;

        /* Update for DiscreteIntegrator: '<S134>/Integrator' incorporates:
         *  Sum: '<S138>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_a += (rtb_Subtract3_od -
          rtb_MathFunction_f_idx_1) * 0.004F;

        /* Update for DiscreteIntegrator: '<S135>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S135>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_nf += 0.004F * FMS_DW.Integrator_DSTATE_b;

        /* Sum: '<S139>/Add6' */
        rtb_Saturation_n = rtb_Divide_l_idx_0 + rtb_Add4_d;

        /* Sum: '<S139>/Subtract3' */
        rtb_Subtract3_od = rtb_Divide_l_idx_0 - rtb_Add4_d;

        /* Signum: '<S139>/Sign5' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_MathFunction_p_idx_0 = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_MathFunction_p_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_p_idx_0 = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S139>/Sign5' */

        /* Signum: '<S139>/Sign3' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S139>/Sign3' */

        /* Signum: '<S139>/Sign4' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S139>/Sign4' */

        /* Signum: '<S139>/Sign6' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S139>/Sign6' */

        /* Update for DiscreteIntegrator: '<S135>/Integrator' incorporates:
         *  Gain: '<S139>/Gain3'
         *  Gain: '<S139>/Gain4'
         *  Product: '<S139>/Divide'
         *  Product: '<S139>/Multiply5'
         *  Product: '<S139>/Multiply6'
         *  Sum: '<S139>/Subtract4'
         *  Sum: '<S139>/Subtract5'
         *  Sum: '<S139>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_b += ((rtb_Divide_l_idx_0 / rtb_Add4_d -
          rtb_MathFunction_p_idx_0) * -rtb_Integrator1_a * ((rtb_Saturation_n -
          rtb_Subtract3_od) * 0.5F) - rtb_Divide_l_idx_1 * rtb_Integrator1_a) *
          0.004F;

        /* End of Outputs for SubSystem: '<S37>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S37>/Altitude' incorporates:
           *  ActionPort: '<S43>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S67>/Integrator'
           *  DiscreteIntegrator: '<S67>/Integrator1'
           *  DiscreteIntegrator: '<S68>/Integrator'
           *  DiscreteIntegrator: '<S68>/Integrator1'
           */
          FMS_DW.Integrator1_DSTATE_n = 0.0F;
          FMS_DW.Integrator_DSTATE_c = 0.0F;
          FMS_DW.Integrator1_DSTATE_i = 0.0F;
          FMS_DW.Integrator_DSTATE_g = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S37>/Altitude' */

          /* SystemReset for IfAction SubSystem: '<S37>/Altitude' incorporates:
           *  ActionPort: '<S43>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S54>/Motion Status'
           *  Chart: '<S74>/Motion State'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_b);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_b);

          /* End of SystemReset for SubSystem: '<S37>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Altitude' incorporates:
         *  ActionPort: '<S43>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S65>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Divide_l_idx_0 = 0.0F;
        } else {
          rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S65>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S65>/Gain' */
        rtb_Saturation_n = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Divide_l_idx_0;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S66>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Divide_l_idx_0 = 0.0F;
        } else {
          rtb_Divide_l_idx_0 = FMS_U.Pilot_Cmd.stick_pitch -
            (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S66>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Gain: '<S66>/Gain' */
        rtb_MathFunction_p_idx_0 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_Divide_l_idx_0;

        /* Sum: '<S69>/Sum of Elements' incorporates:
         *  Math: '<S69>/Square'
         *  SignalConversion: '<S69>/TmpSignal ConversionAtSquareInport1'
         *  Sum: '<S70>/Sum of Elements'
         *  Switch: '<S51>/Switch'
         */
        rtb_Divide_l_idx_0 = rtb_Saturation_n * rtb_Saturation_n +
          rtb_MathFunction_p_idx_0 * rtb_MathFunction_p_idx_0;

        /* Switch: '<S51>/Switch' incorporates:
         *  Constant: '<S64>/Constant'
         *  Product: '<S70>/Divide'
         *  RelationalOperator: '<S64>/Compare'
         *  Sqrt: '<S69>/Sqrt'
         *  Sum: '<S69>/Sum of Elements'
         */
        if (sqrtf(rtb_Divide_l_idx_0) > 1.0F) {
          /* Math: '<S70>/Math Function1'
           *
           * About '<S70>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_l_idx_0 < 0.0F) {
            rtb_Subtract3_od = -sqrtf(fabsf(rtb_Divide_l_idx_0));
          } else {
            rtb_Subtract3_od = sqrtf(rtb_Divide_l_idx_0);
          }

          /* End of Math: '<S70>/Math Function1' */

          /* Switch: '<S70>/Switch' incorporates:
           *  Constant: '<S70>/Constant'
           *  Product: '<S70>/Product'
           */
          if (rtb_Subtract3_od > 0.0F) {
            rtb_MatrixConcatenate3[0] = rtb_Saturation_n;
            rtb_MatrixConcatenate3[1] = rtb_MathFunction_p_idx_0;
            rtb_MatrixConcatenate3[2] = rtb_Subtract3_od;
          } else {
            rtb_MatrixConcatenate3[0] = 0.0F;
            rtb_MatrixConcatenate3[1] = 0.0F;
            rtb_MatrixConcatenate3[2] = 1.0F;
          }

          /* End of Switch: '<S70>/Switch' */
          rtb_Saturation_n = rtb_MatrixConcatenate3[0] / rtb_MatrixConcatenate3
            [2];
          rtb_MathFunction_p_idx_0 = rtb_MatrixConcatenate3[1] /
            rtb_MatrixConcatenate3[2];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Logic: '<S51>/Logical Operator' incorporates:
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Product: '<S71>/Multiply1' incorporates:
         *  Constant: '<S71>/const1'
         *  DiscreteIntegrator: '<S67>/Integrator'
         */
        rtb_Add4_d = FMS_DW.Integrator_DSTATE_c * 0.04F;

        /* Sum: '<S71>/Add' incorporates:
         *  DataTypeConversion: '<S51>/Data Type Conversion'
         *  DiscreteIntegrator: '<S67>/Integrator1'
         *  Gain: '<S51>/Gain'
         *  Product: '<S51>/Multiply'
         *  Sum: '<S67>/Subtract'
         */
        rtb_Integrator1_a = (FMS_DW.Integrator1_DSTATE_n -
                             FMS_PARAM.ROLL_PITCH_LIM * rtb_Saturation_n *
                             (real32_T)rtb_FixPtRelationalOperator_me) +
          rtb_Add4_d;

        /* Saturate: '<S71>/Saturation' incorporates:
         *  Constant: '<S67>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Divide_l_idx_0 = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Divide_l_idx_0 = 0.0F;
        } else {
          rtb_Divide_l_idx_0 = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S71>/Saturation' */

        /* Product: '<S71>/Multiply7' incorporates:
         *  Constant: '<S71>/const'
         */
        rtb_Divide_l_idx_1 = 31.415926F * rtb_Divide_l_idx_0;

        /* Product: '<S71>/Multiply' */
        rtb_Divide_l_idx_0 = rtb_Divide_l_idx_1 * FMS_ConstB.Square_m;

        /* Signum: '<S71>/Sign' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Integrator1_a > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Integrator1_a;
        }

        /* End of Signum: '<S71>/Sign' */

        /* Sum: '<S71>/Add2' incorporates:
         *  Abs: '<S71>/Abs'
         *  Gain: '<S71>/Gain'
         *  Gain: '<S71>/Gain1'
         *  Product: '<S71>/Multiply2'
         *  Product: '<S71>/Multiply3'
         *  Sqrt: '<S71>/Sqrt'
         *  Sum: '<S71>/Add1'
         *  Sum: '<S71>/Subtract'
         */
        rtb_MathFunction_f_idx_0 = (sqrtf((8.0F * fabsf(rtb_Integrator1_a) +
          rtb_Divide_l_idx_0) * rtb_Divide_l_idx_0) - rtb_Divide_l_idx_0) * 0.5F
          * rtb_Saturation_n + rtb_Add4_d;

        /* Sum: '<S71>/Add4' */
        rtb_Subtract3_od = (rtb_Integrator1_a - rtb_MathFunction_f_idx_0) +
          rtb_Add4_d;

        /* Sum: '<S71>/Add3' */
        rtb_Saturation_n = rtb_Integrator1_a + rtb_Divide_l_idx_0;

        /* Sum: '<S71>/Subtract1' */
        rtb_Integrator1_a -= rtb_Divide_l_idx_0;

        /* Signum: '<S71>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S71>/Sign1' */

        /* Signum: '<S71>/Sign2' */
        if (rtb_Integrator1_a < 0.0F) {
          rtb_Integrator1_a = -1.0F;
        } else {
          if (rtb_Integrator1_a > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          }
        }

        /* End of Signum: '<S71>/Sign2' */

        /* Sum: '<S71>/Add5' incorporates:
         *  Gain: '<S71>/Gain2'
         *  Product: '<S71>/Multiply4'
         *  Sum: '<S71>/Subtract2'
         */
        rtb_MathFunction_f_idx_0 += (rtb_Saturation_n - rtb_Integrator1_a) *
          0.5F * rtb_Subtract3_od;

        /* Sum: '<S71>/Subtract3' */
        rtb_Saturation_n = rtb_MathFunction_f_idx_0 - rtb_Divide_l_idx_0;

        /* Sum: '<S71>/Add6' */
        rtb_Subtract3_od = rtb_MathFunction_f_idx_0 + rtb_Divide_l_idx_0;

        /* Signum: '<S71>/Sign5' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_Add4_d = -1.0F;
        } else if (rtb_MathFunction_f_idx_0 > 0.0F) {
          rtb_Add4_d = 1.0F;
        } else {
          rtb_Add4_d = rtb_MathFunction_f_idx_0;
        }

        /* End of Signum: '<S71>/Sign5' */

        /* Signum: '<S71>/Sign3' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S71>/Sign3' */

        /* Signum: '<S71>/Sign4' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S71>/Sign4' */

        /* Product: '<S71>/Multiply5' incorporates:
         *  Gain: '<S71>/Gain3'
         *  Gain: '<S71>/Gain4'
         *  Product: '<S71>/Divide'
         *  Sum: '<S71>/Subtract4'
         *  Sum: '<S71>/Subtract5'
         */
        rtb_Subtract3_od = (rtb_MathFunction_f_idx_0 / rtb_Divide_l_idx_0 -
                            rtb_Add4_d) * -rtb_Divide_l_idx_1 *
          ((rtb_Subtract3_od - rtb_Saturation_n) * 0.5F);

        /* Signum: '<S71>/Sign6' */
        if (rtb_MathFunction_f_idx_0 < 0.0F) {
          rtb_MathFunction_f_idx_0 = -1.0F;
        } else {
          if (rtb_MathFunction_f_idx_0 > 0.0F) {
            rtb_MathFunction_f_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S71>/Sign6' */

        /* Product: '<S71>/Multiply6' */
        rtb_MathFunction_f_idx_1 = rtb_MathFunction_f_idx_0 * rtb_Divide_l_idx_1;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S54>/Motion Status' incorporates:
         *  Abs: '<S54>/Abs'
         *  Abs: '<S54>/Abs1'
         *  Constant: '<S62>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S62>/Compare'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S53>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S53>/Hold Control' incorporates:
             *  ActionPort: '<S55>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S53>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S53>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S53>/Hold Control' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_lf,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S53>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S53>/Move Control' incorporates:
           *  ActionPort: '<S56>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_lf);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S53>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S53>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S50>/Switch' incorporates:
         *  Constant: '<S50>/Constant'
         *  Saturate: '<S53>/Saturation1'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_B.Compare) {
          rtb_MathFunction_f_idx_0 = 0.5F;
        } else if (FMS_B.Merge_lf > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S53>/Saturation1' */
          rtb_MathFunction_f_idx_0 = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_lf < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S53>/Saturation1' */
          rtb_MathFunction_f_idx_0 = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S53>/Saturation1' */
          rtb_MathFunction_f_idx_0 = FMS_B.Merge_lf;
        }

        /* End of Switch: '<S50>/Switch' */

        /* Chart: '<S74>/Motion State' incorporates:
         *  Abs: '<S74>/Abs'
         *  Abs: '<S74>/Abs1'
         *  Constant: '<S83>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S83>/Compare'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_b);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S73>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S73>/Hold Control' incorporates:
             *  ActionPort: '<S75>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S73>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_hb);

            /* End of SystemReset for SubSystem: '<S73>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S73>/Hold Control' incorporates:
           *  ActionPort: '<S75>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                            &FMS_DW.HoldControl_hb);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S73>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_mn != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S73>/Move Control' incorporates:
             *  ActionPort: '<S76>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S73>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_o);

            /* End of SystemReset for SubSystem: '<S73>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S73>/Move Control' incorporates:
           *  ActionPort: '<S76>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                            &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S73>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S73>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S43>/Bus Assignment'
         *  Constant: '<S43>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S43>/Bus Assignment' incorporates:
         *  DiscreteIntegrator: '<S67>/Integrator1'
         *  DiscreteIntegrator: '<S68>/Integrator1'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
        FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_n;
        FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_i;

        /* Saturate: '<S73>/Saturation' */
        if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_h;
        }

        /* End of Saturate: '<S73>/Saturation' */

        /* BusAssignment: '<S43>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = rtb_MathFunction_f_idx_0;

        /* Product: '<S72>/Multiply1' incorporates:
         *  Constant: '<S72>/const1'
         *  DiscreteIntegrator: '<S68>/Integrator'
         */
        rtb_MathFunction_f_idx_0 = FMS_DW.Integrator_DSTATE_g * 0.04F;

        /* Sum: '<S72>/Add' incorporates:
         *  DataTypeConversion: '<S51>/Data Type Conversion'
         *  DiscreteIntegrator: '<S68>/Integrator1'
         *  Gain: '<S51>/Gain1'
         *  Product: '<S51>/Multiply1'
         *  Sum: '<S68>/Subtract'
         */
        rtb_Divide_l_idx_1 = (FMS_DW.Integrator1_DSTATE_i -
                              -FMS_PARAM.ROLL_PITCH_LIM *
                              rtb_MathFunction_p_idx_0 * (real32_T)
                              rtb_FixPtRelationalOperator_me) +
          rtb_MathFunction_f_idx_0;

        /* Saturate: '<S72>/Saturation' incorporates:
         *  Constant: '<S68>/Constant'
         */
        if (FMS_PARAM.STICK_SENS > 1.0F) {
          rtb_Divide_l_idx_0 = 1.0F;
        } else if (FMS_PARAM.STICK_SENS < 0.0F) {
          rtb_Divide_l_idx_0 = 0.0F;
        } else {
          rtb_Divide_l_idx_0 = FMS_PARAM.STICK_SENS;
        }

        /* End of Saturate: '<S72>/Saturation' */

        /* Product: '<S72>/Multiply7' incorporates:
         *  Constant: '<S72>/const'
         */
        rtb_Integrator1_a = 31.415926F * rtb_Divide_l_idx_0;

        /* Product: '<S72>/Multiply' */
        rtb_Add4_d = rtb_Integrator1_a * FMS_ConstB.Square_i;

        /* Signum: '<S72>/Sign' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else if (rtb_Divide_l_idx_1 > 0.0F) {
          rtb_Saturation_n = 1.0F;
        } else {
          rtb_Saturation_n = rtb_Divide_l_idx_1;
        }

        /* End of Signum: '<S72>/Sign' */

        /* Sum: '<S72>/Add2' incorporates:
         *  Abs: '<S72>/Abs'
         *  Gain: '<S72>/Gain'
         *  Gain: '<S72>/Gain1'
         *  Product: '<S72>/Multiply2'
         *  Product: '<S72>/Multiply3'
         *  Sqrt: '<S72>/Sqrt'
         *  Sum: '<S72>/Add1'
         *  Sum: '<S72>/Subtract'
         */
        rtb_Divide_l_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_l_idx_1) +
          rtb_Add4_d) * rtb_Add4_d) - rtb_Add4_d) * 0.5F * rtb_Saturation_n +
          rtb_MathFunction_f_idx_0;

        /* Sum: '<S72>/Add4' */
        rtb_MathFunction_p_idx_0 = (rtb_Divide_l_idx_1 - rtb_Divide_l_idx_0) +
          rtb_MathFunction_f_idx_0;

        /* Sum: '<S72>/Add3' */
        rtb_Saturation_n = rtb_Divide_l_idx_1 + rtb_Add4_d;

        /* Sum: '<S72>/Subtract1' */
        rtb_Divide_l_idx_1 -= rtb_Add4_d;

        /* Signum: '<S72>/Sign1' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S72>/Sign1' */

        /* Signum: '<S72>/Sign2' */
        if (rtb_Divide_l_idx_1 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_l_idx_1 > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S72>/Sign2' */

        /* Sum: '<S72>/Add5' incorporates:
         *  Gain: '<S72>/Gain2'
         *  Product: '<S72>/Multiply4'
         *  Sum: '<S72>/Subtract2'
         */
        rtb_Divide_l_idx_0 += (rtb_Saturation_n - rtb_Divide_l_idx_1) * 0.5F *
          rtb_MathFunction_p_idx_0;

        /* Update for DiscreteIntegrator: '<S67>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S67>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_c;

        /* Update for DiscreteIntegrator: '<S67>/Integrator' incorporates:
         *  Sum: '<S71>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_c += (rtb_Subtract3_od -
          rtb_MathFunction_f_idx_1) * 0.004F;

        /* Update for DiscreteIntegrator: '<S68>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S68>/Integrator'
         */
        FMS_DW.Integrator1_DSTATE_i += 0.004F * FMS_DW.Integrator_DSTATE_g;

        /* Sum: '<S72>/Add6' */
        rtb_Saturation_n = rtb_Divide_l_idx_0 + rtb_Add4_d;

        /* Sum: '<S72>/Subtract3' */
        rtb_Subtract3_od = rtb_Divide_l_idx_0 - rtb_Add4_d;

        /* Signum: '<S72>/Sign5' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_MathFunction_p_idx_0 = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_MathFunction_p_idx_0 = 1.0F;
        } else {
          rtb_MathFunction_p_idx_0 = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S72>/Sign5' */

        /* Signum: '<S72>/Sign3' */
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = -1.0F;
        } else {
          if (rtb_Saturation_n > 0.0F) {
            rtb_Saturation_n = 1.0F;
          }
        }

        /* End of Signum: '<S72>/Sign3' */

        /* Signum: '<S72>/Sign4' */
        if (rtb_Subtract3_od < 0.0F) {
          rtb_Subtract3_od = -1.0F;
        } else {
          if (rtb_Subtract3_od > 0.0F) {
            rtb_Subtract3_od = 1.0F;
          }
        }

        /* End of Signum: '<S72>/Sign4' */

        /* Signum: '<S72>/Sign6' */
        if (rtb_Divide_l_idx_0 < 0.0F) {
          rtb_Divide_l_idx_1 = -1.0F;
        } else if (rtb_Divide_l_idx_0 > 0.0F) {
          rtb_Divide_l_idx_1 = 1.0F;
        } else {
          rtb_Divide_l_idx_1 = rtb_Divide_l_idx_0;
        }

        /* End of Signum: '<S72>/Sign6' */

        /* Update for DiscreteIntegrator: '<S68>/Integrator' incorporates:
         *  Gain: '<S72>/Gain3'
         *  Gain: '<S72>/Gain4'
         *  Product: '<S72>/Divide'
         *  Product: '<S72>/Multiply5'
         *  Product: '<S72>/Multiply6'
         *  Sum: '<S72>/Subtract4'
         *  Sum: '<S72>/Subtract5'
         *  Sum: '<S72>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE_g += ((rtb_Divide_l_idx_0 / rtb_Add4_d -
          rtb_MathFunction_p_idx_0) * -rtb_Integrator1_a * ((rtb_Saturation_n -
          rtb_Subtract3_od) * 0.5F) - rtb_Divide_l_idx_1 * rtb_Integrator1_a) *
          0.004F;

        /* End of Outputs for SubSystem: '<S37>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S37>/Position' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S100>/Motion State'
           *  Chart: '<S112>/Motion State'
           *  Chart: '<S89>/Motion Status'
           */
          FMS_MotionStatus_n_Reset(&FMS_DW.sf_MotionStatus_h);
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_l);
          FMS_MotionState_jr_Reset(&FMS_DW.sf_MotionState_a);

          /* End of SystemReset for SubSystem: '<S37>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Position' incorporates:
         *  ActionPort: '<S44>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S89>/Motion Status' incorporates:
         *  Abs: '<S89>/Abs'
         *  Abs: '<S89>/Abs1'
         *  Constant: '<S97>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S97>/Compare'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_MotionStatus_b(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_c, &FMS_DW.sf_MotionStatus_h);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S88>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S88>/Hold Control' incorporates:
             *  ActionPort: '<S90>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S88>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_c);

            /* End of SystemReset for SubSystem: '<S88>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S88>/Hold Control' incorporates:
           *  ActionPort: '<S90>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_ld,
                          &FMS_DW.HoldControl_c);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S88>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S88>/Move Control' incorporates:
           *  ActionPort: '<S91>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_ld);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S88>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S88>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S100>/Motion State' incorporates:
         *  Abs: '<S100>/Abs'
         *  Abs: '<S100>/Abs1'
         *  Constant: '<S109>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S109>/Compare'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_l);

        /* Chart: '<S112>/Motion State' incorporates:
         *  Abs: '<S112>/Abs1'
         *  Abs: '<S112>/Abs2'
         *  Constant: '<S125>/Constant'
         *  Constant: '<S126>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Logic: '<S112>/Logical Operator'
         *  Math: '<S112>/Square'
         *  Math: '<S112>/Square1'
         *  RelationalOperator: '<S125>/Compare'
         *  RelationalOperator: '<S126>/Compare'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sqrt: '<S112>/Sqrt'
         *  Sum: '<S112>/Add'
         */
        FMS_MotionState_a((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ) || (fabsf
          (FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ), sqrtf
                          (FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                           FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_ki,
                          &FMS_DW.sf_MotionState_a);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S111>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_lm;
        FMS_DW.SwitchCase_ActiveSubsystem_lm = -1;
        switch (rtb_state_ki) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_lm = 0;
          break;

         case MotionState_Brake:
         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_lm = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_lm) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_lm != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S111>/Hold Control' incorporates:
             *  ActionPort: '<S113>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S111>/Switch Case' */
            FMS_HoldControl_g_Reset(&FMS_DW.HoldControl_at);

            /* End of SystemReset for SubSystem: '<S111>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S111>/Hold Control' incorporates:
           *  ActionPort: '<S113>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_a(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge_p,
                            &FMS_ConstB.HoldControl_at, &FMS_DW.HoldControl_at);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S111>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_lm != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S111>/Move Control' incorporates:
             *  ActionPort: '<S114>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S111>/Switch Case' */
            FMS_MoveControl_lh_Reset(&FMS_DW.MoveControl_k1);

            /* End of SystemReset for SubSystem: '<S111>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S111>/Move Control' incorporates:
           *  ActionPort: '<S114>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                            &FMS_ConstB.MoveControl_k1, &FMS_DW.MoveControl_k1);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S111>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S111>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S85>/Switch' incorporates:
         *  Constant: '<S85>/Constant'
         *  Saturate: '<S88>/Saturation1'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_B.Compare) {
          rtb_Saturation_n = 0.5F;
        } else if (FMS_B.Merge_ld > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S88>/Saturation1' */
          rtb_Saturation_n = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_ld < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S88>/Saturation1' */
          rtb_Saturation_n = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S88>/Saturation1' */
          rtb_Saturation_n = FMS_B.Merge_ld;
        }

        /* End of Switch: '<S85>/Switch' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S99>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
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
            /* SystemReset for IfAction SubSystem: '<S99>/Hold Control' incorporates:
             *  ActionPort: '<S101>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S99>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_h2);

            /* End of SystemReset for SubSystem: '<S99>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S99>/Hold Control' incorporates:
           *  ActionPort: '<S101>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_e,
                            &FMS_DW.HoldControl_h2);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S99>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_bu != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S99>/Move Control' incorporates:
             *  ActionPort: '<S102>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S99>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_m1);

            /* End of SystemReset for SubSystem: '<S99>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S99>/Move Control' incorporates:
           *  ActionPort: '<S102>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_e,
                            &FMS_ConstB.MoveControl_m1, &FMS_DW.MoveControl_m1);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S99>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S99>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S44>/Bus Assignment'
         *  Constant: '<S44>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S44>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;

        /* Saturate: '<S99>/Saturation' */
        if (FMS_B.Merge_e > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_e < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_e;
        }

        /* End of Saturate: '<S99>/Saturation' */

        /* Saturate: '<S111>/Saturation1' */
        if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
        }

        if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
        }

        /* End of Saturate: '<S111>/Saturation1' */

        /* BusAssignment: '<S44>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = rtb_Saturation_n;

        /* End of Outputs for SubSystem: '<S37>/Position' */
        break;

       case 4:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S37>/Terrain' incorporates:
           *  ActionPort: '<S46>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
           *  Chart: '<S156>/Motion Status'
           *  Chart: '<S170>/Motion State'
           *  Chart: '<S182>/Motion State'
           */
          FMS_MotionState_jr_Reset(&FMS_DW.sf_MotionState_ej);
          FMS_DW.temporalCounter_i1_j = 0U;
          FMS_DW.is_active_c12_FMS = 0U;
          FMS_DW.is_c12_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
          FMS_MotionState_j_Reset(&FMS_DW.sf_MotionState_k);

          /* End of SystemReset for SubSystem: '<S37>/Terrain' */
        }

        /* Outputs for IfAction SubSystem: '<S37>/Terrain' incorporates:
         *  ActionPort: '<S46>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Chart: '<S182>/Motion State' incorporates:
         *  Abs: '<S182>/Abs1'
         *  Abs: '<S182>/Abs2'
         *  Constant: '<S195>/Constant'
         *  Constant: '<S196>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Logic: '<S182>/Logical Operator'
         *  Math: '<S182>/Square'
         *  Math: '<S182>/Square1'
         *  RelationalOperator: '<S195>/Compare'
         *  RelationalOperator: '<S196>/Compare'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         *  Sqrt: '<S182>/Sqrt'
         *  Sum: '<S182>/Add'
         */
        FMS_MotionState_a((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ) || (fabsf
          (FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ), sqrtf
                          (FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                           FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_c,
                          &FMS_DW.sf_MotionState_ej);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S181>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_n;
        FMS_DW.SwitchCase_ActiveSubsystem_n = -1;
        switch (rtb_state_c) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_n = 0;
          break;

         case MotionState_Brake:
         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_n = 1;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_n) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_n != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S181>/Hold Control' incorporates:
             *  ActionPort: '<S183>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S181>/Switch Case' */
            FMS_HoldControl_g_Reset(&FMS_DW.HoldControl_nn);

            /* End of SystemReset for SubSystem: '<S181>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S181>/Hold Control' incorporates:
           *  ActionPort: '<S183>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_a(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_U.INS_Out.psi, FMS_B.Merge,
                            &FMS_ConstB.HoldControl_nn, &FMS_DW.HoldControl_nn);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S181>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_n != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S181>/Move Control' incorporates:
             *  ActionPort: '<S184>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S181>/Switch Case' */
            FMS_MoveControl_lh_Reset(&FMS_DW.MoveControl_mz);

            /* End of SystemReset for SubSystem: '<S181>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S181>/Move Control' incorporates:
           *  ActionPort: '<S184>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                            FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge,
                            &FMS_ConstB.MoveControl_mz, &FMS_DW.MoveControl_mz);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S181>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S181>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* RelationalOperator: '<S167>/Compare' incorporates:
         *  Abs: '<S156>/Abs1'
         *  Constant: '<S167>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtb_FixPtRelationalOperator_me = (fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
          FMS_PARAM.THROTTLE_DZ);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Chart: '<S156>/Motion Status' incorporates:
         *  Abs: '<S156>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_DW.temporalCounter_i1_j < 511U) {
          FMS_DW.temporalCounter_i1_j++;
        }

        if (FMS_DW.is_active_c12_FMS == 0U) {
          FMS_DW.is_active_c12_FMS = 1U;
          FMS_DW.is_c12_FMS = FMS_IN_Move_n;
          rtb_state_ki = MotionState_Move;
        } else {
          switch (FMS_DW.is_c12_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_ki = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.vd) <= 0.15) ||
                (FMS_DW.temporalCounter_i1_j >= 375U)) {
              FMS_DW.is_c12_FMS = FMS_IN_Hold_d;
              rtb_state_ki = MotionState_Hold;
            } else {
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c12_FMS = FMS_IN_Move_n;
                rtb_state_ki = MotionState_Move;
              }
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            break;

           case FMS_IN_Hold_d:
            rtb_state_ki = MotionState_Hold;
            if (rtb_FixPtRelationalOperator_me) {
              FMS_DW.is_c12_FMS = FMS_IN_Move_n;
              rtb_state_ki = MotionState_Move;
            } else {
              if (rtb_state_c == MotionState_Move) {
                FMS_DW.is_c12_FMS = FMS_IN_TerrainTrack;
                rtb_state_ki = MotionState_TerrainTrack;
              }
            }
            break;

           case FMS_IN_Move_n:
            rtb_state_ki = MotionState_Move;
            if (!rtb_FixPtRelationalOperator_me) {
              FMS_DW.is_c12_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_j = 0U;
              rtb_state_ki = MotionState_Brake;
            }
            break;

           default:
            rtb_state_ki = MotionState_TerrainTrack;
            if (rtb_FixPtRelationalOperator_me) {
              FMS_DW.is_c12_FMS = FMS_IN_Move_n;
              rtb_state_ki = MotionState_Move;
            } else {
              if (rtb_state_c == MotionState_Hold) {
                FMS_DW.is_c12_FMS = FMS_IN_Hold_d;
                rtb_state_ki = MotionState_Hold;
              }
            }
            break;
          }
        }

        /* End of Chart: '<S156>/Motion Status' */

        /* SwitchCase: '<S155>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_fi;
        FMS_DW.SwitchCase_ActiveSubsystem_fi = -1;
        switch (rtb_state_ki) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_fi = 0;
          break;

         case MotionState_Brake:
         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_fi = 1;
          break;

         case MotionState_TerrainTrack:
          FMS_DW.SwitchCase_ActiveSubsystem_fi = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_fi) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fi != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S155>/Hold Control' incorporates:
             *  ActionPort: '<S157>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S155>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_l);

            /* End of SystemReset for SubSystem: '<S155>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S155>/Hold Control' incorporates:
           *  ActionPort: '<S157>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_a,
                          &FMS_DW.HoldControl_l);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S155>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S155>/Move Control' incorporates:
           *  ActionPort: '<S158>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_l(FMS_U.Pilot_Cmd.stick_throttle, FMS_U.INS_Out.h_AGL,
                            FMS_U.INS_Out.flag, &FMS_B.Merge_a);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S155>/Move Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_fi != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S155>/Terrain Control' incorporates:
             *  ActionPort: '<S159>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S155>/Switch Case' incorporates:
             *  Delay: '<S159>/Delay'
             *  DiscreteIntegrator: '<S165>/Integrator'
             *  DiscreteIntegrator: '<S165>/Integrator1'
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.Integrator1_DSTATE = 0.0F;
            FMS_DW.Integrator_DSTATE = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S155>/Terrain Control' */
          }

          /* Outputs for IfAction SubSystem: '<S155>/Terrain Control' incorporates:
           *  ActionPort: '<S159>/Action Port'
           */
          /* Delay: '<S159>/Delay' incorporates:
           *  Inport: '<Root>/Terrain_Info'
           *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE = FMS_U.Terrain_Info.range_m;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Product: '<S166>/Multiply1' incorporates:
           *  Constant: '<S166>/const1'
           *  DiscreteIntegrator: '<S165>/Integrator'
           */
          rtb_Saturation_n = FMS_DW.Integrator_DSTATE * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S166>/Add' incorporates:
           *  Delay: '<S159>/Delay'
           *  DiscreteIntegrator: '<S165>/Integrator1'
           *  Gain: '<S159>/Gain2'
           *  Inport: '<Root>/Terrain_Info'
           *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
           *  Sum: '<S159>/Sum'
           *  Sum: '<S165>/Subtract'
           */
          rtb_Subtract3_od = (FMS_DW.Integrator1_DSTATE -
                              (FMS_U.Terrain_Info.range_m - FMS_DW.Delay_DSTATE)
                              * FMS_PARAM.Z_P) + rtb_Saturation_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S166>/Saturation' incorporates:
           *  Constant: '<S165>/Constant'
           */
          if (FMS_PARAM.STICK_SENS > 1.0F) {
            rtb_Divide_l_idx_0 = 1.0F;
          } else if (FMS_PARAM.STICK_SENS < 0.0F) {
            rtb_Divide_l_idx_0 = 0.0F;
          } else {
            rtb_Divide_l_idx_0 = FMS_PARAM.STICK_SENS;
          }

          /* End of Saturate: '<S166>/Saturation' */

          /* Product: '<S166>/Multiply7' incorporates:
           *  Constant: '<S166>/const'
           */
          rtb_Divide_l_idx_0 *= 980.6F;

          /* Product: '<S166>/Multiply' */
          rtb_Add4_d = rtb_Divide_l_idx_0 * FMS_ConstB.Square;

          /* Signum: '<S166>/Sign' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Integrator1_a = -1.0F;
          } else if (rtb_Subtract3_od > 0.0F) {
            rtb_Integrator1_a = 1.0F;
          } else {
            rtb_Integrator1_a = rtb_Subtract3_od;
          }

          /* End of Signum: '<S166>/Sign' */

          /* Sum: '<S166>/Add2' incorporates:
           *  Abs: '<S166>/Abs'
           *  Gain: '<S166>/Gain'
           *  Gain: '<S166>/Gain1'
           *  Product: '<S166>/Multiply2'
           *  Product: '<S166>/Multiply3'
           *  Sqrt: '<S166>/Sqrt'
           *  Sum: '<S166>/Add1'
           *  Sum: '<S166>/Subtract'
           */
          rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Subtract3_od) +
            rtb_Add4_d) * rtb_Add4_d) - rtb_Add4_d) * 0.5F * rtb_Integrator1_a +
            rtb_Saturation_n;

          /* Sum: '<S166>/Add4' */
          rtb_MathFunction_p_idx_0 = (rtb_Subtract3_od - rtb_Integrator1_a) +
            rtb_Saturation_n;

          /* Sum: '<S166>/Add3' */
          rtb_Saturation_n = rtb_Subtract3_od + rtb_Add4_d;

          /* Sum: '<S166>/Subtract1' */
          rtb_Subtract3_od -= rtb_Add4_d;

          /* Signum: '<S166>/Sign1' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* End of Signum: '<S166>/Sign1' */

          /* Signum: '<S166>/Sign2' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else {
            if (rtb_Subtract3_od > 0.0F) {
              rtb_Subtract3_od = 1.0F;
            }
          }

          /* End of Signum: '<S166>/Sign2' */

          /* Sum: '<S166>/Add5' incorporates:
           *  Gain: '<S166>/Gain2'
           *  Product: '<S166>/Multiply4'
           *  Sum: '<S166>/Subtract2'
           */
          rtb_Integrator1_a += (rtb_Saturation_n - rtb_Subtract3_od) * 0.5F *
            rtb_MathFunction_p_idx_0;

          /* SignalConversion: '<S159>/OutportBufferForw_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S165>/Integrator1'
           */
          FMS_B.Merge_a = FMS_DW.Integrator1_DSTATE;

          /* Update for Delay: '<S159>/Delay' */
          FMS_DW.icLoad = 0U;

          /* Update for DiscreteIntegrator: '<S165>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S165>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

          /* Sum: '<S166>/Add6' */
          rtb_Saturation_n = rtb_Integrator1_a + rtb_Add4_d;

          /* Sum: '<S166>/Subtract3' */
          rtb_Subtract3_od = rtb_Integrator1_a - rtb_Add4_d;

          /* Signum: '<S166>/Sign5' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_MathFunction_p_idx_0 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_MathFunction_p_idx_0 = 1.0F;
          } else {
            rtb_MathFunction_p_idx_0 = rtb_Integrator1_a;
          }

          /* End of Signum: '<S166>/Sign5' */

          /* Signum: '<S166>/Sign3' */
          if (rtb_Saturation_n < 0.0F) {
            rtb_Saturation_n = -1.0F;
          } else {
            if (rtb_Saturation_n > 0.0F) {
              rtb_Saturation_n = 1.0F;
            }
          }

          /* End of Signum: '<S166>/Sign3' */

          /* Signum: '<S166>/Sign4' */
          if (rtb_Subtract3_od < 0.0F) {
            rtb_Subtract3_od = -1.0F;
          } else {
            if (rtb_Subtract3_od > 0.0F) {
              rtb_Subtract3_od = 1.0F;
            }
          }

          /* End of Signum: '<S166>/Sign4' */

          /* Signum: '<S166>/Sign6' */
          if (rtb_Integrator1_a < 0.0F) {
            rtb_Divide_l_idx_1 = -1.0F;
          } else if (rtb_Integrator1_a > 0.0F) {
            rtb_Divide_l_idx_1 = 1.0F;
          } else {
            rtb_Divide_l_idx_1 = rtb_Integrator1_a;
          }

          /* End of Signum: '<S166>/Sign6' */

          /* Update for DiscreteIntegrator: '<S165>/Integrator' incorporates:
           *  Gain: '<S166>/Gain3'
           *  Gain: '<S166>/Gain4'
           *  Product: '<S166>/Divide'
           *  Product: '<S166>/Multiply5'
           *  Product: '<S166>/Multiply6'
           *  Sum: '<S166>/Subtract4'
           *  Sum: '<S166>/Subtract5'
           *  Sum: '<S166>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE += ((rtb_Integrator1_a / rtb_Add4_d -
            rtb_MathFunction_p_idx_0) * -rtb_Divide_l_idx_0 * ((rtb_Saturation_n
            - rtb_Subtract3_od) * 0.5F) - rtb_Divide_l_idx_1 *
            rtb_Divide_l_idx_0) * 0.004F;

          /* End of Outputs for SubSystem: '<S155>/Terrain Control' */
          break;
        }

        /* End of SwitchCase: '<S155>/Switch Case' */

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Switch: '<S152>/Switch' incorporates:
         *  Constant: '<S152>/Constant'
         *  Saturate: '<S155>/Saturation1'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        if (FMS_B.Compare) {
          rtb_Saturation_n = 0.5F;
        } else if (FMS_B.Merge_a > FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S155>/Saturation1' */
          rtb_Saturation_n = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_a < -FMS_PARAM.VEL_Z_LIM) {
          /* Saturate: '<S155>/Saturation1' */
          rtb_Saturation_n = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* Saturate: '<S155>/Saturation1' */
          rtb_Saturation_n = FMS_B.Merge_a;
        }

        /* End of Switch: '<S152>/Switch' */

        /* Chart: '<S170>/Motion State' incorporates:
         *  Abs: '<S170>/Abs'
         *  Abs: '<S170>/Abs1'
         *  Constant: '<S179>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S179>/Compare'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        FMS_MotionState_e(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                          fabsf(FMS_U.INS_Out.r), &rtb_state_c,
                          &FMS_DW.sf_MotionState_k);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* SwitchCase: '<S169>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S32>/BusConversion_InsertedFor_FMS_In_at_inport_0'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
        switch (rtb_state_c) {
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
            /* SystemReset for IfAction SubSystem: '<S169>/Hold Control' incorporates:
             *  ActionPort: '<S171>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S169>/Switch Case' */
            FMS_HoldControl_kp_Reset(&FMS_DW.HoldControl_ha);

            /* End of SystemReset for SubSystem: '<S169>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S169>/Hold Control' incorporates:
           *  ActionPort: '<S171>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_HoldControl_k(FMS_U.INS_Out.psi, &FMS_B.Merge_l,
                            &FMS_DW.HoldControl_ha);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S169>/Hold Control' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S169>/Move Control' incorporates:
             *  ActionPort: '<S172>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S169>/Switch Case' */
            FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_nm);

            /* End of SystemReset for SubSystem: '<S169>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S169>/Move Control' incorporates:
           *  ActionPort: '<S172>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_MoveControl_b(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_l,
                            &FMS_ConstB.MoveControl_nm, &FMS_DW.MoveControl_nm);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S169>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S169>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S46>/Bus Assignment'
         *  Constant: '<S46>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S46>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_a;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

        /* Saturate: '<S169>/Saturation' */
        if (FMS_B.Merge_l > FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S46>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.YAW_RATE_LIM) {
          /* BusAssignment: '<S46>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
        } else {
          /* BusAssignment: '<S46>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S169>/Saturation' */

        /* Saturate: '<S181>/Saturation1' */
        if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S46>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S46>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S46>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
        }

        if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S46>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
        } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
          /* BusAssignment: '<S46>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
        } else {
          /* BusAssignment: '<S46>/Bus Assignment' incorporates:
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
        }

        /* End of Saturate: '<S181>/Saturation1' */

        /* BusAssignment: '<S46>/Bus Assignment' incorporates:
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = rtb_Saturation_n;

        /* End of Outputs for SubSystem: '<S37>/Terrain' */
        break;

       case 5:
        /* Outputs for IfAction SubSystem: '<S37>/Unknown' incorporates:
         *  ActionPort: '<S47>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_i);

        /* End of Outputs for SubSystem: '<S37>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S37>/Switch Case' */
      /* End of Outputs for SubSystem: '<S33>/Assist' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S33>/Manual' incorporates:
       *  ActionPort: '<S39>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S39>/Bus Assignment'
       *  Constant: '<S39>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S39>/Bus Assignment' incorporates:
       *  Constant: '<S39>/Constant2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.reset = 1U;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

      /* End of Outputs for SubSystem: '<S33>/Manual' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S33>/Unknown' incorporates:
       *  ActionPort: '<S41>/Action Port'
       */
      /* Outport: '<Root>/FMS_Out' */
      FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

      /* End of Outputs for SubSystem: '<S33>/Unknown' */
      break;
    }

    /* End of SwitchCase: '<S33>/Switch Case' */
    /* End of Outputs for SubSystem: '<S31>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S31>/Switch Case' */

  /* DataTypeConversion: '<S34>/Data Type Conversion' incorporates:
   *  Outport: '<Root>/FMS_Out'
   */
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  /* Sum: '<S34>/Sum' incorporates:
   *  Constant: '<S34>/Constant'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy5Inport1'
   */
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

  /* BusAssignment: '<S34>/Bus Assignment' incorporates:
   *  DataStoreRead: '<S34>/Data Store Read'
   *  DiscreteIntegrator: '<S541>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S32>/TmpSignal ConversionAtSignal Copy4Inport1'
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

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_fu ==
    FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S15>/SetHome' incorporates:
   *  TriggerPort: '<S22>/Trigger'
   */
  if (rtb_FixPtRelationalOperator_me && (FMS_PrevZCX.SetHome_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S22>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_FixPtRelationalOperator_me;

  /* End of Outputs for SubSystem: '<S15>/SetHome' */

  /* Update for UnitDelay: '<S18>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S18>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S14>/Constant1'
   */
  rtb_Divide_l_idx_0 = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Divide_l_idx_0 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Divide_l_idx_0;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S25>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S568>/Delay Input1' incorporates:
   *  Inport: '<Root>/Terrain_Info'
   *
   * Block description for '<S568>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_j = FMS_U.Terrain_Info.timestamp;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_Divide_l_idx_0 = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_m +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Divide_l_idx_0 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_m = (uint32_T)rtb_Divide_l_idx_0;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_m = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

  /* Update for Delay: '<S569>/Delay' */
  FMS_DW.Delay_DSTATE_o = rtb_Switch_mc;

  /* Update for UnitDelay: '<S20>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S21>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S21>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S26>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S26>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S27>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S27>/Delay Input1':
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

  /* Update for DiscreteIntegrator: '<S556>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S556>/Gain'
   *  Sum: '<S556>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Multiply_ft[0] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply_ft[1] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 2.0F * 0.004F;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply_ft[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S558>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S558>/Gain'
   *  Sum: '<S558>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_d += ((real32_T)rtb_Divide_dr -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_d) * 10.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S557>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S557>/Gain'
   *  Sum: '<S557>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_k += (rtb_Divide_l_idx_2 -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_k) * 10.0F * 0.004F;

  /* Update for UnitDelay: '<S11>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_Divide_l_idx_0 = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Divide_l_idx_0 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_Divide_l_idx_0;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S541>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S541>/Constant'
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

  /* Start for SwitchCase: '<S31>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S31>/Arm' */
  /* Start for SwitchCase: '<S33>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S33>/SubMode' */
  /* Start for SwitchCase: '<S40>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_at = -1;

  /* Start for IfAction SubSystem: '<S40>/Return' */
  /* Start for SwitchCase: '<S492>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S482>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ld = -1;

  /* End of Start for SubSystem: '<S40>/Return' */

  /* Start for IfAction SubSystem: '<S40>/Hold' */
  /* Start for SwitchCase: '<S424>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for SwitchCase: '<S402>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pp = -1;

  /* Start for SwitchCase: '<S412>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bn = -1;

  /* End of Start for SubSystem: '<S40>/Hold' */
  /* End of Start for SubSystem: '<S33>/SubMode' */

  /* Start for IfAction SubSystem: '<S33>/Auto' */
  /* Start for SwitchCase: '<S38>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* Start for IfAction SubSystem: '<S38>/Mission' */
  /* Start for Resettable SubSystem: '<S198>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S249>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ai = -1;

  /* Start for SwitchCase: '<S239>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S198>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S38>/Mission' */
  /* End of Start for SubSystem: '<S33>/Auto' */

  /* Start for IfAction SubSystem: '<S33>/Assist' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S37>/Stabilize' */
  /* Start for SwitchCase: '<S140>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fs = -1;

  /* End of Start for SubSystem: '<S37>/Stabilize' */

  /* Start for IfAction SubSystem: '<S37>/Altitude' */
  /* Start for SwitchCase: '<S53>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* Start for SwitchCase: '<S73>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_mn = -1;

  /* End of Start for SubSystem: '<S37>/Altitude' */

  /* Start for IfAction SubSystem: '<S37>/Position' */
  /* Start for SwitchCase: '<S88>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for SwitchCase: '<S111>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_lm = -1;

  /* Start for SwitchCase: '<S99>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bu = -1;

  /* End of Start for SubSystem: '<S37>/Position' */

  /* Start for IfAction SubSystem: '<S37>/Terrain' */
  /* Start for SwitchCase: '<S181>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S155>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fi = -1;

  /* Start for SwitchCase: '<S169>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* End of Start for SubSystem: '<S37>/Terrain' */
  /* End of Start for SubSystem: '<S33>/Assist' */
  /* End of Start for SubSystem: '<S31>/Arm' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Delay_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
  FMS_PrevZCX.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S556>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S558>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S557>/Discrete-Time Integrator5' */
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

  /* SystemInitialize for IfAction SubSystem: '<S31>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S33>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S40>/Takeoff' */
  /* InitializeConditions for Delay: '<S538>/cur_waypoint' */
  FMS_DW.icLoad_j1 = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S534>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S534>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S40>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S40>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S440>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S440>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S40>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S40>/Return' */
  /* InitializeConditions for DiscreteIntegrator: '<S472>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTAT_mx = 0U;

  /* InitializeConditions for Delay: '<S471>/Delay1' */
  FMS_DW.Delay1_DSTATE_b = false;

  /* InitializeConditions for Delay: '<S471>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S467>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_j = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S521>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_e = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* InitializeConditions for Delay: '<S449>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_j = 1U;

  /* InitializeConditions for Delay: '<S448>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator' */
  FMS_DW.Integrator_DSTATE_bs = 0.0F;

  /* SystemInitialize for Chart: '<S493>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S492>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S492>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S492>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_j);

  /* End of SystemInitialize for SubSystem: '<S492>/Move Control' */

  /* SystemInitialize for Merge: '<S492>/Merge' */
  FMS_B.Merge_ah[0] = 0.0F;
  FMS_B.Merge_ah[1] = 0.0F;

  /* SystemInitialize for Chart: '<S483>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S482>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S482>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S482>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S482>/Move Control' */

  /* SystemInitialize for Merge: '<S482>/Merge' */
  FMS_B.Merge_jj = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S40>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S40>/Hold' */
  /* SystemInitialize for Chart: '<S403>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S413>/Motion State' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S425>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S424>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S424>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S424>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S424>/Move Control' */

  /* SystemInitialize for Merge: '<S424>/Merge' */
  FMS_B.Merge_o[0] = 0.0F;
  FMS_B.Merge_o[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S402>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S402>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S402>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_n);

  /* End of SystemInitialize for SubSystem: '<S402>/Move Control' */

  /* SystemInitialize for Merge: '<S402>/Merge' */
  FMS_B.Merge_ey = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S412>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_k);

  /* End of SystemInitialize for SubSystem: '<S412>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S412>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S412>/Move Control' */

  /* SystemInitialize for Merge: '<S412>/Merge' */
  FMS_B.Merge_n1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S40>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S33>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S33>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S38>/Mission' */
  /* InitializeConditions for UnitDelay: '<S201>/Delay Input1'
   *
   * Block description for '<S201>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S198>/Mission_SubSystem' */
  /* InitializeConditions for DiscreteIntegrator: '<S229>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for Delay: '<S228>/Delay1' */
  FMS_DW.Delay1_DSTATE = false;

  /* InitializeConditions for Delay: '<S228>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S224>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S278>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;
  FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for Delay: '<S206>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S209>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S250>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_n);

  /* SystemInitialize for IfAction SubSystem: '<S249>/Hold Control' */
  FMS_HoldControl_c_Init(&FMS_DW.HoldControl_d);

  /* End of SystemInitialize for SubSystem: '<S249>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S249>/Move Control' */
  FMS_MoveControl_l_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S249>/Move Control' */

  /* SystemInitialize for Merge: '<S249>/Merge' */
  FMS_B.Merge_n[0] = 0.0F;
  FMS_B.Merge_n[1] = 0.0F;

  /* SystemInitialize for Chart: '<S240>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_jt);

  /* SystemInitialize for IfAction SubSystem: '<S239>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S239>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S239>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_m);

  /* End of SystemInitialize for SubSystem: '<S239>/Move Control' */

  /* SystemInitialize for Merge: '<S239>/Merge' */
  FMS_B.Merge_e3 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S198>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S38>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S33>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S33>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S37>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S134>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_k = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S134>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nf = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* SystemInitialize for Chart: '<S141>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_e);

  /* SystemInitialize for IfAction SubSystem: '<S140>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_h);

  /* End of SystemInitialize for SubSystem: '<S140>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S140>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S140>/Move Control' */

  /* SystemInitialize for Merge: '<S140>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S67>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S67>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* SystemInitialize for Chart: '<S54>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S53>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S53>/Hold Control' */

  /* SystemInitialize for Merge: '<S53>/Merge' */
  FMS_B.Merge_lf = 0.0F;

  /* SystemInitialize for Chart: '<S74>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_b);

  /* SystemInitialize for IfAction SubSystem: '<S73>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_hb);

  /* End of SystemInitialize for SubSystem: '<S73>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S73>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S73>/Move Control' */

  /* SystemInitialize for Merge: '<S73>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Position' */
  /* SystemInitialize for Chart: '<S89>/Motion Status' */
  FMS_MotionStatus_o_Init(&FMS_DW.sf_MotionStatus_h);

  /* SystemInitialize for IfAction SubSystem: '<S88>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_c);

  /* End of SystemInitialize for SubSystem: '<S88>/Hold Control' */

  /* SystemInitialize for Chart: '<S100>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_l);

  /* SystemInitialize for Chart: '<S112>/Motion State' */
  FMS_MotionState_b_Init(&FMS_DW.sf_MotionState_a);

  /* SystemInitialize for IfAction SubSystem: '<S111>/Hold Control' */
  FMS_HoldControl_n_Init(&FMS_DW.HoldControl_at);

  /* End of SystemInitialize for SubSystem: '<S111>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S111>/Move Control' */
  FMS_MoveControl_n_Init(&FMS_DW.MoveControl_k1);

  /* End of SystemInitialize for SubSystem: '<S111>/Move Control' */

  /* SystemInitialize for Merge: '<S111>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for Merge: '<S88>/Merge' */
  FMS_B.Merge_ld = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S99>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_h2);

  /* End of SystemInitialize for SubSystem: '<S99>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S99>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_m1);

  /* End of SystemInitialize for SubSystem: '<S99>/Move Control' */

  /* SystemInitialize for Merge: '<S99>/Merge' */
  FMS_B.Merge_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Position' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Terrain' */
  /* SystemInitialize for Chart: '<S182>/Motion State' */
  FMS_MotionState_b_Init(&FMS_DW.sf_MotionState_ej);

  /* SystemInitialize for IfAction SubSystem: '<S181>/Hold Control' */
  FMS_HoldControl_n_Init(&FMS_DW.HoldControl_nn);

  /* End of SystemInitialize for SubSystem: '<S181>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S181>/Move Control' */
  FMS_MoveControl_n_Init(&FMS_DW.MoveControl_mz);

  /* End of SystemInitialize for SubSystem: '<S181>/Move Control' */

  /* SystemInitialize for Merge: '<S181>/Merge' */
  FMS_B.Merge[0] = 0.0F;
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Chart: '<S156>/Motion Status' */
  FMS_DW.temporalCounter_i1_j = 0U;
  FMS_DW.is_active_c12_FMS = 0U;
  FMS_DW.is_c12_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S155>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_l);

  /* End of SystemInitialize for SubSystem: '<S155>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S155>/Terrain Control' */
  /* InitializeConditions for Delay: '<S159>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S165>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S165>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S155>/Terrain Control' */

  /* SystemInitialize for Merge: '<S155>/Merge' */
  FMS_B.Merge_a = 0.0F;

  /* SystemInitialize for Chart: '<S170>/Motion State' */
  FMS_MotionState_l_Init(&FMS_DW.sf_MotionState_k);

  /* SystemInitialize for IfAction SubSystem: '<S169>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_ha);

  /* End of SystemInitialize for SubSystem: '<S169>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S169>/Move Control' */
  FMS_MoveControl_j_Init(&FMS_DW.MoveControl_nm);

  /* End of SystemInitialize for SubSystem: '<S169>/Move Control' */

  /* SystemInitialize for Merge: '<S169>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Terrain' */
  /* End of SystemInitialize for SubSystem: '<S33>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S31>/Arm' */
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
