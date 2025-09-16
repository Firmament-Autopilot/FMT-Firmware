/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2533
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 15 11:08:00 2025
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

/* Named constants for Chart: '<S690>/Motion Status' */
#define FMS_IN_Brake_b                 ((uint8_T)1U)
#define FMS_IN_Hold_b                  ((uint8_T)2U)
#define FMS_IN_Move_h                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_g       ((uint8_T)0U)

/* Named constants for Chart: '<S700>/Motion State' */
#define FMS_IN_Brake_n                 ((uint8_T)1U)
#define FMS_IN_Hold_o                  ((uint8_T)2U)
#define FMS_IN_Move_o                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_a       ((uint8_T)0U)

/* Named constants for Chart: '<S396>/Motion State' */
#define FMS_IN_Brake_p                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_l                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_m       ((uint8_T)0U)

/* Named constants for Chart: '<S136>/Motion State' */
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
#define FMS_IN_StallProtect            ((uint8_T)5U)
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
struct_R5NVdknldGABThoGFgAvrE FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  1.2F,
  1.5F,
  5.0F,
  2.0F,
  2.5F,
  1.04719758F,
  0.52359879F,
  15.0F,
  5.0F,
  5.0F,
  2.0F,
  1.0F,
  0.5F,
  0.6F,
  120U,
  1U,
  1200U,
  50.0F,
  18.0F,
  22.0F,
  14.0F,
  10.0F,
  1.0F,
  10.0F,
  8.0F,
  0.785398185F,
  0.52359879F,
  0.52359879F,
  50.0F,
  0.95F,
  8.0F,
  0.52359879F,
  0.52359879F,
  1.0F,
  100.0F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S4>/Constant1'
                                        *   '<S37>/Constant'
                                        *   '<S742>/Constant1'
                                        *   '<S743>/Constant'
                                        *   '<S745>/Constant1'
                                        *   '<S746>/FW_ACCEPT_R'
                                        *   '<S746>/MC_ACCEPT_R'
                                        *   '<S749>/Constant'
                                        *   '<S48>/L1'
                                        *   '<S225>/Dead Zone'
                                        *   '<S225>/Gain'
                                        *   '<S226>/Dead Zone'
                                        *   '<S226>/Gain'
                                        *   '<S227>/Dead Zone'
                                        *   '<S227>/Gain'
                                        *   '<S228>/Dead Zone'
                                        *   '<S228>/Gain'
                                        *   '<S231>/Constant4'
                                        *   '<S232>/Constant4'
                                        *   '<S600>/L1'
                                        *   '<S95>/Gain'
                                        *   '<S96>/Gain1'
                                        *   '<S97>/Gain'
                                        *   '<S118>/Gain1'
                                        *   '<S185>/Gain'
                                        *   '<S185>/Gain1'
                                        *   '<S186>/Gain1'
                                        *   '<S234>/Gain2'
                                        *   '<S234>/Saturation1'
                                        *   '<S235>/L1'
                                        *   '<S235>/R'
                                        *   '<S235>/Saturation1'
                                        *   '<S252>/Gain'
                                        *   '<S252>/Saturation1'
                                        *   '<S274>/Gain'
                                        *   '<S274>/Saturation1'
                                        *   '<S309>/Gain'
                                        *   '<S309>/Gain1'
                                        *   '<S386>/Gain'
                                        *   '<S386>/Gain1'
                                        *   '<S388>/Constant'
                                        *   '<S412>/L1'
                                        *   '<S493>/Saturation'
                                        *   '<S494>/Saturation1'
                                        *   '<S494>/Saturation2'
                                        *   '<S494>/Saturation3'
                                        *   '<S651>/Land_Speed'
                                        *   '<S652>/Saturation1'
                                        *   '<S731>/Takeoff_Speed'
                                        *   '<S732>/Gain2'
                                        *   '<S732>/Saturation1'
                                        *   '<S98>/Saturation1'
                                        *   '<S109>/Dead Zone'
                                        *   '<S109>/Gain'
                                        *   '<S112>/Dead Zone'
                                        *   '<S112>/Gain'
                                        *   '<S121>/Saturation1'
                                        *   '<S132>/Dead Zone'
                                        *   '<S132>/Gain'
                                        *   '<S135>/Saturation1'
                                        *   '<S182>/Constant'
                                        *   '<S182>/Constant1'
                                        *   '<S182>/Constant2'
                                        *   '<S188>/Dead Zone'
                                        *   '<S188>/Gain'
                                        *   '<S189>/Dead Zone'
                                        *   '<S189>/Gain'
                                        *   '<S194>/Dead Zone'
                                        *   '<S194>/Gain'
                                        *   '<S202>/Gain'
                                        *   '<S202>/Saturation1'
                                        *   '<S203>/Constant4'
                                        *   '<S257>/L1'
                                        *   '<S257>/Saturation1'
                                        *   '<S279>/L1'
                                        *   '<S279>/Saturation1'
                                        *   '<S311>/Saturation1'
                                        *   '<S323>/Dead Zone'
                                        *   '<S323>/Gain'
                                        *   '<S324>/Dead Zone'
                                        *   '<S324>/Gain'
                                        *   '<S329>/Saturation'
                                        *   '<S345>/Saturation1'
                                        *   '<S357>/Saturation'
                                        *   '<S370>/Saturation1'
                                        *   '<S389>/Dead Zone'
                                        *   '<S389>/Gain'
                                        *   '<S390>/Dead Zone'
                                        *   '<S390>/Gain'
                                        *   '<S395>/Saturation'
                                        *   '<S549>/Gain2'
                                        *   '<S556>/Gain1'
                                        *   '<S556>/Gain2'
                                        *   '<S606>/Saturation1'
                                        *   '<S617>/Saturation'
                                        *   '<S638>/Saturation1'
                                        *   '<S653>/Constant'
                                        *   '<S656>/Gain2'
                                        *   '<S680>/Constant'
                                        *   '<S680>/vel'
                                        *   '<S680>/Acceleration_Speed'
                                        *   '<S680>/Saturation'
                                        *   '<S680>/Switch'
                                        *   '<S684>/Constant'
                                        *   '<S101>/Gain2'
                                        *   '<S102>/Gain1'
                                        *   '<S107>/Constant'
                                        *   '<S124>/Gain2'
                                        *   '<S125>/Gain1'
                                        *   '<S130>/Constant'
                                        *   '<S138>/L1'
                                        *   '<S139>/Gain6'
                                        *   '<S177>/Constant'
                                        *   '<S178>/Constant'
                                        *   '<S208>/L1'
                                        *   '<S208>/Saturation1'
                                        *   '<S314>/Gain2'
                                        *   '<S315>/Gain1'
                                        *   '<S321>/Constant'
                                        *   '<S332>/Gain2'
                                        *   '<S333>/Gain1'
                                        *   '<S340>/Constant'
                                        *   '<S348>/Gain2'
                                        *   '<S349>/Gain1'
                                        *   '<S355>/Constant'
                                        *   '<S360>/Gain2'
                                        *   '<S361>/Gain1'
                                        *   '<S368>/Constant'
                                        *   '<S372>/Gain2'
                                        *   '<S373>/Gain6'
                                        *   '<S383>/Constant'
                                        *   '<S384>/Constant'
                                        *   '<S398>/Gain2'
                                        *   '<S399>/Gain1'
                                        *   '<S406>/Constant'
                                        *   '<S431>/Gain'
                                        *   '<S431>/Saturation1'
                                        *   '<S434>/Constant'
                                        *   '<S434>/vel'
                                        *   '<S434>/Switch'
                                        *   '<S609>/Gain2'
                                        *   '<S610>/Gain1'
                                        *   '<S621>/Gain2'
                                        *   '<S622>/Gain1'
                                        *   '<S630>/Gain2'
                                        *   '<S630>/Saturation'
                                        *   '<S631>/Integrator'
                                        *   '<S641>/Gain2'
                                        *   '<S642>/Gain6'
                                        *   '<S665>/Gain2'
                                        *   '<S665>/Saturation'
                                        *   '<S666>/Integrator'
                                        *   '<S104>/Dead Zone'
                                        *   '<S104>/Gain'
                                        *   '<S127>/Dead Zone'
                                        *   '<S127>/Gain'
                                        *   '<S174>/Dead Zone'
                                        *   '<S174>/Gain'
                                        *   '<S317>/Land_Speed'
                                        *   '<S318>/Constant'
                                        *   '<S320>/Dead Zone'
                                        *   '<S320>/Gain'
                                        *   '<S337>/Dead Zone'
                                        *   '<S337>/Gain'
                                        *   '<S351>/Land_Speed'
                                        *   '<S352>/Constant'
                                        *   '<S354>/Dead Zone'
                                        *   '<S354>/Gain'
                                        *   '<S365>/Dead Zone'
                                        *   '<S365>/Gain'
                                        *   '<S377>/Dead Zone'
                                        *   '<S377>/Gain'
                                        *   '<S378>/Dead Zone'
                                        *   '<S378>/Gain'
                                        *   '<S403>/Dead Zone'
                                        *   '<S403>/Gain'
                                        *   '<S418>/Gain2'
                                        *   '<S418>/Saturation'
                                        *   '<S419>/Integrator'
                                        *   '<S612>/Dead Zone'
                                        *   '<S612>/Gain'
                                        *   '<S626>/Dead Zone'
                                        *   '<S626>/Gain'
                                        *   '<S646>/Dead Zone'
                                        *   '<S646>/Gain'
                                        *   '<S647>/Dead Zone'
                                        *   '<S647>/Gain'
                                        *   '<S689>/Saturation1'
                                        *   '<S699>/Saturation1'
                                        *   '<S449>/Saturation1'
                                        *   '<S459>/Saturation1'
                                        *   '<S692>/Gain2'
                                        *   '<S693>/Gain1'
                                        *   '<S702>/Gain2'
                                        *   '<S703>/Gain6'
                                        *   '<S452>/Gain2'
                                        *   '<S453>/Gain1'
                                        *   '<S462>/Gain2'
                                        *   '<S463>/Gain6'
                                        *   '<S695>/Dead Zone'
                                        *   '<S695>/Gain'
                                        *   '<S707>/Dead Zone'
                                        *   '<S707>/Gain'
                                        *   '<S708>/Dead Zone'
                                        *   '<S708>/Gain'
                                        *   '<S455>/Dead Zone'
                                        *   '<S455>/Gain'
                                        *   '<S467>/Dead Zone'
                                        *   '<S467>/Gain'
                                        *   '<S468>/Dead Zone'
                                        *   '<S468>/Gain'
                                        */

struct_TYt7YeNdxIDXfczXumtXXB FMS_EXPORT = {
  4U,

  { 86, 84, 79, 76, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S2>/Constant'
                                        *   '<S23>/Constant1'
                                        *   '<S741>/Constant'
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
static void FMS_Combo_Stick(void);
static boolean_T FMS_CheckModeValid(VTOLMode vtol_mode_in, VTOLState
  vtol_state_in);
static boolean_T FMS_sf_msg_pop_VTOL_M(void);
static void FMS_c11_FMS(void);
static void FMS_sf_msg_discard_M(void);
static void FMS_sf_msg_discard_VTOL_M(void);
static void initialize_msg_local_queues_for(void);

/*
 * Output and update for atomic system:
 *    '<S281>/NearbyRefWP'
 *    '<S259>/NearbyRefWP'
 *    '<S210>/NearbyRefWP'
 *    '<S682>/NearbyRefWP'
 *    '<S436>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_f, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S285>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S281>/SearchL1RefWP'
 *    '<S259>/SearchL1RefWP'
 *    '<S210>/SearchL1RefWP'
 *    '<S682>/SearchL1RefWP'
 *    '<S436>/SearchL1RefWP'
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

  /* SignalConversion: '<S287>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S259>/OutRegionRegWP'
 *    '<S210>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_p, real32_T rtu_L1, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  real32_T u_tmp;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S264>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S299>/Unknown'
 *    '<S297>/Unknown'
 *    '<S296>/Unknown'
 *    '<S47>/Unknown'
 */
void FMS_Unknown(FMS_Out_Bus *rty_FMS_Out, const ConstB_Unknown_FMS_T *localC)
{
  int32_T i;

  /* BusAssignment: '<S233>/Bus Assignment' incorporates:
   *  Constant: '<S233>/Constant'
   *  Constant: '<S233>/Constant2'
   *  SignalConversion: '<S233>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S233>/Bus Assignment' */
}

/*
 * System initialize for action system:
 *    '<S98>/Hold Control'
 *    '<S121>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S101>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S98>/Hold Control'
 *    '<S121>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S101>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S98>/Hold Control'
 *    '<S121>/Hold Control'
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
 *    '<S121>/Brake Control'
 *    '<S689>/Brake Control'
 *    '<S606>/Brake Control'
 *    '<S617>/Brake Control'
 *    '<S449>/Brake Control'
 *    '<S395>/Brake Control'
 *    '<S311>/Brake Control'
 *    '<S329>/Brake Control'
 *    '<S345>/Brake Control'
 *    '<S357>/Brake Control'
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
 *    '<S121>/Move Control'
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
 *    '<S121>/Move Control'
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
 *    '<S121>/Move Control'
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
 *    '<S122>/Motion Status'
 *    '<S312>/Motion Status'
 *    '<S346>/Motion Status'
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
 *    '<S122>/Motion Status'
 *    '<S312>/Motion Status'
 *    '<S346>/Motion Status'
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
 *    '<S122>/Motion Status'
 *    '<S312>/Motion Status'
 *    '<S346>/Motion Status'
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
 *    '<S141>/OutRegionRefWP'
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

  /* SignalConversion: '<S152>/TmpSignal ConversionAt SFunction Inport1' */
  t = (rtu_c - rtu_p0[0]) * rtu_n[0] + (rtu_c_f - rtu_p0[1]) * rtu_n[1];
  scale = 1.29246971E-26F;

  /* SignalConversion: '<S152>/TmpSignal ConversionAt SFunction Inport1' */
  absxk = fabsf((t * rtu_n[0] + rtu_p0[0]) - rtu_c);
  if (absxk > 1.29246971E-26F) {
    d1 = 1.0F;
    scale = absxk;
  } else {
    b_t = absxk / 1.29246971E-26F;
    d1 = b_t * b_t;
  }

  /* SignalConversion: '<S152>/TmpSignal ConversionAt SFunction Inport1' */
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
 *    '<S141>/SearchL1RefWP'
 *    '<S51>/SearchL1RefWP'
 */
void FMS_SearchL1RefWP_k(real32_T rtu_c, real32_T rtu_c_n, const real32_T
  rtu_p0[2], const real32_T rtu_n[2], real32_T rtu_L1, real32_T rty_P[2],
  real32_T *rty_t)
{
  real32_T B;
  real32_T m_idx_0;
  real32_T m_idx_1;

  /* SignalConversion: '<S153>/TmpSignal ConversionAt SFunction Inport1' */
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
 *    '<S689>/Hold Control'
 *    '<S606>/Hold Control'
 *    '<S449>/Hold Control'
 *    '<S311>/Hold Control'
 *    '<S345>/Hold Control'
 */
void FMS_HoldControl_o_Init(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S692>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S689>/Hold Control'
 *    '<S606>/Hold Control'
 *    '<S449>/Hold Control'
 *    '<S311>/Hold Control'
 *    '<S345>/Hold Control'
 */
void FMS_HoldControl_k_Reset(DW_HoldControl_FMS_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S692>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S689>/Hold Control'
 *    '<S606>/Hold Control'
 *    '<S449>/Hold Control'
 *    '<S311>/Hold Control'
 *    '<S345>/Hold Control'
 */
void FMS_HoldControl_e(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
  DW_HoldControl_FMS_f_T *localDW)
{
  /* Delay: '<S692>/Delay' incorporates:
   *  Gain: '<S694>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S692>/Gain2' incorporates:
   *  Delay: '<S692>/Delay'
   *  Gain: '<S694>/Gain'
   *  Sum: '<S692>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S692>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S689>/Move Control'
 *    '<S606>/Move Control'
 */
void FMS_MoveControl_b_Init(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S696>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S696>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S689>/Move Control'
 *    '<S606>/Move Control'
 */
void FMS_MoveControl_e_Reset(DW_MoveControl_FMS_e_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S696>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S696>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S689>/Move Control'
 *    '<S606>/Move Control'
 */
void FMS_MoveControl_c(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs, const
  ConstB_MoveControl_FMS_b_T *localC, DW_MoveControl_FMS_e_T *localDW)
{
  real32_T rtb_Add3_aw;
  real32_T rtb_Subtract3_d;
  real32_T rtb_a_o;
  real32_T rtb_Add4_e3;
  real32_T rtb_a_jg;

  /* Product: '<S697>/Multiply1' incorporates:
   *  Constant: '<S697>/const1'
   *  DiscreteIntegrator: '<S696>/Integrator'
   */
  rtb_Add3_aw = localDW->Integrator_DSTATE * 0.05F;

  /* DeadZone: '<S695>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_a_o = 0.0F;
  } else {
    rtb_a_o = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S695>/Dead Zone' */

  /* Sum: '<S697>/Add' incorporates:
   *  DiscreteIntegrator: '<S696>/Integrator1'
   *  Gain: '<S693>/Gain1'
   *  Gain: '<S695>/Gain'
   *  Sum: '<S696>/Subtract'
   */
  rtb_Subtract3_d = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.THROTTLE_DZ) * rtb_a_o * -FMS_PARAM.VEL_Z_LIM) + rtb_Add3_aw;

  /* Signum: '<S697>/Sign' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_a_o = -1.0F;
  } else if (rtb_Subtract3_d > 0.0F) {
    rtb_a_o = 1.0F;
  } else {
    rtb_a_o = rtb_Subtract3_d;
  }

  /* End of Signum: '<S697>/Sign' */

  /* Sum: '<S697>/Add2' incorporates:
   *  Abs: '<S697>/Abs'
   *  Gain: '<S697>/Gain'
   *  Gain: '<S697>/Gain1'
   *  Product: '<S697>/Multiply2'
   *  Product: '<S697>/Multiply3'
   *  Sqrt: '<S697>/Sqrt'
   *  Sum: '<S697>/Add1'
   *  Sum: '<S697>/Subtract'
   */
  rtb_a_o = (sqrtf((8.0F * fabsf(rtb_Subtract3_d) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_o + rtb_Add3_aw;

  /* Sum: '<S697>/Add4' */
  rtb_Add4_e3 = (rtb_Subtract3_d - rtb_a_o) + rtb_Add3_aw;

  /* Sum: '<S697>/Add3' */
  rtb_Add3_aw = rtb_Subtract3_d + localC->d;

  /* Sum: '<S697>/Subtract1' */
  rtb_Subtract3_d -= localC->d;

  /* Signum: '<S697>/Sign1' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S697>/Sign1' */

  /* Signum: '<S697>/Sign2' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S697>/Sign2' */

  /* Sum: '<S697>/Add5' incorporates:
   *  Gain: '<S697>/Gain2'
   *  Product: '<S697>/Multiply4'
   *  Sum: '<S697>/Subtract2'
   */
  rtb_a_o += (rtb_Add3_aw - rtb_Subtract3_d) * 0.5F * rtb_Add4_e3;

  /* SignalConversion: '<S696>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S696>/Integrator1'
   */
  *rty_w_cmd_mPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S696>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S696>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S697>/Add6' */
  rtb_Add3_aw = rtb_a_o + localC->d;

  /* Sum: '<S697>/Subtract3' */
  rtb_Subtract3_d = rtb_a_o - localC->d;

  /* Signum: '<S697>/Sign5' */
  if (rtb_a_o < 0.0F) {
    rtb_Add4_e3 = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_Add4_e3 = 1.0F;
  } else {
    rtb_Add4_e3 = rtb_a_o;
  }

  /* End of Signum: '<S697>/Sign5' */

  /* Signum: '<S697>/Sign3' */
  if (rtb_Add3_aw < 0.0F) {
    rtb_Add3_aw = -1.0F;
  } else {
    if (rtb_Add3_aw > 0.0F) {
      rtb_Add3_aw = 1.0F;
    }
  }

  /* End of Signum: '<S697>/Sign3' */

  /* Signum: '<S697>/Sign4' */
  if (rtb_Subtract3_d < 0.0F) {
    rtb_Subtract3_d = -1.0F;
  } else {
    if (rtb_Subtract3_d > 0.0F) {
      rtb_Subtract3_d = 1.0F;
    }
  }

  /* End of Signum: '<S697>/Sign4' */

  /* Signum: '<S697>/Sign6' */
  if (rtb_a_o < 0.0F) {
    rtb_a_jg = -1.0F;
  } else if (rtb_a_o > 0.0F) {
    rtb_a_jg = 1.0F;
  } else {
    rtb_a_jg = rtb_a_o;
  }

  /* End of Signum: '<S697>/Sign6' */

  /* Update for DiscreteIntegrator: '<S696>/Integrator' incorporates:
   *  Constant: '<S697>/const'
   *  Gain: '<S697>/Gain3'
   *  Product: '<S697>/Divide'
   *  Product: '<S697>/Multiply5'
   *  Product: '<S697>/Multiply6'
   *  Sum: '<S697>/Subtract4'
   *  Sum: '<S697>/Subtract5'
   *  Sum: '<S697>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_o / localC->d - rtb_Add4_e3) *
    localC->Gain4 * ((rtb_Add3_aw - rtb_Subtract3_d) * 0.5F) - rtb_a_jg *
    78.448F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S690>/Motion Status'
 *    '<S607>/Motion Status'
 *    '<S450>/Motion Status'
 */
void FMS_MotionStatus_a_Init(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * System reset for atomic system:
 *    '<S690>/Motion Status'
 *    '<S607>/Motion Status'
 *    '<S450>/Motion Status'
 */
void FMS_MotionStatus_f_Reset(DW_MotionStatus_FMS_p_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c1_FMS = 0U;
  localDW->is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_g;
}

/*
 * Output and update for atomic system:
 *    '<S690>/Motion Status'
 *    '<S607>/Motion Status'
 *    '<S450>/Motion Status'
 */
void FMS_MotionStatus_g(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionStatus_FMS_p_T *localDW)
{
  /* Chart: '<S690>/Motion Status' */
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

  /* End of Chart: '<S690>/Motion Status' */
}

/*
 * System initialize for action system:
 *    '<S699>/Hold Control'
 *    '<S638>/Hold Control'
 *    '<S459>/Hold Control'
 */
void FMS_HoldControl_l_Init(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S702>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S699>/Hold Control'
 *    '<S638>/Hold Control'
 *    '<S459>/Hold Control'
 */
void FMS_HoldControl_i_Reset(DW_HoldControl_FMS_m_T *localDW)
{
  /* InitializeConditions for Delay: '<S702>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S699>/Hold Control'
 *    '<S638>/Hold Control'
 *    '<S459>/Hold Control'
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

  /* Delay: '<S702>/Delay' incorporates:
   *  SignalConversion: '<S702>/TmpSignal ConversionAtDelayInport2'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE[0] = rtu_FMS_In;
    localDW->Delay_DSTATE[1] = rtu_FMS_In_g;
  }

  /* Trigonometry: '<S706>/Trigonometric Function1' incorporates:
   *  Gain: '<S705>/Gain'
   *  Trigonometry: '<S706>/Trigonometric Function3'
   */
  rtb_VectorConcatenate_d_tmp_0 = arm_cos_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[0] = rtb_VectorConcatenate_d_tmp_0;

  /* Trigonometry: '<S706>/Trigonometric Function' incorporates:
   *  Gain: '<S705>/Gain'
   *  Trigonometry: '<S706>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d_tmp = arm_sin_f32(-rtu_FMS_In_d);
  rtb_VectorConcatenate_al[1] = rtb_VectorConcatenate_d_tmp;

  /* SignalConversion: '<S706>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S706>/Constant3'
   */
  rtb_VectorConcatenate_al[2] = 0.0F;

  /* Gain: '<S706>/Gain' */
  rtb_VectorConcatenate_al[3] = -rtb_VectorConcatenate_d_tmp;

  /* Trigonometry: '<S706>/Trigonometric Function3' */
  rtb_VectorConcatenate_al[4] = rtb_VectorConcatenate_d_tmp_0;

  /* SignalConversion: '<S706>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S706>/Constant4'
   */
  rtb_VectorConcatenate_al[5] = 0.0F;

  /* SignalConversion: '<S706>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_al[6] = localC->VectorConcatenate3[0];
  rtb_VectorConcatenate_al[7] = localC->VectorConcatenate3[1];
  rtb_VectorConcatenate_al[8] = localC->VectorConcatenate3[2];

  /* SignalConversion: '<S702>/TmpSignal ConversionAtMultiplyInport2' incorporates:
   *  Delay: '<S702>/Delay'
   *  SignalConversion: '<S702>/TmpSignal ConversionAtDelayInport2'
   *  Sum: '<S702>/Sum'
   */
  rtb_VectorConcatenate_d_tmp_0 = localDW->Delay_DSTATE[0] - rtu_FMS_In;
  rtb_VectorConcatenate_d_tmp = localDW->Delay_DSTATE[1] - rtu_FMS_In_g;

  /* Product: '<S702>/Multiply' incorporates:
   *  SignalConversion: '<S702>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = rtb_VectorConcatenate_al[i + 3] *
      rtb_VectorConcatenate_d_tmp + rtb_VectorConcatenate_al[i] *
      rtb_VectorConcatenate_d_tmp_0;
  }

  /* End of Product: '<S702>/Multiply' */

  /* Gain: '<S702>/Gain2' */
  rty_uv_cmd_mPs[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[0];
  rty_uv_cmd_mPs[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_d[1];

  /* Update for Delay: '<S702>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S699>/Brake Control'
 *    '<S638>/Brake Control'
 *    '<S459>/Brake Control'
 */
void FMS_BrakeControl_e(real32_T rty_uv_cmd_mPs[2])
{
  /* SignalConversion: '<S701>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
  rty_uv_cmd_mPs[0] = 0.0F;
  rty_uv_cmd_mPs[1] = 0.0F;
}

/*
 * System initialize for action system:
 *    '<S699>/Move Control'
 *    '<S638>/Move Control'
 */
void FMS_MoveControl_f_Init(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S709>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S709>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S709>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S709>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * System reset for action system:
 *    '<S699>/Move Control'
 *    '<S638>/Move Control'
 */
void FMS_MoveControl_l_Reset(DW_MoveControl_FMS_l_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S709>/Integrator' */
  localDW->Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S709>/Integrator1' */
  localDW->Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S709>/Integrator' */
  localDW->Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S709>/Integrator1' */
  localDW->Integrator1_DSTATE[1] = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S699>/Move Control'
 *    '<S638>/Move Control'
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

  /* DiscreteIntegrator: '<S709>/Integrator' */
  rtb_v2_ew_idx_0 = localDW->Integrator_DSTATE[0];

  /* Product: '<S710>/Multiply1' incorporates:
   *  Constant: '<S710>/const1'
   *  DiscreteIntegrator: '<S709>/Integrator'
   */
  rtb_Add3_l_idx_0 = localDW->Integrator_DSTATE[0] * 0.05F;

  /* DiscreteIntegrator: '<S709>/Integrator' */
  rtb_v2_ew_idx_1 = localDW->Integrator_DSTATE[1];

  /* Product: '<S710>/Multiply1' incorporates:
   *  Constant: '<S710>/const1'
   *  DiscreteIntegrator: '<S709>/Integrator'
   */
  rtb_Add3_l_idx_1 = localDW->Integrator_DSTATE[1] * 0.05F;

  /* DeadZone: '<S707>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S707>/Dead Zone' */

  /* Sum: '<S710>/Add' incorporates:
   *  DiscreteIntegrator: '<S709>/Integrator1'
   *  Gain: '<S703>/Gain6'
   *  Gain: '<S707>/Gain'
   *  Sum: '<S709>/Subtract'
   */
  rtb_Subtract3_p_idx_0 = (localDW->Integrator1_DSTATE[0] - 1.0F / (1.0F -
    FMS_PARAM.PITCH_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_0;

  /* DeadZone: '<S708>/Dead Zone' */
  if (rtu_FMS_In_h > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - FMS_PARAM.ROLL_DZ;
  } else if (rtu_FMS_In_h >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract3_p_idx_1 = 0.0F;
  } else {
    rtb_Subtract3_p_idx_1 = rtu_FMS_In_h - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S708>/Dead Zone' */

  /* Sum: '<S710>/Add' incorporates:
   *  DiscreteIntegrator: '<S709>/Integrator1'
   *  Gain: '<S703>/Gain6'
   *  Gain: '<S708>/Gain'
   *  Sum: '<S709>/Subtract'
   */
  rtb_Subtract3_p_idx_1 = (localDW->Integrator1_DSTATE[1] - 1.0F / (1.0F -
    FMS_PARAM.ROLL_DZ) * rtb_Subtract3_p_idx_1 * FMS_PARAM.VEL_XY_LIM) +
    rtb_Add3_l_idx_1;

  /* Signum: '<S710>/Sign' */
  if (rtb_Subtract3_p_idx_0 < 0.0F) {
    rtb_Subtract3_p_idx_0_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0 > 0.0F) {
    rtb_Subtract3_p_idx_0_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0_0 = rtb_Subtract3_p_idx_0;
  }

  /* Sum: '<S710>/Add2' incorporates:
   *  Abs: '<S710>/Abs'
   *  Gain: '<S710>/Gain'
   *  Gain: '<S710>/Gain1'
   *  Product: '<S710>/Multiply2'
   *  Product: '<S710>/Multiply3'
   *  Signum: '<S710>/Sign'
   *  Sqrt: '<S710>/Sqrt'
   *  Sum: '<S710>/Add1'
   *  Sum: '<S710>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_0) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_Subtract3_p_idx_0_0 +
    rtb_Add3_l_idx_0;

  /* Sum: '<S710>/Add3' incorporates:
   *  Signum: '<S710>/Sign'
   */
  u = rtb_Subtract3_p_idx_0 + localC->d;

  /* Sum: '<S710>/Subtract1' incorporates:
   *  Signum: '<S710>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_0 - localC->d;

  /* Signum: '<S710>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S710>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S710>/Add5' incorporates:
   *  Gain: '<S710>/Gain2'
   *  Product: '<S710>/Multiply4'
   *  Signum: '<S710>/Sign'
   *  Sum: '<S710>/Add2'
   *  Sum: '<S710>/Add4'
   *  Sum: '<S710>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_0 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_0) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S709>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S709>/Integrator1'
   */
  rty_uv_cmd_mPs[0] = localDW->Integrator1_DSTATE[0];

  /* Signum: '<S710>/Sign3' incorporates:
   *  Sum: '<S710>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S710>/Sign4' incorporates:
   *  Sum: '<S710>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S710>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S710>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S710>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S710>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S709>/Integrator' incorporates:
   *  Constant: '<S710>/const'
   *  Gain: '<S710>/Gain3'
   *  Product: '<S710>/Divide'
   *  Product: '<S710>/Multiply5'
   *  Product: '<S710>/Multiply6'
   *  Sum: '<S710>/Subtract4'
   *  Sum: '<S710>/Subtract5'
   *  Sum: '<S710>/Subtract6'
   */
  localDW->Integrator_DSTATE[0] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S709>/Integrator1' */
  localDW->Integrator1_DSTATE[0] += 0.004F * rtb_v2_ew_idx_0;

  /* Signum: '<S710>/Sign' */
  if (rtb_Subtract3_p_idx_1 < 0.0F) {
    rtb_v2_ew_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_1 > 0.0F) {
    rtb_v2_ew_idx_0 = 1.0F;
  } else {
    rtb_v2_ew_idx_0 = rtb_Subtract3_p_idx_1;
  }

  /* Sum: '<S710>/Add2' incorporates:
   *  Abs: '<S710>/Abs'
   *  Gain: '<S710>/Gain'
   *  Gain: '<S710>/Gain1'
   *  Product: '<S710>/Multiply2'
   *  Product: '<S710>/Multiply3'
   *  Signum: '<S710>/Sign'
   *  Sqrt: '<S710>/Sqrt'
   *  Sum: '<S710>/Add1'
   *  Sum: '<S710>/Subtract'
   */
  rtb_Subtract3_p_idx_0_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_p_idx_1) +
    localC->d) * localC->d) - localC->d) * 0.5F * rtb_v2_ew_idx_0 +
    rtb_Add3_l_idx_1;

  /* Sum: '<S710>/Add3' incorporates:
   *  Signum: '<S710>/Sign'
   */
  u = rtb_Subtract3_p_idx_1 + localC->d;

  /* Sum: '<S710>/Subtract1' incorporates:
   *  Signum: '<S710>/Sign'
   */
  rtb_Subtract3_jp = rtb_Subtract3_p_idx_1 - localC->d;

  /* Signum: '<S710>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S710>/Sign2' */
  if (rtb_Subtract3_jp < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else {
    if (rtb_Subtract3_jp > 0.0F) {
      rtb_Subtract3_jp = 1.0F;
    }
  }

  /* Sum: '<S710>/Add5' incorporates:
   *  Gain: '<S710>/Gain2'
   *  Product: '<S710>/Multiply4'
   *  Signum: '<S710>/Sign'
   *  Sum: '<S710>/Add2'
   *  Sum: '<S710>/Add4'
   *  Sum: '<S710>/Subtract2'
   */
  rtb_Subtract3_p_idx_0_0 += ((rtb_Subtract3_p_idx_1 - rtb_Subtract3_p_idx_0_0)
    + rtb_Add3_l_idx_1) * ((u - rtb_Subtract3_jp) * 0.5F);

  /* SignalConversion: '<S709>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S709>/Integrator1'
   */
  rty_uv_cmd_mPs[1] = localDW->Integrator1_DSTATE[1];

  /* Signum: '<S710>/Sign3' incorporates:
   *  Sum: '<S710>/Add6'
   */
  u = rtb_Subtract3_p_idx_0_0 + localC->d;

  /* Signum: '<S710>/Sign4' incorporates:
   *  Sum: '<S710>/Subtract3'
   */
  rtb_Add3_l_idx_0 = rtb_Subtract3_p_idx_0_0 - localC->d;

  /* Signum: '<S710>/Sign5' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_p_idx_0 = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_p_idx_0 = 1.0F;
  } else {
    rtb_Subtract3_p_idx_0 = rtb_Subtract3_p_idx_0_0;
  }

  /* Signum: '<S710>/Sign3' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* Signum: '<S710>/Sign4' */
  if (rtb_Add3_l_idx_0 < 0.0F) {
    rtb_Add3_l_idx_0 = -1.0F;
  } else {
    if (rtb_Add3_l_idx_0 > 0.0F) {
      rtb_Add3_l_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S710>/Sign6' */
  if (rtb_Subtract3_p_idx_0_0 < 0.0F) {
    rtb_Subtract3_jp = -1.0F;
  } else if (rtb_Subtract3_p_idx_0_0 > 0.0F) {
    rtb_Subtract3_jp = 1.0F;
  } else {
    rtb_Subtract3_jp = rtb_Subtract3_p_idx_0_0;
  }

  /* Update for DiscreteIntegrator: '<S709>/Integrator' incorporates:
   *  Constant: '<S710>/const'
   *  Gain: '<S710>/Gain3'
   *  Product: '<S710>/Divide'
   *  Product: '<S710>/Multiply5'
   *  Product: '<S710>/Multiply6'
   *  Sum: '<S710>/Subtract4'
   *  Sum: '<S710>/Subtract5'
   *  Sum: '<S710>/Subtract6'
   */
  localDW->Integrator_DSTATE[1] += ((rtb_Subtract3_p_idx_0_0 / localC->d -
    rtb_Subtract3_p_idx_0) * localC->Gain4 * ((u - rtb_Add3_l_idx_0) * 0.5F) -
    rtb_Subtract3_jp * 58.836F) * 0.004F;

  /* Update for DiscreteIntegrator: '<S709>/Integrator1' */
  localDW->Integrator1_DSTATE[1] += 0.004F * rtb_v2_ew_idx_1;
}

/*
 * System initialize for atomic system:
 *    '<S700>/Motion State'
 *    '<S639>/Motion State'
 *    '<S460>/Motion State'
 */
void FMS_MotionState_Init(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * System reset for atomic system:
 *    '<S700>/Motion State'
 *    '<S639>/Motion State'
 *    '<S460>/Motion State'
 */
void FMS_MotionState_Reset(DW_MotionState_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c2_FMS = 0U;
  localDW->is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_a;
}

/*
 * Output and update for atomic system:
 *    '<S700>/Motion State'
 *    '<S639>/Motion State'
 *    '<S460>/Motion State'
 */
void FMS_MotionState(real32_T rtu_motion_req, real32_T rtu_speed, MotionState
                     *rty_state, DW_MotionState_FMS_T *localDW)
{
  /* Chart: '<S700>/Motion State' */
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

  /* End of Chart: '<S700>/Motion State' */
}

/*
 * Output and update for atomic system:
 *    '<S682>/OutRegionRegWP'
 *    '<S436>/OutRegionRegWP'
 */
void FMS_OutRegionRegWP_c(const real32_T rtu_P1[2], const real32_T rtu_P2[2],
  real32_T rtu_P3, real32_T rtu_P3_g, real32_T rty_P[2])
{
  real32_T P1P3_idx_0;
  real32_T P1P3_idx_1;
  rty_P[0] = rtu_P2[0] - rtu_P1[0];
  rty_P[1] = rtu_P2[1] - rtu_P1[1];

  /* SignalConversion: '<S715>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S617>/Hold Control'
 *    '<S395>/Hold Control'
 *    '<S329>/Hold Control'
 *    '<S357>/Hold Control'
 */
void FMS_HoldControl_d_Init(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S621>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S617>/Hold Control'
 *    '<S395>/Hold Control'
 *    '<S329>/Hold Control'
 *    '<S357>/Hold Control'
 */
void FMS_HoldControl_o_Reset(DW_HoldControl_FMS_c_T *localDW)
{
  /* InitializeConditions for Delay: '<S621>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S617>/Hold Control'
 *    '<S395>/Hold Control'
 *    '<S329>/Hold Control'
 *    '<S357>/Hold Control'
 */
void FMS_HoldControl_f(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  DW_HoldControl_FMS_c_T *localDW)
{
  real32_T rtb_psi_error_rad;
  real32_T rtb_Abs_cp;

  /* Delay: '<S621>/Delay' */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = rtu_FMS_In;
  }

  /* Sum: '<S621>/Sum' incorporates:
   *  Delay: '<S621>/Delay'
   */
  rtb_psi_error_rad = localDW->Delay_DSTATE - rtu_FMS_In;

  /* Abs: '<S624>/Abs' */
  rtb_Abs_cp = fabsf(rtb_psi_error_rad);

  /* Switch: '<S624>/Switch' incorporates:
   *  Constant: '<S624>/Constant'
   *  Constant: '<S625>/Constant'
   *  Product: '<S624>/Multiply'
   *  RelationalOperator: '<S625>/Compare'
   *  Sum: '<S624>/Subtract'
   */
  if (rtb_Abs_cp > 3.14159274F) {
    /* Signum: '<S624>/Sign' */
    if (rtb_psi_error_rad < 0.0F) {
      rtb_psi_error_rad = -1.0F;
    } else {
      if (rtb_psi_error_rad > 0.0F) {
        rtb_psi_error_rad = 1.0F;
      }
    }

    /* End of Signum: '<S624>/Sign' */
    rtb_psi_error_rad *= rtb_Abs_cp - 6.28318548F;
  }

  /* End of Switch: '<S624>/Switch' */

  /* Gain: '<S621>/Gain2' */
  *rty_psi_rate_cmd_radPs = FMS_PARAM.YAW_P * rtb_psi_error_rad;

  /* Update for Delay: '<S621>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * System initialize for action system:
 *    '<S617>/Move Control'
 *    '<S395>/Move Control'
 *    '<S329>/Move Control'
 *    '<S357>/Move Control'
 */
void FMS_MoveControl_i_Init(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S627>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S627>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * System reset for action system:
 *    '<S617>/Move Control'
 *    '<S395>/Move Control'
 *    '<S329>/Move Control'
 *    '<S357>/Move Control'
 */
void FMS_MoveControl_m_Reset(DW_MoveControl_FMS_g_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S627>/Integrator1' */
  localDW->Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S627>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
}

/*
 * Output and update for action system:
 *    '<S617>/Move Control'
 *    '<S395>/Move Control'
 *    '<S329>/Move Control'
 *    '<S357>/Move Control'
 */
void FMS_MoveControl_a(real32_T rtu_FMS_In, real32_T *rty_psi_rate_cmd_radPs,
  const ConstB_MoveControl_FMS_e_T *localC, DW_MoveControl_FMS_g_T *localDW)
{
  real32_T rtb_Add3_mb;
  real32_T rtb_Subtract3_e;
  real32_T rtb_a_h;
  real32_T rtb_Add4_e;
  real32_T rtb_a_g;

  /* Product: '<S628>/Multiply1' incorporates:
   *  Constant: '<S628>/const1'
   *  DiscreteIntegrator: '<S627>/Integrator'
   */
  rtb_Add3_mb = localDW->Integrator_DSTATE * 0.02F;

  /* DeadZone: '<S626>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.YAW_DZ) {
    rtb_a_h = rtu_FMS_In - FMS_PARAM.YAW_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.YAW_DZ) {
    rtb_a_h = 0.0F;
  } else {
    rtb_a_h = rtu_FMS_In - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S626>/Dead Zone' */

  /* Sum: '<S628>/Add' incorporates:
   *  DiscreteIntegrator: '<S627>/Integrator1'
   *  Gain: '<S622>/Gain1'
   *  Gain: '<S626>/Gain'
   *  Sum: '<S627>/Subtract'
   */
  rtb_Subtract3_e = (localDW->Integrator1_DSTATE - 1.0F / (1.0F -
    FMS_PARAM.YAW_DZ) * rtb_a_h * FMS_PARAM.YAW_RATE_LIM) + rtb_Add3_mb;

  /* Signum: '<S628>/Sign' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_a_h = -1.0F;
  } else if (rtb_Subtract3_e > 0.0F) {
    rtb_a_h = 1.0F;
  } else {
    rtb_a_h = rtb_Subtract3_e;
  }

  /* End of Signum: '<S628>/Sign' */

  /* Sum: '<S628>/Add2' incorporates:
   *  Abs: '<S628>/Abs'
   *  Gain: '<S628>/Gain'
   *  Gain: '<S628>/Gain1'
   *  Product: '<S628>/Multiply2'
   *  Product: '<S628>/Multiply3'
   *  Sqrt: '<S628>/Sqrt'
   *  Sum: '<S628>/Add1'
   *  Sum: '<S628>/Subtract'
   */
  rtb_a_h = (sqrtf((8.0F * fabsf(rtb_Subtract3_e) + localC->d) * localC->d) -
             localC->d) * 0.5F * rtb_a_h + rtb_Add3_mb;

  /* Sum: '<S628>/Add4' */
  rtb_Add4_e = (rtb_Subtract3_e - rtb_a_h) + rtb_Add3_mb;

  /* Sum: '<S628>/Add3' */
  rtb_Add3_mb = rtb_Subtract3_e + localC->d;

  /* Sum: '<S628>/Subtract1' */
  rtb_Subtract3_e -= localC->d;

  /* Signum: '<S628>/Sign1' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S628>/Sign1' */

  /* Signum: '<S628>/Sign2' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S628>/Sign2' */

  /* Sum: '<S628>/Add5' incorporates:
   *  Gain: '<S628>/Gain2'
   *  Product: '<S628>/Multiply4'
   *  Sum: '<S628>/Subtract2'
   */
  rtb_a_h += (rtb_Add3_mb - rtb_Subtract3_e) * 0.5F * rtb_Add4_e;

  /* SignalConversion: '<S627>/Signal Copy' incorporates:
   *  DiscreteIntegrator: '<S627>/Integrator1'
   */
  *rty_psi_rate_cmd_radPs = localDW->Integrator1_DSTATE;

  /* Update for DiscreteIntegrator: '<S627>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S627>/Integrator'
   */
  localDW->Integrator1_DSTATE += 0.004F * localDW->Integrator_DSTATE;

  /* Sum: '<S628>/Add6' */
  rtb_Add3_mb = rtb_a_h + localC->d;

  /* Sum: '<S628>/Subtract3' */
  rtb_Subtract3_e = rtb_a_h - localC->d;

  /* Signum: '<S628>/Sign5' */
  if (rtb_a_h < 0.0F) {
    rtb_Add4_e = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_Add4_e = 1.0F;
  } else {
    rtb_Add4_e = rtb_a_h;
  }

  /* End of Signum: '<S628>/Sign5' */

  /* Signum: '<S628>/Sign3' */
  if (rtb_Add3_mb < 0.0F) {
    rtb_Add3_mb = -1.0F;
  } else {
    if (rtb_Add3_mb > 0.0F) {
      rtb_Add3_mb = 1.0F;
    }
  }

  /* End of Signum: '<S628>/Sign3' */

  /* Signum: '<S628>/Sign4' */
  if (rtb_Subtract3_e < 0.0F) {
    rtb_Subtract3_e = -1.0F;
  } else {
    if (rtb_Subtract3_e > 0.0F) {
      rtb_Subtract3_e = 1.0F;
    }
  }

  /* End of Signum: '<S628>/Sign4' */

  /* Signum: '<S628>/Sign6' */
  if (rtb_a_h < 0.0F) {
    rtb_a_g = -1.0F;
  } else if (rtb_a_h > 0.0F) {
    rtb_a_g = 1.0F;
  } else {
    rtb_a_g = rtb_a_h;
  }

  /* End of Signum: '<S628>/Sign6' */

  /* Update for DiscreteIntegrator: '<S627>/Integrator' incorporates:
   *  Constant: '<S628>/const'
   *  Gain: '<S628>/Gain3'
   *  Product: '<S628>/Divide'
   *  Product: '<S628>/Multiply5'
   *  Product: '<S628>/Multiply6'
   *  Sum: '<S628>/Subtract4'
   *  Sum: '<S628>/Subtract5'
   *  Sum: '<S628>/Subtract6'
   */
  localDW->Integrator_DSTATE += ((rtb_a_h / localC->d - rtb_Add4_e) *
    localC->Gain4 * ((rtb_Add3_mb - rtb_Subtract3_e) * 0.5F) - rtb_a_g *
    15.707963F) * 0.004F;
}

/*
 * System initialize for atomic system:
 *    '<S396>/Motion State'
 *    '<S330>/Motion State'
 *    '<S358>/Motion State'
 */
void FMS_MotionState_f_Init(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * System reset for atomic system:
 *    '<S396>/Motion State'
 *    '<S330>/Motion State'
 *    '<S358>/Motion State'
 */
void FMS_MotionState_g_Reset(DW_MotionState_FMS_i_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c19_FMS = 0U;
  localDW->is_c19_FMS = FMS_IN_NO_ACTIVE_CHILD_m;
}

/*
 * Output and update for atomic system:
 *    '<S396>/Motion State'
 *    '<S330>/Motion State'
 *    '<S358>/Motion State'
 */
void FMS_MotionState_m(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState
  *rty_state, DW_MotionState_FMS_i_T *localDW)
{
  /* Chart: '<S396>/Motion State' */
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

  /* End of Chart: '<S396>/Motion State' */
}

/*
 * Output and update for action system:
 *    '<S311>/Move Control'
 *    '<S345>/Move Control'
 */
void FMS_MoveControl_g(real32_T rtu_FMS_In, real32_T rtu_FMS_In_b, uint32_T
  rtu_FMS_In_o, real32_T *rty_w_cmd_mPs)
{
  real32_T rtb_Gain1_fk;

  /* DeadZone: '<S320>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = rtu_FMS_In - FMS_PARAM.THROTTLE_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Gain1_fk = 0.0F;
  } else {
    rtb_Gain1_fk = rtu_FMS_In - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S320>/Dead Zone' */

  /* Gain: '<S315>/Gain1' incorporates:
   *  Gain: '<S320>/Gain'
   */
  rtb_Gain1_fk = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Gain1_fk *
    -FMS_PARAM.VEL_Z_LIM;

  /* Switch: '<S315>/Switch' incorporates:
   *  Constant: '<S317>/Land_Speed'
   *  Constant: '<S318>/Constant'
   *  Constant: '<S319>/Constant'
   *  Gain: '<S317>/Gain'
   *  Logic: '<S315>/Logical Operator'
   *  MinMax: '<S317>/Min'
   *  RelationalOperator: '<S318>/Compare'
   *  RelationalOperator: '<S319>/Compare'
   *  S-Function (sfix_bitop): '<S315>/cmd_p valid'
   */
  if ((rtb_Gain1_fk > 0.0F) && ((rtu_FMS_In_o & 256U) != 0U) && (rtu_FMS_In_b <=
       FMS_PARAM.ASSIST_LAND_H)) {
    *rty_w_cmd_mPs = 0.5F * fminf(FMS_PARAM.LAND_SPEED, rtb_Gain1_fk);
  } else {
    *rty_w_cmd_mPs = rtb_Gain1_fk;
  }

  /* End of Switch: '<S315>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.AcceptRadius' */
void FMS_VehicleAcceptRadius(VTOLState rtu_state, real32_T *rty_radius)
{
  /* Switch: '<S746>/Switch' incorporates:
   *  Constant: '<S746>/FW_ACCEPT_R'
   *  Constant: '<S746>/MC_ACCEPT_R'
   *  Constant: '<S753>/Constant'
   *  RelationalOperator: '<S753>/Compare'
   */
  if (rtu_state == VTOLState_Multicopter) {
    *rty_radius = FMS_PARAM.MC_ACCEPT_R;
  } else {
    *rty_radius = FMS_PARAM.FW_ACCEPT_R;
  }

  /* End of Switch: '<S746>/Switch' */
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

  /* Math: '<S764>/Rem' incorporates:
   *  Constant: '<S764>/Constant1'
   *  Sum: '<S748>/Sum'
   */
  rtb_Rem_h = rt_remf(rtu_psi_cmd - rtu_psi_est, 6.28318548F);

  /* Switch: '<S764>/Switch' incorporates:
   *  Abs: '<S764>/Abs'
   *  Constant: '<S764>/Constant'
   *  Constant: '<S765>/Constant'
   *  Product: '<S764>/Multiply'
   *  RelationalOperator: '<S765>/Compare'
   *  Sum: '<S764>/Add'
   */
  if (fabsf(rtb_Rem_h) > 3.14159274F) {
    /* Signum: '<S764>/Sign' */
    if (rtb_Rem_h < 0.0F) {
      rtb_Rem_h_0 = -1.0F;
    } else if (rtb_Rem_h > 0.0F) {
      rtb_Rem_h_0 = 1.0F;
    } else {
      rtb_Rem_h_0 = rtb_Rem_h;
    }

    /* End of Signum: '<S764>/Sign' */
    *rty_err = rtb_Rem_h - 6.28318548F * rtb_Rem_h_0;
  } else {
    *rty_err = rtb_Rem_h;
  }

  /* End of Switch: '<S764>/Switch' */
}

/* Output and update for function-call system: '<S6>/Vehicle.WaypointAngle' */
void FMS_VehicleWaypointAngle(const real32_T rtu_start[3], const real32_T
  rtu_end[3], real32_T *rty_angle, const ConstB_VehicleWaypointAngle_F_T *localC)
{
  real32_T rtb_Switch2_b;
  real32_T rtb_Divide_cw_idx_1;
  real32_T rtb_Divide_cw_idx_0;
  real32_T rtb_Switch_a_idx_1;

  /* Sum: '<S751>/Sum' */
  rtb_Divide_cw_idx_0 = rtu_end[0] - rtu_start[0];
  rtb_Divide_cw_idx_1 = rtu_end[1] - rtu_start[1];

  /* Sum: '<S770>/Sum of Elements' incorporates:
   *  Math: '<S770>/Math Function'
   *  SignalConversion: '<S770>/TmpSignal ConversionAtMath FunctionInport1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_1 * rtb_Divide_cw_idx_1 +
    rtb_Divide_cw_idx_0 * rtb_Divide_cw_idx_0;

  /* Math: '<S770>/Math Function1' incorporates:
   *  Sum: '<S770>/Sum of Elements'
   *
   * About '<S770>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -sqrtf(fabsf(rtb_Switch2_b));
  } else {
    rtb_Switch2_b = sqrtf(rtb_Switch2_b);
  }

  /* End of Math: '<S770>/Math Function1' */

  /* Switch: '<S770>/Switch' incorporates:
   *  Constant: '<S770>/Constant'
   *  Product: '<S770>/Product'
   */
  if (rtb_Switch2_b > 0.0F) {
    rtb_Switch_a_idx_1 = rtb_Divide_cw_idx_0;
  } else {
    rtb_Divide_cw_idx_1 = 0.0F;
    rtb_Switch_a_idx_1 = 0.0F;
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S770>/Switch' */

  /* Product: '<S770>/Divide' */
  rtb_Divide_cw_idx_0 = rtb_Divide_cw_idx_1 / rtb_Switch2_b;
  rtb_Divide_cw_idx_1 = rtb_Switch_a_idx_1 / rtb_Switch2_b;

  /* Sum: '<S768>/Subtract' incorporates:
   *  Product: '<S768>/Multiply'
   *  Product: '<S768>/Multiply1'
   */
  rtb_Switch2_b = rtb_Divide_cw_idx_0 * localC->Divide[1] - rtb_Divide_cw_idx_1 *
    localC->Divide[0];

  /* Signum: '<S767>/Sign1' */
  if (rtb_Switch2_b < 0.0F) {
    rtb_Switch2_b = -1.0F;
  } else {
    if (rtb_Switch2_b > 0.0F) {
      rtb_Switch2_b = 1.0F;
    }
  }

  /* End of Signum: '<S767>/Sign1' */

  /* Switch: '<S767>/Switch2' incorporates:
   *  Constant: '<S767>/Constant4'
   */
  if (rtb_Switch2_b == 0.0F) {
    rtb_Switch2_b = 1.0F;
  }

  /* End of Switch: '<S767>/Switch2' */

  /* DotProduct: '<S767>/Dot Product' */
  rtb_Divide_cw_idx_0 = localC->Divide[0] * rtb_Divide_cw_idx_0 + localC->
    Divide[1] * rtb_Divide_cw_idx_1;

  /* Trigonometry: '<S767>/Acos' incorporates:
   *  DotProduct: '<S767>/Dot Product'
   */
  if (rtb_Divide_cw_idx_0 > 1.0F) {
    rtb_Divide_cw_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_cw_idx_0 < -1.0F) {
      rtb_Divide_cw_idx_0 = -1.0F;
    }
  }

  /* Product: '<S767>/Multiply' incorporates:
   *  Trigonometry: '<S767>/Acos'
   */
  rtb_Divide_cw_idx_0 = acosf(rtb_Divide_cw_idx_0) * rtb_Switch2_b;

  /* Switch: '<S751>/Switch' incorporates:
   *  Bias: '<S751>/Bias'
   */
  if (rtb_Divide_cw_idx_0 >= 0.0F) {
    *rty_angle = rtb_Divide_cw_idx_0;
  } else {
    *rty_angle = rtb_Divide_cw_idx_0 + 6.28318548F;
  }

  /* End of Switch: '<S751>/Switch' */
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
  real_T rtb_Sum_ek_idx_0;

  /* Gain: '<S754>/deg2rad' */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S755>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_ek_idx_0);

  /* Math: '<S755>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S755>/Multiply1' incorporates:
   *  Product: '<S755>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S755>/Divide' incorporates:
   *  Constant: '<S755>/Constant'
   *  Constant: '<S755>/R'
   *  Sqrt: '<S755>/Sqrt'
   *  Sum: '<S755>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S755>/Product3' incorporates:
   *  Constant: '<S755>/Constant1'
   *  Product: '<S755>/Multiply1'
   *  Sum: '<S755>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S755>/Multiply2' incorporates:
   *  Trigonometry: '<S755>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_ek_idx_0);

  /* Sum: '<S754>/Sum' */
  rtb_Sum_ek_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S759>/Abs' incorporates:
   *  Abs: '<S762>/Abs1'
   *  Switch: '<S759>/Switch1'
   */
  rtb_Sum_n1 = fabs(rtb_Sum_ek_idx_0);

  /* Switch: '<S759>/Switch1' incorporates:
   *  Abs: '<S759>/Abs'
   *  Bias: '<S759>/Bias2'
   *  Bias: '<S759>/Bias3'
   *  Constant: '<S756>/Constant'
   *  Constant: '<S756>/Constant1'
   *  Constant: '<S761>/Constant'
   *  Gain: '<S759>/Gain1'
   *  Product: '<S759>/Multiply'
   *  RelationalOperator: '<S761>/Compare'
   *  Switch: '<S756>/Switch'
   */
  if (rtb_Sum_n1 > 90.0) {
    /* Switch: '<S762>/Switch1' incorporates:
     *  Bias: '<S762>/Bias2'
     *  Bias: '<S762>/Bias3'
     *  Constant: '<S762>/Constant'
     *  Constant: '<S763>/Constant'
     *  Math: '<S762>/Math Function'
     *  RelationalOperator: '<S763>/Compare'
     */
    if (rtb_Sum_n1 > 180.0) {
      rtb_Sum_ek_idx_0 = rt_modd(rtb_Sum_ek_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S762>/Switch1' */

    /* Signum: '<S759>/Sign' */
    if (rtb_Sum_ek_idx_0 < 0.0) {
      rtb_Sum_ek_idx_0 = -1.0;
    } else {
      if (rtb_Sum_ek_idx_0 > 0.0) {
        rtb_Sum_ek_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S759>/Sign' */
    rtb_Sum_ek_idx_0 *= -(rtb_Sum_n1 + -90.0) + 90.0;
    rtb_Compare_dy_0 = 180;
  } else {
    rtb_Compare_dy_0 = 0;
  }

  /* Sum: '<S756>/Sum' incorporates:
   *  Sum: '<S754>/Sum'
   */
  rtb_Sum_n1 = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_dy_0;

  /* Product: '<S754>/Multiply' incorporates:
   *  Gain: '<S754>/deg2rad1'
   */
  rtb_Sum_ek_idx_0 = 0.017453292519943295 * rtb_Sum_ek_idx_0 * rtb_Gain_lq;

  /* Switch: '<S758>/Switch1' incorporates:
   *  Abs: '<S758>/Abs1'
   *  Bias: '<S758>/Bias2'
   *  Bias: '<S758>/Bias3'
   *  Constant: '<S758>/Constant'
   *  Constant: '<S760>/Constant'
   *  Math: '<S758>/Math Function'
   *  RelationalOperator: '<S760>/Compare'
   */
  if (fabs(rtb_Sum_n1) > 180.0) {
    rtb_Sum_n1 = rt_modd(rtb_Sum_n1 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S758>/Switch1' */

  /* Product: '<S754>/Multiply' incorporates:
   *  Gain: '<S754>/deg2rad1'
   */
  rtb_Sum_n1 = 0.017453292519943295 * rtb_Sum_n1 * rtb_Sum2_m;

  /* Gain: '<S754>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S757>/SinCos' */
  rtb_Sum3_l = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S757>/Sum2' incorporates:
   *  Product: '<S757>/Multiply1'
   *  Product: '<S757>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_ek_idx_0 * rtb_Gain_lq + rtb_Sum_n1 * rtb_Sum3_l;

  /* Product: '<S757>/Multiply3' */
  rtb_Sum3_l *= rtb_Sum_ek_idx_0;

  /* Product: '<S757>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_n1;

  /* Sum: '<S757>/Sum3' */
  rtb_Sum3_l = rtb_Gain_lq - rtb_Sum3_l;

  /* DataTypeConversion: '<S747>/Data Type Conversion' incorporates:
   *  Gain: '<S754>/Gain'
   *  Sum: '<S754>/Sum1'
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
  /* RelationalOperator: '<S766>/Compare' incorporates:
   *  Abs: '<S750>/Abs'
   *  Constant: '<S766>/Constant'
   *  MinMax: '<S750>/Max'
   *  Sum: '<S750>/Sum'
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
      /* Reshape: '<S749>/Reshape' incorporates:
       *  Constant: '<S749>/Constant'
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
static void FMS_Combo_Stick(void)
{
  int32_T b_previousEvent;
  switch (FMS_DW.is_Combo_Stick) {
   case FMS_IN_Arm:
    if (!FMS_BottomRight(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                         FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
    {
      FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.durationLastReferenceTick_1_jb = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Combo_Stick = FMS_IN_Idle;
      FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
      FMS_DW.condWasTrueAtLastTimeStep_2_e = FMS_DW.bl;
    }
    break;

   case FMS_IN_Disarm:
    if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                        FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle)) {
      FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.durationLastReferenceTick_1_jb = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Combo_Stick = FMS_IN_Idle;
      FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
      FMS_DW.condWasTrueAtLastTimeStep_2_e = FMS_DW.bl;
    }
    break;

   case FMS_IN_Idle:
    if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
      FMS_DW.durationLastReferenceTick_1_jb = FMS_DW.chartAbsoluteTimeCounter;
    }

    FMS_DW.condWasTrueAtLastTimeStep_1_k = FMS_DW.br;
    if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_jb >
        375) {
      FMS_DW.is_Combo_Stick = FMS_IN_Arm;
      FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
      FMS_sf_msg_send_M();
    } else {
      if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_e)) {
        FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2_e = FMS_DW.bl;
      if (FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_2_a
          > 375) {
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
          FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
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
      FMS_Combo_Stick();
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
        if (fabsf(FMS_B.DiscreteTimeIntegrator5_p) < 2.0F) {
          b_sf_internal_predicateOutput = true;
        } else if (FMS_DW.temporalCounter_i2 >= 5000U) {
          b_sf_internal_predicateOutput = true;
        } else {
          FMS_B.flag = FMS_B.BusConversion_InsertedFor_FMSSt.flag;

          /* Outputs for Function Call SubSystem: '<S6>/VTOL_State.IsPosValid' */
          /* RelationalOperator: '<S752>/Compare' incorporates:
           *  Constant: '<S752>/Constant'
           *  S-Function (sfix_bitop): '<S744>/Bitwise AND'
           */
          FMS_B.Compare_b = ((FMS_B.flag & 212U) == 212U);

          /* End of Outputs for SubSystem: '<S6>/VTOL_State.IsPosValid' */
          b_sf_internal_predicateOutput = !FMS_B.Compare_b;
        }

        if (b_sf_internal_predicateOutput) {
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
        } else {
          FMS_B.Airspeed_n = FMS_B.DiscreteTimeIntegrator5;

          /* Outputs for Function Call SubSystem: '<S6>/VTOL_State.IsStall' */
          /* RelationalOperator: '<S745>/Relational Operator1' incorporates:
           *  Constant: '<S745>/Constant1'
           */
          FMS_B.RelationalOperator1_b = (FMS_B.Airspeed_n <=
            FMS_PARAM.FW_STALL_SPEED);

          /* End of Outputs for SubSystem: '<S6>/VTOL_State.IsStall' */
          if (FMS_B.RelationalOperator1_b) {
            FMS_DW.is_VTOL_State = FMS_IN_StallProtect;
            FMS_B.vtol_state = VTOLState_Stall;
          }
        }
        break;

       case FMS_IN_ForwardTrans:
        FMS_B.Airspeed = FMS_B.DiscreteTimeIntegrator5;

        /* Outputs for Function Call SubSystem: '<S6>/VTOL_State.ForwardTransCplt' */
        /* RelationalOperator: '<S743>/Relational Operator' incorporates:
         *  Constant: '<S743>/Constant'
         */
        FMS_B.RelationalOperator = (FMS_B.Airspeed >= FMS_PARAM.FW_SPEED_MIN);

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

       case FMS_IN_StallProtect:
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
        } else {
          FMS_B.Airspeed_m = FMS_B.DiscreteTimeIntegrator5;

          /* Outputs for Function Call SubSystem: '<S6>/VTOL_State.EndStall' */
          /* RelationalOperator: '<S742>/Relational Operator1' incorporates:
           *  Constant: '<S742>/Constant1'
           */
          FMS_B.RelationalOperator1 = (FMS_B.Airspeed_m >=
            FMS_PARAM.FW_SPEED_MIN);

          /* End of Outputs for SubSystem: '<S6>/VTOL_State.EndStall' */
          if (FMS_B.RelationalOperator1) {
            FMS_DW.is_VTOL_State = FMS_IN_Fixwing;
            FMS_B.vtol_state = VTOLState_Fixwing;
          }
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
  real32_T rtb_a_bx;
  real32_T rtb_Divide_or;
  real32_T rtb_Sign5_mn;
  MotionState rtb_state_l4;
  real32_T rtb_Subtract3_g;
  real32_T rtb_Sign5_dc;
  real32_T rtb_VectorConcatenate_h[9];
  MotionState rtb_state_fg;
  real32_T rtb_Sign5_l;
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
  /* Outputs for IfAction SubSystem: '<S135>/Hold Control' incorporates:
   *  ActionPort: '<S138>/Action Port'
   */
  /* SwitchCase: '<S135>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S150>/Square'
   *  Math: '<S18>/Square'
   *  Math: '<S60>/Square'
   *  Sqrt: '<S150>/Sqrt'
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

  /* End of Outputs for SubSystem: '<S135>/Hold Control' */
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
  rtb_Sign5_l = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_0;

  /* Math: '<S15>/Square2' incorporates:
   *  Math: '<S16>/Square2'
   *  Math: '<S17>/Square2'
   */
  rtb_a_bx = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

  /* Math: '<S15>/Square1' incorporates:
   *  Math: '<S16>/Square1'
   *  Math: '<S17>/Square1'
   */
  rtb_Divide_or = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_1;

  /* Math: '<S15>/Square3' incorporates:
   *  Math: '<S16>/Square3'
   *  Math: '<S17>/Square3'
   */
  rtb_Sign5_mn = rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3;

  /* Sum: '<S15>/Subtract' incorporates:
   *  Math: '<S15>/Square'
   *  Math: '<S15>/Square1'
   *  Math: '<S15>/Square2'
   *  Math: '<S15>/Square3'
   *  Sum: '<S15>/Add'
   *  Sum: '<S15>/Add1'
   */
  rtb_MatrixConcatenate1_i[0] = (rtb_Sign5_l + rtb_Divide_or) - (rtb_a_bx +
    rtb_Sign5_mn);

  /* Product: '<S15>/Multiply' incorporates:
   *  Product: '<S16>/Multiply'
   */
  rtb_Sign5_dc = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_2;

  /* Product: '<S15>/Multiply1' incorporates:
   *  Product: '<S16>/Multiply1'
   */
  rtb_Subtract3_g = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_3;

  /* Gain: '<S15>/Gain' incorporates:
   *  Product: '<S15>/Multiply'
   *  Product: '<S15>/Multiply1'
   *  Sum: '<S15>/Subtract1'
   */
  rtb_MatrixConcatenate1_i[1] = (rtb_Sign5_dc - rtb_Subtract3_g) * 2.0F;

  /* Product: '<S15>/Multiply2' incorporates:
   *  Product: '<S17>/Multiply'
   */
  rtb_MatrixConcatenate1_i_tmp = rtb_Divide_lr_idx_1 * rtb_Divide_lr_idx_3;

  /* Product: '<S15>/Multiply3' incorporates:
   *  Product: '<S17>/Multiply1'
   */
  rtb_MatrixConcatenate1_i_tmp_0 = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_2;

  /* Gain: '<S15>/Gain1' incorporates:
   *  Product: '<S15>/Multiply2'
   *  Product: '<S15>/Multiply3'
   *  Sum: '<S15>/Add2'
   */
  rtb_MatrixConcatenate1_i[2] = (rtb_MatrixConcatenate1_i_tmp +
    rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

  /* Gain: '<S16>/Gain' incorporates:
   *  Sum: '<S16>/Add3'
   */
  rtb_MatrixConcatenate1_i[3] = (rtb_Sign5_dc + rtb_Subtract3_g) * 2.0F;

  /* Sum: '<S16>/Subtract' incorporates:
   *  Sum: '<S16>/Add'
   *  Sum: '<S16>/Add1'
   */
  rtb_MatrixConcatenate1_i[4] = (rtb_Sign5_l + rtb_a_bx) - (rtb_Divide_or +
    rtb_Sign5_mn);

  /* Product: '<S16>/Multiply2' incorporates:
   *  Product: '<S17>/Multiply2'
   */
  rtb_Sign5_dc = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_3;

  /* Product: '<S16>/Multiply3' incorporates:
   *  Product: '<S17>/Multiply3'
   */
  rtb_Subtract3_g = rtb_Divide_lr_idx_0 * rtb_Divide_lr_idx_1;

  /* Gain: '<S16>/Gain1' incorporates:
   *  Product: '<S16>/Multiply2'
   *  Product: '<S16>/Multiply3'
   *  Sum: '<S16>/Subtract1'
   */
  rtb_MatrixConcatenate1_i[5] = (rtb_Sign5_dc - rtb_Subtract3_g) * 2.0F;

  /* Gain: '<S17>/Gain' incorporates:
   *  Sum: '<S17>/Subtract2'
   */
  rtb_MatrixConcatenate1_i[6] = (rtb_MatrixConcatenate1_i_tmp -
    rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

  /* Gain: '<S17>/Gain1' incorporates:
   *  Sum: '<S17>/Add2'
   */
  rtb_MatrixConcatenate1_i[7] = (rtb_Sign5_dc + rtb_Subtract3_g) * 2.0F;

  /* Sum: '<S17>/Subtract' incorporates:
   *  Sum: '<S17>/Add'
   *  Sum: '<S17>/Add1'
   */
  rtb_MatrixConcatenate1_i[8] = (rtb_Sign5_l + rtb_Sign5_mn) - (rtb_Divide_or +
    rtb_a_bx);

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
   *  ActionPort: '<S197>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S197>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S201>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S46>/SubMode' incorporates:
   *  ActionPort: '<S88>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Return' incorporates:
   *  ActionPort: '<S231>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Takeoff' incorporates:
   *  ActionPort: '<S232>/Action Port'
   */
  /* SwitchCase: '<S86>/Switch Case' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Math: '<S220>/Math Function'
   *  Math: '<S269>/Math Function'
   *  Math: '<S291>/Math Function'
   *  SwitchCase: '<S39>/Switch Case'
   *  SwitchCase: '<S41>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S88>/Switch Case'
   */
  rtb_Sign5_l = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
  rtb_a_bx = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

  /* End of Outputs for SubSystem: '<S88>/Takeoff' */
  /* End of Outputs for SubSystem: '<S88>/Return' */
  /* End of Outputs for SubSystem: '<S197>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S86>/Mission' */
  /* End of Outputs for SubSystem: '<S46>/Auto' */

  /* Outputs for IfAction SubSystem: '<S41>/MC_Mode' incorporates:
   *  ActionPort: '<S47>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
   *  ActionPort: '<S297>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S297>/Mission' incorporates:
   *  ActionPort: '<S408>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S408>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S412>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S47>/SubMode' incorporates:
   *  ActionPort: '<S299>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S299>/Return' incorporates:
   *  ActionPort: '<S600>/Action Port'
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
  /* Outputs for IfAction SubSystem: '<S135>/Hold Control' incorporates:
   *  ActionPort: '<S138>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Hold' incorporates:
   *  ActionPort: '<S229>/Action Port'
   */
  /* SwitchCase: '<S135>/Switch Case' incorporates:
   *  Math: '<S1>/Square2'
   *  Math: '<S1>/Square3'
   *  Sqrt: '<S156>/Sqrt'
   *  Sqrt: '<S1>/Sqrt'
   *  Sqrt: '<S219>/Sqrt'
   *  Sqrt: '<S245>/Sqrt'
   *  Sqrt: '<S268>/Sqrt'
   *  Sqrt: '<S371>/Sqrt'
   *  Sqrt: '<S478>/Sqrt'
   *  Sqrt: '<S66>/Sqrt'
   *  Sqrt: '<S718>/Sqrt'
   *  Sum: '<S158>/Sum of Elements'
   *  Sum: '<S1>/Add'
   *  Sum: '<S246>/Sum of Elements'
   *  Sum: '<S480>/Sum of Elements'
   *  Sum: '<S68>/Sum of Elements'
   *  Sum: '<S720>/Sum of Elements'
   *  Switch: '<S138>/Switch'
   *  Switch: '<S48>/Switch'
   *  SwitchCase: '<S296>/Switch Case'
   *  SwitchCase: '<S297>/Switch Case'
   *  SwitchCase: '<S299>/Switch Case'
   *  SwitchCase: '<S39>/Switch Case'
   *  SwitchCase: '<S41>/Switch Case'
   *  SwitchCase: '<S46>/Switch Case'
   *  SwitchCase: '<S47>/Switch Case'
   *  SwitchCase: '<S85>/Switch Case'
   *  SwitchCase: '<S86>/Switch Case'
   *  SwitchCase: '<S88>/Switch Case'
   */
  rtb_Divide_lr_idx_3 = rtb_Sign5_l + rtb_a_bx;

  /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
   *  ActionPort: '<S296>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S296>/Position' incorporates:
   *  ActionPort: '<S303>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S46>/Auto' incorporates:
   *  ActionPort: '<S86>/Action Port'
   */
  /* Outputs for IfAction SubSystem: '<S86>/Mission' incorporates:
   *  ActionPort: '<S197>/Action Port'
   */
  /* Outputs for Resettable SubSystem: '<S197>/Mission_SubSystem' incorporates:
   *  ResetPort: '<S201>/Reset'
   */
  /* Outputs for IfAction SubSystem: '<S88>/Return' incorporates:
   *  ActionPort: '<S231>/Action Port'
   */
  rtb_Divide_lr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);

  /* End of Outputs for SubSystem: '<S88>/Return' */
  /* End of Outputs for SubSystem: '<S197>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S86>/Mission' */
  /* End of Outputs for SubSystem: '<S46>/Auto' */
  /* End of Outputs for SubSystem: '<S296>/Position' */
  /* End of Outputs for SubSystem: '<S47>/Assist' */
  /* End of Outputs for SubSystem: '<S88>/Hold' */
  /* End of Outputs for SubSystem: '<S135>/Hold Control' */
  /* End of Outputs for SubSystem: '<S85>/Position' */
  /* End of Outputs for SubSystem: '<S46>/Assist' */
  /* End of Outputs for SubSystem: '<S41>/BackwardTrans_Mode' */
  /* End of Outputs for SubSystem: '<S299>/Return' */
  /* End of Outputs for SubSystem: '<S47>/SubMode' */
  /* End of Outputs for SubSystem: '<S408>/Mission_SubSystem' */
  /* End of Outputs for SubSystem: '<S297>/Mission' */
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
          /* Disable for SwitchCase: '<S135>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

          /* Disable for SwitchCase: '<S121>/Switch Case' */
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
        /* Disable for SwitchCase: '<S299>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S699>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S689>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S638>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

          /* Disable for SwitchCase: '<S606>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

          /* Disable for SwitchCase: '<S617>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
          break;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S297>/Switch Case' */
        if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
          /* Disable for Resettable SubSystem: '<S408>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S459>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S449>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S408>/Mission_SubSystem' */
        }

        FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S296>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
         case 4:
          break;

         case 1:
          /* Disable for SwitchCase: '<S395>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S311>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

          /* Disable for SwitchCase: '<S329>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S345>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

          /* Disable for SwitchCase: '<S370>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

          /* Disable for SwitchCase: '<S357>/Switch Case' */
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
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S42>/Bus Assignment'
     *  BusAssignment: '<S43>/Bus Assignment'
     *  Constant: '<S43>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S43>/Bus Assignment' incorporates:
     *  BusAssignment: '<S42>/Bus Assignment'
     *  Constant: '<S43>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
    FMS_Y.FMS_Out.reset = 1U;
    FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_mv;
    FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ap;

    /* End of Outputs for SubSystem: '<S39>/Disarm' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S39>/Standby' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    /* Outport: '<Root>/FMS_Out' incorporates:
     *  BusAssignment: '<S42>/Bus Assignment'
     *  BusAssignment: '<S44>/Bus Assignment'
     *  Constant: '<S44>/Constant'
     */
    FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

    /* BusAssignment: '<S44>/Bus Assignment' incorporates:
     *  BusAssignment: '<S42>/Bus Assignment'
     *  Constant: '<S44>/Constant2'
     *  Outport: '<Root>/FMS_Out'
     */
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
     case VTOLState_Stall:
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
            /* Disable for SwitchCase: '<S135>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S121>/Switch Case' */
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
          /* Disable for SwitchCase: '<S299>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S699>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S689>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S638>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S606>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S617>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S297>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S408>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S459>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S449>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S408>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S296>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S395>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S311>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S329>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S345>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S370>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S357>/Switch Case' */
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
            /* Disable for SwitchCase: '<S135>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S121>/Switch Case' */
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
           *  ActionPort: '<S232>/Action Port'
           */
          /* Sum: '<S291>/Sum of Elements' incorporates:
           *  Sum: '<S290>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Sign5_l + rtb_a_bx;

          /* Math: '<S291>/Math Function1' incorporates:
           *  Sum: '<S291>/Sum of Elements'
           *
           * About '<S291>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S291>/Math Function1' */

          /* Switch: '<S291>/Switch' incorporates:
           *  Constant: '<S291>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S291>/Product'
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

          /* End of Switch: '<S291>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S281>/NearbyRefWP' incorporates:
           *  Constant: '<S279>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Divide_i5,
                          &rtb_Divide_lr_idx_2);

          /* MATLAB Function: '<S281>/SearchL1RefWP' incorporates:
           *  Constant: '<S279>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_P_cg, &rtb_Divide_lr_idx_3);

          /* MATLAB Function: '<S281>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S276>/Sum'
           *  Sum: '<S276>/Sum1'
           */
          rtb_Divide_pr_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_pr_idx_2 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          d = FMS_B.Cmd_In.sp_waypoint[1] - FMS_B.Cmd_In.cur_waypoint[1];
          rtb_Sign5_l = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_a_bx = d * d;
          rtb_Divide_pr_idx_1 = (rtb_Sign5_l * d + rtb_Divide_pr_idx_2 *
            rtb_Divide_pr_idx_0) / (rtb_a_bx + rtb_Divide_pr_idx_0 *
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
            rtb_Divide_or = (rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_0 +
                             FMS_B.Cmd_In.cur_waypoint[0]) - FMS_U.INS_Out.x_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Divide_or * rtb_Divide_or;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_Divide_or = (rtb_Divide_pr_idx_1 * d +
                             FMS_B.Cmd_In.cur_waypoint[1]) - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Divide_pr_idx_1 += sqrtf(rtb_Divide_or * rtb_Divide_or +
              rtb_Subtract_hb[0]) * 0.5774F / sqrtf(rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_a_bx);
            if (rtb_Divide_pr_idx_1 > 1.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            rtb_P_dg[0] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_0 +
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_P_dg[1] = rtb_Divide_pr_idx_1 * d + FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* End of MATLAB Function: '<S281>/OutRegionRegWP' */

          /* Switch: '<S281>/Switch1' incorporates:
           *  Constant: '<S284>/Constant'
           *  RelationalOperator: '<S284>/Compare'
           */
          if (rtb_Divide_lr_idx_2 <= 0.0F) {
            /* Switch: '<S281>/Switch' incorporates:
             *  Constant: '<S283>/Constant'
             *  RelationalOperator: '<S283>/Compare'
             */
            if (rtb_Divide_lr_idx_3 >= 0.0F) {
              rtb_Divide_i5[0] = rtb_P_cg[0];
              rtb_Divide_i5[1] = rtb_P_cg[1];
            } else {
              rtb_Divide_i5[0] = rtb_P_dg[0];
              rtb_Divide_i5[1] = rtb_P_dg[1];
            }

            /* End of Switch: '<S281>/Switch' */
          }

          /* End of Switch: '<S281>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S282>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_i5[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_i5[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S292>/Sum of Elements' incorporates:
           *  Math: '<S292>/Math Function'
           */
          rtb_Divide_lr_idx_3 = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

          /* Math: '<S292>/Math Function1' incorporates:
           *  Sum: '<S292>/Sum of Elements'
           *
           * About '<S292>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S292>/Math Function1' */

          /* Switch: '<S292>/Switch' incorporates:
           *  Constant: '<S292>/Constant'
           *  Product: '<S292>/Product'
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

          /* End of Switch: '<S292>/Switch' */

          /* Product: '<S291>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S294>/Sum of Elements' incorporates:
           *  Math: '<S294>/Math Function'
           *  SignalConversion: '<S294>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S294>/Math Function1' incorporates:
           *  Sum: '<S294>/Sum of Elements'
           *
           * About '<S294>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S294>/Math Function1' */

          /* Switch: '<S294>/Switch' incorporates:
           *  Constant: '<S294>/Constant'
           *  Product: '<S294>/Product'
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

          /* End of Switch: '<S294>/Switch' */

          /* Product: '<S292>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S295>/Sum of Elements' incorporates:
           *  Math: '<S295>/Math Function'
           *  SignalConversion: '<S295>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S295>/Math Function1' incorporates:
           *  Sum: '<S295>/Sum of Elements'
           *
           * About '<S295>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S295>/Math Function1' */

          /* Switch: '<S295>/Switch' incorporates:
           *  Constant: '<S295>/Constant'
           *  Product: '<S295>/Product'
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

          /* End of Switch: '<S295>/Switch' */

          /* Product: '<S295>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S294>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S295>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S294>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S276>/Divide' incorporates:
           *  Math: '<S277>/Square'
           *  Math: '<S278>/Square'
           *  Sqrt: '<S277>/Sqrt'
           *  Sqrt: '<S278>/Sqrt'
           *  Sum: '<S277>/Sum of Elements'
           *  Sum: '<S278>/Sum of Elements'
           */
          rtb_Divide_pr_idx_2 = sqrtf(rtb_Sign5_l * rtb_Sign5_l +
            rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2) / sqrtf
            (rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0 + d * d);

          /* Saturate: '<S276>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S276>/Saturation' */

          /* Sum: '<S293>/Subtract' incorporates:
           *  Product: '<S293>/Multiply'
           *  Product: '<S293>/Multiply1'
           */
          rtb_Divide_pr_idx_1 = rtb_Subtract_hb[0] * rtb_Divide_i5[1] -
            rtb_Subtract_hb[1] * rtb_Divide_i5[0];

          /* Signum: '<S289>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S289>/Sign1' */

          /* Switch: '<S289>/Switch2' incorporates:
           *  Constant: '<S289>/Constant4'
           */
          if (rtb_Divide_pr_idx_1 == 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          }

          /* End of Switch: '<S289>/Switch2' */

          /* DotProduct: '<S289>/Dot Product' */
          rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Subtract_hb[0] +
            rtb_Divide_i5[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S289>/Acos' incorporates:
           *  DotProduct: '<S289>/Dot Product'
           */
          if (rtb_Divide_pr_idx_0 > 1.0F) {
            rtb_Divide_pr_idx_0 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 < -1.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            }
          }

          /* Product: '<S289>/Multiply' incorporates:
           *  Trigonometry: '<S289>/Acos'
           */
          rtb_Divide_pr_idx_1 *= acosf(rtb_Divide_pr_idx_0);

          /* Saturate: '<S288>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.57079637F) {
            rtb_Divide_pr_idx_1 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_1 < -1.57079637F) {
              rtb_Divide_pr_idx_1 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S288>/Saturation' */

          /* Sqrt: '<S290>/Sqrt' */
          rtb_Divide_lr_idx_2 = sqrtf(rtb_Saturation_e);

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S232>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S232>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S232>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S232>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_f;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_mf;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_mc;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S288>/Divide' incorporates:
           *  Constant: '<S279>/L1'
           *  Gain: '<S288>/Gain'
           *  Math: '<S288>/Square'
           *  Product: '<S288>/Multiply1'
           *  Trigonometry: '<S288>/Sin'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Divide_pr_idx_1) / FMS_PARAM.FW_L1;

          /* Saturate: '<S279>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S232>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S232>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S232>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S279>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S274>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S276>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S274>/Sum2'
           *  Sum: '<S276>/Add'
           *  Sum: '<S276>/Subtract'
           */
          rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_pr_idx_2 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S274>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S232>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S232>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S232>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S274>/Saturation1' */
          /* End of Outputs for SubSystem: '<S88>/Takeoff' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S88>/Land' incorporates:
           *  ActionPort: '<S230>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S230>/Bus Assignment1'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S230>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S230>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S230>/Constant'
           *  Constant: '<S230>/Constant4'
           *  Constant: '<S230>/Constant5'
           *  Constant: '<S230>/Constant7'
           *  Outport: '<Root>/FMS_Out'
           */
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
           *  ActionPort: '<S231>/Action Port'
           */
          /* Math: '<S269>/Math Function' */
          rtb_Subtract_hb[0] = rtb_Sign5_l;
          rtb_Subtract_hb[1] = rtb_a_bx;

          /* Sum: '<S269>/Sum of Elements' */
          rtb_Saturation_e = rtb_Sign5_l + rtb_a_bx;

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
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S269>/Product'
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

          /* End of Switch: '<S269>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S259>/NearbyRefWP' incorporates:
           *  Constant: '<S257>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Divide_pr_idx_1);

          /* MATLAB Function: '<S259>/SearchL1RefWP' incorporates:
           *  Constant: '<S257>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_i5, &rtb_Saturation_e);

          /* MATLAB Function: '<S259>/OutRegionRegWP' incorporates:
           *  Constant: '<S257>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_cg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S259>/Switch1' incorporates:
           *  Constant: '<S262>/Constant'
           *  RelationalOperator: '<S262>/Compare'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Divide_i5[0] = rtb_Subtract_hb[0];
            rtb_Divide_i5[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S261>/Compare' incorporates:
             *  Constant: '<S261>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_e >= 0.0F);

            /* Switch: '<S259>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_i5[0] = rtb_P_cg[0];
              rtb_Divide_i5[1] = rtb_P_cg[1];
            }

            /* End of Switch: '<S259>/Switch' */
          }

          /* End of Switch: '<S259>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S260>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_i5[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_i5[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S270>/Sum of Elements' incorporates:
           *  Math: '<S270>/Math Function'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

          /* Math: '<S270>/Math Function1' incorporates:
           *  Sum: '<S270>/Sum of Elements'
           *
           * About '<S270>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Saturation_e = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S270>/Math Function1' */

          /* Switch: '<S270>/Switch' incorporates:
           *  Constant: '<S270>/Constant'
           *  Product: '<S270>/Product'
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

          /* End of Switch: '<S270>/Switch' */

          /* Product: '<S269>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S272>/Sum of Elements' incorporates:
           *  Math: '<S272>/Math Function'
           *  SignalConversion: '<S272>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S272>/Math Function1' incorporates:
           *  Sum: '<S272>/Sum of Elements'
           *
           * About '<S272>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Saturation_e = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S272>/Math Function1' */

          /* Switch: '<S272>/Switch' incorporates:
           *  Constant: '<S272>/Constant'
           *  Product: '<S272>/Product'
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

          /* End of Switch: '<S272>/Switch' */

          /* Product: '<S270>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S273>/Sum of Elements' incorporates:
           *  Math: '<S273>/Math Function'
           *  SignalConversion: '<S273>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S273>/Math Function1' incorporates:
           *  Sum: '<S273>/Sum of Elements'
           *
           * About '<S273>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Saturation_e = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S273>/Math Function1' */

          /* Switch: '<S273>/Switch' incorporates:
           *  Constant: '<S273>/Constant'
           *  Product: '<S273>/Product'
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

          /* End of Switch: '<S273>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S254>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_e = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_3 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S273>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S272>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S254>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sign5_l = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S273>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S272>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S254>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S254>/Divide' incorporates:
           *  Math: '<S255>/Square'
           *  Math: '<S256>/Square'
           *  Sqrt: '<S255>/Sqrt'
           *  Sqrt: '<S256>/Sqrt'
           *  Sum: '<S254>/Sum'
           *  Sum: '<S254>/Sum1'
           *  Sum: '<S255>/Sum of Elements'
           *  Sum: '<S256>/Sum of Elements'
           */
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3
            + rtb_Saturation_e * rtb_Saturation_e) / sqrtf(rtb_Sign5_l *
            rtb_Sign5_l + rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2);

          /* Saturate: '<S254>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = 0.0F;
            }
          }

          /* End of Saturate: '<S254>/Saturation' */

          /* Sum: '<S271>/Subtract' incorporates:
           *  Product: '<S271>/Multiply'
           *  Product: '<S271>/Multiply1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Divide_i5[1] -
            rtb_Subtract_hb[1] * rtb_Divide_i5[0];

          /* Signum: '<S267>/Sign1' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S267>/Sign1' */

          /* Switch: '<S267>/Switch2' incorporates:
           *  Constant: '<S267>/Constant4'
           */
          if (rtb_Saturation_e == 0.0F) {
            rtb_Saturation_e = 1.0F;
          }

          /* End of Switch: '<S267>/Switch2' */

          /* DotProduct: '<S267>/Dot Product' */
          rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Subtract_hb[0] +
            rtb_Divide_i5[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S267>/Acos' incorporates:
           *  DotProduct: '<S267>/Dot Product'
           */
          if (rtb_Divide_pr_idx_0 > 1.0F) {
            rtb_Divide_pr_idx_0 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 < -1.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            }
          }

          /* Product: '<S267>/Multiply' incorporates:
           *  Trigonometry: '<S267>/Acos'
           */
          rtb_Saturation_e *= acosf(rtb_Divide_pr_idx_0);

          /* Saturate: '<S266>/Saturation' */
          if (rtb_Saturation_e > 1.57079637F) {
            rtb_Saturation_e = 1.57079637F;
          } else {
            if (rtb_Saturation_e < -1.57079637F) {
              rtb_Saturation_e = -1.57079637F;
            }
          }

          /* End of Saturate: '<S266>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S231>/Bus Assignment1'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S231>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S231>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S231>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_be;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_g;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_dz;
          FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;

          /* Product: '<S266>/Divide' incorporates:
           *  Constant: '<S257>/L1'
           *  Gain: '<S266>/Gain'
           *  Math: '<S266>/Square'
           *  Product: '<S266>/Multiply1'
           *  Trigonometry: '<S266>/Sin'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_e) / FMS_PARAM.FW_L1;

          /* Saturate: '<S257>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S231>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S257>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S252>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S254>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S252>/Sum2'
           *  Sum: '<S254>/Add'
           *  Sum: '<S254>/Subtract'
           */
          rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_pr_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S252>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S231>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S231>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S252>/Saturation1' */
          /* End of Outputs for SubSystem: '<S88>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_kv != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S88>/Hold' incorporates:
             *  ActionPort: '<S229>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S88>/Switch Case' incorporates:
             *  Delay: '<S234>/Delay'
             *  Delay: '<S239>/start_vel'
             */
            FMS_DW.icLoad_lf = 1U;
            FMS_DW.icLoad_mz = 1U;

            /* End of InitializeConditions for SubSystem: '<S88>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S88>/Hold' incorporates:
           *  ActionPort: '<S229>/Action Port'
           */
          /* Math: '<S246>/Math Function1'
           *
           * About '<S246>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S246>/Math Function1' */

          /* Switch: '<S246>/Switch' incorporates:
           *  Constant: '<S246>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S246>/Product'
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

          /* End of Switch: '<S246>/Switch' */

          /* Delay: '<S239>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_lf != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.start_vel_DSTATE_l3[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE_l3[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Sum: '<S251>/Sum of Elements' incorporates:
           *  Delay: '<S239>/start_vel'
           *  Math: '<S251>/Math Function'
           */
          rtb_Saturation_e = FMS_DW.start_vel_DSTATE_l3[0] *
            FMS_DW.start_vel_DSTATE_l3[0] + FMS_DW.start_vel_DSTATE_l3[1] *
            FMS_DW.start_vel_DSTATE_l3[1];

          /* Math: '<S251>/Math Function1' incorporates:
           *  Sum: '<S251>/Sum of Elements'
           *
           * About '<S251>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S251>/Math Function1' */

          /* Switch: '<S251>/Switch' incorporates:
           *  Constant: '<S251>/Constant'
           *  Delay: '<S239>/start_vel'
           *  Product: '<S251>/Product'
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

          /* End of Switch: '<S251>/Switch' */

          /* Product: '<S246>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S249>/Sum of Elements' incorporates:
           *  Math: '<S249>/Math Function'
           *  SignalConversion: '<S249>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S249>/Math Function1' incorporates:
           *  Sum: '<S249>/Sum of Elements'
           *
           * About '<S249>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S249>/Math Function1' */

          /* Switch: '<S249>/Switch' incorporates:
           *  Constant: '<S249>/Constant'
           *  Product: '<S249>/Product'
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

          /* End of Switch: '<S249>/Switch' */

          /* MinMax: '<S237>/Max' incorporates:
           *  Constant: '<S235>/L1'
           *  Constant: '<S235>/R'
           *  Gain: '<S237>/Gain'
           */
          rtb_Divide_pr_idx_1 = fmaxf(FMS_PARAM.FW_LOITER_R, 0.5F *
            FMS_PARAM.FW_L1);

          /* MATLAB Function: '<S237>/SearchL1RefWP' incorporates:
           *  Constant: '<S235>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S242>/TmpSignal ConversionAt SFunction Inport2'
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

          /* End of MATLAB Function: '<S237>/SearchL1RefWP' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* RelationalOperator: '<S240>/Compare' incorporates:
           *  Constant: '<S240>/Constant'
           */
          rtb_FixPtRelationalOperator_me = (rtb_n > 0);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S237>/OutRegionRegWP' incorporates:
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

          /* Switch: '<S237>/Switch' incorporates:
           *  Constant: '<S235>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S237>/OutRegionRegWP'
           *  Product: '<S251>/Divide'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation_e = rtb_P_cg[0];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] >
                     rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S237>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S238>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Square_ds[0] = rtb_Saturation_e - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S237>/Switch' incorporates:
           *  Constant: '<S235>/L1'
           *  Inport: '<Root>/INS_Out'
           *  MATLAB Function: '<S237>/OutRegionRegWP'
           *  Product: '<S251>/Divide'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (rtb_FixPtRelationalOperator_me) {
            rtb_Saturation_e = rtb_P_cg[1];
          } else if (rtb_Subtract_hb[0] + rtb_Subtract_hb[1] >
                     rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S237>/OutRegionRegWP' incorporates:
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
          /* Sum: '<S238>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Square_ds[1] = rtb_Saturation_e - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S247>/Sum of Elements' incorporates:
           *  Math: '<S247>/Math Function'
           */
          rtb_Saturation_e = rtb_Square_ds[0] * rtb_Square_ds[0] +
            rtb_Square_ds[1] * rtb_Square_ds[1];

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
           *  Product: '<S247>/Product'
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

          /* End of Switch: '<S247>/Switch' */

          /* Product: '<S247>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_ee[0] / rtb_Switch_ee[2];
          rtb_Divide_i5[1] = rtb_Switch_ee[1] / rtb_Switch_ee[2];

          /* Sum: '<S250>/Sum of Elements' incorporates:
           *  Math: '<S250>/Math Function'
           *  SignalConversion: '<S250>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S250>/Math Function1' incorporates:
           *  Sum: '<S250>/Sum of Elements'
           *
           * About '<S250>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S250>/Math Function1' */

          /* Switch: '<S250>/Switch' incorporates:
           *  Constant: '<S250>/Constant'
           *  Product: '<S250>/Product'
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

          /* End of Switch: '<S250>/Switch' */

          /* Product: '<S250>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_ee[0] / rtb_Switch_ee[2];

          /* Product: '<S249>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S250>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_ee[1] / rtb_Switch_ee[2];

          /* Product: '<S249>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S248>/Subtract' incorporates:
           *  Product: '<S248>/Multiply'
           *  Product: '<S248>/Multiply1'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_i5[0] * rtb_Subtract_hb[1] -
            rtb_Divide_i5[1] * rtb_Subtract_hb[0];

          /* Signum: '<S244>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S244>/Sign1' */

          /* Switch: '<S244>/Switch2' incorporates:
           *  Constant: '<S244>/Constant4'
           */
          if (rtb_Divide_pr_idx_1 == 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          }

          /* End of Switch: '<S244>/Switch2' */

          /* DotProduct: '<S244>/Dot Product' */
          rtb_Divide_pr_idx_2 = rtb_Subtract_hb[0] * rtb_Divide_i5[0] +
            rtb_Subtract_hb[1] * rtb_Divide_i5[1];

          /* Trigonometry: '<S244>/Acos' incorporates:
           *  DotProduct: '<S244>/Dot Product'
           */
          if (rtb_Divide_pr_idx_2 > 1.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            }
          }

          /* Product: '<S244>/Multiply' incorporates:
           *  Trigonometry: '<S244>/Acos'
           */
          rtb_Divide_pr_idx_1 *= acosf(rtb_Divide_pr_idx_2);

          /* Saturate: '<S243>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.57079637F) {
            rtb_Divide_pr_idx_1 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_1 < -1.57079637F) {
              rtb_Divide_pr_idx_1 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S243>/Saturation' */

          /* Delay: '<S234>/Delay' incorporates:
           *  Gain: '<S236>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_mz != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nc = -FMS_U.INS_Out.h_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S229>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S229>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S229>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S229>/Constant3'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_pu;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_gu;
          FMS_Y.FMS_Out.u_cmd = 15.0F;

          /* Product: '<S243>/Divide' incorporates:
           *  Constant: '<S235>/L1'
           *  Gain: '<S243>/Gain'
           *  Math: '<S243>/Square'
           *  Product: '<S243>/Multiply1'
           *  Trigonometry: '<S243>/Sin'
           */
          rtb_Saturation_e = 2.0F * (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2) *
            arm_sin_f32(rtb_Divide_pr_idx_1) / FMS_PARAM.FW_L1;

          /* Saturate: '<S235>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S229>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S229>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S229>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S235>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S234>/Gain2' incorporates:
           *  Delay: '<S234>/Delay'
           *  Gain: '<S236>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S234>/Sum'
           */
          rtb_Saturation_e = (FMS_DW.Delay_DSTATE_nc - (-FMS_U.INS_Out.h_R)) *
            FMS_PARAM.Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S234>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S229>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S229>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S229>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S234>/Saturation1' */

          /* Update for Delay: '<S239>/start_vel' */
          FMS_DW.icLoad_lf = 0U;

          /* Update for Delay: '<S234>/Delay' */
          FMS_DW.icLoad_mz = 0U;

          /* End of Outputs for SubSystem: '<S88>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S88>/Unknown' incorporates:
           *  ActionPort: '<S233>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
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
         *  RelationalOperator: '<S200>/FixPt Relational Operator'
         *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S200>/Delay Input1'
         *
         * Block description for '<S200>/Delay Input1':
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
           *  ActionPort: '<S198>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S198>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S198>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S198>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_f1;

          /* End of Outputs for SubSystem: '<S86>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_hd != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S86>/Mission' incorporates:
             *  ActionPort: '<S197>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S86>/Switch Case' incorporates:
             *  UnitDelay: '<S200>/Delay Input1'
             *
             * Block description for '<S200>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_dy = 0U;

            /* End of InitializeConditions for SubSystem: '<S86>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S86>/Mission' incorporates:
           *  ActionPort: '<S197>/Action Port'
           */
          /* Outputs for Resettable SubSystem: '<S197>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S201>/Reset'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE_k = (ZCSigState)
            (FMS_B.wp_index != FMS_DW.DelayInput1_DSTATE_dy);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S220>/Math Function' incorporates:
           *  RelationalOperator: '<S200>/FixPt Relational Operator'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S200>/Delay Input1'
           *
           * Block description for '<S200>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_Subtract_hb[0] = rtb_Sign5_l;
          rtb_Subtract_hb[1] = rtb_a_bx;

          /* Sum: '<S220>/Sum of Elements' */
          rtb_Saturation_e = rtb_Sign5_l + rtb_a_bx;

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
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S220>/Product'
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

          /* End of Switch: '<S220>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S210>/NearbyRefWP' incorporates:
           *  Constant: '<S208>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.FW_L1, rtb_Subtract_hb,
                          &rtb_Divide_pr_idx_1);

          /* MATLAB Function: '<S210>/SearchL1RefWP' incorporates:
           *  Constant: '<S208>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                            FMS_PARAM.FW_L1, rtb_Divide_i5, &rtb_Saturation_e);

          /* MATLAB Function: '<S210>/OutRegionRegWP' incorporates:
           *  Constant: '<S208>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                             FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                             FMS_PARAM.FW_L1, rtb_P_cg);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S210>/Switch1' incorporates:
           *  Constant: '<S213>/Constant'
           *  RelationalOperator: '<S213>/Compare'
           */
          if (rtb_Divide_pr_idx_1 > 0.0F) {
            rtb_Divide_i5[0] = rtb_Subtract_hb[0];
            rtb_Divide_i5[1] = rtb_Subtract_hb[1];
          } else {
            /* RelationalOperator: '<S212>/Compare' incorporates:
             *  Constant: '<S212>/Constant'
             */
            rtb_FixPtRelationalOperator_me = (rtb_Saturation_e >= 0.0F);

            /* Switch: '<S210>/Switch' */
            if (!rtb_FixPtRelationalOperator_me) {
              rtb_Divide_i5[0] = rtb_P_cg[0];
              rtb_Divide_i5[1] = rtb_P_cg[1];
            }

            /* End of Switch: '<S210>/Switch' */
          }

          /* End of Switch: '<S210>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S211>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Subtract_hb[0] = rtb_Divide_i5[0] - FMS_U.INS_Out.x_R;
          rtb_Subtract_hb[1] = rtb_Divide_i5[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S221>/Sum of Elements' incorporates:
           *  Math: '<S221>/Math Function'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Subtract_hb[0] +
            rtb_Subtract_hb[1] * rtb_Subtract_hb[1];

          /* Math: '<S221>/Math Function1' incorporates:
           *  Sum: '<S221>/Sum of Elements'
           *
           * About '<S221>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S221>/Math Function1' */

          /* Switch: '<S221>/Switch' incorporates:
           *  Constant: '<S221>/Constant'
           *  Product: '<S221>/Product'
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

          /* End of Switch: '<S221>/Switch' */

          /* Product: '<S220>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Subtract_hb[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S223>/Sum of Elements' incorporates:
           *  Math: '<S223>/Math Function'
           *  SignalConversion: '<S223>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S223>/Math Function1' incorporates:
           *  Sum: '<S223>/Sum of Elements'
           *
           * About '<S223>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S223>/Math Function1' */

          /* Switch: '<S223>/Switch' incorporates:
           *  Constant: '<S223>/Constant'
           *  Product: '<S223>/Product'
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

          /* End of Switch: '<S223>/Switch' */

          /* Product: '<S221>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S224>/Sum of Elements' incorporates:
           *  Math: '<S224>/Math Function'
           *  SignalConversion: '<S224>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[1] * rtb_Subtract_hb[1] +
            rtb_Subtract_hb[0] * rtb_Subtract_hb[0];

          /* Math: '<S224>/Math Function1' incorporates:
           *  Sum: '<S224>/Sum of Elements'
           *
           * About '<S224>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S224>/Math Function1' */

          /* Switch: '<S224>/Switch' incorporates:
           *  Constant: '<S224>/Constant'
           *  Product: '<S224>/Product'
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

          /* End of Switch: '<S224>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S205>/Sum' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Saturation_e = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Divide_lr_idx_3 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S224>/Divide' */
          rtb_Subtract_hb[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S223>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S205>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Sign5_l = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint
            [0];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S224>/Divide' */
          rtb_Subtract_hb[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S223>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S205>/Sum1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S205>/Divide' incorporates:
           *  Math: '<S206>/Square'
           *  Math: '<S207>/Square'
           *  Sqrt: '<S206>/Sqrt'
           *  Sqrt: '<S207>/Sqrt'
           *  Sum: '<S205>/Sum'
           *  Sum: '<S205>/Sum1'
           *  Sum: '<S206>/Sum of Elements'
           *  Sum: '<S207>/Sum of Elements'
           */
          rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3 * rtb_Divide_lr_idx_3
            + rtb_Saturation_e * rtb_Saturation_e) / sqrtf(rtb_Sign5_l *
            rtb_Sign5_l + rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2);

          /* Saturate: '<S205>/Saturation' */
          if (rtb_Divide_pr_idx_1 > 1.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = 0.0F;
            }
          }

          /* End of Saturate: '<S205>/Saturation' */

          /* Sum: '<S222>/Subtract' incorporates:
           *  Product: '<S222>/Multiply'
           *  Product: '<S222>/Multiply1'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] * rtb_Divide_i5[1] -
            rtb_Subtract_hb[1] * rtb_Divide_i5[0];

          /* Signum: '<S218>/Sign1' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S218>/Sign1' */

          /* Switch: '<S218>/Switch2' incorporates:
           *  Constant: '<S218>/Constant4'
           */
          if (rtb_Saturation_e == 0.0F) {
            rtb_Saturation_e = 1.0F;
          }

          /* End of Switch: '<S218>/Switch2' */

          /* DotProduct: '<S218>/Dot Product' */
          rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Subtract_hb[0] +
            rtb_Divide_i5[1] * rtb_Subtract_hb[1];

          /* Trigonometry: '<S218>/Acos' incorporates:
           *  DotProduct: '<S218>/Dot Product'
           */
          if (rtb_Divide_pr_idx_0 > 1.0F) {
            rtb_Divide_pr_idx_0 = 1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 < -1.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            }
          }

          /* Product: '<S218>/Multiply' incorporates:
           *  Trigonometry: '<S218>/Acos'
           */
          rtb_Saturation_e *= acosf(rtb_Divide_pr_idx_0);

          /* Saturate: '<S217>/Saturation' */
          if (rtb_Saturation_e > 1.57079637F) {
            rtb_Saturation_e = 1.57079637F;
          } else {
            if (rtb_Saturation_e < -1.57079637F) {
              rtb_Saturation_e = -1.57079637F;
            }
          }

          /* End of Saturate: '<S217>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S201>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S201>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S201>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ll;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l5;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_a0;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S203>/Switch' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            /* BusAssignment: '<S201>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Cmd_In.set_speed;
          } else {
            /* BusAssignment: '<S201>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Constant: '<S203>/Constant4'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S203>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S217>/Divide' incorporates:
           *  Constant: '<S208>/L1'
           *  Gain: '<S217>/Gain'
           *  Math: '<S217>/Square'
           *  Product: '<S217>/Multiply1'
           *  Trigonometry: '<S217>/Sin'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
            arm_sin_f32(rtb_Saturation_e) / FMS_PARAM.FW_L1;

          /* Saturate: '<S208>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S201>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S201>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S201>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S208>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S202>/Gain' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S205>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S202>/Sum2'
           *  Sum: '<S205>/Add'
           *  Sum: '<S205>/Subtract'
           */
          rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
            - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Divide_pr_idx_1 +
            FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.FW_Z_P;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S202>/Saturation1' */
          if (rtb_Saturation_e > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S201>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S201>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S201>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S202>/Saturation1' */
          /* End of Outputs for SubSystem: '<S197>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S200>/Delay Input1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S200>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_dy = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S86>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S86>/Unknown' incorporates:
           *  ActionPort: '<S199>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
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
            /* Disable for SwitchCase: '<S135>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

            /* Disable for SwitchCase: '<S121>/Switch Case' */
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
             *  DiscreteIntegrator: '<S190>/Integrator'
             *  DiscreteIntegrator: '<S190>/Integrator1'
             *  DiscreteIntegrator: '<S191>/Integrator'
             *  DiscreteIntegrator: '<S191>/Integrator1'
             *  DiscreteIntegrator: '<S195>/Integrator'
             *  DiscreteIntegrator: '<S195>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_he = 0.0F;
            FMS_DW.Integrator_DSTATE_av = 0.0F;
            FMS_DW.Integrator1_DSTATE_o = 0.0F;
            FMS_DW.Integrator1_DSTATE_mx = 0.0F;
            FMS_DW.Integrator_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_ky = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S85>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S85>/Stabilize' incorporates:
           *  ActionPort: '<S92>/Action Port'
           */
          /* Product: '<S192>/Multiply1' incorporates:
           *  Constant: '<S192>/const1'
           *  DiscreteIntegrator: '<S190>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_av * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S188>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S188>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S192>/Add' incorporates:
           *  DiscreteIntegrator: '<S190>/Integrator1'
           *  Gain: '<S185>/Gain'
           *  Gain: '<S188>/Gain'
           *  Sum: '<S190>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE_he - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.FW_ROLL_LIM) +
            rtb_a_bx;

          /* Signum: '<S192>/Sign' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
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
          d = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) + FMS_ConstB.d_ny) *
                     FMS_ConstB.d_ny) - FMS_ConstB.d_ny) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_a_bx;

          /* Sum: '<S192>/Add4' */
          rtb_Saturation_e = (rtb_Divide_lr_idx_2 - d) + rtb_a_bx;

          /* Sum: '<S192>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_ny;

          /* Sum: '<S192>/Subtract1' */
          rtb_Divide_lr_idx_2 -= FMS_ConstB.d_ny;

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
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S192>/Sign2' */

          /* Sum: '<S192>/Add5' incorporates:
           *  Gain: '<S192>/Gain2'
           *  Product: '<S192>/Multiply4'
           *  Sum: '<S192>/Subtract2'
           */
          d += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) * 0.5F *
            rtb_Saturation_e;

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S92>/Bus Assignment'
           *  Constant: '<S92>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S92>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DiscreteIntegrator: '<S190>/Integrator1'
           *  DiscreteIntegrator: '<S191>/Integrator1'
           *  DiscreteIntegrator: '<S195>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_lx;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_f;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_he;
          FMS_Y.FMS_Out.theta_cmd = FMS_DW.Integrator1_DSTATE_o;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_mx;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S187>/Saturation' incorporates:
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

          /* End of Saturate: '<S187>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S92>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S187>/Constant5'
           *  Gain: '<S187>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S187>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(1000.0F
            * rtb_Saturation_e), 65536.0F) + 1000U);

          /* Product: '<S196>/Multiply1' incorporates:
           *  Constant: '<S196>/const1'
           *  DiscreteIntegrator: '<S195>/Integrator'
           */
          rtb_a_bx = FMS_DW.Integrator_DSTATE_g * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S194>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S194>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S196>/Add' incorporates:
           *  DiscreteIntegrator: '<S195>/Integrator1'
           *  Gain: '<S186>/Gain1'
           *  Gain: '<S194>/Gain'
           *  Sum: '<S195>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_mx - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation_e * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_a_bx;

          /* Signum: '<S196>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S196>/Sign' */

          /* Sum: '<S196>/Add2' incorporates:
           *  Abs: '<S196>/Abs'
           *  Gain: '<S196>/Gain'
           *  Gain: '<S196>/Gain1'
           *  Product: '<S196>/Multiply2'
           *  Product: '<S196>/Multiply3'
           *  Sqrt: '<S196>/Sqrt'
           *  Sum: '<S196>/Add1'
           *  Sum: '<S196>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_hr) * FMS_ConstB.d_hr) - FMS_ConstB.d_hr) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_a_bx;

          /* Sum: '<S196>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_a_bx;

          /* Sum: '<S196>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_hr;

          /* Sum: '<S196>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_hr;

          /* Signum: '<S196>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S196>/Sign1' */

          /* Signum: '<S196>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S196>/Sign2' */

          /* Sum: '<S196>/Add5' incorporates:
           *  Gain: '<S196>/Gain2'
           *  Product: '<S196>/Multiply4'
           *  Sum: '<S196>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Sum: '<S196>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_hr;

          /* Sum: '<S196>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_hr;

          /* Product: '<S196>/Divide' */
          rtb_Divide_or = rtb_Divide_lr_idx_2 / FMS_ConstB.d_hr;

          /* Signum: '<S196>/Sign5' incorporates:
           *  Signum: '<S196>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Sign5_mn = -1.0F;

            /* Signum: '<S196>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Sign5_mn = 1.0F;

            /* Signum: '<S196>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_mn = rtb_Divide_lr_idx_2;

            /* Signum: '<S196>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S196>/Sign5' */

          /* Product: '<S193>/Multiply1' incorporates:
           *  Constant: '<S193>/const1'
           *  DiscreteIntegrator: '<S191>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_ky * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S189>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S189>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S193>/Add' incorporates:
           *  DiscreteIntegrator: '<S191>/Integrator1'
           *  Gain: '<S185>/Gain1'
           *  Gain: '<S189>/Gain'
           *  Sum: '<S191>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_o - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.FW_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S193>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S193>/Sign' */

          /* Sum: '<S193>/Add2' incorporates:
           *  Abs: '<S193>/Abs'
           *  Gain: '<S193>/Gain'
           *  Gain: '<S193>/Gain1'
           *  Product: '<S193>/Multiply2'
           *  Product: '<S193>/Multiply3'
           *  Sqrt: '<S193>/Sqrt'
           *  Sum: '<S193>/Add1'
           *  Sum: '<S193>/Subtract'
           */
          rtb_a_bx = (sqrtf((8.0F * fabsf(rtb_Saturation_e) + FMS_ConstB.d_my) *
                            FMS_ConstB.d_my) - FMS_ConstB.d_my) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S193>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_Saturation_e - rtb_a_bx) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S193>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_my;

          /* Sum: '<S193>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_my;

          /* Signum: '<S193>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S193>/Sign1' */

          /* Signum: '<S193>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S193>/Sign2' */

          /* Sum: '<S193>/Add5' incorporates:
           *  Gain: '<S193>/Gain2'
           *  Product: '<S193>/Multiply4'
           *  Sum: '<S193>/Subtract2'
           */
          rtb_a_bx += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Update for DiscreteIntegrator: '<S190>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S190>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_he += 0.004F * FMS_DW.Integrator_DSTATE_av;

          /* Sum: '<S192>/Subtract3' */
          rtb_Divide_lr_idx_2 = d - FMS_ConstB.d_ny;

          /* Sum: '<S192>/Add6' */
          rtb_Divide_lr_idx_3 = d + FMS_ConstB.d_ny;

          /* Signum: '<S192>/Sign5' incorporates:
           *  Signum: '<S192>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S192>/Sign6' */
            rtb_Saturation_e = -1.0F;
          } else if (d > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S192>/Sign6' */
            rtb_Saturation_e = 1.0F;
          } else {
            rtb_Sign5_l = d;

            /* Signum: '<S192>/Sign6' */
            rtb_Saturation_e = d;
          }

          /* End of Signum: '<S192>/Sign5' */

          /* Signum: '<S192>/Sign3' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S192>/Sign3' */

          /* Signum: '<S192>/Sign4' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S192>/Sign4' */

          /* Update for DiscreteIntegrator: '<S190>/Integrator' incorporates:
           *  Constant: '<S192>/const'
           *  Gain: '<S192>/Gain3'
           *  Product: '<S192>/Divide'
           *  Product: '<S192>/Multiply5'
           *  Product: '<S192>/Multiply6'
           *  Sum: '<S192>/Subtract4'
           *  Sum: '<S192>/Subtract5'
           *  Sum: '<S192>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_av += ((d / FMS_ConstB.d_ny - rtb_Sign5_l) *
            FMS_ConstB.Gain4_ko * ((rtb_Divide_lr_idx_3 - rtb_Divide_lr_idx_2) *
            0.5F) - rtb_Saturation_e * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S191>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S191>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_o += 0.004F * FMS_DW.Integrator_DSTATE_ky;

          /* Update for DiscreteIntegrator: '<S195>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S195>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mx += 0.004F * FMS_DW.Integrator_DSTATE_g;

          /* Signum: '<S196>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S196>/Sign3' */

          /* Signum: '<S196>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S196>/Sign4' */

          /* Update for DiscreteIntegrator: '<S195>/Integrator' incorporates:
           *  Constant: '<S196>/const'
           *  Gain: '<S196>/Gain3'
           *  Product: '<S196>/Multiply5'
           *  Product: '<S196>/Multiply6'
           *  Sum: '<S196>/Subtract4'
           *  Sum: '<S196>/Subtract5'
           *  Sum: '<S196>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_g += ((rtb_Divide_or - rtb_Sign5_mn) *
            FMS_ConstB.Gain4_n * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
            0.5F) - rtb_Divide_pr_idx_2 * 15.707963F) * 0.004F;

          /* Sum: '<S193>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_a_bx - FMS_ConstB.d_my;

          /* Sum: '<S193>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_a_bx + FMS_ConstB.d_my;

          /* Signum: '<S193>/Sign5' incorporates:
           *  Signum: '<S193>/Sign6'
           */
          if (rtb_a_bx < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S193>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_a_bx > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S193>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_a_bx;

            /* Signum: '<S193>/Sign6' */
            rtb_Sign5_l = rtb_a_bx;
          }

          /* End of Signum: '<S193>/Sign5' */

          /* Signum: '<S193>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S193>/Sign3' */

          /* Signum: '<S193>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S193>/Sign4' */

          /* Update for DiscreteIntegrator: '<S191>/Integrator' incorporates:
           *  Constant: '<S193>/const'
           *  Gain: '<S193>/Gain3'
           *  Product: '<S193>/Divide'
           *  Product: '<S193>/Multiply5'
           *  Product: '<S193>/Multiply6'
           *  Sum: '<S193>/Subtract4'
           *  Sum: '<S193>/Subtract5'
           *  Sum: '<S193>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ky += ((rtb_a_bx / FMS_ConstB.d_my -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_k2 * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 12.566371F) * 0.004F;

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
             *  DiscreteIntegrator: '<S115>/Integrator'
             *  DiscreteIntegrator: '<S115>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_lj = 0.0F;
            FMS_DW.Integrator_DSTATE_i3 = 0.0F;
            FMS_DW.Integrator1_DSTATE_gw = 0.0F;
            FMS_DW.Integrator1_DSTATE_mg = 0.0F;
            FMS_DW.Integrator_DSTATE_l = 0.0F;
            FMS_DW.Integrator_DSTATE_e = 0.0F;

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

          /* Product: '<S111>/Multiply1' incorporates:
           *  Constant: '<S111>/const1'
           *  DiscreteIntegrator: '<S110>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_i3 * 0.04F;

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
           *  Gain: '<S95>/Gain'
           *  Sum: '<S110>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE_lj - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.FW_ROLL_LIM) +
            rtb_Divide_pr_idx_1;

          /* Signum: '<S111>/Sign' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            rtb_Saturation_e = rtb_Divide_lr_idx_2;
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
          d = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) + FMS_ConstB.d_bi) *
                     FMS_ConstB.d_bi) - FMS_ConstB.d_bi) * 0.5F *
            rtb_Saturation_e + rtb_Divide_pr_idx_1;

          /* Sum: '<S111>/Add4' */
          rtb_Saturation_e = (rtb_Divide_lr_idx_2 - d) + rtb_Divide_pr_idx_1;

          /* Sum: '<S111>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_bi;

          /* Sum: '<S111>/Subtract1' */
          rtb_Divide_lr_idx_2 -= FMS_ConstB.d_bi;

          /* Signum: '<S111>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S111>/Sign1' */

          /* Signum: '<S111>/Sign2' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S111>/Sign2' */

          /* Sum: '<S111>/Add5' incorporates:
           *  Gain: '<S111>/Gain2'
           *  Product: '<S111>/Multiply4'
           *  Sum: '<S111>/Subtract2'
           */
          d += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) * 0.5F *
            rtb_Saturation_e;

          /* Sum: '<S111>/Add6' */
          rtb_Divide_pr_idx_1 = d + FMS_ConstB.d_bi;

          /* Sum: '<S111>/Subtract3' */
          rtb_Divide_pr_idx_0 = d - FMS_ConstB.d_bi;

          /* Product: '<S111>/Divide' */
          rtb_a_bx = d / FMS_ConstB.d_bi;

          /* Signum: '<S111>/Sign5' incorporates:
           *  Signum: '<S111>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_or = -1.0F;

            /* Signum: '<S111>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_or = 1.0F;

            /* Signum: '<S111>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Divide_or = d;

            /* Signum: '<S111>/Sign6' */
            rtb_Divide_pr_idx_2 = d;
          }

          /* End of Signum: '<S111>/Sign5' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S90>/Bus Assignment'
           *  Constant: '<S90>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S90>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DiscreteIntegrator: '<S110>/Integrator1'
           *  DiscreteIntegrator: '<S113>/Integrator1'
           *  DiscreteIntegrator: '<S115>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_ih;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_p;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3_c;
          FMS_Y.FMS_Out.phi_cmd = FMS_DW.Integrator1_DSTATE_lj;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_gw;
          FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_mg;

          /* Saturate: '<S98>/Saturation1' */
          if (FMS_B.Merge_j > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S90>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_j < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S90>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S90>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_j;
          }

          /* End of Saturate: '<S98>/Saturation1' */

          /* Product: '<S116>/Multiply1' incorporates:
           *  Constant: '<S116>/const1'
           *  DiscreteIntegrator: '<S115>/Integrator'
           */
          d = FMS_DW.Integrator_DSTATE_l * 0.05F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S97>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < 0.3F) {
            rtb_Saturation_e = 0.3F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S97>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S116>/Add' incorporates:
           *  DiscreteIntegrator: '<S115>/Integrator1'
           *  Gain: '<S97>/Gain'
           *  Sum: '<S115>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_mg -
                              FMS_PARAM.FW_SPEED_MAX * rtb_Saturation_e) + d;

          /* Signum: '<S116>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_MatrixConcatenate1_i_tmp = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_MatrixConcatenate1_i_tmp = 1.0F;
          } else {
            rtb_MatrixConcatenate1_i_tmp = rtb_Saturation_e;
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
          rtb_Subtract3_g = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_d) * FMS_ConstB.d_d) - FMS_ConstB.d_d) * 0.5F *
            rtb_MatrixConcatenate1_i_tmp + d;

          /* Sum: '<S116>/Add4' */
          rtb_Divide_lr_idx_3 = (rtb_Saturation_e - rtb_Subtract3_g) + d;

          /* Sum: '<S116>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_d;

          /* Sum: '<S116>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_d;

          /* Signum: '<S116>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S116>/Sign1' */

          /* Signum: '<S116>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S116>/Sign2' */

          /* Sum: '<S116>/Add5' incorporates:
           *  Gain: '<S116>/Gain2'
           *  Product: '<S116>/Multiply4'
           *  Sum: '<S116>/Subtract2'
           */
          rtb_Subtract3_g += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F *
            rtb_Divide_lr_idx_3;

          /* Sum: '<S116>/Add6' */
          rtb_Divide_lr_idx_2 = rtb_Subtract3_g + FMS_ConstB.d_d;

          /* Sum: '<S116>/Subtract3' */
          rtb_Divide_lr_idx_3 = rtb_Subtract3_g - FMS_ConstB.d_d;

          /* Product: '<S116>/Divide' */
          rtb_Sign5_mn = rtb_Subtract3_g / FMS_ConstB.d_d;

          /* Signum: '<S116>/Sign5' incorporates:
           *  Signum: '<S116>/Sign6'
           */
          if (rtb_Subtract3_g < 0.0F) {
            rtb_Sign5_dc = -1.0F;

            /* Signum: '<S116>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Subtract3_g > 0.0F) {
            rtb_Sign5_dc = 1.0F;

            /* Signum: '<S116>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Sign5_dc = rtb_Subtract3_g;

            /* Signum: '<S116>/Sign6' */
            rtb_Sign5_l = rtb_Subtract3_g;
          }

          /* End of Signum: '<S116>/Sign5' */

          /* Product: '<S114>/Multiply1' incorporates:
           *  Constant: '<S114>/const1'
           *  DiscreteIntegrator: '<S113>/Integrator'
           */
          rtb_Subtract3_g = FMS_DW.Integrator_DSTATE_e * 0.02F;

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
           *  Gain: '<S96>/Gain1'
           *  Sum: '<S113>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_gw - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation_e * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Subtract3_g;

          /* Signum: '<S114>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_MatrixConcatenate1_i_tmp = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_MatrixConcatenate1_i_tmp = 1.0F;
          } else {
            rtb_MatrixConcatenate1_i_tmp = rtb_Saturation_e;
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
          d = (sqrtf((8.0F * fabsf(rtb_Saturation_e) + FMS_ConstB.d_nt) *
                     FMS_ConstB.d_nt) - FMS_ConstB.d_nt) * 0.5F *
            rtb_MatrixConcatenate1_i_tmp + rtb_Subtract3_g;

          /* Sum: '<S114>/Add4' */
          rtb_Subtract3_g += rtb_Saturation_e - d;

          /* Sum: '<S114>/Add3' */
          rtb_MatrixConcatenate1_i_tmp = rtb_Saturation_e + FMS_ConstB.d_nt;

          /* Sum: '<S114>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_nt;

          /* Signum: '<S114>/Sign1' */
          if (rtb_MatrixConcatenate1_i_tmp < 0.0F) {
            rtb_MatrixConcatenate1_i_tmp = -1.0F;
          } else {
            if (rtb_MatrixConcatenate1_i_tmp > 0.0F) {
              rtb_MatrixConcatenate1_i_tmp = 1.0F;
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
          d += (rtb_MatrixConcatenate1_i_tmp - rtb_Saturation_e) * 0.5F *
            rtb_Subtract3_g;

          /* Update for DiscreteIntegrator: '<S110>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S110>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_lj += 0.004F * FMS_DW.Integrator_DSTATE_i3;

          /* Signum: '<S111>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S111>/Sign3' */

          /* Signum: '<S111>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S111>/Sign4' */

          /* Update for DiscreteIntegrator: '<S110>/Integrator' incorporates:
           *  Constant: '<S111>/const'
           *  Gain: '<S111>/Gain3'
           *  Product: '<S111>/Multiply5'
           *  Product: '<S111>/Multiply6'
           *  Sum: '<S111>/Subtract4'
           *  Sum: '<S111>/Subtract5'
           *  Sum: '<S111>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i3 += ((rtb_a_bx - rtb_Divide_or) *
            FMS_ConstB.Gain4_d1 * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
            0.5F) - rtb_Divide_pr_idx_2 * 12.566371F) * 0.004F;

          /* Update for DiscreteIntegrator: '<S113>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S113>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_gw += 0.004F * FMS_DW.Integrator_DSTATE_e;

          /* Update for DiscreteIntegrator: '<S115>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S115>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_mg += 0.004F * FMS_DW.Integrator_DSTATE_l;

          /* Signum: '<S116>/Sign3' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S116>/Sign3' */

          /* Signum: '<S116>/Sign4' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S116>/Sign4' */

          /* Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
           *  Constant: '<S116>/const'
           *  Gain: '<S116>/Gain3'
           *  Product: '<S116>/Multiply5'
           *  Product: '<S116>/Multiply6'
           *  Sum: '<S116>/Subtract4'
           *  Sum: '<S116>/Subtract5'
           *  Sum: '<S116>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_l += ((rtb_Sign5_mn - rtb_Sign5_dc) *
            FMS_ConstB.Gain4_p2 * ((rtb_Divide_lr_idx_2 - rtb_Divide_lr_idx_3) *
            0.5F) - rtb_Sign5_l * 78.448F) * 0.004F;

          /* Sum: '<S114>/Subtract3' */
          rtb_Divide_pr_idx_1 = d - FMS_ConstB.d_nt;

          /* Sum: '<S114>/Add6' */
          rtb_Divide_pr_idx_0 = d + FMS_ConstB.d_nt;

          /* Signum: '<S114>/Sign5' incorporates:
           *  Signum: '<S114>/Sign6'
           */
          if (d < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S114>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (d > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S114>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = d;

            /* Signum: '<S114>/Sign6' */
            rtb_Sign5_l = d;
          }

          /* End of Signum: '<S114>/Sign5' */

          /* Signum: '<S114>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S114>/Sign3' */

          /* Signum: '<S114>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S114>/Sign4' */

          /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
           *  Constant: '<S114>/const'
           *  Gain: '<S114>/Gain3'
           *  Product: '<S114>/Divide'
           *  Product: '<S114>/Multiply5'
           *  Product: '<S114>/Multiply6'
           *  Sum: '<S114>/Subtract4'
           *  Sum: '<S114>/Subtract5'
           *  Sum: '<S114>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_e += ((d / FMS_ConstB.d_nt -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_kf * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 15.707963F) * 0.004F;

          /* End of Outputs for SubSystem: '<S85>/Altitude' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S85>/Position' incorporates:
             *  ActionPort: '<S91>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S85>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S133>/Integrator'
             *  DiscreteIntegrator: '<S133>/Integrator1'
             *  DiscreteIntegrator: '<S183>/Integrator'
             *  DiscreteIntegrator: '<S183>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_l = 0.0F;
            FMS_DW.Integrator1_DSTATE_nd = 0.0F;
            FMS_DW.Integrator_DSTATE_a = 0.0F;
            FMS_DW.Integrator_DSTATE_ha = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S85>/Position' */

            /* SystemReset for IfAction SubSystem: '<S85>/Position' incorporates:
             *  ActionPort: '<S91>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S85>/Switch Case' incorporates:
             *  Chart: '<S122>/Motion Status'
             *  Chart: '<S136>/Motion State'
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
          /* Outputs for IfAction SubSystem: '<S135>/Hold Control' incorporates:
           *  ActionPort: '<S138>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SwitchCase: '<S135>/Switch Case' incorporates:
           *  Gain: '<S180>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S169>/Trigonometric Function1'
           *  Trigonometry: '<S169>/Trigonometric Function3'
           *  Trigonometry: '<S181>/Trigonometric Function1'
           *  Trigonometry: '<S181>/Trigonometric Function3'
           */
          rtb_Sign5_l = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S135>/Hold Control' */

          /* Trigonometry: '<S181>/Trigonometric Function1' */
          rtb_VectorConcatenate_h[0] = rtb_Sign5_l;

          /* Outputs for IfAction SubSystem: '<S135>/Hold Control' incorporates:
           *  ActionPort: '<S138>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SwitchCase: '<S135>/Switch Case' incorporates:
           *  Gain: '<S180>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S169>/Trigonometric Function'
           *  Trigonometry: '<S181>/Trigonometric Function'
           *  Trigonometry: '<S181>/Trigonometric Function2'
           */
          rtb_a_bx = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S135>/Hold Control' */

          /* Trigonometry: '<S181>/Trigonometric Function' */
          rtb_VectorConcatenate_h[1] = rtb_a_bx;

          /* SignalConversion: '<S181>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S181>/Constant3'
           */
          rtb_VectorConcatenate_h[2] = 0.0F;

          /* Gain: '<S181>/Gain' */
          rtb_VectorConcatenate_h[3] = -rtb_a_bx;

          /* Trigonometry: '<S181>/Trigonometric Function3' */
          rtb_VectorConcatenate_h[4] = rtb_Sign5_l;

          /* SignalConversion: '<S181>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S181>/Constant4'
           */
          rtb_VectorConcatenate_h[5] = 0.0F;

          /* SignalConversion: '<S181>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_gy[0];
          rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_gy[1];
          rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_gy[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S122>/Motion Status' incorporates:
           *  Abs: '<S122>/Abs'
           *  Abs: '<S122>/Abs1'
           *  Constant: '<S130>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S130>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
                           FMS_PARAM.PITCH_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_m);

          /* Logic: '<S136>/Logical Operator' incorporates:
           *  Abs: '<S136>/Abs1'
           *  Abs: '<S136>/Abs2'
           *  Constant: '<S177>/Constant'
           *  Constant: '<S178>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S177>/Compare'
           *  RelationalOperator: '<S178>/Compare'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_yaw) >
            FMS_PARAM.YAW_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S136>/Motion State' incorporates:
           *  Abs: '<S136>/Abs'
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

              /* Product: '<S136>/Multiply' incorporates:
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

              /* End of Product: '<S136>/Multiply' */
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

          /* End of Chart: '<S136>/Motion State' */

          /* SwitchCase: '<S135>/Switch Case' */
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
              /* InitializeConditions for IfAction SubSystem: '<S135>/Hold Control' incorporates:
               *  ActionPort: '<S138>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S135>/Switch Case' incorporates:
               *  Delay: '<S143>/start_vel'
               *  Delay: '<S143>/start_wp'
               *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
               *  DiscreteIntegrator: '<S173>/Discrete-Time Integrator1'
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

              /* End of InitializeConditions for SubSystem: '<S135>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S135>/Hold Control' incorporates:
             *  ActionPort: '<S138>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Product: '<S146>/Divide' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.quat[0] / d;
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.quat[1] / d;
            rtb_Divide_pr_idx_2 = FMS_U.INS_Out.quat[2] / d;
            rtb_Saturation_e = FMS_U.INS_Out.quat[3] / d;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S147>/Subtract' incorporates:
             *  Math: '<S147>/Square'
             *  Math: '<S147>/Square1'
             *  Math: '<S147>/Square2'
             *  Math: '<S147>/Square3'
             *  Sum: '<S147>/Add'
             *  Sum: '<S147>/Add1'
             */
            rtb_VectorConcatenate_h[0] = (rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1) -
              (rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2 + rtb_Saturation_e *
               rtb_Saturation_e);

            /* Gain: '<S147>/Gain' incorporates:
             *  Product: '<S147>/Multiply'
             *  Product: '<S147>/Multiply1'
             *  Sum: '<S147>/Subtract1'
             */
            rtb_VectorConcatenate_h[1] = (rtb_Divide_pr_idx_1 *
              rtb_Divide_pr_idx_2 - rtb_Divide_pr_idx_0 * rtb_Saturation_e) *
              2.0F;

            /* Gain: '<S147>/Gain1' incorporates:
             *  Product: '<S147>/Multiply2'
             *  Product: '<S147>/Multiply3'
             *  Sum: '<S147>/Add2'
             */
            rtb_VectorConcatenate_h[2] = (rtb_Divide_pr_idx_1 * rtb_Saturation_e
              + rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_2) * 2.0F;

            /* Gain: '<S148>/Gain' incorporates:
             *  Product: '<S148>/Multiply'
             *  Product: '<S148>/Multiply1'
             *  Sum: '<S148>/Add3'
             */
            rtb_VectorConcatenate_h[3] = (rtb_Divide_pr_idx_1 *
              rtb_Divide_pr_idx_2 + rtb_Divide_pr_idx_0 * rtb_Saturation_e) *
              2.0F;

            /* Sum: '<S148>/Subtract' incorporates:
             *  Math: '<S148>/Square'
             *  Math: '<S148>/Square1'
             *  Math: '<S148>/Square2'
             *  Math: '<S148>/Square3'
             *  Sum: '<S148>/Add'
             *  Sum: '<S148>/Add1'
             */
            rtb_VectorConcatenate_h[4] = (rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2) -
              (rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 + rtb_Saturation_e *
               rtb_Saturation_e);

            /* Gain: '<S148>/Gain1' incorporates:
             *  Product: '<S148>/Multiply2'
             *  Product: '<S148>/Multiply3'
             *  Sum: '<S148>/Subtract1'
             */
            rtb_VectorConcatenate_h[5] = (rtb_Divide_pr_idx_2 * rtb_Saturation_e
              - rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_1) * 2.0F;

            /* Gain: '<S149>/Gain' incorporates:
             *  Product: '<S149>/Multiply'
             *  Product: '<S149>/Multiply1'
             *  Sum: '<S149>/Subtract2'
             */
            rtb_VectorConcatenate_h[6] = (rtb_Divide_pr_idx_1 * rtb_Saturation_e
              - rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_2) * 2.0F;

            /* Gain: '<S149>/Gain1' incorporates:
             *  Product: '<S149>/Multiply2'
             *  Product: '<S149>/Multiply3'
             *  Sum: '<S149>/Add2'
             */
            rtb_VectorConcatenate_h[7] = (rtb_Divide_pr_idx_2 * rtb_Saturation_e
              + rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_1) * 2.0F;

            /* Sum: '<S149>/Subtract' incorporates:
             *  Math: '<S149>/Square'
             *  Math: '<S149>/Square1'
             *  Math: '<S149>/Square2'
             *  Math: '<S149>/Square3'
             *  Sum: '<S149>/Add'
             *  Sum: '<S149>/Add1'
             */
            rtb_VectorConcatenate_h[8] = (rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Saturation_e * rtb_Saturation_e) -
              (rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2 *
               rtb_Divide_pr_idx_2);

            /* Product: '<S140>/Multiply' incorporates:
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

            /* End of Product: '<S140>/Multiply' */

            /* Trigonometry: '<S169>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = rtb_Sign5_l;

            /* Trigonometry: '<S169>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = rtb_a_bx;

            /* SignalConversion: '<S169>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S169>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S169>/Gain' incorporates:
             *  Gain: '<S168>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S169>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S169>/Trigonometric Function3' */
            rtb_VectorConcatenate_h[4] = rtb_Sign5_l;

            /* SignalConversion: '<S169>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S169>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* SignalConversion: '<S169>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_lr[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_lr[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_lr[2];

            /* Delay: '<S143>/start_vel' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            if (FMS_DW.icLoad_g != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.start_vel_DSTATE_l[0] = FMS_U.INS_Out.vn;
              FMS_DW.start_vel_DSTATE_l[1] = FMS_U.INS_Out.ve;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* Math: '<S164>/Math Function' incorporates:
             *  Delay: '<S143>/start_vel'
             */
            rtb_Subtract_hb[0] = FMS_DW.start_vel_DSTATE_l[0] *
              FMS_DW.start_vel_DSTATE_l[0];
            rtb_Subtract_hb[1] = FMS_DW.start_vel_DSTATE_l[1] *
              FMS_DW.start_vel_DSTATE_l[1];

            /* Sum: '<S164>/Sum of Elements' */
            rtb_Saturation_e = rtb_Subtract_hb[0] + rtb_Subtract_hb[1];

            /* Math: '<S164>/Math Function1' incorporates:
             *  Sum: '<S164>/Sum of Elements'
             *
             * About '<S164>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Divide_pr_idx_1 = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S164>/Math Function1' */

            /* Switch: '<S164>/Switch' incorporates:
             *  Constant: '<S164>/Constant'
             *  Delay: '<S143>/start_vel'
             *  Product: '<S164>/Product'
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

            /* End of Switch: '<S164>/Switch' */

            /* Delay: '<S143>/start_wp' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            if (FMS_DW.icLoad_ef != 0) {
              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              FMS_DW.start_wp_DSTATE_p[0] = FMS_U.INS_Out.x_R;
              FMS_DW.start_wp_DSTATE_p[1] = FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            }

            /* End of Delay: '<S143>/start_wp' */

            /* Product: '<S164>/Divide' */
            rtb_Divide_i5[0] = rtb_Switch_ee[0] / rtb_Switch_ee[2];
            rtb_Divide_i5[1] = rtb_Switch_ee[1] / rtb_Switch_ee[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* MATLAB Function: '<S141>/SearchL1RefWP' incorporates:
             *  Constant: '<S138>/L1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            FMS_SearchL1RefWP_k(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                                FMS_DW.start_wp_DSTATE_p, rtb_Divide_i5,
                                FMS_PARAM.FW_L1, rtb_Subtract_hb,
                                &rtb_Saturation_e);

            /* MATLAB Function: '<S141>/OutRegionRefWP' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            FMS_OutRegionRefWP(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               FMS_DW.start_wp_DSTATE_p, rtb_Divide_i5, rtb_P_dg);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S167>/Multiply' incorporates:
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

            /* End of Product: '<S167>/Multiply' */

            /* DiscreteIntegrator: '<S171>/Discrete-Time Integrator' */
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

            /* DiscreteIntegrator: '<S173>/Discrete-Time Integrator1' incorporates:
             *  Constant: '<S165>/Constant'
             *  Sum: '<S165>/Sum'
             */
            if (FMS_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
              FMS_DW.DiscreteTimeIntegrator1_DSTA_jv = 0.0F -
                rtb_VectorConcatenate_g0[1];
            }

            if (FMS_DW.DiscreteTimeIntegrator1_PrevR_p != 0) {
              FMS_DW.DiscreteTimeIntegrator1_DSTA_jv = 0.0F -
                rtb_VectorConcatenate_g0[1];
            }

            /* Signum: '<S140>/Sign' incorporates:
             *  Math: '<S157>/Square'
             *  Math: '<S158>/Math Function1'
             *  Math: '<S159>/Math Function'
             *  Sum: '<S142>/Subtract'
             *  Switch: '<S138>/Switch'
             *  Switch: '<S141>/Switch'
             *
             * About '<S158>/Math Function1':
             *  Operator: sqrt
             */
            if ((rtb_Switch_an[0] < 0.0F) || (rtb_Switch_an[0] <= 0.0F)) {
              /* Switch: '<S138>/Switch' incorporates:
               *  Constant: '<S165>/Constant'
               *  Constant: '<S172>/kp'
               *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
               *  Product: '<S172>/Multiply'
               *  Sum: '<S165>/Sum'
               *  Sum: '<S166>/Add'
               */
              FMS_B.Merge_be = (0.0F - rtb_VectorConcatenate_g0[1]) * 1.2F +
                FMS_DW.DiscreteTimeIntegrator_DSTATE_k;
            } else {
              if (rtb_Divide_lr_idx_3 < 0.0F) {
                /* Math: '<S158>/Math Function1' incorporates:
                 *  Switch: '<S138>/Switch'
                 *
                 * About '<S158>/Math Function1':
                 *  Operator: sqrt
                 */
                rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
              } else {
                /* Math: '<S158>/Math Function1' incorporates:
                 *  Switch: '<S138>/Switch'
                 *
                 * About '<S158>/Math Function1':
                 *  Operator: sqrt
                 */
                rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
              }

              /* Switch: '<S158>/Switch' incorporates:
               *  Constant: '<S158>/Constant'
               *  Inport: '<Root>/INS_Out'
               *  Product: '<S158>/Product'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Switch: '<S138>/Switch'
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

              /* End of Switch: '<S158>/Switch' */

              /* Product: '<S158>/Divide' incorporates:
               *  Switch: '<S138>/Switch'
               */
              rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

              /* RelationalOperator: '<S151>/Compare' incorporates:
               *  Constant: '<S151>/Constant'
               *  Switch: '<S138>/Switch'
               */
              rtb_FixPtRelationalOperator_me = (rtb_Saturation_e > 0.0F);

              /* Switch: '<S141>/Switch' incorporates:
               *  Switch: '<S138>/Switch'
               */
              if (rtb_FixPtRelationalOperator_me) {
                rtb_Divide_pr_idx_1 = rtb_Subtract_hb[0];
              } else {
                rtb_Divide_pr_idx_1 = rtb_P_dg[0];
              }

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              /* Sum: '<S142>/Subtract' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Switch: '<S138>/Switch'
               */
              rtb_Divide_pr_idx_2 = rtb_Divide_pr_idx_1 - FMS_U.INS_Out.x_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
              rtb_Subtract_hb[0] = rtb_Divide_pr_idx_2;
              rtb_Square_ds[0] = rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2;

              /* Switch: '<S141>/Switch' incorporates:
               *  Math: '<S159>/Math Function'
               *  Sum: '<S142>/Subtract'
               *  Switch: '<S138>/Switch'
               */
              if (rtb_FixPtRelationalOperator_me) {
                rtb_Divide_pr_idx_1 = rtb_Subtract_hb[1];
              } else {
                rtb_Divide_pr_idx_1 = rtb_P_dg[1];
              }

              /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
              /* Sum: '<S142>/Subtract' incorporates:
               *  Inport: '<Root>/INS_Out'
               *  SignalConversion: '<S40>/Signal Copy1'
               *  Switch: '<S138>/Switch'
               */
              rtb_Divide_pr_idx_2 = rtb_Divide_pr_idx_1 - FMS_U.INS_Out.y_R;

              /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

              /* Math: '<S159>/Math Function' incorporates:
               *  Math: '<S157>/Square'
               *  Switch: '<S138>/Switch'
               */
              rtb_Saturation_e = rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2;

              /* Sum: '<S159>/Sum of Elements' incorporates:
               *  Math: '<S159>/Math Function'
               *  Switch: '<S138>/Switch'
               */
              rtb_Divide_lr_idx_3 = rtb_Saturation_e + rtb_Square_ds[0];

              /* Math: '<S159>/Math Function1' incorporates:
               *  Sum: '<S159>/Sum of Elements'
               *  Switch: '<S138>/Switch'
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
               *  Switch: '<S138>/Switch'
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

              /* End of Switch: '<S159>/Switch' */

              /* Product: '<S159>/Divide' incorporates:
               *  Switch: '<S138>/Switch'
               */
              rtb_Square_ds[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Subtract_hb[0] *= rtb_Subtract_hb[0];

              /* Product: '<S159>/Divide' incorporates:
               *  Math: '<S157>/Square'
               *  Switch: '<S138>/Switch'
               */
              rtb_Square_ds[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

              /* Sum: '<S161>/Sum of Elements' incorporates:
               *  Math: '<S161>/Math Function'
               *  SignalConversion: '<S161>/TmpSignal ConversionAtMath FunctionInport1'
               *  Switch: '<S138>/Switch'
               */
              rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
                rtb_Divide_i5[0] * rtb_Divide_i5[0];

              /* Math: '<S161>/Math Function1' incorporates:
               *  Sum: '<S161>/Sum of Elements'
               *  Switch: '<S138>/Switch'
               *
               * About '<S161>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_lr_idx_3 < 0.0F) {
                rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
              } else {
                rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
              }

              /* End of Math: '<S161>/Math Function1' */

              /* Switch: '<S161>/Switch' incorporates:
               *  Constant: '<S161>/Constant'
               *  Product: '<S161>/Product'
               *  Switch: '<S138>/Switch'
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

              /* End of Switch: '<S161>/Switch' */

              /* Product: '<S161>/Divide' incorporates:
               *  Switch: '<S138>/Switch'
               */
              rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

              /* Sum: '<S162>/Sum of Elements' incorporates:
               *  Math: '<S162>/Math Function'
               *  SignalConversion: '<S162>/TmpSignal ConversionAtMath FunctionInport1'
               *  Switch: '<S138>/Switch'
               */
              rtb_Divide_lr_idx_3 = rtb_Square_ds[1] * rtb_Square_ds[1] +
                rtb_Square_ds[0] * rtb_Square_ds[0];

              /* Math: '<S162>/Math Function1' incorporates:
               *  Sum: '<S162>/Sum of Elements'
               *  Switch: '<S138>/Switch'
               *
               * About '<S162>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Divide_lr_idx_3 < 0.0F) {
                rtb_Divide_pr_idx_1 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
              } else {
                rtb_Divide_pr_idx_1 = sqrtf(rtb_Divide_lr_idx_3);
              }

              /* End of Math: '<S162>/Math Function1' */

              /* Switch: '<S162>/Switch' incorporates:
               *  Constant: '<S162>/Constant'
               *  Product: '<S162>/Product'
               *  Switch: '<S138>/Switch'
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

              /* End of Switch: '<S162>/Switch' */

              /* Product: '<S162>/Divide' incorporates:
               *  Switch: '<S138>/Switch'
               */
              rtb_Square_ds[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Square_ds[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

              /* Sum: '<S160>/Subtract' incorporates:
               *  Product: '<S160>/Multiply'
               *  Product: '<S160>/Multiply1'
               *  Switch: '<S138>/Switch'
               */
              rtb_Divide_pr_idx_1 = rtb_Square_ds[0] * rtb_Divide_i5[1] -
                rtb_Square_ds[1] * rtb_Divide_i5[0];

              /* Signum: '<S155>/Sign1' incorporates:
               *  Switch: '<S138>/Switch'
               */
              if (rtb_Divide_pr_idx_1 < 0.0F) {
                rtb_Divide_pr_idx_1 = -1.0F;
              } else {
                if (rtb_Divide_pr_idx_1 > 0.0F) {
                  rtb_Divide_pr_idx_1 = 1.0F;
                }
              }

              /* End of Signum: '<S155>/Sign1' */

              /* Switch: '<S155>/Switch2' incorporates:
               *  Constant: '<S155>/Constant4'
               *  Switch: '<S138>/Switch'
               */
              if (rtb_Divide_pr_idx_1 == 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }

              /* End of Switch: '<S155>/Switch2' */

              /* DotProduct: '<S155>/Dot Product' incorporates:
               *  Switch: '<S138>/Switch'
               */
              rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] * rtb_Square_ds[0] +
                rtb_Divide_i5[1] * rtb_Square_ds[1];

              /* Trigonometry: '<S155>/Acos' incorporates:
               *  DotProduct: '<S155>/Dot Product'
               *  Switch: '<S138>/Switch'
               */
              if (rtb_Divide_pr_idx_0 > 1.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              } else {
                if (rtb_Divide_pr_idx_0 < -1.0F) {
                  rtb_Divide_pr_idx_0 = -1.0F;
                }
              }

              /* Product: '<S155>/Multiply' incorporates:
               *  Switch: '<S138>/Switch'
               *  Trigonometry: '<S155>/Acos'
               */
              rtb_Divide_pr_idx_1 *= acosf(rtb_Divide_pr_idx_0);

              /* Saturate: '<S154>/Saturation' incorporates:
               *  Switch: '<S138>/Switch'
               */
              if (rtb_Divide_pr_idx_1 > 1.57079637F) {
                rtb_Divide_pr_idx_1 = 1.57079637F;
              } else {
                if (rtb_Divide_pr_idx_1 < -1.57079637F) {
                  rtb_Divide_pr_idx_1 = -1.57079637F;
                }
              }

              /* End of Saturate: '<S154>/Saturation' */

              /* Switch: '<S138>/Switch' incorporates:
               *  Constant: '<S138>/L1'
               *  Constant: '<S154>/Constant'
               *  Gain: '<S154>/Gain'
               *  Math: '<S154>/Square'
               *  MinMax: '<S154>/Max'
               *  MinMax: '<S154>/Min'
               *  Product: '<S154>/Divide'
               *  Product: '<S154>/Multiply1'
               *  Sqrt: '<S157>/Sqrt'
               *  Sum: '<S157>/Sum of Elements'
               *  Trigonometry: '<S154>/Sin'
               */
              FMS_B.Merge_be = rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F *
                arm_sin_f32(rtb_Divide_pr_idx_1) / fminf(FMS_PARAM.FW_L1, fmaxf
                (sqrtf(rtb_Saturation_e + rtb_Subtract_hb[0]), 0.5F));
            }

            /* End of Signum: '<S140>/Sign' */

            /* Update for Delay: '<S143>/start_vel' */
            FMS_DW.icLoad_g = 0U;

            /* Update for Delay: '<S143>/start_wp' */
            FMS_DW.icLoad_ef = 0U;

            /* Update for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' incorporates:
             *  Constant: '<S165>/Constant'
             *  Constant: '<S171>/ki'
             *  Product: '<S171>/Multiply'
             *  Sum: '<S165>/Sum'
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

            /* End of Update for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' */

            /* Update for DiscreteIntegrator: '<S173>/Discrete-Time Integrator1' incorporates:
             *  Constant: '<S165>/Constant'
             *  Gain: '<S173>/Gain'
             *  Sum: '<S165>/Sum'
             *  Sum: '<S173>/Sum5'
             */
            FMS_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
            FMS_DW.DiscreteTimeIntegrator1_DSTA_jv += ((0.0F -
              rtb_VectorConcatenate_g0[1]) -
              FMS_DW.DiscreteTimeIntegrator1_DSTA_jv) * 62.831852F * 0.004F;
            FMS_DW.DiscreteTimeIntegrator1_PrevR_p = 0;

            /* End of Outputs for SubSystem: '<S135>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S135>/Brake Control' incorporates:
             *  ActionPort: '<S137>/Action Port'
             */
            /* SignalConversion: '<S137>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
             *  Constant: '<S137>/Brake Speed'
             */
            FMS_B.Merge_be = 0.0F;

            /* End of Outputs for SubSystem: '<S135>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_d != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S135>/Move Control' incorporates:
               *  ActionPort: '<S139>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S135>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S175>/Integrator'
               *  DiscreteIntegrator: '<S175>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_c = 0.0F;
              FMS_DW.Integrator_DSTATE_f1 = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S135>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S135>/Move Control' incorporates:
             *  ActionPort: '<S139>/Action Port'
             */
            /* Product: '<S176>/Multiply1' incorporates:
             *  Constant: '<S176>/const1'
             *  DiscreteIntegrator: '<S175>/Integrator'
             */
            rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_f1 * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S174>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S174>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S176>/Add' incorporates:
             *  DiscreteIntegrator: '<S175>/Integrator1'
             *  Gain: '<S139>/Gain6'
             *  Gain: '<S174>/Gain'
             *  Sum: '<S175>/Subtract'
             */
            rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_c - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.FW_ACC_Y_LIM) +
              rtb_Divide_pr_idx_1;

            /* Signum: '<S176>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            } else {
              rtb_Divide_lr_idx_2 = rtb_Saturation_e;
            }

            /* End of Signum: '<S176>/Sign' */

            /* Sum: '<S176>/Add2' incorporates:
             *  Abs: '<S176>/Abs'
             *  Gain: '<S176>/Gain'
             *  Gain: '<S176>/Gain1'
             *  Product: '<S176>/Multiply2'
             *  Product: '<S176>/Multiply3'
             *  Sqrt: '<S176>/Sqrt'
             *  Sum: '<S176>/Add1'
             *  Sum: '<S176>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
              FMS_ConstB.d_h) * FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F *
              rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

            /* Sum: '<S176>/Add4' */
            rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
              rtb_Divide_pr_idx_1;

            /* Sum: '<S176>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_h;

            /* Sum: '<S176>/Subtract1' */
            rtb_Saturation_e -= FMS_ConstB.d_h;

            /* Signum: '<S176>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S176>/Sign1' */

            /* Signum: '<S176>/Sign2' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else {
              if (rtb_Saturation_e > 0.0F) {
                rtb_Saturation_e = 1.0F;
              }
            }

            /* End of Signum: '<S176>/Sign2' */

            /* Sum: '<S176>/Add5' incorporates:
             *  Gain: '<S176>/Gain2'
             *  Product: '<S176>/Multiply4'
             *  Sum: '<S176>/Subtract2'
             */
            rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S139>/OutportBufferForay_cmd_mPs2' incorporates:
             *  DiscreteIntegrator: '<S175>/Integrator1'
             */
            FMS_B.Merge_be = FMS_DW.Integrator1_DSTATE_c;

            /* Update for DiscreteIntegrator: '<S175>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S175>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_c += 0.004F * FMS_DW.Integrator_DSTATE_f1;

            /* Sum: '<S176>/Subtract3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_h;

            /* Sum: '<S176>/Add6' */
            rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_h;

            /* Signum: '<S176>/Sign5' incorporates:
             *  Signum: '<S176>/Sign6'
             */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;

              /* Signum: '<S176>/Sign6' */
              rtb_Sign5_l = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;

              /* Signum: '<S176>/Sign6' */
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

              /* Signum: '<S176>/Sign6' */
              rtb_Sign5_l = rtb_Divide_lr_idx_2;
            }

            /* End of Signum: '<S176>/Sign5' */

            /* Signum: '<S176>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S176>/Sign3' */

            /* Signum: '<S176>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S176>/Sign4' */

            /* Update for DiscreteIntegrator: '<S175>/Integrator' incorporates:
             *  Constant: '<S176>/const'
             *  Gain: '<S176>/Gain3'
             *  Product: '<S176>/Divide'
             *  Product: '<S176>/Multiply5'
             *  Product: '<S176>/Multiply6'
             *  Sum: '<S176>/Subtract4'
             *  Sum: '<S176>/Subtract5'
             *  Sum: '<S176>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_f1 += ((rtb_Divide_lr_idx_2 /
              FMS_ConstB.d_h - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_b *
              ((rtb_Divide_pr_idx_0 - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l
              * 58.836F) * 0.004F;

            /* End of Outputs for SubSystem: '<S135>/Move Control' */
            break;
          }

          /* SwitchCase: '<S121>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S121>/Hold Control' incorporates:
               *  ActionPort: '<S124>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S121>/Switch Case' */
              FMS_HoldControl_Reset(&FMS_DW.HoldControl_j);

              /* End of SystemReset for SubSystem: '<S121>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S121>/Hold Control' incorporates:
             *  ActionPort: '<S124>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_fb,
                            &FMS_DW.HoldControl_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S121>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S121>/Brake Control' incorporates:
             *  ActionPort: '<S123>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_fb);

            /* End of Outputs for SubSystem: '<S121>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_ad != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S121>/Move Control' incorporates:
               *  ActionPort: '<S125>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S121>/Switch Case' */
              FMS_MoveControl_Reset(&FMS_DW.MoveControl_l);

              /* End of SystemReset for SubSystem: '<S121>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S121>/Move Control' incorporates:
             *  ActionPort: '<S125>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_fb,
                            &FMS_ConstB.MoveControl_l, &FMS_DW.MoveControl_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S121>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S121>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S91>/Bus Assignment'
           *  Constant: '<S91>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S91>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DiscreteIntegrator: '<S133>/Integrator1'
           *  DiscreteIntegrator: '<S183>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_p;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o3;
          FMS_Y.FMS_Out.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_l;
          FMS_Y.FMS_Out.u_cmd = FMS_DW.Integrator1_DSTATE_nd;

          /* Saturate: '<S135>/Saturation1' */
          if (FMS_B.Merge_be > FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S91>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.FW_ACC_Y_LIM;
          } else if (FMS_B.Merge_be < -FMS_PARAM.FW_ACC_Y_LIM) {
            /* BusAssignment: '<S91>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.FW_ACC_Y_LIM;
          } else {
            /* BusAssignment: '<S91>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_be;
          }

          /* End of Saturate: '<S135>/Saturation1' */

          /* Saturate: '<S121>/Saturation1' */
          if (FMS_B.Merge_fb > FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S91>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.FW_VEL_Z_LIM;
          } else if (FMS_B.Merge_fb < -FMS_PARAM.FW_VEL_Z_LIM) {
            /* BusAssignment: '<S91>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.FW_VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S91>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_fb;
          }

          /* End of Saturate: '<S121>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Saturate: '<S120>/Saturation' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > 1.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle < -1.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            rtb_Divide_pr_idx_1 = FMS_U.Pilot_Cmd.stick_throttle;
          }

          /* End of Saturate: '<S120>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S184>/Multiply1' incorporates:
           *  Constant: '<S184>/const1'
           *  DiscreteIntegrator: '<S183>/Integrator'
           */
          rtb_Saturation_e = FMS_DW.Integrator_DSTATE_a * 0.05F;

          /* Switch: '<S182>/Switch' incorporates:
           *  Constant: '<S182>/Constant'
           *  Constant: '<S182>/Constant1'
           *  Constant: '<S182>/Constant2'
           *  Product: '<S182>/Multiply'
           *  Product: '<S182>/Multiply1'
           *  Sum: '<S182>/Subtract'
           *  Sum: '<S182>/Subtract1'
           *  Sum: '<S182>/Sum'
           *  Sum: '<S182>/Sum1'
           */
          if (rtb_Divide_pr_idx_1 >= 0.0F) {
            rtb_Divide_pr_idx_1 = (FMS_PARAM.FW_SPEED_MAX -
              FMS_PARAM.FW_CRUISE_SPEED) * rtb_Divide_pr_idx_1 +
              FMS_PARAM.FW_CRUISE_SPEED;
          } else {
            rtb_Divide_pr_idx_1 = (FMS_PARAM.FW_CRUISE_SPEED -
              FMS_PARAM.FW_SPEED_MIN) * rtb_Divide_pr_idx_1 +
              FMS_PARAM.FW_CRUISE_SPEED;
          }

          /* End of Switch: '<S182>/Switch' */

          /* Sum: '<S184>/Add' incorporates:
           *  DiscreteIntegrator: '<S183>/Integrator1'
           *  Sum: '<S183>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (FMS_DW.Integrator1_DSTATE_nd -
            rtb_Divide_pr_idx_1) + rtb_Saturation_e;

          /* Signum: '<S184>/Sign' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S184>/Sign' */

          /* Sum: '<S184>/Add2' incorporates:
           *  Abs: '<S184>/Abs'
           *  Gain: '<S184>/Gain'
           *  Gain: '<S184>/Gain1'
           *  Product: '<S184>/Multiply2'
           *  Product: '<S184>/Multiply3'
           *  Sqrt: '<S184>/Sqrt'
           *  Sum: '<S184>/Add1'
           *  Sum: '<S184>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_3) +
            FMS_ConstB.d_ad) * FMS_ConstB.d_ad) - FMS_ConstB.d_ad) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Saturation_e;

          /* Sum: '<S184>/Add4' */
          rtb_Saturation_e += rtb_Divide_lr_idx_3 - rtb_Divide_lr_idx_2;

          /* Sum: '<S184>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_ad;

          /* Sum: '<S184>/Subtract1' */
          rtb_Divide_lr_idx_3 -= FMS_ConstB.d_ad;

          /* Signum: '<S184>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S184>/Sign1' */

          /* Signum: '<S184>/Sign2' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S184>/Sign2' */

          /* Sum: '<S184>/Add5' incorporates:
           *  Gain: '<S184>/Gain2'
           *  Product: '<S184>/Multiply4'
           *  Sum: '<S184>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_3) *
            0.5F * rtb_Saturation_e;

          /* Sum: '<S184>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_ad;

          /* Sum: '<S184>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_ad;

          /* Product: '<S184>/Divide' */
          d = rtb_Divide_lr_idx_2 / FMS_ConstB.d_ad;

          /* Signum: '<S184>/Sign5' incorporates:
           *  Signum: '<S184>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S184>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S184>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Divide_lr_idx_2;

            /* Signum: '<S184>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S184>/Sign5' */

          /* Product: '<S134>/Multiply1' incorporates:
           *  Constant: '<S134>/const1'
           *  DiscreteIntegrator: '<S133>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_ha * 0.02F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S132>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S132>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S134>/Add' incorporates:
           *  DiscreteIntegrator: '<S133>/Integrator1'
           *  Gain: '<S118>/Gain1'
           *  Gain: '<S132>/Gain'
           *  Sum: '<S133>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_l - 1.0F / (1.0F -
            FMS_PARAM.YAW_DZ) * rtb_Saturation_e * FMS_PARAM.FW_YAW_RATE_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S134>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S134>/Sign' */

          /* Sum: '<S134>/Add2' incorporates:
           *  Abs: '<S134>/Abs'
           *  Gain: '<S134>/Gain'
           *  Gain: '<S134>/Gain1'
           *  Product: '<S134>/Multiply2'
           *  Product: '<S134>/Multiply3'
           *  Sqrt: '<S134>/Sqrt'
           *  Sum: '<S134>/Add1'
           *  Sum: '<S134>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_l) * FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S134>/Add4' */
          rtb_a_bx = (rtb_Saturation_e - rtb_Divide_lr_idx_3) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S134>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_l;

          /* Sum: '<S134>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_l;

          /* Signum: '<S134>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S134>/Sign1' */

          /* Signum: '<S134>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S134>/Sign2' */

          /* Sum: '<S134>/Add5' incorporates:
           *  Gain: '<S134>/Gain2'
           *  Product: '<S134>/Multiply4'
           *  Sum: '<S134>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F
            * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S133>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S133>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_l += 0.004F * FMS_DW.Integrator_DSTATE_ha;

          /* Update for DiscreteIntegrator: '<S183>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S183>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_nd += 0.004F * FMS_DW.Integrator_DSTATE_a;

          /* Signum: '<S184>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S184>/Sign3' */

          /* Signum: '<S184>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S184>/Sign4' */

          /* Update for DiscreteIntegrator: '<S183>/Integrator' incorporates:
           *  Constant: '<S184>/const'
           *  Gain: '<S184>/Gain3'
           *  Product: '<S184>/Multiply5'
           *  Product: '<S184>/Multiply6'
           *  Sum: '<S184>/Subtract4'
           *  Sum: '<S184>/Subtract5'
           *  Sum: '<S184>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_a += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_f *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 78.448F) * 0.004F;

          /* Sum: '<S134>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_l;

          /* Sum: '<S134>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_l;

          /* Signum: '<S134>/Sign5' incorporates:
           *  Signum: '<S134>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S134>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S134>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S134>/Sign6' */
            rtb_Sign5_l = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S134>/Sign5' */

          /* Signum: '<S134>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S134>/Sign3' */

          /* Signum: '<S134>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S134>/Sign4' */

          /* Update for DiscreteIntegrator: '<S133>/Integrator' incorporates:
           *  Constant: '<S134>/const'
           *  Gain: '<S134>/Gain3'
           *  Product: '<S134>/Divide'
           *  Product: '<S134>/Multiply5'
           *  Product: '<S134>/Multiply6'
           *  Sum: '<S134>/Subtract4'
           *  Sum: '<S134>/Subtract5'
           *  Sum: '<S134>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_ha += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_l
            - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_ak * ((rtb_Divide_pr_idx_0
            - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 15.707963F) * 0.004F;

          /* End of Outputs for SubSystem: '<S85>/Position' */
          break;

         case 3:
          /* Outputs for IfAction SubSystem: '<S85>/Unknown' incorporates:
           *  ActionPort: '<S93>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
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
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  BusAssignment: '<S87>/Bus Assignment'
         *  Constant: '<S87>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S87>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_nu;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_lc;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S225>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S225>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Gain: '<S225>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.p_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_Saturation_e;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S226>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S226>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Gain: '<S226>/Gain'
         *  Gain: '<S87>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.q_cmd = -(1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_Saturation_e);

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S227>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S227>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Gain: '<S227>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.r_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_Saturation_e;

        /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
        /* DeadZone: '<S228>/Dead Zone' incorporates:
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

        /* End of DeadZone: '<S228>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

        /* BusAssignment: '<S87>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Gain: '<S228>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) *
          rtb_Saturation_e;

        /* End of Outputs for SubSystem: '<S46>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S46>/Unknown' incorporates:
         *  ActionPort: '<S89>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
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
      rtb_Sign5_l = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;

      /* Math: '<S57>/Square2' incorporates:
       *  Math: '<S58>/Square2'
       *  Math: '<S59>/Square2'
       */
      rtb_a_bx = rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2;

      /* Math: '<S57>/Square1' incorporates:
       *  Math: '<S58>/Square1'
       *  Math: '<S59>/Square1'
       */
      rtb_Divide_or = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

      /* Math: '<S57>/Square3' incorporates:
       *  Math: '<S58>/Square3'
       *  Math: '<S59>/Square3'
       */
      rtb_Sign5_mn = rtb_Saturation_e * rtb_Saturation_e;

      /* Sum: '<S57>/Subtract' incorporates:
       *  Math: '<S57>/Square'
       *  Math: '<S57>/Square1'
       *  Math: '<S57>/Square2'
       *  Math: '<S57>/Square3'
       *  Sum: '<S57>/Add'
       *  Sum: '<S57>/Add1'
       */
      rtb_MatrixConcatenate1_i[0] = (rtb_Sign5_l + rtb_Divide_or) - (rtb_a_bx +
        rtb_Sign5_mn);

      /* Product: '<S57>/Multiply' incorporates:
       *  Product: '<S58>/Multiply'
       */
      rtb_Sign5_dc = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_2;

      /* Product: '<S57>/Multiply1' incorporates:
       *  Product: '<S58>/Multiply1'
       */
      rtb_Subtract3_g = rtb_Divide_pr_idx_0 * rtb_Saturation_e;

      /* Gain: '<S57>/Gain' incorporates:
       *  Product: '<S57>/Multiply'
       *  Product: '<S57>/Multiply1'
       *  Sum: '<S57>/Subtract1'
       */
      rtb_MatrixConcatenate1_i[1] = (rtb_Sign5_dc - rtb_Subtract3_g) * 2.0F;

      /* Product: '<S57>/Multiply2' incorporates:
       *  Product: '<S59>/Multiply'
       */
      rtb_MatrixConcatenate1_i_tmp = rtb_Divide_pr_idx_1 * rtb_Saturation_e;

      /* Product: '<S57>/Multiply3' incorporates:
       *  Product: '<S59>/Multiply1'
       */
      rtb_MatrixConcatenate1_i_tmp_0 = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_2;

      /* Gain: '<S57>/Gain1' incorporates:
       *  Product: '<S57>/Multiply2'
       *  Product: '<S57>/Multiply3'
       *  Sum: '<S57>/Add2'
       */
      rtb_MatrixConcatenate1_i[2] = (rtb_MatrixConcatenate1_i_tmp +
        rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

      /* Gain: '<S58>/Gain' incorporates:
       *  Sum: '<S58>/Add3'
       */
      rtb_MatrixConcatenate1_i[3] = (rtb_Sign5_dc + rtb_Subtract3_g) * 2.0F;

      /* Sum: '<S58>/Subtract' incorporates:
       *  Sum: '<S58>/Add'
       *  Sum: '<S58>/Add1'
       */
      rtb_MatrixConcatenate1_i[4] = (rtb_Sign5_l + rtb_a_bx) - (rtb_Divide_or +
        rtb_Sign5_mn);

      /* Product: '<S58>/Multiply2' incorporates:
       *  Product: '<S59>/Multiply2'
       */
      rtb_Sign5_dc = rtb_Divide_pr_idx_2 * rtb_Saturation_e;

      /* Product: '<S58>/Multiply3' incorporates:
       *  Product: '<S59>/Multiply3'
       */
      rtb_Subtract3_g = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_1;

      /* Gain: '<S58>/Gain1' incorporates:
       *  Product: '<S58>/Multiply2'
       *  Product: '<S58>/Multiply3'
       *  Sum: '<S58>/Subtract1'
       */
      rtb_MatrixConcatenate1_i[5] = (rtb_Sign5_dc - rtb_Subtract3_g) * 2.0F;

      /* Gain: '<S59>/Gain' incorporates:
       *  Sum: '<S59>/Subtract2'
       */
      rtb_MatrixConcatenate1_i[6] = (rtb_MatrixConcatenate1_i_tmp -
        rtb_MatrixConcatenate1_i_tmp_0) * 2.0F;

      /* Gain: '<S59>/Gain1' incorporates:
       *  Sum: '<S59>/Add2'
       */
      rtb_MatrixConcatenate1_i[7] = (rtb_Sign5_dc + rtb_Subtract3_g) * 2.0F;

      /* Sum: '<S59>/Subtract' incorporates:
       *  Sum: '<S59>/Add'
       *  Sum: '<S59>/Add1'
       */
      rtb_MatrixConcatenate1_i[8] = (rtb_Sign5_l + rtb_Sign5_mn) -
        (rtb_Divide_or + rtb_a_bx);

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
      if (rtb_MatrixConcatenate1_i_0[0] >= 1.0F) {
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

      /* Outport: '<Root>/FMS_Out' incorporates:
       *  BusAssignment: '<S42>/Bus Assignment'
       *  BusAssignment: '<S45>/Bus Assignment'
       *  Constant: '<S45>/Constant'
       */
      FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

      /* BusAssignment: '<S45>/Bus Assignment' incorporates:
       *  BusAssignment: '<S42>/Bus Assignment'
       *  Constant: '<S45>/Constant3'
       *  Constant: '<S45>/Constant4'
       *  Outport: '<Root>/FMS_Out'
       */
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
          /* Disable for SwitchCase: '<S299>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
           case 0:
           case 1:
           case 4:
            break;

           case 2:
            /* Disable for SwitchCase: '<S699>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S689>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S638>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S606>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S617>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }

          FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;
          break;

         case 1:
          /* Disable for SwitchCase: '<S297>/Switch Case' */
          if (FMS_DW.SwitchCase_ActiveSubsystem_f == 1) {
            /* Disable for Resettable SubSystem: '<S408>/Mission_SubSystem' */
            /* Disable for SwitchCase: '<S459>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S449>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* End of Disable for SubSystem: '<S408>/Mission_SubSystem' */
          }

          FMS_DW.SwitchCase_ActiveSubsystem_f = -1;
          break;

         case 2:
          /* Disable for SwitchCase: '<S296>/Switch Case' */
          switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
           case 0:
           case 4:
            break;

           case 1:
            /* Disable for SwitchCase: '<S395>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S311>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S329>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S345>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S370>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S357>/Switch Case' */
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
         *  ActionPort: '<S299>/Action Port'
         */
        /* SwitchCase: '<S299>/Switch Case' incorporates:
         *  Math: '<S721>/Math Function'
         *  Sum: '<S683>/Subtract'
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
            /* Disable for SwitchCase: '<S699>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

            /* Disable for SwitchCase: '<S689>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_p = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S638>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

            /* Disable for SwitchCase: '<S606>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

            /* Disable for SwitchCase: '<S617>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_c = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_b4) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S299>/Takeoff' incorporates:
             *  ActionPort: '<S601>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S299>/Switch Case' incorporates:
             *  Delay: '<S739>/cur_waypoint'
             *  DiscreteIntegrator: '<S735>/Integrator'
             *  DiscreteIntegrator: '<S735>/Integrator1'
             */
            FMS_DW.icLoad_hz = 1U;
            FMS_DW.Integrator1_DSTATE_f = 0.0F;
            FMS_DW.Integrator_DSTATE_k = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S299>/Takeoff' */
          }

          /* Outputs for IfAction SubSystem: '<S299>/Takeoff' incorporates:
           *  ActionPort: '<S601>/Action Port'
           */
          /* Delay: '<S739>/cur_waypoint' incorporates:
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
          /* Product: '<S739>/Divide' incorporates:
           *  Delay: '<S739>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S739>/Sum1'
           *  Sum: '<S739>/Sum2'
           */
          rtb_Divide_lr_idx_2 = 1.0F / (FMS_B.Cmd_In.sp_waypoint[2] -
            FMS_DW.cur_waypoint_DSTATE[2]) * (FMS_U.INS_Out.h_R -
            FMS_DW.cur_waypoint_DSTATE[2]);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Saturate: '<S739>/Saturation' */
          if (rtb_Divide_lr_idx_2 > 1.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = 0.0F;
            }
          }

          /* End of Saturate: '<S739>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S740>/Trigonometric Function1' incorporates:
           *  Gain: '<S738>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S740>/Trigonometric Function' incorporates:
           *  Gain: '<S738>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S740>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S740>/Constant3'
           */
          rtb_VectorConcatenate_h[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S740>/Gain' incorporates:
           *  Gain: '<S738>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S740>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S740>/Trigonometric Function3' incorporates:
           *  Gain: '<S738>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S740>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S740>/Constant4'
           */
          rtb_VectorConcatenate_h[5] = 0.0F;

          /* SignalConversion: '<S740>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_cs[0];
          rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_cs[1];
          rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_cs[2];

          /* Saturate: '<S732>/Saturation1' */
          rtb_Divide_pr_idx_0 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Divide_pr_idx_2 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S732>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S739>/cur_waypoint'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S739>/Multiply'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S732>/Sum'
           *  Sum: '<S739>/Sum3'
           *  Sum: '<S739>/Sum4'
           */
          rtb_Divide_pr_idx_1 = ((FMS_B.Cmd_In.sp_waypoint[0] -
            FMS_DW.cur_waypoint_DSTATE[0]) * rtb_Divide_lr_idx_2 +
            FMS_DW.cur_waypoint_DSTATE[0]) - FMS_U.INS_Out.x_R;
          rtb_Divide_lr_idx_2 = ((FMS_B.Cmd_In.sp_waypoint[1] -
            FMS_DW.cur_waypoint_DSTATE[1]) * rtb_Divide_lr_idx_2 +
            FMS_DW.cur_waypoint_DSTATE[1]) - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S732>/Multiply' */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 3]
              * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
              rtb_Divide_pr_idx_1;
          }

          /* Saturate: '<S732>/Saturation1' incorporates:
           *  Gain: '<S732>/Gain2'
           *  Product: '<S732>/Multiply'
           */
          rtb_Saturation_e = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
          rtb_Divide_pr_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S601>/Bus Assignment1'
           *  Constant: '<S601>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S601>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S601>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_n1;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S732>/Saturation1' */
          if (rtb_Saturation_e > rtb_Divide_pr_idx_0) {
            /* BusAssignment: '<S601>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_0;
          } else if (rtb_Saturation_e < rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S601>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_2;
          } else {
            /* BusAssignment: '<S601>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_e;
          }

          if (rtb_Divide_pr_idx_1 > rtb_Divide_pr_idx_0) {
            /* BusAssignment: '<S601>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_0;
          } else if (rtb_Divide_pr_idx_1 < rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S601>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_2;
          } else {
            /* BusAssignment: '<S601>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_1;
          }

          /* BusAssignment: '<S601>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DiscreteIntegrator: '<S735>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_f;

          /* Product: '<S736>/Multiply1' incorporates:
           *  Constant: '<S736>/const1'
           *  DiscreteIntegrator: '<S735>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_k * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S731>/Switch' incorporates:
           *  Abs: '<S731>/Abs'
           *  Abs: '<S731>/Abs1'
           *  Constant: '<S731>/Takeoff_Speed'
           *  Constant: '<S733>/Constant'
           *  Constant: '<S734>/Constant'
           *  Gain: '<S731>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S731>/Logical Operator'
           *  RelationalOperator: '<S733>/Compare'
           *  RelationalOperator: '<S734>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S731>/Sum'
           *  Sum: '<S731>/Sum1'
           */
          if ((fabsf(FMS_B.Cmd_In.sp_waypoint[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
              (fabsf(FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2]) > 2.0F))
          {
            rtb_Saturation_e = -FMS_PARAM.TAKEOFF_SPEED;
          } else {
            rtb_Saturation_e = 0.5F * -FMS_PARAM.TAKEOFF_SPEED;
          }

          /* End of Switch: '<S731>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S736>/Add' incorporates:
           *  DiscreteIntegrator: '<S735>/Integrator1'
           *  Sum: '<S735>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_f - rtb_Saturation_e)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S736>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S736>/Sign' */

          /* Sum: '<S736>/Add2' incorporates:
           *  Abs: '<S736>/Abs'
           *  Gain: '<S736>/Gain'
           *  Gain: '<S736>/Gain1'
           *  Product: '<S736>/Multiply2'
           *  Product: '<S736>/Multiply3'
           *  Sqrt: '<S736>/Sqrt'
           *  Sum: '<S736>/Add1'
           *  Sum: '<S736>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_b) * FMS_ConstB.d_b) - FMS_ConstB.d_b) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_lr_idx_2;

          /* Sum: '<S736>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S736>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_b;

          /* Sum: '<S736>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_b;

          /* Signum: '<S736>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S736>/Sign1' */

          /* Signum: '<S736>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S736>/Sign2' */

          /* Sum: '<S736>/Add5' incorporates:
           *  Gain: '<S736>/Gain2'
           *  Product: '<S736>/Multiply4'
           *  Sum: '<S736>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Update for Delay: '<S739>/cur_waypoint' */
          FMS_DW.icLoad_hz = 0U;

          /* Update for DiscreteIntegrator: '<S735>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S735>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_k;

          /* Sum: '<S736>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_b;

          /* Sum: '<S736>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_b;

          /* Signum: '<S736>/Sign5' incorporates:
           *  Signum: '<S736>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S736>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S736>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;

            /* Signum: '<S736>/Sign6' */
            rtb_Sign5_l = rtb_Saturation_e;
          }

          /* End of Signum: '<S736>/Sign5' */

          /* Signum: '<S736>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S736>/Sign3' */

          /* Signum: '<S736>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S736>/Sign4' */

          /* Update for DiscreteIntegrator: '<S735>/Integrator' incorporates:
           *  Constant: '<S736>/const'
           *  Gain: '<S736>/Gain3'
           *  Product: '<S736>/Divide'
           *  Product: '<S736>/Multiply5'
           *  Product: '<S736>/Multiply6'
           *  Sum: '<S736>/Subtract4'
           *  Sum: '<S736>/Subtract5'
           *  Sum: '<S736>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_k += ((rtb_Saturation_e / FMS_ConstB.d_b -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_i * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S299>/Takeoff' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S299>/Land' incorporates:
             *  ActionPort: '<S599>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S299>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S654>/Integrator'
             *  DiscreteIntegrator: '<S654>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_g = 0.0F;
            FMS_DW.Integrator_DSTATE_cy = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S299>/Land' */
          }

          /* Outputs for IfAction SubSystem: '<S299>/Land' incorporates:
           *  ActionPort: '<S599>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Trigonometry: '<S659>/Trigonometric Function1' incorporates:
           *  Gain: '<S658>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S659>/Trigonometric Function' incorporates:
           *  Gain: '<S658>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S659>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S659>/Constant3'
           */
          rtb_VectorConcatenate_h[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S659>/Gain' incorporates:
           *  Gain: '<S658>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Trigonometry: '<S659>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S659>/Trigonometric Function3' incorporates:
           *  Gain: '<S658>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SignalConversion: '<S659>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S659>/Constant4'
           */
          rtb_VectorConcatenate_h[5] = 0.0F;

          /* SignalConversion: '<S659>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_j0[0];
          rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_j0[1];
          rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_j0[2];

          /* Saturate: '<S652>/Saturation1' */
          rtb_Divide_pr_idx_2 = FMS_PARAM.VEL_XY_LIM / 5.0F;
          rtb_Sign5_l = -FMS_PARAM.VEL_XY_LIM / 5.0F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* SignalConversion: '<S656>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S656>/Sum'
           */
          rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_lr_idx_2 = FMS_B.Cmd_In.sp_waypoint[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S656>/Multiply' incorporates:
           *  SignalConversion: '<S656>/TmpSignal ConversionAtMultiplyInport2'
           *  Sum: '<S656>/Sum'
           */
          for (rtb_n = 0; rtb_n < 3; rtb_n++) {
            rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 3]
              * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
              rtb_Divide_pr_idx_1;
          }

          /* End of Product: '<S656>/Multiply' */

          /* Saturate: '<S652>/Saturation1' incorporates:
           *  Gain: '<S656>/Gain2'
           */
          rtb_Saturation_e = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
          rtb_Divide_pr_idx_1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S599>/Bus Assignment1'
           *  Constant: '<S599>/Constant1'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S599>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S599>/Constant'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_e;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_l;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;
          FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

          /* Saturate: '<S652>/Saturation1' */
          if (rtb_Saturation_e > rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S599>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Divide_pr_idx_2;
          } else if (rtb_Saturation_e < rtb_Sign5_l) {
            /* BusAssignment: '<S599>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Sign5_l;
          } else {
            /* BusAssignment: '<S599>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Saturation_e;
          }

          if (rtb_Divide_pr_idx_1 > rtb_Divide_pr_idx_2) {
            /* BusAssignment: '<S599>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_2;
          } else if (rtb_Divide_pr_idx_1 < rtb_Sign5_l) {
            /* BusAssignment: '<S599>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Sign5_l;
          } else {
            /* BusAssignment: '<S599>/Bus Assignment1' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Divide_pr_idx_1;
          }

          /* BusAssignment: '<S599>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DiscreteIntegrator: '<S654>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_DW.Integrator1_DSTATE_g;

          /* Product: '<S655>/Multiply1' incorporates:
           *  Constant: '<S655>/const1'
           *  DiscreteIntegrator: '<S654>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_cy * 0.35F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S651>/Switch' incorporates:
           *  Constant: '<S651>/Land_Speed'
           *  Constant: '<S653>/Constant'
           *  Gain: '<S651>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  Logic: '<S651>/Logical Operator'
           *  RelationalOperator: '<S653>/Compare'
           *  S-Function (sfix_bitop): '<S651>/cmd_p valid'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (((FMS_U.INS_Out.flag & 256U) != 0U) && (FMS_U.INS_Out.h_AGL <=
               FMS_PARAM.ASSIST_LAND_H)) {
            rtb_Saturation_e = 0.5F * FMS_PARAM.LAND_SPEED;
          } else {
            rtb_Saturation_e = FMS_PARAM.LAND_SPEED;
          }

          /* End of Switch: '<S651>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S655>/Add' incorporates:
           *  DiscreteIntegrator: '<S654>/Integrator1'
           *  Sum: '<S654>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_g - rtb_Saturation_e) +
            rtb_Divide_pr_idx_1;

          /* Signum: '<S655>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S655>/Sign' */

          /* Sum: '<S655>/Add2' incorporates:
           *  Abs: '<S655>/Abs'
           *  Gain: '<S655>/Gain'
           *  Gain: '<S655>/Gain1'
           *  Product: '<S655>/Multiply2'
           *  Product: '<S655>/Multiply3'
           *  Sqrt: '<S655>/Sqrt'
           *  Sum: '<S655>/Add1'
           *  Sum: '<S655>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_om) * FMS_ConstB.d_om) - FMS_ConstB.d_om) * 0.5F *
            rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

          /* Sum: '<S655>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_pr_idx_1;

          /* Sum: '<S655>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_om;

          /* Sum: '<S655>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_om;

          /* Signum: '<S655>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S655>/Sign1' */

          /* Signum: '<S655>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S655>/Sign2' */

          /* Sum: '<S655>/Add5' incorporates:
           *  Gain: '<S655>/Gain2'
           *  Product: '<S655>/Multiply4'
           *  Sum: '<S655>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Update for DiscreteIntegrator: '<S654>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S654>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_cy;

          /* Sum: '<S655>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_om;

          /* Sum: '<S655>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_om;

          /* Signum: '<S655>/Sign5' incorporates:
           *  Signum: '<S655>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S655>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S655>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S655>/Sign6' */
            rtb_Sign5_l = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S655>/Sign5' */

          /* Signum: '<S655>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S655>/Sign3' */

          /* Signum: '<S655>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S655>/Sign4' */

          /* Update for DiscreteIntegrator: '<S654>/Integrator' incorporates:
           *  Constant: '<S655>/const'
           *  Gain: '<S655>/Gain3'
           *  Product: '<S655>/Divide'
           *  Product: '<S655>/Multiply5'
           *  Product: '<S655>/Multiply6'
           *  Sum: '<S655>/Subtract4'
           *  Sum: '<S655>/Subtract5'
           *  Sum: '<S655>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_cy += ((rtb_Divide_lr_idx_2 / FMS_ConstB.d_om
            - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_p * ((rtb_Divide_pr_idx_0
            - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 9.806F) * 0.004F;

          /* End of Outputs for SubSystem: '<S299>/Land' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S299>/Return' incorporates:
             *  ActionPort: '<S600>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S299>/Switch Case' incorporates:
             *  Delay: '<S663>/Delay'
             *  Delay: '<S684>/Delay'
             *  DiscreteIntegrator: '<S666>/Integrator'
             *  DiscreteIntegrator: '<S666>/Integrator1'
             *  DiscreteIntegrator: '<S680>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S685>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S726>/Discrete-Time Integrator'
             */
            FMS_DW.icLoad_c = 1U;
            FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;
            FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetS_j = 0;
            FMS_DW.l1_heading_j = 0.0F;
            FMS_DW.icLoad_h = 1U;
            FMS_DW.Integrator1_IC_LOADING_on = 1U;
            FMS_DW.Integrator_DSTATE_f = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S299>/Return' */

            /* SystemReset for IfAction SubSystem: '<S299>/Return' incorporates:
             *  ActionPort: '<S600>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S299>/Switch Case' incorporates:
             *  Chart: '<S690>/Motion Status'
             *  Chart: '<S700>/Motion State'
             */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_p);
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_g);

            /* End of SystemReset for SubSystem: '<S299>/Return' */
          }

          /* Outputs for IfAction SubSystem: '<S299>/Return' incorporates:
           *  ActionPort: '<S600>/Action Port'
           */
          /* Delay: '<S684>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_m[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_m[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* RelationalOperator: '<S679>/Compare' incorporates:
           *  Constant: '<S730>/Constant'
           *  DiscreteIntegrator: '<S685>/Discrete-Time Integrator'
           *  RelationalOperator: '<S730>/Compare'
           */
          rtb_FixPtRelationalOperator_me =
            (FMS_DW.DiscreteTimeIntegrator_DSTATE_a <= 3);

          /* DiscreteIntegrator: '<S680>/Acceleration_Speed' */
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
          /* Chart: '<S700>/Motion State' incorporates:
           *  Constant: '<S700>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S700>/Square'
           *  Math: '<S700>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S700>/Sqrt'
           *  Sum: '<S700>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_p);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S699>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S699>/Hold Control' incorporates:
               *  ActionPort: '<S702>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S699>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_i);

              /* End of SystemReset for SubSystem: '<S699>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S699>/Hold Control' incorporates:
             *  ActionPort: '<S702>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_m,
                              &FMS_ConstB.HoldControl_i, &FMS_DW.HoldControl_i);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S699>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S699>/Brake Control' incorporates:
             *  ActionPort: '<S701>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_m);

            /* End of Outputs for SubSystem: '<S699>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_l != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S699>/Move Control' incorporates:
               *  ActionPort: '<S703>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S699>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_k);

              /* End of SystemReset for SubSystem: '<S699>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S699>/Move Control' incorporates:
             *  ActionPort: '<S703>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_m,
                              &FMS_ConstB.MoveControl_k, &FMS_DW.MoveControl_k);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S699>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S699>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S690>/Motion Status' incorporates:
           *  Abs: '<S690>/Abs'
           *  Constant: '<S690>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S689>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S689>/Hold Control' incorporates:
               *  ActionPort: '<S692>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S689>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_e);

              /* End of SystemReset for SubSystem: '<S689>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S689>/Hold Control' incorporates:
             *  ActionPort: '<S692>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_oo,
                              &FMS_DW.HoldControl_e);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S689>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S689>/Brake Control' incorporates:
             *  ActionPort: '<S691>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_oo);

            /* End of Outputs for SubSystem: '<S689>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_p != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S689>/Move Control' incorporates:
               *  ActionPort: '<S693>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S689>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_c);

              /* End of SystemReset for SubSystem: '<S689>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S689>/Move Control' incorporates:
             *  ActionPort: '<S693>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_oo,
                              &FMS_ConstB.MoveControl_c, &FMS_DW.MoveControl_c);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S689>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S689>/Switch Case' */

          /* Switch: '<S661>/Switch' incorporates:
           *  Product: '<S684>/Multiply'
           *  Sum: '<S684>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S699>/Saturation1' */
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

            /* End of Saturate: '<S699>/Saturation1' */

            /* Saturate: '<S689>/Saturation1' */
            if (FMS_B.Merge_oo > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_oo < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_oo;
            }

            /* End of Saturate: '<S689>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S684>/Sum' incorporates:
             *  Delay: '<S684>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_m[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S727>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S680>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Square_bg[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S684>/Sum' incorporates:
             *  Delay: '<S684>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_m[1];

            /* Sum: '<S680>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S686>/Sqrt' incorporates:
             *  Math: '<S686>/Square'
             *  Sum: '<S680>/Sum'
             *  Sum: '<S686>/Sum of Elements'
             */
            rtb_Saturation_e = sqrtf(rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0 +
              rtb_Saturation_e * rtb_Saturation_e);

            /* SignalConversion: '<S729>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_db[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_db[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_db[2];

            /* SignalConversion: '<S729>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S729>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S728>/Gain' incorporates:
             *  DiscreteIntegrator: '<S726>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S726>/Add'
             */
            rtb_Divide_pr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading_j);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S729>/Trigonometric Function3' incorporates:
             *  Trigonometry: '<S729>/Trigonometric Function1'
             */
            rtb_Sign5_l = arm_cos_f32(rtb_Divide_pr_idx_2);
            rtb_VectorConcatenate_h[4] = rtb_Sign5_l;

            /* Trigonometry: '<S729>/Trigonometric Function2' incorporates:
             *  Trigonometry: '<S729>/Trigonometric Function'
             */
            rtb_a_bx = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S729>/Gain' incorporates:
             *  Trigonometry: '<S729>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -rtb_a_bx;

            /* SignalConversion: '<S729>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S729>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S729>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = rtb_a_bx;

            /* Trigonometry: '<S729>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = rtb_Sign5_l;

            /* Switch: '<S680>/Switch' incorporates:
             *  Constant: '<S680>/vel'
             */
            if (rtb_Saturation_e > FMS_PARAM.L1) {
              rtb_Divide_pr_idx_2 = FMS_PARAM.CRUISE_SPEED;
            } else {
              /* Gain: '<S680>/Gain' */
              rtb_Divide_pr_idx_2 = 0.5F * rtb_Saturation_e;

              /* Saturate: '<S680>/Saturation' */
              if (rtb_Divide_pr_idx_2 > FMS_PARAM.CRUISE_SPEED) {
                rtb_Divide_pr_idx_2 = FMS_PARAM.CRUISE_SPEED;
              } else {
                if (rtb_Divide_pr_idx_2 < 0.5F) {
                  rtb_Divide_pr_idx_2 = 0.5F;
                }
              }

              /* End of Saturate: '<S680>/Saturation' */
            }

            /* End of Switch: '<S680>/Switch' */

            /* Switch: '<S680>/Switch1' incorporates:
             *  DiscreteIntegrator: '<S680>/Acceleration_Speed'
             *  Sum: '<S680>/Sum1'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE_a - rtb_Divide_pr_idx_2 < 0.0F)
            {
              rtb_Divide_pr_idx_2 = FMS_DW.Acceleration_Speed_DSTATE_a;
            }

            /* End of Switch: '<S680>/Switch1' */

            /* Sum: '<S727>/Sum of Elements' incorporates:
             *  Math: '<S727>/Math Function'
             */
            rtb_Saturation_e = rtb_Switch_c2[0] * rtb_Switch_c2[0] +
              rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

            /* Math: '<S727>/Math Function1' incorporates:
             *  Sum: '<S727>/Sum of Elements'
             *
             * About '<S727>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Saturation_e = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S727>/Math Function1' */

            /* Switch: '<S727>/Switch' incorporates:
             *  Constant: '<S727>/Constant'
             *  Product: '<S727>/Product'
             */
            if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_0 = rtb_Square_bg[0];
            } else {
              rtb_Divide_pr_idx_0 = 0.0F;
              rtb_Divide_pr_idx_1 = 0.0F;
              rtb_Saturation_e = 1.0F;
            }

            /* End of Switch: '<S727>/Switch' */

            /* Product: '<S725>/Multiply2' incorporates:
             *  Product: '<S727>/Divide'
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

          /* End of Switch: '<S661>/Switch' */

          /* Delay: '<S663>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_h != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_nx = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S666>/Integrator1' incorporates:
           *  Delay: '<S663>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_on != 0) {
            FMS_DW.Integrator1_DSTATE_b = FMS_DW.Delay_DSTATE_nx;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S670>/Rem' incorporates:
           *  Constant: '<S670>/Constant1'
           *  DiscreteIntegrator: '<S666>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S665>/Sum'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_DW.Integrator1_DSTATE_b -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S670>/Switch' incorporates:
           *  Abs: '<S670>/Abs'
           *  Constant: '<S670>/Constant'
           *  Constant: '<S671>/Constant'
           *  Product: '<S670>/Multiply'
           *  RelationalOperator: '<S671>/Compare'
           *  Sum: '<S670>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S670>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S670>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S670>/Switch' */

          /* Gain: '<S665>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S665>/Saturation' */
          if (rtb_Divide_pr_idx_2 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_pr_idx_2 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Divide_pr_idx_2 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_2 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S665>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S600>/Bus Assignment1'
           *  Constant: '<S600>/Constant2'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S600>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_li;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_c2[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_c2[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_c2[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_2;

          /* Math: '<S720>/Math Function1'
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
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S720>/Product'
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

          /* End of Switch: '<S720>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S600>/Sum' incorporates:
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

          /* SignalConversion: '<S677>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S600>/Sum'
           */
          rtb_P_cg[0] = rtb_Divide_pr_idx_0;
          rtb_P_cg[1] = rtb_Divide_pr_idx_1;

          /* Math: '<S677>/Math Function' incorporates:
           *  Sum: '<S600>/Sum'
           */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

          /* Sum: '<S677>/Sum of Elements' */
          rtb_Saturation_e = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S677>/Math Function1' incorporates:
           *  Sum: '<S677>/Sum of Elements'
           *
           * About '<S677>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S677>/Math Function1' */

          /* Switch: '<S677>/Switch' incorporates:
           *  Constant: '<S677>/Constant'
           *  Product: '<S677>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_a_bx = rtb_Divide_pr_idx_2;
          } else {
            rtb_Divide_pr_idx_0 = 0.0F;
            rtb_Divide_pr_idx_1 = 0.0F;
            rtb_a_bx = 1.0F;
          }

          /* End of Switch: '<S677>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S682>/NearbyRefWP' incorporates:
           *  Constant: '<S600>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_i5,
                          &rtb_Saturation_e);

          /* MATLAB Function: '<S682>/SearchL1RefWP' incorporates:
           *  Constant: '<S600>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_cg, &rtb_Divide_pr_idx_2);

          /* MATLAB Function: '<S682>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S682>/Switch1' incorporates:
           *  Constant: '<S713>/Constant'
           *  RelationalOperator: '<S713>/Compare'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_i5[0];
            rtb_P_cg[1] = rtb_Divide_i5[1];
          } else {
            /* RelationalOperator: '<S712>/Compare' incorporates:
             *  Constant: '<S712>/Constant'
             */
            rtb_Compare_kd = (rtb_Divide_pr_idx_2 >= 0.0F);

            /* Switch: '<S682>/Switch' */
            if (!rtb_Compare_kd) {
              rtb_P_cg[0] = rtb_Square_ds[0];
              rtb_P_cg[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S682>/Switch' */
          }

          /* End of Switch: '<S682>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S683>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_cg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_cg[0] = rtb_Sign5_l;
          rtb_Subtract_hb[0] = rtb_Sign5_l * rtb_Sign5_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S683>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S721>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S721>/Sum of Elements' incorporates:
           *  Math: '<S721>/Math Function'
           *  Sum: '<S719>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Subtract_hb[0] + rtb_Sign5_l * rtb_Sign5_l;

          /* Math: '<S721>/Math Function1' incorporates:
           *  Sum: '<S721>/Sum of Elements'
           *
           * About '<S721>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S721>/Math Function1' */

          /* Switch: '<S721>/Switch' incorporates:
           *  Constant: '<S721>/Constant'
           *  Product: '<S721>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Switch_an[0] = rtb_P_cg[0];
            rtb_Switch_an[1] = rtb_Sign5_l;
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S721>/Switch' */

          /* Product: '<S720>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S723>/Sum of Elements' incorporates:
           *  Math: '<S723>/Math Function'
           *  SignalConversion: '<S723>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S723>/Math Function1' incorporates:
           *  Sum: '<S723>/Sum of Elements'
           *
           * About '<S723>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S723>/Math Function1' */

          /* Switch: '<S723>/Switch' incorporates:
           *  Constant: '<S723>/Constant'
           *  Product: '<S723>/Product'
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

          /* End of Switch: '<S723>/Switch' */

          /* Product: '<S721>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S724>/Sum of Elements' incorporates:
           *  Math: '<S724>/Math Function'
           *  SignalConversion: '<S724>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S724>/Math Function1' incorporates:
           *  Sum: '<S724>/Sum of Elements'
           *
           * About '<S724>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S724>/Math Function1' */

          /* Switch: '<S724>/Switch' incorporates:
           *  Constant: '<S724>/Constant'
           *  Product: '<S724>/Product'
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

          /* End of Switch: '<S724>/Switch' */

          /* Product: '<S724>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S723>/Divide' */
          rtb_P_cg[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S677>/Divide' */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 / rtb_a_bx;

          /* Product: '<S724>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S723>/Divide' */
          rtb_P_cg[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S677>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 / rtb_a_bx;

          /* Sum: '<S722>/Subtract' incorporates:
           *  Product: '<S722>/Multiply'
           *  Product: '<S722>/Multiply1'
           */
          rtb_Divide_pr_idx_2 = rtb_Divide_i5[0] * rtb_P_cg[1] - rtb_Divide_i5[1]
            * rtb_P_cg[0];

          /* Signum: '<S717>/Sign1' */
          if (rtb_Divide_pr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S717>/Sign1' */

          /* Switch: '<S717>/Switch2' incorporates:
           *  Constant: '<S717>/Constant4'
           */
          if (rtb_Divide_pr_idx_2 == 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          }

          /* End of Switch: '<S717>/Switch2' */

          /* DotProduct: '<S717>/Dot Product' */
          rtb_Sign5_l = rtb_P_cg[0] * rtb_Divide_i5[0] + rtb_P_cg[1] *
            rtb_Divide_i5[1];

          /* Trigonometry: '<S717>/Acos' incorporates:
           *  DotProduct: '<S717>/Dot Product'
           */
          if (rtb_Sign5_l > 1.0F) {
            rtb_Sign5_l = 1.0F;
          } else {
            if (rtb_Sign5_l < -1.0F) {
              rtb_Sign5_l = -1.0F;
            }
          }

          /* Product: '<S717>/Multiply' incorporates:
           *  Trigonometry: '<S717>/Acos'
           */
          rtb_Divide_pr_idx_2 *= acosf(rtb_Sign5_l);

          /* Saturate: '<S683>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.57079637F) {
            rtb_Divide_pr_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.57079637F) {
              rtb_Divide_pr_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S683>/Saturation' */

          /* Product: '<S683>/Divide' incorporates:
           *  Constant: '<S600>/L1'
           *  Constant: '<S683>/Constant'
           *  Gain: '<S683>/Gain'
           *  Math: '<S683>/Square'
           *  MinMax: '<S683>/Max'
           *  MinMax: '<S683>/Min'
           *  Product: '<S683>/Multiply1'
           *  Sqrt: '<S719>/Sqrt'
           *  Trigonometry: '<S683>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Divide_pr_idx_2) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_e), 0.5F));

          /* Sum: '<S675>/Subtract' incorporates:
           *  Product: '<S675>/Multiply'
           *  Product: '<S675>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide_m[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide_m[0];

          /* Signum: '<S664>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S664>/Sign1' */

          /* Switch: '<S664>/Switch2' incorporates:
           *  Constant: '<S664>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S664>/Switch2' */

          /* DotProduct: '<S664>/Dot Product' */
          rtb_Saturation_e = FMS_ConstB.Divide_m[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide_m[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S664>/Acos' incorporates:
           *  DotProduct: '<S664>/Dot Product'
           */
          if (rtb_Saturation_e > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            if (rtb_Saturation_e < -1.0F) {
              rtb_Saturation_e = -1.0F;
            }
          }

          /* Product: '<S664>/Multiply' incorporates:
           *  Trigonometry: '<S664>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_Saturation_e);

          /* Math: '<S667>/Rem' incorporates:
           *  Constant: '<S667>/Constant1'
           *  Delay: '<S663>/Delay'
           *  Sum: '<S663>/Sum2'
           */
          rtb_Divide_pr_idx_2 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_nx, 6.28318548F);

          /* Switch: '<S667>/Switch' incorporates:
           *  Abs: '<S667>/Abs'
           *  Constant: '<S667>/Constant'
           *  Constant: '<S673>/Constant'
           *  Product: '<S667>/Multiply'
           *  RelationalOperator: '<S673>/Compare'
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

          /* Sum: '<S663>/Sum' incorporates:
           *  Delay: '<S663>/Delay'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + FMS_DW.Delay_DSTATE_nx;

          /* Product: '<S672>/Multiply1' incorporates:
           *  Constant: '<S672>/const1'
           *  DiscreteIntegrator: '<S666>/Integrator'
           */
          rtb_Divide_pr_idx_2 = FMS_DW.Integrator_DSTATE_f * 0.785398185F;

          /* Sum: '<S672>/Add' incorporates:
           *  DiscreteIntegrator: '<S666>/Integrator1'
           *  Sum: '<S666>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_b -
            rtb_Divide_pr_idx_1) + rtb_Divide_pr_idx_2;

          /* Signum: '<S672>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S672>/Sign' */

          /* Sum: '<S672>/Add2' incorporates:
           *  Abs: '<S672>/Abs'
           *  Gain: '<S672>/Gain'
           *  Gain: '<S672>/Gain1'
           *  Product: '<S672>/Multiply2'
           *  Product: '<S672>/Multiply3'
           *  Sqrt: '<S672>/Sqrt'
           *  Sum: '<S672>/Add1'
           *  Sum: '<S672>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_n) * FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2;

          /* Sum: '<S672>/Add4' */
          rtb_Divide_pr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S672>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_n;

          /* Sum: '<S672>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_n;

          /* Signum: '<S672>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S672>/Sign1' */

          /* Signum: '<S672>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S672>/Sign2' */

          /* Sum: '<S672>/Add5' incorporates:
           *  Gain: '<S672>/Gain2'
           *  Product: '<S672>/Multiply4'
           *  Sum: '<S672>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_pr_idx_2;

          /* Sum: '<S672>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_n;

          /* Sum: '<S672>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e - FMS_ConstB.d_n;

          /* Product: '<S672>/Divide' */
          d = rtb_Saturation_e / FMS_ConstB.d_n;

          /* Signum: '<S672>/Sign5' incorporates:
           *  Signum: '<S672>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S672>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S672>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Saturation_e;

            /* Signum: '<S672>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S672>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S663>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S668>/Rem' incorporates:
           *  Constant: '<S668>/Constant1'
           */
          rtb_Saturation_e = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S668>/Switch' incorporates:
           *  Abs: '<S668>/Abs'
           *  Constant: '<S668>/Constant'
           *  Constant: '<S674>/Constant'
           *  Product: '<S668>/Multiply'
           *  RelationalOperator: '<S674>/Compare'
           *  Sum: '<S668>/Add'
           */
          if (fabsf(rtb_Saturation_e) > 3.14159274F) {
            /* Signum: '<S668>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_e;
            }

            /* End of Signum: '<S668>/Sign' */
            rtb_Saturation_e -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S668>/Switch' */

          /* Abs: '<S661>/Abs' */
          rtb_Saturation_e = fabsf(rtb_Saturation_e);

          /* Update for Delay: '<S684>/Delay' */
          FMS_DW.icLoad_c = 0U;

          /* Update for DiscreteIntegrator: '<S685>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S678>/Constant'
           *  RelationalOperator: '<S678>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S685>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S680>/Acceleration_Speed' incorporates:
           *  Constant: '<S680>/Constant'
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

          /* End of Update for DiscreteIntegrator: '<S680>/Acceleration_Speed' */

          /* Product: '<S684>/Divide1' incorporates:
           *  Constant: '<S684>/Constant'
           */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 / FMS_PARAM.CRUISE_SPEED;

          /* Saturate: '<S684>/Saturation' */
          if (rtb_Saturation_e > 0.314159274F) {
            rtb_Saturation_e = 0.314159274F;
          } else {
            if (rtb_Saturation_e < -0.314159274F) {
              rtb_Saturation_e = -0.314159274F;
            }
          }

          /* End of Saturate: '<S684>/Saturation' */

          /* Update for DiscreteIntegrator: '<S726>/Discrete-Time Integrator' */
          FMS_DW.l1_heading_j += 0.004F * rtb_Saturation_e;

          /* Update for Delay: '<S663>/Delay' */
          FMS_DW.icLoad_h = 0U;

          /* Update for DiscreteIntegrator: '<S666>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S666>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_on = 0U;
          FMS_DW.Integrator1_DSTATE_b += 0.004F * FMS_DW.Integrator_DSTATE_f;

          /* Signum: '<S672>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S672>/Sign3' */

          /* Signum: '<S672>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S672>/Sign4' */

          /* Update for DiscreteIntegrator: '<S666>/Integrator' incorporates:
           *  Constant: '<S672>/const'
           *  Gain: '<S672>/Gain3'
           *  Product: '<S672>/Multiply5'
           *  Product: '<S672>/Multiply6'
           *  Sum: '<S672>/Subtract4'
           *  Sum: '<S672>/Subtract5'
           *  Sum: '<S672>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_f += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_d *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 1.04719758F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_f >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_f = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_f <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_f = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S666>/Integrator' */
          /* End of Outputs for SubSystem: '<S299>/Return' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_b4 != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S299>/Hold' incorporates:
             *  ActionPort: '<S598>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S299>/Switch Case' incorporates:
             *  Delay: '<S619>/Delay'
             *  DiscreteIntegrator: '<S631>/Integrator'
             *  DiscreteIntegrator: '<S631>/Integrator1'
             */
            FMS_DW.icLoad_n = 1U;
            FMS_DW.Integrator1_IC_LOADING_o = 1U;
            FMS_DW.Integrator1_PrevResetState = 0;
            FMS_DW.Integrator_DSTATE_hi = 0.0F;
            FMS_DW.Integrator_PrevResetState = 0;

            /* End of InitializeConditions for SubSystem: '<S299>/Hold' */

            /* SystemReset for IfAction SubSystem: '<S299>/Hold' incorporates:
             *  ActionPort: '<S598>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S299>/Switch Case' incorporates:
             *  Chart: '<S607>/Motion Status'
             *  Chart: '<S618>/Motion State'
             *  Chart: '<S639>/Motion State'
             */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_e);
            FMS_DW.temporalCounter_i1_il = 0U;
            FMS_DW.is_active_c15_FMS = 0U;
            FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_d);

            /* End of SystemReset for SubSystem: '<S299>/Hold' */
          }

          /* Outputs for IfAction SubSystem: '<S299>/Hold' incorporates:
           *  ActionPort: '<S598>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S607>/Motion Status' incorporates:
           *  Abs: '<S607>/Abs'
           *  Constant: '<S607>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_e);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S618>/Motion State' incorporates:
           *  Abs: '<S618>/Abs'
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

          /* End of Chart: '<S618>/Motion State' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S639>/Motion State' incorporates:
           *  Constant: '<S639>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S639>/Square'
           *  Math: '<S639>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S639>/Sqrt'
           *  Sum: '<S639>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_og,
                          &FMS_DW.sf_MotionState_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S638>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S638>/Hold Control' incorporates:
               *  ActionPort: '<S641>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S638>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_ft);

              /* End of SystemReset for SubSystem: '<S638>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S638>/Hold Control' incorporates:
             *  ActionPort: '<S641>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_p,
                              &FMS_ConstB.HoldControl_ft, &FMS_DW.HoldControl_ft);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S638>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S638>/Brake Control' incorporates:
             *  ActionPort: '<S640>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_p);

            /* End of Outputs for SubSystem: '<S638>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_nm != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S638>/Move Control' incorporates:
               *  ActionPort: '<S642>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S638>/Switch Case' */
              FMS_MoveControl_l_Reset(&FMS_DW.MoveControl_p);

              /* End of SystemReset for SubSystem: '<S638>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S638>/Move Control' incorporates:
             *  ActionPort: '<S642>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_k(FMS_U.Pilot_Cmd.stick_pitch,
                              FMS_U.Pilot_Cmd.stick_roll, FMS_B.Merge_p,
                              &FMS_ConstB.MoveControl_p, &FMS_DW.MoveControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S638>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S638>/Switch Case' */

          /* SwitchCase: '<S606>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S606>/Hold Control' incorporates:
               *  ActionPort: '<S609>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S606>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_g);

              /* End of SystemReset for SubSystem: '<S606>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S606>/Hold Control' incorporates:
             *  ActionPort: '<S609>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_po,
                              &FMS_DW.HoldControl_g);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S606>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S606>/Brake Control' incorporates:
             *  ActionPort: '<S608>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_po);

            /* End of Outputs for SubSystem: '<S606>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_k4 != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S606>/Move Control' incorporates:
               *  ActionPort: '<S610>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S606>/Switch Case' */
              FMS_MoveControl_e_Reset(&FMS_DW.MoveControl_d);

              /* End of SystemReset for SubSystem: '<S606>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S606>/Move Control' incorporates:
             *  ActionPort: '<S610>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_c(FMS_U.Pilot_Cmd.stick_throttle, &FMS_B.Merge_po,
                              &FMS_ConstB.MoveControl_d, &FMS_DW.MoveControl_d);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S606>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S606>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S616>/Compare' incorporates:
           *  Constant: '<S616>/Constant'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.Cmd_In.set_yaw < 0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Delay: '<S619>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_n != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_h = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S631>/Integrator1' incorporates:
           *  Delay: '<S619>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING_o != 0) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Integrator1_PrevResetState != 0)) {
            FMS_DW.Integrator1_DSTATE_jz = FMS_DW.Delay_DSTATE_h;
          }

          /* SwitchCase: '<S617>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S617>/Hold Control' incorporates:
               *  ActionPort: '<S621>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S617>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_f);

              /* End of SystemReset for SubSystem: '<S617>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S617>/Hold Control' incorporates:
             *  ActionPort: '<S621>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_h,
                              &FMS_DW.HoldControl_f);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S617>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S617>/Brake Control' incorporates:
             *  ActionPort: '<S620>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_h);

            /* End of Outputs for SubSystem: '<S617>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_c != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S617>/Move Control' incorporates:
               *  ActionPort: '<S622>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S617>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_a);

              /* End of SystemReset for SubSystem: '<S617>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S617>/Move Control' incorporates:
             *  ActionPort: '<S622>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_h,
                              &FMS_ConstB.MoveControl_a, &FMS_DW.MoveControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S617>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S617>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S604>/Switch' incorporates:
           *  Saturate: '<S617>/Saturation'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_yaw >= 0.0F) {
            /* Math: '<S634>/Rem' incorporates:
             *  Constant: '<S634>/Constant1'
             *  DiscreteIntegrator: '<S631>/Integrator1'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S630>/Sum'
             */
            rtb_Divide_pr_idx_1 = rt_remf(FMS_DW.Integrator1_DSTATE_jz -
              FMS_U.INS_Out.psi, 6.28318548F);

            /* Switch: '<S634>/Switch' incorporates:
             *  Abs: '<S634>/Abs'
             *  Constant: '<S634>/Constant'
             *  Constant: '<S635>/Constant'
             *  Product: '<S634>/Multiply'
             *  RelationalOperator: '<S635>/Compare'
             *  Sum: '<S634>/Add'
             */
            if (fabsf(rtb_Divide_pr_idx_1) > 3.14159274F) {
              /* Signum: '<S634>/Sign' */
              if (rtb_Divide_pr_idx_1 < 0.0F) {
                rtb_Divide_lr_idx_2 = -1.0F;
              } else if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              } else {
                rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1;
              }

              /* End of Signum: '<S634>/Sign' */
              rtb_Divide_pr_idx_1 -= 6.28318548F * rtb_Divide_lr_idx_2;
            }

            /* End of Switch: '<S634>/Switch' */

            /* Gain: '<S630>/Gain2' */
            rtb_Divide_pr_idx_1 *= FMS_PARAM.YAW_P;

            /* Saturate: '<S630>/Saturation' */
            if (rtb_Divide_pr_idx_1 > FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
            } else {
              if (rtb_Divide_pr_idx_1 < -FMS_PARAM.YAW_RATE_LIM) {
                rtb_Divide_pr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
              }
            }

            /* End of Saturate: '<S630>/Saturation' */
          } else if (FMS_B.Merge_h > FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S617>/Saturation' */
            rtb_Divide_pr_idx_1 = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_h < -FMS_PARAM.YAW_RATE_LIM) {
            /* Saturate: '<S617>/Saturation' */
            rtb_Divide_pr_idx_1 = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* Saturate: '<S617>/Saturation' */
            rtb_Divide_pr_idx_1 = FMS_B.Merge_h;
          }

          /* End of Switch: '<S604>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  BusAssignment: '<S598>/Bus Assignment'
           *  Constant: '<S598>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S598>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_i;
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_1;

          /* Saturate: '<S638>/Saturation1' */
          if (FMS_B.Merge_p[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S598>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S598>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S598>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge_p[0];
          }

          if (FMS_B.Merge_p[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S598>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_p[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S598>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S598>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge_p[1];
          }

          /* End of Saturate: '<S638>/Saturation1' */

          /* Saturate: '<S606>/Saturation1' */
          if (FMS_B.Merge_po > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S598>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_po < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S598>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S598>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_po;
          }

          /* End of Saturate: '<S606>/Saturation1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S632>/Rem' incorporates:
           *  Constant: '<S632>/Constant1'
           *  Delay: '<S619>/Delay'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           *  Sum: '<S619>/Sum2'
           */
          rtb_Divide_pr_idx_1 = rt_remf(FMS_B.Cmd_In.set_yaw -
            FMS_DW.Delay_DSTATE_h, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S632>/Switch' incorporates:
           *  Abs: '<S632>/Abs'
           *  Constant: '<S632>/Constant'
           *  Constant: '<S637>/Constant'
           *  Product: '<S632>/Multiply'
           *  RelationalOperator: '<S637>/Compare'
           *  Sum: '<S632>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_1) > 3.14159274F) {
            /* Signum: '<S632>/Sign' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            } else {
              rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1;
            }

            /* End of Signum: '<S632>/Sign' */
            rtb_Divide_pr_idx_1 -= 6.28318548F * rtb_Divide_lr_idx_2;
          }

          /* End of Switch: '<S632>/Switch' */

          /* Sum: '<S619>/Sum' incorporates:
           *  Delay: '<S619>/Delay'
           */
          rtb_Divide_lr_idx_2 = rtb_Divide_pr_idx_1 + FMS_DW.Delay_DSTATE_h;

          /* DiscreteIntegrator: '<S631>/Integrator' */
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

          /* Product: '<S636>/Multiply1' incorporates:
           *  Constant: '<S636>/const1'
           *  DiscreteIntegrator: '<S631>/Integrator'
           */
          rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_hi * 0.785398185F;

          /* Sum: '<S636>/Add' incorporates:
           *  DiscreteIntegrator: '<S631>/Integrator1'
           *  Sum: '<S631>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_jz - rtb_Divide_lr_idx_2)
            + rtb_Divide_pr_idx_1;

          /* Signum: '<S636>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_2 = 1.0F;
          } else {
            rtb_Divide_lr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S636>/Sign' */

          /* Sum: '<S636>/Add2' incorporates:
           *  Abs: '<S636>/Abs'
           *  Gain: '<S636>/Gain'
           *  Gain: '<S636>/Gain1'
           *  Product: '<S636>/Multiply2'
           *  Product: '<S636>/Multiply3'
           *  Sqrt: '<S636>/Sqrt'
           *  Sum: '<S636>/Add1'
           *  Sum: '<S636>/Subtract'
           */
          rtb_Divide_lr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_k) * FMS_ConstB.d_k) - FMS_ConstB.d_k) * 0.5F *
            rtb_Divide_lr_idx_2 + rtb_Divide_pr_idx_1;

          /* Sum: '<S636>/Add4' */
          rtb_Divide_pr_idx_0 = (rtb_Saturation_e - rtb_Divide_lr_idx_2) +
            rtb_Divide_pr_idx_1;

          /* Sum: '<S636>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_k;

          /* Sum: '<S636>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_k;

          /* Signum: '<S636>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S636>/Sign1' */

          /* Signum: '<S636>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S636>/Sign2' */

          /* Sum: '<S636>/Add5' incorporates:
           *  Gain: '<S636>/Gain2'
           *  Product: '<S636>/Multiply4'
           *  Sum: '<S636>/Subtract2'
           */
          rtb_Divide_lr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_pr_idx_0;

          /* Update for Delay: '<S619>/Delay' */
          FMS_DW.icLoad_n = 0U;

          /* Update for DiscreteIntegrator: '<S631>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S631>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING_o = 0U;
          FMS_DW.Integrator1_DSTATE_jz += 0.004F * FMS_DW.Integrator_DSTATE_hi;
          FMS_DW.Integrator1_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Sum: '<S636>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 - FMS_ConstB.d_k;

          /* Sum: '<S636>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_2 + FMS_ConstB.d_k;

          /* Signum: '<S636>/Sign5' incorporates:
           *  Signum: '<S636>/Sign6'
           */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S636>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Divide_lr_idx_2 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S636>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_2;

            /* Signum: '<S636>/Sign6' */
            rtb_Sign5_l = rtb_Divide_lr_idx_2;
          }

          /* End of Signum: '<S636>/Sign5' */

          /* Signum: '<S636>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S636>/Sign3' */

          /* Signum: '<S636>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S636>/Sign4' */

          /* Update for DiscreteIntegrator: '<S631>/Integrator' incorporates:
           *  Constant: '<S636>/const'
           *  Gain: '<S636>/Gain3'
           *  Product: '<S636>/Divide'
           *  Product: '<S636>/Multiply5'
           *  Product: '<S636>/Multiply6'
           *  Sum: '<S636>/Subtract4'
           *  Sum: '<S636>/Subtract5'
           *  Sum: '<S636>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hi += ((rtb_Divide_lr_idx_2 / FMS_ConstB.d_k
            - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_a * ((rtb_Divide_pr_idx_0
            - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 0.785398185F) *
            0.004F;
          if (FMS_DW.Integrator_DSTATE_hi >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_hi = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_hi <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_hi = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          FMS_DW.Integrator_PrevResetState = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* End of Update for DiscreteIntegrator: '<S631>/Integrator' */
          /* End of Outputs for SubSystem: '<S299>/Hold' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S299>/Unknown' incorporates:
           *  ActionPort: '<S602>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_e);

          /* End of Outputs for SubSystem: '<S299>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/SubMode' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S47>/Auto' incorporates:
         *  ActionPort: '<S297>/Action Port'
         */
        /* SwitchCase: '<S297>/Switch Case' incorporates:
         *  Math: '<S481>/Math Function'
         *  Sum: '<S437>/Subtract'
         *  Sum: '<S494>/Sum1'
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
          /* Disable for Resettable SubSystem: '<S408>/Mission_SubSystem' */
          /* Disable for SwitchCase: '<S459>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

          /* Disable for SwitchCase: '<S449>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

          /* End of Disable for SubSystem: '<S408>/Mission_SubSystem' */
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S297>/Offboard' incorporates:
           *  ActionPort: '<S409>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Gain: '<S575>/rad2deg' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Multiply_g_idx_0 = 57.295779513082323 * FMS_U.INS_Out.lat_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S578>/deg2rad' */
          rtb_Switch1_n = 0.017453292519943295 * rtb_Multiply_g_idx_0;

          /* Trigonometry: '<S579>/Sin' */
          rtb_Gain = sin(rtb_Switch1_n);

          /* Math: '<S579>/Square1' */
          rtb_Gain *= rtb_Gain;

          /* Product: '<S579>/Multiply1' incorporates:
           *  Product: '<S579>/Multiply'
           */
          rtb_Sum3 = FMS_ConstB.ff * rtb_Gain;

          /* Product: '<S579>/Divide' incorporates:
           *  Constant: '<S579>/Constant'
           *  Constant: '<S579>/R'
           *  Sqrt: '<S579>/Sqrt'
           *  Sum: '<S579>/Sum1'
           */
          rtb_Gain = 6.378137E+6 / sqrt(1.0 - rtb_Sum3);

          /* Product: '<S579>/Product3' incorporates:
           *  Constant: '<S579>/Constant1'
           *  Product: '<S579>/Multiply1'
           *  Sum: '<S579>/Sum2'
           */
          rtb_Sum3 = 1.0 / (1.0 - rtb_Sum3) * FMS_ConstB.Sum4 * rtb_Gain;

          /* Product: '<S579>/Multiply2' incorporates:
           *  Trigonometry: '<S579>/Cos'
           */
          rtb_Gain *= cos(rtb_Switch1_n);

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S578>/Sum' incorporates:
           *  Gain: '<S575>/Gain'
           *  Inport: '<Root>/Auto_Cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          rtb_Multiply_g_idx_0 = 1.0000000000287557E-7 * (real_T)
            FMS_U.Auto_Cmd.lat_cmd - rtb_Multiply_g_idx_0;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S583>/Abs' incorporates:
           *  Abs: '<S586>/Abs1'
           *  Switch: '<S583>/Switch1'
           */
          rtb_Switch1_n = fabs(rtb_Multiply_g_idx_0);

          /* Switch: '<S583>/Switch1' incorporates:
           *  Abs: '<S583>/Abs'
           *  Bias: '<S583>/Bias2'
           *  Bias: '<S583>/Bias3'
           *  Constant: '<S580>/Constant'
           *  Constant: '<S580>/Constant1'
           *  Constant: '<S585>/Constant'
           *  Gain: '<S583>/Gain1'
           *  Product: '<S583>/Multiply'
           *  RelationalOperator: '<S585>/Compare'
           *  Switch: '<S580>/Switch'
           */
          if (rtb_Switch1_n > 90.0) {
            /* Switch: '<S586>/Switch1' incorporates:
             *  Bias: '<S586>/Bias2'
             *  Bias: '<S586>/Bias3'
             *  Constant: '<S586>/Constant'
             *  Constant: '<S587>/Constant'
             *  Math: '<S586>/Math Function'
             *  RelationalOperator: '<S587>/Compare'
             */
            if (rtb_Switch1_n > 180.0) {
              rtb_Multiply_g_idx_0 = rt_modd(rtb_Multiply_g_idx_0 + 180.0, 360.0)
                + -180.0;
            }

            /* End of Switch: '<S586>/Switch1' */

            /* Signum: '<S583>/Sign' */
            if (rtb_Multiply_g_idx_0 < 0.0) {
              rtb_Multiply_g_idx_0 = -1.0;
            } else {
              if (rtb_Multiply_g_idx_0 > 0.0) {
                rtb_Multiply_g_idx_0 = 1.0;
              }
            }

            /* End of Signum: '<S583>/Sign' */
            rtb_Multiply_g_idx_0 *= -(rtb_Switch1_n + -90.0) + 90.0;
            rtb_n = 180;
          } else {
            rtb_n = 0;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S580>/Sum' incorporates:
           *  Gain: '<S575>/Gain1'
           *  Gain: '<S575>/rad2deg'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S578>/Sum'
           */
          rtb_Switch1_n = (1.0000000000287557E-7 * (real_T)
                           FMS_U.Auto_Cmd.lon_cmd - 57.295779513082323 *
                           FMS_U.INS_Out.lon_0) + (real_T)rtb_n;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Product: '<S578>/Multiply' incorporates:
           *  Gain: '<S578>/deg2rad1'
           */
          rtb_Multiply_g_idx_0 = 0.017453292519943295 * rtb_Multiply_g_idx_0 *
            rtb_Sum3;

          /* Switch: '<S582>/Switch1' incorporates:
           *  Abs: '<S582>/Abs1'
           *  Bias: '<S582>/Bias2'
           *  Bias: '<S582>/Bias3'
           *  Constant: '<S582>/Constant'
           *  Constant: '<S584>/Constant'
           *  Math: '<S582>/Math Function'
           *  RelationalOperator: '<S584>/Compare'
           */
          if (fabs(rtb_Switch1_n) > 180.0) {
            rtb_Switch1_n = rt_modd(rtb_Switch1_n + 180.0, 360.0) + -180.0;
          }

          /* End of Switch: '<S582>/Switch1' */

          /* Product: '<S578>/Multiply' incorporates:
           *  Gain: '<S578>/deg2rad1'
           */
          rtb_Gain *= 0.017453292519943295 * rtb_Switch1_n;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S556>/Index Vector' incorporates:
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S560>/Multiply1'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S569>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S569>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S569>/Trigonometric Function3' incorporates:
             *  Gain: '<S568>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S569>/Gain' incorporates:
             *  Gain: '<S568>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S569>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S569>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S569>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S569>/Trigonometric Function' incorporates:
             *  Gain: '<S568>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S569>/Trigonometric Function1' incorporates:
             *  Gain: '<S568>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S569>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_j[0];

            /* Switch: '<S562>/Switch' incorporates:
             *  Constant: '<S577>/Constant'
             *  DataTypeConversion: '<S575>/Data Type Conversion1'
             *  Product: '<S581>/Multiply1'
             *  Product: '<S581>/Multiply2'
             *  RelationalOperator: '<S577>/Compare'
             *  S-Function (sfix_bitop): '<S574>/lat_cmd valid'
             *  Sum: '<S581>/Sum2'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) {
              rtb_Saturation_e = (real32_T)(rtb_Multiply_g_idx_0 *
                FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.x_cmd;
            }

            /* Product: '<S560>/Multiply' incorporates:
             *  Constant: '<S566>/Constant'
             *  Constant: '<S567>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S559>/Logical Operator'
             *  RelationalOperator: '<S566>/Compare'
             *  RelationalOperator: '<S567>/Compare'
             *  S-Function (sfix_bitop): '<S559>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S559>/x_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S560>/Sum1'
             */
            rtb_Divide_pr_idx_1 = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U) ? rtb_Saturation_e -
              FMS_U.INS_Out.x_R : 0.0F;

            /* SignalConversion: '<S569>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_j[1];

            /* Switch: '<S562>/Switch' incorporates:
             *  Constant: '<S577>/Constant'
             *  DataTypeConversion: '<S575>/Data Type Conversion1'
             *  Product: '<S581>/Multiply3'
             *  Product: '<S581>/Multiply4'
             *  RelationalOperator: '<S577>/Compare'
             *  S-Function (sfix_bitop): '<S574>/lon_cmd valid'
             *  Sum: '<S581>/Sum3'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) {
              rtb_Saturation_e = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
                rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.y_cmd;
            }

            /* Product: '<S560>/Multiply' incorporates:
             *  Constant: '<S566>/Constant'
             *  Constant: '<S567>/Constant'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S559>/Logical Operator'
             *  RelationalOperator: '<S566>/Compare'
             *  RelationalOperator: '<S567>/Compare'
             *  S-Function (sfix_bitop): '<S559>/lon_cmd valid'
             *  S-Function (sfix_bitop): '<S559>/y_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S560>/Sum1'
             */
            rtb_Divide_lr_idx_2 = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U) ||
              ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U) ? rtb_Saturation_e -
              FMS_U.INS_Out.y_R : 0.0F;

            /* SignalConversion: '<S569>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_j[2];

            /* Switch: '<S562>/Switch' incorporates:
             *  Constant: '<S577>/Constant'
             *  DataTypeConversion: '<S575>/Data Type Conversion'
             *  DataTypeConversion: '<S575>/Data Type Conversion1'
             *  Gain: '<S575>/Gain2'
             *  Gain: '<S578>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  RelationalOperator: '<S577>/Compare'
             *  S-Function (sfix_bitop): '<S574>/alt_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S578>/Sum1'
             */
            if ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U) {
              rtb_Saturation_e = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
                -FMS_U.INS_Out.alt_0);
            } else {
              rtb_Saturation_e = FMS_U.Auto_Cmd.z_cmd;
            }

            /* Product: '<S560>/Multiply' incorporates:
             *  Constant: '<S566>/Constant'
             *  Constant: '<S567>/Constant'
             *  Gain: '<S563>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Logic: '<S559>/Logical Operator'
             *  RelationalOperator: '<S566>/Compare'
             *  RelationalOperator: '<S567>/Compare'
             *  S-Function (sfix_bitop): '<S559>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S559>/z_cmd valid'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S560>/Sum1'
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

            /* SignalConversion: '<S502>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S502>/Constant4'
             *  MultiPortSwitch: '<S491>/Index Vector'
             *  Product: '<S560>/Multiply1'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S502>/Trigonometric Function3' incorporates:
             *  Gain: '<S501>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S491>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S502>/Gain' incorporates:
             *  Gain: '<S501>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S491>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S502>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S502>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S502>/Constant3'
             *  MultiPortSwitch: '<S491>/Index Vector'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S502>/Trigonometric Function' incorporates:
             *  Gain: '<S501>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S491>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S502>/Trigonometric Function1' incorporates:
             *  Gain: '<S501>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S491>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S502>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S491>/Index Vector'
             */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_d[0];

            /* Product: '<S491>/Multiply' incorporates:
             *  Constant: '<S500>/Constant'
             *  RelationalOperator: '<S500>/Compare'
             *  S-Function (sfix_bitop): '<S497>/ax_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;

            /* SignalConversion: '<S502>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S491>/Index Vector'
             */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_d[1];

            /* Product: '<S491>/Multiply' incorporates:
             *  Constant: '<S500>/Constant'
             *  RelationalOperator: '<S500>/Compare'
             *  S-Function (sfix_bitop): '<S497>/ay_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;

            /* SignalConversion: '<S502>/ConcatBufferAtVector ConcatenateIn3' incorporates:
             *  MultiPortSwitch: '<S491>/Index Vector'
             */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_d[2];

            /* Product: '<S491>/Multiply' incorporates:
             *  Constant: '<S500>/Constant'
             *  RelationalOperator: '<S500>/Compare'
             *  S-Function (sfix_bitop): '<S497>/az_cmd valid'
             */
            rtb_Divide_pr_idx_0 = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;

            /* MultiPortSwitch: '<S491>/Index Vector' incorporates:
             *  Product: '<S498>/Multiply'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_Switch_ee[rtb_n] = rtb_VectorConcatenate_h[rtb_n + 6] *
                rtb_Divide_pr_idx_0 + (rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1);
            }
            break;

           case 1:
            /* SignalConversion: '<S572>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S572>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S572>/Trigonometric Function3' incorporates:
             *  DataStoreRead: '<S561>/Data Store Read'
             *  Gain: '<S570>/Gain'
             *  Trigonometry: '<S572>/Trigonometric Function1'
             */
            rtb_Sign5_l = arm_cos_f32(-FMS_DW.home[3]);
            rtb_VectorConcatenate_h[4] = rtb_Sign5_l;

            /* Trigonometry: '<S572>/Trigonometric Function2' incorporates:
             *  DataStoreRead: '<S561>/Data Store Read'
             *  Gain: '<S570>/Gain'
             *  Trigonometry: '<S572>/Trigonometric Function'
             */
            rtb_a_bx = arm_sin_f32(-FMS_DW.home[3]);

            /* Gain: '<S572>/Gain' incorporates:
             *  Trigonometry: '<S572>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -rtb_a_bx;

            /* SignalConversion: '<S572>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S572>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S572>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = rtb_a_bx;

            /* Trigonometry: '<S572>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = rtb_Sign5_l;

            /* SignalConversion: '<S573>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S573>/Constant4'
             */
            rtb_MatrixConcatenate1_i[5] = 0.0F;

            /* Gain: '<S571>/Gain' incorporates:
             *  DataStoreRead: '<S561>/Data Store Read'
             *  Gain: '<S503>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  MultiPortSwitch: '<S491>/Index Vector'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S561>/Subtract'
             */
            rtb_Divide_pr_idx_2 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S573>/Trigonometric Function3' incorporates:
             *  Gain: '<S571>/Gain'
             *  Trigonometry: '<S573>/Trigonometric Function1'
             */
            rtb_Sign5_l = arm_cos_f32(rtb_Divide_pr_idx_2);
            rtb_MatrixConcatenate1_i[4] = rtb_Sign5_l;

            /* Trigonometry: '<S573>/Trigonometric Function2' incorporates:
             *  Gain: '<S571>/Gain'
             *  Trigonometry: '<S573>/Trigonometric Function'
             */
            rtb_a_bx = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S573>/Gain' incorporates:
             *  Trigonometry: '<S573>/Trigonometric Function2'
             */
            rtb_MatrixConcatenate1_i[3] = -rtb_a_bx;

            /* SignalConversion: '<S573>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S573>/Constant3'
             */
            rtb_MatrixConcatenate1_i[2] = 0.0F;

            /* Trigonometry: '<S573>/Trigonometric Function' */
            rtb_MatrixConcatenate1_i[1] = rtb_a_bx;

            /* Trigonometry: '<S573>/Trigonometric Function1' */
            rtb_MatrixConcatenate1_i[0] = rtb_Sign5_l;

            /* RelationalOperator: '<S577>/Compare' incorporates:
             *  Constant: '<S577>/Constant'
             *  S-Function (sfix_bitop): '<S574>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S574>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S574>/lon_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);

            /* DataTypeConversion: '<S575>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S575>/Data Type Conversion'
             *  Gain: '<S575>/Gain2'
             *  Gain: '<S578>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S581>/Multiply1'
             *  Product: '<S581>/Multiply2'
             *  Product: '<S581>/Multiply3'
             *  Product: '<S581>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S578>/Sum1'
             *  Sum: '<S581>/Sum2'
             *  Sum: '<S581>/Sum3'
             */
            rtb_Switch_c2[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S562>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S572>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_i[0];

            /* SignalConversion: '<S573>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[6] = FMS_ConstB.VectorConcatenate3_m[0];

            /* Sum: '<S561>/Sum' incorporates:
             *  DataStoreRead: '<S561>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S572>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_i[1];

            /* SignalConversion: '<S573>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[7] = FMS_ConstB.VectorConcatenate3_m[1];

            /* Sum: '<S561>/Sum' incorporates:
             *  DataStoreRead: '<S561>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S572>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_i[2];

            /* SignalConversion: '<S573>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_MatrixConcatenate1_i[8] = FMS_ConstB.VectorConcatenate3_m[2];

            /* Sum: '<S561>/Sum' incorporates:
             *  DataStoreRead: '<S561>/Data Store Read'
             *  Gain: '<S563>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S566>/Compare' incorporates:
             *  Constant: '<S566>/Constant'
             *  S-Function (sfix_bitop): '<S559>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S559>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S559>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S567>/Compare' incorporates:
             *  Constant: '<S567>/Constant'
             *  S-Function (sfix_bitop): '<S559>/alt_cmd valid'
             *  S-Function (sfix_bitop): '<S559>/lat_cmd valid'
             *  S-Function (sfix_bitop): '<S559>/lon_cmd valid'
             */
            tmp_1[0] = ((FMS_U.Auto_Cmd.cmd_mask & 1024U) > 0U);
            tmp_1[1] = ((FMS_U.Auto_Cmd.cmd_mask & 2048U) > 0U);
            tmp_1[2] = ((FMS_U.Auto_Cmd.cmd_mask & 4096U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Sum: '<S561>/Sum2' incorporates:
               *  Product: '<S561>/Multiply2'
               *  Switch: '<S562>/Switch'
               */
              if (tmp[rtb_n]) {
                rtb_Saturation_e = rtb_Switch_c2[rtb_n];
              } else {
                rtb_Saturation_e = rtb_MatrixConcatenate1_i_0[rtb_n];
              }

              /* Product: '<S561>/Multiply' incorporates:
               *  Logic: '<S559>/Logical Operator'
               *  Product: '<S561>/Multiply2'
               *  Sum: '<S561>/Sum'
               *  Sum: '<S561>/Sum2'
               */
              rtb_Switch_ee[rtb_n] = tmp_0[rtb_n] || tmp_1[rtb_n] ?
                rtb_Saturation_e - ((rtb_VectorConcatenate_h[rtb_n + 3] *
                rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1) + rtb_VectorConcatenate_h[rtb_n + 6] *
                                    rtb_Divide_pr_idx_0) : 0.0F;
            }

            /* SignalConversion: '<S504>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S504>/Constant4'
             *  MultiPortSwitch: '<S491>/Index Vector'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S504>/Trigonometric Function3' incorporates:
             *  MultiPortSwitch: '<S491>/Index Vector'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(rtb_Divide_pr_idx_2);

            /* Gain: '<S504>/Gain' incorporates:
             *  MultiPortSwitch: '<S491>/Index Vector'
             *  Trigonometry: '<S504>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(rtb_Divide_pr_idx_2);

            /* SignalConversion: '<S504>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S504>/Constant3'
             *  MultiPortSwitch: '<S491>/Index Vector'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S504>/Trigonometric Function' incorporates:
             *  MultiPortSwitch: '<S491>/Index Vector'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(rtb_Divide_pr_idx_2);

            /* Trigonometry: '<S504>/Trigonometric Function1' incorporates:
             *  MultiPortSwitch: '<S491>/Index Vector'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(rtb_Divide_pr_idx_2);

            /* Product: '<S491>/Multiply' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.ax_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.ay_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.az_cmd;

            /* RelationalOperator: '<S500>/Compare' incorporates:
             *  Constant: '<S500>/Constant'
             *  S-Function (sfix_bitop): '<S497>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S497>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S497>/az_cmd valid'
             */
            tmp[0] = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            tmp[1] = ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U);
            tmp[2] = ((FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U);
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* SignalConversion: '<S504>/ConcatBufferAtVector ConcatenateIn3' incorporates:
               *  MultiPortSwitch: '<S491>/Index Vector'
               */
              rtb_VectorConcatenate_h[rtb_n + 6] =
                FMS_ConstB.VectorConcatenate3_l[rtb_n];

              /* Product: '<S491>/Multiply' */
              rtb_Switch_c2[rtb_n] = tmp[rtb_n] ?
                rtb_MatrixConcatenate1_i_0[rtb_n] : 0.0F;
              rtb_Switch_an[rtb_n] = rtb_MatrixConcatenate1_i[rtb_n + 6] *
                rtb_Switch_ee[2] + (rtb_MatrixConcatenate1_i[rtb_n + 3] *
                                    rtb_Switch_ee[1] +
                                    rtb_MatrixConcatenate1_i[rtb_n] *
                                    rtb_Switch_ee[0]);
            }

            /* MultiPortSwitch: '<S491>/Index Vector' incorporates:
             *  Product: '<S499>/Multiply3'
             *  Product: '<S561>/Multiply3'
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

            /* S-Function (sfix_bitop): '<S574>/lat_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S559>/lat_cmd valid'
             */
            tmp_2 = FMS_U.Auto_Cmd.cmd_mask & 1024U;

            /* RelationalOperator: '<S577>/Compare' incorporates:
             *  Constant: '<S577>/Constant'
             *  S-Function (sfix_bitop): '<S574>/lat_cmd valid'
             */
            tmp[0] = (tmp_2 > 0U);

            /* S-Function (sfix_bitop): '<S574>/lon_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S559>/lon_cmd valid'
             */
            tmp_3 = FMS_U.Auto_Cmd.cmd_mask & 2048U;

            /* RelationalOperator: '<S577>/Compare' incorporates:
             *  Constant: '<S577>/Constant'
             *  S-Function (sfix_bitop): '<S574>/lon_cmd valid'
             */
            tmp[1] = (tmp_3 > 0U);

            /* S-Function (sfix_bitop): '<S574>/alt_cmd valid' incorporates:
             *  S-Function (sfix_bitop): '<S559>/alt_cmd valid'
             */
            tmp_4 = FMS_U.Auto_Cmd.cmd_mask & 4096U;

            /* RelationalOperator: '<S577>/Compare' incorporates:
             *  Constant: '<S577>/Constant'
             *  S-Function (sfix_bitop): '<S574>/alt_cmd valid'
             */
            tmp[2] = (tmp_4 > 0U);

            /* DataTypeConversion: '<S575>/Data Type Conversion1' incorporates:
             *  DataTypeConversion: '<S575>/Data Type Conversion'
             *  Gain: '<S575>/Gain2'
             *  Gain: '<S578>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S581>/Multiply1'
             *  Product: '<S581>/Multiply2'
             *  Product: '<S581>/Multiply3'
             *  Product: '<S581>/Multiply4'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S578>/Sum1'
             *  Sum: '<S581>/Sum2'
             *  Sum: '<S581>/Sum3'
             */
            rtb_Switch_c2[0] = (real32_T)(rtb_Multiply_g_idx_0 *
              FMS_ConstB.SinCos_o2 + rtb_Gain * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[1] = (real32_T)(rtb_Gain * FMS_ConstB.SinCos_o2 -
              rtb_Multiply_g_idx_0 * FMS_ConstB.SinCos_o1);
            rtb_Switch_c2[2] = (real32_T)-(FMS_U.Auto_Cmd.alt_cmd +
              -FMS_U.INS_Out.alt_0);

            /* Switch: '<S562>/Switch' */
            rtb_MatrixConcatenate1_i_0[0] = FMS_U.Auto_Cmd.x_cmd;
            rtb_MatrixConcatenate1_i_0[1] = FMS_U.Auto_Cmd.y_cmd;
            rtb_MatrixConcatenate1_i_0[2] = FMS_U.Auto_Cmd.z_cmd;

            /* SignalConversion: '<S565>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_g[0];

            /* Sum: '<S558>/Sum' incorporates:
             *  DataStoreRead: '<S558>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_1 = FMS_U.INS_Out.x_R - FMS_DW.home[0];

            /* SignalConversion: '<S565>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_g[1];

            /* Sum: '<S558>/Sum' incorporates:
             *  DataStoreRead: '<S558>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_lr_idx_2 = FMS_U.INS_Out.y_R - FMS_DW.home[1];

            /* SignalConversion: '<S565>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_g[2];

            /* Sum: '<S558>/Sum' incorporates:
             *  DataStoreRead: '<S558>/Data Store Read'
             *  Gain: '<S563>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_Divide_pr_idx_0 = -FMS_U.INS_Out.h_R - FMS_DW.home[2];

            /* RelationalOperator: '<S566>/Compare' incorporates:
             *  Constant: '<S566>/Constant'
             *  S-Function (sfix_bitop): '<S559>/x_cmd valid'
             *  S-Function (sfix_bitop): '<S559>/y_cmd valid'
             *  S-Function (sfix_bitop): '<S559>/z_cmd valid'
             */
            tmp_0[0] = ((FMS_U.Auto_Cmd.cmd_mask & 128U) > 0U);
            tmp_0[1] = ((FMS_U.Auto_Cmd.cmd_mask & 256U) > 0U);
            tmp_0[2] = ((FMS_U.Auto_Cmd.cmd_mask & 512U) > 0U);

            /* RelationalOperator: '<S567>/Compare' incorporates:
             *  Constant: '<S567>/Constant'
             */
            tmp_1[0] = (tmp_2 > 0U);
            tmp_1[1] = (tmp_3 > 0U);
            tmp_1[2] = (tmp_4 > 0U);

            /* Sum: '<S558>/Sum2' incorporates:
             *  Logic: '<S559>/Logical Operator'
             *  Product: '<S558>/Multiply'
             *  Product: '<S558>/Multiply2'
             *  Sum: '<S558>/Sum'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              /* Switch: '<S562>/Switch' incorporates:
               *  Product: '<S558>/Multiply2'
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

            /* End of Sum: '<S558>/Sum2' */

            /* MultiPortSwitch: '<S491>/Index Vector' incorporates:
             *  Constant: '<S500>/Constant'
             *  Product: '<S491>/Multiply'
             *  RelationalOperator: '<S500>/Compare'
             *  S-Function (sfix_bitop): '<S497>/ax_cmd valid'
             *  S-Function (sfix_bitop): '<S497>/ay_cmd valid'
             *  S-Function (sfix_bitop): '<S497>/az_cmd valid'
             */
            rtb_Switch_ee[0] = (FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U ?
              FMS_U.Auto_Cmd.ax_cmd : 0.0F;
            rtb_Switch_ee[1] = (FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U ?
              FMS_U.Auto_Cmd.ay_cmd : 0.0F;
            rtb_Switch_ee[2] = (FMS_U.Auto_Cmd.cmd_mask & 262144U) > 0U ?
              FMS_U.Auto_Cmd.az_cmd : 0.0F;
            break;
          }

          /* End of MultiPortSwitch: '<S556>/Index Vector' */

          /* Sum: '<S552>/Sum1' incorporates:
           *  Constant: '<S552>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S552>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_U.Auto_Cmd.psi_cmd, 6.28318548F) -
            FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Abs: '<S553>/Abs' */
          rtb_Divide_pr_idx_1 = fabsf(rtb_Divide_pr_idx_2);

          /* Switch: '<S553>/Switch' incorporates:
           *  Constant: '<S553>/Constant'
           *  Constant: '<S554>/Constant'
           *  Product: '<S553>/Multiply'
           *  RelationalOperator: '<S554>/Compare'
           *  Sum: '<S553>/Subtract'
           */
          if (rtb_Divide_pr_idx_1 > 3.14159274F) {
            /* Signum: '<S553>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_2 > 0.0F) {
                rtb_Divide_pr_idx_2 = 1.0F;
              }
            }

            /* End of Signum: '<S553>/Sign' */
            rtb_Divide_pr_idx_2 *= rtb_Divide_pr_idx_1 - 6.28318548F;
          }

          /* End of Switch: '<S553>/Switch' */

          /* Saturate: '<S552>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 0.314159274F) {
            rtb_Divide_pr_idx_2 = 0.314159274F;
          } else {
            if (rtb_Divide_pr_idx_2 < -0.314159274F) {
              rtb_Divide_pr_idx_2 = -0.314159274F;
            }
          }

          /* End of Saturate: '<S552>/Saturation' */

          /* Gain: '<S549>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S493>/Sum' incorporates:
           *  Constant: '<S551>/Constant'
           *  Constant: '<S555>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S549>/Multiply2'
           *  Product: '<S550>/Multiply1'
           *  RelationalOperator: '<S551>/Compare'
           *  RelationalOperator: '<S555>/Compare'
           *  S-Function (sfix_bitop): '<S549>/psi_cmd valid'
           *  S-Function (sfix_bitop): '<S550>/psi_rate_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          rtb_Saturation_e = ((FMS_U.Auto_Cmd.cmd_mask & 32U) > 0U ?
                              rtb_Divide_pr_idx_2 : 0.0F) +
            ((FMS_U.Auto_Cmd.cmd_mask & 64U) > 0U ? FMS_U.Auto_Cmd.psi_rate_cmd :
             0.0F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Gain: '<S556>/Gain1' */
          rtb_Square_bg[0] = FMS_PARAM.XY_P * rtb_Switch_an[0];
          rtb_Square_bg[1] = FMS_PARAM.XY_P * rtb_Switch_an[1];

          /* Gain: '<S556>/Gain2' */
          rtb_Divide_pr_idx_2 = FMS_PARAM.Z_P * rtb_Switch_an[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MultiPortSwitch: '<S557>/Index Vector' incorporates:
           *  Constant: '<S593>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  Product: '<S557>/Multiply'
           *  Product: '<S590>/Multiply'
           *  Product: '<S591>/Multiply3'
           *  RelationalOperator: '<S593>/Compare'
           *  S-Function (sfix_bitop): '<S589>/u_cmd valid'
           *  S-Function (sfix_bitop): '<S589>/v_cmd valid'
           *  S-Function (sfix_bitop): '<S589>/w_cmd valid'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          switch (FMS_U.Auto_Cmd.frame) {
           case 0:
            /* SignalConversion: '<S595>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S595>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Trigonometry: '<S595>/Trigonometric Function3' incorporates:
             *  Gain: '<S594>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Gain: '<S595>/Gain' incorporates:
             *  Gain: '<S594>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S595>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S595>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S595>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S595>/Trigonometric Function' incorporates:
             *  Gain: '<S594>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S595>/Trigonometric Function1' incorporates:
             *  Gain: '<S594>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* SignalConversion: '<S595>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_in[0];

            /* Product: '<S557>/Multiply' incorporates:
             *  Constant: '<S593>/Constant'
             *  RelationalOperator: '<S593>/Compare'
             *  S-Function (sfix_bitop): '<S589>/u_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S595>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_in[1];

            /* Product: '<S557>/Multiply' incorporates:
             *  Constant: '<S593>/Constant'
             *  RelationalOperator: '<S593>/Compare'
             *  S-Function (sfix_bitop): '<S589>/v_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S595>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_in[2];

            /* Product: '<S557>/Multiply' incorporates:
             *  Constant: '<S593>/Constant'
             *  RelationalOperator: '<S593>/Compare'
             *  S-Function (sfix_bitop): '<S589>/w_cmd valid'
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
            /* SignalConversion: '<S597>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S597>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Gain: '<S596>/Gain' incorporates:
             *  DataStoreRead: '<S591>/Data Store Read'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S591>/Subtract'
             */
            rtb_Divide_pr_idx_1 = -(FMS_U.INS_Out.psi - FMS_DW.home[3]);

            /* Trigonometry: '<S597>/Trigonometric Function3' incorporates:
             *  Gain: '<S596>/Gain'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(rtb_Divide_pr_idx_1);

            /* Gain: '<S597>/Gain' incorporates:
             *  Gain: '<S596>/Gain'
             *  Trigonometry: '<S597>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(rtb_Divide_pr_idx_1);

            /* SignalConversion: '<S597>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S597>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S597>/Trigonometric Function' incorporates:
             *  Gain: '<S596>/Gain'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(rtb_Divide_pr_idx_1);

            /* Trigonometry: '<S597>/Trigonometric Function1' incorporates:
             *  Gain: '<S596>/Gain'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(rtb_Divide_pr_idx_1);

            /* SignalConversion: '<S597>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_gj[0];

            /* Product: '<S557>/Multiply' incorporates:
             *  Constant: '<S593>/Constant'
             *  RelationalOperator: '<S593>/Compare'
             *  S-Function (sfix_bitop): '<S589>/u_cmd valid'
             */
            rtb_Divide_pr_idx_1 = (FMS_U.Auto_Cmd.cmd_mask & 8192U) > 0U ?
              FMS_U.Auto_Cmd.u_cmd : 0.0F;

            /* SignalConversion: '<S597>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_gj[1];

            /* Product: '<S557>/Multiply' incorporates:
             *  Constant: '<S593>/Constant'
             *  RelationalOperator: '<S593>/Compare'
             *  S-Function (sfix_bitop): '<S589>/v_cmd valid'
             */
            rtb_Divide_lr_idx_2 = (FMS_U.Auto_Cmd.cmd_mask & 16384U) > 0U ?
              FMS_U.Auto_Cmd.v_cmd : 0.0F;

            /* SignalConversion: '<S597>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_gj[2];

            /* Product: '<S557>/Multiply' incorporates:
             *  Constant: '<S593>/Constant'
             *  RelationalOperator: '<S593>/Compare'
             *  S-Function (sfix_bitop): '<S589>/w_cmd valid'
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

          /* End of MultiPortSwitch: '<S557>/Index Vector' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_Switch_an[0] += rtb_Square_bg[0];
          rtb_Switch_an[1] += rtb_Square_bg[1];

          /* Sum: '<S494>/Sum1' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + rtb_Switch_an[2];

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S512>/Switch' incorporates:
           *  Constant: '<S527>/Constant'
           *  Constant: '<S529>/Constant'
           *  Constant: '<S530>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S527>/Compare'
           *  RelationalOperator: '<S529>/Compare'
           *  RelationalOperator: '<S530>/Compare'
           *  S-Function (sfix_bitop): '<S512>/x_u_cmd'
           *  S-Function (sfix_bitop): '<S512>/y_v_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S512>/Logical Operator' incorporates:
             *  Constant: '<S528>/Constant'
             *  Constant: '<S529>/Constant'
             *  Constant: '<S530>/Constant'
             *  RelationalOperator: '<S528>/Compare'
             *  RelationalOperator: '<S529>/Compare'
             *  RelationalOperator: '<S530>/Compare'
             *  S-Function (sfix_bitop): '<S512>/lat_lon_cmd valid'
             *  S-Function (sfix_bitop): '<S512>/x_u_cmd'
             *  S-Function (sfix_bitop): '<S512>/y_v_cmd'
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

          /* End of Switch: '<S512>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Atomic SubSystem: '<S492>/u_cmd_valid' */
          /* MATLAB Function: '<S524>/bit_shift' incorporates:
           *  DataTypeConversion: '<S492>/Data Type Conversion6'
           */
          rtb_y_aw = (uint16_T)(rtb_Compare_kd << 6);

          /* End of Outputs for SubSystem: '<S492>/u_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S492>/v_cmd_valid' */
          /* MATLAB Function: '<S525>/bit_shift' incorporates:
           *  DataTypeConversion: '<S492>/Data Type Conversion7'
           */
          rtb_y_cc = (uint16_T)(rtb_FixPtRelationalOperator_me << 7);

          /* End of Outputs for SubSystem: '<S492>/v_cmd_valid' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S513>/Switch' incorporates:
           *  Constant: '<S532>/Constant'
           *  Constant: '<S533>/Constant'
           *  Constant: '<S535>/Constant'
           *  Inport: '<Root>/Auto_Cmd'
           *  RelationalOperator: '<S532>/Compare'
           *  RelationalOperator: '<S533>/Compare'
           *  RelationalOperator: '<S535>/Compare'
           *  S-Function (sfix_bitop): '<S513>/ax_cmd'
           *  S-Function (sfix_bitop): '<S513>/ay_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           */
          if (FMS_U.Auto_Cmd.frame < 2) {
            /* Logic: '<S513>/Logical Operator' incorporates:
             *  Constant: '<S533>/Constant'
             *  Constant: '<S535>/Constant'
             *  RelationalOperator: '<S533>/Compare'
             *  RelationalOperator: '<S535>/Compare'
             *  S-Function (sfix_bitop): '<S513>/ax_cmd'
             *  S-Function (sfix_bitop): '<S513>/ay_cmd'
             */
            rtb_Compare_kd = (((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U) ||
                              ((FMS_U.Auto_Cmd.cmd_mask & 131072U) > 0U));
            rtb_FixPtRelationalOperator_me = rtb_Compare_kd;
          } else {
            rtb_Compare_kd = ((FMS_U.Auto_Cmd.cmd_mask & 65536U) > 0U);
            rtb_FixPtRelationalOperator_me = ((FMS_U.Auto_Cmd.cmd_mask & 131072U)
              > 0U);
          }

          /* End of Switch: '<S513>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S409>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S409>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S409>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Inport: '<Root>/Auto_Cmd'
           *  Outport: '<Root>/FMS_Out'
           *  SignalConversion: '<S40>/Signal Copy'
           */
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

          /* Saturate: '<S493>/Saturation' */
          if (rtb_Saturation_e > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (rtb_Saturation_e < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = rtb_Saturation_e;
          }

          /* End of Saturate: '<S493>/Saturation' */

          /* Saturate: '<S494>/Saturation2' */
          if (rtb_Switch_an[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_an[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = rtb_Switch_an[0];
          }

          /* End of Saturate: '<S494>/Saturation2' */

          /* Saturate: '<S494>/Saturation1' */
          if (rtb_Switch_an[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (rtb_Switch_an[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = rtb_Switch_an[1];
          }

          /* End of Saturate: '<S494>/Saturation1' */

          /* Saturate: '<S494>/Saturation3' */
          if (rtb_Divide_pr_idx_1 > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (rtb_Divide_pr_idx_1 < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S409>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = rtb_Divide_pr_idx_1;
          }

          /* End of Saturate: '<S494>/Saturation3' */

          /* Outputs for Atomic SubSystem: '<S492>/q_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Outputs for Atomic SubSystem: '<S492>/r_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S492>/phi_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S492>/theta_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S492>/psi_rate_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S492>/w_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S492>/ax_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S492>/ay_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S492>/az_cmd_valid' */
          /* Outputs for Atomic SubSystem: '<S492>/throttle_cmd_valid' */
          /* BusAssignment: '<S409>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S505>/Constant'
           *  Constant: '<S506>/Constant'
           *  Constant: '<S507>/Constant'
           *  Constant: '<S508>/Constant'
           *  Constant: '<S509>/Constant'
           *  Constant: '<S510>/Constant'
           *  Constant: '<S511>/Constant'
           *  Constant: '<S531>/Constant'
           *  Constant: '<S534>/Constant'
           *  DataTypeConversion: '<S492>/Data Type Conversion10'
           *  DataTypeConversion: '<S492>/Data Type Conversion9'
           *  Inport: '<Root>/Auto_Cmd'
           *  MATLAB Function: '<S514>/bit_shift'
           *  MATLAB Function: '<S515>/bit_shift'
           *  MATLAB Function: '<S516>/bit_shift'
           *  MATLAB Function: '<S518>/bit_shift'
           *  MATLAB Function: '<S519>/bit_shift'
           *  MATLAB Function: '<S520>/bit_shift'
           *  MATLAB Function: '<S521>/bit_shift'
           *  MATLAB Function: '<S522>/bit_shift'
           *  MATLAB Function: '<S523>/bit_shift'
           *  MATLAB Function: '<S526>/bit_shift'
           *  Outport: '<Root>/FMS_Out'
           *  RelationalOperator: '<S505>/Compare'
           *  RelationalOperator: '<S506>/Compare'
           *  RelationalOperator: '<S507>/Compare'
           *  RelationalOperator: '<S508>/Compare'
           *  RelationalOperator: '<S509>/Compare'
           *  RelationalOperator: '<S510>/Compare'
           *  RelationalOperator: '<S511>/Compare'
           *  RelationalOperator: '<S531>/Compare'
           *  RelationalOperator: '<S534>/Compare'
           *  S-Function (sfix_bitop): '<S492>/p_cmd'
           *  S-Function (sfix_bitop): '<S492>/phi_cmd'
           *  S-Function (sfix_bitop): '<S492>/psi_psi_rate_cmd'
           *  S-Function (sfix_bitop): '<S492>/q_cmd'
           *  S-Function (sfix_bitop): '<S492>/r_cmd'
           *  S-Function (sfix_bitop): '<S492>/theta_cmd'
           *  S-Function (sfix_bitop): '<S492>/throttle_cmd'
           *  S-Function (sfix_bitop): '<S512>/alt_z_w_cmd'
           *  S-Function (sfix_bitop): '<S513>/az_cmd'
           *  SignalConversion: '<S40>/Signal Copy'
           *  Sum: '<S492>/Add'
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

          /* End of Outputs for SubSystem: '<S492>/throttle_cmd_valid' */
          /* End of Outputs for SubSystem: '<S492>/az_cmd_valid' */
          /* End of Outputs for SubSystem: '<S492>/ay_cmd_valid' */
          /* End of Outputs for SubSystem: '<S492>/ax_cmd_valid' */
          /* End of Outputs for SubSystem: '<S492>/w_cmd_valid' */
          /* End of Outputs for SubSystem: '<S492>/psi_rate_cmd_valid' */
          /* End of Outputs for SubSystem: '<S492>/theta_cmd_valid' */
          /* End of Outputs for SubSystem: '<S492>/phi_cmd_valid' */
          /* End of Outputs for SubSystem: '<S492>/r_cmd_valid' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S492>/q_cmd_valid' */
          /* End of Outputs for SubSystem: '<S297>/Offboard' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S297>/Mission' incorporates:
             *  ActionPort: '<S408>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S297>/Switch Case' incorporates:
             *  UnitDelay: '<S411>/Delay Input1'
             *
             * Block description for '<S411>/Delay Input1':
             *
             *  Store in Global RAM
             */
            FMS_DW.DelayInput1_DSTATE_n = 0U;

            /* End of InitializeConditions for SubSystem: '<S297>/Mission' */

            /* SystemReset for IfAction SubSystem: '<S297>/Mission' incorporates:
             *  ActionPort: '<S408>/Action Port'
             */
            /* SystemReset for Resettable SubSystem: '<S408>/Mission_SubSystem' */
            /* SystemReset for SwitchCase: '<S297>/Switch Case' incorporates:
             *  Chart: '<S450>/Motion Status'
             *  Chart: '<S460>/Motion State'
             *  Delay: '<S416>/Delay'
             *  Delay: '<S438>/Delay'
             *  DiscreteIntegrator: '<S419>/Integrator'
             *  DiscreteIntegrator: '<S419>/Integrator1'
             *  DiscreteIntegrator: '<S434>/Acceleration_Speed'
             *  DiscreteIntegrator: '<S439>/Discrete-Time Integrator'
             *  DiscreteIntegrator: '<S486>/Discrete-Time Integrator'
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

            /* End of SystemReset for SubSystem: '<S408>/Mission_SubSystem' */
            /* End of SystemReset for SubSystem: '<S297>/Mission' */
          }

          /* Outputs for IfAction SubSystem: '<S297>/Mission' incorporates:
           *  ActionPort: '<S408>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* RelationalOperator: '<S411>/FixPt Relational Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *  UnitDelay: '<S411>/Delay Input1'
           *
           * Block description for '<S411>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_B.wp_index !=
            FMS_DW.DelayInput1_DSTATE_n);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outputs for Resettable SubSystem: '<S408>/Mission_SubSystem' incorporates:
           *  ResetPort: '<S412>/Reset'
           */
          if (rtb_FixPtRelationalOperator_me &&
              (FMS_PrevZCX.Mission_SubSystem_Reset_ZCE != POS_ZCSIG)) {
            /* Disable for SwitchCase: '<S459>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

            /* Disable for SwitchCase: '<S449>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

            /* InitializeConditions for Delay: '<S438>/Delay' */
            FMS_DW.icLoad_l = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S439>/Discrete-Time Integrator' */
            FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;

            /* InitializeConditions for DiscreteIntegrator: '<S434>/Acceleration_Speed' */
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
            FMS_DW.Acceleration_Speed_PrevResetSta = 0;

            /* InitializeConditions for DiscreteIntegrator: '<S486>/Discrete-Time Integrator' */
            FMS_DW.l1_heading = 0.0F;

            /* InitializeConditions for Delay: '<S416>/Delay' */
            FMS_DW.icLoad_m = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator1' */
            FMS_DW.Integrator1_IC_LOADING = 1U;

            /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator' */
            FMS_DW.Integrator_DSTATE_m = 0.0F;

            /* SystemReset for Chart: '<S460>/Motion State' */
            FMS_MotionState_Reset(&FMS_DW.sf_MotionState_g);

            /* SystemReset for Chart: '<S450>/Motion Status' */
            FMS_MotionStatus_f_Reset(&FMS_DW.sf_MotionStatus_d);
          }

          FMS_PrevZCX.Mission_SubSystem_Reset_ZCE =
            rtb_FixPtRelationalOperator_me;

          /* Delay: '<S438>/Delay' incorporates:
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
          /* Switch: '<S434>/Switch2' incorporates:
           *  Constant: '<S434>/vel'
           *  Constant: '<S443>/Constant'
           *  RelationalOperator: '<S443>/Compare'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          if (FMS_B.Cmd_In.set_speed > 0.0F) {
            d = FMS_B.Cmd_In.set_speed;
          } else {
            d = FMS_PARAM.CRUISE_SPEED;
          }

          /* End of Switch: '<S434>/Switch2' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* DiscreteIntegrator: '<S439>/Discrete-Time Integrator' incorporates:
           *  UnitDelay: '<S411>/Delay Input1'
           *
           * Block description for '<S411>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_DW.DiscreteTimeIntegrator_DSTAT_kf;

          /* RelationalOperator: '<S433>/Compare' incorporates:
           *  Constant: '<S490>/Constant'
           *  RelationalOperator: '<S490>/Compare'
           *  UnitDelay: '<S411>/Delay Input1'
           *
           * Block description for '<S411>/Delay Input1':
           *
           *  Store in Global RAM
           */
          rtb_FixPtRelationalOperator_me = (FMS_DW.DelayInput1_DSTATE_n <= 3);

          /* DiscreteIntegrator: '<S434>/Acceleration_Speed' */
          if (rtb_FixPtRelationalOperator_me ||
              (FMS_DW.Acceleration_Speed_PrevResetSta != 0)) {
            FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S460>/Motion State' incorporates:
           *  Constant: '<S460>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S460>/Square'
           *  Math: '<S460>/Square1'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sqrt: '<S460>/Sqrt'
           *  Sum: '<S460>/Add'
           */
          FMS_MotionState(0.0F, sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve), &rtb_state_l4,
                          &FMS_DW.sf_MotionState_g);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S459>/Switch Case' incorporates:
           *  DiscreteIntegrator: '<S469>/Integrator1'
           *  Gain: '<S463>/Gain6'
           *  Gain: '<S467>/Gain'
           *  Gain: '<S468>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S469>/Subtract'
           *  Sum: '<S470>/Add'
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
              /* SystemReset for IfAction SubSystem: '<S459>/Hold Control' incorporates:
               *  ActionPort: '<S462>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S459>/Switch Case' */
              FMS_HoldControl_i_Reset(&FMS_DW.HoldControl_m);

              /* End of SystemReset for SubSystem: '<S459>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S459>/Hold Control' incorporates:
             *  ActionPort: '<S462>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_i(FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                              FMS_U.INS_Out.psi, FMS_B.Merge_f,
                              &FMS_ConstB.HoldControl_m, &FMS_DW.HoldControl_m);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S459>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S459>/Brake Control' incorporates:
             *  ActionPort: '<S461>/Action Port'
             */
            FMS_BrakeControl_e(FMS_B.Merge_f);

            /* End of Outputs for SubSystem: '<S459>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_fg != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S459>/Move Control' incorporates:
               *  ActionPort: '<S463>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S459>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S469>/Integrator'
               *  DiscreteIntegrator: '<S469>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;
              FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S459>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S459>/Move Control' incorporates:
             *  ActionPort: '<S463>/Action Port'
             */
            /* SignalConversion: '<S463>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S469>/Integrator1'
             */
            FMS_B.Merge_f[0] = FMS_DW.Integrator1_DSTATE_e[0];

            /* Product: '<S470>/Multiply1' incorporates:
             *  Constant: '<S470>/const1'
             *  DiscreteIntegrator: '<S469>/Integrator'
             */
            rtb_Subtract_hb[0] = FMS_DW.Integrator_DSTATE_o[0] * 0.05F;

            /* SignalConversion: '<S463>/OutportBufferForuv_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S469>/Integrator1'
             */
            FMS_B.Merge_f[1] = FMS_DW.Integrator1_DSTATE_e[1];

            /* Product: '<S470>/Multiply1' incorporates:
             *  Constant: '<S470>/const1'
             *  DiscreteIntegrator: '<S469>/Integrator'
             */
            rtb_Subtract_hb[1] = FMS_DW.Integrator_DSTATE_o[1] * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S467>/Dead Zone' incorporates:
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

            /* Sum: '<S470>/Add' incorporates:
             *  DiscreteIntegrator: '<S469>/Integrator1'
             *  Gain: '<S463>/Gain6'
             *  Gain: '<S467>/Gain'
             *  Sum: '<S469>/Subtract'
             */
            rtb_Divide_i5[0] = (FMS_DW.Integrator1_DSTATE_e[0] - 1.0F / (1.0F -
              FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[0];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S468>/Dead Zone' incorporates:
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

            /* Sum: '<S470>/Add' incorporates:
             *  DiscreteIntegrator: '<S469>/Integrator1'
             *  Gain: '<S463>/Gain6'
             *  Gain: '<S468>/Gain'
             *  Sum: '<S469>/Subtract'
             */
            rtb_Divide_i5[1] = (FMS_DW.Integrator1_DSTATE_e[1] - 1.0F / (1.0F -
              FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.VEL_XY_LIM) +
              rtb_Subtract_hb[1];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S467>/Dead Zone' incorporates:
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

            /* Signum: '<S470>/Sign' incorporates:
             *  DiscreteIntegrator: '<S469>/Integrator1'
             *  Gain: '<S463>/Gain6'
             *  Gain: '<S467>/Gain'
             *  Sum: '<S469>/Subtract'
             *  Sum: '<S470>/Add'
             */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S470>/Add2' incorporates:
             *  Abs: '<S470>/Abs'
             *  Gain: '<S470>/Gain'
             *  Gain: '<S470>/Gain1'
             *  Product: '<S470>/Multiply2'
             *  Product: '<S470>/Multiply3'
             *  Signum: '<S470>/Sign'
             *  Sqrt: '<S470>/Sqrt'
             *  Sum: '<S470>/Add1'
             *  Sum: '<S470>/Subtract'
             */
            rtb_Sign5_l = (sqrtf((8.0F * fabsf(rtb_Divide_i5[0]) +
                                  FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                           FMS_ConstB.d_oe) * 0.5F * rtb_Divide_pr_idx_0 +
              rtb_Subtract_hb[0];

            /* Sum: '<S470>/Add3' incorporates:
             *  Signum: '<S470>/Sign'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_i5[0] + FMS_ConstB.d_oe;

            /* Sum: '<S470>/Subtract1' incorporates:
             *  Signum: '<S470>/Sign'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_i5[0] - FMS_ConstB.d_oe;

            /* Signum: '<S470>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S470>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S470>/Add5' incorporates:
             *  Gain: '<S470>/Gain2'
             *  Product: '<S470>/Multiply4'
             *  Signum: '<S470>/Sign'
             *  Sum: '<S470>/Add2'
             *  Sum: '<S470>/Add4'
             *  Sum: '<S470>/Subtract2'
             */
            rtb_Sign5_l += ((rtb_Divide_i5[0] - rtb_Sign5_l) + rtb_Subtract_hb[0])
              * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F);

            /* Update for DiscreteIntegrator: '<S469>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S469>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[0] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[0];

            /* Signum: '<S470>/Sign4' incorporates:
             *  Sum: '<S470>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Sign5_l - FMS_ConstB.d_oe;

            /* Signum: '<S470>/Sign3' incorporates:
             *  Sum: '<S470>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Sign5_l + FMS_ConstB.d_oe;

            /* Signum: '<S470>/Sign5' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Sign5_l;
            }

            /* Signum: '<S470>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S470>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S470>/Sign6' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Sign5_l;
            }

            /* Update for DiscreteIntegrator: '<S469>/Integrator' incorporates:
             *  Constant: '<S470>/const'
             *  Gain: '<S470>/Gain3'
             *  Product: '<S470>/Divide'
             *  Product: '<S470>/Multiply5'
             *  Product: '<S470>/Multiply6'
             *  Sum: '<S470>/Subtract4'
             *  Sum: '<S470>/Subtract5'
             *  Sum: '<S470>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[0] += ((rtb_Sign5_l / FMS_ConstB.d_oe -
              rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_g * ((rtb_Divide_pr_idx_0
              - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Saturation_e * 58.836F) *
              0.004F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S468>/Dead Zone' incorporates:
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

            /* Signum: '<S470>/Sign' incorporates:
             *  DiscreteIntegrator: '<S469>/Integrator1'
             *  Gain: '<S463>/Gain6'
             *  Gain: '<S468>/Gain'
             *  Sum: '<S469>/Subtract'
             *  Sum: '<S470>/Add'
             */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S470>/Add2' incorporates:
             *  Abs: '<S470>/Abs'
             *  Gain: '<S470>/Gain'
             *  Gain: '<S470>/Gain1'
             *  Product: '<S470>/Multiply2'
             *  Product: '<S470>/Multiply3'
             *  Signum: '<S470>/Sign'
             *  Sqrt: '<S470>/Sqrt'
             *  Sum: '<S470>/Add1'
             *  Sum: '<S470>/Subtract'
             */
            rtb_Sign5_l = (sqrtf((8.0F * fabsf(rtb_Divide_i5[1]) +
                                  FMS_ConstB.d_oe) * FMS_ConstB.d_oe) -
                           FMS_ConstB.d_oe) * 0.5F * rtb_Divide_pr_idx_0 +
              rtb_Subtract_hb[1];

            /* Sum: '<S470>/Add3' incorporates:
             *  Signum: '<S470>/Sign'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_i5[1] + FMS_ConstB.d_oe;

            /* Sum: '<S470>/Subtract1' incorporates:
             *  Signum: '<S470>/Sign'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_i5[1] - FMS_ConstB.d_oe;

            /* Signum: '<S470>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S470>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Sum: '<S470>/Add5' incorporates:
             *  Gain: '<S470>/Gain2'
             *  Product: '<S470>/Multiply4'
             *  Signum: '<S470>/Sign'
             *  Sum: '<S470>/Add2'
             *  Sum: '<S470>/Add4'
             *  Sum: '<S470>/Subtract2'
             */
            rtb_Sign5_l += ((rtb_Divide_i5[1] - rtb_Sign5_l) + rtb_Subtract_hb[1])
              * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F);

            /* Update for DiscreteIntegrator: '<S469>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S469>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_e[1] += 0.004F *
              FMS_DW.Integrator_DSTATE_o[1];

            /* Signum: '<S470>/Sign4' incorporates:
             *  Sum: '<S470>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Sign5_l - FMS_ConstB.d_oe;

            /* Signum: '<S470>/Sign3' incorporates:
             *  Sum: '<S470>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Sign5_l + FMS_ConstB.d_oe;

            /* Signum: '<S470>/Sign5' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Sign5_l;
            }

            /* Signum: '<S470>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S470>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S470>/Sign6' */
            if (rtb_Sign5_l < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Sign5_l > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Sign5_l;
            }

            /* Update for DiscreteIntegrator: '<S469>/Integrator' incorporates:
             *  Constant: '<S470>/const'
             *  Gain: '<S470>/Gain3'
             *  Product: '<S470>/Divide'
             *  Product: '<S470>/Multiply5'
             *  Product: '<S470>/Multiply6'
             *  Sum: '<S470>/Subtract4'
             *  Sum: '<S470>/Subtract5'
             *  Sum: '<S470>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_o[1] += ((rtb_Sign5_l / FMS_ConstB.d_oe -
              rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_g * ((rtb_Divide_pr_idx_0
              - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Saturation_e * 58.836F) *
              0.004F;

            /* End of Outputs for SubSystem: '<S459>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S459>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S450>/Motion Status' incorporates:
           *  Abs: '<S450>/Abs'
           *  Constant: '<S450>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_MotionStatus_g(0.0F, fabsf(FMS_U.INS_Out.vd), &rtb_state_l4,
                             &FMS_DW.sf_MotionStatus_d);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S449>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S449>/Hold Control' incorporates:
               *  ActionPort: '<S452>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S449>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_n);

              /* End of SystemReset for SubSystem: '<S449>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S449>/Hold Control' incorporates:
             *  ActionPort: '<S452>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_d,
                              &FMS_DW.HoldControl_n);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S449>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S449>/Brake Control' incorporates:
             *  ActionPort: '<S451>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_d);

            /* End of Outputs for SubSystem: '<S449>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_h != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S449>/Move Control' incorporates:
               *  ActionPort: '<S453>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S449>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S456>/Integrator'
               *  DiscreteIntegrator: '<S456>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE_n = 0.0F;
              FMS_DW.Integrator_DSTATE_ij = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S449>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S449>/Move Control' incorporates:
             *  ActionPort: '<S453>/Action Port'
             */
            /* Product: '<S457>/Multiply1' incorporates:
             *  Constant: '<S457>/const1'
             *  DiscreteIntegrator: '<S456>/Integrator'
             */
            rtb_Divide_pr_idx_1 = FMS_DW.Integrator_DSTATE_ij * 0.05F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S455>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S455>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sum: '<S457>/Add' incorporates:
             *  DiscreteIntegrator: '<S456>/Integrator1'
             *  Gain: '<S453>/Gain1'
             *  Gain: '<S455>/Gain'
             *  Sum: '<S456>/Subtract'
             */
            rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
              FMS_PARAM.THROTTLE_DZ) * rtb_Saturation_e * -FMS_PARAM.VEL_Z_LIM)
              + rtb_Divide_pr_idx_1;

            /* Signum: '<S457>/Sign' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_0;
            }

            /* End of Signum: '<S457>/Sign' */

            /* Sum: '<S457>/Add2' incorporates:
             *  Abs: '<S457>/Abs'
             *  Gain: '<S457>/Gain'
             *  Gain: '<S457>/Gain1'
             *  Product: '<S457>/Multiply2'
             *  Product: '<S457>/Multiply3'
             *  Sqrt: '<S457>/Sqrt'
             *  Sum: '<S457>/Add1'
             *  Sum: '<S457>/Subtract'
             */
            rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
              FMS_ConstB.d_oc) * FMS_ConstB.d_oc) - FMS_ConstB.d_oc) * 0.5F *
              rtb_Saturation_e + rtb_Divide_pr_idx_1;

            /* Sum: '<S457>/Add4' */
            rtb_Divide_pr_idx_2 = (rtb_Divide_pr_idx_0 - rtb_Saturation_e) +
              rtb_Divide_pr_idx_1;

            /* Sum: '<S457>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_oc;

            /* Sum: '<S457>/Subtract1' */
            rtb_Divide_pr_idx_0 -= FMS_ConstB.d_oc;

            /* Signum: '<S457>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S457>/Sign1' */

            /* Signum: '<S457>/Sign2' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S457>/Sign2' */

            /* Sum: '<S457>/Add5' incorporates:
             *  Gain: '<S457>/Gain2'
             *  Product: '<S457>/Multiply4'
             *  Sum: '<S457>/Subtract2'
             */
            rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
              0.5F * rtb_Divide_pr_idx_2;

            /* SignalConversion: '<S453>/OutportBufferForw_cmd_mPs' incorporates:
             *  DiscreteIntegrator: '<S456>/Integrator1'
             */
            FMS_B.Merge_d = FMS_DW.Integrator1_DSTATE_n;

            /* Update for DiscreteIntegrator: '<S456>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S456>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_ij;

            /* Sum: '<S457>/Subtract3' */
            rtb_Divide_pr_idx_1 = rtb_Saturation_e - FMS_ConstB.d_oc;

            /* Sum: '<S457>/Add6' */
            rtb_Divide_pr_idx_0 = rtb_Saturation_e + FMS_ConstB.d_oc;

            /* Signum: '<S457>/Sign5' incorporates:
             *  Signum: '<S457>/Sign6'
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_pr_idx_2 = -1.0F;

              /* Signum: '<S457>/Sign6' */
              rtb_Sign5_l = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;

              /* Signum: '<S457>/Sign6' */
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Divide_pr_idx_2 = rtb_Saturation_e;

              /* Signum: '<S457>/Sign6' */
              rtb_Sign5_l = rtb_Saturation_e;
            }

            /* End of Signum: '<S457>/Sign5' */

            /* Signum: '<S457>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* End of Signum: '<S457>/Sign3' */

            /* Signum: '<S457>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* End of Signum: '<S457>/Sign4' */

            /* Update for DiscreteIntegrator: '<S456>/Integrator' incorporates:
             *  Constant: '<S457>/const'
             *  Gain: '<S457>/Gain3'
             *  Product: '<S457>/Divide'
             *  Product: '<S457>/Multiply5'
             *  Product: '<S457>/Multiply6'
             *  Sum: '<S457>/Subtract4'
             *  Sum: '<S457>/Subtract5'
             *  Sum: '<S457>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE_ij += ((rtb_Saturation_e / FMS_ConstB.d_oc
              - rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_j *
              ((rtb_Divide_pr_idx_0 - rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l
              * 78.448F) * 0.004F;

            /* End of Outputs for SubSystem: '<S449>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S449>/Switch Case' */

          /* Switch: '<S414>/Switch' incorporates:
           *  Product: '<S438>/Multiply'
           *  Sum: '<S438>/Sum'
           */
          if (rtb_FixPtRelationalOperator_me) {
            /* Saturate: '<S459>/Saturation1' */
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

            /* End of Saturate: '<S459>/Saturation1' */

            /* Saturate: '<S449>/Saturation1' */
            if (FMS_B.Merge_d > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (FMS_B.Merge_d < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = FMS_B.Merge_d;
            }

            /* End of Saturate: '<S449>/Saturation1' */
          } else {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S438>/Sum' incorporates:
             *  Delay: '<S438>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_DW.Delay_DSTATE_o[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S487>/TmpSignal ConversionAtMath FunctionInport1' */
            rtb_Switch_c2[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S434>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_waypoint[0];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Subtract_hb[0] = rtb_Divide_pr_idx_1;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S438>/Sum' incorporates:
             *  Delay: '<S438>/Delay'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_DW.Delay_DSTATE_o[1];

            /* Sum: '<S434>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Saturation_e = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Sqrt: '<S446>/Sqrt' incorporates:
             *  Math: '<S446>/Square'
             *  Sum: '<S434>/Sum'
             *  Sum: '<S446>/Sum of Elements'
             */
            rtb_Divide_pr_idx_0 = sqrtf(rtb_Divide_pr_idx_0 *
              rtb_Divide_pr_idx_0 + rtb_Saturation_e * rtb_Saturation_e);

            /* SignalConversion: '<S489>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3_c[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3_c[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3_c[2];

            /* SignalConversion: '<S489>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S489>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S488>/Gain' incorporates:
             *  DiscreteIntegrator: '<S486>/Discrete-Time Integrator'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S486>/Add'
             */
            rtb_Saturation_e = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Trigonometry: '<S489>/Trigonometric Function3' */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(rtb_Saturation_e);

            /* Gain: '<S489>/Gain' incorporates:
             *  Trigonometry: '<S489>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(rtb_Saturation_e);

            /* SignalConversion: '<S489>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S489>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Trigonometry: '<S489>/Trigonometric Function' */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(rtb_Saturation_e);

            /* Trigonometry: '<S489>/Trigonometric Function1' */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(rtb_Saturation_e);

            /* Switch: '<S445>/Switch2' incorporates:
             *  Constant: '<S434>/Constant2'
             *  DiscreteIntegrator: '<S434>/Acceleration_Speed'
             *  RelationalOperator: '<S445>/LowerRelop1'
             *  RelationalOperator: '<S445>/UpperRelop'
             *  Switch: '<S445>/Switch'
             */
            if (FMS_DW.Acceleration_Speed_DSTATE > d) {
              rtb_Saturation_e = d;
            } else if (FMS_DW.Acceleration_Speed_DSTATE < 0.0F) {
              /* Switch: '<S445>/Switch' incorporates:
               *  Constant: '<S434>/Constant2'
               */
              rtb_Saturation_e = 0.0F;
            } else {
              rtb_Saturation_e = FMS_DW.Acceleration_Speed_DSTATE;
            }

            /* End of Switch: '<S445>/Switch2' */

            /* Switch: '<S434>/Switch' */
            if (rtb_Divide_pr_idx_0 > FMS_PARAM.L1) {
              rtb_Divide_pr_idx_2 = d;
            } else {
              /* Gain: '<S434>/Gain' */
              rtb_Divide_pr_idx_2 = 0.5F * rtb_Divide_pr_idx_0;

              /* Switch: '<S444>/Switch2' incorporates:
               *  Constant: '<S434>/Constant1'
               *  RelationalOperator: '<S444>/LowerRelop1'
               *  RelationalOperator: '<S444>/UpperRelop'
               *  Switch: '<S444>/Switch'
               */
              if (rtb_Divide_pr_idx_2 > d) {
                rtb_Divide_pr_idx_2 = d;
              } else {
                if (rtb_Divide_pr_idx_2 < 0.5F) {
                  /* Switch: '<S444>/Switch' incorporates:
                   *  Constant: '<S434>/Constant1'
                   */
                  rtb_Divide_pr_idx_2 = 0.5F;
                }
              }

              /* End of Switch: '<S444>/Switch2' */
            }

            /* End of Switch: '<S434>/Switch' */

            /* Switch: '<S434>/Switch1' incorporates:
             *  Sum: '<S434>/Sum1'
             */
            if (rtb_Saturation_e - rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_2 = rtb_Saturation_e;
            }

            /* End of Switch: '<S434>/Switch1' */

            /* Sum: '<S487>/Sum of Elements' incorporates:
             *  Math: '<S487>/Math Function'
             */
            rtb_Saturation_e = rtb_Switch_c2[0] * rtb_Switch_c2[0] +
              rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

            /* Math: '<S487>/Math Function1' incorporates:
             *  Sum: '<S487>/Sum of Elements'
             *
             * About '<S487>/Math Function1':
             *  Operator: sqrt
             */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
            } else {
              rtb_Saturation_e = sqrtf(rtb_Saturation_e);
            }

            /* End of Math: '<S487>/Math Function1' */

            /* Switch: '<S487>/Switch' incorporates:
             *  Constant: '<S487>/Constant'
             *  Product: '<S487>/Product'
             */
            if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_pr_idx_0 = rtb_Subtract_hb[0];
            } else {
              rtb_Divide_pr_idx_0 = 0.0F;
              rtb_Divide_pr_idx_1 = 0.0F;
              rtb_Saturation_e = 1.0F;
            }

            /* End of Switch: '<S487>/Switch' */

            /* Product: '<S485>/Multiply2' incorporates:
             *  Product: '<S487>/Divide'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_0 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_1 / rtb_Saturation_e *
              rtb_Divide_pr_idx_2;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Sum: '<S440>/Sum1' incorporates:
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Divide_pr_idx_2 = FMS_B.Cmd_In.sp_waypoint[0] -
              FMS_B.Cmd_In.cur_waypoint[0];
            rtb_Saturation_e = FMS_B.Cmd_In.sp_waypoint[1] -
              FMS_B.Cmd_In.cur_waypoint[1];

            /* Sum: '<S440>/Sum' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            rtb_Sign5_l = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
            rtb_a_bx = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S440>/Divide' incorporates:
             *  Math: '<S441>/Square'
             *  Math: '<S442>/Square'
             *  Sqrt: '<S441>/Sqrt'
             *  Sqrt: '<S442>/Sqrt'
             *  Sum: '<S440>/Sum'
             *  Sum: '<S440>/Sum1'
             *  Sum: '<S441>/Sum of Elements'
             *  Sum: '<S442>/Sum of Elements'
             */
            rtb_Saturation_e = sqrtf(rtb_Sign5_l * rtb_Sign5_l + rtb_a_bx *
              rtb_a_bx) / sqrtf(rtb_Divide_pr_idx_2 * rtb_Divide_pr_idx_2 +
                                rtb_Saturation_e * rtb_Saturation_e);

            /* Saturate: '<S440>/Saturation' */
            if (rtb_Saturation_e > 1.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              if (rtb_Saturation_e < 0.0F) {
                rtb_Saturation_e = 0.0F;
              }
            }

            /* End of Saturate: '<S440>/Saturation' */

            /* Product: '<S438>/Multiply' */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n +
                3] * rtb_Divide_pr_idx_1 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_0;
            }

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S431>/Gain' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  Product: '<S440>/Multiply'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy3Inport1'
             *  Sum: '<S431>/Sum2'
             *  Sum: '<S440>/Add'
             *  Sum: '<S440>/Subtract'
             */
            rtb_Saturation_e = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
              - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Saturation_e +
              FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            rtb_Switch_c2[0] = rtb_VectorConcatenate_g0[0];
            rtb_Switch_c2[1] = rtb_VectorConcatenate_g0[1];

            /* Saturate: '<S431>/Saturation1' incorporates:
             *  Product: '<S438>/Multiply'
             */
            if (rtb_Saturation_e > FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = FMS_PARAM.VEL_Z_LIM;
            } else if (rtb_Saturation_e < -FMS_PARAM.VEL_Z_LIM) {
              rtb_Switch_c2[2] = -FMS_PARAM.VEL_Z_LIM;
            } else {
              rtb_Switch_c2[2] = rtb_Saturation_e;
            }

            /* End of Saturate: '<S431>/Saturation1' */
          }

          /* End of Switch: '<S414>/Switch' */

          /* Delay: '<S416>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          if (FMS_DW.icLoad_m != 0) {
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n = FMS_U.INS_Out.psi;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          }

          /* DiscreteIntegrator: '<S419>/Integrator1' incorporates:
           *  Delay: '<S416>/Delay'
           */
          if (FMS_DW.Integrator1_IC_LOADING != 0) {
            FMS_DW.Integrator1_DSTATE_mf = FMS_DW.Delay_DSTATE_n;
          }

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Math: '<S423>/Rem' incorporates:
           *  Constant: '<S423>/Constant1'
           *  DiscreteIntegrator: '<S419>/Integrator1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  Sum: '<S418>/Sum'
           */
          rtb_Divide_pr_idx_2 = rt_remf(FMS_DW.Integrator1_DSTATE_mf -
            FMS_U.INS_Out.psi, 6.28318548F);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S423>/Switch' incorporates:
           *  Abs: '<S423>/Abs'
           *  Constant: '<S423>/Constant'
           *  Constant: '<S424>/Constant'
           *  Product: '<S423>/Multiply'
           *  RelationalOperator: '<S424>/Compare'
           *  Sum: '<S423>/Add'
           */
          if (fabsf(rtb_Divide_pr_idx_2) > 3.14159274F) {
            /* Signum: '<S423>/Sign' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2;
            }

            /* End of Signum: '<S423>/Sign' */
            rtb_Divide_pr_idx_2 -= 6.28318548F * rtb_Divide_pr_idx_1;
          }

          /* End of Switch: '<S423>/Switch' */

          /* Gain: '<S418>/Gain2' */
          rtb_Divide_pr_idx_2 *= FMS_PARAM.YAW_P;

          /* Saturate: '<S418>/Saturation' */
          if (rtb_Divide_pr_idx_2 > FMS_PARAM.YAW_RATE_LIM) {
            rtb_Divide_pr_idx_2 = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (rtb_Divide_pr_idx_2 < -FMS_PARAM.YAW_RATE_LIM) {
              rtb_Divide_pr_idx_2 = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Saturate: '<S418>/Saturation' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S412>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S412>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S412>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d3;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_d;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
          FMS_Y.FMS_Out.u_cmd = rtb_Switch_c2[0];
          FMS_Y.FMS_Out.v_cmd = rtb_Switch_c2[1];
          FMS_Y.FMS_Out.w_cmd = rtb_Switch_c2[2];
          FMS_Y.FMS_Out.psi_rate_cmd = rtb_Divide_pr_idx_2;

          /* Math: '<S480>/Math Function1'
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
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S480>/Product'
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

          /* End of Switch: '<S480>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S412>/Sum' incorporates:
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

          /* SignalConversion: '<S430>/TmpSignal ConversionAtMath FunctionInport1' incorporates:
           *  Sum: '<S412>/Sum'
           */
          rtb_P_cg[0] = rtb_Divide_pr_idx_0;
          rtb_P_cg[1] = rtb_Divide_pr_idx_1;

          /* Math: '<S430>/Math Function' incorporates:
           *  Sum: '<S412>/Sum'
           */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 * rtb_Divide_pr_idx_0;
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1;

          /* Sum: '<S430>/Sum of Elements' */
          rtb_Saturation_e = rtb_Square_ds[0] + rtb_Square_ds[1];

          /* Math: '<S430>/Math Function1' incorporates:
           *  Sum: '<S430>/Sum of Elements'
           *
           * About '<S430>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S430>/Math Function1' */

          /* Switch: '<S430>/Switch' incorporates:
           *  Constant: '<S430>/Constant'
           *  Product: '<S430>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_a_bx = rtb_Divide_pr_idx_2;
          } else {
            rtb_Divide_pr_idx_0 = 0.0F;
            rtb_Divide_pr_idx_1 = 0.0F;
            rtb_a_bx = 1.0F;
          }

          /* End of Switch: '<S430>/Switch' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* MATLAB Function: '<S436>/NearbyRefWP' incorporates:
           *  Constant: '<S412>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_NearbyRefWP(&rtb_Switch_an[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_i5,
                          &rtb_Saturation_e);

          /* MATLAB Function: '<S436>/SearchL1RefWP' incorporates:
           *  Constant: '<S412>/L1'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_SearchL1RefWP(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                            FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, FMS_PARAM.L1,
                            rtb_P_cg, &rtb_Divide_pr_idx_2);

          /* MATLAB Function: '<S436>/OutRegionRegWP' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          FMS_OutRegionRegWP_c(&rtb_Switch_ee[0], &rtb_Switch_an[0],
                               FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                               rtb_Square_ds);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Switch: '<S436>/Switch1' incorporates:
           *  Constant: '<S473>/Constant'
           *  RelationalOperator: '<S473>/Compare'
           */
          if (rtb_Saturation_e > 0.0F) {
            rtb_P_cg[0] = rtb_Divide_i5[0];
            rtb_P_cg[1] = rtb_Divide_i5[1];
          } else {
            /* RelationalOperator: '<S472>/Compare' incorporates:
             *  Constant: '<S472>/Constant'
             */
            rtb_Compare_kd = (rtb_Divide_pr_idx_2 >= 0.0F);

            /* Switch: '<S436>/Switch' */
            if (!rtb_Compare_kd) {
              rtb_P_cg[0] = rtb_Square_ds[0];
              rtb_P_cg[1] = rtb_Square_ds[1];
            }

            /* End of Switch: '<S436>/Switch' */
          }

          /* End of Switch: '<S436>/Switch1' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S437>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_cg[0] - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          rtb_P_cg[0] = rtb_Sign5_l;
          rtb_Square_bg[0] = rtb_Sign5_l * rtb_Sign5_l;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S437>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S481>/Math Function'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Sign5_l = rtb_P_cg[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S481>/Sum of Elements' incorporates:
           *  Math: '<S481>/Math Function'
           *  Sum: '<S479>/Sum of Elements'
           */
          rtb_Saturation_e = rtb_Square_bg[0] + rtb_Sign5_l * rtb_Sign5_l;

          /* Math: '<S481>/Math Function1' incorporates:
           *  Sum: '<S481>/Sum of Elements'
           *
           * About '<S481>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Saturation_e));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Saturation_e);
          }

          /* End of Math: '<S481>/Math Function1' */

          /* Switch: '<S481>/Switch' incorporates:
           *  Constant: '<S481>/Constant'
           *  Product: '<S481>/Product'
           */
          if (rtb_Divide_pr_idx_2 > 0.0F) {
            rtb_Switch_an[0] = rtb_P_cg[0];
            rtb_Switch_an[1] = rtb_Sign5_l;
            rtb_Switch_an[2] = rtb_Divide_pr_idx_2;
          } else {
            rtb_Switch_an[0] = 0.0F;
            rtb_Switch_an[1] = 0.0F;
            rtb_Switch_an[2] = 1.0F;
          }

          /* End of Switch: '<S481>/Switch' */

          /* Product: '<S480>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];
          rtb_Divide_i5[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Sum: '<S483>/Sum of Elements' incorporates:
           *  Math: '<S483>/Math Function'
           *  SignalConversion: '<S483>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S483>/Math Function1' incorporates:
           *  Sum: '<S483>/Sum of Elements'
           *
           * About '<S483>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S483>/Math Function1' */

          /* Switch: '<S483>/Switch' incorporates:
           *  Constant: '<S483>/Constant'
           *  Product: '<S483>/Product'
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

          /* End of Switch: '<S483>/Switch' */

          /* Product: '<S481>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Sum: '<S484>/Sum of Elements' incorporates:
           *  Math: '<S484>/Math Function'
           *  SignalConversion: '<S484>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Divide_lr_idx_3 = rtb_Divide_i5[1] * rtb_Divide_i5[1] +
            rtb_Divide_i5[0] * rtb_Divide_i5[0];

          /* Math: '<S484>/Math Function1' incorporates:
           *  Sum: '<S484>/Sum of Elements'
           *
           * About '<S484>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -sqrtf(fabsf(rtb_Divide_lr_idx_3));
          } else {
            rtb_Divide_pr_idx_2 = sqrtf(rtb_Divide_lr_idx_3);
          }

          /* End of Math: '<S484>/Math Function1' */

          /* Switch: '<S484>/Switch' incorporates:
           *  Constant: '<S484>/Constant'
           *  Product: '<S484>/Product'
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

          /* End of Switch: '<S484>/Switch' */

          /* Product: '<S484>/Divide' */
          rtb_Divide_i5[0] = rtb_Switch_an[0] / rtb_Switch_an[2];

          /* Product: '<S483>/Divide' */
          rtb_P_cg[0] = rtb_Switch_c2[0] / rtb_Switch_c2[2];

          /* Product: '<S430>/Divide' */
          rtb_Square_ds[0] = rtb_Divide_pr_idx_0 / rtb_a_bx;

          /* Product: '<S484>/Divide' */
          rtb_Divide_i5[1] = rtb_Switch_an[1] / rtb_Switch_an[2];

          /* Product: '<S483>/Divide' */
          rtb_P_cg[1] = rtb_Switch_c2[1] / rtb_Switch_c2[2];

          /* Product: '<S430>/Divide' */
          rtb_Square_ds[1] = rtb_Divide_pr_idx_1 / rtb_a_bx;

          /* Sum: '<S482>/Subtract' incorporates:
           *  Product: '<S482>/Multiply'
           *  Product: '<S482>/Multiply1'
           */
          rtb_Divide_pr_idx_2 = rtb_Divide_i5[0] * rtb_P_cg[1] - rtb_Divide_i5[1]
            * rtb_P_cg[0];

          /* Signum: '<S477>/Sign1' */
          if (rtb_Divide_pr_idx_2 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S477>/Sign1' */

          /* Switch: '<S477>/Switch2' incorporates:
           *  Constant: '<S477>/Constant4'
           */
          if (rtb_Divide_pr_idx_2 == 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;
          }

          /* End of Switch: '<S477>/Switch2' */

          /* DotProduct: '<S477>/Dot Product' */
          rtb_Sign5_l = rtb_P_cg[0] * rtb_Divide_i5[0] + rtb_P_cg[1] *
            rtb_Divide_i5[1];

          /* Trigonometry: '<S477>/Acos' incorporates:
           *  DotProduct: '<S477>/Dot Product'
           */
          if (rtb_Sign5_l > 1.0F) {
            rtb_Sign5_l = 1.0F;
          } else {
            if (rtb_Sign5_l < -1.0F) {
              rtb_Sign5_l = -1.0F;
            }
          }

          /* Product: '<S477>/Multiply' incorporates:
           *  Trigonometry: '<S477>/Acos'
           */
          rtb_Divide_pr_idx_2 *= acosf(rtb_Sign5_l);

          /* Saturate: '<S437>/Saturation' */
          if (rtb_Divide_pr_idx_2 > 1.57079637F) {
            rtb_Divide_pr_idx_2 = 1.57079637F;
          } else {
            if (rtb_Divide_pr_idx_2 < -1.57079637F) {
              rtb_Divide_pr_idx_2 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S437>/Saturation' */

          /* Product: '<S437>/Divide' incorporates:
           *  Constant: '<S412>/L1'
           *  Constant: '<S437>/Constant'
           *  Gain: '<S437>/Gain'
           *  Math: '<S437>/Square'
           *  MinMax: '<S437>/Max'
           *  MinMax: '<S437>/Min'
           *  Product: '<S437>/Multiply1'
           *  Sqrt: '<S479>/Sqrt'
           *  Trigonometry: '<S437>/Sin'
           */
          rtb_Divide_lr_idx_2 = arm_sin_f32(rtb_Divide_pr_idx_2) *
            (rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2 * 2.0F) / fminf
            (FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_e), 0.5F));

          /* Sum: '<S428>/Subtract' incorporates:
           *  Product: '<S428>/Multiply'
           *  Product: '<S428>/Multiply1'
           */
          rtb_Divide_lr_idx_3 = rtb_Square_ds[0] * FMS_ConstB.Divide[1] -
            rtb_Square_ds[1] * FMS_ConstB.Divide[0];

          /* Signum: '<S417>/Sign1' */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_3 > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            }
          }

          /* End of Signum: '<S417>/Sign1' */

          /* Switch: '<S417>/Switch2' incorporates:
           *  Constant: '<S417>/Constant4'
           */
          if (rtb_Divide_lr_idx_3 == 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          }

          /* End of Switch: '<S417>/Switch2' */

          /* DotProduct: '<S417>/Dot Product' */
          rtb_Saturation_e = FMS_ConstB.Divide[0] * rtb_Square_ds[0] +
            FMS_ConstB.Divide[1] * rtb_Square_ds[1];

          /* Trigonometry: '<S417>/Acos' incorporates:
           *  DotProduct: '<S417>/Dot Product'
           */
          if (rtb_Saturation_e > 1.0F) {
            rtb_Saturation_e = 1.0F;
          } else {
            if (rtb_Saturation_e < -1.0F) {
              rtb_Saturation_e = -1.0F;
            }
          }

          /* Product: '<S417>/Multiply' incorporates:
           *  Trigonometry: '<S417>/Acos'
           */
          rtb_Divide_lr_idx_3 *= acosf(rtb_Saturation_e);

          /* Math: '<S420>/Rem' incorporates:
           *  Constant: '<S420>/Constant1'
           *  Delay: '<S416>/Delay'
           *  Sum: '<S416>/Sum2'
           */
          rtb_Divide_pr_idx_2 = rt_remf(rtb_Divide_lr_idx_3 -
            FMS_DW.Delay_DSTATE_n, 6.28318548F);

          /* Switch: '<S420>/Switch' incorporates:
           *  Abs: '<S420>/Abs'
           *  Constant: '<S420>/Constant'
           *  Constant: '<S426>/Constant'
           *  Product: '<S420>/Multiply'
           *  RelationalOperator: '<S426>/Compare'
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

          /* Sum: '<S416>/Sum' incorporates:
           *  Delay: '<S416>/Delay'
           */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 + FMS_DW.Delay_DSTATE_n;

          /* Product: '<S425>/Multiply1' incorporates:
           *  Constant: '<S425>/const1'
           *  DiscreteIntegrator: '<S419>/Integrator'
           */
          rtb_Divide_pr_idx_2 = FMS_DW.Integrator_DSTATE_m * 0.785398185F;

          /* Sum: '<S425>/Add' incorporates:
           *  DiscreteIntegrator: '<S419>/Integrator1'
           *  Sum: '<S419>/Subtract'
           */
          rtb_Divide_pr_idx_0 = (FMS_DW.Integrator1_DSTATE_mf -
            rtb_Divide_pr_idx_1) + rtb_Divide_pr_idx_2;

          /* Signum: '<S425>/Sign' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else if (rtb_Divide_pr_idx_0 > 0.0F) {
            rtb_Divide_pr_idx_1 = 1.0F;
          } else {
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0;
          }

          /* End of Signum: '<S425>/Sign' */

          /* Sum: '<S425>/Add2' incorporates:
           *  Abs: '<S425>/Abs'
           *  Gain: '<S425>/Gain'
           *  Gain: '<S425>/Gain1'
           *  Product: '<S425>/Multiply2'
           *  Product: '<S425>/Multiply3'
           *  Sqrt: '<S425>/Sqrt'
           *  Sum: '<S425>/Add1'
           *  Sum: '<S425>/Subtract'
           */
          rtb_Saturation_e = (sqrtf((8.0F * fabsf(rtb_Divide_pr_idx_0) +
            FMS_ConstB.d_m) * FMS_ConstB.d_m) - FMS_ConstB.d_m) * 0.5F *
            rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_2;

          /* Sum: '<S425>/Add4' */
          rtb_Divide_pr_idx_2 += rtb_Divide_pr_idx_0 - rtb_Saturation_e;

          /* Sum: '<S425>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_0 + FMS_ConstB.d_m;

          /* Sum: '<S425>/Subtract1' */
          rtb_Divide_pr_idx_0 -= FMS_ConstB.d_m;

          /* Signum: '<S425>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S425>/Sign1' */

          /* Signum: '<S425>/Sign2' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S425>/Sign2' */

          /* Sum: '<S425>/Add5' incorporates:
           *  Gain: '<S425>/Gain2'
           *  Product: '<S425>/Multiply4'
           *  Sum: '<S425>/Subtract2'
           */
          rtb_Saturation_e += (rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F
            * rtb_Divide_pr_idx_2;

          /* Sum: '<S425>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_m;

          /* Sum: '<S425>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Saturation_e - FMS_ConstB.d_m;

          /* Product: '<S425>/Divide' */
          rtb_Sign5_l = rtb_Saturation_e / FMS_ConstB.d_m;

          /* Signum: '<S425>/Sign5' incorporates:
           *  Signum: '<S425>/Sign6'
           */
          if (rtb_Saturation_e < 0.0F) {
            rtb_a_bx = -1.0F;

            /* Signum: '<S425>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_a_bx = 1.0F;

            /* Signum: '<S425>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_a_bx = rtb_Saturation_e;

            /* Signum: '<S425>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Saturation_e;
          }

          /* End of Signum: '<S425>/Sign5' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Sum: '<S416>/Sum1' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S40>/Signal Copy1'
           */
          rtb_Divide_lr_idx_3 -= FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Math: '<S421>/Rem' incorporates:
           *  Constant: '<S421>/Constant1'
           */
          rtb_Saturation_e = rt_remf(rtb_Divide_lr_idx_3, 6.28318548F);

          /* Switch: '<S421>/Switch' incorporates:
           *  Abs: '<S421>/Abs'
           *  Constant: '<S421>/Constant'
           *  Constant: '<S427>/Constant'
           *  Product: '<S421>/Multiply'
           *  RelationalOperator: '<S427>/Compare'
           *  Sum: '<S421>/Add'
           */
          if (fabsf(rtb_Saturation_e) > 3.14159274F) {
            /* Signum: '<S421>/Sign' */
            if (rtb_Saturation_e < 0.0F) {
              rtb_Divide_lr_idx_3 = -1.0F;
            } else if (rtb_Saturation_e > 0.0F) {
              rtb_Divide_lr_idx_3 = 1.0F;
            } else {
              rtb_Divide_lr_idx_3 = rtb_Saturation_e;
            }

            /* End of Signum: '<S421>/Sign' */
            rtb_Saturation_e -= 6.28318548F * rtb_Divide_lr_idx_3;
          }

          /* End of Switch: '<S421>/Switch' */

          /* Abs: '<S414>/Abs' */
          rtb_Saturation_e = fabsf(rtb_Saturation_e);

          /* Update for Delay: '<S438>/Delay' */
          FMS_DW.icLoad_l = 0U;

          /* Update for DiscreteIntegrator: '<S439>/Discrete-Time Integrator' incorporates:
           *  Constant: '<S432>/Constant'
           *  RelationalOperator: '<S432>/Compare'
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

          /* End of Update for DiscreteIntegrator: '<S439>/Discrete-Time Integrator' */

          /* Update for DiscreteIntegrator: '<S434>/Acceleration_Speed' incorporates:
           *  Constant: '<S434>/Constant'
           */
          FMS_DW.Acceleration_Speed_DSTATE += 0.004F * FMS_PARAM.CRUISE_ACC;
          FMS_DW.Acceleration_Speed_PrevResetSta = (int8_T)
            rtb_FixPtRelationalOperator_me;

          /* Product: '<S438>/Divide1' */
          rtb_Saturation_e = rtb_Divide_lr_idx_2 / d;

          /* Saturate: '<S438>/Saturation' */
          if (rtb_Saturation_e > 0.314159274F) {
            rtb_Saturation_e = 0.314159274F;
          } else {
            if (rtb_Saturation_e < -0.314159274F) {
              rtb_Saturation_e = -0.314159274F;
            }
          }

          /* End of Saturate: '<S438>/Saturation' */

          /* Update for DiscreteIntegrator: '<S486>/Discrete-Time Integrator' */
          FMS_DW.l1_heading += 0.004F * rtb_Saturation_e;

          /* Update for Delay: '<S416>/Delay' */
          FMS_DW.icLoad_m = 0U;

          /* Update for DiscreteIntegrator: '<S419>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S419>/Integrator'
           */
          FMS_DW.Integrator1_IC_LOADING = 0U;
          FMS_DW.Integrator1_DSTATE_mf += 0.004F * FMS_DW.Integrator_DSTATE_m;

          /* Signum: '<S425>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S425>/Sign3' */

          /* Signum: '<S425>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S425>/Sign4' */

          /* Update for DiscreteIntegrator: '<S419>/Integrator' incorporates:
           *  Constant: '<S425>/const'
           *  Gain: '<S425>/Gain3'
           *  Product: '<S425>/Multiply5'
           *  Product: '<S425>/Multiply6'
           *  Sum: '<S425>/Subtract4'
           *  Sum: '<S425>/Subtract5'
           *  Sum: '<S425>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_m += ((rtb_Sign5_l - rtb_a_bx) *
            FMS_ConstB.Gain4_cu * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) *
            0.5F) - rtb_Divide_pr_idx_2 * 0.785398185F) * 0.004F;
          if (FMS_DW.Integrator_DSTATE_m >= FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE_m = FMS_PARAM.YAW_RATE_LIM;
          } else {
            if (FMS_DW.Integrator_DSTATE_m <= -FMS_PARAM.YAW_RATE_LIM) {
              FMS_DW.Integrator_DSTATE_m = -FMS_PARAM.YAW_RATE_LIM;
            }
          }

          /* End of Update for DiscreteIntegrator: '<S419>/Integrator' */
          /* End of Outputs for SubSystem: '<S408>/Mission_SubSystem' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Update for UnitDelay: '<S411>/Delay Input1' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
           *
           * Block description for '<S411>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_n = FMS_B.wp_index;

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S297>/Mission' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S297>/Unknown' incorporates:
           *  ActionPort: '<S410>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_nt);

          /* End of Outputs for SubSystem: '<S297>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Auto' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S47>/Assist' incorporates:
         *  ActionPort: '<S296>/Action Port'
         */
        /* SwitchCase: '<S296>/Switch Case' */
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
            /* Disable for SwitchCase: '<S395>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_e = -1;
            break;

           case 2:
            /* Disable for SwitchCase: '<S311>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

            /* Disable for SwitchCase: '<S329>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
            break;

           case 3:
            /* Disable for SwitchCase: '<S345>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for SwitchCase: '<S370>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

            /* Disable for SwitchCase: '<S357>/Switch Case' */
            FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
            break;
          }
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_o) {
         case 0:
          /* Outputs for IfAction SubSystem: '<S296>/Acro' incorporates:
           *  ActionPort: '<S301>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S301>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S301>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Gain: '<S306>/Gain'
           *  Gain: '<S306>/Gain1'
           *  Gain: '<S306>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Outport: '<Root>/FMS_Out'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_d;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_c;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
          FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
          FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

          /* Saturate: '<S307>/Saturation' incorporates:
           *  Constant: '<S307>/Constant4'
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S40>/Signal Copy2'
           *  Sum: '<S307>/Sum'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
            rtb_Saturation_e = 2.0F;
          } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
            rtb_Saturation_e = 0.0F;
          } else {
            rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
          }

          /* End of Saturate: '<S307>/Saturation' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* BusAssignment: '<S301>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S307>/Constant5'
           *  Gain: '<S307>/Gain2'
           *  Outport: '<Root>/FMS_Out'
           *  Sum: '<S307>/Add'
           */
          FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
            rtb_Saturation_e), 65536.0F) + 1000U);

          /* End of Outputs for SubSystem: '<S296>/Acro' */
          break;

         case 1:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S296>/Stabilize' incorporates:
             *  ActionPort: '<S304>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S296>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S391>/Integrator'
             *  DiscreteIntegrator: '<S391>/Integrator1'
             *  DiscreteIntegrator: '<S392>/Integrator'
             *  DiscreteIntegrator: '<S392>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_d = 0.0F;
            FMS_DW.Integrator1_DSTATE_j = 0.0F;
            FMS_DW.Integrator_DSTATE_hl = 0.0F;
            FMS_DW.Integrator_DSTATE_i = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S296>/Stabilize' */

            /* SystemReset for IfAction SubSystem: '<S296>/Stabilize' incorporates:
             *  ActionPort: '<S304>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S296>/Switch Case' incorporates:
             *  Chart: '<S396>/Motion State'
             */
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_m);

            /* End of SystemReset for SubSystem: '<S296>/Stabilize' */
          }

          /* Outputs for IfAction SubSystem: '<S296>/Stabilize' incorporates:
           *  ActionPort: '<S304>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Logic: '<S386>/Logical Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S396>/Motion State' incorporates:
           *  Abs: '<S396>/Abs'
           *  Abs: '<S396>/Abs1'
           *  Constant: '<S406>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S406>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_m);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S395>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S395>/Hold Control' incorporates:
               *  ActionPort: '<S398>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S395>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_jv);

              /* End of SystemReset for SubSystem: '<S395>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S395>/Hold Control' incorporates:
             *  ActionPort: '<S398>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_o2,
                              &FMS_DW.HoldControl_jv);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S395>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S395>/Brake Control' incorporates:
             *  ActionPort: '<S397>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o2);

            /* End of Outputs for SubSystem: '<S395>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_e != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S395>/Move Control' incorporates:
               *  ActionPort: '<S399>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S395>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_b);

              /* End of SystemReset for SubSystem: '<S395>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S395>/Move Control' incorporates:
             *  ActionPort: '<S399>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_o2,
                              &FMS_ConstB.MoveControl_b, &FMS_DW.MoveControl_b);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S395>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S395>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S388>/Switch' incorporates:
           *  Constant: '<S388>/Constant'
           *  Constant: '<S388>/Constant4'
           *  Constant: '<S388>/Constant5'
           *  Gain: '<S388>/Gain2'
           *  Inport: '<Root>/Pilot_Cmd'
           *  Saturate: '<S388>/Saturation'
           *  SignalConversion: '<S40>/Signal Copy2'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           *  Sum: '<S388>/Add'
           *  Sum: '<S388>/Sum'
           */
          if (FMS_B.Compare) {
            rtb_y_aw = FMS_PARAM.LAND_LOCK_THRO;
          } else {
            if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
              /* Saturate: '<S388>/Saturation' */
              rtb_Saturation_e = 2.0F;
            } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
              /* Saturate: '<S388>/Saturation' */
              rtb_Saturation_e = 0.0F;
            } else {
              /* Saturate: '<S388>/Saturation' incorporates:
               *  Constant: '<S388>/Constant4'
               *  Inport: '<Root>/Pilot_Cmd'
               *  SignalConversion: '<S40>/Signal Copy2'
               *  Sum: '<S388>/Sum'
               */
              rtb_Saturation_e = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
            }

            rtb_y_aw = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
              rtb_Saturation_e), 65536.0F) + 1000U);
          }

          /* End of Switch: '<S388>/Switch' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S304>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S304>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S304>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DataTypeConversion: '<S386>/Data Type Conversion'
           *  DiscreteIntegrator: '<S391>/Integrator1'
           *  DiscreteIntegrator: '<S392>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S386>/Multiply'
           *  Product: '<S386>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_d;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_j;

          /* Saturate: '<S395>/Saturation' */
          if (FMS_B.Merge_o2 > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S304>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_o2 < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S304>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S304>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_o2;
          }

          /* End of Saturate: '<S395>/Saturation' */

          /* BusAssignment: '<S304>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.throttle_cmd = rtb_y_aw;

          /* Product: '<S394>/Multiply1' incorporates:
           *  Constant: '<S394>/const1'
           *  DiscreteIntegrator: '<S392>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_hl * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S390>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S390>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S394>/Add' incorporates:
           *  DiscreteIntegrator: '<S392>/Integrator1'
           *  Gain: '<S386>/Gain1'
           *  Gain: '<S390>/Gain'
           *  Sum: '<S392>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_j - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S394>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S394>/Sign' */

          /* Sum: '<S394>/Add2' incorporates:
           *  Abs: '<S394>/Abs'
           *  Gain: '<S394>/Gain'
           *  Gain: '<S394>/Gain1'
           *  Product: '<S394>/Multiply2'
           *  Product: '<S394>/Multiply3'
           *  Sqrt: '<S394>/Sqrt'
           *  Sum: '<S394>/Add1'
           *  Sum: '<S394>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_g) * FMS_ConstB.d_g) - FMS_ConstB.d_g) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S394>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Saturation_e - rtb_Divide_lr_idx_3;

          /* Sum: '<S394>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_g;

          /* Sum: '<S394>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_g;

          /* Signum: '<S394>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S394>/Sign1' */

          /* Signum: '<S394>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S394>/Sign2' */

          /* Sum: '<S394>/Add5' incorporates:
           *  Gain: '<S394>/Gain2'
           *  Product: '<S394>/Multiply4'
           *  Sum: '<S394>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Sum: '<S394>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_g;

          /* Sum: '<S394>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_g;

          /* Product: '<S394>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_g;

          /* Signum: '<S394>/Sign5' incorporates:
           *  Signum: '<S394>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S394>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S394>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Divide_lr_idx_3;

            /* Signum: '<S394>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S394>/Sign5' */

          /* Product: '<S393>/Multiply1' incorporates:
           *  Constant: '<S393>/const1'
           *  DiscreteIntegrator: '<S391>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_i * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S389>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S389>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S393>/Add' incorporates:
           *  DiscreteIntegrator: '<S391>/Integrator1'
           *  Gain: '<S386>/Gain'
           *  Gain: '<S389>/Gain'
           *  Sum: '<S391>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_d - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S393>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S393>/Sign' */

          /* Sum: '<S393>/Add2' incorporates:
           *  Abs: '<S393>/Abs'
           *  Gain: '<S393>/Gain'
           *  Gain: '<S393>/Gain1'
           *  Product: '<S393>/Multiply2'
           *  Product: '<S393>/Multiply3'
           *  Sqrt: '<S393>/Sqrt'
           *  Sum: '<S393>/Add1'
           *  Sum: '<S393>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S393>/Add4' */
          rtb_a_bx = (rtb_Saturation_e - rtb_Divide_lr_idx_3) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S393>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_a;

          /* Sum: '<S393>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_a;

          /* Signum: '<S393>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S393>/Sign1' */

          /* Signum: '<S393>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S393>/Sign2' */

          /* Sum: '<S393>/Add5' incorporates:
           *  Gain: '<S393>/Gain2'
           *  Product: '<S393>/Multiply4'
           *  Sum: '<S393>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F
            * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S391>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S391>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_i;

          /* Update for DiscreteIntegrator: '<S392>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S392>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_j += 0.004F * FMS_DW.Integrator_DSTATE_hl;

          /* Signum: '<S394>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S394>/Sign3' */

          /* Signum: '<S394>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S394>/Sign4' */

          /* Update for DiscreteIntegrator: '<S392>/Integrator' incorporates:
           *  Constant: '<S394>/const'
           *  Gain: '<S394>/Gain3'
           *  Product: '<S394>/Multiply5'
           *  Product: '<S394>/Multiply6'
           *  Sum: '<S394>/Subtract4'
           *  Sum: '<S394>/Subtract5'
           *  Sum: '<S394>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_hl += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_o
            * ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 12.566371F) * 0.004F;

          /* Sum: '<S393>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_a;

          /* Sum: '<S393>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_a;

          /* Signum: '<S393>/Sign5' incorporates:
           *  Signum: '<S393>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S393>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S393>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S393>/Sign6' */
            rtb_Sign5_l = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S393>/Sign5' */

          /* Signum: '<S393>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S393>/Sign3' */

          /* Signum: '<S393>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S393>/Sign4' */

          /* Update for DiscreteIntegrator: '<S391>/Integrator' incorporates:
           *  Constant: '<S393>/const'
           *  Gain: '<S393>/Gain3'
           *  Product: '<S393>/Divide'
           *  Product: '<S393>/Multiply5'
           *  Product: '<S393>/Multiply6'
           *  Sum: '<S393>/Subtract4'
           *  Sum: '<S393>/Subtract5'
           *  Sum: '<S393>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_i += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_a -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_k * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S296>/Stabilize' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S296>/Altitude' incorporates:
             *  ActionPort: '<S302>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S296>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S325>/Integrator'
             *  DiscreteIntegrator: '<S325>/Integrator1'
             *  DiscreteIntegrator: '<S326>/Integrator'
             *  DiscreteIntegrator: '<S326>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_m = 0.0F;
            FMS_DW.Integrator1_DSTATE_h = 0.0F;
            FMS_DW.Integrator_DSTATE_c = 0.0F;
            FMS_DW.Integrator_DSTATE_h = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S296>/Altitude' */

            /* SystemReset for IfAction SubSystem: '<S296>/Altitude' incorporates:
             *  ActionPort: '<S302>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S296>/Switch Case' incorporates:
             *  Chart: '<S312>/Motion Status'
             *  Chart: '<S330>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_k);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_dx);

            /* End of SystemReset for SubSystem: '<S296>/Altitude' */
          }

          /* Outputs for IfAction SubSystem: '<S296>/Altitude' incorporates:
           *  ActionPort: '<S302>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S312>/Motion Status' incorporates:
           *  Abs: '<S312>/Abs'
           *  Abs: '<S312>/Abs1'
           *  Constant: '<S321>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S321>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_k);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S311>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S311>/Hold Control' incorporates:
               *  ActionPort: '<S314>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S311>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_bq);

              /* End of SystemReset for SubSystem: '<S311>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S311>/Hold Control' incorporates:
             *  ActionPort: '<S314>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                              &FMS_DW.HoldControl_bq);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S311>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S311>/Brake Control' incorporates:
             *  ActionPort: '<S313>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S311>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S311>/Move Control' incorporates:
             *  ActionPort: '<S315>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_l);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S311>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S311>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Switch: '<S308>/Switch' incorporates:
           *  Constant: '<S308>/Constant'
           *  Saturate: '<S311>/Saturation1'
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          if (FMS_B.Compare) {
            rtb_Divide_pr_idx_1 = 0.5F;
          } else if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S311>/Saturation1' */
            rtb_Divide_pr_idx_1 = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
            /* Saturate: '<S311>/Saturation1' */
            rtb_Divide_pr_idx_1 = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* Saturate: '<S311>/Saturation1' */
            rtb_Divide_pr_idx_1 = FMS_B.Merge_l;
          }

          /* End of Switch: '<S308>/Switch' */

          /* Logic: '<S309>/Logical Operator' incorporates:
           *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy7Inport1'
           */
          rtb_FixPtRelationalOperator_me = !FMS_B.Compare;

          /* Chart: '<S330>/Motion State' incorporates:
           *  Abs: '<S330>/Abs'
           *  Abs: '<S330>/Abs1'
           *  Constant: '<S340>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S340>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_dx);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S329>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S329>/Hold Control' incorporates:
               *  ActionPort: '<S332>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S329>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_p);

              /* End of SystemReset for SubSystem: '<S329>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S329>/Hold Control' incorporates:
             *  ActionPort: '<S332>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_b,
                              &FMS_DW.HoldControl_p);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S329>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S329>/Brake Control' incorporates:
             *  ActionPort: '<S331>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_b);

            /* End of Outputs for SubSystem: '<S329>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_i != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S329>/Move Control' incorporates:
               *  ActionPort: '<S333>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S329>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_h);

              /* End of SystemReset for SubSystem: '<S329>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S329>/Move Control' incorporates:
             *  ActionPort: '<S333>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_b,
                              &FMS_ConstB.MoveControl_h, &FMS_DW.MoveControl_h);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S329>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S329>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S302>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S302>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S302>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  DataTypeConversion: '<S309>/Data Type Conversion'
           *  DiscreteIntegrator: '<S325>/Integrator1'
           *  DiscreteIntegrator: '<S326>/Integrator1'
           *  Outport: '<Root>/FMS_Out'
           *  Product: '<S309>/Multiply'
           *  Product: '<S309>/Multiply1'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_n;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_a;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;
          FMS_Y.FMS_Out.phi_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_m;
          FMS_Y.FMS_Out.theta_cmd = (real32_T)rtb_FixPtRelationalOperator_me *
            FMS_DW.Integrator1_DSTATE_h;

          /* Saturate: '<S329>/Saturation' */
          if (FMS_B.Merge_b > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_b < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S302>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_b;
          }

          /* End of Saturate: '<S329>/Saturation' */

          /* BusAssignment: '<S302>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Divide_pr_idx_1;

          /* Product: '<S328>/Multiply1' incorporates:
           *  Constant: '<S328>/const1'
           *  DiscreteIntegrator: '<S326>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_c * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S324>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S324>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S328>/Add' incorporates:
           *  DiscreteIntegrator: '<S326>/Integrator1'
           *  Gain: '<S309>/Gain1'
           *  Gain: '<S324>/Gain'
           *  Sum: '<S326>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_h - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_Saturation_e * -FMS_PARAM.ROLL_PITCH_LIM)
            + rtb_Divide_lr_idx_2;

          /* Signum: '<S328>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
          }

          /* End of Signum: '<S328>/Sign' */

          /* Sum: '<S328>/Add2' incorporates:
           *  Abs: '<S328>/Abs'
           *  Gain: '<S328>/Gain'
           *  Gain: '<S328>/Gain1'
           *  Product: '<S328>/Multiply2'
           *  Product: '<S328>/Multiply3'
           *  Sqrt: '<S328>/Sqrt'
           *  Sum: '<S328>/Add1'
           *  Sum: '<S328>/Subtract'
           */
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_o) * FMS_ConstB.d_o) - FMS_ConstB.d_o) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S328>/Add4' */
          rtb_Divide_lr_idx_2 += rtb_Saturation_e - rtb_Divide_lr_idx_3;

          /* Sum: '<S328>/Add3' */
          rtb_Divide_pr_idx_1 = rtb_Saturation_e + FMS_ConstB.d_o;

          /* Sum: '<S328>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_o;

          /* Signum: '<S328>/Sign1' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S328>/Sign1' */

          /* Signum: '<S328>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S328>/Sign2' */

          /* Sum: '<S328>/Add5' incorporates:
           *  Gain: '<S328>/Gain2'
           *  Product: '<S328>/Multiply4'
           *  Sum: '<S328>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_pr_idx_1 - rtb_Saturation_e) * 0.5F
            * rtb_Divide_lr_idx_2;

          /* Sum: '<S328>/Add6' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_o;

          /* Sum: '<S328>/Subtract3' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_o;

          /* Product: '<S328>/Divide' */
          d = rtb_Divide_lr_idx_3 / FMS_ConstB.d_o;

          /* Signum: '<S328>/Sign5' incorporates:
           *  Signum: '<S328>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Sign5_l = -1.0F;

            /* Signum: '<S328>/Sign6' */
            rtb_Divide_pr_idx_2 = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Sign5_l = 1.0F;

            /* Signum: '<S328>/Sign6' */
            rtb_Divide_pr_idx_2 = 1.0F;
          } else {
            rtb_Sign5_l = rtb_Divide_lr_idx_3;

            /* Signum: '<S328>/Sign6' */
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S328>/Sign5' */

          /* Product: '<S327>/Multiply1' incorporates:
           *  Constant: '<S327>/const1'
           *  DiscreteIntegrator: '<S325>/Integrator'
           */
          rtb_Divide_lr_idx_2 = FMS_DW.Integrator_DSTATE_h * 0.04F;

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* DeadZone: '<S323>/Dead Zone' incorporates:
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

          /* End of DeadZone: '<S323>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Sum: '<S327>/Add' incorporates:
           *  DiscreteIntegrator: '<S325>/Integrator1'
           *  Gain: '<S309>/Gain'
           *  Gain: '<S323>/Gain'
           *  Sum: '<S325>/Subtract'
           */
          rtb_Saturation_e = (FMS_DW.Integrator1_DSTATE_m - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_Saturation_e * FMS_PARAM.ROLL_PITCH_LIM) +
            rtb_Divide_lr_idx_2;

          /* Signum: '<S327>/Sign' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Divide_lr_idx_3 = -1.0F;
          } else if (rtb_Saturation_e > 0.0F) {
            rtb_Divide_lr_idx_3 = 1.0F;
          } else {
            rtb_Divide_lr_idx_3 = rtb_Saturation_e;
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
          rtb_Divide_lr_idx_3 = (sqrtf((8.0F * fabsf(rtb_Saturation_e) +
            FMS_ConstB.d_c) * FMS_ConstB.d_c) - FMS_ConstB.d_c) * 0.5F *
            rtb_Divide_lr_idx_3 + rtb_Divide_lr_idx_2;

          /* Sum: '<S327>/Add4' */
          rtb_a_bx = (rtb_Saturation_e - rtb_Divide_lr_idx_3) +
            rtb_Divide_lr_idx_2;

          /* Sum: '<S327>/Add3' */
          rtb_Divide_lr_idx_2 = rtb_Saturation_e + FMS_ConstB.d_c;

          /* Sum: '<S327>/Subtract1' */
          rtb_Saturation_e -= FMS_ConstB.d_c;

          /* Signum: '<S327>/Sign1' */
          if (rtb_Divide_lr_idx_2 < 0.0F) {
            rtb_Divide_lr_idx_2 = -1.0F;
          } else {
            if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_lr_idx_2 = 1.0F;
            }
          }

          /* End of Signum: '<S327>/Sign1' */

          /* Signum: '<S327>/Sign2' */
          if (rtb_Saturation_e < 0.0F) {
            rtb_Saturation_e = -1.0F;
          } else {
            if (rtb_Saturation_e > 0.0F) {
              rtb_Saturation_e = 1.0F;
            }
          }

          /* End of Signum: '<S327>/Sign2' */

          /* Sum: '<S327>/Add5' incorporates:
           *  Gain: '<S327>/Gain2'
           *  Product: '<S327>/Multiply4'
           *  Sum: '<S327>/Subtract2'
           */
          rtb_Divide_lr_idx_3 += (rtb_Divide_lr_idx_2 - rtb_Saturation_e) * 0.5F
            * rtb_a_bx;

          /* Update for DiscreteIntegrator: '<S325>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S325>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_m += 0.004F * FMS_DW.Integrator_DSTATE_h;

          /* Update for DiscreteIntegrator: '<S326>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S326>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_h += 0.004F * FMS_DW.Integrator_DSTATE_c;

          /* Signum: '<S328>/Sign3' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S328>/Sign3' */

          /* Signum: '<S328>/Sign4' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S328>/Sign4' */

          /* Update for DiscreteIntegrator: '<S326>/Integrator' incorporates:
           *  Constant: '<S328>/const'
           *  Gain: '<S328>/Gain3'
           *  Product: '<S328>/Multiply5'
           *  Product: '<S328>/Multiply6'
           *  Sum: '<S328>/Subtract4'
           *  Sum: '<S328>/Subtract5'
           *  Sum: '<S328>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_c += ((d - rtb_Sign5_l) * FMS_ConstB.Gain4_c *
            ((rtb_Divide_pr_idx_1 - rtb_Divide_pr_idx_0) * 0.5F) -
            rtb_Divide_pr_idx_2 * 12.566371F) * 0.004F;

          /* Sum: '<S327>/Subtract3' */
          rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_3 - FMS_ConstB.d_c;

          /* Sum: '<S327>/Add6' */
          rtb_Divide_pr_idx_0 = rtb_Divide_lr_idx_3 + FMS_ConstB.d_c;

          /* Signum: '<S327>/Sign5' incorporates:
           *  Signum: '<S327>/Sign6'
           */
          if (rtb_Divide_lr_idx_3 < 0.0F) {
            rtb_Divide_pr_idx_2 = -1.0F;

            /* Signum: '<S327>/Sign6' */
            rtb_Sign5_l = -1.0F;
          } else if (rtb_Divide_lr_idx_3 > 0.0F) {
            rtb_Divide_pr_idx_2 = 1.0F;

            /* Signum: '<S327>/Sign6' */
            rtb_Sign5_l = 1.0F;
          } else {
            rtb_Divide_pr_idx_2 = rtb_Divide_lr_idx_3;

            /* Signum: '<S327>/Sign6' */
            rtb_Sign5_l = rtb_Divide_lr_idx_3;
          }

          /* End of Signum: '<S327>/Sign5' */

          /* Signum: '<S327>/Sign3' */
          if (rtb_Divide_pr_idx_0 < 0.0F) {
            rtb_Divide_pr_idx_0 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_0 > 0.0F) {
              rtb_Divide_pr_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S327>/Sign3' */

          /* Signum: '<S327>/Sign4' */
          if (rtb_Divide_pr_idx_1 < 0.0F) {
            rtb_Divide_pr_idx_1 = -1.0F;
          } else {
            if (rtb_Divide_pr_idx_1 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S327>/Sign4' */

          /* Update for DiscreteIntegrator: '<S325>/Integrator' incorporates:
           *  Constant: '<S327>/const'
           *  Gain: '<S327>/Gain3'
           *  Product: '<S327>/Divide'
           *  Product: '<S327>/Multiply5'
           *  Product: '<S327>/Multiply6'
           *  Sum: '<S327>/Subtract4'
           *  Sum: '<S327>/Subtract5'
           *  Sum: '<S327>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_h += ((rtb_Divide_lr_idx_3 / FMS_ConstB.d_c -
            rtb_Divide_pr_idx_2) * FMS_ConstB.Gain4_h * ((rtb_Divide_pr_idx_0 -
            rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 12.566371F) * 0.004F;

          /* End of Outputs for SubSystem: '<S296>/Altitude' */
          break;

         case 3:
          if (FMS_DW.SwitchCase_ActiveSubsystem_o != rtPrevAction) {
            /* SystemReset for IfAction SubSystem: '<S296>/Position' incorporates:
             *  ActionPort: '<S303>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S296>/Switch Case' incorporates:
             *  Chart: '<S346>/Motion Status'
             *  Chart: '<S358>/Motion State'
             *  Chart: '<S371>/Motion State'
             */
            FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_o);
            FMS_MotionState_g_Reset(&FMS_DW.sf_MotionState_f);
            FMS_DW.temporalCounter_i1_g = 0U;
            FMS_DW.is_active_c16_FMS = 0U;
            FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

            /* End of SystemReset for SubSystem: '<S296>/Position' */
          }

          /* Outputs for IfAction SubSystem: '<S296>/Position' incorporates:
           *  ActionPort: '<S303>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S346>/Motion Status' incorporates:
           *  Abs: '<S346>/Abs'
           *  Abs: '<S346>/Abs1'
           *  Constant: '<S355>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S355>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_throttle) >
                           FMS_PARAM.THROTTLE_DZ, fabsf(FMS_U.INS_Out.vd),
                           &rtb_state_l4, &FMS_DW.sf_MotionStatus_o);

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* SwitchCase: '<S345>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S345>/Hold Control' incorporates:
               *  ActionPort: '<S348>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S345>/Switch Case' */
              FMS_HoldControl_k_Reset(&FMS_DW.HoldControl_j3);

              /* End of SystemReset for SubSystem: '<S345>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S345>/Hold Control' incorporates:
             *  ActionPort: '<S348>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_e(FMS_U.INS_Out.h_R, &FMS_B.Merge_o,
                              &FMS_DW.HoldControl_j3);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S345>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S345>/Brake Control' incorporates:
             *  ActionPort: '<S347>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S345>/Brake Control' */
            break;

           case 2:
            /* Outputs for IfAction SubSystem: '<S345>/Move Control' incorporates:
             *  ActionPort: '<S349>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_g(FMS_U.Pilot_Cmd.stick_throttle,
                              FMS_U.INS_Out.h_AGL, FMS_U.INS_Out.flag,
                              &FMS_B.Merge_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S345>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S345>/Switch Case' */

          /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
          /* Chart: '<S358>/Motion State' incorporates:
           *  Abs: '<S358>/Abs'
           *  Abs: '<S358>/Abs1'
           *  Constant: '<S368>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S368>/Compare'
           *  SignalConversion: '<S40>/Signal Copy1'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          FMS_MotionState_m(fabsf(FMS_U.Pilot_Cmd.stick_yaw) > FMS_PARAM.YAW_DZ,
                            fabsf(FMS_U.INS_Out.r), &rtb_state_l4,
                            &FMS_DW.sf_MotionState_f);

          /* Logic: '<S371>/Logical Operator' incorporates:
           *  Abs: '<S371>/Abs1'
           *  Abs: '<S371>/Abs2'
           *  Constant: '<S383>/Constant'
           *  Constant: '<S384>/Constant'
           *  Inport: '<Root>/Pilot_Cmd'
           *  RelationalOperator: '<S383>/Compare'
           *  RelationalOperator: '<S384>/Compare'
           *  SignalConversion: '<S40>/Signal Copy2'
           */
          rtb_FixPtRelationalOperator_me = ((fabsf(FMS_U.Pilot_Cmd.stick_pitch) >
            FMS_PARAM.PITCH_DZ) || (fabsf(FMS_U.Pilot_Cmd.stick_roll) >
            FMS_PARAM.ROLL_DZ));

          /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

          /* Chart: '<S371>/Motion State' */
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

          /* End of Chart: '<S371>/Motion State' */

          /* SwitchCase: '<S370>/Switch Case' */
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
              /* InitializeConditions for IfAction SubSystem: '<S370>/Hold Control' incorporates:
               *  ActionPort: '<S372>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S370>/Switch Case' incorporates:
               *  Delay: '<S372>/Delay'
               */
              FMS_DW.icLoad = 1U;

              /* End of InitializeConditions for SubSystem: '<S370>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S370>/Hold Control' incorporates:
             *  ActionPort: '<S372>/Action Port'
             */
            /* Delay: '<S372>/Delay' incorporates:
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
            /* Trigonometry: '<S376>/Trigonometric Function1' incorporates:
             *  Gain: '<S375>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S376>/Trigonometric Function' incorporates:
             *  Gain: '<S375>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S376>/ConcatBufferAtVector Concatenate1In3' incorporates:
             *  Constant: '<S376>/Constant3'
             */
            rtb_VectorConcatenate_h[2] = 0.0F;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* Gain: '<S376>/Gain' incorporates:
             *  Gain: '<S375>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Trigonometry: '<S376>/Trigonometric Function2'
             */
            rtb_VectorConcatenate_h[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

            /* Trigonometry: '<S376>/Trigonometric Function3' incorporates:
             *  Gain: '<S375>/Gain'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             */
            rtb_VectorConcatenate_h[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* SignalConversion: '<S376>/ConcatBufferAtVector Concatenate2In3' incorporates:
             *  Constant: '<S376>/Constant4'
             */
            rtb_VectorConcatenate_h[5] = 0.0F;

            /* SignalConversion: '<S376>/ConcatBufferAtVector ConcatenateIn3' */
            rtb_VectorConcatenate_h[6] = FMS_ConstB.VectorConcatenate3[0];
            rtb_VectorConcatenate_h[7] = FMS_ConstB.VectorConcatenate3[1];
            rtb_VectorConcatenate_h[8] = FMS_ConstB.VectorConcatenate3[2];

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* SignalConversion: '<S372>/TmpSignal ConversionAtMultiplyInport2' incorporates:
             *  Delay: '<S372>/Delay'
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S40>/Signal Copy1'
             *  Sum: '<S372>/Sum'
             */
            rtb_Divide_pr_idx_1 = FMS_DW.Delay_DSTATE[0] - FMS_U.INS_Out.x_R;
            rtb_Divide_lr_idx_2 = FMS_DW.Delay_DSTATE[1] - FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Product: '<S372>/Multiply' incorporates:
             *  SignalConversion: '<S372>/TmpSignal ConversionAtMultiplyInport2'
             */
            for (rtb_n = 0; rtb_n < 3; rtb_n++) {
              rtb_VectorConcatenate_g0[rtb_n] = rtb_VectorConcatenate_h[rtb_n +
                3] * rtb_Divide_lr_idx_2 + rtb_VectorConcatenate_h[rtb_n] *
                rtb_Divide_pr_idx_1;
            }

            /* End of Product: '<S372>/Multiply' */

            /* Gain: '<S372>/Gain2' */
            FMS_B.Merge[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[0];
            FMS_B.Merge[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_g0[1];

            /* Update for Delay: '<S372>/Delay' */
            FMS_DW.icLoad = 0U;

            /* End of Outputs for SubSystem: '<S370>/Hold Control' */
            break;

           case 1:
            if (FMS_DW.SwitchCase_ActiveSubsystem_bf != rtPrevAction) {
              /* InitializeConditions for IfAction SubSystem: '<S370>/Move Control' incorporates:
               *  ActionPort: '<S373>/Action Port'
               */
              /* InitializeConditions for SwitchCase: '<S370>/Switch Case' incorporates:
               *  DiscreteIntegrator: '<S379>/Integrator'
               *  DiscreteIntegrator: '<S379>/Integrator1'
               */
              FMS_DW.Integrator1_DSTATE[0] = 0.0F;
              FMS_DW.Integrator_DSTATE[0] = 0.0F;
              FMS_DW.Integrator1_DSTATE[1] = 0.0F;
              FMS_DW.Integrator_DSTATE[1] = 0.0F;

              /* End of InitializeConditions for SubSystem: '<S370>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S370>/Move Control' incorporates:
             *  ActionPort: '<S373>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S377>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S377>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S377>/Gain' */
            rtb_Divide_pr_idx_1 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
              rtb_Saturation_e;

            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            /* DeadZone: '<S378>/Dead Zone' incorporates:
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

            /* End of DeadZone: '<S378>/Dead Zone' */
            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */

            /* Gain: '<S378>/Gain' */
            rtb_Divide_lr_idx_2 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
              rtb_Saturation_e;

            /* SignalConversion: '<S380>/TmpSignal ConversionAtSquareInport1' */
            rtb_Square_bg[0] = rtb_Divide_pr_idx_1;
            rtb_Square_bg[1] = rtb_Divide_lr_idx_2;

            /* Sum: '<S380>/Sum of Elements' incorporates:
             *  Math: '<S380>/Square'
             *  SignalConversion: '<S380>/TmpSignal ConversionAtSquareInport1'
             *  Sum: '<S381>/Sum of Elements'
             *  Switch: '<S373>/Switch'
             */
            rtb_Saturation_e = rtb_Divide_pr_idx_1 * rtb_Divide_pr_idx_1 +
              rtb_Divide_lr_idx_2 * rtb_Divide_lr_idx_2;

            /* Switch: '<S373>/Switch' incorporates:
             *  Product: '<S381>/Divide'
             *  Sqrt: '<S380>/Sqrt'
             *  Sum: '<S380>/Sum of Elements'
             */
            if (sqrtf(rtb_Saturation_e) > 1.0F) {
              /* Math: '<S381>/Math Function1'
               *
               * About '<S381>/Math Function1':
               *  Operator: sqrt
               */
              if (rtb_Saturation_e < 0.0F) {
                rtb_Saturation_e = -sqrtf(fabsf(rtb_Saturation_e));
              } else {
                rtb_Saturation_e = sqrtf(rtb_Saturation_e);
              }

              /* End of Math: '<S381>/Math Function1' */

              /* Switch: '<S381>/Switch' incorporates:
               *  Constant: '<S381>/Constant'
               *  Product: '<S381>/Product'
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

              /* End of Switch: '<S381>/Switch' */
              rtb_Square_bg[0] = rtb_Switch_an[0] / rtb_Switch_an[2];
              rtb_Square_bg[1] = rtb_Switch_an[1] / rtb_Switch_an[2];
            }

            /* Product: '<S382>/Multiply1' incorporates:
             *  Constant: '<S382>/const1'
             *  DiscreteIntegrator: '<S379>/Integrator'
             */
            rtb_Divide_pr_idx_0 = FMS_DW.Integrator_DSTATE[0] * 0.1F;

            /* Sum: '<S382>/Add' incorporates:
             *  DiscreteIntegrator: '<S379>/Integrator1'
             *  Gain: '<S373>/Gain6'
             *  Sum: '<S379>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE[0] -
              FMS_PARAM.VEL_XY_LIM * rtb_Square_bg[0]) + rtb_Divide_pr_idx_0;

            /* Signum: '<S382>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
            }

            /* Sum: '<S382>/Add2' incorporates:
             *  Abs: '<S382>/Abs'
             *  Gain: '<S382>/Gain'
             *  Gain: '<S382>/Gain1'
             *  Product: '<S382>/Multiply2'
             *  Product: '<S382>/Multiply3'
             *  Sqrt: '<S382>/Sqrt'
             *  Sum: '<S382>/Add1'
             *  Sum: '<S382>/Subtract'
             */
            rtb_Divide_pr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_0;

            /* Sum: '<S382>/Add4' */
            rtb_Divide_pr_idx_0 += rtb_Divide_lr_idx_2 - rtb_Divide_pr_idx_2;

            /* Sum: '<S382>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Sum: '<S382>/Subtract1' */
            rtb_Divide_lr_idx_2 -= FMS_ConstB.d;

            /* Signum: '<S382>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S382>/Sign2' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_2 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              }
            }

            /* Sum: '<S382>/Add5' incorporates:
             *  Gain: '<S382>/Gain2'
             *  Product: '<S382>/Multiply4'
             *  Sum: '<S382>/Subtract2'
             */
            rtb_Divide_pr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S379>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S379>/Integrator1'
             */
            FMS_B.Merge[0] = FMS_DW.Integrator1_DSTATE[0];

            /* Update for DiscreteIntegrator: '<S379>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S379>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];

            /* Signum: '<S382>/Sign4' incorporates:
             *  Sum: '<S382>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S382>/Sign3' incorporates:
             *  Sum: '<S382>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S382>/Sign5' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_2;
            }

            /* Signum: '<S382>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S382>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S382>/Sign6' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Sign5_l = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Sign5_l = rtb_Divide_pr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S379>/Integrator' incorporates:
             *  Constant: '<S382>/const'
             *  Gain: '<S382>/Gain3'
             *  Product: '<S382>/Divide'
             *  Product: '<S382>/Multiply5'
             *  Product: '<S382>/Multiply6'
             *  Sum: '<S382>/Subtract4'
             *  Sum: '<S382>/Subtract5'
             *  Sum: '<S382>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[0] += ((rtb_Divide_pr_idx_2 / FMS_ConstB.d
              - rtb_Saturation_e) * FMS_ConstB.Gain4 * ((rtb_Divide_pr_idx_0 -
              rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 39.224F) * 0.004F;

            /* Product: '<S382>/Multiply1' incorporates:
             *  Constant: '<S382>/const1'
             *  DiscreteIntegrator: '<S379>/Integrator'
             */
            rtb_Divide_pr_idx_0 = FMS_DW.Integrator_DSTATE[1] * 0.1F;

            /* Sum: '<S382>/Add' incorporates:
             *  DiscreteIntegrator: '<S379>/Integrator1'
             *  Gain: '<S373>/Gain6'
             *  Sum: '<S379>/Subtract'
             */
            rtb_Divide_lr_idx_2 = (FMS_DW.Integrator1_DSTATE[1] -
              FMS_PARAM.VEL_XY_LIM * rtb_Square_bg[1]) + rtb_Divide_pr_idx_0;

            /* Signum: '<S382>/Sign' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else if (rtb_Divide_lr_idx_2 > 0.0F) {
              rtb_Divide_pr_idx_1 = 1.0F;
            } else {
              rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2;
            }

            /* Sum: '<S382>/Add2' incorporates:
             *  Abs: '<S382>/Abs'
             *  Gain: '<S382>/Gain'
             *  Gain: '<S382>/Gain1'
             *  Product: '<S382>/Multiply2'
             *  Product: '<S382>/Multiply3'
             *  Sqrt: '<S382>/Sqrt'
             *  Sum: '<S382>/Add1'
             *  Sum: '<S382>/Subtract'
             */
            rtb_Divide_pr_idx_2 = (sqrtf((8.0F * fabsf(rtb_Divide_lr_idx_2) +
              FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
              rtb_Divide_pr_idx_1 + rtb_Divide_pr_idx_0;

            /* Sum: '<S382>/Add4' */
            rtb_Divide_pr_idx_0 += rtb_Divide_lr_idx_2 - rtb_Divide_pr_idx_2;

            /* Sum: '<S382>/Add3' */
            rtb_Divide_pr_idx_1 = rtb_Divide_lr_idx_2 + FMS_ConstB.d;

            /* Sum: '<S382>/Subtract1' */
            rtb_Divide_lr_idx_2 -= FMS_ConstB.d;

            /* Signum: '<S382>/Sign1' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S382>/Sign2' */
            if (rtb_Divide_lr_idx_2 < 0.0F) {
              rtb_Divide_lr_idx_2 = -1.0F;
            } else {
              if (rtb_Divide_lr_idx_2 > 0.0F) {
                rtb_Divide_lr_idx_2 = 1.0F;
              }
            }

            /* Sum: '<S382>/Add5' incorporates:
             *  Gain: '<S382>/Gain2'
             *  Product: '<S382>/Multiply4'
             *  Sum: '<S382>/Subtract2'
             */
            rtb_Divide_pr_idx_2 += (rtb_Divide_pr_idx_1 - rtb_Divide_lr_idx_2) *
              0.5F * rtb_Divide_pr_idx_0;

            /* SignalConversion: '<S379>/Signal Copy' incorporates:
             *  DiscreteIntegrator: '<S379>/Integrator1'
             */
            FMS_B.Merge[1] = FMS_DW.Integrator1_DSTATE[1];

            /* Update for DiscreteIntegrator: '<S379>/Integrator1' incorporates:
             *  DiscreteIntegrator: '<S379>/Integrator'
             */
            FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];

            /* Signum: '<S382>/Sign4' incorporates:
             *  Sum: '<S382>/Subtract3'
             */
            rtb_Divide_pr_idx_1 = rtb_Divide_pr_idx_2 - FMS_ConstB.d;

            /* Signum: '<S382>/Sign3' incorporates:
             *  Sum: '<S382>/Add6'
             */
            rtb_Divide_pr_idx_0 = rtb_Divide_pr_idx_2 + FMS_ConstB.d;

            /* Signum: '<S382>/Sign5' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Saturation_e = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Saturation_e = 1.0F;
            } else {
              rtb_Saturation_e = rtb_Divide_pr_idx_2;
            }

            /* Signum: '<S382>/Sign3' */
            if (rtb_Divide_pr_idx_0 < 0.0F) {
              rtb_Divide_pr_idx_0 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_0 > 0.0F) {
                rtb_Divide_pr_idx_0 = 1.0F;
              }
            }

            /* Signum: '<S382>/Sign4' */
            if (rtb_Divide_pr_idx_1 < 0.0F) {
              rtb_Divide_pr_idx_1 = -1.0F;
            } else {
              if (rtb_Divide_pr_idx_1 > 0.0F) {
                rtb_Divide_pr_idx_1 = 1.0F;
              }
            }

            /* Signum: '<S382>/Sign6' */
            if (rtb_Divide_pr_idx_2 < 0.0F) {
              rtb_Sign5_l = -1.0F;
            } else if (rtb_Divide_pr_idx_2 > 0.0F) {
              rtb_Sign5_l = 1.0F;
            } else {
              rtb_Sign5_l = rtb_Divide_pr_idx_2;
            }

            /* Update for DiscreteIntegrator: '<S379>/Integrator' incorporates:
             *  Constant: '<S382>/const'
             *  Gain: '<S382>/Gain3'
             *  Product: '<S382>/Divide'
             *  Product: '<S382>/Multiply5'
             *  Product: '<S382>/Multiply6'
             *  Sum: '<S382>/Subtract4'
             *  Sum: '<S382>/Subtract5'
             *  Sum: '<S382>/Subtract6'
             */
            FMS_DW.Integrator_DSTATE[1] += ((rtb_Divide_pr_idx_2 / FMS_ConstB.d
              - rtb_Saturation_e) * FMS_ConstB.Gain4 * ((rtb_Divide_pr_idx_0 -
              rtb_Divide_pr_idx_1) * 0.5F) - rtb_Sign5_l * 39.224F) * 0.004F;

            /* End of Outputs for SubSystem: '<S370>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S370>/Switch Case' */

          /* SwitchCase: '<S357>/Switch Case' incorporates:
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
              /* SystemReset for IfAction SubSystem: '<S357>/Hold Control' incorporates:
               *  ActionPort: '<S360>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S357>/Switch Case' */
              FMS_HoldControl_o_Reset(&FMS_DW.HoldControl_a);

              /* End of SystemReset for SubSystem: '<S357>/Hold Control' */
            }

            /* Outputs for IfAction SubSystem: '<S357>/Hold Control' incorporates:
             *  ActionPort: '<S360>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_HoldControl_f(FMS_U.INS_Out.psi, &FMS_B.Merge_k,
                              &FMS_DW.HoldControl_a);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S357>/Hold Control' */
            break;

           case 1:
            /* Outputs for IfAction SubSystem: '<S357>/Brake Control' incorporates:
             *  ActionPort: '<S359>/Action Port'
             */
            FMS_BrakeControl(&FMS_B.Merge_k);

            /* End of Outputs for SubSystem: '<S357>/Brake Control' */
            break;

           case 2:
            if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
              /* SystemReset for IfAction SubSystem: '<S357>/Move Control' incorporates:
               *  ActionPort: '<S361>/Action Port'
               */
              /* SystemReset for SwitchCase: '<S357>/Switch Case' */
              FMS_MoveControl_m_Reset(&FMS_DW.MoveControl_o);

              /* End of SystemReset for SubSystem: '<S357>/Move Control' */
            }

            /* Outputs for IfAction SubSystem: '<S357>/Move Control' incorporates:
             *  ActionPort: '<S361>/Action Port'
             */
            /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
            FMS_MoveControl_a(FMS_U.Pilot_Cmd.stick_yaw, &FMS_B.Merge_k,
                              &FMS_ConstB.MoveControl_o, &FMS_DW.MoveControl_o);

            /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
            /* End of Outputs for SubSystem: '<S357>/Move Control' */
            break;
          }

          /* End of SwitchCase: '<S357>/Switch Case' */

          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S303>/Bus Assignment'
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Constant: '<S303>/Constant'
           */
          FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

          /* BusAssignment: '<S303>/Bus Assignment' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_m;
          FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_j;
          FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2;

          /* Saturate: '<S357>/Saturation' */
          if (FMS_B.Merge_k > FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
          } else if (FMS_B.Merge_k < -FMS_PARAM.YAW_RATE_LIM) {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
          } else {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.psi_rate_cmd = FMS_B.Merge_k;
          }

          /* End of Saturate: '<S357>/Saturation' */

          /* Saturate: '<S370>/Saturation1' */
          if (FMS_B.Merge[0] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[0] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.u_cmd = FMS_B.Merge[0];
          }

          if (FMS_B.Merge[1] > FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge[1] < -FMS_PARAM.VEL_XY_LIM) {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = -FMS_PARAM.VEL_XY_LIM;
          } else {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.v_cmd = FMS_B.Merge[1];
          }

          /* End of Saturate: '<S370>/Saturation1' */

          /* Saturate: '<S345>/Saturation1' */
          if (FMS_B.Merge_o > FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_o < -FMS_PARAM.VEL_Z_LIM) {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
          } else {
            /* BusAssignment: '<S303>/Bus Assignment' incorporates:
             *  BusAssignment: '<S42>/Bus Assignment'
             *  Outport: '<Root>/FMS_Out'
             */
            FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_o;
          }

          /* End of Saturate: '<S345>/Saturation1' */
          /* End of Outputs for SubSystem: '<S296>/Position' */
          break;

         case 4:
          /* Outputs for IfAction SubSystem: '<S296>/Unknown' incorporates:
           *  ActionPort: '<S305>/Action Port'
           */
          /* Outport: '<Root>/FMS_Out' incorporates:
           *  BusAssignment: '<S42>/Bus Assignment'
           */
          FMS_Unknown(&FMS_Y.FMS_Out, &FMS_ConstB.Unknown_d3);

          /* End of Outputs for SubSystem: '<S296>/Unknown' */
          break;
        }

        /* End of Outputs for SubSystem: '<S47>/Assist' */
        break;

       case 3:
        /* Outputs for IfAction SubSystem: '<S47>/Manual' incorporates:
         *  ActionPort: '<S298>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S298>/Bus Assignment'
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S298>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S298>/Bus Assignment' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
         *  Constant: '<S298>/Constant2'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.reset = 1U;
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1;

        /* End of Outputs for SubSystem: '<S47>/Manual' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S47>/Unknown' incorporates:
         *  ActionPort: '<S300>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S42>/Bus Assignment'
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

  /* BusAssignment: '<S42>/Bus Assignment' incorporates:
   *  Constant: '<S42>/Constant'
   *  DataStoreRead: '<S42>/Data Store Read'
   *  DataTypeConversion: '<S42>/Data Type Conversion'
   *  DataTypeConversion: '<S42>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S741>/Discrete-Time Integrator'
   *  Outport: '<Root>/FMS_Out'
   *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy4Inport1'
   *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy5Inport1'
   *  SignalConversion: '<S40>/TmpSignal ConversionAtSignal Copy8Inport1'
   *  Sum: '<S42>/Sum'
   */
  FMS_Y.FMS_Out.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE_g;
  FMS_Y.FMS_Out.mode = (uint8_T)FMS_B.target_mode;

  /* Outputs for Atomic SubSystem: '<S5>/FMS_Input' */
  FMS_Y.FMS_Out.ext_state = (uint8_T)FMS_B.vtol_state;
  FMS_Y.FMS_Out.wp_consume = FMS_B.wp_consume;
  FMS_Y.FMS_Out.wp_current = (uint8_T)(FMS_B.wp_index - 1);

  /* End of Outputs for SubSystem: '<S5>/FMS_Input' */
  FMS_Y.FMS_Out.home[0] = FMS_DW.home[0];
  FMS_Y.FMS_Out.home[1] = FMS_DW.home[1];
  FMS_Y.FMS_Out.home[2] = FMS_DW.home[2];
  FMS_Y.FMS_Out.home[3] = FMS_DW.home[3];

  /* Update for DiscreteIntegrator: '<S741>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S741>/Constant'
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
    FMS_B.DiscreteTimeIntegrator5) * 62.831852F * 0.004F;

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
  /* Start for SwitchCase: '<S135>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_d = -1;

  /* Start for SwitchCase: '<S121>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ad = -1;

  /* End of Start for SubSystem: '<S85>/Position' */
  /* End of Start for SubSystem: '<S46>/Assist' */
  /* End of Start for SubSystem: '<S41>/FW_Mode' */

  /* Start for IfAction SubSystem: '<S41>/MC_Mode' */
  /* Start for SwitchCase: '<S47>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b = -1;

  /* Start for IfAction SubSystem: '<S47>/SubMode' */
  /* Start for SwitchCase: '<S299>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_b4 = -1;

  /* Start for IfAction SubSystem: '<S299>/Return' */
  /* Start for SwitchCase: '<S699>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S689>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_p = -1;

  /* End of Start for SubSystem: '<S299>/Return' */

  /* Start for IfAction SubSystem: '<S299>/Hold' */
  /* Start for SwitchCase: '<S638>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nm = -1;

  /* Start for SwitchCase: '<S606>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k4 = -1;

  /* Start for SwitchCase: '<S617>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_c = -1;

  /* End of Start for SubSystem: '<S299>/Hold' */
  /* End of Start for SubSystem: '<S47>/SubMode' */

  /* Start for IfAction SubSystem: '<S47>/Auto' */
  /* Start for SwitchCase: '<S297>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S297>/Mission' */
  /* Start for Resettable SubSystem: '<S408>/Mission_SubSystem' */
  /* Start for SwitchCase: '<S459>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_fg = -1;

  /* Start for SwitchCase: '<S449>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_h = -1;

  /* End of Start for SubSystem: '<S408>/Mission_SubSystem' */
  /* End of Start for SubSystem: '<S297>/Mission' */
  /* End of Start for SubSystem: '<S47>/Auto' */

  /* Start for IfAction SubSystem: '<S47>/Assist' */
  /* Start for SwitchCase: '<S296>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_o = -1;

  /* Start for IfAction SubSystem: '<S296>/Stabilize' */
  /* Start for SwitchCase: '<S395>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_e = -1;

  /* End of Start for SubSystem: '<S296>/Stabilize' */

  /* Start for IfAction SubSystem: '<S296>/Altitude' */
  /* Start for SwitchCase: '<S311>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_nh = -1;

  /* Start for SwitchCase: '<S329>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S296>/Altitude' */

  /* Start for IfAction SubSystem: '<S296>/Position' */
  /* Start for SwitchCase: '<S345>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for SwitchCase: '<S370>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_bf = -1;

  /* Start for SwitchCase: '<S357>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S296>/Position' */
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
  /* InitializeConditions for Delay: '<S239>/start_vel' */
  FMS_DW.icLoad_lf = 1U;

  /* InitializeConditions for Delay: '<S234>/Delay' */
  FMS_DW.icLoad_mz = 1U;

  /* End of SystemInitialize for SubSystem: '<S88>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S46>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S46>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S86>/Mission' */
  /* InitializeConditions for UnitDelay: '<S200>/Delay Input1'
   *
   * Block description for '<S200>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_dy = 0U;

  /* End of SystemInitialize for SubSystem: '<S86>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S46>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S46>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S85>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S190>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_he = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S190>/Integrator' */
  FMS_DW.Integrator_DSTATE_av = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S191>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S195>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mx = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S195>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S191>/Integrator' */
  FMS_DW.Integrator_DSTATE_ky = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S85>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S85>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S110>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_lj = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S110>/Integrator' */
  FMS_DW.Integrator_DSTATE_i3 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_gw = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_mg = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator' */
  FMS_DW.Integrator_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator' */
  FMS_DW.Integrator_DSTATE_e = 0.0F;

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
  /* InitializeConditions for DiscreteIntegrator: '<S133>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_l = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S183>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_nd = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S183>/Integrator' */
  FMS_DW.Integrator_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S133>/Integrator' */
  FMS_DW.Integrator_DSTATE_ha = 0.0F;

  /* SystemInitialize for Chart: '<S122>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_m);

  /* SystemInitialize for Chart: '<S136>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c26_FMS = 0U;
  FMS_DW.is_c26_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S135>/Hold Control' */
  /* InitializeConditions for Delay: '<S143>/start_vel' */
  FMS_DW.icLoad_g = 1U;

  /* InitializeConditions for Delay: '<S143>/start_wp' */
  FMS_DW.icLoad_ef = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_k = FMS_ConstB.Constant_a;
  if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k >= 1.0F) {
    FMS_DW.DiscreteTimeIntegrator_DSTATE_k = 1.0F;
  } else {
    if (FMS_DW.DiscreteTimeIntegrator_DSTATE_k <= -1.0F) {
      FMS_DW.DiscreteTimeIntegrator_DSTATE_k = -1.0F;
    }
  }

  FMS_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S173>/Discrete-Time Integrator1' */
  FMS_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  FMS_DW.DiscreteTimeIntegrator1_PrevR_p = 0;

  /* End of SystemInitialize for SubSystem: '<S135>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S135>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S175>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S175>/Integrator' */
  FMS_DW.Integrator_DSTATE_f1 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S135>/Move Control' */

  /* SystemInitialize for IfAction SubSystem: '<S121>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_j);

  /* End of SystemInitialize for SubSystem: '<S121>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S121>/Move Control' */
  FMS_MoveControl_Init(&FMS_DW.MoveControl_l);

  /* End of SystemInitialize for SubSystem: '<S121>/Move Control' */

  /* SystemInitialize for Merge: '<S121>/Merge' */
  FMS_B.Merge_fb = 0.0F;

  /* SystemInitialize for Merge: '<S135>/Merge' */
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
  /* SystemInitialize for IfAction SubSystem: '<S299>/Takeoff' */
  /* InitializeConditions for Delay: '<S739>/cur_waypoint' */
  FMS_DW.icLoad_hz = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S735>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S735>/Integrator' */
  FMS_DW.Integrator_DSTATE_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S299>/Takeoff' */

  /* SystemInitialize for IfAction SubSystem: '<S299>/Land' */
  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S654>/Integrator' */
  FMS_DW.Integrator_DSTATE_cy = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S299>/Land' */

  /* SystemInitialize for IfAction SubSystem: '<S299>/Return' */
  /* InitializeConditions for Delay: '<S684>/Delay' */
  FMS_DW.icLoad_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S685>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTATE_a = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S680>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE_a = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetS_j = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S726>/Discrete-Time Integrator' */
  FMS_DW.l1_heading_j = 0.0F;

  /* InitializeConditions for Delay: '<S663>/Delay' */
  FMS_DW.icLoad_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S666>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_on = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S666>/Integrator' */
  FMS_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Chart: '<S700>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_p);

  /* SystemInitialize for IfAction SubSystem: '<S699>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_i);

  /* End of SystemInitialize for SubSystem: '<S699>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S699>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_k);

  /* End of SystemInitialize for SubSystem: '<S699>/Move Control' */

  /* SystemInitialize for Merge: '<S699>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S690>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_g);

  /* SystemInitialize for IfAction SubSystem: '<S689>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_e);

  /* End of SystemInitialize for SubSystem: '<S689>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S689>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_c);

  /* End of SystemInitialize for SubSystem: '<S689>/Move Control' */

  /* SystemInitialize for Merge: '<S689>/Merge' */
  FMS_B.Merge_oo = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S299>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S299>/Hold' */
  /* InitializeConditions for Delay: '<S619>/Delay' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S631>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING_o = 1U;
  FMS_DW.Integrator1_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S631>/Integrator' */
  FMS_DW.Integrator_DSTATE_hi = 0.0F;
  FMS_DW.Integrator_PrevResetState = 0;

  /* SystemInitialize for Chart: '<S607>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_e);

  /* SystemInitialize for Chart: '<S618>/Motion State' */
  FMS_DW.temporalCounter_i1_il = 0U;
  FMS_DW.is_active_c15_FMS = 0U;
  FMS_DW.is_c15_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for Chart: '<S639>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_d);

  /* SystemInitialize for IfAction SubSystem: '<S638>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_ft);

  /* End of SystemInitialize for SubSystem: '<S638>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S638>/Move Control' */
  FMS_MoveControl_f_Init(&FMS_DW.MoveControl_p);

  /* End of SystemInitialize for SubSystem: '<S638>/Move Control' */

  /* SystemInitialize for Merge: '<S638>/Merge' */
  FMS_B.Merge_p[0] = 0.0F;
  FMS_B.Merge_p[1] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S606>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_g);

  /* End of SystemInitialize for SubSystem: '<S606>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S606>/Move Control' */
  FMS_MoveControl_b_Init(&FMS_DW.MoveControl_d);

  /* End of SystemInitialize for SubSystem: '<S606>/Move Control' */

  /* SystemInitialize for Merge: '<S606>/Merge' */
  FMS_B.Merge_po = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S617>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_f);

  /* End of SystemInitialize for SubSystem: '<S617>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S617>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_a);

  /* End of SystemInitialize for SubSystem: '<S617>/Move Control' */

  /* SystemInitialize for Merge: '<S617>/Merge' */
  FMS_B.Merge_h = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S299>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S47>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S297>/Mission' */
  /* InitializeConditions for UnitDelay: '<S411>/Delay Input1'
   *
   * Block description for '<S411>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = 0U;

  /* SystemInitialize for Resettable SubSystem: '<S408>/Mission_SubSystem' */
  /* InitializeConditions for Delay: '<S438>/Delay' */
  FMS_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S439>/Discrete-Time Integrator' */
  FMS_DW.DiscreteTimeIntegrator_DSTAT_kf = 0U;

  /* InitializeConditions for DiscreteIntegrator: '<S434>/Acceleration_Speed' */
  FMS_DW.Acceleration_Speed_DSTATE = 0.0F;
  FMS_DW.Acceleration_Speed_PrevResetSta = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S486>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S416>/Delay' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S419>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S460>/Motion State' */
  FMS_MotionState_Init(&FMS_DW.sf_MotionState_g);

  /* SystemInitialize for IfAction SubSystem: '<S459>/Hold Control' */
  FMS_HoldControl_l_Init(&FMS_DW.HoldControl_m);

  /* End of SystemInitialize for SubSystem: '<S459>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S459>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S469>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S469>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S459>/Move Control' */

  /* SystemInitialize for Merge: '<S459>/Merge' */
  FMS_B.Merge_f[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S459>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S469>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S469>/Integrator' */
  FMS_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S459>/Move Control' */

  /* SystemInitialize for Merge: '<S459>/Merge' */
  FMS_B.Merge_f[1] = 0.0F;

  /* SystemInitialize for Chart: '<S450>/Motion Status' */
  FMS_MotionStatus_a_Init(&FMS_DW.sf_MotionStatus_d);

  /* SystemInitialize for IfAction SubSystem: '<S449>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_n);

  /* End of SystemInitialize for SubSystem: '<S449>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S449>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S456>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S456>/Integrator' */
  FMS_DW.Integrator_DSTATE_ij = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S449>/Move Control' */

  /* SystemInitialize for Merge: '<S449>/Merge' */
  FMS_B.Merge_d = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S408>/Mission_SubSystem' */
  /* End of SystemInitialize for SubSystem: '<S297>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S47>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S47>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S296>/Stabilize' */
  /* InitializeConditions for DiscreteIntegrator: '<S391>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S392>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S392>/Integrator' */
  FMS_DW.Integrator_DSTATE_hl = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S391>/Integrator' */
  FMS_DW.Integrator_DSTATE_i = 0.0F;

  /* SystemInitialize for Chart: '<S396>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_m);

  /* SystemInitialize for IfAction SubSystem: '<S395>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_jv);

  /* End of SystemInitialize for SubSystem: '<S395>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S395>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_b);

  /* End of SystemInitialize for SubSystem: '<S395>/Move Control' */

  /* SystemInitialize for Merge: '<S395>/Merge' */
  FMS_B.Merge_o2 = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S296>/Stabilize' */

  /* SystemInitialize for IfAction SubSystem: '<S296>/Altitude' */
  /* InitializeConditions for DiscreteIntegrator: '<S325>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_m = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S326>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_h = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S326>/Integrator' */
  FMS_DW.Integrator_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S325>/Integrator' */
  FMS_DW.Integrator_DSTATE_h = 0.0F;

  /* SystemInitialize for Chart: '<S312>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_k);

  /* SystemInitialize for IfAction SubSystem: '<S311>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_bq);

  /* End of SystemInitialize for SubSystem: '<S311>/Hold Control' */

  /* SystemInitialize for Merge: '<S311>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* SystemInitialize for Chart: '<S330>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_dx);

  /* SystemInitialize for IfAction SubSystem: '<S329>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_p);

  /* End of SystemInitialize for SubSystem: '<S329>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S329>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_h);

  /* End of SystemInitialize for SubSystem: '<S329>/Move Control' */

  /* SystemInitialize for Merge: '<S329>/Merge' */
  FMS_B.Merge_b = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S296>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S296>/Position' */
  /* SystemInitialize for Chart: '<S346>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_o);

  /* SystemInitialize for IfAction SubSystem: '<S345>/Hold Control' */
  FMS_HoldControl_o_Init(&FMS_DW.HoldControl_j3);

  /* End of SystemInitialize for SubSystem: '<S345>/Hold Control' */

  /* SystemInitialize for Chart: '<S358>/Motion State' */
  FMS_MotionState_f_Init(&FMS_DW.sf_MotionState_f);

  /* SystemInitialize for Chart: '<S371>/Motion State' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S370>/Hold Control' */
  /* InitializeConditions for Delay: '<S372>/Delay' */
  FMS_DW.icLoad = 1U;

  /* End of SystemInitialize for SubSystem: '<S370>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S370>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S379>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S379>/Integrator' */
  FMS_DW.Integrator_DSTATE[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S370>/Move Control' */

  /* SystemInitialize for Merge: '<S370>/Merge' */
  FMS_B.Merge[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S370>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S379>/Integrator1' */
  FMS_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S379>/Integrator' */
  FMS_DW.Integrator_DSTATE[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S370>/Move Control' */

  /* SystemInitialize for Merge: '<S370>/Merge' */
  FMS_B.Merge[1] = 0.0F;

  /* SystemInitialize for Merge: '<S345>/Merge' */
  FMS_B.Merge_o = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S357>/Hold Control' */
  FMS_HoldControl_d_Init(&FMS_DW.HoldControl_a);

  /* End of SystemInitialize for SubSystem: '<S357>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S357>/Move Control' */
  FMS_MoveControl_i_Init(&FMS_DW.MoveControl_o);

  /* End of SystemInitialize for SubSystem: '<S357>/Move Control' */

  /* SystemInitialize for Merge: '<S357>/Merge' */
  FMS_B.Merge_k = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S296>/Position' */
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
