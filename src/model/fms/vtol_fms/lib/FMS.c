/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2472
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jul 30 16:19:08 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S99>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S687>/Motion Status' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S697>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S393>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S134>/Motion State' */
#define FMS_IN_Brake_bw                ((uint8_T)1U)
#define FMS_IN_Hold_od                 ((uint8_T)2U)
#define FMS_IN_Move_p                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_o       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Align                   ((uint8_T)1U)
#define FMS_IN_Altitude                ((uint8_T)2U)
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_BackTrans               ((uint8_T)1U)
#define FMS_IN_BackwardTrans           ((uint8_T)1U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Connect                 ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Disarming               ((uint8_T)1U)
#define FMS_IN_Execute                 ((uint8_T)2U)
#define FMS_IN_Fixwing                 ((uint8_T)2U)
#define FMS_IN_ForwardTrans            ((uint8_T)3U)
#define FMS_IN_Hold_h                  ((uint8_T)1U)
#define FMS_IN_Hold_hs                 ((uint8_T)4U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)3U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Land                    ((uint8_T)2U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)2U)
#define FMS_IN_Loiter_p                ((uint8_T)1U)
#define FMS_IN_Lost                    ((uint8_T)2U)
#define FMS_IN_MC_Land                 ((uint8_T)1U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_o                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_Multicopter             ((uint8_T)4U)
#define FMS_IN_NextWP                  ((uint8_T)3U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_g                ((uint8_T)2U)
#define FMS_IN_Return_gw               ((uint8_T)4U)
#define FMS_IN_Run                     ((uint8_T)2U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)5U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_IN_Takeoff_k               ((uint8_T)5U)
#define FMS_IN_Takeoff_k2              ((uint8_T)1U)
#define FMS_IN_Transition              ((uint8_T)6U)
#define FMS_IN_VTOL_Land               ((uint8_T)2U)
#define FMS_IN_VTOL_Land_c             ((uint8_T)7U)
#define FMS_IN_Wait                    ((uint8_T)4U)
#define FMS_IN_WaitBackTransCplt       ((uint8_T)8U)
#define FMS_IN_Wait_k                  ((uint8_T)5U)
#define FMS_IN_Waypoint                ((uint8_T)9U)
#define FMS_IN_Waypoint_c              ((uint8_T)2U)
#define FMS_IN_Waypoint_cj             ((uint8_T)4U)
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
  ,                                    /* home */
  0U                                   /* error */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_sVzVC2xSXHFQuusuHtL6zE FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  1.2F,
  1.5F,
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
  30.0F,
  20.0F,
  17.0F,
  1.0F,
  10.0F,
  8.0F,
  0.785398185F,
  0.52359879F,
  0.52359879F,
  22.0F,
  50.0F,
  0.95F,
  8.0F,
  0.785398185F,
  0.785398185F,
  1.0F,
  55.0F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S4>/Constant1'
                                        *   '<S37>/Constant'
                                        *   '<S739>/Constant'
                                        *   '<S740>/FW_ACCEPT_R'
                                        *   '<S740>/MC_ACCEPT_R'
                                        *   '<S743>/Constant'
                                        *   '<S48>/L1'
                                        *   '<S221>/Dead Zone'
                                        *   '<S221>/Gain'
                                        *   '<S222>/Dead Zone'
                                        *   '<S222>/Gain'
                                        *   '<S223>/Dead Zone'
                                        *   '<S223>/Gain'
                                        *   '<S224>/Dead Zone'
                                        *   '<S224>/Gain'
                                        *   '<S227>/Constant4'
                                        *   '<S228>/Constant4'
                                        *   '<S597>/L1'
                                        *   '<S94>/Gain'
                                        *   '<S96>/Gain'
                                        *   '<S97>/Gain1'
                                        *   '<S115>/Gain'
                                        *   '<S117>/Gain1'
                                        *   '<S181>/Gain'
                                        *   '<S181>/Gain1'
                                        *   '<S182>/Gain1'
                                        *   '<S230>/Gain2'
                                        *   '<S230>/Saturation1'
                                        *   '<S231>/L1'
                                        *   '<S231>/R'
                                        *   '<S231>/Saturation1'
                                        *   '<S248>/Gain'
                                        *   '<S248>/Saturation1'
                                        *   '<S270>/Gain'
                                        *   '<S270>/Saturation1'
                                        *   '<S305>/Gain'
                                        *   '<S305>/Gain1'
                                        *   '<S383>/Gain'
                                        *   '<S383>/Gain1'
                                        *   '<S385>/Constant'
                                        *   '<S409>/L1'
                                        *   '<S490>/Saturation'
                                        *   '<S491>/Saturation1'
                                        *   '<S491>/Saturation2'
                                        *   '<S491>/Saturation3'
                                        *   '<S648>/Land_Speed'
                                        *   '<S649>/Saturation1'
                                        *   '<S728>/Takeoff_Speed'
                                        *   '<S729>/Gain2'
                                        *   '<S729>/Saturation1'
                                        *   '<S98>/Saturation1'
                                        *   '<S109>/Dead Zone'
                                        *   '<S109>/Gain'
                                        *   '<S112>/Dead Zone'
                                        *   '<S112>/Gain'
                                        *   '<S119>/Saturation1'
                                        *   '<S130>/Dead Zone'
                                        *   '<S130>/Gain'
                                        *   '<S133>/Saturation1'
                                        *   '<S184>/Dead Zone'
                                        *   '<S184>/Gain'
                                        *   '<S185>/Dead Zone'
                                        *   '<S185>/Gain'
                                        *   '<S190>/Dead Zone'
                                        *   '<S190>/Gain'
                                        *   '<S198>/Gain'
                                        *   '<S198>/Saturation1'
                                        *   '<S199>/Constant4'
                                        *   '<S253>/L1'
                                        *   '<S253>/Saturation1'
                                        *   '<S275>/L1'
                                        *   '<S275>/Saturation1'
                                        *   '<S307>/Saturation1'
                                        *   '<S319>/Dead Zone'
                                        *   '<S319>/Gain'
                                        *   '<S320>/Dead Zone'
                                        *   '<S320>/Gain'
                                        *   '<S325>/Saturation'
                                        *   '<S341>/Saturation1'
                                        *   '<S353>/Saturation'
                                        *   '<S366>/Saturation1'
                                        *   '<S386>/Dead Zone'
                                        *   '<S386>/Gain'
                                        *   '<S387>/Dead Zone'
                                        *   '<S387>/Gain'
                                        *   '<S392>/Saturation'
                                        *   '<S546>/Gain2'
                                        *   '<S553>/Gain1'
                                        *   '<S553>/Gain2'
                                        *   '<S603>/Saturation1'
                                        *   '<S614>/Saturation'
                                        *   '<S635>/Saturation1'
                                        *   '<S650>/Constant'
                                        *   '<S653>/Gain2'
                                        *   '<S677>/Constant'
                                        *   '<S677>/vel'
                                        *   '<S677>/Acceleration_Speed'
                                        *   '<S677>/Saturation'
                                        *   '<S677>/Switch'
                                        *   '<S681>/Constant'
                                        *   '<S101>/Gain2'
                                        *   '<S102>/Gain1'
                                        *   '<S107>/Constant'
                                        *   '<S122>/Gain2'
                                        *   '<S123>/Gain1'
                                        *   '<S128>/Constant'
                                        *   '<S136>/L1'
                                        *   '<S137>/Gain6'
                                        *   '<S176>/Constant'
                                        *   '<S177>/Constant'
                                        *   '<S204>/L1'
                                        *   '<S204>/Saturation1'
                                        *   '<S310>/Gain2'
                                        *   '<S311>/Gain1'
                                        *   '<S317>/Constant'
                                        *   '<S328>/Gain2'
                                        *   '<S329>/Gain1'
                                        *   '<S336>/Constant'
                                        *   '<S344>/Gain2'
                                        *   '<S345>/Gain1'
                                        *   '<S351>/Constant'
                                        *   '<S356>/Gain2'
                                        *   '<S357>/Gain1'
                                        *   '<S364>/Constant'
                                        *   '<S369>/Gain2'
                                        *   '<S370>/Gain6'
                                        *   '<S380>/Constant'
                                        *   '<S381>/Constant'
                                        *   '<S395>/Gain2'
                                        *   '<S396>/Gain1'
                                        *   '<S403>/Constant'
                                        *   '<S428>/Gain'
                                        *   '<S428>/Saturation1'
                                        *   '<S431>/Constant'
                                        *   '<S431>/vel'
                                        *   '<S431>/Switch'
                                        *   '<S606>/Gain2'
                                        *   '<S607>/Gain1'
                                        *   '<S618>/Gain2'
                                        *   '<S619>/Gain1'
                                        *   '<S627>/Gain2'
                                        *   '<S627>/Saturation'
                                        *   '<S628>/Integrator'
                                        *   '<S638>/Gain2'
                                        *   '<S639>/Gain6'
                                        *   '<S662>/Gain2'
                                        *   '<S662>/Saturation'
                                        *   '<S663>/Integrator'
                                        *   '<S104>/Dead Zone'
                                        *   '<S104>/Gain'
                                        *   '<S125>/Dead Zone'
                                        *   '<S125>/Gain'
                                        *   '<S173>/Dead Zone'
                                        *   '<S173>/Gain'
                                        *   '<S313>/Land_Speed'
                                        *   '<S314>/Constant'
                                        *   '<S316>/Dead Zone'
                                        *   '<S316>/Gain'
                                        *   '<S333>/Dead Zone'
                                        *   '<S333>/Gain'
                                        *   '<S347>/Land_Speed'
                                        *   '<S348>/Constant'
                                        *   '<S350>/Dead Zone'
                                        *   '<S350>/Gain'
                                        *   '<S361>/Dead Zone'
                                        *   '<S361>/Gain'
                                        *   '<S374>/Dead Zone'
                                        *   '<S374>/Gain'
                                        *   '<S375>/Dead Zone'
                                        *   '<S375>/Gain'
                                        *   '<S400>/Dead Zone'
                                        *   '<S400>/Gain'
                                        *   '<S415>/Gain2'
                                        *   '<S415>/Saturation'
                                        *   '<S416>/Integrator'
                                        *   '<S609>/Dead Zone'
                                        *   '<S609>/Gain'
                                        *   '<S623>/Dead Zone'
                                        *   '<S623>/Gain'
                                        *   '<S643>/Dead Zone'
                                        *   '<S643>/Gain'
                                        *   '<S644>/Dead Zone'
                                        *   '<S644>/Gain'
                                        *   '<S686>/Saturation1'
                                        *   '<S696>/Saturation1'
                                        *   '<S446>/Saturation1'
                                        *   '<S456>/Saturation1'
                                        *   '<S689>/Gain2'
                                        *   '<S690>/Gain1'
                                        *   '<S699>/Gain2'
                                        *   '<S700>/Gain6'
                                        *   '<S449>/Gain2'
                                        *   '<S450>/Gain1'
                                        *   '<S459>/Gain2'
                                        *   '<S460>/Gain6'
                                        *   '<S692>/Dead Zone'
                                        *   '<S692>/Gain'
                                        *   '<S704>/Dead Zone'
                                        *   '<S704>/Gain'
                                        *   '<S705>/Dead Zone'
                                        *   '<S705>/Gain'
                                        *   '<S452>/Dead Zone'
                                        *   '<S452>/Gain'
                                        *   '<S464>/Dead Zone'
                                        *   '<S464>/Gain'
                                        *   '<S465>/Dead Zone'
                                        *   '<S465>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S23>/Constant1'
                                        *   '<S738>/Constant'
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
static void FMS_Command_Listener(void);
static boolean_T FMS_BottomRight(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_BottomLeft(real32_T pilot_cmd_stick_yaw, real32_T
  pilot_cmd_stick_throttle);
static boolean_T FMS_sf_msg_pop_M(void);
static void FMS_sf_msg_send_VTOL_M(void);
static void FMS_enter_internal_Hold(void);
static void FMS_enter_internal_VTOL_Land(void);
static real32_T FMS_norm(const real32_T x[2]);
static void FMS_VTOL_Land(void);
static void FMS_Waypoint(void);
static void FMS_exit_internal_Mission(void);
static void FMS_Mission(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
static void FMS_enter_internal_Assist(void);
static void FMS_enter_internal_Auto(void);
static void FMS_enter_internal_Arm(void);
static void FMS_exit_internal_SubMode(void);
static void FMS_SubMode(void);
static void FMS_exit_internal_Arm(void);
static void FMS_Arm(void);
static real_T FMS_ManualArmEvent(real32_T pilot_cmd_stick_throttle, uint32_T
  pilot_cmd_mode);
static void FMS_Vehicle(void);
static boolean_T FMS_CheckModeValid(VTOLMode vtol_mode_in, VTOLState
  vtol_state_in);
static boolean_T FMS_sf_msg_pop_VTOL_M(void);
static void FMS_c11_FMS(void);
static void FMS_sf_msg_discard_M(void);
static void FMS_sf_msg_discard_VTOL_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for atomic system:
 *    '<S277>/NearbyRefWP'
 *    '<S255>/NearbyRefWP'
 *    '<S206>/NearbyRefWP'
 *    '<S679>/NearbyRefWP'
 *    '<S433>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S281>/TmpSignal ConversionAt SFunction Inport2' */
  P3P2_idx_0 = rtu_P2[0] - rtu_P3;
  P3P2_idx_1 = rtu_P2[1] - rtu_P3_f;
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
 * Output and update for atomic system:
 *    '<S277>/SearchL1RefWP'
 *    '<S255>/SearchL1RefWP'
 *    '<S206>/SearchL1RefWP'
 *    '<S679>/SearchL1RefWP'
 *    '<S433>/SearchL1RefWP'
 */
void FMS_SearchL1RefWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_i, real32_T rtu_L1, real32_T rty_P[2],
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

  /* SignalConversion: '<S283>/TmpSignal ConversionAt SFunction Inport3' */
  B = ((rtu_P2[0] - rtu_P1[0]) * (rtu_P1[0] - rtu_P3) + (rtu_P2[1] - rtu_P1[1]) *
       (rtu_P1[1] - rtu_P3_i)) * 2.0F;
  D = B * B - (((((rtu_P3 * rtu_P3 + rtu_P3_i * rtu_P3_i) + rtu_P1[0] * rtu_P1[0])
                 + rtu_P1[1] * rtu_P1[1]) - (rtu_P3 * rtu_P1[0] + rtu_P3_i *
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
 * Output and update for atomic system:
 *    '<S255>/OutRegionRegWP'
 *    '<S206>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S260>/TmpSignal ConversionAt SFunction Inport3' */
  P1P3_idx_0 = rtu_P3 - rtu_P1[0];
  P1P3_idx_1 = rtu_P3_p - rtu_P1[1];
  u_tmp = rty_P[0] * rty_P[0] + rty_P[1] * rty_P[1];
  P1P3_idx_0 = (P1P3_idx_0 * rty_P[0] + P1P3_idx_1 * rty_P[1]) / u_tmp;
  if (P1P3_idx_0 >= 1.0F) {
    rty_P[0] = rtu_P2[0];
    rty_P[1] = rtu_P2[1];
  } else {
    P1P3_idx_0 += rtu_L1 / sqrtf(u_tmp);
    if (P1P3_idx_0 > 1.0F) {
      P1P3_idx_0 = 1.0F;
    } else {
      if (P1P3_idx_0 < 0.0F) {
        P1P3_idx_0 = 0.0F;
      }
    }

    rty_P[0] = P1P3_idx_0 * rty_P[0] + rtu_P1[0];
    rty_P[1] = P1P3_idx_0 * rty_P[1] + rtu_P1[1];
  }
}

/*
 * Output and update for action system:
 *    '<S88>/Unknown'
 *    '<S86>/Unknown'
 *    '<S85>/Unknown'
 *    '<S46>/Unknown'
 *    '<S295>/Unknown'
 *    '<S293>/Unknown'
 *    '<S292>/Unknown'
 *    '<S47>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S229>/Bus Assignment' incorporates:
   *  Constant: '<S229>/Constant'
   *  Constant: '<S229>/Constant2'
   *  SignalConversion: '<S229>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S229>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S98>/Hold Control'
 *    '<S119>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S101>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S98>/Hold Control'
 *    '<S119>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S101>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S98>/Hold Control'
 *    '<S119>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S101>/Delay' incorporates:
   *  Gain: '<S103>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S101>/Gain2' incorporates:
   *  Delay: '<S101>/Delay'
   *  Gain: '<S103>/Gain'
   *  Sum: '<S101>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.FW_Z_P;

  /* Update for Delay: '<S101>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S98>/Brake Control'
 *    '<S119>/Brake Control'
 *    '<S686>/Brake Control'
 *    '<S603>/Brake Control'
 *    '<S614>/Brake Control'
 *    '<S446>/Brake Control'
 *    '<S392>/Brake Control'
 *    '<S307>/Brake Control'
 *    '<S325>/Brake Control'
 *    '<S341>/Brake Control'
 *    '<S353>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S100>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S100>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S98>/Move Control'
 *    '<S119>/Move Control'
 */
void FMS_MoveControl_Init(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S98>/Move Control'
 *    '<S119>/Move Control'
 */
void FMS_MoveControl_Reset(DW_MoveControl_FMS_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S98>/Move Control'
 *    '<S119>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
                     ConstB_MoveControl_FMS_T *localC, DW_MoveControl_FMS_T
                     *localDW)
{
  real32_T rtb_Add3_ci;
  real32_T rtb_Subtract3_df;
  real32_T rtb_a_bz;
  real32_T rtb_Add4_lp;
  real32_T rtb_a_f;

  /* Product: '<S106>/Multiply1' incorporates:
   *  Constant: '<S106>/const1'
   *  DiscreteIntegrator: '<S105>/Integrator'
   */
  rtb_Add3_ci = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S104>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_a_bz = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_a_bz = 0.0F;
  } else {
    rtb_a_bz = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S104>/Dead Zone' */

  /* Sum: '<S106>/Add' incorporates:
   *  DiscreteIntegrator: '<S105>/Integrator1'
   *  Gain: '<S102>/Gain1'
   *  Gain: '<S104>/Gain'
   *  Sum: '<S105>/Subtract'
   */
  rtb_Subtract3_df = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_a_bz * FMS_PARAM.FW_VEL_Z_LIM) + rtb_Add3_ci;

  /* Signum: '<S106>/Sign' */
  if (rtb_Subtract3_df < 0.0F) {
    rtb_a_bz = -1.0F;
  } else if (rtb_Subtract3_df > 0.0F) {
    rtb_a_bz = 1.0F;
  } else {
    rtb_a_bz = rtb_Subtract3_df;
  }

  /* End of Signum: '<S106>/Sign' */

  /* Sum: '<S106>/Add2' incorporates:
   *  Abs: '<S106>/Abs'
   *  Gain: '<S106>/Gain'
   *  Gain: '<S106>/Gain1'
   *  Product: '<S106>/Multiply2'
   *  Product: '<S106>/Multiply3'
   *  Sqrt: '<S106>/Sqrt'
   *  Sum: '<S106>/Add1'
   *  Sum: '<S106>/Subtract'
   */
  rtb_a_bz = (sqrtf((8.0F * fabsf(rtb_Subtract3_df) + localC->d) * localC->d) -
              localC->d) * 0.5F * rtb_a_bz + rtb_Add3_ci;

  /* Sum: '<S106>/Add4' */
  rtb_Add4_lp = (rtb_Subtract3_df - rtb_a_bz) + rtb_Add3_ci;

  /* Sum: '<S106>/Add3' */
  rtb_Add3_ci = rtb_Subtract3_df + localC->d;

  /* Sum: '<S106>/Subtract1' */
  rtb_Subtract3_df -= localC->d;

  /* Signum: '<S106>/Sign1' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S106>/Sign1' */

  /* Signum: '<S106>/Sign2' */
  if (rtb_Subtract3_df < 0.0F) {
    rtb_Subtract3_df = -1.0F;
  } else {
    if (rtb_Subtract3_df > 0.0F) {
      rtb_Subtract3_df = 1.0F;
    }
  }

  /* End of Signum: '<S106>/Sign2' */

  /* Sum: '<S106>/Add5' incorporates:
   *  Gain: '<S106>/Gain2'
   *  Product: '<S106>/Multiply4'
   *  Sum: '<S106>/Subtract2'
   */
  rtb_a_bz += (rtb_Add3_ci - rtb_Subtract3_df) * 0.5F * rtb_Add4_lp;

  /* SignalConversion: '<S102>/OutportBufferForw_cmd_mPs' incorporates:
   *  DiscreteIntegrator: '<S105>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S105>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S105>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S106>/Add6' */
  rtb_Add3_ci = rtb_a_bz + localC->d;

  /* Sum: '<S106>/Subtract3' */
  rtb_Subtract3_df = rtb_a_bz - localC->d;

  /* Signum: '<S106>/Sign5' */
  if (rtb_a_bz < 0.0F) {
    rtb_Add4_lp = -1.0F;
  } else if (rtb_a_bz > 0.0F) {
    rtb_Add4_lp = 1.0F;
  } else {
    rtb_Add4_lp = rtb_a_bz;
  }

  /* End of Signum: '<S106>/Sign5' */

  /* Signum: '<S106>/Sign3' */
  if (rtb_Add3_ci < 0.0F) {
    rtb_Add3_ci = -1.0F;
  } else {
    if (rtb_Add3_ci > 0.0F) {
      rtb_Add3_ci = 1.0F;
    }
  }

  /* End of Signum: '<S106>/Sign3' */

  /* Signum: '<S106>/Sign4' */
  if (rtb_Subtract3_df < 0.0F) {
    rtb_Subtract3_df = -1.0F;
  } else {
    if (rtb_Subtract3_df > 0.0F) {
      rtb_Subtract3_df = 1.0F;
    }
  }

  /* End of Signum: '<S106>/Sign4' */

  /* Signum: '<S106>/Sign6' */
  if (rtb_a_bz < 0.0F) {
    rtb_a_f = -1.0F;
  } else if (rtb_a_bz > 0.0F) {
    rtb_a_f = 1.0F;
  } else {
    rtb_a_f = rtb_a_bz;
  }

  /* End of Signum: '<S106>/Sign6' */

  /* Update for DiscreteIntegrator: '<S105>/Integrator' incorporates:
   *  Constant: '<S106>/const'
   *  Gain: '<S106>/Gain3'
   *  Product: '<S106>/Divide'
   *  Product: '<S106>/Multiply5'
   *  Product: '<S106>/Multiply6'
   *  Sum: '<S106>/Subtract4'
   *  Sum: '<S106>/Subtract5'
   *  Sum: '<S106>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_bz / localC->d - rtb_Add4_lp) *
    localC->Gain4 * ((rtb_Add3_ci - rtb_Subtract3_df) * 0.5F) - rtb_a_f *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S99>/Motion Status'
 *    '<S120>/Motion Status'
 *    '<S308>/Motion Status'
 *    '<S342>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S99>/Motion Status'
 *    '<S120>/Motion Status'
 *    '<S308>/Motion Status'
 *    '<S342>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c10_FMS = 0U;
  localDW->is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S99>/Motion Status'
 *    '<S120>/Motion Status'
 *    '<S308>/Motion Status'
 *    '<S342>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S99>/Motion Status' */
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
        if (rtu_motion_req) {
          localDW->is_c10_FMS = FMS_IN_Move;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req) {
        localDW->is_c10_FMS = FMS_IN_Move;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (!rtu_motion_req) {
        localDW->is_c10_FMS = FMS_IN_Brake;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S99>/Motion Status' */
}

/*
 * Output and update for atomic system:
 *    '<S139>/OutRegionRefWP'
 *    '<S51>/OutRegionRefWP'
 */
void FMS_OutRegionRefWP(real32_T rtu_c, real32_T rtu_c_f, const real32_T rtu_p0
  [2], const real32_T rtu_n[2], real32_T rty_P[2])
{
  real32_T t;
  real32_T d1;
  real32_T scale;
  real32_T absxk;
  real32_T b_t;

  /* SignalConversion: '<S150>/TmpSignal ConversionAt SFunction Inport1' */
  t = (rtu_c - rtu_p0[0]) * rtu_n[0] + (rtu_c_f - rtu_p0[1]) * rtu_n[1];
  scale = 1.29246971E-26F;

  /* SignalConversion: '<S150>/TmpSignal ConversionAt SFunction Inport1' */
  absxk = fabsf((t * rtu_n[0] + rtu_p0[0]) - rtu_c);
  if (absxk > 1.29246971E-26F) {
    d1 = 1.0F;
    scale = absxk;
  } else {
    b_t = absxk / 1.29246971E-26F;
    d1 = b_t * b_t;
  }

  /* SignalConversion: '<S150>/TmpSignal ConversionAt SFunction Inport1' */
  absxk = fabsf((t * rtu_n[1] + rtu_p0[1]) - rtu_c_f);
  if (absxk > scale) {
    b_t = scale / absxk;
    d1 = d1 * b_t * b_t + 1.0F;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    d1 += b_t * b_t;
  }

  d1 = scale * sqrtf(d1);
  t += d1 * 0.577350259F;
  rty_P[0] = t * rtu_n[0] + rtu_p0[0];
  rty_P[1] = t * rtu_n[1] + rtu_p0[1];
}

/*
 * Output and update for atomic system:
 *    '<S139>/SearchL1RefWP'
 *    '<S51>/SearchL1RefWP'
 */
void FMS_SearchL1RefWP_k(real32_T rtu_c, real32_T rtu_c_n, const real32_T
  rtu_p0[2], const real32_T rtu_n[2], real32_T rtu_L1, real32_T rty_P[2],
  real32_T *rty_t)
{
  real32_T B;
  real32_T m_idx_0;
  real32_T m_idx_1;

  /* SignalConversion: '<S151>/TmpSignal ConversionAt SFunction Inport1' */
  m_idx_0 = rtu_p0[0] - rtu_c;
  m_idx_1 = rtu_p0[1] - rtu_c_n;
  B = (rtu_n[0] * m_idx_0 + rtu_n[1] * m_idx_1) * 2.0F;
  rty_P[0] = 0.0F;
  rty_P[1] = 0.0F;
  m_idx_0 = B * B - ((m_idx_0 * m_idx_0 + m_idx_1 * m_idx_1) - rtu_L1 * rtu_L1) *
    4.0F;
  m_idx_1 = -1.0F;
  if (m_idx_0 > 0.0F) {
    m_idx_0 = sqrtf(m_idx_0);
    m_idx_1 = fmaxf((-B + m_idx_0) / 2.0F, (-B - m_idx_0) / 2.0F);
    rty_P[0] = m_idx_1 * rtu_n[0] + rtu_p0[0];
    rty_P[1] = m_idx_1 * rtu_n[1] + rtu_p0[1];
  } else {
    if (m_idx_0 == 0.0F) {
      m_idx_1 = -B / 2.0F;
      rty_P[0] = m_idx_1 * rtu_n[0] + rtu_p0[0];
      rty_P[1] = m_idx_1 * rtu_n[1] + rtu_p0[1];
    }
  }

  *rty_t = m_idx_1;
}

/*
 * System initialize for action system:
 *    '<S686>/Hold Control'
 *    '<S603>/Hold Control'
 *    '<S446>/Hold Control'
 *    '<S307>/Hold Control'
 *    '<S341>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S689>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S686>/Hold Control'
 *    '<S603>/Hold Control'
 *    '<S446>/Hold Control'
 *    '<S307>/Hold Control'
 *    '<S341>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S689>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S686>/Hold Control'
 *    '<S603>/Hold Control'
 *    '<S446>/Hold Control'
 *    '<S307>/Hold Control'
 *    '<S341>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S689>/Delay' incorporates:
   *  Gain: '<S691>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S689>/Gain2' incorporates:
   *  Delay: '<S689>/Delay'
   *  Gain: '<S691>/Gain'
   *  Sum: '<S689>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S689>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S686>/Move Control'
 *    '<S603>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S693>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S693>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S686>/Move Control'
 *    '<S603>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S693>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S693>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S686>/Move Control'
 *    '<S603>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_aw;
  real32_T rtb_Subtract3_d;
  real32_T rtb_a_o;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S694>/Multiply1' incorporates:
   *  Constant: '<S694>/const1'
   *  DiscreteIntegrator: '<S693>/Integrator'
   */
  rtb_Add3_aw = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S692>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = 0.0F;
  } else {
    rtb_a_o = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S692>/Dead Zone' */

  /* Sum: '<S694>/Add' incorporates:
   *  DiscreteIntegrator: '<S693>/Integrator1'
   *  Gain: '<S690>/Gain1'
   *  Gain: '<S692>/Gain'
   *  Sum: '<S693>/Subtract'
   */
  rtb_Subtract3_d = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_o * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_aw;

  /* Signum: '<S694>/Sign' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_a_o = -1.0F;
  } else if (rtb_Subtract3_d > 0.0F) {
    rtb_a_o = 1.0F;
  } else {
    rtb_a_o = rtb_Subtract3_d;
  }

  /* End of Signum: '<S694>/Sign' */

  /* Sum: '<S694>/Add2' incorporates:
   *  Abs: '<S694>/Abs'
   *  Gain: '<S694>/Gain'
   *  Gain: '<S694>/Gain1'
   *  Product: '<S694>/Multiply2'
   *  Product: '<S694>/Multiply3'
   *  Sqrt: '<S694>/Sqrt'
   *  Sum: '<S694>/Add1'
   *  Sum: '<S694>/Subtract'
   */
  rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_d) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_o + rtb_Add3_aw;

  /* Sum: '<S694>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_d - rtb_a_o) + rtb_Add3_aw;

  /* Sum: '<S694>/Add3' */
  rtb_Add3_aw = rtb_Subtract3_d + localC->d;

  /* Sum: '<S694>/Subtract1' */
  rtb_Subtract3_d -= localC->d;

  /* Signum: '<S694>/Sign1' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S694>/Sign1' */

  /* Signum: '<S694>/Sign2' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S694>/Sign2' */

  /* Sum: '<S694>/Add5' incorporates:
   *  Gain: '<S694>/Gain2'
   *  Product: '<S694>/Multiply4'
   *  Sum: '<S694>/Subtract2'
   */
  rtb_a_o += (rtb_Add3_aw - rtb_Subtract3_d) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S693>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S693>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S693>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S693>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S694>/Add6' */
  rtb_Add3_aw = rtb_a_o + localC->d;

  /* Sum: '<S694>/Subtract3' */
  rtb_Subtract3_d = rtb_a_o - localC->d;

  /* Signum: '<S694>/Sign5' */
  if (rtb_a_o < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_o;
  }

  /* End of Signum: '<S694>/Sign5' */

  /* Signum: '<S694>/Sign3' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S694>/Sign3' */

  /* Signum: '<S694>/Sign4' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S694>/Sign4' */

  /* Signum: '<S694>/Sign6' */
  if (rtb_a_o < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_o;
  }

  /* End of Signum: '<S694>/Sign6' */

  /* Update for DiscreteIntegrator: '<S693>/Integrator' incorporates:
   *  Constant: '<S694>/const'
   *  Gain: '<S694>/Gain3'
   *  Product: '<S694>/Divide'
   *  Product: '<S694>/Multiply5'
   *  Product: '<S694>/Multiply6'
   *  Sum: '<S694>/Subtract4'
   *  Sum: '<S694>/Subtract5'
   *  Sum: '<S694>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_o / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_aw - rtb_Subtract3_d) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S687>/Motion Status'
 *    '<S604>/Motion Status'
 *    '<S447>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S687>/Motion Status'
 *    '<S604>/Motion Status'
 *    '<S447>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S687>/Motion Status'
 *    '<S604>/Motion Status'
 *    '<S447>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S687>/Motion Status' */
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c1_FMS == 0U) {
    localDW->is_active_c1_FMS = 1U;
    localDW->is_c1_FMS = FMS_IN_Move_h;
    *rty_state = MotionState_Move;
  } else {
    switch (localDW->is_c1_FMS) {
     case FMS_IN_Brake_b:
      *rty_state = MotionState_Brake;
      if ((rtu_speed <= 0.15) || (localDW->temporalCounter_i1 >= 375U)) {
        localDW->is_c1_FMS = FMS_IN_Hold_b;
        *rty_state = MotionState_Hold;
      } else {
        if (rtu_motion_req == 1.0F) {
          localDW->is_c1_FMS = FMS_IN_Move_h;
          *rty_state = MotionState_Move;
        }
      }
      break;

     case FMS_IN_Hold_b:
      *rty_state = MotionState_Hold;
      if (rtu_motion_req == 1.0F) {
        localDW->is_c1_FMS = FMS_IN_Move_h;
        *rty_state = MotionState_Move;
      }
      break;

     default:
      *rty_state = MotionState_Move;
      if (rtu_motion_req == 0.0F) {
        localDW->is_c1_FMS = FMS_IN_Brake_b;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = MotionState_Brake;
      }
      break;
    }
  }

  /* End of Chart: '<S687>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S696>/Hold Control'
 *    '<S635>/Hold Control'
 *    '<S456>/Hold Control'
 *    '<S366>/Hold Control'
 */
void FMS_HoldControl_l_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S699>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S696>/Hold Control'
 *    '<S635>/Hold Control'
 *    '<S456>/Hold Control'
 *    '<S366>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S699>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S696>/Hold Control'
 *    '<S635>/Hold Control'
 *    '<S456>/Hold Control'
 *    '<S366>/Hold Control'
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

  /* Delay: '<S699>/Delay' incorporates:
   *  SignalConversion: '<S699>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S703>/Trigonometric Function1' incorporates:
   *  Gain: '<S702>/Gain'
   *  Trigonometry: '<S703>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S703>/Trigonometric Function' incorporates:
   *  Gain: '<S702>/Gain'
   *  Trigonometry: '<S703>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S703>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S703>/Constant3'
   */
  rtb_VectorConcatenate_al[2] = 0.0F;

  /* Gain: '<S703>/Gain' */
  rtb_VectorConcatenate_al[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S703>/Trigonometric Function3' */
  rtb_VectorConcatenate_al[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S703>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S703>/Constant4'
   */
  rtb_VectorConcatenate_al[5] = 0.0F;

  /* SignalConversion: '<S703>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_al[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_al[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_al[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S699>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S699>/Delay'
   *  SignalConversion: '<S699>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S699>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S699>/Multiply' incorporates:
   *  SignalConversion: '<S699>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_al[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_al[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S699>/Multiply' */

  /* Gain: '<S699>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S699>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S696>/Brake Control'
 *    '<S635>/Brake Control'
 *    '<S456>/Brake Control'
 *    '<S366>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S698>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S696>/Move Control'
 *    '<S635>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S696>/Move Control'
 *    '<S635>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S706>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S696>/Move Control'
 *    '<S635>/Move Control'
 */
void FMS_MoveControl_k(real32_T rtu_FMS_In, real32_T rtu_FMS_In_h, real32_T
  rty_uv_cmd_mPs[2], const ConstB_MoveControl_FMS_p_T *localC,
  DW_MoveControl_FMS_l_T *localDW)
{
  real32_T rtb_Subtract3_jp;
  real32_T rtb_Add3_l_idx_0;
  real32_T rtb_Subtract3_p_idx_0;
  real32_T rtb_Add3_l_idx_1;
  real32_T rtb_Subtract3_p_idx_1;
  real32_T rtb_v2_ew_idx_0;
  real32_T rtb_v2_ew_idx_1;
  real32_T u;
  real32_T rtb_Subtract3_p_idx_0_0;

  /* DiscreteIntegrator: '<S706>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S707>/Multiply1' incorporates:
   *  Constant: '<S707>/const1'
   *  DiscreteIntegrator: '<S706>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S706>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S707>/Multiply1' incorporates:
   *  Constant: '<S707>/const1'
   *  DiscreteIntegrator: '<S706>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S704>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S704>/Dead Zone' */

  /* Sum: '<S707>/Add' incorporates:
   *  DiscreteIntegrator: '<S706>/Integrator1'
   *  Gain: '<S700>/Gain6'
   *  Gain: '<S704>/Gain'
   *  Sum: '<S706>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S705>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S705>/Dead Zone' */

  /* Sum: '<S707>/Add' incorporates:
   *  DiscreteIntegrator: '<S706>/Integrator1'
   *  Gain: '<S700>/Gain6'
   *  Gain: '<S705>/Gain'
   *  Sum: '<S706>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S707>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S707>/Add2' incorporates:
   *  Abs: '<S707>/Abs'
   *  Gain: '<S707>/Gain'
   *  Gain: '<S707>/Gain1'
   *  Product: '<S707>/Multiply2'
   *  Product: '<S707>/Multiply3'
   *  Signum: '<S707>/Sign'
   *  Sqrt: '<S707>/Sqrt'
   *  Sum: '<S707>/Add1'
   *  Sum: '<S707>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S707>/Add3' incorporates:
   *  Signum: '<S707>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S707>/Subtract1' incorporates:
   *  Signum: '<S707>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S707>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S707>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S707>/Add5' incorporates:
   *  Gain: '<S707>/Gain2'
   *  Product: '<S707>/Multiply4'
   *  Signum: '<S707>/Sign'
   *  Sum: '<S707>/Add2'
   *  Sum: '<S707>/Add4'
   *  Sum: '<S707>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S706>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S706>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S707>/Sign3' incorporates:
   *  Sum: '<S707>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S707>/Sign4' incorporates:
   *  Sum: '<S707>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S707>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S707>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S707>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S707>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S706>/Integrator' incorporates:
   *  Constant: '<S707>/const'
   *  Gain: '<S707>/Gain3'
   *  Product: '<S707>/Divide'
   *  Product: '<S707>/Multiply5'
   *  Product: '<S707>/Multiply6'
   *  Sum: '<S707>/Subtract4'
   *  Sum: '<S707>/Subtract5'
   *  Sum: '<S707>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S706>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S707>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S707>/Add2' incorporates:
   *  Abs: '<S707>/Abs'
   *  Gain: '<S707>/Gain'
   *  Gain: '<S707>/Gain1'
   *  Product: '<S707>/Multiply2'
   *  Product: '<S707>/Multiply3'
   *  Signum: '<S707>/Sign'
   *  Sqrt: '<S707>/Sqrt'
   *  Sum: '<S707>/Add1'
   *  Sum: '<S707>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S707>/Add3' incorporates:
   *  Signum: '<S707>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S707>/Subtract1' incorporates:
   *  Signum: '<S707>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S707>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S707>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S707>/Add5' incorporates:
   *  Gain: '<S707>/Gain2'
   *  Product: '<S707>/Multiply4'
   *  Signum: '<S707>/Sign'
   *  Sum: '<S707>/Add2'
   *  Sum: '<S707>/Add4'
   *  Sum: '<S707>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S706>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S706>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S707>/Sign3' incorporates:
   *  Sum: '<S707>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S707>/Sign4' incorporates:
   *  Sum: '<S707>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S707>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S707>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S707>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S707>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S706>/Integrator' incorporates:
   *  Constant: '<S707>/const'
   *  Gain: '<S707>/Gain3'
   *  Product: '<S707>/Divide'
   *  Product: '<S707>/Multiply5'
   *  Product: '<S707>/Multiply6'
   *  Sum: '<S707>/Subtract4'
   *  Sum: '<S707>/Subtract5'
   *  Sum: '<S707>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S706>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S697>/Motion State'
 *    '<S636>/Motion State'
 *    '<S457>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S697>/Motion State'
 *    '<S636>/Motion State'
 *    '<S457>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S697>/Motion State'
 *    '<S636>/Motion State'
 *    '<S457>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S697>/Motion State' */
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

  /* End of Chart: '<S697>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S679>/OutRegionRegWP'
 *    '<S433>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP_c(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_g, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S712>/TmpSignal ConversionAt SFunction Inport3' */
  P1P3_idx_0 = rtu_P3 - rtu_P1[0];
  P1P3_idx_1 = rtu_P3_g - rtu_P1[1];
  P1P3_idx_0 = (P1P3_idx_0 * rty_P[0] + P1P3_idx_1 * rty_P[1]) / (rty_P[0] *
    rty_P[0] + rty_P[1] * rty_P[1]);
  if (P1P3_idx_0 <= 0.0F) {
    rty_P[0] = rtu_P1[0];
    rty_P[1] = rtu_P1[1];
  } else if (P1P3_idx_0 >= 1.0F) {
    rty_P[0] = rtu_P2[0];
    rty_P[1] = rtu_P2[1];
  } else {
    rty_P[0] = P1P3_idx_0 * rty_P[0] + rtu_P1[0];
    rty_P[1] = P1P3_idx_0 * rty_P[1] + rtu_P1[1];
  }
}

/*
 * System initialize for action system:
 *    '<S614>/Hold Control'
 *    '<S392>/Hold Control'
 *    '<S325>/Hold Control'
 *    '<S353>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S618>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S614>/Hold Control'
 *    '<S392>/Hold Control'
 *    '<S325>/Hold Control'
 *    '<S353>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S618>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S614>/Hold Control'
 *    '<S392>/Hold Control'
 *    '<S325>/Hold Control'
 *    '<S353>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S618>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S618>/Sum' incorporates:
   *  Delay: '<S618>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S621>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S621>/Switch' incorporates:
   *  Constant: '<S621>/Constant'
   *  Constant: '<S622>/Constant'
   *  Product: '<S621>/Multiply'
   *  RelationalOperator: '<S622>/Compare'
   *  Sum: '<S621>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S621>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S621>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S621>/Switch' */

  /* Gain: '<S618>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S618>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S614>/Move Control'
 *    '<S392>/Move Control'
 *    '<S325>/Move Control'
 *    '<S353>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S624>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S624>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S614>/Move Control'
 *    '<S392>/Move Control'
 *    '<S325>/Move Control'
 *    '<S353>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S624>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S624>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S614>/Move Control'
 *    '<S392>/Move Control'
 *    '<S325>/Move Control'
 *    '<S353>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_mb;
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_h;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S625>/Multiply1' incorporates:
   *  Constant: '<S625>/const1'
   *  DiscreteIntegrator: '<S624>/Integrator'
   */
  rtb_Add3_mb = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S623>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_h = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_h = 0.0F;
  } else {
    rtb_a_h = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S623>/Dead Zone' */

  /* Sum: '<S625>/Add' incorporates:
   *  DiscreteIntegrator: '<S624>/Integrator1'
   *  Gain: '<S619>/Gain1'
   *  Gain: '<S623>/Gain'
   *  Sum: '<S624>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_h * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_mb;

  /* Signum: '<S625>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_h = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_h = 1.0F;
  } else {
    rtb_a_h = rtb_Subtract3_e;
  }

  /* End of Signum: '<S625>/Sign' */

  /* Sum: '<S625>/Add2' incorporates:
   *  Abs: '<S625>/Abs'
   *  Gain: '<S625>/Gain'
   *  Gain: '<S625>/Gain1'
   *  Product: '<S625>/Multiply2'
   *  Product: '<S625>/Multiply3'
   *  Sqrt: '<S625>/Sqrt'
   *  Sum: '<S625>/Add1'
   *  Sum: '<S625>/Subtract'
   */
  rtb_a_h = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_h + rtb_Add3_mb;

  /* Sum: '<S625>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_e - rtb_a_h) + rtb_Add3_mb;

  /* Sum: '<S625>/Add3' */
  rtb_Add3_mb = rtb_Subtract3_e + localC->d;

  /* Sum: '<S625>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S625>/Sign1' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S625>/Sign1' */

  /* Signum: '<S625>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S625>/Sign2' */

  /* Sum: '<S625>/Add5' incorporates:
   *  Gain: '<S625>/Gain2'
   *  Product: '<S625>/Multiply4'
   *  Sum: '<S625>/Subtract2'
   */
  rtb_a_h += (rtb_Add3_mb - rtb_Subtract3_e) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S624>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S624>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S624>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S624>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S625>/Add6' */
  rtb_Add3_mb = rtb_a_h + localC->d;

  /* Sum: '<S625>/Subtract3' */
  rtb_Subtract3_e = rtb_a_h - localC->d;

  /* Signum: '<S625>/Sign5' */
  if (rtb_a_h < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_h;
  }

  /* End of Signum: '<S625>/Sign5' */

  /* Signum: '<S625>/Sign3' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S625>/Sign3' */

  /* Signum: '<S625>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S625>/Sign4' */

  /* Signum: '<S625>/Sign6' */
  if (rtb_a_h < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_h;
  }

  /* End of Signum: '<S625>/Sign6' */

  /* Update for DiscreteIntegrator: '<S624>/Integrator' incorporates:
   *  Constant: '<S625>/const'
   *  Gain: '<S625>/Gain3'
   *  Product: '<S625>/Divide'
   *  Product: '<S625>/Multiply5'
   *  Product: '<S625>/Multiply6'
   *  Sum: '<S625>/Subtract4'
   *  Sum: '<S625>/Subtract5'
   *  Sum: '<S625>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_h / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_mb - rtb_Subtract3_e) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S393>/Motion State'
 *    '<S326>/Motion State'
 *    '<S354>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S393>/Motion State'
 *    '<S326>/Motion State'
 *    '<S354>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S393>/Motion State'
 *    '<S326>/Motion State'
 *    '<S354>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S393>/Motion State' */
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

  /* End of Chart: '<S393>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S307>/Move Control'
 *    '<S341>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S316>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S316>/Dead Zone' */

  /* Gain: '<S311>/Gain1' incorporates:
   *  Gain: '<S316>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S311>/Switch' incorporates:
   *  Constant: '<S313>/Land_Speed'
   *  Constant: '<S314>/Constant'
   *  Constant: '<S315>/Constant'
   *  Gain: '<S313>/Gain'
   *  Logic: '<S311>/Logical Operator'
   *  MinMax: '<S313>/Min'
   *  RelationalOperator: '<S314>/Compare'
   *  RelationalOperator: '<S315>/Compare'
   *  S-Function (sfix_bitop): '<S311>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S311>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.AcceptRadius' */
void FMS_VehicleAcceptRadius(VTOLState rtu_state, real32_T *rty_radius)
{
  /* Switch: '<S740>/Switch' incorporates:
   *  Constant: '<S740>/FW_ACCEPT_R'
   *  Constant: '<S740>/MC_ACCEPT_R'
   *  Constant: '<S746>/Constant'
   *  RelationalOperator: '<S746>/Compare'
   */
  if (rtu_state == VTOLState_Multicopter) {
    *rty_radius = FMS_PARAM.MC_ACCEPT_R;
  } else {
    *rty_radius = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S740>/Switch' */
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

/* Output and update for function-call system: '<S6>/Vehicle.HeadingErr' */
void FMS_VehicleHeadingErr(real32_T rtu_psi_cmd, real32_T rtu_psi_est, real32_T *
  rty_err)
{
  real32_T rtb_Rem_h;
  real32_T rtb_Rem_h_0;

  /* Math: '<S757>/Rem' incorporates:
   *  Constant: '<S757>/Constant1'
   *  Sum: '<S742>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S757>/Switch' incorporates:
   *  Abs: '<S757>/Abs'
   *  Constant: '<S757>/Constant'
   *  Constant: '<S758>/Constant'
   *  Product: '<S757>/Multiply'
   *  RelationalOperator: '<S758>/Compare'
   *  Sum: '<S757>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S757>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S757>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S757>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.WaypointAngle' */
void FMS_VehicleWaypointAngle(const real32_T rtu_start[3], const real32_T
  rtu_end[3], real32_T *rty_angle, const ConstB_VehicleWaypointAngle_F_T *localC)
{
  real32_T rtb_Switch2_b;
  real32_T rtb_Divide_cw_idx_1;
  real32_T rtb_Divide_cw_idx_0;
  real32_T rtb_Switch_a_idx_1;

  /* Sum: '<S745>/Sum' */
  rtb_Divide_cw_idx_0 = rtu_end[0] - rtu_start[0];
  rtb_Divide_cw_idx_1 = rtu_end[1] - rtu_start[1];

  /* Sum: '<S763>/Sum of Elements' incorporates:
   *  Math: '<S763>/Math Function'
   *  SignalConversion: '<S763>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S763>/Math Function1' incorporates:
   *  Sum: '<S763>/Sum of Elements'
   *
   * About '<S763>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S763>/Math Function1' */

  /* Switch: '<S763>/Switch' incorporates:
   *  Constant: '<S763>/Constant'
   *  Product: '<S763>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S763>/Switch' */

  /* Product: '<S763>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a_idx_1 / rtb_Switch2_b;

  /* Sum: '<S761>/Subtract' incorporates:
   *  Product: '<S761>/Multiply'
   *  Product: '<S761>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S760>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S760>/Sign1' */

  /* Switch: '<S760>/Switch2' incorporates:
   *  Constant: '<S760>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S760>/Switch2' */

  /* DotProduct: '<S760>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S760>/Acos' incorporates:
   *  DotProduct: '<S760>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S760>/Multiply' incorporates:
   *  Trigonometry: '<S760>/Acos'
   */
  rtb_Divide_cw_idx_0 = acosf(rtb_Divide_cw_idx_0) * rtb_Switch2_b;

  /* Switch: '<S745>/Switch' incorporates:
   *  Bias: '<S745>/Bias'
   */
  if (rtb_Divide_cw_idx_0 >= 0.0F) {
    *rty_angle = rtb_Divide_cw_idx_0;
  } else {
    *rty_angle = rtb_Divide_cw_idx_0 + 6.28318548F;
  }

  /* End of Switch: '<S745>/Switch' */
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
  real_T rtb_Sum2_m;
  real_T rtb_Gain_lq;
  real_T rtb_Sum3_l;
  real_T rtb_Sum_n1;
  int32_T rtb_Compare_dy_0;
  real_T rtb_Sum_e_idx_0;

  /* Gain: '<S747>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S748>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S748>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S748>/Multiply1' incorporates:
   *  Product: '<S748>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S748>/Divide' incorporates:
   *  Constant: '<S748>/Constant'
   *  Constant: '<S748>/R'
   *  Sqrt: '<S748>/Sqrt'
   *  Sum: '<S748>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S748>/Product3' incorporates:
   *  Constant: '<S748>/Constant1'
   *  Product: '<S748>/Multiply1'
   *  Sum: '<S748>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S748>/Multiply2' incorporates:
   *  Trigonometry: '<S748>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S747>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S752>/Abs' incorporates:
   *  Abs: '<S755>/Abs1'
   *  Switch: '<S752>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S752>/Switch1' incorporates:
   *  Abs: '<S752>/Abs'
   *  Bias: '<S752>/Bias2'
   *  Bias: '<S752>/Bias3'
   *  Constant: '<S749>/Constant'
   *  Constant: '<S749>/Constant1'
   *  Constant: '<S754>/Constant'
   *  Gain: '<S752>/Gain1'
   *  Product: '<S752>/Multiply'
   *  RelationalOperator: '<S754>/Compare'
   *  Switch: '<S749>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S755>/Switch1' incorporates:
     *  Bias: '<S755>/Bias2'
     *  Bias: '<S755>/Bias3'
     *  Constant: '<S755>/Constant'
     *  Constant: '<S756>/Constant'
     *  Math: '<S755>/Math Function'
     *  RelationalOperator: '<S756>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S755>/Switch1' */

    /* Signum: '<S752>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S752>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S749>/Sum' incorporates:
   *  Sum: '<S747>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S747>/Multiply' incorporates:
   *  Gain: '<S747>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S751>/Switch1' incorporates:
   *  Abs: '<S751>/Abs1'
   *  Bias: '<S751>/Bias2'
   *  Bias: '<S751>/Bias3'
   *  Constant: '<S751>/Constant'
   *  Constant: '<S753>/Constant'
   *  Math: '<S751>/Math Function'
   *  RelationalOperator: '<S753>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S751>/Switch1' */

  /* Product: '<S747>/Multiply' incorporates:
   *  Gain: '<S747>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S747>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S750>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S750>/Sum2' incorporates:
   *  Product: '<S750>/Multiply1'
   *  Product: '<S750>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S750>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S750>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S750>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S741>/Data Type Conversion' incorporates:
   *  Gain: '<S747>/Gain'
   *  Sum: '<S747>/Sum1'
   */
  rty_pos[0] = (real32_T)rtb_Sum2_m;
  rty_pos[1] = (real32_T)rtb_Sum3_l;
  rty_pos[2] = (real32_T)-(rtu_lla[2] + rtu_href);
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Stabilize(void)
{
  /* Inport: '<Root>/INS_Out' */
  if ((FMS_U.INS_Out.flag & 4U) != 0U) {
    FMS_B.target_mode = PilotMode_Stabilize;

    /* Delay: '<S25>/Delay' */
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

    /* End of Delay: '<S25>/Delay' */
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

    /* Delay: '<S25>/Delay' */
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

    /* End of Delay: '<S25>/Delay' */
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

    /* Delay: '<S25>/Delay' */
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

    /* End of Delay: '<S25>/Delay' */
  } else {
    FMS_DW.is_c3_FMS = FMS_IN_Stabilize_j;
  }

  /* End of Inport: '<Root>/INS_Out' */
}

/* Function for Chart: '<Root>/SafeMode' */
static void FMS_Manual(void)
{
  FMS_B.target_mode = PilotMode_Manual;

  /* Delay: '<S25>/Delay' */
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

  /* End of Delay: '<S25>/Delay' */
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
  FMS_emplace(&FMS_DW.Queue_FMS_Cmd_d, &FMS_DW.M_msgReservedData);
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
static void FMS_Command_Listener(void)
{
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
    if ((FMS_DW.cmd_prev != FMS_DW.cmd_start) && (FMS_B.Switch1 != FMS_Cmd_None))
    {
      FMS_DW.save_cmd = FMS_B.Switch1;
      FMS_DW.is_Command_Listener = FMS_IN_Check;
      FMS_DW.valid_cmd = FMS_CheckCmdValid(FMS_DW.save_cmd, FMS_B.target_mode,
        FMS_B.BusConversion_InsertedFor_FMSSt.flag);
    }
    break;

   case FMS_IN_Send:
    FMS_DW.is_Command_Listener = FMS_IN_Listen;
    break;
  }
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_d, &FMS_DW.Msg_FMS_Cmd_i
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

int32_T FMS_emplace_n(Queue_VTOLMode *q, const VTOLMode *dataIn)
{
  int32_T isEmplaced;
  int32_T newTail;
  Msg_VTOLMode *msg;
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
static void FMS_sf_msg_send_VTOL_M(void)
{
  FMS_emplace_n(&FMS_DW.Queue_VTOLMode_a, &FMS_DW.VTOL_M_msgReservedData);
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_enter_internal_Hold(void)
{
  if (FMS_B.vtol_state == VTOLState_Multicopter) {
    FMS_DW.is_Hold = FMS_IN_Loiter;
    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
    FMS_B.Cmd_In.set_yaw = -1.0F;
    FMS_B.state = VehicleState_Hold;
  } else {
    FMS_DW.is_Hold = FMS_IN_BackTrans;
    if ((FMS_B.state == VehicleState_Mission) && ((FMS_B.vtol_state ==
          VTOLState_Fixwing) || (FMS_B.vtol_state == VTOLState_ForwardTrans))) {
      FMS_DW.need_forwardtrans = 1.0;
    }

    FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
    FMS_sf_msg_send_VTOL_M();
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_enter_internal_VTOL_Land(void)
{
  int32_T tmp;
  int32_T lla_tmp;
  lla_tmp = NAV_Cmd_Land;
  tmp = NAV_Cmd_VTOL_Land;
  if ((FMS_DW.nav_cmd == lla_tmp) || (FMS_DW.nav_cmd == tmp)) {
    FMS_DW.is_VTOL_Land_m = FMS_IN_Waypoint_cj;
    FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
    FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
    FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];

    /* Inport: '<Root>/Mission_Data' */
    FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] * 1.0E-7;
    FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] * 1.0E-7;
    FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] + FMS_DW.home[2]);
    FMS_B.llo[0] = FMS_DW.llo[0];
    FMS_B.llo[1] = FMS_DW.llo[1];
    FMS_B.href = 0.0;
    FMS_B.psio = 0.0;

    /* Outputs for Function Call SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
    F_VehicleArmAutoMissionLLA2FLAT(FMS_B.lla, FMS_B.llo, FMS_B.href, FMS_B.psio,
      FMS_B.DataTypeConversion, &FMS_ConstB.VehicleArmAutoMissionLLA2FLAT);

    /* End of Outputs for SubSystem: '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
    if ((FMS_DW.need_forwardtrans != 0.0) && (FMS_B.vtol_state ==
         VTOLState_Multicopter)) {
      FMS_DW.is_Waypoint_o = FMS_IN_Align;
      FMS_B.start[0] = FMS_B.Cmd_In.cur_waypoint[0];
      FMS_B.end[0] = FMS_B.Cmd_In.sp_waypoint[0];
      FMS_B.start[1] = FMS_B.Cmd_In.cur_waypoint[1];
      FMS_B.end[1] = FMS_B.Cmd_In.sp_waypoint[1];
      FMS_B.start[2] = FMS_B.Cmd_In.cur_waypoint[2];
      FMS_B.end[2] = FMS_B.Cmd_In.sp_waypoint[2];

      /* Outputs for Function Call SubSystem: '<S6>/Vehicle.WaypointAngle' */
      FMS_VehicleWaypointAngle(FMS_B.start, FMS_B.end, &FMS_B.Switch,
        &FMS_ConstB.VehicleWaypointAngle);

      /* End of Outputs for SubSystem: '<S6>/Vehicle.WaypointAngle' */
      FMS_B.Cmd_In.set_yaw = FMS_B.Switch;
      FMS_B.state = VehicleState_Hold;
    } else {
      FMS_DW.is_Waypoint_o = FMS_IN_Execute;
      if (FMS_DW.need_forwardtrans != 0.0) {
        FMS_DW.need_forwardtrans = 0.0;
      }

      FMS_B.state = VehicleState_Mission;
    }
  } else if (FMS_B.vtol_state == VTOLState_Multicopter) {
    FMS_DW.condWasTrueAtLastTimeStep_1 = false;
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_VTOL_Land_m = FMS_IN_Land;
    if ((FMS_DW.nav_cmd == lla_tmp) || (FMS_DW.nav_cmd == tmp)) {
      lla_tmp = FMS_B.wp_index - 1;

      /* Inport: '<Root>/Mission_Data' */
      FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[lla_tmp] * 1.0E-7;
      FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[lla_tmp] * 1.0E-7;
      FMS_B.lla[2] = 0.0;
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
    } else {
      FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
      FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
      FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
    }

    FMS_B.state = VehicleState_Land;

    /* Constant: '<Root>/Constant' */
    FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  } else {
    FMS_DW.is_VTOL_Land_m = FMS_IN_BackTrans;
    FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
    FMS_sf_msg_send_VTOL_M();
  }
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
static void FMS_VTOL_Land(void)
{
  real32_T tmp[2];
  uint32_T qY;
  int32_T lla_tmp;
  switch (FMS_DW.is_VTOL_Land_m) {
   case FMS_IN_BackTrans:
    if (FMS_B.vtol_state == VTOLState_Multicopter) {
      FMS_DW.is_VTOL_Land_m = FMS_IN_Return;
      FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      if ((FMS_DW.nav_cmd == (int32_T)NAV_Cmd_VTOL_Land) || (FMS_DW.nav_cmd ==
           (int32_T)NAV_Cmd_Land)) {
        lla_tmp = FMS_B.wp_index - 1;

        /* Inport: '<Root>/Mission_Data' */
        FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[lla_tmp] * 1.0E-7;
        FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[lla_tmp] * 1.0E-7;
        FMS_B.lla[2] = 0.0;
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
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      } else {
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
      }

      FMS_B.state = VehicleState_Return;
    }
    break;

   case FMS_IN_Land:
    FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;

    /* Constant: '<Root>/Constant' */
    FMS_DW.condWasTrueAtLastTimeStep_1 = false;
    if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1 >=
        500) {
      lla_tmp = (int32_T)(FMS_B.wp_index + 1U);
      if ((uint32_T)lla_tmp > 255U) {
        lla_tmp = 255;
      }

      FMS_B.wp_index = (uint8_T)lla_tmp;
      FMS_DW.is_VTOL_Land_m = FMS_IN_NO_ACTIVE_CHILD_o;
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

   case FMS_IN_Return:
    FMS_B.state_g = FMS_B.vtol_state;

    /* Outputs for Function Call SubSystem: '<S6>/Vehicle.AcceptRadius' */
    FMS_VehicleAcceptRadius(FMS_B.state_g, &FMS_B.Switch_b);

    /* End of Outputs for SubSystem: '<S6>/Vehicle.AcceptRadius' */
    tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
      FMS_B.Cmd_In.sp_waypoint[0];
    tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
      FMS_B.Cmd_In.sp_waypoint[1];
    if (FMS_norm(tmp) <= FMS_B.Switch_b) {
      FMS_DW.condWasTrueAtLastTimeStep_1 = false;
      FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_VTOL_Land_m = FMS_IN_Land;
      if ((FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Land) || (FMS_DW.nav_cmd ==
           (int32_T)NAV_Cmd_VTOL_Land)) {
        /* Inport: '<Root>/Mission_Data' */
        FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] * 1.0E-7;
        FMS_B.lla[2] = 0.0;
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
      } else {
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
        FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
      }

      FMS_B.state = VehicleState_Land;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1 = false;
    }
    break;

   case FMS_IN_Waypoint_cj:
    switch (FMS_DW.is_Waypoint_o) {
     case FMS_IN_Align:
      FMS_B.psi_cmd = FMS_B.Cmd_In.set_yaw;
      FMS_B.psi_est = FMS_B.BusConversion_InsertedFor_FMSSt.psi;

      /* Outputs for Function Call SubSystem: '<S6>/Vehicle.HeadingErr' */
      FMS_VehicleHeadingErr(FMS_B.psi_cmd, FMS_B.psi_est, &FMS_B.Switch_h);

      /* End of Outputs for SubSystem: '<S6>/Vehicle.HeadingErr' */
      if (fabsf(FMS_B.Switch_h) <= 0.087266462599716474) {
        FMS_DW.is_Waypoint_o = FMS_IN_Wait;
        FMS_DW.temporalCounter_i1 = 0U;
      }
      break;

     case FMS_IN_Execute:
      FMS_B.state_g = FMS_B.vtol_state;

      /* Outputs for Function Call SubSystem: '<S6>/Vehicle.AcceptRadius' */
      FMS_VehicleAcceptRadius(FMS_B.state_g, &FMS_B.Switch_b);

      /* End of Outputs for SubSystem: '<S6>/Vehicle.AcceptRadius' */
      tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
        FMS_B.Cmd_In.sp_waypoint[0];
      tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
        FMS_B.Cmd_In.sp_waypoint[1];
      if (FMS_norm(tmp) <= FMS_B.Switch_b) {
        if (FMS_B.vtol_state == VTOLState_Multicopter) {
          FMS_DW.is_Waypoint_o = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.condWasTrueAtLastTimeStep_1 = false;
          FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_VTOL_Land_m = FMS_IN_Land;
          if ((FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Land) || (FMS_DW.nav_cmd ==
               (int32_T)NAV_Cmd_VTOL_Land)) {
            /* Inport: '<Root>/Mission_Data' */
            FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] *
              1.0E-7;
            FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] *
              1.0E-7;
            FMS_B.lla[2] = 0.0;
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
          } else {
            FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
            FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
            FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
          }

          FMS_B.state = VehicleState_Land;

          /* Constant: '<Root>/Constant' */
          FMS_DW.condWasTrueAtLastTimeStep_1 = false;
        } else {
          FMS_DW.is_Waypoint_o = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_VTOL_Land_m = FMS_IN_BackTrans;
          FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
          FMS_sf_msg_send_VTOL_M();
        }
      }
      break;

     case FMS_IN_ForwardTrans:
      if ((FMS_B.vtol_state == VTOLState_ForwardTrans) || (FMS_B.vtol_state ==
           VTOLState_Fixwing)) {
        FMS_DW.is_Waypoint_o = FMS_IN_Execute;
        if (FMS_DW.need_forwardtrans != 0.0) {
          FMS_DW.need_forwardtrans = 0.0;
        }

        FMS_B.state = VehicleState_Mission;
      }
      break;

     case FMS_IN_Wait:
      if (FMS_DW.temporalCounter_i1 >= 500U) {
        FMS_DW.is_Waypoint_o = FMS_IN_ForwardTrans;
        FMS_DW.VTOL_M_msgReservedData = VTOLMode_Fixwing;
        FMS_sf_msg_send_VTOL_M();
      }
      break;
    }
    break;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Waypoint(void)
{
  real32_T tmp[2];
  uint32_T qY;
  int32_T tmp_0;
  switch (FMS_DW.is_Waypoint) {
   case FMS_IN_Align:
    FMS_B.psi_cmd = FMS_B.Cmd_In.set_yaw;
    FMS_B.psi_est = FMS_B.BusConversion_InsertedFor_FMSSt.psi;

    /* Outputs for Function Call SubSystem: '<S6>/Vehicle.HeadingErr' */
    FMS_VehicleHeadingErr(FMS_B.psi_cmd, FMS_B.psi_est, &FMS_B.Switch_h);

    /* End of Outputs for SubSystem: '<S6>/Vehicle.HeadingErr' */
    if (fabsf(FMS_B.Switch_h) <= 0.087266462599716474) {
      FMS_DW.is_Waypoint = FMS_IN_Wait_k;
      FMS_DW.temporalCounter_i1 = 0U;
    }
    break;

   case FMS_IN_Execute:
    FMS_B.state_g = FMS_B.vtol_state;

    /* Outputs for Function Call SubSystem: '<S6>/Vehicle.AcceptRadius' */
    FMS_VehicleAcceptRadius(FMS_B.state_g, &FMS_B.Switch_b);

    /* End of Outputs for SubSystem: '<S6>/Vehicle.AcceptRadius' */
    tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
      FMS_B.Cmd_In.sp_waypoint[0];
    tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
      FMS_B.Cmd_In.sp_waypoint[1];
    if (FMS_norm(tmp) <= FMS_B.Switch_b) {
      /* Inport: '<Root>/Mission_Data' */
      if (FMS_U.Mission_Data.param1[FMS_B.wp_index - 1] > 0.0F) {
        FMS_DW.is_Waypoint = FMS_IN_Hold_hs;
        FMS_DW.temporalCounter_i1 = 0U;
        FMS_B.Cmd_In.set_yaw = -1.0F;
        FMS_B.state = VehicleState_Hold;
      } else {
        tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
        if ((uint32_T)tmp_0 > 255U) {
          tmp_0 = 255;
        }

        FMS_B.wp_index = (uint8_T)tmp_0;
        FMS_DW.is_Waypoint = FMS_IN_NO_ACTIVE_CHILD_o;
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
    break;

   case FMS_IN_ForwardTrans:
    if ((FMS_B.vtol_state == VTOLState_ForwardTrans) || (FMS_B.vtol_state ==
         VTOLState_Fixwing)) {
      FMS_DW.is_Waypoint = FMS_IN_Execute;
      if (FMS_DW.need_forwardtrans != 0.0) {
        FMS_DW.need_forwardtrans = 0.0;
      }

      FMS_B.state = VehicleState_Mission;
    }
    break;

   case FMS_IN_Hold_hs:
    /* Inport: '<Root>/Mission_Data' */
    if (FMS_DW.temporalCounter_i1 >= FMS_U.Mission_Data.param1[FMS_B.wp_index -
        1] * 250.0F) {
      tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
      if ((uint32_T)tmp_0 > 255U) {
        tmp_0 = 255;
      }

      FMS_B.wp_index = (uint8_T)tmp_0;
      FMS_DW.is_Waypoint = FMS_IN_NO_ACTIVE_CHILD_o;
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

   case FMS_IN_Wait_k:
    if (FMS_DW.temporalCounter_i1 >= 500U) {
      FMS_DW.is_Waypoint = FMS_IN_ForwardTrans;
      FMS_DW.VTOL_M_msgReservedData = VTOLMode_Fixwing;
      FMS_sf_msg_send_VTOL_M();
    }
    break;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_Mission(void)
{
  FMS_DW.is_Return_n = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Takeoff = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Waypoint_o = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_VTOL_Land_m = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Waypoint = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_o;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Mission(void)
{
  real32_T tmp[2];
  uint32_T qY;
  int32_T tmp_0;
  boolean_T guard1 = false;
  if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start) {
    FMS_B.Cmd_In.set_speed = 0.0F;
    FMS_exit_internal_Mission();
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
    guard1 = false;
    switch (FMS_DW.is_Mission) {
     case FMS_IN_Disarming:
      FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Vehicle = FMS_IN_Disarm;
      FMS_B.state = VehicleState_Disarm;
      break;

     case FMS_IN_Loiter:
      break;

     case FMS_IN_NextWP:
      if ((FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Takeoff) && (FMS_B.vtol_state ==
           VTOLState_Multicopter)) {
        guard1 = true;
      } else if ((FMS_DW.nav_cmd == (int32_T)NAV_Cmd_VTOL_Takeoff) &&
                 (FMS_B.vtol_state == VTOLState_Multicopter)) {
        FMS_DW.need_forwardtrans = 1.0;
        guard1 = true;
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
        if ((FMS_DW.need_forwardtrans != 0.0) && (FMS_B.vtol_state ==
             VTOLState_Multicopter)) {
          FMS_DW.is_Waypoint = FMS_IN_Align;
          FMS_B.start[0] = FMS_B.Cmd_In.cur_waypoint[0];
          FMS_B.end[0] = FMS_B.Cmd_In.sp_waypoint[0];
          FMS_B.start[1] = FMS_B.Cmd_In.cur_waypoint[1];
          FMS_B.end[1] = FMS_B.Cmd_In.sp_waypoint[1];
          FMS_B.start[2] = FMS_B.Cmd_In.cur_waypoint[2];
          FMS_B.end[2] = FMS_B.Cmd_In.sp_waypoint[2];

          /* Outputs for Function Call SubSystem: '<S6>/Vehicle.WaypointAngle' */
          FMS_VehicleWaypointAngle(FMS_B.start, FMS_B.end, &FMS_B.Switch,
            &FMS_ConstB.VehicleWaypointAngle);

          /* End of Outputs for SubSystem: '<S6>/Vehicle.WaypointAngle' */
          FMS_B.Cmd_In.set_yaw = FMS_B.Switch;
          FMS_B.state = VehicleState_Hold;
        } else {
          FMS_DW.is_Waypoint = FMS_IN_Execute;
          if (FMS_DW.need_forwardtrans != 0.0) {
            FMS_DW.need_forwardtrans = 0.0;
          }

          FMS_B.state = VehicleState_Mission;
        }
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_VTOL_Transition) {
        FMS_DW.is_Mission = FMS_IN_Transition;

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_U.Mission_Data.param1[FMS_B.wp_index - 1] == 3.0F) {
          FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
          FMS_sf_msg_send_VTOL_M();
        } else {
          if (FMS_U.Mission_Data.param1[FMS_B.wp_index - 1] == 4.0F) {
            FMS_DW.need_forwardtrans = 1.0;
          }
        }
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_SetSpeed) {
        /* Inport: '<Root>/Mission_Data' */
        FMS_B.Cmd_In.set_speed = FMS_U.Mission_Data.param2[FMS_B.wp_index - 1];
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
      } else if ((FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Land) || (FMS_DW.nav_cmd ==
                  (int32_T)NAV_Cmd_VTOL_Land)) {
        FMS_DW.is_Mission = FMS_IN_VTOL_Land_c;
        FMS_enter_internal_VTOL_Land();
      } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Return) {
        FMS_DW.is_Mission = FMS_IN_Return_gw;
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        if ((FMS_DW.need_forwardtrans != 0.0) && (FMS_B.vtol_state ==
             VTOLState_Multicopter)) {
          FMS_DW.is_Return_n = FMS_IN_Align;
          FMS_B.start[0] = FMS_B.Cmd_In.cur_waypoint[0];
          FMS_B.end[0] = FMS_B.Cmd_In.sp_waypoint[0];
          FMS_B.start[1] = FMS_B.Cmd_In.cur_waypoint[1];
          FMS_B.end[1] = FMS_B.Cmd_In.sp_waypoint[1];
          FMS_B.start[2] = FMS_B.Cmd_In.cur_waypoint[2];
          FMS_B.end[2] = FMS_B.Cmd_In.sp_waypoint[2];

          /* Outputs for Function Call SubSystem: '<S6>/Vehicle.WaypointAngle' */
          FMS_VehicleWaypointAngle(FMS_B.start, FMS_B.end, &FMS_B.Switch,
            &FMS_ConstB.VehicleWaypointAngle);

          /* End of Outputs for SubSystem: '<S6>/Vehicle.WaypointAngle' */
          FMS_B.Cmd_In.set_yaw = FMS_B.Switch;
          FMS_B.state = VehicleState_Hold;
        } else {
          FMS_DW.is_Return_n = FMS_IN_Execute;
          if (FMS_DW.need_forwardtrans != 0.0) {
            FMS_DW.need_forwardtrans = 0.0;
          }

          FMS_B.state = VehicleState_Return;
        }
      } else {
        FMS_DW.is_Mission = FMS_IN_Loiter;
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.Cmd_In.set_yaw = -1.0F;
        FMS_B.state = VehicleState_Hold;
      }
      break;

     case FMS_IN_Return_gw:
      switch (FMS_DW.is_Return_n) {
       case FMS_IN_Align:
        FMS_B.psi_cmd = FMS_B.Cmd_In.set_yaw;
        FMS_B.psi_est = FMS_B.BusConversion_InsertedFor_FMSSt.psi;

        /* Outputs for Function Call SubSystem: '<S6>/Vehicle.HeadingErr' */
        FMS_VehicleHeadingErr(FMS_B.psi_cmd, FMS_B.psi_est, &FMS_B.Switch_h);

        /* End of Outputs for SubSystem: '<S6>/Vehicle.HeadingErr' */
        if (fabsf(FMS_B.Switch_h) <= 0.087266462599716474) {
          FMS_DW.is_Return_n = FMS_IN_Wait;
          FMS_DW.temporalCounter_i1 = 0U;
        }
        break;

       case FMS_IN_Execute:
        FMS_B.state_g = FMS_B.vtol_state;

        /* Outputs for Function Call SubSystem: '<S6>/Vehicle.AcceptRadius' */
        FMS_VehicleAcceptRadius(FMS_B.state_g, &FMS_B.Switch_b);

        /* End of Outputs for SubSystem: '<S6>/Vehicle.AcceptRadius' */
        tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
          FMS_B.Cmd_In.sp_waypoint[0];
        tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
          FMS_B.Cmd_In.sp_waypoint[1];
        if (FMS_norm(tmp) <= FMS_B.Switch_b) {
          FMS_DW.is_Return_n = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Mission = FMS_IN_VTOL_Land_c;
          FMS_enter_internal_VTOL_Land();
        }
        break;

       case FMS_IN_ForwardTrans:
        if ((FMS_B.vtol_state == VTOLState_ForwardTrans) || (FMS_B.vtol_state ==
             VTOLState_Fixwing)) {
          FMS_DW.is_Return_n = FMS_IN_Execute;
          if (FMS_DW.need_forwardtrans != 0.0) {
            FMS_DW.need_forwardtrans = 0.0;
          }

          FMS_B.state = VehicleState_Return;
        }
        break;

       case FMS_IN_Wait:
        if (FMS_DW.temporalCounter_i1 >= 500U) {
          FMS_DW.is_Return_n = FMS_IN_ForwardTrans;
          FMS_DW.VTOL_M_msgReservedData = VTOLMode_Fixwing;
          FMS_sf_msg_send_VTOL_M();
        }
        break;
      }
      break;

     case FMS_IN_Takeoff_k:
      switch (FMS_DW.is_Takeoff) {
       case FMS_IN_Takeoff_k2:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_waypoint[2]) {
          FMS_B.state_g = FMS_B.vtol_state;

          /* Outputs for Function Call SubSystem: '<S6>/Vehicle.AcceptRadius' */
          FMS_VehicleAcceptRadius(FMS_B.state_g, &FMS_B.Switch_b);

          /* End of Outputs for SubSystem: '<S6>/Vehicle.AcceptRadius' */
          tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
            FMS_B.Cmd_In.sp_waypoint[0];
          tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
            FMS_B.Cmd_In.sp_waypoint[1];
          if (FMS_norm(tmp) > FMS_B.Switch_b) {
            FMS_DW.is_Takeoff = FMS_IN_Waypoint_c;
            FMS_B.Cmd_In.cur_waypoint[0] =
              FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.cur_waypoint[1] =
              FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_B.Cmd_In.cur_waypoint[2] =
              FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
            FMS_B.state = VehicleState_Mission;
          } else {
            tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
            if ((uint32_T)tmp_0 > 255U) {
              tmp_0 = 255;
            }

            FMS_B.wp_index = (uint8_T)tmp_0;
            FMS_DW.is_Takeoff = FMS_IN_NO_ACTIVE_CHILD_o;
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
        }
        break;

       case FMS_IN_Waypoint_c:
        FMS_B.state_g = FMS_B.vtol_state;

        /* Outputs for Function Call SubSystem: '<S6>/Vehicle.AcceptRadius' */
        FMS_VehicleAcceptRadius(FMS_B.state_g, &FMS_B.Switch_b);

        /* End of Outputs for SubSystem: '<S6>/Vehicle.AcceptRadius' */
        tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
          FMS_B.Cmd_In.sp_waypoint[0];
        tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
          FMS_B.Cmd_In.sp_waypoint[1];
        if (FMS_norm(tmp) <= FMS_B.Switch_b) {
          tmp_0 = (int32_T)(FMS_B.wp_index + 1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          FMS_B.wp_index = (uint8_T)tmp_0;
          FMS_DW.is_Takeoff = FMS_IN_NO_ACTIVE_CHILD_o;
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
      break;

     case FMS_IN_Transition:
      /* Inport: '<Root>/Mission_Data' */
      if (FMS_U.Mission_Data.param1[FMS_B.wp_index - 1] == 3.0F) {
        FMS_DW.is_Mission = FMS_IN_WaitBackTransCplt;
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
      break;

     case FMS_IN_VTOL_Land_c:
      FMS_VTOL_Land();
      break;

     case FMS_IN_WaitBackTransCplt:
      if (FMS_B.vtol_state == VTOLState_Multicopter) {
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
      FMS_Waypoint();
      break;
    }

    if (guard1) {
      FMS_DW.is_Mission = FMS_IN_Takeoff_k;
      FMS_DW.is_Takeoff = FMS_IN_Takeoff_k2;

      /* Inport: '<Root>/Mission_Data' */
      FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index - 1] * 1.0E-7;
      FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index - 1] * 1.0E-7;
      FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] + FMS_DW.home[2]);
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
    if (FMS_B.LogicalOperator) {
      FMS_DW.is_Offboard = FMS_IN_Run;
      FMS_B.state = VehicleState_Offboard;
    } else {
      FMS_DW.is_Offboard = FMS_IN_Loiter_p;
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
      FMS_DW.is_Manual = FMS_IN_Manual_o;
      FMS_B.state = VehicleState_Manual;
    } else {
      FMS_DW.is_Manual = FMS_IN_InValidManualMode;
    }
  } else {
    FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_exit_internal_SubMode(void)
{
  FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
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

  /* Outputs for Function Call SubSystem: '<S6>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S759>/Compare' incorporates:
   *  Abs: '<S744>/Abs'
   *  Constant: '<S759>/Constant'
   *  MinMax: '<S744>/Max'
   *  Sum: '<S744>/Sum'
   */
  FMS_B.Compare_k = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S6>/Vehicle.StickMoved' */
  tmp_0 = FMS_getArmMode(FMS_B.target_mode);
  if ((FMS_B.Compare_k || ((FMS_B.BusConversion_InsertedFor_FMSSt.flag & 212U)
        != 212U)) && ((tmp_0 == 1.0) || (tmp_0 == 2.0))) {
    if (tmp_0 == 3.0) {
      FMS_exit_internal_SubMode();
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (tmp_0 == 2.0) {
      FMS_exit_internal_SubMode();
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (tmp_0 == 1.0) {
      FMS_exit_internal_SubMode();
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_o;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_exit_internal_SubMode();
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Pause);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_exit_internal_SubMode();
      FMS_DW.is_SubMode = FMS_IN_Hold_h;
      FMS_enter_internal_Hold();
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
          FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_enter_internal_Arm();
        } else {
          if ((FMS_DW.is_Hold == FMS_IN_BackTrans) && (FMS_B.vtol_state ==
               VTOLState_Multicopter)) {
            FMS_DW.is_Hold = FMS_IN_Loiter;
            FMS_B.Cmd_In.sp_waypoint[0] =
              FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
            FMS_B.Cmd_In.sp_waypoint[1] =
              FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
            FMS_B.Cmd_In.sp_waypoint[2] =
              FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
            FMS_B.Cmd_In.set_yaw = -1.0F;
            FMS_B.state = VehicleState_Hold;
          }
        }
        break;

       case FMS_IN_Land:
        FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1_f = false;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_d >= 500) {
          FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
        } else {
          if (FMS_DW.is_Land == FMS_IN_VTOL_Land) {
            switch (FMS_DW.is_VTOL_Land) {
             case FMS_IN_BackTrans:
              if (FMS_B.vtol_state == VTOLState_Multicopter) {
                FMS_DW.is_VTOL_Land = FMS_IN_Return_g;
                FMS_B.Cmd_In.cur_waypoint[0] =
                  FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
                FMS_B.Cmd_In.cur_waypoint[1] =
                  FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
                FMS_B.Cmd_In.cur_waypoint[2] =
                  FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
                FMS_B.Cmd_In.sp_waypoint[2] =
                  FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
                FMS_B.state = VehicleState_Return;
              }
              break;

             case FMS_IN_Return_g:
              FMS_B.state_g = FMS_B.vtol_state;

              /* Outputs for Function Call SubSystem: '<S6>/Vehicle.AcceptRadius' */
              FMS_VehicleAcceptRadius(FMS_B.state_g, &FMS_B.Switch_b);

              /* End of Outputs for SubSystem: '<S6>/Vehicle.AcceptRadius' */
              tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                FMS_B.Cmd_In.sp_waypoint[0];
              tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                FMS_B.Cmd_In.sp_waypoint[1];
              if (FMS_norm(tmp) <= FMS_B.Switch_b) {
                FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_o;
                FMS_DW.is_Land = FMS_IN_MC_Land;
                FMS_B.state = VehicleState_Land;
              }
              break;
            }
          }
        }
        break;

       case FMS_IN_Return:
        switch (FMS_DW.is_Return) {
         case FMS_IN_Align:
          FMS_B.psi_cmd = FMS_B.Cmd_In.set_yaw;
          FMS_B.psi_est = FMS_B.BusConversion_InsertedFor_FMSSt.psi;

          /* Outputs for Function Call SubSystem: '<S6>/Vehicle.HeadingErr' */
          FMS_VehicleHeadingErr(FMS_B.psi_cmd, FMS_B.psi_est, &FMS_B.Switch_h);

          /* End of Outputs for SubSystem: '<S6>/Vehicle.HeadingErr' */
          if (fabsf(FMS_B.Switch_h) <= 0.087266462599716474) {
            FMS_DW.is_Return = FMS_IN_Wait;
            FMS_DW.temporalCounter_i1 = 0U;
          }
          break;

         case FMS_IN_Execute:
          FMS_B.state_g = FMS_B.vtol_state;

          /* Outputs for Function Call SubSystem: '<S6>/Vehicle.AcceptRadius' */
          FMS_VehicleAcceptRadius(FMS_B.state_g, &FMS_B.Switch_b);

          /* End of Outputs for SubSystem: '<S6>/Vehicle.AcceptRadius' */
          tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
            FMS_B.Cmd_In.sp_waypoint[0];
          tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
            FMS_B.Cmd_In.sp_waypoint[1];
          if (FMS_norm(tmp) <= FMS_B.Switch_b) {
            FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
            FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
            FMS_B.Cmd_In.sp_waypoint[2] = 0.0F;
            FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_DW.durationLastReferenceTick_1_d =
              FMS_DW.chartAbsoluteTimeCounter;
            FMS_DW.is_SubMode = FMS_IN_Land;
            FMS_B.state = VehicleState_Land;

            /* Constant: '<Root>/Constant' */
            FMS_DW.condWasTrueAtLastTimeStep_1_f = false;
            if (FMS_B.vtol_state == VTOLState_Multicopter) {
              FMS_DW.is_Land = FMS_IN_MC_Land;
              FMS_B.state = VehicleState_Land;
            } else {
              FMS_DW.is_Land = FMS_IN_VTOL_Land;
              FMS_DW.is_VTOL_Land = FMS_IN_BackTrans;
              FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
              FMS_sf_msg_send_VTOL_M();
            }
          }
          break;

         case FMS_IN_ForwardTrans:
          if ((FMS_B.vtol_state == VTOLState_ForwardTrans) || (FMS_B.vtol_state ==
               VTOLState_Fixwing)) {
            FMS_DW.is_Return = FMS_IN_Execute;
            FMS_B.state = VehicleState_Return;
          }
          break;

         case FMS_IN_Wait:
          if (FMS_DW.temporalCounter_i1 >= 750U) {
            FMS_DW.is_Return = FMS_IN_ForwardTrans;
            FMS_DW.VTOL_M_msgReservedData = VTOLMode_Fixwing;
            FMS_sf_msg_send_VTOL_M();
          }
          break;
        }
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_waypoint[2]) {
          if (FMS_B.target_mode != PilotMode_None) {
            if (tmp_0 == 3.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_Auto;
              FMS_enter_internal_Auto();
            } else if (tmp_0 == 2.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_Assist;
              FMS_enter_internal_Assist();
            } else if (tmp_0 == 1.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_Manual;
              if (FMS_B.target_mode == PilotMode_Manual) {
                FMS_DW.is_Manual = FMS_IN_Manual_o;
                FMS_B.state = VehicleState_Manual;
              } else {
                FMS_DW.is_Manual = FMS_IN_InValidManualMode;
              }
            } else {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
            }
          } else {
            FMS_DW.is_SubMode = FMS_IN_Hold_h;
            FMS_enter_internal_Hold();
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
    if (FMS_DW.is_Auto == FMS_IN_Mission) {
      FMS_exit_internal_Mission();
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
    } else {
      FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
    }

    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_exit_internal_SubMode();
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T c_sf_internal_predicateOutput;
  real32_T tmp[2];
  real_T tmp_0;
  FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
  if ((FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_n >=
       500) && (FMS_B.target_mode != PilotMode_Mission)) {
    FMS_exit_internal_Arm();
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.target_mode !=
              PilotMode_None)) {
    tmp_0 = FMS_getArmMode(FMS_B.target_mode);
    if (tmp_0 == 3.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Auto;
      FMS_enter_internal_Auto();
    } else if (tmp_0 == 2.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Assist;
      FMS_enter_internal_Assist();
    } else if (tmp_0 == 1.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_o;
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
      FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_SubMode = FMS_IN_Land;
      FMS_B.state = VehicleState_Land;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_f = false;
      if (FMS_B.vtol_state == VTOLState_Multicopter) {
        FMS_DW.is_Land = FMS_IN_MC_Land;
        FMS_B.state = VehicleState_Land;
      } else {
        FMS_DW.is_Land = FMS_IN_VTOL_Land;
        FMS_DW.is_VTOL_Land = FMS_IN_BackTrans;
        FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
        FMS_sf_msg_send_VTOL_M();
      }
    } else {
      if (FMS_sf_msg_pop_M()) {
        c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
          FMS_Cmd_Return);
      } else {
        c_sf_internal_predicateOutput = false;
      }

      if (c_sf_internal_predicateOutput) {
        FMS_exit_internal_Arm();
        FMS_DW.is_Arm = FMS_IN_SubMode;
        FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
        FMS_DW.stick_val[1] =
          FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
        FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
        FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
        FMS_DW.is_SubMode = FMS_IN_Return;
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.state_g = VTOLState_Fixwing;

        /* Outputs for Function Call SubSystem: '<S6>/Vehicle.AcceptRadius' */
        FMS_VehicleAcceptRadius(FMS_B.state_g, &FMS_B.Switch_b);

        /* End of Outputs for SubSystem: '<S6>/Vehicle.AcceptRadius' */
        tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home[0];
        tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home[1];
        if ((FMS_norm(tmp) > 2.0F * FMS_B.Switch_b) && (FMS_B.vtol_state ==
             VTOLState_Multicopter)) {
          FMS_DW.is_Return = FMS_IN_Align;
          FMS_B.start[0] = FMS_B.Cmd_In.cur_waypoint[0];
          FMS_B.end[0] = FMS_B.Cmd_In.sp_waypoint[0];
          FMS_B.start[1] = FMS_B.Cmd_In.cur_waypoint[1];
          FMS_B.end[1] = FMS_B.Cmd_In.sp_waypoint[1];
          FMS_B.start[2] = FMS_B.Cmd_In.cur_waypoint[2];
          FMS_B.end[2] = FMS_B.Cmd_In.sp_waypoint[2];

          /* Outputs for Function Call SubSystem: '<S6>/Vehicle.WaypointAngle' */
          FMS_VehicleWaypointAngle(FMS_B.start, FMS_B.end, &FMS_B.Switch,
            &FMS_ConstB.VehicleWaypointAngle);

          /* End of Outputs for SubSystem: '<S6>/Vehicle.WaypointAngle' */
          FMS_B.Cmd_In.set_yaw = FMS_B.Switch;
          FMS_B.state = VehicleState_Hold;
        } else {
          FMS_DW.is_Return = FMS_IN_Execute;
          FMS_B.state = VehicleState_Return;
        }
      } else {
        switch (FMS_DW.is_Arm) {
         case FMS_IN_Assist:
          if (FMS_B.Compare && ((int32_T)
                                (FMS_B.BusConversion_InsertedFor_FMSSt.flag &
                                 212U) == 212)) {
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_o;
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
            FMS_enter_internal_Hold();
          } else {
            if (FMS_DW.is_Assist == FMS_IN_InvalidAssistMode) {
              FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
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
            if (FMS_DW.is_Auto == FMS_IN_Mission) {
              FMS_exit_internal_Mission();
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
            } else {
              FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
            }

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
            FMS_enter_internal_Hold();
          } else {
            switch (FMS_DW.is_Auto) {
             case FMS_IN_InvalidAutoMode:
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Vehicle = FMS_IN_Disarm;
              FMS_B.state = VehicleState_Disarm;
              break;

             case FMS_IN_Mission:
              FMS_Mission();
              break;

             case FMS_IN_Offboard:
              switch (FMS_DW.is_Offboard) {
               case FMS_IN_Loiter_p:
                if (FMS_B.LogicalOperator) {
                  FMS_DW.is_Offboard = FMS_IN_Run;
                  FMS_B.state = VehicleState_Offboard;
                }
                break;

               case FMS_IN_Run:
                if (!FMS_B.LogicalOperator) {
                  FMS_DW.is_Offboard = FMS_IN_Loiter_p;
                  FMS_B.state = VehicleState_Hold;
                }
                break;
              }
              break;
            }
          }
          break;

         case FMS_IN_InvalidArmMode:
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
          break;

         case FMS_IN_Manual:
          if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
            FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
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
  boolean_T guard5 = false;
  if (FMS_DW.mission_timestamp_prev != FMS_DW.mission_timestamp_start) {
    FMS_B.wp_consume = 0U;
    FMS_B.wp_index = 1U;
    FMS_DW.need_forwardtrans = 0.0;
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
      break;

     case FMS_IN_Standby:
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
        FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
      break;

     default:
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
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
              (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
            FMS_DW.durationLastReferenceTick_1_j =
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
          (FMS_B.target_mode != PilotMode_None)) {
        guard2 = true;
      } else {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_j >= 500) {
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
                (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
              FMS_DW.durationLastReferenceTick_1_j =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
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

      /* Outputs for Function Call SubSystem: '<S6>/Vehicle.PrepTakeoff' */
      /* Reshape: '<S743>/Reshape' incorporates:
       *  Constant: '<S743>/Constant'
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
        FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
        FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_o = false;
      FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      guard4 = false;
      guard5 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
          /* Inport: '<Root>/Mission_Data' */
          b_previousEvent = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
          if ((b_previousEvent == (int32_T)NAV_Cmd_Takeoff) || (b_previousEvent ==
               (int32_T)NAV_Cmd_VTOL_Takeoff)) {
            FMS_DW.prep_mission_takeoff = 1.0;
            FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff ==
              1.0);
            FMS_DW.prep_takeoff = 0.0;
            FMS_DW.condWasTrueAtLastTimeStep_1_o = (FMS_DW.prep_takeoff == 1.0);
            guard4 = true;
          } else {
            guard5 = true;
          }
        } else {
          guard5 = true;
        }
      } else {
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
            (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_o = sf_internal_predicateOutput;
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
static boolean_T FMS_CheckModeValid(VTOLMode vtol_mode_in, VTOLState
  vtol_state_in)
{
  boolean_T valid;
  valid = false;
  if (((vtol_state_in == VTOLState_Multicopter) || (vtol_state_in ==
        VTOLState_BackwardTrans)) && (vtol_mode_in == VTOLMode_Fixwing)) {
    valid = true;
  } else {
    if (((vtol_state_in == VTOLState_Fixwing) || (vtol_state_in ==
          VTOLState_ForwardTrans)) && (vtol_mode_in == VTOLMode_Multicopter)) {
      valid = true;
    }
  }

  return valid;
}

int32_T FMS_pop_c(Queue_VTOLMode *q, Msg_VTOLMode *elementOut)
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
static boolean_T FMS_sf_msg_pop_VTOL_M(void)
{
  boolean_T isPresent;
  if (FMS_DW.VTOL_M_isValid) {
    isPresent = true;
  } else {
    FMS_DW.VTOL_M_msgHandle = FMS_pop_c(&FMS_DW.Queue_VTOLMode_a,
      &FMS_DW.Msg_VTOLMode_l[0]) != 0 ? (void *)&FMS_DW.Msg_VTOLMode_l[0] : NULL;
    if (FMS_DW.VTOL_M_msgHandle != NULL) {
      FMS_DW.VTOL_M_msgDataPtr = &((Msg_VTOLMode *)FMS_DW.VTOL_M_msgHandle)
        ->fData;
      isPresent = true;
      FMS_DW.VTOL_M_msgReservedData = *(VTOLMode *)FMS_DW.VTOL_M_msgDataPtr;
      FMS_DW.VTOL_M_isValid = true;
    } else {
      isPresent = false;
      FMS_DW.VTOL_M_isValid = false;
    }
  }

  return isPresent;
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_c11_FMS(void)
{
  int32_T b_previousEvent;
  boolean_T b_sf_internal_predicateOutput;
  boolean_T guard1 = false;

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
    FMS_DW.vtol_mode_prev = FMS_B.DataTypeConversion_n;
    FMS_DW.vtol_mode_start = FMS_B.DataTypeConversion_n;
    FMS_DW.chartAbsoluteTimeCounter = 0;
    FMS_DW.is_active_c11_FMS = 1U;
    FMS_DW.is_active_Command_Listener = 1U;
    FMS_DW.is_Command_Listener = FMS_IN_Listen;
    FMS_DW.is_active_Combo_Stick = 1U;
    FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_jb = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
    FMS_DW.condWasTrueAtLastTimeStep_2_e = FMS_DW.bl;
    FMS_DW.is_active_Lost_Return = 1U;
    FMS_DW.is_Lost_Return = FMS_IN_Connect;
    FMS_DW.is_active_VTOL_Mode = 1U;
    FMS_DW.is_VTOL_Mode = FMS_IN_Listen;
    FMS_DW.is_active_VTOL_State = 1U;
    FMS_DW.is_VTOL_State = FMS_IN_Multicopter;
    FMS_B.vtol_state = VTOLState_Multicopter;
    FMS_DW.is_active_Vehicle = 1U;
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else {
    if (FMS_DW.is_active_Command_Listener != 0U) {
      FMS_Command_Listener();
    }

    if (FMS_DW.is_active_Combo_Stick != 0U) {
      switch (FMS_DW.is_Combo_Stick) {
       case FMS_IN_Arm:
        if (!FMS_BottomRight(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                             FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_jb =
            FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_e = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_jb =
            FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_e = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_jb =
            FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_jb > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_e)) {
            FMS_DW.durationLastReferenceTick_2_a =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2_e = FMS_DW.bl;
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
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_e)) {
              FMS_DW.durationLastReferenceTick_2_a =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2_e = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
              FMS_DW.durationLastReferenceTick_1_jb =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
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
      switch (FMS_DW.is_VTOL_Mode) {
       case FMS_IN_Check:
        if (FMS_DW.valid_mode) {
          FMS_DW.is_VTOL_Mode = FMS_IN_Send;
          FMS_DW.VTOL_M_msgReservedData = FMS_DW.expect_vtol_mode;
          FMS_sf_msg_send_VTOL_M();
        } else {
          FMS_DW.is_VTOL_Mode = FMS_IN_Listen;
        }
        break;

       case FMS_IN_Listen:
        if (FMS_DW.vtol_mode_prev != FMS_DW.vtol_mode_start) {
          FMS_DW.expect_vtol_mode = FMS_B.DataTypeConversion_n;
          FMS_DW.is_VTOL_Mode = FMS_IN_Check;
          FMS_DW.valid_mode = FMS_CheckModeValid(FMS_DW.expect_vtol_mode,
            FMS_B.vtol_state);
        }
        break;

       case FMS_IN_Send:
        FMS_DW.is_VTOL_Mode = FMS_IN_Listen;
        break;
      }
    }

    if (FMS_DW.is_active_VTOL_State != 0U) {
      guard1 = false;
      switch (FMS_DW.is_VTOL_State) {
       case FMS_IN_BackwardTrans:
        if ((fabsf(FMS_B.DiscreteTimeIntegrator5_p) < 1.0F) ||
            (FMS_DW.temporalCounter_i2 >= 5000U)) {
          guard1 = true;
        } else {
          if (FMS_sf_msg_pop_M()) {
            b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Pause);
          } else {
            b_sf_internal_predicateOutput = false;
          }

          if (b_sf_internal_predicateOutput) {
            guard1 = true;
          } else {
            if (FMS_sf_msg_pop_VTOL_M()) {
              b_sf_internal_predicateOutput = (FMS_DW.VTOL_M_msgReservedData ==
                VTOLMode_Fixwing);
            } else {
              b_sf_internal_predicateOutput = false;
            }

            if (b_sf_internal_predicateOutput) {
              FMS_DW.is_VTOL_State = FMS_IN_ForwardTrans;
              FMS_B.vtol_state = VTOLState_ForwardTrans;
            }
          }
        }
        break;

       case FMS_IN_Fixwing:
        if (FMS_sf_msg_pop_VTOL_M()) {
          b_sf_internal_predicateOutput = (FMS_DW.VTOL_M_msgReservedData ==
            VTOLMode_Multicopter);
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          FMS_DW.is_VTOL_State = FMS_IN_BackwardTrans;
          FMS_DW.temporalCounter_i2 = 0U;
          FMS_B.vtol_state = VTOLState_BackwardTrans;
        }
        break;

       case FMS_IN_ForwardTrans:
        FMS_B.Airspeed = FMS_B.DiscreteTimeIntegrator5;

        /* Outputs for Function Call SubSystem: '<S6>/VTOL_State.ForwardTransCplt' */
        /* RelationalOperator: '<S739>/Relational Operator' incorporates:
         *  Constant: '<S739>/Constant'
         */
        FMS_B.RelationalOperator = (FMS_B.Airspeed >=
          FMS_PARAM.FW_CRUISE_SPEED_MIN);

        /* End of Outputs for SubSystem: '<S6>/VTOL_State.ForwardTransCplt' */
        if (FMS_B.RelationalOperator) {
          FMS_DW.is_VTOL_State = FMS_IN_Fixwing;
          FMS_B.vtol_state = VTOLState_Fixwing;
        } else {
          if (FMS_sf_msg_pop_VTOL_M()) {
            b_sf_internal_predicateOutput = (FMS_DW.VTOL_M_msgReservedData ==
              VTOLMode_Multicopter);
          } else {
            b_sf_internal_predicateOutput = false;
          }

          if (b_sf_internal_predicateOutput) {
            FMS_DW.is_VTOL_State = FMS_IN_BackwardTrans;
            FMS_DW.temporalCounter_i2 = 0U;
            FMS_B.vtol_state = VTOLState_BackwardTrans;
          }
        }
        break;

       case FMS_IN_Multicopter:
        if (FMS_sf_msg_pop_VTOL_M()) {
          b_sf_internal_predicateOutput = (FMS_DW.VTOL_M_msgReservedData ==
            VTOLMode_Fixwing);
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          FMS_DW.is_VTOL_State = FMS_IN_ForwardTrans;
          FMS_B.vtol_state = VTOLState_ForwardTrans;
        }
        break;
      }

      if (guard1) {
        FMS_DW.is_VTOL_State = FMS_IN_Multicopter;
        FMS_B.vtol_state = VTOLState_Multicopter;
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

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_sf_msg_discard_VTOL_M(void)
{
  if (FMS_DW.VTOL_M_isValid) {
    FMS_DW.VTOL_M_isValid = false;
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

void FMS_initQueue_k(Queue_VTOLMode *q, QueuePolicy_T policy, int32_T capacity,
                     Msg_VTOLMode *qPool)
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
  FMS_initQueue((Queue_FMS_Cmd *)&FMS_DW.Queue_FMS_Cmd_d, MSG_FIFO_QUEUE, 10,
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_i[1]);
  FMS_initQueue_k((Queue_VTOLMode *)&FMS_DW.Queue_VTOLMode_a, MSG_FIFO_QUEUE, 10,
                  (Msg_VTOLMode *)&FMS_DW.Msg_VTOLMode_l[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T d;
  real32_T rtb_MatrixConcatenate1_i[9];
  FMS_Cmd rtb_DataTypeConversion1_m;
  boolean_T rtb_FixPtRelationalOperator_me;
  uint8_T rtb_Switch_ga;
  int8_T rtPrevAction;
  real32_T rtb_Switch_c2[3];
  real32_T rtb_Switch_an[3];
  real32_T rtb_Divide_i5[2];
  real32_T rtb_Square_ds[2];
  real32_T rtb_Saturation_e;
  real32_T rtb_Square_bg[2];
  int32_T rtb_n;
  real32_T rtb_Switch_ee[3];
  real32_T rtb_Divide_or;
  real32_T rtb_Sign5_mn;
  real32_T rtb_Add4_o;
  MotionState rtb_state_l4;
  MotionState rtb_state_fg;
  MotionState rtb_state_og;
  real_T rtb_Switch1_n;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_aw;
  uint16_T rtb_y_cc;
  real32_T rtb_VectorConcatenate_ch[9];
  real32_T rtb_P_dg[2];
  boolean_T rtb_Compare_kd;
  real32_T rtb_P_cg[2];
  real32_T rtb_Subtract_hb[2];
  real32_T rtb_MatrixConcatenate1_i_0[3];
  boolean_T tmp[3];
  boolean_T tmp_0[3];
  boolean_T tmp_1[3];
  real32_T rtb_VectorConcatenate_fy[3];
  real32_T rtb_Divide_pr_idx_2;
  real32_T rtb_Divide_pr_idx_1;
  real32_T rtb_Divide_pr_idx_0;
  real32_T rtb_Divide_lr_idx_3;
  real32_T rtb_Divide_lr_idx_2;
  real32_T rtb_Divide_lr_idx_1;
  real32_T rtb_Divide_lr_idx_0;
  real_T rtb_Multiply_g_idx_0;
  real32_T rtb_MatrixConcatenate1_i_tmp;
  real32_T rtb_MatrixConcatenate1_i_tmp_0;
  real32_T rtb_MatrixConcatenate1_i_tmp_1;
  real32_T rtb_MatrixConcatenate1_i_tmp_2;
  real32_T rtb_MatrixConcatenate1_i_tmp_3;
  uint32_T tmp_2;
  uint32_T tmp_3;
  uint32_T tmp_4;

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S39>/Arm' incorporates:
   *  ActionPort: '<S41>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S41>/BackwardTrans_Mode' incorporates:
   *  ActionPort: '<S45>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S41>/FW_Mode' incorporates:
   *  ActionPort: '<S46>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Assist' incorporates:
   *  ActionPort: '<S85>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S85>/Position' incorporates:
   *  ActionPort: '<S91>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S133>/Hold Control' incorporates:
   *  ActionPort: '<S136>/Action Port'
   */
  /* SwitchCase: '<S133>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S148>/Square'
   *  Math: '<S18>/Square'
   *  Math: '<S60>/Square'
   *  Sqrt: '<S148>/Sqrt'
   *  Sqrt: '<S18>/Sqrt'
   *  Sum: '<S18>/Sum of Elements'
   *  SwitchCase: '<S39>/Switch Case'
   *  SwitchCase: '<S41>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S85>/Switch Case'
   */
  rtb_Divide_pr_idx_0 = FMS_U.INS_Out.quat[0] * FMS_U.INS_Out.quat[0];
  rtb_Divide_pr_idx_1 = FMS_U.INS_Out.quat[1] * FMS_U.INS_Out.quat[1];
  rtb_Divide_pr_idx_2 = FMS_U.INS_Out.quat[2] * FMS_U.INS_Out.quat[2];
  rtb_Saturation_e = FMS_U.INS_Out.quat[3] * FMS_U.INS_Out.quat[3];

  /* End of Outputs for SubSystem: '<S41>/BackwardTrans_Mode' */
  d = sqrtf(((rtb_Divide_pr_idx_0 + rtb_Divide_pr_idx_1) + rtb_Divide_pr_idx_2)
            + rtb_Saturation_e);

  /* End of Outputs for SubSystem: '<S133>/Hold Control' */
  /* End of Outputs for SubSystem: '<S85>/Position' */
  /* End of Outputs for SubSystem: '<S46>/Assist' */
  /* End of Outputs for SubSystem: '<S41>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S39>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Product: '<S14>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Sqrt: '<S18>/Sqrt'
   */
  rtb_Divide_lr_idx_0 = FMS_U.INS_Out.quat[0] / d;
  rtb_Divide_lr_idx_1 = FMS_U.INS_Out.quat[1] / d;
  rtb_Divide_lr_idx_2 = FMS_U.INS_Out.quat[2] / d;
  rtb_Divide_lr_idx_3 = FMS_U.INS_Out.quat[3] / d;

  /* Math: '<S15>/Square' incorporates:
   *  Math: '<S16>/Square'
   *  Math: '<S17>/Square'
   */
  rtb_Add4_o = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_0;

  /* Math: '<S15>/Square2' incorporates:
   *  Math: '<S16>/Square2'
   *  Math: '<S17>/Square2'
   */
  rtb_Divide_or = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

  /* Math: '<S15>/Square1' incorporates:
   *  Math: '<S16>/Square1'
   *  Math: '<S17>/Square1'
   */
  rtb_Sign5_mn = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1;

  /* Math: '<S15>/Square3' incorporates:
   *  Math: '<S16>/Square3'
   *  Math: '<S17>/Square3'
   */
  rtb_MatrixConcatenate1_i_tmp_1 = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

  /* Sum: '<S15>/Subtract' incorporates:
   *  Math: '<S15>/Square'
   *  Math: '<S15>/Square1'
   *  Math: '<S15>/Square2'
   *  Math: '<S15>/Square3'
   *  Sum: '<S15>/Add'
   *  Sum: '<S15>/Add1'
   */
  rtb_MatrixConcatenate1_i[0] = (rtb_Add4_o + rtb_Sign5_mn) - (rtb_Divide_or +
    rtb_MatrixConcatenate1_i_tmp_1);

  /* Product: '<S15>/Multiply' incorporates:
   *  Product: '<S16>/Multiply'
   */
  rtb_MatrixConcatenate1_i_tmp = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_2;

  /* Product: '<S15>/Multiply1' incorporates:
   *  Product: '<S16>/Multiply1'
   */
  rtb_MatrixConcatenate1_i_tmp_0 = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_3;

  /* Gain: '<S15>/Gain' incorporates:
   *  Product: '<S15>/Multiply'
   *  Product: '<S15>/Multiply1'
   *  Sum: '<S15>/Subtract1'
   */
  rtb_MatrixConcatenate1_i[1] = (rtb_MatrixConcatenate1_i_tmp -
    rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

  /* Product: '<S15>/Multiply2' incorporates:
   *  Product: '<S17>/Multiply'
   */
  rtb_MatrixConcatenate1_i_tmp_2 = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_3;

  /* Product: '<S15>/Multiply3' incorporates:
   *  Product: '<S17>/Multiply1'
   */
  rtb_MatrixConcatenate1_i_tmp_3 = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_2;

  /* Gain: '<S15>/Gain1' incorporates:
   *  Product: '<S15>/Multiply2'
   *  Product: '<S15>/Multiply3'
   *  Sum: '<S15>/Add2'
   */
  rtb_MatrixConcatenate1_i[2] = (rtb_MatrixConcatenate1_i_tmp_2 +
    rtb_MatrixConcatenate1_i_tmp_3) * 2.0F;

  /* Gain: '<S16>/Gain' incorporates:
   *  Sum: '<S16>/Add3'
   */
  rtb_MatrixConcatenate1_i[3] = (rtb_MatrixConcatenate1_i_tmp +
    rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

  /* Sum: '<S16>/Subtract' incorporates:
   *  Sum: '<S16>/Add'
   *  Sum: '<S16>/Add1'
   */
  rtb_MatrixConcatenate1_i[4] = (rtb_Add4_o + rtb_Divide_or) - (rtb_Sign5_mn +
    rtb_MatrixConcatenate1_i_tmp_1);

  /* Product: '<S16>/Multiply2' incorporates:
   *  Product: '<S17>/Multiply2'
   */
  rtb_MatrixConcatenate1_i_tmp = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_3;

  /* Product: '<S16>/Multiply3' incorporates:
   *  Product: '<S17>/Multiply3'
   */
  rtb_MatrixConcatenate1_i_tmp_0 = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_1;

  /* Gain: '<S16>/Gain1' incorporates:
   *  Product: '<S16>/Multiply2'
   *  Product: '<S16>/Multiply3'
   *  Sum: '<S16>/Subtract1'
   */
  rtb_MatrixConcatenate1_i[5] = (rtb_MatrixConcatenate1_i_tmp -
    rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

  /* Gain: '<S17>/Gain' incorporates:
   *  Sum: '<S17>/Subtract2'
   */
  rtb_MatrixConcatenate1_i[6] = (rtb_MatrixConcatenate1_i_tmp_2 -
    rtb_MatrixConcatenate1_i_tmp_3) * 2.0F;

  /* Gain: '<S17>/Gain1' incorporates:
   *  Sum: '<S17>/Add2'
   */
  rtb_MatrixConcatenate1_i[7] = (rtb_MatrixConcatenate1_i_tmp +
    rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

  /* Sum: '<S17>/Subtract' incorporates:
   *  Sum: '<S17>/Add'
   *  Sum: '<S17>/Add1'
   */
  rtb_MatrixConcatenate1_i[8] = (rtb_Add4_o + rtb_MatrixConcatenate1_i_tmp_1) -
    (rtb_Sign5_mn + rtb_Divide_or);

  /* Product: '<S12>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S12>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (rtb_n = 0; rtb_n < 3; rtb_n++) {
    rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n + 6] *
      FMS_U.INS_Out.vd + (rtb_MatrixConcatenate1_i[rtb_n + 3] * FMS_U.INS_Out.ve
                          + rtb_MatrixConcatenate1_i[rtb_n] * FMS_U.INS_Out.vn);
  }

  /* End of Product: '<S12>/Multiply' */

  /* Signum: '<S12>/Sign' */
  if (rtb_MatrixConcatenate1_i_0[0] < 0.0F) {
    rtb_Divide_lr_idx_0 = -1.0F;
  } else if (rtb_MatrixConcatenate1_i_0[0] > 0.0F) {
    rtb_Divide_lr_idx_0 = 1.0F;
  } else {
    rtb_Divide_lr_idx_0 = rtb_MatrixConcatenate1_i_0[0];
  }

  /* End of Signum: '<S12>/Sign' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for IfAction SubSystem: '<S39>/Arm' incorporates:
   *  ActionPort: '<S41>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S41>/FW_Mode' incorporates:
   *  ActionPort: '<S46>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Auto' incorporates:
   *  ActionPort: '<S86>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S86>/Mission' incorporates:
   *  ActionPort: '<S193>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S193>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S197>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S46>/SubMode' incorporates:
   *  ActionPort: '<S88>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Return' incorporates:
   *  ActionPort: '<S227>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Takeoff' incorporates:
   *  ActionPort: '<S228>/Action Port'
   */
  /* SwitchCase: '<S86>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S216>/Math Function'
   *  Math: '<S265>/Math Function'
   *  Math: '<S287>/Math Function'
   *  SwitchCase: '<S39>/Switch Case'
   *  SwitchCase: '<S41>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S88>/Switch Case'
   */
  rtb_Add4_o = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_Divide_or = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S88>/Takeoff' */
  /* End of Outputs for SubSystem: '<S88>/Return' */
  /* End of Outputs for SubSystem: '<S193>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S86>/Mission' */
  /* End of Outputs for SubSystem: '<S46>/Auto' */

  /* Outputs for IfAction SubSystem: '<S41>/MC_Mode' incorporates:
   *  ActionPort: '<S47>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
   *  ActionPort: '<S293>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S293>/Mission' incorporates:
   *  ActionPort: '<S405>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S405>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S409>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S47>/SubMode' incorporates:
   *  ActionPort: '<S295>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S295>/Return' incorporates:
   *  ActionPort: '<S597>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S41>/BackwardTrans_Mode' incorporates:
   *  ActionPort: '<S45>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Assist' incorporates:
   *  ActionPort: '<S85>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S85>/Position' incorporates:
   *  ActionPort: '<S91>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S133>/Hold Control' incorporates:
   *  ActionPort: '<S136>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Hold' incorporates:
   *  ActionPort: '<S225>/Action Port'
   */
  /* SwitchCase: '<S133>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sqrt: '<S154>/Sqrt'
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S215>/Sqrt'
   *  Sqrt: '<S241>/Sqrt'
   *  Sqrt: '<S264>/Sqrt'
   *  Sqrt: '<S367>/Sqrt'
   *  Sqrt: '<S475>/Sqrt'
   *  Sqrt: '<S66>/Sqrt'
   *  Sqrt: '<S715>/Sqrt'
   *  Sum: '<S156>/Sum of Elements'
   *  Sum: '<S1>/Add'
   *  Sum: '<S242>/Sum of Elements'
   *  Sum: '<S477>/Sum of Elements'
   *  Sum: '<S68>/Sum of Elements'
   *  Sum: '<S717>/Sum of Elements'
   *  Switch: '<S136>/Switch'
   *  Switch: '<S48>/Switch'
   *  SwitchCase: '<S292>/Switch Case'
   *  SwitchCase: '<S293>/Switch Case'
   *  SwitchCase: '<S295>/Switch Case'
   *  SwitchCase: '<S39>/Switch Case'
   *  SwitchCase: '<S41>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S47>/Switch Case'
   *  SwitchCase: '<S85>/Switch Case'
   *  SwitchCase: '<S86>/Switch Case'
   *  SwitchCase: '<S88>/Switch Case'
   */
  rtb_Divide_lr_idx_3 = rtb_Add4_o + rtb_Divide_or;

  /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
   *  ActionPort: '<S292>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S292>/Position' incorporates:
   *  ActionPort: '<S299>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Auto' incorporates:
   *  ActionPort: '<S86>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S86>/Mission' incorporates:
   *  ActionPort: '<S193>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S193>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S197>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Return' incorporates:
   *  ActionPort: '<S227>/Action Port'
   */
  rtb_Divide_lr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);

  /* End of Outputs for SubSystem: '<S88>/Return' */
  /* End of Outputs for SubSystem: '<S193>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S86>/Mission' */
  /* End of Outputs for SubSystem: '<S46>/Auto' */
  /* End of Outputs for SubSystem: '<S292>/Position' */
  /* End of Outputs for SubSystem: '<S47>/Assist' */
  /* End of Outputs for SubSystem: '<S88>/Hold' */
  /* End of Outputs for SubSystem: '<S133>/Hold Control' */
  /* End of Outputs for SubSystem: '<S85>/Position' */
  /* End of Outputs for SubSystem: '<S46>/Assist' */
  /* End of Outputs for SubSystem: '<S41>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S295>/Return' */
  /* End of Outputs for SubSystem: '<S47>/SubMode' */
  /* End of Outputs for SubSystem: '<S405>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S293>/Mission' */
  /* End of Outputs for SubSystem: '<S47>/Auto' */
  /* End of Outputs for SubSystem: '<S41>/MC_Mode' */
  /* End of Outputs for SubSystem: '<S46>/SubMode' */
  /* End of Outputs for SubSystem: '<S41>/FW_Mode' */
  /* End of Outputs for SubSystem: '<S39>/Arm' */
  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* Product: '<S1>/Multiply' incorporates:
   *  Sqrt: '<S1>/Sqrt'
   */
  rtb_Divide_lr_idx_0 *= rtb_Divide_lr_idx_2;

  /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S27>/FixPt Relational Operator'
   *  UnitDelay: '<S27>/Delay Input1'
   *
   * Block description for '<S27>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = 0U;
  }

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S26>/Constant'
   *  Constant: '<S32>/Constant'
   *  Constant: '<S33>/Constant'
   *  DataTypeConversion: '<S25>/Data Type Conversion2'
   *  Delay: '<S25>/Delay'
   *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  Logic: '<S25>/Logical Operator'
   *  Logic: '<S25>/Logical Operator1'
   *  RelationalOperator: '<S26>/Compare'
   *  RelationalOperator: '<S32>/Compare'
   *  RelationalOperator: '<S33>/Compare'
   *  RelationalOperator: '<S34>/FixPt Relational Operator'
   *  Switch: '<S25>/Switch1'
   *  UnitDelay: '<S34>/Delay Input1'
   *
   * Block description for '<S34>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((FMS_U.Pilot_Cmd.mode != 0U) && (FMS_DW.DiscreteTimeIntegrator1_DSTAT_b <
       500U)) {
    FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.Pilot_Cmd.mode;
  } else {
    if ((FMS_U.GCS_Cmd.mode != FMS_DW.DelayInput1_DSTATE_f) &&
        (FMS_U.GCS_Cmd.mode != 0U)) {
      /* Switch: '<S25>/Switch1' incorporates:
       *  DataTypeConversion: '<S25>/Data Type Conversion1'
       *  Delay: '<S25>/Delay'
       *  Inport: '<Root>/GCS_Cmd'
       */
      FMS_DW.Delay_DSTATE_c = (PilotMode)FMS_U.GCS_Cmd.mode;
    }
  }

  /* End of Switch: '<S25>/Switch' */

  /* Chart: '<Root>/SafeMode' incorporates:
   *  Delay: '<S25>/Delay'
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

  /* Saturate: '<S1>/Saturation1' incorporates:
   *  Switch: '<S1>/Switch'
   */
  if (rtb_Divide_lr_idx_0 > 100.0F) {
    rtb_Divide_lr_idx_1 = 100.0F;
  } else if (rtb_Divide_lr_idx_0 < 0.1F) {
    rtb_Divide_lr_idx_1 = 0.1F;
  } else {
    rtb_Divide_lr_idx_1 = rtb_Divide_lr_idx_0;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTATE = rtb_Divide_lr_idx_1;
  }

  FMS_B.DiscreteTimeIntegrator5 = FMS_DW.DiscreteTimeIntegrator5_DSTATE;

  /* End of DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */

  /* DataTypeConversion: '<S24>/Data Type Conversion1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   */
  rtb_DataTypeConversion1_m = (FMS_Cmd)FMS_U.GCS_Cmd.cmd_1;

  /* Switch: '<S24>/Switch1' incorporates:
   *  Constant: '<S24>/Constant1'
   *  DataTypeConversion: '<S24>/Data Type Conversion2'
   *  Inport: '<Root>/GCS_Cmd'
   *  Inport: '<Root>/Pilot_Cmd'
   *  RelationalOperator: '<S29>/FixPt Relational Operator'
   *  RelationalOperator: '<S30>/FixPt Relational Operator'
   *  Switch: '<S24>/Switch2'
   *  UnitDelay: '<S29>/Delay Input1'
   *  UnitDelay: '<S30>/Delay Input1'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Pilot_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_i) {
    FMS_B.Switch1 = (FMS_Cmd)FMS_U.Pilot_Cmd.cmd_1;
  } else if (FMS_U.GCS_Cmd.cmd_1 != FMS_DW.DelayInput1_DSTATE_p) {
    /* Switch: '<S24>/Switch2' */
    FMS_B.Switch1 = rtb_DataTypeConversion1_m;
  } else {
    FMS_B.Switch1 = FMS_Cmd_None;
  }

  /* End of Switch: '<S24>/Switch1' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.BusConversion_InsertedFor_FMS_f = FMS_U.Pilot_Cmd;

  /* RelationalOperator: '<S36>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  UnitDelay: '<S36>/Delay Input1'
   *
   * Block description for '<S36>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_me = (FMS_U.Pilot_Cmd.timestamp !=
    FMS_DW.DelayInput1_DSTATE_h);

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/GCS_Cmd'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator1'
   *  RelationalOperator: '<S35>/FixPt Relational Operator'
   *  UnitDelay: '<S35>/Delay Input1'
   *
   * Block description for '<S35>/Delay Input1':
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

  /* Logic: '<S4>/Logical Operator2' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S4>/Constant1'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  RelationalOperator: '<S37>/Compare'
   */
  FMS_B.LogicalOperator2 = ((FMS_DW.DiscreteTimeIntegrator_DSTATE >=
    FMS_PARAM.LOST_RETURN_TIME) && (FMS_PARAM.LOST_RETURN_EN != 0));

  /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */
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

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
   */
  FMS_B.Compare = (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 1.0F);

  /* BusCreator: '<Root>/BusConversion_InsertedFor_FMS State Machine_at_inport_5' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  FMS_B.BusConversion_InsertedFor_FMSSt = FMS_U.INS_Out;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Delay: '<S21>/Delay'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S20>/FixPt Relational Operator'
   *  Switch: '<S21>/Switch'
   *  UnitDelay: '<S20>/Delay Input1'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (FMS_U.Auto_Cmd.timestamp != FMS_DW.DelayInput1_DSTATE_c) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = 0U;
    rtb_Switch_ga = 1U;
  } else {
    rtb_Switch_ga = FMS_DW.Delay_DSTATE_o;
  }

  /* Logic: '<S2>/Logical Operator' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S22>/Upper Limit'
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Inport: '<Root>/Auto_Cmd'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S22>/Upper Test'
   */
  FMS_B.LogicalOperator = ((FMS_DW.DiscreteTimeIntegrator_DSTATE_b < 1000U) &&
    (rtb_Switch_ga != 0) && (FMS_U.Auto_Cmd.frame <= 2));

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  FMS_B.DataTypeConversion_n = (VTOLMode)FMS_U.Pilot_Cmd.cmd_2;

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  if (FMS_DW.DiscreteTimeIntegrator5_IC_LO_m != 0) {
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_h = rtb_Divide_lr_idx_0;
  }

  FMS_B.DiscreteTimeIntegrator5_p = FMS_DW.DiscreteTimeIntegrator5_DSTAT_h;

  /* End of DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */

  /* Chart: '<Root>/FMS State Machine' incorporates:
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  FMS_DW.durationLastReferenceTick_1_d = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_f = false;
  rtb_FixPtRelationalOperator_me = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_me) ||
      (!FMS_DW.condWasTrueAtLastTimeStep_1_o)) {
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_o = rtb_FixPtRelationalOperator_me;
  rtb_FixPtRelationalOperator_me = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_FixPtRelationalOperator_me) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
  {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_FixPtRelationalOperator_me;
  FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
    FMS_DW.durationLastReferenceTick_1_jb = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_e)) {
    FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2_e = FMS_DW.bl;
  if (FMS_DW.temporalCounter_i1 < MAX_uint32_T) {
    FMS_DW.temporalCounter_i1++;
  }

  if (FMS_DW.temporalCounter_i2 < 8191U) {
    FMS_DW.temporalCounter_i2++;
  }

  FMS_DW.sfEvent = -1;
  FMS_DW.mission_timestamp_prev = FMS_DW.mission_timestamp_start;
  FMS_DW.mission_timestamp_start = FMS_U.Mission_Data.timestamp;
  FMS_DW.cmd_prev = FMS_DW.cmd_start;
  FMS_DW.cmd_start = FMS_B.Switch1;
  FMS_DW.mode_prev = FMS_DW.mode_start;
  FMS_DW.mode_start = FMS_B.target_mode;
  FMS_DW.vtol_mode_prev = FMS_DW.vtol_mode_start;
  FMS_DW.vtol_mode_start = FMS_B.DataTypeConversion_n;
  FMS_DW.M_isValid = false;
  FMS_DW.VTOL_M_isValid = false;
  FMS_c11_FMS();
  FMS_sf_msg_discard_M();
  FMS_sf_msg_discard_VTOL_M();

  /* End of Chart: '<Root>/FMS State Machine' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS Commander' */
  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  /* SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_an[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_ee[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_an[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_ee[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_an[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_Switch_ee[2] = FMS_B.Cmd_In.cur_waypoint[2];

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

  /* SwitchCase: '<S39>/Switch Case' incorporates:
   *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy6Inport1'
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
    /* Disable for SwitchCase: '<S41>/Switch Case' */
    switch (FMS_DW.SwitchCase_ActiveSubsystem_k) {
     case 0:
      /* Disable for SwitchCase: '<S46>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
       case 0:
        /* Disable for SwitchCase: '<S88>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S86>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S85>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
         case 3:
          break;

         case 1:
          /* Disable for SwitchCase: '<S98>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S133>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S119>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 3:
       case 4:
        break;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_pn = -1;
      break;

     case 1:
      break;

     case 2:
      /* Disable for SwitchCase: '<S47>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
       case 0:
        /* Disable for SwitchCase: '<S295>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S696>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S686>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S635>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S603>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S614>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S293>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S405>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S456>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S446>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S405>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S292>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S392>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S307>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S325>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S341>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S366>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S353>/Switch Case' */
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
    }

    FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

    /* End of Disable for SwitchCase: '<S41>/Switch Case' */
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S39>/Disarm' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    /* BusAssignment: '<S43>/Bus Assignment' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant2'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_mv;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ap;

    /* End of Outputs for SubSystem: '<S39>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S39>/Standby' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    /* BusAssignment: '<S44>/Bus Assignment' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant2'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion2_hd;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ft;

    /* End of Outputs for SubSystem: '<S39>/Standby' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S39>/Arm' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    /* SwitchCase: '<S41>/Switch Case' incorporates:
     *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy8Inport1'
     */
    rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_k;

    /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
    switch (FMS_B.vtol_state) {
     case VTOLState_Fixwing:
     case VTOLState_ForwardTrans:
      FMS_DW.SwitchCase_ActiveSubsystem_k = 0;
      break;

     case VTOLState_BackwardTrans:
      FMS_DW.SwitchCase_ActiveSubsystem_k = 1;
      break;

     default:
      FMS_DW.SwitchCase_ActiveSubsystem_k = 2;
      break;
    }

    /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
    if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_k) {
      switch (rtPrevAction) {
       case 0:
        /* Disable for SwitchCase: '<S46>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
         case 0:
          /* Disable for SwitchCase: '<S88>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S86>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S85>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S98>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S133>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S119>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
          break;

         case 3:
         case 4:
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_pn = -1;
        break;

       case 1:
        break;

       case 2:
        /* Disable for SwitchCase: '<S47>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b) {
         case 0:
          /* Disable for SwitchCase: '<S295>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S696>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S686>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S635>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S603>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S614>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S293>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S405>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S456>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S446>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S405>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S292>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S392>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S307>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S325>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S341>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S366>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S353>/Switch Case' */
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
      }
    }

    switch (FMS_DW.SwitchCase_ActiveSubsystem_k) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S41>/FW_Mode' incorporates:
       *  ActionPort: '<S46>/Action Port'
       */
      /* SwitchCase: '<S46>/Switch Case' */
      rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_pn;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      switch (FMS_B.state) {
       case VehicleState_Land:
       case VehicleState_Return:
       case VehicleState_Takeoff:
       case VehicleState_Hold:
        FMS_DW.SwitchCase_ActiveSubsystem_pn = 0;
        break;

       case VehicleState_Offboard:
       case VehicleState_Mission:
        FMS_DW.SwitchCase_ActiveSubsystem_pn = 1;
        break;

       case VehicleState_Acro:
       case VehicleState_Stabilize:
       case VehicleState_Altitude:
       case VehicleState_Position:
        FMS_DW.SwitchCase_ActiveSubsystem_pn = 2;
        break;

       case VehicleState_Manual:
        FMS_DW.SwitchCase_ActiveSubsystem_pn = 3;
        break;

       default:
        FMS_DW.SwitchCase_ActiveSubsystem_pn = 4;
        break;
      }

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_pn) {
        switch (rtPrevAction) {
         case 0:
          /* Disable for SwitchCase: '<S88>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S86>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S85>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S98>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S133>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S119>/Switch Case' */
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

      switch (FMS_DW.SwitchCase_ActiveSubsystem_pn) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S46>/SubMode' incorporates:
         *  ActionPort: '<S88>/Action Port'
         */
        /* SwitchCase: '<S88>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_kv;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_kv) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S88>/Takeoff' incorporates:
           *  ActionPort: '<S228>/Action Port'
           */
          /* Sum: '<S287>/Sum of Elements' incorporates:
           *  Sum: '<S286>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Add4_o + rtb_Divide_or;

          /* Math: '<S287>/Math Function1' incorporates:
           *  Sum: '<S287>/Sum of Elements'
           *
           * About '<S287>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S287>/Math Function1' */

          /* Switch: '<S287>/Switch' incorporates:
           *  Constant: '<S287>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S287>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S287>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S277>/NearbyRefWP' incorporates:
           *  Constant: '<S275>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_i5,
                          &rtb_Divide_lr_idx_2);

          /* MATLAB Function: '<S277>/SearchL1RefWP' incorporates:
           *  Constant: '<S275>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_Divide_lr_idx_3);

          /* MATLAB Function: '<S277>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S272>/Sum'
           *  Sum: '<S272>/Sum1'
           */
          rtb_Divide_pr_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_pr_idx_2 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Add4_o = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Divide_or = d * d;
          rtb_Divide_pr_idx_1 = (rtb_Add4_o * d + rtb_Divide_pr_idx_2 *
            rtb_Divide_pr_idx_0) / (rtb_Divide_or + rtb_Divide_pr_idx_0 *
            rtb_Divide_pr_idx_0);
          if (rtb_Divide_pr_idx_1 <= 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_dg[0] = FMS_B.Cmd_In.cur_waypoint[0];
            rtb_P_dg[1] = FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else if (rtb_Divide_pr_idx_1 >= 1.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_dg[0] = FMS_B.Cmd_In.sp_waypoint[0];
            rtb_P_dg[1] = FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Sign5_mn = (rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_0 +
                            FMS_B.Cmd_In.cur_waypoint[0]) - FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Sign5_mn * rtb_Sign5_mn;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Sign5_mn = (rtb_Divide_pr_idx_1 * d + FMS_B.Cmd_In.cur_waypoint
                            [1]) - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Divide_pr_idx_1 += sqrtf(rtb_Sign5_mn * rtb_Sign5_mn +
              rtb_Subtract_hb[0]) * 0.5774F / sqrtf(rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Divide_or);
            if (rtb_Divide_pr_idx_1 > 1.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_dg[0] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_0 +
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_P_dg[1] = rtb_Divide_pr_idx_1 * d + FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* End of MATLAB Function: '<S277>/OutRegionRegWP' */

          /* Switch: '<S277>/Switch1' incorporates:
           *  Constant: '<S280>/Constant'
           *  RelationalOperator: '<S280>/Compare'
           */
          if (rtb_Divide_lr_idx_2 <= 0.0F) {
            /* Switch: '<S277>/Switch' incorporates:
             *  Constant: '<S279>/Constant'
             *  RelationalOperator: '<S279>/Compare'
             */
            if (rtb_Divide_lr_idx_3 >= 0.0F) {
              rtb_Divide_i5[0] = rtb_P_cg[0];
              rtb_Divide_i5[1] = rtb_P_cg[1];
            } else {
              rtb_Divide_i5[0] = rtb_P_dg[0];
              rtb_Divide_i5[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S277>/Switch' */
          }

          /* End of Switch: '<S277>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S278>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_i5[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_i5[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S288>/Sum of Elements' incorporates:
           *  Math: '<S288>/Math Function'
           */
          rtb_Divide_lr_idx_3 = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

          /* Math: '<S288>/Math Function1' incorporates:
           *  Sum: '<S288>/Sum of Elements'
           *
           * About '<S288>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S288>/Math Function1' */

          /* Switch: '<S288>/Switch' incorporates:
           *  Constant: '<S288>/Constant'
           *  Product: '<S288>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_an[0] = rtb_Subtract_hb[0];
            rtb_Switch_an[1] = rtb_Subtract_hb[1];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S288>/Switch' */

          /* Product: '<S287>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S290>/Sum of Elements' incorporates:
           *  Math: '<S290>/Math Function'
           *  SignalConversion: '<S290>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S290>/Math Function1' incorporates:
           *  Sum: '<S290>/Sum of Elements'
           *
           * About '<S290>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S290>/Math Function1' */

          /* Switch: '<S290>/Switch' incorporates:
           *  Constant: '<S290>/Constant'
           *  Product: '<S290>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Subtract_hb[1];
            rtb_Switch_c2[1] = rtb_Subtract_hb[0];
            rtb_Switch_c2[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S290>/Switch' */

          /* Product: '<S288>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S291>/Sum of Elements' incorporates:
           *  Math: '<S291>/Math Function'
           *  SignalConversion: '<S291>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S291>/Math Function1' incorporates:
           *  Sum: '<S291>/Sum of Elements'
           *
           * About '<S291>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S291>/Math Function1' */

          /* Switch: '<S291>/Switch' incorporates:
           *  Constant: '<S291>/Constant'
           *  Product: '<S291>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_an[0] = rtb_Subtract_hb[1];
            rtb_Switch_an[1] = rtb_Subtract_hb[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S291>/Switch' */

          /* Product: '<S291>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S290>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S291>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S290>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S272>/Divide' incorporates:
           *  Math: '<S273>/Square'
           *  Math: '<S274>/Square'
           *  Sqrt: '<S273>/Sqrt'
           *  Sqrt: '<S274>/Sqrt'
           *  Sum: '<S273>/Sum of Elements'
           *  Sum: '<S274>/Sum of Elements'
           */
          rtb_Divide_pr_idx_2 = sqrtf(rtb_Add4_o * rtb_Add4_o +
            rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2) / sqrtf
            (rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0 + d * d);

          /* Saturate: '<S272>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S272>/Saturation' */

          /* Sum: '<S289>/Subtract' incorporates:
           *  Product: '<S289>/Multiply'
           *  Product: '<S289>/Multiply1'
           */
          rtb_Divide_pr_idx_1 = rtb_Subtract_hb[0] * rtb_Divide_i5[1] -
            rtb_Subtract_hb[1] * rtb_Divide_i5[0];

          /* Signum: '<S285>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S285>/Sign1' */

          /* Switch: '<S285>/Switch2' incorporates:
           *  Constant: '<S285>/Constant4'
           */
          if (rtb_Divide_pr_idx_1 == 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          }

          /* End of Switch: '<S285>/Switch2' */

          /* DotProduct: '<S285>/Dot Product' */
          rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Subtract_hb[0] +
            rtb_Divide_i5[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S285>/Acos' incorporates:
           *  DotProduct: '<S285>/Dot Product'
           */
          if (rtb_Divide_pr_idx_0 > 1.0F) {
            rtb_Divide_pr_idx_0 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 < -1.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            }
          }

          /* Product: '<S285>/Multiply' incorporates:
           *  Trigonometry: '<S285>/Acos'
           */
          rtb_Divide_pr_idx_1 *= acosf(rtb_Divide_pr_idx_0);

          /* Saturate: '<S284>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.57079637F) {
            rtb_Divide_pr_idx_1 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_1 < -1.57079637F) {
              rtb_Divide_pr_idx_1 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S284>/Saturation' */

          /* Sqrt: '<S286>/Sqrt' */
          rtb_Divide_lr_idx_2 = sqrtf(rtb_Saturation_e);

          /* BusAssignment: '<S228>/Bus Assignment' incorporates:
           *  Constant: '<S228>/Constant'
           *  Constant: '<S228>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S284>/Divide' incorporates:
           *  Constant: '<S275>/L1'
           *  Gain: '<S284>/Gain'
           *  Math: '<S284>/Square'
           *  Product: '<S284>/Multiply1'
           *  Trigonometry: '<S284>/Sin'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Divide_pr_idx_1) / FMS_PARAM.FW_L1;

          /* Saturate: '<S275>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S228>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S275>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S270>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S272>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S270>/Sum2'
           *  Sum: '<S272>/Add'
           *  Sum: '<S272>/Subtract'
           */
          rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_pr_idx_2 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S270>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S228>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S228>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S270>/Saturation1' */
          /* End of Outputs for SubSystem: '<S88>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S88>/Land' incorporates:
           *  ActionPort: '<S226>/Action Port'
           */
          /* BusAssignment: '<S226>/Bus Assignment1' incorporates:
           *  Constant: '<S226>/Constant'
           *  Constant: '<S226>/Constant1'
           *  Constant: '<S226>/Constant4'
           *  Constant: '<S226>/Constant5'
           *  Constant: '<S226>/Constant7'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_jf;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b4;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_h;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
          FMS_Y.FMS_Out.u_cmd = 0.0F;
          FMS_Y.FMS_Out.v_cmd = 0.0F;
          FMS_Y.FMS_Out.w_cmd = 0.5F;

          /* End of Outputs for SubSystem: '<S88>/Land' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S88>/Return' incorporates:
           *  ActionPort: '<S227>/Action Port'
           */
          /* Math: '<S265>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Add4_o;
          rtb_Subtract_hb[1] = rtb_Divide_or;

          /* Sum: '<S265>/Sum of Elements' */
          rtb_Saturation_e = rtb_Add4_o + rtb_Divide_or;

          /* Math: '<S265>/Math Function1' incorporates:
           *  Sum: '<S265>/Sum of Elements'
           *
           * About '<S265>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Saturation_e = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S265>/Math Function1' */

          /* Switch: '<S265>/Switch' incorporates:
           *  Constant: '<S265>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S265>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_Saturation_e > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Saturation_e;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S265>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S255>/NearbyRefWP' incorporates:
           *  Constant: '<S253>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Divide_pr_idx_1);

          /* MATLAB Function: '<S255>/SearchL1RefWP' incorporates:
           *  Constant: '<S253>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_i5, &rtb_Saturation_e);

          /* MATLAB Function: '<S255>/OutRegionRegWP' incorporates:
           *  Constant: '<S253>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_cg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S255>/Switch1' incorporates:
           *  Constant: '<S258>/Constant'
           *  RelationalOperator: '<S258>/Compare'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Divide_i5[0] = rtb_Subtract_hb[0];
            rtb_Divide_i5[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S257>/Compare' incorporates:
             *  Constant: '<S257>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_e >= 0.0F);

            /* Switch: '<S255>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_i5[0] = rtb_P_cg[0];
              rtb_Divide_i5[1] = rtb_P_cg[1];
            }

            /* End of Switch: '<S255>/Switch' */
          }

          /* End of Switch: '<S255>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S256>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_i5[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_i5[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S266>/Sum of Elements' incorporates:
           *  Math: '<S266>/Math Function'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

          /* Math: '<S266>/Math Function1' incorporates:
           *  Sum: '<S266>/Sum of Elements'
           *
           * About '<S266>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Saturation_e = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S266>/Math Function1' */

          /* Switch: '<S266>/Switch' incorporates:
           *  Constant: '<S266>/Constant'
           *  Product: '<S266>/Product'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_Switch_an[0] = rtb_Subtract_hb[0];
            rtb_Switch_an[1] = rtb_Subtract_hb[1];
            rtb_Switch_an[2] = rtb_Saturation_e;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S266>/Switch' */

          /* Product: '<S265>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S268>/Sum of Elements' incorporates:
           *  Math: '<S268>/Math Function'
           *  SignalConversion: '<S268>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S268>/Math Function1' incorporates:
           *  Sum: '<S268>/Sum of Elements'
           *
           * About '<S268>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Saturation_e = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S268>/Math Function1' */

          /* Switch: '<S268>/Switch' incorporates:
           *  Constant: '<S268>/Constant'
           *  Product: '<S268>/Product'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_Switch_c2[0] = rtb_Subtract_hb[1];
            rtb_Switch_c2[1] = rtb_Subtract_hb[0];
            rtb_Switch_c2[2] = rtb_Saturation_e;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S268>/Switch' */

          /* Product: '<S266>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S269>/Sum of Elements' incorporates:
           *  Math: '<S269>/Math Function'
           *  SignalConversion: '<S269>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S269>/Math Function1' incorporates:
           *  Sum: '<S269>/Sum of Elements'
           *
           * About '<S269>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Saturation_e = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S269>/Math Function1' */

          /* Switch: '<S269>/Switch' incorporates:
           *  Constant: '<S269>/Constant'
           *  Product: '<S269>/Product'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_Switch_an[0] = rtb_Subtract_hb[1];
            rtb_Switch_an[1] = rtb_Subtract_hb[0];
            rtb_Switch_an[2] = rtb_Saturation_e;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S269>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S250>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_e = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_3 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S269>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S268>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S250>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_o = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S269>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S268>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S250>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S250>/Divide' incorporates:
           *  Math: '<S251>/Square'
           *  Math: '<S252>/Square'
           *  Sqrt: '<S251>/Sqrt'
           *  Sqrt: '<S252>/Sqrt'
           *  Sum: '<S250>/Sum'
           *  Sum: '<S250>/Sum1'
           *  Sum: '<S251>/Sum of Elements'
           *  Sum: '<S252>/Sum of Elements'
           */
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3
            + rtb_Saturation_e * rtb_Saturation_e) / sqrtf(rtb_Add4_o *
            rtb_Add4_o + rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2);

          /* Saturate: '<S250>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = 0.0F;
            }
          }

          /* End of Saturate: '<S250>/Saturation' */

          /* Sum: '<S267>/Subtract' incorporates:
           *  Product: '<S267>/Multiply'
           *  Product: '<S267>/Multiply1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Divide_i5[1] -
            rtb_Subtract_hb[1] * rtb_Divide_i5[0];

          /* Signum: '<S263>/Sign1' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S263>/Sign1' */

          /* Switch: '<S263>/Switch2' incorporates:
           *  Constant: '<S263>/Constant4'
           */
          if (rtb_Saturation_e == 0.0F) {
            rtb_Saturation_e = 1.0F;
          }

          /* End of Switch: '<S263>/Switch2' */

          /* DotProduct: '<S263>/Dot Product' */
          rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Subtract_hb[0] +
            rtb_Divide_i5[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S263>/Acos' incorporates:
           *  DotProduct: '<S263>/Dot Product'
           */
          if (rtb_Divide_pr_idx_0 > 1.0F) {
            rtb_Divide_pr_idx_0 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 < -1.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            }
          }

          /* Product: '<S263>/Multiply' incorporates:
           *  Trigonometry: '<S263>/Acos'
           */
          rtb_Saturation_e *= acosf(rtb_Divide_pr_idx_0);

          /* Saturate: '<S262>/Saturation' */
          if (rtb_Saturation_e > 1.57079637F) {
            rtb_Saturation_e = 1.57079637F;
          } else {
            if (rtb_Saturation_e < -1.57079637F) {
              rtb_Saturation_e = -1.57079637F;
            }
          }

          /* End of Saturate: '<S262>/Saturation' */

          /* BusAssignment: '<S227>/Bus Assignment1' incorporates:
           *  Constant: '<S227>/Constant2'
           *  Constant: '<S227>/Constant4'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S262>/Divide' incorporates:
           *  Constant: '<S253>/L1'
           *  Gain: '<S262>/Gain'
           *  Math: '<S262>/Square'
           *  Product: '<S262>/Multiply1'
           *  Trigonometry: '<S262>/Sin'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_e) / FMS_PARAM.FW_L1;

          /* Saturate: '<S253>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S227>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S227>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S227>/Bus Assignment1' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S253>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S248>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S250>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S248>/Sum2'
           *  Sum: '<S250>/Add'
           *  Sum: '<S250>/Subtract'
           */
          rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_pr_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S248>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S227>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S227>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S227>/Bus Assignment1' */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S248>/Saturation1' */
          /* End of Outputs for SubSystem: '<S88>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S88>/Hold' incorporates:
             *  ActionPort: '<S225>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S88>/Switch Case' incorporates:
             *  Delay: '<S230>/Delay'
             *  Delay: '<S235>/start_vel'
             */
            FMS_DW.icLoad_l = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S88>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S88>/Hold' incorporates:
           *  ActionPort: '<S225>/Action Port'
           */
          /* Math: '<S242>/Math Function1'
           *
           * About '<S242>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S242>/Math Function1' */

          /* Switch: '<S242>/Switch' incorporates:
           *  Constant: '<S242>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S242>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_an[0] = FMS_U.INS_Out.vn;
            rtb_Switch_an[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S242>/Switch' */

          /* Delay: '<S235>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_l != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE_l3[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE_l3[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S247>/Sum of Elements' incorporates:
           *  Delay: '<S235>/start_vel'
           *  Math: '<S247>/Math Function'
           */
          rtb_Saturation_e = FMS_DW.start_vel_DSTATE_l3[0] *
            FMS_DW.start_vel_DSTATE_l3[0] + FMS_DW.start_vel_DSTATE_l3[1] *
            FMS_DW.start_vel_DSTATE_l3[1];

          /* Math: '<S247>/Math Function1' incorporates:
           *  Sum: '<S247>/Sum of Elements'
           *
           * About '<S247>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S247>/Math Function1' */

          /* Switch: '<S247>/Switch' incorporates:
           *  Constant: '<S247>/Constant'
           *  Delay: '<S235>/start_vel'
           *  Product: '<S247>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_ee[0] = FMS_DW.start_vel_DSTATE_l3[0];
            rtb_Switch_ee[1] = FMS_DW.start_vel_DSTATE_l3[1];
            rtb_Switch_ee[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_ee[0] = 0.0F;
            rtb_Switch_ee[1] = 0.0F;
            rtb_Switch_ee[2] = 1.0F;
          }

          /* End of Switch: '<S247>/Switch' */

          /* Product: '<S242>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S245>/Sum of Elements' incorporates:
           *  Math: '<S245>/Math Function'
           *  SignalConversion: '<S245>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S245>/Math Function1' incorporates:
           *  Sum: '<S245>/Sum of Elements'
           *
           * About '<S245>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S245>/Math Function1' */

          /* Switch: '<S245>/Switch' incorporates:
           *  Constant: '<S245>/Constant'
           *  Product: '<S245>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_an[0] = rtb_Divide_i5[1];
            rtb_Switch_an[1] = rtb_Divide_i5[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S245>/Switch' */

          /* MinMax: '<S233>/Max' incorporates:
           *  Constant: '<S231>/L1'
           *  Constant: '<S231>/R'
           *  Gain: '<S233>/Gain'
           */
          rtb_Divide_pr_idx_1 = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S233>/SearchL1RefWP' incorporates:
           *  Constant: '<S231>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S238>/TmpSignal ConversionAt SFunction Inport2'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_P_cg[0] = 0.0F;
          rtb_P_cg[1] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          if ((FMS_U.INS_Out.x_R == FMS_B.Cmd_In.sp_waypoint[0]) &&
              (FMS_U.INS_Out.y_R == FMS_B.Cmd_In.sp_waypoint[1]) &&
              (rtb_Divide_pr_idx_1 == FMS_PARAM.FW_L1)) {
            rtb_n = 0;
          } else {
            rtb_Saturation_e = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
            rtb_Divide_lr_idx_3 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_U.INS_Out.y_R;
            d = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3 +
                      rtb_Saturation_e * rtb_Saturation_e);
            rtb_Divide_pr_idx_2 = FMS_PARAM.FW_L1 * FMS_PARAM.FW_L1;
            rtb_Divide_pr_idx_0 = ((d * d + rtb_Divide_pr_idx_2) -
              rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) / (2.0F * d);
            rtb_Square_ds[0] = rtb_Saturation_e / d;
            rtb_Divide_lr_idx_3 /= d;
            rtb_Saturation_e = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;
            if (rtb_Saturation_e > rtb_Divide_pr_idx_2) {
              rtb_n = 0;
            } else if (rtb_Saturation_e == rtb_Divide_pr_idx_2) {
              rtb_n = 1;
              rtb_P_cg[0] = rtb_Divide_pr_idx_0 * rtb_Square_ds[0] +
                FMS_U.INS_Out.x_R;
              rtb_P_cg[1] = rtb_Divide_pr_idx_0 * rtb_Divide_lr_idx_3 +
                FMS_U.INS_Out.y_R;
            } else {
              rtb_n = 2;
              rtb_Saturation_e = sqrtf(rtb_Divide_pr_idx_2 - rtb_Saturation_e);
              rtb_P_cg[0] = (rtb_Divide_pr_idx_0 * rtb_Square_ds[0] +
                             FMS_U.INS_Out.x_R) + rtb_Saturation_e *
                -rtb_Divide_lr_idx_3;
              rtb_P_cg[1] = (rtb_Divide_pr_idx_0 * rtb_Divide_lr_idx_3 +
                             FMS_U.INS_Out.y_R) + rtb_Saturation_e *
                rtb_Square_ds[0];
            }
          }

          /* End of MATLAB Function: '<S233>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S236>/Compare' incorporates:
           *  Constant: '<S236>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S233>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_e = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Subtract_hb[0] = rtb_Saturation_e * rtb_Saturation_e;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Saturation_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Subtract_hb[1] = rtb_Saturation_e * rtb_Saturation_e;

          /* Switch: '<S233>/Switch' incorporates:
           *  Constant: '<S231>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S233>/OutRegionRegWP'
           *  Product: '<S247>/Divide'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation_e = rtb_P_cg[0];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] >
                     rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S233>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_e = rtb_Switch_ee[0] / rtb_Switch_ee[2] *
              FMS_PARAM.FW_L1 + FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S234>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Square_ds[0] = rtb_Saturation_e - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S233>/Switch' incorporates:
           *  Constant: '<S231>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S233>/OutRegionRegWP'
           *  Product: '<S247>/Divide'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation_e = rtb_P_cg[1];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] >
                     rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S233>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Saturation_e = rtb_Switch_ee[1] / rtb_Switch_ee[2] *
              FMS_PARAM.FW_L1 + FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S234>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Square_ds[1] = rtb_Saturation_e - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S243>/Sum of Elements' incorporates:
           *  Math: '<S243>/Math Function'
           */
          rtb_Saturation_e = rtb_Square_ds[0] * rtb_Square_ds[0] +
            rtb_Square_ds[1] * rtb_Square_ds[1];

          /* Math: '<S243>/Math Function1' incorporates:
           *  Sum: '<S243>/Sum of Elements'
           *
           * About '<S243>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S243>/Math Function1' */

          /* Switch: '<S243>/Switch' incorporates:
           *  Constant: '<S243>/Constant'
           *  Product: '<S243>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_ee[0] = rtb_Square_ds[0];
            rtb_Switch_ee[1] = rtb_Square_ds[1];
            rtb_Switch_ee[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_ee[0] = 0.0F;
            rtb_Switch_ee[1] = 0.0F;
            rtb_Switch_ee[2] = 1.0F;
          }

          /* End of Switch: '<S243>/Switch' */

          /* Product: '<S243>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_ee[0] / rtb_Switch_ee[2];
          rtb_Divide_i5[1] = rtb_Switch_ee[1] / rtb_Switch_ee[2];

          /* Sum: '<S246>/Sum of Elements' incorporates:
           *  Math: '<S246>/Math Function'
           *  SignalConversion: '<S246>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S246>/Math Function1' incorporates:
           *  Sum: '<S246>/Sum of Elements'
           *
           * About '<S246>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S246>/Math Function1' */

          /* Switch: '<S246>/Switch' incorporates:
           *  Constant: '<S246>/Constant'
           *  Product: '<S246>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_ee[0] = rtb_Divide_i5[1];
            rtb_Switch_ee[1] = rtb_Divide_i5[0];
            rtb_Switch_ee[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_ee[0] = 0.0F;
            rtb_Switch_ee[1] = 0.0F;
            rtb_Switch_ee[2] = 1.0F;
          }

          /* End of Switch: '<S246>/Switch' */

          /* Product: '<S246>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_ee[0] / rtb_Switch_ee[2];

          /* Product: '<S245>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S246>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_ee[1] / rtb_Switch_ee[2];

          /* Product: '<S245>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S244>/Subtract' incorporates:
           *  Product: '<S244>/Multiply'
           *  Product: '<S244>/Multiply1'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_i5[0] * rtb_Subtract_hb[1] -
            rtb_Divide_i5[1] * rtb_Subtract_hb[0];

          /* Signum: '<S240>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S240>/Sign1' */

          /* Switch: '<S240>/Switch2' incorporates:
           *  Constant: '<S240>/Constant4'
           */
          if (rtb_Divide_pr_idx_1 == 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          }

          /* End of Switch: '<S240>/Switch2' */

          /* DotProduct: '<S240>/Dot Product' */
          rtb_Divide_pr_idx_2 = rtb_Subtract_hb[0] * rtb_Divide_i5[0] +
            rtb_Subtract_hb[1] * rtb_Divide_i5[1];

          /* Trigonometry: '<S240>/Acos' incorporates:
           *  DotProduct: '<S240>/Dot Product'
           */
          if (rtb_Divide_pr_idx_2 > 1.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            }
          }

          /* Product: '<S240>/Multiply' incorporates:
           *  Trigonometry: '<S240>/Acos'
           */
          rtb_Divide_pr_idx_1 *= acosf(rtb_Divide_pr_idx_2);

          /* Saturate: '<S239>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.57079637F) {
            rtb_Divide_pr_idx_1 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_1 < -1.57079637F) {
              rtb_Divide_pr_idx_1 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S239>/Saturation' */

          /* Delay: '<S230>/Delay' incorporates:
           *  Gain: '<S232>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* BusAssignment: '<S225>/Bus Assignment' incorporates:
           *  Constant: '<S225>/Constant'
           *  Constant: '<S225>/Constant3'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S239>/Divide' incorporates:
           *  Constant: '<S231>/L1'
           *  Gain: '<S239>/Gain'
           *  Math: '<S239>/Square'
           *  Product: '<S239>/Multiply1'
           *  Trigonometry: '<S239>/Sin'
           */
          rtb_Saturation_e = 2.0F * (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2) *
            arm_sin_f32(rtb_Divide_pr_idx_1) / FMS_PARAM.FW_L1;

          /* Saturate: '<S231>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S225>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S225>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S225>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S231>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S230>/Gain2' incorporates:
           *  Delay: '<S230>/Delay'
           *  Gain: '<S232>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S230>/Sum'
           */
          rtb_Saturation_e = (FMS_DW.Delay_DSTATE_nc - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S230>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S225>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S225>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S225>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S230>/Saturation1' */

          /* Update for Delay: '<S235>/start_vel' */
          FMS_DW.icLoad_l = 0U;

          /* Update for Delay: '<S230>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S88>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S88>/Unknown' incorporates:
           *  ActionPort: '<S229>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_j);

          /* End of Outputs for SubSystem: '<S88>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S46>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S46>/Auto' incorporates:
         *  ActionPort: '<S86>/Action Port'
         */
        /* SwitchCase: '<S86>/Switch Case' incorporates:
         *  RelationalOperator: '<S196>/FixPt Relational Operator'
         *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S196>/Delay Input1'
         *
         * Block description for '<S196>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_hd;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        switch (FMS_B.state) {
         case VehicleState_Offboard:
          FMS_DW.SwitchCase_ActiveSubsystem_hd = 0;
          break;

         case VehicleState_Mission:
          FMS_DW.SwitchCase_ActiveSubsystem_hd = 1;
          break;

         default:
          FMS_DW.SwitchCase_ActiveSubsystem_hd = 2;
          break;
        }

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_hd) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S86>/Offboard' incorporates:
           *  ActionPort: '<S194>/Action Port'
           */
          /* BusAssignment: '<S194>/Bus Assignment' incorporates:
           *  Constant: '<S194>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f1;

          /* End of Outputs for SubSystem: '<S86>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_hd != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S86>/Mission' incorporates:
             *  ActionPort: '<S193>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S86>/Switch Case' incorporates:
             *  UnitDelay: '<S196>/Delay Input1'
             *
             * Block description for '<S196>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S86>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S86>/Mission' incorporates:
           *  ActionPort: '<S193>/Action Port'
           */
          /* Outputs for Resettable SubSystem: '<S193>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S197>/Reset'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = (ZCSigState)
            (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S216>/Math Function' incorporates:
           *  RelationalOperator: '<S196>/FixPt Relational Operator'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S196>/Delay Input1'
           *
           * Block description for '<S196>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Subtract_hb[0] = rtb_Add4_o;
          rtb_Subtract_hb[1] = rtb_Divide_or;

          /* Sum: '<S216>/Sum of Elements' */
          rtb_Saturation_e = rtb_Add4_o + rtb_Divide_or;

          /* Math: '<S216>/Math Function1' incorporates:
           *  Sum: '<S216>/Sum of Elements'
           *
           * About '<S216>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S216>/Math Function1' */

          /* Switch: '<S216>/Switch' incorporates:
           *  Constant: '<S216>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S216>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S216>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S206>/NearbyRefWP' incorporates:
           *  Constant: '<S204>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Divide_pr_idx_1);

          /* MATLAB Function: '<S206>/SearchL1RefWP' incorporates:
           *  Constant: '<S204>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_i5, &rtb_Saturation_e);

          /* MATLAB Function: '<S206>/OutRegionRegWP' incorporates:
           *  Constant: '<S204>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_cg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S206>/Switch1' incorporates:
           *  Constant: '<S209>/Constant'
           *  RelationalOperator: '<S209>/Compare'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Divide_i5[0] = rtb_Subtract_hb[0];
            rtb_Divide_i5[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S208>/Compare' incorporates:
             *  Constant: '<S208>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_e >= 0.0F);

            /* Switch: '<S206>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_i5[0] = rtb_P_cg[0];
              rtb_Divide_i5[1] = rtb_P_cg[1];
            }

            /* End of Switch: '<S206>/Switch' */
          }

          /* End of Switch: '<S206>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S207>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_i5[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_i5[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S217>/Sum of Elements' incorporates:
           *  Math: '<S217>/Math Function'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

          /* Math: '<S217>/Math Function1' incorporates:
           *  Sum: '<S217>/Sum of Elements'
           *
           * About '<S217>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S217>/Math Function1' */

          /* Switch: '<S217>/Switch' incorporates:
           *  Constant: '<S217>/Constant'
           *  Product: '<S217>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_an[0] = rtb_Subtract_hb[0];
            rtb_Switch_an[1] = rtb_Subtract_hb[1];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S217>/Switch' */

          /* Product: '<S216>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S219>/Sum of Elements' incorporates:
           *  Math: '<S219>/Math Function'
           *  SignalConversion: '<S219>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S219>/Math Function1' incorporates:
           *  Sum: '<S219>/Sum of Elements'
           *
           * About '<S219>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S219>/Math Function1' */

          /* Switch: '<S219>/Switch' incorporates:
           *  Constant: '<S219>/Constant'
           *  Product: '<S219>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Subtract_hb[1];
            rtb_Switch_c2[1] = rtb_Subtract_hb[0];
            rtb_Switch_c2[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S219>/Switch' */

          /* Product: '<S217>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S220>/Sum of Elements' incorporates:
           *  Math: '<S220>/Math Function'
           *  SignalConversion: '<S220>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S220>/Math Function1' incorporates:
           *  Sum: '<S220>/Sum of Elements'
           *
           * About '<S220>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S220>/Math Function1' */

          /* Switch: '<S220>/Switch' incorporates:
           *  Constant: '<S220>/Constant'
           *  Product: '<S220>/Product'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Switch_an[0] = rtb_Subtract_hb[1];
            rtb_Switch_an[1] = rtb_Subtract_hb[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S220>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S201>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_e = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_3 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S220>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S219>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S201>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Add4_o = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S220>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S219>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S201>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S201>/Divide' incorporates:
           *  Math: '<S202>/Square'
           *  Math: '<S203>/Square'
           *  Sqrt: '<S202>/Sqrt'
           *  Sqrt: '<S203>/Sqrt'
           *  Sum: '<S201>/Sum'
           *  Sum: '<S201>/Sum1'
           *  Sum: '<S202>/Sum of Elements'
           *  Sum: '<S203>/Sum of Elements'
           */
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3
            + rtb_Saturation_e * rtb_Saturation_e) / sqrtf(rtb_Add4_o *
            rtb_Add4_o + rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2);

          /* Saturate: '<S201>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = 0.0F;
            }
          }

          /* End of Saturate: '<S201>/Saturation' */

          /* Sum: '<S218>/Subtract' incorporates:
           *  Product: '<S218>/Multiply'
           *  Product: '<S218>/Multiply1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Divide_i5[1] -
            rtb_Subtract_hb[1] * rtb_Divide_i5[0];

          /* Signum: '<S214>/Sign1' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S214>/Sign1' */

          /* Switch: '<S214>/Switch2' incorporates:
           *  Constant: '<S214>/Constant4'
           */
          if (rtb_Saturation_e == 0.0F) {
            rtb_Saturation_e = 1.0F;
          }

          /* End of Switch: '<S214>/Switch2' */

          /* DotProduct: '<S214>/Dot Product' */
          rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Subtract_hb[0] +
            rtb_Divide_i5[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S214>/Acos' incorporates:
           *  DotProduct: '<S214>/Dot Product'
           */
          if (rtb_Divide_pr_idx_0 > 1.0F) {
            rtb_Divide_pr_idx_0 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 < -1.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            }
          }

          /* Product: '<S214>/Multiply' incorporates:
           *  Trigonometry: '<S214>/Acos'
           */
          rtb_Saturation_e *= acosf(rtb_Divide_pr_idx_0);

          /* Saturate: '<S213>/Saturation' */
          if (rtb_Saturation_e > 1.57079637F) {
            rtb_Saturation_e = 1.57079637F;
          } else {
            if (rtb_Saturation_e < -1.57079637F) {
              rtb_Saturation_e = -1.57079637F;
            }
          }

          /* End of Saturate: '<S213>/Saturation' */

          /* BusAssignment: '<S197>/Bus Assignment' incorporates:
           *  Constant: '<S197>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S199>/Switch' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            /* BusAssignment: '<S197>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Cmd_In.set_speed;
          } else {
            /* BusAssignment: '<S197>/Bus Assignment' incorporates:
             *  Constant: '<S199>/Constant4'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S199>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S213>/Divide' incorporates:
           *  Constant: '<S204>/L1'
           *  Gain: '<S213>/Gain'
           *  Math: '<S213>/Square'
           *  Product: '<S213>/Multiply1'
           *  Trigonometry: '<S213>/Sin'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_e) / FMS_PARAM.FW_L1;

          /* Saturate: '<S204>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S197>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S197>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S197>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S204>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S198>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S201>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S198>/Sum2'
           *  Sum: '<S201>/Add'
           *  Sum: '<S201>/Subtract'
           */
          rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_pr_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S198>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S197>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S197>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S197>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S198>/Saturation1' */
          /* End of Outputs for SubSystem: '<S193>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S196>/Delay Input1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S196>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S86>/Unknown' incorporates:
           *  ActionPort: '<S195>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_n);

          /* End of Outputs for SubSystem: '<S86>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S46>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S46>/Assist' incorporates:
         *  ActionPort: '<S85>/Action Port'
         */
        /* SwitchCase: '<S85>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_a;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_a) {
          switch (rtPrevAction) {
           case 0:
           case 3:
            break;

           case 1:
            /* Disable for SwitchCase: '<S98>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S133>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S119>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S85>/Stabilize' incorporates:
             *  ActionPort: '<S92>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S85>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S186>/Integrator'
             *  DiscreteIntegrator: '<S186>/Integrator1'
             *  DiscreteIntegrator: '<S187>/Integrator'
             *  DiscreteIntegrator: '<S187>/Integrator1'
             *  DiscreteIntegrator: '<S191>/Integrator'
             *  DiscreteIntegrator: '<S191>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator1_DSTATE_mx = 0.0F;
            FMS_DW.Integrator_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S85>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S85>/Stabilize' incorporates:
           *  ActionPort: '<S92>/Action Port'
           */
          /* Product: '<S188>/Multiply1' incorporates:
           *  Constant: '<S188>/const1'
           *  DiscreteIntegrator: '<S186>/Integrator'
           */
          d = FMS_DW.Integrator_DSTATE_a * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S184>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S184>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S188>/Add' incorporates:
           *  DiscreteIntegrator: '<S186>/Integrator1'
           *  Gain: '<S181>/Gain'
           *  Gain: '<S184>/Gain'
           *  Sum: '<S186>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.FW_ROLL_LIM) + d;

          /* Signum: '<S188>/Sign' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S188>/Sign' */

          /* Sum: '<S188>/Add2' incorporates:
           *  Abs: '<S188>/Abs'
           *  Gain: '<S188>/Gain'
           *  Gain: '<S188>/Gain1'
           *  Product: '<S188>/Multiply2'
           *  Product: '<S188>/Multiply3'
           *  Sqrt: '<S188>/Sqrt'
           *  Sum: '<S188>/Add1'
           *  Sum: '<S188>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) +
            FMS_ConstB.d_ny) * FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Divide_pr_idx_1 + d;

          /* Sum: '<S188>/Add4' */
          rtb_Saturation_e = (rtb_Divide_lr_idx_2 - rtb_Divide_lr_idx_3) + d;

          /* Sum: '<S188>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_ny;

          /* Sum: '<S188>/Subtract1' */
          rtb_Divide_lr_idx_2 -= FMS_ConstB.d_ny;

          /* Signum: '<S188>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S188>/Sign1' */

          /* Signum: '<S188>/Sign2' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S188>/Sign2' */

          /* Sum: '<S188>/Add5' incorporates:
           *  Gain: '<S188>/Gain2'
           *  Product: '<S188>/Multiply4'
           *  Sum: '<S188>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) *
            0.5F * rtb_Saturation_e;

          /* BusAssignment: '<S92>/Bus Assignment' incorporates:
           *  Constant: '<S92>/Constant'
           *  DiscreteIntegrator: '<S186>/Integrator1'
           *  DiscreteIntegrator: '<S187>/Integrator1'
           *  DiscreteIntegrator: '<S191>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_mx;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S183>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S183>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S92>/Bus Assignment' incorporates:
           *  Constant: '<S183>/Constant5'
           *  Gain: '<S183>/Gain2'
           *  Sum: '<S183>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_Saturation_e), 65536.0F) + 1000U);

          /* Product: '<S192>/Multiply1' incorporates:
           *  Constant: '<S192>/const1'
           *  DiscreteIntegrator: '<S191>/Integrator'
           */
          d = FMS_DW.Integrator_DSTATE_g * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S190>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S190>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S192>/Add' incorporates:
           *  DiscreteIntegrator: '<S191>/Integrator1'
           *  Gain: '<S182>/Gain1'
           *  Gain: '<S190>/Gain'
           *  Sum: '<S191>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_mx - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation_e * FMS_PARAM.FW_YAW_RATE_LIM) +
            d;

          /* Signum: '<S192>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Add4_o = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Add4_o = rtb_Saturation_e;
          }

          /* End of Signum: '<S192>/Sign' */

          /* Sum: '<S192>/Add2' incorporates:
           *  Abs: '<S192>/Abs'
           *  Gain: '<S192>/Gain'
           *  Gain: '<S192>/Gain1'
           *  Product: '<S192>/Multiply2'
           *  Product: '<S192>/Multiply3'
           *  Sqrt: '<S192>/Sqrt'
           *  Sum: '<S192>/Add1'
           *  Sum: '<S192>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_hr) * FMS_ConstB.d_hr) - FMS_ConstB.d_hr) * 0.5F *
            rtb_Add4_o + d;

          /* Sum: '<S192>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) + d;

          /* Sum: '<S192>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_hr;

          /* Sum: '<S192>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_hr;

          /* Signum: '<S192>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S192>/Sign1' */

          /* Signum: '<S192>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S192>/Sign2' */

          /* Sum: '<S192>/Add5' incorporates:
           *  Gain: '<S192>/Gain2'
           *  Product: '<S192>/Multiply4'
           *  Sum: '<S192>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Sum: '<S192>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_hr;

          /* Sum: '<S192>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_hr;

          /* Product: '<S192>/Divide' */
          rtb_Divide_or = rtb_Divide_lr_idx_2 / FMS_ConstB.d_hr;

          /* Signum: '<S192>/Sign5' incorporates:
           *  Signum: '<S192>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Sign5_mn = -1.0F;

            /* Signum: '<S192>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Sign5_mn = 1.0F;

            /* Signum: '<S192>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_mn = rtb_Divide_lr_idx_2;

            /* Signum: '<S192>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S192>/Sign5' */

          /* Product: '<S189>/Multiply1' incorporates:
           *  Constant: '<S189>/const1'
           *  DiscreteIntegrator: '<S187>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S185>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S185>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S189>/Add' incorporates:
           *  DiscreteIntegrator: '<S187>/Integrator1'
           *  Gain: '<S181>/Gain1'
           *  Gain: '<S185>/Gain'
           *  Sum: '<S187>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.FW_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S189>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Add4_o = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Add4_o = rtb_Saturation_e;
          }

          /* End of Signum: '<S189>/Sign' */

          /* Sum: '<S189>/Add2' incorporates:
           *  Abs: '<S189>/Abs'
           *  Gain: '<S189>/Gain'
           *  Gain: '<S189>/Gain1'
           *  Product: '<S189>/Multiply2'
           *  Product: '<S189>/Multiply3'
           *  Sqrt: '<S189>/Sqrt'
           *  Sum: '<S189>/Add1'
           *  Sum: '<S189>/Subtract'
           */
          d = (sqrtf((8.0F * fabsf(rtb_Saturation_e) + FMS_ConstB.d_my) *
                     FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F * rtb_Add4_o +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S189>/Add4' */
          rtb_Add4_o = (rtb_Saturation_e - d) + rtb_Divide_lr_idx_2;

          /* Sum: '<S189>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_my;

          /* Sum: '<S189>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_my;

          /* Signum: '<S189>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S189>/Sign1' */

          /* Signum: '<S189>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S189>/Sign2' */

          /* Sum: '<S189>/Add5' incorporates:
           *  Gain: '<S189>/Gain2'
           *  Product: '<S189>/Multiply4'
           *  Sum: '<S189>/Subtract2'
           */
          d += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F * rtb_Add4_o;

          /* Update for DiscreteIntegrator: '<S186>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S186>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Sum: '<S188>/Subtract3' */
          rtb_Divide_lr_idx_2 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_ny;

          /* Sum: '<S188>/Add6' */
          rtb_Saturation_e = rtb_Divide_lr_idx_3 + FMS_ConstB.d_ny;

          /* Signum: '<S188>/Sign5' incorporates:
           *  Signum: '<S188>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S188>/Sign6' */
            rtb_MatrixConcatenate1_i_tmp_1 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S188>/Sign6' */
            rtb_MatrixConcatenate1_i_tmp_1 = 1.0F;
          } else {
            rtb_Add4_o = rtb_Divide_lr_idx_3;

            /* Signum: '<S188>/Sign6' */
            rtb_MatrixConcatenate1_i_tmp_1 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S188>/Sign5' */

          /* Signum: '<S188>/Sign3' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S188>/Sign3' */

          /* Signum: '<S188>/Sign4' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S188>/Sign4' */

          /* Update for DiscreteIntegrator: '<S186>/Integrator' incorporates:
           *  Constant: '<S188>/const'
           *  Gain: '<S188>/Gain3'
           *  Product: '<S188>/Divide'
           *  Product: '<S188>/Multiply5'
           *  Product: '<S188>/Multiply6'
           *  Sum: '<S188>/Subtract4'
           *  Sum: '<S188>/Subtract5'
           *  Sum: '<S188>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_ny
            - rtb_Add4_o) * FMS_ConstB.Gain4_ko * ((rtb_Saturation_e -
            rtb_Divide_lr_idx_2) * 0.5F) - rtb_MatrixConcatenate1_i_tmp_1 *
            12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S187>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S187>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S191>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S191>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mx += 0.004F * FMS_DW.Integrator_DSTATE_g;

          /* Signum: '<S192>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S192>/Sign3' */

          /* Signum: '<S192>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S192>/Sign4' */

          /* Update for DiscreteIntegrator: '<S191>/Integrator' incorporates:
           *  Constant: '<S192>/const'
           *  Gain: '<S192>/Gain3'
           *  Product: '<S192>/Multiply5'
           *  Product: '<S192>/Multiply6'
           *  Sum: '<S192>/Subtract4'
           *  Sum: '<S192>/Subtract5'
           *  Sum: '<S192>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_g += ((rtb_Divide_or - rtb_Sign5_mn) *
            FMS_ConstB.Gain4_n * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
            0.5F) - rtb_Divide_pr_idx_2 * 15.707963F) * 0.004F;

          /* Sum: '<S189>/Subtract3' */
          rtb_Divide_pr_idx_1 = d - FMS_ConstB.d_my;

          /* Sum: '<S189>/Add6' */
          rtb_Divide_pr_idx_0 = d + FMS_ConstB.d_my;

          /* Signum: '<S189>/Sign5' incorporates:
           *  Signum: '<S189>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S189>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S189>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = d;

            /* Signum: '<S189>/Sign6' */
            rtb_Add4_o = d;
          }

          /* End of Signum: '<S189>/Sign5' */

          /* Signum: '<S189>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S189>/Sign3' */

          /* Signum: '<S189>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S189>/Sign4' */

          /* Update for DiscreteIntegrator: '<S187>/Integrator' incorporates:
           *  Constant: '<S189>/const'
           *  Gain: '<S189>/Gain3'
           *  Product: '<S189>/Divide'
           *  Product: '<S189>/Multiply5'
           *  Product: '<S189>/Multiply6'
           *  Sum: '<S189>/Subtract4'
           *  Sum: '<S189>/Subtract5'
           *  Sum: '<S189>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((d / FMS_ConstB.d_my -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_k2 * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S85>/Stabilize' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S85>/Altitude' incorporates:
             *  ActionPort: '<S90>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S85>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S110>/Integrator'
             *  DiscreteIntegrator: '<S110>/Integrator1'
             *  DiscreteIntegrator: '<S113>/Integrator'
             *  DiscreteIntegrator: '<S113>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator1_DSTATE_gw = 0.0F;
            FMS_DW.Integrator_DSTATE_e = 0.0F;
            FMS_DW.Integrator_DSTATE_i3 = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S85>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S85>/Altitude' incorporates:
             *  ActionPort: '<S90>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S85>/Switch Case' incorporates:
             *  Chart: '<S99>/Motion Status'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

            /* End of SystemReset for SubSystem: '<S85>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S85>/Altitude' incorporates:
           *  ActionPort: '<S90>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S99>/Motion Status' incorporates:
           *  Abs: '<S99>/Abs'
           *  Abs: '<S99>/Abs1'
           *  Constant: '<S107>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S107>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S98>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l3;
          FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;
          switch (rtb_state_l4) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_l3 = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_l3) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l3 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S98>/Hold Control' incorporates:
               *  ActionPort: '<S101>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S98>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl);

              /* End of SystemReset for SubSystem: '<S98>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S98>/Hold Control' incorporates:
             *  ActionPort: '<S101>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_j,
                            &FMS_DW.HoldControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S98>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S98>/Brake Control' incorporates:
             *  ActionPort: '<S100>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_j);

            /* End of Outputs for SubSystem: '<S98>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l3 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S98>/Move Control' incorporates:
               *  ActionPort: '<S102>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S98>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl);

              /* End of SystemReset for SubSystem: '<S98>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S98>/Move Control' incorporates:
             *  ActionPort: '<S102>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_j,
                            &FMS_ConstB.MoveControl, &FMS_DW.MoveControl);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S98>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S98>/Switch Case' */

          /* BusAssignment: '<S90>/Bus Assignment' incorporates:
           *  Constant: '<S90>/Constant'
           *  DiscreteIntegrator: '<S110>/Integrator1'
           *  DiscreteIntegrator: '<S113>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_ih;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_c;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_lj;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_gw;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S94>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.0F) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S94>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S90>/Bus Assignment' incorporates:
           *  Gain: '<S94>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Saturation_e;

          /* Saturate: '<S98>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S90>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S90>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S90>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S98>/Saturation1' */

          /* Product: '<S114>/Multiply1' incorporates:
           *  Constant: '<S114>/const1'
           *  DiscreteIntegrator: '<S113>/Integrator'
           */
          rtb_Divide_lr_idx_3 = FMS_DW.Integrator_DSTATE_e * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S112>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S112>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S114>/Add' incorporates:
           *  DiscreteIntegrator: '<S113>/Integrator1'
           *  Gain: '<S112>/Gain'
           *  Gain: '<S97>/Gain1'
           *  Sum: '<S113>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_gw - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation_e * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_lr_idx_3;

          /* Signum: '<S114>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Saturation_e;
          }

          /* End of Signum: '<S114>/Sign' */

          /* Sum: '<S114>/Add2' incorporates:
           *  Abs: '<S114>/Abs'
           *  Gain: '<S114>/Gain'
           *  Gain: '<S114>/Gain1'
           *  Product: '<S114>/Multiply2'
           *  Product: '<S114>/Multiply3'
           *  Sqrt: '<S114>/Sqrt'
           *  Sum: '<S114>/Add1'
           *  Sum: '<S114>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_nt) * FMS_ConstB.d_nt) - FMS_ConstB.d_nt) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_lr_idx_3;

          /* Sum: '<S114>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_lr_idx_3;

          /* Sum: '<S114>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_nt;

          /* Sum: '<S114>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_nt;

          /* Signum: '<S114>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S114>/Sign1' */

          /* Signum: '<S114>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S114>/Sign2' */

          /* Sum: '<S114>/Add5' incorporates:
           *  Gain: '<S114>/Gain2'
           *  Product: '<S114>/Multiply4'
           *  Sum: '<S114>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Sum: '<S114>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_nt;

          /* Sum: '<S114>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_nt;

          /* Product: '<S114>/Divide' */
          d = rtb_Divide_lr_idx_2 / FMS_ConstB.d_nt;

          /* Signum: '<S114>/Sign5' incorporates:
           *  Signum: '<S114>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S114>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S114>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Add4_o = rtb_Divide_lr_idx_2;

            /* Signum: '<S114>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S114>/Sign5' */

          /* Product: '<S111>/Multiply1' incorporates:
           *  Constant: '<S111>/const1'
           *  DiscreteIntegrator: '<S110>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S109>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S109>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S111>/Add' incorporates:
           *  DiscreteIntegrator: '<S110>/Integrator1'
           *  Gain: '<S109>/Gain'
           *  Gain: '<S96>/Gain'
           *  Sum: '<S110>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.FW_ROLL_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S111>/Sign' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            rtb_Saturation_e = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S111>/Sign' */

          /* Sum: '<S111>/Add2' incorporates:
           *  Abs: '<S111>/Abs'
           *  Gain: '<S111>/Gain'
           *  Gain: '<S111>/Gain1'
           *  Product: '<S111>/Multiply2'
           *  Product: '<S111>/Multiply3'
           *  Sqrt: '<S111>/Sqrt'
           *  Sum: '<S111>/Add1'
           *  Sum: '<S111>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_3) +
            FMS_ConstB.d_bi) * FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F *
            rtb_Saturation_e + rtb_Divide_lr_idx_2;

          /* Sum: '<S111>/Add4' */
          rtb_Divide_or = (rtb_Divide_lr_idx_3 - rtb_Saturation_e) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S111>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_bi;

          /* Sum: '<S111>/Subtract1' */
          rtb_Divide_lr_idx_3 -= FMS_ConstB.d_bi;

          /* Signum: '<S111>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S111>/Sign1' */

          /* Signum: '<S111>/Sign2' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S111>/Sign2' */

          /* Sum: '<S111>/Add5' incorporates:
           *  Gain: '<S111>/Gain2'
           *  Product: '<S111>/Multiply4'
           *  Sum: '<S111>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_lr_idx_2 - rtb_Divide_lr_idx_3) * 0.5F
            * rtb_Divide_or;

          /* Update for DiscreteIntegrator: '<S110>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S110>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Update for DiscreteIntegrator: '<S113>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S113>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_gw += 0.004F * FMS_DW.Integrator_DSTATE_e;

          /* Signum: '<S114>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S114>/Sign3' */

          /* Signum: '<S114>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S114>/Sign4' */

          /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
           *  Constant: '<S114>/const'
           *  Gain: '<S114>/Gain3'
           *  Product: '<S114>/Multiply5'
           *  Product: '<S114>/Multiply6'
           *  Sum: '<S114>/Subtract4'
           *  Sum: '<S114>/Subtract5'
           *  Sum: '<S114>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_e += ((d - rtb_Add4_o) * FMS_ConstB.Gain4_kf *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 15.707963F) * 0.004F;

          /* Sum: '<S111>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_bi;

          /* Sum: '<S111>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_bi;

          /* Signum: '<S111>/Sign5' incorporates:
           *  Signum: '<S111>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S111>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S111>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;

            /* Signum: '<S111>/Sign6' */
            rtb_Add4_o = rtb_Saturation_e;
          }

          /* End of Signum: '<S111>/Sign5' */

          /* Signum: '<S111>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S111>/Sign3' */

          /* Signum: '<S111>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S111>/Sign4' */

          /* Update for DiscreteIntegrator: '<S110>/Integrator' incorporates:
           *  Constant: '<S111>/const'
           *  Gain: '<S111>/Gain3'
           *  Product: '<S111>/Divide'
           *  Product: '<S111>/Multiply5'
           *  Product: '<S111>/Multiply6'
           *  Sum: '<S111>/Subtract4'
           *  Sum: '<S111>/Subtract5'
           *  Sum: '<S111>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_Saturation_e / FMS_ConstB.d_bi -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_d1 * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S85>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S85>/Position' incorporates:
             *  ActionPort: '<S91>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S85>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S131>/Integrator'
             *  DiscreteIntegrator: '<S131>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_l = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S85>/Position' */

            /* SystemReset for IfAction SubSystem: '<S85>/Position' incorporates:
             *  ActionPort: '<S91>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S85>/Switch Case' incorporates:
             *  Chart: '<S120>/Motion Status'
             *  Chart: '<S134>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_m);
            FMS_DW.temporalCounter_i1_i = 0U;
            FMS_DW.is_active_c26_FMS = 0U;
            FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S85>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S85>/Position' incorporates:
           *  ActionPort: '<S91>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S120>/Motion Status' incorporates:
           *  Abs: '<S120>/Abs'
           *  Abs: '<S120>/Abs1'
           *  Constant: '<S128>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S128>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_m);

          /* Logic: '<S134>/Logical Operator' incorporates:
           *  Abs: '<S134>/Abs1'
           *  Abs: '<S134>/Abs2'
           *  Constant: '<S176>/Constant'
           *  Constant: '<S177>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S176>/Compare'
           *  RelationalOperator: '<S177>/Compare'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_yaw) >
            FMS_PARAM.YAW_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S134>/Motion State' */
          if (FMS_DW.temporalCounter_i1_i < 1023U) {
            FMS_DW.temporalCounter_i1_i++;
          }

          if (FMS_DW.is_active_c26_FMS == 0U) {
            FMS_DW.is_active_c26_FMS = 1U;
            FMS_DW.is_c26_FMS = FMS_IN_Move_p;
            rtb_state_fg = MotionState_Move;
          } else {
            switch (FMS_DW.is_c26_FMS) {
             case FMS_IN_Brake_bw:
              rtb_state_fg = MotionState_Brake;
              if (FMS_DW.temporalCounter_i1_i >= 750U) {
                FMS_DW.is_c26_FMS = FMS_IN_Hold_od;
                rtb_state_fg = MotionState_Hold;
              } else {
                if (rtb_FixPtRelationalOperator_me) {
                  FMS_DW.is_c26_FMS = FMS_IN_Move_p;
                  rtb_state_fg = MotionState_Move;
                }
              }
              break;

             case FMS_IN_Hold_od:
              rtb_state_fg = MotionState_Hold;
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c26_FMS = FMS_IN_Move_p;
                rtb_state_fg = MotionState_Move;
              }
              break;

             default:
              rtb_state_fg = MotionState_Move;
              if (!rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c26_FMS = FMS_IN_Brake_bw;
                FMS_DW.temporalCounter_i1_i = 0U;
                rtb_state_fg = MotionState_Brake;
              }
              break;
            }
          }

          /* End of Chart: '<S134>/Motion State' */

          /* SwitchCase: '<S133>/Switch Case' */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_d;
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;
          switch (rtb_state_fg) {
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
              /* InitializeConditions for IfAction SubSystem: '<S133>/Hold Control' incorporates:
               *  ActionPort: '<S136>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S133>/Switch Case' incorporates:
               *  Delay: '<S141>/start_vel'
               *  Delay: '<S141>/start_wp'
               *  DiscreteIntegrator: '<S170>/Discrete-Time Integrator'
               *  DiscreteIntegrator: '<S172>/Discrete-Time Integrator1'
               */
              FMS_DW.icLoad_g = 1U;
              FMS_DW.icLoad_ef = 1U;
              FMS_DW.DiscreteTimeIntegrator_DSTATE_k = FMS_ConstB.Constant_a;
              if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
                FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
              } else {
                if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
                  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
                }
              }

              FMS_DW.DiscreteTimeIntegrator_PrevRe_d = 0;
              FMS_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
              FMS_DW.DiscreteTimeIntegrator1_PrevR_p = 0;

              /* End of InitializeConditions for SubSystem: '<S133>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S133>/Hold Control' incorporates:
             *  ActionPort: '<S136>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Product: '<S144>/Divide' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.quat[0] / d;
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.quat[1] / d;
            rtb_Divide_pr_idx_2 = FMS_U.INS_Out.quat[2] / d;
            rtb_Saturation_e = FMS_U.INS_Out.quat[3] / d;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S145>/Subtract' incorporates:
             *  Math: '<S145>/Square'
             *  Math: '<S145>/Square1'
             *  Math: '<S145>/Square2'
             *  Math: '<S145>/Square3'
             *  Sum: '<S145>/Add'
             *  Sum: '<S145>/Add1'
             */
            rtb_VectorConcatenate_ch[0] = (rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) -
              (rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2 + rtb_Saturation_e *
               rtb_Saturation_e);

            /* Gain: '<S145>/Gain' incorporates:
             *  Product: '<S145>/Multiply'
             *  Product: '<S145>/Multiply1'
             *  Sum: '<S145>/Subtract1'
             */
            rtb_VectorConcatenate_ch[1] = (rtb_Divide_pr_idx_1 *
              rtb_Divide_pr_idx_2 - rtb_Divide_pr_idx_0 * rtb_Saturation_e) *
              2.0F;

            /* Gain: '<S145>/Gain1' incorporates:
             *  Product: '<S145>/Multiply2'
             *  Product: '<S145>/Multiply3'
             *  Sum: '<S145>/Add2'
             */
            rtb_VectorConcatenate_ch[2] = (rtb_Divide_pr_idx_1 *
              rtb_Saturation_e + rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_2) *
              2.0F;

            /* Gain: '<S146>/Gain' incorporates:
             *  Product: '<S146>/Multiply'
             *  Product: '<S146>/Multiply1'
             *  Sum: '<S146>/Add3'
             */
            rtb_VectorConcatenate_ch[3] = (rtb_Divide_pr_idx_1 *
              rtb_Divide_pr_idx_2 + rtb_Divide_pr_idx_0 * rtb_Saturation_e) *
              2.0F;

            /* Sum: '<S146>/Subtract' incorporates:
             *  Math: '<S146>/Square'
             *  Math: '<S146>/Square1'
             *  Math: '<S146>/Square2'
             *  Math: '<S146>/Square3'
             *  Sum: '<S146>/Add'
             *  Sum: '<S146>/Add1'
             */
            rtb_VectorConcatenate_ch[4] = (rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2) -
              (rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 + rtb_Saturation_e *
               rtb_Saturation_e);

            /* Gain: '<S146>/Gain1' incorporates:
             *  Product: '<S146>/Multiply2'
             *  Product: '<S146>/Multiply3'
             *  Sum: '<S146>/Subtract1'
             */
            rtb_VectorConcatenate_ch[5] = (rtb_Divide_pr_idx_2 *
              rtb_Saturation_e - rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_1) *
              2.0F;

            /* Gain: '<S147>/Gain' incorporates:
             *  Product: '<S147>/Multiply'
             *  Product: '<S147>/Multiply1'
             *  Sum: '<S147>/Subtract2'
             */
            rtb_VectorConcatenate_ch[6] = (rtb_Divide_pr_idx_1 *
              rtb_Saturation_e - rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_2) *
              2.0F;

            /* Gain: '<S147>/Gain1' incorporates:
             *  Product: '<S147>/Multiply2'
             *  Product: '<S147>/Multiply3'
             *  Sum: '<S147>/Add2'
             */
            rtb_VectorConcatenate_ch[7] = (rtb_Divide_pr_idx_2 *
              rtb_Saturation_e + rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_1) *
              2.0F;

            /* Sum: '<S147>/Subtract' incorporates:
             *  Math: '<S147>/Square'
             *  Math: '<S147>/Square1'
             *  Math: '<S147>/Square2'
             *  Math: '<S147>/Square3'
             *  Sum: '<S147>/Add'
             *  Sum: '<S147>/Add1'
             */
            rtb_VectorConcatenate_ch[8] = (rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Saturation_e * rtb_Saturation_e) -
              (rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2 *
               rtb_Divide_pr_idx_2);

            /* Product: '<S138>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 6] *
                FMS_U.INS_Out.vd + (rtb_VectorConcatenate_ch[rtb_n + 3] *
                                    FMS_U.INS_Out.ve +
                                    rtb_VectorConcatenate_ch[rtb_n] *
                                    FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* End of Product: '<S138>/Multiply' */

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Trigonometry: '<S168>/Trigonometric Function1' incorporates:
             *  Gain: '<S167>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S168>/Trigonometric Function3'
             */
            rtb_Saturation_e = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_VectorConcatenate_ch[0] = rtb_Saturation_e;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Trigonometry: '<S168>/Trigonometric Function' incorporates:
             *  Gain: '<S167>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S168>/Trigonometric Function2'
             */
            rtb_Divide_pr_idx_2 = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_VectorConcatenate_ch[1] = rtb_Divide_pr_idx_2;

            /* SignalConversion: '<S168>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S168>/Constant3'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Gain: '<S168>/Gain' */
            rtb_VectorConcatenate_ch[3] = -rtb_Divide_pr_idx_2;

            /* Trigonometry: '<S168>/Trigonometric Function3' */
            rtb_VectorConcatenate_ch[4] = rtb_Saturation_e;

            /* SignalConversion: '<S168>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S168>/Constant4'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_lr[0];
            rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_lr[1];
            rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_lr[2];

            /* Delay: '<S141>/start_vel' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            if (FMS_DW.icLoad_g != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.start_vel_DSTATE_l[0] = FMS_U.INS_Out.vn;
              FMS_DW.start_vel_DSTATE_l[1] = FMS_U.INS_Out.ve;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Math: '<S162>/Math Function' incorporates:
             *  Delay: '<S141>/start_vel'
             */
            rtb_Subtract_hb[0] = FMS_DW.start_vel_DSTATE_l[0] *
              FMS_DW.start_vel_DSTATE_l[0];
            rtb_Subtract_hb[1] = FMS_DW.start_vel_DSTATE_l[1] *
              FMS_DW.start_vel_DSTATE_l[1];

            /* Sum: '<S162>/Sum of Elements' */
            rtb_Saturation_e = rtb_Subtract_hb[0] + rtb_Subtract_hb[1];

            /* Math: '<S162>/Math Function1' incorporates:
             *  Sum: '<S162>/Sum of Elements'
             *
             * About '<S162>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S162>/Math Function1' */

            /* Switch: '<S162>/Switch' incorporates:
             *  Constant: '<S162>/Constant'
             *  Delay: '<S141>/start_vel'
             *  Product: '<S162>/Product'
             */
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Switch_ee[0] = FMS_DW.start_vel_DSTATE_l[0];
              rtb_Switch_ee[1] = FMS_DW.start_vel_DSTATE_l[1];
              rtb_Switch_ee[2] = rtb_Divide_pr_idx_1;
            } else {
              rtb_Switch_ee[0] = 0.0F;
              rtb_Switch_ee[1] = 0.0F;
              rtb_Switch_ee[2] = 1.0F;
            }

            /* End of Switch: '<S162>/Switch' */

            /* Delay: '<S141>/start_wp' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            if (FMS_DW.icLoad_ef != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.start_wp_DSTATE_p[0] = FMS_U.INS_Out.x_R;
              FMS_DW.start_wp_DSTATE_p[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* End of Delay: '<S141>/start_wp' */

            /* Product: '<S162>/Divide' */
            rtb_Divide_i5[0] = rtb_Switch_ee[0] / rtb_Switch_ee[2];
            rtb_Divide_i5[1] = rtb_Switch_ee[1] / rtb_Switch_ee[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S139>/SearchL1RefWP' incorporates:
             *  Constant: '<S136>/L1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            FMS_SearchL1RefWP_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                                FMS_DW.start_wp_DSTATE_p, rtb_Divide_i5,
                                FMS_PARAM.FW_L1, rtb_Subtract_hb,
                                &rtb_Saturation_e);

            /* MATLAB Function: '<S139>/OutRegionRefWP' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            FMS_OutRegionRefWP(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               FMS_DW.start_wp_DSTATE_p, rtb_Divide_i5, rtb_P_dg);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S166>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_VectorConcatenate_fy[rtb_n] = rtb_VectorConcatenate_ch[rtb_n +
                3] * FMS_U.INS_Out.ve + rtb_VectorConcatenate_ch[rtb_n] *
                FMS_U.INS_Out.vn;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* End of Product: '<S166>/Multiply' */

            /* DiscreteIntegrator: '<S170>/Discrete-Time Integrator' */
            if (FMS_DW.DiscreteTimeIntegrator_PrevRe_d != 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_k = FMS_ConstB.Constant_a;
              if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
                FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
              } else {
                if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
                  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
                }
              }
            }

            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
            } else {
              if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
                FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
              }
            }

            /* DiscreteIntegrator: '<S172>/Discrete-Time Integrator1' incorporates:
             *  Constant: '<S164>/Constant'
             *  Sum: '<S164>/Sum'
             */
            if (FMS_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
              FMS_DW.DiscreteTimeIntegrator1_DSTA_jv = 0.0F -
                rtb_VectorConcatenate_fy[1];
            }

            if (FMS_DW.DiscreteTimeIntegrator1_PrevR_p != 0) {
              FMS_DW.DiscreteTimeIntegrator1_DSTA_jv = 0.0F -
                rtb_VectorConcatenate_fy[1];
            }

            /* Signum: '<S138>/Sign' incorporates:
             *  Math: '<S155>/Square'
             *  Math: '<S156>/Math Function1'
             *  Math: '<S157>/Math Function'
             *  Sum: '<S140>/Subtract'
             *  Switch: '<S136>/Switch'
             *  Switch: '<S139>/Switch'
             *
             * About '<S156>/Math Function1':
             *  Operator: sqrt
             */
            if ((rtb_Switch_an[0] < 0.0F) || (rtb_Switch_an[0] <= 0.0F)) {
              /* Switch: '<S136>/Switch' incorporates:
               *  Constant: '<S164>/Constant'
               *  Constant: '<S171>/kp'
               *  DiscreteIntegrator: '<S170>/Discrete-Time Integrator'
               *  Product: '<S171>/Multiply'
               *  Sum: '<S164>/Sum'
               *  Sum: '<S165>/Add'
               */
              FMS_B.Merge_be = (0.0F - rtb_VectorConcatenate_fy[1]) * 1.2F +
                FMS_DW.DiscreteTimeIntegrator_DSTATE_k;
            } else {
              if (rtb_Divide_lr_idx_3 < 0.0F) {
                /* Math: '<S156>/Math Function1' incorporates:
                 *  Switch: '<S136>/Switch'
                 *
                 * About '<S156>/Math Function1':
                 *  Operator: sqrt
                 */
                rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
              } else {
                /* Math: '<S156>/Math Function1' incorporates:
                 *  Switch: '<S136>/Switch'
                 *
                 * About '<S156>/Math Function1':
                 *  Operator: sqrt
                 */
                rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
              }

              /* Switch: '<S156>/Switch' incorporates:
               *  Constant: '<S156>/Constant'
               *  Inport: '<Root>/INS_Out'
               *  Product: '<S156>/Product'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Switch: '<S136>/Switch'
               */
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_Switch_an[0] = FMS_U.INS_Out.vn;
                rtb_Switch_an[1] = FMS_U.INS_Out.ve;

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
                rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
              } else {
                rtb_Switch_an[0] = 0.0F;
                rtb_Switch_an[1] = 0.0F;
                rtb_Switch_an[2] = 1.0F;
              }

              /* End of Switch: '<S156>/Switch' */

              /* Product: '<S156>/Divide' incorporates:
               *  Switch: '<S136>/Switch'
               */
              rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

              /* RelationalOperator: '<S149>/Compare' incorporates:
               *  Constant: '<S149>/Constant'
               *  Switch: '<S136>/Switch'
               */
              rtb_FixPtRelationalOperator_me = (rtb_Saturation_e > 0.0F);

              /* Switch: '<S139>/Switch' incorporates:
               *  Switch: '<S136>/Switch'
               */
              if (rtb_FixPtRelationalOperator_me) {
                rtb_Divide_pr_idx_1 = rtb_Subtract_hb[0];
              } else {
                rtb_Divide_pr_idx_1 = rtb_P_dg[0];
              }

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              /* Sum: '<S140>/Subtract' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Switch: '<S136>/Switch'
               */
              rtb_Divide_pr_idx_2 = rtb_Divide_pr_idx_1 - FMS_U.INS_Out.x_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              rtb_Subtract_hb[0] = rtb_Divide_pr_idx_2;
              rtb_Square_ds[0] = rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2;

              /* Switch: '<S139>/Switch' incorporates:
               *  Math: '<S157>/Math Function'
               *  Sum: '<S140>/Subtract'
               *  Switch: '<S136>/Switch'
               */
              if (rtb_FixPtRelationalOperator_me) {
                rtb_Divide_pr_idx_1 = rtb_Subtract_hb[1];
              } else {
                rtb_Divide_pr_idx_1 = rtb_P_dg[1];
              }

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              /* Sum: '<S140>/Subtract' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Switch: '<S136>/Switch'
               */
              rtb_Divide_pr_idx_2 = rtb_Divide_pr_idx_1 - FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

              /* Math: '<S157>/Math Function' incorporates:
               *  Math: '<S155>/Square'
               *  Switch: '<S136>/Switch'
               */
              rtb_Saturation_e = rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2;

              /* Sum: '<S157>/Sum of Elements' incorporates:
               *  Math: '<S157>/Math Function'
               *  Switch: '<S136>/Switch'
               */
              rtb_Divide_lr_idx_3 = rtb_Saturation_e + rtb_Square_ds[0];

              /* Math: '<S157>/Math Function1' incorporates:
               *  Sum: '<S157>/Sum of Elements'
               *  Switch: '<S136>/Switch'
               *
               * About '<S157>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_lr_idx_3 < 0.0F) {
                rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
              } else {
                rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
              }

              /* End of Math: '<S157>/Math Function1' */

              /* Switch: '<S157>/Switch' incorporates:
               *  Constant: '<S157>/Constant'
               *  Product: '<S157>/Product'
               *  Switch: '<S136>/Switch'
               */
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Switch_an[0] = rtb_Subtract_hb[0];
                rtb_Switch_an[1] = rtb_Divide_pr_idx_2;
                rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
              } else {
                rtb_Switch_an[0] = 0.0F;
                rtb_Switch_an[1] = 0.0F;
                rtb_Switch_an[2] = 1.0F;
              }

              /* End of Switch: '<S157>/Switch' */

              /* Product: '<S157>/Divide' incorporates:
               *  Switch: '<S136>/Switch'
               */
              rtb_Square_ds[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Subtract_hb[0] *= rtb_Subtract_hb[0];

              /* Product: '<S157>/Divide' incorporates:
               *  Math: '<S155>/Square'
               *  Switch: '<S136>/Switch'
               */
              rtb_Square_ds[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

              /* Sum: '<S159>/Sum of Elements' incorporates:
               *  Math: '<S159>/Math Function'
               *  SignalConversion: '<S159>/TmpSignal ConversionAtMath FunctionInport1'
               *  Switch: '<S136>/Switch'
               */
              rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
                rtb_Divide_i5[0] * rtb_Divide_i5[0];

              /* Math: '<S159>/Math Function1' incorporates:
               *  Sum: '<S159>/Sum of Elements'
               *  Switch: '<S136>/Switch'
               *
               * About '<S159>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_lr_idx_3 < 0.0F) {
                rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
              } else {
                rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
              }

              /* End of Math: '<S159>/Math Function1' */

              /* Switch: '<S159>/Switch' incorporates:
               *  Constant: '<S159>/Constant'
               *  Product: '<S159>/Product'
               *  Switch: '<S136>/Switch'
               */
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Switch_an[0] = rtb_Divide_i5[1];
                rtb_Switch_an[1] = rtb_Divide_i5[0];
                rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
              } else {
                rtb_Switch_an[0] = 0.0F;
                rtb_Switch_an[1] = 0.0F;
                rtb_Switch_an[2] = 1.0F;
              }

              /* End of Switch: '<S159>/Switch' */

              /* Product: '<S159>/Divide' incorporates:
               *  Switch: '<S136>/Switch'
               */
              rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

              /* Sum: '<S160>/Sum of Elements' incorporates:
               *  Math: '<S160>/Math Function'
               *  SignalConversion: '<S160>/TmpSignal ConversionAtMath FunctionInport1'
               *  Switch: '<S136>/Switch'
               */
              rtb_Divide_lr_idx_3 = rtb_Square_ds[1] * rtb_Square_ds[1] +
                rtb_Square_ds[0] * rtb_Square_ds[0];

              /* Math: '<S160>/Math Function1' incorporates:
               *  Sum: '<S160>/Sum of Elements'
               *  Switch: '<S136>/Switch'
               *
               * About '<S160>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_lr_idx_3 < 0.0F) {
                rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
              } else {
                rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
              }

              /* End of Math: '<S160>/Math Function1' */

              /* Switch: '<S160>/Switch' incorporates:
               *  Constant: '<S160>/Constant'
               *  Product: '<S160>/Product'
               *  Switch: '<S136>/Switch'
               */
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Switch_an[0] = rtb_Square_ds[1];
                rtb_Switch_an[1] = rtb_Square_ds[0];
                rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
              } else {
                rtb_Switch_an[0] = 0.0F;
                rtb_Switch_an[1] = 0.0F;
                rtb_Switch_an[2] = 1.0F;
              }

              /* End of Switch: '<S160>/Switch' */

              /* Product: '<S160>/Divide' incorporates:
               *  Switch: '<S136>/Switch'
               */
              rtb_Square_ds[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Square_ds[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

              /* Sum: '<S158>/Subtract' incorporates:
               *  Product: '<S158>/Multiply'
               *  Product: '<S158>/Multiply1'
               *  Switch: '<S136>/Switch'
               */
              rtb_Divide_pr_idx_1 = rtb_Square_ds[0] * rtb_Divide_i5[1] -
                rtb_Square_ds[1] * rtb_Divide_i5[0];

              /* Signum: '<S153>/Sign1' incorporates:
               *  Switch: '<S136>/Switch'
               */
              if (rtb_Divide_pr_idx_1 < 0.0F) {
                rtb_Divide_pr_idx_1 = -1.0F;
              } else {
                if (rtb_Divide_pr_idx_1 > 0.0F) {
                  rtb_Divide_pr_idx_1 = 1.0F;
                }
              }

              /* End of Signum: '<S153>/Sign1' */

              /* Switch: '<S153>/Switch2' incorporates:
               *  Constant: '<S153>/Constant4'
               *  Switch: '<S136>/Switch'
               */
              if (rtb_Divide_pr_idx_1 == 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }

              /* End of Switch: '<S153>/Switch2' */

              /* DotProduct: '<S153>/Dot Product' incorporates:
               *  Switch: '<S136>/Switch'
               */
              rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Square_ds[0] +
                rtb_Divide_i5[1] * rtb_Square_ds[1];

              /* Trigonometry: '<S153>/Acos' incorporates:
               *  DotProduct: '<S153>/Dot Product'
               *  Switch: '<S136>/Switch'
               */
              if (rtb_Divide_pr_idx_0 > 1.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              } else {
                if (rtb_Divide_pr_idx_0 < -1.0F) {
                  rtb_Divide_pr_idx_0 = -1.0F;
                }
              }

              /* Product: '<S153>/Multiply' incorporates:
               *  Switch: '<S136>/Switch'
               *  Trigonometry: '<S153>/Acos'
               */
              rtb_Divide_pr_idx_1 *= acosf(rtb_Divide_pr_idx_0);

              /* Saturate: '<S152>/Saturation' incorporates:
               *  Switch: '<S136>/Switch'
               */
              if (rtb_Divide_pr_idx_1 > 1.57079637F) {
                rtb_Divide_pr_idx_1 = 1.57079637F;
              } else {
                if (rtb_Divide_pr_idx_1 < -1.57079637F) {
                  rtb_Divide_pr_idx_1 = -1.57079637F;
                }
              }

              /* End of Saturate: '<S152>/Saturation' */

              /* Switch: '<S136>/Switch' incorporates:
               *  Constant: '<S136>/L1'
               *  Constant: '<S152>/Constant'
               *  Gain: '<S152>/Gain'
               *  Math: '<S152>/Square'
               *  MinMax: '<S152>/Max'
               *  MinMax: '<S152>/Min'
               *  Product: '<S152>/Divide'
               *  Product: '<S152>/Multiply1'
               *  Sqrt: '<S155>/Sqrt'
               *  Sum: '<S155>/Sum of Elements'
               *  Trigonometry: '<S152>/Sin'
               */
              FMS_B.Merge_be = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
                arm_sin_f32(rtb_Divide_pr_idx_1) / fminf(FMS_PARAM.FW_L1, fmaxf
                (sqrtf(rtb_Saturation_e + rtb_Subtract_hb[0]), 0.5F));
            }

            /* End of Signum: '<S138>/Sign' */

            /* Update for Delay: '<S141>/start_vel' */
            FMS_DW.icLoad_g = 0U;

            /* Update for Delay: '<S141>/start_wp' */
            FMS_DW.icLoad_ef = 0U;

            /* Update for DiscreteIntegrator: '<S170>/Discrete-Time Integrator' incorporates:
             *  Constant: '<S164>/Constant'
             *  Constant: '<S170>/ki'
             *  Product: '<S170>/Multiply'
             *  Sum: '<S164>/Sum'
             */
            FMS_DW.DiscreteTimeIntegrator_DSTATE_k += (0.0F -
              rtb_VectorConcatenate_fy[1]) * 0.5F * 0.004F;
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
            } else {
              if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
                FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
              }
            }

            FMS_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

            /* End of Update for DiscreteIntegrator: '<S170>/Discrete-Time Integrator' */

            /* Update for DiscreteIntegrator: '<S172>/Discrete-Time Integrator1' incorporates:
             *  Constant: '<S164>/Constant'
             *  Gain: '<S172>/Gain'
             *  Sum: '<S164>/Sum'
             *  Sum: '<S172>/Sum5'
             */
            FMS_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
            FMS_DW.DiscreteTimeIntegrator1_DSTA_jv += ((0.0F -
              rtb_VectorConcatenate_fy[1]) -
              FMS_DW.DiscreteTimeIntegrator1_DSTA_jv) * 62.831852F * 0.004F;
            FMS_DW.DiscreteTimeIntegrator1_PrevR_p = 0;

            /* End of Outputs for SubSystem: '<S133>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S133>/Brake Control' incorporates:
             *  ActionPort: '<S135>/Action Port'
             */
            /* SignalConversion: '<S135>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
             *  Constant: '<S135>/Brake Speed'
             */
            FMS_B.Merge_be = 0.0F;

            /* End of Outputs for SubSystem: '<S133>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S133>/Move Control' incorporates:
               *  ActionPort: '<S137>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S133>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S174>/Integrator'
               *  DiscreteIntegrator: '<S174>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_c = 0.0F;
              FMS_DW.Integrator_DSTATE_f1 = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S133>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S133>/Move Control' incorporates:
             *  ActionPort: '<S137>/Action Port'
             */
            /* Product: '<S175>/Multiply1' incorporates:
             *  Constant: '<S175>/const1'
             *  DiscreteIntegrator: '<S174>/Integrator'
             */
            rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_f1 * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S173>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S173>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S175>/Add' incorporates:
             *  DiscreteIntegrator: '<S174>/Integrator1'
             *  Gain: '<S137>/Gain6'
             *  Gain: '<S173>/Gain'
             *  Sum: '<S174>/Subtract'
             */
            rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_c - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.FW_ACC_Y_LIM) +
              rtb_Divide_pr_idx_1;

            /* Signum: '<S175>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            } else {
              rtb_Divide_lr_idx_2 = rtb_Saturation_e;
            }

            /* End of Signum: '<S175>/Sign' */

            /* Sum: '<S175>/Add2' incorporates:
             *  Abs: '<S175>/Abs'
             *  Gain: '<S175>/Gain'
             *  Gain: '<S175>/Gain1'
             *  Product: '<S175>/Multiply2'
             *  Product: '<S175>/Multiply3'
             *  Sqrt: '<S175>/Sqrt'
             *  Sum: '<S175>/Add1'
             *  Sum: '<S175>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
              FMS_ConstB.d_h) * FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F *
              rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

            /* Sum: '<S175>/Add4' */
            rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
              rtb_Divide_pr_idx_1;

            /* Sum: '<S175>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_h;

            /* Sum: '<S175>/Subtract1' */
            rtb_Saturation_e -= FMS_ConstB.d_h;

            /* Signum: '<S175>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S175>/Sign1' */

            /* Signum: '<S175>/Sign2' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else {
              if (rtb_Saturation_e > 0.0F) {
                rtb_Saturation_e = 1.0F;
              }
            }

            /* End of Signum: '<S175>/Sign2' */

            /* Sum: '<S175>/Add5' incorporates:
             *  Gain: '<S175>/Gain2'
             *  Product: '<S175>/Multiply4'
             *  Sum: '<S175>/Subtract2'
             */
            rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S137>/OutportBufferForay_cmd_mPs2' incorporates:
             *  DiscreteIntegrator: '<S174>/Integrator1'
             */
            FMS_B.Merge_be = FMS_DW.Integrator1_DSTATE_c;

            /* Update for DiscreteIntegrator: '<S174>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S174>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_c += 0.004F * FMS_DW.Integrator_DSTATE_f1;

            /* Sum: '<S175>/Subtract3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_h;

            /* Sum: '<S175>/Add6' */
            rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_h;

            /* Signum: '<S175>/Sign5' incorporates:
             *  Signum: '<S175>/Sign6'
             */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;

              /* Signum: '<S175>/Sign6' */
              rtb_Add4_o = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;

              /* Signum: '<S175>/Sign6' */
              rtb_Add4_o = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

              /* Signum: '<S175>/Sign6' */
              rtb_Add4_o = rtb_Divide_lr_idx_2;
            }

            /* End of Signum: '<S175>/Sign5' */

            /* Signum: '<S175>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S175>/Sign3' */

            /* Signum: '<S175>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S175>/Sign4' */

            /* Update for DiscreteIntegrator: '<S174>/Integrator' incorporates:
             *  Constant: '<S175>/const'
             *  Gain: '<S175>/Gain3'
             *  Product: '<S175>/Divide'
             *  Product: '<S175>/Multiply5'
             *  Product: '<S175>/Multiply6'
             *  Sum: '<S175>/Subtract4'
             *  Sum: '<S175>/Subtract5'
             *  Sum: '<S175>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_f1 += ((rtb_Divide_lr_idx_2 /
              FMS_ConstB.d_h - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_b *
              ((rtb_Divide_pr_idx_0 - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o *
              58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S133>/Move Control' */
            break;
          }

          /* SwitchCase: '<S119>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ad;
          FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S119>/Hold Control' incorporates:
               *  ActionPort: '<S122>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S119>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S119>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S119>/Hold Control' incorporates:
             *  ActionPort: '<S122>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_fb,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S119>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S119>/Brake Control' incorporates:
             *  ActionPort: '<S121>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_fb);

            /* End of Outputs for SubSystem: '<S119>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S119>/Move Control' incorporates:
               *  ActionPort: '<S123>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S119>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S119>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S119>/Move Control' incorporates:
             *  ActionPort: '<S123>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_fb,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S119>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S119>/Switch Case' */

          /* BusAssignment: '<S91>/Bus Assignment' incorporates:
           *  Constant: '<S91>/Constant'
           *  DiscreteIntegrator: '<S131>/Integrator1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S115>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < -0.2F) {
            rtb_Saturation_e = -0.2F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S115>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S91>/Bus Assignment' incorporates:
           *  Gain: '<S115>/Gain'
           */
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Saturation_e;

          /* Saturate: '<S133>/Saturation1' */
          if (FMS_B.Merge_be > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S91>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (FMS_B.Merge_be < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S91>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S91>/Bus Assignment' */
            FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_be;
          }

          /* End of Saturate: '<S133>/Saturation1' */

          /* Saturate: '<S119>/Saturation1' */
          if (FMS_B.Merge_fb > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S91>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_fb < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S91>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S91>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_fb;
          }

          /* End of Saturate: '<S119>/Saturation1' */

          /* Product: '<S132>/Multiply1' incorporates:
           *  Constant: '<S132>/const1'
           *  DiscreteIntegrator: '<S131>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S130>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
          }

          /* End of DeadZone: '<S130>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S132>/Add' incorporates:
           *  DiscreteIntegrator: '<S131>/Integrator1'
           *  Gain: '<S117>/Gain1'
           *  Gain: '<S130>/Gain'
           *  Sum: '<S131>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation_e * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_pr_idx_1;

          /* Signum: '<S132>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation_e;
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
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_l) * FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
            rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

          /* Sum: '<S132>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_pr_idx_1;

          /* Sum: '<S132>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_l;

          /* Sum: '<S132>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_l;

          /* Signum: '<S132>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S132>/Sign1' */

          /* Signum: '<S132>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S132>/Sign2' */

          /* Sum: '<S132>/Add5' incorporates:
           *  Gain: '<S132>/Gain2'
           *  Product: '<S132>/Multiply4'
           *  Sum: '<S132>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Update for DiscreteIntegrator: '<S131>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S131>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Sum: '<S132>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_l;

          /* Sum: '<S132>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_l;

          /* Signum: '<S132>/Sign5' incorporates:
           *  Signum: '<S132>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S132>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S132>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S132>/Sign6' */
            rtb_Add4_o = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S132>/Sign5' */

          /* Signum: '<S132>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S132>/Sign3' */

          /* Signum: '<S132>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S132>/Sign4' */

          /* Update for DiscreteIntegrator: '<S131>/Integrator' incorporates:
           *  Constant: '<S132>/const'
           *  Gain: '<S132>/Gain3'
           *  Product: '<S132>/Divide'
           *  Product: '<S132>/Multiply5'
           *  Product: '<S132>/Multiply6'
           *  Sum: '<S132>/Subtract4'
           *  Sum: '<S132>/Subtract5'
           *  Sum: '<S132>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ha += ((rtb_Divide_lr_idx_2 / FMS_ConstB.d_l
            - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_ak * ((rtb_Divide_pr_idx_0
            - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 15.707963F) * 0.004F;

          /* End of Outputs for SubSystem: '<S85>/Position' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S85>/Unknown' incorporates:
           *  ActionPort: '<S93>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_p);

          /* End of Outputs for SubSystem: '<S85>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S46>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S46>/Manual' incorporates:
         *  ActionPort: '<S87>/Action Port'
         */
        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  Constant: '<S87>/Constant'
         *  Constant: '<S87>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_nu;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_lc;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S221>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S40>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_e = 0.0F;
        } else {
          rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S221>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  Gain: '<S221>/Gain'
         */
        FMS_Y.FMS_Out.p_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Saturation_e;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S222>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S40>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_e = 0.0F;
        } else {
          rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S222>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  Gain: '<S222>/Gain'
         *  Gain: '<S87>/Gain'
         */
        FMS_Y.FMS_Out.q_cmd = -(1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_Saturation_e);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S223>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S40>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Saturation_e = 0.0F;
        } else {
          rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S223>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  Gain: '<S223>/Gain'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Saturation_e;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S224>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S40>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
          rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle -
            FMS_PARAM.THROTTLE_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
          rtb_Saturation_e = 0.0F;
        } else {
          rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle -
            (-FMS_PARAM.THROTTLE_DZ);
        }

        /* End of DeadZone: '<S224>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  Gain: '<S224>/Gain'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) *
          rtb_Saturation_e;

        /* End of Outputs for SubSystem: '<S46>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S46>/Unknown' incorporates:
         *  ActionPort: '<S89>/Action Port'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown);

        /* End of Outputs for SubSystem: '<S46>/Unknown' */
        break;
      }

      /* End of Outputs for SubSystem: '<S41>/FW_Mode' */
      break;

     case 1:
      if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
        /* InitializeConditions for IfAction SubSystem: '<S41>/BackwardTrans_Mode' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        /* InitializeConditions for SwitchCase: '<S41>/Switch Case' incorporates:
         *  Delay: '<S53>/start_vel'
         *  Delay: '<S53>/start_wp'
         *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
         *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator1'
         */
        FMS_DW.icLoad_i = 1U;
        FMS_DW.icLoad_e = 1U;
        FMS_DW.DiscreteTimeIntegrator_DSTATE_i = FMS_ConstB.Constant;
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i >= 1.0F) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_i = 1.0F;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i <= -1.0F) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_i = -1.0F;
          }
        }

        FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;
        FMS_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
        FMS_DW.DiscreteTimeIntegrator1_PrevRes = 0;

        /* End of InitializeConditions for SwitchCase: '<S41>/Switch Case' */
        /* End of InitializeConditions for SubSystem: '<S41>/BackwardTrans_Mode' */
      }

      /* Outputs for IfAction SubSystem: '<S41>/BackwardTrans_Mode' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Trigonometry: '<S75>/Trigonometric Function1' incorporates:
       *  Gain: '<S73>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_ch[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S75>/Trigonometric Function' incorporates:
       *  Gain: '<S73>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_ch[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S75>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S75>/Constant3'
       */
      rtb_VectorConcatenate_ch[2] = 0.0F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Gain: '<S75>/Gain' incorporates:
       *  Gain: '<S73>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       *  Trigonometry: '<S75>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_ch[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S75>/Trigonometric Function3' incorporates:
       *  Gain: '<S73>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_ch[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S75>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S75>/Constant4'
       */
      rtb_VectorConcatenate_ch[5] = 0.0F;

      /* SignalConversion: '<S75>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_n[0];
      rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_n[1];
      rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_n[2];

      /* Math: '<S53>/Transpose' */
      for (rtb_n = 0; rtb_n < 3; rtb_n++) {
        rtb_MatrixConcatenate1_i[3 * rtb_n] = rtb_VectorConcatenate_ch[rtb_n];
        rtb_MatrixConcatenate1_i[1 + 3 * rtb_n] = rtb_VectorConcatenate_ch[rtb_n
          + 3];
        rtb_MatrixConcatenate1_i[2 + 3 * rtb_n] = rtb_VectorConcatenate_ch[rtb_n
          + 6];
      }

      for (rtb_n = 0; rtb_n < 9; rtb_n++) {
        rtb_VectorConcatenate_ch[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n];
      }

      /* End of Math: '<S53>/Transpose' */

      /* Sqrt: '<S60>/Sqrt' incorporates:
       *  Math: '<S60>/Square'
       *  Sum: '<S60>/Sum of Elements'
       */
      rtb_Saturation_e = sqrtf(((rtb_Divide_pr_idx_0 + rtb_Divide_pr_idx_1) +
        rtb_Divide_pr_idx_2) + rtb_Saturation_e);

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Product: '<S56>/Divide' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_Divide_pr_idx_0 = FMS_U.INS_Out.quat[0] / rtb_Saturation_e;
      rtb_Divide_pr_idx_1 = FMS_U.INS_Out.quat[1] / rtb_Saturation_e;
      rtb_Divide_pr_idx_2 = FMS_U.INS_Out.quat[2] / rtb_Saturation_e;
      rtb_Saturation_e = FMS_U.INS_Out.quat[3] / rtb_Saturation_e;

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Product: '<S53>/Multiply' */
      for (rtb_n = 0; rtb_n < 3; rtb_n++) {
        rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_ch[rtb_n];
      }

      /* End of Product: '<S53>/Multiply' */

      /* Math: '<S57>/Square' incorporates:
       *  Math: '<S58>/Square'
       *  Math: '<S59>/Square'
       */
      rtb_Add4_o = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;

      /* Math: '<S57>/Square2' incorporates:
       *  Math: '<S58>/Square2'
       *  Math: '<S59>/Square2'
       */
      rtb_Divide_or = rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2;

      /* Math: '<S57>/Square1' incorporates:
       *  Math: '<S58>/Square1'
       *  Math: '<S59>/Square1'
       */
      rtb_Sign5_mn = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

      /* Math: '<S57>/Square3' incorporates:
       *  Math: '<S58>/Square3'
       *  Math: '<S59>/Square3'
       */
      rtb_MatrixConcatenate1_i_tmp_1 = rtb_Saturation_e * rtb_Saturation_e;

      /* Sum: '<S57>/Subtract' incorporates:
       *  Math: '<S57>/Square'
       *  Math: '<S57>/Square1'
       *  Math: '<S57>/Square2'
       *  Math: '<S57>/Square3'
       *  Sum: '<S57>/Add'
       *  Sum: '<S57>/Add1'
       */
      rtb_MatrixConcatenate1_i[0] = (rtb_Add4_o + rtb_Sign5_mn) - (rtb_Divide_or
        + rtb_MatrixConcatenate1_i_tmp_1);

      /* Product: '<S57>/Multiply' incorporates:
       *  Product: '<S58>/Multiply'
       */
      rtb_MatrixConcatenate1_i_tmp = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_2;

      /* Product: '<S57>/Multiply1' incorporates:
       *  Product: '<S58>/Multiply1'
       */
      rtb_MatrixConcatenate1_i_tmp_0 = rtb_Divide_pr_idx_0 * rtb_Saturation_e;

      /* Gain: '<S57>/Gain' incorporates:
       *  Product: '<S57>/Multiply'
       *  Product: '<S57>/Multiply1'
       *  Sum: '<S57>/Subtract1'
       */
      rtb_MatrixConcatenate1_i[1] = (rtb_MatrixConcatenate1_i_tmp -
        rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

      /* Product: '<S57>/Multiply2' incorporates:
       *  Product: '<S59>/Multiply'
       */
      rtb_MatrixConcatenate1_i_tmp_2 = rtb_Divide_pr_idx_1 * rtb_Saturation_e;

      /* Product: '<S57>/Multiply3' incorporates:
       *  Product: '<S59>/Multiply1'
       */
      rtb_MatrixConcatenate1_i_tmp_3 = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_2;

      /* Gain: '<S57>/Gain1' incorporates:
       *  Product: '<S57>/Multiply2'
       *  Product: '<S57>/Multiply3'
       *  Sum: '<S57>/Add2'
       */
      rtb_MatrixConcatenate1_i[2] = (rtb_MatrixConcatenate1_i_tmp_2 +
        rtb_MatrixConcatenate1_i_tmp_3) * 2.0F;

      /* Gain: '<S58>/Gain' incorporates:
       *  Sum: '<S58>/Add3'
       */
      rtb_MatrixConcatenate1_i[3] = (rtb_MatrixConcatenate1_i_tmp +
        rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

      /* Sum: '<S58>/Subtract' incorporates:
       *  Sum: '<S58>/Add'
       *  Sum: '<S58>/Add1'
       */
      rtb_MatrixConcatenate1_i[4] = (rtb_Add4_o + rtb_Divide_or) - (rtb_Sign5_mn
        + rtb_MatrixConcatenate1_i_tmp_1);

      /* Product: '<S58>/Multiply2' incorporates:
       *  Product: '<S59>/Multiply2'
       */
      rtb_MatrixConcatenate1_i_tmp = rtb_Divide_pr_idx_2 * rtb_Saturation_e;

      /* Product: '<S58>/Multiply3' incorporates:
       *  Product: '<S59>/Multiply3'
       */
      rtb_MatrixConcatenate1_i_tmp_0 = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_1;

      /* Gain: '<S58>/Gain1' incorporates:
       *  Product: '<S58>/Multiply2'
       *  Product: '<S58>/Multiply3'
       *  Sum: '<S58>/Subtract1'
       */
      rtb_MatrixConcatenate1_i[5] = (rtb_MatrixConcatenate1_i_tmp -
        rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

      /* Gain: '<S59>/Gain' incorporates:
       *  Sum: '<S59>/Subtract2'
       */
      rtb_MatrixConcatenate1_i[6] = (rtb_MatrixConcatenate1_i_tmp_2 -
        rtb_MatrixConcatenate1_i_tmp_3) * 2.0F;

      /* Gain: '<S59>/Gain1' incorporates:
       *  Sum: '<S59>/Add2'
       */
      rtb_MatrixConcatenate1_i[7] = (rtb_MatrixConcatenate1_i_tmp +
        rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

      /* Sum: '<S59>/Subtract' incorporates:
       *  Sum: '<S59>/Add'
       *  Sum: '<S59>/Add1'
       */
      rtb_MatrixConcatenate1_i[8] = (rtb_Add4_o + rtb_MatrixConcatenate1_i_tmp_1)
        - (rtb_Sign5_mn + rtb_Divide_or);

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Trigonometry: '<S80>/Trigonometric Function1' incorporates:
       *  Gain: '<S79>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_ch[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S80>/Trigonometric Function' incorporates:
       *  Gain: '<S79>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_ch[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S80>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S80>/Constant3'
       */
      rtb_VectorConcatenate_ch[2] = 0.0F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Gain: '<S80>/Gain' incorporates:
       *  Gain: '<S79>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       *  Trigonometry: '<S80>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_ch[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S80>/Trigonometric Function3' incorporates:
       *  Gain: '<S79>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_ch[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S80>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S80>/Constant4'
       */
      rtb_VectorConcatenate_ch[5] = 0.0F;

      /* SignalConversion: '<S80>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_o[0];
      rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_o[1];
      rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_o[2];

      /* Delay: '<S53>/start_vel' */
      if (FMS_DW.icLoad_i != 0) {
        FMS_DW.start_vel_DSTATE[0] = rtb_Switch_an[0];
        FMS_DW.start_vel_DSTATE[1] = rtb_Switch_an[1];
      }

      /* Sum: '<S74>/Sum of Elements' incorporates:
       *  Delay: '<S53>/start_vel'
       *  Math: '<S74>/Math Function'
       */
      rtb_Saturation_e = FMS_DW.start_vel_DSTATE[0] * FMS_DW.start_vel_DSTATE[0]
        + FMS_DW.start_vel_DSTATE[1] * FMS_DW.start_vel_DSTATE[1];

      /* Math: '<S74>/Math Function1' incorporates:
       *  Sum: '<S74>/Sum of Elements'
       *
       * About '<S74>/Math Function1':
       *  Operator: sqrt
       */
      if (rtb_Saturation_e < 0.0F) {
        rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
      } else {
        rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
      }

      /* End of Math: '<S74>/Math Function1' */

      /* Switch: '<S74>/Switch' incorporates:
       *  Constant: '<S74>/Constant'
       *  Delay: '<S53>/start_vel'
       *  Product: '<S74>/Product'
       */
      if (rtb_Divide_pr_idx_1 > 0.0F) {
        rtb_Switch_an[0] = FMS_DW.start_vel_DSTATE[0];
        rtb_Switch_an[1] = FMS_DW.start_vel_DSTATE[1];
        rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
      } else {
        rtb_Switch_an[0] = 0.0F;
        rtb_Switch_an[1] = 0.0F;
        rtb_Switch_an[2] = 1.0F;
      }

      /* End of Switch: '<S74>/Switch' */

      /* Delay: '<S53>/start_wp' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      if (FMS_DW.icLoad_e != 0) {
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
        FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      }

      /* End of Delay: '<S53>/start_wp' */

      /* Product: '<S74>/Divide' */
      rtb_Square_bg[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
      rtb_Square_bg[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* MATLAB Function: '<S51>/SearchL1RefWP' incorporates:
       *  Constant: '<S48>/L1'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      FMS_SearchL1RefWP_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                          FMS_DW.start_wp_DSTATE, rtb_Square_bg, FMS_PARAM.FW_L1,
                          rtb_Subtract_hb, &rtb_Saturation_e);

      /* MATLAB Function: '<S51>/OutRegionRefWP' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      FMS_OutRegionRefWP(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                         FMS_DW.start_wp_DSTATE, rtb_Square_bg, rtb_P_dg);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* Product: '<S78>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      for (rtb_n = 0; rtb_n < 3; rtb_n++) {
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        rtb_VectorConcatenate_fy[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 3] *
          FMS_U.INS_Out.ve + rtb_VectorConcatenate_ch[rtb_n] * FMS_U.INS_Out.vn;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      }

      /* End of Product: '<S78>/Multiply' */

      /* DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
      if (FMS_DW.DiscreteTimeIntegrator_PrevRese != 0) {
        FMS_DW.DiscreteTimeIntegrator_DSTATE_i = FMS_ConstB.Constant;
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i >= 1.0F) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_i = 1.0F;
        } else {
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i <= -1.0F) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_i = -1.0F;
          }
        }
      }

      if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i >= 1.0F) {
        FMS_DW.DiscreteTimeIntegrator_DSTATE_i = 1.0F;
      } else {
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i <= -1.0F) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_i = -1.0F;
        }
      }

      /* DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' incorporates:
       *  Constant: '<S76>/Constant'
       *  Sum: '<S76>/Sum'
       */
      if (FMS_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
        FMS_DW.DiscreteTimeIntegrator1_DSTAT_j = 0.0F -
          rtb_VectorConcatenate_fy[1];
      }

      if (FMS_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
        FMS_DW.DiscreteTimeIntegrator1_DSTAT_j = 0.0F -
          rtb_VectorConcatenate_fy[1];
      }

      /* Product: '<S50>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      for (rtb_n = 0; rtb_n < 3; rtb_n++) {
        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        rtb_MatrixConcatenate1_i_0[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n + 6] *
          FMS_U.INS_Out.vd + (rtb_MatrixConcatenate1_i[rtb_n + 3] *
                              FMS_U.INS_Out.ve + rtb_MatrixConcatenate1_i[rtb_n]
                              * FMS_U.INS_Out.vn);

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
      }

      /* End of Product: '<S50>/Multiply' */

      /* Switch: '<S48>/Switch' incorporates:
       *  Constant: '<S48>/L1'
       *  Constant: '<S49>/Constant'
       *  Constant: '<S64>/Constant'
       *  Constant: '<S76>/Constant'
       *  Constant: '<S83>/kp'
       *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
       *  Gain: '<S64>/Gain'
       *  Math: '<S64>/Square'
       *  Math: '<S67>/Square'
       *  Math: '<S69>/Math Function'
       *  MinMax: '<S64>/Max'
       *  MinMax: '<S64>/Min'
       *  Product: '<S64>/Divide'
       *  Product: '<S64>/Multiply1'
       *  Product: '<S83>/Multiply'
       *  RelationalOperator: '<S49>/Compare'
       *  Sqrt: '<S67>/Sqrt'
       *  Sum: '<S52>/Subtract'
       *  Sum: '<S67>/Sum of Elements'
       *  Sum: '<S76>/Sum'
       *  Sum: '<S77>/Add'
       *  Switch: '<S51>/Switch'
       *  Trigonometry: '<S64>/Sin'
       */
      if (rtb_MatrixConcatenate1_i_0[0] >= 3.0F) {
        /* Math: '<S68>/Math Function1'
         *
         * About '<S68>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_3 < 0.0F) {
          rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
        } else {
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
        }

        /* End of Math: '<S68>/Math Function1' */

        /* Switch: '<S68>/Switch' incorporates:
         *  Constant: '<S68>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S68>/Product'
         *  SignalConversion: '<S40>/Signal Copy1'
         */
        if (rtb_Divide_pr_idx_1 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          rtb_Switch_an[0] = FMS_U.INS_Out.vn;
          rtb_Switch_an[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
        } else {
          rtb_Switch_an[0] = 0.0F;
          rtb_Switch_an[1] = 0.0F;
          rtb_Switch_an[2] = 1.0F;
        }

        /* End of Switch: '<S68>/Switch' */

        /* Product: '<S68>/Divide' */
        rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
        rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

        /* RelationalOperator: '<S61>/Compare' incorporates:
         *  Constant: '<S61>/Constant'
         */
        rtb_FixPtRelationalOperator_me = (rtb_Saturation_e > 0.0F);

        /* Switch: '<S51>/Switch' */
        if (rtb_FixPtRelationalOperator_me) {
          rtb_Divide_pr_idx_1 = rtb_Subtract_hb[0];
        } else {
          rtb_Divide_pr_idx_1 = rtb_P_dg[0];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S52>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S40>/Signal Copy1'
         */
        rtb_Divide_pr_idx_2 = rtb_Divide_pr_idx_1 - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        rtb_Subtract_hb[0] = rtb_Divide_pr_idx_2;
        rtb_Square_ds[0] = rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2;

        /* Switch: '<S51>/Switch' incorporates:
         *  Math: '<S69>/Math Function'
         *  Sum: '<S52>/Subtract'
         */
        if (rtb_FixPtRelationalOperator_me) {
          rtb_Divide_pr_idx_1 = rtb_Subtract_hb[1];
        } else {
          rtb_Divide_pr_idx_1 = rtb_P_dg[1];
        }

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* Sum: '<S52>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S40>/Signal Copy1'
         */
        rtb_Divide_pr_idx_2 = rtb_Divide_pr_idx_1 - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* Math: '<S69>/Math Function' incorporates:
         *  Math: '<S67>/Square'
         */
        rtb_Saturation_e = rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2;

        /* Sum: '<S69>/Sum of Elements' incorporates:
         *  Math: '<S69>/Math Function'
         */
        rtb_Divide_lr_idx_3 = rtb_Saturation_e + rtb_Square_ds[0];

        /* Math: '<S69>/Math Function1' incorporates:
         *  Sum: '<S69>/Sum of Elements'
         *
         * About '<S69>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_3 < 0.0F) {
          rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
        } else {
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
        }

        /* End of Math: '<S69>/Math Function1' */

        /* Switch: '<S69>/Switch' incorporates:
         *  Constant: '<S69>/Constant'
         *  Product: '<S69>/Product'
         */
        if (rtb_Divide_pr_idx_1 > 0.0F) {
          rtb_Switch_an[0] = rtb_Subtract_hb[0];
          rtb_Switch_an[1] = rtb_Divide_pr_idx_2;
          rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
        } else {
          rtb_Switch_an[0] = 0.0F;
          rtb_Switch_an[1] = 0.0F;
          rtb_Switch_an[2] = 1.0F;
        }

        /* End of Switch: '<S69>/Switch' */

        /* Product: '<S69>/Divide' */
        rtb_Square_ds[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
        rtb_Subtract_hb[0] *= rtb_Subtract_hb[0];

        /* Product: '<S69>/Divide' incorporates:
         *  Math: '<S67>/Square'
         */
        rtb_Square_ds[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

        /* Sum: '<S71>/Sum of Elements' incorporates:
         *  Math: '<S71>/Math Function'
         *  SignalConversion: '<S71>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
          rtb_Divide_i5[0] * rtb_Divide_i5[0];

        /* Math: '<S71>/Math Function1' incorporates:
         *  Sum: '<S71>/Sum of Elements'
         *
         * About '<S71>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_3 < 0.0F) {
          rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
        } else {
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
        }

        /* End of Math: '<S71>/Math Function1' */

        /* Switch: '<S71>/Switch' incorporates:
         *  Constant: '<S71>/Constant'
         *  Product: '<S71>/Product'
         */
        if (rtb_Divide_pr_idx_1 > 0.0F) {
          rtb_Switch_an[0] = rtb_Divide_i5[1];
          rtb_Switch_an[1] = rtb_Divide_i5[0];
          rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
        } else {
          rtb_Switch_an[0] = 0.0F;
          rtb_Switch_an[1] = 0.0F;
          rtb_Switch_an[2] = 1.0F;
        }

        /* End of Switch: '<S71>/Switch' */

        /* Product: '<S71>/Divide' */
        rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
        rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

        /* Sum: '<S72>/Sum of Elements' incorporates:
         *  Math: '<S72>/Math Function'
         *  SignalConversion: '<S72>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Divide_lr_idx_3 = rtb_Square_ds[1] * rtb_Square_ds[1] +
          rtb_Square_ds[0] * rtb_Square_ds[0];

        /* Math: '<S72>/Math Function1' incorporates:
         *  Sum: '<S72>/Sum of Elements'
         *
         * About '<S72>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Divide_lr_idx_3 < 0.0F) {
          rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
        } else {
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
        }

        /* End of Math: '<S72>/Math Function1' */

        /* Switch: '<S72>/Switch' incorporates:
         *  Constant: '<S72>/Constant'
         *  Product: '<S72>/Product'
         */
        if (rtb_Divide_pr_idx_1 > 0.0F) {
          rtb_Switch_an[0] = rtb_Square_ds[1];
          rtb_Switch_an[1] = rtb_Square_ds[0];
          rtb_Switch_an[2] = rtb_Divide_pr_idx_1;
        } else {
          rtb_Switch_an[0] = 0.0F;
          rtb_Switch_an[1] = 0.0F;
          rtb_Switch_an[2] = 1.0F;
        }

        /* End of Switch: '<S72>/Switch' */

        /* Product: '<S72>/Divide' */
        rtb_Square_ds[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
        rtb_Square_ds[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

        /* Sum: '<S70>/Subtract' incorporates:
         *  Product: '<S70>/Multiply'
         *  Product: '<S70>/Multiply1'
         */
        rtb_Divide_pr_idx_1 = rtb_Square_ds[0] * rtb_Divide_i5[1] -
          rtb_Square_ds[1] * rtb_Divide_i5[0];

        /* Signum: '<S65>/Sign1' */
        if (rtb_Divide_pr_idx_1 < 0.0F) {
          rtb_Divide_pr_idx_1 = -1.0F;
        } else {
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          }
        }

        /* End of Signum: '<S65>/Sign1' */

        /* Switch: '<S65>/Switch2' incorporates:
         *  Constant: '<S65>/Constant4'
         */
        if (rtb_Divide_pr_idx_1 == 0.0F) {
          rtb_Divide_pr_idx_1 = 1.0F;
        }

        /* End of Switch: '<S65>/Switch2' */

        /* DotProduct: '<S65>/Dot Product' */
        rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Square_ds[0] +
          rtb_Divide_i5[1] * rtb_Square_ds[1];

        /* Trigonometry: '<S65>/Acos' incorporates:
         *  DotProduct: '<S65>/Dot Product'
         */
        if (rtb_Divide_pr_idx_0 > 1.0F) {
          rtb_Divide_pr_idx_0 = 1.0F;
        } else {
          if (rtb_Divide_pr_idx_0 < -1.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          }
        }

        /* Product: '<S65>/Multiply' incorporates:
         *  Trigonometry: '<S65>/Acos'
         */
        rtb_Divide_pr_idx_1 *= acosf(rtb_Divide_pr_idx_0);

        /* Saturate: '<S64>/Saturation' */
        if (rtb_Divide_pr_idx_1 > 1.57079637F) {
          rtb_Divide_pr_idx_1 = 1.57079637F;
        } else {
          if (rtb_Divide_pr_idx_1 < -1.57079637F) {
            rtb_Divide_pr_idx_1 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S64>/Saturation' */
        rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
          arm_sin_f32(rtb_Divide_pr_idx_1) / fminf(FMS_PARAM.FW_L1, fmaxf(sqrtf
          (rtb_Saturation_e + rtb_Subtract_hb[0]), 0.5F));
      } else {
        rtb_Saturation_e = (0.0F - rtb_VectorConcatenate_fy[1]) * 1.2F +
          FMS_DW.DiscreteTimeIntegrator_DSTATE_i;
      }

      /* BusAssignment: '<S45>/Bus Assignment' incorporates:
       *  Constant: '<S45>/Constant'
       *  Constant: '<S45>/Constant3'
       *  Constant: '<S45>/Constant4'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
      FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_f;
      FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_g;
      FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_i;
      FMS_Y.FMS_Out.u_cmd = 0.0F;
      FMS_Y.FMS_Out.w_cmd = 0.0F;
      FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
      FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

      /* Update for Delay: '<S53>/start_vel' */
      FMS_DW.icLoad_i = 0U;

      /* Update for Delay: '<S53>/start_wp' */
      FMS_DW.icLoad_e = 0U;

      /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S76>/Constant'
       *  Constant: '<S82>/ki'
       *  Product: '<S82>/Multiply'
       *  Sum: '<S76>/Sum'
       */
      FMS_DW.DiscreteTimeIntegrator_DSTATE_i += (0.0F -
        rtb_VectorConcatenate_fy[1]) * 0.5F * 0.004F;
      if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i >= 1.0F) {
        FMS_DW.DiscreteTimeIntegrator_DSTATE_i = 1.0F;
      } else {
        if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i <= -1.0F) {
          FMS_DW.DiscreteTimeIntegrator_DSTATE_i = -1.0F;
        }
      }

      FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

      /* End of Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' incorporates:
       *  Constant: '<S76>/Constant'
       *  Gain: '<S84>/Gain'
       *  Sum: '<S76>/Sum'
       *  Sum: '<S84>/Sum5'
       */
      FMS_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
      FMS_DW.DiscreteTimeIntegrator1_DSTAT_j += ((0.0F -
        rtb_VectorConcatenate_fy[1]) - FMS_DW.DiscreteTimeIntegrator1_DSTAT_j) *
        62.831852F * 0.004F;
      FMS_DW.DiscreteTimeIntegrator1_PrevRes = 0;

      /* End of Outputs for SubSystem: '<S41>/BackwardTrans_Mode' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S41>/MC_Mode' incorporates:
       *  ActionPort: '<S47>/Action Port'
       */
      /* SwitchCase: '<S47>/Switch Case' */
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
          /* Disable for SwitchCase: '<S295>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S696>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S686>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S635>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S603>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S614>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S293>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S405>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S456>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S446>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S405>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S292>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S392>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S307>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S325>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S341>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S366>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S353>/Switch Case' */
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
        /* Outputs for IfAction SubSystem: '<S47>/SubMode' incorporates:
         *  ActionPort: '<S295>/Action Port'
         */
        /* SwitchCase: '<S295>/Switch Case' incorporates:
         *  Math: '<S718>/Math Function'
         *  Sum: '<S680>/Subtract'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_b4;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_b4) {
          switch (rtPrevAction) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S696>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S686>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S635>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S603>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S614>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Takeoff' incorporates:
             *  ActionPort: '<S598>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Delay: '<S736>/cur_waypoint'
             *  DiscreteIntegrator: '<S732>/Integrator'
             *  DiscreteIntegrator: '<S732>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S295>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Takeoff' incorporates:
           *  ActionPort: '<S598>/Action Port'
           */
          /* Delay: '<S736>/cur_waypoint' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_hz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.cur_waypoint_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.cur_waypoint_DSTATE[1] = FMS_U.INS_Out.y_R;
            FMS_DW.cur_waypoint_DSTATE[2] = FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Product: '<S736>/Divide' incorporates:
           *  Delay: '<S736>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S736>/Sum1'
           *  Sum: '<S736>/Sum2'
           */
          rtb_Divide_lr_idx_2 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S736>/Saturation' */
          if (rtb_Divide_lr_idx_2 > 1.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S736>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S737>/Trigonometric Function1' incorporates:
           *  Gain: '<S735>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_ch[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S737>/Trigonometric Function' incorporates:
           *  Gain: '<S735>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_ch[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S737>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S737>/Constant3'
           */
          rtb_VectorConcatenate_ch[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S737>/Gain' incorporates:
           *  Gain: '<S735>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S737>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ch[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S737>/Trigonometric Function3' incorporates:
           *  Gain: '<S735>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_ch[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S737>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S737>/Constant4'
           */
          rtb_VectorConcatenate_ch[5] = 0.0F;

          /* SignalConversion: '<S737>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_c[0];
          rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_c[1];
          rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_c[2];

          /* Saturate: '<S729>/Saturation1' */
          rtb_Divide_pr_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Divide_pr_idx_2 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S729>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S736>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S736>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S729>/Sum'
           *  Sum: '<S736>/Sum3'
           *  Sum: '<S736>/Sum4'
           */
          rtb_Divide_pr_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_lr_idx_2 +
            FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
          rtb_Divide_lr_idx_2 = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Divide_lr_idx_2 +
            FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S729>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_fy[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 3]
              * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_ch[rtb_n] *
              rtb_Divide_pr_idx_1;
          }

          /* Saturate: '<S729>/Saturation1' incorporates:
           *  Gain: '<S729>/Gain2'
           *  Product: '<S729>/Multiply'
           */
          rtb_Saturation_e = FMS_PARAM.XY_P * rtb_VectorConcatenate_fy[0];
          rtb_Divide_pr_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_fy[1];

          /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
           *  Constant: '<S598>/Constant'
           *  Constant: '<S598>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S729>/Saturation1' */
          if (rtb_Saturation_e > rtb_Divide_pr_idx_0) {
            /* BusAssignment: '<S598>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_0;
          } else if (rtb_Saturation_e < rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S598>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_2;
          } else {
            /* BusAssignment: '<S598>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_e;
          }

          if (rtb_Divide_pr_idx_1 > rtb_Divide_pr_idx_0) {
            /* BusAssignment: '<S598>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_0;
          } else if (rtb_Divide_pr_idx_1 < rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S598>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_2;
          } else {
            /* BusAssignment: '<S598>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_1;
          }

          /* BusAssignment: '<S598>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S732>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S733>/Multiply1' incorporates:
           *  Constant: '<S733>/const1'
           *  DiscreteIntegrator: '<S732>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S728>/Switch' incorporates:
           *  Abs: '<S728>/Abs'
           *  Abs: '<S728>/Abs1'
           *  Constant: '<S728>/Takeoff_Speed'
           *  Constant: '<S730>/Constant'
           *  Constant: '<S731>/Constant'
           *  Gain: '<S728>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S728>/Logical Operator'
           *  RelationalOperator: '<S730>/Compare'
           *  RelationalOperator: '<S731>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S728>/Sum'
           *  Sum: '<S728>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_Saturation_e = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_Saturation_e = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S728>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S733>/Add' incorporates:
           *  DiscreteIntegrator: '<S732>/Integrator1'
           *  Sum: '<S732>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_f - rtb_Saturation_e)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S733>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S733>/Sign' */

          /* Sum: '<S733>/Add2' incorporates:
           *  Abs: '<S733>/Abs'
           *  Gain: '<S733>/Gain'
           *  Gain: '<S733>/Gain1'
           *  Product: '<S733>/Multiply2'
           *  Product: '<S733>/Multiply3'
           *  Sqrt: '<S733>/Sqrt'
           *  Sum: '<S733>/Add1'
           *  Sum: '<S733>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_b) * FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_lr_idx_2;

          /* Sum: '<S733>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S733>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_b;

          /* Sum: '<S733>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_b;

          /* Signum: '<S733>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S733>/Sign1' */

          /* Signum: '<S733>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S733>/Sign2' */

          /* Sum: '<S733>/Add5' incorporates:
           *  Gain: '<S733>/Gain2'
           *  Product: '<S733>/Multiply4'
           *  Sum: '<S733>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Update for Delay: '<S736>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S732>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S732>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S733>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_b;

          /* Sum: '<S733>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_b;

          /* Signum: '<S733>/Sign5' incorporates:
           *  Signum: '<S733>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S733>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S733>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;

            /* Signum: '<S733>/Sign6' */
            rtb_Add4_o = rtb_Saturation_e;
          }

          /* End of Signum: '<S733>/Sign5' */

          /* Signum: '<S733>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S733>/Sign3' */

          /* Signum: '<S733>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S733>/Sign4' */

          /* Update for DiscreteIntegrator: '<S732>/Integrator' incorporates:
           *  Constant: '<S733>/const'
           *  Gain: '<S733>/Gain3'
           *  Product: '<S733>/Divide'
           *  Product: '<S733>/Multiply5'
           *  Product: '<S733>/Multiply6'
           *  Sum: '<S733>/Subtract4'
           *  Sum: '<S733>/Subtract5'
           *  Sum: '<S733>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_Saturation_e / FMS_ConstB.d_b -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_i * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S295>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Land' incorporates:
             *  ActionPort: '<S596>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S651>/Integrator'
             *  DiscreteIntegrator: '<S651>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S295>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Land' incorporates:
           *  ActionPort: '<S596>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S656>/Trigonometric Function1' incorporates:
           *  Gain: '<S655>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_ch[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S656>/Trigonometric Function' incorporates:
           *  Gain: '<S655>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_ch[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S656>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S656>/Constant3'
           */
          rtb_VectorConcatenate_ch[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S656>/Gain' incorporates:
           *  Gain: '<S655>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S656>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_ch[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S656>/Trigonometric Function3' incorporates:
           *  Gain: '<S655>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_ch[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S656>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S656>/Constant4'
           */
          rtb_VectorConcatenate_ch[5] = 0.0F;

          /* SignalConversion: '<S656>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S649>/Saturation1' */
          rtb_Divide_pr_idx_2 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Add4_o = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S653>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S653>/Sum'
           */
          rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_lr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S653>/Multiply' incorporates:
           *  SignalConversion: '<S653>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S653>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_fy[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 3]
              * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_ch[rtb_n] *
              rtb_Divide_pr_idx_1;
          }

          /* End of Product: '<S653>/Multiply' */

          /* Saturate: '<S649>/Saturation1' incorporates:
           *  Gain: '<S653>/Gain2'
           */
          rtb_Saturation_e = FMS_PARAM.XY_P * rtb_VectorConcatenate_fy[0];
          rtb_Divide_pr_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_fy[1];

          /* BusAssignment: '<S596>/Bus Assignment1' incorporates:
           *  Constant: '<S596>/Constant'
           *  Constant: '<S596>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S649>/Saturation1' */
          if (rtb_Saturation_e > rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S596>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_2;
          } else if (rtb_Saturation_e < rtb_Add4_o) {
            /* BusAssignment: '<S596>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Add4_o;
          } else {
            /* BusAssignment: '<S596>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_e;
          }

          if (rtb_Divide_pr_idx_1 > rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S596>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_2;
          } else if (rtb_Divide_pr_idx_1 < rtb_Add4_o) {
            /* BusAssignment: '<S596>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Add4_o;
          } else {
            /* BusAssignment: '<S596>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_1;
          }

          /* BusAssignment: '<S596>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S651>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S652>/Multiply1' incorporates:
           *  Constant: '<S652>/const1'
           *  DiscreteIntegrator: '<S651>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S648>/Switch' incorporates:
           *  Constant: '<S648>/Land_Speed'
           *  Constant: '<S650>/Constant'
           *  Gain: '<S648>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S648>/Logical Operator'
           *  RelationalOperator: '<S650>/Compare'
           *  S-Function (sfix_bitop): '<S648>/cmd_p valid'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_Saturation_e = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_Saturation_e = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S648>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S652>/Add' incorporates:
           *  DiscreteIntegrator: '<S651>/Integrator1'
           *  Sum: '<S651>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_g - rtb_Saturation_e) +
            rtb_Divide_pr_idx_1;

          /* Signum: '<S652>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S652>/Sign' */

          /* Sum: '<S652>/Add2' incorporates:
           *  Abs: '<S652>/Abs'
           *  Gain: '<S652>/Gain'
           *  Gain: '<S652>/Gain1'
           *  Product: '<S652>/Multiply2'
           *  Product: '<S652>/Multiply3'
           *  Sqrt: '<S652>/Sqrt'
           *  Sum: '<S652>/Add1'
           *  Sum: '<S652>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_om) * FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

          /* Sum: '<S652>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_pr_idx_1;

          /* Sum: '<S652>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_om;

          /* Sum: '<S652>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_om;

          /* Signum: '<S652>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S652>/Sign1' */

          /* Signum: '<S652>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S652>/Sign2' */

          /* Sum: '<S652>/Add5' incorporates:
           *  Gain: '<S652>/Gain2'
           *  Product: '<S652>/Multiply4'
           *  Sum: '<S652>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Update for DiscreteIntegrator: '<S651>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S651>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S652>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_om;

          /* Sum: '<S652>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_om;

          /* Signum: '<S652>/Sign5' incorporates:
           *  Signum: '<S652>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S652>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S652>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S652>/Sign6' */
            rtb_Add4_o = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S652>/Sign5' */

          /* Signum: '<S652>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S652>/Sign3' */

          /* Signum: '<S652>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S652>/Sign4' */

          /* Update for DiscreteIntegrator: '<S651>/Integrator' incorporates:
           *  Constant: '<S652>/const'
           *  Gain: '<S652>/Gain3'
           *  Product: '<S652>/Divide'
           *  Product: '<S652>/Multiply5'
           *  Product: '<S652>/Multiply6'
           *  Sum: '<S652>/Subtract4'
           *  Sum: '<S652>/Subtract5'
           *  Sum: '<S652>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_Divide_lr_idx_2 / FMS_ConstB.d_om
            - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_p * ((rtb_Divide_pr_idx_0
            - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S295>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Return' incorporates:
             *  ActionPort: '<S597>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Delay: '<S660>/Delay'
             *  Delay: '<S681>/Delay'
             *  DiscreteIntegrator: '<S663>/Integrator'
             *  DiscreteIntegrator: '<S663>/Integrator1'
             *  DiscreteIntegrator: '<S677>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S682>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S723>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_on = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S295>/Return' */

            /* SystemReset for IfAction SubSystem: '<S295>/Return' incorporates:
             *  ActionPort: '<S597>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Chart: '<S687>/Motion Status'
             *  Chart: '<S697>/Motion State'
             */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S295>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Return' incorporates:
           *  ActionPort: '<S597>/Action Port'
           */
          /* Delay: '<S681>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S676>/Compare' incorporates:
           *  Constant: '<S727>/Constant'
           *  DiscreteIntegrator: '<S682>/Discrete-Time Integrator'
           *  RelationalOperator: '<S727>/Compare'
           */
          rtb_FixPtRelationalOperator_me =
            (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S677>/Acceleration_Speed' */
          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Acceleration_Speed_PrevResetS_j != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
          }

          if (FMS_DW.Acceleration_Speed_DSTATE_a >= FMS_PARAM.CRUISE_SPEED) {
            FMS_DW.Acceleration_Speed_DSTATE_a = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (FMS_DW.Acceleration_Speed_DSTATE_a <= 0.0F) {
              FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            }
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S697>/Motion State' incorporates:
           *  Constant: '<S697>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S697>/Square'
           *  Math: '<S697>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S697>/Sqrt'
           *  Sum: '<S697>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S696>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_l;
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S696>/Hold Control' incorporates:
               *  ActionPort: '<S699>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S696>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S696>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S696>/Hold Control' incorporates:
             *  ActionPort: '<S699>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S696>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S696>/Brake Control' incorporates:
             *  ActionPort: '<S698>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S696>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S696>/Move Control' incorporates:
               *  ActionPort: '<S700>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S696>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S696>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S696>/Move Control' incorporates:
             *  ActionPort: '<S700>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S696>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S696>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S687>/Motion Status' incorporates:
           *  Abs: '<S687>/Abs'
           *  Constant: '<S687>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S686>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_p;
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S686>/Hold Control' incorporates:
               *  ActionPort: '<S689>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S686>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S686>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S686>/Hold Control' incorporates:
             *  ActionPort: '<S689>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S686>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S686>/Brake Control' incorporates:
             *  ActionPort: '<S688>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S686>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S686>/Move Control' incorporates:
               *  ActionPort: '<S690>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S686>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c);

              /* End of SystemReset for SubSystem: '<S686>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S686>/Move Control' incorporates:
             *  ActionPort: '<S690>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S686>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S686>/Switch Case' */

          /* Switch: '<S658>/Switch' incorporates:
           *  Product: '<S681>/Multiply'
           *  Sum: '<S681>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S696>/Saturation1' */
            if (FMS_B.Merge_m[0] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_c2[0] = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_m[0] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_c2[0] = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_c2[0] = FMS_B.Merge_m[0];
            }

            if (FMS_B.Merge_m[1] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_c2[1] = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_m[1] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_c2[1] = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_c2[1] = FMS_B.Merge_m[1];
            }

            /* End of Saturate: '<S696>/Saturation1' */

            /* Saturate: '<S686>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S686>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S681>/Sum' incorporates:
             *  Delay: '<S681>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S724>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S677>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Square_bg[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S681>/Sum' incorporates:
             *  Delay: '<S681>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S677>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S683>/Sqrt' incorporates:
             *  Math: '<S683>/Square'
             *  Sum: '<S677>/Sum'
             *  Sum: '<S683>/Sum of Elements'
             */
            rtb_Divide_pr_idx_0 = sqrtf(rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Saturation_e * rtb_Saturation_e);

            /* SignalConversion: '<S726>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S726>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S726>/Constant4'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S725>/Gain' incorporates:
             *  DiscreteIntegrator: '<S723>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S723>/Add'
             */
            rtb_Divide_pr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S726>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S726>/Trigonometric Function1'
             */
            rtb_Saturation_e = arm_cos_f32(rtb_Divide_pr_idx_2);
            rtb_VectorConcatenate_ch[4] = rtb_Saturation_e;

            /* Trigonometry: '<S726>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S726>/Trigonometric Function'
             */
            rtb_Divide_pr_idx_2 = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S726>/Gain' incorporates:
             *  Trigonometry: '<S726>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ch[3] = -rtb_Divide_pr_idx_2;

            /* SignalConversion: '<S726>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S726>/Constant3'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Trigonometry: '<S726>/Trigonometric Function' */
            rtb_VectorConcatenate_ch[1] = rtb_Divide_pr_idx_2;

            /* Trigonometry: '<S726>/Trigonometric Function1' */
            rtb_VectorConcatenate_ch[0] = rtb_Saturation_e;

            /* Switch: '<S677>/Switch' incorporates:
             *  Constant: '<S677>/vel'
             */
            if (rtb_Divide_pr_idx_0 > FMS_PARAM.L1) {
              rtb_Divide_pr_idx_2 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S677>/Gain' */
              rtb_Divide_pr_idx_2 = 0.5F * rtb_Divide_pr_idx_0;

              /* Saturate: '<S677>/Saturation' */
              if (rtb_Divide_pr_idx_2 > FMS_PARAM.CRUISE_SPEED) {
                rtb_Divide_pr_idx_2 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Divide_pr_idx_2 < 0.5F) {
                  rtb_Divide_pr_idx_2 = 0.5F;
                }
              }

              /* End of Saturate: '<S677>/Saturation' */
            }

            /* End of Switch: '<S677>/Switch' */

            /* Switch: '<S677>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S677>/Acceleration_Speed'
             *  Sum: '<S677>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Divide_pr_idx_2 < 0.0F)
            {
              rtb_Divide_pr_idx_2 = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S677>/Switch1' */

            /* Sum: '<S724>/Sum of Elements' incorporates:
             *  Math: '<S724>/Math Function'
             */
            rtb_Saturation_e = rtb_Switch_c2[0] * rtb_Switch_c2[0] +
              rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

            /* Math: '<S724>/Math Function1' incorporates:
             *  Sum: '<S724>/Sum of Elements'
             *
             * About '<S724>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Saturation_e = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S724>/Math Function1' */

            /* Switch: '<S724>/Switch' incorporates:
             *  Constant: '<S724>/Constant'
             *  Product: '<S724>/Product'
             */
            if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_0 = rtb_Square_bg[0];
            } else {
              rtb_Divide_pr_idx_0 = 0.0F;
              rtb_Divide_pr_idx_1 = 0.0F;
              rtb_Saturation_e = 1.0F;
            }

            /* End of Switch: '<S724>/Switch' */

            /* Product: '<S722>/Multiply2' incorporates:
             *  Product: '<S724>/Divide'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_0 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_1 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_c2[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 3] *
                rtb_Divide_pr_idx_1 + rtb_VectorConcatenate_ch[rtb_n] *
                rtb_Divide_pr_idx_0;
            }
          }

          /* End of Switch: '<S658>/Switch' */

          /* Delay: '<S660>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S663>/Integrator1' incorporates:
           *  Delay: '<S660>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_on != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S667>/Rem' incorporates:
           *  Constant: '<S667>/Constant1'
           *  DiscreteIntegrator: '<S663>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S662>/Sum'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S667>/Switch' incorporates:
           *  Abs: '<S667>/Abs'
           *  Constant: '<S667>/Constant'
           *  Constant: '<S668>/Constant'
           *  Product: '<S667>/Multiply'
           *  RelationalOperator: '<S668>/Compare'
           *  Sum: '<S667>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S667>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S667>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S667>/Switch' */

          /* Gain: '<S662>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S662>/Saturation' */
          if (rtb_Divide_pr_idx_2 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_pr_idx_2 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Divide_pr_idx_2 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_2 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S662>/Saturation' */

          /* BusAssignment: '<S597>/Bus Assignment1' incorporates:
           *  Constant: '<S597>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_li;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_c2[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_c2[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_c2[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_2;

          /* Math: '<S717>/Math Function1'
           *
           * About '<S717>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S717>/Math Function1' */

          /* Switch: '<S717>/Switch' incorporates:
           *  Constant: '<S717>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S717>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S717>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S597>/Sum' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_i5[0] = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_pr_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Divide_i5[1] = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S674>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S597>/Sum'
           */
          rtb_P_cg[0] = rtb_Divide_pr_idx_0;
          rtb_P_cg[1] = rtb_Divide_pr_idx_1;

          /* Math: '<S674>/Math Function' incorporates:
           *  Sum: '<S597>/Sum'
           */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

          /* Sum: '<S674>/Sum of Elements' */
          rtb_Saturation_e = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S674>/Math Function1' incorporates:
           *  Sum: '<S674>/Sum of Elements'
           *
           * About '<S674>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S674>/Math Function1' */

          /* Switch: '<S674>/Switch' incorporates:
           *  Constant: '<S674>/Constant'
           *  Product: '<S674>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Divide_or = rtb_Divide_pr_idx_2;
          } else {
            rtb_Divide_pr_idx_0 = 0.0F;
            rtb_Divide_pr_idx_1 = 0.0F;
            rtb_Divide_or = 1.0F;
          }

          /* End of Switch: '<S674>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S679>/NearbyRefWP' incorporates:
           *  Constant: '<S597>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_i5,
                          &rtb_Saturation_e);

          /* MATLAB Function: '<S679>/SearchL1RefWP' incorporates:
           *  Constant: '<S597>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_cg, &rtb_Divide_pr_idx_2);

          /* MATLAB Function: '<S679>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S679>/Switch1' incorporates:
           *  Constant: '<S710>/Constant'
           *  RelationalOperator: '<S710>/Compare'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_i5[0];
            rtb_P_cg[1] = rtb_Divide_i5[1];
          } else {
            /* RelationalOperator: '<S709>/Compare' incorporates:
             *  Constant: '<S709>/Constant'
             */
            rtb_Compare_kd = (rtb_Divide_pr_idx_2 >= 0.0F);

            /* Switch: '<S679>/Switch' */
            if (!rtb_Compare_kd) {
              rtb_P_cg[0] = rtb_Square_ds[0];
              rtb_P_cg[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S679>/Switch' */
          }

          /* End of Switch: '<S679>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S680>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Add4_o = rtb_P_cg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_cg[0] = rtb_Add4_o;
          rtb_Subtract_hb[0] = rtb_Add4_o * rtb_Add4_o;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S680>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S718>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Add4_o = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S718>/Sum of Elements' incorporates:
           *  Math: '<S718>/Math Function'
           *  Sum: '<S716>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] + rtb_Add4_o * rtb_Add4_o;

          /* Math: '<S718>/Math Function1' incorporates:
           *  Sum: '<S718>/Sum of Elements'
           *
           * About '<S718>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S718>/Math Function1' */

          /* Switch: '<S718>/Switch' incorporates:
           *  Constant: '<S718>/Constant'
           *  Product: '<S718>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Switch_an[0] = rtb_P_cg[0];
            rtb_Switch_an[1] = rtb_Add4_o;
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S718>/Switch' */

          /* Product: '<S717>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S720>/Sum of Elements' incorporates:
           *  Math: '<S720>/Math Function'
           *  SignalConversion: '<S720>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S720>/Math Function1' incorporates:
           *  Sum: '<S720>/Sum of Elements'
           *
           * About '<S720>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S720>/Math Function1' */

          /* Switch: '<S720>/Switch' incorporates:
           *  Constant: '<S720>/Constant'
           *  Product: '<S720>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Divide_i5[1];
            rtb_Switch_c2[1] = rtb_Divide_i5[0];
            rtb_Switch_c2[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S720>/Switch' */

          /* Product: '<S718>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S721>/Sum of Elements' incorporates:
           *  Math: '<S721>/Math Function'
           *  SignalConversion: '<S721>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S721>/Math Function1' incorporates:
           *  Sum: '<S721>/Sum of Elements'
           *
           * About '<S721>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S721>/Math Function1' */

          /* Switch: '<S721>/Switch' incorporates:
           *  Constant: '<S721>/Constant'
           *  Product: '<S721>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Switch_an[0] = rtb_Divide_i5[1];
            rtb_Switch_an[1] = rtb_Divide_i5[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S721>/Switch' */

          /* Product: '<S721>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S720>/Divide' */
          rtb_P_cg[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S674>/Divide' */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 / rtb_Divide_or;

          /* Product: '<S721>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S720>/Divide' */
          rtb_P_cg[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S674>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 / rtb_Divide_or;

          /* Sum: '<S719>/Subtract' incorporates:
           *  Product: '<S719>/Multiply'
           *  Product: '<S719>/Multiply1'
           */
          rtb_Divide_pr_idx_2 = rtb_Divide_i5[0] * rtb_P_cg[1] - rtb_Divide_i5[1]
            * rtb_P_cg[0];

          /* Signum: '<S714>/Sign1' */
          if (rtb_Divide_pr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S714>/Sign1' */

          /* Switch: '<S714>/Switch2' incorporates:
           *  Constant: '<S714>/Constant4'
           */
          if (rtb_Divide_pr_idx_2 == 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          }

          /* End of Switch: '<S714>/Switch2' */

          /* DotProduct: '<S714>/Dot Product' */
          rtb_Add4_o = rtb_P_cg[0] * rtb_Divide_i5[0] + rtb_P_cg[1] *
            rtb_Divide_i5[1];

          /* Trigonometry: '<S714>/Acos' incorporates:
           *  DotProduct: '<S714>/Dot Product'
           */
          if (rtb_Add4_o > 1.0F) {
            rtb_Add4_o = 1.0F;
          } else {
            if (rtb_Add4_o < -1.0F) {
              rtb_Add4_o = -1.0F;
            }
          }

          /* Product: '<S714>/Multiply' incorporates:
           *  Trigonometry: '<S714>/Acos'
           */
          rtb_Divide_pr_idx_2 *= acosf(rtb_Add4_o);

          /* Saturate: '<S680>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.57079637F) {
            rtb_Divide_pr_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.57079637F) {
              rtb_Divide_pr_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S680>/Saturation' */

          /* Product: '<S680>/Divide' incorporates:
           *  Constant: '<S597>/L1'
           *  Constant: '<S680>/Constant'
           *  Gain: '<S680>/Gain'
           *  Math: '<S680>/Square'
           *  MinMax: '<S680>/Max'
           *  MinMax: '<S680>/Min'
           *  Product: '<S680>/Multiply1'
           *  Sqrt: '<S716>/Sqrt'
           *  Trigonometry: '<S680>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Divide_pr_idx_2) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_e), 0.5F));

          /* Sum: '<S672>/Subtract' incorporates:
           *  Product: '<S672>/Multiply'
           *  Product: '<S672>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S661>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S661>/Sign1' */

          /* Switch: '<S661>/Switch2' incorporates:
           *  Constant: '<S661>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S661>/Switch2' */

          /* DotProduct: '<S661>/Dot Product' */
          rtb_Saturation_e = FMS_ConstB.Divide_m[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S661>/Acos' incorporates:
           *  DotProduct: '<S661>/Dot Product'
           */
          if (rtb_Saturation_e > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            if (rtb_Saturation_e < -1.0F) {
              rtb_Saturation_e = -1.0F;
            }
          }

          /* Product: '<S661>/Multiply' incorporates:
           *  Trigonometry: '<S661>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_Saturation_e);

          /* Math: '<S664>/Rem' incorporates:
           *  Constant: '<S664>/Constant1'
           *  Delay: '<S660>/Delay'
           *  Sum: '<S660>/Sum2'
           */
          rtb_Divide_pr_idx_2 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_nx, 6.28318548F);

          /* Switch: '<S664>/Switch' incorporates:
           *  Abs: '<S664>/Abs'
           *  Constant: '<S664>/Constant'
           *  Constant: '<S670>/Constant'
           *  Product: '<S664>/Multiply'
           *  RelationalOperator: '<S670>/Compare'
           *  Sum: '<S664>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S664>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S664>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S664>/Switch' */

          /* Sum: '<S660>/Sum' incorporates:
           *  Delay: '<S660>/Delay'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S669>/Multiply1' incorporates:
           *  Constant: '<S669>/const1'
           *  DiscreteIntegrator: '<S663>/Integrator'
           */
          rtb_Divide_pr_idx_2 = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S669>/Add' incorporates:
           *  DiscreteIntegrator: '<S663>/Integrator1'
           *  Sum: '<S663>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_b -
            rtb_Divide_pr_idx_1) + rtb_Divide_pr_idx_2;

          /* Signum: '<S669>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S669>/Sign' */

          /* Sum: '<S669>/Add2' incorporates:
           *  Abs: '<S669>/Abs'
           *  Gain: '<S669>/Gain'
           *  Gain: '<S669>/Gain1'
           *  Product: '<S669>/Multiply2'
           *  Product: '<S669>/Multiply3'
           *  Sqrt: '<S669>/Sqrt'
           *  Sum: '<S669>/Add1'
           *  Sum: '<S669>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_n) * FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2;

          /* Sum: '<S669>/Add4' */
          rtb_Divide_pr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S669>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_n;

          /* Sum: '<S669>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_n;

          /* Signum: '<S669>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S669>/Sign1' */

          /* Signum: '<S669>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S669>/Sign2' */

          /* Sum: '<S669>/Add5' incorporates:
           *  Gain: '<S669>/Gain2'
           *  Product: '<S669>/Multiply4'
           *  Sum: '<S669>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_pr_idx_2;

          /* Sum: '<S669>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_n;

          /* Sum: '<S669>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e - FMS_ConstB.d_n;

          /* Product: '<S669>/Divide' */
          d = rtb_Saturation_e / FMS_ConstB.d_n;

          /* Signum: '<S669>/Sign5' incorporates:
           *  Signum: '<S669>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S669>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S669>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Add4_o = rtb_Saturation_e;

            /* Signum: '<S669>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S669>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S660>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S665>/Rem' incorporates:
           *  Constant: '<S665>/Constant1'
           */
          rtb_Saturation_e = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S665>/Switch' incorporates:
           *  Abs: '<S665>/Abs'
           *  Constant: '<S665>/Constant'
           *  Constant: '<S671>/Constant'
           *  Product: '<S665>/Multiply'
           *  RelationalOperator: '<S671>/Compare'
           *  Sum: '<S665>/Add'
           */
          if (fabsf(rtb_Saturation_e) > 3.14159274F) {
            /* Signum: '<S665>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_e;
            }

            /* End of Signum: '<S665>/Sign' */
            rtb_Saturation_e -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S665>/Switch' */

          /* Abs: '<S658>/Abs' */
          rtb_Saturation_e = fabsf(rtb_Saturation_e);

          /* Update for Delay: '<S681>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S682>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S675>/Constant'
           *  RelationalOperator: '<S675>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTATE_a = (uint8_T)((uint32_T)
            (rtb_Saturation_e <= 0.17453292F) +
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a);
          if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S682>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S677>/Acceleration_Speed' incorporates:
           *  Constant: '<S677>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE_a += 0.004F * FMS_PARAM.CRUISE_ACC;
          if (FMS_DW.Acceleration_Speed_DSTATE_a >= FMS_PARAM.CRUISE_SPEED) {
            FMS_DW.Acceleration_Speed_DSTATE_a = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (FMS_DW.Acceleration_Speed_DSTATE_a <= 0.0F) {
              FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            }
          }

          FMS_DW.Acceleration_Speed_PrevResetS_j = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* End of Update for DiscreteIntegrator: '<S677>/Acceleration_Speed' */

          /* Product: '<S681>/Divide1' incorporates:
           *  Constant: '<S681>/Constant'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S681>/Saturation' */
          if (rtb_Saturation_e > 0.314159274F) {
            rtb_Saturation_e = 0.314159274F;
          } else {
            if (rtb_Saturation_e < -0.314159274F) {
              rtb_Saturation_e = -0.314159274F;
            }
          }

          /* End of Saturate: '<S681>/Saturation' */

          /* Update for DiscreteIntegrator: '<S723>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_Saturation_e;

          /* Update for Delay: '<S660>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S663>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S663>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_on = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Signum: '<S669>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S669>/Sign3' */

          /* Signum: '<S669>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S669>/Sign4' */

          /* Update for DiscreteIntegrator: '<S663>/Integrator' incorporates:
           *  Constant: '<S669>/const'
           *  Gain: '<S669>/Gain3'
           *  Product: '<S669>/Multiply5'
           *  Product: '<S669>/Multiply6'
           *  Sum: '<S669>/Subtract4'
           *  Sum: '<S669>/Subtract5'
           *  Sum: '<S669>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_f += ((d - rtb_Add4_o) * FMS_ConstB.Gain4_d *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_f >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_f = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_f <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_f = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S663>/Integrator' */
          /* End of Outputs for SubSystem: '<S295>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Hold' incorporates:
             *  ActionPort: '<S595>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Delay: '<S616>/Delay'
             *  DiscreteIntegrator: '<S628>/Integrator'
             *  DiscreteIntegrator: '<S628>/Integrator1'
             */
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S295>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S295>/Hold' incorporates:
             *  ActionPort: '<S595>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Chart: '<S604>/Motion Status'
             *  Chart: '<S615>/Motion State'
             *  Chart: '<S636>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_il = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S295>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Hold' incorporates:
           *  ActionPort: '<S595>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S604>/Motion Status' incorporates:
           *  Abs: '<S604>/Abs'
           *  Constant: '<S604>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S615>/Motion State' incorporates:
           *  Abs: '<S615>/Abs'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.temporalCounter_i1_il < 255U) {
            FMS_DW.temporalCounter_i1_il++;
          }

          if (FMS_DW.is_active_c15_FMS == 0U) {
            FMS_DW.is_active_c15_FMS = 1U;
            FMS_DW.is_c15_FMS = FMS_IN_Move_p;
            rtb_state_fg = MotionState_Move;
          } else {
            switch (FMS_DW.is_c15_FMS) {
             case FMS_IN_Brake_bw:
              rtb_state_fg = MotionState_Brake;

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              if ((fabsf(FMS_U.INS_Out.r) <= 0.1) ||
                  (FMS_DW.temporalCounter_i1_il >= 250U)) {
                FMS_DW.is_c15_FMS = FMS_IN_Hold_od;
                rtb_state_fg = MotionState_Hold;
              }

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              break;

             case FMS_IN_Hold_od:
              rtb_state_fg = MotionState_Hold;
              break;

             default:
              FMS_DW.is_c15_FMS = FMS_IN_Brake_bw;
              FMS_DW.temporalCounter_i1_il = 0U;
              rtb_state_fg = MotionState_Brake;
              break;
            }
          }

          /* End of Chart: '<S615>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S636>/Motion State' incorporates:
           *  Constant: '<S636>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S636>/Square'
           *  Math: '<S636>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S636>/Sqrt'
           *  Sum: '<S636>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                          &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S635>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_nm;
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;
          switch (rtb_state_og) {
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
              /* SystemReset for IfAction SubSystem: '<S635>/Hold Control' incorporates:
               *  ActionPort: '<S638>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S635>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S635>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S635>/Hold Control' incorporates:
             *  ActionPort: '<S638>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S635>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S635>/Brake Control' incorporates:
             *  ActionPort: '<S637>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S635>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S635>/Move Control' incorporates:
               *  ActionPort: '<S639>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S635>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S635>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S635>/Move Control' incorporates:
             *  ActionPort: '<S639>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S635>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S635>/Switch Case' */

          /* SwitchCase: '<S603>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_k4;
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S603>/Hold Control' incorporates:
               *  ActionPort: '<S606>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S603>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S603>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S603>/Hold Control' incorporates:
             *  ActionPort: '<S606>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S603>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S603>/Brake Control' incorporates:
             *  ActionPort: '<S605>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S603>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S603>/Move Control' incorporates:
               *  ActionPort: '<S607>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S603>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S603>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S603>/Move Control' incorporates:
             *  ActionPort: '<S607>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S603>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S603>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S613>/Compare' incorporates:
           *  Constant: '<S613>/Constant'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S616>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S628>/Integrator1' incorporates:
           *  Delay: '<S616>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Integrator1_PrevResetState != 0)) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          /* SwitchCase: '<S614>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_c;
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          switch (rtb_state_fg) {
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
              /* SystemReset for IfAction SubSystem: '<S614>/Hold Control' incorporates:
               *  ActionPort: '<S618>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S614>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S614>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S614>/Hold Control' incorporates:
             *  ActionPort: '<S618>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S614>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S614>/Brake Control' incorporates:
             *  ActionPort: '<S617>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S614>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S614>/Move Control' incorporates:
               *  ActionPort: '<S619>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S614>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S614>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S614>/Move Control' incorporates:
             *  ActionPort: '<S619>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S614>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S614>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S601>/Switch' incorporates:
           *  Saturate: '<S614>/Saturation'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_yaw >= 0.0F) {
            /* Math: '<S631>/Rem' incorporates:
             *  Constant: '<S631>/Constant1'
             *  DiscreteIntegrator: '<S628>/Integrator1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S627>/Sum'
             */
            rtb_Divide_pr_idx_1 = rt_remf(FMS_DW.Integrator1_DSTATE_jz -
              FMS_U.INS_Out.psi, 6.28318548F);

            /* Switch: '<S631>/Switch' incorporates:
             *  Abs: '<S631>/Abs'
             *  Constant: '<S631>/Constant'
             *  Constant: '<S632>/Constant'
             *  Product: '<S631>/Multiply'
             *  RelationalOperator: '<S632>/Compare'
             *  Sum: '<S631>/Add'
             */
            if (fabsf(rtb_Divide_pr_idx_1) > 3.14159274F) {
              /* Signum: '<S631>/Sign' */
              if (rtb_Divide_pr_idx_1 < 0.0F) {
                rtb_Divide_lr_idx_2 = -1.0F;
              } else if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              } else {
                rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1;
              }

              /* End of Signum: '<S631>/Sign' */
              rtb_Divide_pr_idx_1 -= 6.28318548F * rtb_Divide_lr_idx_2;
            }

            /* End of Switch: '<S631>/Switch' */

            /* Gain: '<S627>/Gain2' */
            rtb_Divide_pr_idx_1 *= FMS_PARAM.YAW_P;

            /* Saturate: '<S627>/Saturation' */
            if (rtb_Divide_pr_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
            } else {
              if (rtb_Divide_pr_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
                rtb_Divide_pr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
              }
            }

            /* End of Saturate: '<S627>/Saturation' */
          } else if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S614>/Saturation' */
            rtb_Divide_pr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S614>/Saturation' */
            rtb_Divide_pr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* Saturate: '<S614>/Saturation' */
            rtb_Divide_pr_idx_1 = FMS_B.Merge_h;
          }

          /* End of Switch: '<S601>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S595>/Bus Assignment' incorporates:
           *  Constant: '<S595>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_1;

          /* Saturate: '<S635>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S595>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S595>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S595>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S595>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S595>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S595>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S635>/Saturation1' */

          /* Saturate: '<S603>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S595>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S595>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S595>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S603>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S629>/Rem' incorporates:
           *  Constant: '<S629>/Constant1'
           *  Delay: '<S616>/Delay'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S616>/Sum2'
           */
          rtb_Divide_pr_idx_1 = rt_remf(FMS_B.Cmd_In.set_yaw -
            FMS_DW.Delay_DSTATE_h, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S629>/Switch' incorporates:
           *  Abs: '<S629>/Abs'
           *  Constant: '<S629>/Constant'
           *  Constant: '<S634>/Constant'
           *  Product: '<S629>/Multiply'
           *  RelationalOperator: '<S634>/Compare'
           *  Sum: '<S629>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_1) > 3.14159274F) {
            /* Signum: '<S629>/Sign' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            } else {
              rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1;
            }

            /* End of Signum: '<S629>/Sign' */
            rtb_Divide_pr_idx_1 -= 6.28318548F * rtb_Divide_lr_idx_2;
          }

          /* End of Switch: '<S629>/Switch' */

          /* Sum: '<S616>/Sum' incorporates:
           *  Delay: '<S616>/Delay'
           */
          rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1 + FMS_DW.Delay_DSTATE_h;

          /* DiscreteIntegrator: '<S628>/Integrator' */
          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Integrator_PrevResetState != 0)) {
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
          }

          if (FMS_DW.Integrator_DSTATE_hi >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_hi = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_hi <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_hi = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* Product: '<S633>/Multiply1' incorporates:
           *  Constant: '<S633>/const1'
           *  DiscreteIntegrator: '<S628>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S633>/Add' incorporates:
           *  DiscreteIntegrator: '<S628>/Integrator1'
           *  Sum: '<S628>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_jz - rtb_Divide_lr_idx_2)
            + rtb_Divide_pr_idx_1;

          /* Signum: '<S633>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S633>/Sign' */

          /* Sum: '<S633>/Add2' incorporates:
           *  Abs: '<S633>/Abs'
           *  Gain: '<S633>/Gain'
           *  Gain: '<S633>/Gain1'
           *  Product: '<S633>/Multiply2'
           *  Product: '<S633>/Multiply3'
           *  Sqrt: '<S633>/Sqrt'
           *  Sum: '<S633>/Add1'
           *  Sum: '<S633>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_k) * FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

          /* Sum: '<S633>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_pr_idx_1;

          /* Sum: '<S633>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_k;

          /* Sum: '<S633>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_k;

          /* Signum: '<S633>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S633>/Sign1' */

          /* Signum: '<S633>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S633>/Sign2' */

          /* Sum: '<S633>/Add5' incorporates:
           *  Gain: '<S633>/Gain2'
           *  Product: '<S633>/Multiply4'
           *  Sum: '<S633>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Update for Delay: '<S616>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S628>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S628>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Sum: '<S633>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_k;

          /* Sum: '<S633>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_k;

          /* Signum: '<S633>/Sign5' incorporates:
           *  Signum: '<S633>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S633>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S633>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S633>/Sign6' */
            rtb_Add4_o = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S633>/Sign5' */

          /* Signum: '<S633>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S633>/Sign3' */

          /* Signum: '<S633>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S633>/Sign4' */

          /* Update for DiscreteIntegrator: '<S628>/Integrator' incorporates:
           *  Constant: '<S633>/const'
           *  Gain: '<S633>/Gain3'
           *  Product: '<S633>/Divide'
           *  Product: '<S633>/Multiply5'
           *  Product: '<S633>/Multiply6'
           *  Sum: '<S633>/Subtract4'
           *  Sum: '<S633>/Subtract5'
           *  Sum: '<S633>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hi += ((rtb_Divide_lr_idx_2 / FMS_ConstB.d_k
            - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_a * ((rtb_Divide_pr_idx_0
            - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_hi >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_hi = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_hi <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_hi = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          FMS_DW.Integrator_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* End of Update for DiscreteIntegrator: '<S628>/Integrator' */
          /* End of Outputs for SubSystem: '<S295>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S295>/Unknown' incorporates:
           *  ActionPort: '<S599>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S295>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
         *  ActionPort: '<S293>/Action Port'
         */
        /* SwitchCase: '<S293>/Switch Case' incorporates:
         *  Math: '<S478>/Math Function'
         *  Sum: '<S434>/Subtract'
         *  Sum: '<S491>/Sum1'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_f;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_f) &&
            (rtPrevAction == 1)) {
          /* Disable for Resettable SubSystem: '<S405>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S456>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S446>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S405>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S293>/Offboard' incorporates:
           *  ActionPort: '<S406>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S572>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S575>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S576>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S576>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S576>/Multiply1' incorporates:
           *  Product: '<S576>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S576>/Divide' incorporates:
           *  Constant: '<S576>/Constant'
           *  Constant: '<S576>/R'
           *  Sqrt: '<S576>/Sqrt'
           *  Sum: '<S576>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S576>/Product3' incorporates:
           *  Constant: '<S576>/Constant1'
           *  Product: '<S576>/Multiply1'
           *  Sum: '<S576>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S576>/Multiply2' incorporates:
           *  Trigonometry: '<S576>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S575>/Sum' incorporates:
           *  Gain: '<S572>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S580>/Abs' incorporates:
           *  Abs: '<S583>/Abs1'
           *  Switch: '<S580>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S580>/Switch1' incorporates:
           *  Abs: '<S580>/Abs'
           *  Bias: '<S580>/Bias2'
           *  Bias: '<S580>/Bias3'
           *  Constant: '<S577>/Constant'
           *  Constant: '<S577>/Constant1'
           *  Constant: '<S582>/Constant'
           *  Gain: '<S580>/Gain1'
           *  Product: '<S580>/Multiply'
           *  RelationalOperator: '<S582>/Compare'
           *  Switch: '<S577>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S583>/Switch1' incorporates:
             *  Bias: '<S583>/Bias2'
             *  Bias: '<S583>/Bias3'
             *  Constant: '<S583>/Constant'
             *  Constant: '<S584>/Constant'
             *  Math: '<S583>/Math Function'
             *  RelationalOperator: '<S584>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S583>/Switch1' */

            /* Signum: '<S580>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S580>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S577>/Sum' incorporates:
           *  Gain: '<S572>/Gain1'
           *  Gain: '<S572>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S575>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S575>/Multiply' incorporates:
           *  Gain: '<S575>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S579>/Switch1' incorporates:
           *  Abs: '<S579>/Abs1'
           *  Bias: '<S579>/Bias2'
           *  Bias: '<S579>/Bias3'
           *  Constant: '<S579>/Constant'
           *  Constant: '<S581>/Constant'
           *  Math: '<S579>/Math Function'
           *  RelationalOperator: '<S581>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S579>/Switch1' */

          /* Product: '<S575>/Multiply' incorporates:
           *  Gain: '<S575>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S553>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S557>/Multiply1'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S566>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S566>/Constant4'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* Trigonometry: '<S566>/Trigonometric Function3' incorporates:
             *  Gain: '<S565>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S566>/Gain' incorporates:
             *  Gain: '<S565>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S566>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ch[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S566>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S566>/Constant3'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Trigonometry: '<S566>/Trigonometric Function' incorporates:
             *  Gain: '<S565>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S566>/Trigonometric Function1' incorporates:
             *  Gain: '<S565>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S566>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S559>/Switch' incorporates:
             *  Constant: '<S574>/Constant'
             *  DataTypeConversion: '<S572>/Data Type Conversion1'
             *  Product: '<S578>/Multiply1'
             *  Product: '<S578>/Multiply2'
             *  RelationalOperator: '<S574>/Compare'
             *  S-Function (sfix_bitop): '<S571>/lat_cmd valid'
             *  Sum: '<S578>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_Saturation_e = (real32_T)(rtb_Multiply_g_idx_0 *
                FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S557>/Multiply' incorporates:
             *  Constant: '<S563>/Constant'
             *  Constant: '<S564>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S556>/Logical Operator'
             *  RelationalOperator: '<S563>/Compare'
             *  RelationalOperator: '<S564>/Compare'
             *  S-Function (sfix_bitop): '<S556>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/x_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S557>/Sum1'
             */
            rtb_Divide_pr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_e -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S566>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S559>/Switch' incorporates:
             *  Constant: '<S574>/Constant'
             *  DataTypeConversion: '<S572>/Data Type Conversion1'
             *  Product: '<S578>/Multiply3'
             *  Product: '<S578>/Multiply4'
             *  RelationalOperator: '<S574>/Compare'
             *  S-Function (sfix_bitop): '<S571>/lon_cmd valid'
             *  Sum: '<S578>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_Saturation_e = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S557>/Multiply' incorporates:
             *  Constant: '<S563>/Constant'
             *  Constant: '<S564>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S556>/Logical Operator'
             *  RelationalOperator: '<S563>/Compare'
             *  RelationalOperator: '<S564>/Compare'
             *  S-Function (sfix_bitop): '<S556>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/y_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S557>/Sum1'
             */
            rtb_Divide_lr_idx_2 = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_e -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S566>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S559>/Switch' incorporates:
             *  Constant: '<S574>/Constant'
             *  DataTypeConversion: '<S572>/Data Type Conversion'
             *  DataTypeConversion: '<S572>/Data Type Conversion1'
             *  Gain: '<S572>/Gain2'
             *  Gain: '<S575>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S574>/Compare'
             *  S-Function (sfix_bitop): '<S571>/alt_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S575>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_Saturation_e = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                -FMS_U.INS_Out.alt_0);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S557>/Multiply' incorporates:
             *  Constant: '<S563>/Constant'
             *  Constant: '<S564>/Constant'
             *  Gain: '<S560>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S556>/Logical Operator'
             *  RelationalOperator: '<S563>/Compare'
             *  RelationalOperator: '<S564>/Compare'
             *  S-Function (sfix_bitop): '<S556>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/z_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S557>/Sum1'
             */
            rtb_Divide_pr_idx_0 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_e -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_ch[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_ch[rtb_n] *
                rtb_Divide_pr_idx_1);
            }

            /* SignalConversion: '<S499>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S499>/Constant4'
             *  MultiPortSwitch: '<S488>/Index Vector'
             *  Product: '<S557>/Multiply1'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* Trigonometry: '<S499>/Trigonometric Function3' incorporates:
             *  Gain: '<S498>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S488>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S499>/Gain' incorporates:
             *  Gain: '<S498>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S488>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S499>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ch[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S499>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S499>/Constant3'
             *  MultiPortSwitch: '<S488>/Index Vector'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Trigonometry: '<S499>/Trigonometric Function' incorporates:
             *  Gain: '<S498>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S488>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S499>/Trigonometric Function1' incorporates:
             *  Gain: '<S498>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S488>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S499>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S488>/Index Vector'
             */
            rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S488>/Multiply' incorporates:
             *  Constant: '<S497>/Constant'
             *  RelationalOperator: '<S497>/Compare'
             *  S-Function (sfix_bitop): '<S494>/ax_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S499>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S488>/Index Vector'
             */
            rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S488>/Multiply' incorporates:
             *  Constant: '<S497>/Constant'
             *  RelationalOperator: '<S497>/Compare'
             *  S-Function (sfix_bitop): '<S494>/ay_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S499>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S488>/Index Vector'
             */
            rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S488>/Multiply' incorporates:
             *  Constant: '<S497>/Constant'
             *  RelationalOperator: '<S497>/Compare'
             *  S-Function (sfix_bitop): '<S494>/az_cmd valid'
             */
            rtb_Divide_pr_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S488>/Index Vector' incorporates:
             *  Product: '<S495>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ee[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_ch[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_ch[rtb_n] *
                rtb_Divide_pr_idx_1);
            }
            break;

           case 1:
            /* SignalConversion: '<S569>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S569>/Constant4'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* Trigonometry: '<S569>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S558>/Data Store Read'
             *  Gain: '<S567>/Gain'
             *  Trigonometry: '<S569>/Trigonometric Function1'
             */
            rtb_Saturation_e = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate_ch[4] = rtb_Saturation_e;

            /* Trigonometry: '<S569>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S558>/Data Store Read'
             *  Gain: '<S567>/Gain'
             *  Trigonometry: '<S569>/Trigonometric Function'
             */
            rtb_Divide_pr_idx_2 = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S569>/Gain' incorporates:
             *  Trigonometry: '<S569>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ch[3] = -rtb_Divide_pr_idx_2;

            /* SignalConversion: '<S569>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S569>/Constant3'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Trigonometry: '<S569>/Trigonometric Function' */
            rtb_VectorConcatenate_ch[1] = rtb_Divide_pr_idx_2;

            /* Trigonometry: '<S569>/Trigonometric Function1' */
            rtb_VectorConcatenate_ch[0] = rtb_Saturation_e;

            /* SignalConversion: '<S570>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S570>/Constant4'
             */
            rtb_MatrixConcatenate1_i[5] = 0.0F;

            /* Gain: '<S568>/Gain' incorporates:
             *  DataStoreRead: '<S558>/Data Store Read'
             *  Gain: '<S500>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S488>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S558>/Subtract'
             */
            rtb_Divide_pr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S570>/Trigonometric Function3' incorporates:
             *  Gain: '<S568>/Gain'
             *  Trigonometry: '<S570>/Trigonometric Function1'
             */
            rtb_Add4_o = arm_cos_f32(rtb_Divide_pr_idx_2);
            rtb_MatrixConcatenate1_i[4] = rtb_Add4_o;

            /* Trigonometry: '<S570>/Trigonometric Function2' incorporates:
             *  Gain: '<S568>/Gain'
             *  Trigonometry: '<S570>/Trigonometric Function'
             */
            rtb_Divide_or = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S570>/Gain' incorporates:
             *  Trigonometry: '<S570>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1_i[3] = -rtb_Divide_or;

            /* SignalConversion: '<S570>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S570>/Constant3'
             */
            rtb_MatrixConcatenate1_i[2] = 0.0F;

            /* Trigonometry: '<S570>/Trigonometric Function' */
            rtb_MatrixConcatenate1_i[1] = rtb_Divide_or;

            /* Trigonometry: '<S570>/Trigonometric Function1' */
            rtb_MatrixConcatenate1_i[0] = rtb_Add4_o;

            /* RelationalOperator: '<S574>/Compare' incorporates:
             *  Constant: '<S574>/Constant'
             *  S-Function (sfix_bitop): '<S571>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S571>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S571>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S572>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S572>/Data Type Conversion'
             *  Gain: '<S572>/Gain2'
             *  Gain: '<S575>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S578>/Multiply1'
             *  Product: '<S578>/Multiply2'
             *  Product: '<S578>/Multiply3'
             *  Product: '<S578>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S575>/Sum1'
             *  Sum: '<S578>/Sum2'
             *  Sum: '<S578>/Sum3'
             */
            rtb_Switch_c2[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S559>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S569>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S570>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S558>/Sum' incorporates:
             *  DataStoreRead: '<S558>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S569>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S570>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S558>/Sum' incorporates:
             *  DataStoreRead: '<S558>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S569>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S570>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S558>/Sum' incorporates:
             *  DataStoreRead: '<S558>/Data Store Read'
             *  Gain: '<S560>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S563>/Compare' incorporates:
             *  Constant: '<S563>/Constant'
             *  S-Function (sfix_bitop): '<S556>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S564>/Compare' incorporates:
             *  Constant: '<S564>/Constant'
             *  S-Function (sfix_bitop): '<S556>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S558>/Sum2' incorporates:
               *  Product: '<S558>/Multiply2'
               *  Switch: '<S559>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_Saturation_e = rtb_Switch_c2[rtb_n];
              } else {
                rtb_Saturation_e = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              /* Product: '<S558>/Multiply' incorporates:
               *  Logic: '<S556>/Logical Operator'
               *  Product: '<S558>/Multiply2'
               *  Sum: '<S558>/Sum'
               *  Sum: '<S558>/Sum2'
               */
              rtb_Switch_ee[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ?
                rtb_Saturation_e - ((rtb_VectorConcatenate_ch[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_ch[rtb_n] *
                rtb_Divide_pr_idx_1) + rtb_VectorConcatenate_ch[rtb_n + 6] *
                                    rtb_Divide_pr_idx_0) : 0.0F;
            }

            /* SignalConversion: '<S501>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S501>/Constant4'
             *  MultiPortSwitch: '<S488>/Index Vector'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* Trigonometry: '<S501>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S488>/Index Vector'
             */
            rtb_VectorConcatenate_ch[4] = arm_cos_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S501>/Gain' incorporates:
             *  MultiPortSwitch: '<S488>/Index Vector'
             *  Trigonometry: '<S501>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ch[3] = -arm_sin_f32(rtb_Divide_pr_idx_2);

            /* SignalConversion: '<S501>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S501>/Constant3'
             *  MultiPortSwitch: '<S488>/Index Vector'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Trigonometry: '<S501>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S488>/Index Vector'
             */
            rtb_VectorConcatenate_ch[1] = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Trigonometry: '<S501>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S488>/Index Vector'
             */
            rtb_VectorConcatenate_ch[0] = arm_cos_f32(rtb_Divide_pr_idx_2);

            /* Product: '<S488>/Multiply' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S497>/Compare' incorporates:
             *  Constant: '<S497>/Constant'
             *  S-Function (sfix_bitop): '<S494>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S494>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S494>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S501>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S488>/Index Vector'
               */
              rtb_VectorConcatenate_ch[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S488>/Multiply' */
              rtb_Switch_c2[rtb_n] = tmp[rtb_n] ?
                rtb_MatrixConcatenate1_i_0[rtb_n] : 0.0F;
              rtb_Switch_an[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n + 6] *
                rtb_Switch_ee[2] + (rtb_MatrixConcatenate1_i[rtb_n + 3] *
                                    rtb_Switch_ee[1] +
                                    rtb_MatrixConcatenate1_i[rtb_n] *
                                    rtb_Switch_ee[0]);
            }

            /* MultiPortSwitch: '<S488>/Index Vector' incorporates:
             *  Product: '<S496>/Multiply3'
             *  Product: '<S558>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ee[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 6] *
                rtb_Switch_c2[2] + (rtb_VectorConcatenate_ch[rtb_n + 3] *
                                    rtb_Switch_c2[1] +
                                    rtb_VectorConcatenate_ch[rtb_n] *
                                    rtb_Switch_c2[0]);
            }
            break;

           default:
            /* SignalConversion: '<S562>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S562>/Constant4'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* Trigonometry: '<S562>/Trigonometric Function3' incorporates:
             *  Gain: '<S561>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S562>/Gain' incorporates:
             *  Gain: '<S561>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S562>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ch[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S562>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S562>/Constant3'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Trigonometry: '<S562>/Trigonometric Function' incorporates:
             *  Gain: '<S561>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S562>/Trigonometric Function1' incorporates:
             *  Gain: '<S561>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* S-Function (sfix_bitop): '<S571>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S556>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S574>/Compare' incorporates:
             *  Constant: '<S574>/Constant'
             *  S-Function (sfix_bitop): '<S571>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S571>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S556>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S574>/Compare' incorporates:
             *  Constant: '<S574>/Constant'
             *  S-Function (sfix_bitop): '<S571>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S571>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S556>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S574>/Compare' incorporates:
             *  Constant: '<S574>/Constant'
             *  S-Function (sfix_bitop): '<S571>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S572>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S572>/Data Type Conversion'
             *  Gain: '<S572>/Gain2'
             *  Gain: '<S575>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S578>/Multiply1'
             *  Product: '<S578>/Multiply2'
             *  Product: '<S578>/Multiply3'
             *  Product: '<S578>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S575>/Sum1'
             *  Sum: '<S578>/Sum2'
             *  Sum: '<S578>/Sum3'
             */
            rtb_Switch_c2[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S559>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S562>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_g[0];

            /* Sum: '<S555>/Sum' incorporates:
             *  DataStoreRead: '<S555>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S562>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_g[1];

            /* Sum: '<S555>/Sum' incorporates:
             *  DataStoreRead: '<S555>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S562>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Sum: '<S555>/Sum' incorporates:
             *  DataStoreRead: '<S555>/Data Store Read'
             *  Gain: '<S560>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S563>/Compare' incorporates:
             *  Constant: '<S563>/Constant'
             *  S-Function (sfix_bitop): '<S556>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S556>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S564>/Compare' incorporates:
             *  Constant: '<S564>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S555>/Sum2' incorporates:
             *  Logic: '<S556>/Logical Operator'
             *  Product: '<S555>/Multiply'
             *  Product: '<S555>/Multiply2'
             *  Sum: '<S555>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S559>/Switch' incorporates:
               *  Product: '<S555>/Multiply2'
               */
              if (tmp[rtb_n]) {
                rtb_Saturation_e = rtb_Switch_c2[rtb_n];
              } else {
                rtb_Saturation_e = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              rtb_Switch_an[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ?
                rtb_Saturation_e - ((rtb_VectorConcatenate_ch[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_ch[rtb_n] *
                rtb_Divide_pr_idx_1) + rtb_VectorConcatenate_ch[rtb_n + 6] *
                                    rtb_Divide_pr_idx_0) : 0.0F;
            }

            /* End of Sum: '<S555>/Sum2' */

            /* MultiPortSwitch: '<S488>/Index Vector' incorporates:
             *  Constant: '<S497>/Constant'
             *  Product: '<S488>/Multiply'
             *  RelationalOperator: '<S497>/Compare'
             *  S-Function (sfix_bitop): '<S494>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S494>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S494>/az_cmd valid'
             */
            rtb_Switch_ee[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ee[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ee[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S553>/Index Vector' */

          /* Sum: '<S549>/Sum1' incorporates:
           *  Constant: '<S549>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S549>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S550>/Abs' */
          rtb_Divide_pr_idx_1 = fabsf(rtb_Divide_pr_idx_2);

          /* Switch: '<S550>/Switch' incorporates:
           *  Constant: '<S550>/Constant'
           *  Constant: '<S551>/Constant'
           *  Product: '<S550>/Multiply'
           *  RelationalOperator: '<S551>/Compare'
           *  Sum: '<S550>/Subtract'
           */
          if (rtb_Divide_pr_idx_1 > 3.14159274F) {
            /* Signum: '<S550>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_2 > 0.0F) {
                rtb_Divide_pr_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S550>/Sign' */
            rtb_Divide_pr_idx_2 *= rtb_Divide_pr_idx_1 - 6.28318548F;
          }

          /* End of Switch: '<S550>/Switch' */

          /* Saturate: '<S549>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 0.314159274F) {
            rtb_Divide_pr_idx_2 = 0.314159274F;
          } else {
            if (rtb_Divide_pr_idx_2 < -0.314159274F) {
              rtb_Divide_pr_idx_2 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S549>/Saturation' */

          /* Gain: '<S546>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S490>/Sum' incorporates:
           *  Constant: '<S548>/Constant'
           *  Constant: '<S552>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S546>/Multiply2'
           *  Product: '<S547>/Multiply1'
           *  RelationalOperator: '<S548>/Compare'
           *  RelationalOperator: '<S552>/Compare'
           *  S-Function (sfix_bitop): '<S546>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S547>/psi_rate_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          rtb_Saturation_e = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                              rtb_Divide_pr_idx_2 : 0.0F) +
            ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S553>/Gain1' */
          rtb_Square_bg[0] = FMS_PARAM.XY_P * rtb_Switch_an[0];
          rtb_Square_bg[1] = FMS_PARAM.XY_P * rtb_Switch_an[1];

          /* Gain: '<S553>/Gain2' */
          rtb_Divide_pr_idx_2 = FMS_PARAM.Z_P * rtb_Switch_an[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S554>/Index Vector' incorporates:
           *  Constant: '<S590>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S554>/Multiply'
           *  Product: '<S587>/Multiply'
           *  Product: '<S588>/Multiply3'
           *  RelationalOperator: '<S590>/Compare'
           *  S-Function (sfix_bitop): '<S586>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S586>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S586>/w_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S592>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S592>/Constant4'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* Trigonometry: '<S592>/Trigonometric Function3' incorporates:
             *  Gain: '<S591>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S592>/Gain' incorporates:
             *  Gain: '<S591>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S592>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ch[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S592>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S592>/Constant3'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Trigonometry: '<S592>/Trigonometric Function' incorporates:
             *  Gain: '<S591>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S592>/Trigonometric Function1' incorporates:
             *  Gain: '<S591>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_ch[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S592>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S554>/Multiply' incorporates:
             *  Constant: '<S590>/Constant'
             *  RelationalOperator: '<S590>/Compare'
             *  S-Function (sfix_bitop): '<S586>/u_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S592>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S554>/Multiply' incorporates:
             *  Constant: '<S590>/Constant'
             *  RelationalOperator: '<S590>/Compare'
             *  S-Function (sfix_bitop): '<S586>/v_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S592>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S554>/Multiply' incorporates:
             *  Constant: '<S590>/Constant'
             *  RelationalOperator: '<S590>/Compare'
             *  S-Function (sfix_bitop): '<S586>/w_cmd valid'
             */
            rtb_Divide_pr_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_ch[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_ch[rtb_n] *
                rtb_Divide_pr_idx_1);
            }
            break;

           case 1:
            /* SignalConversion: '<S594>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S594>/Constant4'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* Gain: '<S593>/Gain' incorporates:
             *  DataStoreRead: '<S588>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S588>/Subtract'
             */
            rtb_Divide_pr_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S594>/Trigonometric Function3' incorporates:
             *  Gain: '<S593>/Gain'
             */
            rtb_VectorConcatenate_ch[4] = arm_cos_f32(rtb_Divide_pr_idx_1);

            /* Gain: '<S594>/Gain' incorporates:
             *  Gain: '<S593>/Gain'
             *  Trigonometry: '<S594>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ch[3] = -arm_sin_f32(rtb_Divide_pr_idx_1);

            /* SignalConversion: '<S594>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S594>/Constant3'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Trigonometry: '<S594>/Trigonometric Function' incorporates:
             *  Gain: '<S593>/Gain'
             */
            rtb_VectorConcatenate_ch[1] = arm_sin_f32(rtb_Divide_pr_idx_1);

            /* Trigonometry: '<S594>/Trigonometric Function1' incorporates:
             *  Gain: '<S593>/Gain'
             */
            rtb_VectorConcatenate_ch[0] = arm_cos_f32(rtb_Divide_pr_idx_1);

            /* SignalConversion: '<S594>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Product: '<S554>/Multiply' incorporates:
             *  Constant: '<S590>/Constant'
             *  RelationalOperator: '<S590>/Compare'
             *  S-Function (sfix_bitop): '<S586>/u_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S594>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Product: '<S554>/Multiply' incorporates:
             *  Constant: '<S590>/Constant'
             *  RelationalOperator: '<S590>/Compare'
             *  S-Function (sfix_bitop): '<S586>/v_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S594>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Product: '<S554>/Multiply' incorporates:
             *  Constant: '<S590>/Constant'
             *  RelationalOperator: '<S590>/Compare'
             *  S-Function (sfix_bitop): '<S586>/w_cmd valid'
             */
            rtb_Divide_pr_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_ch[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_ch[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_ch[rtb_n] *
                rtb_Divide_pr_idx_1);
            }
            break;

           default:
            rtb_Switch_an[0] = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;
            rtb_Switch_an[1] = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;
            rtb_Switch_an[2] = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S554>/Index Vector' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Switch_an[0] += rtb_Square_bg[0];
          rtb_Switch_an[1] += rtb_Square_bg[1];

          /* Sum: '<S491>/Sum1' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + rtb_Switch_an[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S509>/Switch' incorporates:
           *  Constant: '<S524>/Constant'
           *  Constant: '<S526>/Constant'
           *  Constant: '<S527>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S524>/Compare'
           *  RelationalOperator: '<S526>/Compare'
           *  RelationalOperator: '<S527>/Compare'
           *  S-Function (sfix_bitop): '<S509>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S509>/y_v_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S509>/Logical Operator' incorporates:
             *  Constant: '<S525>/Constant'
             *  Constant: '<S526>/Constant'
             *  Constant: '<S527>/Constant'
             *  RelationalOperator: '<S525>/Compare'
             *  RelationalOperator: '<S526>/Compare'
             *  RelationalOperator: '<S527>/Compare'
             *  S-Function (sfix_bitop): '<S509>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S509>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S509>/y_v_cmd'
             */
            rtb_Compare_kd = (((FMS_U.Auto_Cmd.cmd_mask & 3072U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 16640U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_Compare_kd;
          } else {
            rtb_Compare_kd = ((FMS_U.Auto_Cmd.cmd_mask & 8320U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 16640U)
              > 0U);
          }

          /* End of Switch: '<S509>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S489>/u_cmd_valid' */
          /* MATLAB Function: '<S521>/bit_shift' incorporates:
           *  DataTypeConversion: '<S489>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_Compare_kd << 6);

          /* End of Outputs for SubSystem: '<S489>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S489>/v_cmd_valid' */
          /* MATLAB Function: '<S522>/bit_shift' incorporates:
           *  DataTypeConversion: '<S489>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

          /* End of Outputs for SubSystem: '<S489>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S510>/Switch' incorporates:
           *  Constant: '<S529>/Constant'
           *  Constant: '<S530>/Constant'
           *  Constant: '<S532>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S529>/Compare'
           *  RelationalOperator: '<S530>/Compare'
           *  RelationalOperator: '<S532>/Compare'
           *  S-Function (sfix_bitop): '<S510>/ax_cmd'
           *  S-Function (sfix_bitop): '<S510>/ay_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S510>/Logical Operator' incorporates:
             *  Constant: '<S530>/Constant'
             *  Constant: '<S532>/Constant'
             *  RelationalOperator: '<S530>/Compare'
             *  RelationalOperator: '<S532>/Compare'
             *  S-Function (sfix_bitop): '<S510>/ax_cmd'
             *  S-Function (sfix_bitop): '<S510>/ay_cmd'
             */
            rtb_Compare_kd = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_Compare_kd;
          } else {
            rtb_Compare_kd = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S510>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S406>/Bus Assignment' incorporates:
           *  Constant: '<S406>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dg;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_Y.FMS_Out.p_cmd = FMS_U.Auto_Cmd.p_cmd;
          FMS_Y.FMS_Out.q_cmd = FMS_U.Auto_Cmd.q_cmd;
          FMS_Y.FMS_Out.r_cmd = FMS_U.Auto_Cmd.r_cmd;
          FMS_Y.FMS_Out.phi_cmd = FMS_U.Auto_Cmd.phi_cmd;
          FMS_Y.FMS_Out.theta_cmd = FMS_U.Auto_Cmd.theta_cmd;
          FMS_Y.FMS_Out.throttle_cmd = FMS_U.Auto_Cmd.throttle_cmd;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          FMS_Y.FMS_Out.ax_cmd = rtb_Switch_ee[0];
          FMS_Y.FMS_Out.ay_cmd = rtb_Switch_ee[1];
          FMS_Y.FMS_Out.az_cmd = rtb_Switch_ee[2];

          /* Saturate: '<S490>/Saturation' */
          if (rtb_Saturation_e > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S490>/Saturation' */

          /* Saturate: '<S491>/Saturation2' */
          if (rtb_Switch_an[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_an[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_an[0];
          }

          /* End of Saturate: '<S491>/Saturation2' */

          /* Saturate: '<S491>/Saturation1' */
          if (rtb_Switch_an[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_an[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_an[1];
          }

          /* End of Saturate: '<S491>/Saturation1' */

          /* Saturate: '<S491>/Saturation3' */
          if (rtb_Divide_pr_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_pr_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S406>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Divide_pr_idx_1;
          }

          /* End of Saturate: '<S491>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S489>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S489>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S489>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S489>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S489>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S489>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S489>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S489>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S489>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S489>/throttle_cmd_valid' */
          /* BusAssignment: '<S406>/Bus Assignment' incorporates:
           *  Constant: '<S502>/Constant'
           *  Constant: '<S503>/Constant'
           *  Constant: '<S504>/Constant'
           *  Constant: '<S505>/Constant'
           *  Constant: '<S506>/Constant'
           *  Constant: '<S507>/Constant'
           *  Constant: '<S508>/Constant'
           *  Constant: '<S528>/Constant'
           *  Constant: '<S531>/Constant'
           *  DataTypeConversion: '<S489>/Data Type Conversion10'
           *  DataTypeConversion: '<S489>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S511>/bit_shift'
           *  MATLAB Function: '<S512>/bit_shift'
           *  MATLAB Function: '<S513>/bit_shift'
           *  MATLAB Function: '<S515>/bit_shift'
           *  MATLAB Function: '<S516>/bit_shift'
           *  MATLAB Function: '<S517>/bit_shift'
           *  MATLAB Function: '<S518>/bit_shift'
           *  MATLAB Function: '<S519>/bit_shift'
           *  MATLAB Function: '<S520>/bit_shift'
           *  MATLAB Function: '<S523>/bit_shift'
           *  RelationalOperator: '<S502>/Compare'
           *  RelationalOperator: '<S503>/Compare'
           *  RelationalOperator: '<S504>/Compare'
           *  RelationalOperator: '<S505>/Compare'
           *  RelationalOperator: '<S506>/Compare'
           *  RelationalOperator: '<S507>/Compare'
           *  RelationalOperator: '<S508>/Compare'
           *  RelationalOperator: '<S528>/Compare'
           *  RelationalOperator: '<S531>/Compare'
           *  S-Function (sfix_bitop): '<S489>/p_cmd'
           *  S-Function (sfix_bitop): '<S489>/phi_cmd'
           *  S-Function (sfix_bitop): '<S489>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S489>/q_cmd'
           *  S-Function (sfix_bitop): '<S489>/r_cmd'
           *  S-Function (sfix_bitop): '<S489>/theta_cmd'
           *  S-Function (sfix_bitop): '<S489>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S509>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S510>/az_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           *  Sum: '<S489>/Add'
           */
          FMS_Y.FMS_Out.cmd_mask = (uint16_T)((((((((((((uint32_T)(uint16_T)
            ((uint32_T)(((FMS_U.Auto_Cmd.cmd_mask & 2U) > 0U) << 1) +
             ((FMS_U.Auto_Cmd.cmd_mask & 1U) > 0U)) + (uint16_T)
            (((FMS_U.Auto_Cmd.cmd_mask & 4U) > 0U) << 2)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 8U) > 0U) << 3)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 16U) > 0U) << 4)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 96U) > 0U) << 5)) + rtb_y_aw) +
            rtb_y_cc) + (((FMS_U.Auto_Cmd.cmd_mask & 37376U) > 0U) << 8)) +
            (rtb_Compare_kd << 9)) + (rtb_FixPtRelationalOperator_me << 10)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U) << 11)) +
            (((FMS_U.Auto_Cmd.cmd_mask & 524288U) > 0U) << 12));

          /* End of Outputs for SubSystem: '<S489>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S489>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S489>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S489>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S489>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S489>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S489>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S489>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S489>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S489>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S293>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S293>/Mission' incorporates:
             *  ActionPort: '<S405>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S293>/Switch Case' incorporates:
             *  UnitDelay: '<S408>/Delay Input1'
             *
             * Block description for '<S408>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S293>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S293>/Mission' incorporates:
             *  ActionPort: '<S405>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S405>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S293>/Switch Case' incorporates:
             *  Chart: '<S447>/Motion Status'
             *  Chart: '<S457>/Motion State'
             *  Delay: '<S413>/Delay'
             *  Delay: '<S435>/Delay'
             *  DiscreteIntegrator: '<S416>/Integrator'
             *  DiscreteIntegrator: '<S416>/Integrator1'
             *  DiscreteIntegrator: '<S431>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S436>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S483>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;
            FMS_DW.l1_heading = 0.0F;
            FMS_DW.icLoad_m = 1U;
            FMS_DW.Integrator1_IC_LOADING = 1U;
            FMS_DW.Integrator_DSTATE_m = 0.0F;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);

            /* End of SystemReset for SubSystem: '<S405>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S293>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S293>/Mission' incorporates:
           *  ActionPort: '<S405>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S408>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S408>/Delay Input1'
           *
           * Block description for '<S408>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S405>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S409>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S456>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S446>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for Delay: '<S435>/Delay' */
            FMS_DW.icLoad = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S436>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S431>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S483>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S413>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S416>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S416>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S457>/Motion State' */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S447>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S435>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S431>/Switch2' incorporates:
           *  Constant: '<S431>/vel'
           *  Constant: '<S440>/Constant'
           *  RelationalOperator: '<S440>/Compare'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            d = FMS_B.Cmd_In.set_speed;
          } else {
            d = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S431>/Switch2' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S436>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S408>/Delay Input1'
           *
           * Block description for '<S408>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTAT_kf;

          /* RelationalOperator: '<S430>/Compare' incorporates:
           *  Constant: '<S487>/Constant'
           *  RelationalOperator: '<S487>/Compare'
           *  UnitDelay: '<S408>/Delay Input1'
           *
           * Block description for '<S408>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S431>/Acceleration_Speed' */
          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S457>/Motion State' incorporates:
           *  Constant: '<S457>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S457>/Square'
           *  Math: '<S457>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S457>/Sqrt'
           *  Sum: '<S457>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S456>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S466>/Integrator1'
           *  Gain: '<S460>/Gain6'
           *  Gain: '<S464>/Gain'
           *  Gain: '<S465>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S466>/Subtract'
           *  Sum: '<S467>/Add'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_fg;
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;
          switch (rtb_state_l4) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_fg = 0;
            break;

           case MotionState_Brake:
            FMS_DW.SwitchCase_ActiveSubsystem_fg = 1;
            break;

           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_fg = 2;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_fg) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S456>/Hold Control' incorporates:
               *  ActionPort: '<S459>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S456>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S456>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S456>/Hold Control' incorporates:
             *  ActionPort: '<S459>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S456>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S456>/Brake Control' incorporates:
             *  ActionPort: '<S458>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S456>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S456>/Move Control' incorporates:
               *  ActionPort: '<S460>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S456>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S466>/Integrator'
               *  DiscreteIntegrator: '<S466>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S456>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S456>/Move Control' incorporates:
             *  ActionPort: '<S460>/Action Port'
             */
            /* SignalConversion: '<S460>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S466>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S467>/Multiply1' incorporates:
             *  Constant: '<S467>/const1'
             *  DiscreteIntegrator: '<S466>/Integrator'
             */
            rtb_Subtract_hb[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S460>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S466>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S467>/Multiply1' incorporates:
             *  Constant: '<S467>/const1'
             *  DiscreteIntegrator: '<S466>/Integrator'
             */
            rtb_Subtract_hb[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S464>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch -
                FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch -
                (-FMS_PARAM.PITCH_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S467>/Add' incorporates:
             *  DiscreteIntegrator: '<S466>/Integrator1'
             *  Gain: '<S460>/Gain6'
             *  Gain: '<S464>/Gain'
             *  Sum: '<S466>/Subtract'
             */
            rtb_Divide_i5[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S465>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S467>/Add' incorporates:
             *  DiscreteIntegrator: '<S466>/Integrator1'
             *  Gain: '<S460>/Gain6'
             *  Gain: '<S465>/Gain'
             *  Sum: '<S466>/Subtract'
             */
            rtb_Divide_i5[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S464>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch -
                FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch -
                (-FMS_PARAM.PITCH_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F
              - FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Signum: '<S467>/Sign' incorporates:
             *  DiscreteIntegrator: '<S466>/Integrator1'
             *  Gain: '<S460>/Gain6'
             *  Gain: '<S464>/Gain'
             *  Sum: '<S466>/Subtract'
             *  Sum: '<S467>/Add'
             */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S467>/Add2' incorporates:
             *  Abs: '<S467>/Abs'
             *  Gain: '<S467>/Gain'
             *  Gain: '<S467>/Gain1'
             *  Product: '<S467>/Multiply2'
             *  Product: '<S467>/Multiply3'
             *  Signum: '<S467>/Sign'
             *  Sqrt: '<S467>/Sqrt'
             *  Sum: '<S467>/Add1'
             *  Sum: '<S467>/Subtract'
             */
            rtb_Add4_o = (sqrtf((8.0F * fabsf(rtb_Divide_i5[0]) +
                                 FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                          FMS_ConstB.d_oe) * 0.5F * rtb_Divide_pr_idx_0 +
              rtb_Subtract_hb[0];

            /* Sum: '<S467>/Add3' incorporates:
             *  Signum: '<S467>/Sign'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_i5[0] + FMS_ConstB.d_oe;

            /* Sum: '<S467>/Subtract1' incorporates:
             *  Signum: '<S467>/Sign'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] - FMS_ConstB.d_oe;

            /* Signum: '<S467>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S467>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S467>/Add5' incorporates:
             *  Gain: '<S467>/Gain2'
             *  Product: '<S467>/Multiply4'
             *  Signum: '<S467>/Sign'
             *  Sum: '<S467>/Add2'
             *  Sum: '<S467>/Add4'
             *  Sum: '<S467>/Subtract2'
             */
            rtb_Add4_o += ((rtb_Divide_i5[0] - rtb_Add4_o) + rtb_Subtract_hb[0])
              * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F);

            /* Update for DiscreteIntegrator: '<S466>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S466>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S467>/Sign4' incorporates:
             *  Sum: '<S467>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Add4_o - FMS_ConstB.d_oe;

            /* Signum: '<S467>/Sign3' incorporates:
             *  Sum: '<S467>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Add4_o + FMS_ConstB.d_oe;

            /* Signum: '<S467>/Sign5' */
            if (rtb_Add4_o < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else if (rtb_Add4_o > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Add4_o;
            }

            /* Signum: '<S467>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S467>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S467>/Sign6' */
            if (rtb_Add4_o < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Add4_o > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Add4_o;
            }

            /* Update for DiscreteIntegrator: '<S466>/Integrator' incorporates:
             *  Constant: '<S467>/const'
             *  Gain: '<S467>/Gain3'
             *  Product: '<S467>/Divide'
             *  Product: '<S467>/Multiply5'
             *  Product: '<S467>/Multiply6'
             *  Sum: '<S467>/Subtract4'
             *  Sum: '<S467>/Subtract5'
             *  Sum: '<S467>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Add4_o / FMS_ConstB.d_oe -
              rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_g * ((rtb_Divide_pr_idx_0
              - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Saturation_e * 58.836F) *
              0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S465>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F
              - FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Signum: '<S467>/Sign' incorporates:
             *  DiscreteIntegrator: '<S466>/Integrator1'
             *  Gain: '<S460>/Gain6'
             *  Gain: '<S465>/Gain'
             *  Sum: '<S466>/Subtract'
             *  Sum: '<S467>/Add'
             */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S467>/Add2' incorporates:
             *  Abs: '<S467>/Abs'
             *  Gain: '<S467>/Gain'
             *  Gain: '<S467>/Gain1'
             *  Product: '<S467>/Multiply2'
             *  Product: '<S467>/Multiply3'
             *  Signum: '<S467>/Sign'
             *  Sqrt: '<S467>/Sqrt'
             *  Sum: '<S467>/Add1'
             *  Sum: '<S467>/Subtract'
             */
            rtb_Add4_o = (sqrtf((8.0F * fabsf(rtb_Divide_i5[1]) +
                                 FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                          FMS_ConstB.d_oe) * 0.5F * rtb_Divide_pr_idx_0 +
              rtb_Subtract_hb[1];

            /* Sum: '<S467>/Add3' incorporates:
             *  Signum: '<S467>/Sign'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_i5[1] + FMS_ConstB.d_oe;

            /* Sum: '<S467>/Subtract1' incorporates:
             *  Signum: '<S467>/Sign'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_i5[1] - FMS_ConstB.d_oe;

            /* Signum: '<S467>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S467>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S467>/Add5' incorporates:
             *  Gain: '<S467>/Gain2'
             *  Product: '<S467>/Multiply4'
             *  Signum: '<S467>/Sign'
             *  Sum: '<S467>/Add2'
             *  Sum: '<S467>/Add4'
             *  Sum: '<S467>/Subtract2'
             */
            rtb_Add4_o += ((rtb_Divide_i5[1] - rtb_Add4_o) + rtb_Subtract_hb[1])
              * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F);

            /* Update for DiscreteIntegrator: '<S466>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S466>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S467>/Sign4' incorporates:
             *  Sum: '<S467>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Add4_o - FMS_ConstB.d_oe;

            /* Signum: '<S467>/Sign3' incorporates:
             *  Sum: '<S467>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Add4_o + FMS_ConstB.d_oe;

            /* Signum: '<S467>/Sign5' */
            if (rtb_Add4_o < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else if (rtb_Add4_o > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Add4_o;
            }

            /* Signum: '<S467>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S467>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S467>/Sign6' */
            if (rtb_Add4_o < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Add4_o > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Add4_o;
            }

            /* Update for DiscreteIntegrator: '<S466>/Integrator' incorporates:
             *  Constant: '<S467>/const'
             *  Gain: '<S467>/Gain3'
             *  Product: '<S467>/Divide'
             *  Product: '<S467>/Multiply5'
             *  Product: '<S467>/Multiply6'
             *  Sum: '<S467>/Subtract4'
             *  Sum: '<S467>/Subtract5'
             *  Sum: '<S467>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Add4_o / FMS_ConstB.d_oe -
              rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_g * ((rtb_Divide_pr_idx_0
              - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Saturation_e * 58.836F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S456>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S456>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S447>/Motion Status' incorporates:
           *  Abs: '<S447>/Abs'
           *  Constant: '<S447>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S446>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_h;
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S446>/Hold Control' incorporates:
               *  ActionPort: '<S449>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S446>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S446>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S446>/Hold Control' incorporates:
             *  ActionPort: '<S449>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S446>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S446>/Brake Control' incorporates:
             *  ActionPort: '<S448>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S446>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S446>/Move Control' incorporates:
               *  ActionPort: '<S450>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S446>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S453>/Integrator'
               *  DiscreteIntegrator: '<S453>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S446>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S446>/Move Control' incorporates:
             *  ActionPort: '<S450>/Action Port'
             */
            /* Product: '<S454>/Multiply1' incorporates:
             *  Constant: '<S454>/const1'
             *  DiscreteIntegrator: '<S453>/Integrator'
             */
            rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S452>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle -
                FMS_PARAM.THROTTLE_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ)
            {
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle -
                (-FMS_PARAM.THROTTLE_DZ);
            }

            /* End of DeadZone: '<S452>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S454>/Add' incorporates:
             *  DiscreteIntegrator: '<S453>/Integrator1'
             *  Gain: '<S450>/Gain1'
             *  Gain: '<S452>/Gain'
             *  Sum: '<S453>/Subtract'
             */
            rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_Saturation_e * -FMS_PARAM.VEL_Z_LIM)
              + rtb_Divide_pr_idx_1;

            /* Signum: '<S454>/Sign' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_0;
            }

            /* End of Signum: '<S454>/Sign' */

            /* Sum: '<S454>/Add2' incorporates:
             *  Abs: '<S454>/Abs'
             *  Gain: '<S454>/Gain'
             *  Gain: '<S454>/Gain1'
             *  Product: '<S454>/Multiply2'
             *  Product: '<S454>/Multiply3'
             *  Sqrt: '<S454>/Sqrt'
             *  Sum: '<S454>/Add1'
             *  Sum: '<S454>/Subtract'
             */
            rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
              FMS_ConstB.d_oc) * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation_e + rtb_Divide_pr_idx_1;

            /* Sum: '<S454>/Add4' */
            rtb_Divide_pr_idx_2 = (rtb_Divide_pr_idx_0 - rtb_Saturation_e) +
              rtb_Divide_pr_idx_1;

            /* Sum: '<S454>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_oc;

            /* Sum: '<S454>/Subtract1' */
            rtb_Divide_pr_idx_0 -= FMS_ConstB.d_oc;

            /* Signum: '<S454>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S454>/Sign1' */

            /* Signum: '<S454>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S454>/Sign2' */

            /* Sum: '<S454>/Add5' incorporates:
             *  Gain: '<S454>/Gain2'
             *  Product: '<S454>/Multiply4'
             *  Sum: '<S454>/Subtract2'
             */
            rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
              0.5F * rtb_Divide_pr_idx_2;

            /* SignalConversion: '<S450>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S453>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S453>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S453>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S454>/Subtract3' */
            rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_oc;

            /* Sum: '<S454>/Add6' */
            rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_oc;

            /* Signum: '<S454>/Sign5' incorporates:
             *  Signum: '<S454>/Sign6'
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;

              /* Signum: '<S454>/Sign6' */
              rtb_Add4_o = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;

              /* Signum: '<S454>/Sign6' */
              rtb_Add4_o = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Saturation_e;

              /* Signum: '<S454>/Sign6' */
              rtb_Add4_o = rtb_Saturation_e;
            }

            /* End of Signum: '<S454>/Sign5' */

            /* Signum: '<S454>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S454>/Sign3' */

            /* Signum: '<S454>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S454>/Sign4' */

            /* Update for DiscreteIntegrator: '<S453>/Integrator' incorporates:
             *  Constant: '<S454>/const'
             *  Gain: '<S454>/Gain3'
             *  Product: '<S454>/Divide'
             *  Product: '<S454>/Multiply5'
             *  Product: '<S454>/Multiply6'
             *  Sum: '<S454>/Subtract4'
             *  Sum: '<S454>/Subtract5'
             *  Sum: '<S454>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_Saturation_e / FMS_ConstB.d_oc
              - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_j *
              ((rtb_Divide_pr_idx_0 - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o *
              78.448F) * 0.004F;

            /* End of Outputs for SubSystem: '<S446>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S446>/Switch Case' */

          /* Switch: '<S411>/Switch' incorporates:
           *  Product: '<S435>/Multiply'
           *  Sum: '<S435>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S456>/Saturation1' */
            if (FMS_B.Merge_f[0] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_c2[0] = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_f[0] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_c2[0] = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_c2[0] = FMS_B.Merge_f[0];
            }

            if (FMS_B.Merge_f[1] > FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_c2[1] = FMS_PARAM.VEL_XY_LIM;
            } else if (FMS_B.Merge_f[1] < -FMS_PARAM.VEL_XY_LIM) {
              rtb_Switch_c2[1] = -FMS_PARAM.VEL_XY_LIM;
            } else {
              rtb_Switch_c2[1] = FMS_B.Merge_f[1];
            }

            /* End of Saturate: '<S456>/Saturation1' */

            /* Saturate: '<S446>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S446>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S435>/Sum' incorporates:
             *  Delay: '<S435>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S484>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S431>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S435>/Sum' incorporates:
             *  Delay: '<S435>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE[1];

            /* Sum: '<S431>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S443>/Sqrt' incorporates:
             *  Math: '<S443>/Square'
             *  Sum: '<S431>/Sum'
             *  Sum: '<S443>/Sum of Elements'
             */
            rtb_Divide_pr_idx_0 = sqrtf(rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Saturation_e * rtb_Saturation_e);

            /* SignalConversion: '<S486>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_ch[6] = FMS_ConstB.VectorConcatenate3[0];
            rtb_VectorConcatenate_ch[7] = FMS_ConstB.VectorConcatenate3[1];
            rtb_VectorConcatenate_ch[8] = FMS_ConstB.VectorConcatenate3[2];

            /* SignalConversion: '<S486>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S486>/Constant4'
             */
            rtb_VectorConcatenate_ch[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S485>/Gain' incorporates:
             *  DiscreteIntegrator: '<S483>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S483>/Add'
             */
            rtb_Saturation_e = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S486>/Trigonometric Function3' */
            rtb_VectorConcatenate_ch[4] = arm_cos_f32(rtb_Saturation_e);

            /* Gain: '<S486>/Gain' incorporates:
             *  Trigonometry: '<S486>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_ch[3] = -arm_sin_f32(rtb_Saturation_e);

            /* SignalConversion: '<S486>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S486>/Constant3'
             */
            rtb_VectorConcatenate_ch[2] = 0.0F;

            /* Trigonometry: '<S486>/Trigonometric Function' */
            rtb_VectorConcatenate_ch[1] = arm_sin_f32(rtb_Saturation_e);

            /* Trigonometry: '<S486>/Trigonometric Function1' */
            rtb_VectorConcatenate_ch[0] = arm_cos_f32(rtb_Saturation_e);

            /* Switch: '<S442>/Switch2' incorporates:
             *  Constant: '<S431>/Constant2'
             *  DiscreteIntegrator: '<S431>/Acceleration_Speed'
             *  RelationalOperator: '<S442>/LowerRelop1'
             *  RelationalOperator: '<S442>/UpperRelop'
             *  Switch: '<S442>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > d) {
              rtb_Saturation_e = d;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S442>/Switch' incorporates:
               *  Constant: '<S431>/Constant2'
               */
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S442>/Switch2' */

            /* Switch: '<S431>/Switch' */
            if (rtb_Divide_pr_idx_0 > FMS_PARAM.L1) {
              rtb_Divide_pr_idx_2 = d;
            } else {
              /* Gain: '<S431>/Gain' */
              rtb_Divide_pr_idx_2 = 0.5F * rtb_Divide_pr_idx_0;

              /* Switch: '<S441>/Switch2' incorporates:
               *  Constant: '<S431>/Constant1'
               *  RelationalOperator: '<S441>/LowerRelop1'
               *  RelationalOperator: '<S441>/UpperRelop'
               *  Switch: '<S441>/Switch'
               */
              if (rtb_Divide_pr_idx_2 > d) {
                rtb_Divide_pr_idx_2 = d;
              } else {
                if (rtb_Divide_pr_idx_2 < 0.5F) {
                  /* Switch: '<S441>/Switch' incorporates:
                   *  Constant: '<S431>/Constant1'
                   */
                  rtb_Divide_pr_idx_2 = 0.5F;
                }
              }

              /* End of Switch: '<S441>/Switch2' */
            }

            /* End of Switch: '<S431>/Switch' */

            /* Switch: '<S431>/Switch1' incorporates:
             *  Sum: '<S431>/Sum1'
             */
            if (rtb_Saturation_e - rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = rtb_Saturation_e;
            }

            /* End of Switch: '<S431>/Switch1' */

            /* Sum: '<S484>/Sum of Elements' incorporates:
             *  Math: '<S484>/Math Function'
             */
            rtb_Saturation_e = rtb_Switch_c2[0] * rtb_Switch_c2[0] +
              rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

            /* Math: '<S484>/Math Function1' incorporates:
             *  Sum: '<S484>/Sum of Elements'
             *
             * About '<S484>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Saturation_e = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S484>/Math Function1' */

            /* Switch: '<S484>/Switch' incorporates:
             *  Constant: '<S484>/Constant'
             *  Product: '<S484>/Product'
             */
            if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_0 = rtb_Subtract_hb[0];
            } else {
              rtb_Divide_pr_idx_0 = 0.0F;
              rtb_Divide_pr_idx_1 = 0.0F;
              rtb_Saturation_e = 1.0F;
            }

            /* End of Switch: '<S484>/Switch' */

            /* Product: '<S482>/Multiply2' incorporates:
             *  Product: '<S484>/Divide'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_0 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_1 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S437>/Sum1' incorporates:
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_e = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S437>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add4_o = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Divide_or = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S437>/Divide' incorporates:
             *  Math: '<S438>/Square'
             *  Math: '<S439>/Square'
             *  Sqrt: '<S438>/Sqrt'
             *  Sqrt: '<S439>/Sqrt'
             *  Sum: '<S437>/Sum'
             *  Sum: '<S437>/Sum1'
             *  Sum: '<S438>/Sum of Elements'
             *  Sum: '<S439>/Sum of Elements'
             */
            rtb_Saturation_e = sqrtf(rtb_Add4_o * rtb_Add4_o + rtb_Divide_or *
              rtb_Divide_or) / sqrtf(rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2 +
              rtb_Saturation_e * rtb_Saturation_e);

            /* Saturate: '<S437>/Saturation' */
            if (rtb_Saturation_e > 1.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              if (rtb_Saturation_e < 0.0F) {
                rtb_Saturation_e = 0.0F;
              }
            }

            /* End of Saturate: '<S437>/Saturation' */

            /* Product: '<S435>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_fy[rtb_n] = rtb_VectorConcatenate_ch[rtb_n +
                3] * rtb_Divide_pr_idx_1 + rtb_VectorConcatenate_ch[rtb_n] *
                rtb_Divide_pr_idx_0;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S428>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S437>/Multiply'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S428>/Sum2'
             *  Sum: '<S437>/Add'
             *  Sum: '<S437>/Subtract'
             */
            rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
              - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_e +
              FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_VectorConcatenate_fy[0];
            rtb_Switch_c2[1] = rtb_VectorConcatenate_fy[1];

            /* Saturate: '<S428>/Saturation1' incorporates:
             *  Product: '<S435>/Multiply'
             */
            if (rtb_Saturation_e > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_Saturation_e < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_Saturation_e;
            }

            /* End of Saturate: '<S428>/Saturation1' */
          }

          /* End of Switch: '<S411>/Switch' */

          /* Delay: '<S413>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S416>/Integrator1' incorporates:
           *  Delay: '<S413>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S420>/Rem' incorporates:
           *  Constant: '<S420>/Constant1'
           *  DiscreteIntegrator: '<S416>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S415>/Sum'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S420>/Switch' incorporates:
           *  Abs: '<S420>/Abs'
           *  Constant: '<S420>/Constant'
           *  Constant: '<S421>/Constant'
           *  Product: '<S420>/Multiply'
           *  RelationalOperator: '<S421>/Compare'
           *  Sum: '<S420>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S420>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S420>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S420>/Switch' */

          /* Gain: '<S415>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S415>/Saturation' */
          if (rtb_Divide_pr_idx_2 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_pr_idx_2 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Divide_pr_idx_2 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_2 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S415>/Saturation' */

          /* BusAssignment: '<S409>/Bus Assignment' incorporates:
           *  Constant: '<S409>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d3;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_d;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_c2[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_c2[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_c2[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_2;

          /* Math: '<S477>/Math Function1'
           *
           * About '<S477>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S477>/Math Function1' */

          /* Switch: '<S477>/Switch' incorporates:
           *  Constant: '<S477>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S477>/Product'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = FMS_U.INS_Out.vn;
            rtb_Switch_c2[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S477>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S409>/Sum' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_i5[0] = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_pr_idx_0 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Divide_i5[1] = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S427>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S409>/Sum'
           */
          rtb_P_cg[0] = rtb_Divide_pr_idx_0;
          rtb_P_cg[1] = rtb_Divide_pr_idx_1;

          /* Math: '<S427>/Math Function' incorporates:
           *  Sum: '<S409>/Sum'
           */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

          /* Sum: '<S427>/Sum of Elements' */
          rtb_Saturation_e = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S427>/Math Function1' incorporates:
           *  Sum: '<S427>/Sum of Elements'
           *
           * About '<S427>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S427>/Math Function1' */

          /* Switch: '<S427>/Switch' incorporates:
           *  Constant: '<S427>/Constant'
           *  Product: '<S427>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Divide_or = rtb_Divide_pr_idx_2;
          } else {
            rtb_Divide_pr_idx_0 = 0.0F;
            rtb_Divide_pr_idx_1 = 0.0F;
            rtb_Divide_or = 1.0F;
          }

          /* End of Switch: '<S427>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S433>/NearbyRefWP' incorporates:
           *  Constant: '<S409>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_i5,
                          &rtb_Saturation_e);

          /* MATLAB Function: '<S433>/SearchL1RefWP' incorporates:
           *  Constant: '<S409>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_cg, &rtb_Divide_pr_idx_2);

          /* MATLAB Function: '<S433>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S433>/Switch1' incorporates:
           *  Constant: '<S470>/Constant'
           *  RelationalOperator: '<S470>/Compare'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_i5[0];
            rtb_P_cg[1] = rtb_Divide_i5[1];
          } else {
            /* RelationalOperator: '<S469>/Compare' incorporates:
             *  Constant: '<S469>/Constant'
             */
            rtb_Compare_kd = (rtb_Divide_pr_idx_2 >= 0.0F);

            /* Switch: '<S433>/Switch' */
            if (!rtb_Compare_kd) {
              rtb_P_cg[0] = rtb_Square_ds[0];
              rtb_P_cg[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S433>/Switch' */
          }

          /* End of Switch: '<S433>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S434>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Add4_o = rtb_P_cg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_cg[0] = rtb_Add4_o;
          rtb_Square_bg[0] = rtb_Add4_o * rtb_Add4_o;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S434>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S478>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Add4_o = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S478>/Sum of Elements' incorporates:
           *  Math: '<S478>/Math Function'
           *  Sum: '<S476>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Square_bg[0] + rtb_Add4_o * rtb_Add4_o;

          /* Math: '<S478>/Math Function1' incorporates:
           *  Sum: '<S478>/Sum of Elements'
           *
           * About '<S478>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S478>/Math Function1' */

          /* Switch: '<S478>/Switch' incorporates:
           *  Constant: '<S478>/Constant'
           *  Product: '<S478>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Switch_an[0] = rtb_P_cg[0];
            rtb_Switch_an[1] = rtb_Add4_o;
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S478>/Switch' */

          /* Product: '<S477>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S480>/Sum of Elements' incorporates:
           *  Math: '<S480>/Math Function'
           *  SignalConversion: '<S480>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S480>/Math Function1' incorporates:
           *  Sum: '<S480>/Sum of Elements'
           *
           * About '<S480>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S480>/Math Function1' */

          /* Switch: '<S480>/Switch' incorporates:
           *  Constant: '<S480>/Constant'
           *  Product: '<S480>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Switch_c2[0] = rtb_Divide_i5[1];
            rtb_Switch_c2[1] = rtb_Divide_i5[0];
            rtb_Switch_c2[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_c2[0] = 0.0F;
            rtb_Switch_c2[1] = 0.0F;
            rtb_Switch_c2[2] = 1.0F;
          }

          /* End of Switch: '<S480>/Switch' */

          /* Product: '<S478>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S481>/Sum of Elements' incorporates:
           *  Math: '<S481>/Math Function'
           *  SignalConversion: '<S481>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S481>/Math Function1' incorporates:
           *  Sum: '<S481>/Sum of Elements'
           *
           * About '<S481>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S481>/Math Function1' */

          /* Switch: '<S481>/Switch' incorporates:
           *  Constant: '<S481>/Constant'
           *  Product: '<S481>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Switch_an[0] = rtb_Divide_i5[1];
            rtb_Switch_an[1] = rtb_Divide_i5[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S481>/Switch' */

          /* Product: '<S481>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S480>/Divide' */
          rtb_P_cg[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S427>/Divide' */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 / rtb_Divide_or;

          /* Product: '<S481>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S480>/Divide' */
          rtb_P_cg[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S427>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 / rtb_Divide_or;

          /* Sum: '<S479>/Subtract' incorporates:
           *  Product: '<S479>/Multiply'
           *  Product: '<S479>/Multiply1'
           */
          rtb_Divide_pr_idx_2 = rtb_Divide_i5[0] * rtb_P_cg[1] - rtb_Divide_i5[1]
            * rtb_P_cg[0];

          /* Signum: '<S474>/Sign1' */
          if (rtb_Divide_pr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S474>/Sign1' */

          /* Switch: '<S474>/Switch2' incorporates:
           *  Constant: '<S474>/Constant4'
           */
          if (rtb_Divide_pr_idx_2 == 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          }

          /* End of Switch: '<S474>/Switch2' */

          /* DotProduct: '<S474>/Dot Product' */
          rtb_Add4_o = rtb_P_cg[0] * rtb_Divide_i5[0] + rtb_P_cg[1] *
            rtb_Divide_i5[1];

          /* Trigonometry: '<S474>/Acos' incorporates:
           *  DotProduct: '<S474>/Dot Product'
           */
          if (rtb_Add4_o > 1.0F) {
            rtb_Add4_o = 1.0F;
          } else {
            if (rtb_Add4_o < -1.0F) {
              rtb_Add4_o = -1.0F;
            }
          }

          /* Product: '<S474>/Multiply' incorporates:
           *  Trigonometry: '<S474>/Acos'
           */
          rtb_Divide_pr_idx_2 *= acosf(rtb_Add4_o);

          /* Saturate: '<S434>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.57079637F) {
            rtb_Divide_pr_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.57079637F) {
              rtb_Divide_pr_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S434>/Saturation' */

          /* Product: '<S434>/Divide' incorporates:
           *  Constant: '<S409>/L1'
           *  Constant: '<S434>/Constant'
           *  Gain: '<S434>/Gain'
           *  Math: '<S434>/Square'
           *  MinMax: '<S434>/Max'
           *  MinMax: '<S434>/Min'
           *  Product: '<S434>/Multiply1'
           *  Sqrt: '<S476>/Sqrt'
           *  Trigonometry: '<S434>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Divide_pr_idx_2) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_e), 0.5F));

          /* Sum: '<S425>/Subtract' incorporates:
           *  Product: '<S425>/Multiply'
           *  Product: '<S425>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S414>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S414>/Sign1' */

          /* Switch: '<S414>/Switch2' incorporates:
           *  Constant: '<S414>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S414>/Switch2' */

          /* DotProduct: '<S414>/Dot Product' */
          rtb_Saturation_e = FMS_ConstB.Divide[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S414>/Acos' incorporates:
           *  DotProduct: '<S414>/Dot Product'
           */
          if (rtb_Saturation_e > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            if (rtb_Saturation_e < -1.0F) {
              rtb_Saturation_e = -1.0F;
            }
          }

          /* Product: '<S414>/Multiply' incorporates:
           *  Trigonometry: '<S414>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_Saturation_e);

          /* Math: '<S417>/Rem' incorporates:
           *  Constant: '<S417>/Constant1'
           *  Delay: '<S413>/Delay'
           *  Sum: '<S413>/Sum2'
           */
          rtb_Divide_pr_idx_2 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_n, 6.28318548F);

          /* Switch: '<S417>/Switch' incorporates:
           *  Abs: '<S417>/Abs'
           *  Constant: '<S417>/Constant'
           *  Constant: '<S423>/Constant'
           *  Product: '<S417>/Multiply'
           *  RelationalOperator: '<S423>/Compare'
           *  Sum: '<S417>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S417>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S417>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S417>/Switch' */

          /* Sum: '<S413>/Sum' incorporates:
           *  Delay: '<S413>/Delay'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S422>/Multiply1' incorporates:
           *  Constant: '<S422>/const1'
           *  DiscreteIntegrator: '<S416>/Integrator'
           */
          rtb_Divide_pr_idx_2 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S422>/Add' incorporates:
           *  DiscreteIntegrator: '<S416>/Integrator1'
           *  Sum: '<S416>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_mf -
            rtb_Divide_pr_idx_1) + rtb_Divide_pr_idx_2;

          /* Signum: '<S422>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
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
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2;

          /* Sum: '<S422>/Add4' */
          rtb_Divide_pr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S422>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_m;

          /* Sum: '<S422>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_m;

          /* Signum: '<S422>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign1' */

          /* Signum: '<S422>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign2' */

          /* Sum: '<S422>/Add5' incorporates:
           *  Gain: '<S422>/Gain2'
           *  Product: '<S422>/Multiply4'
           *  Sum: '<S422>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_pr_idx_2;

          /* Sum: '<S422>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_m;

          /* Sum: '<S422>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e - FMS_ConstB.d_m;

          /* Product: '<S422>/Divide' */
          rtb_Add4_o = rtb_Saturation_e / FMS_ConstB.d_m;

          /* Signum: '<S422>/Sign5' incorporates:
           *  Signum: '<S422>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S422>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S422>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Saturation_e;

            /* Signum: '<S422>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S422>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S413>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S418>/Rem' incorporates:
           *  Constant: '<S418>/Constant1'
           */
          rtb_Saturation_e = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S418>/Switch' incorporates:
           *  Abs: '<S418>/Abs'
           *  Constant: '<S418>/Constant'
           *  Constant: '<S424>/Constant'
           *  Product: '<S418>/Multiply'
           *  RelationalOperator: '<S424>/Compare'
           *  Sum: '<S418>/Add'
           */
          if (fabsf(rtb_Saturation_e) > 3.14159274F) {
            /* Signum: '<S418>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_e;
            }

            /* End of Signum: '<S418>/Sign' */
            rtb_Saturation_e -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S418>/Switch' */

          /* Abs: '<S411>/Abs' */
          rtb_Saturation_e = fabsf(rtb_Saturation_e);

          /* Update for Delay: '<S435>/Delay' */
          FMS_DW.icLoad = 0U;

          /* Update for DiscreteIntegrator: '<S436>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S429>/Constant'
           *  RelationalOperator: '<S429>/Compare'
           */
          FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = (uint8_T)((uint32_T)
            (rtb_Saturation_e <= 0.17453292F) +
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kf);
          if (FMS_DW.DiscreteTimeIntegrator_DSTAT_kf >= 100) {
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 100U;
          } else {
            if (FMS_DW.DiscreteTimeIntegrator_DSTAT_kf <= 0) {
              FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S436>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S431>/Acceleration_Speed' incorporates:
           *  Constant: '<S431>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Product: '<S435>/Divide1' */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 / d;

          /* Saturate: '<S435>/Saturation' */
          if (rtb_Saturation_e > 0.314159274F) {
            rtb_Saturation_e = 0.314159274F;
          } else {
            if (rtb_Saturation_e < -0.314159274F) {
              rtb_Saturation_e = -0.314159274F;
            }
          }

          /* End of Saturate: '<S435>/Saturation' */

          /* Update for DiscreteIntegrator: '<S483>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_Saturation_e;

          /* Update for Delay: '<S413>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S416>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S416>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S422>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign3' */

          /* Signum: '<S422>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S422>/Sign4' */

          /* Update for DiscreteIntegrator: '<S416>/Integrator' incorporates:
           *  Constant: '<S422>/const'
           *  Gain: '<S422>/Gain3'
           *  Product: '<S422>/Multiply5'
           *  Product: '<S422>/Multiply6'
           *  Sum: '<S422>/Subtract4'
           *  Sum: '<S422>/Subtract5'
           *  Sum: '<S422>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_m += ((rtb_Add4_o - rtb_Divide_or) *
            FMS_ConstB.Gain4_cu * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
            0.5F) - rtb_Divide_pr_idx_2 * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_m >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_m = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_m <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_m = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S416>/Integrator' */
          /* End of Outputs for SubSystem: '<S405>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S408>/Delay Input1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S408>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S293>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S293>/Unknown' incorporates:
           *  ActionPort: '<S407>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S293>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
         *  ActionPort: '<S292>/Action Port'
         */
        /* SwitchCase: '<S292>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_o;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
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

        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
        if (rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_o) {
          switch (rtPrevAction) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S392>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S307>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S325>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S341>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S366>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S353>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S292>/Acro' incorporates:
           *  ActionPort: '<S297>/Action Port'
           */
          /* BusAssignment: '<S297>/Bus Assignment' incorporates:
           *  Constant: '<S297>/Constant'
           *  Gain: '<S302>/Gain'
           *  Gain: '<S302>/Gain1'
           *  Gain: '<S302>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_c;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
          FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
          FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

          /* Saturate: '<S303>/Saturation' incorporates:
           *  Constant: '<S303>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           *  Sum: '<S303>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_Saturation_e = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S303>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S297>/Bus Assignment' incorporates:
           *  Constant: '<S303>/Constant5'
           *  Gain: '<S303>/Gain2'
           *  Sum: '<S303>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_Saturation_e), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S292>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S292>/Stabilize' incorporates:
             *  ActionPort: '<S300>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S292>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S388>/Integrator'
             *  DiscreteIntegrator: '<S388>/Integrator1'
             *  DiscreteIntegrator: '<S389>/Integrator'
             *  DiscreteIntegrator: '<S389>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S292>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S292>/Stabilize' incorporates:
             *  ActionPort: '<S300>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S292>/Switch Case' incorporates:
             *  Chart: '<S393>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S292>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S292>/Stabilize' incorporates:
           *  ActionPort: '<S300>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S383>/Logical Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S393>/Motion State' incorporates:
           *  Abs: '<S393>/Abs'
           *  Abs: '<S393>/Abs1'
           *  Constant: '<S403>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S403>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S392>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_e;
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S392>/Hold Control' incorporates:
               *  ActionPort: '<S395>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S392>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S392>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S392>/Hold Control' incorporates:
             *  ActionPort: '<S395>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S392>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S392>/Brake Control' incorporates:
             *  ActionPort: '<S394>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S392>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S392>/Move Control' incorporates:
               *  ActionPort: '<S396>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S392>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S392>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S392>/Move Control' incorporates:
             *  ActionPort: '<S396>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S392>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S392>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S385>/Switch' incorporates:
           *  Constant: '<S385>/Constant'
           *  Constant: '<S385>/Constant4'
           *  Constant: '<S385>/Constant5'
           *  Gain: '<S385>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S385>/Saturation'
           *  SignalConversion: '<S40>/Signal Copy2'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S385>/Add'
           *  Sum: '<S385>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S385>/Saturation' */
              rtb_Saturation_e = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S385>/Saturation' */
              rtb_Saturation_e = 0.0F;
            } else {
              /* Saturate: '<S385>/Saturation' incorporates:
               *  Constant: '<S385>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S40>/Signal Copy2'
               *  Sum: '<S385>/Sum'
               */
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
              rtb_Saturation_e), 65536.0F) + 1000U);
          }

          /* End of Switch: '<S385>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S300>/Bus Assignment' incorporates:
           *  Constant: '<S300>/Constant'
           *  DataTypeConversion: '<S383>/Data Type Conversion'
           *  DiscreteIntegrator: '<S388>/Integrator1'
           *  DiscreteIntegrator: '<S389>/Integrator1'
           *  Product: '<S383>/Multiply'
           *  Product: '<S383>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S392>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S300>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S300>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S300>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S392>/Saturation' */

          /* BusAssignment: '<S300>/Bus Assignment' */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S391>/Multiply1' incorporates:
           *  Constant: '<S391>/const1'
           *  DiscreteIntegrator: '<S389>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S387>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S387>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S391>/Add' incorporates:
           *  DiscreteIntegrator: '<S389>/Integrator1'
           *  Gain: '<S383>/Gain1'
           *  Gain: '<S387>/Gain'
           *  Sum: '<S389>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S391>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S391>/Sign' */

          /* Sum: '<S391>/Add2' incorporates:
           *  Abs: '<S391>/Abs'
           *  Gain: '<S391>/Gain'
           *  Gain: '<S391>/Gain1'
           *  Product: '<S391>/Multiply2'
           *  Product: '<S391>/Multiply3'
           *  Sqrt: '<S391>/Sqrt'
           *  Sum: '<S391>/Add1'
           *  Sum: '<S391>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_g) * FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S391>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Saturation_e - rtb_Divide_lr_idx_3;

          /* Sum: '<S391>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_g;

          /* Sum: '<S391>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_g;

          /* Signum: '<S391>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S391>/Sign1' */

          /* Signum: '<S391>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S391>/Sign2' */

          /* Sum: '<S391>/Add5' incorporates:
           *  Gain: '<S391>/Gain2'
           *  Product: '<S391>/Multiply4'
           *  Sum: '<S391>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Sum: '<S391>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_g;

          /* Sum: '<S391>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_g;

          /* Product: '<S391>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_g;

          /* Signum: '<S391>/Sign5' incorporates:
           *  Signum: '<S391>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S391>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S391>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Add4_o = rtb_Divide_lr_idx_3;

            /* Signum: '<S391>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S391>/Sign5' */

          /* Product: '<S390>/Multiply1' incorporates:
           *  Constant: '<S390>/const1'
           *  DiscreteIntegrator: '<S388>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S386>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S386>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S390>/Add' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator1'
           *  Gain: '<S383>/Gain'
           *  Gain: '<S386>/Gain'
           *  Sum: '<S388>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S390>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S390>/Sign' */

          /* Sum: '<S390>/Add2' incorporates:
           *  Abs: '<S390>/Abs'
           *  Gain: '<S390>/Gain'
           *  Gain: '<S390>/Gain1'
           *  Product: '<S390>/Multiply2'
           *  Product: '<S390>/Multiply3'
           *  Sqrt: '<S390>/Sqrt'
           *  Sum: '<S390>/Add1'
           *  Sum: '<S390>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S390>/Add4' */
          rtb_Divide_or = (rtb_Saturation_e - rtb_Divide_lr_idx_3) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S390>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_a;

          /* Sum: '<S390>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_a;

          /* Signum: '<S390>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S390>/Sign1' */

          /* Signum: '<S390>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S390>/Sign2' */

          /* Sum: '<S390>/Add5' incorporates:
           *  Gain: '<S390>/Gain2'
           *  Product: '<S390>/Multiply4'
           *  Sum: '<S390>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_or;

          /* Update for DiscreteIntegrator: '<S388>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S389>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S389>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S391>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S391>/Sign3' */

          /* Signum: '<S391>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S391>/Sign4' */

          /* Update for DiscreteIntegrator: '<S389>/Integrator' incorporates:
           *  Constant: '<S391>/const'
           *  Gain: '<S391>/Gain3'
           *  Product: '<S391>/Multiply5'
           *  Product: '<S391>/Multiply6'
           *  Sum: '<S391>/Subtract4'
           *  Sum: '<S391>/Subtract5'
           *  Sum: '<S391>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((d - rtb_Add4_o) * FMS_ConstB.Gain4_o *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 12.566371F) * 0.004F;

          /* Sum: '<S390>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_a;

          /* Sum: '<S390>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_a;

          /* Signum: '<S390>/Sign5' incorporates:
           *  Signum: '<S390>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S390>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S390>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S390>/Sign6' */
            rtb_Add4_o = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S390>/Sign5' */

          /* Signum: '<S390>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S390>/Sign3' */

          /* Signum: '<S390>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S390>/Sign4' */

          /* Update for DiscreteIntegrator: '<S388>/Integrator' incorporates:
           *  Constant: '<S390>/const'
           *  Gain: '<S390>/Gain3'
           *  Product: '<S390>/Divide'
           *  Product: '<S390>/Multiply5'
           *  Product: '<S390>/Multiply6'
           *  Sum: '<S390>/Subtract4'
           *  Sum: '<S390>/Subtract5'
           *  Sum: '<S390>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_a -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_k * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S292>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S292>/Altitude' incorporates:
             *  ActionPort: '<S298>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S292>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S321>/Integrator'
             *  DiscreteIntegrator: '<S321>/Integrator1'
             *  DiscreteIntegrator: '<S322>/Integrator'
             *  DiscreteIntegrator: '<S322>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S292>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S292>/Altitude' incorporates:
             *  ActionPort: '<S298>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S292>/Switch Case' incorporates:
             *  Chart: '<S308>/Motion Status'
             *  Chart: '<S326>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S292>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S292>/Altitude' incorporates:
           *  ActionPort: '<S298>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S308>/Motion Status' incorporates:
           *  Abs: '<S308>/Abs'
           *  Abs: '<S308>/Abs1'
           *  Constant: '<S317>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S317>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S307>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_nh;
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S307>/Hold Control' incorporates:
               *  ActionPort: '<S310>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S307>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S307>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S307>/Hold Control' incorporates:
             *  ActionPort: '<S310>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S307>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S307>/Brake Control' incorporates:
             *  ActionPort: '<S309>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S307>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S307>/Move Control' incorporates:
             *  ActionPort: '<S311>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S307>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S307>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S304>/Switch' incorporates:
           *  Constant: '<S304>/Constant'
           *  Saturate: '<S307>/Saturation1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Divide_pr_idx_1 = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S307>/Saturation1' */
            rtb_Divide_pr_idx_1 = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S307>/Saturation1' */
            rtb_Divide_pr_idx_1 = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S307>/Saturation1' */
            rtb_Divide_pr_idx_1 = FMS_B.Merge_l;
          }

          /* End of Switch: '<S304>/Switch' */

          /* Logic: '<S305>/Logical Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S326>/Motion State' incorporates:
           *  Abs: '<S326>/Abs'
           *  Abs: '<S326>/Abs1'
           *  Constant: '<S336>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S336>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S325>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_i;
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S325>/Hold Control' incorporates:
               *  ActionPort: '<S328>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S325>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_p);

              /* End of SystemReset for SubSystem: '<S325>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S325>/Hold Control' incorporates:
             *  ActionPort: '<S328>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S325>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S325>/Brake Control' incorporates:
             *  ActionPort: '<S327>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S325>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S325>/Move Control' incorporates:
               *  ActionPort: '<S329>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S325>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S325>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S325>/Move Control' incorporates:
             *  ActionPort: '<S329>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S325>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S325>/Switch Case' */

          /* BusAssignment: '<S298>/Bus Assignment' incorporates:
           *  Constant: '<S298>/Constant'
           *  DataTypeConversion: '<S305>/Data Type Conversion'
           *  DiscreteIntegrator: '<S321>/Integrator1'
           *  DiscreteIntegrator: '<S322>/Integrator1'
           *  Product: '<S305>/Multiply'
           *  Product: '<S305>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S325>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S298>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S298>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S298>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S325>/Saturation' */

          /* BusAssignment: '<S298>/Bus Assignment' */
          FMS_Y.FMS_Out.w_cmd = rtb_Divide_pr_idx_1;

          /* Product: '<S324>/Multiply1' incorporates:
           *  Constant: '<S324>/const1'
           *  DiscreteIntegrator: '<S322>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S320>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S320>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S324>/Add' incorporates:
           *  DiscreteIntegrator: '<S322>/Integrator1'
           *  Gain: '<S305>/Gain1'
           *  Gain: '<S320>/Gain'
           *  Sum: '<S322>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S324>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S324>/Sign' */

          /* Sum: '<S324>/Add2' incorporates:
           *  Abs: '<S324>/Abs'
           *  Gain: '<S324>/Gain'
           *  Gain: '<S324>/Gain1'
           *  Product: '<S324>/Multiply2'
           *  Product: '<S324>/Multiply3'
           *  Sqrt: '<S324>/Sqrt'
           *  Sum: '<S324>/Add1'
           *  Sum: '<S324>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_o) * FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S324>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Saturation_e - rtb_Divide_lr_idx_3;

          /* Sum: '<S324>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_o;

          /* Sum: '<S324>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_o;

          /* Signum: '<S324>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S324>/Sign1' */

          /* Signum: '<S324>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S324>/Sign2' */

          /* Sum: '<S324>/Add5' incorporates:
           *  Gain: '<S324>/Gain2'
           *  Product: '<S324>/Multiply4'
           *  Sum: '<S324>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Sum: '<S324>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_o;

          /* Sum: '<S324>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_o;

          /* Product: '<S324>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_o;

          /* Signum: '<S324>/Sign5' incorporates:
           *  Signum: '<S324>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S324>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S324>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Add4_o = rtb_Divide_lr_idx_3;

            /* Signum: '<S324>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S324>/Sign5' */

          /* Product: '<S323>/Multiply1' incorporates:
           *  Constant: '<S323>/const1'
           *  DiscreteIntegrator: '<S321>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S319>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S319>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S323>/Add' incorporates:
           *  DiscreteIntegrator: '<S321>/Integrator1'
           *  Gain: '<S305>/Gain'
           *  Gain: '<S319>/Gain'
           *  Sum: '<S321>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S323>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S323>/Sign' */

          /* Sum: '<S323>/Add2' incorporates:
           *  Abs: '<S323>/Abs'
           *  Gain: '<S323>/Gain'
           *  Gain: '<S323>/Gain1'
           *  Product: '<S323>/Multiply2'
           *  Product: '<S323>/Multiply3'
           *  Sqrt: '<S323>/Sqrt'
           *  Sum: '<S323>/Add1'
           *  Sum: '<S323>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_c) * FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S323>/Add4' */
          rtb_Divide_or = (rtb_Saturation_e - rtb_Divide_lr_idx_3) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S323>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_c;

          /* Sum: '<S323>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_c;

          /* Signum: '<S323>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S323>/Sign1' */

          /* Signum: '<S323>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S323>/Sign2' */

          /* Sum: '<S323>/Add5' incorporates:
           *  Gain: '<S323>/Gain2'
           *  Product: '<S323>/Multiply4'
           *  Sum: '<S323>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_or;

          /* Update for DiscreteIntegrator: '<S321>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S321>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S322>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S322>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S324>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S324>/Sign3' */

          /* Signum: '<S324>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S324>/Sign4' */

          /* Update for DiscreteIntegrator: '<S322>/Integrator' incorporates:
           *  Constant: '<S324>/const'
           *  Gain: '<S324>/Gain3'
           *  Product: '<S324>/Multiply5'
           *  Product: '<S324>/Multiply6'
           *  Sum: '<S324>/Subtract4'
           *  Sum: '<S324>/Subtract5'
           *  Sum: '<S324>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((d - rtb_Add4_o) * FMS_ConstB.Gain4_c *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 12.566371F) * 0.004F;

          /* Sum: '<S323>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_c;

          /* Sum: '<S323>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_c;

          /* Signum: '<S323>/Sign5' incorporates:
           *  Signum: '<S323>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S323>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S323>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S323>/Sign6' */
            rtb_Add4_o = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S323>/Sign5' */

          /* Signum: '<S323>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S323>/Sign3' */

          /* Signum: '<S323>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S323>/Sign4' */

          /* Update for DiscreteIntegrator: '<S321>/Integrator' incorporates:
           *  Constant: '<S323>/const'
           *  Gain: '<S323>/Gain3'
           *  Product: '<S323>/Divide'
           *  Product: '<S323>/Multiply5'
           *  Product: '<S323>/Multiply6'
           *  Sum: '<S323>/Subtract4'
           *  Sum: '<S323>/Subtract5'
           *  Sum: '<S323>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_c -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_h * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S292>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S292>/Position' incorporates:
             *  ActionPort: '<S299>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S292>/Switch Case' incorporates:
             *  Chart: '<S342>/Motion Status'
             *  Chart: '<S354>/Motion State'
             *  Chart: '<S367>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S292>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S292>/Position' incorporates:
           *  ActionPort: '<S299>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S342>/Motion Status' incorporates:
           *  Abs: '<S342>/Abs'
           *  Abs: '<S342>/Abs1'
           *  Constant: '<S351>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S351>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S341>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_n;
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S341>/Hold Control' incorporates:
               *  ActionPort: '<S344>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S341>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S341>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S341>/Hold Control' incorporates:
             *  ActionPort: '<S344>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S341>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S341>/Brake Control' incorporates:
             *  ActionPort: '<S343>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S341>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S341>/Move Control' incorporates:
             *  ActionPort: '<S345>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S341>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S341>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S354>/Motion State' incorporates:
           *  Abs: '<S354>/Abs'
           *  Abs: '<S354>/Abs1'
           *  Constant: '<S364>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S364>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S367>/Logical Operator' incorporates:
           *  Abs: '<S367>/Abs1'
           *  Abs: '<S367>/Abs2'
           *  Constant: '<S380>/Constant'
           *  Constant: '<S381>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S380>/Compare'
           *  RelationalOperator: '<S381>/Compare'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S367>/Motion State' */
          if (FMS_DW.temporalCounter_i1_g < 2047U) {
            FMS_DW.temporalCounter_i1_g++;
          }

          if (FMS_DW.is_active_c16_FMS == 0U) {
            FMS_DW.is_active_c16_FMS = 1U;
            FMS_DW.is_c16_FMS = FMS_IN_Move_p;
            rtb_state_fg = MotionState_Move;
          } else {
            switch (FMS_DW.is_c16_FMS) {
             case FMS_IN_Brake_bw:
              rtb_state_fg = MotionState_Brake;
              if ((rtb_Divide_lr_idx_2 <= 0.2) || (FMS_DW.temporalCounter_i1_g >=
                   1250U)) {
                FMS_DW.is_c16_FMS = FMS_IN_Hold_od;
                rtb_state_fg = MotionState_Hold;
              } else {
                if (rtb_FixPtRelationalOperator_me) {
                  FMS_DW.is_c16_FMS = FMS_IN_Move_p;
                  rtb_state_fg = MotionState_Move;
                }
              }
              break;

             case FMS_IN_Hold_od:
              rtb_state_fg = MotionState_Hold;
              if (rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_p;
                rtb_state_fg = MotionState_Move;
              }
              break;

             default:
              rtb_state_fg = MotionState_Move;
              if (!rtb_FixPtRelationalOperator_me) {
                FMS_DW.is_c16_FMS = FMS_IN_Brake_bw;
                FMS_DW.temporalCounter_i1_g = 0U;
                rtb_state_fg = MotionState_Brake;
              }
              break;
            }
          }

          /* End of Chart: '<S367>/Motion State' */

          /* SwitchCase: '<S366>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_bf;
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;
          switch (rtb_state_fg) {
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
              /* SystemReset for IfAction SubSystem: '<S366>/Hold Control' incorporates:
               *  ActionPort: '<S369>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S366>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_jz);

              /* End of SystemReset for SubSystem: '<S366>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S366>/Hold Control' incorporates:
             *  ActionPort: '<S369>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge,
                              &FMS_ConstB.HoldControl_jz, &FMS_DW.HoldControl_jz);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S366>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S366>/Brake Control' incorporates:
             *  ActionPort: '<S368>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge);

            /* End of Outputs for SubSystem: '<S366>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S366>/Move Control' incorporates:
               *  ActionPort: '<S370>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S366>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S376>/Integrator'
               *  DiscreteIntegrator: '<S376>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S366>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S366>/Move Control' incorporates:
             *  ActionPort: '<S370>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S374>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch -
                FMS_PARAM.PITCH_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_pitch -
                (-FMS_PARAM.PITCH_DZ);
            }

            /* End of DeadZone: '<S374>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S374>/Gain' */
            rtb_Divide_pr_idx_1 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
              rtb_Saturation_e;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S375>/Dead Zone' incorporates:
             *  Inport: '<Root>/Pilot_Cmd'
             *  SignalConversion: '<S40>/Signal Copy2'
             */
            if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
            } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_roll -
                (-FMS_PARAM.ROLL_DZ);
            }

            /* End of DeadZone: '<S375>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S375>/Gain' */
            rtb_Divide_lr_idx_2 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
              rtb_Saturation_e;

            /* SignalConversion: '<S377>/TmpSignal ConversionAtSquareInport1' */
            rtb_Square_bg[0] = rtb_Divide_pr_idx_1;
            rtb_Square_bg[1] = rtb_Divide_lr_idx_2;

            /* Sum: '<S377>/Sum of Elements' incorporates:
             *  Math: '<S377>/Square'
             *  SignalConversion: '<S377>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S378>/Sum of Elements'
             *  Switch: '<S370>/Switch'
             */
            rtb_Saturation_e = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 +
              rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

            /* Switch: '<S370>/Switch' incorporates:
             *  Product: '<S378>/Divide'
             *  Sqrt: '<S377>/Sqrt'
             *  Sum: '<S377>/Sum of Elements'
             */
            if (sqrtf(rtb_Saturation_e) > 1.0F) {
              /* Math: '<S378>/Math Function1'
               *
               * About '<S378>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Saturation_e < 0.0F) {
                rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
              } else {
                rtb_Saturation_e = sqrtf(rtb_Saturation_e);
              }

              /* End of Math: '<S378>/Math Function1' */

              /* Switch: '<S378>/Switch' incorporates:
               *  Constant: '<S378>/Constant'
               *  Product: '<S378>/Product'
               */
              if (rtb_Saturation_e > 0.0F) {
                rtb_Switch_an[0] = rtb_Divide_pr_idx_1;
                rtb_Switch_an[1] = rtb_Divide_lr_idx_2;
                rtb_Switch_an[2] = rtb_Saturation_e;
              } else {
                rtb_Switch_an[0] = 0.0F;
                rtb_Switch_an[1] = 0.0F;
                rtb_Switch_an[2] = 1.0F;
              }

              /* End of Switch: '<S378>/Switch' */
              rtb_Square_bg[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Square_bg[1] = rtb_Switch_an[1] / rtb_Switch_an[2];
            }

            /* Product: '<S379>/Multiply1' incorporates:
             *  Constant: '<S379>/const1'
             *  DiscreteIntegrator: '<S376>/Integrator'
             */
            rtb_Divide_pr_idx_0 = FMS_DW.Integrator_DSTATE[0] * 0.05F;

            /* Sum: '<S379>/Add' incorporates:
             *  DiscreteIntegrator: '<S376>/Integrator1'
             *  Gain: '<S370>/Gain6'
             *  Sum: '<S376>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE[0] -
              FMS_PARAM.VEL_XY_LIM * rtb_Square_bg[0]) + rtb_Divide_pr_idx_0;

            /* Signum: '<S379>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
            }

            /* Sum: '<S379>/Add2' incorporates:
             *  Abs: '<S379>/Abs'
             *  Gain: '<S379>/Gain'
             *  Gain: '<S379>/Gain1'
             *  Product: '<S379>/Multiply2'
             *  Product: '<S379>/Multiply3'
             *  Sqrt: '<S379>/Sqrt'
             *  Sum: '<S379>/Add1'
             *  Sum: '<S379>/Subtract'
             */
            rtb_Divide_pr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_0;

            /* Sum: '<S379>/Add4' */
            rtb_Divide_pr_idx_0 += rtb_Divide_lr_idx_2 - rtb_Divide_pr_idx_2;

            /* Sum: '<S379>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Sum: '<S379>/Subtract1' */
            rtb_Divide_lr_idx_2 -= FMS_ConstB.d;

            /* Signum: '<S379>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S379>/Sign2' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_2 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              }
            }

            /* Sum: '<S379>/Add5' incorporates:
             *  Gain: '<S379>/Gain2'
             *  Product: '<S379>/Multiply4'
             *  Sum: '<S379>/Subtract2'
             */
            rtb_Divide_pr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S376>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S376>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S376>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S376>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S379>/Sign4' incorporates:
             *  Sum: '<S379>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S379>/Sign3' incorporates:
             *  Sum: '<S379>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S379>/Sign5' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_2;
            }

            /* Signum: '<S379>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S379>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S379>/Sign6' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Add4_o = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Add4_o = 1.0F;
            } else {
              rtb_Add4_o = rtb_Divide_pr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S376>/Integrator' incorporates:
             *  Constant: '<S379>/const'
             *  Gain: '<S379>/Gain3'
             *  Product: '<S379>/Divide'
             *  Product: '<S379>/Multiply5'
             *  Product: '<S379>/Multiply6'
             *  Sum: '<S379>/Subtract4'
             *  Sum: '<S379>/Subtract5'
             *  Sum: '<S379>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Divide_pr_idx_2 / FMS_ConstB.d
              - rtb_Saturation_e) * FMS_ConstB.Gain4 * ((rtb_Divide_pr_idx_0 -
              rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 58.836F) * 0.004F;

            /* Product: '<S379>/Multiply1' incorporates:
             *  Constant: '<S379>/const1'
             *  DiscreteIntegrator: '<S376>/Integrator'
             */
            rtb_Divide_pr_idx_0 = FMS_DW.Integrator_DSTATE[1] * 0.05F;

            /* Sum: '<S379>/Add' incorporates:
             *  DiscreteIntegrator: '<S376>/Integrator1'
             *  Gain: '<S370>/Gain6'
             *  Sum: '<S376>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE[1] -
              FMS_PARAM.VEL_XY_LIM * rtb_Square_bg[1]) + rtb_Divide_pr_idx_0;

            /* Signum: '<S379>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
            }

            /* Sum: '<S379>/Add2' incorporates:
             *  Abs: '<S379>/Abs'
             *  Gain: '<S379>/Gain'
             *  Gain: '<S379>/Gain1'
             *  Product: '<S379>/Multiply2'
             *  Product: '<S379>/Multiply3'
             *  Sqrt: '<S379>/Sqrt'
             *  Sum: '<S379>/Add1'
             *  Sum: '<S379>/Subtract'
             */
            rtb_Divide_pr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_0;

            /* Sum: '<S379>/Add4' */
            rtb_Divide_pr_idx_0 += rtb_Divide_lr_idx_2 - rtb_Divide_pr_idx_2;

            /* Sum: '<S379>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Sum: '<S379>/Subtract1' */
            rtb_Divide_lr_idx_2 -= FMS_ConstB.d;

            /* Signum: '<S379>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S379>/Sign2' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_2 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              }
            }

            /* Sum: '<S379>/Add5' incorporates:
             *  Gain: '<S379>/Gain2'
             *  Product: '<S379>/Multiply4'
             *  Sum: '<S379>/Subtract2'
             */
            rtb_Divide_pr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S376>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S376>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S376>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S376>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S379>/Sign4' incorporates:
             *  Sum: '<S379>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S379>/Sign3' incorporates:
             *  Sum: '<S379>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S379>/Sign5' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_2;
            }

            /* Signum: '<S379>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S379>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S379>/Sign6' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Add4_o = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Add4_o = 1.0F;
            } else {
              rtb_Add4_o = rtb_Divide_pr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S376>/Integrator' incorporates:
             *  Constant: '<S379>/const'
             *  Gain: '<S379>/Gain3'
             *  Product: '<S379>/Divide'
             *  Product: '<S379>/Multiply5'
             *  Product: '<S379>/Multiply6'
             *  Sum: '<S379>/Subtract4'
             *  Sum: '<S379>/Subtract5'
             *  Sum: '<S379>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Divide_pr_idx_2 / FMS_ConstB.d
              - rtb_Saturation_e) * FMS_ConstB.Gain4 * ((rtb_Divide_pr_idx_0 -
              rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S366>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S366>/Switch Case' */

          /* SwitchCase: '<S353>/Switch Case' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_g;
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
          switch (rtb_state_l4) {
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
              /* SystemReset for IfAction SubSystem: '<S353>/Hold Control' incorporates:
               *  ActionPort: '<S356>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S353>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S353>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S353>/Hold Control' incorporates:
             *  ActionPort: '<S356>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S353>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S353>/Brake Control' incorporates:
             *  ActionPort: '<S355>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S353>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S353>/Move Control' incorporates:
               *  ActionPort: '<S357>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S353>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S353>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S353>/Move Control' incorporates:
             *  ActionPort: '<S357>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S353>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S353>/Switch Case' */

          /* BusAssignment: '<S299>/Bus Assignment' incorporates:
           *  Constant: '<S299>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S353>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S353>/Saturation' */

          /* Saturate: '<S366>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S366>/Saturation1' */

          /* Saturate: '<S341>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S299>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S341>/Saturation1' */
          /* End of Outputs for SubSystem: '<S292>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S292>/Unknown' incorporates:
           *  ActionPort: '<S301>/Action Port'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S292>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S47>/Manual' incorporates:
         *  ActionPort: '<S294>/Action Port'
         */
        /* BusAssignment: '<S294>/Bus Assignment' incorporates:
         *  Constant: '<S294>/Constant'
         *  Constant: '<S294>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S47>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S47>/Unknown' incorporates:
         *  ActionPort: '<S296>/Action Port'
         */
        FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d);

        /* End of Outputs for SubSystem: '<S47>/Unknown' */
        break;
      }

      /* End of Outputs for SubSystem: '<S41>/MC_Mode' */
      break;
    }

    /* End of Outputs for SubSystem: '<S39>/Arm' */
    break;
  }

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  /* BusAssignment: '<S42>/Bus Assignment' incorporates:
   *  Constant: '<S42>/Constant'
   *  DataStoreRead: '<S42>/Data Store Read'
   *  DataTypeConversion: '<S42>/Data Type Conversion'
   *  DataTypeConversion: '<S42>/Data Type Conversion1'
   *  DiscreteIntegrator: '<S738>/Discrete-Time Integrator'
   *  Gain: '<S42>/Gain'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy8Inport1'
   *  Sum: '<S42>/Sum'
   *  Sum: '<S42>/Sum1'
   */
  FMS_Y.FMS_Out.ctrl_mode = (uint8_T)((uint32_T)(uint8_T)((uint8_T)
    FMS_B.vtol_state << 6) + FMS_Y.FMS_Out.ctrl_mode);

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
  FMS_Y.FMS_Out.home[0] = FMS_DW.home[0];
  FMS_Y.FMS_Out.home[1] = FMS_DW.home[1];
  FMS_Y.FMS_Out.home[2] = FMS_DW.home[2];
  FMS_Y.FMS_Out.home[3] = FMS_DW.home[3];

  /* Update for DiscreteIntegrator: '<S738>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S738>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_g += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS Commander' */

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   */
  rtb_FixPtRelationalOperator_me = (rtb_DataTypeConversion1_m == FMS_Cmd_SetHome);

  /* Outputs for Triggered SubSystem: '<S24>/SetHome' incorporates:
   *  TriggerPort: '<S31>/Trigger'
   */
  if (rtb_FixPtRelationalOperator_me && (FMS_PrevZCX.SetHome_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S31>/Data Store Write' incorporates:
     *  Inport: '<Root>/GCS_Cmd'
     */
    FMS_DW.home[0] = FMS_U.GCS_Cmd.param[0];
    FMS_DW.home[1] = FMS_U.GCS_Cmd.param[1];
    FMS_DW.home[2] = FMS_U.GCS_Cmd.param[2];
    FMS_DW.home[3] = FMS_U.GCS_Cmd.param[3];
  }

  FMS_PrevZCX.SetHome_Trig_ZCE = rtb_FixPtRelationalOperator_me;

  /* End of Outputs for SubSystem: '<S24>/SetHome' */

  /* Update for UnitDelay: '<S27>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S27>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S23>/Constant1'
   */
  rtb_Saturation_e = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTAT_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation_e < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = (uint32_T)rtb_Saturation_e;
  } else {
    FMS_DW.DiscreteTimeIntegrator1_DSTAT_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S34>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S34>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_f = FMS_U.GCS_Cmd.mode;

  /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S11>/Gain'
   *  Sum: '<S11>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Divide_lr_idx_1 -
    FMS_B.DiscreteTimeIntegrator5) * 125.663704F * 0.004F;

  /* Update for UnitDelay: '<S29>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S29>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = FMS_U.Pilot_Cmd.cmd_1;

  /* Update for UnitDelay: '<S30>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S30>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = FMS_U.GCS_Cmd.cmd_1;

  /* Update for UnitDelay: '<S35>/Delay Input1' incorporates:
   *  Inport: '<Root>/GCS_Cmd'
   *
   * Block description for '<S35>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_d = FMS_U.GCS_Cmd.timestamp;

  /* Update for UnitDelay: '<S36>/Delay Input1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *
   * Block description for '<S36>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_h = FMS_U.Pilot_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += 0.004F;
  if (FMS_DW.DiscreteTimeIntegrator_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator1_DSTATE += 0.004F;
  if (FMS_DW.DiscreteTimeIntegrator1_DSTATE >= 65535.0F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = 65535.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator1_DSTATE <= 0.0F) {
      FMS_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' */

  /* Update for UnitDelay: '<S20>/Delay Input1' incorporates:
   *  Inport: '<Root>/Auto_Cmd'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = FMS_U.Auto_Cmd.timestamp;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Saturation_e = (real32_T)FMS_DW.DiscreteTimeIntegrator_DSTATE_b +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation_e < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = (uint32_T)rtb_Saturation_e;
  } else {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_b = MAX_uint32_T;
  }

  /* End of Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */

  /* Update for Delay: '<S21>/Delay' */
  FMS_DW.Delay_DSTATE_o = rtb_Switch_ga;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S10>/Gain'
   *  Sum: '<S10>/Sum5'
   */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_m = 0U;
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_h += (rtb_Divide_lr_idx_0 -
    FMS_B.DiscreteTimeIntegrator5_p) * 125.663704F * 0.004F;
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
    FMS_B.vtol_state = VTOLState_Multicopter;
    FMS_B.state_g = VTOLState_Multicopter;
    FMS_B.DataTypeConversion_n = VTOLMode_Multicopter;
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
  /* Start for SwitchCase: '<S39>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S39>/Arm' */
  /* Start for SwitchCase: '<S41>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for IfAction SubSystem: '<S41>/FW_Mode' */
  /* Start for SwitchCase: '<S46>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_pn = -1;

  /* Start for IfAction SubSystem: '<S46>/SubMode' */
  /* Start for SwitchCase: '<S88>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_kv = -1;

  /* End of Start for SubSystem: '<S46>/SubMode' */

  /* Start for IfAction SubSystem: '<S46>/Auto' */
  /* Start for SwitchCase: '<S86>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_hd = -1;

  /* End of Start for SubSystem: '<S46>/Auto' */

  /* Start for IfAction SubSystem: '<S46>/Assist' */
  /* Start for SwitchCase: '<S85>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_a = -1;

  /* Start for IfAction SubSystem: '<S85>/Altitude' */
  /* Start for SwitchCase: '<S98>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l3 = -1;

  /* End of Start for SubSystem: '<S85>/Altitude' */

  /* Start for IfAction SubSystem: '<S85>/Position' */
  /* Start for SwitchCase: '<S133>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S119>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;

  /* End of Start for SubSystem: '<S85>/Position' */
  /* End of Start for SubSystem: '<S46>/Assist' */
  /* End of Start for SubSystem: '<S41>/FW_Mode' */

  /* Start for IfAction SubSystem: '<S41>/MC_Mode' */
  /* Start for SwitchCase: '<S47>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S47>/SubMode' */
  /* Start for SwitchCase: '<S295>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S295>/Return' */
  /* Start for SwitchCase: '<S696>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S686>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S295>/Return' */

  /* Start for IfAction SubSystem: '<S295>/Hold' */
  /* Start for SwitchCase: '<S635>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S603>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S614>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S295>/Hold' */
  /* End of Start for SubSystem: '<S47>/SubMode' */

  /* Start for IfAction SubSystem: '<S47>/Auto' */
  /* Start for SwitchCase: '<S293>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S293>/Mission' */
  /* Start for Resettable SubSystem: '<S405>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S456>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S446>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S405>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S293>/Mission' */
  /* End of Start for SubSystem: '<S47>/Auto' */

  /* Start for IfAction SubSystem: '<S47>/Assist' */
  /* Start for SwitchCase: '<S292>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S292>/Stabilize' */
  /* Start for SwitchCase: '<S392>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S292>/Stabilize' */

  /* Start for IfAction SubSystem: '<S292>/Altitude' */
  /* Start for SwitchCase: '<S307>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S325>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S292>/Altitude' */

  /* Start for IfAction SubSystem: '<S292>/Position' */
  /* Start for SwitchCase: '<S341>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S366>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S353>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S292>/Position' */
  /* End of Start for SubSystem: '<S47>/Assist' */
  /* End of Start for SubSystem: '<S41>/MC_Mode' */
  /* End of Start for SubSystem: '<S39>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.SetHome_Trig_ZCE = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = POS_ZCSIG;
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  FMS_DW.DiscreteTimeIntegrator5_IC_LO_m = 1U;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_active_Lost_Return = 0U;
  FMS_DW.is_Lost_Return = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_active_VTOL_Mode = 0U;
  FMS_DW.is_VTOL_Mode = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_active_VTOL_State = 0U;
  FMS_DW.is_VTOL_State = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.temporalCounter_i2 = 0U;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Return_n = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Takeoff = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_VTOL_Land_m = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Waypoint_o = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Waypoint = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Offboard = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Hold = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Land = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_VTOL_Land = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Return = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c11_FMS = 0U;
  FMS_DW.M_msgReservedData = FMS_Cmd_None;
  FMS_DW.prep_takeoff = 0.0;
  FMS_DW.bl = false;
  FMS_DW.br = false;
  FMS_DW.prep_mission_takeoff = 0.0;
  FMS_DW.VTOL_M_msgReservedData = VTOLMode_Multicopter;
  FMS_B.wp_consume = 0U;
  FMS_B.wp_index = 1U;
  FMS_DW.chartAbsoluteTimeCounter = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS Commander' */
  /* SystemInitialize for IfAction SubSystem: '<S39>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S41>/FW_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S46>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S88>/Hold' */
  /* InitializeConditions for Delay: '<S235>/start_vel' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for Delay: '<S230>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S88>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S46>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S46>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S86>/Mission' */
  /* InitializeConditions for UnitDelay: '<S196>/Delay Input1'
   *
   * Block description for '<S196>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* End of SystemInitialize for SubSystem: '<S86>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S46>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S46>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S85>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S186>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S186>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S187>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S191>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mx = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S191>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S187>/Integrator' */
  FMS_DW.Integrator_DSTATE_ky = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S85>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S85>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S110>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_lj = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_gw = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator' */
  FMS_DW.Integrator_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S110>/Integrator' */
  FMS_DW.Integrator_DSTATE_i3 = 0.0F;

  /* SystemInitialize for Chart: '<S99>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S98>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S98>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S98>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl);

  /* End of SystemInitialize for SubSystem: '<S98>/Move Control' */

  /* SystemInitialize for Merge: '<S98>/Merge' */
  FMS_B.Merge_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S85>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S85>/Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S131>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S131>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S120>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S134>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c26_FMS = 0U;
  FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S133>/Hold Control' */
  /* InitializeConditions for Delay: '<S141>/start_vel' */
  FMS_DW.icLoad_g = 1U;

  /* InitializeConditions for Delay: '<S141>/start_wp' */
  FMS_DW.icLoad_ef = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S170>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = FMS_ConstB.Constant_a;
  if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
    }
  }

  FMS_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S170>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S172>/Discrete-Time Integrator1' */
  FMS_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  FMS_DW.DiscreteTimeIntegrator1_PrevR_p = 0;

  /* End of SystemInitialize for SubSystem: '<S133>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S133>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S174>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S174>/Integrator' */
  FMS_DW.Integrator_DSTATE_f1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S133>/Move Control' */

  /* SystemInitialize for IfAction SubSystem: '<S119>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S119>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S119>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S119>/Move Control' */

  /* SystemInitialize for Merge: '<S119>/Merge' */
  FMS_B.Merge_fb = 0.0F;

  /* SystemInitialize for Merge: '<S133>/Merge' */
  FMS_B.Merge_be = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S85>/Position' */
  /* End of SystemInitialize for SubSystem: '<S46>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S41>/FW_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S41>/BackwardTrans_Mode' */
  /* InitializeConditions for Delay: '<S53>/start_vel' */
  FMS_DW.icLoad_i = 1U;

  /* InitializeConditions for Delay: '<S53>/start_wp' */
  FMS_DW.icLoad_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_i = FMS_ConstB.Constant;
  if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i >= 1.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_i = 1.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE_i <= -1.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE_i = -1.0F;
    }
  }

  FMS_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' */
  FMS_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  FMS_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* End of SystemInitialize for SubSystem: '<S41>/BackwardTrans_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S41>/MC_Mode' */
  /* SystemInitialize for IfAction SubSystem: '<S47>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S295>/Takeoff' */
  /* InitializeConditions for Delay: '<S736>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S732>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S732>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S295>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S651>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S651>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S295>/Return' */
  /* InitializeConditions for Delay: '<S681>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S682>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S677>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S723>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S660>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S663>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_on = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S663>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S697>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S696>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S696>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S696>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S696>/Move Control' */

  /* SystemInitialize for Merge: '<S696>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S687>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S686>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S686>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S686>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S686>/Move Control' */

  /* SystemInitialize for Merge: '<S686>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S295>/Hold' */
  /* InitializeConditions for Delay: '<S616>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S628>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;
  FMS_DW.Integrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S628>/Integrator' */
  FMS_DW.Integrator_DSTATE_hi = 0.0F;
  FMS_DW.Integrator_PrevResetState = 0;

  /* SystemInitialize for Chart: '<S604>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S615>/Motion State' */
  FMS_DW.temporalCounter_i1_il = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for Chart: '<S636>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S635>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S635>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S635>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S635>/Move Control' */

  /* SystemInitialize for Merge: '<S635>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S603>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S603>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S603>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S603>/Move Control' */

  /* SystemInitialize for Merge: '<S603>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S614>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S614>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S614>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S614>/Move Control' */

  /* SystemInitialize for Merge: '<S614>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S47>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S293>/Mission' */
  /* InitializeConditions for UnitDelay: '<S408>/Delay Input1'
   *
   * Block description for '<S408>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S405>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S435>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S436>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S431>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S483>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S413>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S416>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S416>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S457>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S456>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S456>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S456>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S466>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S466>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S456>/Move Control' */

  /* SystemInitialize for Merge: '<S456>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S456>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S466>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S466>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S456>/Move Control' */

  /* SystemInitialize for Merge: '<S456>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S447>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S446>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S446>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S446>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S453>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S446>/Move Control' */

  /* SystemInitialize for Merge: '<S446>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S405>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S293>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S47>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S292>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S388>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S389>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S389>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S388>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S393>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S392>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S392>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S392>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S392>/Move Control' */

  /* SystemInitialize for Merge: '<S392>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S292>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S292>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S321>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S322>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S322>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S321>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S308>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S307>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S307>/Hold Control' */

  /* SystemInitialize for Merge: '<S307>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S326>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S325>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S325>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S325>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S325>/Move Control' */

  /* SystemInitialize for Merge: '<S325>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S292>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S292>/Position' */
  /* SystemInitialize for Chart: '<S342>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S341>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S341>/Hold Control' */

  /* SystemInitialize for Chart: '<S354>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S367>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S366>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_jz);

  /* End of SystemInitialize for SubSystem: '<S366>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S366>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S376>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S376>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S366>/Move Control' */

  /* SystemInitialize for Merge: '<S366>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S366>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S376>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S376>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S366>/Move Control' */

  /* SystemInitialize for Merge: '<S366>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S341>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S353>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S353>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S353>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S353>/Move Control' */

  /* SystemInitialize for Merge: '<S353>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S292>/Position' */
  /* End of SystemInitialize for SubSystem: '<S47>/Assist' */
  /* End of SystemInitialize for SubSystem: '<S41>/MC_Mode' */
  /* End of SystemInitialize for SubSystem: '<S39>/Arm' */
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
