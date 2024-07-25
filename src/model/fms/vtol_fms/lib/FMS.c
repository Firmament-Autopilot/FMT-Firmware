/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2144
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jul 24 10:37:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S602>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S612>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S324>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S239>/Motion Status' */
#define FMS_IN_Brake_o                 ((uint8_T)1U)
#define FMS_IN_Hold_g                  ((uint8_T)2U)
#define FMS_IN_Move_p                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_k       ((uint8_T)0U)

/* Named constants for Chart: '<S539>/Motion State' */
#define FMS_IN_Brake_m                 ((uint8_T)1U)
#define FMS_IN_Hold_ow                 ((uint8_T)2U)
#define FMS_IN_Move_a                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_p       ((uint8_T)0U)

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
#define FMS_IN_Loiter_p                ((uint8_T)2U)
#define FMS_IN_Lost                    ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)3U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_h                ((uint8_T)4U)
#define FMS_IN_Run                     ((uint8_T)2U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)5U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_IN_Takeoff_d               ((uint8_T)5U)
#define FMS_IN_Waypoint                ((uint8_T)6U)
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
struct_ZIzGCZlY9KQnkiaeIKL2fF FMS_PARAM = {
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
  1.0F,
  1.0F,
  0.3F,
  0.6F,
  120U,
  1U,
  1300U,
  20.0F,
  15.0F,
  1.0F,
  5.0F,
  8.0F,
  0.785398185F,
  0.785398185F,
  1.04719758F,
  30.0F,
  50.0F,
  0.95F,
  8.0F,
  0.785398185F,
  0.785398185F,
  1.0F,
  55.0F,
  1.0F,
  1.0F,
  1.0F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S3>/Constant1'
                                        *   '<S8>/ACCEPT_R'
                                        *   '<S8>/MC_ACCEPT_R'
                                        *   '<S27>/Constant'
                                        *   '<S655>/Constant'
                                        *   '<S154>/Gain'
                                        *   '<S154>/Gain4'
                                        *   '<S154>/Gain5'
                                        *   '<S158>/Constant4'
                                        *   '<S159>/Constant4'
                                        *   '<S522>/L1'
                                        *   '<S46>/Gain'
                                        *   '<S48>/Gain'
                                        *   '<S49>/Gain1'
                                        *   '<S67>/Gain'
                                        *   '<S69>/Gain1'
                                        *   '<S115>/Gain'
                                        *   '<S115>/Gain1'
                                        *   '<S116>/Gain1'
                                        *   '<S131>/Constant4'
                                        *   '<S161>/Gain2'
                                        *   '<S161>/Saturation1'
                                        *   '<S162>/L1'
                                        *   '<S162>/R'
                                        *   '<S162>/Saturation1'
                                        *   '<S179>/Gain'
                                        *   '<S179>/Saturation1'
                                        *   '<S201>/Gain'
                                        *   '<S201>/Saturation1'
                                        *   '<S236>/Gain'
                                        *   '<S236>/Gain1'
                                        *   '<S314>/Gain'
                                        *   '<S314>/Gain1'
                                        *   '<S316>/Constant'
                                        *   '<S340>/L1'
                                        *   '<S418>/Saturation'
                                        *   '<S419>/Saturation1'
                                        *   '<S419>/Saturation2'
                                        *   '<S419>/Saturation3'
                                        *   '<S563>/Land_Speed'
                                        *   '<S564>/Saturation1'
                                        *   '<S643>/Takeoff_Speed'
                                        *   '<S644>/Gain2'
                                        *   '<S644>/Saturation1'
                                        *   '<S50>/Saturation1'
                                        *   '<S61>/Dead Zone'
                                        *   '<S61>/Gain'
                                        *   '<S64>/Dead Zone'
                                        *   '<S64>/Gain'
                                        *   '<S71>/Saturation1'
                                        *   '<S82>/Dead Zone'
                                        *   '<S82>/Gain'
                                        *   '<S85>/Saturation1'
                                        *   '<S118>/Dead Zone'
                                        *   '<S118>/Gain'
                                        *   '<S119>/Dead Zone'
                                        *   '<S119>/Gain'
                                        *   '<S124>/Dead Zone'
                                        *   '<S124>/Gain'
                                        *   '<S132>/Gain'
                                        *   '<S132>/Saturation1'
                                        *   '<S184>/L1'
                                        *   '<S184>/Saturation1'
                                        *   '<S206>/L1'
                                        *   '<S206>/Saturation1'
                                        *   '<S238>/Saturation1'
                                        *   '<S250>/Dead Zone'
                                        *   '<S250>/Gain'
                                        *   '<S251>/Dead Zone'
                                        *   '<S251>/Gain'
                                        *   '<S256>/Saturation'
                                        *   '<S272>/Saturation1'
                                        *   '<S284>/Saturation'
                                        *   '<S297>/Saturation1'
                                        *   '<S317>/Dead Zone'
                                        *   '<S317>/Gain'
                                        *   '<S318>/Dead Zone'
                                        *   '<S318>/Gain'
                                        *   '<S323>/Saturation'
                                        *   '<S472>/Gain2'
                                        *   '<S479>/Gain1'
                                        *   '<S479>/Gain2'
                                        *   '<S528>/Saturation1'
                                        *   '<S538>/Saturation'
                                        *   '<S550>/Saturation1'
                                        *   '<S565>/Constant'
                                        *   '<S568>/Gain2'
                                        *   '<S592>/Constant'
                                        *   '<S592>/vel'
                                        *   '<S592>/Acceleration_Speed'
                                        *   '<S592>/Saturation'
                                        *   '<S592>/Switch'
                                        *   '<S596>/Constant'
                                        *   '<S53>/Gain2'
                                        *   '<S54>/Gain1'
                                        *   '<S59>/Constant'
                                        *   '<S74>/Gain2'
                                        *   '<S75>/Gain1'
                                        *   '<S80>/Constant'
                                        *   '<S88>/L1'
                                        *   '<S89>/Gain6'
                                        *   '<S111>/Constant'
                                        *   '<S137>/L1'
                                        *   '<S137>/Saturation1'
                                        *   '<S241>/Gain2'
                                        *   '<S242>/Gain1'
                                        *   '<S248>/Constant'
                                        *   '<S259>/Gain2'
                                        *   '<S260>/Gain1'
                                        *   '<S267>/Constant'
                                        *   '<S275>/Gain2'
                                        *   '<S276>/Gain1'
                                        *   '<S282>/Constant'
                                        *   '<S287>/Gain2'
                                        *   '<S288>/Gain1'
                                        *   '<S295>/Constant'
                                        *   '<S300>/Gain2'
                                        *   '<S301>/Gain6'
                                        *   '<S311>/Constant'
                                        *   '<S312>/Constant'
                                        *   '<S326>/Gain2'
                                        *   '<S327>/Gain1'
                                        *   '<S334>/Constant'
                                        *   '<S359>/Gain'
                                        *   '<S359>/Saturation1'
                                        *   '<S362>/Constant'
                                        *   '<S362>/vel'
                                        *   '<S362>/Acceleration_Speed'
                                        *   '<S362>/Saturation'
                                        *   '<S362>/Switch'
                                        *   '<S366>/Constant'
                                        *   '<S531>/Gain2'
                                        *   '<S532>/Gain1'
                                        *   '<S541>/Gain2'
                                        *   '<S542>/Gain1'
                                        *   '<S553>/Gain2'
                                        *   '<S554>/Gain6'
                                        *   '<S577>/Gain2'
                                        *   '<S577>/Saturation'
                                        *   '<S578>/Integrator'
                                        *   '<S56>/Dead Zone'
                                        *   '<S56>/Gain'
                                        *   '<S77>/Dead Zone'
                                        *   '<S77>/Gain'
                                        *   '<S108>/Dead Zone'
                                        *   '<S108>/Gain'
                                        *   '<S244>/Land_Speed'
                                        *   '<S245>/Constant'
                                        *   '<S247>/Dead Zone'
                                        *   '<S247>/Gain'
                                        *   '<S264>/Dead Zone'
                                        *   '<S264>/Gain'
                                        *   '<S278>/Land_Speed'
                                        *   '<S279>/Constant'
                                        *   '<S281>/Dead Zone'
                                        *   '<S281>/Gain'
                                        *   '<S292>/Dead Zone'
                                        *   '<S292>/Gain'
                                        *   '<S305>/Dead Zone'
                                        *   '<S305>/Gain'
                                        *   '<S306>/Dead Zone'
                                        *   '<S306>/Gain'
                                        *   '<S331>/Dead Zone'
                                        *   '<S331>/Gain'
                                        *   '<S346>/Gain2'
                                        *   '<S346>/Saturation'
                                        *   '<S347>/Integrator'
                                        *   '<S534>/Dead Zone'
                                        *   '<S534>/Gain'
                                        *   '<S546>/Dead Zone'
                                        *   '<S546>/Gain'
                                        *   '<S558>/Dead Zone'
                                        *   '<S558>/Gain'
                                        *   '<S559>/Dead Zone'
                                        *   '<S559>/Gain'
                                        *   '<S601>/Saturation1'
                                        *   '<S611>/Saturation1'
                                        *   '<S374>/Saturation1'
                                        *   '<S384>/Saturation1'
                                        *   '<S604>/Gain2'
                                        *   '<S605>/Gain1'
                                        *   '<S614>/Gain2'
                                        *   '<S615>/Gain6'
                                        *   '<S377>/Gain2'
                                        *   '<S378>/Gain1'
                                        *   '<S387>/Gain2'
                                        *   '<S388>/Gain6'
                                        *   '<S607>/Dead Zone'
                                        *   '<S607>/Gain'
                                        *   '<S619>/Dead Zone'
                                        *   '<S619>/Gain'
                                        *   '<S620>/Dead Zone'
                                        *   '<S620>/Gain'
                                        *   '<S380>/Dead Zone'
                                        *   '<S380>/Gain'
                                        *   '<S392>/Dead Zone'
                                        *   '<S392>/Gain'
                                        *   '<S393>/Dead Zone'
                                        *   '<S393>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S1>/Constant'
                                        *   '<S13>/Constant1'
                                        *   '<S653>/Constant'
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
 * System initialize for action system:
 *    '<S601>/Hold Control'
 *    '<S528>/Hold Control'
 *    '<S374>/Hold Control'
 *    '<S238>/Hold Control'
 *    '<S272>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S604>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S601>/Hold Control'
 *    '<S528>/Hold Control'
 *    '<S374>/Hold Control'
 *    '<S238>/Hold Control'
 *    '<S272>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S604>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S601>/Hold Control'
 *    '<S528>/Hold Control'
 *    '<S374>/Hold Control'
 *    '<S238>/Hold Control'
 *    '<S272>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S604>/Delay' incorporates:
   *  Gain: '<S606>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S604>/Gain2' incorporates:
   *  Delay: '<S604>/Delay'
   *  Gain: '<S606>/Gain'
   *  Sum: '<S604>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S604>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S601>/Brake Control'
 *    '<S528>/Brake Control'
 *    '<S538>/Brake Control'
 *    '<S374>/Brake Control'
 *    '<S323>/Brake Control'
 *    '<S238>/Brake Control'
 *    '<S256>/Brake Control'
 *    '<S272>/Brake Control'
 *    '<S284>/Brake Control'
 *    '<S50>/Brake Control'
 *    '<S71>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S603>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S603>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S601>/Move Control'
 *    '<S528>/Move Control'
 *    '<S374>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S608>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S608>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S601>/Move Control'
 *    '<S528>/Move Control'
 *    '<S374>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S608>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S608>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S601>/Move Control'
 *    '<S528>/Move Control'
 *    '<S374>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3_j;
  real32_T rtb_Subtract3_m;
  real32_T rtb_a_dp;
  real32_T rtb_Add4_cu;
  real32_T rtb_a_jg;

  /* Product: '<S609>/Multiply1' incorporates:
   *  Constant: '<S609>/const1'
   *  DiscreteIntegrator: '<S608>/Integrator'
   */
  rtb_Add3_j = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S607>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_dp = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_dp = 0.0F;
  } else {
    rtb_a_dp = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S607>/Dead Zone' */

  /* Sum: '<S609>/Add' incorporates:
   *  DiscreteIntegrator: '<S608>/Integrator1'
   *  Gain: '<S605>/Gain1'
   *  Gain: '<S607>/Gain'
   *  Sum: '<S608>/Subtract'
   */
  rtb_Subtract3_m = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_dp * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_j;

  /* Signum: '<S609>/Sign' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_a_dp = -1.0F;
  } else if (rtb_Subtract3_m > 0.0F) {
    rtb_a_dp = 1.0F;
  } else {
    rtb_a_dp = rtb_Subtract3_m;
  }

  /* End of Signum: '<S609>/Sign' */

  /* Sum: '<S609>/Add2' incorporates:
   *  Abs: '<S609>/Abs'
   *  Gain: '<S609>/Gain'
   *  Gain: '<S609>/Gain1'
   *  Product: '<S609>/Multiply2'
   *  Product: '<S609>/Multiply3'
   *  Sqrt: '<S609>/Sqrt'
   *  Sum: '<S609>/Add1'
   *  Sum: '<S609>/Subtract'
   */
  rtb_a_dp = (sqrtf((8.0F * fabsf(rtb_Subtract3_m) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_dp + rtb_Add3_j;

  /* Sum: '<S609>/Add4' */
  rtb_Add4_cu = (rtb_Subtract3_m - rtb_a_dp) + rtb_Add3_j;

  /* Sum: '<S609>/Add3' */
  rtb_Add3_j = rtb_Subtract3_m + localC->d;

  /* Sum: '<S609>/Subtract1' */
  rtb_Subtract3_m -= localC->d;

  /* Signum: '<S609>/Sign1' */
  if (rtb_Add3_j < 0.0F) {
    rtb_Add3_j = -1.0F;
  } else {
    if (rtb_Add3_j > 0.0F) {
      rtb_Add3_j = 1.0F;
    }
  }

  /* End of Signum: '<S609>/Sign1' */

  /* Signum: '<S609>/Sign2' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S609>/Sign2' */

  /* Sum: '<S609>/Add5' incorporates:
   *  Gain: '<S609>/Gain2'
   *  Product: '<S609>/Multiply4'
   *  Sum: '<S609>/Subtract2'
   */
  rtb_a_dp += (rtb_Add3_j - rtb_Subtract3_m) * 0.5F * rtb_Add4_cu;

  /* SignalConversion: '<S608>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S608>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S608>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S608>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S609>/Add6' */
  rtb_Add3_j = rtb_a_dp + localC->d;

  /* Sum: '<S609>/Subtract3' */
  rtb_Subtract3_m = rtb_a_dp - localC->d;

  /* Signum: '<S609>/Sign5' */
  if (rtb_a_dp < 0.0F) {
    rtb_Add4_cu = -1.0F;
  } else if (rtb_a_dp > 0.0F) {
    rtb_Add4_cu = 1.0F;
  } else {
    rtb_Add4_cu = rtb_a_dp;
  }

  /* End of Signum: '<S609>/Sign5' */

  /* Signum: '<S609>/Sign3' */
  if (rtb_Add3_j < 0.0F) {
    rtb_Add3_j = -1.0F;
  } else {
    if (rtb_Add3_j > 0.0F) {
      rtb_Add3_j = 1.0F;
    }
  }

  /* End of Signum: '<S609>/Sign3' */

  /* Signum: '<S609>/Sign4' */
  if (rtb_Subtract3_m < 0.0F) {
    rtb_Subtract3_m = -1.0F;
  } else {
    if (rtb_Subtract3_m > 0.0F) {
      rtb_Subtract3_m = 1.0F;
    }
  }

  /* End of Signum: '<S609>/Sign4' */

  /* Signum: '<S609>/Sign6' */
  if (rtb_a_dp < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_dp > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_dp;
  }

  /* End of Signum: '<S609>/Sign6' */

  /* Update for DiscreteIntegrator: '<S608>/Integrator' incorporates:
   *  Constant: '<S609>/const'
   *  Gain: '<S609>/Gain3'
   *  Product: '<S609>/Divide'
   *  Product: '<S609>/Multiply5'
   *  Product: '<S609>/Multiply6'
   *  Sum: '<S609>/Subtract4'
   *  Sum: '<S609>/Subtract5'
   *  Sum: '<S609>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_dp / localC->d - rtb_Add4_cu) *
    localC->Gain4 * ((rtb_Add3_j - rtb_Subtract3_m) * 0.5F) - rtb_a_jg * 78.448F)
    * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S602>/Motion Status'
 *    '<S529>/Motion Status'
 *    '<S375>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S602>/Motion Status'
 *    '<S529>/Motion Status'
 *    '<S375>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S602>/Motion Status'
 *    '<S529>/Motion Status'
 *    '<S375>/Motion Status'
 */
void FMS_MotionStatus(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                      *rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S602>/Motion Status' */
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

  /* End of Chart: '<S602>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S611>/Hold Control'
 *    '<S550>/Hold Control'
 *    '<S384>/Hold Control'
 *    '<S297>/Hold Control'
 */
void FMS_HoldControl_l_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S614>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S611>/Hold Control'
 *    '<S550>/Hold Control'
 *    '<S384>/Hold Control'
 *    '<S297>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S614>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S611>/Hold Control'
 *    '<S550>/Hold Control'
 *    '<S384>/Hold Control'
 *    '<S297>/Hold Control'
 */
void FMS_HoldControl_i(real32_T rtu_FMS_In, real32_T rtu_FMS_In_g, real32_T
  rtu_FMS_In_d, real32_T rty_uv_cmd_mPs[2], const ConstB_HoldControl_FMS_k_T
  *localC, DW_HoldControl_FMS_m_T *localDW)
{
  real32_T rtb_VectorConcatenate_al[9];
  real32_T rtb_VectorConcatenate_d[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_d_tmp;
  real32_T rtb_VectorConcatenate_d_tmp_0;

  /* Delay: '<S614>/Delay' incorporates:
   *  SignalConversion: '<S614>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S618>/Trigonometric Function1' incorporates:
   *  Gain: '<S617>/Gain'
   *  Trigonometry: '<S618>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S618>/Trigonometric Function' incorporates:
   *  Gain: '<S617>/Gain'
   *  Trigonometry: '<S618>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S618>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S618>/Constant3'
   */
  rtb_VectorConcatenate_al[2] = 0.0F;

  /* Gain: '<S618>/Gain' */
  rtb_VectorConcatenate_al[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S618>/Trigonometric Function3' */
  rtb_VectorConcatenate_al[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S618>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S618>/Constant4'
   */
  rtb_VectorConcatenate_al[5] = 0.0F;

  /* SignalConversion: '<S618>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_al[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_al[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_al[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S614>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S614>/Delay'
   *  SignalConversion: '<S614>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S614>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S614>/Multiply' incorporates:
   *  SignalConversion: '<S614>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_al[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_al[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S614>/Multiply' */

  /* Gain: '<S614>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S614>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S611>/Brake Control'
 *    '<S550>/Brake Control'
 *    '<S384>/Brake Control'
 *    '<S297>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S613>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S611>/Move Control'
 *    '<S550>/Move Control'
 *    '<S384>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S621>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S621>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S621>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S621>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S611>/Move Control'
 *    '<S550>/Move Control'
 *    '<S384>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S621>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S621>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S621>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S621>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S611>/Move Control'
 *    '<S550>/Move Control'
 *    '<S384>/Move Control'
 */
void FMS_MoveControl_k(real32_T rtu_FMS_In, real32_T rtu_FMS_In_h, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_p_T *localC,
  DW_MoveControl_FMS_l_T *localDW)
{
  real32_T rtb_Subtract3_ko;
  real32_T rtb_Add3_l_idx_0;
  real32_T rtb_Subtract3_p_idx_0;
  real32_T rtb_Add3_l_idx_1;
  real32_T rtb_Subtract3_p_idx_1;
  real32_T rtb_v2_ew_idx_0;
  real32_T rtb_v2_ew_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_p_idx_0_0;

  /* DiscreteIntegrator: '<S621>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S622>/Multiply1' incorporates:
   *  Constant: '<S622>/const1'
   *  DiscreteIntegrator: '<S621>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S621>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S622>/Multiply1' incorporates:
   *  Constant: '<S622>/const1'
   *  DiscreteIntegrator: '<S621>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S619>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S619>/Dead Zone' */

  /* Sum: '<S622>/Add' incorporates:
   *  DiscreteIntegrator: '<S621>/Integrator1'
   *  Gain: '<S615>/Gain6'
   *  Gain: '<S619>/Gain'
   *  Sum: '<S621>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S620>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S620>/Dead Zone' */

  /* Sum: '<S622>/Add' incorporates:
   *  DiscreteIntegrator: '<S621>/Integrator1'
   *  Gain: '<S615>/Gain6'
   *  Gain: '<S620>/Gain'
   *  Sum: '<S621>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S622>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S622>/Add2' incorporates:
   *  Abs: '<S622>/Abs'
   *  Gain: '<S622>/Gain'
   *  Gain: '<S622>/Gain1'
   *  Product: '<S622>/Multiply2'
   *  Product: '<S622>/Multiply3'
   *  Signum: '<S622>/Sign'
   *  Sqrt: '<S622>/Sqrt'
   *  Sum: '<S622>/Add1'
   *  Sum: '<S622>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S622>/Add3' incorporates:
   *  Signum: '<S622>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S622>/Subtract1' incorporates:
   *  Signum: '<S622>/Sign'
   */
  rtb_Subtract3_ko = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S622>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S622>/Sign2' */
  if (rtb_Subtract3_ko < 0.0F) {
    rtb_Subtract3_ko = -1.0F;
  } else {
    if (rtb_Subtract3_ko > 0.0F) {
      rtb_Subtract3_ko = 1.0F;
    }
  }

  /* Sum: '<S622>/Add5' incorporates:
   *  Gain: '<S622>/Gain2'
   *  Product: '<S622>/Multiply4'
   *  Signum: '<S622>/Sign'
   *  Sum: '<S622>/Add2'
   *  Sum: '<S622>/Add4'
   *  Sum: '<S622>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_ko) * 0.5F);

  /* SignalConversion: '<S621>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S621>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S622>/Sign3' incorporates:
   *  Sum: '<S622>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S622>/Sign4' incorporates:
   *  Sum: '<S622>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S622>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S622>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S622>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S622>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_ko = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_ko = 1.0F;
  } else {
    rtb_Subtract3_ko = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S621>/Integrator' incorporates:
   *  Constant: '<S622>/const'
   *  Gain: '<S622>/Gain3'
   *  Product: '<S622>/Divide'
   *  Product: '<S622>/Multiply5'
   *  Product: '<S622>/Multiply6'
   *  Sum: '<S622>/Subtract4'
   *  Sum: '<S622>/Subtract5'
   *  Sum: '<S622>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_ko * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S621>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S622>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S622>/Add2' incorporates:
   *  Abs: '<S622>/Abs'
   *  Gain: '<S622>/Gain'
   *  Gain: '<S622>/Gain1'
   *  Product: '<S622>/Multiply2'
   *  Product: '<S622>/Multiply3'
   *  Signum: '<S622>/Sign'
   *  Sqrt: '<S622>/Sqrt'
   *  Sum: '<S622>/Add1'
   *  Sum: '<S622>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S622>/Add3' incorporates:
   *  Signum: '<S622>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S622>/Subtract1' incorporates:
   *  Signum: '<S622>/Sign'
   */
  rtb_Subtract3_ko = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S622>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S622>/Sign2' */
  if (rtb_Subtract3_ko < 0.0F) {
    rtb_Subtract3_ko = -1.0F;
  } else {
    if (rtb_Subtract3_ko > 0.0F) {
      rtb_Subtract3_ko = 1.0F;
    }
  }

  /* Sum: '<S622>/Add5' incorporates:
   *  Gain: '<S622>/Gain2'
   *  Product: '<S622>/Multiply4'
   *  Signum: '<S622>/Sign'
   *  Sum: '<S622>/Add2'
   *  Sum: '<S622>/Add4'
   *  Sum: '<S622>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_ko) * 0.5F);

  /* SignalConversion: '<S621>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S621>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S622>/Sign3' incorporates:
   *  Sum: '<S622>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S622>/Sign4' incorporates:
   *  Sum: '<S622>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S622>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S622>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S622>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S622>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_ko = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_ko = 1.0F;
  } else {
    rtb_Subtract3_ko = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S621>/Integrator' incorporates:
   *  Constant: '<S622>/const'
   *  Gain: '<S622>/Gain3'
   *  Product: '<S622>/Divide'
   *  Product: '<S622>/Multiply5'
   *  Product: '<S622>/Multiply6'
   *  Sum: '<S622>/Subtract4'
   *  Sum: '<S622>/Subtract5'
   *  Sum: '<S622>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_ko * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S621>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S612>/Motion State'
 *    '<S551>/Motion State'
 *    '<S385>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S612>/Motion State'
 *    '<S551>/Motion State'
 *    '<S385>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S612>/Motion State'
 *    '<S551>/Motion State'
 *    '<S385>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S612>/Motion State' */
  if (localDW->temporalCounter_i1 < 1023U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c2_FMS == 0U) {
    localDW->is_active_c2_FMS = 1U;
    localDW->is_c2_FMS = FMS_IN_Move_o;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c2_FMS) {
     case FMS_IN_Brake_n:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.2) || (localDW->temporalCounter_i1 >= 625U)) {
        localDW->is_c2_FMS = FMS_IN_Hold_o;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req == 1.0F) {
          localDW->is_c2_FMS = FMS_IN_Move_o;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_o:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req == 1.0F) {
        localDW->is_c2_FMS = FMS_IN_Move_o;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (rtu_motion_req == 0.0F) {
        localDW->is_c2_FMS = FMS_IN_Brake_n;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S612>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S594>/NearbyRefWP'
 *    '<S364>/NearbyRefWP'
 *    '<S208>/NearbyRefWP'
 *    '<S186>/NearbyRefWP'
 *    '<S139>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S626>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S538>/Hold Control'
 *    '<S323>/Hold Control'
 *    '<S256>/Hold Control'
 *    '<S284>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S541>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S538>/Hold Control'
 *    '<S323>/Hold Control'
 *    '<S256>/Hold Control'
 *    '<S284>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S541>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S538>/Hold Control'
 *    '<S323>/Hold Control'
 *    '<S256>/Hold Control'
 *    '<S284>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S541>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S541>/Sum' incorporates:
   *  Delay: '<S541>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S544>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S544>/Switch' incorporates:
   *  Constant: '<S544>/Constant'
   *  Constant: '<S545>/Constant'
   *  Product: '<S544>/Multiply'
   *  RelationalOperator: '<S545>/Compare'
   *  Sum: '<S544>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S544>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S544>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S544>/Switch' */

  /* Gain: '<S541>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S541>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S538>/Move Control'
 *    '<S323>/Move Control'
 *    '<S256>/Move Control'
 *    '<S284>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S547>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S547>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S538>/Move Control'
 *    '<S323>/Move Control'
 *    '<S256>/Move Control'
 *    '<S284>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S547>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S547>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S538>/Move Control'
 *    '<S323>/Move Control'
 *    '<S256>/Move Control'
 *    '<S284>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_n4;
  real32_T rtb_Subtract3_g;
  real32_T rtb_a_pq;
  real32_T rtb_Add4_om;
  real32_T rtb_a_g;

  /* Product: '<S548>/Multiply1' incorporates:
   *  Constant: '<S548>/const1'
   *  DiscreteIntegrator: '<S547>/Integrator'
   */
  rtb_Add3_n4 = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S546>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_pq = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_pq = 0.0F;
  } else {
    rtb_a_pq = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S546>/Dead Zone' */

  /* Sum: '<S548>/Add' incorporates:
   *  DiscreteIntegrator: '<S547>/Integrator1'
   *  Gain: '<S542>/Gain1'
   *  Gain: '<S546>/Gain'
   *  Sum: '<S547>/Subtract'
   */
  rtb_Subtract3_g = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_pq * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_n4;

  /* Signum: '<S548>/Sign' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_a_pq = -1.0F;
  } else if (rtb_Subtract3_g > 0.0F) {
    rtb_a_pq = 1.0F;
  } else {
    rtb_a_pq = rtb_Subtract3_g;
  }

  /* End of Signum: '<S548>/Sign' */

  /* Sum: '<S548>/Add2' incorporates:
   *  Abs: '<S548>/Abs'
   *  Gain: '<S548>/Gain'
   *  Gain: '<S548>/Gain1'
   *  Product: '<S548>/Multiply2'
   *  Product: '<S548>/Multiply3'
   *  Sqrt: '<S548>/Sqrt'
   *  Sum: '<S548>/Add1'
   *  Sum: '<S548>/Subtract'
   */
  rtb_a_pq = (sqrtf((8.0F * fabsf(rtb_Subtract3_g) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_pq + rtb_Add3_n4;

  /* Sum: '<S548>/Add4' */
  rtb_Add4_om = (rtb_Subtract3_g - rtb_a_pq) + rtb_Add3_n4;

  /* Sum: '<S548>/Add3' */
  rtb_Add3_n4 = rtb_Subtract3_g + localC->d;

  /* Sum: '<S548>/Subtract1' */
  rtb_Subtract3_g -= localC->d;

  /* Signum: '<S548>/Sign1' */
  if (rtb_Add3_n4 < 0.0F) {
    rtb_Add3_n4 = -1.0F;
  } else {
    if (rtb_Add3_n4 > 0.0F) {
      rtb_Add3_n4 = 1.0F;
    }
  }

  /* End of Signum: '<S548>/Sign1' */

  /* Signum: '<S548>/Sign2' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_Subtract3_g = -1.0F;
  } else {
    if (rtb_Subtract3_g > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    }
  }

  /* End of Signum: '<S548>/Sign2' */

  /* Sum: '<S548>/Add5' incorporates:
   *  Gain: '<S548>/Gain2'
   *  Product: '<S548>/Multiply4'
   *  Sum: '<S548>/Subtract2'
   */
  rtb_a_pq += (rtb_Add3_n4 - rtb_Subtract3_g) * 0.5F * rtb_Add4_om;

  /* SignalConversion: '<S547>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S547>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S547>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S547>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S548>/Add6' */
  rtb_Add3_n4 = rtb_a_pq + localC->d;

  /* Sum: '<S548>/Subtract3' */
  rtb_Subtract3_g = rtb_a_pq - localC->d;

  /* Signum: '<S548>/Sign5' */
  if (rtb_a_pq < 0.0F) {
    rtb_Add4_om = -1.0F;
  } else if (rtb_a_pq > 0.0F) {
    rtb_Add4_om = 1.0F;
  } else {
    rtb_Add4_om = rtb_a_pq;
  }

  /* End of Signum: '<S548>/Sign5' */

  /* Signum: '<S548>/Sign3' */
  if (rtb_Add3_n4 < 0.0F) {
    rtb_Add3_n4 = -1.0F;
  } else {
    if (rtb_Add3_n4 > 0.0F) {
      rtb_Add3_n4 = 1.0F;
    }
  }

  /* End of Signum: '<S548>/Sign3' */

  /* Signum: '<S548>/Sign4' */
  if (rtb_Subtract3_g < 0.0F) {
    rtb_Subtract3_g = -1.0F;
  } else {
    if (rtb_Subtract3_g > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    }
  }

  /* End of Signum: '<S548>/Sign4' */

  /* Signum: '<S548>/Sign6' */
  if (rtb_a_pq < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_pq > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_pq;
  }

  /* End of Signum: '<S548>/Sign6' */

  /* Update for DiscreteIntegrator: '<S547>/Integrator' incorporates:
   *  Constant: '<S548>/const'
   *  Gain: '<S548>/Gain3'
   *  Product: '<S548>/Divide'
   *  Product: '<S548>/Multiply5'
   *  Product: '<S548>/Multiply6'
   *  Sum: '<S548>/Subtract4'
   *  Sum: '<S548>/Subtract5'
   *  Sum: '<S548>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_pq / localC->d - rtb_Add4_om) *
    localC->Gain4 * ((rtb_Add3_n4 - rtb_Subtract3_g) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * Output and update for action system:
 *    '<S226>/Unknown'
 *    '<S224>/Unknown'
 *    '<S223>/Unknown'
 *    '<S36>/Unknown'
 *    '<S40>/Unknown'
 *    '<S38>/Unknown'
 *    '<S37>/Unknown'
 *    '<S35>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S524>/Bus Assignment' incorporates:
   *  Constant: '<S524>/Constant'
   *  Constant: '<S524>/Constant2'
   *  SignalConversion: '<S524>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S524>/Bus Assignment' */
}

/*
 * Output and update for atomic system:
 *    '<S364>/SearchL1RefWP'
 *    '<S208>/SearchL1RefWP'
 *    '<S186>/SearchL1RefWP'
 *    '<S139>/SearchL1RefWP'
 */
void FMS_SearchL1RefWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_h, real32_T rtu_L1, real32_T rty_P[2],
  real32_T *rty_u)
{
  real32_T A;
  real32_T B;
  real32_T D;
  real32_T a;
  real32_T u1_tmp;
  boolean_T guard1 = false;
  a = rtu_P2[0] - rtu_P1[0];
  A = rtu_P2[1] - rtu_P1[1];
  A = a * a + A * A;

  /* SignalConversion: '<S401>/TmpSignal ConversionAt SFunction Inport3' */
  B = ((rtu_P2[0] - rtu_P1[0]) * (rtu_P1[0] - rtu_P3) + (rtu_P2[1] - rtu_P1[1]) *
       (rtu_P1[1] - rtu_P3_h)) * 2.0F;
  D = B * B - (((((rtu_P3 * rtu_P3 + rtu_P3_h * rtu_P3_h) + rtu_P1[0] * rtu_P1[0])
                 + rtu_P1[1] * rtu_P1[1]) - (rtu_P3 * rtu_P1[0] + rtu_P3_h *
    rtu_P1[1]) * 2.0F) - rtu_L1 * rtu_L1) * (4.0F * A);
  a = -1.0F;
  rty_P[0] = 0.0F;
  rty_P[1] = 0.0F;
  guard1 = false;
  if (D > 0.0F) {
    u1_tmp = sqrtf(D);
    D = (-B + u1_tmp) / (2.0F * A);
    A = (-B - u1_tmp) / (2.0F * A);
    if ((D >= 0.0F) && (D <= 1.0F) && (A >= 0.0F) && (A <= 1.0F)) {
      a = fmaxf(D, A);
      guard1 = true;
    } else if ((D >= 0.0F) && (D <= 1.0F)) {
      a = D;
      guard1 = true;
    } else {
      if ((A >= 0.0F) && (A <= 1.0F)) {
        a = A;
        guard1 = true;
      }
    }
  } else {
    if (D == 0.0F) {
      D = -B / (2.0F * A);
      if ((D >= 0.0F) && (D <= 1.0F)) {
        a = D;
        guard1 = true;
      }
    }
  }

  if (guard1) {
    rty_P[0] = (rtu_P2[0] - rtu_P1[0]) * a + rtu_P1[0];
    rty_P[1] = (rtu_P2[1] - rtu_P1[1]) * a + rtu_P1[1];
  }

  *rty_u = a;
}

/*
 * System initialize for atomic system:
 *    '<S324>/Motion State'
 *    '<S257>/Motion State'
 *    '<S285>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S324>/Motion State'
 *    '<S257>/Motion State'
 *    '<S285>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S324>/Motion State'
 *    '<S257>/Motion State'
 *    '<S285>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S324>/Motion State' */
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c19_FMS == 0U) {
    localDW->is_active_c19_FMS = 1U;
    localDW->is_c19_FMS = FMS_IN_Move_l;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c19_FMS) {
     case FMS_IN_Brake_p:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.1) || (localDW->temporalCounter_i1 >= 250U)) {
        localDW->is_c19_FMS = FMS_IN_Hold_p;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c19_FMS = FMS_IN_Move_l;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_p:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c19_FMS = FMS_IN_Move_l;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c19_FMS = FMS_IN_Brake_p;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S324>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S238>/Move Control'
 *    '<S272>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S247>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S247>/Dead Zone' */

  /* Gain: '<S242>/Gain1' incorporates:
   *  Gain: '<S247>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S244>/Land_Speed'
   *  Constant: '<S245>/Constant'
   *  Constant: '<S246>/Constant'
   *  Gain: '<S244>/Gain'
   *  Logic: '<S242>/Logical Operator'
   *  MinMax: '<S244>/Min'
   *  RelationalOperator: '<S245>/Compare'
   *  RelationalOperator: '<S246>/Compare'
   *  S-Function (sfix_bitop): '<S242>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S242>/Switch' */
}

/*
 * System initialize for atomic system:
 *    '<S239>/Motion Status'
 *    '<S273>/Motion Status'
 *    '<S51>/Motion Status'
 *    '<S72>/Motion Status'
 */
void FMS_MotionStatus_c_Init(DW_MotionStatus_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_k;
}

/*
 * System reset for atomic system:
 *    '<S239>/Motion Status'
 *    '<S273>/Motion Status'
 *    '<S51>/Motion Status'
 *    '<S72>/Motion Status'
 */
void FMS_MotionStatus_a_Reset(DW_MotionStatus_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD_k;
}

/*
 * Output and update for atomic system:
 *    '<S239>/Motion Status'
 *    '<S273>/Motion Status'
 *    '<S51>/Motion Status'
 *    '<S72>/Motion Status'
 */
void FMS_MotionStatus_k(boolean_T rtu_motion_req, real32_T rtu_speed,
  MotionState *rty_state, DW_MotionStatus_FMS_i_T *localDW)
{
  /* Chart: '<S239>/Motion Status' */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c17_FMS == 0U) {
    localDW->is_active_c17_FMS = 1U;
    localDW->is_c17_FMS = FMS_IN_Move_p;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c17_FMS) {
     case FMS_IN_Brake_o:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.15) || (localDW->temporalCounter_i1 >= 375U)) {
        localDW->is_c17_FMS = FMS_IN_Hold_g;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req) {
          localDW->is_c17_FMS = FMS_IN_Move_p;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_g:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Move_p;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c17_FMS = FMS_IN_Brake_o;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S239>/Motion Status' */
}

/*
 * Output and update for atomic system:
 *    '<S208>/OutRegionRegWP'
 *    '<S186>/OutRegionRegWP'
 *    '<S139>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_k, real32_T rty_P[2])
{
  real32_T u;
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S213>/TmpSignal ConversionAt SFunction Inport3' */
  P1P3_idx_0 = rtu_P3 - rtu_P1[0];
  P1P3_idx_1 = rtu_P3_k - rtu_P1[1];
  u_tmp = rty_P[0] * rty_P[0] + rty_P[1] * rty_P[1];
  u = (P1P3_idx_0 * rty_P[0] + P1P3_idx_1 * rty_P[1]) / u_tmp;
  if (u <= 0.0F) {
    rty_P[0] = rtu_P1[0];
    rty_P[1] = rtu_P1[1];
  } else if (u >= 1.0F) {
    rty_P[0] = rtu_P2[0];
    rty_P[1] = rtu_P2[1];
  } else {
    /* SignalConversion: '<S213>/TmpSignal ConversionAt SFunction Inport3' */
    P1P3_idx_0 = (u * rty_P[0] + rtu_P1[0]) - rtu_P3;
    P1P3_idx_1 = (u * rty_P[1] + rtu_P1[1]) - rtu_P3_k;
    u += sqrtf(P1P3_idx_0 * P1P3_idx_0 + P1P3_idx_1 * P1P3_idx_1) * 0.5774F /
      sqrtf(u_tmp);
    if (u > 1.0F) {
      u = 1.0F;
    }

    rty_P[0] = u * rty_P[0] + rtu_P1[0];
    rty_P[1] = u * rty_P[1] + rtu_P1[1];
  }
}

/*
 * System initialize for action system:
 *    '<S50>/Hold Control'
 *    '<S71>/Hold Control'
 */
void FMS_HoldControl_e_Init(DW_HoldControl_FMS_b_T *localDW)
{
  /* InitializeConditions for Delay: '<S53>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S50>/Hold Control'
 *    '<S71>/Hold Control'
 */
void FMS_HoldControl_p_Reset(DW_HoldControl_FMS_b_T *localDW)
{
  /* InitializeConditions for Delay: '<S53>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S50>/Hold Control'
 *    '<S71>/Hold Control'
 */
void FMS_HoldControl_o(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_b_T *localDW)
{
  /* Delay: '<S53>/Delay' incorporates:
   *  Gain: '<S55>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S53>/Gain2' incorporates:
   *  Delay: '<S53>/Delay'
   *  Gain: '<S55>/Gain'
   *  Sum: '<S53>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.FW_Z_P;

  /* Update for Delay: '<S53>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S50>/Move Control'
 *    '<S71>/Move Control'
 */
void FMS_MoveControl_e_Init(DW_MoveControl_FMS_a_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S50>/Move Control'
 *    '<S71>/Move Control'
 */
void FMS_MoveControl_d_Reset(DW_MoveControl_FMS_a_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S50>/Move Control'
 *    '<S71>/Move Control'
 */
void FMS_MoveControl_o(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_i_T *localC, DW_MoveControl_FMS_a_T *localDW)
{
  real32_T rtb_Add3_m5;
  real32_T rtb_Subtract3_b1;
  real32_T rtb_a_iv;
  real32_T rtb_Add4_n;
  real32_T rtb_a_f;

  /* Product: '<S58>/Multiply1' incorporates:
   *  Constant: '<S58>/const1'
   *  DiscreteIntegrator: '<S57>/Integrator'
   */
  rtb_Add3_m5 = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S56>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_a_iv = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_a_iv = 0.0F;
  } else {
    rtb_a_iv = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S56>/Dead Zone' */

  /* Sum: '<S58>/Add' incorporates:
   *  DiscreteIntegrator: '<S57>/Integrator1'
   *  Gain: '<S54>/Gain1'
   *  Gain: '<S56>/Gain'
   *  Sum: '<S57>/Subtract'
   */
  rtb_Subtract3_b1 = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_a_iv * FMS_PARAM.FW_VEL_Z_LIM) + rtb_Add3_m5;

  /* Signum: '<S58>/Sign' */
  if (rtb_Subtract3_b1 < 0.0F) {
    rtb_a_iv = -1.0F;
  } else if (rtb_Subtract3_b1 > 0.0F) {
    rtb_a_iv = 1.0F;
  } else {
    rtb_a_iv = rtb_Subtract3_b1;
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
  rtb_a_iv = (sqrtf((8.0F * fabsf(rtb_Subtract3_b1) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_iv + rtb_Add3_m5;

  /* Sum: '<S58>/Add4' */
  rtb_Add4_n = (rtb_Subtract3_b1 - rtb_a_iv) + rtb_Add3_m5;

  /* Sum: '<S58>/Add3' */
  rtb_Add3_m5 = rtb_Subtract3_b1 + localC->d;

  /* Sum: '<S58>/Subtract1' */
  rtb_Subtract3_b1 -= localC->d;

  /* Signum: '<S58>/Sign1' */
  if (rtb_Add3_m5 < 0.0F) {
    rtb_Add3_m5 = -1.0F;
  } else {
    if (rtb_Add3_m5 > 0.0F) {
      rtb_Add3_m5 = 1.0F;
    }
  }

  /* End of Signum: '<S58>/Sign1' */

  /* Signum: '<S58>/Sign2' */
  if (rtb_Subtract3_b1 < 0.0F) {
    rtb_Subtract3_b1 = -1.0F;
  } else {
    if (rtb_Subtract3_b1 > 0.0F) {
      rtb_Subtract3_b1 = 1.0F;
    }
  }

  /* End of Signum: '<S58>/Sign2' */

  /* Sum: '<S58>/Add5' incorporates:
   *  Gain: '<S58>/Gain2'
   *  Product: '<S58>/Multiply4'
   *  Sum: '<S58>/Subtract2'
   */
  rtb_a_iv += (rtb_Add3_m5 - rtb_Subtract3_b1) * 0.5F * rtb_Add4_n;

  /* SignalConversion: '<S54>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S57>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S57>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S57>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S58>/Add6' */
  rtb_Add3_m5 = rtb_a_iv + localC->d;

  /* Sum: '<S58>/Subtract3' */
  rtb_Subtract3_b1 = rtb_a_iv - localC->d;

  /* Signum: '<S58>/Sign5' */
  if (rtb_a_iv < 0.0F) {
    rtb_Add4_n = -1.0F;
  } else if (rtb_a_iv > 0.0F) {
    rtb_Add4_n = 1.0F;
  } else {
    rtb_Add4_n = rtb_a_iv;
  }

  /* End of Signum: '<S58>/Sign5' */

  /* Signum: '<S58>/Sign3' */
  if (rtb_Add3_m5 < 0.0F) {
    rtb_Add3_m5 = -1.0F;
  } else {
    if (rtb_Add3_m5 > 0.0F) {
      rtb_Add3_m5 = 1.0F;
    }
  }

  /* End of Signum: '<S58>/Sign3' */

  /* Signum: '<S58>/Sign4' */
  if (rtb_Subtract3_b1 < 0.0F) {
    rtb_Subtract3_b1 = -1.0F;
  } else {
    if (rtb_Subtract3_b1 > 0.0F) {
      rtb_Subtract3_b1 = 1.0F;
    }
  }

  /* End of Signum: '<S58>/Sign4' */

  /* Signum: '<S58>/Sign6' */
  if (rtb_a_iv < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_a_iv > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_a_iv;
  }

  /* End of Signum: '<S58>/Sign6' */

  /* Update for DiscreteIntegrator: '<S57>/Integrator' incorporates:
   *  Constant: '<S58>/const'
   *  Gain: '<S58>/Gain3'
   *  Product: '<S58>/Divide'
   *  Product: '<S58>/Multiply5'
   *  Product: '<S58>/Multiply6'
   *  Sum: '<S58>/Subtract4'
   *  Sum: '<S58>/Subtract5'
   *  Sum: '<S58>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_iv / localC->d - rtb_Add4_n) *
    localC->Gain4 * ((rtb_Add3_m5 - rtb_Subtract3_b1) * 0.5F) - rtb_a_f *
    78.448F) * 0.004F;
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
  real_T rtb_Gain_lq;
  real_T rtb_Sum3_l;
  real_T rtb_Sum_n1;
  int32_T rtb_Compare_d_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S657>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S658>/Sin' */
  rtb_Sum2_ee = sin(rtb_Sum_e_idx_0);

  /* Math: '<S658>/Square1' */
  rtb_Sum2_ee *= rtb_Sum2_ee;

  /* Product: '<S658>/Multiply1' incorporates:
   *  Product: '<S658>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_ee;

  /* Product: '<S658>/Divide' incorporates:
   *  Constant: '<S658>/Constant'
   *  Constant: '<S658>/R'
   *  Sqrt: '<S658>/Sqrt'
   *  Sum: '<S658>/Sum1'
   */
  rtb_Sum2_ee = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S658>/Product3' incorporates:
   *  Constant: '<S658>/Constant1'
   *  Product: '<S658>/Multiply1'
   *  Sum: '<S658>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_ee;

  /* Product: '<S658>/Multiply2' incorporates:
   *  Trigonometry: '<S658>/Cos'
   */
  rtb_Sum2_ee *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S657>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S662>/Abs' incorporates:
   *  Abs: '<S665>/Abs1'
   *  Switch: '<S662>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S662>/Switch1' incorporates:
   *  Abs: '<S662>/Abs'
   *  Bias: '<S662>/Bias2'
   *  Bias: '<S662>/Bias3'
   *  Constant: '<S659>/Constant'
   *  Constant: '<S659>/Constant1'
   *  Constant: '<S664>/Constant'
   *  Gain: '<S662>/Gain1'
   *  Product: '<S662>/Multiply'
   *  RelationalOperator: '<S664>/Compare'
   *  Switch: '<S659>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S665>/Switch1' incorporates:
     *  Bias: '<S665>/Bias2'
     *  Bias: '<S665>/Bias3'
     *  Constant: '<S665>/Constant'
     *  Constant: '<S666>/Constant'
     *  Math: '<S665>/Math Function'
     *  RelationalOperator: '<S666>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S665>/Switch1' */

    /* Signum: '<S662>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S662>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_d_0 = 180;
  } else {
    rtb_Compare_d_0 = 0;
  }

  /* Sum: '<S659>/Sum' incorporates:
   *  Sum: '<S657>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_d_0;

  /* Product: '<S657>/Multiply' incorporates:
   *  Gain: '<S657>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S661>/Switch1' incorporates:
   *  Abs: '<S661>/Abs1'
   *  Bias: '<S661>/Bias2'
   *  Bias: '<S661>/Bias3'
   *  Constant: '<S661>/Constant'
   *  Constant: '<S663>/Constant'
   *  Math: '<S661>/Math Function'
   *  RelationalOperator: '<S663>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S661>/Switch1' */

  /* Product: '<S657>/Multiply' incorporates:
   *  Gain: '<S657>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_ee;

  /* Gain: '<S657>/deg2rad2' */
  rtb_Sum2_ee = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S660>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_ee);
  rtb_Gain_lq = cos(rtb_Sum2_ee);

  /* Sum: '<S660>/Sum2' incorporates:
   *  Product: '<S660>/Multiply1'
   *  Product: '<S660>/Multiply2'
   */
  rtb_Sum2_ee = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S660>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S660>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S660>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S654>/Data Type Conversion' incorporates:
   *  Gain: '<S657>/Gain'
   *  Sum: '<S657>/Sum1'
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

    /* Delay: '<S15>/Delay' */
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

    /* End of Delay: '<S15>/Delay' */
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

    /* Delay: '<S15>/Delay' */
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

    /* End of Delay: '<S15>/Delay' */
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

    /* Delay: '<S15>/Delay' */
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

    /* End of Delay: '<S15>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Manual(void)
{
  FMS_B.target_mode = PilotMode_Manual;

  /* Delay: '<S15>/Delay' */
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

  /* End of Delay: '<S15>/Delay' */
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
    FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  } else {
    FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Auto(void)
{
  boolean_T sf_internal_predicateOutput;
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  real32_T tmp[2];
  uint32_T qY;
  int32_T lla_tmp;
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
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
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
          FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
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
            lla_tmp = FMS_B.wp_index - 1;

            /* Inport: '<Root>/Mission_Data' */
            FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[lla_tmp] * 1.0E-7;
            FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[lla_tmp] * 1.0E-7;
            FMS_B.lla[2] = -(FMS_U.Mission_Data.z[lla_tmp] + FMS_DW.home[2]);
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
          } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
            FMS_DW.is_Mission = FMS_IN_Return_h;
            FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
            FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
            FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
            FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
            FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
            FMS_B.Cmd_In.sp_waypoint[2] =
              FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
            FMS_B.state = VehicleState_Return;
          } else {
            FMS_DW.is_Mission = FMS_IN_Loiter_p;
            FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
            FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
            FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
            FMS_B.state = VehicleState_Hold;
          }
          break;

         case FMS_IN_Return_h:
          tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home[0];
          tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home[1];
          if (FMS_norm(tmp) <= FMS_B.Switch) {
            lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
            if ((uint32_T)lla_tmp > 255U) {
              lla_tmp = 255;
            }

            FMS_B.wp_index = (uint8_T)lla_tmp;
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

         case FMS_IN_Takeoff_d:
          if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
              FMS_B.Cmd_In.sp_waypoint[2]) {
            lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
            if ((uint32_T)lla_tmp > 255U) {
              lla_tmp = 255;
            }

            FMS_B.wp_index = (uint8_T)lla_tmp;
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
          scale = 1.29246971E-26F;
          absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                        FMS_B.Cmd_In.sp_waypoint[0]);
          if (absxk > 1.29246971E-26F) {
            y = 1.0F;
            scale = absxk;
          } else {
            t = absxk / 1.29246971E-26F;
            y = t * t;
          }

          absxk = fabsf(FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                        FMS_B.Cmd_In.sp_waypoint[1]);
          if (absxk > scale) {
            t = scale / absxk;
            y = y * t * t + 1.0F;
            scale = absxk;
          } else {
            t = absxk / scale;
            y += t * t;
          }

          y = scale * sqrtf(y);
          if (y <= FMS_B.Switch) {
            lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
            if ((uint32_T)lla_tmp > 255U) {
              lla_tmp = 255;
            }

            FMS_B.wp_index = (uint8_T)lla_tmp;
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
  real32_T tmp[2];
  real_T tmp_0;
  FMS_B.stick_val[0] = FMS_DW.stick_val[0];
  FMS_B.stick_val[1] = FMS_DW.stick_val[1];
  FMS_B.stick_val[2] = FMS_DW.stick_val[2];
  FMS_B.stick_val[3] = FMS_DW.stick_val[3];
  FMS_B.pilot_cmd = FMS_B.BusConversion_InsertedFor_FMS_f;

  /* Outputs for Function Call SubSystem: '<S5>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S667>/Compare' incorporates:
   *  Abs: '<S656>/Abs'
   *  Constant: '<S667>/Constant'
   *  MinMax: '<S656>/Max'
   *  Sum: '<S656>/Sum'
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
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (FMS_getArmMode(FMS_B.target_mode) == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
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
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Land:
        FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1 = false;
        if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1
            >= 500) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        }
        break;

       case FMS_IN_Return:
        tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home[0];
        tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home[1];
        if (FMS_norm(tmp) <= FMS_B.Switch) {
          FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
          FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
          FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
          FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_SubMode = FMS_IN_Land;
          FMS_B.state = VehicleState_Land;

          /* Constant: '<Root>/Constant' */
          FMS_DW.condWasTrueAtLastTimeStep_1 = false;
        }
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_waypoint[2]) {
          if (FMS_B.target_mode != PilotMode_None) {
            tmp_0 = FMS_getArmMode(FMS_B.target_mode);
            if (tmp_0 == 3.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_Auto;
              FMS_enter_internal_Auto();
            } else if (tmp_0 == 2.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_Assist;
              FMS_enter_internal_Assist();
            } else if (tmp_0 == 1.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_Manual;
              if (FMS_B.target_mode == PilotMode_Manual) {
                FMS_DW.is_Manual = FMS_IN_Manual_g;
                FMS_B.state = VehicleState_Manual;
              } else {
                FMS_DW.is_Manual = FMS_IN_InValidManualMode;
              }
            } else {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
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
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T c_sf_internal_predicateOutput;
  real_T tmp;
  FMS_DW.durationLastReferenceTick_1_o = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_a = false;
  if ((FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_o >=
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
      FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_SubMode = FMS_IN_Land;
      FMS_B.state = VehicleState_Land;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1 = false;
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
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
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
              FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.state = VehicleState_Disarm;
            }
          }
          break;

         case FMS_IN_Auto:
          FMS_Auto();
          break;

         case FMS_IN_InvalidArmMode:
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
          break;

         case FMS_IN_Manual:
          if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
            FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
      break;

     default:
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
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
      if ((FMS_ManualArmEvent
           (FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle,
            FMS_B.BusConversion_InsertedFor_FMS_f.mode) == 1.0) &&
          (FMS_B.target_mode != PilotMode_None)) {
        guard2 = true;
      } else {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
          FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_j = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_f >= 500) {
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
                (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
              FMS_DW.durationLastReferenceTick_1_f =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_j = sf_internal_predicateOutput;
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
      /* Reshape: '<S655>/Reshape' incorporates:
       *  Constant: '<S655>/Constant'
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
      FMS_DW.durationLastReferenceTick_1_o = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_a = false;
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
      FMS_DW.durationLastReferenceTick_1_o = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_a = false;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_j = false;
      FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
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
          FMS_DW.condWasTrueAtLastTimeStep_1_j = (FMS_DW.prep_takeoff == 1.0);
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
        FMS_DW.home[3] = FMS_B.BusConversion_InsertedFor_FMSSt.psi;
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
   *  Constant: '<Root>/Constant2'
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
    FMS_DW.is_active_Lost_Return = 1U;
    FMS_DW.is_Lost_Return = FMS_IN_Connect;
    FMS_DW.is_active_VTOL_Mode = 1U;
    FMS_B.vtol_mode = VTOLMode_Multicopter;
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

    if (FMS_DW.is_active_VTOL_Mode != 0U) {
      FMS_B.vtol_mode = VTOLMode_Multicopter;
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
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  real32_T rtb_Add3_a;
  real32_T rtb_VectorConcatenate_ph[9];
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_o;
  real32_T rtb_Add4_o;
  boolean_T rtb_Compare_ii;
  MotionState rtb_state_k0;
  real32_T rtb_TmpSignalConversionAtMath_j[2];
  real32_T rtb_MathFunction_cx[2];
  real32_T rtb_Switch_kx[3];
  real32_T rtb_Sign5_fx;
  real32_T rtb_Rem_n;
  MotionState rtb_state_cq;
  MotionState rtb_state_ig;
  real_T rtb_Switch1_l4;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_o;
  uint16_T rtb_y_b;
  int32_T rtb_n;
  real32_T rtb_TmpSignalConversionAtDela_a[2];
  real32_T rtb_VectorConcatenate_c[9];
  real32_T rtb_Sqrt_h;
  boolean_T rtb_LogicalOperator_fl;
  real32_T rtb_TmpSignalConversionAtMath_l[3];
  real32_T rtb_Sum_k[2];
  real32_T rtb_VectorConcatenate_bq[3];
  boolean_T tmp[3];
  real32_T tmp_0[3];
  boolean_T tmp_1[3];
  boolean_T tmp_2[3];
  real32_T rtb_P_p_idx_0;
  real32_T rtb_Switch_n_idx_1;
  real_T rtb_Multiply_l_idx_0;
  real32_T u1_tmp;
  uint32_T tmp_3;
  uint32_T tmp_4;
  uint32_T tmp_5;
  boolean_T guard1 = false;

  /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S17>/FixPt Relational Operator'
   *  UnitDelay: '<S17>/Delay Input1'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S16>/Constant'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   *  DataTypeConversion: '<S15>/Data Type Conversion2'
   *  Delay: '<S15>/Delay'
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S15>/Logical Operator'
   *  Logic: '<S15>/Logical Operator1'
   *  RelationalOperator: '<S16>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   *  RelationalOperator: '<S24>/FixPt Relational Operator'
   *  Switch: '<S15>/Switch1'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S15>/Switch1' incorporates:
       *  DataTypeConversion: '<S15>/Data Type Conversion1'
       *  Delay: '<S15>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S15>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S15>/Delay'
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

  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_m = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* Switch: '<S14>/Switch1' incorporates:
   *  Constant: '<S14>/Constant1'
   *  DataTypeConversion: '<S14>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S19>/FixPt Relational Operator'
   *  RelationalOperator: '<S20>/FixPt Relational Operator'
   *  Switch: '<S14>/Switch2'
   *  UnitDelay: '<S19>/Delay Input1'
   *  UnitDelay: '<S20>/Delay Input1'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S14>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_m;
  } else {
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S14>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S26>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S26>/Delay Input1'
   *
   * Block description for '<S26>/Delay Input1':
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
   *  RelationalOperator: '<S25>/FixPt Relational Operator'
   *  UnitDelay: '<S25>/Delay Input1'
   *
   * Block description for '<S25>/Delay Input1':
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
   *  Constant: '<S27>/Constant'
   *  Constant: '<S3>/Constant1'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  RelationalOperator: '<S27>/Compare'
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

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Delay: '<S11>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S10>/FixPt Relational Operator'
   *  Switch: '<S11>/Switch'
   *  UnitDelay: '<S10>/Delay Input1'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Auto_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_c) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = 0U;
    rtb_Switch_ga = 1U;
  } else {
    rtb_Switch_ga = FMS_DW.Delay_DSTATE_o;
  }

  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S12>/Upper Limit'
   *  Constant: '<S9>/Constant'
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S12>/Upper Test'
   *  RelationalOperator: '<S9>/Compare'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_b < 1000U) &&
    (rtb_Switch_ga != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/ACCEPT_R'
   *  Constant: '<S8>/MC_ACCEPT_R'
   */
  if (FMS_ConstB.Compare) {
    FMS_B.Switch = FMS_PARAM.MC_ACCEPT_R;
  } else {
    FMS_B.Switch = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  rtb_FixPtRelationalOperator_me = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_me) ||
      (!FMS_DW.condWasTrueAtLastTimeStep_1_j)) {
    FMS_DW.durationLastReferenceTick_1_f = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_j = rtb_FixPtRelationalOperator_me;
  rtb_FixPtRelationalOperator_me = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_me) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
  {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_FixPtRelationalOperator_me;
  FMS_DW.durationLastReferenceTick_1_o = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_a = false;
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
  /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
  /* SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_kx[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_TmpSignalConversionAtMath_l[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_kx[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_TmpSignalConversionAtMath_l[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_kx[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_TmpSignalConversionAtMath_l[2] = FMS_B.Cmd_In.cur_waypoint[2];

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

  /* SwitchCase: '<S29>/Switch Case' incorporates:
   *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S31>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_k) {
     case 0:
      /* Disable for SwitchCase: '<S36>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
       case 0:
        /* Disable for SwitchCase: '<S226>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S611>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ln = -1;

          /* Disable for SwitchCase: '<S601>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S550>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S528>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S538>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S224>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S336>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S384>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

          /* Disable for SwitchCase: '<S374>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_af = -1;

          /* End of Disable for SubSystem: '<S336>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S223>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S323>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S238>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S256>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S272>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S297>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S284>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_o = -1;
        break;

       case 3:
       case 4:
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_b = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S35>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
       case 0:
        /* Disable for SwitchCase: '<S40>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S38>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S50>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S85>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S71>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 3:
       case 4:
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
      break;
    }

    FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

    /* End of Disable for SwitchCase: '<S31>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S29>/Disarm' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* BusAssignment: '<S33>/Bus Assignment' incorporates:
     *  Constant: '<S33>/Constant'
     *  Constant: '<S33>/Constant2'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_mv;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ap;

    /* End of Outputs for SubSystem: '<S29>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S29>/Standby' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* BusAssignment: '<S34>/Bus Assignment' incorporates:
     *  Constant: '<S34>/Constant'
     *  Constant: '<S34>/Constant2'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_hd;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ft;

    /* End of Outputs for SubSystem: '<S29>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S29>/Arm' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* SwitchCase: '<S31>/Switch Case' incorporates:
     *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy8Inport1'
     */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_k;

    /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
    if (FMS_B.vtol_mode == VTOLMode_Multicopter) {
      FMS_DW.SwitchCase_ActiveSubsystem_k = 0;
    } else {
      FMS_DW.SwitchCase_ActiveSubsystem_k = 1;
    }

    /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_k) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S36>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
         case 0:
          /* Disable for SwitchCase: '<S226>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S611>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ln = -1;

            /* Disable for SwitchCase: '<S601>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S550>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S528>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S538>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S224>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S336>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S384>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S374>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_af = -1;

            /* End of Disable for SubSystem: '<S336>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S223>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S323>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S238>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S256>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S272>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S297>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S284>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;
          break;

         case 3:
         case 4:
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S35>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
         case 0:
          /* Disable for SwitchCase: '<S40>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S38>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S37>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S50>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S85>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S71>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
          break;

         case 3:
         case 4:
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
        break;
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_k) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S31>/MC_Mode' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* SwitchCase: '<S36>/Switch Case' */
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
          /* Disable for SwitchCase: '<S226>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S611>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ln = -1;

            /* Disable for SwitchCase: '<S601>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S550>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S528>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S538>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S224>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S336>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S384>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S374>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_af = -1;

            /* End of Disable for SubSystem: '<S336>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S223>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S323>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S238>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S256>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S272>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S297>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S284>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_o = -1;
          break;

         case 3:
         case 4:
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S36>/SubMode' incorporates:
         *  ActionPort: '<S226>/Action Port'
         */
        /* SwitchCase: '<S226>/Switch Case' incorporates:
         *  Product: '<S635>/Divide'
         *  Sum: '<S595>/Subtract'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b4;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        switch (FMS_B.state) {
         case VehicleState_Takeoff:
          FMS_DW.SwitchCase_ActiveSubsystem_b4 = 0;
          break;

         case VehicleState_Land:
          FMS_DW.SwitchCase_ActiveSubsystem_b4 = 1;
          break;

         case VehicleState_Return:
          FMS_DW.SwitchCase_ActiveSubsystem_b4 = 2;
          break;

         case VehicleState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_b4 = 3;
          break;

         default:
          FMS_DW.SwitchCase_ActiveSubsystem_b4 = 4;
          break;
        }

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b4) {
          switch (rtPrevAction) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S611>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ln = -1;

            /* Disable for SwitchCase: '<S601>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S550>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S528>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S538>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S226>/Takeoff' incorporates:
             *  ActionPort: '<S523>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S226>/Switch Case' incorporates:
             *  Delay: '<S651>/cur_waypoint'
             *  DiscreteIntegrator: '<S647>/Integrator'
             *  DiscreteIntegrator: '<S647>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k1 = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S226>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S226>/Takeoff' incorporates:
           *  ActionPort: '<S523>/Action Port'
           */
          /* Delay: '<S651>/cur_waypoint' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_hz != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
            FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Product: '<S651>/Divide' incorporates:
           *  Delay: '<S651>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S651>/Sum1'
           *  Sum: '<S651>/Sum2'
           */
          rtb_Add3_a = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
                               FMS_DW.cur_waypoint_DSTATE[2]) *
            (FMS_U.INS_Out.h_R - FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S651>/Saturation' */
          if (rtb_Add3_a > 1.0F) {
            rtb_Add3_a = 1.0F;
          } else {
            if (rtb_Add3_a < 0.0F) {
              rtb_Add3_a = 0.0F;
            }
          }

          /* End of Saturate: '<S651>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Trigonometry: '<S652>/Trigonometric Function1' incorporates:
           *  Gain: '<S650>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Trigonometry: '<S652>/Trigonometric Function3'
           */
          rtb_Subtract3_e = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_VectorConcatenate_ph[0] = rtb_Subtract3_e;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Trigonometry: '<S652>/Trigonometric Function' incorporates:
           *  Gain: '<S650>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Trigonometry: '<S652>/Trigonometric Function2'
           */
          rtb_a_o = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_VectorConcatenate_ph[1] = rtb_a_o;

          /* SignalConversion: '<S652>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S652>/Constant3'
           */
          rtb_VectorConcatenate_ph[2] = 0.0F;

          /* Gain: '<S652>/Gain' */
          rtb_VectorConcatenate_ph[3] = -rtb_a_o;

          /* Trigonometry: '<S652>/Trigonometric Function3' */
          rtb_VectorConcatenate_ph[4] = rtb_Subtract3_e;

          /* SignalConversion: '<S652>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S652>/Constant4'
           */
          rtb_VectorConcatenate_ph[5] = 0.0F;

          /* SignalConversion: '<S652>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Saturate: '<S644>/Saturation1' */
          rtb_Add4_o = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Sqrt_h = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* SignalConversion: '<S644>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S651>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S651>/Multiply'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S644>/Sum'
           *  Sum: '<S651>/Sum3'
           *  Sum: '<S651>/Sum4'
           */
          rtb_Subtract3_e = ((FMS_B.Cmd_In.sp_waypoint[0] -
                              FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Add3_a +
                             FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
          rtb_a_o = ((FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.cur_waypoint_DSTATE[1])
                     * rtb_Add3_a + FMS_DW.cur_waypoint_DSTATE[1]) -
            FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S644>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_bq[rtb_n] = rtb_VectorConcatenate_ph[rtb_n + 3]
              * rtb_a_o + rtb_VectorConcatenate_ph[rtb_n] * rtb_Subtract3_e;
          }

          /* Saturate: '<S644>/Saturation1' incorporates:
           *  Gain: '<S644>/Gain2'
           *  Product: '<S644>/Multiply'
           */
          rtb_Switch_n_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_bq[0];
          rtb_Add3_a = FMS_PARAM.XY_P * rtb_VectorConcatenate_bq[1];

          /* BusAssignment: '<S523>/Bus Assignment1' incorporates:
           *  Constant: '<S523>/Constant'
           *  Constant: '<S523>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S644>/Saturation1' */
          if (rtb_Switch_n_idx_1 > rtb_Add4_o) {
            /* BusAssignment: '<S523>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Add4_o;
          } else if (rtb_Switch_n_idx_1 < rtb_Sqrt_h) {
            /* BusAssignment: '<S523>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_h;
          } else {
            /* BusAssignment: '<S523>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_n_idx_1;
          }

          if (rtb_Add3_a > rtb_Add4_o) {
            /* BusAssignment: '<S523>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Add4_o;
          } else if (rtb_Add3_a < rtb_Sqrt_h) {
            /* BusAssignment: '<S523>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Sqrt_h;
          } else {
            /* BusAssignment: '<S523>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Add3_a;
          }

          /* BusAssignment: '<S523>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S647>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S648>/Multiply1' incorporates:
           *  Constant: '<S648>/const1'
           *  DiscreteIntegrator: '<S647>/Integrator'
           */
          rtb_Add3_a = FMS_DW.Integrator_DSTATE_k1 * 0.35F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S643>/Switch' incorporates:
           *  Abs: '<S643>/Abs'
           *  Abs: '<S643>/Abs1'
           *  Constant: '<S643>/Takeoff_Speed'
           *  Constant: '<S645>/Constant'
           *  Constant: '<S646>/Constant'
           *  Gain: '<S643>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S643>/Logical Operator'
           *  RelationalOperator: '<S645>/Compare'
           *  RelationalOperator: '<S646>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S643>/Sum'
           *  Sum: '<S643>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_a_o = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_a_o = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S643>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S648>/Add' incorporates:
           *  DiscreteIntegrator: '<S647>/Integrator1'
           *  Sum: '<S647>/Subtract'
           */
          rtb_Subtract3_e = (FMS_DW.Integrator1_DSTATE_f - rtb_a_o) + rtb_Add3_a;

          /* Signum: '<S648>/Sign' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Subtract3_e > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Subtract3_e;
          }

          /* End of Signum: '<S648>/Sign' */

          /* Sum: '<S648>/Add2' incorporates:
           *  Abs: '<S648>/Abs'
           *  Gain: '<S648>/Gain'
           *  Gain: '<S648>/Gain1'
           *  Product: '<S648>/Multiply2'
           *  Product: '<S648>/Multiply3'
           *  Sqrt: '<S648>/Sqrt'
           *  Sum: '<S648>/Add1'
           *  Sum: '<S648>/Subtract'
           */
          rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + FMS_ConstB.d_bl) *
                           FMS_ConstB.d_bl) - FMS_ConstB.d_bl) * 0.5F * rtb_a_o
            + rtb_Add3_a;

          /* Sum: '<S648>/Add4' */
          rtb_Add4_o = (rtb_Subtract3_e - rtb_a_o) + rtb_Add3_a;

          /* Sum: '<S648>/Add3' */
          rtb_Add3_a = rtb_Subtract3_e + FMS_ConstB.d_bl;

          /* Sum: '<S648>/Subtract1' */
          rtb_Subtract3_e -= FMS_ConstB.d_bl;

          /* Signum: '<S648>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S648>/Sign1' */

          /* Signum: '<S648>/Sign2' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S648>/Sign2' */

          /* Sum: '<S648>/Add5' incorporates:
           *  Gain: '<S648>/Gain2'
           *  Product: '<S648>/Multiply4'
           *  Sum: '<S648>/Subtract2'
           */
          rtb_a_o += (rtb_Add3_a - rtb_Subtract3_e) * 0.5F * rtb_Add4_o;

          /* Update for Delay: '<S651>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S647>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S647>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k1;

          /* Sum: '<S648>/Subtract3' */
          rtb_Add3_a = rtb_a_o - FMS_ConstB.d_bl;

          /* Sum: '<S648>/Add6' */
          rtb_Subtract3_e = rtb_a_o + FMS_ConstB.d_bl;

          /* Signum: '<S648>/Sign5' incorporates:
           *  Signum: '<S648>/Sign6'
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S648>/Sign6' */
            rtb_Sqrt_h = -1.0F;
          } else if (rtb_a_o > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S648>/Sign6' */
            rtb_Sqrt_h = 1.0F;
          } else {
            rtb_Add4_o = rtb_a_o;

            /* Signum: '<S648>/Sign6' */
            rtb_Sqrt_h = rtb_a_o;
          }

          /* End of Signum: '<S648>/Sign5' */

          /* Signum: '<S648>/Sign3' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S648>/Sign3' */

          /* Signum: '<S648>/Sign4' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S648>/Sign4' */

          /* Update for DiscreteIntegrator: '<S647>/Integrator' incorporates:
           *  Constant: '<S648>/const'
           *  Gain: '<S648>/Gain3'
           *  Product: '<S648>/Divide'
           *  Product: '<S648>/Multiply5'
           *  Product: '<S648>/Multiply6'
           *  Sum: '<S648>/Subtract4'
           *  Sum: '<S648>/Subtract5'
           *  Sum: '<S648>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k1 += ((rtb_a_o / FMS_ConstB.d_bl -
            rtb_Add4_o) * FMS_ConstB.Gain4_i * ((rtb_Subtract3_e - rtb_Add3_a) *
            0.5F) - rtb_Sqrt_h * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S226>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S226>/Land' incorporates:
             *  ActionPort: '<S521>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S226>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S566>/Integrator'
             *  DiscreteIntegrator: '<S566>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_gs = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S226>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S226>/Land' incorporates:
           *  ActionPort: '<S521>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Trigonometry: '<S571>/Trigonometric Function1' incorporates:
           *  Gain: '<S570>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_ph[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S571>/Trigonometric Function' incorporates:
           *  Gain: '<S570>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_ph[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S571>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S571>/Constant3'
           */
          rtb_VectorConcatenate_ph[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S571>/Gain' incorporates:
           *  Gain: '<S570>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Trigonometry: '<S571>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ph[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S571>/Trigonometric Function3' incorporates:
           *  Gain: '<S570>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_ph[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S571>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S571>/Constant4'
           */
          rtb_VectorConcatenate_ph[5] = 0.0F;

          /* SignalConversion: '<S571>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S564>/Saturation1' */
          rtb_Add4_o = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Sqrt_h = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* SignalConversion: '<S568>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S568>/Sum'
           */
          rtb_Subtract3_e = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_a_o = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S568>/Multiply' incorporates:
           *  SignalConversion: '<S568>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_bq[rtb_n] = rtb_VectorConcatenate_ph[rtb_n + 3]
              * rtb_a_o + rtb_VectorConcatenate_ph[rtb_n] * rtb_Subtract3_e;
          }

          /* End of Product: '<S568>/Multiply' */

          /* Saturate: '<S564>/Saturation1' incorporates:
           *  Gain: '<S568>/Gain2'
           */
          rtb_Switch_n_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_bq[0];
          rtb_Add3_a = FMS_PARAM.XY_P * rtb_VectorConcatenate_bq[1];

          /* BusAssignment: '<S521>/Bus Assignment1' incorporates:
           *  Constant: '<S521>/Constant'
           *  Constant: '<S521>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ly;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_ot;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S564>/Saturation1' */
          if (rtb_Switch_n_idx_1 > rtb_Add4_o) {
            /* BusAssignment: '<S521>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Add4_o;
          } else if (rtb_Switch_n_idx_1 < rtb_Sqrt_h) {
            /* BusAssignment: '<S521>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Sqrt_h;
          } else {
            /* BusAssignment: '<S521>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_n_idx_1;
          }

          if (rtb_Add3_a > rtb_Add4_o) {
            /* BusAssignment: '<S521>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Add4_o;
          } else if (rtb_Add3_a < rtb_Sqrt_h) {
            /* BusAssignment: '<S521>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Sqrt_h;
          } else {
            /* BusAssignment: '<S521>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Add3_a;
          }

          /* BusAssignment: '<S521>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S566>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_gs;

          /* Product: '<S567>/Multiply1' incorporates:
           *  Constant: '<S567>/const1'
           *  DiscreteIntegrator: '<S566>/Integrator'
           */
          rtb_Add3_a = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S563>/Switch' incorporates:
           *  Constant: '<S563>/Land_Speed'
           *  Constant: '<S565>/Constant'
           *  Gain: '<S563>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S563>/Logical Operator'
           *  RelationalOperator: '<S565>/Compare'
           *  S-Function (sfix_bitop): '<S563>/cmd_p valid'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_a_o = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_a_o = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S563>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S567>/Add' incorporates:
           *  DiscreteIntegrator: '<S566>/Integrator1'
           *  Sum: '<S566>/Subtract'
           */
          rtb_Subtract3_e = (FMS_DW.Integrator1_DSTATE_gs - rtb_a_o) +
            rtb_Add3_a;

          /* Signum: '<S567>/Sign' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Subtract3_e > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Subtract3_e;
          }

          /* End of Signum: '<S567>/Sign' */

          /* Sum: '<S567>/Add2' incorporates:
           *  Abs: '<S567>/Abs'
           *  Gain: '<S567>/Gain'
           *  Gain: '<S567>/Gain1'
           *  Product: '<S567>/Multiply2'
           *  Product: '<S567>/Multiply3'
           *  Sqrt: '<S567>/Sqrt'
           *  Sum: '<S567>/Add1'
           *  Sum: '<S567>/Subtract'
           */
          rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + FMS_ConstB.d_om) *
                           FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F * rtb_a_o
            + rtb_Add3_a;

          /* Sum: '<S567>/Add4' */
          rtb_Add4_o = (rtb_Subtract3_e - rtb_a_o) + rtb_Add3_a;

          /* Sum: '<S567>/Add3' */
          rtb_Add3_a = rtb_Subtract3_e + FMS_ConstB.d_om;

          /* Sum: '<S567>/Subtract1' */
          rtb_Subtract3_e -= FMS_ConstB.d_om;

          /* Signum: '<S567>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S567>/Sign1' */

          /* Signum: '<S567>/Sign2' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S567>/Sign2' */

          /* Sum: '<S567>/Add5' incorporates:
           *  Gain: '<S567>/Gain2'
           *  Product: '<S567>/Multiply4'
           *  Sum: '<S567>/Subtract2'
           */
          rtb_a_o += (rtb_Add3_a - rtb_Subtract3_e) * 0.5F * rtb_Add4_o;

          /* Update for DiscreteIntegrator: '<S566>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S566>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_gs += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S567>/Subtract3' */
          rtb_Add3_a = rtb_a_o - FMS_ConstB.d_om;

          /* Sum: '<S567>/Add6' */
          rtb_Subtract3_e = rtb_a_o + FMS_ConstB.d_om;

          /* Signum: '<S567>/Sign5' incorporates:
           *  Signum: '<S567>/Sign6'
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S567>/Sign6' */
            rtb_Sqrt_h = -1.0F;
          } else if (rtb_a_o > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S567>/Sign6' */
            rtb_Sqrt_h = 1.0F;
          } else {
            rtb_Add4_o = rtb_a_o;

            /* Signum: '<S567>/Sign6' */
            rtb_Sqrt_h = rtb_a_o;
          }

          /* End of Signum: '<S567>/Sign5' */

          /* Signum: '<S567>/Sign3' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S567>/Sign3' */

          /* Signum: '<S567>/Sign4' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S567>/Sign4' */

          /* Update for DiscreteIntegrator: '<S566>/Integrator' incorporates:
           *  Constant: '<S567>/const'
           *  Gain: '<S567>/Gain3'
           *  Product: '<S567>/Divide'
           *  Product: '<S567>/Multiply5'
           *  Product: '<S567>/Multiply6'
           *  Sum: '<S567>/Subtract4'
           *  Sum: '<S567>/Subtract5'
           *  Sum: '<S567>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_a_o / FMS_ConstB.d_om -
            rtb_Add4_o) * FMS_ConstB.Gain4_p * ((rtb_Subtract3_e - rtb_Add3_a) *
            0.5F) - rtb_Sqrt_h * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S226>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S226>/Return' incorporates:
             *  ActionPort: '<S522>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S226>/Switch Case' incorporates:
             *  Delay: '<S574>/Delay'
             *  Delay: '<S575>/Delay'
             *  Delay: '<S596>/Delay'
             *  DiscreteIntegrator: '<S578>/Integrator'
             *  DiscreteIntegrator: '<S578>/Integrator1'
             *  DiscreteIntegrator: '<S592>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S597>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S638>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.icLoad_f = 1U;
            FMS_DW.Integrator_DSTATE_fr = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S226>/Return' */

            /* SystemReset for IfAction SubSystem: '<S226>/Return' incorporates:
             *  ActionPort: '<S522>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S226>/Switch Case' incorporates:
             *  Chart: '<S602>/Motion Status'
             *  Chart: '<S612>/Motion State'
             */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState);
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

            /* End of SystemReset for SubSystem: '<S226>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S226>/Return' incorporates:
           *  ActionPort: '<S522>/Action Port'
           */
          /* Delay: '<S596>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* RelationalOperator: '<S591>/Compare' incorporates:
           *  Constant: '<S642>/Constant'
           *  DiscreteIntegrator: '<S597>/Discrete-Time Integrator'
           *  RelationalOperator: '<S642>/Compare'
           */
          rtb_Compare_ii = (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S592>/Acceleration_Speed' */
          if (rtb_Compare_ii || (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
          }

          if (FMS_DW.Acceleration_Speed_DSTATE_a >= FMS_PARAM.CRUISE_SPEED) {
            FMS_DW.Acceleration_Speed_DSTATE_a = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (FMS_DW.Acceleration_Speed_DSTATE_a <= 0.0F) {
              FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            }
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S612>/Motion State' incorporates:
           *  Constant: '<S612>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S612>/Square'
           *  Math: '<S612>/Square1'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sqrt: '<S612>/Sqrt'
           *  Sum: '<S612>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_k0,
                          &FMS_DW.sf_MotionState);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S611>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ln;
          FMS_DW.SwitchCase_ActiveSubsystem_ln = -1;
          switch (rtb_state_k0) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_ln = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_ln = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_ln = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_ln) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ln != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S611>/Hold Control' incorporates:
               *  ActionPort: '<S614>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S611>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S611>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S611>/Hold Control' incorporates:
             *  ActionPort: '<S614>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S611>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S611>/Brake Control' incorporates:
             *  ActionPort: '<S613>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S611>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ln != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S611>/Move Control' incorporates:
               *  ActionPort: '<S615>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S611>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S611>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S611>/Move Control' incorporates:
             *  ActionPort: '<S615>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S611>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S611>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S602>/Motion Status' incorporates:
           *  Abs: '<S602>/Abs'
           *  Constant: '<S602>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_k0,
                           &FMS_DW.sf_MotionStatus);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S601>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_pv;
          FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;
          switch (rtb_state_k0) {
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
              /* SystemReset for IfAction SubSystem: '<S601>/Hold Control' incorporates:
               *  ActionPort: '<S604>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S601>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl);

              /* End of SystemReset for SubSystem: '<S601>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S601>/Hold Control' incorporates:
             *  ActionPort: '<S604>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                            &FMS_DW.HoldControl);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S601>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S601>/Brake Control' incorporates:
             *  ActionPort: '<S603>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S601>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_pv != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S601>/Move Control' incorporates:
               *  ActionPort: '<S605>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S601>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl);

              /* End of SystemReset for SubSystem: '<S601>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S601>/Move Control' incorporates:
             *  ActionPort: '<S605>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                            &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S601>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S601>/Switch Case' */

          /* Switch: '<S573>/Switch' incorporates:
           *  Product: '<S596>/Multiply'
           *  Sum: '<S596>/Sum'
           */
          if (rtb_Compare_ii) {
            /* Saturate: '<S611>/Saturation1' */
            if (FMS_B.Merge_m[0] > FMS_PARAM.VEL_XY_LIM) {
              rtb_TmpSignalConversionAtMath_l[0] = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_m[0] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_TmpSignalConversionAtMath_l[0] = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_TmpSignalConversionAtMath_l[0] = FMS_B.Merge_m[0];
            }

            if (FMS_B.Merge_m[1] > FMS_PARAM.VEL_XY_LIM) {
              rtb_TmpSignalConversionAtMath_l[1] = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_m[1] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_TmpSignalConversionAtMath_l[1] = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_TmpSignalConversionAtMath_l[1] = FMS_B.Merge_m[1];
            }

            /* End of Saturate: '<S611>/Saturation1' */

            /* Saturate: '<S601>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_TmpSignalConversionAtMath_l[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_TmpSignalConversionAtMath_l[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_TmpSignalConversionAtMath_l[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S601>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S596>/Sum' incorporates:
             *  Delay: '<S596>/Delay'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_n_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* SignalConversion: '<S639>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_TmpSignalConversionAtMath_l[0] = rtb_Switch_n_idx_1;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S592>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_P_p_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Add3_a = rtb_Switch_n_idx_1;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S596>/Sum' incorporates:
             *  Delay: '<S596>/Delay'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_n_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S592>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Sign5_fx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Sqrt: '<S598>/Sqrt' incorporates:
             *  Math: '<S598>/Square'
             *  Sum: '<S592>/Sum'
             *  Sum: '<S598>/Sum of Elements'
             */
            rtb_Sqrt_h = sqrtf(rtb_P_p_idx_0 * rtb_P_p_idx_0 + rtb_Sign5_fx *
                               rtb_Sign5_fx);

            /* SignalConversion: '<S641>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_d[0];
            rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_d[1];
            rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* SignalConversion: '<S641>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S641>/Constant4'
             */
            rtb_VectorConcatenate_ph[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Gain: '<S640>/Gain' incorporates:
             *  DiscreteIntegrator: '<S638>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S638>/Add'
             */
            rtb_Add4_o = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Trigonometry: '<S641>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S641>/Trigonometric Function1'
             */
            rtb_Subtract3_e = arm_cos_f32(rtb_Add4_o);
            rtb_VectorConcatenate_ph[4] = rtb_Subtract3_e;

            /* Trigonometry: '<S641>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S641>/Trigonometric Function'
             */
            rtb_a_o = arm_sin_f32(rtb_Add4_o);

            /* Gain: '<S641>/Gain' incorporates:
             *  Trigonometry: '<S641>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ph[3] = -rtb_a_o;

            /* SignalConversion: '<S641>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S641>/Constant3'
             */
            rtb_VectorConcatenate_ph[2] = 0.0F;

            /* Trigonometry: '<S641>/Trigonometric Function' */
            rtb_VectorConcatenate_ph[1] = rtb_a_o;

            /* Trigonometry: '<S641>/Trigonometric Function1' */
            rtb_VectorConcatenate_ph[0] = rtb_Subtract3_e;

            /* Switch: '<S592>/Switch' incorporates:
             *  Constant: '<S592>/vel'
             */
            if (rtb_Sqrt_h > FMS_PARAM.L1) {
              rtb_Add4_o = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S592>/Gain' */
              rtb_Add4_o = 0.5F * rtb_Sqrt_h;

              /* Saturate: '<S592>/Saturation' */
              if (rtb_Add4_o > FMS_PARAM.CRUISE_SPEED) {
                rtb_Add4_o = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Add4_o < 0.5F) {
                  rtb_Add4_o = 0.5F;
                }
              }

              /* End of Saturate: '<S592>/Saturation' */
            }

            /* End of Switch: '<S592>/Switch' */

            /* Switch: '<S592>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S592>/Acceleration_Speed'
             *  Sum: '<S592>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Add4_o < 0.0F) {
              rtb_Add4_o = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S592>/Switch1' */

            /* Sum: '<S639>/Sum of Elements' incorporates:
             *  Math: '<S639>/Math Function'
             */
            rtb_a_o = rtb_TmpSignalConversionAtMath_l[0] *
              rtb_TmpSignalConversionAtMath_l[0] + rtb_Switch_n_idx_1 *
              rtb_Switch_n_idx_1;

            /* Math: '<S639>/Math Function1' incorporates:
             *  Sum: '<S639>/Sum of Elements'
             *
             * About '<S639>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_a_o < 0.0F) {
              rtb_a_o = -sqrtf(fabsf(rtb_a_o));
            } else {
              rtb_a_o = sqrtf(rtb_a_o);
            }

            /* End of Math: '<S639>/Math Function1' */

            /* Switch: '<S639>/Switch' incorporates:
             *  Constant: '<S639>/Constant'
             *  Product: '<S639>/Product'
             */
            if (rtb_a_o <= 0.0F) {
              rtb_Add3_a = 0.0F;
              rtb_Switch_n_idx_1 = 0.0F;
              rtb_a_o = 1.0F;
            }

            /* End of Switch: '<S639>/Switch' */

            /* Product: '<S637>/Multiply2' incorporates:
             *  Product: '<S639>/Divide'
             */
            rtb_Add3_a = rtb_Add3_a / rtb_a_o * rtb_Add4_o;
            rtb_Switch_n_idx_1 = rtb_Switch_n_idx_1 / rtb_a_o * rtb_Add4_o;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMath_l[rtb_n] =
                rtb_VectorConcatenate_ph[rtb_n + 3] * rtb_Switch_n_idx_1 +
                rtb_VectorConcatenate_ph[rtb_n] * rtb_Add3_a;
            }
          }

          /* End of Switch: '<S573>/Switch' */

          /* Delay: '<S575>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S578>/Integrator1' incorporates:
           *  Delay: '<S575>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_bb = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Math: '<S582>/Rem' incorporates:
           *  Constant: '<S582>/Constant1'
           *  DiscreteIntegrator: '<S578>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S577>/Sum'
           */
          rtb_Add3_a = rt_remf(FMS_DW.Integrator1_DSTATE_bb - FMS_U.INS_Out.psi,
                               6.28318548F);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S582>/Switch' incorporates:
           *  Abs: '<S582>/Abs'
           *  Constant: '<S582>/Constant'
           *  Constant: '<S583>/Constant'
           *  Product: '<S582>/Multiply'
           *  RelationalOperator: '<S583>/Compare'
           *  Sum: '<S582>/Add'
           */
          if (fabsf(rtb_Add3_a) > 3.14159274F) {
            /* Signum: '<S582>/Sign' */
            if (rtb_Add3_a < 0.0F) {
              rtb_Subtract3_e = -1.0F;
            } else if (rtb_Add3_a > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            } else {
              rtb_Subtract3_e = rtb_Add3_a;
            }

            /* End of Signum: '<S582>/Sign' */
            rtb_Add3_a -= 6.28318548F * rtb_Subtract3_e;
          }

          /* End of Switch: '<S582>/Switch' */

          /* Gain: '<S577>/Gain2' */
          rtb_Add3_a *= FMS_PARAM.YAW_P;

          /* Saturate: '<S577>/Saturation' */
          if (rtb_Add3_a > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Add3_a = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Add3_a < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Add3_a = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S577>/Saturation' */

          /* BusAssignment: '<S522>/Bus Assignment1' incorporates:
           *  Constant: '<S522>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_li;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mg;
          FMS_Y.FMS_Out.u_cmd = rtb_TmpSignalConversionAtMath_l[0];
          FMS_Y.FMS_Out.v_cmd = rtb_TmpSignalConversionAtMath_l[1];
          FMS_Y.FMS_Out.w_cmd = rtb_TmpSignalConversionAtMath_l[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Add3_a;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S632>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S632>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S630>/Sum of Elements'
           */
          rtb_a_o = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S632>/Math Function1' incorporates:
           *  Sum: '<S632>/Sum of Elements'
           *
           * About '<S632>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S632>/Math Function1' */

          /* Switch: '<S632>/Switch' incorporates:
           *  Constant: '<S632>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S632>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Add3_a > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_TmpSignalConversionAtMath_l[0] = FMS_U.INS_Out.vn;
            rtb_TmpSignalConversionAtMath_l[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_TmpSignalConversionAtMath_l[2] = rtb_Add3_a;
          } else {
            rtb_TmpSignalConversionAtMath_l[0] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[1] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[2] = 1.0F;
          }

          /* End of Switch: '<S632>/Switch' */

          /* Delay: '<S574>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_f != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_nc[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S522>/Sum' incorporates:
           *  Delay: '<S574>/Delay'
           *  MATLAB Function: '<S594>/OutRegionRegWP'
           *  MATLAB Function: '<S594>/SearchL1RefWP'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_p_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_DW.Delay_DSTATE_nc[0];
          rtb_Sign5_fx = FMS_B.Cmd_In.sp_waypoint[1] - FMS_DW.Delay_DSTATE_nc[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S589>/Sum of Elements' incorporates:
           *  Math: '<S589>/Math Function'
           *  Sum: '<S522>/Sum'
           */
          rtb_Subtract3_e = rtb_Sign5_fx * rtb_Sign5_fx + rtb_P_p_idx_0 *
            rtb_P_p_idx_0;

          /* Math: '<S589>/Math Function1' incorporates:
           *  Sum: '<S589>/Sum of Elements'
           *
           * About '<S589>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_Subtract3_e));
          } else {
            rtb_Add3_a = sqrtf(rtb_Subtract3_e);
          }

          /* End of Math: '<S589>/Math Function1' */

          /* Switch: '<S589>/Switch' incorporates:
           *  Constant: '<S589>/Constant'
           *  Product: '<S589>/Product'
           *  Sum: '<S522>/Sum'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Add4_o = rtb_Sign5_fx;
            rtb_Switch_n_idx_1 = rtb_P_p_idx_0;
            rtb_Sqrt_h = rtb_Add3_a;
          } else {
            rtb_Add4_o = 0.0F;
            rtb_Switch_n_idx_1 = 0.0F;
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S589>/Switch' */

          /* Product: '<S632>/Divide' */
          rtb_Sum_k[0] = rtb_TmpSignalConversionAtMath_l[0] /
            rtb_TmpSignalConversionAtMath_l[2];
          rtb_Sum_k[1] = rtb_TmpSignalConversionAtMath_l[1] /
            rtb_TmpSignalConversionAtMath_l[2];

          /* Sum: '<S635>/Sum of Elements' incorporates:
           *  Math: '<S635>/Math Function'
           *  SignalConversion: '<S635>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Subtract3_e = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] *
            rtb_Sum_k[0];

          /* Math: '<S635>/Math Function1' incorporates:
           *  Sum: '<S635>/Sum of Elements'
           *
           * About '<S635>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_Subtract3_e));
          } else {
            rtb_Add3_a = sqrtf(rtb_Subtract3_e);
          }

          /* End of Math: '<S635>/Math Function1' */

          /* Switch: '<S635>/Switch' incorporates:
           *  Constant: '<S635>/Constant'
           *  Product: '<S635>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_TmpSignalConversionAtMath_l[0] = rtb_Sum_k[1];
            rtb_TmpSignalConversionAtMath_l[1] = rtb_Sum_k[0];
            rtb_TmpSignalConversionAtMath_l[2] = rtb_Add3_a;
          } else {
            rtb_TmpSignalConversionAtMath_l[0] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[1] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[2] = 1.0F;
          }

          /* End of Switch: '<S635>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S594>/NearbyRefWP' incorporates:
           *  Constant: '<S522>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_kx[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Sum_k, &rtb_Rem_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* MATLAB Function: '<S594>/SearchL1RefWP' incorporates:
           *  Constant: '<S522>/L1'
           *  Delay: '<S574>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Subtract3_e = rtb_P_p_idx_0 * rtb_P_p_idx_0 + rtb_Sign5_fx *
            rtb_Sign5_fx;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          B = (rtb_P_p_idx_0 * (FMS_DW.Delay_DSTATE_nc[0] - FMS_U.INS_Out.x_R) +
               rtb_Sign5_fx * (FMS_DW.Delay_DSTATE_nc[1] - FMS_U.INS_Out.y_R)) *
            2.0F;
          D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                           FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                          FMS_DW.Delay_DSTATE_nc[0] * FMS_DW.Delay_DSTATE_nc[0])
                         + FMS_DW.Delay_DSTATE_nc[1] * FMS_DW.Delay_DSTATE_nc[1])
                        - (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_nc[0] +
                           FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_nc[1]) * 2.0F)
                       - FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * rtb_Subtract3_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Add3_a = -1.0F;
          rtb_MathFunction_cx[0] = 0.0F;
          rtb_MathFunction_cx[1] = 0.0F;
          guard1 = false;
          if (D > 0.0F) {
            u1_tmp = sqrtf(D);
            D = (-B + u1_tmp) / (2.0F * rtb_Subtract3_e);
            rtb_Subtract3_e = (-B - u1_tmp) / (2.0F * rtb_Subtract3_e);
            if ((D >= 0.0F) && (D <= 1.0F) && (rtb_Subtract3_e >= 0.0F) &&
                (rtb_Subtract3_e <= 1.0F)) {
              rtb_Add3_a = fmaxf(D, rtb_Subtract3_e);
              guard1 = true;
            } else if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_Add3_a = D;
              guard1 = true;
            } else {
              if ((rtb_Subtract3_e >= 0.0F) && (rtb_Subtract3_e <= 1.0F)) {
                rtb_Add3_a = rtb_Subtract3_e;
                guard1 = true;
              }
            }
          } else {
            if (D == 0.0F) {
              D = -B / (2.0F * rtb_Subtract3_e);
              if ((D >= 0.0F) && (D <= 1.0F)) {
                rtb_Add3_a = D;
                guard1 = true;
              }
            }
          }

          if (guard1) {
            rtb_MathFunction_cx[0] = rtb_P_p_idx_0 * rtb_Add3_a +
              FMS_DW.Delay_DSTATE_nc[0];
            rtb_MathFunction_cx[1] = rtb_Sign5_fx * rtb_Add3_a +
              FMS_DW.Delay_DSTATE_nc[1];
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S594>/OutRegionRegWP' incorporates:
           *  Delay: '<S574>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract3_e = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_nc[1]) *
                             rtb_Sign5_fx + (FMS_U.INS_Out.x_R -
            FMS_DW.Delay_DSTATE_nc[0]) * rtb_P_p_idx_0) / (rtb_P_p_idx_0 *
            rtb_P_p_idx_0 + rtb_Sign5_fx * rtb_Sign5_fx);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_FixPtRelationalOperator_me = (rtb_Subtract3_e <= 0.0F);
          rtb_LogicalOperator_fl = (rtb_Subtract3_e >= 1.0F);
          if (rtb_FixPtRelationalOperator_me) {
            rtb_P_p_idx_0 = FMS_DW.Delay_DSTATE_nc[0];
          } else if (rtb_LogicalOperator_fl) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_P_p_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else {
            rtb_P_p_idx_0 = rtb_Subtract3_e * rtb_P_p_idx_0 +
              FMS_DW.Delay_DSTATE_nc[0];
          }

          /* Switch: '<S594>/Switch1' incorporates:
           *  Constant: '<S625>/Constant'
           *  RelationalOperator: '<S625>/Compare'
           */
          if (rtb_Rem_n <= 0.0F) {
            /* Switch: '<S594>/Switch' incorporates:
             *  Constant: '<S624>/Constant'
             *  MATLAB Function: '<S594>/SearchL1RefWP'
             *  RelationalOperator: '<S624>/Compare'
             */
            if (rtb_Add3_a >= 0.0F) {
              rtb_Sum_k[0] = rtb_MathFunction_cx[0];
              rtb_Sum_k[1] = rtb_MathFunction_cx[1];
            } else {
              rtb_Sum_k[0] = rtb_P_p_idx_0;

              /* MATLAB Function: '<S594>/OutRegionRegWP' incorporates:
               *  Delay: '<S574>/Delay'
               *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
               */
              if (rtb_FixPtRelationalOperator_me) {
                rtb_Sum_k[1] = FMS_DW.Delay_DSTATE_nc[1];
              } else if (rtb_LogicalOperator_fl) {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_Sum_k[1] = FMS_B.Cmd_In.sp_waypoint[1];

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              } else {
                rtb_Sum_k[1] = rtb_Subtract3_e * rtb_Sign5_fx +
                  FMS_DW.Delay_DSTATE_nc[1];
              }
            }

            /* End of Switch: '<S594>/Switch' */
          }

          /* End of Switch: '<S594>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S595>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_P_p_idx_0 = rtb_Sum_k[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S633>/Math Function' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_P_p_idx_0 * rtb_P_p_idx_0;
          rtb_Sum_k[0] = rtb_P_p_idx_0;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S595>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_P_p_idx_0 = rtb_Sum_k[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S633>/Math Function' incorporates:
           *  Math: '<S631>/Square'
           */
          rtb_Subtract3_e = rtb_P_p_idx_0 * rtb_P_p_idx_0;

          /* Sum: '<S633>/Sum of Elements' incorporates:
           *  Math: '<S633>/Math Function'
           */
          rtb_Add3_a = rtb_Subtract3_e + rtb_TmpSignalConversionAtMath_j[0];

          /* Math: '<S633>/Math Function1' incorporates:
           *  Sum: '<S633>/Sum of Elements'
           *
           * About '<S633>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_Add3_a));
          } else {
            rtb_Add3_a = sqrtf(rtb_Add3_a);
          }

          /* End of Math: '<S633>/Math Function1' */

          /* Switch: '<S633>/Switch' incorporates:
           *  Constant: '<S633>/Constant'
           *  Product: '<S633>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Switch_kx[0] = rtb_Sum_k[0];
            rtb_Switch_kx[1] = rtb_P_p_idx_0;
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S633>/Switch' */

          /* Product: '<S633>/Divide' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_Switch_kx[0] / rtb_Switch_kx
            [2];
          rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_kx[1] / rtb_Switch_kx
            [2];

          /* Sum: '<S636>/Sum of Elements' incorporates:
           *  Math: '<S636>/Math Function'
           *  SignalConversion: '<S636>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Add3_a = rtb_TmpSignalConversionAtMath_j[1] *
            rtb_TmpSignalConversionAtMath_j[1] +
            rtb_TmpSignalConversionAtMath_j[0] *
            rtb_TmpSignalConversionAtMath_j[0];

          /* Math: '<S636>/Math Function1' incorporates:
           *  Sum: '<S636>/Sum of Elements'
           *
           * About '<S636>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_Add3_a));
          } else {
            rtb_Add3_a = sqrtf(rtb_Add3_a);
          }

          /* End of Math: '<S636>/Math Function1' */

          /* Switch: '<S636>/Switch' incorporates:
           *  Constant: '<S636>/Constant'
           *  Product: '<S636>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Switch_kx[0] = rtb_TmpSignalConversionAtMath_j[1];
            rtb_Switch_kx[1] = rtb_TmpSignalConversionAtMath_j[0];
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S636>/Switch' */

          /* Product: '<S636>/Divide' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_Switch_kx[0] / rtb_Switch_kx
            [2];

          /* Math: '<S631>/Square' */
          rtb_TmpSignalConversionAtDela_a[0] = rtb_Sum_k[0] * rtb_Sum_k[0];

          /* Product: '<S589>/Divide' */
          rtb_MathFunction_cx[0] = rtb_Add4_o / rtb_Sqrt_h;
          rtb_Sum_k[0] = rtb_TmpSignalConversionAtMath_l[0] /
            rtb_TmpSignalConversionAtMath_l[2];

          /* Product: '<S636>/Divide' incorporates:
           *  Product: '<S635>/Divide'
           */
          rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_kx[1] / rtb_Switch_kx
            [2];

          /* Product: '<S635>/Divide' */
          rtb_P_p_idx_0 = rtb_TmpSignalConversionAtMath_l[1] /
            rtb_TmpSignalConversionAtMath_l[2];

          /* Product: '<S589>/Divide' */
          rtb_MathFunction_cx[1] = rtb_Switch_n_idx_1 / rtb_Sqrt_h;

          /* Sqrt: '<S630>/Sqrt' */
          rtb_Add3_a = sqrtf(rtb_a_o);

          /* Gain: '<S595>/Gain' incorporates:
           *  Math: '<S595>/Square'
           */
          rtb_a_o = rtb_Add3_a * rtb_Add3_a * 2.0F;

          /* Sum: '<S634>/Subtract' incorporates:
           *  Product: '<S634>/Multiply'
           *  Product: '<S634>/Multiply1'
           */
          rtb_Add3_a = rtb_TmpSignalConversionAtMath_j[0] * rtb_P_p_idx_0 -
            rtb_TmpSignalConversionAtMath_j[1] * rtb_Sum_k[0];

          /* Signum: '<S629>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S629>/Sign1' */

          /* Switch: '<S629>/Switch2' incorporates:
           *  Constant: '<S629>/Constant4'
           */
          if (rtb_Add3_a == 0.0F) {
            rtb_Add3_a = 1.0F;
          }

          /* End of Switch: '<S629>/Switch2' */

          /* DotProduct: '<S629>/Dot Product' */
          rtb_P_p_idx_0 = rtb_Sum_k[0] * rtb_TmpSignalConversionAtMath_j[0] +
            rtb_P_p_idx_0 * rtb_TmpSignalConversionAtMath_j[1];

          /* Trigonometry: '<S629>/Acos' incorporates:
           *  DotProduct: '<S629>/Dot Product'
           */
          if (rtb_P_p_idx_0 > 1.0F) {
            rtb_P_p_idx_0 = 1.0F;
          } else {
            if (rtb_P_p_idx_0 < -1.0F) {
              rtb_P_p_idx_0 = -1.0F;
            }
          }

          /* Product: '<S629>/Multiply' incorporates:
           *  Trigonometry: '<S629>/Acos'
           */
          rtb_Add3_a *= acosf(rtb_P_p_idx_0);

          /* Saturate: '<S595>/Saturation' */
          if (rtb_Add3_a > 1.57079637F) {
            rtb_Add3_a = 1.57079637F;
          } else {
            if (rtb_Add3_a < -1.57079637F) {
              rtb_Add3_a = -1.57079637F;
            }
          }

          /* End of Saturate: '<S595>/Saturation' */

          /* Product: '<S595>/Divide' incorporates:
           *  Constant: '<S522>/L1'
           *  Constant: '<S595>/Constant'
           *  MinMax: '<S595>/Max'
           *  MinMax: '<S595>/Min'
           *  Product: '<S595>/Multiply1'
           *  Sqrt: '<S631>/Sqrt'
           *  Sum: '<S631>/Sum of Elements'
           *  Trigonometry: '<S595>/Sin'
           */
          rtb_a_o = arm_sin_f32(rtb_Add3_a) * rtb_a_o / fminf(FMS_PARAM.L1,
            fmaxf(sqrtf(rtb_Subtract3_e + rtb_TmpSignalConversionAtDela_a[0]),
                  0.5F));

          /* Sum: '<S587>/Subtract' incorporates:
           *  Product: '<S587>/Multiply'
           *  Product: '<S587>/Multiply1'
           */
          rtb_Sqrt_h = rtb_MathFunction_cx[0] * FMS_ConstB.Divide_m[1] -
            rtb_MathFunction_cx[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S576>/Sign1' */
          if (rtb_Sqrt_h < 0.0F) {
            rtb_Sqrt_h = -1.0F;
          } else {
            if (rtb_Sqrt_h > 0.0F) {
              rtb_Sqrt_h = 1.0F;
            }
          }

          /* End of Signum: '<S576>/Sign1' */

          /* Switch: '<S576>/Switch2' incorporates:
           *  Constant: '<S576>/Constant4'
           */
          if (rtb_Sqrt_h == 0.0F) {
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S576>/Switch2' */

          /* DotProduct: '<S576>/Dot Product' */
          rtb_Switch_n_idx_1 = FMS_ConstB.Divide_m[0] * rtb_MathFunction_cx[0] +
            FMS_ConstB.Divide_m[1] * rtb_MathFunction_cx[1];

          /* Trigonometry: '<S576>/Acos' incorporates:
           *  DotProduct: '<S576>/Dot Product'
           */
          if (rtb_Switch_n_idx_1 > 1.0F) {
            rtb_Switch_n_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_n_idx_1 < -1.0F) {
              rtb_Switch_n_idx_1 = -1.0F;
            }
          }

          /* Product: '<S576>/Multiply' incorporates:
           *  Trigonometry: '<S576>/Acos'
           */
          rtb_Sqrt_h *= acosf(rtb_Switch_n_idx_1);

          /* Math: '<S579>/Rem' incorporates:
           *  Constant: '<S579>/Constant1'
           *  Delay: '<S575>/Delay'
           *  Sum: '<S575>/Sum2'
           */
          rtb_Add3_a = rt_remf(rtb_Sqrt_h - FMS_DW.Delay_DSTATE_nx, 6.28318548F);

          /* Switch: '<S579>/Switch' incorporates:
           *  Abs: '<S579>/Abs'
           *  Constant: '<S579>/Constant'
           *  Constant: '<S585>/Constant'
           *  Product: '<S579>/Multiply'
           *  RelationalOperator: '<S585>/Compare'
           *  Sum: '<S579>/Add'
           */
          if (fabsf(rtb_Add3_a) > 3.14159274F) {
            /* Signum: '<S579>/Sign' */
            if (rtb_Add3_a < 0.0F) {
              rtb_Subtract3_e = -1.0F;
            } else if (rtb_Add3_a > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            } else {
              rtb_Subtract3_e = rtb_Add3_a;
            }

            /* End of Signum: '<S579>/Sign' */
            rtb_Add3_a -= 6.28318548F * rtb_Subtract3_e;
          }

          /* End of Switch: '<S579>/Switch' */

          /* Sum: '<S575>/Sum' incorporates:
           *  Delay: '<S575>/Delay'
           */
          rtb_Subtract3_e = rtb_Add3_a + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S584>/Multiply1' incorporates:
           *  Constant: '<S584>/const1'
           *  DiscreteIntegrator: '<S578>/Integrator'
           */
          rtb_Add3_a = FMS_DW.Integrator_DSTATE_fr * 0.785398185F;

          /* Sum: '<S584>/Add' incorporates:
           *  DiscreteIntegrator: '<S578>/Integrator1'
           *  Sum: '<S578>/Subtract'
           */
          rtb_Subtract3_e = (FMS_DW.Integrator1_DSTATE_bb - rtb_Subtract3_e) +
            rtb_Add3_a;

          /* Signum: '<S584>/Sign' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Add4_o = -1.0F;
          } else if (rtb_Subtract3_e > 0.0F) {
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Add4_o = rtb_Subtract3_e;
          }

          /* End of Signum: '<S584>/Sign' */

          /* Sum: '<S584>/Add2' incorporates:
           *  Abs: '<S584>/Abs'
           *  Gain: '<S584>/Gain'
           *  Gain: '<S584>/Gain1'
           *  Product: '<S584>/Multiply2'
           *  Product: '<S584>/Multiply3'
           *  Sqrt: '<S584>/Sqrt'
           *  Sum: '<S584>/Add1'
           *  Sum: '<S584>/Subtract'
           */
          rtb_Rem_n = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + FMS_ConstB.d_nx) *
                             FMS_ConstB.d_nx) - FMS_ConstB.d_nx) * 0.5F *
            rtb_Add4_o + rtb_Add3_a;

          /* Sum: '<S584>/Add4' */
          rtb_Add4_o = (rtb_Subtract3_e - rtb_Rem_n) + rtb_Add3_a;

          /* Sum: '<S584>/Add3' */
          rtb_Add3_a = rtb_Subtract3_e + FMS_ConstB.d_nx;

          /* Sum: '<S584>/Subtract1' */
          rtb_Subtract3_e -= FMS_ConstB.d_nx;

          /* Signum: '<S584>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S584>/Sign1' */

          /* Signum: '<S584>/Sign2' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S584>/Sign2' */

          /* Sum: '<S584>/Add5' incorporates:
           *  Gain: '<S584>/Gain2'
           *  Product: '<S584>/Multiply4'
           *  Sum: '<S584>/Subtract2'
           */
          rtb_Rem_n += (rtb_Add3_a - rtb_Subtract3_e) * 0.5F * rtb_Add4_o;

          /* Sum: '<S584>/Add6' */
          rtb_Add3_a = rtb_Rem_n + FMS_ConstB.d_nx;

          /* Sum: '<S584>/Subtract3' */
          rtb_Subtract3_e = rtb_Rem_n - FMS_ConstB.d_nx;

          /* Product: '<S584>/Divide' */
          rtb_P_p_idx_0 = rtb_Rem_n / FMS_ConstB.d_nx;

          /* Signum: '<S584>/Sign5' incorporates:
           *  Signum: '<S584>/Sign6'
           */
          if (rtb_Rem_n < 0.0F) {
            rtb_Sign5_fx = -1.0F;

            /* Signum: '<S584>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Rem_n > 0.0F) {
            rtb_Sign5_fx = 1.0F;

            /* Signum: '<S584>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Sign5_fx = rtb_Rem_n;

            /* Signum: '<S584>/Sign6' */
            rtb_Add4_o = rtb_Rem_n;
          }

          /* End of Signum: '<S584>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S575>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Sqrt_h -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S580>/Rem' incorporates:
           *  Constant: '<S580>/Constant1'
           */
          rtb_Rem_n = rt_remf(rtb_Sqrt_h, 6.28318548F);

          /* Switch: '<S580>/Switch' incorporates:
           *  Abs: '<S580>/Abs'
           *  Constant: '<S580>/Constant'
           *  Constant: '<S586>/Constant'
           *  Product: '<S580>/Multiply'
           *  RelationalOperator: '<S586>/Compare'
           *  Sum: '<S580>/Add'
           */
          if (fabsf(rtb_Rem_n) > 3.14159274F) {
            /* Signum: '<S580>/Sign' */
            if (rtb_Rem_n < 0.0F) {
              rtb_Switch_n_idx_1 = -1.0F;
            } else if (rtb_Rem_n > 0.0F) {
              rtb_Switch_n_idx_1 = 1.0F;
            } else {
              rtb_Switch_n_idx_1 = rtb_Rem_n;
            }

            /* End of Signum: '<S580>/Sign' */
            rtb_Rem_n -= 6.28318548F * rtb_Switch_n_idx_1;
          }

          /* End of Switch: '<S580>/Switch' */

          /* Abs: '<S573>/Abs' */
          rtb_Rem_n = fabsf(rtb_Rem_n);

          /* Update for Delay: '<S596>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S597>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S590>/Constant'
           *  RelationalOperator: '<S590>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_a = (uint8_T)((uint32_T)
            (rtb_Rem_n <= 0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_a);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S597>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S592>/Acceleration_Speed' incorporates:
           *  Constant: '<S592>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE_a += 0.004F * FMS_PARAM.CRUISE_ACC;
          if (FMS_DW.Acceleration_Speed_DSTATE_a >= FMS_PARAM.CRUISE_SPEED) {
            FMS_DW.Acceleration_Speed_DSTATE_a = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (FMS_DW.Acceleration_Speed_DSTATE_a <= 0.0F) {
              FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            }
          }

          FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)rtb_Compare_ii;

          /* End of Update for DiscreteIntegrator: '<S592>/Acceleration_Speed' */

          /* Product: '<S596>/Divide1' incorporates:
           *  Constant: '<S596>/Constant'
           */
          rtb_Switch_n_idx_1 = rtb_a_o / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S596>/Saturation' */
          if (rtb_Switch_n_idx_1 > 0.314159274F) {
            rtb_Switch_n_idx_1 = 0.314159274F;
          } else {
            if (rtb_Switch_n_idx_1 < -0.314159274F) {
              rtb_Switch_n_idx_1 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S596>/Saturation' */

          /* Update for DiscreteIntegrator: '<S638>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_Switch_n_idx_1;

          /* Update for Delay: '<S575>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S578>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S578>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_bb += 0.004F * FMS_DW.Integrator_DSTATE_fr;

          /* Update for Delay: '<S574>/Delay' */
          FMS_DW.icLoad_f = 0U;

          /* Signum: '<S584>/Sign3' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S584>/Sign3' */

          /* Signum: '<S584>/Sign4' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S584>/Sign4' */

          /* Update for DiscreteIntegrator: '<S578>/Integrator' incorporates:
           *  Constant: '<S584>/const'
           *  Gain: '<S584>/Gain3'
           *  Product: '<S584>/Multiply5'
           *  Product: '<S584>/Multiply6'
           *  Sum: '<S584>/Subtract4'
           *  Sum: '<S584>/Subtract5'
           *  Sum: '<S584>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_fr += ((rtb_P_p_idx_0 - rtb_Sign5_fx) *
            FMS_ConstB.Gain4_d3 * ((rtb_Add3_a - rtb_Subtract3_e) * 0.5F) -
            rtb_Add4_o * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_fr >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_fr = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_fr <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_fr = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S578>/Integrator' */
          /* End of Outputs for SubSystem: '<S226>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S226>/Hold' incorporates:
             *  ActionPort: '<S520>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S226>/Switch Case' incorporates:
             *  Chart: '<S529>/Motion Status'
             *  Chart: '<S539>/Motion State'
             *  Chart: '<S551>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_il = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S226>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S226>/Hold' incorporates:
           *  ActionPort: '<S520>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S529>/Motion Status' incorporates:
           *  Abs: '<S529>/Abs'
           *  Constant: '<S529>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_k0,
                           &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Chart: '<S539>/Motion State' incorporates:
           *  Abs: '<S539>/Abs'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.temporalCounter_i1_il < 255U) {
            FMS_DW.temporalCounter_i1_il++;
          }

          if (FMS_DW.is_active_c15_FMS == 0U) {
            FMS_DW.is_active_c15_FMS = 1U;
            FMS_DW.is_c15_FMS = FMS_IN_Move_a;
            rtb_state_ig = MotionState_Move;
          } else {
            switch (FMS_DW.is_c15_FMS) {
             case FMS_IN_Brake_m:
              rtb_state_ig = MotionState_Brake;

              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              if ((fabsf(FMS_U.INS_Out.r) <= 0.1) ||
                  (FMS_DW.temporalCounter_i1_il >= 250U)) {
                FMS_DW.is_c15_FMS = FMS_IN_Hold_ow;
                rtb_state_ig = MotionState_Hold;
              }

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              break;

             case FMS_IN_Hold_ow:
              rtb_state_ig = MotionState_Hold;
              break;

             default:
              FMS_DW.is_c15_FMS = FMS_IN_Brake_m;
              FMS_DW.temporalCounter_i1_il = 0U;
              rtb_state_ig = MotionState_Brake;
              break;
            }
          }

          /* End of Chart: '<S539>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S551>/Motion State' incorporates:
           *  Constant: '<S551>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S551>/Square'
           *  Math: '<S551>/Square1'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sqrt: '<S551>/Sqrt'
           *  Sum: '<S551>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_cq,
                          &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S550>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_nm;
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;
          switch (rtb_state_cq) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_nm = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_nm = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_nm = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_nm) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S550>/Hold Control' incorporates:
               *  ActionPort: '<S553>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S550>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S550>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S550>/Hold Control' incorporates:
             *  ActionPort: '<S553>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S550>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S550>/Brake Control' incorporates:
             *  ActionPort: '<S552>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S550>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S550>/Move Control' incorporates:
               *  ActionPort: '<S554>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S550>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S550>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S550>/Move Control' incorporates:
             *  ActionPort: '<S554>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S550>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S550>/Switch Case' */

          /* SwitchCase: '<S528>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_k4;
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;
          switch (rtb_state_k0) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_k4) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S528>/Hold Control' incorporates:
               *  ActionPort: '<S531>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S528>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S528>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S528>/Hold Control' incorporates:
             *  ActionPort: '<S531>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                            &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S528>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S528>/Brake Control' incorporates:
             *  ActionPort: '<S530>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S528>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S528>/Move Control' incorporates:
               *  ActionPort: '<S532>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S528>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S528>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S528>/Move Control' incorporates:
             *  ActionPort: '<S532>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                            &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S528>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S528>/Switch Case' */

          /* SwitchCase: '<S538>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_cv;
          FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;
          switch (rtb_state_ig) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_cv = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_cv = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_cv = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_cv) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_cv != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S538>/Hold Control' incorporates:
               *  ActionPort: '<S541>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S538>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S538>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S538>/Hold Control' incorporates:
             *  ActionPort: '<S541>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S538>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S538>/Brake Control' incorporates:
             *  ActionPort: '<S540>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S538>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_cv != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S538>/Move Control' incorporates:
               *  ActionPort: '<S542>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S538>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S538>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S538>/Move Control' incorporates:
             *  ActionPort: '<S542>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S538>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S538>/Switch Case' */

          /* BusAssignment: '<S520>/Bus Assignment' incorporates:
           *  Constant: '<S520>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_bb;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_bd;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;

          /* Saturate: '<S538>/Saturation' */
          if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_h;
          }

          /* End of Saturate: '<S538>/Saturation' */

          /* Saturate: '<S550>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S550>/Saturation1' */

          /* Saturate: '<S528>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S520>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S528>/Saturation1' */
          /* End of Outputs for SubSystem: '<S226>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S226>/Unknown' incorporates:
           *  ActionPort: '<S524>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S226>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S226>/Switch Case' */
        /* End of Outputs for SubSystem: '<S36>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S36>/Auto' incorporates:
         *  ActionPort: '<S224>/Action Port'
         */
        /* SwitchCase: '<S224>/Switch Case' incorporates:
         *  Math: '<S404>/Square'
         *  Sum: '<S365>/Subtract'
         *  Sum: '<S419>/Sum1'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        switch (FMS_B.state) {
         case VehicleState_Offboard:
          FMS_DW.SwitchCase_ActiveSubsystem_f = 0;
          break;

         case VehicleState_Mission:
          FMS_DW.SwitchCase_ActiveSubsystem_f = 1;
          break;

         default:
          FMS_DW.SwitchCase_ActiveSubsystem_f = 2;
          break;
        }

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) &&
            (rtPrevAction == 1)) {
          /* Disable for Resettable SubSystem: '<S336>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S384>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

          /* Disable for SwitchCase: '<S374>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_af = -1;

          /* End of Disable for SubSystem: '<S336>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S224>/Offboard' incorporates:
           *  ActionPort: '<S337>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S498>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Multiply_l_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S501>/deg2rad' */
          rtb_Switch1_l4 = 0.017453292519943295 * rtb_Multiply_l_idx_0;

          /* Trigonometry: '<S502>/Sin' */
          rtb_Gain = sin(rtb_Switch1_l4);

          /* Math: '<S502>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S502>/Multiply1' incorporates:
           *  Product: '<S502>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S502>/Divide' incorporates:
           *  Constant: '<S502>/Constant'
           *  Constant: '<S502>/R'
           *  Sqrt: '<S502>/Sqrt'
           *  Sum: '<S502>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S502>/Product3' incorporates:
           *  Constant: '<S502>/Constant1'
           *  Product: '<S502>/Multiply1'
           *  Sum: '<S502>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S502>/Multiply2' incorporates:
           *  Trigonometry: '<S502>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_l4);

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S501>/Sum' incorporates:
           *  Gain: '<S498>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          rtb_Multiply_l_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_l_idx_0;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Abs: '<S506>/Abs' incorporates:
           *  Abs: '<S509>/Abs1'
           *  Switch: '<S506>/Switch1'
           */
          rtb_Switch1_l4 = fabs(rtb_Multiply_l_idx_0);

          /* Switch: '<S506>/Switch1' incorporates:
           *  Abs: '<S506>/Abs'
           *  Bias: '<S506>/Bias2'
           *  Bias: '<S506>/Bias3'
           *  Constant: '<S503>/Constant'
           *  Constant: '<S503>/Constant1'
           *  Constant: '<S508>/Constant'
           *  Gain: '<S506>/Gain1'
           *  Product: '<S506>/Multiply'
           *  RelationalOperator: '<S508>/Compare'
           *  Switch: '<S503>/Switch'
           */
          if (rtb_Switch1_l4 > 90.0) {
            /* Switch: '<S509>/Switch1' incorporates:
             *  Bias: '<S509>/Bias2'
             *  Bias: '<S509>/Bias3'
             *  Constant: '<S509>/Constant'
             *  Constant: '<S510>/Constant'
             *  Math: '<S509>/Math Function'
             *  RelationalOperator: '<S510>/Compare'
             */
            if (rtb_Switch1_l4 > 180.0) {
              rtb_Multiply_l_idx_0 = rt_modd(rtb_Multiply_l_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S509>/Switch1' */

            /* Signum: '<S506>/Sign' */
            if (rtb_Multiply_l_idx_0 < 0.0) {
              rtb_Multiply_l_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_l_idx_0 > 0.0) {
                rtb_Multiply_l_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S506>/Sign' */
            rtb_Multiply_l_idx_0 *= -(rtb_Switch1_l4 + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S503>/Sum' incorporates:
           *  Gain: '<S498>/Gain1'
           *  Gain: '<S498>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S501>/Sum'
           */
          rtb_Switch1_l4 = (1.0000000000287557E-7 * (real_T)
                            FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                            FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S501>/Multiply' incorporates:
           *  Gain: '<S501>/deg2rad1'
           */
          rtb_Multiply_l_idx_0 = 0.017453292519943295 * rtb_Multiply_l_idx_0 *
            rtb_Sum3;

          /* Switch: '<S505>/Switch1' incorporates:
           *  Abs: '<S505>/Abs1'
           *  Bias: '<S505>/Bias2'
           *  Bias: '<S505>/Bias3'
           *  Constant: '<S505>/Constant'
           *  Constant: '<S507>/Constant'
           *  Math: '<S505>/Math Function'
           *  RelationalOperator: '<S507>/Compare'
           */
          if (fabs(rtb_Switch1_l4) > 180.0) {
            rtb_Switch1_l4 = rt_modd(rtb_Switch1_l4 + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S505>/Switch1' */

          /* Product: '<S501>/Multiply' incorporates:
           *  Gain: '<S501>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_l4;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MultiPortSwitch: '<S479>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S483>/Multiply1'
           *  Product: '<S484>/Multiply3'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S492>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S492>/Constant4'
             */
            rtb_VectorConcatenate_ph[5] = 0.0F;

            /* Trigonometry: '<S492>/Trigonometric Function3' incorporates:
             *  Gain: '<S491>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S492>/Gain' incorporates:
             *  Gain: '<S491>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S492>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ph[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S492>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S492>/Constant3'
             */
            rtb_VectorConcatenate_ph[2] = 0.0F;

            /* Trigonometry: '<S492>/Trigonometric Function' incorporates:
             *  Gain: '<S491>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S492>/Trigonometric Function1' incorporates:
             *  Gain: '<S491>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S492>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_e[0];

            /* Saturate: '<S483>/Saturation' incorporates:
             *  Constant: '<S489>/Constant'
             *  Constant: '<S490>/Constant'
             *  Constant: '<S500>/Constant'
             *  DataTypeConversion: '<S498>/Data Type Conversion1'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S482>/Logical Operator'
             *  Product: '<S483>/Multiply'
             *  Product: '<S504>/Multiply1'
             *  Product: '<S504>/Multiply2'
             *  RelationalOperator: '<S489>/Compare'
             *  RelationalOperator: '<S490>/Compare'
             *  RelationalOperator: '<S500>/Compare'
             *  S-Function (sfix_bitop): '<S482>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S482>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S497>/lat_cmd valid'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S483>/Sum1'
             *  Sum: '<S504>/Sum2'
             *  Switch: '<S485>/Switch'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_a_o = (real32_T)(rtb_Multiply_l_idx_0 * FMS_ConstB.SinCos_o2 +
                                   rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_a_o = FMS_U.Auto_Cmd.x_cmd;
            }

            rtb_Switch_n_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_a_o -
              FMS_U.INS_Out.x_R : 0.0F;
            if (rtb_Switch_n_idx_1 > 4.0F) {
              rtb_Switch_n_idx_1 = 4.0F;
            } else {
              if (rtb_Switch_n_idx_1 < -4.0F) {
                rtb_Switch_n_idx_1 = -4.0F;
              }
            }

            /* SignalConversion: '<S492>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_e[1];

            /* Saturate: '<S483>/Saturation' incorporates:
             *  Constant: '<S489>/Constant'
             *  Constant: '<S490>/Constant'
             *  Constant: '<S500>/Constant'
             *  DataTypeConversion: '<S498>/Data Type Conversion1'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S482>/Logical Operator'
             *  Product: '<S483>/Multiply'
             *  Product: '<S504>/Multiply3'
             *  Product: '<S504>/Multiply4'
             *  RelationalOperator: '<S489>/Compare'
             *  RelationalOperator: '<S490>/Compare'
             *  RelationalOperator: '<S500>/Compare'
             *  S-Function (sfix_bitop): '<S482>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S482>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S497>/lon_cmd valid'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S483>/Sum1'
             *  Sum: '<S504>/Sum3'
             *  Switch: '<S485>/Switch'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_a_o = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                                   rtb_Multiply_l_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_a_o = FMS_U.Auto_Cmd.y_cmd;
            }

            rtb_Add3_a = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_a_o -
              FMS_U.INS_Out.y_R : 0.0F;
            if (rtb_Add3_a > 4.0F) {
              rtb_Add3_a = 4.0F;
            } else {
              if (rtb_Add3_a < -4.0F) {
                rtb_Add3_a = -4.0F;
              }
            }

            /* SignalConversion: '<S492>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_e[2];

            /* Saturate: '<S483>/Saturation' incorporates:
             *  Constant: '<S489>/Constant'
             *  Constant: '<S490>/Constant'
             *  Constant: '<S500>/Constant'
             *  DataTypeConversion: '<S498>/Data Type Conversion'
             *  DataTypeConversion: '<S498>/Data Type Conversion1'
             *  Gain: '<S486>/Gain'
             *  Gain: '<S498>/Gain2'
             *  Gain: '<S501>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S482>/Logical Operator'
             *  Product: '<S483>/Multiply'
             *  RelationalOperator: '<S489>/Compare'
             *  RelationalOperator: '<S490>/Compare'
             *  RelationalOperator: '<S500>/Compare'
             *  S-Function (sfix_bitop): '<S482>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S482>/z_cmd valid'
             *  S-Function (sfix_bitop): '<S497>/alt_cmd valid'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S483>/Sum1'
             *  Sum: '<S501>/Sum1'
             *  Switch: '<S485>/Switch'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_a_o = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                                    -FMS_U.INS_Out.alt_0);
            } else {
              rtb_a_o = FMS_U.Auto_Cmd.z_cmd;
            }

            rtb_Subtract3_e = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_a_o -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            if (rtb_Subtract3_e > 2.0F) {
              rtb_Subtract3_e = 2.0F;
            } else {
              if (rtb_Subtract3_e < -2.0F) {
                rtb_Subtract3_e = -2.0F;
              }
            }

            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_kx[rtb_n] = rtb_VectorConcatenate_ph[rtb_n + 6] *
                rtb_Subtract3_e + (rtb_VectorConcatenate_ph[rtb_n + 3] *
                                   rtb_Add3_a + rtb_VectorConcatenate_ph[rtb_n] *
                                   rtb_Switch_n_idx_1);
            }

            /* SignalConversion: '<S426>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S426>/Constant4'
             *  MultiPortSwitch: '<S416>/Index Vector'
             *  Product: '<S483>/Multiply1'
             */
            rtb_VectorConcatenate_ph[5] = 0.0F;

            /* Trigonometry: '<S426>/Trigonometric Function3' incorporates:
             *  Gain: '<S425>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S416>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S426>/Gain' incorporates:
             *  Gain: '<S425>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S416>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S426>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ph[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S426>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S426>/Constant3'
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[2] = 0.0F;

            /* Trigonometry: '<S426>/Trigonometric Function' incorporates:
             *  Gain: '<S425>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S416>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S426>/Trigonometric Function1' incorporates:
             *  Gain: '<S425>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S416>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S426>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_l[0];

            /* Product: '<S416>/Multiply' incorporates:
             *  Constant: '<S424>/Constant'
             *  RelationalOperator: '<S424>/Compare'
             *  S-Function (sfix_bitop): '<S421>/ax_cmd valid'
             */
            rtb_Subtract3_e = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S426>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_l[1];

            /* Product: '<S416>/Multiply' incorporates:
             *  Constant: '<S424>/Constant'
             *  RelationalOperator: '<S424>/Compare'
             *  S-Function (sfix_bitop): '<S421>/ay_cmd valid'
             */
            rtb_a_o = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S426>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_l[2];

            /* Product: '<S416>/Multiply' incorporates:
             *  Constant: '<S424>/Constant'
             *  RelationalOperator: '<S424>/Compare'
             *  S-Function (sfix_bitop): '<S421>/az_cmd valid'
             */
            rtb_P_p_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S416>/Index Vector' incorporates:
             *  Product: '<S422>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMath_l[rtb_n] =
                rtb_VectorConcatenate_ph[rtb_n + 6] * rtb_P_p_idx_0 +
                (rtb_VectorConcatenate_ph[rtb_n + 3] * rtb_a_o +
                 rtb_VectorConcatenate_ph[rtb_n] * rtb_Subtract3_e);
            }
            break;

           case 1:
            /* SignalConversion: '<S496>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S496>/Constant4'
             */
            rtb_VectorConcatenate_ph[5] = 0.0F;

            /* Gain: '<S494>/Gain' incorporates:
             *  Gain: '<S427>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S416>/Index Vector'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S484>/Subtract'
             */
            rtb_Add3_a = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

            /* Trigonometry: '<S496>/Trigonometric Function3' incorporates:
             *  Gain: '<S494>/Gain'
             *  Trigonometry: '<S496>/Trigonometric Function1'
             */
            rtb_Subtract3_e = arm_cos_f32(rtb_Add3_a);
            rtb_VectorConcatenate_ph[4] = rtb_Subtract3_e;

            /* Trigonometry: '<S496>/Trigonometric Function2' incorporates:
             *  Gain: '<S494>/Gain'
             *  Trigonometry: '<S496>/Trigonometric Function'
             */
            rtb_a_o = arm_sin_f32(rtb_Add3_a);

            /* Gain: '<S496>/Gain' incorporates:
             *  Trigonometry: '<S496>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ph[3] = -rtb_a_o;

            /* SignalConversion: '<S496>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S496>/Constant3'
             */
            rtb_VectorConcatenate_ph[2] = 0.0F;

            /* Trigonometry: '<S496>/Trigonometric Function' */
            rtb_VectorConcatenate_ph[1] = rtb_a_o;

            /* Trigonometry: '<S496>/Trigonometric Function1' */
            rtb_VectorConcatenate_ph[0] = rtb_Subtract3_e;

            /* SignalConversion: '<S496>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_n[0];

            /* SignalConversion: '<S495>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_c[6] = FMS_ConstB.VectorConcatenate3_p[0];

            /* SignalConversion: '<S496>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_n[1];

            /* SignalConversion: '<S495>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_c[7] = FMS_ConstB.VectorConcatenate3_p[1];

            /* SignalConversion: '<S496>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_n[2];

            /* SignalConversion: '<S495>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_c[8] = FMS_ConstB.VectorConcatenate3_p[2];

            /* SignalConversion: '<S495>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S495>/Constant4'
             */
            rtb_VectorConcatenate_c[5] = 0.0F;

            /* Trigonometry: '<S495>/Trigonometric Function3' incorporates:
             *  Gain: '<S493>/Gain'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Trigonometry: '<S495>/Trigonometric Function1'
             */
            rtb_Subtract3_e = arm_cos_f32(-FMS_B.Cmd_In.offboard_psi_0);
            rtb_VectorConcatenate_c[4] = rtb_Subtract3_e;

            /* Trigonometry: '<S495>/Trigonometric Function2' incorporates:
             *  Gain: '<S493>/Gain'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Trigonometry: '<S495>/Trigonometric Function'
             */
            rtb_a_o = arm_sin_f32(-FMS_B.Cmd_In.offboard_psi_0);

            /* Gain: '<S495>/Gain' incorporates:
             *  Trigonometry: '<S495>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_c[3] = -rtb_a_o;

            /* SignalConversion: '<S495>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S495>/Constant3'
             */
            rtb_VectorConcatenate_c[2] = 0.0F;

            /* Trigonometry: '<S495>/Trigonometric Function' */
            rtb_VectorConcatenate_c[1] = rtb_a_o;

            /* Trigonometry: '<S495>/Trigonometric Function1' */
            rtb_VectorConcatenate_c[0] = rtb_Subtract3_e;

            /* RelationalOperator: '<S500>/Compare' incorporates:
             *  Constant: '<S500>/Constant'
             *  S-Function (sfix_bitop): '<S497>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S497>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S497>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S498>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S498>/Data Type Conversion'
             *  Gain: '<S498>/Gain2'
             *  Gain: '<S501>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S504>/Multiply1'
             *  Product: '<S504>/Multiply2'
             *  Product: '<S504>/Multiply3'
             *  Product: '<S504>/Multiply4'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S501>/Sum1'
             *  Sum: '<S504>/Sum2'
             *  Sum: '<S504>/Sum3'
             */
            rtb_VectorConcatenate_bq[0] = (real32_T)(rtb_Multiply_l_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_VectorConcatenate_bq[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_l_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_VectorConcatenate_bq[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S485>/Switch' */
            tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
            tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
            tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* RelationalOperator: '<S489>/Compare' incorporates:
             *  Constant: '<S489>/Constant'
             *  S-Function (sfix_bitop): '<S482>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S482>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S482>/z_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S490>/Compare' incorporates:
             *  Constant: '<S490>/Constant'
             *  S-Function (sfix_bitop): '<S482>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S482>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S482>/lon_cmd valid'
             */
            tmp_2[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_2[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_2[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S484>/Sum2' incorporates:
               *  Product: '<S484>/Multiply2'
               *  Switch: '<S485>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_a_o = rtb_VectorConcatenate_bq[rtb_n];
              } else {
                rtb_a_o = tmp_0[rtb_n];
              }

              /* Saturate: '<S484>/Saturation1' incorporates:
               *  Gain: '<S486>/Gain'
               *  Inport: '<Root>/INS_Out'
               *  Logic: '<S482>/Logical Operator'
               *  Product: '<S484>/Multiply'
               *  Product: '<S484>/Multiply2'
               *  SignalConversion: '<S30>/Signal Copy1'
               *  Sum: '<S484>/Sum2'
               */
              rtb_Switch_n_idx_1 = tmp_1[rtb_n] || tmp_2[rtb_n] ? rtb_a_o -
                ((rtb_VectorConcatenate_c[rtb_n + 3] * FMS_U.INS_Out.y_R +
                  rtb_VectorConcatenate_c[rtb_n] * FMS_U.INS_Out.x_R) +
                 rtb_VectorConcatenate_c[rtb_n + 6] * -FMS_U.INS_Out.h_R) : 0.0F;
              if (rtb_Switch_n_idx_1 > FMS_ConstP.pooled35[rtb_n]) {
                rtb_TmpSignalConversionAtMath_l[rtb_n] =
                  FMS_ConstP.pooled35[rtb_n];
              } else if (rtb_Switch_n_idx_1 < FMS_ConstP.pooled36[rtb_n]) {
                rtb_TmpSignalConversionAtMath_l[rtb_n] =
                  FMS_ConstP.pooled36[rtb_n];
              } else {
                rtb_TmpSignalConversionAtMath_l[rtb_n] = rtb_Switch_n_idx_1;
              }

              /* End of Saturate: '<S484>/Saturation1' */
            }

            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_kx[rtb_n] = rtb_VectorConcatenate_ph[rtb_n + 6] *
                rtb_TmpSignalConversionAtMath_l[2] +
                (rtb_VectorConcatenate_ph[rtb_n + 3] *
                 rtb_TmpSignalConversionAtMath_l[1] +
                 rtb_VectorConcatenate_ph[rtb_n] *
                 rtb_TmpSignalConversionAtMath_l[0]);
            }

            /* SignalConversion: '<S428>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S428>/Constant4'
             *  MultiPortSwitch: '<S416>/Index Vector'
             *  Product: '<S484>/Multiply3'
             */
            rtb_VectorConcatenate_ph[5] = 0.0F;

            /* Trigonometry: '<S428>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[4] = arm_cos_f32(rtb_Add3_a);

            /* Gain: '<S428>/Gain' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             *  Trigonometry: '<S428>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ph[3] = -arm_sin_f32(rtb_Add3_a);

            /* SignalConversion: '<S428>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S428>/Constant3'
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[2] = 0.0F;

            /* Trigonometry: '<S428>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[1] = arm_sin_f32(rtb_Add3_a);

            /* Trigonometry: '<S428>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[0] = arm_cos_f32(rtb_Add3_a);

            /* SignalConversion: '<S428>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Product: '<S416>/Multiply' incorporates:
             *  Constant: '<S424>/Constant'
             *  RelationalOperator: '<S424>/Compare'
             *  S-Function (sfix_bitop): '<S421>/ax_cmd valid'
             */
            rtb_Subtract3_e = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S428>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Product: '<S416>/Multiply' incorporates:
             *  Constant: '<S424>/Constant'
             *  RelationalOperator: '<S424>/Compare'
             *  S-Function (sfix_bitop): '<S421>/ay_cmd valid'
             */
            rtb_a_o = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S428>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S416>/Index Vector'
             */
            rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Product: '<S416>/Multiply' incorporates:
             *  Constant: '<S424>/Constant'
             *  RelationalOperator: '<S424>/Compare'
             *  S-Function (sfix_bitop): '<S421>/az_cmd valid'
             */
            rtb_P_p_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S416>/Index Vector' incorporates:
             *  Product: '<S423>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_TmpSignalConversionAtMath_l[rtb_n] =
                rtb_VectorConcatenate_ph[rtb_n + 6] * rtb_P_p_idx_0 +
                (rtb_VectorConcatenate_ph[rtb_n + 3] * rtb_a_o +
                 rtb_VectorConcatenate_ph[rtb_n] * rtb_Subtract3_e);
            }
            break;

           default:
            /* SignalConversion: '<S488>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_a[0];
            rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_a[1];
            rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_a[2];

            /* SignalConversion: '<S488>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S488>/Constant4'
             */
            rtb_VectorConcatenate_ph[5] = 0.0F;

            /* Trigonometry: '<S488>/Trigonometric Function3' incorporates:
             *  Gain: '<S487>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S488>/Gain' incorporates:
             *  Gain: '<S487>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S488>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ph[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S488>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S488>/Constant3'
             */
            rtb_VectorConcatenate_ph[2] = 0.0F;

            /* Trigonometry: '<S488>/Trigonometric Function' incorporates:
             *  Gain: '<S487>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S488>/Trigonometric Function1' incorporates:
             *  Gain: '<S487>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* S-Function (sfix_bitop): '<S497>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S482>/lat_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S500>/Compare' incorporates:
             *  Constant: '<S500>/Constant'
             *  S-Function (sfix_bitop): '<S497>/lat_cmd valid'
             */
            tmp[0] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S497>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S482>/lon_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S500>/Compare' incorporates:
             *  Constant: '<S500>/Constant'
             *  S-Function (sfix_bitop): '<S497>/lon_cmd valid'
             */
            tmp[1] = (tmp_4 > 0U);

            /* S-Function (sfix_bitop): '<S497>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S482>/alt_cmd valid'
             */
            tmp_5 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S500>/Compare' incorporates:
             *  Constant: '<S500>/Constant'
             *  S-Function (sfix_bitop): '<S497>/alt_cmd valid'
             */
            tmp[2] = (tmp_5 > 0U);

            /* DataTypeConversion: '<S498>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S498>/Data Type Conversion'
             *  Gain: '<S498>/Gain2'
             *  Gain: '<S501>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S504>/Multiply1'
             *  Product: '<S504>/Multiply2'
             *  Product: '<S504>/Multiply3'
             *  Product: '<S504>/Multiply4'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S501>/Sum1'
             *  Sum: '<S504>/Sum2'
             *  Sum: '<S504>/Sum3'
             */
            rtb_VectorConcatenate_bq[0] = (real32_T)(rtb_Multiply_l_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_VectorConcatenate_bq[1] = (real32_T)(rtb_Gain *
              FMS_ConstB.SinCos_o2 - rtb_Multiply_l_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_VectorConcatenate_bq[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S485>/Switch' */
            tmp_0[0] = FMS_U.Auto_Cmd.x_cmd;
            tmp_0[1] = FMS_U.Auto_Cmd.y_cmd;
            tmp_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* RelationalOperator: '<S489>/Compare' incorporates:
             *  Constant: '<S489>/Constant'
             *  S-Function (sfix_bitop): '<S482>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S482>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S482>/z_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S490>/Compare' incorporates:
             *  Constant: '<S490>/Constant'
             */
            tmp_2[0] = (tmp_3 > 0U);
            tmp_2[1] = (tmp_4 > 0U);
            tmp_2[2] = (tmp_5 > 0U);

            /* Sum: '<S481>/Sum2' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S485>/Switch' incorporates:
               *  Product: '<S481>/Multiply2'
               */
              if (tmp[rtb_n]) {
                rtb_a_o = rtb_VectorConcatenate_bq[rtb_n];
              } else {
                rtb_a_o = tmp_0[rtb_n];
              }

              /* Saturate: '<S481>/Saturation1' incorporates:
               *  Gain: '<S486>/Gain'
               *  Inport: '<Root>/INS_Out'
               *  Logic: '<S482>/Logical Operator'
               *  Product: '<S481>/Multiply'
               *  Product: '<S481>/Multiply2'
               *  SignalConversion: '<S30>/Signal Copy1'
               */
              rtb_Switch_n_idx_1 = tmp_1[rtb_n] || tmp_2[rtb_n] ? rtb_a_o -
                ((rtb_VectorConcatenate_ph[rtb_n + 3] * FMS_U.INS_Out.y_R +
                  rtb_VectorConcatenate_ph[rtb_n] * FMS_U.INS_Out.x_R) +
                 rtb_VectorConcatenate_ph[rtb_n + 6] * -FMS_U.INS_Out.h_R) :
                0.0F;
              if (rtb_Switch_n_idx_1 > FMS_ConstP.pooled35[rtb_n]) {
                rtb_Switch_kx[rtb_n] = FMS_ConstP.pooled35[rtb_n];
              } else if (rtb_Switch_n_idx_1 < FMS_ConstP.pooled36[rtb_n]) {
                rtb_Switch_kx[rtb_n] = FMS_ConstP.pooled36[rtb_n];
              } else {
                rtb_Switch_kx[rtb_n] = rtb_Switch_n_idx_1;
              }

              /* End of Saturate: '<S481>/Saturation1' */
            }

            /* End of Sum: '<S481>/Sum2' */

            /* MultiPortSwitch: '<S416>/Index Vector' incorporates:
             *  Constant: '<S424>/Constant'
             *  Product: '<S416>/Multiply'
             *  RelationalOperator: '<S424>/Compare'
             *  S-Function (sfix_bitop): '<S421>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S421>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S421>/az_cmd valid'
             */
            rtb_TmpSignalConversionAtMath_l[0] = (FMS_U.Auto_Cmd.cmd_mask &
              65536U) > 0U ? FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_TmpSignalConversionAtMath_l[1] = (FMS_U.Auto_Cmd.cmd_mask &
              131072U) > 0U ? FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_TmpSignalConversionAtMath_l[2] = (FMS_U.Auto_Cmd.cmd_mask &
              262144U) > 0U ? FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S479>/Index Vector' */

          /* Sum: '<S475>/Sum1' incorporates:
           *  Constant: '<S475>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S475>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Sqrt_h = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Abs: '<S476>/Abs' */
          rtb_Add3_a = fabsf(rtb_Sqrt_h);

          /* Switch: '<S476>/Switch' incorporates:
           *  Constant: '<S476>/Constant'
           *  Constant: '<S477>/Constant'
           *  Product: '<S476>/Multiply'
           *  RelationalOperator: '<S477>/Compare'
           *  Sum: '<S476>/Subtract'
           */
          if (rtb_Add3_a > 3.14159274F) {
            /* Signum: '<S476>/Sign' */
            if (rtb_Sqrt_h < 0.0F) {
              rtb_Sqrt_h = -1.0F;
            } else {
              if (rtb_Sqrt_h > 0.0F) {
                rtb_Sqrt_h = 1.0F;
              }
            }

            /* End of Signum: '<S476>/Sign' */
            rtb_Sqrt_h *= rtb_Add3_a - 6.28318548F;
          }

          /* End of Switch: '<S476>/Switch' */

          /* Saturate: '<S475>/Saturation' */
          if (rtb_Sqrt_h > 0.314159274F) {
            rtb_Sqrt_h = 0.314159274F;
          } else {
            if (rtb_Sqrt_h < -0.314159274F) {
              rtb_Sqrt_h = -0.314159274F;
            }
          }

          /* End of Saturate: '<S475>/Saturation' */

          /* Gain: '<S472>/Gain2' */
          rtb_Sqrt_h *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S418>/Sum' incorporates:
           *  Constant: '<S474>/Constant'
           *  Constant: '<S478>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S472>/Multiply2'
           *  Product: '<S473>/Multiply1'
           *  RelationalOperator: '<S474>/Compare'
           *  RelationalOperator: '<S478>/Compare'
           *  S-Function (sfix_bitop): '<S472>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S473>/psi_rate_cmd valid'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          rtb_Switch_n_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                                rtb_Sqrt_h : 0.0F) + ((FMS_U.Auto_Cmd.cmd_mask &
            64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd : 0.0F);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S479>/Gain1' */
          rtb_Add3_a = FMS_PARAM.XY_P * rtb_Switch_kx[0];
          rtb_Add4_o = FMS_PARAM.XY_P * rtb_Switch_kx[1];

          /* Gain: '<S479>/Gain2' */
          rtb_Sqrt_h = FMS_PARAM.Z_P * rtb_Switch_kx[2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MultiPortSwitch: '<S480>/Index Vector' incorporates:
           *  Constant: '<S515>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S480>/Multiply'
           *  Product: '<S513>/Multiply'
           *  Product: '<S514>/Multiply3'
           *  RelationalOperator: '<S515>/Compare'
           *  S-Function (sfix_bitop): '<S512>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S512>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S512>/w_cmd valid'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S517>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S517>/Constant4'
             */
            rtb_VectorConcatenate_ph[5] = 0.0F;

            /* Trigonometry: '<S517>/Trigonometric Function3' incorporates:
             *  Gain: '<S516>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S517>/Gain' incorporates:
             *  Gain: '<S516>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S517>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ph[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S517>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S517>/Constant3'
             */
            rtb_VectorConcatenate_ph[2] = 0.0F;

            /* Trigonometry: '<S517>/Trigonometric Function' incorporates:
             *  Gain: '<S516>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S517>/Trigonometric Function1' incorporates:
             *  Gain: '<S516>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_ph[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S517>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_h[0];

            /* Product: '<S480>/Multiply' incorporates:
             *  Constant: '<S515>/Constant'
             *  RelationalOperator: '<S515>/Compare'
             *  S-Function (sfix_bitop): '<S512>/u_cmd valid'
             */
            rtb_Subtract3_e = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S517>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_h[1];

            /* Product: '<S480>/Multiply' incorporates:
             *  Constant: '<S515>/Constant'
             *  RelationalOperator: '<S515>/Compare'
             *  S-Function (sfix_bitop): '<S512>/v_cmd valid'
             */
            rtb_a_o = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S517>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_h[2];

            /* Product: '<S480>/Multiply' incorporates:
             *  Constant: '<S515>/Constant'
             *  RelationalOperator: '<S515>/Compare'
             *  S-Function (sfix_bitop): '<S512>/w_cmd valid'
             */
            rtb_P_p_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_kx[rtb_n] = rtb_VectorConcatenate_ph[rtb_n + 6] *
                rtb_P_p_idx_0 + (rtb_VectorConcatenate_ph[rtb_n + 3] * rtb_a_o +
                                 rtb_VectorConcatenate_ph[rtb_n] *
                                 rtb_Subtract3_e);
            }
            break;

           case 1:
            /* SignalConversion: '<S519>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S519>/Constant4'
             */
            rtb_VectorConcatenate_ph[5] = 0.0F;

            /* Gain: '<S518>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S514>/Subtract'
             */
            rtb_Subtract3_e = -(FMS_U.INS_Out.psi - FMS_B.Cmd_In.offboard_psi_0);

            /* Trigonometry: '<S519>/Trigonometric Function3' incorporates:
             *  Gain: '<S518>/Gain'
             */
            rtb_VectorConcatenate_ph[4] = arm_cos_f32(rtb_Subtract3_e);

            /* Gain: '<S519>/Gain' incorporates:
             *  Gain: '<S518>/Gain'
             *  Trigonometry: '<S519>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ph[3] = -arm_sin_f32(rtb_Subtract3_e);

            /* SignalConversion: '<S519>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S519>/Constant3'
             */
            rtb_VectorConcatenate_ph[2] = 0.0F;

            /* Trigonometry: '<S519>/Trigonometric Function' incorporates:
             *  Gain: '<S518>/Gain'
             */
            rtb_VectorConcatenate_ph[1] = arm_sin_f32(rtb_Subtract3_e);

            /* Trigonometry: '<S519>/Trigonometric Function1' incorporates:
             *  Gain: '<S518>/Gain'
             */
            rtb_VectorConcatenate_ph[0] = arm_cos_f32(rtb_Subtract3_e);

            /* SignalConversion: '<S519>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_gr[0];

            /* Product: '<S480>/Multiply' incorporates:
             *  Constant: '<S515>/Constant'
             *  RelationalOperator: '<S515>/Compare'
             *  S-Function (sfix_bitop): '<S512>/u_cmd valid'
             */
            rtb_Subtract3_e = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S519>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_gr[1];

            /* Product: '<S480>/Multiply' incorporates:
             *  Constant: '<S515>/Constant'
             *  RelationalOperator: '<S515>/Compare'
             *  S-Function (sfix_bitop): '<S512>/v_cmd valid'
             */
            rtb_a_o = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S519>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_gr[2];

            /* Product: '<S480>/Multiply' incorporates:
             *  Constant: '<S515>/Constant'
             *  RelationalOperator: '<S515>/Compare'
             *  S-Function (sfix_bitop): '<S512>/w_cmd valid'
             */
            rtb_P_p_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_kx[rtb_n] = rtb_VectorConcatenate_ph[rtb_n + 6] *
                rtb_P_p_idx_0 + (rtb_VectorConcatenate_ph[rtb_n + 3] * rtb_a_o +
                                 rtb_VectorConcatenate_ph[rtb_n] *
                                 rtb_Subtract3_e);
            }
            break;

           default:
            rtb_Switch_kx[0] = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;
            rtb_Switch_kx[1] = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;
            rtb_Switch_kx[2] = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S480>/Index Vector' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_Switch_kx[0] += rtb_Add3_a;
          rtb_Switch_kx[1] += rtb_Add4_o;

          /* Sum: '<S419>/Sum1' */
          rtb_Add3_a = rtb_Sqrt_h + rtb_Switch_kx[2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S436>/Switch' incorporates:
           *  Constant: '<S451>/Constant'
           *  Constant: '<S452>/Constant'
           *  Constant: '<S453>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S451>/Compare'
           *  RelationalOperator: '<S452>/Compare'
           *  RelationalOperator: '<S453>/Compare'
           *  S-Function (sfix_bitop): '<S436>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S436>/y_v_cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S436>/Logical Operator' incorporates:
             *  Constant: '<S452>/Constant'
             *  Constant: '<S453>/Constant'
             *  RelationalOperator: '<S452>/Compare'
             *  RelationalOperator: '<S453>/Compare'
             *  S-Function (sfix_bitop): '<S436>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S436>/y_v_cmd'
             */
            rtb_LogicalOperator_fl = (((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_fl;
          } else {
            rtb_LogicalOperator_fl = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U)
              > 0U);
          }

          /* End of Switch: '<S436>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S417>/u_cmd_valid' */
          /* MATLAB Function: '<S448>/bit_shift' incorporates:
           *  DataTypeConversion: '<S417>/Data Type Conversion6'
           */
          rtb_y_o = (uint16_T)(rtb_LogicalOperator_fl << 6);

          /* End of Outputs for SubSystem: '<S417>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S417>/v_cmd_valid' */
          /* MATLAB Function: '<S449>/bit_shift' incorporates:
           *  DataTypeConversion: '<S417>/Data Type Conversion7'
           */
          rtb_y_b = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

          /* End of Outputs for SubSystem: '<S417>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S437>/Switch' incorporates:
           *  Constant: '<S455>/Constant'
           *  Constant: '<S456>/Constant'
           *  Constant: '<S458>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S455>/Compare'
           *  RelationalOperator: '<S456>/Compare'
           *  RelationalOperator: '<S458>/Compare'
           *  S-Function (sfix_bitop): '<S437>/ax_cmd'
           *  S-Function (sfix_bitop): '<S437>/ay_cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S437>/Logical Operator' incorporates:
             *  Constant: '<S456>/Constant'
             *  Constant: '<S458>/Constant'
             *  RelationalOperator: '<S456>/Compare'
             *  RelationalOperator: '<S458>/Compare'
             *  S-Function (sfix_bitop): '<S437>/ax_cmd'
             *  S-Function (sfix_bitop): '<S437>/ay_cmd'
             */
            rtb_LogicalOperator_fl = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_LogicalOperator_fl;
          } else {
            rtb_LogicalOperator_fl = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S437>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S337>/Bus Assignment' incorporates:
           *  Constant: '<S337>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_jr;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dg;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_l;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_Y.FMS_Out.p_cmd = FMS_U.Auto_Cmd.p_cmd;
          FMS_Y.FMS_Out.q_cmd = FMS_U.Auto_Cmd.q_cmd;
          FMS_Y.FMS_Out.r_cmd = FMS_U.Auto_Cmd.r_cmd;
          FMS_Y.FMS_Out.phi_cmd = FMS_U.Auto_Cmd.phi_cmd;
          FMS_Y.FMS_Out.theta_cmd = FMS_U.Auto_Cmd.theta_cmd;
          FMS_Y.FMS_Out.throttle_cmd = FMS_U.Auto_Cmd.throttle_cmd;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          FMS_Y.FMS_Out.ax_cmd = rtb_TmpSignalConversionAtMath_l[0];
          FMS_Y.FMS_Out.ay_cmd = rtb_TmpSignalConversionAtMath_l[1];
          FMS_Y.FMS_Out.az_cmd = rtb_TmpSignalConversionAtMath_l[2];

          /* Saturate: '<S418>/Saturation' */
          if (rtb_Switch_n_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_Switch_n_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_Switch_n_idx_1;
          }

          /* End of Saturate: '<S418>/Saturation' */

          /* Saturate: '<S419>/Saturation2' */
          if (rtb_Switch_kx[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_kx[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_kx[0];
          }

          /* End of Saturate: '<S419>/Saturation2' */

          /* Saturate: '<S419>/Saturation1' */
          if (rtb_Switch_kx[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_kx[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_kx[1];
          }

          /* End of Saturate: '<S419>/Saturation1' */

          /* Saturate: '<S419>/Saturation3' */
          if (rtb_Add3_a > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Add3_a < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S337>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Add3_a;
          }

          /* End of Saturate: '<S419>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S417>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S417>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S417>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S417>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S417>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S417>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S417>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S417>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S417>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S417>/throttle_cmd_valid' */
          /* BusAssignment: '<S337>/Bus Assignment' incorporates:
           *  Constant: '<S429>/Constant'
           *  Constant: '<S430>/Constant'
           *  Constant: '<S431>/Constant'
           *  Constant: '<S432>/Constant'
           *  Constant: '<S433>/Constant'
           *  Constant: '<S434>/Constant'
           *  Constant: '<S435>/Constant'
           *  Constant: '<S454>/Constant'
           *  Constant: '<S457>/Constant'
           *  DataTypeConversion: '<S417>/Data Type Conversion10'
           *  DataTypeConversion: '<S417>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S438>/bit_shift'
           *  MATLAB Function: '<S439>/bit_shift'
           *  MATLAB Function: '<S440>/bit_shift'
           *  MATLAB Function: '<S442>/bit_shift'
           *  MATLAB Function: '<S443>/bit_shift'
           *  MATLAB Function: '<S444>/bit_shift'
           *  MATLAB Function: '<S445>/bit_shift'
           *  MATLAB Function: '<S446>/bit_shift'
           *  MATLAB Function: '<S447>/bit_shift'
           *  MATLAB Function: '<S450>/bit_shift'
           *  RelationalOperator: '<S429>/Compare'
           *  RelationalOperator: '<S430>/Compare'
           *  RelationalOperator: '<S431>/Compare'
           *  RelationalOperator: '<S432>/Compare'
           *  RelationalOperator: '<S433>/Compare'
           *  RelationalOperator: '<S434>/Compare'
           *  RelationalOperator: '<S435>/Compare'
           *  RelationalOperator: '<S454>/Compare'
           *  RelationalOperator: '<S457>/Compare'
           *  S-Function (sfix_bitop): '<S417>/p_cmd'
           *  S-Function (sfix_bitop): '<S417>/phi_cmd'
           *  S-Function (sfix_bitop): '<S417>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S417>/q_cmd'
           *  S-Function (sfix_bitop): '<S417>/r_cmd'
           *  S-Function (sfix_bitop): '<S417>/theta_cmd'
           *  S-Function (sfix_bitop): '<S417>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S436>/z_w_cmd'
           *  S-Function (sfix_bitop): '<S437>/az_cmd'
           *  SignalConversion: '<S30>/Signal Copy'
           *  Sum: '<S417>/Add'
           */
          FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
            ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
             ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
            (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) + rtb_y_o) + rtb_y_b)
            + (((FMS_U.Auto_Cmd.cmd_mask & 33280U) > 0U) << 8)) +
            (rtb_LogicalOperator_fl << 9)) + (rtb_FixPtRelationalOperator_me <<
            10)) + (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

          /* End of Outputs for SubSystem: '<S417>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S417>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S417>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S417>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S417>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S417>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S417>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S417>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S417>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S417>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S224>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S224>/Mission' incorporates:
             *  ActionPort: '<S336>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S224>/Switch Case' incorporates:
             *  UnitDelay: '<S339>/Delay Input1'
             *
             * Block description for '<S339>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S224>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S224>/Mission' incorporates:
             *  ActionPort: '<S336>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S336>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S224>/Switch Case' incorporates:
             *  Chart: '<S375>/Motion Status'
             *  Chart: '<S385>/Motion State'
             *  Delay: '<S344>/Delay'
             *  Delay: '<S366>/Delay'
             *  DiscreteIntegrator: '<S347>/Integrator'
             *  DiscreteIntegrator: '<S347>/Integrator1'
             *  DiscreteIntegrator: '<S362>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S367>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S411>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_p = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;
            FMS_DW.l1_heading = 0.0F;
            FMS_DW.icLoad_mb = 1U;
            FMS_DW.Integrator1_IC_LOADING = 1U;
            FMS_DW.Integrator_DSTATE_m = 0.0F;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_h);

            /* End of SystemReset for SubSystem: '<S336>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S224>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S224>/Mission' incorporates:
           *  ActionPort: '<S336>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* RelationalOperator: '<S339>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S339>/Delay Input1'
           *
           * Block description for '<S339>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S336>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S340>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_p != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S384>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

            /* Disable for SwitchCase: '<S374>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_af = -1;

            /* InitializeConditions for Delay: '<S366>/Delay' */
            FMS_DW.icLoad_p = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S367>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S362>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S411>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S344>/Delay' */
            FMS_DW.icLoad_mb = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S347>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S347>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S385>/Motion State' */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S375>/Motion Status' */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_h);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_p =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S366>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_p != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_b[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_b[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S367>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S339>/Delay Input1'
           *
           * Block description for '<S339>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTATE_k;

          /* RelationalOperator: '<S361>/Compare' incorporates:
           *  Constant: '<S415>/Constant'
           *  RelationalOperator: '<S415>/Compare'
           *  UnitDelay: '<S339>/Delay Input1'
           *
           * Block description for '<S339>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Compare_ii = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S362>/Acceleration_Speed' */
          if (rtb_Compare_ii || (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          if (FMS_DW.Acceleration_Speed_DSTATE >= FMS_PARAM.CRUISE_SPEED) {
            FMS_DW.Acceleration_Speed_DSTATE = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (FMS_DW.Acceleration_Speed_DSTATE <= 0.0F) {
              FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            }
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S385>/Motion State' incorporates:
           *  Constant: '<S385>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S385>/Square'
           *  Math: '<S385>/Square1'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sqrt: '<S385>/Sqrt'
           *  Sum: '<S385>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_k0,
                          &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S384>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_c;
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          switch (rtb_state_k0) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_c = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_c = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_c = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_c) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S384>/Hold Control' incorporates:
               *  ActionPort: '<S387>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S384>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_fy);

              /* End of SystemReset for SubSystem: '<S384>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S384>/Hold Control' incorporates:
             *  ActionPort: '<S387>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_ls,
                              &FMS_ConstB.HoldControl_fy, &FMS_DW.HoldControl_fy);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S384>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S384>/Brake Control' incorporates:
             *  ActionPort: '<S386>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_ls);

            /* End of Outputs for SubSystem: '<S384>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S384>/Move Control' incorporates:
               *  ActionPort: '<S388>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S384>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_i);

              /* End of SystemReset for SubSystem: '<S384>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S384>/Move Control' incorporates:
             *  ActionPort: '<S388>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_ls,
                              &FMS_ConstB.MoveControl_i, &FMS_DW.MoveControl_i);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S384>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S384>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S375>/Motion Status' incorporates:
           *  Abs: '<S375>/Abs'
           *  Constant: '<S375>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_MotionStatus(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_k0,
                           &FMS_DW.sf_MotionStatus_h);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S374>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_af;
          FMS_DW.SwitchCase_ActiveSubsystem_af = -1;
          switch (rtb_state_k0) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_af = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_af = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_af = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_af) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_af != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S374>/Hold Control' incorporates:
               *  ActionPort: '<S377>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S374>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_b);

              /* End of SystemReset for SubSystem: '<S374>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S374>/Hold Control' incorporates:
             *  ActionPort: '<S377>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_i,
                            &FMS_DW.HoldControl_b);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S374>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S374>/Brake Control' incorporates:
             *  ActionPort: '<S376>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_i);

            /* End of Outputs for SubSystem: '<S374>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_af != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S374>/Move Control' incorporates:
               *  ActionPort: '<S378>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S374>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_c);

              /* End of SystemReset for SubSystem: '<S374>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S374>/Move Control' incorporates:
             *  ActionPort: '<S378>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_i,
                            &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S374>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S374>/Switch Case' */

          /* Switch: '<S342>/Switch' incorporates:
           *  Product: '<S366>/Multiply'
           *  Sum: '<S366>/Sum'
           */
          if (rtb_Compare_ii) {
            /* Saturate: '<S384>/Saturation1' */
            if (FMS_B.Merge_ls[0] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Add4_o = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_ls[0] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Add4_o = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Add4_o = FMS_B.Merge_ls[0];
            }

            if (FMS_B.Merge_ls[1] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_n_idx_1 = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_ls[1] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_n_idx_1 = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_n_idx_1 = FMS_B.Merge_ls[1];
            }

            /* End of Saturate: '<S384>/Saturation1' */

            /* Saturate: '<S374>/Saturation1' */
            if (FMS_B.Merge_i > FMS_PARAM.VEL_Z_LIM) {
              rtb_Sqrt_h = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_i < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Sqrt_h = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Sqrt_h = FMS_B.Merge_i;
            }

            /* End of Saturate: '<S374>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S366>/Sum' incorporates:
             *  Delay: '<S366>/Delay'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_n_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_b[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* SignalConversion: '<S412>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Add4_o = rtb_Switch_n_idx_1;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S362>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Subtract3_e = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Sum_k[0] = rtb_Switch_n_idx_1;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S366>/Sum' incorporates:
             *  Delay: '<S366>/Delay'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Switch_n_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_b[1];

            /* Sum: '<S362>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add3_a = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Sqrt: '<S371>/Sqrt' incorporates:
             *  Math: '<S371>/Square'
             *  Sum: '<S362>/Sum'
             *  Sum: '<S371>/Sum of Elements'
             */
            rtb_Add3_a = sqrtf(rtb_Subtract3_e * rtb_Subtract3_e + rtb_Add3_a *
                               rtb_Add3_a);

            /* SignalConversion: '<S414>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3_g[0];
            rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3_g[1];
            rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* SignalConversion: '<S414>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S414>/Constant4'
             */
            rtb_VectorConcatenate_ph[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Gain: '<S413>/Gain' incorporates:
             *  DiscreteIntegrator: '<S411>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S411>/Add'
             */
            rtb_Subtract3_e = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Trigonometry: '<S414>/Trigonometric Function3' */
            rtb_VectorConcatenate_ph[4] = arm_cos_f32(rtb_Subtract3_e);

            /* Gain: '<S414>/Gain' incorporates:
             *  Trigonometry: '<S414>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ph[3] = -arm_sin_f32(rtb_Subtract3_e);

            /* SignalConversion: '<S414>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S414>/Constant3'
             */
            rtb_VectorConcatenate_ph[2] = 0.0F;

            /* Trigonometry: '<S414>/Trigonometric Function' */
            rtb_VectorConcatenate_ph[1] = arm_sin_f32(rtb_Subtract3_e);

            /* Trigonometry: '<S414>/Trigonometric Function1' */
            rtb_VectorConcatenate_ph[0] = arm_cos_f32(rtb_Subtract3_e);

            /* Switch: '<S362>/Switch' incorporates:
             *  Constant: '<S362>/vel'
             */
            if (rtb_Add3_a > FMS_PARAM.L1) {
              rtb_Subtract3_e = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S362>/Gain' */
              rtb_Subtract3_e = 0.5F * rtb_Add3_a;

              /* Saturate: '<S362>/Saturation' */
              if (rtb_Subtract3_e > FMS_PARAM.CRUISE_SPEED) {
                rtb_Subtract3_e = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Subtract3_e < 0.5F) {
                  rtb_Subtract3_e = 0.5F;
                }
              }

              /* End of Saturate: '<S362>/Saturation' */
            }

            /* End of Switch: '<S362>/Switch' */

            /* Switch: '<S362>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S362>/Acceleration_Speed'
             *  Sum: '<S362>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE - rtb_Subtract3_e < 0.0F) {
              rtb_Subtract3_e = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S362>/Switch1' */

            /* Sum: '<S412>/Sum of Elements' incorporates:
             *  Math: '<S412>/Math Function'
             */
            rtb_a_o = rtb_Add4_o * rtb_Add4_o + rtb_Switch_n_idx_1 *
              rtb_Switch_n_idx_1;

            /* Math: '<S412>/Math Function1' incorporates:
             *  Sum: '<S412>/Sum of Elements'
             *
             * About '<S412>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_a_o < 0.0F) {
              rtb_a_o = -sqrtf(fabsf(rtb_a_o));
            } else {
              rtb_a_o = sqrtf(rtb_a_o);
            }

            /* End of Math: '<S412>/Math Function1' */

            /* Switch: '<S412>/Switch' incorporates:
             *  Constant: '<S412>/Constant'
             *  Product: '<S412>/Product'
             */
            if (rtb_a_o > 0.0F) {
              rtb_Add3_a = rtb_Sum_k[0];
            } else {
              rtb_Add3_a = 0.0F;
              rtb_Switch_n_idx_1 = 0.0F;
              rtb_a_o = 1.0F;
            }

            /* End of Switch: '<S412>/Switch' */

            /* Product: '<S410>/Multiply2' incorporates:
             *  Product: '<S412>/Divide'
             */
            rtb_Rem_n = rtb_Add3_a / rtb_a_o * rtb_Subtract3_e;
            B = rtb_Switch_n_idx_1 / rtb_a_o * rtb_Subtract3_e;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S368>/Sum1' incorporates:
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_P_p_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Sign5_fx = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S368>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add3_a = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Subtract3_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Product: '<S368>/Divide' incorporates:
             *  Math: '<S369>/Square'
             *  Math: '<S370>/Square'
             *  Sqrt: '<S369>/Sqrt'
             *  Sqrt: '<S370>/Sqrt'
             *  Sum: '<S368>/Sum'
             *  Sum: '<S368>/Sum1'
             *  Sum: '<S369>/Sum of Elements'
             *  Sum: '<S370>/Sum of Elements'
             */
            rtb_Subtract3_e = sqrtf(rtb_Add3_a * rtb_Add3_a + rtb_Subtract3_e *
              rtb_Subtract3_e) / sqrtf(rtb_P_p_idx_0 * rtb_P_p_idx_0 +
              rtb_Sign5_fx * rtb_Sign5_fx);

            /* Saturate: '<S368>/Saturation' */
            if (rtb_Subtract3_e > 1.0F) {
              rtb_Subtract3_e = 1.0F;
            } else {
              if (rtb_Subtract3_e < 0.0F) {
                rtb_Subtract3_e = 0.0F;
              }
            }

            /* End of Saturate: '<S368>/Saturation' */

            /* Product: '<S366>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_bq[rtb_n] = rtb_VectorConcatenate_ph[rtb_n +
                3] * B + rtb_VectorConcatenate_ph[rtb_n] * rtb_Rem_n;
            }

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Gain: '<S359>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S368>/Multiply'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S359>/Sum2'
             *  Sum: '<S368>/Add'
             *  Sum: '<S368>/Subtract'
             */
            rtb_Sqrt_h = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
              FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Subtract3_e +
              FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Add4_o = rtb_VectorConcatenate_bq[0];
            rtb_Switch_n_idx_1 = rtb_VectorConcatenate_bq[1];

            /* Saturate: '<S359>/Saturation1' incorporates:
             *  Product: '<S366>/Multiply'
             */
            if (rtb_Sqrt_h > FMS_PARAM.VEL_Z_LIM) {
              rtb_Sqrt_h = FMS_PARAM.VEL_Z_LIM;
            } else {
              if (rtb_Sqrt_h < -FMS_PARAM.VEL_Z_LIM) {
                rtb_Sqrt_h = -FMS_PARAM.VEL_Z_LIM;
              }
            }

            /* End of Saturate: '<S359>/Saturation1' */
          }

          /* End of Switch: '<S342>/Switch' */

          /* Delay: '<S344>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mb != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S347>/Integrator1' incorporates:
           *  Delay: '<S344>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mfw = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Math: '<S351>/Rem' incorporates:
           *  Constant: '<S351>/Constant1'
           *  DiscreteIntegrator: '<S347>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S346>/Sum'
           */
          rtb_Subtract3_e = rt_remf(FMS_DW.Integrator1_DSTATE_mfw -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S351>/Switch' incorporates:
           *  Abs: '<S351>/Abs'
           *  Constant: '<S351>/Constant'
           *  Constant: '<S352>/Constant'
           *  Product: '<S351>/Multiply'
           *  RelationalOperator: '<S352>/Compare'
           *  Sum: '<S351>/Add'
           */
          if (fabsf(rtb_Subtract3_e) > 3.14159274F) {
            /* Signum: '<S351>/Sign' */
            if (rtb_Subtract3_e < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else if (rtb_Subtract3_e > 0.0F) {
              rtb_Add3_a = 1.0F;
            } else {
              rtb_Add3_a = rtb_Subtract3_e;
            }

            /* End of Signum: '<S351>/Sign' */
            rtb_Subtract3_e -= 6.28318548F * rtb_Add3_a;
          }

          /* End of Switch: '<S351>/Switch' */

          /* Gain: '<S346>/Gain2' */
          rtb_Subtract3_e *= FMS_PARAM.YAW_P;

          /* Saturate: '<S346>/Saturation' */
          if (rtb_Subtract3_e > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Subtract3_e = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Subtract3_e < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Subtract3_e = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S346>/Saturation' */

          /* BusAssignment: '<S340>/Bus Assignment' incorporates:
           *  Constant: '<S340>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d3;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_d;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
          FMS_Y.FMS_Out.u_cmd = rtb_Add4_o;
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_n_idx_1;
          FMS_Y.FMS_Out.w_cmd = rtb_Sqrt_h;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Subtract3_e;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S405>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S405>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_a_o = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S405>/Math Function1' incorporates:
           *  Sum: '<S405>/Sum of Elements'
           *
           * About '<S405>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Subtract3_e = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Subtract3_e = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S405>/Math Function1' */

          /* Switch: '<S405>/Switch' incorporates:
           *  Constant: '<S405>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S405>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Subtract3_e > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Add4_o = FMS_U.INS_Out.vn;
            rtb_Switch_n_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Sqrt_h = rtb_Subtract3_e;
          } else {
            rtb_Add4_o = 0.0F;
            rtb_Switch_n_idx_1 = 0.0F;
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S405>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S340>/Sum' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          B = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_TmpSignalConversionAtDela_a[0] = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Rem_n = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
          rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S358>/Math Function' incorporates:
           *  Sum: '<S340>/Sum'
           */
          rtb_MathFunction_cx[0] = rtb_Rem_n * rtb_Rem_n;
          rtb_MathFunction_cx[1] = B * B;

          /* Sum: '<S358>/Sum of Elements' */
          rtb_a_o = rtb_MathFunction_cx[0] + rtb_MathFunction_cx[1];

          /* Math: '<S358>/Math Function1' incorporates:
           *  Sum: '<S358>/Sum of Elements'
           *
           * About '<S358>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Subtract3_e = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Subtract3_e = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S358>/Math Function1' */

          /* Switch: '<S358>/Switch' incorporates:
           *  Constant: '<S358>/Constant'
           *  Product: '<S358>/Product'
           */
          if (rtb_Subtract3_e > 0.0F) {
            rtb_Sign5_fx = rtb_Subtract3_e;
          } else {
            rtb_Rem_n = 0.0F;
            B = 0.0F;
            rtb_Sign5_fx = 1.0F;
          }

          /* End of Switch: '<S358>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S364>/NearbyRefWP' incorporates:
           *  Constant: '<S340>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_kx[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                          rtb_TmpSignalConversionAtDela_a, &rtb_a_o);

          /* MATLAB Function: '<S364>/SearchL1RefWP' incorporates:
           *  Constant: '<S340>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_TmpSignalConversionAtMath_l[0], &rtb_Switch_kx
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.L1, rtb_MathFunction_cx, &D);

          /* MATLAB Function: '<S364>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract3_e = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          u1_tmp = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Add3_a = ((FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1]) *
                        u1_tmp + (FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint
            [0]) * rtb_Subtract3_e) / (rtb_Subtract3_e * rtb_Subtract3_e +
            u1_tmp * u1_tmp);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_FixPtRelationalOperator_me = (rtb_Add3_a <= 0.0F);
          rtb_LogicalOperator_fl = (rtb_Add3_a >= 1.0F);
          if (rtb_FixPtRelationalOperator_me) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_P_p_idx_0 = FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else if (rtb_LogicalOperator_fl) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_P_p_idx_0 = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_P_p_idx_0 = rtb_Add3_a * rtb_Subtract3_e +
              FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Switch: '<S364>/Switch1' incorporates:
           *  Constant: '<S398>/Constant'
           *  RelationalOperator: '<S398>/Compare'
           */
          if (rtb_a_o <= 0.0F) {
            /* Switch: '<S364>/Switch' incorporates:
             *  Constant: '<S397>/Constant'
             *  RelationalOperator: '<S397>/Compare'
             */
            if (D >= 0.0F) {
              rtb_TmpSignalConversionAtDela_a[0] = rtb_MathFunction_cx[0];
              rtb_TmpSignalConversionAtDela_a[1] = rtb_MathFunction_cx[1];
            } else {
              rtb_TmpSignalConversionAtDela_a[0] = rtb_P_p_idx_0;

              /* MATLAB Function: '<S364>/OutRegionRegWP' incorporates:
               *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
               */
              if (rtb_FixPtRelationalOperator_me) {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.cur_waypoint[1];

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              } else if (rtb_LogicalOperator_fl) {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_TmpSignalConversionAtDela_a[1] = FMS_B.Cmd_In.sp_waypoint[1];

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              } else {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_TmpSignalConversionAtDela_a[1] = rtb_Add3_a * u1_tmp +
                  FMS_B.Cmd_In.cur_waypoint[1];

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              }
            }

            /* End of Switch: '<S364>/Switch' */
          }

          /* End of Switch: '<S364>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S365>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          D = rtb_TmpSignalConversionAtDela_a[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S406>/Math Function' */
          rtb_TmpSignalConversionAtMath_j[0] = D * D;
          rtb_Add3_a = D;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S365>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          D = rtb_TmpSignalConversionAtDela_a[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S406>/Math Function' incorporates:
           *  Math: '<S404>/Square'
           */
          rtb_a_o = D * D;

          /* Sum: '<S406>/Sum of Elements' incorporates:
           *  Math: '<S406>/Math Function'
           */
          rtb_Subtract3_e = rtb_a_o + rtb_TmpSignalConversionAtMath_j[0];

          /* Math: '<S406>/Math Function1' incorporates:
           *  Sum: '<S406>/Sum of Elements'
           *
           * About '<S406>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -sqrtf(fabsf(rtb_Subtract3_e));
          } else {
            rtb_Subtract3_e = sqrtf(rtb_Subtract3_e);
          }

          /* End of Math: '<S406>/Math Function1' */

          /* Switch: '<S406>/Switch' incorporates:
           *  Constant: '<S406>/Constant'
           *  Product: '<S406>/Product'
           */
          if (rtb_Subtract3_e > 0.0F) {
            rtb_Switch_kx[0] = rtb_Add3_a;
            rtb_Switch_kx[1] = D;
            rtb_Switch_kx[2] = rtb_Subtract3_e;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S406>/Switch' */

          /* Product: '<S405>/Divide' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_Add4_o / rtb_Sqrt_h;
          rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_n_idx_1 / rtb_Sqrt_h;

          /* Sum: '<S408>/Sum of Elements' incorporates:
           *  Math: '<S408>/Math Function'
           *  SignalConversion: '<S408>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_j[1] *
            rtb_TmpSignalConversionAtMath_j[1] +
            rtb_TmpSignalConversionAtMath_j[0] *
            rtb_TmpSignalConversionAtMath_j[0];

          /* Math: '<S408>/Math Function1' incorporates:
           *  Sum: '<S408>/Sum of Elements'
           *
           * About '<S408>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -sqrtf(fabsf(rtb_Subtract3_e));
          } else {
            rtb_Subtract3_e = sqrtf(rtb_Subtract3_e);
          }

          /* End of Math: '<S408>/Math Function1' */

          /* Switch: '<S408>/Switch' incorporates:
           *  Constant: '<S408>/Constant'
           *  Product: '<S408>/Product'
           */
          if (rtb_Subtract3_e > 0.0F) {
            rtb_Add4_o = rtb_TmpSignalConversionAtMath_j[1];
            rtb_Switch_n_idx_1 = rtb_TmpSignalConversionAtMath_j[0];
            rtb_Sqrt_h = rtb_Subtract3_e;
          } else {
            rtb_Add4_o = 0.0F;
            rtb_Switch_n_idx_1 = 0.0F;
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S408>/Switch' */

          /* Product: '<S406>/Divide' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_Switch_kx[0] / rtb_Switch_kx
            [2];
          rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_kx[1] / rtb_Switch_kx
            [2];

          /* Sum: '<S409>/Sum of Elements' incorporates:
           *  Math: '<S409>/Math Function'
           *  SignalConversion: '<S409>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_j[1] *
            rtb_TmpSignalConversionAtMath_j[1] +
            rtb_TmpSignalConversionAtMath_j[0] *
            rtb_TmpSignalConversionAtMath_j[0];

          /* Math: '<S409>/Math Function1' incorporates:
           *  Sum: '<S409>/Sum of Elements'
           *
           * About '<S409>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -sqrtf(fabsf(rtb_Subtract3_e));
          } else {
            rtb_Subtract3_e = sqrtf(rtb_Subtract3_e);
          }

          /* End of Math: '<S409>/Math Function1' */

          /* Switch: '<S409>/Switch' incorporates:
           *  Constant: '<S409>/Constant'
           *  Product: '<S409>/Product'
           */
          if (rtb_Subtract3_e > 0.0F) {
            rtb_Switch_kx[0] = rtb_TmpSignalConversionAtMath_j[1];
            rtb_Switch_kx[1] = rtb_TmpSignalConversionAtMath_j[0];
            rtb_Switch_kx[2] = rtb_Subtract3_e;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S409>/Switch' */

          /* Product: '<S409>/Divide' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_Switch_kx[0] / rtb_Switch_kx
            [2];

          /* Product: '<S408>/Divide' */
          rtb_TmpSignalConversionAtDela_a[0] = rtb_Add4_o / rtb_Sqrt_h;

          /* Product: '<S358>/Divide' */
          rtb_MathFunction_cx[0] = rtb_Rem_n / rtb_Sign5_fx;
          rtb_Add3_a *= rtb_Add3_a;

          /* Product: '<S409>/Divide' incorporates:
           *  Math: '<S404>/Square'
           */
          rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_kx[1] / rtb_Switch_kx
            [2];

          /* Product: '<S408>/Divide' */
          rtb_TmpSignalConversionAtDela_a[1] = rtb_Switch_n_idx_1 / rtb_Sqrt_h;

          /* Product: '<S358>/Divide' */
          rtb_MathFunction_cx[1] = B / rtb_Sign5_fx;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S403>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S403>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S403>/Sum of Elements'
           */
          rtb_Subtract3_e = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Gain: '<S365>/Gain' incorporates:
           *  Math: '<S365>/Square'
           */
          rtb_Add4_o = rtb_Subtract3_e * rtb_Subtract3_e * 2.0F;

          /* Sum: '<S407>/Subtract' incorporates:
           *  Product: '<S407>/Multiply'
           *  Product: '<S407>/Multiply1'
           */
          rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_j[0] *
            rtb_TmpSignalConversionAtDela_a[1] -
            rtb_TmpSignalConversionAtMath_j[1] *
            rtb_TmpSignalConversionAtDela_a[0];

          /* Signum: '<S402>/Sign1' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S402>/Sign1' */

          /* Switch: '<S402>/Switch2' incorporates:
           *  Constant: '<S402>/Constant4'
           */
          if (rtb_Subtract3_e == 0.0F) {
            rtb_Subtract3_e = 1.0F;
          }

          /* End of Switch: '<S402>/Switch2' */

          /* DotProduct: '<S402>/Dot Product' */
          rtb_Switch_n_idx_1 = rtb_TmpSignalConversionAtDela_a[0] *
            rtb_TmpSignalConversionAtMath_j[0] +
            rtb_TmpSignalConversionAtDela_a[1] *
            rtb_TmpSignalConversionAtMath_j[1];

          /* Trigonometry: '<S402>/Acos' incorporates:
           *  DotProduct: '<S402>/Dot Product'
           */
          if (rtb_Switch_n_idx_1 > 1.0F) {
            rtb_Switch_n_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_n_idx_1 < -1.0F) {
              rtb_Switch_n_idx_1 = -1.0F;
            }
          }

          /* Product: '<S402>/Multiply' incorporates:
           *  Trigonometry: '<S402>/Acos'
           */
          rtb_Subtract3_e *= acosf(rtb_Switch_n_idx_1);

          /* Saturate: '<S365>/Saturation' */
          if (rtb_Subtract3_e > 1.57079637F) {
            rtb_Subtract3_e = 1.57079637F;
          } else {
            if (rtb_Subtract3_e < -1.57079637F) {
              rtb_Subtract3_e = -1.57079637F;
            }
          }

          /* End of Saturate: '<S365>/Saturation' */

          /* Product: '<S365>/Divide' incorporates:
           *  Constant: '<S340>/L1'
           *  Constant: '<S365>/Constant'
           *  MinMax: '<S365>/Max'
           *  MinMax: '<S365>/Min'
           *  Product: '<S365>/Multiply1'
           *  Sqrt: '<S404>/Sqrt'
           *  Sum: '<S404>/Sum of Elements'
           *  Trigonometry: '<S365>/Sin'
           */
          rtb_Sqrt_h = arm_sin_f32(rtb_Subtract3_e) * rtb_Add4_o / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_a_o + rtb_Add3_a), 0.5F));

          /* Sum: '<S356>/Subtract' incorporates:
           *  Product: '<S356>/Multiply'
           *  Product: '<S356>/Multiply1'
           */
          rtb_P_p_idx_0 = rtb_MathFunction_cx[0] * FMS_ConstB.Divide[1] -
            rtb_MathFunction_cx[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S345>/Sign1' */
          if (rtb_P_p_idx_0 < 0.0F) {
            rtb_P_p_idx_0 = -1.0F;
          } else {
            if (rtb_P_p_idx_0 > 0.0F) {
              rtb_P_p_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S345>/Sign1' */

          /* Switch: '<S345>/Switch2' incorporates:
           *  Constant: '<S345>/Constant4'
           */
          if (rtb_P_p_idx_0 == 0.0F) {
            rtb_P_p_idx_0 = 1.0F;
          }

          /* End of Switch: '<S345>/Switch2' */

          /* DotProduct: '<S345>/Dot Product' */
          rtb_Switch_n_idx_1 = FMS_ConstB.Divide[0] * rtb_MathFunction_cx[0] +
            FMS_ConstB.Divide[1] * rtb_MathFunction_cx[1];

          /* Trigonometry: '<S345>/Acos' incorporates:
           *  DotProduct: '<S345>/Dot Product'
           */
          if (rtb_Switch_n_idx_1 > 1.0F) {
            rtb_Switch_n_idx_1 = 1.0F;
          } else {
            if (rtb_Switch_n_idx_1 < -1.0F) {
              rtb_Switch_n_idx_1 = -1.0F;
            }
          }

          /* Product: '<S345>/Multiply' incorporates:
           *  Trigonometry: '<S345>/Acos'
           */
          rtb_P_p_idx_0 *= acosf(rtb_Switch_n_idx_1);

          /* Math: '<S348>/Rem' incorporates:
           *  Constant: '<S348>/Constant1'
           *  Delay: '<S344>/Delay'
           *  Sum: '<S344>/Sum2'
           */
          rtb_Subtract3_e = rt_remf(rtb_P_p_idx_0 - FMS_DW.Delay_DSTATE_n,
            6.28318548F);

          /* Switch: '<S348>/Switch' incorporates:
           *  Abs: '<S348>/Abs'
           *  Constant: '<S348>/Constant'
           *  Constant: '<S354>/Constant'
           *  Product: '<S348>/Multiply'
           *  RelationalOperator: '<S354>/Compare'
           *  Sum: '<S348>/Add'
           */
          if (fabsf(rtb_Subtract3_e) > 3.14159274F) {
            /* Signum: '<S348>/Sign' */
            if (rtb_Subtract3_e < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else if (rtb_Subtract3_e > 0.0F) {
              rtb_Add3_a = 1.0F;
            } else {
              rtb_Add3_a = rtb_Subtract3_e;
            }

            /* End of Signum: '<S348>/Sign' */
            rtb_Subtract3_e -= 6.28318548F * rtb_Add3_a;
          }

          /* End of Switch: '<S348>/Switch' */

          /* Sum: '<S344>/Sum' incorporates:
           *  Delay: '<S344>/Delay'
           */
          rtb_Add3_a = rtb_Subtract3_e + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S353>/Multiply1' incorporates:
           *  Constant: '<S353>/const1'
           *  DiscreteIntegrator: '<S347>/Integrator'
           */
          rtb_Subtract3_e = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S353>/Add' incorporates:
           *  DiscreteIntegrator: '<S347>/Integrator1'
           *  Sum: '<S347>/Subtract'
           */
          rtb_Add4_o = (FMS_DW.Integrator1_DSTATE_mfw - rtb_Add3_a) +
            rtb_Subtract3_e;

          /* Signum: '<S353>/Sign' */
          if (rtb_Add4_o < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else if (rtb_Add4_o > 0.0F) {
            rtb_Add3_a = 1.0F;
          } else {
            rtb_Add3_a = rtb_Add4_o;
          }

          /* End of Signum: '<S353>/Sign' */

          /* Sum: '<S353>/Add2' incorporates:
           *  Abs: '<S353>/Abs'
           *  Gain: '<S353>/Gain'
           *  Gain: '<S353>/Gain1'
           *  Product: '<S353>/Multiply2'
           *  Product: '<S353>/Multiply3'
           *  Sqrt: '<S353>/Sqrt'
           *  Sum: '<S353>/Add1'
           *  Sum: '<S353>/Subtract'
           */
          rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Add4_o) + FMS_ConstB.d_mv) *
                           FMS_ConstB.d_mv) - FMS_ConstB.d_mv) * 0.5F *
            rtb_Add3_a + rtb_Subtract3_e;

          /* Sum: '<S353>/Add4' */
          rtb_Subtract3_e += rtb_Add4_o - rtb_a_o;

          /* Sum: '<S353>/Add3' */
          rtb_Add3_a = rtb_Add4_o + FMS_ConstB.d_mv;

          /* Sum: '<S353>/Subtract1' */
          rtb_Add4_o -= FMS_ConstB.d_mv;

          /* Signum: '<S353>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S353>/Sign1' */

          /* Signum: '<S353>/Sign2' */
          if (rtb_Add4_o < 0.0F) {
            rtb_Add4_o = -1.0F;
          } else {
            if (rtb_Add4_o > 0.0F) {
              rtb_Add4_o = 1.0F;
            }
          }

          /* End of Signum: '<S353>/Sign2' */

          /* Sum: '<S353>/Add5' incorporates:
           *  Gain: '<S353>/Gain2'
           *  Product: '<S353>/Multiply4'
           *  Sum: '<S353>/Subtract2'
           */
          rtb_a_o += (rtb_Add3_a - rtb_Add4_o) * 0.5F * rtb_Subtract3_e;

          /* Sum: '<S353>/Add6' */
          rtb_Add3_a = rtb_a_o + FMS_ConstB.d_mv;

          /* Sum: '<S353>/Subtract3' */
          rtb_Subtract3_e = rtb_a_o - FMS_ConstB.d_mv;

          /* Product: '<S353>/Divide' */
          rtb_Rem_n = rtb_a_o / FMS_ConstB.d_mv;

          /* Signum: '<S353>/Sign5' incorporates:
           *  Signum: '<S353>/Sign6'
           */
          if (rtb_a_o < 0.0F) {
            rtb_Sign5_fx = -1.0F;

            /* Signum: '<S353>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_a_o > 0.0F) {
            rtb_Sign5_fx = 1.0F;

            /* Signum: '<S353>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Sign5_fx = rtb_a_o;

            /* Signum: '<S353>/Sign6' */
            rtb_Add4_o = rtb_a_o;
          }

          /* End of Signum: '<S353>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S344>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_P_p_idx_0 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S349>/Rem' incorporates:
           *  Constant: '<S349>/Constant1'
           */
          rtb_a_o = rt_remf(rtb_P_p_idx_0, 6.28318548F);

          /* Switch: '<S349>/Switch' incorporates:
           *  Abs: '<S349>/Abs'
           *  Constant: '<S349>/Constant'
           *  Constant: '<S355>/Constant'
           *  Product: '<S349>/Multiply'
           *  RelationalOperator: '<S355>/Compare'
           *  Sum: '<S349>/Add'
           */
          if (fabsf(rtb_a_o) > 3.14159274F) {
            /* Signum: '<S349>/Sign' */
            if (rtb_a_o < 0.0F) {
              rtb_Switch_n_idx_1 = -1.0F;
            } else if (rtb_a_o > 0.0F) {
              rtb_Switch_n_idx_1 = 1.0F;
            } else {
              rtb_Switch_n_idx_1 = rtb_a_o;
            }

            /* End of Signum: '<S349>/Sign' */
            rtb_a_o -= 6.28318548F * rtb_Switch_n_idx_1;
          }

          /* End of Switch: '<S349>/Switch' */

          /* Abs: '<S342>/Abs' */
          rtb_a_o = fabsf(rtb_a_o);

          /* Update for Delay: '<S366>/Delay' */
          FMS_DW.icLoad_p = 0U;

          /* Update for DiscreteIntegrator: '<S367>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S360>/Constant'
           *  RelationalOperator: '<S360>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_k = (uint8_T)((uint32_T)(rtb_a_o <=
            0.17453292F) + FMS_DW.DiscreteTimeIntegrator_DSTATE_k);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S367>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S362>/Acceleration_Speed' incorporates:
           *  Constant: '<S362>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          if (FMS_DW.Acceleration_Speed_DSTATE >= FMS_PARAM.CRUISE_SPEED) {
            FMS_DW.Acceleration_Speed_DSTATE = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (FMS_DW.Acceleration_Speed_DSTATE <= 0.0F) {
              FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            }
          }

          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)rtb_Compare_ii;

          /* End of Update for DiscreteIntegrator: '<S362>/Acceleration_Speed' */

          /* Product: '<S366>/Divide1' incorporates:
           *  Constant: '<S366>/Constant'
           */
          rtb_Switch_n_idx_1 = rtb_Sqrt_h / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S366>/Saturation' */
          if (rtb_Switch_n_idx_1 > 0.314159274F) {
            rtb_Switch_n_idx_1 = 0.314159274F;
          } else {
            if (rtb_Switch_n_idx_1 < -0.314159274F) {
              rtb_Switch_n_idx_1 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S366>/Saturation' */

          /* Update for DiscreteIntegrator: '<S411>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_Switch_n_idx_1;

          /* Update for Delay: '<S344>/Delay' */
          FMS_DW.icLoad_mb = 0U;

          /* Update for DiscreteIntegrator: '<S347>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S347>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mfw += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S353>/Sign3' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S353>/Sign3' */

          /* Signum: '<S353>/Sign4' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S353>/Sign4' */

          /* Update for DiscreteIntegrator: '<S347>/Integrator' incorporates:
           *  Constant: '<S353>/const'
           *  Gain: '<S353>/Gain3'
           *  Product: '<S353>/Multiply5'
           *  Product: '<S353>/Multiply6'
           *  Sum: '<S353>/Subtract4'
           *  Sum: '<S353>/Subtract5'
           *  Sum: '<S353>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_m += ((rtb_Rem_n - rtb_Sign5_fx) *
            FMS_ConstB.Gain4_cu * ((rtb_Add3_a - rtb_Subtract3_e) * 0.5F) -
            rtb_Add4_o * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_m >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_m = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_m <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_m = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S347>/Integrator' */
          /* End of Outputs for SubSystem: '<S336>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Update for UnitDelay: '<S339>/Delay Input1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S339>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S224>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S224>/Unknown' incorporates:
           *  ActionPort: '<S338>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_n);

          /* End of Outputs for SubSystem: '<S224>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S224>/Switch Case' */
        /* End of Outputs for SubSystem: '<S36>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S36>/Assist' incorporates:
         *  ActionPort: '<S223>/Action Port'
         */
        /* SwitchCase: '<S223>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_o;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        switch (FMS_B.state) {
         case VehicleState_Acro:
          FMS_DW.SwitchCase_ActiveSubsystem_o = 0;
          break;

         case VehicleState_Stabilize:
          FMS_DW.SwitchCase_ActiveSubsystem_o = 1;
          break;

         case VehicleState_Altitude:
          FMS_DW.SwitchCase_ActiveSubsystem_o = 2;
          break;

         case VehicleState_Position:
          FMS_DW.SwitchCase_ActiveSubsystem_o = 3;
          break;

         default:
          FMS_DW.SwitchCase_ActiveSubsystem_o = 4;
          break;
        }

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_o) {
          switch (rtPrevAction) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S323>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S238>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S256>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S272>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S297>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S284>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S223>/Acro' incorporates:
           *  ActionPort: '<S228>/Action Port'
           */
          /* BusAssignment: '<S228>/Bus Assignment' incorporates:
           *  Constant: '<S228>/Constant'
           *  Gain: '<S233>/Gain'
           *  Gain: '<S233>/Gain1'
           *  Gain: '<S233>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_c;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
          FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
          FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

          /* Saturate: '<S234>/Saturation' incorporates:
           *  Constant: '<S234>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           *  Sum: '<S234>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_a_o = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S234>/Saturation' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S228>/Bus Assignment' incorporates:
           *  Constant: '<S234>/Constant5'
           *  Gain: '<S234>/Gain2'
           *  Sum: '<S234>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_a_o), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S223>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S223>/Stabilize' incorporates:
             *  ActionPort: '<S231>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S223>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S319>/Integrator'
             *  DiscreteIntegrator: '<S319>/Integrator1'
             *  DiscreteIntegrator: '<S320>/Integrator'
             *  DiscreteIntegrator: '<S320>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_ib = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S223>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S223>/Stabilize' incorporates:
             *  ActionPort: '<S231>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S223>/Switch Case' incorporates:
             *  Chart: '<S324>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S223>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S223>/Stabilize' incorporates:
           *  ActionPort: '<S231>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Logic: '<S314>/Logical Operator' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S324>/Motion State' incorporates:
           *  Abs: '<S324>/Abs'
           *  Abs: '<S324>/Abs1'
           *  Constant: '<S334>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S334>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_k0,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S323>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_e;
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          switch (rtb_state_k0) {
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
              /* SystemReset for IfAction SubSystem: '<S323>/Hold Control' incorporates:
               *  ActionPort: '<S326>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S323>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S323>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S323>/Hold Control' incorporates:
             *  ActionPort: '<S326>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S323>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S323>/Brake Control' incorporates:
             *  ActionPort: '<S325>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S323>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S323>/Move Control' incorporates:
               *  ActionPort: '<S327>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S323>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S323>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S323>/Move Control' incorporates:
             *  ActionPort: '<S327>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S323>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S323>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S316>/Switch' incorporates:
           *  Constant: '<S316>/Constant'
           *  Constant: '<S316>/Constant4'
           *  Constant: '<S316>/Constant5'
           *  Gain: '<S316>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S316>/Saturation'
           *  SignalConversion: '<S30>/Signal Copy2'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S316>/Add'
           *  Sum: '<S316>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_o = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S316>/Saturation' */
              rtb_a_o = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S316>/Saturation' */
              rtb_a_o = 0.0F;
            } else {
              /* Saturate: '<S316>/Saturation' incorporates:
               *  Constant: '<S316>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S30>/Signal Copy2'
               *  Sum: '<S316>/Sum'
               */
              rtb_a_o = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_o = (uint16_T)((uint16_T)fmodf(floorf(500.0F * rtb_a_o),
              65536.0F) + 1000U);
          }

          /* End of Switch: '<S316>/Switch' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S231>/Bus Assignment' incorporates:
           *  Constant: '<S231>/Constant'
           *  DataTypeConversion: '<S314>/Data Type Conversion'
           *  DiscreteIntegrator: '<S319>/Integrator1'
           *  DiscreteIntegrator: '<S320>/Integrator1'
           *  Product: '<S314>/Multiply'
           *  Product: '<S314>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_lb;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ii;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d2;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S323>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S231>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S323>/Saturation' */

          /* BusAssignment: '<S231>/Bus Assignment' */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_o;

          /* Product: '<S322>/Multiply1' incorporates:
           *  Constant: '<S322>/const1'
           *  DiscreteIntegrator: '<S320>/Integrator'
           */
          rtb_Sign5_fx = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S318>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S318>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S322>/Add' incorporates:
           *  DiscreteIntegrator: '<S320>/Integrator1'
           *  Gain: '<S314>/Gain1'
           *  Gain: '<S318>/Gain'
           *  Sum: '<S320>/Subtract'
           */
          rtb_Switch_n_idx_1 = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_a_o * -FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Sign5_fx;

          /* Signum: '<S322>/Sign' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Switch_n_idx_1 > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Switch_n_idx_1;
          }

          /* End of Signum: '<S322>/Sign' */

          /* Sum: '<S322>/Add2' incorporates:
           *  Abs: '<S322>/Abs'
           *  Gain: '<S322>/Gain'
           *  Gain: '<S322>/Gain1'
           *  Product: '<S322>/Multiply2'
           *  Product: '<S322>/Multiply3'
           *  Sqrt: '<S322>/Sqrt'
           *  Sum: '<S322>/Add1'
           *  Sum: '<S322>/Subtract'
           */
          rtb_P_p_idx_0 = (sqrtf((8.0F * fabsf(rtb_Switch_n_idx_1) +
            FMS_ConstB.d_g) * FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F * rtb_a_o
            + rtb_Sign5_fx;

          /* Sum: '<S322>/Add4' */
          rtb_Subtract3_e = (rtb_Switch_n_idx_1 - rtb_P_p_idx_0) + rtb_Sign5_fx;

          /* Sum: '<S322>/Add3' */
          rtb_Add3_a = rtb_Switch_n_idx_1 + FMS_ConstB.d_g;

          /* Sum: '<S322>/Subtract1' */
          rtb_Switch_n_idx_1 -= FMS_ConstB.d_g;

          /* Signum: '<S322>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S322>/Sign1' */

          /* Signum: '<S322>/Sign2' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_Switch_n_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_n_idx_1 > 0.0F) {
              rtb_Switch_n_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S322>/Sign2' */

          /* Sum: '<S322>/Add5' incorporates:
           *  Gain: '<S322>/Gain2'
           *  Product: '<S322>/Multiply4'
           *  Sum: '<S322>/Subtract2'
           */
          rtb_P_p_idx_0 += (rtb_Add3_a - rtb_Switch_n_idx_1) * 0.5F *
            rtb_Subtract3_e;

          /* Sum: '<S322>/Add6' */
          rtb_Add3_a = rtb_P_p_idx_0 + FMS_ConstB.d_g;

          /* Sum: '<S322>/Subtract3' */
          rtb_Subtract3_e = rtb_P_p_idx_0 - FMS_ConstB.d_g;

          /* Product: '<S322>/Divide' */
          rtb_Sqrt_h = rtb_P_p_idx_0 / FMS_ConstB.d_g;

          /* Signum: '<S322>/Sign5' incorporates:
           *  Signum: '<S322>/Sign6'
           */
          if (rtb_P_p_idx_0 < 0.0F) {
            rtb_Rem_n = -1.0F;

            /* Signum: '<S322>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_P_p_idx_0 > 0.0F) {
            rtb_Rem_n = 1.0F;

            /* Signum: '<S322>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Rem_n = rtb_P_p_idx_0;

            /* Signum: '<S322>/Sign6' */
            rtb_Add4_o = rtb_P_p_idx_0;
          }

          /* End of Signum: '<S322>/Sign5' */

          /* Product: '<S321>/Multiply1' incorporates:
           *  Constant: '<S321>/const1'
           *  DiscreteIntegrator: '<S319>/Integrator'
           */
          rtb_Sign5_fx = FMS_DW.Integrator_DSTATE_ib * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S317>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S317>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S321>/Add' incorporates:
           *  DiscreteIntegrator: '<S319>/Integrator1'
           *  Gain: '<S314>/Gain'
           *  Gain: '<S317>/Gain'
           *  Sum: '<S319>/Subtract'
           */
          rtb_Switch_n_idx_1 = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_a_o * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Sign5_fx;

          /* Signum: '<S321>/Sign' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Switch_n_idx_1 > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Switch_n_idx_1;
          }

          /* End of Signum: '<S321>/Sign' */

          /* Sum: '<S321>/Add2' incorporates:
           *  Abs: '<S321>/Abs'
           *  Gain: '<S321>/Gain'
           *  Gain: '<S321>/Gain1'
           *  Product: '<S321>/Multiply2'
           *  Product: '<S321>/Multiply3'
           *  Sqrt: '<S321>/Sqrt'
           *  Sum: '<S321>/Add1'
           *  Sum: '<S321>/Subtract'
           */
          rtb_P_p_idx_0 = (sqrtf((8.0F * fabsf(rtb_Switch_n_idx_1) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F * rtb_a_o
            + rtb_Sign5_fx;

          /* Sum: '<S321>/Add4' */
          rtb_Sign5_fx += rtb_Switch_n_idx_1 - rtb_P_p_idx_0;

          /* Sum: '<S321>/Add3' */
          rtb_a_o = rtb_Switch_n_idx_1 + FMS_ConstB.d_a;

          /* Sum: '<S321>/Subtract1' */
          rtb_Switch_n_idx_1 -= FMS_ConstB.d_a;

          /* Signum: '<S321>/Sign1' */
          if (rtb_a_o < 0.0F) {
            rtb_a_o = -1.0F;
          } else {
            if (rtb_a_o > 0.0F) {
              rtb_a_o = 1.0F;
            }
          }

          /* End of Signum: '<S321>/Sign1' */

          /* Signum: '<S321>/Sign2' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_Switch_n_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_n_idx_1 > 0.0F) {
              rtb_Switch_n_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S321>/Sign2' */

          /* Sum: '<S321>/Add5' incorporates:
           *  Gain: '<S321>/Gain2'
           *  Product: '<S321>/Multiply4'
           *  Sum: '<S321>/Subtract2'
           */
          rtb_P_p_idx_0 += (rtb_a_o - rtb_Switch_n_idx_1) * 0.5F * rtb_Sign5_fx;

          /* Update for DiscreteIntegrator: '<S319>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S319>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_ib;

          /* Update for DiscreteIntegrator: '<S320>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S320>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S322>/Sign3' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S322>/Sign3' */

          /* Signum: '<S322>/Sign4' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S322>/Sign4' */

          /* Update for DiscreteIntegrator: '<S320>/Integrator' incorporates:
           *  Constant: '<S322>/const'
           *  Gain: '<S322>/Gain3'
           *  Product: '<S322>/Multiply5'
           *  Product: '<S322>/Multiply6'
           *  Sum: '<S322>/Subtract4'
           *  Sum: '<S322>/Subtract5'
           *  Sum: '<S322>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((rtb_Sqrt_h - rtb_Rem_n) *
            FMS_ConstB.Gain4_o * ((rtb_Add3_a - rtb_Subtract3_e) * 0.5F) -
            rtb_Add4_o * 12.566371F) * 0.004F;

          /* Sum: '<S321>/Subtract3' */
          rtb_Add3_a = rtb_P_p_idx_0 - FMS_ConstB.d_a;

          /* Sum: '<S321>/Add6' */
          rtb_Subtract3_e = rtb_P_p_idx_0 + FMS_ConstB.d_a;

          /* Signum: '<S321>/Sign5' incorporates:
           *  Signum: '<S321>/Sign6'
           */
          if (rtb_P_p_idx_0 < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S321>/Sign6' */
            rtb_Sqrt_h = -1.0F;
          } else if (rtb_P_p_idx_0 > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S321>/Sign6' */
            rtb_Sqrt_h = 1.0F;
          } else {
            rtb_Add4_o = rtb_P_p_idx_0;

            /* Signum: '<S321>/Sign6' */
            rtb_Sqrt_h = rtb_P_p_idx_0;
          }

          /* End of Signum: '<S321>/Sign5' */

          /* Signum: '<S321>/Sign3' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S321>/Sign3' */

          /* Signum: '<S321>/Sign4' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S321>/Sign4' */

          /* Update for DiscreteIntegrator: '<S319>/Integrator' incorporates:
           *  Constant: '<S321>/const'
           *  Gain: '<S321>/Gain3'
           *  Product: '<S321>/Divide'
           *  Product: '<S321>/Multiply5'
           *  Product: '<S321>/Multiply6'
           *  Sum: '<S321>/Subtract4'
           *  Sum: '<S321>/Subtract5'
           *  Sum: '<S321>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ib += ((rtb_P_p_idx_0 / FMS_ConstB.d_a -
            rtb_Add4_o) * FMS_ConstB.Gain4_kf * ((rtb_Subtract3_e - rtb_Add3_a) *
            0.5F) - rtb_Sqrt_h * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S223>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S223>/Altitude' incorporates:
             *  ActionPort: '<S229>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S223>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S252>/Integrator'
             *  DiscreteIntegrator: '<S252>/Integrator1'
             *  DiscreteIntegrator: '<S253>/Integrator'
             *  DiscreteIntegrator: '<S253>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_mf = 0.0F;
            FMS_DW.Integrator1_DSTATE_hg = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S223>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S223>/Altitude' incorporates:
             *  ActionPort: '<S229>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S223>/Switch Case' incorporates:
             *  Chart: '<S239>/Motion Status'
             *  Chart: '<S257>/Motion State'
             */
            FMS_MotionStatus_a_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S223>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S223>/Altitude' incorporates:
           *  ActionPort: '<S229>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S239>/Motion Status' incorporates:
           *  Abs: '<S239>/Abs'
           *  Abs: '<S239>/Abs1'
           *  Constant: '<S248>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S248>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionStatus_k(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                             FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                             &rtb_state_k0, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S238>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_nh;
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;
          switch (rtb_state_k0) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_nh = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_nh = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_nh = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_nh) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nh != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S238>/Hold Control' incorporates:
               *  ActionPort: '<S241>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S238>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S238>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S238>/Hold Control' incorporates:
             *  ActionPort: '<S241>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                            &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S238>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S238>/Brake Control' incorporates:
             *  ActionPort: '<S240>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S238>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S238>/Move Control' incorporates:
             *  ActionPort: '<S242>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S238>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S238>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Switch: '<S235>/Switch' incorporates:
           *  Constant: '<S235>/Constant'
           *  Saturate: '<S238>/Saturation1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Add3_a = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S238>/Saturation1' */
            rtb_Add3_a = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S238>/Saturation1' */
            rtb_Add3_a = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S238>/Saturation1' */
            rtb_Add3_a = FMS_B.Merge_l;
          }

          /* End of Switch: '<S235>/Switch' */

          /* Logic: '<S236>/Logical Operator' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S257>/Motion State' incorporates:
           *  Abs: '<S257>/Abs'
           *  Abs: '<S257>/Abs1'
           *  Constant: '<S267>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S267>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_k0,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S256>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          switch (rtb_state_k0) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_i = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_i = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_i = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_i) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S256>/Hold Control' incorporates:
               *  ActionPort: '<S259>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S256>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_p);

              /* End of SystemReset for SubSystem: '<S256>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S256>/Hold Control' incorporates:
             *  ActionPort: '<S259>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_bd,
                              &FMS_DW.HoldControl_p);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S256>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S256>/Brake Control' incorporates:
             *  ActionPort: '<S258>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_bd);

            /* End of Outputs for SubSystem: '<S256>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S256>/Move Control' incorporates:
               *  ActionPort: '<S260>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S256>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S256>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S256>/Move Control' incorporates:
             *  ActionPort: '<S260>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_bd,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S256>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S256>/Switch Case' */

          /* BusAssignment: '<S229>/Bus Assignment' incorporates:
           *  Constant: '<S229>/Constant'
           *  DataTypeConversion: '<S236>/Data Type Conversion'
           *  DiscreteIntegrator: '<S252>/Integrator1'
           *  DiscreteIntegrator: '<S253>/Integrator1'
           *  Product: '<S236>/Multiply'
           *  Product: '<S236>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_aj;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_l;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_mf;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_hg;

          /* Saturate: '<S256>/Saturation' */
          if (FMS_B.Merge_bd > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S229>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_bd < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S229>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S229>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_bd;
          }

          /* End of Saturate: '<S256>/Saturation' */

          /* BusAssignment: '<S229>/Bus Assignment' */
          FMS_Y.FMS_Out.w_cmd = rtb_Add3_a;

          /* Product: '<S255>/Multiply1' incorporates:
           *  Constant: '<S255>/const1'
           *  DiscreteIntegrator: '<S253>/Integrator'
           */
          rtb_Sign5_fx = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S251>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S251>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S255>/Add' incorporates:
           *  DiscreteIntegrator: '<S253>/Integrator1'
           *  Gain: '<S236>/Gain1'
           *  Gain: '<S251>/Gain'
           *  Sum: '<S253>/Subtract'
           */
          rtb_Switch_n_idx_1 = (FMS_DW.Integrator1_DSTATE_hg - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_a_o * -FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Sign5_fx;

          /* Signum: '<S255>/Sign' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Switch_n_idx_1 > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Switch_n_idx_1;
          }

          /* End of Signum: '<S255>/Sign' */

          /* Sum: '<S255>/Add2' incorporates:
           *  Abs: '<S255>/Abs'
           *  Gain: '<S255>/Gain'
           *  Gain: '<S255>/Gain1'
           *  Product: '<S255>/Multiply2'
           *  Product: '<S255>/Multiply3'
           *  Sqrt: '<S255>/Sqrt'
           *  Sum: '<S255>/Add1'
           *  Sum: '<S255>/Subtract'
           */
          rtb_P_p_idx_0 = (sqrtf((8.0F * fabsf(rtb_Switch_n_idx_1) +
            FMS_ConstB.d_o) * FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F * rtb_a_o
            + rtb_Sign5_fx;

          /* Sum: '<S255>/Add4' */
          rtb_Subtract3_e = (rtb_Switch_n_idx_1 - rtb_P_p_idx_0) + rtb_Sign5_fx;

          /* Sum: '<S255>/Add3' */
          rtb_Add3_a = rtb_Switch_n_idx_1 + FMS_ConstB.d_o;

          /* Sum: '<S255>/Subtract1' */
          rtb_Switch_n_idx_1 -= FMS_ConstB.d_o;

          /* Signum: '<S255>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S255>/Sign1' */

          /* Signum: '<S255>/Sign2' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_Switch_n_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_n_idx_1 > 0.0F) {
              rtb_Switch_n_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S255>/Sign2' */

          /* Sum: '<S255>/Add5' incorporates:
           *  Gain: '<S255>/Gain2'
           *  Product: '<S255>/Multiply4'
           *  Sum: '<S255>/Subtract2'
           */
          rtb_P_p_idx_0 += (rtb_Add3_a - rtb_Switch_n_idx_1) * 0.5F *
            rtb_Subtract3_e;

          /* Sum: '<S255>/Add6' */
          rtb_Add3_a = rtb_P_p_idx_0 + FMS_ConstB.d_o;

          /* Sum: '<S255>/Subtract3' */
          rtb_Subtract3_e = rtb_P_p_idx_0 - FMS_ConstB.d_o;

          /* Product: '<S255>/Divide' */
          rtb_Sqrt_h = rtb_P_p_idx_0 / FMS_ConstB.d_o;

          /* Signum: '<S255>/Sign5' incorporates:
           *  Signum: '<S255>/Sign6'
           */
          if (rtb_P_p_idx_0 < 0.0F) {
            rtb_Rem_n = -1.0F;

            /* Signum: '<S255>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_P_p_idx_0 > 0.0F) {
            rtb_Rem_n = 1.0F;

            /* Signum: '<S255>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Rem_n = rtb_P_p_idx_0;

            /* Signum: '<S255>/Sign6' */
            rtb_Add4_o = rtb_P_p_idx_0;
          }

          /* End of Signum: '<S255>/Sign5' */

          /* Product: '<S254>/Multiply1' incorporates:
           *  Constant: '<S254>/const1'
           *  DiscreteIntegrator: '<S252>/Integrator'
           */
          rtb_Sign5_fx = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S250>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S250>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S254>/Add' incorporates:
           *  DiscreteIntegrator: '<S252>/Integrator1'
           *  Gain: '<S236>/Gain'
           *  Gain: '<S250>/Gain'
           *  Sum: '<S252>/Subtract'
           */
          rtb_Switch_n_idx_1 = (FMS_DW.Integrator1_DSTATE_mf - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_a_o * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Sign5_fx;

          /* Signum: '<S254>/Sign' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Switch_n_idx_1 > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Switch_n_idx_1;
          }

          /* End of Signum: '<S254>/Sign' */

          /* Sum: '<S254>/Add2' incorporates:
           *  Abs: '<S254>/Abs'
           *  Gain: '<S254>/Gain'
           *  Gain: '<S254>/Gain1'
           *  Product: '<S254>/Multiply2'
           *  Product: '<S254>/Multiply3'
           *  Sqrt: '<S254>/Sqrt'
           *  Sum: '<S254>/Add1'
           *  Sum: '<S254>/Subtract'
           */
          rtb_P_p_idx_0 = (sqrtf((8.0F * fabsf(rtb_Switch_n_idx_1) +
            FMS_ConstB.d_c) * FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F * rtb_a_o
            + rtb_Sign5_fx;

          /* Sum: '<S254>/Add4' */
          rtb_Sign5_fx += rtb_Switch_n_idx_1 - rtb_P_p_idx_0;

          /* Sum: '<S254>/Add3' */
          rtb_a_o = rtb_Switch_n_idx_1 + FMS_ConstB.d_c;

          /* Sum: '<S254>/Subtract1' */
          rtb_Switch_n_idx_1 -= FMS_ConstB.d_c;

          /* Signum: '<S254>/Sign1' */
          if (rtb_a_o < 0.0F) {
            rtb_a_o = -1.0F;
          } else {
            if (rtb_a_o > 0.0F) {
              rtb_a_o = 1.0F;
            }
          }

          /* End of Signum: '<S254>/Sign1' */

          /* Signum: '<S254>/Sign2' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_Switch_n_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_n_idx_1 > 0.0F) {
              rtb_Switch_n_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S254>/Sign2' */

          /* Sum: '<S254>/Add5' incorporates:
           *  Gain: '<S254>/Gain2'
           *  Product: '<S254>/Multiply4'
           *  Sum: '<S254>/Subtract2'
           */
          rtb_P_p_idx_0 += (rtb_a_o - rtb_Switch_n_idx_1) * 0.5F * rtb_Sign5_fx;

          /* Update for DiscreteIntegrator: '<S252>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S252>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S253>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S253>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_hg += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S255>/Sign3' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S255>/Sign3' */

          /* Signum: '<S255>/Sign4' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S255>/Sign4' */

          /* Update for DiscreteIntegrator: '<S253>/Integrator' incorporates:
           *  Constant: '<S255>/const'
           *  Gain: '<S255>/Gain3'
           *  Product: '<S255>/Multiply5'
           *  Product: '<S255>/Multiply6'
           *  Sum: '<S255>/Subtract4'
           *  Sum: '<S255>/Subtract5'
           *  Sum: '<S255>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((rtb_Sqrt_h - rtb_Rem_n) *
            FMS_ConstB.Gain4_c * ((rtb_Add3_a - rtb_Subtract3_e) * 0.5F) -
            rtb_Add4_o * 12.566371F) * 0.004F;

          /* Sum: '<S254>/Subtract3' */
          rtb_Add3_a = rtb_P_p_idx_0 - FMS_ConstB.d_c;

          /* Sum: '<S254>/Add6' */
          rtb_Subtract3_e = rtb_P_p_idx_0 + FMS_ConstB.d_c;

          /* Signum: '<S254>/Sign5' incorporates:
           *  Signum: '<S254>/Sign6'
           */
          if (rtb_P_p_idx_0 < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S254>/Sign6' */
            rtb_Sqrt_h = -1.0F;
          } else if (rtb_P_p_idx_0 > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S254>/Sign6' */
            rtb_Sqrt_h = 1.0F;
          } else {
            rtb_Add4_o = rtb_P_p_idx_0;

            /* Signum: '<S254>/Sign6' */
            rtb_Sqrt_h = rtb_P_p_idx_0;
          }

          /* End of Signum: '<S254>/Sign5' */

          /* Signum: '<S254>/Sign3' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S254>/Sign3' */

          /* Signum: '<S254>/Sign4' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S254>/Sign4' */

          /* Update for DiscreteIntegrator: '<S252>/Integrator' incorporates:
           *  Constant: '<S254>/const'
           *  Gain: '<S254>/Gain3'
           *  Product: '<S254>/Divide'
           *  Product: '<S254>/Multiply5'
           *  Product: '<S254>/Multiply6'
           *  Sum: '<S254>/Subtract4'
           *  Sum: '<S254>/Subtract5'
           *  Sum: '<S254>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_P_p_idx_0 / FMS_ConstB.d_c -
            rtb_Add4_o) * FMS_ConstB.Gain4_h * ((rtb_Subtract3_e - rtb_Add3_a) *
            0.5F) - rtb_Sqrt_h * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S223>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S223>/Position' incorporates:
             *  ActionPort: '<S230>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S223>/Switch Case' incorporates:
             *  Chart: '<S273>/Motion Status'
             *  Chart: '<S285>/Motion State'
             *  Chart: '<S298>/Motion State'
             */
            FMS_MotionStatus_a_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

            /* End of SystemReset for SubSystem: '<S223>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S223>/Position' incorporates:
           *  ActionPort: '<S230>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S273>/Motion Status' incorporates:
           *  Abs: '<S273>/Abs'
           *  Abs: '<S273>/Abs1'
           *  Constant: '<S282>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S282>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionStatus_k(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                             FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                             &rtb_state_k0, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S272>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_n;
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;
          switch (rtb_state_k0) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_n = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_n = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_n = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_n) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_n != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S272>/Hold Control' incorporates:
               *  ActionPort: '<S275>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S272>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S272>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S272>/Hold Control' incorporates:
             *  ActionPort: '<S275>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                            &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S272>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S272>/Brake Control' incorporates:
             *  ActionPort: '<S274>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S272>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S272>/Move Control' incorporates:
             *  ActionPort: '<S276>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S272>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S272>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S285>/Motion State' incorporates:
           *  Abs: '<S285>/Abs'
           *  Abs: '<S285>/Abs1'
           *  Constant: '<S295>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S295>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_k0,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S298>/Logical Operator' incorporates:
           *  Abs: '<S298>/Abs1'
           *  Abs: '<S298>/Abs2'
           *  Constant: '<S311>/Constant'
           *  Constant: '<S312>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S311>/Compare'
           *  RelationalOperator: '<S312>/Compare'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Chart: '<S298>/Motion State' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S298>/Square'
           *  Math: '<S298>/Square1'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sqrt: '<S298>/Sqrt'
           *  Sum: '<S298>/Add'
           */
          if (FMS_DW.temporalCounter_i1_g < 2047U) {
            FMS_DW.temporalCounter_i1_g++;
          }

          if (FMS_DW.is_active_c16_FMS == 0U) {
            FMS_DW.is_active_c16_FMS = 1U;
            FMS_DW.is_c16_FMS = FMS_IN_Move_a;
            rtb_state_ig = MotionState_Move;
          } else {
            switch (FMS_DW.is_c16_FMS) {
             case FMS_IN_Brake_m:
              rtb_state_ig = MotionState_Brake;

              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                         FMS_U.INS_Out.ve) <= 0.2) ||
                  (FMS_DW.temporalCounter_i1_g >= 2000U)) {
                FMS_DW.is_c16_FMS = FMS_IN_Hold_ow;
                rtb_state_ig = MotionState_Hold;
              } else {
                if (rtb_FixPtRelationalOperator_me) {
                  FMS_DW.is_c16_FMS = FMS_IN_Move_a;
                  rtb_state_ig = MotionState_Move;
                }
              }

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              break;

             case FMS_IN_Hold_ow:
              rtb_state_ig = MotionState_Hold;
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_a;
                rtb_state_ig = MotionState_Move;
              }
              break;

             default:
              rtb_state_ig = MotionState_Move;
              if (!rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c16_FMS = FMS_IN_Brake_m;
                FMS_DW.temporalCounter_i1_g = 0U;
                rtb_state_ig = MotionState_Brake;
              }
              break;
            }
          }

          /* End of Chart: '<S298>/Motion State' */

          /* SwitchCase: '<S297>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_bf;
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;
          switch (rtb_state_ig) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_bf = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_bf = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_bf = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_bf) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S297>/Hold Control' incorporates:
               *  ActionPort: '<S300>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S297>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_jz);

              /* End of SystemReset for SubSystem: '<S297>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S297>/Hold Control' incorporates:
             *  ActionPort: '<S300>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_jz, &FMS_DW.HoldControl_jz);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S297>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S297>/Brake Control' incorporates:
             *  ActionPort: '<S299>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S297>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S297>/Move Control' incorporates:
               *  ActionPort: '<S301>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S297>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S307>/Integrator'
               *  DiscreteIntegrator: '<S307>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_b[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_l[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_b[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_l[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S297>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S297>/Move Control' incorporates:
             *  ActionPort: '<S301>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* DeadZone: '<S305>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S30>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_a_o = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_a_o = 0.0F;
            } else {
              rtb_a_o = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
            }

            /* End of DeadZone: '<S305>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Gain: '<S305>/Gain' */
            rtb_Add3_a = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_a_o;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* DeadZone: '<S306>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S30>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_a_o = 0.0F;
            } else {
              rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S306>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Gain: '<S306>/Gain' */
            rtb_Add4_o = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_a_o;

            /* Sum: '<S308>/Sum of Elements' incorporates:
             *  Math: '<S308>/Square'
             *  SignalConversion: '<S308>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S309>/Sum of Elements'
             *  Switch: '<S301>/Switch'
             */
            rtb_a_o = rtb_Add3_a * rtb_Add3_a + rtb_Add4_o * rtb_Add4_o;

            /* Switch: '<S301>/Switch' incorporates:
             *  Product: '<S309>/Divide'
             *  Sqrt: '<S308>/Sqrt'
             *  Sum: '<S308>/Sum of Elements'
             */
            if (sqrtf(rtb_a_o) > 1.0F) {
              /* Math: '<S309>/Math Function1'
               *
               * About '<S309>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_a_o < 0.0F) {
                rtb_Subtract3_e = -sqrtf(fabsf(rtb_a_o));
              } else {
                rtb_Subtract3_e = sqrtf(rtb_a_o);
              }

              /* End of Math: '<S309>/Math Function1' */

              /* Switch: '<S309>/Switch' incorporates:
               *  Constant: '<S309>/Constant'
               *  Product: '<S309>/Product'
               */
              if (rtb_Subtract3_e > 0.0F) {
                rtb_Switch_kx[0] = rtb_Add3_a;
                rtb_Switch_kx[1] = rtb_Add4_o;
                rtb_Switch_kx[2] = rtb_Subtract3_e;
              } else {
                rtb_Switch_kx[0] = 0.0F;
                rtb_Switch_kx[1] = 0.0F;
                rtb_Switch_kx[2] = 1.0F;
              }

              /* End of Switch: '<S309>/Switch' */
              rtb_Add3_a = rtb_Switch_kx[0] / rtb_Switch_kx[2];
              rtb_Add4_o = rtb_Switch_kx[1] / rtb_Switch_kx[2];
            }

            /* Product: '<S310>/Multiply1' incorporates:
             *  Constant: '<S310>/const1'
             *  DiscreteIntegrator: '<S307>/Integrator'
             */
            rtb_Subtract3_e = FMS_DW.Integrator_DSTATE_l[0] * 0.05F;

            /* Sum: '<S310>/Add' incorporates:
             *  DiscreteIntegrator: '<S307>/Integrator1'
             *  Gain: '<S301>/Gain6'
             *  Sum: '<S307>/Subtract'
             */
            D = (FMS_DW.Integrator1_DSTATE_b[0] - FMS_PARAM.VEL_XY_LIM *
                 rtb_Add3_a) + rtb_Subtract3_e;

            /* Signum: '<S310>/Sign' */
            if (D < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else if (D > 0.0F) {
              rtb_Add3_a = 1.0F;
            } else {
              rtb_Add3_a = D;
            }

            /* Sum: '<S310>/Add2' incorporates:
             *  Abs: '<S310>/Abs'
             *  Gain: '<S310>/Gain'
             *  Gain: '<S310>/Gain1'
             *  Product: '<S310>/Multiply2'
             *  Product: '<S310>/Multiply3'
             *  Sqrt: '<S310>/Sqrt'
             *  Sum: '<S310>/Add1'
             *  Sum: '<S310>/Subtract'
             */
            rtb_P_p_idx_0 = (sqrtf((8.0F * fabsf(D) + FMS_ConstB.d_f) *
              FMS_ConstB.d_f) - FMS_ConstB.d_f) * 0.5F * rtb_Add3_a +
              rtb_Subtract3_e;

            /* Sum: '<S310>/Add4' */
            rtb_Subtract3_e += D - rtb_P_p_idx_0;

            /* Sum: '<S310>/Add3' */
            rtb_Add3_a = D + FMS_ConstB.d_f;

            /* Sum: '<S310>/Subtract1' */
            D -= FMS_ConstB.d_f;

            /* Signum: '<S310>/Sign1' */
            if (rtb_Add3_a < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else {
              if (rtb_Add3_a > 0.0F) {
                rtb_Add3_a = 1.0F;
              }
            }

            /* Signum: '<S310>/Sign2' */
            if (D < 0.0F) {
              D = -1.0F;
            } else {
              if (D > 0.0F) {
                D = 1.0F;
              }
            }

            /* Sum: '<S310>/Add5' incorporates:
             *  Gain: '<S310>/Gain2'
             *  Product: '<S310>/Multiply4'
             *  Sum: '<S310>/Subtract2'
             */
            rtb_P_p_idx_0 += (rtb_Add3_a - D) * 0.5F * rtb_Subtract3_e;

            /* SignalConversion: '<S307>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S307>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_b[0];

            /* Update for DiscreteIntegrator: '<S307>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S307>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_b[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_l[0];

            /* Signum: '<S310>/Sign4' incorporates:
             *  Sum: '<S310>/Subtract3'
             */
            rtb_Add3_a = rtb_P_p_idx_0 - FMS_ConstB.d_f;

            /* Signum: '<S310>/Sign3' incorporates:
             *  Sum: '<S310>/Add6'
             */
            rtb_Subtract3_e = rtb_P_p_idx_0 + FMS_ConstB.d_f;

            /* Signum: '<S310>/Sign5' */
            if (rtb_P_p_idx_0 < 0.0F) {
              rtb_a_o = -1.0F;
            } else if (rtb_P_p_idx_0 > 0.0F) {
              rtb_a_o = 1.0F;
            } else {
              rtb_a_o = rtb_P_p_idx_0;
            }

            /* Signum: '<S310>/Sign3' */
            if (rtb_Subtract3_e < 0.0F) {
              rtb_Subtract3_e = -1.0F;
            } else {
              if (rtb_Subtract3_e > 0.0F) {
                rtb_Subtract3_e = 1.0F;
              }
            }

            /* Signum: '<S310>/Sign4' */
            if (rtb_Add3_a < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else {
              if (rtb_Add3_a > 0.0F) {
                rtb_Add3_a = 1.0F;
              }
            }

            /* Signum: '<S310>/Sign6' */
            if (rtb_P_p_idx_0 < 0.0F) {
              rtb_Switch_n_idx_1 = -1.0F;
            } else if (rtb_P_p_idx_0 > 0.0F) {
              rtb_Switch_n_idx_1 = 1.0F;
            } else {
              rtb_Switch_n_idx_1 = rtb_P_p_idx_0;
            }

            /* Update for DiscreteIntegrator: '<S307>/Integrator' incorporates:
             *  Constant: '<S310>/const'
             *  Gain: '<S310>/Gain3'
             *  Product: '<S310>/Divide'
             *  Product: '<S310>/Multiply5'
             *  Product: '<S310>/Multiply6'
             *  Sum: '<S310>/Subtract4'
             *  Sum: '<S310>/Subtract5'
             *  Sum: '<S310>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_l[0] += ((rtb_P_p_idx_0 / FMS_ConstB.d_f -
              rtb_a_o) * FMS_ConstB.Gain4_f * ((rtb_Subtract3_e - rtb_Add3_a) *
              0.5F) - rtb_Switch_n_idx_1 * 58.836F) * 0.004F;

            /* Product: '<S310>/Multiply1' incorporates:
             *  Constant: '<S310>/const1'
             *  DiscreteIntegrator: '<S307>/Integrator'
             */
            rtb_Subtract3_e = FMS_DW.Integrator_DSTATE_l[1] * 0.05F;

            /* Sum: '<S310>/Add' incorporates:
             *  DiscreteIntegrator: '<S307>/Integrator1'
             *  Gain: '<S301>/Gain6'
             *  Sum: '<S307>/Subtract'
             */
            D = (FMS_DW.Integrator1_DSTATE_b[1] - FMS_PARAM.VEL_XY_LIM *
                 rtb_Add4_o) + rtb_Subtract3_e;

            /* Signum: '<S310>/Sign' */
            if (D < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else if (D > 0.0F) {
              rtb_Add3_a = 1.0F;
            } else {
              rtb_Add3_a = D;
            }

            /* Sum: '<S310>/Add2' incorporates:
             *  Abs: '<S310>/Abs'
             *  Gain: '<S310>/Gain'
             *  Gain: '<S310>/Gain1'
             *  Product: '<S310>/Multiply2'
             *  Product: '<S310>/Multiply3'
             *  Sqrt: '<S310>/Sqrt'
             *  Sum: '<S310>/Add1'
             *  Sum: '<S310>/Subtract'
             */
            rtb_P_p_idx_0 = (sqrtf((8.0F * fabsf(D) + FMS_ConstB.d_f) *
              FMS_ConstB.d_f) - FMS_ConstB.d_f) * 0.5F * rtb_Add3_a +
              rtb_Subtract3_e;

            /* Sum: '<S310>/Add4' */
            rtb_Subtract3_e += D - rtb_P_p_idx_0;

            /* Sum: '<S310>/Add3' */
            rtb_Add3_a = D + FMS_ConstB.d_f;

            /* Sum: '<S310>/Subtract1' */
            D -= FMS_ConstB.d_f;

            /* Signum: '<S310>/Sign1' */
            if (rtb_Add3_a < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else {
              if (rtb_Add3_a > 0.0F) {
                rtb_Add3_a = 1.0F;
              }
            }

            /* Signum: '<S310>/Sign2' */
            if (D < 0.0F) {
              D = -1.0F;
            } else {
              if (D > 0.0F) {
                D = 1.0F;
              }
            }

            /* Sum: '<S310>/Add5' incorporates:
             *  Gain: '<S310>/Gain2'
             *  Product: '<S310>/Multiply4'
             *  Sum: '<S310>/Subtract2'
             */
            rtb_P_p_idx_0 += (rtb_Add3_a - D) * 0.5F * rtb_Subtract3_e;

            /* SignalConversion: '<S307>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S307>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_b[1];

            /* Update for DiscreteIntegrator: '<S307>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S307>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_b[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_l[1];

            /* Signum: '<S310>/Sign4' incorporates:
             *  Sum: '<S310>/Subtract3'
             */
            rtb_Add3_a = rtb_P_p_idx_0 - FMS_ConstB.d_f;

            /* Signum: '<S310>/Sign3' incorporates:
             *  Sum: '<S310>/Add6'
             */
            rtb_Subtract3_e = rtb_P_p_idx_0 + FMS_ConstB.d_f;

            /* Signum: '<S310>/Sign5' */
            if (rtb_P_p_idx_0 < 0.0F) {
              rtb_a_o = -1.0F;
            } else if (rtb_P_p_idx_0 > 0.0F) {
              rtb_a_o = 1.0F;
            } else {
              rtb_a_o = rtb_P_p_idx_0;
            }

            /* Signum: '<S310>/Sign3' */
            if (rtb_Subtract3_e < 0.0F) {
              rtb_Subtract3_e = -1.0F;
            } else {
              if (rtb_Subtract3_e > 0.0F) {
                rtb_Subtract3_e = 1.0F;
              }
            }

            /* Signum: '<S310>/Sign4' */
            if (rtb_Add3_a < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else {
              if (rtb_Add3_a > 0.0F) {
                rtb_Add3_a = 1.0F;
              }
            }

            /* Signum: '<S310>/Sign6' */
            if (rtb_P_p_idx_0 < 0.0F) {
              rtb_Switch_n_idx_1 = -1.0F;
            } else if (rtb_P_p_idx_0 > 0.0F) {
              rtb_Switch_n_idx_1 = 1.0F;
            } else {
              rtb_Switch_n_idx_1 = rtb_P_p_idx_0;
            }

            /* Update for DiscreteIntegrator: '<S307>/Integrator' incorporates:
             *  Constant: '<S310>/const'
             *  Gain: '<S310>/Gain3'
             *  Product: '<S310>/Divide'
             *  Product: '<S310>/Multiply5'
             *  Product: '<S310>/Multiply6'
             *  Sum: '<S310>/Subtract4'
             *  Sum: '<S310>/Subtract5'
             *  Sum: '<S310>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_l[1] += ((rtb_P_p_idx_0 / FMS_ConstB.d_f -
              rtb_a_o) * FMS_ConstB.Gain4_f * ((rtb_Subtract3_e - rtb_Add3_a) *
              0.5F) - rtb_Switch_n_idx_1 * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S297>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S297>/Switch Case' */

          /* SwitchCase: '<S284>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_g;
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          switch (rtb_state_k0) {
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
              /* SystemReset for IfAction SubSystem: '<S284>/Hold Control' incorporates:
               *  ActionPort: '<S287>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S284>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S284>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S284>/Hold Control' incorporates:
             *  ActionPort: '<S287>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S284>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S284>/Brake Control' incorporates:
             *  ActionPort: '<S286>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S284>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S284>/Move Control' incorporates:
               *  ActionPort: '<S288>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S284>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S284>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S284>/Move Control' incorporates:
             *  ActionPort: '<S288>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S284>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S284>/Switch Case' */

          /* BusAssignment: '<S230>/Bus Assignment' incorporates:
           *  Constant: '<S230>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_du;

          /* Saturate: '<S284>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S284>/Saturation' */

          /* Saturate: '<S297>/Saturation1' */
          if (FMS_B.Merge_f[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_f[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_f[0];
          }

          if (FMS_B.Merge_f[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_f[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_f[1];
          }

          /* End of Saturate: '<S297>/Saturation1' */

          /* Saturate: '<S272>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S230>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S272>/Saturation1' */
          /* End of Outputs for SubSystem: '<S223>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S223>/Unknown' incorporates:
           *  ActionPort: '<S232>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

          /* End of Outputs for SubSystem: '<S223>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S223>/Switch Case' */
        /* End of Outputs for SubSystem: '<S36>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S36>/Manual' incorporates:
         *  ActionPort: '<S225>/Action Port'
         */
        /* BusAssignment: '<S225>/Bus Assignment' incorporates:
         *  Constant: '<S225>/Constant'
         *  Constant: '<S225>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_h;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_is;

        /* End of Outputs for SubSystem: '<S36>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S36>/Unknown' incorporates:
         *  ActionPort: '<S227>/Action Port'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

        /* End of Outputs for SubSystem: '<S36>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S36>/Switch Case' */
      /* End of Outputs for SubSystem: '<S31>/MC_Mode' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S31>/FW_Mode' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* SwitchCase: '<S35>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_p;

      /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Land:
       case VehicleState_Return:
       case VehicleState_Takeoff:
       case VehicleState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_p = 0;
        break;

       case VehicleState_Offboard:
       case VehicleState_Mission:
        FMS_DW.SwitchCase_ActiveSubsystem_p = 1;
        break;

       case VehicleState_Acro:
       case VehicleState_Stabilize:
       case VehicleState_Altitude:
       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_p = 2;
        break;

       case VehicleState_Manual:
        FMS_DW.SwitchCase_ActiveSubsystem_p = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_p = 4;
        break;
      }

      /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_p) {
        switch (rtPrevAction) {
         case 0:
          /* Disable for SwitchCase: '<S40>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S38>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S37>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S50>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S85>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S71>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
          break;

         case 3:
         case 4:
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_p) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S35>/SubMode' incorporates:
         *  ActionPort: '<S40>/Action Port'
         */
        /* SwitchCase: '<S40>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_kv;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        switch (FMS_B.state) {
         case VehicleState_Takeoff:
          FMS_DW.SwitchCase_ActiveSubsystem_kv = 0;
          break;

         case VehicleState_Land:
          FMS_DW.SwitchCase_ActiveSubsystem_kv = 1;
          break;

         case VehicleState_Return:
          FMS_DW.SwitchCase_ActiveSubsystem_kv = 2;
          break;

         case VehicleState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_kv = 3;
          break;

         default:
          FMS_DW.SwitchCase_ActiveSubsystem_kv = 4;
          break;
        }

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_kv) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S40>/Takeoff' incorporates:
           *  ActionPort: '<S159>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Math: '<S218>/Math Function' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Sum_k[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
          rtb_Sum_k[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* Sum: '<S218>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S218>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_a_o = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S218>/Math Function1' incorporates:
           *  Sum: '<S218>/Sum of Elements'
           *
           * About '<S218>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S218>/Math Function1' */

          /* Switch: '<S218>/Switch' incorporates:
           *  Constant: '<S218>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S218>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Add3_a > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Add4_o = FMS_U.INS_Out.vn;
            rtb_Switch_n_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Sqrt_h = rtb_Add3_a;
          } else {
            rtb_Add4_o = 0.0F;
            rtb_Switch_n_idx_1 = 0.0F;
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S218>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S208>/NearbyRefWP' incorporates:
           *  Constant: '<S206>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_kx[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Sum_k,
                          &rtb_Subtract3_e);

          /* MATLAB Function: '<S208>/SearchL1RefWP' incorporates:
           *  Constant: '<S206>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_TmpSignalConversionAtMath_l[0], &rtb_Switch_kx
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_TmpSignalConversionAtMath_j,
                            &rtb_Add3_a);

          /* MATLAB Function: '<S208>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_TmpSignalConversionAtMath_l[0],
                             &rtb_Switch_kx[0], FMS_U.INS_Out.x_R,
                             FMS_U.INS_Out.y_R, rtb_TmpSignalConversionAtDela_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S208>/Switch1' incorporates:
           *  Constant: '<S211>/Constant'
           *  RelationalOperator: '<S211>/Compare'
           */
          if (rtb_Subtract3_e > 0.0F) {
            rtb_TmpSignalConversionAtMath_j[0] = rtb_Sum_k[0];
            rtb_TmpSignalConversionAtMath_j[1] = rtb_Sum_k[1];
          } else {
            /* RelationalOperator: '<S210>/Compare' incorporates:
             *  Constant: '<S210>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Add3_a >= 0.0F);

            /* Switch: '<S208>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_TmpSignalConversionAtMath_j[0] =
                rtb_TmpSignalConversionAtDela_a[0];
              rtb_TmpSignalConversionAtMath_j[1] =
                rtb_TmpSignalConversionAtDela_a[1];
            }

            /* End of Switch: '<S208>/Switch' */
          }

          /* End of Switch: '<S208>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S209>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Sum_k[0] = rtb_TmpSignalConversionAtMath_j[0] - FMS_U.INS_Out.x_R;
          rtb_Sum_k[1] = rtb_TmpSignalConversionAtMath_j[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S219>/Sum of Elements' incorporates:
           *  Math: '<S219>/Math Function'
           */
          rtb_a_o = rtb_Sum_k[0] * rtb_Sum_k[0] + rtb_Sum_k[1] * rtb_Sum_k[1];

          /* Math: '<S219>/Math Function1' incorporates:
           *  Sum: '<S219>/Sum of Elements'
           *
           * About '<S219>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S219>/Math Function1' */

          /* Switch: '<S219>/Switch' incorporates:
           *  Constant: '<S219>/Constant'
           *  Product: '<S219>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Switch_kx[0] = rtb_Sum_k[0];
            rtb_Switch_kx[1] = rtb_Sum_k[1];
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S219>/Switch' */

          /* Product: '<S218>/Divide' */
          rtb_Sum_k[0] = rtb_Add4_o / rtb_Sqrt_h;
          rtb_Sum_k[1] = rtb_Switch_n_idx_1 / rtb_Sqrt_h;

          /* Sum: '<S221>/Sum of Elements' incorporates:
           *  Math: '<S221>/Math Function'
           *  SignalConversion: '<S221>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_o = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] * rtb_Sum_k[0];

          /* Math: '<S221>/Math Function1' incorporates:
           *  Sum: '<S221>/Sum of Elements'
           *
           * About '<S221>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S221>/Math Function1' */

          /* Switch: '<S221>/Switch' incorporates:
           *  Constant: '<S221>/Constant'
           *  Product: '<S221>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Add4_o = rtb_Sum_k[1];
            rtb_Switch_n_idx_1 = rtb_Sum_k[0];
            rtb_Sqrt_h = rtb_Add3_a;
          } else {
            rtb_Add4_o = 0.0F;
            rtb_Switch_n_idx_1 = 0.0F;
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S221>/Switch' */

          /* Product: '<S219>/Divide' */
          rtb_Sum_k[0] = rtb_Switch_kx[0] / rtb_Switch_kx[2];
          rtb_Sum_k[1] = rtb_Switch_kx[1] / rtb_Switch_kx[2];

          /* Sum: '<S222>/Sum of Elements' incorporates:
           *  Math: '<S222>/Math Function'
           *  SignalConversion: '<S222>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_o = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] * rtb_Sum_k[0];

          /* Math: '<S222>/Math Function1' incorporates:
           *  Sum: '<S222>/Sum of Elements'
           *
           * About '<S222>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S222>/Math Function1' */

          /* Switch: '<S222>/Switch' incorporates:
           *  Constant: '<S222>/Constant'
           *  Product: '<S222>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Switch_kx[0] = rtb_Sum_k[1];
            rtb_Switch_kx[1] = rtb_Sum_k[0];
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S222>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S203>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_o = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Subtract3_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S222>/Divide' */
          rtb_Sum_k[0] = rtb_Switch_kx[0] / rtb_Switch_kx[2];

          /* Product: '<S221>/Divide' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_Add4_o / rtb_Sqrt_h;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S203>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_a = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S222>/Divide' */
          rtb_Sum_k[1] = rtb_Switch_kx[1] / rtb_Switch_kx[2];

          /* Product: '<S221>/Divide' */
          rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_n_idx_1 / rtb_Sqrt_h;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S203>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_o = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S203>/Divide' incorporates:
           *  Math: '<S204>/Square'
           *  Math: '<S205>/Square'
           *  Sqrt: '<S204>/Sqrt'
           *  Sqrt: '<S205>/Sqrt'
           *  Sum: '<S203>/Sum'
           *  Sum: '<S203>/Sum1'
           *  Sum: '<S204>/Sum of Elements'
           *  Sum: '<S205>/Sum of Elements'
           */
          rtb_a_o = sqrtf(rtb_Subtract3_e * rtb_Subtract3_e + rtb_a_o * rtb_a_o)
            / sqrtf(rtb_Add3_a * rtb_Add3_a + rtb_Add4_o * rtb_Add4_o);

          /* Saturate: '<S203>/Saturation' */
          if (rtb_a_o > 1.0F) {
            rtb_a_o = 1.0F;
          } else {
            if (rtb_a_o < 0.0F) {
              rtb_a_o = 0.0F;
            }
          }

          /* End of Saturate: '<S203>/Saturation' */

          /* Sum: '<S220>/Subtract' incorporates:
           *  Product: '<S220>/Multiply'
           *  Product: '<S220>/Multiply1'
           */
          rtb_Add3_a = rtb_Sum_k[0] * rtb_TmpSignalConversionAtMath_j[1] -
            rtb_Sum_k[1] * rtb_TmpSignalConversionAtMath_j[0];

          /* Signum: '<S216>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S216>/Sign1' */

          /* Switch: '<S216>/Switch2' incorporates:
           *  Constant: '<S216>/Constant4'
           */
          if (rtb_Add3_a == 0.0F) {
            rtb_Add3_a = 1.0F;
          }

          /* End of Switch: '<S216>/Switch2' */

          /* DotProduct: '<S216>/Dot Product' */
          rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_j[0] * rtb_Sum_k[0] +
            rtb_TmpSignalConversionAtMath_j[1] * rtb_Sum_k[1];

          /* Trigonometry: '<S216>/Acos' incorporates:
           *  DotProduct: '<S216>/Dot Product'
           */
          if (rtb_Subtract3_e > 1.0F) {
            rtb_Subtract3_e = 1.0F;
          } else {
            if (rtb_Subtract3_e < -1.0F) {
              rtb_Subtract3_e = -1.0F;
            }
          }

          /* Product: '<S216>/Multiply' incorporates:
           *  Trigonometry: '<S216>/Acos'
           */
          rtb_Add3_a *= acosf(rtb_Subtract3_e);

          /* Saturate: '<S215>/Saturation' */
          if (rtb_Add3_a > 1.57079637F) {
            rtb_Add3_a = 1.57079637F;
          } else {
            if (rtb_Add3_a < -1.57079637F) {
              rtb_Add3_a = -1.57079637F;
            }
          }

          /* End of Saturate: '<S215>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S217>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S217>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S217>/Sum of Elements'
           */
          rtb_Subtract3_e = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S159>/Bus Assignment' incorporates:
           *  Constant: '<S159>/Constant'
           *  Constant: '<S159>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S215>/Divide' incorporates:
           *  Constant: '<S206>/L1'
           *  Gain: '<S215>/Gain'
           *  Math: '<S215>/Square'
           *  Product: '<S215>/Multiply1'
           *  Trigonometry: '<S215>/Sin'
           */
          rtb_Switch_n_idx_1 = rtb_Subtract3_e * rtb_Subtract3_e * 2.0F *
            arm_sin_f32(rtb_Add3_a) / FMS_PARAM.FW_L1;

          /* Saturate: '<S206>/Saturation1' */
          if (rtb_Switch_n_idx_1 > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Switch_n_idx_1 < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Switch_n_idx_1;
          }

          /* End of Saturate: '<S206>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S201>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S203>/Multiply'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S201>/Sum2'
           *  Sum: '<S203>/Add'
           *  Sum: '<S203>/Subtract'
           */
          rtb_Switch_n_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_a_o +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S201>/Saturation1' */
          if (rtb_Switch_n_idx_1 > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Switch_n_idx_1 < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S159>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Switch_n_idx_1;
          }

          /* End of Saturate: '<S201>/Saturation1' */
          /* End of Outputs for SubSystem: '<S40>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S40>/Land' incorporates:
           *  ActionPort: '<S157>/Action Port'
           */
          /* BusAssignment: '<S157>/Bus Assignment1' incorporates:
           *  Constant: '<S157>/Constant'
           *  Constant: '<S157>/Constant1'
           *  Constant: '<S157>/Constant4'
           *  Constant: '<S157>/Constant5'
           *  Constant: '<S157>/Constant7'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_h;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
          FMS_Y.FMS_Out.u_cmd = 0.0F;
          FMS_Y.FMS_Out.v_cmd = 0.0F;
          FMS_Y.FMS_Out.w_cmd = 0.5F;

          /* End of Outputs for SubSystem: '<S40>/Land' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S40>/Return' incorporates:
           *  ActionPort: '<S158>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Math: '<S196>/Math Function' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Sum_k[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
          rtb_Sum_k[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* Sum: '<S196>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S196>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_a_o = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S196>/Math Function1' incorporates:
           *  Sum: '<S196>/Sum of Elements'
           *
           * About '<S196>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S196>/Math Function1' */

          /* Switch: '<S196>/Switch' incorporates:
           *  Constant: '<S196>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S196>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Add3_a > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Add4_o = FMS_U.INS_Out.vn;
            rtb_Switch_n_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Sqrt_h = rtb_Add3_a;
          } else {
            rtb_Add4_o = 0.0F;
            rtb_Switch_n_idx_1 = 0.0F;
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S196>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S186>/NearbyRefWP' incorporates:
           *  Constant: '<S184>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_kx[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Sum_k,
                          &rtb_Subtract3_e);

          /* MATLAB Function: '<S186>/SearchL1RefWP' incorporates:
           *  Constant: '<S184>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_TmpSignalConversionAtMath_l[0], &rtb_Switch_kx
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_TmpSignalConversionAtMath_j,
                            &rtb_Add3_a);

          /* MATLAB Function: '<S186>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_TmpSignalConversionAtMath_l[0],
                             &rtb_Switch_kx[0], FMS_U.INS_Out.x_R,
                             FMS_U.INS_Out.y_R, rtb_TmpSignalConversionAtDela_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S186>/Switch1' incorporates:
           *  Constant: '<S189>/Constant'
           *  RelationalOperator: '<S189>/Compare'
           */
          if (rtb_Subtract3_e > 0.0F) {
            rtb_TmpSignalConversionAtMath_j[0] = rtb_Sum_k[0];
            rtb_TmpSignalConversionAtMath_j[1] = rtb_Sum_k[1];
          } else {
            /* RelationalOperator: '<S188>/Compare' incorporates:
             *  Constant: '<S188>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Add3_a >= 0.0F);

            /* Switch: '<S186>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_TmpSignalConversionAtMath_j[0] =
                rtb_TmpSignalConversionAtDela_a[0];
              rtb_TmpSignalConversionAtMath_j[1] =
                rtb_TmpSignalConversionAtDela_a[1];
            }

            /* End of Switch: '<S186>/Switch' */
          }

          /* End of Switch: '<S186>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S187>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Sum_k[0] = rtb_TmpSignalConversionAtMath_j[0] - FMS_U.INS_Out.x_R;
          rtb_Sum_k[1] = rtb_TmpSignalConversionAtMath_j[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S197>/Sum of Elements' incorporates:
           *  Math: '<S197>/Math Function'
           */
          rtb_a_o = rtb_Sum_k[0] * rtb_Sum_k[0] + rtb_Sum_k[1] * rtb_Sum_k[1];

          /* Math: '<S197>/Math Function1' incorporates:
           *  Sum: '<S197>/Sum of Elements'
           *
           * About '<S197>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S197>/Math Function1' */

          /* Switch: '<S197>/Switch' incorporates:
           *  Constant: '<S197>/Constant'
           *  Product: '<S197>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Switch_kx[0] = rtb_Sum_k[0];
            rtb_Switch_kx[1] = rtb_Sum_k[1];
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S197>/Switch' */

          /* Product: '<S196>/Divide' */
          rtb_Sum_k[0] = rtb_Add4_o / rtb_Sqrt_h;
          rtb_Sum_k[1] = rtb_Switch_n_idx_1 / rtb_Sqrt_h;

          /* Sum: '<S199>/Sum of Elements' incorporates:
           *  Math: '<S199>/Math Function'
           *  SignalConversion: '<S199>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_o = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] * rtb_Sum_k[0];

          /* Math: '<S199>/Math Function1' incorporates:
           *  Sum: '<S199>/Sum of Elements'
           *
           * About '<S199>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S199>/Math Function1' */

          /* Switch: '<S199>/Switch' incorporates:
           *  Constant: '<S199>/Constant'
           *  Product: '<S199>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Add4_o = rtb_Sum_k[1];
            rtb_Switch_n_idx_1 = rtb_Sum_k[0];
            rtb_Sqrt_h = rtb_Add3_a;
          } else {
            rtb_Add4_o = 0.0F;
            rtb_Switch_n_idx_1 = 0.0F;
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S199>/Switch' */

          /* Product: '<S197>/Divide' */
          rtb_Sum_k[0] = rtb_Switch_kx[0] / rtb_Switch_kx[2];
          rtb_Sum_k[1] = rtb_Switch_kx[1] / rtb_Switch_kx[2];

          /* Sum: '<S200>/Sum of Elements' incorporates:
           *  Math: '<S200>/Math Function'
           *  SignalConversion: '<S200>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_o = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] * rtb_Sum_k[0];

          /* Math: '<S200>/Math Function1' incorporates:
           *  Sum: '<S200>/Sum of Elements'
           *
           * About '<S200>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S200>/Math Function1' */

          /* Switch: '<S200>/Switch' incorporates:
           *  Constant: '<S200>/Constant'
           *  Product: '<S200>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Switch_kx[0] = rtb_Sum_k[1];
            rtb_Switch_kx[1] = rtb_Sum_k[0];
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S200>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S181>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_o = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Subtract3_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S200>/Divide' */
          rtb_Sum_k[0] = rtb_Switch_kx[0] / rtb_Switch_kx[2];

          /* Product: '<S199>/Divide' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_Add4_o / rtb_Sqrt_h;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S181>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_a = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S200>/Divide' */
          rtb_Sum_k[1] = rtb_Switch_kx[1] / rtb_Switch_kx[2];

          /* Product: '<S199>/Divide' */
          rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_n_idx_1 / rtb_Sqrt_h;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S181>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_o = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S181>/Divide' incorporates:
           *  Math: '<S182>/Square'
           *  Math: '<S183>/Square'
           *  Sqrt: '<S182>/Sqrt'
           *  Sqrt: '<S183>/Sqrt'
           *  Sum: '<S181>/Sum'
           *  Sum: '<S181>/Sum1'
           *  Sum: '<S182>/Sum of Elements'
           *  Sum: '<S183>/Sum of Elements'
           */
          rtb_a_o = sqrtf(rtb_Subtract3_e * rtb_Subtract3_e + rtb_a_o * rtb_a_o)
            / sqrtf(rtb_Add3_a * rtb_Add3_a + rtb_Add4_o * rtb_Add4_o);

          /* Saturate: '<S181>/Saturation' */
          if (rtb_a_o > 1.0F) {
            rtb_a_o = 1.0F;
          } else {
            if (rtb_a_o < 0.0F) {
              rtb_a_o = 0.0F;
            }
          }

          /* End of Saturate: '<S181>/Saturation' */

          /* Sum: '<S198>/Subtract' incorporates:
           *  Product: '<S198>/Multiply'
           *  Product: '<S198>/Multiply1'
           */
          rtb_Add3_a = rtb_Sum_k[0] * rtb_TmpSignalConversionAtMath_j[1] -
            rtb_Sum_k[1] * rtb_TmpSignalConversionAtMath_j[0];

          /* Signum: '<S194>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S194>/Sign1' */

          /* Switch: '<S194>/Switch2' incorporates:
           *  Constant: '<S194>/Constant4'
           */
          if (rtb_Add3_a == 0.0F) {
            rtb_Add3_a = 1.0F;
          }

          /* End of Switch: '<S194>/Switch2' */

          /* DotProduct: '<S194>/Dot Product' */
          rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_j[0] * rtb_Sum_k[0] +
            rtb_TmpSignalConversionAtMath_j[1] * rtb_Sum_k[1];

          /* Trigonometry: '<S194>/Acos' incorporates:
           *  DotProduct: '<S194>/Dot Product'
           */
          if (rtb_Subtract3_e > 1.0F) {
            rtb_Subtract3_e = 1.0F;
          } else {
            if (rtb_Subtract3_e < -1.0F) {
              rtb_Subtract3_e = -1.0F;
            }
          }

          /* Product: '<S194>/Multiply' incorporates:
           *  Trigonometry: '<S194>/Acos'
           */
          rtb_Add3_a *= acosf(rtb_Subtract3_e);

          /* Saturate: '<S193>/Saturation' */
          if (rtb_Add3_a > 1.57079637F) {
            rtb_Add3_a = 1.57079637F;
          } else {
            if (rtb_Add3_a < -1.57079637F) {
              rtb_Add3_a = -1.57079637F;
            }
          }

          /* End of Saturate: '<S193>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S195>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S195>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S195>/Sum of Elements'
           */
          rtb_Subtract3_e = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S158>/Bus Assignment1' incorporates:
           *  Constant: '<S158>/Constant2'
           *  Constant: '<S158>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S193>/Divide' incorporates:
           *  Constant: '<S184>/L1'
           *  Gain: '<S193>/Gain'
           *  Math: '<S193>/Square'
           *  Product: '<S193>/Multiply1'
           *  Trigonometry: '<S193>/Sin'
           */
          rtb_Switch_n_idx_1 = rtb_Subtract3_e * rtb_Subtract3_e * 2.0F *
            arm_sin_f32(rtb_Add3_a) / FMS_PARAM.FW_L1;

          /* Saturate: '<S184>/Saturation1' */
          if (rtb_Switch_n_idx_1 > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S158>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Switch_n_idx_1 < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S158>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S158>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Switch_n_idx_1;
          }

          /* End of Saturate: '<S184>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S179>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S181>/Multiply'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S179>/Sum2'
           *  Sum: '<S181>/Add'
           *  Sum: '<S181>/Subtract'
           */
          rtb_Switch_n_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_a_o +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S179>/Saturation1' */
          if (rtb_Switch_n_idx_1 > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S158>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Switch_n_idx_1 < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S158>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S158>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = rtb_Switch_n_idx_1;
          }

          /* End of Saturate: '<S179>/Saturation1' */
          /* End of Outputs for SubSystem: '<S40>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S40>/Hold' incorporates:
             *  ActionPort: '<S156>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S40>/Switch Case' incorporates:
             *  Delay: '<S161>/Delay'
             *  Delay: '<S166>/start_vel'
             */
            FMS_DW.icLoad_l = 1U;
            FMS_DW.icLoad_m = 1U;

            /* End of InitializeConditions for SubSystem: '<S40>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S40>/Hold' incorporates:
           *  ActionPort: '<S156>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S173>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S173>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_a_o = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S173>/Math Function1' incorporates:
           *  Sum: '<S173>/Sum of Elements'
           *
           * About '<S173>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S173>/Math Function1' */

          /* Switch: '<S173>/Switch' incorporates:
           *  Constant: '<S173>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S173>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Add3_a > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_kx[0] = FMS_U.INS_Out.vn;
            rtb_Switch_kx[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S173>/Switch' */

          /* Delay: '<S166>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_l != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.start_vel_DSTATE_l[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE_l[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Sum: '<S178>/Sum of Elements' incorporates:
           *  Delay: '<S166>/start_vel'
           *  Math: '<S178>/Math Function'
           */
          rtb_a_o = FMS_DW.start_vel_DSTATE_l[0] * FMS_DW.start_vel_DSTATE_l[0]
            + FMS_DW.start_vel_DSTATE_l[1] * FMS_DW.start_vel_DSTATE_l[1];

          /* Math: '<S178>/Math Function1' incorporates:
           *  Sum: '<S178>/Sum of Elements'
           *
           * About '<S178>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S178>/Math Function1' */

          /* Switch: '<S178>/Switch' incorporates:
           *  Constant: '<S178>/Constant'
           *  Delay: '<S166>/start_vel'
           *  Product: '<S178>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_TmpSignalConversionAtMath_l[0] = FMS_DW.start_vel_DSTATE_l[0];
            rtb_TmpSignalConversionAtMath_l[1] = FMS_DW.start_vel_DSTATE_l[1];
            rtb_TmpSignalConversionAtMath_l[2] = rtb_Add3_a;
          } else {
            rtb_TmpSignalConversionAtMath_l[0] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[1] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[2] = 1.0F;
          }

          /* End of Switch: '<S178>/Switch' */

          /* Product: '<S173>/Divide' */
          rtb_Sum_k[0] = rtb_Switch_kx[0] / rtb_Switch_kx[2];
          rtb_Sum_k[1] = rtb_Switch_kx[1] / rtb_Switch_kx[2];

          /* Sum: '<S176>/Sum of Elements' incorporates:
           *  Math: '<S176>/Math Function'
           *  SignalConversion: '<S176>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_o = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] * rtb_Sum_k[0];

          /* Math: '<S176>/Math Function1' incorporates:
           *  Sum: '<S176>/Sum of Elements'
           *
           * About '<S176>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S176>/Math Function1' */

          /* Switch: '<S176>/Switch' incorporates:
           *  Constant: '<S176>/Constant'
           *  Product: '<S176>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Switch_kx[0] = rtb_Sum_k[1];
            rtb_Switch_kx[1] = rtb_Sum_k[0];
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S176>/Switch' */

          /* MinMax: '<S164>/Max' incorporates:
           *  Constant: '<S162>/L1'
           *  Constant: '<S162>/R'
           *  Gain: '<S164>/Gain'
           */
          rtb_Subtract3_e = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F * FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S164>/SearchL1RefWP' incorporates:
           *  Constant: '<S162>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_TmpSignalConversionAtMath_j[0] = 0.0F;
          rtb_TmpSignalConversionAtMath_j[1] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          if ((FMS_U.INS_Out.x_R == FMS_B.Cmd_In.cur_waypoint[0]) &&
              (FMS_U.INS_Out.y_R == FMS_B.Cmd_In.cur_waypoint[1]) &&
              (rtb_Subtract3_e == FMS_PARAM.FW_L1)) {
            rtb_n = 0;
          } else {
            rtb_Add3_a = FMS_B.Cmd_In.cur_waypoint[0] - FMS_U.INS_Out.x_R;
            rtb_TmpSignalConversionAtDela_a[0] = rtb_Add3_a * rtb_Add3_a;
            rtb_MathFunction_cx[0] = rtb_Add3_a;
            rtb_Add3_a = FMS_B.Cmd_In.cur_waypoint[1] - FMS_U.INS_Out.y_R;
            rtb_a_o = sqrtf(rtb_Add3_a * rtb_Add3_a +
                            rtb_TmpSignalConversionAtDela_a[0]);
            rtb_Switch_n_idx_1 = FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1;
            rtb_Add4_o = ((rtb_a_o * rtb_a_o + rtb_Switch_n_idx_1) -
                          rtb_Subtract3_e * rtb_Subtract3_e) / (2.0F * rtb_a_o);
            rtb_MathFunction_cx[0] /= rtb_a_o;
            rtb_Add3_a /= rtb_a_o;
            rtb_a_o = rtb_Add4_o * rtb_Add4_o;
            if (rtb_a_o > rtb_Switch_n_idx_1) {
              rtb_n = 0;
            } else if (rtb_a_o == rtb_Switch_n_idx_1) {
              rtb_n = 1;
              rtb_TmpSignalConversionAtMath_j[0] = rtb_Add4_o *
                rtb_MathFunction_cx[0] + FMS_U.INS_Out.x_R;
              rtb_TmpSignalConversionAtMath_j[1] = rtb_Add4_o * rtb_Add3_a +
                FMS_U.INS_Out.y_R;
            } else {
              rtb_n = 2;
              rtb_a_o = sqrtf(rtb_Switch_n_idx_1 - rtb_a_o);
              rtb_TmpSignalConversionAtMath_j[0] = (rtb_Add4_o *
                rtb_MathFunction_cx[0] + FMS_U.INS_Out.x_R) + rtb_a_o *
                -rtb_Add3_a;
              rtb_TmpSignalConversionAtMath_j[1] = (rtb_Add4_o * rtb_Add3_a +
                FMS_U.INS_Out.y_R) + rtb_a_o * rtb_MathFunction_cx[0];
            }
          }

          /* End of MATLAB Function: '<S164>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* RelationalOperator: '<S167>/Compare' incorporates:
           *  Constant: '<S167>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S164>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_a = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtDela_a[0] = rtb_Add3_a * rtb_Add3_a;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          rtb_Add3_a = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          rtb_TmpSignalConversionAtDela_a[1] = rtb_Add3_a * rtb_Add3_a;

          /* Switch: '<S164>/Switch' incorporates:
           *  Constant: '<S162>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S164>/OutRegionRegWP'
           *  Product: '<S178>/Divide'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Add3_a = rtb_TmpSignalConversionAtMath_j[0];
          } else if (rtb_TmpSignalConversionAtDela_a[0] +
                     rtb_TmpSignalConversionAtDela_a[1] > rtb_Subtract3_e *
                     rtb_Subtract3_e) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* MATLAB Function: '<S164>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add3_a = FMS_B.Cmd_In.cur_waypoint[0];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Add3_a = rtb_TmpSignalConversionAtMath_l[0] /
              rtb_TmpSignalConversionAtMath_l[2] * FMS_PARAM.FW_L1 +
              FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S165>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_MathFunction_cx[0] = rtb_Add3_a - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S164>/Switch' incorporates:
           *  Constant: '<S162>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S164>/OutRegionRegWP'
           *  Product: '<S178>/Divide'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Add3_a = rtb_TmpSignalConversionAtMath_j[1];
          } else if (rtb_TmpSignalConversionAtDela_a[0] +
                     rtb_TmpSignalConversionAtDela_a[1] > rtb_Subtract3_e *
                     rtb_Subtract3_e) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* MATLAB Function: '<S164>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add3_a = FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Add3_a = rtb_TmpSignalConversionAtMath_l[1] /
              rtb_TmpSignalConversionAtMath_l[2] * FMS_PARAM.FW_L1 +
              FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S165>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_MathFunction_cx[1] = rtb_Add3_a - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S174>/Sum of Elements' incorporates:
           *  Math: '<S174>/Math Function'
           */
          rtb_a_o = rtb_MathFunction_cx[0] * rtb_MathFunction_cx[0] +
            rtb_MathFunction_cx[1] * rtb_MathFunction_cx[1];

          /* Math: '<S174>/Math Function1' incorporates:
           *  Sum: '<S174>/Sum of Elements'
           *
           * About '<S174>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S174>/Math Function1' */

          /* Switch: '<S174>/Switch' incorporates:
           *  Constant: '<S174>/Constant'
           *  Product: '<S174>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_TmpSignalConversionAtMath_l[0] = rtb_MathFunction_cx[0];
            rtb_TmpSignalConversionAtMath_l[1] = rtb_MathFunction_cx[1];
            rtb_TmpSignalConversionAtMath_l[2] = rtb_Add3_a;
          } else {
            rtb_TmpSignalConversionAtMath_l[0] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[1] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[2] = 1.0F;
          }

          /* End of Switch: '<S174>/Switch' */

          /* Product: '<S174>/Divide' */
          rtb_Sum_k[0] = rtb_TmpSignalConversionAtMath_l[0] /
            rtb_TmpSignalConversionAtMath_l[2];
          rtb_Sum_k[1] = rtb_TmpSignalConversionAtMath_l[1] /
            rtb_TmpSignalConversionAtMath_l[2];

          /* Sum: '<S177>/Sum of Elements' incorporates:
           *  Math: '<S177>/Math Function'
           *  SignalConversion: '<S177>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_o = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] * rtb_Sum_k[0];

          /* Math: '<S177>/Math Function1' incorporates:
           *  Sum: '<S177>/Sum of Elements'
           *
           * About '<S177>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S177>/Math Function1' */

          /* Switch: '<S177>/Switch' incorporates:
           *  Constant: '<S177>/Constant'
           *  Product: '<S177>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_TmpSignalConversionAtMath_l[0] = rtb_Sum_k[1];
            rtb_TmpSignalConversionAtMath_l[1] = rtb_Sum_k[0];
            rtb_TmpSignalConversionAtMath_l[2] = rtb_Add3_a;
          } else {
            rtb_TmpSignalConversionAtMath_l[0] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[1] = 0.0F;
            rtb_TmpSignalConversionAtMath_l[2] = 1.0F;
          }

          /* End of Switch: '<S177>/Switch' */

          /* Product: '<S177>/Divide' */
          rtb_Sum_k[0] = rtb_TmpSignalConversionAtMath_l[0] /
            rtb_TmpSignalConversionAtMath_l[2];

          /* Product: '<S176>/Divide' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_Switch_kx[0] / rtb_Switch_kx
            [2];

          /* Product: '<S177>/Divide' */
          rtb_Sum_k[1] = rtb_TmpSignalConversionAtMath_l[1] /
            rtb_TmpSignalConversionAtMath_l[2];

          /* Product: '<S176>/Divide' */
          rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_kx[1] / rtb_Switch_kx
            [2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S172>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S172>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S172>/Sum of Elements'
           */
          rtb_Add3_a = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                             FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S170>/Square' */
          rtb_a_o = rtb_Add3_a * rtb_Add3_a;

          /* Sum: '<S175>/Subtract' incorporates:
           *  Product: '<S175>/Multiply'
           *  Product: '<S175>/Multiply1'
           */
          rtb_Add3_a = rtb_Sum_k[0] * rtb_TmpSignalConversionAtMath_j[1] -
            rtb_Sum_k[1] * rtb_TmpSignalConversionAtMath_j[0];

          /* Signum: '<S171>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S171>/Sign1' */

          /* Switch: '<S171>/Switch2' incorporates:
           *  Constant: '<S171>/Constant4'
           */
          if (rtb_Add3_a == 0.0F) {
            rtb_Add3_a = 1.0F;
          }

          /* End of Switch: '<S171>/Switch2' */

          /* DotProduct: '<S171>/Dot Product' */
          rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_j[0] * rtb_Sum_k[0] +
            rtb_TmpSignalConversionAtMath_j[1] * rtb_Sum_k[1];

          /* Trigonometry: '<S171>/Acos' incorporates:
           *  DotProduct: '<S171>/Dot Product'
           */
          if (rtb_Subtract3_e > 1.0F) {
            rtb_Subtract3_e = 1.0F;
          } else {
            if (rtb_Subtract3_e < -1.0F) {
              rtb_Subtract3_e = -1.0F;
            }
          }

          /* Product: '<S171>/Multiply' incorporates:
           *  Trigonometry: '<S171>/Acos'
           */
          rtb_Add3_a *= acosf(rtb_Subtract3_e);

          /* Saturate: '<S170>/Saturation' */
          if (rtb_Add3_a > 1.57079637F) {
            rtb_Add3_a = 1.57079637F;
          } else {
            if (rtb_Add3_a < -1.57079637F) {
              rtb_Add3_a = -1.57079637F;
            }
          }

          /* End of Saturate: '<S170>/Saturation' */

          /* Delay: '<S161>/Delay' incorporates:
           *  Gain: '<S163>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_DW.Delay_DSTATE = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          }

          /* BusAssignment: '<S156>/Bus Assignment' incorporates:
           *  Constant: '<S156>/Constant'
           *  Constant: '<S156>/Constant3'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_g;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S170>/Divide' incorporates:
           *  Constant: '<S162>/L1'
           *  Gain: '<S170>/Gain'
           *  Product: '<S170>/Multiply1'
           *  Trigonometry: '<S170>/Sin'
           */
          rtb_Switch_n_idx_1 = 2.0F * rtb_a_o * arm_sin_f32(rtb_Add3_a) /
            FMS_PARAM.FW_L1;

          /* Saturate: '<S162>/Saturation1' */
          if (rtb_Switch_n_idx_1 > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S156>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Switch_n_idx_1 < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S156>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S156>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Switch_n_idx_1;
          }

          /* End of Saturate: '<S162>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S161>/Gain2' incorporates:
           *  Delay: '<S161>/Delay'
           *  Gain: '<S163>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S161>/Sum'
           */
          rtb_Switch_n_idx_1 = (FMS_DW.Delay_DSTATE - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S161>/Saturation1' */
          if (rtb_Switch_n_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S156>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Switch_n_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S156>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S156>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Switch_n_idx_1;
          }

          /* End of Saturate: '<S161>/Saturation1' */

          /* Update for Delay: '<S166>/start_vel' */
          FMS_DW.icLoad_l = 0U;

          /* Update for Delay: '<S161>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* End of Outputs for SubSystem: '<S40>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S40>/Unknown' incorporates:
           *  ActionPort: '<S160>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_j);

          /* End of Outputs for SubSystem: '<S40>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S40>/Switch Case' */
        /* End of Outputs for SubSystem: '<S35>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S35>/Auto' incorporates:
         *  ActionPort: '<S38>/Action Port'
         */
        /* SwitchCase: '<S38>/Switch Case' incorporates:
         *  RelationalOperator: '<S130>/FixPt Relational Operator'
         *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S130>/Delay Input1'
         *
         * Block description for '<S130>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_h;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        switch (FMS_B.state) {
         case VehicleState_Offboard:
          FMS_DW.SwitchCase_ActiveSubsystem_h = 0;
          break;

         case VehicleState_Mission:
          FMS_DW.SwitchCase_ActiveSubsystem_h = 1;
          break;

         default:
          FMS_DW.SwitchCase_ActiveSubsystem_h = 2;
          break;
        }

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_h) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S38>/Offboard' incorporates:
           *  ActionPort: '<S128>/Action Port'
           */
          /* BusAssignment: '<S128>/Bus Assignment' incorporates:
           *  Constant: '<S128>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f;

          /* End of Outputs for SubSystem: '<S38>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S38>/Mission' incorporates:
             *  ActionPort: '<S127>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S38>/Switch Case' incorporates:
             *  UnitDelay: '<S130>/Delay Input1'
             *
             * Block description for '<S130>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S38>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S38>/Mission' incorporates:
           *  ActionPort: '<S127>/Action Port'
           */
          /* Outputs for Resettable SubSystem: '<S127>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S131>/Reset'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = (ZCSigState)(FMS_B.wp_index
            != FMS_DW.DelayInput1_DSTATE_dy);

          /* Math: '<S149>/Math Function' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  RelationalOperator: '<S130>/FixPt Relational Operator'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S130>/Delay Input1'
           *
           * Block description for '<S130>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Sum_k[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
          rtb_Sum_k[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* Sum: '<S149>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S149>/Math Function'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_a_o = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
            FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Math: '<S149>/Math Function1' incorporates:
           *  Sum: '<S149>/Sum of Elements'
           *
           * About '<S149>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S149>/Math Function1' */

          /* Switch: '<S149>/Switch' incorporates:
           *  Constant: '<S149>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S149>/Product'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          if (rtb_Add3_a > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Add4_o = FMS_U.INS_Out.vn;
            rtb_Switch_n_idx_1 = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_Sqrt_h = rtb_Add3_a;
          } else {
            rtb_Add4_o = 0.0F;
            rtb_Switch_n_idx_1 = 0.0F;
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S149>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* MATLAB Function: '<S139>/NearbyRefWP' incorporates:
           *  Constant: '<S137>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_kx[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Sum_k,
                          &rtb_Subtract3_e);

          /* MATLAB Function: '<S139>/SearchL1RefWP' incorporates:
           *  Constant: '<S137>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_TmpSignalConversionAtMath_l[0], &rtb_Switch_kx
                            [0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_TmpSignalConversionAtMath_j,
                            &rtb_Add3_a);

          /* MATLAB Function: '<S139>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_TmpSignalConversionAtMath_l[0],
                             &rtb_Switch_kx[0], FMS_U.INS_Out.x_R,
                             FMS_U.INS_Out.y_R, rtb_TmpSignalConversionAtDela_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Switch: '<S139>/Switch1' incorporates:
           *  Constant: '<S142>/Constant'
           *  RelationalOperator: '<S142>/Compare'
           */
          if (rtb_Subtract3_e > 0.0F) {
            rtb_TmpSignalConversionAtMath_j[0] = rtb_Sum_k[0];
            rtb_TmpSignalConversionAtMath_j[1] = rtb_Sum_k[1];
          } else {
            /* RelationalOperator: '<S141>/Compare' incorporates:
             *  Constant: '<S141>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Add3_a >= 0.0F);

            /* Switch: '<S139>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_TmpSignalConversionAtMath_j[0] =
                rtb_TmpSignalConversionAtDela_a[0];
              rtb_TmpSignalConversionAtMath_j[1] =
                rtb_TmpSignalConversionAtDela_a[1];
            }

            /* End of Switch: '<S139>/Switch' */
          }

          /* End of Switch: '<S139>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S140>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_Sum_k[0] = rtb_TmpSignalConversionAtMath_j[0] - FMS_U.INS_Out.x_R;
          rtb_Sum_k[1] = rtb_TmpSignalConversionAtMath_j[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S150>/Sum of Elements' incorporates:
           *  Math: '<S150>/Math Function'
           */
          rtb_a_o = rtb_Sum_k[0] * rtb_Sum_k[0] + rtb_Sum_k[1] * rtb_Sum_k[1];

          /* Math: '<S150>/Math Function1' incorporates:
           *  Sum: '<S150>/Sum of Elements'
           *
           * About '<S150>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S150>/Math Function1' */

          /* Switch: '<S150>/Switch' incorporates:
           *  Constant: '<S150>/Constant'
           *  Product: '<S150>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Switch_kx[0] = rtb_Sum_k[0];
            rtb_Switch_kx[1] = rtb_Sum_k[1];
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S150>/Switch' */

          /* Product: '<S149>/Divide' */
          rtb_Sum_k[0] = rtb_Add4_o / rtb_Sqrt_h;
          rtb_Sum_k[1] = rtb_Switch_n_idx_1 / rtb_Sqrt_h;

          /* Sum: '<S152>/Sum of Elements' incorporates:
           *  Math: '<S152>/Math Function'
           *  SignalConversion: '<S152>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_o = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] * rtb_Sum_k[0];

          /* Math: '<S152>/Math Function1' incorporates:
           *  Sum: '<S152>/Sum of Elements'
           *
           * About '<S152>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S152>/Math Function1' */

          /* Switch: '<S152>/Switch' incorporates:
           *  Constant: '<S152>/Constant'
           *  Product: '<S152>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Add4_o = rtb_Sum_k[1];
            rtb_Switch_n_idx_1 = rtb_Sum_k[0];
            rtb_Sqrt_h = rtb_Add3_a;
          } else {
            rtb_Add4_o = 0.0F;
            rtb_Switch_n_idx_1 = 0.0F;
            rtb_Sqrt_h = 1.0F;
          }

          /* End of Switch: '<S152>/Switch' */

          /* Product: '<S150>/Divide' */
          rtb_Sum_k[0] = rtb_Switch_kx[0] / rtb_Switch_kx[2];
          rtb_Sum_k[1] = rtb_Switch_kx[1] / rtb_Switch_kx[2];

          /* Sum: '<S153>/Sum of Elements' incorporates:
           *  Math: '<S153>/Math Function'
           *  SignalConversion: '<S153>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_a_o = rtb_Sum_k[1] * rtb_Sum_k[1] + rtb_Sum_k[0] * rtb_Sum_k[0];

          /* Math: '<S153>/Math Function1' incorporates:
           *  Sum: '<S153>/Sum of Elements'
           *
           * About '<S153>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
          } else {
            rtb_Add3_a = sqrtf(rtb_a_o);
          }

          /* End of Math: '<S153>/Math Function1' */

          /* Switch: '<S153>/Switch' incorporates:
           *  Constant: '<S153>/Constant'
           *  Product: '<S153>/Product'
           */
          if (rtb_Add3_a > 0.0F) {
            rtb_Switch_kx[0] = rtb_Sum_k[1];
            rtb_Switch_kx[1] = rtb_Sum_k[0];
            rtb_Switch_kx[2] = rtb_Add3_a;
          } else {
            rtb_Switch_kx[0] = 0.0F;
            rtb_Switch_kx[1] = 0.0F;
            rtb_Switch_kx[2] = 1.0F;
          }

          /* End of Switch: '<S153>/Switch' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S134>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_a_o = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Subtract3_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S153>/Divide' */
          rtb_Sum_k[0] = rtb_Switch_kx[0] / rtb_Switch_kx[2];

          /* Product: '<S152>/Divide' */
          rtb_TmpSignalConversionAtMath_j[0] = rtb_Add4_o / rtb_Sqrt_h;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S134>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add3_a = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S153>/Divide' */
          rtb_Sum_k[1] = rtb_Switch_kx[1] / rtb_Switch_kx[2];

          /* Product: '<S152>/Divide' */
          rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_n_idx_1 / rtb_Sqrt_h;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sum: '<S134>/Sum1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_o = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Product: '<S134>/Divide' incorporates:
           *  Math: '<S135>/Square'
           *  Math: '<S136>/Square'
           *  Sqrt: '<S135>/Sqrt'
           *  Sqrt: '<S136>/Sqrt'
           *  Sum: '<S134>/Sum'
           *  Sum: '<S134>/Sum1'
           *  Sum: '<S135>/Sum of Elements'
           *  Sum: '<S136>/Sum of Elements'
           */
          rtb_a_o = sqrtf(rtb_Subtract3_e * rtb_Subtract3_e + rtb_a_o * rtb_a_o)
            / sqrtf(rtb_Add3_a * rtb_Add3_a + rtb_Add4_o * rtb_Add4_o);

          /* Saturate: '<S134>/Saturation' */
          if (rtb_a_o > 1.0F) {
            rtb_a_o = 1.0F;
          } else {
            if (rtb_a_o < 0.0F) {
              rtb_a_o = 0.0F;
            }
          }

          /* End of Saturate: '<S134>/Saturation' */

          /* Sum: '<S151>/Subtract' incorporates:
           *  Product: '<S151>/Multiply'
           *  Product: '<S151>/Multiply1'
           */
          rtb_Add3_a = rtb_Sum_k[0] * rtb_TmpSignalConversionAtMath_j[1] -
            rtb_Sum_k[1] * rtb_TmpSignalConversionAtMath_j[0];

          /* Signum: '<S147>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S147>/Sign1' */

          /* Switch: '<S147>/Switch2' incorporates:
           *  Constant: '<S147>/Constant4'
           */
          if (rtb_Add3_a == 0.0F) {
            rtb_Add3_a = 1.0F;
          }

          /* End of Switch: '<S147>/Switch2' */

          /* DotProduct: '<S147>/Dot Product' */
          rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_j[0] * rtb_Sum_k[0] +
            rtb_TmpSignalConversionAtMath_j[1] * rtb_Sum_k[1];

          /* Trigonometry: '<S147>/Acos' incorporates:
           *  DotProduct: '<S147>/Dot Product'
           */
          if (rtb_Subtract3_e > 1.0F) {
            rtb_Subtract3_e = 1.0F;
          } else {
            if (rtb_Subtract3_e < -1.0F) {
              rtb_Subtract3_e = -1.0F;
            }
          }

          /* Product: '<S147>/Multiply' incorporates:
           *  Trigonometry: '<S147>/Acos'
           */
          rtb_Add3_a *= acosf(rtb_Subtract3_e);

          /* Saturate: '<S146>/Saturation' */
          if (rtb_Add3_a > 1.57079637F) {
            rtb_Add3_a = 1.57079637F;
          } else {
            if (rtb_Add3_a < -1.57079637F) {
              rtb_Add3_a = -1.57079637F;
            }
          }

          /* End of Saturate: '<S146>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Sqrt: '<S148>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S148>/Square'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Sum: '<S148>/Sum of Elements'
           */
          rtb_Subtract3_e = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S131>/Bus Assignment' incorporates:
           *  Constant: '<S131>/Constant'
           *  Constant: '<S131>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S146>/Divide' incorporates:
           *  Constant: '<S137>/L1'
           *  Gain: '<S146>/Gain'
           *  Math: '<S146>/Square'
           *  Product: '<S146>/Multiply1'
           *  Trigonometry: '<S146>/Sin'
           */
          rtb_Switch_n_idx_1 = rtb_Subtract3_e * rtb_Subtract3_e * 2.0F *
            arm_sin_f32(rtb_Add3_a) / FMS_PARAM.FW_L1;

          /* Saturate: '<S137>/Saturation1' */
          if (rtb_Switch_n_idx_1 > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S131>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Switch_n_idx_1 < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S131>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S131>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Switch_n_idx_1;
          }

          /* End of Saturate: '<S137>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S132>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S134>/Multiply'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S132>/Sum2'
           *  Sum: '<S134>/Add'
           *  Sum: '<S134>/Subtract'
           */
          rtb_Switch_n_idx_1 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_a_o +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Saturate: '<S132>/Saturation1' */
          if (rtb_Switch_n_idx_1 > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S131>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Switch_n_idx_1 < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S131>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S131>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Switch_n_idx_1;
          }

          /* End of Saturate: '<S132>/Saturation1' */
          /* End of Outputs for SubSystem: '<S127>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Update for UnitDelay: '<S130>/Delay Input1' incorporates:
           *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S130>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S38>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S38>/Unknown' incorporates:
           *  ActionPort: '<S129>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_n0);

          /* End of Outputs for SubSystem: '<S38>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S38>/Switch Case' */
        /* End of Outputs for SubSystem: '<S35>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S35>/Assist' incorporates:
         *  ActionPort: '<S37>/Action Port'
         */
        /* SwitchCase: '<S37>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        switch (FMS_B.state) {
         case VehicleState_Stabilize:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 0;
          break;

         case VehicleState_Altitude:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 1;
          break;

         case VehicleState_Position:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 2;
          break;

         default:
          FMS_DW.SwitchCase_ActiveSubsystem_a = 3;
          break;
        }

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_a) {
          switch (rtPrevAction) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S50>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S85>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S71>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S37>/Stabilize' incorporates:
             *  ActionPort: '<S44>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S120>/Integrator'
             *  DiscreteIntegrator: '<S120>/Integrator1'
             *  DiscreteIntegrator: '<S121>/Integrator'
             *  DiscreteIntegrator: '<S121>/Integrator1'
             *  DiscreteIntegrator: '<S125>/Integrator'
             *  DiscreteIntegrator: '<S125>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S37>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S37>/Stabilize' incorporates:
           *  ActionPort: '<S44>/Action Port'
           */
          /* Product: '<S122>/Multiply1' incorporates:
           *  Constant: '<S122>/const1'
           *  DiscreteIntegrator: '<S120>/Integrator'
           */
          rtb_P_p_idx_0 = FMS_DW.Integrator_DSTATE_a * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S118>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S118>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S122>/Add' incorporates:
           *  DiscreteIntegrator: '<S120>/Integrator1'
           *  Gain: '<S115>/Gain'
           *  Gain: '<S118>/Gain'
           *  Sum: '<S120>/Subtract'
           */
          rtb_Subtract3_e = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_a_o * FMS_PARAM.FW_ROLL_LIM) +
            rtb_P_p_idx_0;

          /* Signum: '<S122>/Sign' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else if (rtb_Subtract3_e > 0.0F) {
            rtb_Add3_a = 1.0F;
          } else {
            rtb_Add3_a = rtb_Subtract3_e;
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
          rtb_Switch_n_idx_1 = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Add3_a + rtb_P_p_idx_0;

          /* Sum: '<S122>/Add4' */
          rtb_a_o = (rtb_Subtract3_e - rtb_Switch_n_idx_1) + rtb_P_p_idx_0;

          /* Sum: '<S122>/Add3' */
          rtb_Add3_a = rtb_Subtract3_e + FMS_ConstB.d_ny;

          /* Sum: '<S122>/Subtract1' */
          rtb_Subtract3_e -= FMS_ConstB.d_ny;

          /* Signum: '<S122>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S122>/Sign1' */

          /* Signum: '<S122>/Sign2' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S122>/Sign2' */

          /* Sum: '<S122>/Add5' incorporates:
           *  Gain: '<S122>/Gain2'
           *  Product: '<S122>/Multiply4'
           *  Sum: '<S122>/Subtract2'
           */
          rtb_Switch_n_idx_1 += (rtb_Add3_a - rtb_Subtract3_e) * 0.5F * rtb_a_o;

          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Constant: '<S44>/Constant'
           *  DiscreteIntegrator: '<S120>/Integrator1'
           *  DiscreteIntegrator: '<S121>/Integrator1'
           *  DiscreteIntegrator: '<S125>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_h;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_m;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Saturate: '<S117>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_a_o = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S117>/Saturation' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S44>/Bus Assignment' incorporates:
           *  Constant: '<S117>/Constant5'
           *  Gain: '<S117>/Gain2'
           *  Sum: '<S117>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_a_o), 65536.0F) + 1000U);

          /* Product: '<S126>/Multiply1' incorporates:
           *  Constant: '<S126>/const1'
           *  DiscreteIntegrator: '<S125>/Integrator'
           */
          rtb_P_p_idx_0 = FMS_DW.Integrator_DSTATE_g * 0.02F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S124>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S124>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S126>/Add' incorporates:
           *  DiscreteIntegrator: '<S125>/Integrator1'
           *  Gain: '<S116>/Gain1'
           *  Gain: '<S124>/Gain'
           *  Sum: '<S125>/Subtract'
           */
          rtb_Sqrt_h = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_a_o * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_P_p_idx_0;

          /* Signum: '<S126>/Sign' */
          if (rtb_Sqrt_h < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Sqrt_h > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Sqrt_h;
          }

          /* End of Signum: '<S126>/Sign' */

          /* Sum: '<S126>/Add2' incorporates:
           *  Abs: '<S126>/Abs'
           *  Gain: '<S126>/Gain'
           *  Gain: '<S126>/Gain1'
           *  Product: '<S126>/Multiply2'
           *  Product: '<S126>/Multiply3'
           *  Sqrt: '<S126>/Sqrt'
           *  Sum: '<S126>/Add1'
           *  Sum: '<S126>/Subtract'
           */
          B = (sqrtf((8.0F * fabsf(rtb_Sqrt_h) + FMS_ConstB.d_hr) *
                     FMS_ConstB.d_hr) - FMS_ConstB.d_hr) * 0.5F * rtb_a_o +
            rtb_P_p_idx_0;

          /* Sum: '<S126>/Add4' */
          rtb_Subtract3_e = (rtb_Sqrt_h - B) + rtb_P_p_idx_0;

          /* Sum: '<S126>/Add3' */
          rtb_Add3_a = rtb_Sqrt_h + FMS_ConstB.d_hr;

          /* Sum: '<S126>/Subtract1' */
          rtb_Sqrt_h -= FMS_ConstB.d_hr;

          /* Signum: '<S126>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S126>/Sign1' */

          /* Signum: '<S126>/Sign2' */
          if (rtb_Sqrt_h < 0.0F) {
            rtb_Sqrt_h = -1.0F;
          } else {
            if (rtb_Sqrt_h > 0.0F) {
              rtb_Sqrt_h = 1.0F;
            }
          }

          /* End of Signum: '<S126>/Sign2' */

          /* Sum: '<S126>/Add5' incorporates:
           *  Gain: '<S126>/Gain2'
           *  Product: '<S126>/Multiply4'
           *  Sum: '<S126>/Subtract2'
           */
          B += (rtb_Add3_a - rtb_Sqrt_h) * 0.5F * rtb_Subtract3_e;

          /* Sum: '<S126>/Add6' */
          rtb_Add3_a = B + FMS_ConstB.d_hr;

          /* Sum: '<S126>/Subtract3' */
          rtb_Subtract3_e = B - FMS_ConstB.d_hr;

          /* Product: '<S126>/Divide' */
          rtb_Rem_n = B / FMS_ConstB.d_hr;

          /* Signum: '<S126>/Sign5' incorporates:
           *  Signum: '<S126>/Sign6'
           */
          if (B < 0.0F) {
            rtb_Sign5_fx = -1.0F;

            /* Signum: '<S126>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (B > 0.0F) {
            rtb_Sign5_fx = 1.0F;

            /* Signum: '<S126>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Sign5_fx = B;

            /* Signum: '<S126>/Sign6' */
            rtb_Add4_o = B;
          }

          /* End of Signum: '<S126>/Sign5' */

          /* Product: '<S123>/Multiply1' incorporates:
           *  Constant: '<S123>/const1'
           *  DiscreteIntegrator: '<S121>/Integrator'
           */
          B = FMS_DW.Integrator_DSTATE_k * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S119>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S119>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S123>/Add' incorporates:
           *  DiscreteIntegrator: '<S121>/Integrator1'
           *  Gain: '<S115>/Gain1'
           *  Gain: '<S119>/Gain'
           *  Sum: '<S121>/Subtract'
           */
          rtb_Sqrt_h = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_a_o * -FMS_PARAM.FW_PITCH_LIM) + B;

          /* Signum: '<S123>/Sign' */
          if (rtb_Sqrt_h < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Sqrt_h > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Sqrt_h;
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
          rtb_P_p_idx_0 = (sqrtf((8.0F * fabsf(rtb_Sqrt_h) + FMS_ConstB.d_m) *
            FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F * rtb_a_o + B;

          /* Sum: '<S123>/Add4' */
          B += rtb_Sqrt_h - rtb_P_p_idx_0;

          /* Sum: '<S123>/Add3' */
          rtb_a_o = rtb_Sqrt_h + FMS_ConstB.d_m;

          /* Sum: '<S123>/Subtract1' */
          rtb_Sqrt_h -= FMS_ConstB.d_m;

          /* Signum: '<S123>/Sign1' */
          if (rtb_a_o < 0.0F) {
            rtb_a_o = -1.0F;
          } else {
            if (rtb_a_o > 0.0F) {
              rtb_a_o = 1.0F;
            }
          }

          /* End of Signum: '<S123>/Sign1' */

          /* Signum: '<S123>/Sign2' */
          if (rtb_Sqrt_h < 0.0F) {
            rtb_Sqrt_h = -1.0F;
          } else {
            if (rtb_Sqrt_h > 0.0F) {
              rtb_Sqrt_h = 1.0F;
            }
          }

          /* End of Signum: '<S123>/Sign2' */

          /* Sum: '<S123>/Add5' incorporates:
           *  Gain: '<S123>/Gain2'
           *  Product: '<S123>/Multiply4'
           *  Sum: '<S123>/Subtract2'
           */
          rtb_P_p_idx_0 += (rtb_a_o - rtb_Sqrt_h) * 0.5F * B;

          /* Update for DiscreteIntegrator: '<S120>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S120>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Sum: '<S122>/Subtract3' */
          rtb_a_o = rtb_Switch_n_idx_1 - FMS_ConstB.d_ny;

          /* Sum: '<S122>/Add6' */
          B = rtb_Switch_n_idx_1 + FMS_ConstB.d_ny;

          /* Signum: '<S122>/Sign5' incorporates:
           *  Signum: '<S122>/Sign6'
           */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_Sqrt_h = -1.0F;

            /* Signum: '<S122>/Sign6' */
            D = -1.0F;
          } else if (rtb_Switch_n_idx_1 > 0.0F) {
            rtb_Sqrt_h = 1.0F;

            /* Signum: '<S122>/Sign6' */
            D = 1.0F;
          } else {
            rtb_Sqrt_h = rtb_Switch_n_idx_1;

            /* Signum: '<S122>/Sign6' */
            D = rtb_Switch_n_idx_1;
          }

          /* End of Signum: '<S122>/Sign5' */

          /* Signum: '<S122>/Sign3' */
          if (B < 0.0F) {
            B = -1.0F;
          } else {
            if (B > 0.0F) {
              B = 1.0F;
            }
          }

          /* End of Signum: '<S122>/Sign3' */

          /* Signum: '<S122>/Sign4' */
          if (rtb_a_o < 0.0F) {
            rtb_a_o = -1.0F;
          } else {
            if (rtb_a_o > 0.0F) {
              rtb_a_o = 1.0F;
            }
          }

          /* End of Signum: '<S122>/Sign4' */

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
          FMS_DW.Integrator_DSTATE_a += ((rtb_Switch_n_idx_1 / FMS_ConstB.d_ny -
            rtb_Sqrt_h) * FMS_ConstB.Gain4_ko * ((B - rtb_a_o) * 0.5F) - D *
            12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S121>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S121>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Update for DiscreteIntegrator: '<S125>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S125>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_g;

          /* Signum: '<S126>/Sign3' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S126>/Sign3' */

          /* Signum: '<S126>/Sign4' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S126>/Sign4' */

          /* Update for DiscreteIntegrator: '<S125>/Integrator' incorporates:
           *  Constant: '<S126>/const'
           *  Gain: '<S126>/Gain3'
           *  Product: '<S126>/Multiply5'
           *  Product: '<S126>/Multiply6'
           *  Sum: '<S126>/Subtract4'
           *  Sum: '<S126>/Subtract5'
           *  Sum: '<S126>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_g += ((rtb_Rem_n - rtb_Sign5_fx) *
            FMS_ConstB.Gain4_n * ((rtb_Add3_a - rtb_Subtract3_e) * 0.5F) -
            rtb_Add4_o * 15.707963F) * 0.004F;

          /* Sum: '<S123>/Subtract3' */
          rtb_Add3_a = rtb_P_p_idx_0 - FMS_ConstB.d_m;

          /* Sum: '<S123>/Add6' */
          rtb_Subtract3_e = rtb_P_p_idx_0 + FMS_ConstB.d_m;

          /* Signum: '<S123>/Sign5' incorporates:
           *  Signum: '<S123>/Sign6'
           */
          if (rtb_P_p_idx_0 < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S123>/Sign6' */
            rtb_Sqrt_h = -1.0F;
          } else if (rtb_P_p_idx_0 > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S123>/Sign6' */
            rtb_Sqrt_h = 1.0F;
          } else {
            rtb_Add4_o = rtb_P_p_idx_0;

            /* Signum: '<S123>/Sign6' */
            rtb_Sqrt_h = rtb_P_p_idx_0;
          }

          /* End of Signum: '<S123>/Sign5' */

          /* Signum: '<S123>/Sign3' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S123>/Sign3' */

          /* Signum: '<S123>/Sign4' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S123>/Sign4' */

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
          FMS_DW.Integrator_DSTATE_k += ((rtb_P_p_idx_0 / FMS_ConstB.d_m -
            rtb_Add4_o) * FMS_ConstB.Gain4_k2 * ((rtb_Subtract3_e - rtb_Add3_a) *
            0.5F) - rtb_Sqrt_h * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S37>/Stabilize' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S37>/Altitude' incorporates:
             *  ActionPort: '<S42>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S62>/Integrator'
             *  DiscreteIntegrator: '<S62>/Integrator1'
             *  DiscreteIntegrator: '<S65>/Integrator'
             *  DiscreteIntegrator: '<S65>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_l = 0.0F;
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_e = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S37>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S37>/Altitude' incorporates:
             *  ActionPort: '<S42>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
             *  Chart: '<S51>/Motion Status'
             */
            FMS_MotionStatus_a_Reset(&FMS_DW.sf_MotionStatus_a);

            /* End of SystemReset for SubSystem: '<S37>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S37>/Altitude' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S51>/Motion Status' incorporates:
           *  Abs: '<S51>/Abs'
           *  Abs: '<S51>/Abs1'
           *  Constant: '<S59>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S59>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionStatus_k(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                             FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                             &rtb_state_k0, &FMS_DW.sf_MotionStatus_a);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SwitchCase: '<S50>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
          switch (rtb_state_k0) {
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
              /* SystemReset for IfAction SubSystem: '<S50>/Hold Control' incorporates:
               *  ActionPort: '<S53>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S50>/Switch Case' */
              FMS_HoldControl_p_Reset(&FMS_DW.HoldControl_o);

              /* End of SystemReset for SubSystem: '<S50>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S50>/Hold Control' incorporates:
             *  ActionPort: '<S53>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_o(FMS_U.INS_Out.h_R, &FMS_B.Merge_j,
                              &FMS_DW.HoldControl_o);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S50>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S50>/Brake Control' incorporates:
             *  ActionPort: '<S52>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_j);

            /* End of Outputs for SubSystem: '<S50>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S50>/Move Control' incorporates:
               *  ActionPort: '<S54>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S50>/Switch Case' */
              FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_ou);

              /* End of SystemReset for SubSystem: '<S50>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S50>/Move Control' incorporates:
             *  ActionPort: '<S54>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_j,
                              &FMS_ConstB.MoveControl_ou, &FMS_DW.MoveControl_ou);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S50>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S50>/Switch Case' */

          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Constant: '<S42>/Constant'
           *  DiscreteIntegrator: '<S62>/Integrator1'
           *  DiscreteIntegrator: '<S65>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_l;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Saturate: '<S46>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_a_o = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S46>/Saturation' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S42>/Bus Assignment' incorporates:
           *  Gain: '<S46>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_a_o;

          /* Saturate: '<S50>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S42>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S42>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S42>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S50>/Saturation1' */

          /* Product: '<S66>/Multiply1' incorporates:
           *  Constant: '<S66>/const1'
           *  DiscreteIntegrator: '<S65>/Integrator'
           */
          rtb_Switch_n_idx_1 = FMS_DW.Integrator_DSTATE_e * 0.02F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S64>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S64>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S66>/Add' incorporates:
           *  DiscreteIntegrator: '<S65>/Integrator1'
           *  Gain: '<S49>/Gain1'
           *  Gain: '<S64>/Gain'
           *  Sum: '<S65>/Subtract'
           */
          rtb_P_p_idx_0 = (FMS_DW.Integrator1_DSTATE_g - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_a_o * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Switch_n_idx_1;

          /* Signum: '<S66>/Sign' */
          if (rtb_P_p_idx_0 < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else if (rtb_P_p_idx_0 > 0.0F) {
            rtb_Add3_a = 1.0F;
          } else {
            rtb_Add3_a = rtb_P_p_idx_0;
          }

          /* End of Signum: '<S66>/Sign' */

          /* Sum: '<S66>/Add2' incorporates:
           *  Abs: '<S66>/Abs'
           *  Gain: '<S66>/Gain'
           *  Gain: '<S66>/Gain1'
           *  Product: '<S66>/Multiply2'
           *  Product: '<S66>/Multiply3'
           *  Sqrt: '<S66>/Sqrt'
           *  Sum: '<S66>/Add1'
           *  Sum: '<S66>/Subtract'
           */
          rtb_Sign5_fx = (sqrtf((8.0F * fabsf(rtb_P_p_idx_0) + FMS_ConstB.d_n) *
                                FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Add3_a + rtb_Switch_n_idx_1;

          /* Sum: '<S66>/Add4' */
          rtb_Subtract3_e = (rtb_P_p_idx_0 - rtb_Sign5_fx) + rtb_Switch_n_idx_1;

          /* Sum: '<S66>/Add3' */
          rtb_Add3_a = rtb_P_p_idx_0 + FMS_ConstB.d_n;

          /* Sum: '<S66>/Subtract1' */
          rtb_P_p_idx_0 -= FMS_ConstB.d_n;

          /* Signum: '<S66>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S66>/Sign1' */

          /* Signum: '<S66>/Sign2' */
          if (rtb_P_p_idx_0 < 0.0F) {
            rtb_P_p_idx_0 = -1.0F;
          } else {
            if (rtb_P_p_idx_0 > 0.0F) {
              rtb_P_p_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S66>/Sign2' */

          /* Sum: '<S66>/Add5' incorporates:
           *  Gain: '<S66>/Gain2'
           *  Product: '<S66>/Multiply4'
           *  Sum: '<S66>/Subtract2'
           */
          rtb_Sign5_fx += (rtb_Add3_a - rtb_P_p_idx_0) * 0.5F * rtb_Subtract3_e;

          /* Sum: '<S66>/Add6' */
          rtb_Add3_a = rtb_Sign5_fx + FMS_ConstB.d_n;

          /* Sum: '<S66>/Subtract3' */
          rtb_Subtract3_e = rtb_Sign5_fx - FMS_ConstB.d_n;

          /* Product: '<S66>/Divide' */
          rtb_Sqrt_h = rtb_Sign5_fx / FMS_ConstB.d_n;

          /* Signum: '<S66>/Sign5' incorporates:
           *  Signum: '<S66>/Sign6'
           */
          if (rtb_Sign5_fx < 0.0F) {
            rtb_Rem_n = -1.0F;

            /* Signum: '<S66>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Sign5_fx > 0.0F) {
            rtb_Rem_n = 1.0F;

            /* Signum: '<S66>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Rem_n = rtb_Sign5_fx;

            /* Signum: '<S66>/Sign6' */
            rtb_Add4_o = rtb_Sign5_fx;
          }

          /* End of Signum: '<S66>/Sign5' */

          /* Product: '<S63>/Multiply1' incorporates:
           *  Constant: '<S63>/const1'
           *  DiscreteIntegrator: '<S62>/Integrator'
           */
          rtb_Sign5_fx = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S61>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S61>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S63>/Add' incorporates:
           *  DiscreteIntegrator: '<S62>/Integrator1'
           *  Gain: '<S48>/Gain'
           *  Gain: '<S61>/Gain'
           *  Sum: '<S62>/Subtract'
           */
          rtb_Switch_n_idx_1 = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_a_o * FMS_PARAM.FW_ROLL_LIM) + rtb_Sign5_fx;

          /* Signum: '<S63>/Sign' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Switch_n_idx_1 > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Switch_n_idx_1;
          }

          /* End of Signum: '<S63>/Sign' */

          /* Sum: '<S63>/Add2' incorporates:
           *  Abs: '<S63>/Abs'
           *  Gain: '<S63>/Gain'
           *  Gain: '<S63>/Gain1'
           *  Product: '<S63>/Multiply2'
           *  Product: '<S63>/Multiply3'
           *  Sqrt: '<S63>/Sqrt'
           *  Sum: '<S63>/Add1'
           *  Sum: '<S63>/Subtract'
           */
          rtb_P_p_idx_0 = (sqrtf((8.0F * fabsf(rtb_Switch_n_idx_1) +
            FMS_ConstB.d_b) * FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F * rtb_a_o
            + rtb_Sign5_fx;

          /* Sum: '<S63>/Add4' */
          rtb_Sign5_fx += rtb_Switch_n_idx_1 - rtb_P_p_idx_0;

          /* Sum: '<S63>/Add3' */
          rtb_a_o = rtb_Switch_n_idx_1 + FMS_ConstB.d_b;

          /* Sum: '<S63>/Subtract1' */
          rtb_Switch_n_idx_1 -= FMS_ConstB.d_b;

          /* Signum: '<S63>/Sign1' */
          if (rtb_a_o < 0.0F) {
            rtb_a_o = -1.0F;
          } else {
            if (rtb_a_o > 0.0F) {
              rtb_a_o = 1.0F;
            }
          }

          /* End of Signum: '<S63>/Sign1' */

          /* Signum: '<S63>/Sign2' */
          if (rtb_Switch_n_idx_1 < 0.0F) {
            rtb_Switch_n_idx_1 = -1.0F;
          } else {
            if (rtb_Switch_n_idx_1 > 0.0F) {
              rtb_Switch_n_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S63>/Sign2' */

          /* Sum: '<S63>/Add5' incorporates:
           *  Gain: '<S63>/Gain2'
           *  Product: '<S63>/Multiply4'
           *  Sum: '<S63>/Subtract2'
           */
          rtb_P_p_idx_0 += (rtb_a_o - rtb_Switch_n_idx_1) * 0.5F * rtb_Sign5_fx;

          /* Update for DiscreteIntegrator: '<S62>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S62>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S65>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S65>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_e;

          /* Signum: '<S66>/Sign3' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S66>/Sign3' */

          /* Signum: '<S66>/Sign4' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S66>/Sign4' */

          /* Update for DiscreteIntegrator: '<S65>/Integrator' incorporates:
           *  Constant: '<S66>/const'
           *  Gain: '<S66>/Gain3'
           *  Product: '<S66>/Multiply5'
           *  Product: '<S66>/Multiply6'
           *  Sum: '<S66>/Subtract4'
           *  Sum: '<S66>/Subtract5'
           *  Sum: '<S66>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_e += ((rtb_Sqrt_h - rtb_Rem_n) *
            FMS_ConstB.Gain4_k * ((rtb_Add3_a - rtb_Subtract3_e) * 0.5F) -
            rtb_Add4_o * 15.707963F) * 0.004F;

          /* Sum: '<S63>/Subtract3' */
          rtb_Add3_a = rtb_P_p_idx_0 - FMS_ConstB.d_b;

          /* Sum: '<S63>/Add6' */
          rtb_Subtract3_e = rtb_P_p_idx_0 + FMS_ConstB.d_b;

          /* Signum: '<S63>/Sign5' incorporates:
           *  Signum: '<S63>/Sign6'
           */
          if (rtb_P_p_idx_0 < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S63>/Sign6' */
            rtb_Sqrt_h = -1.0F;
          } else if (rtb_P_p_idx_0 > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S63>/Sign6' */
            rtb_Sqrt_h = 1.0F;
          } else {
            rtb_Add4_o = rtb_P_p_idx_0;

            /* Signum: '<S63>/Sign6' */
            rtb_Sqrt_h = rtb_P_p_idx_0;
          }

          /* End of Signum: '<S63>/Sign5' */

          /* Signum: '<S63>/Sign3' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S63>/Sign3' */

          /* Signum: '<S63>/Sign4' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S63>/Sign4' */

          /* Update for DiscreteIntegrator: '<S62>/Integrator' incorporates:
           *  Constant: '<S63>/const'
           *  Gain: '<S63>/Gain3'
           *  Product: '<S63>/Divide'
           *  Product: '<S63>/Multiply5'
           *  Product: '<S63>/Multiply6'
           *  Sum: '<S63>/Subtract4'
           *  Sum: '<S63>/Subtract5'
           *  Sum: '<S63>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((rtb_P_p_idx_0 / FMS_ConstB.d_b -
            rtb_Add4_o) * FMS_ConstB.Gain4_d * ((rtb_Subtract3_e - rtb_Add3_a) *
            0.5F) - rtb_Sqrt_h * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S37>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S37>/Position' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S37>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S83>/Integrator'
             *  DiscreteIntegrator: '<S83>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE = 0.0F;
            FMS_DW.Integrator_DSTATE = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S37>/Position' */

            /* SystemReset for IfAction SubSystem: '<S37>/Position' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S37>/Switch Case' incorporates:
             *  Chart: '<S72>/Motion Status'
             *  Chart: '<S86>/Motion State'
             */
            FMS_MotionStatus_a_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c26_FMS = 0U;
            FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

            /* End of SystemReset for SubSystem: '<S37>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S37>/Position' incorporates:
           *  ActionPort: '<S43>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Trigonometry: '<S114>/Trigonometric Function1' incorporates:
           *  Gain: '<S113>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_ph[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S114>/Trigonometric Function' incorporates:
           *  Gain: '<S113>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_ph[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S114>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S114>/Constant3'
           */
          rtb_VectorConcatenate_ph[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Gain: '<S114>/Gain' incorporates:
           *  Gain: '<S113>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  Trigonometry: '<S114>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ph[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S114>/Trigonometric Function3' incorporates:
           *  Gain: '<S113>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S30>/Signal Copy1'
           */
          rtb_VectorConcatenate_ph[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* SignalConversion: '<S114>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S114>/Constant4'
           */
          rtb_VectorConcatenate_ph[5] = 0.0F;

          /* SignalConversion: '<S114>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ph[6] = FMS_ConstB.VectorConcatenate3[0];
          rtb_VectorConcatenate_ph[7] = FMS_ConstB.VectorConcatenate3[1];
          rtb_VectorConcatenate_ph[8] = FMS_ConstB.VectorConcatenate3[2];

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Chart: '<S72>/Motion Status' incorporates:
           *  Abs: '<S72>/Abs'
           *  Abs: '<S72>/Abs1'
           *  Constant: '<S80>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S80>/Compare'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          FMS_MotionStatus_k(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                             FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                             &rtb_state_k0, &FMS_DW.sf_MotionStatus_m);

          /* RelationalOperator: '<S111>/Compare' incorporates:
           *  Abs: '<S86>/Abs1'
           *  Constant: '<S111>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ);

          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Chart: '<S86>/Motion State' incorporates:
           *  Abs: '<S86>/Abs'
           */
          if (FMS_DW.temporalCounter_i1_i < 1023U) {
            FMS_DW.temporalCounter_i1_i++;
          }

          if (FMS_DW.is_active_c26_FMS == 0U) {
            FMS_DW.is_active_c26_FMS = 1U;
            FMS_DW.is_c26_FMS = FMS_IN_Move_a;
            rtb_state_ig = MotionState_Move;
          } else {
            switch (FMS_DW.is_c26_FMS) {
             case FMS_IN_Brake_m:
              rtb_state_ig = MotionState_Brake;

              /* Product: '<S86>/Multiply' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S30>/Signal Copy1'
               */
              for (rtb_n = 0; rtb_n < 3; rtb_n++) {
                /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
                rtb_VectorConcatenate_bq[rtb_n] = rtb_VectorConcatenate_ph[rtb_n
                  + 6] * FMS_U.INS_Out.vd + (rtb_VectorConcatenate_ph[rtb_n + 3]
                  * FMS_U.INS_Out.ve + rtb_VectorConcatenate_ph[rtb_n] *
                  FMS_U.INS_Out.vn);

                /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              }

              /* End of Product: '<S86>/Multiply' */
              if ((fabsf(rtb_VectorConcatenate_bq[1]) <= 0.2) ||
                  (FMS_DW.temporalCounter_i1_i >= 625U)) {
                FMS_DW.is_c26_FMS = FMS_IN_Hold_ow;
                rtb_state_ig = MotionState_Hold;
              } else {
                if (rtb_FixPtRelationalOperator_me) {
                  FMS_DW.is_c26_FMS = FMS_IN_Move_a;
                  rtb_state_ig = MotionState_Move;
                }
              }
              break;

             case FMS_IN_Hold_ow:
              rtb_state_ig = MotionState_Hold;
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c26_FMS = FMS_IN_Move_a;
                rtb_state_ig = MotionState_Move;
              }
              break;

             default:
              rtb_state_ig = MotionState_Move;
              if (!rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c26_FMS = FMS_IN_Brake_m;
                FMS_DW.temporalCounter_i1_i = 0U;
                rtb_state_ig = MotionState_Brake;
              }
              break;
            }
          }

          /* End of Chart: '<S86>/Motion State' */

          /* SwitchCase: '<S85>/Switch Case' incorporates:
           *  MATLAB Function: '<S90>/SearchL1RefWP'
           *  Math: '<S99>/Square'
           *  Product: '<S106>/Divide'
           *  Sum: '<S91>/Subtract'
           *  Switch: '<S90>/Switch'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_d;
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
          switch (rtb_state_ig) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_d = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_d = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_d = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_d) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S85>/Hold Control' incorporates:
               *  ActionPort: '<S88>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S85>/Switch Case' incorporates:
               *  Delay: '<S92>/start_vel'
               *  Delay: '<S92>/start_wp'
               */
              FMS_DW.icLoad = 1U;
              FMS_DW.icLoad_e = 1U;

              /* End of InitializeConditions for SubSystem: '<S85>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S85>/Hold Control' incorporates:
             *  ActionPort: '<S88>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Trigonometry: '<S107>/Trigonometric Function1' incorporates:
             *  Gain: '<S105>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_c[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S107>/Trigonometric Function' incorporates:
             *  Gain: '<S105>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_c[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* SignalConversion: '<S107>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S107>/Constant3'
             */
            rtb_VectorConcatenate_c[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Gain: '<S107>/Gain' incorporates:
             *  Gain: '<S105>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Trigonometry: '<S107>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_c[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S107>/Trigonometric Function3' incorporates:
             *  Gain: '<S105>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_VectorConcatenate_c[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* SignalConversion: '<S107>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S107>/Constant4'
             */
            rtb_VectorConcatenate_c[5] = 0.0F;

            /* SignalConversion: '<S107>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_c[6] = FMS_ConstB.VectorConcatenate3_j[0];
            rtb_VectorConcatenate_c[7] = FMS_ConstB.VectorConcatenate3_j[1];
            rtb_VectorConcatenate_c[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Math: '<S92>/Transpose' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_ph[3 * rtb_n] =
                rtb_VectorConcatenate_c[rtb_n];
              rtb_VectorConcatenate_ph[1 + 3 * rtb_n] =
                rtb_VectorConcatenate_c[rtb_n + 3];
              rtb_VectorConcatenate_ph[2 + 3 * rtb_n] =
                rtb_VectorConcatenate_c[rtb_n + 6];
            }

            for (rtb_n = 0; rtb_n < 9; rtb_n++) {
              rtb_VectorConcatenate_c[rtb_n] = rtb_VectorConcatenate_ph[rtb_n];
            }

            /* End of Math: '<S92>/Transpose' */

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S100>/Sum of Elements' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Math: '<S100>/Math Function'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_a_o = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
              FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Math: '<S100>/Math Function1' incorporates:
             *  Sum: '<S100>/Sum of Elements'
             *
             * About '<S100>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_a_o < 0.0F) {
              rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
            } else {
              rtb_Add3_a = sqrtf(rtb_a_o);
            }

            /* End of Math: '<S100>/Math Function1' */

            /* Switch: '<S100>/Switch' incorporates:
             *  Constant: '<S100>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S100>/Product'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            if (rtb_Add3_a > 0.0F) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              rtb_Switch_kx[0] = FMS_U.INS_Out.vn;
              rtb_Switch_kx[1] = FMS_U.INS_Out.ve;

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
              rtb_Switch_kx[2] = rtb_Add3_a;
            } else {
              rtb_Switch_kx[0] = 0.0F;
              rtb_Switch_kx[1] = 0.0F;
              rtb_Switch_kx[2] = 1.0F;
            }

            /* End of Switch: '<S100>/Switch' */

            /* Product: '<S100>/Divide' */
            rtb_TmpSignalConversionAtMath_j[0] = rtb_Switch_kx[0] /
              rtb_Switch_kx[2];
            rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_kx[1] /
              rtb_Switch_kx[2];

            /* Sum: '<S103>/Sum of Elements' incorporates:
             *  Math: '<S103>/Math Function'
             *  SignalConversion: '<S103>/TmpSignal ConversionAtMath FunctionInport1'
             */
            rtb_a_o = rtb_TmpSignalConversionAtMath_j[1] *
              rtb_TmpSignalConversionAtMath_j[1] +
              rtb_TmpSignalConversionAtMath_j[0] *
              rtb_TmpSignalConversionAtMath_j[0];

            /* Math: '<S103>/Math Function1' incorporates:
             *  Sum: '<S103>/Sum of Elements'
             *
             * About '<S103>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_a_o < 0.0F) {
              rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
            } else {
              rtb_Add3_a = sqrtf(rtb_a_o);
            }

            /* End of Math: '<S103>/Math Function1' */

            /* Switch: '<S103>/Switch' incorporates:
             *  Constant: '<S103>/Constant'
             *  Product: '<S103>/Product'
             */
            if (rtb_Add3_a > 0.0F) {
              rtb_Switch_kx[0] = rtb_TmpSignalConversionAtMath_j[1];
              rtb_Switch_kx[1] = rtb_TmpSignalConversionAtMath_j[0];
              rtb_Switch_kx[2] = rtb_Add3_a;
            } else {
              rtb_Switch_kx[0] = 0.0F;
              rtb_Switch_kx[1] = 0.0F;
              rtb_Switch_kx[2] = 1.0F;
            }

            /* End of Switch: '<S103>/Switch' */

            /* Delay: '<S92>/start_vel' incorporates:
             *  Product: '<S92>/Multiply'
             */
            if (FMS_DW.icLoad != 0) {
              /* Product: '<S92>/Multiply' */
              for (rtb_n = 0; rtb_n < 3; rtb_n++) {
                rtb_VectorConcatenate_bq[rtb_n] = rtb_VectorConcatenate_c[rtb_n];
              }

              FMS_DW.start_vel_DSTATE[0] = rtb_VectorConcatenate_bq[0];
              FMS_DW.start_vel_DSTATE[1] = rtb_VectorConcatenate_bq[1];
            }

            /* Sum: '<S106>/Sum of Elements' incorporates:
             *  Delay: '<S92>/start_vel'
             *  Math: '<S106>/Math Function'
             */
            rtb_a_o = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0] +
              FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

            /* Math: '<S106>/Math Function1' incorporates:
             *  Sum: '<S106>/Sum of Elements'
             *
             * About '<S106>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_a_o < 0.0F) {
              rtb_Add3_a = -sqrtf(fabsf(rtb_a_o));
            } else {
              rtb_Add3_a = sqrtf(rtb_a_o);
            }

            /* End of Math: '<S106>/Math Function1' */

            /* Switch: '<S106>/Switch' incorporates:
             *  Constant: '<S106>/Constant'
             *  Delay: '<S92>/start_vel'
             *  Product: '<S106>/Product'
             */
            if (rtb_Add3_a > 0.0F) {
              rtb_TmpSignalConversionAtMath_l[0] = FMS_DW.start_vel_DSTATE[0];
              rtb_TmpSignalConversionAtMath_l[1] = FMS_DW.start_vel_DSTATE[1];
              rtb_TmpSignalConversionAtMath_l[2] = rtb_Add3_a;
            } else {
              rtb_TmpSignalConversionAtMath_l[0] = 0.0F;
              rtb_TmpSignalConversionAtMath_l[1] = 0.0F;
              rtb_TmpSignalConversionAtMath_l[2] = 1.0F;
            }

            /* End of Switch: '<S106>/Switch' */

            /* Delay: '<S92>/start_wp' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            if (FMS_DW.icLoad_e != 0) {
              /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
              FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
              FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            }

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* MATLAB Function: '<S90>/SearchL1RefWP' incorporates:
             *  Delay: '<S92>/start_wp'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_Sum_k[0] = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Sum_k[1] = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Product: '<S106>/Divide' */
            rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_l[0] /
              rtb_TmpSignalConversionAtMath_l[2];

            /* MATLAB Function: '<S90>/SearchL1RefWP' */
            rtb_Add3_a = rtb_Subtract3_e * rtb_Sum_k[0];
            rtb_P_p_idx_0 = rtb_Subtract3_e;

            /* Product: '<S106>/Divide' */
            rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_l[1] /
              rtb_TmpSignalConversionAtMath_l[2];

            /* MATLAB Function: '<S90>/SearchL1RefWP' */
            rtb_Add3_a += rtb_Subtract3_e * rtb_Sum_k[1];
            B = 2.0F * rtb_Add3_a;
            rtb_Add3_a = rtb_Sum_k[0] * rtb_Sum_k[0];
            rtb_Sum_k[0] = 0.0F;

            /* MATLAB Function: '<S90>/SearchL1RefWP' */
            rtb_Add3_a += rtb_Sum_k[1] * rtb_Sum_k[1];
            rtb_Sum_k[1] = 0.0F;

            /* MATLAB Function: '<S90>/SearchL1RefWP' incorporates:
             *  Constant: '<S88>/L1'
             *  Delay: '<S92>/start_wp'
             */
            D = B * B - (rtb_Add3_a - FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1) * 4.0F;
            rtb_Add3_a = -1.0F;
            if (D > 0.0F) {
              rtb_Add3_a = sqrtf(D);
              rtb_Add3_a = fmaxf((-B + rtb_Add3_a) / 2.0F, (-B - rtb_Add3_a) /
                                 2.0F);
              rtb_Sum_k[0] = rtb_Add3_a * rtb_P_p_idx_0 +
                FMS_DW.start_wp_DSTATE[0];
              rtb_Sum_k[1] = rtb_Add3_a * rtb_Subtract3_e +
                FMS_DW.start_wp_DSTATE[1];
            } else {
              if (D == 0.0F) {
                rtb_Add3_a = -B / 2.0F;
                rtb_Sum_k[0] = rtb_Add3_a * rtb_P_p_idx_0 +
                  FMS_DW.start_wp_DSTATE[0];
                rtb_Sum_k[1] = rtb_Add3_a * rtb_Subtract3_e +
                  FMS_DW.start_wp_DSTATE[1];
              }
            }

            /* RelationalOperator: '<S93>/Compare' incorporates:
             *  Constant: '<S93>/Constant'
             *  MATLAB Function: '<S90>/SearchL1RefWP'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Add3_a > 0.0F);

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* MATLAB Function: '<S90>/OutRegionRefWP' incorporates:
             *  Delay: '<S92>/start_wp'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_Add3_a = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
              rtb_P_p_idx_0 + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1]) *
              rtb_Subtract3_e;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            rtb_a_o = 1.29246971E-26F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Add4_o = fabsf((rtb_Add3_a * rtb_P_p_idx_0 +
                                FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            if (rtb_Add4_o > 1.29246971E-26F) {
              rtb_Sqrt_h = 1.0F;
              rtb_a_o = rtb_Add4_o;
            } else {
              rtb_Switch_n_idx_1 = rtb_Add4_o / 1.29246971E-26F;
              rtb_Sqrt_h = rtb_Switch_n_idx_1 * rtb_Switch_n_idx_1;
            }

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            rtb_Add4_o = fabsf((rtb_Add3_a * rtb_Subtract3_e +
                                FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            if (rtb_Add4_o > rtb_a_o) {
              rtb_Switch_n_idx_1 = rtb_a_o / rtb_Add4_o;
              rtb_Sqrt_h = rtb_Sqrt_h * rtb_Switch_n_idx_1 * rtb_Switch_n_idx_1
                + 1.0F;
              rtb_a_o = rtb_Add4_o;
            } else {
              rtb_Switch_n_idx_1 = rtb_Add4_o / rtb_a_o;
              rtb_Sqrt_h += rtb_Switch_n_idx_1 * rtb_Switch_n_idx_1;
            }

            rtb_Sqrt_h = rtb_a_o * sqrtf(rtb_Sqrt_h);
            rtb_Add4_o = rtb_Sqrt_h * 0.577350259F + rtb_Add3_a;

            /* Switch: '<S90>/Switch' incorporates:
             *  Delay: '<S92>/start_wp'
             *  MATLAB Function: '<S90>/OutRegionRefWP'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Add3_a = rtb_Sum_k[0];
            } else {
              rtb_Add3_a = rtb_Add4_o * rtb_P_p_idx_0 + FMS_DW.start_wp_DSTATE[0];
            }

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S91>/Subtract' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_P_p_idx_0 = rtb_Add3_a - FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Math: '<S101>/Math Function' */
            rtb_TmpSignalConversionAtMath_j[0] = rtb_P_p_idx_0 * rtb_P_p_idx_0;
            rtb_Sum_k[0] = rtb_P_p_idx_0;

            /* Switch: '<S90>/Switch' incorporates:
             *  Delay: '<S92>/start_wp'
             *  MATLAB Function: '<S90>/OutRegionRefWP'
             *  Sum: '<S91>/Subtract'
             */
            if (rtb_FixPtRelationalOperator_me) {
              rtb_Add3_a = rtb_Sum_k[1];
            } else {
              rtb_Add3_a = rtb_Add4_o * rtb_Subtract3_e +
                FMS_DW.start_wp_DSTATE[1];
            }

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sum: '<S91>/Subtract' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S30>/Signal Copy1'
             */
            rtb_P_p_idx_0 = rtb_Add3_a - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Math: '<S101>/Math Function' incorporates:
             *  Math: '<S99>/Square'
             */
            rtb_a_o = rtb_P_p_idx_0 * rtb_P_p_idx_0;

            /* Sum: '<S101>/Sum of Elements' incorporates:
             *  Math: '<S101>/Math Function'
             */
            rtb_Subtract3_e = rtb_a_o + rtb_TmpSignalConversionAtMath_j[0];

            /* Math: '<S101>/Math Function1' incorporates:
             *  Sum: '<S101>/Sum of Elements'
             *
             * About '<S101>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Subtract3_e < 0.0F) {
              rtb_Add3_a = -sqrtf(fabsf(rtb_Subtract3_e));
            } else {
              rtb_Add3_a = sqrtf(rtb_Subtract3_e);
            }

            /* End of Math: '<S101>/Math Function1' */

            /* Switch: '<S101>/Switch' incorporates:
             *  Constant: '<S101>/Constant'
             *  Product: '<S101>/Product'
             */
            if (rtb_Add3_a > 0.0F) {
              rtb_TmpSignalConversionAtMath_l[0] = rtb_Sum_k[0];
              rtb_TmpSignalConversionAtMath_l[1] = rtb_P_p_idx_0;
              rtb_TmpSignalConversionAtMath_l[2] = rtb_Add3_a;
            } else {
              rtb_TmpSignalConversionAtMath_l[0] = 0.0F;
              rtb_TmpSignalConversionAtMath_l[1] = 0.0F;
              rtb_TmpSignalConversionAtMath_l[2] = 1.0F;
            }

            /* End of Switch: '<S101>/Switch' */

            /* Product: '<S101>/Divide' */
            rtb_TmpSignalConversionAtDela_a[0] =
              rtb_TmpSignalConversionAtMath_l[0] /
              rtb_TmpSignalConversionAtMath_l[2];
            rtb_TmpSignalConversionAtDela_a[1] =
              rtb_TmpSignalConversionAtMath_l[1] /
              rtb_TmpSignalConversionAtMath_l[2];

            /* Sum: '<S104>/Sum of Elements' incorporates:
             *  Math: '<S104>/Math Function'
             *  SignalConversion: '<S104>/TmpSignal ConversionAtMath FunctionInport1'
             */
            rtb_Subtract3_e = rtb_TmpSignalConversionAtDela_a[1] *
              rtb_TmpSignalConversionAtDela_a[1] +
              rtb_TmpSignalConversionAtDela_a[0] *
              rtb_TmpSignalConversionAtDela_a[0];

            /* Math: '<S104>/Math Function1' incorporates:
             *  Sum: '<S104>/Sum of Elements'
             *
             * About '<S104>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Subtract3_e < 0.0F) {
              rtb_Add3_a = -sqrtf(fabsf(rtb_Subtract3_e));
            } else {
              rtb_Add3_a = sqrtf(rtb_Subtract3_e);
            }

            /* End of Math: '<S104>/Math Function1' */

            /* Switch: '<S104>/Switch' incorporates:
             *  Constant: '<S104>/Constant'
             *  Product: '<S104>/Product'
             */
            if (rtb_Add3_a > 0.0F) {
              rtb_TmpSignalConversionAtMath_l[0] =
                rtb_TmpSignalConversionAtDela_a[1];
              rtb_TmpSignalConversionAtMath_l[1] =
                rtb_TmpSignalConversionAtDela_a[0];
              rtb_TmpSignalConversionAtMath_l[2] = rtb_Add3_a;
            } else {
              rtb_TmpSignalConversionAtMath_l[0] = 0.0F;
              rtb_TmpSignalConversionAtMath_l[1] = 0.0F;
              rtb_TmpSignalConversionAtMath_l[2] = 1.0F;
            }

            /* End of Switch: '<S104>/Switch' */

            /* Product: '<S104>/Divide' */
            rtb_TmpSignalConversionAtDela_a[0] =
              rtb_TmpSignalConversionAtMath_l[0] /
              rtb_TmpSignalConversionAtMath_l[2];

            /* Product: '<S103>/Divide' */
            rtb_TmpSignalConversionAtMath_j[0] = rtb_Switch_kx[0] /
              rtb_Switch_kx[2];
            rtb_Sum_k[0] *= rtb_Sum_k[0];

            /* Product: '<S104>/Divide' incorporates:
             *  Math: '<S99>/Square'
             */
            rtb_TmpSignalConversionAtDela_a[1] =
              rtb_TmpSignalConversionAtMath_l[1] /
              rtb_TmpSignalConversionAtMath_l[2];

            /* Product: '<S103>/Divide' */
            rtb_TmpSignalConversionAtMath_j[1] = rtb_Switch_kx[1] /
              rtb_Switch_kx[2];

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* Sqrt: '<S98>/Sqrt' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Math: '<S98>/Square'
             *  SignalConversion: '<S30>/Signal Copy1'
             *  Sum: '<S98>/Sum of Elements'
             */
            rtb_Add3_a = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                               FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Gain: '<S96>/Gain' incorporates:
             *  Math: '<S96>/Square'
             */
            rtb_Add4_o = rtb_Add3_a * rtb_Add3_a * 2.0F;

            /* Sum: '<S102>/Subtract' incorporates:
             *  Product: '<S102>/Multiply'
             *  Product: '<S102>/Multiply1'
             */
            rtb_Add3_a = rtb_TmpSignalConversionAtDela_a[0] *
              rtb_TmpSignalConversionAtMath_j[1] -
              rtb_TmpSignalConversionAtDela_a[1] *
              rtb_TmpSignalConversionAtMath_j[0];

            /* Signum: '<S97>/Sign1' */
            if (rtb_Add3_a < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else {
              if (rtb_Add3_a > 0.0F) {
                rtb_Add3_a = 1.0F;
              }
            }

            /* End of Signum: '<S97>/Sign1' */

            /* Switch: '<S97>/Switch2' incorporates:
             *  Constant: '<S97>/Constant4'
             */
            if (rtb_Add3_a == 0.0F) {
              rtb_Add3_a = 1.0F;
            }

            /* End of Switch: '<S97>/Switch2' */

            /* DotProduct: '<S97>/Dot Product' */
            rtb_Subtract3_e = rtb_TmpSignalConversionAtMath_j[0] *
              rtb_TmpSignalConversionAtDela_a[0] +
              rtb_TmpSignalConversionAtMath_j[1] *
              rtb_TmpSignalConversionAtDela_a[1];

            /* Trigonometry: '<S97>/Acos' incorporates:
             *  DotProduct: '<S97>/Dot Product'
             */
            if (rtb_Subtract3_e > 1.0F) {
              rtb_Subtract3_e = 1.0F;
            } else {
              if (rtb_Subtract3_e < -1.0F) {
                rtb_Subtract3_e = -1.0F;
              }
            }

            /* Product: '<S97>/Multiply' incorporates:
             *  Trigonometry: '<S97>/Acos'
             */
            rtb_Add3_a *= acosf(rtb_Subtract3_e);

            /* Saturate: '<S96>/Saturation' */
            if (rtb_Add3_a > 1.57079637F) {
              rtb_Add3_a = 1.57079637F;
            } else {
              if (rtb_Add3_a < -1.57079637F) {
                rtb_Add3_a = -1.57079637F;
              }
            }

            /* End of Saturate: '<S96>/Saturation' */

            /* Product: '<S96>/Divide' incorporates:
             *  Constant: '<S88>/L1'
             *  Constant: '<S96>/Constant'
             *  MinMax: '<S96>/Max'
             *  MinMax: '<S96>/Min'
             *  Product: '<S96>/Multiply1'
             *  Sqrt: '<S99>/Sqrt'
             *  Sum: '<S99>/Sum of Elements'
             *  Trigonometry: '<S96>/Sin'
             */
            FMS_B.Merge_b = arm_sin_f32(rtb_Add3_a) * rtb_Add4_o / fminf
              (FMS_PARAM.FW_L1, fmaxf(sqrtf(rtb_a_o + rtb_Sum_k[0]), 0.5F));

            /* Update for Delay: '<S92>/start_vel' */
            FMS_DW.icLoad = 0U;

            /* Update for Delay: '<S92>/start_wp' */
            FMS_DW.icLoad_e = 0U;

            /* End of Outputs for SubSystem: '<S85>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S85>/Brake Control' incorporates:
             *  ActionPort: '<S87>/Action Port'
             */
            /* SignalConversion: '<S87>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
             *  Constant: '<S87>/Brake Speed'
             */
            FMS_B.Merge_b = 0.0F;

            /* End of Outputs for SubSystem: '<S85>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S85>/Move Control' incorporates:
               *  ActionPort: '<S89>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S85>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S109>/Integrator'
               *  DiscreteIntegrator: '<S109>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_c = 0.0F;
              FMS_DW.Integrator_DSTATE_f = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S85>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S85>/Move Control' incorporates:
             *  ActionPort: '<S89>/Action Port'
             */
            /* Product: '<S110>/Multiply1' incorporates:
             *  Constant: '<S110>/const1'
             *  DiscreteIntegrator: '<S109>/Integrator'
             */
            rtb_Add3_a = FMS_DW.Integrator_DSTATE_f * 0.05F;

            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            /* DeadZone: '<S108>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S30>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_a_o = 0.0F;
            } else {
              rtb_a_o = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S108>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

            /* Sum: '<S110>/Add' incorporates:
             *  DiscreteIntegrator: '<S109>/Integrator1'
             *  Gain: '<S108>/Gain'
             *  Gain: '<S89>/Gain6'
             *  Sum: '<S109>/Subtract'
             */
            rtb_Subtract3_e = (FMS_DW.Integrator1_DSTATE_c - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_a_o * FMS_PARAM.FW_ACC_Y_LIM) +
              rtb_Add3_a;

            /* Signum: '<S110>/Sign' */
            if (rtb_Subtract3_e < 0.0F) {
              rtb_a_o = -1.0F;
            } else if (rtb_Subtract3_e > 0.0F) {
              rtb_a_o = 1.0F;
            } else {
              rtb_a_o = rtb_Subtract3_e;
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
            rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + FMS_ConstB.d_h) *
                             FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F * rtb_a_o
              + rtb_Add3_a;

            /* Sum: '<S110>/Add4' */
            rtb_Add4_o = (rtb_Subtract3_e - rtb_a_o) + rtb_Add3_a;

            /* Sum: '<S110>/Add3' */
            rtb_Add3_a = rtb_Subtract3_e + FMS_ConstB.d_h;

            /* Sum: '<S110>/Subtract1' */
            rtb_Subtract3_e -= FMS_ConstB.d_h;

            /* Signum: '<S110>/Sign1' */
            if (rtb_Add3_a < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else {
              if (rtb_Add3_a > 0.0F) {
                rtb_Add3_a = 1.0F;
              }
            }

            /* End of Signum: '<S110>/Sign1' */

            /* Signum: '<S110>/Sign2' */
            if (rtb_Subtract3_e < 0.0F) {
              rtb_Subtract3_e = -1.0F;
            } else {
              if (rtb_Subtract3_e > 0.0F) {
                rtb_Subtract3_e = 1.0F;
              }
            }

            /* End of Signum: '<S110>/Sign2' */

            /* Sum: '<S110>/Add5' incorporates:
             *  Gain: '<S110>/Gain2'
             *  Product: '<S110>/Multiply4'
             *  Sum: '<S110>/Subtract2'
             */
            rtb_a_o += (rtb_Add3_a - rtb_Subtract3_e) * 0.5F * rtb_Add4_o;

            /* SignalConversion: '<S89>/OutportBufferForay_cmd_mPs2' incorporates:
             *  DiscreteIntegrator: '<S109>/Integrator1'
             */
            FMS_B.Merge_b = FMS_DW.Integrator1_DSTATE_c;

            /* Update for DiscreteIntegrator: '<S109>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S109>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_c += 0.004F * FMS_DW.Integrator_DSTATE_f;

            /* Sum: '<S110>/Subtract3' */
            rtb_Add3_a = rtb_a_o - FMS_ConstB.d_h;

            /* Sum: '<S110>/Add6' */
            rtb_Subtract3_e = rtb_a_o + FMS_ConstB.d_h;

            /* Signum: '<S110>/Sign5' incorporates:
             *  Signum: '<S110>/Sign6'
             */
            if (rtb_a_o < 0.0F) {
              rtb_Add4_o = -1.0F;

              /* Signum: '<S110>/Sign6' */
              rtb_Sqrt_h = -1.0F;
            } else if (rtb_a_o > 0.0F) {
              rtb_Add4_o = 1.0F;

              /* Signum: '<S110>/Sign6' */
              rtb_Sqrt_h = 1.0F;
            } else {
              rtb_Add4_o = rtb_a_o;

              /* Signum: '<S110>/Sign6' */
              rtb_Sqrt_h = rtb_a_o;
            }

            /* End of Signum: '<S110>/Sign5' */

            /* Signum: '<S110>/Sign3' */
            if (rtb_Subtract3_e < 0.0F) {
              rtb_Subtract3_e = -1.0F;
            } else {
              if (rtb_Subtract3_e > 0.0F) {
                rtb_Subtract3_e = 1.0F;
              }
            }

            /* End of Signum: '<S110>/Sign3' */

            /* Signum: '<S110>/Sign4' */
            if (rtb_Add3_a < 0.0F) {
              rtb_Add3_a = -1.0F;
            } else {
              if (rtb_Add3_a > 0.0F) {
                rtb_Add3_a = 1.0F;
              }
            }

            /* End of Signum: '<S110>/Sign4' */

            /* Update for DiscreteIntegrator: '<S109>/Integrator' incorporates:
             *  Constant: '<S110>/const'
             *  Gain: '<S110>/Gain3'
             *  Product: '<S110>/Divide'
             *  Product: '<S110>/Multiply5'
             *  Product: '<S110>/Multiply6'
             *  Sum: '<S110>/Subtract4'
             *  Sum: '<S110>/Subtract5'
             *  Sum: '<S110>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_f += ((rtb_a_o / FMS_ConstB.d_h -
              rtb_Add4_o) * FMS_ConstB.Gain4_b * ((rtb_Subtract3_e - rtb_Add3_a)
              * 0.5F) - rtb_Sqrt_h * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S85>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S85>/Switch Case' */

          /* SwitchCase: '<S71>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy1'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ad;
          FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
          switch (rtb_state_k0) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_ad = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_ad = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_ad = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_ad) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S71>/Hold Control' incorporates:
               *  ActionPort: '<S74>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S71>/Switch Case' */
              FMS_HoldControl_p_Reset(&FMS_DW.HoldControl_jx);

              /* End of SystemReset for SubSystem: '<S71>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S71>/Hold Control' incorporates:
             *  ActionPort: '<S74>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_HoldControl_o(FMS_U.INS_Out.h_R, &FMS_B.Merge,
                              &FMS_DW.HoldControl_jx);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S71>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S71>/Brake Control' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge);

            /* End of Outputs for SubSystem: '<S71>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S71>/Move Control' incorporates:
               *  ActionPort: '<S75>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S71>/Switch Case' */
              FMS_MoveControl_d_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S71>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S71>/Move Control' incorporates:
             *  ActionPort: '<S75>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
            FMS_MoveControl_o(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge,
                              &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S71>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S71>/Switch Case' */

          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Constant: '<S43>/Constant'
           *  DiscreteIntegrator: '<S83>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* Saturate: '<S67>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_a_o = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S67>/Saturation' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* BusAssignment: '<S43>/Bus Assignment' incorporates:
           *  Gain: '<S67>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_a_o;

          /* Saturate: '<S85>/Saturation1' */
          if (FMS_B.Merge_b > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S43>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S43>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S43>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S85>/Saturation1' */

          /* Saturate: '<S71>/Saturation1' */
          if (FMS_B.Merge > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S43>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S43>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S43>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge;
          }

          /* End of Saturate: '<S71>/Saturation1' */

          /* Product: '<S84>/Multiply1' incorporates:
           *  Constant: '<S84>/const1'
           *  DiscreteIntegrator: '<S83>/Integrator'
           */
          rtb_Add3_a = FMS_DW.Integrator_DSTATE * 0.02F;

          /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
          /* DeadZone: '<S82>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S30>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_a_o = 0.0F;
          } else {
            rtb_a_o = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S82>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

          /* Sum: '<S84>/Add' incorporates:
           *  DiscreteIntegrator: '<S83>/Integrator1'
           *  Gain: '<S69>/Gain1'
           *  Gain: '<S82>/Gain'
           *  Sum: '<S83>/Subtract'
           */
          rtb_Subtract3_e = (FMS_DW.Integrator1_DSTATE - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_a_o * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Add3_a;

          /* Signum: '<S84>/Sign' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_a_o = -1.0F;
          } else if (rtb_Subtract3_e > 0.0F) {
            rtb_a_o = 1.0F;
          } else {
            rtb_a_o = rtb_Subtract3_e;
          }

          /* End of Signum: '<S84>/Sign' */

          /* Sum: '<S84>/Add2' incorporates:
           *  Abs: '<S84>/Abs'
           *  Gain: '<S84>/Gain'
           *  Gain: '<S84>/Gain1'
           *  Product: '<S84>/Multiply2'
           *  Product: '<S84>/Multiply3'
           *  Sqrt: '<S84>/Sqrt'
           *  Sum: '<S84>/Add1'
           *  Sum: '<S84>/Subtract'
           */
          rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + FMS_ConstB.d) *
                           FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_a_o +
            rtb_Add3_a;

          /* Sum: '<S84>/Add4' */
          rtb_Add4_o = (rtb_Subtract3_e - rtb_a_o) + rtb_Add3_a;

          /* Sum: '<S84>/Add3' */
          rtb_Add3_a = rtb_Subtract3_e + FMS_ConstB.d;

          /* Sum: '<S84>/Subtract1' */
          rtb_Subtract3_e -= FMS_ConstB.d;

          /* Signum: '<S84>/Sign1' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign1' */

          /* Signum: '<S84>/Sign2' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign2' */

          /* Sum: '<S84>/Add5' incorporates:
           *  Gain: '<S84>/Gain2'
           *  Product: '<S84>/Multiply4'
           *  Sum: '<S84>/Subtract2'
           */
          rtb_a_o += (rtb_Add3_a - rtb_Subtract3_e) * 0.5F * rtb_Add4_o;

          /* Update for DiscreteIntegrator: '<S83>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S83>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

          /* Sum: '<S84>/Subtract3' */
          rtb_Add3_a = rtb_a_o - FMS_ConstB.d;

          /* Sum: '<S84>/Add6' */
          rtb_Subtract3_e = rtb_a_o + FMS_ConstB.d;

          /* Signum: '<S84>/Sign5' incorporates:
           *  Signum: '<S84>/Sign6'
           */
          if (rtb_a_o < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S84>/Sign6' */
            rtb_Sqrt_h = -1.0F;
          } else if (rtb_a_o > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S84>/Sign6' */
            rtb_Sqrt_h = 1.0F;
          } else {
            rtb_Add4_o = rtb_a_o;

            /* Signum: '<S84>/Sign6' */
            rtb_Sqrt_h = rtb_a_o;
          }

          /* End of Signum: '<S84>/Sign5' */

          /* Signum: '<S84>/Sign3' */
          if (rtb_Subtract3_e < 0.0F) {
            rtb_Subtract3_e = -1.0F;
          } else {
            if (rtb_Subtract3_e > 0.0F) {
              rtb_Subtract3_e = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign3' */

          /* Signum: '<S84>/Sign4' */
          if (rtb_Add3_a < 0.0F) {
            rtb_Add3_a = -1.0F;
          } else {
            if (rtb_Add3_a > 0.0F) {
              rtb_Add3_a = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign4' */

          /* Update for DiscreteIntegrator: '<S83>/Integrator' incorporates:
           *  Constant: '<S84>/const'
           *  Gain: '<S84>/Gain3'
           *  Product: '<S84>/Divide'
           *  Product: '<S84>/Multiply5'
           *  Product: '<S84>/Multiply6'
           *  Sum: '<S84>/Subtract4'
           *  Sum: '<S84>/Subtract5'
           *  Sum: '<S84>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE += ((rtb_a_o / FMS_ConstB.d - rtb_Add4_o) *
            FMS_ConstB.Gain4 * ((rtb_Subtract3_e - rtb_Add3_a) * 0.5F) -
            rtb_Sqrt_h * 15.707963F) * 0.004F;

          /* End of Outputs for SubSystem: '<S37>/Position' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S37>/Unknown' incorporates:
           *  ActionPort: '<S45>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_p);

          /* End of Outputs for SubSystem: '<S37>/Unknown' */
          break;
        }

        /* End of SwitchCase: '<S37>/Switch Case' */
        /* End of Outputs for SubSystem: '<S35>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S35>/Manual' incorporates:
         *  ActionPort: '<S39>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* Saturate: '<S155>/Saturation' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S30>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
          rtb_a_o = 1.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
          rtb_a_o = 0.0F;
        } else {
          rtb_a_o = FMS_U.Pilot_Cmd.stick_throttle;
        }

        /* End of Saturate: '<S155>/Saturation' */
        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* DataTypeConversion: '<S154>/Data Type Conversion' incorporates:
         *  Constant: '<S155>/Constant5'
         *  Gain: '<S155>/Gain4'
         *  Sum: '<S155>/Add'
         */
        rtb_y_o = (uint16_T)fmodf(floorf(1000.0F * rtb_a_o + 1000.0F), 65536.0F);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DataTypeConversion: '<S154>/Data Type Conversion1' incorporates:
         *  Bias: '<S154>/Bias1'
         *  Gain: '<S154>/Gain'
         *  Gain: '<S154>/Gain1'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S30>/Signal Copy2'
         */
        rtb_a_o = fmodf(floorf(FMS_PARAM.MANUAL_ROLL_REV *
          FMS_U.Pilot_Cmd.stick_roll * 500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
        rtb_y_b = (uint16_T)(rtb_a_o < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                             (uint16_T)-rtb_a_o : (int32_T)(uint16_T)rtb_a_o);

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  Constant: '<S39>/Constant'
         *  Constant: '<S39>/Constant2'
         *  SignalConversion: '<S39>/TmpHiddenBufferAtBus AssignmentInport1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;
        FMS_Y.FMS_Out.actuator_cmd[0] = rtb_y_o;
        FMS_Y.FMS_Out.actuator_cmd[1] = rtb_y_o;
        FMS_Y.FMS_Out.actuator_cmd[2] = rtb_y_b;
        FMS_Y.FMS_Out.actuator_cmd[3] = rtb_y_b;

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DataTypeConversion: '<S154>/Data Type Conversion2' incorporates:
         *  Bias: '<S154>/Bias2'
         *  Gain: '<S154>/Gain2'
         *  Gain: '<S154>/Gain4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S30>/Signal Copy2'
         */
        rtb_a_o = fmodf(floorf(FMS_PARAM.MANUAL_PITCH_REV *
          FMS_U.Pilot_Cmd.stick_pitch * -500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S154>/Data Type Conversion2'
         */
        FMS_Y.FMS_Out.actuator_cmd[4] = (uint16_T)(rtb_a_o < 0.0F ? (int32_T)
          (uint16_T)-(int16_T)(uint16_T)-rtb_a_o : (int32_T)(uint16_T)rtb_a_o);

        /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
        /* DataTypeConversion: '<S154>/Data Type Conversion3' incorporates:
         *  Bias: '<S154>/Bias3'
         *  Gain: '<S154>/Gain3'
         *  Gain: '<S154>/Gain5'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S30>/Signal Copy2'
         */
        rtb_a_o = fmodf(floorf(FMS_PARAM.MANUAL_YAW_REV *
          FMS_U.Pilot_Cmd.stick_yaw * 500.0F + 1500.0F), 65536.0F);

        /* End of Outputs for SubSystem: '<S4>/FMS_Input' */

        /* BusAssignment: '<S39>/Bus Assignment' incorporates:
         *  DataTypeConversion: '<S154>/Data Type Conversion3'
         */
        FMS_Y.FMS_Out.actuator_cmd[5] = (uint16_T)(rtb_a_o < 0.0F ? (int32_T)
          (uint16_T)-(int16_T)(uint16_T)-rtb_a_o : (int32_T)(uint16_T)rtb_a_o);
        for (rtb_n = 0; rtb_n < 10; rtb_n++) {
          FMS_Y.FMS_Out.actuator_cmd[rtb_n + 6] = 0U;
        }

        /* End of Outputs for SubSystem: '<S35>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S35>/Unknown' incorporates:
         *  ActionPort: '<S41>/Action Port'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nb);

        /* End of Outputs for SubSystem: '<S35>/Unknown' */
        break;
      }

      /* End of SwitchCase: '<S35>/Switch Case' */
      /* End of Outputs for SubSystem: '<S31>/FW_Mode' */
      break;
    }

    /* End of SwitchCase: '<S31>/Switch Case' */
    /* End of Outputs for SubSystem: '<S29>/Arm' */
    break;
  }

  /* End of SwitchCase: '<S29>/Switch Case' */

  /* Outputs for Atomic SubSystem: '<S4>/FMS_Input' */
  /* BusAssignment: '<S32>/Bus Assignment' incorporates:
   *  Constant: '<S32>/Constant'
   *  DataStoreRead: '<S32>/Data Store Read'
   *  DataTypeConversion: '<S32>/Data Type Conversion'
   *  DataTypeConversion: '<S32>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S653>/Discrete-Time Integrator'
   *  Gain: '<S32>/Gain'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  SignalConversion: '<S30>/TmpSignal ConversionAtSignal Copy8Inport1'
   *  Sum: '<S32>/Sum'
   *  Sum: '<S32>/Sum1'
   */
  FMS_Y.FMS_Out.ctrl_mode = (uint8_T)((uint32_T)(uint8_T)((uint8_T)
    FMS_B.vtol_mode << 7) + FMS_Y.FMS_Out.ctrl_mode);

  /* End of Outputs for SubSystem: '<S4>/FMS_Input' */
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

  /* Update for DiscreteIntegrator: '<S653>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S653>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S14>/SetHome' incorporates:
   *  TriggerPort: '<S21>/Trigger'
   */
  if (rtb_FixPtRelationalOperator_me && (FMS_PrevZCX.SetHome_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S21>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_FixPtRelationalOperator_me;

  /* End of Outputs for SubSystem: '<S14>/SetHome' */

  /* Update for UnitDelay: '<S17>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S17>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  rtb_a_o = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_a_o < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_a_o;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for UnitDelay: '<S19>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S20>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S25>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S26>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S26>/Delay Input1':
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

  /* Update for UnitDelay: '<S10>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S10>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_a_o = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b + (real32_T)
    FMS_EXPORT.period;
  if (rtb_a_o < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_a_o;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */

  /* Update for Delay: '<S11>/Delay' */
  FMS_DW.Delay_DSTATE_o = rtb_Switch_ga;
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
    FMS_B.vtol_mode = VTOLMode_Multicopter;
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
  /* Start for SwitchCase: '<S29>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S29>/Arm' */
  /* Start for SwitchCase: '<S31>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for IfAction SubSystem: '<S31>/MC_Mode' */
  /* Start for SwitchCase: '<S36>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S36>/SubMode' */
  /* Start for SwitchCase: '<S226>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S226>/Return' */
  /* Start for SwitchCase: '<S611>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ln = -1;

  /* Start for SwitchCase: '<S601>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pv = -1;

  /* End of Start for SubSystem: '<S226>/Return' */

  /* Start for IfAction SubSystem: '<S226>/Hold' */
  /* Start for SwitchCase: '<S550>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S528>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S538>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_cv = -1;

  /* End of Start for SubSystem: '<S226>/Hold' */
  /* End of Start for SubSystem: '<S36>/SubMode' */

  /* Start for IfAction SubSystem: '<S36>/Auto' */
  /* Start for SwitchCase: '<S224>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S224>/Mission' */
  /* Start for Resettable SubSystem: '<S336>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S384>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* Start for SwitchCase: '<S374>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_af = -1;

  /* End of Start for SubSystem: '<S336>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S224>/Mission' */
  /* End of Start for SubSystem: '<S36>/Auto' */

  /* Start for IfAction SubSystem: '<S36>/Assist' */
  /* Start for SwitchCase: '<S223>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S223>/Stabilize' */
  /* Start for SwitchCase: '<S323>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S223>/Stabilize' */

  /* Start for IfAction SubSystem: '<S223>/Altitude' */
  /* Start for SwitchCase: '<S238>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S256>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S223>/Altitude' */

  /* Start for IfAction SubSystem: '<S223>/Position' */
  /* Start for SwitchCase: '<S272>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S297>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S284>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S223>/Position' */
  /* End of Start for SubSystem: '<S36>/Assist' */
  /* End of Start for SubSystem: '<S31>/MC_Mode' */

  /* Start for IfAction SubSystem: '<S31>/FW_Mode' */
  /* Start for SwitchCase: '<S35>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* Start for IfAction SubSystem: '<S35>/SubMode' */
  /* Start for SwitchCase: '<S40>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;

  /* End of Start for SubSystem: '<S35>/SubMode' */

  /* Start for IfAction SubSystem: '<S35>/Auto' */
  /* Start for SwitchCase: '<S38>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S35>/Auto' */

  /* Start for IfAction SubSystem: '<S35>/Assist' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S37>/Altitude' */
  /* Start for SwitchCase: '<S50>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* End of Start for SubSystem: '<S37>/Altitude' */

  /* Start for IfAction SubSystem: '<S37>/Position' */
  /* Start for SwitchCase: '<S85>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S71>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;

  /* End of Start for SubSystem: '<S37>/Position' */
  /* End of Start for SubSystem: '<S35>/Assist' */
  /* End of Start for SubSystem: '<S31>/FW_Mode' */
  /* End of Start for SubSystem: '<S29>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_p = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_active_Lost_Return = 0U;
  FMS_DW.is_Lost_Return = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_active_VTOL_Mode = 0U;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_p;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_p;
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
  /* SystemInitialize for IfAction SubSystem: '<S29>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S31>/MC_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S36>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S226>/Takeoff' */
  /* InitializeConditions for Delay: '<S651>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S647>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S647>/Integrator' */
  FMS_DW.Integrator_DSTATE_k1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S226>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S226>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S566>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_gs = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S566>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S226>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S226>/Return' */
  /* InitializeConditions for Delay: '<S596>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S597>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S592>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S638>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S575>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S578>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;

  /* InitializeConditions for Delay: '<S574>/Delay' */
  FMS_DW.icLoad_f = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S578>/Integrator' */
  FMS_DW.Integrator_DSTATE_fr = 0.0F;

  /* SystemInitialize for Chart: '<S612>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState);

  /* SystemInitialize for IfAction SubSystem: '<S611>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S611>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S611>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S611>/Move Control' */

  /* SystemInitialize for Merge: '<S611>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S602>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S601>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S601>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S601>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S601>/Move Control' */

  /* SystemInitialize for Merge: '<S601>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S226>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S226>/Hold' */
  /* SystemInitialize for Chart: '<S529>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S539>/Motion State' */
  FMS_DW.temporalCounter_i1_il = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for Chart: '<S551>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S550>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S550>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S550>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S550>/Move Control' */

  /* SystemInitialize for Merge: '<S550>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S528>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S528>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S528>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S528>/Move Control' */

  /* SystemInitialize for Merge: '<S528>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S538>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S538>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S538>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S538>/Move Control' */

  /* SystemInitialize for Merge: '<S538>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S226>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S36>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S224>/Mission' */
  /* InitializeConditions for UnitDelay: '<S339>/Delay Input1'
   *
   * Block description for '<S339>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S336>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S366>/Delay' */
  FMS_DW.icLoad_p = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S367>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S362>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S411>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S344>/Delay' */
  FMS_DW.icLoad_mb = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S347>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S347>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S385>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S384>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_fy);

  /* End of SystemInitialize for SubSystem: '<S384>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S384>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_i);

  /* End of SystemInitialize for SubSystem: '<S384>/Move Control' */

  /* SystemInitialize for Merge: '<S384>/Merge' */
  FMS_B.Merge_ls[0] = 0.0F;
  FMS_B.Merge_ls[1] = 0.0F;

  /* SystemInitialize for Chart: '<S375>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_h);

  /* SystemInitialize for IfAction SubSystem: '<S374>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_b);

  /* End of SystemInitialize for SubSystem: '<S374>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S374>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S374>/Move Control' */

  /* SystemInitialize for Merge: '<S374>/Merge' */
  FMS_B.Merge_i = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S336>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S224>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S36>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S36>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S223>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S319>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S320>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S319>/Integrator' */
  FMS_DW.Integrator_DSTATE_ib = 0.0F;

  /* SystemInitialize for Chart: '<S324>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S323>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S323>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S323>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S323>/Move Control' */

  /* SystemInitialize for Merge: '<S323>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S223>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S223>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S252>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mf = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S253>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_hg = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S253>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S252>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S239>/Motion Status' */
  FMS_MotionStatus_c_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S238>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S238>/Hold Control' */

  /* SystemInitialize for Merge: '<S238>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S257>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S256>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S256>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S256>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S256>/Move Control' */

  /* SystemInitialize for Merge: '<S256>/Merge' */
  FMS_B.Merge_bd = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S223>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S223>/Position' */
  /* SystemInitialize for Chart: '<S273>/Motion Status' */
  FMS_MotionStatus_c_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S272>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S272>/Hold Control' */

  /* SystemInitialize for Chart: '<S285>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S298>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S297>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_jz);

  /* End of SystemInitialize for SubSystem: '<S297>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S297>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S307>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_b[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S307>/Integrator' */
  FMS_DW.Integrator_DSTATE_l[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S297>/Move Control' */

  /* SystemInitialize for Merge: '<S297>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S297>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S307>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_b[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S307>/Integrator' */
  FMS_DW.Integrator_DSTATE_l[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S297>/Move Control' */

  /* SystemInitialize for Merge: '<S297>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Merge: '<S272>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S284>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S284>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S284>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S284>/Move Control' */

  /* SystemInitialize for Merge: '<S284>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S223>/Position' */
  /* End of SystemInitialize for SubSystem: '<S36>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S31>/MC_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S31>/FW_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S35>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S40>/Hold' */
  /* InitializeConditions for Delay: '<S166>/start_vel' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for Delay: '<S161>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* End of SystemInitialize for SubSystem: '<S40>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S35>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S35>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S38>/Mission' */
  /* InitializeConditions for UnitDelay: '<S130>/Delay Input1'
   *
   * Block description for '<S130>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* End of SystemInitialize for SubSystem: '<S38>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S35>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S35>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S37>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S125>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S125>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S62>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S65>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S65>/Integrator' */
  FMS_DW.Integrator_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S62>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S51>/Motion Status' */
  FMS_MotionStatus_c_Init(&FMS_DW.sf_MotionStatus_a);

  /* SystemInitialize for IfAction SubSystem: '<S50>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_o);

  /* End of SystemInitialize for SubSystem: '<S50>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S50>/Move Control' */
  FMS_MoveControl_e_Init(&FMS_DW.MoveControl_ou);

  /* End of SystemInitialize for SubSystem: '<S50>/Move Control' */

  /* SystemInitialize for Merge: '<S50>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S37>/Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S83>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* SystemInitialize for Chart: '<S72>/Motion Status' */
  FMS_MotionStatus_c_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S86>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c26_FMS = 0U;
  FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

  /* SystemInitialize for IfAction SubSystem: '<S85>/Hold Control' */
  /* InitializeConditions for Delay: '<S92>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S92>/start_wp' */
  FMS_DW.icLoad_e = 1U;

  /* End of SystemInitialize for SubSystem: '<S85>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S85>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S85>/Move Control' */

  /* SystemInitialize for IfAction SubSystem: '<S71>/Hold Control' */
  FMS_HoldControl_e_Init(&FMS_DW.HoldControl_jx);

  /* End of SystemInitialize for SubSystem: '<S71>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S71>/Move Control' */
  FMS_MoveControl_e_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S71>/Move Control' */

  /* SystemInitialize for Merge: '<S71>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for Merge: '<S85>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S37>/Position' */
  /* End of SystemInitialize for SubSystem: '<S35>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S31>/FW_Mode' */
  /* End of SystemInitialize for SubSystem: '<S29>/Arm' */
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
