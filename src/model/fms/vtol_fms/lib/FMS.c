/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2494
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 27 13:47:10 2025
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

/* Named constants for Chart: '<S686>/Motion Status' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S696>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S392>/Motion State' */
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
                                        *   '<S738>/Constant'
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
                                        *   '<S596>/L1'
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
                                        *   '<S382>/Gain'
                                        *   '<S382>/Gain1'
                                        *   '<S384>/Constant'
                                        *   '<S408>/L1'
                                        *   '<S489>/Saturation'
                                        *   '<S490>/Saturation1'
                                        *   '<S490>/Saturation2'
                                        *   '<S490>/Saturation3'
                                        *   '<S647>/Land_Speed'
                                        *   '<S648>/Saturation1'
                                        *   '<S727>/Takeoff_Speed'
                                        *   '<S728>/Gain2'
                                        *   '<S728>/Saturation1'
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
                                        *   '<S385>/Dead Zone'
                                        *   '<S385>/Gain'
                                        *   '<S386>/Dead Zone'
                                        *   '<S386>/Gain'
                                        *   '<S391>/Saturation'
                                        *   '<S545>/Gain2'
                                        *   '<S552>/Gain1'
                                        *   '<S552>/Gain2'
                                        *   '<S602>/Saturation1'
                                        *   '<S613>/Saturation'
                                        *   '<S634>/Saturation1'
                                        *   '<S649>/Constant'
                                        *   '<S652>/Gain2'
                                        *   '<S676>/Constant'
                                        *   '<S676>/vel'
                                        *   '<S676>/Acceleration_Speed'
                                        *   '<S676>/Saturation'
                                        *   '<S676>/Switch'
                                        *   '<S680>/Constant'
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
                                        *   '<S368>/Gain2'
                                        *   '<S369>/Gain6'
                                        *   '<S379>/Constant'
                                        *   '<S380>/Constant'
                                        *   '<S394>/Gain2'
                                        *   '<S395>/Gain1'
                                        *   '<S402>/Constant'
                                        *   '<S427>/Gain'
                                        *   '<S427>/Saturation1'
                                        *   '<S430>/Constant'
                                        *   '<S430>/vel'
                                        *   '<S430>/Switch'
                                        *   '<S605>/Gain2'
                                        *   '<S606>/Gain1'
                                        *   '<S617>/Gain2'
                                        *   '<S618>/Gain1'
                                        *   '<S626>/Gain2'
                                        *   '<S626>/Saturation'
                                        *   '<S627>/Integrator'
                                        *   '<S637>/Gain2'
                                        *   '<S638>/Gain6'
                                        *   '<S661>/Gain2'
                                        *   '<S661>/Saturation'
                                        *   '<S662>/Integrator'
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
                                        *   '<S373>/Dead Zone'
                                        *   '<S373>/Gain'
                                        *   '<S374>/Dead Zone'
                                        *   '<S374>/Gain'
                                        *   '<S399>/Dead Zone'
                                        *   '<S399>/Gain'
                                        *   '<S414>/Gain2'
                                        *   '<S414>/Saturation'
                                        *   '<S415>/Integrator'
                                        *   '<S608>/Dead Zone'
                                        *   '<S608>/Gain'
                                        *   '<S622>/Dead Zone'
                                        *   '<S622>/Gain'
                                        *   '<S642>/Dead Zone'
                                        *   '<S642>/Gain'
                                        *   '<S643>/Dead Zone'
                                        *   '<S643>/Gain'
                                        *   '<S685>/Saturation1'
                                        *   '<S695>/Saturation1'
                                        *   '<S445>/Saturation1'
                                        *   '<S455>/Saturation1'
                                        *   '<S688>/Gain2'
                                        *   '<S689>/Gain1'
                                        *   '<S698>/Gain2'
                                        *   '<S699>/Gain6'
                                        *   '<S448>/Gain2'
                                        *   '<S449>/Gain1'
                                        *   '<S458>/Gain2'
                                        *   '<S459>/Gain6'
                                        *   '<S691>/Dead Zone'
                                        *   '<S691>/Gain'
                                        *   '<S703>/Dead Zone'
                                        *   '<S703>/Gain'
                                        *   '<S704>/Dead Zone'
                                        *   '<S704>/Gain'
                                        *   '<S451>/Dead Zone'
                                        *   '<S451>/Gain'
                                        *   '<S463>/Dead Zone'
                                        *   '<S463>/Gain'
                                        *   '<S464>/Dead Zone'
                                        *   '<S464>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S23>/Constant1'
                                        *   '<S737>/Constant'
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
 *    '<S678>/NearbyRefWP'
 *    '<S432>/NearbyRefWP'
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
 *    '<S678>/SearchL1RefWP'
 *    '<S432>/SearchL1RefWP'
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
 *    '<S685>/Brake Control'
 *    '<S602>/Brake Control'
 *    '<S613>/Brake Control'
 *    '<S445>/Brake Control'
 *    '<S391>/Brake Control'
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
 *    '<S685>/Hold Control'
 *    '<S602>/Hold Control'
 *    '<S445>/Hold Control'
 *    '<S307>/Hold Control'
 *    '<S341>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S688>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S685>/Hold Control'
 *    '<S602>/Hold Control'
 *    '<S445>/Hold Control'
 *    '<S307>/Hold Control'
 *    '<S341>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S688>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S685>/Hold Control'
 *    '<S602>/Hold Control'
 *    '<S445>/Hold Control'
 *    '<S307>/Hold Control'
 *    '<S341>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S688>/Delay' incorporates:
   *  Gain: '<S690>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S688>/Gain2' incorporates:
   *  Delay: '<S688>/Delay'
   *  Gain: '<S690>/Gain'
   *  Sum: '<S688>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S688>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S685>/Move Control'
 *    '<S602>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S692>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S692>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S685>/Move Control'
 *    '<S602>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S692>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S692>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S685>/Move Control'
 *    '<S602>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_aw;
  real32_T rtb_Subtract3_d;
  real32_T rtb_a_o;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S693>/Multiply1' incorporates:
   *  Constant: '<S693>/const1'
   *  DiscreteIntegrator: '<S692>/Integrator'
   */
  rtb_Add3_aw = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S691>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = 0.0F;
  } else {
    rtb_a_o = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S691>/Dead Zone' */

  /* Sum: '<S693>/Add' incorporates:
   *  DiscreteIntegrator: '<S692>/Integrator1'
   *  Gain: '<S689>/Gain1'
   *  Gain: '<S691>/Gain'
   *  Sum: '<S692>/Subtract'
   */
  rtb_Subtract3_d = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_o * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_aw;

  /* Signum: '<S693>/Sign' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_a_o = -1.0F;
  } else if (rtb_Subtract3_d > 0.0F) {
    rtb_a_o = 1.0F;
  } else {
    rtb_a_o = rtb_Subtract3_d;
  }

  /* End of Signum: '<S693>/Sign' */

  /* Sum: '<S693>/Add2' incorporates:
   *  Abs: '<S693>/Abs'
   *  Gain: '<S693>/Gain'
   *  Gain: '<S693>/Gain1'
   *  Product: '<S693>/Multiply2'
   *  Product: '<S693>/Multiply3'
   *  Sqrt: '<S693>/Sqrt'
   *  Sum: '<S693>/Add1'
   *  Sum: '<S693>/Subtract'
   */
  rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_d) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_o + rtb_Add3_aw;

  /* Sum: '<S693>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_d - rtb_a_o) + rtb_Add3_aw;

  /* Sum: '<S693>/Add3' */
  rtb_Add3_aw = rtb_Subtract3_d + localC->d;

  /* Sum: '<S693>/Subtract1' */
  rtb_Subtract3_d -= localC->d;

  /* Signum: '<S693>/Sign1' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S693>/Sign1' */

  /* Signum: '<S693>/Sign2' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S693>/Sign2' */

  /* Sum: '<S693>/Add5' incorporates:
   *  Gain: '<S693>/Gain2'
   *  Product: '<S693>/Multiply4'
   *  Sum: '<S693>/Subtract2'
   */
  rtb_a_o += (rtb_Add3_aw - rtb_Subtract3_d) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S692>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S692>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S692>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S692>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S693>/Add6' */
  rtb_Add3_aw = rtb_a_o + localC->d;

  /* Sum: '<S693>/Subtract3' */
  rtb_Subtract3_d = rtb_a_o - localC->d;

  /* Signum: '<S693>/Sign5' */
  if (rtb_a_o < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_o;
  }

  /* End of Signum: '<S693>/Sign5' */

  /* Signum: '<S693>/Sign3' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S693>/Sign3' */

  /* Signum: '<S693>/Sign4' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S693>/Sign4' */

  /* Signum: '<S693>/Sign6' */
  if (rtb_a_o < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_o;
  }

  /* End of Signum: '<S693>/Sign6' */

  /* Update for DiscreteIntegrator: '<S692>/Integrator' incorporates:
   *  Constant: '<S693>/const'
   *  Gain: '<S693>/Gain3'
   *  Product: '<S693>/Divide'
   *  Product: '<S693>/Multiply5'
   *  Product: '<S693>/Multiply6'
   *  Sum: '<S693>/Subtract4'
   *  Sum: '<S693>/Subtract5'
   *  Sum: '<S693>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_o / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_aw - rtb_Subtract3_d) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S686>/Motion Status'
 *    '<S603>/Motion Status'
 *    '<S446>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S686>/Motion Status'
 *    '<S603>/Motion Status'
 *    '<S446>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S686>/Motion Status'
 *    '<S603>/Motion Status'
 *    '<S446>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S686>/Motion Status' */
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

  /* End of Chart: '<S686>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S695>/Hold Control'
 *    '<S634>/Hold Control'
 *    '<S455>/Hold Control'
 */
void FMS_HoldControl_l_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S698>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S695>/Hold Control'
 *    '<S634>/Hold Control'
 *    '<S455>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S698>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S695>/Hold Control'
 *    '<S634>/Hold Control'
 *    '<S455>/Hold Control'
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

  /* Delay: '<S698>/Delay' incorporates:
   *  SignalConversion: '<S698>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S702>/Trigonometric Function1' incorporates:
   *  Gain: '<S701>/Gain'
   *  Trigonometry: '<S702>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S702>/Trigonometric Function' incorporates:
   *  Gain: '<S701>/Gain'
   *  Trigonometry: '<S702>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S702>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S702>/Constant3'
   */
  rtb_VectorConcatenate_al[2] = 0.0F;

  /* Gain: '<S702>/Gain' */
  rtb_VectorConcatenate_al[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S702>/Trigonometric Function3' */
  rtb_VectorConcatenate_al[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S702>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S702>/Constant4'
   */
  rtb_VectorConcatenate_al[5] = 0.0F;

  /* SignalConversion: '<S702>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_al[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_al[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_al[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S698>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S698>/Delay'
   *  SignalConversion: '<S698>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S698>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S698>/Multiply' incorporates:
   *  SignalConversion: '<S698>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_al[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_al[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S698>/Multiply' */

  /* Gain: '<S698>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S698>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S695>/Brake Control'
 *    '<S634>/Brake Control'
 *    '<S455>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S697>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S695>/Move Control'
 *    '<S634>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S705>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S705>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S705>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S705>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S695>/Move Control'
 *    '<S634>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S705>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S705>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S705>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S705>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S695>/Move Control'
 *    '<S634>/Move Control'
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

  /* DiscreteIntegrator: '<S705>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S706>/Multiply1' incorporates:
   *  Constant: '<S706>/const1'
   *  DiscreteIntegrator: '<S705>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S705>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S706>/Multiply1' incorporates:
   *  Constant: '<S706>/const1'
   *  DiscreteIntegrator: '<S705>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S703>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S703>/Dead Zone' */

  /* Sum: '<S706>/Add' incorporates:
   *  DiscreteIntegrator: '<S705>/Integrator1'
   *  Gain: '<S699>/Gain6'
   *  Gain: '<S703>/Gain'
   *  Sum: '<S705>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S704>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S704>/Dead Zone' */

  /* Sum: '<S706>/Add' incorporates:
   *  DiscreteIntegrator: '<S705>/Integrator1'
   *  Gain: '<S699>/Gain6'
   *  Gain: '<S704>/Gain'
   *  Sum: '<S705>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S706>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S706>/Add2' incorporates:
   *  Abs: '<S706>/Abs'
   *  Gain: '<S706>/Gain'
   *  Gain: '<S706>/Gain1'
   *  Product: '<S706>/Multiply2'
   *  Product: '<S706>/Multiply3'
   *  Signum: '<S706>/Sign'
   *  Sqrt: '<S706>/Sqrt'
   *  Sum: '<S706>/Add1'
   *  Sum: '<S706>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S706>/Add3' incorporates:
   *  Signum: '<S706>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S706>/Subtract1' incorporates:
   *  Signum: '<S706>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S706>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S706>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S706>/Add5' incorporates:
   *  Gain: '<S706>/Gain2'
   *  Product: '<S706>/Multiply4'
   *  Signum: '<S706>/Sign'
   *  Sum: '<S706>/Add2'
   *  Sum: '<S706>/Add4'
   *  Sum: '<S706>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S705>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S705>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S706>/Sign3' incorporates:
   *  Sum: '<S706>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S706>/Sign4' incorporates:
   *  Sum: '<S706>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S706>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S706>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S706>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S706>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S705>/Integrator' incorporates:
   *  Constant: '<S706>/const'
   *  Gain: '<S706>/Gain3'
   *  Product: '<S706>/Divide'
   *  Product: '<S706>/Multiply5'
   *  Product: '<S706>/Multiply6'
   *  Sum: '<S706>/Subtract4'
   *  Sum: '<S706>/Subtract5'
   *  Sum: '<S706>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S705>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S706>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S706>/Add2' incorporates:
   *  Abs: '<S706>/Abs'
   *  Gain: '<S706>/Gain'
   *  Gain: '<S706>/Gain1'
   *  Product: '<S706>/Multiply2'
   *  Product: '<S706>/Multiply3'
   *  Signum: '<S706>/Sign'
   *  Sqrt: '<S706>/Sqrt'
   *  Sum: '<S706>/Add1'
   *  Sum: '<S706>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S706>/Add3' incorporates:
   *  Signum: '<S706>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S706>/Subtract1' incorporates:
   *  Signum: '<S706>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S706>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S706>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S706>/Add5' incorporates:
   *  Gain: '<S706>/Gain2'
   *  Product: '<S706>/Multiply4'
   *  Signum: '<S706>/Sign'
   *  Sum: '<S706>/Add2'
   *  Sum: '<S706>/Add4'
   *  Sum: '<S706>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S705>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S705>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S706>/Sign3' incorporates:
   *  Sum: '<S706>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S706>/Sign4' incorporates:
   *  Sum: '<S706>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S706>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S706>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S706>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S706>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S705>/Integrator' incorporates:
   *  Constant: '<S706>/const'
   *  Gain: '<S706>/Gain3'
   *  Product: '<S706>/Divide'
   *  Product: '<S706>/Multiply5'
   *  Product: '<S706>/Multiply6'
   *  Sum: '<S706>/Subtract4'
   *  Sum: '<S706>/Subtract5'
   *  Sum: '<S706>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S705>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S696>/Motion State'
 *    '<S635>/Motion State'
 *    '<S456>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S696>/Motion State'
 *    '<S635>/Motion State'
 *    '<S456>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S696>/Motion State'
 *    '<S635>/Motion State'
 *    '<S456>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S696>/Motion State' */
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

  /* End of Chart: '<S696>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S678>/OutRegionRegWP'
 *    '<S432>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP_c(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_g, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S711>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S613>/Hold Control'
 *    '<S391>/Hold Control'
 *    '<S325>/Hold Control'
 *    '<S353>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S617>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S613>/Hold Control'
 *    '<S391>/Hold Control'
 *    '<S325>/Hold Control'
 *    '<S353>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S617>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S613>/Hold Control'
 *    '<S391>/Hold Control'
 *    '<S325>/Hold Control'
 *    '<S353>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S617>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S617>/Sum' incorporates:
   *  Delay: '<S617>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S620>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S620>/Switch' incorporates:
   *  Constant: '<S620>/Constant'
   *  Constant: '<S621>/Constant'
   *  Product: '<S620>/Multiply'
   *  RelationalOperator: '<S621>/Compare'
   *  Sum: '<S620>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S620>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S620>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S620>/Switch' */

  /* Gain: '<S617>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S617>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S613>/Move Control'
 *    '<S391>/Move Control'
 *    '<S325>/Move Control'
 *    '<S353>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S623>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S623>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S613>/Move Control'
 *    '<S391>/Move Control'
 *    '<S325>/Move Control'
 *    '<S353>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S623>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S623>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S613>/Move Control'
 *    '<S391>/Move Control'
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

  /* Product: '<S624>/Multiply1' incorporates:
   *  Constant: '<S624>/const1'
   *  DiscreteIntegrator: '<S623>/Integrator'
   */
  rtb_Add3_mb = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S622>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_h = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_h = 0.0F;
  } else {
    rtb_a_h = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S622>/Dead Zone' */

  /* Sum: '<S624>/Add' incorporates:
   *  DiscreteIntegrator: '<S623>/Integrator1'
   *  Gain: '<S618>/Gain1'
   *  Gain: '<S622>/Gain'
   *  Sum: '<S623>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_h * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_mb;

  /* Signum: '<S624>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_h = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_h = 1.0F;
  } else {
    rtb_a_h = rtb_Subtract3_e;
  }

  /* End of Signum: '<S624>/Sign' */

  /* Sum: '<S624>/Add2' incorporates:
   *  Abs: '<S624>/Abs'
   *  Gain: '<S624>/Gain'
   *  Gain: '<S624>/Gain1'
   *  Product: '<S624>/Multiply2'
   *  Product: '<S624>/Multiply3'
   *  Sqrt: '<S624>/Sqrt'
   *  Sum: '<S624>/Add1'
   *  Sum: '<S624>/Subtract'
   */
  rtb_a_h = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_h + rtb_Add3_mb;

  /* Sum: '<S624>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_e - rtb_a_h) + rtb_Add3_mb;

  /* Sum: '<S624>/Add3' */
  rtb_Add3_mb = rtb_Subtract3_e + localC->d;

  /* Sum: '<S624>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S624>/Sign1' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S624>/Sign1' */

  /* Signum: '<S624>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S624>/Sign2' */

  /* Sum: '<S624>/Add5' incorporates:
   *  Gain: '<S624>/Gain2'
   *  Product: '<S624>/Multiply4'
   *  Sum: '<S624>/Subtract2'
   */
  rtb_a_h += (rtb_Add3_mb - rtb_Subtract3_e) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S623>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S623>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S623>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S623>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S624>/Add6' */
  rtb_Add3_mb = rtb_a_h + localC->d;

  /* Sum: '<S624>/Subtract3' */
  rtb_Subtract3_e = rtb_a_h - localC->d;

  /* Signum: '<S624>/Sign5' */
  if (rtb_a_h < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_h;
  }

  /* End of Signum: '<S624>/Sign5' */

  /* Signum: '<S624>/Sign3' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S624>/Sign3' */

  /* Signum: '<S624>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S624>/Sign4' */

  /* Signum: '<S624>/Sign6' */
  if (rtb_a_h < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_h;
  }

  /* End of Signum: '<S624>/Sign6' */

  /* Update for DiscreteIntegrator: '<S623>/Integrator' incorporates:
   *  Constant: '<S624>/const'
   *  Gain: '<S624>/Gain3'
   *  Product: '<S624>/Divide'
   *  Product: '<S624>/Multiply5'
   *  Product: '<S624>/Multiply6'
   *  Sum: '<S624>/Subtract4'
   *  Sum: '<S624>/Subtract5'
   *  Sum: '<S624>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_h / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_mb - rtb_Subtract3_e) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S392>/Motion State'
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
 *    '<S392>/Motion State'
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
 *    '<S392>/Motion State'
 *    '<S326>/Motion State'
 *    '<S354>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S392>/Motion State' */
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

  /* End of Chart: '<S392>/Motion State' */
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
   *  Constant: '<S747>/Constant'
   *  RelationalOperator: '<S747>/Compare'
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

  /* Math: '<S758>/Rem' incorporates:
   *  Constant: '<S758>/Constant1'
   *  Sum: '<S742>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S758>/Switch' incorporates:
   *  Abs: '<S758>/Abs'
   *  Constant: '<S758>/Constant'
   *  Constant: '<S759>/Constant'
   *  Product: '<S758>/Multiply'
   *  RelationalOperator: '<S759>/Compare'
   *  Sum: '<S758>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S758>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S758>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S758>/Switch' */
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

  /* Sum: '<S764>/Sum of Elements' incorporates:
   *  Math: '<S764>/Math Function'
   *  SignalConversion: '<S764>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S764>/Math Function1' incorporates:
   *  Sum: '<S764>/Sum of Elements'
   *
   * About '<S764>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S764>/Math Function1' */

  /* Switch: '<S764>/Switch' incorporates:
   *  Constant: '<S764>/Constant'
   *  Product: '<S764>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S764>/Switch' */

  /* Product: '<S764>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a_idx_1 / rtb_Switch2_b;

  /* Sum: '<S762>/Subtract' incorporates:
   *  Product: '<S762>/Multiply'
   *  Product: '<S762>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S761>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S761>/Sign1' */

  /* Switch: '<S761>/Switch2' incorporates:
   *  Constant: '<S761>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S761>/Switch2' */

  /* DotProduct: '<S761>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S761>/Acos' incorporates:
   *  DotProduct: '<S761>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S761>/Multiply' incorporates:
   *  Trigonometry: '<S761>/Acos'
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

  /* Gain: '<S748>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S749>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S749>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S749>/Multiply1' incorporates:
   *  Product: '<S749>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S749>/Divide' incorporates:
   *  Constant: '<S749>/Constant'
   *  Constant: '<S749>/R'
   *  Sqrt: '<S749>/Sqrt'
   *  Sum: '<S749>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S749>/Product3' incorporates:
   *  Constant: '<S749>/Constant1'
   *  Product: '<S749>/Multiply1'
   *  Sum: '<S749>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S749>/Multiply2' incorporates:
   *  Trigonometry: '<S749>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S748>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S753>/Abs' incorporates:
   *  Abs: '<S756>/Abs1'
   *  Switch: '<S753>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S753>/Switch1' incorporates:
   *  Abs: '<S753>/Abs'
   *  Bias: '<S753>/Bias2'
   *  Bias: '<S753>/Bias3'
   *  Constant: '<S750>/Constant'
   *  Constant: '<S750>/Constant1'
   *  Constant: '<S755>/Constant'
   *  Gain: '<S753>/Gain1'
   *  Product: '<S753>/Multiply'
   *  RelationalOperator: '<S755>/Compare'
   *  Switch: '<S750>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S756>/Switch1' incorporates:
     *  Bias: '<S756>/Bias2'
     *  Bias: '<S756>/Bias3'
     *  Constant: '<S756>/Constant'
     *  Constant: '<S757>/Constant'
     *  Math: '<S756>/Math Function'
     *  RelationalOperator: '<S757>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S756>/Switch1' */

    /* Signum: '<S753>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S753>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S750>/Sum' incorporates:
   *  Sum: '<S748>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S748>/Multiply' incorporates:
   *  Gain: '<S748>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S752>/Switch1' incorporates:
   *  Abs: '<S752>/Abs1'
   *  Bias: '<S752>/Bias2'
   *  Bias: '<S752>/Bias3'
   *  Constant: '<S752>/Constant'
   *  Constant: '<S754>/Constant'
   *  Math: '<S752>/Math Function'
   *  RelationalOperator: '<S754>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S752>/Switch1' */

  /* Product: '<S748>/Multiply' incorporates:
   *  Gain: '<S748>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S748>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S751>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S751>/Sum2' incorporates:
   *  Product: '<S751>/Multiply1'
   *  Product: '<S751>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S751>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_e_idx_0;

  /* Product: '<S751>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S751>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S741>/Data Type Conversion' incorporates:
   *  Gain: '<S748>/Gain'
   *  Sum: '<S748>/Sum1'
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
  /* RelationalOperator: '<S760>/Compare' incorporates:
   *  Abs: '<S744>/Abs'
   *  Constant: '<S760>/Constant'
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
  boolean_T sf_internal_predicateOutput;
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
        if (fabsf(FMS_B.DiscreteTimeIntegrator5_p) < 1.0F) {
          sf_internal_predicateOutput = true;
        } else if (FMS_DW.temporalCounter_i2 >= 5000U) {
          sf_internal_predicateOutput = true;
        } else {
          FMS_B.flag = FMS_B.BusConversion_InsertedFor_FMSSt.flag;

          /* Outputs for Function Call SubSystem: '<S6>/VTOL_State.IsPosValid' */
          /* RelationalOperator: '<S746>/Compare' incorporates:
           *  Constant: '<S746>/Constant'
           *  S-Function (sfix_bitop): '<S739>/Bitwise AND'
           */
          FMS_B.Compare_b = ((FMS_B.flag & 212U) == 212U);

          /* End of Outputs for SubSystem: '<S6>/VTOL_State.IsPosValid' */
          sf_internal_predicateOutput = !FMS_B.Compare_b;
        }

        if (sf_internal_predicateOutput) {
          guard1 = true;
        } else {
          if (FMS_sf_msg_pop_M()) {
            sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
              FMS_Cmd_Pause);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            guard1 = true;
          } else {
            if (FMS_sf_msg_pop_VTOL_M()) {
              sf_internal_predicateOutput = (FMS_DW.VTOL_M_msgReservedData ==
                VTOLMode_Fixwing);
            } else {
              sf_internal_predicateOutput = false;
            }

            if (sf_internal_predicateOutput) {
              FMS_DW.is_VTOL_State = FMS_IN_ForwardTrans;
              FMS_B.vtol_state = VTOLState_ForwardTrans;
            }
          }
        }
        break;

       case FMS_IN_Fixwing:
        if (FMS_sf_msg_pop_VTOL_M()) {
          sf_internal_predicateOutput = (FMS_DW.VTOL_M_msgReservedData ==
            VTOLMode_Multicopter);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          FMS_DW.is_VTOL_State = FMS_IN_BackwardTrans;
          FMS_DW.temporalCounter_i2 = 0U;
          FMS_B.vtol_state = VTOLState_BackwardTrans;
        }
        break;

       case FMS_IN_ForwardTrans:
        FMS_B.Airspeed = FMS_B.DiscreteTimeIntegrator5;

        /* Outputs for Function Call SubSystem: '<S6>/VTOL_State.ForwardTransCplt' */
        /* RelationalOperator: '<S738>/Relational Operator' incorporates:
         *  Constant: '<S738>/Constant'
         */
        FMS_B.RelationalOperator = (FMS_B.Airspeed >=
          FMS_PARAM.FW_CRUISE_SPEED_MIN);

        /* End of Outputs for SubSystem: '<S6>/VTOL_State.ForwardTransCplt' */
        if (FMS_B.RelationalOperator) {
          FMS_DW.is_VTOL_State = FMS_IN_Fixwing;
          FMS_B.vtol_state = VTOLState_Fixwing;
        } else {
          if (FMS_sf_msg_pop_VTOL_M()) {
            sf_internal_predicateOutput = (FMS_DW.VTOL_M_msgReservedData ==
              VTOLMode_Multicopter);
          } else {
            sf_internal_predicateOutput = false;
          }

          if (sf_internal_predicateOutput) {
            FMS_DW.is_VTOL_State = FMS_IN_BackwardTrans;
            FMS_DW.temporalCounter_i2 = 0U;
            FMS_B.vtol_state = VTOLState_BackwardTrans;
          }
        }
        break;

       case FMS_IN_Multicopter:
        if (FMS_sf_msg_pop_VTOL_M()) {
          sf_internal_predicateOutput = (FMS_DW.VTOL_M_msgReservedData ==
            VTOLMode_Fixwing);
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
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
  real32_T rtb_VectorConcatenate_h[9];
  MotionState rtb_state_fg;
  MotionState rtb_state_og;
  real_T rtb_Switch1_n;
  real_T rtb_Gain;
  real_T rtb_Sum3;
  uint16_T rtb_y_aw;
  uint16_T rtb_y_cc;
  real32_T rtb_P_dg[2];
  boolean_T rtb_Compare_kd;
  real32_T rtb_P_cg[2];
  real32_T rtb_Subtract_hb[2];
  real32_T rtb_MatrixConcatenate1_i_0[3];
  real32_T rtb_VectorConcatenate_g0[3];
  boolean_T tmp[3];
  boolean_T tmp_0[3];
  boolean_T tmp_1[3];
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
   *  ActionPort: '<S404>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S404>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S408>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S47>/SubMode' incorporates:
   *  ActionPort: '<S295>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S295>/Return' incorporates:
   *  ActionPort: '<S596>/Action Port'
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
   *  Sqrt: '<S474>/Sqrt'
   *  Sqrt: '<S66>/Sqrt'
   *  Sqrt: '<S714>/Sqrt'
   *  Sum: '<S156>/Sum of Elements'
   *  Sum: '<S1>/Add'
   *  Sum: '<S242>/Sum of Elements'
   *  Sum: '<S476>/Sum of Elements'
   *  Sum: '<S68>/Sum of Elements'
   *  Sum: '<S716>/Sum of Elements'
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
  /* End of Outputs for SubSystem: '<S404>/Mission_SubSystem' */
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

  /* Switch: '<S1>/Switch' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  S-Function (sfix_bitop): '<S1>/Bitwise AND'
   */
  if ((FMS_U.INS_Out.flag & 512U) > 0U) {
    rtb_Divide_lr_idx_1 = FMS_U.INS_Out.airspeed;
  } else {
    rtb_Divide_lr_idx_1 = rtb_Divide_lr_idx_0;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_Divide_lr_idx_1 > 100.0F) {
    rtb_Divide_lr_idx_1 = 100.0F;
  } else {
    if (rtb_Divide_lr_idx_1 < 0.1F) {
      rtb_Divide_lr_idx_1 = 0.1F;
    }
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
    rtb_Switch_ga = FMS_DW.Delay_DSTATE_oi;
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
          /* Disable for SwitchCase: '<S695>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S685>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S634>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S602>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S613>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S293>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S404>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S455>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S445>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S404>/Mission_SubSystem' */
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
          /* Disable for SwitchCase: '<S391>/Switch Case' */
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
            /* Disable for SwitchCase: '<S695>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S685>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S634>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S602>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S613>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S293>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S404>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S455>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S445>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S404>/Mission_SubSystem' */
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
            /* Disable for SwitchCase: '<S391>/Switch Case' */
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
            FMS_DW.icLoad_lf = 1U;
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
          if (FMS_DW.icLoad_lf != 0) {
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
          FMS_DW.icLoad_lf = 0U;

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
          /* Outputs for IfAction SubSystem: '<S133>/Hold Control' incorporates:
           *  ActionPort: '<S136>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SwitchCase: '<S133>/Switch Case' incorporates:
           *  Gain: '<S179>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S168>/Trigonometric Function1'
           *  Trigonometry: '<S168>/Trigonometric Function3'
           *  Trigonometry: '<S180>/Trigonometric Function1'
           *  Trigonometry: '<S180>/Trigonometric Function3'
           */
          rtb_Add4_o = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S133>/Hold Control' */

          /* Trigonometry: '<S180>/Trigonometric Function1' */
          rtb_VectorConcatenate_h[0] = rtb_Add4_o;

          /* Outputs for IfAction SubSystem: '<S133>/Hold Control' incorporates:
           *  ActionPort: '<S136>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SwitchCase: '<S133>/Switch Case' incorporates:
           *  Gain: '<S179>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S168>/Trigonometric Function'
           *  Trigonometry: '<S180>/Trigonometric Function'
           *  Trigonometry: '<S180>/Trigonometric Function2'
           */
          rtb_Divide_or = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S133>/Hold Control' */

          /* Trigonometry: '<S180>/Trigonometric Function' */
          rtb_VectorConcatenate_h[1] = rtb_Divide_or;

          /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S180>/Constant3'
           */
          rtb_VectorConcatenate_h[2] = 0.0F;

          /* Gain: '<S180>/Gain' */
          rtb_VectorConcatenate_h[3] = -rtb_Divide_or;

          /* Trigonometry: '<S180>/Trigonometric Function3' */
          rtb_VectorConcatenate_h[4] = rtb_Add4_o;

          /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S180>/Constant4'
           */
          rtb_VectorConcatenate_h[5] = 0.0F;

          /* SignalConversion: '<S180>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_gy[0];
          rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_gy[1];
          rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_gy[2];

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

          /* Chart: '<S134>/Motion State' incorporates:
           *  Abs: '<S134>/Abs'
           */
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

              /* Product: '<S134>/Multiply' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S40>/Signal Copy1'
               */
              for (rtb_n = 0; rtb_n < 3; rtb_n++) {
                /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
                rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n
                  + 6] * FMS_U.INS_Out.vd + (rtb_VectorConcatenate_h[rtb_n + 3] *
                  FMS_U.INS_Out.ve + rtb_VectorConcatenate_h[rtb_n] *
                  FMS_U.INS_Out.vn);

                /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              }

              /* End of Product: '<S134>/Multiply' */
              if ((FMS_DW.temporalCounter_i1_i >= 625U) && (fabsf
                   (rtb_VectorConcatenate_g0[0]) > 5.0F)) {
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
            rtb_VectorConcatenate_h[0] = (rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) -
              (rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2 + rtb_Saturation_e *
               rtb_Saturation_e);

            /* Gain: '<S145>/Gain' incorporates:
             *  Product: '<S145>/Multiply'
             *  Product: '<S145>/Multiply1'
             *  Sum: '<S145>/Subtract1'
             */
            rtb_VectorConcatenate_h[1] = (rtb_Divide_pr_idx_1 *
              rtb_Divide_pr_idx_2 - rtb_Divide_pr_idx_0 * rtb_Saturation_e) *
              2.0F;

            /* Gain: '<S145>/Gain1' incorporates:
             *  Product: '<S145>/Multiply2'
             *  Product: '<S145>/Multiply3'
             *  Sum: '<S145>/Add2'
             */
            rtb_VectorConcatenate_h[2] = (rtb_Divide_pr_idx_1 * rtb_Saturation_e
              + rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_2) * 2.0F;

            /* Gain: '<S146>/Gain' incorporates:
             *  Product: '<S146>/Multiply'
             *  Product: '<S146>/Multiply1'
             *  Sum: '<S146>/Add3'
             */
            rtb_VectorConcatenate_h[3] = (rtb_Divide_pr_idx_1 *
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
            rtb_VectorConcatenate_h[4] = (rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2) -
              (rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 + rtb_Saturation_e *
               rtb_Saturation_e);

            /* Gain: '<S146>/Gain1' incorporates:
             *  Product: '<S146>/Multiply2'
             *  Product: '<S146>/Multiply3'
             *  Sum: '<S146>/Subtract1'
             */
            rtb_VectorConcatenate_h[5] = (rtb_Divide_pr_idx_2 * rtb_Saturation_e
              - rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_1) * 2.0F;

            /* Gain: '<S147>/Gain' incorporates:
             *  Product: '<S147>/Multiply'
             *  Product: '<S147>/Multiply1'
             *  Sum: '<S147>/Subtract2'
             */
            rtb_VectorConcatenate_h[6] = (rtb_Divide_pr_idx_1 * rtb_Saturation_e
              - rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_2) * 2.0F;

            /* Gain: '<S147>/Gain1' incorporates:
             *  Product: '<S147>/Multiply2'
             *  Product: '<S147>/Multiply3'
             *  Sum: '<S147>/Add2'
             */
            rtb_VectorConcatenate_h[7] = (rtb_Divide_pr_idx_2 * rtb_Saturation_e
              + rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_1) * 2.0F;

            /* Sum: '<S147>/Subtract' incorporates:
             *  Math: '<S147>/Square'
             *  Math: '<S147>/Square1'
             *  Math: '<S147>/Square2'
             *  Math: '<S147>/Square3'
             *  Sum: '<S147>/Add'
             *  Sum: '<S147>/Add1'
             */
            rtb_VectorConcatenate_h[8] = (rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Saturation_e * rtb_Saturation_e) -
              (rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2 *
               rtb_Divide_pr_idx_2);

            /* Product: '<S138>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 6] *
                FMS_U.INS_Out.vd + (rtb_VectorConcatenate_h[rtb_n + 3] *
                                    FMS_U.INS_Out.ve +
                                    rtb_VectorConcatenate_h[rtb_n] *
                                    FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* End of Product: '<S138>/Multiply' */

            /* Trigonometry: '<S168>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = rtb_Add4_o;

            /* Trigonometry: '<S168>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = rtb_Divide_or;

            /* SignalConversion: '<S168>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S168>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S168>/Gain' incorporates:
             *  Gain: '<S167>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S168>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S168>/Trigonometric Function3' */
            rtb_VectorConcatenate_h[4] = rtb_Add4_o;

            /* SignalConversion: '<S168>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S168>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_lr[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_lr[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_lr[2];

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
              rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n +
                3] * FMS_U.INS_Out.ve + rtb_VectorConcatenate_h[rtb_n] *
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
                rtb_VectorConcatenate_g0[1];
            }

            if (FMS_DW.DiscreteTimeIntegrator1_PrevR_p != 0) {
              FMS_DW.DiscreteTimeIntegrator1_DSTA_jv = 0.0F -
                rtb_VectorConcatenate_g0[1];
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
              FMS_B.Merge_be = (0.0F - rtb_VectorConcatenate_g0[1]) * 1.2F +
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
              rtb_VectorConcatenate_g0[1]) * 0.5F * 0.004F;
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
              rtb_VectorConcatenate_g0[1]) -
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
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.1F) {
            rtb_Saturation_e = 0.1F;
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
      rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S75>/Trigonometric Function' incorporates:
       *  Gain: '<S73>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S75>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S75>/Constant3'
       */
      rtb_VectorConcatenate_h[2] = 0.0F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Gain: '<S75>/Gain' incorporates:
       *  Gain: '<S73>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       *  Trigonometry: '<S75>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S75>/Trigonometric Function3' incorporates:
       *  Gain: '<S73>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S75>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S75>/Constant4'
       */
      rtb_VectorConcatenate_h[5] = 0.0F;

      /* SignalConversion: '<S75>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_n[0];
      rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_n[1];
      rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_n[2];

      /* Math: '<S53>/Transpose' */
      for (rtb_n = 0; rtb_n < 3; rtb_n++) {
        rtb_MatrixConcatenate1_i[3 * rtb_n] = rtb_VectorConcatenate_h[rtb_n];
        rtb_MatrixConcatenate1_i[1 + 3 * rtb_n] = rtb_VectorConcatenate_h[rtb_n
          + 3];
        rtb_MatrixConcatenate1_i[2 + 3 * rtb_n] = rtb_VectorConcatenate_h[rtb_n
          + 6];
      }

      for (rtb_n = 0; rtb_n < 9; rtb_n++) {
        rtb_VectorConcatenate_h[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n];
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
        rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_h[rtb_n];
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
      rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S80>/Trigonometric Function' incorporates:
       *  Gain: '<S79>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S80>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S80>/Constant3'
       */
      rtb_VectorConcatenate_h[2] = 0.0F;

      /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
      /* Gain: '<S80>/Gain' incorporates:
       *  Gain: '<S79>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       *  Trigonometry: '<S80>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

      /* Trigonometry: '<S80>/Trigonometric Function3' incorporates:
       *  Gain: '<S79>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S40>/Signal Copy1'
       */
      rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

      /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

      /* SignalConversion: '<S80>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S80>/Constant4'
       */
      rtb_VectorConcatenate_h[5] = 0.0F;

      /* SignalConversion: '<S80>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_o[0];
      rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_o[1];
      rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_o[2];

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
        rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 3] *
          FMS_U.INS_Out.ve + rtb_VectorConcatenate_h[rtb_n] * FMS_U.INS_Out.vn;

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
          rtb_VectorConcatenate_g0[1];
      }

      if (FMS_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
        FMS_DW.DiscreteTimeIntegrator1_DSTAT_j = 0.0F -
          rtb_VectorConcatenate_g0[1];
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
        rtb_Saturation_e = (0.0F - rtb_VectorConcatenate_g0[1]) * 1.2F +
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
        rtb_VectorConcatenate_g0[1]) * 0.5F * 0.004F;
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
        rtb_VectorConcatenate_g0[1]) - FMS_DW.DiscreteTimeIntegrator1_DSTAT_j) *
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
            /* Disable for SwitchCase: '<S695>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S685>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S634>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S602>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S613>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S293>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S404>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S455>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S445>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S404>/Mission_SubSystem' */
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
            /* Disable for SwitchCase: '<S391>/Switch Case' */
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
         *  Math: '<S717>/Math Function'
         *  Sum: '<S679>/Subtract'
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
            /* Disable for SwitchCase: '<S695>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S685>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S634>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S602>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S613>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Takeoff' incorporates:
             *  ActionPort: '<S597>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Delay: '<S735>/cur_waypoint'
             *  DiscreteIntegrator: '<S731>/Integrator'
             *  DiscreteIntegrator: '<S731>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S295>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Takeoff' incorporates:
           *  ActionPort: '<S597>/Action Port'
           */
          /* Delay: '<S735>/cur_waypoint' incorporates:
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
          /* Product: '<S735>/Divide' incorporates:
           *  Delay: '<S735>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S735>/Sum1'
           *  Sum: '<S735>/Sum2'
           */
          rtb_Divide_lr_idx_2 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S735>/Saturation' */
          if (rtb_Divide_lr_idx_2 > 1.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S735>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S736>/Trigonometric Function1' incorporates:
           *  Gain: '<S734>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S736>/Trigonometric Function' incorporates:
           *  Gain: '<S734>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S736>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S736>/Constant3'
           */
          rtb_VectorConcatenate_h[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S736>/Gain' incorporates:
           *  Gain: '<S734>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S736>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S736>/Trigonometric Function3' incorporates:
           *  Gain: '<S734>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S736>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S736>/Constant4'
           */
          rtb_VectorConcatenate_h[5] = 0.0F;

          /* SignalConversion: '<S736>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_cs[0];
          rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_cs[1];
          rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_cs[2];

          /* Saturate: '<S728>/Saturation1' */
          rtb_Divide_pr_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Divide_pr_idx_2 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S728>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S735>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S735>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S728>/Sum'
           *  Sum: '<S735>/Sum3'
           *  Sum: '<S735>/Sum4'
           */
          rtb_Divide_pr_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_lr_idx_2 +
            FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
          rtb_Divide_lr_idx_2 = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Divide_lr_idx_2 +
            FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S728>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 3]
              * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
              rtb_Divide_pr_idx_1;
          }

          /* Saturate: '<S728>/Saturation1' incorporates:
           *  Gain: '<S728>/Gain2'
           *  Product: '<S728>/Multiply'
           */
          rtb_Saturation_e = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
          rtb_Divide_pr_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

          /* BusAssignment: '<S597>/Bus Assignment1' incorporates:
           *  Constant: '<S597>/Constant'
           *  Constant: '<S597>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S728>/Saturation1' */
          if (rtb_Saturation_e > rtb_Divide_pr_idx_0) {
            /* BusAssignment: '<S597>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_0;
          } else if (rtb_Saturation_e < rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S597>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_2;
          } else {
            /* BusAssignment: '<S597>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_e;
          }

          if (rtb_Divide_pr_idx_1 > rtb_Divide_pr_idx_0) {
            /* BusAssignment: '<S597>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_0;
          } else if (rtb_Divide_pr_idx_1 < rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S597>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_2;
          } else {
            /* BusAssignment: '<S597>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_1;
          }

          /* BusAssignment: '<S597>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S731>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S732>/Multiply1' incorporates:
           *  Constant: '<S732>/const1'
           *  DiscreteIntegrator: '<S731>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S727>/Switch' incorporates:
           *  Abs: '<S727>/Abs'
           *  Abs: '<S727>/Abs1'
           *  Constant: '<S727>/Takeoff_Speed'
           *  Constant: '<S729>/Constant'
           *  Constant: '<S730>/Constant'
           *  Gain: '<S727>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S727>/Logical Operator'
           *  RelationalOperator: '<S729>/Compare'
           *  RelationalOperator: '<S730>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S727>/Sum'
           *  Sum: '<S727>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_Saturation_e = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_Saturation_e = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S727>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S732>/Add' incorporates:
           *  DiscreteIntegrator: '<S731>/Integrator1'
           *  Sum: '<S731>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_f - rtb_Saturation_e)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S732>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S732>/Sign' */

          /* Sum: '<S732>/Add2' incorporates:
           *  Abs: '<S732>/Abs'
           *  Gain: '<S732>/Gain'
           *  Gain: '<S732>/Gain1'
           *  Product: '<S732>/Multiply2'
           *  Product: '<S732>/Multiply3'
           *  Sqrt: '<S732>/Sqrt'
           *  Sum: '<S732>/Add1'
           *  Sum: '<S732>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_b) * FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_lr_idx_2;

          /* Sum: '<S732>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S732>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_b;

          /* Sum: '<S732>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_b;

          /* Signum: '<S732>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S732>/Sign1' */

          /* Signum: '<S732>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S732>/Sign2' */

          /* Sum: '<S732>/Add5' incorporates:
           *  Gain: '<S732>/Gain2'
           *  Product: '<S732>/Multiply4'
           *  Sum: '<S732>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Update for Delay: '<S735>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S731>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S731>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S732>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_b;

          /* Sum: '<S732>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_b;

          /* Signum: '<S732>/Sign5' incorporates:
           *  Signum: '<S732>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S732>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S732>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;

            /* Signum: '<S732>/Sign6' */
            rtb_Add4_o = rtb_Saturation_e;
          }

          /* End of Signum: '<S732>/Sign5' */

          /* Signum: '<S732>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S732>/Sign3' */

          /* Signum: '<S732>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S732>/Sign4' */

          /* Update for DiscreteIntegrator: '<S731>/Integrator' incorporates:
           *  Constant: '<S732>/const'
           *  Gain: '<S732>/Gain3'
           *  Product: '<S732>/Divide'
           *  Product: '<S732>/Multiply5'
           *  Product: '<S732>/Multiply6'
           *  Sum: '<S732>/Subtract4'
           *  Sum: '<S732>/Subtract5'
           *  Sum: '<S732>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_Saturation_e / FMS_ConstB.d_b -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_i * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S295>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Land' incorporates:
             *  ActionPort: '<S595>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S650>/Integrator'
             *  DiscreteIntegrator: '<S650>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S295>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Land' incorporates:
           *  ActionPort: '<S595>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S655>/Trigonometric Function1' incorporates:
           *  Gain: '<S654>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S655>/Trigonometric Function' incorporates:
           *  Gain: '<S654>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S655>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S655>/Constant3'
           */
          rtb_VectorConcatenate_h[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S655>/Gain' incorporates:
           *  Gain: '<S654>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S655>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S655>/Trigonometric Function3' incorporates:
           *  Gain: '<S654>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S655>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S655>/Constant4'
           */
          rtb_VectorConcatenate_h[5] = 0.0F;

          /* SignalConversion: '<S655>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S648>/Saturation1' */
          rtb_Divide_pr_idx_2 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Add4_o = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S652>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S652>/Sum'
           */
          rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_lr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S652>/Multiply' incorporates:
           *  SignalConversion: '<S652>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S652>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 3]
              * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
              rtb_Divide_pr_idx_1;
          }

          /* End of Product: '<S652>/Multiply' */

          /* Saturate: '<S648>/Saturation1' incorporates:
           *  Gain: '<S652>/Gain2'
           */
          rtb_Saturation_e = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
          rtb_Divide_pr_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

          /* BusAssignment: '<S595>/Bus Assignment1' incorporates:
           *  Constant: '<S595>/Constant'
           *  Constant: '<S595>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S648>/Saturation1' */
          if (rtb_Saturation_e > rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S595>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_2;
          } else if (rtb_Saturation_e < rtb_Add4_o) {
            /* BusAssignment: '<S595>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Add4_o;
          } else {
            /* BusAssignment: '<S595>/Bus Assignment1' */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_e;
          }

          if (rtb_Divide_pr_idx_1 > rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S595>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_2;
          } else if (rtb_Divide_pr_idx_1 < rtb_Add4_o) {
            /* BusAssignment: '<S595>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Add4_o;
          } else {
            /* BusAssignment: '<S595>/Bus Assignment1' */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_1;
          }

          /* BusAssignment: '<S595>/Bus Assignment1' incorporates:
           *  DiscreteIntegrator: '<S650>/Integrator1'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S651>/Multiply1' incorporates:
           *  Constant: '<S651>/const1'
           *  DiscreteIntegrator: '<S650>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S647>/Switch' incorporates:
           *  Constant: '<S647>/Land_Speed'
           *  Constant: '<S649>/Constant'
           *  Gain: '<S647>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S647>/Logical Operator'
           *  RelationalOperator: '<S649>/Compare'
           *  S-Function (sfix_bitop): '<S647>/cmd_p valid'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_Saturation_e = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_Saturation_e = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S647>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S651>/Add' incorporates:
           *  DiscreteIntegrator: '<S650>/Integrator1'
           *  Sum: '<S650>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_g - rtb_Saturation_e) +
            rtb_Divide_pr_idx_1;

          /* Signum: '<S651>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S651>/Sign' */

          /* Sum: '<S651>/Add2' incorporates:
           *  Abs: '<S651>/Abs'
           *  Gain: '<S651>/Gain'
           *  Gain: '<S651>/Gain1'
           *  Product: '<S651>/Multiply2'
           *  Product: '<S651>/Multiply3'
           *  Sqrt: '<S651>/Sqrt'
           *  Sum: '<S651>/Add1'
           *  Sum: '<S651>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_om) * FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

          /* Sum: '<S651>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_pr_idx_1;

          /* Sum: '<S651>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_om;

          /* Sum: '<S651>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_om;

          /* Signum: '<S651>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S651>/Sign1' */

          /* Signum: '<S651>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S651>/Sign2' */

          /* Sum: '<S651>/Add5' incorporates:
           *  Gain: '<S651>/Gain2'
           *  Product: '<S651>/Multiply4'
           *  Sum: '<S651>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Update for DiscreteIntegrator: '<S650>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S650>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S651>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_om;

          /* Sum: '<S651>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_om;

          /* Signum: '<S651>/Sign5' incorporates:
           *  Signum: '<S651>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S651>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S651>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S651>/Sign6' */
            rtb_Add4_o = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S651>/Sign5' */

          /* Signum: '<S651>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S651>/Sign3' */

          /* Signum: '<S651>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S651>/Sign4' */

          /* Update for DiscreteIntegrator: '<S650>/Integrator' incorporates:
           *  Constant: '<S651>/const'
           *  Gain: '<S651>/Gain3'
           *  Product: '<S651>/Divide'
           *  Product: '<S651>/Multiply5'
           *  Product: '<S651>/Multiply6'
           *  Sum: '<S651>/Subtract4'
           *  Sum: '<S651>/Subtract5'
           *  Sum: '<S651>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_Divide_lr_idx_2 / FMS_ConstB.d_om
            - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_p * ((rtb_Divide_pr_idx_0
            - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S295>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Return' incorporates:
             *  ActionPort: '<S596>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Delay: '<S659>/Delay'
             *  Delay: '<S680>/Delay'
             *  DiscreteIntegrator: '<S662>/Integrator'
             *  DiscreteIntegrator: '<S662>/Integrator1'
             *  DiscreteIntegrator: '<S676>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S681>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S722>/Discrete-Time Integrator'
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
             *  ActionPort: '<S596>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Chart: '<S686>/Motion Status'
             *  Chart: '<S696>/Motion State'
             */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S295>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Return' incorporates:
           *  ActionPort: '<S596>/Action Port'
           */
          /* Delay: '<S680>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S675>/Compare' incorporates:
           *  Constant: '<S726>/Constant'
           *  DiscreteIntegrator: '<S681>/Discrete-Time Integrator'
           *  RelationalOperator: '<S726>/Compare'
           */
          rtb_FixPtRelationalOperator_me =
            (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S676>/Acceleration_Speed' */
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
          /* Chart: '<S696>/Motion State' incorporates:
           *  Constant: '<S696>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S696>/Square'
           *  Math: '<S696>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S696>/Sqrt'
           *  Sum: '<S696>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S695>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S695>/Hold Control' incorporates:
               *  ActionPort: '<S698>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S695>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S695>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S695>/Hold Control' incorporates:
             *  ActionPort: '<S698>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S695>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S695>/Brake Control' incorporates:
             *  ActionPort: '<S697>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S695>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S695>/Move Control' incorporates:
               *  ActionPort: '<S699>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S695>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S695>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S695>/Move Control' incorporates:
             *  ActionPort: '<S699>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S695>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S695>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S686>/Motion Status' incorporates:
           *  Abs: '<S686>/Abs'
           *  Constant: '<S686>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S685>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S685>/Hold Control' incorporates:
               *  ActionPort: '<S688>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S685>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S685>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S685>/Hold Control' incorporates:
             *  ActionPort: '<S688>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S685>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S685>/Brake Control' incorporates:
             *  ActionPort: '<S687>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S685>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S685>/Move Control' incorporates:
               *  ActionPort: '<S689>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S685>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c);

              /* End of SystemReset for SubSystem: '<S685>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S685>/Move Control' incorporates:
             *  ActionPort: '<S689>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S685>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S685>/Switch Case' */

          /* Switch: '<S657>/Switch' incorporates:
           *  Product: '<S680>/Multiply'
           *  Sum: '<S680>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S695>/Saturation1' */
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

            /* End of Saturate: '<S695>/Saturation1' */

            /* Saturate: '<S685>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S685>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S680>/Sum' incorporates:
             *  Delay: '<S680>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S723>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S676>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Square_bg[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S680>/Sum' incorporates:
             *  Delay: '<S680>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S676>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S682>/Sqrt' incorporates:
             *  Math: '<S682>/Square'
             *  Sum: '<S676>/Sum'
             *  Sum: '<S682>/Sum of Elements'
             */
            rtb_Saturation_e = sqrtf(rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0 +
              rtb_Saturation_e * rtb_Saturation_e);

            /* SignalConversion: '<S725>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S725>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S725>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S724>/Gain' incorporates:
             *  DiscreteIntegrator: '<S722>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S722>/Add'
             */
            rtb_Divide_pr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S725>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S725>/Trigonometric Function1'
             */
            rtb_Add4_o = arm_cos_f32(rtb_Divide_pr_idx_2);
            rtb_VectorConcatenate_h[4] = rtb_Add4_o;

            /* Trigonometry: '<S725>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S725>/Trigonometric Function'
             */
            rtb_Divide_or = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S725>/Gain' incorporates:
             *  Trigonometry: '<S725>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -rtb_Divide_or;

            /* SignalConversion: '<S725>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S725>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S725>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = rtb_Divide_or;

            /* Trigonometry: '<S725>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = rtb_Add4_o;

            /* Switch: '<S676>/Switch' incorporates:
             *  Constant: '<S676>/vel'
             */
            if (rtb_Saturation_e > FMS_PARAM.L1) {
              rtb_Divide_pr_idx_2 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S676>/Gain' */
              rtb_Divide_pr_idx_2 = 0.5F * rtb_Saturation_e;

              /* Saturate: '<S676>/Saturation' */
              if (rtb_Divide_pr_idx_2 > FMS_PARAM.CRUISE_SPEED) {
                rtb_Divide_pr_idx_2 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Divide_pr_idx_2 < 0.5F) {
                  rtb_Divide_pr_idx_2 = 0.5F;
                }
              }

              /* End of Saturate: '<S676>/Saturation' */
            }

            /* End of Switch: '<S676>/Switch' */

            /* Switch: '<S676>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S676>/Acceleration_Speed'
             *  Sum: '<S676>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Divide_pr_idx_2 < 0.0F)
            {
              rtb_Divide_pr_idx_2 = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S676>/Switch1' */

            /* Sum: '<S723>/Sum of Elements' incorporates:
             *  Math: '<S723>/Math Function'
             */
            rtb_Saturation_e = rtb_Switch_c2[0] * rtb_Switch_c2[0] +
              rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

            /* Math: '<S723>/Math Function1' incorporates:
             *  Sum: '<S723>/Sum of Elements'
             *
             * About '<S723>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Saturation_e = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S723>/Math Function1' */

            /* Switch: '<S723>/Switch' incorporates:
             *  Constant: '<S723>/Constant'
             *  Product: '<S723>/Product'
             */
            if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_0 = rtb_Square_bg[0];
            } else {
              rtb_Divide_pr_idx_0 = 0.0F;
              rtb_Divide_pr_idx_1 = 0.0F;
              rtb_Saturation_e = 1.0F;
            }

            /* End of Switch: '<S723>/Switch' */

            /* Product: '<S721>/Multiply2' incorporates:
             *  Product: '<S723>/Divide'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_0 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_1 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_c2[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_pr_idx_1 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_0;
            }
          }

          /* End of Switch: '<S657>/Switch' */

          /* Delay: '<S659>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S662>/Integrator1' incorporates:
           *  Delay: '<S659>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_on != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S666>/Rem' incorporates:
           *  Constant: '<S666>/Constant1'
           *  DiscreteIntegrator: '<S662>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S661>/Sum'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S666>/Switch' incorporates:
           *  Abs: '<S666>/Abs'
           *  Constant: '<S666>/Constant'
           *  Constant: '<S667>/Constant'
           *  Product: '<S666>/Multiply'
           *  RelationalOperator: '<S667>/Compare'
           *  Sum: '<S666>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S666>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S666>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S666>/Switch' */

          /* Gain: '<S661>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S661>/Saturation' */
          if (rtb_Divide_pr_idx_2 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_pr_idx_2 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Divide_pr_idx_2 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_2 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S661>/Saturation' */

          /* BusAssignment: '<S596>/Bus Assignment1' incorporates:
           *  Constant: '<S596>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_li;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_c2[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_c2[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_c2[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_2;

          /* Math: '<S716>/Math Function1'
           *
           * About '<S716>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S716>/Math Function1' */

          /* Switch: '<S716>/Switch' incorporates:
           *  Constant: '<S716>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S716>/Product'
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

          /* End of Switch: '<S716>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S596>/Sum' incorporates:
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

          /* SignalConversion: '<S673>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S596>/Sum'
           */
          rtb_P_cg[0] = rtb_Divide_pr_idx_0;
          rtb_P_cg[1] = rtb_Divide_pr_idx_1;

          /* Math: '<S673>/Math Function' incorporates:
           *  Sum: '<S596>/Sum'
           */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

          /* Sum: '<S673>/Sum of Elements' */
          rtb_Saturation_e = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S673>/Math Function1' incorporates:
           *  Sum: '<S673>/Sum of Elements'
           *
           * About '<S673>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S673>/Math Function1' */

          /* Switch: '<S673>/Switch' incorporates:
           *  Constant: '<S673>/Constant'
           *  Product: '<S673>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Divide_or = rtb_Divide_pr_idx_2;
          } else {
            rtb_Divide_pr_idx_0 = 0.0F;
            rtb_Divide_pr_idx_1 = 0.0F;
            rtb_Divide_or = 1.0F;
          }

          /* End of Switch: '<S673>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S678>/NearbyRefWP' incorporates:
           *  Constant: '<S596>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_i5,
                          &rtb_Saturation_e);

          /* MATLAB Function: '<S678>/SearchL1RefWP' incorporates:
           *  Constant: '<S596>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_cg, &rtb_Divide_pr_idx_2);

          /* MATLAB Function: '<S678>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S678>/Switch1' incorporates:
           *  Constant: '<S709>/Constant'
           *  RelationalOperator: '<S709>/Compare'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_i5[0];
            rtb_P_cg[1] = rtb_Divide_i5[1];
          } else {
            /* RelationalOperator: '<S708>/Compare' incorporates:
             *  Constant: '<S708>/Constant'
             */
            rtb_Compare_kd = (rtb_Divide_pr_idx_2 >= 0.0F);

            /* Switch: '<S678>/Switch' */
            if (!rtb_Compare_kd) {
              rtb_P_cg[0] = rtb_Square_ds[0];
              rtb_P_cg[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S678>/Switch' */
          }

          /* End of Switch: '<S678>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S679>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Add4_o = rtb_P_cg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_cg[0] = rtb_Add4_o;
          rtb_Subtract_hb[0] = rtb_Add4_o * rtb_Add4_o;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S679>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S717>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Add4_o = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S717>/Sum of Elements' incorporates:
           *  Math: '<S717>/Math Function'
           *  Sum: '<S715>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] + rtb_Add4_o * rtb_Add4_o;

          /* Math: '<S717>/Math Function1' incorporates:
           *  Sum: '<S717>/Sum of Elements'
           *
           * About '<S717>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S717>/Math Function1' */

          /* Switch: '<S717>/Switch' incorporates:
           *  Constant: '<S717>/Constant'
           *  Product: '<S717>/Product'
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

          /* End of Switch: '<S717>/Switch' */

          /* Product: '<S716>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S719>/Sum of Elements' incorporates:
           *  Math: '<S719>/Math Function'
           *  SignalConversion: '<S719>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S719>/Math Function1' incorporates:
           *  Sum: '<S719>/Sum of Elements'
           *
           * About '<S719>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S719>/Math Function1' */

          /* Switch: '<S719>/Switch' incorporates:
           *  Constant: '<S719>/Constant'
           *  Product: '<S719>/Product'
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

          /* End of Switch: '<S719>/Switch' */

          /* Product: '<S717>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

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
            rtb_Switch_an[0] = rtb_Divide_i5[1];
            rtb_Switch_an[1] = rtb_Divide_i5[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S720>/Switch' */

          /* Product: '<S720>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S719>/Divide' */
          rtb_P_cg[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S673>/Divide' */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 / rtb_Divide_or;

          /* Product: '<S720>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S719>/Divide' */
          rtb_P_cg[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S673>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 / rtb_Divide_or;

          /* Sum: '<S718>/Subtract' incorporates:
           *  Product: '<S718>/Multiply'
           *  Product: '<S718>/Multiply1'
           */
          rtb_Divide_pr_idx_2 = rtb_Divide_i5[0] * rtb_P_cg[1] - rtb_Divide_i5[1]
            * rtb_P_cg[0];

          /* Signum: '<S713>/Sign1' */
          if (rtb_Divide_pr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S713>/Sign1' */

          /* Switch: '<S713>/Switch2' incorporates:
           *  Constant: '<S713>/Constant4'
           */
          if (rtb_Divide_pr_idx_2 == 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          }

          /* End of Switch: '<S713>/Switch2' */

          /* DotProduct: '<S713>/Dot Product' */
          rtb_Add4_o = rtb_P_cg[0] * rtb_Divide_i5[0] + rtb_P_cg[1] *
            rtb_Divide_i5[1];

          /* Trigonometry: '<S713>/Acos' incorporates:
           *  DotProduct: '<S713>/Dot Product'
           */
          if (rtb_Add4_o > 1.0F) {
            rtb_Add4_o = 1.0F;
          } else {
            if (rtb_Add4_o < -1.0F) {
              rtb_Add4_o = -1.0F;
            }
          }

          /* Product: '<S713>/Multiply' incorporates:
           *  Trigonometry: '<S713>/Acos'
           */
          rtb_Divide_pr_idx_2 *= acosf(rtb_Add4_o);

          /* Saturate: '<S679>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.57079637F) {
            rtb_Divide_pr_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.57079637F) {
              rtb_Divide_pr_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S679>/Saturation' */

          /* Product: '<S679>/Divide' incorporates:
           *  Constant: '<S596>/L1'
           *  Constant: '<S679>/Constant'
           *  Gain: '<S679>/Gain'
           *  Math: '<S679>/Square'
           *  MinMax: '<S679>/Max'
           *  MinMax: '<S679>/Min'
           *  Product: '<S679>/Multiply1'
           *  Sqrt: '<S715>/Sqrt'
           *  Trigonometry: '<S679>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Divide_pr_idx_2) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_e), 0.5F));

          /* Sum: '<S671>/Subtract' incorporates:
           *  Product: '<S671>/Multiply'
           *  Product: '<S671>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S660>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S660>/Sign1' */

          /* Switch: '<S660>/Switch2' incorporates:
           *  Constant: '<S660>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S660>/Switch2' */

          /* DotProduct: '<S660>/Dot Product' */
          rtb_Saturation_e = FMS_ConstB.Divide_m[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S660>/Acos' incorporates:
           *  DotProduct: '<S660>/Dot Product'
           */
          if (rtb_Saturation_e > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            if (rtb_Saturation_e < -1.0F) {
              rtb_Saturation_e = -1.0F;
            }
          }

          /* Product: '<S660>/Multiply' incorporates:
           *  Trigonometry: '<S660>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_Saturation_e);

          /* Math: '<S663>/Rem' incorporates:
           *  Constant: '<S663>/Constant1'
           *  Delay: '<S659>/Delay'
           *  Sum: '<S659>/Sum2'
           */
          rtb_Divide_pr_idx_2 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_nx, 6.28318548F);

          /* Switch: '<S663>/Switch' incorporates:
           *  Abs: '<S663>/Abs'
           *  Constant: '<S663>/Constant'
           *  Constant: '<S669>/Constant'
           *  Product: '<S663>/Multiply'
           *  RelationalOperator: '<S669>/Compare'
           *  Sum: '<S663>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S663>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S663>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S663>/Switch' */

          /* Sum: '<S659>/Sum' incorporates:
           *  Delay: '<S659>/Delay'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S668>/Multiply1' incorporates:
           *  Constant: '<S668>/const1'
           *  DiscreteIntegrator: '<S662>/Integrator'
           */
          rtb_Divide_pr_idx_2 = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S668>/Add' incorporates:
           *  DiscreteIntegrator: '<S662>/Integrator1'
           *  Sum: '<S662>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_b -
            rtb_Divide_pr_idx_1) + rtb_Divide_pr_idx_2;

          /* Signum: '<S668>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S668>/Sign' */

          /* Sum: '<S668>/Add2' incorporates:
           *  Abs: '<S668>/Abs'
           *  Gain: '<S668>/Gain'
           *  Gain: '<S668>/Gain1'
           *  Product: '<S668>/Multiply2'
           *  Product: '<S668>/Multiply3'
           *  Sqrt: '<S668>/Sqrt'
           *  Sum: '<S668>/Add1'
           *  Sum: '<S668>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_n) * FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2;

          /* Sum: '<S668>/Add4' */
          rtb_Divide_pr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S668>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_n;

          /* Sum: '<S668>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_n;

          /* Signum: '<S668>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S668>/Sign1' */

          /* Signum: '<S668>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S668>/Sign2' */

          /* Sum: '<S668>/Add5' incorporates:
           *  Gain: '<S668>/Gain2'
           *  Product: '<S668>/Multiply4'
           *  Sum: '<S668>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_pr_idx_2;

          /* Sum: '<S668>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_n;

          /* Sum: '<S668>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e - FMS_ConstB.d_n;

          /* Product: '<S668>/Divide' */
          d = rtb_Saturation_e / FMS_ConstB.d_n;

          /* Signum: '<S668>/Sign5' incorporates:
           *  Signum: '<S668>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S668>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S668>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Add4_o = rtb_Saturation_e;

            /* Signum: '<S668>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S668>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S659>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S664>/Rem' incorporates:
           *  Constant: '<S664>/Constant1'
           */
          rtb_Saturation_e = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S664>/Switch' incorporates:
           *  Abs: '<S664>/Abs'
           *  Constant: '<S664>/Constant'
           *  Constant: '<S670>/Constant'
           *  Product: '<S664>/Multiply'
           *  RelationalOperator: '<S670>/Compare'
           *  Sum: '<S664>/Add'
           */
          if (fabsf(rtb_Saturation_e) > 3.14159274F) {
            /* Signum: '<S664>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_e;
            }

            /* End of Signum: '<S664>/Sign' */
            rtb_Saturation_e -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S664>/Switch' */

          /* Abs: '<S657>/Abs' */
          rtb_Saturation_e = fabsf(rtb_Saturation_e);

          /* Update for Delay: '<S680>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S681>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S674>/Constant'
           *  RelationalOperator: '<S674>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S681>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S676>/Acceleration_Speed' incorporates:
           *  Constant: '<S676>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S676>/Acceleration_Speed' */

          /* Product: '<S680>/Divide1' incorporates:
           *  Constant: '<S680>/Constant'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S680>/Saturation' */
          if (rtb_Saturation_e > 0.314159274F) {
            rtb_Saturation_e = 0.314159274F;
          } else {
            if (rtb_Saturation_e < -0.314159274F) {
              rtb_Saturation_e = -0.314159274F;
            }
          }

          /* End of Saturate: '<S680>/Saturation' */

          /* Update for DiscreteIntegrator: '<S722>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_Saturation_e;

          /* Update for Delay: '<S659>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S662>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S662>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_on = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Signum: '<S668>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S668>/Sign3' */

          /* Signum: '<S668>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S668>/Sign4' */

          /* Update for DiscreteIntegrator: '<S662>/Integrator' incorporates:
           *  Constant: '<S668>/const'
           *  Gain: '<S668>/Gain3'
           *  Product: '<S668>/Multiply5'
           *  Product: '<S668>/Multiply6'
           *  Sum: '<S668>/Subtract4'
           *  Sum: '<S668>/Subtract5'
           *  Sum: '<S668>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S662>/Integrator' */
          /* End of Outputs for SubSystem: '<S295>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S295>/Hold' incorporates:
             *  ActionPort: '<S594>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Delay: '<S615>/Delay'
             *  DiscreteIntegrator: '<S627>/Integrator'
             *  DiscreteIntegrator: '<S627>/Integrator1'
             */
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S295>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S295>/Hold' incorporates:
             *  ActionPort: '<S594>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S295>/Switch Case' incorporates:
             *  Chart: '<S603>/Motion Status'
             *  Chart: '<S614>/Motion State'
             *  Chart: '<S635>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_il = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S295>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S295>/Hold' incorporates:
           *  ActionPort: '<S594>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S603>/Motion Status' incorporates:
           *  Abs: '<S603>/Abs'
           *  Constant: '<S603>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S614>/Motion State' incorporates:
           *  Abs: '<S614>/Abs'
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

          /* End of Chart: '<S614>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S635>/Motion State' incorporates:
           *  Constant: '<S635>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S635>/Square'
           *  Math: '<S635>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S635>/Sqrt'
           *  Sum: '<S635>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                          &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S634>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S634>/Hold Control' incorporates:
               *  ActionPort: '<S637>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S634>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S634>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S634>/Hold Control' incorporates:
             *  ActionPort: '<S637>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S634>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S634>/Brake Control' incorporates:
             *  ActionPort: '<S636>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S634>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S634>/Move Control' incorporates:
               *  ActionPort: '<S638>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S634>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S634>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S634>/Move Control' incorporates:
             *  ActionPort: '<S638>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S634>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S634>/Switch Case' */

          /* SwitchCase: '<S602>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S602>/Hold Control' incorporates:
               *  ActionPort: '<S605>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S602>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S602>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S602>/Hold Control' incorporates:
             *  ActionPort: '<S605>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S602>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S602>/Brake Control' incorporates:
             *  ActionPort: '<S604>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S602>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S602>/Move Control' incorporates:
               *  ActionPort: '<S606>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S602>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S602>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S602>/Move Control' incorporates:
             *  ActionPort: '<S606>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S602>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S602>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S612>/Compare' incorporates:
           *  Constant: '<S612>/Constant'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S615>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S627>/Integrator1' incorporates:
           *  Delay: '<S615>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Integrator1_PrevResetState != 0)) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          /* SwitchCase: '<S613>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S613>/Hold Control' incorporates:
               *  ActionPort: '<S617>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S613>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S613>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S613>/Hold Control' incorporates:
             *  ActionPort: '<S617>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S613>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S613>/Brake Control' incorporates:
             *  ActionPort: '<S616>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S613>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S613>/Move Control' incorporates:
               *  ActionPort: '<S618>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S613>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S613>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S613>/Move Control' incorporates:
             *  ActionPort: '<S618>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S613>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S613>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S600>/Switch' incorporates:
           *  Saturate: '<S613>/Saturation'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_yaw >= 0.0F) {
            /* Math: '<S630>/Rem' incorporates:
             *  Constant: '<S630>/Constant1'
             *  DiscreteIntegrator: '<S627>/Integrator1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S626>/Sum'
             */
            rtb_Divide_pr_idx_1 = rt_remf(FMS_DW.Integrator1_DSTATE_jz -
              FMS_U.INS_Out.psi, 6.28318548F);

            /* Switch: '<S630>/Switch' incorporates:
             *  Abs: '<S630>/Abs'
             *  Constant: '<S630>/Constant'
             *  Constant: '<S631>/Constant'
             *  Product: '<S630>/Multiply'
             *  RelationalOperator: '<S631>/Compare'
             *  Sum: '<S630>/Add'
             */
            if (fabsf(rtb_Divide_pr_idx_1) > 3.14159274F) {
              /* Signum: '<S630>/Sign' */
              if (rtb_Divide_pr_idx_1 < 0.0F) {
                rtb_Divide_lr_idx_2 = -1.0F;
              } else if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              } else {
                rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1;
              }

              /* End of Signum: '<S630>/Sign' */
              rtb_Divide_pr_idx_1 -= 6.28318548F * rtb_Divide_lr_idx_2;
            }

            /* End of Switch: '<S630>/Switch' */

            /* Gain: '<S626>/Gain2' */
            rtb_Divide_pr_idx_1 *= FMS_PARAM.YAW_P;

            /* Saturate: '<S626>/Saturation' */
            if (rtb_Divide_pr_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
            } else {
              if (rtb_Divide_pr_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
                rtb_Divide_pr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
              }
            }

            /* End of Saturate: '<S626>/Saturation' */
          } else if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S613>/Saturation' */
            rtb_Divide_pr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S613>/Saturation' */
            rtb_Divide_pr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* Saturate: '<S613>/Saturation' */
            rtb_Divide_pr_idx_1 = FMS_B.Merge_h;
          }

          /* End of Switch: '<S600>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S594>/Bus Assignment' incorporates:
           *  Constant: '<S594>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_1;

          /* Saturate: '<S634>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S594>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S594>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S594>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S594>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S594>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S594>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S634>/Saturation1' */

          /* Saturate: '<S602>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S594>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S594>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S594>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S602>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S628>/Rem' incorporates:
           *  Constant: '<S628>/Constant1'
           *  Delay: '<S615>/Delay'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S615>/Sum2'
           */
          rtb_Divide_pr_idx_1 = rt_remf(FMS_B.Cmd_In.set_yaw -
            FMS_DW.Delay_DSTATE_h, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S628>/Switch' incorporates:
           *  Abs: '<S628>/Abs'
           *  Constant: '<S628>/Constant'
           *  Constant: '<S633>/Constant'
           *  Product: '<S628>/Multiply'
           *  RelationalOperator: '<S633>/Compare'
           *  Sum: '<S628>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_1) > 3.14159274F) {
            /* Signum: '<S628>/Sign' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            } else {
              rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1;
            }

            /* End of Signum: '<S628>/Sign' */
            rtb_Divide_pr_idx_1 -= 6.28318548F * rtb_Divide_lr_idx_2;
          }

          /* End of Switch: '<S628>/Switch' */

          /* Sum: '<S615>/Sum' incorporates:
           *  Delay: '<S615>/Delay'
           */
          rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1 + FMS_DW.Delay_DSTATE_h;

          /* DiscreteIntegrator: '<S627>/Integrator' */
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

          /* Product: '<S632>/Multiply1' incorporates:
           *  Constant: '<S632>/const1'
           *  DiscreteIntegrator: '<S627>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S632>/Add' incorporates:
           *  DiscreteIntegrator: '<S627>/Integrator1'
           *  Sum: '<S627>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_jz - rtb_Divide_lr_idx_2)
            + rtb_Divide_pr_idx_1;

          /* Signum: '<S632>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S632>/Sign' */

          /* Sum: '<S632>/Add2' incorporates:
           *  Abs: '<S632>/Abs'
           *  Gain: '<S632>/Gain'
           *  Gain: '<S632>/Gain1'
           *  Product: '<S632>/Multiply2'
           *  Product: '<S632>/Multiply3'
           *  Sqrt: '<S632>/Sqrt'
           *  Sum: '<S632>/Add1'
           *  Sum: '<S632>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_k) * FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

          /* Sum: '<S632>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_pr_idx_1;

          /* Sum: '<S632>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_k;

          /* Sum: '<S632>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_k;

          /* Signum: '<S632>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S632>/Sign1' */

          /* Signum: '<S632>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S632>/Sign2' */

          /* Sum: '<S632>/Add5' incorporates:
           *  Gain: '<S632>/Gain2'
           *  Product: '<S632>/Multiply4'
           *  Sum: '<S632>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Update for Delay: '<S615>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S627>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S627>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Sum: '<S632>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_k;

          /* Sum: '<S632>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_k;

          /* Signum: '<S632>/Sign5' incorporates:
           *  Signum: '<S632>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S632>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S632>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S632>/Sign6' */
            rtb_Add4_o = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S632>/Sign5' */

          /* Signum: '<S632>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S632>/Sign3' */

          /* Signum: '<S632>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S632>/Sign4' */

          /* Update for DiscreteIntegrator: '<S627>/Integrator' incorporates:
           *  Constant: '<S632>/const'
           *  Gain: '<S632>/Gain3'
           *  Product: '<S632>/Divide'
           *  Product: '<S632>/Multiply5'
           *  Product: '<S632>/Multiply6'
           *  Sum: '<S632>/Subtract4'
           *  Sum: '<S632>/Subtract5'
           *  Sum: '<S632>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S627>/Integrator' */
          /* End of Outputs for SubSystem: '<S295>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S295>/Unknown' incorporates:
           *  ActionPort: '<S598>/Action Port'
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
         *  Math: '<S477>/Math Function'
         *  Sum: '<S433>/Subtract'
         *  Sum: '<S490>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S404>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S455>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S445>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S404>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S293>/Offboard' incorporates:
           *  ActionPort: '<S405>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S571>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S574>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S575>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S575>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S575>/Multiply1' incorporates:
           *  Product: '<S575>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S575>/Divide' incorporates:
           *  Constant: '<S575>/Constant'
           *  Constant: '<S575>/R'
           *  Sqrt: '<S575>/Sqrt'
           *  Sum: '<S575>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S575>/Product3' incorporates:
           *  Constant: '<S575>/Constant1'
           *  Product: '<S575>/Multiply1'
           *  Sum: '<S575>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S575>/Multiply2' incorporates:
           *  Trigonometry: '<S575>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S574>/Sum' incorporates:
           *  Gain: '<S571>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S579>/Abs' incorporates:
           *  Abs: '<S582>/Abs1'
           *  Switch: '<S579>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S579>/Switch1' incorporates:
           *  Abs: '<S579>/Abs'
           *  Bias: '<S579>/Bias2'
           *  Bias: '<S579>/Bias3'
           *  Constant: '<S576>/Constant'
           *  Constant: '<S576>/Constant1'
           *  Constant: '<S581>/Constant'
           *  Gain: '<S579>/Gain1'
           *  Product: '<S579>/Multiply'
           *  RelationalOperator: '<S581>/Compare'
           *  Switch: '<S576>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S582>/Switch1' incorporates:
             *  Bias: '<S582>/Bias2'
             *  Bias: '<S582>/Bias3'
             *  Constant: '<S582>/Constant'
             *  Constant: '<S583>/Constant'
             *  Math: '<S582>/Math Function'
             *  RelationalOperator: '<S583>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S582>/Switch1' */

            /* Signum: '<S579>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S579>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S576>/Sum' incorporates:
           *  Gain: '<S571>/Gain1'
           *  Gain: '<S571>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S574>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S574>/Multiply' incorporates:
           *  Gain: '<S574>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S578>/Switch1' incorporates:
           *  Abs: '<S578>/Abs1'
           *  Bias: '<S578>/Bias2'
           *  Bias: '<S578>/Bias3'
           *  Constant: '<S578>/Constant'
           *  Constant: '<S580>/Constant'
           *  Math: '<S578>/Math Function'
           *  RelationalOperator: '<S580>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S578>/Switch1' */

          /* Product: '<S574>/Multiply' incorporates:
           *  Gain: '<S574>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S552>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S556>/Multiply1'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S565>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S565>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S565>/Trigonometric Function3' incorporates:
             *  Gain: '<S564>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S565>/Gain' incorporates:
             *  Gain: '<S564>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S565>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S565>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S565>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S565>/Trigonometric Function' incorporates:
             *  Gain: '<S564>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S565>/Trigonometric Function1' incorporates:
             *  Gain: '<S564>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S565>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S558>/Switch' incorporates:
             *  Constant: '<S573>/Constant'
             *  DataTypeConversion: '<S571>/Data Type Conversion1'
             *  Product: '<S577>/Multiply1'
             *  Product: '<S577>/Multiply2'
             *  RelationalOperator: '<S573>/Compare'
             *  S-Function (sfix_bitop): '<S570>/lat_cmd valid'
             *  Sum: '<S577>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_Saturation_e = (real32_T)(rtb_Multiply_g_idx_0 *
                FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S556>/Multiply' incorporates:
             *  Constant: '<S562>/Constant'
             *  Constant: '<S563>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S555>/Logical Operator'
             *  RelationalOperator: '<S562>/Compare'
             *  RelationalOperator: '<S563>/Compare'
             *  S-Function (sfix_bitop): '<S555>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S555>/x_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S556>/Sum1'
             */
            rtb_Divide_pr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_e -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S565>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S558>/Switch' incorporates:
             *  Constant: '<S573>/Constant'
             *  DataTypeConversion: '<S571>/Data Type Conversion1'
             *  Product: '<S577>/Multiply3'
             *  Product: '<S577>/Multiply4'
             *  RelationalOperator: '<S573>/Compare'
             *  S-Function (sfix_bitop): '<S570>/lon_cmd valid'
             *  Sum: '<S577>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_Saturation_e = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S556>/Multiply' incorporates:
             *  Constant: '<S562>/Constant'
             *  Constant: '<S563>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S555>/Logical Operator'
             *  RelationalOperator: '<S562>/Compare'
             *  RelationalOperator: '<S563>/Compare'
             *  S-Function (sfix_bitop): '<S555>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S555>/y_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S556>/Sum1'
             */
            rtb_Divide_lr_idx_2 = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_e -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S565>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S558>/Switch' incorporates:
             *  Constant: '<S573>/Constant'
             *  DataTypeConversion: '<S571>/Data Type Conversion'
             *  DataTypeConversion: '<S571>/Data Type Conversion1'
             *  Gain: '<S571>/Gain2'
             *  Gain: '<S574>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S573>/Compare'
             *  S-Function (sfix_bitop): '<S570>/alt_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S574>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_Saturation_e = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                -FMS_U.INS_Out.alt_0);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S556>/Multiply' incorporates:
             *  Constant: '<S562>/Constant'
             *  Constant: '<S563>/Constant'
             *  Gain: '<S559>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S555>/Logical Operator'
             *  RelationalOperator: '<S562>/Compare'
             *  RelationalOperator: '<S563>/Compare'
             *  S-Function (sfix_bitop): '<S555>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S555>/z_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S556>/Sum1'
             */
            rtb_Divide_pr_idx_0 = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) ? rtb_Saturation_e -
              (-FMS_U.INS_Out.h_R) : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1);
            }

            /* SignalConversion: '<S498>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S498>/Constant4'
             *  MultiPortSwitch: '<S487>/Index Vector'
             *  Product: '<S556>/Multiply1'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S498>/Trigonometric Function3' incorporates:
             *  Gain: '<S497>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S487>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S498>/Gain' incorporates:
             *  Gain: '<S497>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S487>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S498>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S498>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S498>/Constant3'
             *  MultiPortSwitch: '<S487>/Index Vector'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S498>/Trigonometric Function' incorporates:
             *  Gain: '<S497>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S487>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S498>/Trigonometric Function1' incorporates:
             *  Gain: '<S497>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S487>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S498>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S487>/Index Vector'
             */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S487>/Multiply' incorporates:
             *  Constant: '<S496>/Constant'
             *  RelationalOperator: '<S496>/Compare'
             *  S-Function (sfix_bitop): '<S493>/ax_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S498>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S487>/Index Vector'
             */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S487>/Multiply' incorporates:
             *  Constant: '<S496>/Constant'
             *  RelationalOperator: '<S496>/Compare'
             *  S-Function (sfix_bitop): '<S493>/ay_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S498>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S487>/Index Vector'
             */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S487>/Multiply' incorporates:
             *  Constant: '<S496>/Constant'
             *  RelationalOperator: '<S496>/Compare'
             *  S-Function (sfix_bitop): '<S493>/az_cmd valid'
             */
            rtb_Divide_pr_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S487>/Index Vector' incorporates:
             *  Product: '<S494>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ee[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1);
            }
            break;

           case 1:
            /* SignalConversion: '<S568>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S568>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S568>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S557>/Data Store Read'
             *  Gain: '<S566>/Gain'
             *  Trigonometry: '<S568>/Trigonometric Function1'
             */
            rtb_Add4_o = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate_h[4] = rtb_Add4_o;

            /* Trigonometry: '<S568>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S557>/Data Store Read'
             *  Gain: '<S566>/Gain'
             *  Trigonometry: '<S568>/Trigonometric Function'
             */
            rtb_Divide_or = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S568>/Gain' incorporates:
             *  Trigonometry: '<S568>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -rtb_Divide_or;

            /* SignalConversion: '<S568>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S568>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S568>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = rtb_Divide_or;

            /* Trigonometry: '<S568>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = rtb_Add4_o;

            /* SignalConversion: '<S569>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S569>/Constant4'
             */
            rtb_MatrixConcatenate1_i[5] = 0.0F;

            /* Gain: '<S567>/Gain' incorporates:
             *  DataStoreRead: '<S557>/Data Store Read'
             *  Gain: '<S499>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S487>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S557>/Subtract'
             */
            rtb_Divide_pr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S569>/Trigonometric Function3' incorporates:
             *  Gain: '<S567>/Gain'
             *  Trigonometry: '<S569>/Trigonometric Function1'
             */
            rtb_Add4_o = arm_cos_f32(rtb_Divide_pr_idx_2);
            rtb_MatrixConcatenate1_i[4] = rtb_Add4_o;

            /* Trigonometry: '<S569>/Trigonometric Function2' incorporates:
             *  Gain: '<S567>/Gain'
             *  Trigonometry: '<S569>/Trigonometric Function'
             */
            rtb_Divide_or = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S569>/Gain' incorporates:
             *  Trigonometry: '<S569>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1_i[3] = -rtb_Divide_or;

            /* SignalConversion: '<S569>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S569>/Constant3'
             */
            rtb_MatrixConcatenate1_i[2] = 0.0F;

            /* Trigonometry: '<S569>/Trigonometric Function' */
            rtb_MatrixConcatenate1_i[1] = rtb_Divide_or;

            /* Trigonometry: '<S569>/Trigonometric Function1' */
            rtb_MatrixConcatenate1_i[0] = rtb_Add4_o;

            /* RelationalOperator: '<S573>/Compare' incorporates:
             *  Constant: '<S573>/Constant'
             *  S-Function (sfix_bitop): '<S570>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S570>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S570>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S571>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S571>/Data Type Conversion'
             *  Gain: '<S571>/Gain2'
             *  Gain: '<S574>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S577>/Multiply1'
             *  Product: '<S577>/Multiply2'
             *  Product: '<S577>/Multiply3'
             *  Product: '<S577>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S574>/Sum1'
             *  Sum: '<S577>/Sum2'
             *  Sum: '<S577>/Sum3'
             */
            rtb_Switch_c2[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S558>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S568>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S569>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S557>/Sum' incorporates:
             *  DataStoreRead: '<S557>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S568>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S569>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S557>/Sum' incorporates:
             *  DataStoreRead: '<S557>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S568>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S569>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S557>/Sum' incorporates:
             *  DataStoreRead: '<S557>/Data Store Read'
             *  Gain: '<S559>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S562>/Compare' incorporates:
             *  Constant: '<S562>/Constant'
             *  S-Function (sfix_bitop): '<S555>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S555>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S555>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S563>/Compare' incorporates:
             *  Constant: '<S563>/Constant'
             *  S-Function (sfix_bitop): '<S555>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S555>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S555>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S557>/Sum2' incorporates:
               *  Product: '<S557>/Multiply2'
               *  Switch: '<S558>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_Saturation_e = rtb_Switch_c2[rtb_n];
              } else {
                rtb_Saturation_e = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              /* Product: '<S557>/Multiply' incorporates:
               *  Logic: '<S555>/Logical Operator'
               *  Product: '<S557>/Multiply2'
               *  Sum: '<S557>/Sum'
               *  Sum: '<S557>/Sum2'
               */
              rtb_Switch_ee[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ?
                rtb_Saturation_e - ((rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1) + rtb_VectorConcatenate_h[rtb_n + 6] *
                                    rtb_Divide_pr_idx_0) : 0.0F;
            }

            /* SignalConversion: '<S500>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S500>/Constant4'
             *  MultiPortSwitch: '<S487>/Index Vector'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S500>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S487>/Index Vector'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S500>/Gain' incorporates:
             *  MultiPortSwitch: '<S487>/Index Vector'
             *  Trigonometry: '<S500>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(rtb_Divide_pr_idx_2);

            /* SignalConversion: '<S500>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S500>/Constant3'
             *  MultiPortSwitch: '<S487>/Index Vector'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S500>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S487>/Index Vector'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Trigonometry: '<S500>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S487>/Index Vector'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(rtb_Divide_pr_idx_2);

            /* Product: '<S487>/Multiply' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S496>/Compare' incorporates:
             *  Constant: '<S496>/Constant'
             *  S-Function (sfix_bitop): '<S493>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S493>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S493>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S500>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S487>/Index Vector'
               */
              rtb_VectorConcatenate_h[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S487>/Multiply' */
              rtb_Switch_c2[rtb_n] = tmp[rtb_n] ?
                rtb_MatrixConcatenate1_i_0[rtb_n] : 0.0F;
              rtb_Switch_an[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n + 6] *
                rtb_Switch_ee[2] + (rtb_MatrixConcatenate1_i[rtb_n + 3] *
                                    rtb_Switch_ee[1] +
                                    rtb_MatrixConcatenate1_i[rtb_n] *
                                    rtb_Switch_ee[0]);
            }

            /* MultiPortSwitch: '<S487>/Index Vector' incorporates:
             *  Product: '<S495>/Multiply3'
             *  Product: '<S557>/Multiply3'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ee[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 6] *
                rtb_Switch_c2[2] + (rtb_VectorConcatenate_h[rtb_n + 3] *
                                    rtb_Switch_c2[1] +
                                    rtb_VectorConcatenate_h[rtb_n] *
                                    rtb_Switch_c2[0]);
            }
            break;

           default:
            /* SignalConversion: '<S561>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S561>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S561>/Trigonometric Function3' incorporates:
             *  Gain: '<S560>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S561>/Gain' incorporates:
             *  Gain: '<S560>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S561>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S561>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S561>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S561>/Trigonometric Function' incorporates:
             *  Gain: '<S560>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S561>/Trigonometric Function1' incorporates:
             *  Gain: '<S560>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* S-Function (sfix_bitop): '<S570>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S555>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S573>/Compare' incorporates:
             *  Constant: '<S573>/Constant'
             *  S-Function (sfix_bitop): '<S570>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S570>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S555>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S573>/Compare' incorporates:
             *  Constant: '<S573>/Constant'
             *  S-Function (sfix_bitop): '<S570>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S570>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S555>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S573>/Compare' incorporates:
             *  Constant: '<S573>/Constant'
             *  S-Function (sfix_bitop): '<S570>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S571>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S571>/Data Type Conversion'
             *  Gain: '<S571>/Gain2'
             *  Gain: '<S574>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S577>/Multiply1'
             *  Product: '<S577>/Multiply2'
             *  Product: '<S577>/Multiply3'
             *  Product: '<S577>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S574>/Sum1'
             *  Sum: '<S577>/Sum2'
             *  Sum: '<S577>/Sum3'
             */
            rtb_Switch_c2[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S558>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S561>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_g[0];

            /* Sum: '<S554>/Sum' incorporates:
             *  DataStoreRead: '<S554>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S561>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_g[1];

            /* Sum: '<S554>/Sum' incorporates:
             *  DataStoreRead: '<S554>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S561>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Sum: '<S554>/Sum' incorporates:
             *  DataStoreRead: '<S554>/Data Store Read'
             *  Gain: '<S559>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S562>/Compare' incorporates:
             *  Constant: '<S562>/Constant'
             *  S-Function (sfix_bitop): '<S555>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S555>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S555>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S563>/Compare' incorporates:
             *  Constant: '<S563>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S554>/Sum2' incorporates:
             *  Logic: '<S555>/Logical Operator'
             *  Product: '<S554>/Multiply'
             *  Product: '<S554>/Multiply2'
             *  Sum: '<S554>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S558>/Switch' incorporates:
               *  Product: '<S554>/Multiply2'
               */
              if (tmp[rtb_n]) {
                rtb_Saturation_e = rtb_Switch_c2[rtb_n];
              } else {
                rtb_Saturation_e = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              rtb_Switch_an[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ?
                rtb_Saturation_e - ((rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1) + rtb_VectorConcatenate_h[rtb_n + 6] *
                                    rtb_Divide_pr_idx_0) : 0.0F;
            }

            /* End of Sum: '<S554>/Sum2' */

            /* MultiPortSwitch: '<S487>/Index Vector' incorporates:
             *  Constant: '<S496>/Constant'
             *  Product: '<S487>/Multiply'
             *  RelationalOperator: '<S496>/Compare'
             *  S-Function (sfix_bitop): '<S493>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S493>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S493>/az_cmd valid'
             */
            rtb_Switch_ee[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ee[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ee[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S552>/Index Vector' */

          /* Sum: '<S548>/Sum1' incorporates:
           *  Constant: '<S548>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S548>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S549>/Abs' */
          rtb_Divide_pr_idx_1 = fabsf(rtb_Divide_pr_idx_2);

          /* Switch: '<S549>/Switch' incorporates:
           *  Constant: '<S549>/Constant'
           *  Constant: '<S550>/Constant'
           *  Product: '<S549>/Multiply'
           *  RelationalOperator: '<S550>/Compare'
           *  Sum: '<S549>/Subtract'
           */
          if (rtb_Divide_pr_idx_1 > 3.14159274F) {
            /* Signum: '<S549>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_2 > 0.0F) {
                rtb_Divide_pr_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S549>/Sign' */
            rtb_Divide_pr_idx_2 *= rtb_Divide_pr_idx_1 - 6.28318548F;
          }

          /* End of Switch: '<S549>/Switch' */

          /* Saturate: '<S548>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 0.314159274F) {
            rtb_Divide_pr_idx_2 = 0.314159274F;
          } else {
            if (rtb_Divide_pr_idx_2 < -0.314159274F) {
              rtb_Divide_pr_idx_2 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S548>/Saturation' */

          /* Gain: '<S545>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S489>/Sum' incorporates:
           *  Constant: '<S547>/Constant'
           *  Constant: '<S551>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S545>/Multiply2'
           *  Product: '<S546>/Multiply1'
           *  RelationalOperator: '<S547>/Compare'
           *  RelationalOperator: '<S551>/Compare'
           *  S-Function (sfix_bitop): '<S545>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S546>/psi_rate_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          rtb_Saturation_e = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                              rtb_Divide_pr_idx_2 : 0.0F) +
            ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S552>/Gain1' */
          rtb_Square_bg[0] = FMS_PARAM.XY_P * rtb_Switch_an[0];
          rtb_Square_bg[1] = FMS_PARAM.XY_P * rtb_Switch_an[1];

          /* Gain: '<S552>/Gain2' */
          rtb_Divide_pr_idx_2 = FMS_PARAM.Z_P * rtb_Switch_an[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S553>/Index Vector' incorporates:
           *  Constant: '<S589>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S553>/Multiply'
           *  Product: '<S586>/Multiply'
           *  Product: '<S587>/Multiply3'
           *  RelationalOperator: '<S589>/Compare'
           *  S-Function (sfix_bitop): '<S585>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S585>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S585>/w_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S591>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S591>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S591>/Trigonometric Function3' incorporates:
             *  Gain: '<S590>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S591>/Gain' incorporates:
             *  Gain: '<S590>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S591>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S591>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S591>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S591>/Trigonometric Function' incorporates:
             *  Gain: '<S590>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S591>/Trigonometric Function1' incorporates:
             *  Gain: '<S590>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S591>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S553>/Multiply' incorporates:
             *  Constant: '<S589>/Constant'
             *  RelationalOperator: '<S589>/Compare'
             *  S-Function (sfix_bitop): '<S585>/u_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S591>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S553>/Multiply' incorporates:
             *  Constant: '<S589>/Constant'
             *  RelationalOperator: '<S589>/Compare'
             *  S-Function (sfix_bitop): '<S585>/v_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S591>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S553>/Multiply' incorporates:
             *  Constant: '<S589>/Constant'
             *  RelationalOperator: '<S589>/Compare'
             *  S-Function (sfix_bitop): '<S585>/w_cmd valid'
             */
            rtb_Divide_pr_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1);
            }
            break;

           case 1:
            /* SignalConversion: '<S593>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S593>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Gain: '<S592>/Gain' incorporates:
             *  DataStoreRead: '<S587>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S587>/Subtract'
             */
            rtb_Divide_pr_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S593>/Trigonometric Function3' incorporates:
             *  Gain: '<S592>/Gain'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(rtb_Divide_pr_idx_1);

            /* Gain: '<S593>/Gain' incorporates:
             *  Gain: '<S592>/Gain'
             *  Trigonometry: '<S593>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(rtb_Divide_pr_idx_1);

            /* SignalConversion: '<S593>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S593>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S593>/Trigonometric Function' incorporates:
             *  Gain: '<S592>/Gain'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(rtb_Divide_pr_idx_1);

            /* Trigonometry: '<S593>/Trigonometric Function1' incorporates:
             *  Gain: '<S592>/Gain'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(rtb_Divide_pr_idx_1);

            /* SignalConversion: '<S593>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Product: '<S553>/Multiply' incorporates:
             *  Constant: '<S589>/Constant'
             *  RelationalOperator: '<S589>/Compare'
             *  S-Function (sfix_bitop): '<S585>/u_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S593>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Product: '<S553>/Multiply' incorporates:
             *  Constant: '<S589>/Constant'
             *  RelationalOperator: '<S589>/Compare'
             *  S-Function (sfix_bitop): '<S585>/v_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S593>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Product: '<S553>/Multiply' incorporates:
             *  Constant: '<S589>/Constant'
             *  RelationalOperator: '<S589>/Compare'
             *  S-Function (sfix_bitop): '<S585>/w_cmd valid'
             */
            rtb_Divide_pr_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 32768U) > 0U ?
              FMS_U.Auto_Cmd.w_cmd : 0.0F;
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_an[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
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

          /* End of MultiPortSwitch: '<S553>/Index Vector' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Switch_an[0] += rtb_Square_bg[0];
          rtb_Switch_an[1] += rtb_Square_bg[1];

          /* Sum: '<S490>/Sum1' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + rtb_Switch_an[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S508>/Switch' incorporates:
           *  Constant: '<S523>/Constant'
           *  Constant: '<S525>/Constant'
           *  Constant: '<S526>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S523>/Compare'
           *  RelationalOperator: '<S525>/Compare'
           *  RelationalOperator: '<S526>/Compare'
           *  S-Function (sfix_bitop): '<S508>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S508>/y_v_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S508>/Logical Operator' incorporates:
             *  Constant: '<S524>/Constant'
             *  Constant: '<S525>/Constant'
             *  Constant: '<S526>/Constant'
             *  RelationalOperator: '<S524>/Compare'
             *  RelationalOperator: '<S525>/Compare'
             *  RelationalOperator: '<S526>/Compare'
             *  S-Function (sfix_bitop): '<S508>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S508>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S508>/y_v_cmd'
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

          /* End of Switch: '<S508>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S488>/u_cmd_valid' */
          /* MATLAB Function: '<S520>/bit_shift' incorporates:
           *  DataTypeConversion: '<S488>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_Compare_kd << 6);

          /* End of Outputs for SubSystem: '<S488>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S488>/v_cmd_valid' */
          /* MATLAB Function: '<S521>/bit_shift' incorporates:
           *  DataTypeConversion: '<S488>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

          /* End of Outputs for SubSystem: '<S488>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S509>/Switch' incorporates:
           *  Constant: '<S528>/Constant'
           *  Constant: '<S529>/Constant'
           *  Constant: '<S531>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S528>/Compare'
           *  RelationalOperator: '<S529>/Compare'
           *  RelationalOperator: '<S531>/Compare'
           *  S-Function (sfix_bitop): '<S509>/ax_cmd'
           *  S-Function (sfix_bitop): '<S509>/ay_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S509>/Logical Operator' incorporates:
             *  Constant: '<S529>/Constant'
             *  Constant: '<S531>/Constant'
             *  RelationalOperator: '<S529>/Compare'
             *  RelationalOperator: '<S531>/Compare'
             *  S-Function (sfix_bitop): '<S509>/ax_cmd'
             *  S-Function (sfix_bitop): '<S509>/ay_cmd'
             */
            rtb_Compare_kd = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_Compare_kd;
          } else {
            rtb_Compare_kd = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S509>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S405>/Bus Assignment' incorporates:
           *  Constant: '<S405>/Constant'
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

          /* Saturate: '<S489>/Saturation' */
          if (rtb_Saturation_e > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S489>/Saturation' */

          /* Saturate: '<S490>/Saturation2' */
          if (rtb_Switch_an[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_an[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_an[0];
          }

          /* End of Saturate: '<S490>/Saturation2' */

          /* Saturate: '<S490>/Saturation1' */
          if (rtb_Switch_an[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_an[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_an[1];
          }

          /* End of Saturate: '<S490>/Saturation1' */

          /* Saturate: '<S490>/Saturation3' */
          if (rtb_Divide_pr_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_pr_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S405>/Bus Assignment' */
            FMS_Y.FMS_Out.w_cmd = rtb_Divide_pr_idx_1;
          }

          /* End of Saturate: '<S490>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S488>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S488>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S488>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S488>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S488>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S488>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S488>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S488>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S488>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S488>/throttle_cmd_valid' */
          /* BusAssignment: '<S405>/Bus Assignment' incorporates:
           *  Constant: '<S501>/Constant'
           *  Constant: '<S502>/Constant'
           *  Constant: '<S503>/Constant'
           *  Constant: '<S504>/Constant'
           *  Constant: '<S505>/Constant'
           *  Constant: '<S506>/Constant'
           *  Constant: '<S507>/Constant'
           *  Constant: '<S527>/Constant'
           *  Constant: '<S530>/Constant'
           *  DataTypeConversion: '<S488>/Data Type Conversion10'
           *  DataTypeConversion: '<S488>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S510>/bit_shift'
           *  MATLAB Function: '<S511>/bit_shift'
           *  MATLAB Function: '<S512>/bit_shift'
           *  MATLAB Function: '<S514>/bit_shift'
           *  MATLAB Function: '<S515>/bit_shift'
           *  MATLAB Function: '<S516>/bit_shift'
           *  MATLAB Function: '<S517>/bit_shift'
           *  MATLAB Function: '<S518>/bit_shift'
           *  MATLAB Function: '<S519>/bit_shift'
           *  MATLAB Function: '<S522>/bit_shift'
           *  RelationalOperator: '<S501>/Compare'
           *  RelationalOperator: '<S502>/Compare'
           *  RelationalOperator: '<S503>/Compare'
           *  RelationalOperator: '<S504>/Compare'
           *  RelationalOperator: '<S505>/Compare'
           *  RelationalOperator: '<S506>/Compare'
           *  RelationalOperator: '<S507>/Compare'
           *  RelationalOperator: '<S527>/Compare'
           *  RelationalOperator: '<S530>/Compare'
           *  S-Function (sfix_bitop): '<S488>/p_cmd'
           *  S-Function (sfix_bitop): '<S488>/phi_cmd'
           *  S-Function (sfix_bitop): '<S488>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S488>/q_cmd'
           *  S-Function (sfix_bitop): '<S488>/r_cmd'
           *  S-Function (sfix_bitop): '<S488>/theta_cmd'
           *  S-Function (sfix_bitop): '<S488>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S508>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S509>/az_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           *  Sum: '<S488>/Add'
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

          /* End of Outputs for SubSystem: '<S488>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S488>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S488>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S488>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S488>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S488>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S488>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S488>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S488>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S488>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S293>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S293>/Mission' incorporates:
             *  ActionPort: '<S404>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S293>/Switch Case' incorporates:
             *  UnitDelay: '<S407>/Delay Input1'
             *
             * Block description for '<S407>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S293>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S293>/Mission' incorporates:
             *  ActionPort: '<S404>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S404>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S293>/Switch Case' incorporates:
             *  Chart: '<S446>/Motion Status'
             *  Chart: '<S456>/Motion State'
             *  Delay: '<S412>/Delay'
             *  Delay: '<S434>/Delay'
             *  DiscreteIntegrator: '<S415>/Integrator'
             *  DiscreteIntegrator: '<S415>/Integrator1'
             *  DiscreteIntegrator: '<S430>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S435>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S482>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_l = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;
            FMS_DW.l1_heading = 0.0F;
            FMS_DW.icLoad_m = 1U;
            FMS_DW.Integrator1_IC_LOADING = 1U;
            FMS_DW.Integrator_DSTATE_m = 0.0F;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);

            /* End of SystemReset for SubSystem: '<S404>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S293>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S293>/Mission' incorporates:
           *  ActionPort: '<S404>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S407>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S407>/Delay Input1'
           *
           * Block description for '<S407>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S404>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S408>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S455>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S445>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for Delay: '<S434>/Delay' */
            FMS_DW.icLoad_l = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S435>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S430>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S482>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S412>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S415>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S415>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S456>/Motion State' */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S446>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S434>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_l != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_o[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_o[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S430>/Switch2' incorporates:
           *  Constant: '<S430>/vel'
           *  Constant: '<S439>/Constant'
           *  RelationalOperator: '<S439>/Compare'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            d = FMS_B.Cmd_In.set_speed;
          } else {
            d = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S430>/Switch2' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S435>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S407>/Delay Input1'
           *
           * Block description for '<S407>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTAT_kf;

          /* RelationalOperator: '<S429>/Compare' incorporates:
           *  Constant: '<S486>/Constant'
           *  RelationalOperator: '<S486>/Compare'
           *  UnitDelay: '<S407>/Delay Input1'
           *
           * Block description for '<S407>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S430>/Acceleration_Speed' */
          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S456>/Motion State' incorporates:
           *  Constant: '<S456>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S456>/Square'
           *  Math: '<S456>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S456>/Sqrt'
           *  Sum: '<S456>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S455>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S465>/Integrator1'
           *  Gain: '<S459>/Gain6'
           *  Gain: '<S463>/Gain'
           *  Gain: '<S464>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S465>/Subtract'
           *  Sum: '<S466>/Add'
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
              /* SystemReset for IfAction SubSystem: '<S455>/Hold Control' incorporates:
               *  ActionPort: '<S458>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S455>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S455>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S455>/Hold Control' incorporates:
             *  ActionPort: '<S458>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S455>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S455>/Brake Control' incorporates:
             *  ActionPort: '<S457>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S455>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S455>/Move Control' incorporates:
               *  ActionPort: '<S459>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S455>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S465>/Integrator'
               *  DiscreteIntegrator: '<S465>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S455>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S455>/Move Control' incorporates:
             *  ActionPort: '<S459>/Action Port'
             */
            /* SignalConversion: '<S459>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S465>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S466>/Multiply1' incorporates:
             *  Constant: '<S466>/const1'
             *  DiscreteIntegrator: '<S465>/Integrator'
             */
            rtb_Subtract_hb[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S459>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S465>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S466>/Multiply1' incorporates:
             *  Constant: '<S466>/const1'
             *  DiscreteIntegrator: '<S465>/Integrator'
             */
            rtb_Subtract_hb[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S463>/Dead Zone' incorporates:
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

            /* Sum: '<S466>/Add' incorporates:
             *  DiscreteIntegrator: '<S465>/Integrator1'
             *  Gain: '<S459>/Gain6'
             *  Gain: '<S463>/Gain'
             *  Sum: '<S465>/Subtract'
             */
            rtb_Divide_i5[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S464>/Dead Zone' incorporates:
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

            /* Sum: '<S466>/Add' incorporates:
             *  DiscreteIntegrator: '<S465>/Integrator1'
             *  Gain: '<S459>/Gain6'
             *  Gain: '<S464>/Gain'
             *  Sum: '<S465>/Subtract'
             */
            rtb_Divide_i5[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S463>/Dead Zone' incorporates:
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

            /* Signum: '<S466>/Sign' incorporates:
             *  DiscreteIntegrator: '<S465>/Integrator1'
             *  Gain: '<S459>/Gain6'
             *  Gain: '<S463>/Gain'
             *  Sum: '<S465>/Subtract'
             *  Sum: '<S466>/Add'
             */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S466>/Add2' incorporates:
             *  Abs: '<S466>/Abs'
             *  Gain: '<S466>/Gain'
             *  Gain: '<S466>/Gain1'
             *  Product: '<S466>/Multiply2'
             *  Product: '<S466>/Multiply3'
             *  Signum: '<S466>/Sign'
             *  Sqrt: '<S466>/Sqrt'
             *  Sum: '<S466>/Add1'
             *  Sum: '<S466>/Subtract'
             */
            rtb_Add4_o = (sqrtf((8.0F * fabsf(rtb_Divide_i5[0]) +
                                 FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                          FMS_ConstB.d_oe) * 0.5F * rtb_Divide_pr_idx_0 +
              rtb_Subtract_hb[0];

            /* Sum: '<S466>/Add3' incorporates:
             *  Signum: '<S466>/Sign'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_i5[0] + FMS_ConstB.d_oe;

            /* Sum: '<S466>/Subtract1' incorporates:
             *  Signum: '<S466>/Sign'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] - FMS_ConstB.d_oe;

            /* Signum: '<S466>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S466>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S466>/Add5' incorporates:
             *  Gain: '<S466>/Gain2'
             *  Product: '<S466>/Multiply4'
             *  Signum: '<S466>/Sign'
             *  Sum: '<S466>/Add2'
             *  Sum: '<S466>/Add4'
             *  Sum: '<S466>/Subtract2'
             */
            rtb_Add4_o += ((rtb_Divide_i5[0] - rtb_Add4_o) + rtb_Subtract_hb[0])
              * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F);

            /* Update for DiscreteIntegrator: '<S465>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S465>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S466>/Sign4' incorporates:
             *  Sum: '<S466>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Add4_o - FMS_ConstB.d_oe;

            /* Signum: '<S466>/Sign3' incorporates:
             *  Sum: '<S466>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Add4_o + FMS_ConstB.d_oe;

            /* Signum: '<S466>/Sign5' */
            if (rtb_Add4_o < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else if (rtb_Add4_o > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Add4_o;
            }

            /* Signum: '<S466>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S466>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S466>/Sign6' */
            if (rtb_Add4_o < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Add4_o > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Add4_o;
            }

            /* Update for DiscreteIntegrator: '<S465>/Integrator' incorporates:
             *  Constant: '<S466>/const'
             *  Gain: '<S466>/Gain3'
             *  Product: '<S466>/Divide'
             *  Product: '<S466>/Multiply5'
             *  Product: '<S466>/Multiply6'
             *  Sum: '<S466>/Subtract4'
             *  Sum: '<S466>/Subtract5'
             *  Sum: '<S466>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Add4_o / FMS_ConstB.d_oe -
              rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_g * ((rtb_Divide_pr_idx_0
              - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Saturation_e * 58.836F) *
              0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S464>/Dead Zone' incorporates:
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

            /* Signum: '<S466>/Sign' incorporates:
             *  DiscreteIntegrator: '<S465>/Integrator1'
             *  Gain: '<S459>/Gain6'
             *  Gain: '<S464>/Gain'
             *  Sum: '<S465>/Subtract'
             *  Sum: '<S466>/Add'
             */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S466>/Add2' incorporates:
             *  Abs: '<S466>/Abs'
             *  Gain: '<S466>/Gain'
             *  Gain: '<S466>/Gain1'
             *  Product: '<S466>/Multiply2'
             *  Product: '<S466>/Multiply3'
             *  Signum: '<S466>/Sign'
             *  Sqrt: '<S466>/Sqrt'
             *  Sum: '<S466>/Add1'
             *  Sum: '<S466>/Subtract'
             */
            rtb_Add4_o = (sqrtf((8.0F * fabsf(rtb_Divide_i5[1]) +
                                 FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                          FMS_ConstB.d_oe) * 0.5F * rtb_Divide_pr_idx_0 +
              rtb_Subtract_hb[1];

            /* Sum: '<S466>/Add3' incorporates:
             *  Signum: '<S466>/Sign'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_i5[1] + FMS_ConstB.d_oe;

            /* Sum: '<S466>/Subtract1' incorporates:
             *  Signum: '<S466>/Sign'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_i5[1] - FMS_ConstB.d_oe;

            /* Signum: '<S466>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S466>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S466>/Add5' incorporates:
             *  Gain: '<S466>/Gain2'
             *  Product: '<S466>/Multiply4'
             *  Signum: '<S466>/Sign'
             *  Sum: '<S466>/Add2'
             *  Sum: '<S466>/Add4'
             *  Sum: '<S466>/Subtract2'
             */
            rtb_Add4_o += ((rtb_Divide_i5[1] - rtb_Add4_o) + rtb_Subtract_hb[1])
              * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F);

            /* Update for DiscreteIntegrator: '<S465>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S465>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S466>/Sign4' incorporates:
             *  Sum: '<S466>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Add4_o - FMS_ConstB.d_oe;

            /* Signum: '<S466>/Sign3' incorporates:
             *  Sum: '<S466>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Add4_o + FMS_ConstB.d_oe;

            /* Signum: '<S466>/Sign5' */
            if (rtb_Add4_o < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else if (rtb_Add4_o > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Add4_o;
            }

            /* Signum: '<S466>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S466>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S466>/Sign6' */
            if (rtb_Add4_o < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Add4_o > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Add4_o;
            }

            /* Update for DiscreteIntegrator: '<S465>/Integrator' incorporates:
             *  Constant: '<S466>/const'
             *  Gain: '<S466>/Gain3'
             *  Product: '<S466>/Divide'
             *  Product: '<S466>/Multiply5'
             *  Product: '<S466>/Multiply6'
             *  Sum: '<S466>/Subtract4'
             *  Sum: '<S466>/Subtract5'
             *  Sum: '<S466>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Add4_o / FMS_ConstB.d_oe -
              rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_g * ((rtb_Divide_pr_idx_0
              - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Saturation_e * 58.836F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S455>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S455>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S446>/Motion Status' incorporates:
           *  Abs: '<S446>/Abs'
           *  Constant: '<S446>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S445>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S445>/Hold Control' incorporates:
               *  ActionPort: '<S448>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S445>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S445>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S445>/Hold Control' incorporates:
             *  ActionPort: '<S448>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S445>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S445>/Brake Control' incorporates:
             *  ActionPort: '<S447>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S445>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S445>/Move Control' incorporates:
               *  ActionPort: '<S449>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S445>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S452>/Integrator'
               *  DiscreteIntegrator: '<S452>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S445>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S445>/Move Control' incorporates:
             *  ActionPort: '<S449>/Action Port'
             */
            /* Product: '<S453>/Multiply1' incorporates:
             *  Constant: '<S453>/const1'
             *  DiscreteIntegrator: '<S452>/Integrator'
             */
            rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S451>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S451>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S453>/Add' incorporates:
             *  DiscreteIntegrator: '<S452>/Integrator1'
             *  Gain: '<S449>/Gain1'
             *  Gain: '<S451>/Gain'
             *  Sum: '<S452>/Subtract'
             */
            rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_Saturation_e * -FMS_PARAM.VEL_Z_LIM)
              + rtb_Divide_pr_idx_1;

            /* Signum: '<S453>/Sign' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_0;
            }

            /* End of Signum: '<S453>/Sign' */

            /* Sum: '<S453>/Add2' incorporates:
             *  Abs: '<S453>/Abs'
             *  Gain: '<S453>/Gain'
             *  Gain: '<S453>/Gain1'
             *  Product: '<S453>/Multiply2'
             *  Product: '<S453>/Multiply3'
             *  Sqrt: '<S453>/Sqrt'
             *  Sum: '<S453>/Add1'
             *  Sum: '<S453>/Subtract'
             */
            rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
              FMS_ConstB.d_oc) * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation_e + rtb_Divide_pr_idx_1;

            /* Sum: '<S453>/Add4' */
            rtb_Divide_pr_idx_2 = (rtb_Divide_pr_idx_0 - rtb_Saturation_e) +
              rtb_Divide_pr_idx_1;

            /* Sum: '<S453>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_oc;

            /* Sum: '<S453>/Subtract1' */
            rtb_Divide_pr_idx_0 -= FMS_ConstB.d_oc;

            /* Signum: '<S453>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S453>/Sign1' */

            /* Signum: '<S453>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S453>/Sign2' */

            /* Sum: '<S453>/Add5' incorporates:
             *  Gain: '<S453>/Gain2'
             *  Product: '<S453>/Multiply4'
             *  Sum: '<S453>/Subtract2'
             */
            rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
              0.5F * rtb_Divide_pr_idx_2;

            /* SignalConversion: '<S449>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S452>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S452>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S452>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S453>/Subtract3' */
            rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_oc;

            /* Sum: '<S453>/Add6' */
            rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_oc;

            /* Signum: '<S453>/Sign5' incorporates:
             *  Signum: '<S453>/Sign6'
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;

              /* Signum: '<S453>/Sign6' */
              rtb_Add4_o = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;

              /* Signum: '<S453>/Sign6' */
              rtb_Add4_o = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Saturation_e;

              /* Signum: '<S453>/Sign6' */
              rtb_Add4_o = rtb_Saturation_e;
            }

            /* End of Signum: '<S453>/Sign5' */

            /* Signum: '<S453>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S453>/Sign3' */

            /* Signum: '<S453>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S453>/Sign4' */

            /* Update for DiscreteIntegrator: '<S452>/Integrator' incorporates:
             *  Constant: '<S453>/const'
             *  Gain: '<S453>/Gain3'
             *  Product: '<S453>/Divide'
             *  Product: '<S453>/Multiply5'
             *  Product: '<S453>/Multiply6'
             *  Sum: '<S453>/Subtract4'
             *  Sum: '<S453>/Subtract5'
             *  Sum: '<S453>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_Saturation_e / FMS_ConstB.d_oc
              - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_j *
              ((rtb_Divide_pr_idx_0 - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o *
              78.448F) * 0.004F;

            /* End of Outputs for SubSystem: '<S445>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S445>/Switch Case' */

          /* Switch: '<S410>/Switch' incorporates:
           *  Product: '<S434>/Multiply'
           *  Sum: '<S434>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S455>/Saturation1' */
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

            /* End of Saturate: '<S455>/Saturation1' */

            /* Saturate: '<S445>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S445>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S434>/Sum' incorporates:
             *  Delay: '<S434>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_o[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S483>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S430>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S434>/Sum' incorporates:
             *  Delay: '<S434>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_o[1];

            /* Sum: '<S430>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S442>/Sqrt' incorporates:
             *  Math: '<S442>/Square'
             *  Sum: '<S430>/Sum'
             *  Sum: '<S442>/Sum of Elements'
             */
            rtb_Divide_pr_idx_0 = sqrtf(rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Saturation_e * rtb_Saturation_e);

            /* SignalConversion: '<S485>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_c[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_c[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_c[2];

            /* SignalConversion: '<S485>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S485>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S484>/Gain' incorporates:
             *  DiscreteIntegrator: '<S482>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S482>/Add'
             */
            rtb_Saturation_e = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S485>/Trigonometric Function3' */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(rtb_Saturation_e);

            /* Gain: '<S485>/Gain' incorporates:
             *  Trigonometry: '<S485>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(rtb_Saturation_e);

            /* SignalConversion: '<S485>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S485>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S485>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(rtb_Saturation_e);

            /* Trigonometry: '<S485>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(rtb_Saturation_e);

            /* Switch: '<S441>/Switch2' incorporates:
             *  Constant: '<S430>/Constant2'
             *  DiscreteIntegrator: '<S430>/Acceleration_Speed'
             *  RelationalOperator: '<S441>/LowerRelop1'
             *  RelationalOperator: '<S441>/UpperRelop'
             *  Switch: '<S441>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > d) {
              rtb_Saturation_e = d;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S441>/Switch' incorporates:
               *  Constant: '<S430>/Constant2'
               */
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S441>/Switch2' */

            /* Switch: '<S430>/Switch' */
            if (rtb_Divide_pr_idx_0 > FMS_PARAM.L1) {
              rtb_Divide_pr_idx_2 = d;
            } else {
              /* Gain: '<S430>/Gain' */
              rtb_Divide_pr_idx_2 = 0.5F * rtb_Divide_pr_idx_0;

              /* Switch: '<S440>/Switch2' incorporates:
               *  Constant: '<S430>/Constant1'
               *  RelationalOperator: '<S440>/LowerRelop1'
               *  RelationalOperator: '<S440>/UpperRelop'
               *  Switch: '<S440>/Switch'
               */
              if (rtb_Divide_pr_idx_2 > d) {
                rtb_Divide_pr_idx_2 = d;
              } else {
                if (rtb_Divide_pr_idx_2 < 0.5F) {
                  /* Switch: '<S440>/Switch' incorporates:
                   *  Constant: '<S430>/Constant1'
                   */
                  rtb_Divide_pr_idx_2 = 0.5F;
                }
              }

              /* End of Switch: '<S440>/Switch2' */
            }

            /* End of Switch: '<S430>/Switch' */

            /* Switch: '<S430>/Switch1' incorporates:
             *  Sum: '<S430>/Sum1'
             */
            if (rtb_Saturation_e - rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = rtb_Saturation_e;
            }

            /* End of Switch: '<S430>/Switch1' */

            /* Sum: '<S483>/Sum of Elements' incorporates:
             *  Math: '<S483>/Math Function'
             */
            rtb_Saturation_e = rtb_Switch_c2[0] * rtb_Switch_c2[0] +
              rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

            /* Math: '<S483>/Math Function1' incorporates:
             *  Sum: '<S483>/Sum of Elements'
             *
             * About '<S483>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Saturation_e = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S483>/Math Function1' */

            /* Switch: '<S483>/Switch' incorporates:
             *  Constant: '<S483>/Constant'
             *  Product: '<S483>/Product'
             */
            if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_0 = rtb_Subtract_hb[0];
            } else {
              rtb_Divide_pr_idx_0 = 0.0F;
              rtb_Divide_pr_idx_1 = 0.0F;
              rtb_Saturation_e = 1.0F;
            }

            /* End of Switch: '<S483>/Switch' */

            /* Product: '<S481>/Multiply2' incorporates:
             *  Product: '<S483>/Divide'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_0 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_1 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S436>/Sum1' incorporates:
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_e = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S436>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Add4_o = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Divide_or = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S436>/Divide' incorporates:
             *  Math: '<S437>/Square'
             *  Math: '<S438>/Square'
             *  Sqrt: '<S437>/Sqrt'
             *  Sqrt: '<S438>/Sqrt'
             *  Sum: '<S436>/Sum'
             *  Sum: '<S436>/Sum1'
             *  Sum: '<S437>/Sum of Elements'
             *  Sum: '<S438>/Sum of Elements'
             */
            rtb_Saturation_e = sqrtf(rtb_Add4_o * rtb_Add4_o + rtb_Divide_or *
              rtb_Divide_or) / sqrtf(rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2 +
              rtb_Saturation_e * rtb_Saturation_e);

            /* Saturate: '<S436>/Saturation' */
            if (rtb_Saturation_e > 1.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              if (rtb_Saturation_e < 0.0F) {
                rtb_Saturation_e = 0.0F;
              }
            }

            /* End of Saturate: '<S436>/Saturation' */

            /* Product: '<S434>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n +
                3] * rtb_Divide_pr_idx_1 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_0;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S427>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S436>/Multiply'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S427>/Sum2'
             *  Sum: '<S436>/Add'
             *  Sum: '<S436>/Subtract'
             */
            rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
              - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_e +
              FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_VectorConcatenate_g0[0];
            rtb_Switch_c2[1] = rtb_VectorConcatenate_g0[1];

            /* Saturate: '<S427>/Saturation1' incorporates:
             *  Product: '<S434>/Multiply'
             */
            if (rtb_Saturation_e > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_Saturation_e < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_Saturation_e;
            }

            /* End of Saturate: '<S427>/Saturation1' */
          }

          /* End of Switch: '<S410>/Switch' */

          /* Delay: '<S412>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S415>/Integrator1' incorporates:
           *  Delay: '<S412>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S419>/Rem' incorporates:
           *  Constant: '<S419>/Constant1'
           *  DiscreteIntegrator: '<S415>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S414>/Sum'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S419>/Switch' incorporates:
           *  Abs: '<S419>/Abs'
           *  Constant: '<S419>/Constant'
           *  Constant: '<S420>/Constant'
           *  Product: '<S419>/Multiply'
           *  RelationalOperator: '<S420>/Compare'
           *  Sum: '<S419>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S419>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S419>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S419>/Switch' */

          /* Gain: '<S414>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S414>/Saturation' */
          if (rtb_Divide_pr_idx_2 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_pr_idx_2 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Divide_pr_idx_2 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_2 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S414>/Saturation' */

          /* BusAssignment: '<S408>/Bus Assignment' incorporates:
           *  Constant: '<S408>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d3;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_d;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_c2[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_c2[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_c2[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_2;

          /* Math: '<S476>/Math Function1'
           *
           * About '<S476>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S476>/Math Function1' */

          /* Switch: '<S476>/Switch' incorporates:
           *  Constant: '<S476>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S476>/Product'
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

          /* End of Switch: '<S476>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S408>/Sum' incorporates:
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

          /* SignalConversion: '<S426>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S408>/Sum'
           */
          rtb_P_cg[0] = rtb_Divide_pr_idx_0;
          rtb_P_cg[1] = rtb_Divide_pr_idx_1;

          /* Math: '<S426>/Math Function' incorporates:
           *  Sum: '<S408>/Sum'
           */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

          /* Sum: '<S426>/Sum of Elements' */
          rtb_Saturation_e = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S426>/Math Function1' incorporates:
           *  Sum: '<S426>/Sum of Elements'
           *
           * About '<S426>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S426>/Math Function1' */

          /* Switch: '<S426>/Switch' incorporates:
           *  Constant: '<S426>/Constant'
           *  Product: '<S426>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Divide_or = rtb_Divide_pr_idx_2;
          } else {
            rtb_Divide_pr_idx_0 = 0.0F;
            rtb_Divide_pr_idx_1 = 0.0F;
            rtb_Divide_or = 1.0F;
          }

          /* End of Switch: '<S426>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S432>/NearbyRefWP' incorporates:
           *  Constant: '<S408>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_i5,
                          &rtb_Saturation_e);

          /* MATLAB Function: '<S432>/SearchL1RefWP' incorporates:
           *  Constant: '<S408>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_cg, &rtb_Divide_pr_idx_2);

          /* MATLAB Function: '<S432>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S432>/Switch1' incorporates:
           *  Constant: '<S469>/Constant'
           *  RelationalOperator: '<S469>/Compare'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_i5[0];
            rtb_P_cg[1] = rtb_Divide_i5[1];
          } else {
            /* RelationalOperator: '<S468>/Compare' incorporates:
             *  Constant: '<S468>/Constant'
             */
            rtb_Compare_kd = (rtb_Divide_pr_idx_2 >= 0.0F);

            /* Switch: '<S432>/Switch' */
            if (!rtb_Compare_kd) {
              rtb_P_cg[0] = rtb_Square_ds[0];
              rtb_P_cg[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S432>/Switch' */
          }

          /* End of Switch: '<S432>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S433>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Add4_o = rtb_P_cg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_cg[0] = rtb_Add4_o;
          rtb_Square_bg[0] = rtb_Add4_o * rtb_Add4_o;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S433>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S477>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Add4_o = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S477>/Sum of Elements' incorporates:
           *  Math: '<S477>/Math Function'
           *  Sum: '<S475>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Square_bg[0] + rtb_Add4_o * rtb_Add4_o;

          /* Math: '<S477>/Math Function1' incorporates:
           *  Sum: '<S477>/Sum of Elements'
           *
           * About '<S477>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S477>/Math Function1' */

          /* Switch: '<S477>/Switch' incorporates:
           *  Constant: '<S477>/Constant'
           *  Product: '<S477>/Product'
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

          /* End of Switch: '<S477>/Switch' */

          /* Product: '<S476>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S479>/Sum of Elements' incorporates:
           *  Math: '<S479>/Math Function'
           *  SignalConversion: '<S479>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S479>/Math Function1' incorporates:
           *  Sum: '<S479>/Sum of Elements'
           *
           * About '<S479>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S479>/Math Function1' */

          /* Switch: '<S479>/Switch' incorporates:
           *  Constant: '<S479>/Constant'
           *  Product: '<S479>/Product'
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

          /* End of Switch: '<S479>/Switch' */

          /* Product: '<S477>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

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
            rtb_Switch_an[0] = rtb_Divide_i5[1];
            rtb_Switch_an[1] = rtb_Divide_i5[0];
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S480>/Switch' */

          /* Product: '<S480>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S479>/Divide' */
          rtb_P_cg[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S426>/Divide' */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 / rtb_Divide_or;

          /* Product: '<S480>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S479>/Divide' */
          rtb_P_cg[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S426>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 / rtb_Divide_or;

          /* Sum: '<S478>/Subtract' incorporates:
           *  Product: '<S478>/Multiply'
           *  Product: '<S478>/Multiply1'
           */
          rtb_Divide_pr_idx_2 = rtb_Divide_i5[0] * rtb_P_cg[1] - rtb_Divide_i5[1]
            * rtb_P_cg[0];

          /* Signum: '<S473>/Sign1' */
          if (rtb_Divide_pr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S473>/Sign1' */

          /* Switch: '<S473>/Switch2' incorporates:
           *  Constant: '<S473>/Constant4'
           */
          if (rtb_Divide_pr_idx_2 == 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          }

          /* End of Switch: '<S473>/Switch2' */

          /* DotProduct: '<S473>/Dot Product' */
          rtb_Add4_o = rtb_P_cg[0] * rtb_Divide_i5[0] + rtb_P_cg[1] *
            rtb_Divide_i5[1];

          /* Trigonometry: '<S473>/Acos' incorporates:
           *  DotProduct: '<S473>/Dot Product'
           */
          if (rtb_Add4_o > 1.0F) {
            rtb_Add4_o = 1.0F;
          } else {
            if (rtb_Add4_o < -1.0F) {
              rtb_Add4_o = -1.0F;
            }
          }

          /* Product: '<S473>/Multiply' incorporates:
           *  Trigonometry: '<S473>/Acos'
           */
          rtb_Divide_pr_idx_2 *= acosf(rtb_Add4_o);

          /* Saturate: '<S433>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.57079637F) {
            rtb_Divide_pr_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.57079637F) {
              rtb_Divide_pr_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S433>/Saturation' */

          /* Product: '<S433>/Divide' incorporates:
           *  Constant: '<S408>/L1'
           *  Constant: '<S433>/Constant'
           *  Gain: '<S433>/Gain'
           *  Math: '<S433>/Square'
           *  MinMax: '<S433>/Max'
           *  MinMax: '<S433>/Min'
           *  Product: '<S433>/Multiply1'
           *  Sqrt: '<S475>/Sqrt'
           *  Trigonometry: '<S433>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Divide_pr_idx_2) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_e), 0.5F));

          /* Sum: '<S424>/Subtract' incorporates:
           *  Product: '<S424>/Multiply'
           *  Product: '<S424>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S413>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S413>/Sign1' */

          /* Switch: '<S413>/Switch2' incorporates:
           *  Constant: '<S413>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S413>/Switch2' */

          /* DotProduct: '<S413>/Dot Product' */
          rtb_Saturation_e = FMS_ConstB.Divide[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S413>/Acos' incorporates:
           *  DotProduct: '<S413>/Dot Product'
           */
          if (rtb_Saturation_e > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            if (rtb_Saturation_e < -1.0F) {
              rtb_Saturation_e = -1.0F;
            }
          }

          /* Product: '<S413>/Multiply' incorporates:
           *  Trigonometry: '<S413>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_Saturation_e);

          /* Math: '<S416>/Rem' incorporates:
           *  Constant: '<S416>/Constant1'
           *  Delay: '<S412>/Delay'
           *  Sum: '<S412>/Sum2'
           */
          rtb_Divide_pr_idx_2 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_n, 6.28318548F);

          /* Switch: '<S416>/Switch' incorporates:
           *  Abs: '<S416>/Abs'
           *  Constant: '<S416>/Constant'
           *  Constant: '<S422>/Constant'
           *  Product: '<S416>/Multiply'
           *  RelationalOperator: '<S422>/Compare'
           *  Sum: '<S416>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S416>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S416>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S416>/Switch' */

          /* Sum: '<S412>/Sum' incorporates:
           *  Delay: '<S412>/Delay'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S421>/Multiply1' incorporates:
           *  Constant: '<S421>/const1'
           *  DiscreteIntegrator: '<S415>/Integrator'
           */
          rtb_Divide_pr_idx_2 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S421>/Add' incorporates:
           *  DiscreteIntegrator: '<S415>/Integrator1'
           *  Sum: '<S415>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_mf -
            rtb_Divide_pr_idx_1) + rtb_Divide_pr_idx_2;

          /* Signum: '<S421>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S421>/Sign' */

          /* Sum: '<S421>/Add2' incorporates:
           *  Abs: '<S421>/Abs'
           *  Gain: '<S421>/Gain'
           *  Gain: '<S421>/Gain1'
           *  Product: '<S421>/Multiply2'
           *  Product: '<S421>/Multiply3'
           *  Sqrt: '<S421>/Sqrt'
           *  Sum: '<S421>/Add1'
           *  Sum: '<S421>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2;

          /* Sum: '<S421>/Add4' */
          rtb_Divide_pr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S421>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_m;

          /* Sum: '<S421>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_m;

          /* Signum: '<S421>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S421>/Sign1' */

          /* Signum: '<S421>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S421>/Sign2' */

          /* Sum: '<S421>/Add5' incorporates:
           *  Gain: '<S421>/Gain2'
           *  Product: '<S421>/Multiply4'
           *  Sum: '<S421>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_pr_idx_2;

          /* Sum: '<S421>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_m;

          /* Sum: '<S421>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e - FMS_ConstB.d_m;

          /* Product: '<S421>/Divide' */
          rtb_Add4_o = rtb_Saturation_e / FMS_ConstB.d_m;

          /* Signum: '<S421>/Sign5' incorporates:
           *  Signum: '<S421>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S421>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S421>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Divide_or = rtb_Saturation_e;

            /* Signum: '<S421>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S421>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S412>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S417>/Rem' incorporates:
           *  Constant: '<S417>/Constant1'
           */
          rtb_Saturation_e = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S417>/Switch' incorporates:
           *  Abs: '<S417>/Abs'
           *  Constant: '<S417>/Constant'
           *  Constant: '<S423>/Constant'
           *  Product: '<S417>/Multiply'
           *  RelationalOperator: '<S423>/Compare'
           *  Sum: '<S417>/Add'
           */
          if (fabsf(rtb_Saturation_e) > 3.14159274F) {
            /* Signum: '<S417>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_e;
            }

            /* End of Signum: '<S417>/Sign' */
            rtb_Saturation_e -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S417>/Switch' */

          /* Abs: '<S410>/Abs' */
          rtb_Saturation_e = fabsf(rtb_Saturation_e);

          /* Update for Delay: '<S434>/Delay' */
          FMS_DW.icLoad_l = 0U;

          /* Update for DiscreteIntegrator: '<S435>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S428>/Constant'
           *  RelationalOperator: '<S428>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S435>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S430>/Acceleration_Speed' incorporates:
           *  Constant: '<S430>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Product: '<S434>/Divide1' */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 / d;

          /* Saturate: '<S434>/Saturation' */
          if (rtb_Saturation_e > 0.314159274F) {
            rtb_Saturation_e = 0.314159274F;
          } else {
            if (rtb_Saturation_e < -0.314159274F) {
              rtb_Saturation_e = -0.314159274F;
            }
          }

          /* End of Saturate: '<S434>/Saturation' */

          /* Update for DiscreteIntegrator: '<S482>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_Saturation_e;

          /* Update for Delay: '<S412>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S415>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S415>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S421>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S421>/Sign3' */

          /* Signum: '<S421>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S421>/Sign4' */

          /* Update for DiscreteIntegrator: '<S415>/Integrator' incorporates:
           *  Constant: '<S421>/const'
           *  Gain: '<S421>/Gain3'
           *  Product: '<S421>/Multiply5'
           *  Product: '<S421>/Multiply6'
           *  Sum: '<S421>/Subtract4'
           *  Sum: '<S421>/Subtract5'
           *  Sum: '<S421>/Subtract6'
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

          /* End of Update for DiscreteIntegrator: '<S415>/Integrator' */
          /* End of Outputs for SubSystem: '<S404>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S407>/Delay Input1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S407>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S293>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S293>/Unknown' incorporates:
           *  ActionPort: '<S406>/Action Port'
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
            /* Disable for SwitchCase: '<S391>/Switch Case' */
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
             *  DiscreteIntegrator: '<S387>/Integrator'
             *  DiscreteIntegrator: '<S387>/Integrator1'
             *  DiscreteIntegrator: '<S388>/Integrator'
             *  DiscreteIntegrator: '<S388>/Integrator1'
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
             *  Chart: '<S392>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S292>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S292>/Stabilize' incorporates:
           *  ActionPort: '<S300>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S382>/Logical Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S392>/Motion State' incorporates:
           *  Abs: '<S392>/Abs'
           *  Abs: '<S392>/Abs1'
           *  Constant: '<S402>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S402>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S391>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S391>/Hold Control' incorporates:
               *  ActionPort: '<S394>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S391>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S391>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S391>/Hold Control' incorporates:
             *  ActionPort: '<S394>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S391>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S391>/Brake Control' incorporates:
             *  ActionPort: '<S393>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S391>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S391>/Move Control' incorporates:
               *  ActionPort: '<S395>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S391>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S391>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S391>/Move Control' incorporates:
             *  ActionPort: '<S395>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S391>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S391>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S384>/Switch' incorporates:
           *  Constant: '<S384>/Constant'
           *  Constant: '<S384>/Constant4'
           *  Constant: '<S384>/Constant5'
           *  Gain: '<S384>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S384>/Saturation'
           *  SignalConversion: '<S40>/Signal Copy2'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S384>/Add'
           *  Sum: '<S384>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S384>/Saturation' */
              rtb_Saturation_e = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S384>/Saturation' */
              rtb_Saturation_e = 0.0F;
            } else {
              /* Saturate: '<S384>/Saturation' incorporates:
               *  Constant: '<S384>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S40>/Signal Copy2'
               *  Sum: '<S384>/Sum'
               */
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
              rtb_Saturation_e), 65536.0F) + 1000U);
          }

          /* End of Switch: '<S384>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S300>/Bus Assignment' incorporates:
           *  Constant: '<S300>/Constant'
           *  DataTypeConversion: '<S382>/Data Type Conversion'
           *  DiscreteIntegrator: '<S387>/Integrator1'
           *  DiscreteIntegrator: '<S388>/Integrator1'
           *  Product: '<S382>/Multiply'
           *  Product: '<S382>/Multiply1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S391>/Saturation' */
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

          /* End of Saturate: '<S391>/Saturation' */

          /* BusAssignment: '<S300>/Bus Assignment' */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S390>/Multiply1' incorporates:
           *  Constant: '<S390>/const1'
           *  DiscreteIntegrator: '<S388>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S386>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S386>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S390>/Add' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator1'
           *  Gain: '<S382>/Gain1'
           *  Gain: '<S386>/Gain'
           *  Sum: '<S388>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

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
            FMS_ConstB.d_g) * FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S390>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Saturation_e - rtb_Divide_lr_idx_3;

          /* Sum: '<S390>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_g;

          /* Sum: '<S390>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_g;

          /* Signum: '<S390>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
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
          rtb_Divide_lr_idx_3 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Sum: '<S390>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_g;

          /* Sum: '<S390>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_g;

          /* Product: '<S390>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_g;

          /* Signum: '<S390>/Sign5' incorporates:
           *  Signum: '<S390>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Add4_o = -1.0F;

            /* Signum: '<S390>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Add4_o = 1.0F;

            /* Signum: '<S390>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Add4_o = rtb_Divide_lr_idx_3;

            /* Signum: '<S390>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S390>/Sign5' */

          /* Product: '<S389>/Multiply1' incorporates:
           *  Constant: '<S389>/const1'
           *  DiscreteIntegrator: '<S387>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S385>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S385>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S389>/Add' incorporates:
           *  DiscreteIntegrator: '<S387>/Integrator1'
           *  Gain: '<S382>/Gain'
           *  Gain: '<S385>/Gain'
           *  Sum: '<S387>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S389>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S389>/Sign' */

          /* Sum: '<S389>/Add2' incorporates:
           *  Abs: '<S389>/Abs'
           *  Gain: '<S389>/Gain'
           *  Gain: '<S389>/Gain1'
           *  Product: '<S389>/Multiply2'
           *  Product: '<S389>/Multiply3'
           *  Sqrt: '<S389>/Sqrt'
           *  Sum: '<S389>/Add1'
           *  Sum: '<S389>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S389>/Add4' */
          rtb_Divide_or = (rtb_Saturation_e - rtb_Divide_lr_idx_3) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S389>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_a;

          /* Sum: '<S389>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_a;

          /* Signum: '<S389>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S389>/Sign1' */

          /* Signum: '<S389>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S389>/Sign2' */

          /* Sum: '<S389>/Add5' incorporates:
           *  Gain: '<S389>/Gain2'
           *  Product: '<S389>/Multiply4'
           *  Sum: '<S389>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_or;

          /* Update for DiscreteIntegrator: '<S387>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S387>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S388>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S388>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S390>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S390>/Sign3' */

          /* Signum: '<S390>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S390>/Sign4' */

          /* Update for DiscreteIntegrator: '<S388>/Integrator' incorporates:
           *  Constant: '<S390>/const'
           *  Gain: '<S390>/Gain3'
           *  Product: '<S390>/Multiply5'
           *  Product: '<S390>/Multiply6'
           *  Sum: '<S390>/Subtract4'
           *  Sum: '<S390>/Subtract5'
           *  Sum: '<S390>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((d - rtb_Add4_o) * FMS_ConstB.Gain4_o *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 12.566371F) * 0.004F;

          /* Sum: '<S389>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_a;

          /* Sum: '<S389>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_a;

          /* Signum: '<S389>/Sign5' incorporates:
           *  Signum: '<S389>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S389>/Sign6' */
            rtb_Add4_o = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S389>/Sign6' */
            rtb_Add4_o = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S389>/Sign6' */
            rtb_Add4_o = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S389>/Sign5' */

          /* Signum: '<S389>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S389>/Sign3' */

          /* Signum: '<S389>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S389>/Sign4' */

          /* Update for DiscreteIntegrator: '<S387>/Integrator' incorporates:
           *  Constant: '<S389>/const'
           *  Gain: '<S389>/Gain3'
           *  Product: '<S389>/Divide'
           *  Product: '<S389>/Multiply5'
           *  Product: '<S389>/Multiply6'
           *  Sum: '<S389>/Subtract4'
           *  Sum: '<S389>/Subtract5'
           *  Sum: '<S389>/Subtract6'
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
           *  Constant: '<S379>/Constant'
           *  Constant: '<S380>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S379>/Compare'
           *  RelationalOperator: '<S380>/Compare'
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

          /* SwitchCase: '<S366>/Switch Case' */
          rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_bf;
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;
          switch (rtb_state_fg) {
           case MotionState_Hold:
            FMS_DW.SwitchCase_ActiveSubsystem_bf = 0;
            break;

           case MotionState_Brake:
           case MotionState_Move:
            FMS_DW.SwitchCase_ActiveSubsystem_bf = 1;
            break;
          }

          switch (FMS_DW.SwitchCase_ActiveSubsystem_bf) {
           case 0:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S366>/Hold Control' incorporates:
               *  ActionPort: '<S368>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S366>/Switch Case' incorporates:
               *  Delay: '<S368>/Delay'
               */
              FMS_DW.icLoad = 1U;

              /* End of InitializeConditions for SubSystem: '<S366>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S366>/Hold Control' incorporates:
             *  ActionPort: '<S368>/Action Port'
             */
            /* Delay: '<S368>/Delay' incorporates:
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
            /* Trigonometry: '<S372>/Trigonometric Function1' incorporates:
             *  Gain: '<S371>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S372>/Trigonometric Function' incorporates:
             *  Gain: '<S371>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S372>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S372>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S372>/Gain' incorporates:
             *  Gain: '<S371>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S372>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S372>/Trigonometric Function3' incorporates:
             *  Gain: '<S371>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S372>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S372>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* SignalConversion: '<S372>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* SignalConversion: '<S368>/TmpSignal ConversionAtMultiplyInport2' incorporates:
             *  Delay: '<S368>/Delay'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S368>/Sum'
             */
            rtb_Divide_pr_idx_1 = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Divide_lr_idx_2 = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S368>/Multiply' incorporates:
             *  SignalConversion: '<S368>/TmpSignal ConversionAtMultiplyInport2'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n +
                3] * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1;
            }

            /* End of Product: '<S368>/Multiply' */

            /* Gain: '<S368>/Gain2' */
            FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
            FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

            /* Update for Delay: '<S368>/Delay' */
            FMS_DW.icLoad = 0U;

            /* End of Outputs for SubSystem: '<S366>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S366>/Move Control' incorporates:
               *  ActionPort: '<S369>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S366>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S375>/Integrator'
               *  DiscreteIntegrator: '<S375>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S366>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S366>/Move Control' incorporates:
             *  ActionPort: '<S369>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S373>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S373>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S373>/Gain' */
            rtb_Divide_pr_idx_1 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
              rtb_Saturation_e;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S374>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S374>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S374>/Gain' */
            rtb_Divide_lr_idx_2 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
              rtb_Saturation_e;

            /* SignalConversion: '<S376>/TmpSignal ConversionAtSquareInport1' */
            rtb_Square_bg[0] = rtb_Divide_pr_idx_1;
            rtb_Square_bg[1] = rtb_Divide_lr_idx_2;

            /* Sum: '<S376>/Sum of Elements' incorporates:
             *  Math: '<S376>/Square'
             *  SignalConversion: '<S376>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S377>/Sum of Elements'
             *  Switch: '<S369>/Switch'
             */
            rtb_Saturation_e = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 +
              rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

            /* Switch: '<S369>/Switch' incorporates:
             *  Product: '<S377>/Divide'
             *  Sqrt: '<S376>/Sqrt'
             *  Sum: '<S376>/Sum of Elements'
             */
            if (sqrtf(rtb_Saturation_e) > 1.0F) {
              /* Math: '<S377>/Math Function1'
               *
               * About '<S377>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Saturation_e < 0.0F) {
                rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
              } else {
                rtb_Saturation_e = sqrtf(rtb_Saturation_e);
              }

              /* End of Math: '<S377>/Math Function1' */

              /* Switch: '<S377>/Switch' incorporates:
               *  Constant: '<S377>/Constant'
               *  Product: '<S377>/Product'
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

              /* End of Switch: '<S377>/Switch' */
              rtb_Square_bg[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Square_bg[1] = rtb_Switch_an[1] / rtb_Switch_an[2];
            }

            /* Product: '<S378>/Multiply1' incorporates:
             *  Constant: '<S378>/const1'
             *  DiscreteIntegrator: '<S375>/Integrator'
             */
            rtb_Divide_pr_idx_0 = FMS_DW.Integrator_DSTATE[0] * 0.1F;

            /* Sum: '<S378>/Add' incorporates:
             *  DiscreteIntegrator: '<S375>/Integrator1'
             *  Gain: '<S369>/Gain6'
             *  Sum: '<S375>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE[0] -
              FMS_PARAM.VEL_XY_LIM * rtb_Square_bg[0]) + rtb_Divide_pr_idx_0;

            /* Signum: '<S378>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
            }

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
            rtb_Divide_pr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_0;

            /* Sum: '<S378>/Add4' */
            rtb_Divide_pr_idx_0 += rtb_Divide_lr_idx_2 - rtb_Divide_pr_idx_2;

            /* Sum: '<S378>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Sum: '<S378>/Subtract1' */
            rtb_Divide_lr_idx_2 -= FMS_ConstB.d;

            /* Signum: '<S378>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S378>/Sign2' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_2 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              }
            }

            /* Sum: '<S378>/Add5' incorporates:
             *  Gain: '<S378>/Gain2'
             *  Product: '<S378>/Multiply4'
             *  Sum: '<S378>/Subtract2'
             */
            rtb_Divide_pr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S375>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S375>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S375>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S375>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S378>/Sign4' incorporates:
             *  Sum: '<S378>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S378>/Sign3' incorporates:
             *  Sum: '<S378>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S378>/Sign5' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_2;
            }

            /* Signum: '<S378>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S378>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S378>/Sign6' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Add4_o = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Add4_o = 1.0F;
            } else {
              rtb_Add4_o = rtb_Divide_pr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S375>/Integrator' incorporates:
             *  Constant: '<S378>/const'
             *  Gain: '<S378>/Gain3'
             *  Product: '<S378>/Divide'
             *  Product: '<S378>/Multiply5'
             *  Product: '<S378>/Multiply6'
             *  Sum: '<S378>/Subtract4'
             *  Sum: '<S378>/Subtract5'
             *  Sum: '<S378>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Divide_pr_idx_2 / FMS_ConstB.d
              - rtb_Saturation_e) * FMS_ConstB.Gain4 * ((rtb_Divide_pr_idx_0 -
              rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 39.224F) * 0.004F;

            /* Product: '<S378>/Multiply1' incorporates:
             *  Constant: '<S378>/const1'
             *  DiscreteIntegrator: '<S375>/Integrator'
             */
            rtb_Divide_pr_idx_0 = FMS_DW.Integrator_DSTATE[1] * 0.1F;

            /* Sum: '<S378>/Add' incorporates:
             *  DiscreteIntegrator: '<S375>/Integrator1'
             *  Gain: '<S369>/Gain6'
             *  Sum: '<S375>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE[1] -
              FMS_PARAM.VEL_XY_LIM * rtb_Square_bg[1]) + rtb_Divide_pr_idx_0;

            /* Signum: '<S378>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
            }

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
            rtb_Divide_pr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_0;

            /* Sum: '<S378>/Add4' */
            rtb_Divide_pr_idx_0 += rtb_Divide_lr_idx_2 - rtb_Divide_pr_idx_2;

            /* Sum: '<S378>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Sum: '<S378>/Subtract1' */
            rtb_Divide_lr_idx_2 -= FMS_ConstB.d;

            /* Signum: '<S378>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S378>/Sign2' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_2 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              }
            }

            /* Sum: '<S378>/Add5' incorporates:
             *  Gain: '<S378>/Gain2'
             *  Product: '<S378>/Multiply4'
             *  Sum: '<S378>/Subtract2'
             */
            rtb_Divide_pr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S375>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S375>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S375>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S375>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S378>/Sign4' incorporates:
             *  Sum: '<S378>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S378>/Sign3' incorporates:
             *  Sum: '<S378>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S378>/Sign5' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_2;
            }

            /* Signum: '<S378>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S378>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S378>/Sign6' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Add4_o = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Add4_o = 1.0F;
            } else {
              rtb_Add4_o = rtb_Divide_pr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S375>/Integrator' incorporates:
             *  Constant: '<S378>/const'
             *  Gain: '<S378>/Gain3'
             *  Product: '<S378>/Divide'
             *  Product: '<S378>/Multiply5'
             *  Product: '<S378>/Multiply6'
             *  Sum: '<S378>/Subtract4'
             *  Sum: '<S378>/Subtract5'
             *  Sum: '<S378>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Divide_pr_idx_2 / FMS_ConstB.d
              - rtb_Saturation_e) * FMS_ConstB.Gain4 * ((rtb_Divide_pr_idx_0 -
              rtb_Divide_pr_idx_1) * 0.5F) - rtb_Add4_o * 39.224F) * 0.004F;

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
   *  DiscreteIntegrator: '<S737>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S737>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S737>/Constant'
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
  FMS_DW.Delay_DSTATE_oi = rtb_Switch_ga;

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
  /* Start for SwitchCase: '<S695>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S685>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S295>/Return' */

  /* Start for IfAction SubSystem: '<S295>/Hold' */
  /* Start for SwitchCase: '<S634>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S602>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S613>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S295>/Hold' */
  /* End of Start for SubSystem: '<S47>/SubMode' */

  /* Start for IfAction SubSystem: '<S47>/Auto' */
  /* Start for SwitchCase: '<S293>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S293>/Mission' */
  /* Start for Resettable SubSystem: '<S404>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S455>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S445>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S404>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S293>/Mission' */
  /* End of Start for SubSystem: '<S47>/Auto' */

  /* Start for IfAction SubSystem: '<S47>/Assist' */
  /* Start for SwitchCase: '<S292>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S292>/Stabilize' */
  /* Start for SwitchCase: '<S391>/Switch Case' */
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
  FMS_DW.icLoad_lf = 1U;

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
  /* InitializeConditions for Delay: '<S735>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S731>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S731>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S295>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S650>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S650>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S295>/Return' */
  /* InitializeConditions for Delay: '<S680>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S681>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S676>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S722>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S659>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S662>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_on = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S662>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S696>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S695>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S695>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S695>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S695>/Move Control' */

  /* SystemInitialize for Merge: '<S695>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S686>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S685>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S685>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S685>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S685>/Move Control' */

  /* SystemInitialize for Merge: '<S685>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S295>/Hold' */
  /* InitializeConditions for Delay: '<S615>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S627>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;
  FMS_DW.Integrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S627>/Integrator' */
  FMS_DW.Integrator_DSTATE_hi = 0.0F;
  FMS_DW.Integrator_PrevResetState = 0;

  /* SystemInitialize for Chart: '<S603>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S614>/Motion State' */
  FMS_DW.temporalCounter_i1_il = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for Chart: '<S635>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S634>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S634>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S634>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S634>/Move Control' */

  /* SystemInitialize for Merge: '<S634>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S602>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S602>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S602>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S602>/Move Control' */

  /* SystemInitialize for Merge: '<S602>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S613>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S613>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S613>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S613>/Move Control' */

  /* SystemInitialize for Merge: '<S613>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S295>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S47>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S293>/Mission' */
  /* InitializeConditions for UnitDelay: '<S407>/Delay Input1'
   *
   * Block description for '<S407>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S404>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S434>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S435>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S430>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S482>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S412>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S415>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S415>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S456>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S455>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S455>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S455>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S455>/Move Control' */

  /* SystemInitialize for Merge: '<S455>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S455>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S465>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S455>/Move Control' */

  /* SystemInitialize for Merge: '<S455>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S446>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S445>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S445>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S445>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S445>/Move Control' */

  /* SystemInitialize for Merge: '<S445>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S404>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S293>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S47>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S292>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S387>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S388>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S388>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S387>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S392>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S391>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S391>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S391>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S391>/Move Control' */

  /* SystemInitialize for Merge: '<S391>/Merge' */
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
  /* InitializeConditions for Delay: '<S368>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S366>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S366>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S366>/Move Control' */

  /* SystemInitialize for Merge: '<S366>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S366>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S375>/Integrator' */
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
